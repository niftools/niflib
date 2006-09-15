/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkEntity.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkEntity::TYPE("bhkEntity", &BHK_ENTITY_PARENT::TypeConst() );

bhkEntity::bhkEntity() BHK_ENTITY_CONSTRUCT {}

bhkEntity::~bhkEntity() {}

void bhkEntity::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_ENTITY_READ
}

void bhkEntity::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_ENTITY_WRITE
}

string bhkEntity::asString( bool verbose ) const {
	BHK_ENTITY_STRING
}

void bhkEntity::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_ENTITY_FIXLINKS
}

list<NiObjectRef> bhkEntity::GetRefs() const {
	BHK_ENTITY_GETREFS
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

