/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiClod.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiClod::TYPE("NiClod", &NI_CLOD_PARENT::TypeConst() );

NiClod::NiClod() NI_CLOD_CONSTRUCT {}

NiClod::~NiClod() {}

void NiClod::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CLOD_READ
}

void NiClod::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_CLOD_WRITE
}

string NiClod::asString( bool verbose ) const {
	NI_CLOD_STRING
}

void NiClod::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_CLOD_FIXLINKS
}

list<NiObjectRef> NiClod::GetRefs() const {
	NI_CLOD_GETREFS
}

const Type & NiClod::GetType() const {
	return TYPE;
};

