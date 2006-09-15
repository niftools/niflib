/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSequenceStreamHelper.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSequenceStreamHelper::TYPE("NiSequenceStreamHelper", &NI_SEQUENCE_STREAM_HELPER_PARENT::TypeConst() );

NiSequenceStreamHelper::NiSequenceStreamHelper() NI_SEQUENCE_STREAM_HELPER_CONSTRUCT {}

NiSequenceStreamHelper::~NiSequenceStreamHelper() {}

void NiSequenceStreamHelper::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SEQUENCE_STREAM_HELPER_READ
}

void NiSequenceStreamHelper::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_SEQUENCE_STREAM_HELPER_WRITE
}

string NiSequenceStreamHelper::asString( bool verbose ) const {
	NI_SEQUENCE_STREAM_HELPER_STRING
}

void NiSequenceStreamHelper::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_SEQUENCE_STREAM_HELPER_FIXLINKS
}

list<NiObjectRef> NiSequenceStreamHelper::GetRefs() const {
	NI_SEQUENCE_STREAM_HELPER_GETREFS
}

const Type & NiSequenceStreamHelper::GetType() const {
	return TYPE;
};

