/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkRigidBodyT.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRigidBodyT::TYPE("bhkRigidBodyT", &BHK_RIGID_BODY_T_PARENT::TypeConst() );

bhkRigidBodyT::bhkRigidBodyT() BHK_RIGID_BODY_T_CONSTRUCT {}

bhkRigidBodyT::~bhkRigidBodyT() {}

void bhkRigidBodyT::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void bhkRigidBodyT::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string bhkRigidBodyT::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void bhkRigidBodyT::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> bhkRigidBodyT::GetRefs() const {
	return InternalGetRefs();
}

const Type & bhkRigidBodyT::GetType() const {
	return TYPE;
};

