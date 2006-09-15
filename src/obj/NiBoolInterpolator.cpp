/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBoolInterpolator.h"
#include "../../include/obj/NiBoolData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBoolInterpolator::TYPE("NiBoolInterpolator", &NI_BOOL_INTERPOLATOR_PARENT::TypeConst() );

NiBoolInterpolator::NiBoolInterpolator() NI_BOOL_INTERPOLATOR_CONSTRUCT {}

NiBoolInterpolator::~NiBoolInterpolator() {}

void NiBoolInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BOOL_INTERPOLATOR_READ
}

void NiBoolInterpolator::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_BOOL_INTERPOLATOR_WRITE
}

string NiBoolInterpolator::asString( bool verbose ) const {
	NI_BOOL_INTERPOLATOR_STRING
}

void NiBoolInterpolator::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_BOOL_INTERPOLATOR_FIXLINKS
}

list<NiObjectRef> NiBoolInterpolator::GetRefs() const {
	NI_BOOL_INTERPOLATOR_GETREFS
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

void NiBoolInterpolator::SetData( Ref<NiBoolData > value ) {
	data = value;
}

