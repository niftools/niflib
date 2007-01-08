/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkEntity.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkEntity::TYPE("bhkEntity", &BHK_ENTITY_PARENT::TypeConst() );

bhkEntity::bhkEntity() BHK_ENTITY_CONSTRUCT {}

bhkEntity::~bhkEntity() {}

void bhkEntity::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkEntity::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkEntity::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkEntity::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkEntity::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkEntity::GetType() const {
	return TYPE;
};

Ref<bhkShape > bhkEntity::GetShape() const {
	return shape;
}

void bhkEntity::SetShape( Ref<bhkShape > value ) {
	shape = value;
}

OblivionLayer bhkEntity::GetLayer() const {
	return layer;
}

void bhkEntity::SetLayer( OblivionLayer value ) {
	layer = value;
}

