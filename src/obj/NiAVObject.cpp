/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiProperty.h"
#include "../../include/obj/NiCollisionData.h"
#include "../../include/obj/NiCollisionObject.h"
using namespace Niflib;


#define NIFLIB_GET_FLAG(value, shift, mask) \
   (( value >> shift ) & mask)

#define NIFLIB_MASK_FLAG(flag, value, shift, mask) \
   ((flag ^ ~(mask << shift)) | ((value & mask) << shift))

//Definition of TYPE constant
const Type NiAVObject::TYPE("NiAVObject", &NI_A_V_OBJECT_PARENT::TypeConst() );

NiAVObject::NiAVObject() NI_A_V_OBJECT_CONSTRUCT, parent(NULL) {}

NiAVObject::~NiAVObject() {
	//Clear Properties
	ClearProperties();
}

void NiAVObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiAVObject::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiAVObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiAVObject::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
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

NiAVObject::CollisionType NiAVObject::GetCollision()
{
   return (NiAVObject::CollisionType)NIFLIB_GET_FLAG(flags, 1, 0x03);
}

void NiAVObject::SetCollsion(NiAVObject::CollisionType value)
{
   flags = NIFLIB_MASK_FLAG(flags, value, 1, 0x03);
}

bool NiAVObject::GetHidden()
{
   return (bool)NIFLIB_GET_FLAG(flags, 0, 0x01);
}

Ref<NiCollisionData > NiAVObject::GetCollisionData() const {
   return collisionData;
}

void NiAVObject::SetCollisionData( Ref<NiCollisionData > value ) {
   collisionData = value;
}


Ref<NiCollisionObject > NiAVObject::GetCollisionObject() const {
  return collisionObject;
}

void NiAVObject::SetCollisionObject( Ref<NiCollisionObject > value ) {
   collisionObject = value;
}

void NiAVObject::SetHidden(bool value)
{
   flags = NIFLIB_MASK_FLAG(flags, value, 0, 0x01);
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
