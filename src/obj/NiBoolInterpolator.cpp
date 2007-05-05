/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBoolInterpolator.h"
#include "../../include/obj/NiBoolData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBoolInterpolator::TYPE("NiBoolInterpolator", &NI_BOOL_INTERPOLATOR_PARENT::TYPE );

NiBoolInterpolator::NiBoolInterpolator() NI_BOOL_INTERPOLATOR_CONSTRUCT {}

NiBoolInterpolator::~NiBoolInterpolator() {}

void NiBoolInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiBoolInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiBoolInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBoolInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiBoolInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBoolInterpolator::GetType() const {
	return TYPE;
};

bool NiBoolInterpolator::GetBoolValue() const {
	return boolValue;
}

void NiBoolInterpolator::SetBoolValue( bool value ) {
	boolValue = value;
}

Ref<NiBoolData > NiBoolInterpolator::GetData() const {
	return data;
}

void NiBoolInterpolator::SetData( NiBoolData * value ) {
	data = value;
}
