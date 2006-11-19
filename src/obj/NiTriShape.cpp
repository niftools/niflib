/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTriShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTriShape::TYPE("NiTriShape", &NI_TRI_SHAPE_PARENT::TypeConst() );

NiTriShape::NiTriShape() NI_TRI_SHAPE_CONSTRUCT {}

NiTriShape::~NiTriShape() {}

void NiTriShape::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTriShape::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTriShape::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTriShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTriShape::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTriShape::GetType() const {
	return TYPE;
};

