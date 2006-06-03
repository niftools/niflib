/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/BSBound.h"

//Definition of TYPE constant
const Type BSBound::TYPE("BSBound", &B_S_BOUND_PARENT::TYPE );

BSBound::BSBound() B_S_BOUND_CONSTRUCT {}

BSBound::~BSBound() {}

void BSBound::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
	B_S_BOUND_READ
}

void BSBound::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	B_S_BOUND_WRITE
}

string BSBound::asString( bool verbose ) const {
	B_S_BOUND_STRING
}

void BSBound::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
	B_S_BOUND_FIXLINKS
}

const Type & BSBound::GetType() const {
	return TYPE;
};

