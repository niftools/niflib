/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSXFlags.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSXFlags::TYPE("BSXFlags", &B_S_X_FLAGS_PARENT::TYPE );

BSXFlags::BSXFlags() B_S_X_FLAGS_CONSTRUCT {}

BSXFlags::~BSXFlags() {}

void BSXFlags::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void BSXFlags::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string BSXFlags::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSXFlags::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> BSXFlags::GetRefs() const {
	return InternalGetRefs();
}

const Type & BSXFlags::GetType() const {
	return TYPE;
};

unsigned int BSXFlags::GetFlags() const {
	return flags;
}

void BSXFlags::SetFlags( unsigned int value ) {
	flags = value;
}
