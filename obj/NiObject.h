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

#ifndef _NIOBJECT_H_
#define _NIOBJECT_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include "NIF_IO.h"
#include "Ref.h"
#include "xml_extract.h"

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
	bool operator<( const Type & compare_to ) const { return (this < &compare_to); }
private:
	string name;
	const Type * base_type;
};

/**
 * NiObject - Base Object class from which all other objects derive
 */

class NiObject;
typedef Ref<NiObject> NiObjectRef;
typedef Ref<NiObject> blk_ref; //Temporary to make old code compile
typedef NiObject IBlock;

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
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version ) {}
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {}
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {}

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
	 * \verbose Determines whether or not detailed information about large areas of data will be printed out.
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
	virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to retrieve all blocks that the current block is linked to through <i>all</i> attributes.
	 * \return A list of references to blocks that this attribute links its owner block to.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * list<blk_ref> attr_list = my_block->GetLinks();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * attr_list = my_block.GetLinks()
	 * \endcode
	 */
	virtual list<NiObjectRef> GetLinks();
	
	// Python Operator Overloads
	string __str__() const {
		return asString();
	};

	virtual void RemoveCrossLink( NiObject * block_to_remove );

	void IncCrossRef( NiObject * block );
	void DecCrossRef( NiObject* block );
	virtual void ReassignCrossRefs( const map<string,NiObjectRef> & name_map ) {}
	
	static unsigned int NumObjectsInMemory() { return objectsInMemory; }
private:
	unsigned int _ref_count;
	list<NiObject*> _cross_refs;
	static unsigned int objectsInMemory;
};


/*
 * Casting Templates
 */

template <class T> Ref<T> StaticCast( NiObject * object ) {
	return (T*)object;
}

template <class T> const Ref<T> SaticCast (const NiObject * object) {
	return (const T*)object;
}

template <class T> Ref<T> DynamicCast( NiObject * object ) {
	if ( object->IsDerivedType(T::TYPE) ) {
		return (T*)object;
	} else {
		return NULL;
	}
}

template <class T> const Ref<T> DynamicCast( const NiObject * object ) {
	if ( object->IsDerivedType(T::TYPE) ) {
		return (const T*)object;
	} else {
		return NULL;
	}
}

#endif