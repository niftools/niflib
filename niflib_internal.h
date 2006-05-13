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

#include "niflib.h"
#include <iomanip>
#include <sstream>

typedef unsigned char	byte;
typedef unsigned short	ushort;
typedef unsigned int	uint;

const char ATTRERR[] = "Attribute type Missmatch.";

//Inernal Attribute Abstract Class
class AAttr : public IAttr {
public:
	AAttr( string const & name, IBlock * owner ) : _name(name), _owner(owner) {}
	~AAttr() {}
	string GetName() const { return _name; }
	//Getters
	int asInt() const { throw runtime_error(ATTRERR); }
	float asFloat() const { throw runtime_error(ATTRERR); }
	Float3 asFloat3() const { throw runtime_error(ATTRERR); }
	Float4 asFloat4() const { throw runtime_error(ATTRERR); }
	Matrix33 asMatrix33() const { throw runtime_error(ATTRERR); }
	blk_ref asLink() const { throw runtime_error(ATTRERR); }
	TexSource asTexSource() const { throw runtime_error(ATTRERR); }
	BoundingBox asBoundingBox() const { throw runtime_error(ATTRERR); }
	TexDesc asTexDesc() const { throw runtime_error(ATTRERR); }
	list<blk_ref> asLinkList() const { throw runtime_error(ATTRERR); }
	//Setters
	void Set(int) { throw runtime_error(ATTRERR); }
	void Set(float) { throw runtime_error(ATTRERR); }
	void Set(Float3 const &) { throw runtime_error(ATTRERR); }
	void Set(Float4 const &) { throw runtime_error(ATTRERR); }
	void Set(string const &) { throw runtime_error(ATTRERR); }
	void Set(Matrix33 const &) { throw runtime_error(ATTRERR); }
	void Set(blk_ref const &) { throw runtime_error(ATTRERR); }
	void Set(TexSource const &) { throw runtime_error(ATTRERR); }
	void Set(BoundingBox const &) { throw runtime_error(ATTRERR); }
	void Set(TexDesc const &) { throw runtime_error(ATTRERR); }
	//Link functions
	bool HasLinks() const { return false; }
	void AddLink( blk_ref const & block ) { cout << "AddLink" << endl; throw runtime_error(ATTRERR); }
	void AddLinks( list<blk_ref> const & new_links ) { cout << "AddLinkS" << endl; throw runtime_error(ATTRERR); }
	void ClearLinks() { cout << "ClearLinks" << endl; throw runtime_error(ATTRERR); }
	void RemoveLinks( blk_ref const & block ) { cout << "RemoveLinks" << endl; throw runtime_error(ATTRERR); }
	blk_ref FindLink( string const & block_type ) const { cout << "FindLink" << endl; throw runtime_error(ATTRERR); }
protected:
	string _name;
	IBlock * _owner;
};

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



/**
 * Base Object class from which all other objects derive
 */

class NiObject {
public:
	NiObject();
	~NiObject();
	//Run-Time Type Information
	static const Type TYPE;
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
	
private:
	unsigned int _ref_count;
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

//Internal Abstract Block Class

class ABlock : public IBlock {
public:
	ABlock();
	~ABlock();
	static const Type TYPE;
	blk_ref Clone( unsigned int version = 0xFFFFFFFF );
	//void AddAttr( AttrType type, string const & name, unsigned int first_ver = 0, unsigned int last_ver = 0xFFFFFFFF );
	attr_ref GetAttr(string const & attr_name) const;
	vector<attr_ref> GetAttrs() const;
	int GetBlockNum() const { return _block_num; }
	bool IsControllable() const { return false; }
	bool IsController() const { return false; }
	string asString() const;

	//Links
	blk_ref GetParent() const;
	list<blk_ref> GetLinks() const;

	//Reference Counting
	void AddRef();
	void SubtractRef();

	//Interface
	void * QueryInterface( int id ) {
		/*if ( id == BlockInternal ) {
			return (void*)static_cast<IBlockInternal*>(this);;
		} else {*/
			return NULL;
		/*}*/
	}

	void const * QueryInterface( int id ) const {
		/*if ( id == BlockInternal ) {
			return (void const *)static_cast<IBlockInternal const *>(this);;
		} else {*/
			return NULL;
		/*}*/
	}

	//--Internal Functions--//
	void AddParent( IBlock * new_parent);
	void RemoveParent( IBlock * match );
	void SetBlockNum( int n ) { _block_num = n; }
	virtual void FixLinks( const vector<blk_ref> & blocks );
	void SetBlockTypeNum( int n ) { _block_type_num = n; }
	int GetBlockTypeNum() { return _block_type_num; }

	void AddChild( IBlock * new_child );
	void RemoveChild( IBlock * old_child );

	virtual void RemoveCrossLink( IBlock * block_to_remove );

	void IncCrossRef( IBlock * block );
	void DecCrossRef( IBlock * block );
	virtual void ReassignCrossRefs( const map<string,blk_ref> & name_map ) {}

	virtual void Read( istream& in, unsigned int version );
	virtual void Write( ostream& out, unsigned int version ) const;
protected:
	map<string, attr_ref> _attr_map;
	vector<attr_ref> _attr_vect;
	int _block_num;
	int _block_type_num;
	unsigned int _ref_count;
	vector<IBlock*> _parents;
	list<IBlock*> _cross_refs;
};

//--Link Classes--//

class Link {
public:
	//Constructors
	Link () : _owner(NULL), index(-1) {}
	Link ( IBlock * owner) : _owner(owner), index(-1) {}
	//Destructor
	~Link() { KillLink(); }
	void SetIndex( const int new_index );
	void Nullify() {
		KillLink();
		link.nullify();
	};
	blk_ref GetLink() const { return link; }
	void SetLink( const blk_ref & new_link );
	void Fix( const vector<blk_ref> & blocks );
	void SetOwner( IBlock * owner );
private:
	IBlock * _owner;
	blk_ref link;
	int index;
	void InitLink();
	void KillLink();
};

//--CrossRef Classes--//

class CrossRef {
public:
	//Constructors
	CrossRef () : _owner(NULL), ref(NULL), index(-1) {}
	CrossRef ( IBlock * owner) : _owner(owner), ref(NULL), index(-1) {}
	//Destructor
	~CrossRef() { KillRef(); }
	void SetIndex( const int new_index );
	void Nullify() {
		KillRef();
		ref = NULL;
	}
	IBlock * GetCrossRef() const { return ref; }
	void SetCrossRef( IBlock * new_ref );
	void LostRef( IBlock * match );
	void Fix( const vector<blk_ref> & blocks );
	void SetOwner( IBlock * owner );
private:
	IBlock * _owner;
	IBlock * ref;
	int index;
	void InitRef();
	void KillRef();
};


struct HeaderString {
	string header;
};

#endif