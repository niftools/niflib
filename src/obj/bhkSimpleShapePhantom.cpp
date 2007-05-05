/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkSimpleShapePhantom.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSimpleShapePhantom::TYPE("bhkSimpleShapePhantom", &BHK_SIMPLE_SHAPE_PHANTOM_PARENT::TYPE );

bhkSimpleShapePhantom::bhkSimpleShapePhantom() BHK_SIMPLE_SHAPE_PHANTOM_CONSTRUCT {}

bhkSimpleShapePhantom::~bhkSimpleShapePhantom() {}

void bhkSimpleShapePhantom::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkSimpleShapePhantom::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkSimpleShapePhantom::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkSimpleShapePhantom::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkSimpleShapePhantom::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkSimpleShapePhantom::GetType() const {
	return TYPE;
};
