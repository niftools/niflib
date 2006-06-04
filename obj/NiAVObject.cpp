/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiAVObject.h"
#include "NiNode.h"
#include "NiProperty.h"
#include "NiCollisionData.h"
#include "NiCollisionObject.h"

//Definition of TYPE constant
const Type NiAVObject::TYPE("NiAVObject", &NI_A_V_OBJECT_PARENT::TYPE );

NiAVObject::NiAVObject() NI_A_V_OBJECT_CONSTRUCT, parent(NULL) {}

NiAVObject::~NiAVObject() {}

void NiAVObject::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	NI_A_V_OBJECT_READ
}

void NiAVObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	NI_A_V_OBJECT_WRITE
}

string NiAVObject::asString( bool verbose ) const {
	NI_A_V_OBJECT_STRING
}

void NiAVObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	NI_A_V_OBJECT_FIXLINKS
}

/*! 
 * This is a conveniance function that allows you to retrieve the full 4x4 matrix transform of a node.  It accesses the "Rotation," "Translation," and "Scale" attributes and builds a complete 4x4 transformation matrix from them.
 * \return A 4x4 transformation matrix built from the node's transform attributes.
 * \sa INode::GetWorldTransform
 */
Matrix44 NiAVObject::GetLocalTransform() const {
	return Matrix44( translation, rotation, scale );
}
/*! 
 * This function will return a transform matrix that represents the location of this node in world space.  In other words, it concatenates all parent transforms up to the root of the scene to give the ultimate combined transform from the origin for this node.
 * \return The 4x4 world transform matrix of this node.
 * \sa INode::GetLocalTransform
 */
Matrix44 NiAVObject::GetWorldTransform() const {
	//Get Parent Transform if there is one
	NiNodeRef par = GetParent();

	if ( par != NULL ) {
		//Multipy local matrix and parent world matrix for result
		return GetLocalTransform() * par->GetWorldTransform();
	}
	else {
		//No parent transform, simply return local transform
		return GetLocalTransform();
	}
}
/*!
 * This function returns the bind position world matrix.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.
 * \return The 4x4 world bind position matrix of this node.
 * \sa INode::GetLocalBindPos, INode::SetWorldBindPos
 */
Matrix44 NiAVObject::GetWorldBindPos() const {
	return bindPosition;
}
/*! This function returns the bind position world matrix of this node multiplied with the inverse of the bind position world matrix of its parent object if any.  Thus it returns the bind position of the object in local coordinates.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.
 * \return The 4x4 local bind position matrix of this node.
 * \sa INode::SetWorldBindPos, INode::GetWorldBindPos
 */
Matrix44 NiAVObject::GetLocalBindPos() const {
	//Get Parent Transform if there is one
	NiNodeRef par = GetParent();
	if ( par != NULL ) {
		//There is a node parent
		//multiply its inverse with this block's bind position to get the local bind position
		return bindPosition * par->GetWorldBindPos().Inverse();
	}
	else {
		//No parent transform, simply return local transform
		return GetWorldBindPos();
	}
}

/*!
 * This function sets the bind position of this object relative to the origin.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.  This function must be called on every object in a skin and bones system (the bones and the skinned shapes) in order for skinning information to be written to a Nif file.
 * \param m The 4x4 world bind position matrix of this node
 * \sa INode::GetLocalBindPos, INode::GetWorldBindPos
 */
void NiAVObject::SetWorldBindPos( Matrix44 const & m )  {}

void NiAVObject::SetParent( Ref<NiNode> new_parent ) {
	parent = new_parent;
}

Ref<NiNode> NiAVObject::GetParent() const {
	return parent;
}

void NiAVObject::ResetSkinnedFlag() {

}
