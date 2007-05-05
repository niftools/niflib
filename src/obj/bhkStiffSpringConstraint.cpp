/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkStiffSpringConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkStiffSpringConstraint::TYPE("bhkStiffSpringConstraint", &BHK_STIFF_SPRING_CONSTRAINT_PARENT::TYPE );

bhkStiffSpringConstraint::bhkStiffSpringConstraint() BHK_STIFF_SPRING_CONSTRAINT_CONSTRUCT {}

bhkStiffSpringConstraint::~bhkStiffSpringConstraint() {}

void bhkStiffSpringConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkStiffSpringConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkStiffSpringConstraint::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkStiffSpringConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkStiffSpringConstraint::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkStiffSpringConstraint::GetType() const {
	return TYPE;
};
