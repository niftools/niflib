/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiInterpolator::TYPE("NiInterpolator", &NI_INTERPOLATOR_PARENT::TypeConst() );

NiInterpolator::NiInterpolator() NI_INTERPOLATOR_CONSTRUCT {}

NiInterpolator::~NiInterpolator() {}

void NiInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiInterpolator::GetType() const {
	return TYPE;
};

const Type & NiInterpolator::TypeConst() {
	return TYPE;
}
