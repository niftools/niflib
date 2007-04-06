/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTransformData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTransformData::TYPE("NiTransformData", &NI_TRANSFORM_DATA_PARENT::TypeConst() );

NiTransformData::NiTransformData() NI_TRANSFORM_DATA_CONSTRUCT {}

NiTransformData::~NiTransformData() {}

void NiTransformData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTransformData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTransformData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTransformData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTransformData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTransformData::GetType() const {
	return TYPE;
};

const Type & NiTransformData::TypeConst() {
	return TYPE;
}
