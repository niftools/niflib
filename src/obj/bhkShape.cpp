/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkShape::TYPE("bhkShape", &BHK_SHAPE_PARENT::TypeConst() );

bhkShape::bhkShape() BHK_SHAPE_CONSTRUCT {}

bhkShape::~bhkShape() {}

void bhkShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkShape::GetType() const {
	return TYPE;
};

