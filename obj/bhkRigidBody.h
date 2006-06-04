/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKRIGIDBODY_H_
#define _BHKRIGIDBODY_H_

#include "bhkEntity.h"
// Include structures
#include "gen/QuaternionXYZW.h"

// Forward define of referenced blocks
#include "Ref.h"
class AbhkConstraint;

#include "gen/obj_defines.h"

/*
 * bhkRigidBody
 */

class bhkRigidBody;
typedef Ref<bhkRigidBody> bhkRigidBodyRef;

class bhkRigidBody : public BHK_RIGID_BODY_PARENT {
public:
	bhkRigidBody();
	~bhkRigidBody();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	BHK_RIGID_BODY_MEMBERS
};

#endif
