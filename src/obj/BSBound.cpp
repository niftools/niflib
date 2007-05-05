/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/BSBound.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSBound::TYPE("BSBound", &B_S_BOUND_PARENT::TYPE );

BSBound::BSBound() B_S_BOUND_CONSTRUCT {}

BSBound::~BSBound() {}

void BSBound::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void BSBound::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string BSBound::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void BSBound::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> BSBound::GetRefs() const {
	return InternalGetRefs();
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
