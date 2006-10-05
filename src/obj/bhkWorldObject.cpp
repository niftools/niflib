/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkWorldObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkWorldObject::TYPE("bhkWorldObject", &BHK_WORLD_OBJECT_PARENT::TypeConst() );

bhkWorldObject::bhkWorldObject() BHK_WORLD_OBJECT_CONSTRUCT {}

bhkWorldObject::~bhkWorldObject() {}

void bhkWorldObject::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkWorldObject::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkWorldObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkWorldObject::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkWorldObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkWorldObject::GetType() const {
	return TYPE;
};

