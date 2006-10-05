/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINEINTERPOLATOR_H_
#define _NIBSPLINEINTERPOLATOR_H_

#include "NiInterpolator.h"
namespace Niflib {

// Forward define of referenced blocks
class NiBSplineData;
class NiBSplineBasisData;

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
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
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

	/*!
	 * Refers to NiBSplineData.
	 */
	Ref<NiBSplineData > GetSplineData() const;
	void SetSplineData( Ref<NiBSplineData > value );

	/*!
	 * Refers to NiBSPlineBasisData.
	 */
	Ref<NiBSplineBasisData > GetBasisData() const;
	void SetBasisData( Ref<NiBSplineBasisData > value );

protected:

   // internal method for bspline calculation in child classes
   static void bspline(int n, int t, int l, float *control, float *output, int num_output);

protected:
	NI_B_SPLINE_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
