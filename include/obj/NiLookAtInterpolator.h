/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILOOKATINTERPOLATOR_H_
#define _NILOOKATINTERPOLATOR_H_

#include "NiInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiNode;
class NiPoint3Interpolator;
class NiFloatInterpolator;

//#include "../gen/obj_defines.h"

class NiLookAtInterpolator;
typedef Ref<NiLookAtInterpolator> NiLookAtInterpolatorRef;

/*!
 * NiLookAtInterpolator - Unknown.
 */

class NiLookAtInterpolator : public NI_LOOK_AT_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiLookAtInterpolator();
	NIFLIB_API ~NiLookAtInterpolator();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the node that this interpolator is focused on.
	 * \return The node that this interpolator is focused on.
	 */
	NIFLIB_API Ref<NiNode > GetLookAt() const;

	/*!
	 * Sets the node that this interpolator will focus on.
	 * \return The new node that the interpolator will focus on, or NULL to clear the current one.
	 */
	NIFLIB_API void SetLookAt( Ref<NiNode > value );

	/*!
	 * Gets the translation of the interpolator.  Could be the necessary value to point at the referenced node in the current pose.
	 * \return The translation of the interpolator.
	 */
	NIFLIB_API Vector3 GetTranslation() const;

	/*!
	 * Sets the translation of the interpolator.  Could be the necessary value to point at the referenced node in the current pose.
	 * \param[in] value The new translation for the interpolator.
	 */
	NIFLIB_API void SetTranslation( Vector3 value );

	/*!
	 * Gets the rotation of the interpolator.  Could be the necessary value to point at the referenced node in the current pose.
	 * \return The rotation of the interpolator.
	 */
	NIFLIB_API Quaternion GetRotation() const;

	/*!
	 * Sets the rotation of the interpolator.  Could be the necessary value to point at the referenced node in the current pose.
	 * \param[in] value The new rotation for the interpolator.
	 */
	NIFLIB_API void SetRotation( Quaternion value );

	/*!
	 * Gets the scale of the interpolator.  Could be the necessary value to point at the referenced node in the current pose.
	 * \return The scale of the interpolator.
	 */
	NIFLIB_API float GetScale() const;

	/*!
	 * Sets the scale of the interpolator.  Could be the necessary value to point at the referenced node in the current pose.
	 * \param[in] value The new scale for the interpolator.
	 */
	NIFLIB_API void SetScale( float value );

protected:
	NI_LOOK_AT_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
