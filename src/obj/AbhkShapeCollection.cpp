/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AbhkShapeCollection.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AbhkShapeCollection::TYPE("AbhkShapeCollection", &ABHK_SHAPE_COLLECTION_PARENT::TypeConst() );

AbhkShapeCollection::AbhkShapeCollection() ABHK_SHAPE_COLLECTION_CONSTRUCT {}

AbhkShapeCollection::~AbhkShapeCollection() {}

void AbhkShapeCollection::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void AbhkShapeCollection::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string AbhkShapeCollection::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AbhkShapeCollection::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> AbhkShapeCollection::GetRefs() const {
	return InternalGetRefs();
}

const Type & AbhkShapeCollection::GetType() const {
	return TYPE;
};

