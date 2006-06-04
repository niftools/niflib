/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKMALLEABLECONSTRAINT_H_
#define _BHKMALLEABLECONSTRAINT_H_

#include "AbhkConstraint.h"
// Include structures
#include "gen/RagDollDescriptor.h"
#include "gen/LimitedHingeDescriptor.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiObject;

#include "gen/obj_defines.h"

/*
 * bhkMalleableConstraint
 */

class bhkMalleableConstraint;
typedef Ref<bhkMalleableConstraint> bhkMalleableConstraintRef;

class bhkMalleableConstraint : public BHK_MALLEABLE_CONSTRAINT_PARENT {
public:
	bhkMalleableConstraint();
	~bhkMalleableConstraint();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_MALLEABLE_CONSTRAINT_MEMBERS
};

#endif
