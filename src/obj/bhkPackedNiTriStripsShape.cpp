/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkPackedNiTriStripsShape.h"
#include "../../include/obj/hkPackedNiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPackedNiTriStripsShape::TYPE("bhkPackedNiTriStripsShape", &BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT::TypeConst() );

bhkPackedNiTriStripsShape::bhkPackedNiTriStripsShape() BHK_PACKED_NI_TRI_STRIPS_SHAPE_CONSTRUCT {}

bhkPackedNiTriStripsShape::~bhkPackedNiTriStripsShape() {}

void bhkPackedNiTriStripsShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkPackedNiTriStripsShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkPackedNiTriStripsShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkPackedNiTriStripsShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkPackedNiTriStripsShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkPackedNiTriStripsShape::GetType() const {
	return TYPE;
};

const Type & bhkPackedNiTriStripsShape::TypeConst() {
	return TYPE;
}
