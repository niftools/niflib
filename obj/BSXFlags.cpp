/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "BSXFlags.h"

//Definition of TYPE constant
const Type BSXFlags::TYPE("BSXFlags", &B_S_X_FLAGS_PARENT::TypeConst() );

BSXFlags::BSXFlags() B_S_X_FLAGS_CONSTRUCT {}

BSXFlags::~BSXFlags() {}

void BSXFlags::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	B_S_X_FLAGS_READ
}

void BSXFlags::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	B_S_X_FLAGS_WRITE
}

string BSXFlags::asString( bool verbose ) const {
	B_S_X_FLAGS_STRING
}

void BSXFlags::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	B_S_X_FLAGS_FIXLINKS
}

list<NiObjectRef> BSXFlags::GetRefs() const {
	B_S_X_FLAGS_GETREFS
}

const Type & BSXFlags::GetType() const {
	return TYPE;
};

uint BSXFlags::GetFlags() const {
	return flags;
};

void BSXFlags::SetFlags( uint n ) {
	flags = n;
};
