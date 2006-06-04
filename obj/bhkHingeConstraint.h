/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKHINGECONSTRAINT_H_
#define _BHKHINGECONSTRAINT_H_

#include "AbhkConstraint.h"

#include "gen/obj_defines.h"

class bhkHingeConstraint;
typedef Ref<bhkHingeConstraint> bhkHingeConstraintRef;

/*!
 * bhkHingeConstraint - A hinge constraint.
 */

class bhkHingeConstraint : public BHK_HINGE_CONSTRAINT_PARENT {
public:
	bhkHingeConstraint();
	~bhkHingeConstraint();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_HINGE_CONSTRAINT_MEMBERS
};

#endif
