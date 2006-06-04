/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKLIMITEDHINGECONSTRAINT_H_
#define _BHKLIMITEDHINGECONSTRAINT_H_

#include "AbhkConstraint.h"
// Include structures
#include "gen/LimitedHingeDescriptor.h"

#include "gen/obj_defines.h"

/*
 * bhkLimitedHingeConstraint
 */

class bhkLimitedHingeConstraint;
typedef Ref<bhkLimitedHingeConstraint> bhkLimitedHingeConstraintRef;

class bhkLimitedHingeConstraint : public BHK_LIMITED_HINGE_CONSTRAINT_PARENT {
public:
	bhkLimitedHingeConstraint();
	~bhkLimitedHingeConstraint();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	BHK_LIMITED_HINGE_CONSTRAINT_MEMBERS
};

#endif
