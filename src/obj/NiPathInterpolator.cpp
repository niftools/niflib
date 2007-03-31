/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPathInterpolator.h"
#include "../../include/obj/NiPosData.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPathInterpolator::TYPE("NiPathInterpolator", &NI_PATH_INTERPOLATOR_PARENT::TypeConst() );

NiPathInterpolator::NiPathInterpolator() NI_PATH_INTERPOLATOR_CONSTRUCT {}

NiPathInterpolator::~NiPathInterpolator() {}

void NiPathInterpolator::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPathInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPathInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPathInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPathInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPathInterpolator::GetType() const {
	return TYPE;
};

Ref<NiPosData > NiPathInterpolator::GetPosData() const {
	return posData;
}

void NiPathInterpolator::SetPosData( Ref<NiPosData > value ) {
	posData = value;
}

Ref<NiFloatData > NiPathInterpolator::GetFloatData() const {
	return floatData;
}

void NiPathInterpolator::SetFloatData( Ref<NiFloatData > value ) {
	floatData = value;
}

const Type & NiPathInterpolator::TypeConst() {
	return TYPE;
}
