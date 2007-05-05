/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBlendInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendInterpolator::TYPE("NiBlendInterpolator", &NI_BLEND_INTERPOLATOR_PARENT::TYPE );

NiBlendInterpolator::NiBlendInterpolator() NI_BLEND_INTERPOLATOR_CONSTRUCT {}

NiBlendInterpolator::~NiBlendInterpolator() {}

void NiBlendInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBlendInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBlendInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBlendInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBlendInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBlendInterpolator::GetType() const {
	return TYPE;
};
