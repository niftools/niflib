/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiSequenceStreamHelper.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSequenceStreamHelper::TYPE("NiSequenceStreamHelper", &NI_SEQUENCE_STREAM_HELPER_PARENT::TypeConst() );

NiSequenceStreamHelper::NiSequenceStreamHelper() NI_SEQUENCE_STREAM_HELPER_CONSTRUCT {}

NiSequenceStreamHelper::~NiSequenceStreamHelper() {}

void NiSequenceStreamHelper::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiSequenceStreamHelper::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiSequenceStreamHelper::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiSequenceStreamHelper::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiSequenceStreamHelper::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiSequenceStreamHelper::GetType() const {
	return TYPE;
};

const Type & NiSequenceStreamHelper::TypeConst() {
	return TYPE;
}
