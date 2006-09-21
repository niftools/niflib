/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKHINGECONSTRAINT_H_
#define _BHKHINGECONSTRAINT_H_

#include "AbhkConstraint.h"
namespace Niflib {

#include "../gen/obj_defines.h"

class bhkHingeConstraint;
typedef Ref<bhkHingeConstraint> bhkHingeConstraintRef;

/*!
 * bhkHingeConstraint - A hinge constraint.
 */

class NIFLIB_API bhkHingeConstraint : public BHK_HINGE_CONSTRAINT_PARENT {
public:
	bhkHingeConstraint();
	~bhkHingeConstraint();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	BHK_HINGE_CONSTRAINT_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
