/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINEINTERPOLATOR_H_
#define _NIBSPLINEINTERPOLATOR_H_

#include "NiInterpolator.h"
namespace Niflib {

// Forward define of referenced blocks
class NiBSplineData;
class NiBSplineBasisData;

//#include "../gen/obj_defines.h"

class NiBSplineInterpolator;
typedef Ref<NiBSplineInterpolator> NiBSplineInterpolatorRef;

/*!
 * NiBSplineInterpolator - A B-spline (component?) interpolator.
 */

class NiBSplineInterpolator : public NI_B_SPLINE_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiBSplineInterpolator();
	NIFLIB_API ~NiBSplineInterpolator();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Animation start time.
	 */
	NIFLIB_API float GetStartTime() const;
	NIFLIB_API void SetStartTime( float value );

	/*!
	 * Animation stop time.
	 */
	NIFLIB_API float GetStopTime() const;
	NIFLIB_API void SetStopTime( float value );

	/*!
	 * Refers to NiBSplineData.
	 */
	NIFLIB_API Ref<NiBSplineData > GetSplineData() const;
	NIFLIB_API void SetSplineData( Ref<NiBSplineData > value );

	/*!
	 * Refers to NiBSPlineBasisData.
	 */
	NIFLIB_API Ref<NiBSplineBasisData > GetBasisData() const;
	NIFLIB_API void SetBasisData( Ref<NiBSplineBasisData > value );

protected:

   // internal method for bspline calculation in child classes
   static void bspline(int n, int t, int l, float *control, float *output, int num_output);

protected:
	NI_B_SPLINE_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
