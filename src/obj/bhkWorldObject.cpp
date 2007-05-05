/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkWorldObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkWorldObject::TYPE("bhkWorldObject", &BHK_WORLD_OBJECT_PARENT::TYPE );

bhkWorldObject::bhkWorldObject() BHK_WORLD_OBJECT_CONSTRUCT {}

bhkWorldObject::~bhkWorldObject() {}

void bhkWorldObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkWorldObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkWorldObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkWorldObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkWorldObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkWorldObject::GetType() const {
	return TYPE;
};
