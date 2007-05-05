/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkRefObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRefObject::TYPE("bhkRefObject", &BHK_REF_OBJECT_PARENT::TYPE );

bhkRefObject::bhkRefObject() BHK_REF_OBJECT_CONSTRUCT {}

bhkRefObject::~bhkRefObject() {}

void bhkRefObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkRefObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkRefObject::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkRefObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkRefObject::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkRefObject::GetType() const {
	return TYPE;
};
