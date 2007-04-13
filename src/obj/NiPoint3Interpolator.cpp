/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPoint3Interpolator.h"
#include "../../include/obj/NiPosData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPoint3Interpolator::TYPE("NiPoint3Interpolator", &NI_POINT3_INTERPOLATOR_PARENT::TypeConst() );

NiPoint3Interpolator::NiPoint3Interpolator() NI_POINT3_INTERPOLATOR_CONSTRUCT {}

NiPoint3Interpolator::~NiPoint3Interpolator() {}

void NiPoint3Interpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPoint3Interpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPoint3Interpolator::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPoint3Interpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPoint3Interpolator::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPoint3Interpolator::GetType() const {
	return TYPE;
};

Vector3 NiPoint3Interpolator::GetPoint3Value() const {
	return point3Value;
}

void NiPoint3Interpolator::SetPoint3Value( Vector3 value ) {
	point3Value = value;
}

Ref<NiPosData > NiPoint3Interpolator::GetData() const {
	return data;
}

void NiPoint3Interpolator::SetData( NiPosData * value ) {
	data = value;
}

const Type & NiPoint3Interpolator::TypeConst() {
	return TYPE;
}
