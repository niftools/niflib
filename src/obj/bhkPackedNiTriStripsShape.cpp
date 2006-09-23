/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkPackedNiTriStripsShape.h"
#include "../../include/obj/hkPackedNiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPackedNiTriStripsShape::TYPE("bhkPackedNiTriStripsShape", &BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT::TypeConst() );

bhkPackedNiTriStripsShape::bhkPackedNiTriStripsShape() BHK_PACKED_NI_TRI_STRIPS_SHAPE_CONSTRUCT {}

bhkPackedNiTriStripsShape::~bhkPackedNiTriStripsShape() {}

void bhkPackedNiTriStripsShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkPackedNiTriStripsShape::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkPackedNiTriStripsShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkPackedNiTriStripsShape::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkPackedNiTriStripsShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkPackedNiTriStripsShape::GetType() const {
	return TYPE;
};

