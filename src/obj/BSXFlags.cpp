/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSXFlags.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSXFlags::TYPE("BSXFlags", &B_S_X_FLAGS_PARENT::TypeConst() );

BSXFlags::BSXFlags() B_S_X_FLAGS_CONSTRUCT {}

BSXFlags::~BSXFlags() {}

void BSXFlags::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void BSXFlags::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string BSXFlags::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSXFlags::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> BSXFlags::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSXFlags::GetType() const {
	return TYPE;
};

uint BSXFlags::GetFlags() const {
	return flags;
}

void BSXFlags::SetFlags( uint value ) {
	flags = value;
}

