/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkBoxShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBoxShape::TYPE("bhkBoxShape", &BHK_BOX_SHAPE_PARENT::TypeConst() );

bhkBoxShape::bhkBoxShape() BHK_BOX_SHAPE_CONSTRUCT {}

bhkBoxShape::~bhkBoxShape() {}

void bhkBoxShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkBoxShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkBoxShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkBoxShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkBoxShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkBoxShape::GetType() const {
	return TYPE;
};

Vector3 bhkBoxShape::GetDimensions() const {
	return dimensions;
}

void bhkBoxShape::SetDimensions(const Vector3 &value) {
	dimensions = value;
}

