/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTriShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTriShape::TYPE("NiTriShape", &NI_TRI_SHAPE_PARENT::TYPE );

NiTriShape::NiTriShape() NI_TRI_SHAPE_CONSTRUCT {}

NiTriShape::~NiTriShape() {}

void NiTriShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void NiTriShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string NiTriShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTriShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> NiTriShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTriShape::GetType() const {
	return TYPE;
};
