/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/bhkRigidBodyT.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRigidBodyT::TYPE("bhkRigidBodyT", &BHK_RIGID_BODY_T_PARENT::TypeConst() );

bhkRigidBodyT::bhkRigidBodyT() BHK_RIGID_BODY_T_CONSTRUCT {}

bhkRigidBodyT::~bhkRigidBodyT() {}

void bhkRigidBodyT::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_RIGID_BODY_T_READ
}

void bhkRigidBodyT::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	BHK_RIGID_BODY_T_WRITE
}

string bhkRigidBodyT::asString( bool verbose ) const {
	BHK_RIGID_BODY_T_STRING
}

void bhkRigidBodyT::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	BHK_RIGID_BODY_T_FIXLINKS
}

list<NiObjectRef> bhkRigidBodyT::GetRefs() const {
	BHK_RIGID_BODY_T_GETREFS
}

const Type & bhkRigidBodyT::GetType() const {
	return TYPE;
};

