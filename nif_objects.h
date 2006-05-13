/* Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above
     copyright notice, this list of conditions and the following
     disclaimer in the documentation and/or other materials provided
     with the distribution.

   * Neither the name of the NIF File Format Library and Tools
     project nor the names of its contributors may be used to endorse
     or promote products derived from this software without specific
     prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

#ifndef _INTERNAL_H_
#define _INTERNAL_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <vector>

using namespace std;

/**
 * Run Time Type Inforamtion Class
 */
class Type {
public:
	Type (const string & type_name, const Type * base_type );
	~Type();

	string GetTypeName() const;

	bool IsSameType ( const Type & compare_to ) const;
	bool IsDerivedType ( const Type & compare_to ) const;
private:
	string name;
	const Type * base_type;
};

/**
 * Smart Pointer Template
 */
template <class T> class Ref {
public:
	Ref( T * object = NULL );
	Ref(const Ref & ref_to_copy );

	operator T*() const;
	T& operator*() const;
	T* operator->() const;

	Ref & operator=( T * object );
	Ref & operator=( const Ref & ref );

	bool operator==(T * object) const;
	bool operator!=(T * object) const;
	bool operator==(const Ref & ref) const;
	bool operator!=(const Ref & ref) const;

protected:
	//The shared object
	T* _object;
};

class NiObject;
typedef Ref<NiObject> NiObjectRef;
typedef Ref<NiObject> blk_ref; //Temporary to make old code compile
typedef NiObject IBlock;

/**
 * Base Object class from which all other objects derive
 */

class NiObject {
public:
	NiObject();
	~NiObject();
	//Run-Time Type Information
	static const Type TYPE;

	/*!
	 * Used to determine an object's type.  These type strings are the same as the class names of the blocks in the <a href = "http://niftools.sourceforge.net/docsys/">NIF File Format Browser</a>.
	 * \return A string containing the type of the object.  Ex. NiNode, NiTriShapeData, NiParticleSystemController, etc.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * cout << my_block->GetType();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * print block.GetType()
	 * \endcode
	 * 
	 * \sa CreateBlock
	 */
	virtual const Type & GetType() const { return TYPE; };

	bool IsSameType( const Type & compare_to ) const;
	bool IsSameType( const NiObject * object ) const;
	bool IsDerivedType (const Type & compare_to ) const;
	bool IsDerivedType( const NiObject * objct ) const;

	//Streaming Functions
	virtual void Read( istream& in, unsigned int version ) {};
	virtual void Write( ostream& out, unsigned int version ) const {};
	//TODO Register objects in list
	//TODO Link up objects from previously created list

	//Reference Counting
	void AddRef(); //Should not be called directly
	void SubtractRef(); //Should not be called directly
	unsigned int GetNumRefs() { return _ref_count; }

	/*! Returns A new block that contains all the same data that this block does, but occupies a different part of memory.  The data stored in a NIF file varies from version to version.  Usually you are safe with the default option (the highest availiable version) but you may need to use an earlier version if you need to clone an obsolete piece of information.
	 * \param version The version number to use in the memory streaming operation.  Default is the highest version availiable.
	 * \return A cloned copy of this block as a new block.
	 * \sa CreateBlock
	 */
	NiObjectRef Clone( unsigned int version = 0xFFFFFFFF );

	/*!
	 * Summarizes the information contained in this block in English.
	 * \return A string containing a summary of the information within the block in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * cout << my_block->asString();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * print block.asString()
	 * \endcode
	 * 
	 * \sa IAttr::asString, SetVerboseMode
	 */
	virtual string asString() const;
	
	// Python Operator Overloads
	string __str__() const {
		return asString();
	};

	virtual void RemoveCrossLink( NiObject * block_to_remove );

	void IncCrossRef( NiObject * block );
	void DecCrossRef( NiObject* block );
	virtual void ReassignCrossRefs( const map<string,NiObjectRef> & name_map ) {}
	
private:
	unsigned int _ref_count;
	list<NiObject*> _cross_refs;
};


/*
 * Casting Templates
 */

template <class T> T* StaticCast( NiObject * object ) {
	return (T*)object;
}

template <class T> const T* SaticCast (const NiObject * object) {
	return (const T*)object;
}

template <class T> T* DynamicCast( NiObject * object ) {
	if ( object->IsDerivedType(T::TYPE) ) {
		return (T*)object;
	} else {
		return NULL;
	}
}

template <class T> const T* DynamicCast( const NiObject * object ) {
	if ( object->IsDerivedType(T::TYPE) ) {
		return (const T*)object;
	} else {
		return NULL;
	}
}


const Type NiObject::TYPE("NiObject", NULL );

////--Link Classes--//
//
//class Link {
//public:
//	//Constructors
//	Link () : _owner(NULL), index(-1) {}
//	Link ( NiObject * owner) : _owner(owner), index(-1) {}
//	//Destructor
//	~Link() { KillLink(); }
//	void SetIndex( const int new_index );
//	void Nullify() {
//		KillLink();
//		link.nullify();
//	};
//	blk_ref GetLink() const { return link; }
//	void SetLink( const blk_ref & new_link );
//	void Fix( const vector<blk_ref> & blocks );
//	void SetOwner( IBlock * owner );
//private:
//	IBlock * _owner;
//	blk_ref link;
//	int index;
//	void InitLink();
//	void KillLink();
//};
//
////--CrossRef Classes--//
//
//class CrossRef {
//public:
//	//Constructors
//	CrossRef () : _owner(NULL), ref(NULL), index(-1) {}
//	CrossRef ( NiObject * owner) : _owner(owner), ref(NULL), index(-1) {}
//	//Destructor
//	~CrossRef() { KillRef(); }
//	void SetIndex( const int new_index );
//	void Nullify() {
//		KillRef();
//		ref = NULL;
//	}
//	IBlock * GetCrossRef() const { return ref; }
//	void SetCrossRef( NiObject * new_ref );
//	void LostRef( NiObject * match );
//	void Fix( const vector<blk_ref> & blocks );
//	void SetOwner( NiObject * owner );
//private:
//	IBlock * _owner;
//	IBlock * ref;
//	int index;
//	void InitRef();
//	void KillRef();
//};


struct HeaderString {
	string header;
};

#endif