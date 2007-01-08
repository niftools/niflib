/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiPSysCylinderEmitter.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysCylinderEmitter::TYPE("NiPSysCylinderEmitter", &NI_P_SYS_CYLINDER_EMITTER_PARENT::TypeConst() );

NiPSysCylinderEmitter::NiPSysCylinderEmitter() NI_P_SYS_CYLINDER_EMITTER_CONSTRUCT {}

NiPSysCylinderEmitter::~NiPSysCylinderEmitter() {}

void NiPSysCylinderEmitter::Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiPSysCylinderEmitter::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiPSysCylinderEmitter::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiPSysCylinderEmitter::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiPSysCylinderEmitter::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiPSysCylinderEmitter::GetType() const {
	return TYPE;
};

