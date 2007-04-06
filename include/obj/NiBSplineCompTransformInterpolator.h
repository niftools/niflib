/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINECOMPTRANSFORMINTERPOLATOR_H_
#define _NIBSPLINECOMPTRANSFORMINTERPOLATOR_H_

#include "NiBSplineInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiBSplineCompTransformInterpolator;
typedef Ref<NiBSplineCompTransformInterpolator> NiBSplineCompTransformInterpolatorRef;

/*!
 * NiBSplineCompTransformInterpolator
 */
class NiBSplineCompTransformInterpolator : public NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiBSplineCompTransformInterpolator();
	NIFLIB_API ~NiBSplineCompTransformInterpolator();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Base translation when translate curve not defined.
	 */
	NIFLIB_API Vector3 GetTranslation() const;
	NIFLIB_API void SetTranslation( Vector3 value );

	/*!
	 * Base rotation when rotation curve not defined.
	 */
	NIFLIB_API Quaternion GetRotation() const;
	NIFLIB_API void SetRotation( Quaternion value );

	/*!
	 * Base scale when scale curve not defined.
	 */
	NIFLIB_API float GetScale() const;
	NIFLIB_API void SetScale( float value );

	/*!
	 * Translate Bias
	 */
	NIFLIB_API float GetTranslateBias() const;
	NIFLIB_API void SetTranslateBias( float value );

	/*!
	 * Translate Multiplier
	 */
	NIFLIB_API float GetTranslateMultiplier() const;
	NIFLIB_API void SetTranslateMultiplier( float value );

	/*!
	 * Rotation Bias
	 */
	NIFLIB_API float GetRotationBias() const;
	NIFLIB_API void SetRotationBias( float value );

	/*!
	 * Rotation Multiplier
	 */
	NIFLIB_API float GetRotationMultiplier() const;
	NIFLIB_API void SetRotationMultiplier( float value );

	/*!
	 * Scale Bias
	 */
	NIFLIB_API float GetScaleBias() const;
	NIFLIB_API void SetScaleBias( float value );

	/*!
	 * Scale Multiplier
	 */
	NIFLIB_API float GetScaleMultiplier() const;
	NIFLIB_API void SetScaleMultiplier( float value );

   /*! Retrieves the control quaternion rotation data.
   * \return A vector containing control Quaternion data which specify rotation over time.
   */
   NIFLIB_API vector< Quaternion > GetQuatRotateControlData() const;

   /*! Retrieves the control translation data.
   * \return A vector containing control Vector3 data which specify translation over time.
   */
   NIFLIB_API vector< Vector3 > GetTranslateControlData() const;

   /*! Retrieves the scale key data.
   * \return A vector containing control float data which specify scale over time.
   */
   NIFLIB_API vector< float > GetScaleControlData() const;

   /*! Retrieves the sampled quaternion rotation key data between start and stop time.
   * \param npoints The number of data points to sample between start and stop time.
   * \param degree N-th order degree of polynomial used to fit the data.
   * \return A vector containing Key<Quaternion> data which specify rotation over time.
   */
   NIFLIB_API vector< Key<Quaternion> > SampleQuatRotateKeys(int npoints, int degree) const;

   /*! Retrieves the sampled scale key data between start and stop time.
   * \param npoints The number of data points to sample between start and stop time.
   * \param degree N-th order degree of polynomial used to fit the data.
   * \return A vector containing Key<Vector3> data which specify translation over time.
   */
   NIFLIB_API vector< Key<Vector3> > SampleTranslateKeys(int npoints, int degree) const;

   /*! Retrieves the sampled scale key data between start and stop time.
   * \param npoints The number of data points to sample between start and stop time.
   * \param degree N-th order degree of polynomial used to fit the data.
   * \return A vector containing Key<float> data which specify scale over time.
   */
   NIFLIB_API vector< Key<float> > SampleScaleKeys(int npoints, int degree) const;

   /*! Retrieves the number of control points used in the spline curve.
   * \return The number of control points used in the spline curve.
   */
   NIFLIB_API int GetNumControlPt() const;

protected:
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
