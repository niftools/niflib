/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NITRANSFORMINTERPOLATOR_H_
#define _NITRANSFORMINTERPOLATOR_H_

#include "NiInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiTransformData;

//#include "../gen/obj_defines.h"

class NiTransformInterpolator;
typedef Ref<NiTransformInterpolator> NiTransformInterpolatorRef;

/*!
 * NiTransformInterpolator - Unknown.
 */

class NiTransformInterpolator : public NI_TRANSFORM_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiTransformInterpolator();
	NIFLIB_API ~NiTransformInterpolator();
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
	 * Gets the translation value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \return The translation value stored in this object.
	 */
	NIFLIB_API Vector3 GetTranslation() const;

	/*!
	 * Sets the translation value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \param[in] value The new translation value to store in this object.
	 */
	NIFLIB_API void SetTranslation( Vector3 value );

	/*!
	 * Gets the rotation value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \return The rotation value stored in this object.
	 */
	NIFLIB_API Quaternion GetRotation() const;

	/*!
	 * Sets the rotation value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \param[in] value The new rotation value to store in this object.
	 */
	NIFLIB_API void SetRotation( Quaternion value );

	/*!
	 * Gets the scale value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \return The scale value stored in this object.
	 */
	NIFLIB_API float GetScale() const;

	/*!
	 * Sets the scale value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \param[in] value The new scale value to store in this object.
	 */
	NIFLIB_API void SetScale( float value );

	/*!
	 * Gets the NiTransformData object that this interpolator links to, if any.
	 * \return The NiTransformData object that this interpolator links to, or NULL if one is not linked.
	 */
	NIFLIB_API Ref<NiTransformData > GetData() const;

	/*!
	 * Sets the NiTransformData object that this interpolator links to, if any.
	 * \return The NiTransformData object that this interpolator should now link to, or NULL to clear the current one.
	 */
	NIFLIB_API void SetData( NiTransformData * value );

protected:
	NI_TRANSFORM_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
