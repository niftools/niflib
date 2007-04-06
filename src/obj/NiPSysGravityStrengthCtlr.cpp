/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysGravityStrengthCtlr.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysGravityStrengthCtlr::TYPE("NiPSysGravityStrengthCtlr", &NI_P_SYS_GRAVITY_STRENGTH_CTLR_PARENT::TypeConst() );

NiPSysGravityStrengthCtlr::NiPSysGravityStrengthCtlr() NI_P_SYS_GRAVITY_STRENGTH_CTLR_CONSTRUCT {}

NiPSysGravityStrengthCtlr::~NiPSysGravityStrengthCtlr() {}

void NiPSysGravityStrengthCtlr::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiPSysGravityStrengthCtlr::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiPSysGravityStrengthCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysGravityStrengthCtlr::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiPSysGravityStrengthCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysGravityStrengthCtlr::GetType() const {
	return TYPE;
};

const Type & NiPSysGravityStrengthCtlr::TypeConst() {
	return TYPE;
}
