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

NiAVObject::~NiAVObject() {
	//Clear Properties
	ClearProperties();
}

void NiAVObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_A_V_OBJECT_READ
}

void NiAVObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_A_V_OBJECT_WRITE
}

string NiAVObject::asString( bool verbose ) const {
	NI_A_V_OBJECT_STRING
}

void NiAVObject::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_A_V_OBJECT_FIXLINKS
}

list<NiObjectRef> NiAVObject::GetRefs() const {
	NI_A_V_OBJECT_GETREFS
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

void NiAVObject::SetParent( NiNode * new_parent ) {
	parent = new_parent;
}

Ref<NiNode> NiAVObject::GetParent() const {
	return parent;
}

void NiAVObject::AddProperty( Ref<NiProperty> & obj ) {
	properties.push_back( obj );
}

void NiAVObject::RemoveProperty( Ref<NiProperty> obj ) {
	//Search property list for the one to remove
	for ( vector< NiPropertyRef >::iterator it = properties.begin(); it != properties.end(); ) {
		if ( *it == obj ) {
			it = properties.erase( it );
		} else {
			++it;
		}
	}
}

void NiAVObject::ClearProperties() {
	properties.clear();
}

vector< Ref<NiProperty> > NiAVObject::GetProperties() const {
	return properties;
}

Ref<NiProperty> NiAVObject::GetPropertyByType( const Type & compare_to ) {
	for ( uint i = 0; i < properties.size(); ++i ) {
		if ( properties[i]->IsSameType( compare_to ) ) {
			return properties[i];
		}
	}
	//No matching properties found, return NULL
	return NULL;
}

ushort NiAVObject::GetFlags() const {
	return flags;
}

void NiAVObject::SetFlags( ushort n ) {
	flags = n;
}

Matrix33 NiAVObject::GetLocalRotation() const {
	return rotation;
}

void NiAVObject::SetLocalRotation( const Matrix33 & n ) {
	rotation = n;
}

Vector3 NiAVObject::GetLocalTranslation() const {
	return translation;
}

void NiAVObject::SetLocalTranslation( const Vector3 & n ) {
	translation = n;
}

float NiAVObject::GetLocalScale() const {
	return scale;
}

void NiAVObject::SetLocalScale( float n ) {
	scale = n;
}

Vector3 NiAVObject::GetVelocity() const {
	return velocity;
}

void NiAVObject::SetVelocity( const Vector3 & n ) {
	velocity = n;
}