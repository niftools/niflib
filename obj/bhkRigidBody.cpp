/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "obj/bhkRigidBody.h"
#include "gen/QuaternionXYZW.h"

//Definition of TYPE constant
const Type bhkRigidBody::TYPE("bhkRigidBody", &BHK_RIGID_BODY_PARENT::TYPE );

bhkRigidBody::bhkRigidBody() BHK_RIGID_BODY_CONSTRUCT {}

bhkRigidBody::~bhkRigidBody() {}

void bhkRigidBody::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  BHK_RIGID_BODY_READ
}

void bhkRigidBody::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  BHK_RIGID_BODY_WRITE
}

string bhkRigidBody::asString( bool verbose ) const {
  BHK_RIGID_BODY_STRING
}

void bhkRigidBody::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  BHK_RIGID_BODY_FIXLINKS
}

const Type & bhkRigidBody::GetType() const {
  return TYPE;
};

