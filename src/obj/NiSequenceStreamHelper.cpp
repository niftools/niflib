/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSequenceStreamHelper.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSequenceStreamHelper::TYPE("NiSequenceStreamHelper", &NI_SEQUENCE_STREAM_HELPER_PARENT::TypeConst() );

NiSequenceStreamHelper::NiSequenceStreamHelper() NI_SEQUENCE_STREAM_HELPER_CONSTRUCT {}

NiSequenceStreamHelper::~NiSequenceStreamHelper() {}

void NiSequenceStreamHelper::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiSequenceStreamHelper::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiSequenceStreamHelper::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSequenceStreamHelper::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiSequenceStreamHelper::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSequenceStreamHelper::GetType() const {
	return TYPE;
};

