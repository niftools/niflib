/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABHKRAGDOLLCONSTRAINT_H_
#define _ABHKRAGDOLLCONSTRAINT_H_

#include "xml_extract.h"
#include ABHK_RAGDOLL_CONSTRAINT_INCLUDE

/*
 * AbhkRagdollConstraint
 */

class AbhkRagdollConstraint;
typedef Ref<AbhkRagdollConstraint> AbhkRagdollConstraintRef;

class AbhkRagdollConstraint : public ABHK_RAGDOLL_CONSTRAINT_PARENT {
public:
	AbhkRagdollConstraint();
	~AbhkRagdollConstraint();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	ABHK_RAGDOLL_CONSTRAINT_MEMBERS
};
#endif
