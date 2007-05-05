/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkRigidBodyT.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRigidBodyT::TYPE("bhkRigidBodyT", &BHK_RIGID_BODY_T_PARENT::TYPE );

bhkRigidBodyT::bhkRigidBodyT() BHK_RIGID_BODY_T_CONSTRUCT {}

bhkRigidBodyT::~bhkRigidBodyT() {}

void bhkRigidBodyT::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalRead( in, link_stack, info );
}

void bhkRigidBodyT::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	InternalWrite( out, link_map, info );
}

string bhkRigidBodyT::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkRigidBodyT::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	InternalFixLinks( objects, link_stack, info );
}

list<NiObjectRef> bhkRigidBodyT::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkRigidBodyT::GetType() const {
	return TYPE;
};
