/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysGravityStrengthCtlr.h"
#include "../../include/obj/NiFloatData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysGravityStrengthCtlr::TYPE("NiPSysGravityStrengthCtlr", &NI_P_SYS_GRAVITY_STRENGTH_CTLR_PARENT::TypeConst() );

NiPSysGravityStrengthCtlr::NiPSysGravityStrengthCtlr() NI_P_SYS_GRAVITY_STRENGTH_CTLR_CONSTRUCT {}

NiPSysGravityStrengthCtlr::~NiPSysGravityStrengthCtlr() {}

void NiPSysGravityStrengthCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysGravityStrengthCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysGravityStrengthCtlr::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysGravityStrengthCtlr::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysGravityStrengthCtlr::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysGravityStrengthCtlr::GetType() const {
	return TYPE;
};

