/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINEINTERPOLATOR_H_
#define _NIBSPLINEINTERPOLATOR_H_

#include "NiInterpolator.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiBSplineInterpolator;
typedef Ref<NiBSplineInterpolator> NiBSplineInterpolatorRef;

/*!
 * NiBSplineInterpolator - A B-spline (component?) interpolator.
 */

class NIFLIB_API NiBSplineInterpolator : public NI_B_SPLINE_INTERPOLATOR_PARENT {
public:
	NiBSplineInterpolator();
	~NiBSplineInterpolator();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Animation start time.
	 */
	float GetStartTime() const;
	void SetStartTime( float value );

	/*!
	 * Animation stop time.
	 */
	float GetStopTime() const;
	void SetStopTime( float value );

protected:
	NI_B_SPLINE_INTERPOLATOR_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
