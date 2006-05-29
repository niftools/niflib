/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "BSXFlags.h"

//Definition of TYPE constant
const Type BSXFlags::TYPE("BSXFlags", &B_S_X_FLAGS_PARENT::TYPE );

BSXFlags::BSXFlags() B_S_X_FLAGS_CONSTRUCT {}

BSXFlags::~BSXFlags() {}

void BSXFlags::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	B_S_X_FLAGS_READ
}

void BSXFlags::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	B_S_X_FLAGS_WRITE
}

string BSXFlags::asString( bool verbose ) const {
	B_S_X_FLAGS_STRING
}

void BSXFlags::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	B_S_X_FLAGS_FIXLINKS
}

