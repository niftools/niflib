/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "APSysCtlr.h"
using namespace Niflib;

//Definition of TYPE constant
const Type APSysCtlr::TYPE("APSysCtlr", &A_P_SYS_CTLR_PARENT::TypeConst() );

APSysCtlr::APSysCtlr() A_P_SYS_CTLR_CONSTRUCT {}

APSysCtlr::~APSysCtlr() {}

void APSysCtlr::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	A_P_SYS_CTLR_READ
}

void APSysCtlr::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	A_P_SYS_CTLR_WRITE
}

string APSysCtlr::asString( bool verbose ) const {
	A_P_SYS_CTLR_STRING
}

void APSysCtlr::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	A_P_SYS_CTLR_FIXLINKS
}

list<NiObjectRef> APSysCtlr::GetRefs() const {
	A_P_SYS_CTLR_GETREFS
}

const Type & APSysCtlr::GetType() const {
	return TYPE;
};

