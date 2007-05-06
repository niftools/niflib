/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Gets the base translation when a translate curve is not defined.
	 * \return The base translation.
	 */
	NIFLIB_API Vector3 GetTranslation() const;

	/*!
	 * Sets the base translation when a translate curve is not defined.
	 * \param[in] value The new base translation.
	 */
	NIFLIB_API void SetTranslation( Vector3 value );

	/*!
	 * Gets the base rotation when a translate curve is not defined.
	 * \return The base rotation.
	 */
	NIFLIB_API Quaternion GetRotation() const;

	/*!
	 * Sets the base rotation when a translate curve is not defined.
	 * \param[in] value The new base rotation.
	 */
	NIFLIB_API void SetRotation( Quaternion value );

	/*!
	 * Gets the base scale when a translate curve is not defined.
	 * \return The base scale.
	 */
	NIFLIB_API float GetScale() const;

	/*!
	 * Sets the base scale when a translate curve is not defined.
	 * \param[in] value The new base scale.
	 */
	NIFLIB_API void SetScale( float value );

	/*!
	 * Gets translate bias.
	 * \return The translate bias.
	 */
	NIFLIB_API float GetTranslateBias() const;

	/*!
	 * Sets translate bias.
	 * \param[in] value The new translate bias.
	 */
	NIFLIB_API void SetTranslateBias( float value );

	/*!
	 * Gets translate multiplier.
	 * \return The translate bias.
	 */
	NIFLIB_API float GetTranslateMultiplier() const;

	/*!
	 * Sets translate multiplier.
	 * \param[in] value The new translate bias.
	 */
	NIFLIB_API void SetTranslateMultiplier( float value );

	/*!
	 * Gets rotation bias.
	 * \return The rotation bias.
	 */
	NIFLIB_API float GetRotationBias() const;

	/*!
	 * Sets rotation bias.
	 * \param[in] value The new rotation bias.
	 */
	NIFLIB_API void SetRotationBias( float value );

	/*!
	 * Gets rotation multiplier.
	 * \return The translate bias.
	 */
	NIFLIB_API float GetRotationMultiplier() const;

	/*!
	 * Sets rotation multiplier.
	 * \param[in] value The new translate bias.
	 */
	NIFLIB_API void SetRotationMultiplier( float value );

	/*!
	 * Gets scale bias.
	 * \return The scale bias.
	 */
	NIFLIB_API float GetScaleBias() const;

	/*!
	 * Sets scale bias.
	 * \param[in] value The new scale bias.
	 */
	NIFLIB_API void SetScaleBias( float value );

	/*!
	 * Gets scale multiplier.
	 * \return The scale multiplier.
	 */
	NIFLIB_API float GetScaleMultiplier() const;

	/*!
	 * Sets scale multiplier.
	 * \param[in] value The new scale multiplier.
	 */
	NIFLIB_API void SetScaleMultiplier( float value );

	/*!
	 * Retrieves the control quaternion rotation data.
	 * \return A vector containing control Quaternion data which specify rotation over time.
	 */
	NIFLIB_API vector< Quaternion > GetQuatRotateControlData() const;

	/*!
	 * Retrieves the control translation data.
	 * \return A vector containing control Vector3 data which specify translation over time.
	 */
	NIFLIB_API vector< Vector3 > GetTranslateControlData() const;

	/*!
	 * Retrieves the scale key data.
	 * \return A vector containing control float data which specify scale over time.
	 */
	NIFLIB_API vector< float > GetScaleControlData() const;

	/*!
	 * Retrieves the sampled quaternion rotation key data between start and stop time.
	 * \param npoints The number of data points to sample between start and stop time.
	 * \param degree N-th order degree of polynomial used to fit the data.
	 * \return A vector containing Key<Quaternion> data which specify rotation over time.
	 */
	NIFLIB_API vector< Key<Quaternion> > SampleQuatRotateKeys(int npoints, int degree) const;

	/*!
	 * Retrieves the sampled scale key data between start and stop time.
	 * \param npoints The number of data points to sample between start and stop time.
	 * \param degree N-th order degree of polynomial used to fit the data.
	 * \return A vector containing Key<Vector3> data which specify translation over time.
	 */
	NIFLIB_API vector< Key<Vector3> > SampleTranslateKeys(int npoints, int degree) const;

	/*!
	 * Retrieves the sampled scale key data between start and stop time.
	 * \param npoints The number of data points to sample between start and stop time.
	 * \param degree N-th order degree of polynomial used to fit the data.
	 * \return A vector containing Key<float> data which specify scale over time.
	 */
	NIFLIB_API vector< Key<float> > SampleScaleKeys(int npoints, int degree) const;

	/*!
	 * Retrieves the number of control points used in the spline curve.
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
