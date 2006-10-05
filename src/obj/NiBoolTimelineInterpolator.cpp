/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiBoolTimelineInterpolator.h"
#include "../../include/obj/NiBoolData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBoolTimelineInterpolator::TYPE("NiBoolTimelineInterpolator", &NI_BOOL_TIMELINE_INTERPOLATOR_PARENT::TypeConst() );

NiBoolTimelineInterpolator::NiBoolTimelineInterpolator() NI_BOOL_TIMELINE_INTERPOLATOR_CONSTRUCT {}

NiBoolTimelineInterpolator::~NiBoolTimelineInterpolator() {}

void NiBoolTimelineInterpolator::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiBoolTimelineInterpolator::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiBoolTimelineInterpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiBoolTimelineInterpolator::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiBoolTimelineInterpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiBoolTimelineInterpolator::GetType() const {
	return TYPE;
};

byte NiBoolTimelineInterpolator::GetBoolValue() const {
	return boolValue;
}

void NiBoolTimelineInterpolator::SetBoolValue( byte value ) {
	boolValue = value;
}

Ref<NiBoolData > NiBoolTimelineInterpolator::GetData() const {
	return data;
}

void NiBoolTimelineInterpolator::SetData( Ref<NiBoolData > value ) {
	data = value;
}

