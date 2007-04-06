/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/AbhkShapeCollection.h"
using namespace Niflib;

//Definition of TYPE constant
const Type AbhkShapeCollection::TYPE("AbhkShapeCollection", &ABHK_SHAPE_COLLECTION_PARENT::TypeConst() );

AbhkShapeCollection::AbhkShapeCollection() ABHK_SHAPE_COLLECTION_CONSTRUCT {}

AbhkShapeCollection::~AbhkShapeCollection() {}

void AbhkShapeCollection::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void AbhkShapeCollection::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string AbhkShapeCollection::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void AbhkShapeCollection::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> AbhkShapeCollection::GetRefs() const {
	return InternalGetRefs();
}

const Type & AbhkShapeCollection::GetType() const {
	return TYPE;
};

const Type & AbhkShapeCollection::TypeConst() {
	return TYPE;
}
