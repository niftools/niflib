/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINECOMPPOINT3INTERPOLATOR_H_
#define _NIBSPLINECOMPPOINT3INTERPOLATOR_H_

#include "NiBSplineInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiBSplineCompPoint3Interpolator;
typedef Ref<NiBSplineCompPoint3Interpolator> NiBSplineCompPoint3InterpolatorRef;

/*!
 * NiBSplineCompPoint3Interpolator - Unknown.
 */

class NiBSplineCompPoint3Interpolator : public NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiBSplineCompPoint3Interpolator();
	NIFLIB_API ~NiBSplineCompPoint3Interpolator();
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
	NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
