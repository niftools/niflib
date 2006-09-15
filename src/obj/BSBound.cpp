/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "BSBound.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSBound::TYPE("BSBound", &B_S_BOUND_PARENT::TypeConst() );

BSBound::BSBound() B_S_BOUND_CONSTRUCT {}

BSBound::~BSBound() {}

void BSBound::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	B_S_BOUND_READ
}

void BSBound::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	B_S_BOUND_WRITE
}

string BSBound::asString( bool verbose ) const {
	B_S_BOUND_STRING
}

void BSBound::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	B_S_BOUND_FIXLINKS
}

list<NiObjectRef> BSBound::GetRefs() const {
	B_S_BOUND_GETREFS
}

const Type & BSBound::GetType() const {
	return TYPE;
};

Vector3 BSBound::GetCenter() const {
	return center;
}

void BSBound::SetCenter( const Vector3 & value ) {
	center = value;
}

Vector3 BSBound::GetDimensions() const {
	return dimensions;
}

void BSBound::SetDimensions( const Vector3 & value ) {
	dimensions = value;
}

