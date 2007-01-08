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
class NIFLIB_API NiBSplineCompTransformInterpolator : public NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT {
public:
	NiBSplineCompTransformInterpolator();
	~NiBSplineCompTransformInterpolator();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Base translation when translate curve not defined.
	 */
	Vector3 GetTranslation() const;
	void SetTranslation( Vector3 value );

	/*!
	 * Base rotation when rotation curve not defined.
	 */
	Quaternion GetRotation() const;
	void SetRotation( Quaternion value );

	/*!
	 * Base scale when scale curve not defined.
	 */
	float GetScale() const;
	void SetScale( float value );

	/*!
	 * Translate Bias
	 */
	float GetTranslateBias() const;
	void SetTranslateBias( float value );

	/*!
	 * Translate Multiplier
	 */
	float GetTranslateMultiplier() const;
	void SetTranslateMultiplier( float value );

	/*!
	 * Rotation Bias
	 */
	float GetRotationBias() const;
	void SetRotationBias( float value );

	/*!
	 * Rotation Multiplier
	 */
	float GetRotationMultiplier() const;
	void SetRotationMultiplier( float value );

	/*!
	 * Scale Bias
	 */
	float GetScaleBias() const;
	void SetScaleBias( float value );

	/*!
	 * Scale Multiplier
	 */
	float GetScaleMultiplier() const;
	void SetScaleMultiplier( float value );

   /*! Retrieves the control quaternion rotation data.
   * \return A vector containing control Quaternion data which specify rotation over time.
   */
   vector< Quaternion > GetQuatRotateControlData() const;

   /*! Retrieves the control translation data.
   * \return A vector containing control Vector3 data which specify translation over time.
   */
   vector< Vector3 > GetTranslateControlData() const;

   /*! Retrieves the scale key data.
   * \return A vector containing control float data which specify scale over time.
   */
   vector< float > GetScaleControlData() const;

   /*! Retrieves the sampled quaternion rotation key data between start and stop time.
   * \param npoints The number of data points to sample between start and stop time.
   * \param degree N-th order degree of polynomial used to fit the data.
   * \return A vector containing Key<Quaternion> data which specify rotation over time.
   */
   vector< Key<Quaternion> > SampleQuatRotateKeys(int npoints, int degree) const;

   /*! Retrieves the sampled scale key data between start and stop time.
   * \param npoints The number of data points to sample between start and stop time.
   * \param degree N-th order degree of polynomial used to fit the data.
   * \return A vector containing Key<Vector3> data which specify translation over time.
   */
   vector< Key<Vector3> > SampleTranslateKeys(int npoints, int degree) const;

   /*! Retrieves the sampled scale key data between start and stop time.
   * \param npoints The number of data points to sample between start and stop time.
   * \param degree N-th order degree of polynomial used to fit the data.
   * \return A vector containing Key<float> data which specify scale over time.
   */
   vector< Key<float> > SampleScaleKeys(int npoints, int degree) const;

   /*! Retrieves the number of control points used in the spline curve.
   * \return The number of control points used in the spline curve.
   */
   int GetNumControlPt() const;

protected:
	NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
