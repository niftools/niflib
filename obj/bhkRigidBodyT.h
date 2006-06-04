/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKRIGIDBODYT_H_
#define _BHKRIGIDBODYT_H_

#include "bhkRigidBody.h"

#include "gen/obj_defines.h"

/*
 * bhkRigidBodyT
 */

class bhkRigidBodyT;
typedef Ref<bhkRigidBodyT> bhkRigidBodyTRef;

class bhkRigidBodyT : public BHK_RIGID_BODY_T_PARENT {
public:
	bhkRigidBodyT();
	~bhkRigidBodyT();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_RIGID_BODY_T_MEMBERS
};

#endif
