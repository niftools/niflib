/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIAVOBJECT_H_
#define _NIAVOBJECT_H_

// Includes
#include "obj/NiProperty.h"
#include "gen/BoundingBox.h"
#include "obj/NiCollisionData.h"
#include "obj/NiCollisionObject.h"

#include "gen/obj_defines.h"
#include NI_A_V_OBJECT_INCLUDE

/*
 * NiAVObject - An audio/video object?  Part of the scene graph and has a position in 3D.
 */

class NiAVObject;
typedef Ref<NiAVObject> NiAVObjectRef;

class NiAVObject : public NI_A_V_OBJECT_PARENT {
public:
	NiAVObject();
	~NiAVObject();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );

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

	void SetParent( NiAVObjectRef new_parent ) {
		parent = new_parent;
	}
	NiAVObjectRef GetParent() { return parent; }

private:
	NI_A_V_OBJECT_MEMBERS

	NiAVObject * parent;
	void ResetSkinnedFlag();
	Matrix44 bindPosition;
};

#endif
