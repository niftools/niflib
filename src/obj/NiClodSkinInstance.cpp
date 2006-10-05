/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiClodSkinInstance.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiClodSkinInstance::TYPE("NiClodSkinInstance", &NI_CLOD_SKIN_INSTANCE_PARENT::TypeConst() );

NiClodSkinInstance::NiClodSkinInstance() NI_CLOD_SKIN_INSTANCE_CONSTRUCT {}

NiClodSkinInstance::~NiClodSkinInstance() {}

void NiClodSkinInstance::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiClodSkinInstance::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiClodSkinInstance::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiClodSkinInstance::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiClodSkinInstance::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiClodSkinInstance::GetType() const {
	return TYPE;
};

