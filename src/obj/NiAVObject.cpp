/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiProperty.h"
#include "../../include/obj/NiCollisionData.h"
#include "../../include/obj/NiCollisionObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiAVObject::TYPE("NiAVObject", &NI_A_V_OBJECT_PARENT::TypeConst() );

NiAVObject::NiAVObject() NI_A_V_OBJECT_CONSTRUCT, parent(NULL) {}

NiAVObject::~NiAVObject() {
	//Clear Properties
	ClearProperties();

	//Clear Collision Object Link
	if ( collisionObject != NULL ) {
		collisionObject->SetParent(NULL);
	}
}

void NiAVObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiAVObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiAVObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAVObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiAVObject::GetRefs() const {
	return InternalGetRefs();
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

void NiAVObject::AddProperty( const Ref<NiProperty> & obj ) {
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
	for ( unsigned int i = 0; i < properties.size(); ++i ) {
		if ( properties[i]->IsSameType( compare_to ) ) {
			return properties[i];
		}
	}
	//No matching properties found, return NULL
	return NULL;
}

unsigned short NiAVObject::GetFlags() const {
	return flags;
}

void NiAVObject::SetFlags( unsigned short n ) {
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

NiAVObject::CollisionType NiAVObject::GetCollisionMode() const {
	//Mask off the 2 significant bits
	unsigned short temp = flags & 0x6;

	//Shift the result one right
	return NiAVObject::CollisionType(temp >> 1);
}

void NiAVObject::SetCollisionMode( CollisionType value ) {
	unsigned short temp = (unsigned short)value;

	//Shift one left
	temp = temp << 1;

	//Zero out the values in the flags for the 2 significant bits
	flags = flags & 0xFFF9;

	//Now combine values
	flags = flags | temp;
}

Ref<NiCollisionData > NiAVObject::GetCollisionData() const {
   return collisionData;
}

void NiAVObject::SetCollisionData( NiCollisionData * value ) {
   collisionData = value;
}


Ref<NiCollisionObject > NiAVObject::GetCollisionObject() const {
  return collisionObject;
}

void NiAVObject::SetCollisionObject( NiCollisionObject * value ) {
	if ( value->GetParent() != NULL ) {
		throw runtime_error( "You have attempted to add a collision object to a NiNode which is already attached to another NiNode." );
	}
	value->SetParent( this );

	if ( collisionObject !=NULL ) {
		//Remove unlink previous collision object from this node
		collisionObject->SetParent(NULL);
	}

	collisionObject = value;
}

void NiAVObject::SetLocalTransform( const Matrix44 & n ) {
	n.Decompose( translation, rotation, scale );
}

bool NiAVObject::GetVisibility() const {
	return !( flags & 1 );
}

void NiAVObject::SetVisibility( bool n ) {
	//Only do anything if the value is different from what it already is
	if ( GetVisibility() != n ) {
		//Flip the bit
		flags ^= 1;
	}
}

bool NiAVObject::HasBoundingBox() const {
	return hasBoundingBox;
}

void NiAVObject::ClearBoundingBox() {
	hasBoundingBox = false;
}

BoundingBox NiAVObject::GetBoundingBox() const {
	if ( hasBoundingBox == true ) {
		return boundingBox;
	} else {
		throw runtime_error("This NIAVObject has no Bounding Box.");
	}
}

void NiAVObject::SetBoundingBox( const BoundingBox & n ) {
	boundingBox = n;
	hasBoundingBox = true;
}

const Type & NiAVObject::GetType() const {
	return TYPE;
};

const Type & NiAVObject::TypeConst() {
	return TYPE;
}
