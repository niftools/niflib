/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NiPSysGravityStrengthCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysGravityStrengthCtlr::TYPE("NiPSysGravityStrengthCtlr", &NI_P_SYS_GRAVITY_STRENGTH_CTLR_PARENT::TypeConst() );

NiPSysGravityStrengthCtlr::NiPSysGravityStrengthCtlr() NI_P_SYS_GRAVITY_STRENGTH_CTLR_CONSTRUCT {}

NiPSysGravityStrengthCtlr::~NiPSysGravityStrengthCtlr() {}

void NiPSysGravityStrengthCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_GRAVITY_STRENGTH_CTLR_READ
}

void NiPSysGravityStrengthCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_P_SYS_GRAVITY_STRENGTH_CTLR_WRITE
}

string NiPSysGravityStrengthCtlr::asString( bool verbose ) const {
	NI_P_SYS_GRAVITY_STRENGTH_CTLR_STRING
}

void NiPSysGravityStrengthCtlr::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_P_SYS_GRAVITY_STRENGTH_CTLR_FIXLINKS
}

list<NiObjectRef> NiPSysGravityStrengthCtlr::GetRefs() const {
	NI_P_SYS_GRAVITY_STRENGTH_CTLR_GETREFS
}

const Type & NiPSysGravityStrengthCtlr::GetType() const {
	return TYPE;
};

