/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABHKRAGDOLLCONSTRAINT_H_
#define _ABHKRAGDOLLCONSTRAINT_H_

#include "AbhkConstraint.h"

#include "gen/obj_defines.h"

class AbhkRagdollConstraint;
typedef Ref<AbhkRagdollConstraint> AbhkRagdollConstraintRef;

/*!
 * AbhkRagdollConstraint - Ragdoll constraint.
 */

class AbhkRagdollConstraint : public ABHK_RAGDOLL_CONSTRAINT_PARENT {
public:
	AbhkRagdollConstraint();
	~AbhkRagdollConstraint();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	ABHK_RAGDOLL_CONSTRAINT_MEMBERS
};

#endif
