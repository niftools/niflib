/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiLightColorController.h"
#include "NiPosData.h"
#include "NiPoint3Interpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiLightColorController::TYPE("NiLightColorController", &NI_LIGHT_COLOR_CONTROLLER_PARENT::TypeConst() );

NiLightColorController::NiLightColorController() NI_LIGHT_COLOR_CONTROLLER_CONSTRUCT {}

NiLightColorController::~NiLightColorController() {}

void NiLightColorController::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_LIGHT_COLOR_CONTROLLER_READ
}

void NiLightColorController::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_LIGHT_COLOR_CONTROLLER_WRITE
}

string NiLightColorController::asString( bool verbose ) const {
	NI_LIGHT_COLOR_CONTROLLER_STRING
}

void NiLightColorController::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_LIGHT_COLOR_CONTROLLER_FIXLINKS
}

list<NiObjectRef> NiLightColorController::GetRefs() const {
	NI_LIGHT_COLOR_CONTROLLER_GETREFS
}

const Type & NiLightColorController::GetType() const {
	return TYPE;
};

Ref<NiPosData > NiLightColorController::GetData() const {
	return data;
}

void NiLightColorController::SetData( Ref<NiPosData > value ) {
	data = value;
}

Ref<NiPoint3Interpolator > NiLightColorController::GetInterpolator() const {
	return interpolator;
}

void NiLightColorController::SetInterpolator( Ref<NiPoint3Interpolator > value ) {
	interpolator = value;
}

