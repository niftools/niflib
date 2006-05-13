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

//--Typedefs--//

typedef unsigned char	byte;
typedef unsigned short	ushort;
typedef unsigned int	uint;

#include "nif_math.h"

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

const Type NiObject::TYPE("NiObject", NULL );

/*
 * NiObjectNET - An object that has a name and can be parented to other objects.  Can have extra data and controllers attatched.
 */

class NiObjectNET;

typedef Ref<NiObjectNET> NiObjectNETRef;

class NiObjectNET : public NiObject {
public:
	NiObjectNET() {}
	~NiObjectNET() {}
	//Run-Time Type Information
	static const Type TYPE;

	string name;

	void SetParent( NiObjectNETRef new_parent ) {
		parent = new_parent;
	}
	NiObjectNETRef GetParent() { return parent; }

private:
	NiObjectNET * parent;
	//TODO: pointer to extra data type... find out what that is.  AExtraData right now.  Need functions to add/remove.
	//TODO: pointer to first NiTimeController type.  Need functions to add/remove.
};

const Type NiObjectNET::TYPE("NiObjectNET", &NiObject::TYPE );

/*
 * NiAVObject - An audio/video object?  Part of the scene graph and has a position in 3D.
 */

class NiAVObject;

typedef Ref<NiAVObject> NiAVObjectRef;

class NiAVObject : public NiObjectNET {
public:
	NiAVObject() {}
	~NiAVObject() {}
	//Run-Time Type Information
	static const Type TYPE;

	short flags;
	Vector3 localTranslate;
	Matrix33 localRotate;
	float localScale;
	Vector3 localVelocity;
	//TODO: list of NiProperty pointers.  Need functions to add/remove.
	//TODO:  Bounding Box.  What to do with newer files that have a link?  Wrap this in a function and translate?

	/*! 
	 * This is a conveniance function that allows you to retrieve the full 4x4 matrix transform of a node.  It accesses the "Rotation," "Translation," and "Scale" attributes and builds a complete 4x4 transformation matrix from them.
	 * \return A 4x4 transformation matrix built from the node's transform attributes.
	 * \sa INode::GetWorldTransform
	 */
	Matrix44 GetLocalTransform() const;

	/*! 
	 * This function will return a transform matrix that represents the location of this node in world space.  In other words, it concatenates all parent transforms up to the root of the scene to give the ultimate combined transform from the origin for this node.
	 * \return The 4x4 world transform matrix of this node.
	 * \sa INode::GetLocalTransform
	 */
	Matrix44 GetWorldTransform() const;

	/*!
	 * This function returns the bind position world matrix.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.
	 * \return The 4x4 world bind position matrix of this node.
	 * \sa INode::GetLocalBindPos, INode::SetWorldBindPos
	 */
	Matrix44 GetWorldBindPos() const;

	/*! This function returns the bind position world matrix of this node multiplied with the inverse of the bind position world matrix of its parent object if any.  Thus it returns the bind position of the object in local coordinates.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.
	 * \return The 4x4 local bind position matrix of this node.
	 * \sa INode::SetWorldBindPos, INode::GetWorldBindPos
	 */
	Matrix44 GetLocalBindPos() const;

	/*!
	 * This function sets the bind position of this object relative to the origin.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.  This function must be called on every object in a skin and bones system (the bones and the skinned shapes) in order for skinning information to be written to a Nif file.
	 * \param m The 4x4 world bind position matrix of this node
	 * \sa INode::GetLocalBindPos, INode::GetWorldBindPos
	 */
	void SetWorldBindPos( Matrix44 const & m );

protected:
	void ResetSkinnedFlag();
	Matrix44 bindPosition;

};

const Type NiAVObject::TYPE("NiAVObject", &NiObjectNET::TYPE );

/*
 * NiNode - A basic scene graph node.  Can have children.
 */

class NiNode;

typedef Ref<NiNode> NiNodeRef;

class NiNode : public NiAVObject {
public:
	NiNode() {}
	~NiNode() {}
	//Run-Time Type Information
	static const Type TYPE;

	//TODO:  Add functions to get and set children and store a list of NiObjectNET references
};

const Type NiNode::TYPE("NiNode", &NiAVObject::TYPE );


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