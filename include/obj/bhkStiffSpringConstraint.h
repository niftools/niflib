/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSTIFFSPRINGCONSTRAINT_H_
#define _BHKSTIFFSPRINGCONSTRAINT_H_

#include "AbhkConstraint.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class bhkStiffSpringConstraint;
typedef Ref<bhkStiffSpringConstraint> bhkStiffSpringConstraintRef;

/*!
 * bhkStiffSpringConstraint - A spring constraint.
 */

class bhkStiffSpringConstraint : public BHK_STIFF_SPRING_CONSTRAINT_PARENT {
public:
	NIFLIB_API bhkStiffSpringConstraint();
	NIFLIB_API ~bhkStiffSpringConstraint();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

protected:
	BHK_STIFF_SPRING_CONSTRAINT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
