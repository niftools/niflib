/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSerializable.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSerializable::TYPE("bhkSerializable", &BHK_SERIALIZABLE_PARENT::TypeConst() );

bhkSerializable::bhkSerializable() BHK_SERIALIZABLE_CONSTRUCT {}

bhkSerializable::~bhkSerializable() {}

void bhkSerializable::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkSerializable::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkSerializable::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSerializable::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkSerializable::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSerializable::GetType() const {
	return TYPE;
};

const Type & bhkSerializable::TypeConst() {
	return TYPE;
}
