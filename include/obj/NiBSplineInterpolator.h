/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIBSPLINEINTERPOLATOR_H_
#define _NIBSPLINEINTERPOLATOR_H_

#include "NiInterpolator.h"
namespace Niflib {

// Forward define of referenced NIF objects
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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the animation start time.
	 * \return The animation start time
	 */
	NIFLIB_API float GetStartTime() const;

	/*!
	 * Sets the animation start time.
	 * \param[in] value The new animation start time
	 */
	NIFLIB_API void SetStartTime( float value );

	/*!
	 * Retrieves the animation stop time.
	 * \return The animation stop time
	 */
	NIFLIB_API float GetStopTime() const;

	/*!
	 * Sets the animation stop time.
	 * \param[in] value The new animation stop time
	 */
	NIFLIB_API void SetStopTime( float value );

	/*!
	 * Gets the NiBSplineData used by this interpolator.
	 * \return the NiBSplineData used by this interpolator.
	 */
	NIFLIB_API Ref<NiBSplineData > GetSplineData() const;

	/*!
	 * Sets the NiBSplineData used by this interpolator.
	 * \param[in] value The NiBSplineData used by this interpolator.
	 */
	NIFLIB_API void SetSplineData( NiBSplineData * value );

	/*!
	 * Gets the NiBSplineBasisData used by this interpolator.
	 * \return the NiBSplineBasisData used by this interpolator.
	 */
	NIFLIB_API Ref<NiBSplineBasisData > GetBasisData() const;

	/*!
	 * Sets the SetBasisData used by this interpolator.
	 * \param[in] value The SetBasisData used by this interpolator.
	 */
	NIFLIB_API void SetBasisData( NiBSplineBasisData * value );

protected:

   // internal method for bspline calculation in child classes
   static void bspline(int n, int t, int l, float *control, float *output, int num_output);

protected:
	NI_B_SPLINE_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
