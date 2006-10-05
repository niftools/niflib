/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendInterpolator::TYPE("NiBlendInterpolator", &NI_BLEND_INTERPOLATOR_PARENT::TypeConst() );

NiBlendInterpolator::NiBlendInterpolator() NI_BLEND_INTERPOLATOR_CONSTRUCT {}

NiBlendInterpolator::~NiBlendInterpolator() {}

void NiBlendInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBlendInterpolator::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBlendInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendInterpolator::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBlendInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendInterpolator::GetType() const {
	return TYPE;
};

