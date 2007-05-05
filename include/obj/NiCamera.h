/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICAMERA_H_
#define _NICAMERA_H_

#include "NiAVObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiObject;

//#include "../gen/obj_defines.h"

class NiCamera;
typedef Ref<NiCamera> NiCameraRef;

/*!
 * NiCamera - Camera object.
 */

class NiCamera : public NI_CAMERA_PARENT {
public:
	NIFLIB_API NiCamera();
	NIFLIB_API ~NiCamera();
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
	 * Retrieves the frustum left value.
	 * \return The frstum left value.
	 */
	NIFLIB_API float GetFrustumLeft() const;

	/*!
	 * Sets the frustum left value.
	 * \param[in] value The new frstum left value.
	 */
	NIFLIB_API void SetFrustumLeft( float value );

	/*!
	 * Retrieves the frustum right value.
	 * \return The frstum right value.
	 */
	NIFLIB_API float GetFrustumRight() const;

	/*!
	 * Sets the frustum right value.
	 * \param[in] value The new frstum right value.
	 */
	NIFLIB_API void SetFrustumRight( float value );

	/*!
	 * Retrieves the frustum top value.
	 * \return The frstum top value.
	 */
	NIFLIB_API float GetFrustumTop() const;
	NIFLIB_API void SetFrustumTop( float value );

	/*!
	 * Retrieves the frustum bottom value.
	 * \return The frstum bottom value.
	 */
	NIFLIB_API float GetFrustumBottom() const;

	/*!
	 * Sets the frustum top value.
	 * \param[in] value The new frstum top value.
	 */
	NIFLIB_API void SetFrustumBottom( float value );

	/*!
	 * Retrieves the frustum near value.
	 * \return The frstum near value.
	 */
	NIFLIB_API float GetFrustumNear() const;

	/*!
	 * Sets the frustum near value.
	 * \param[in] value The new frstum near value.
	 */
	NIFLIB_API void SetFrustumNear( float value );

	/*!
	 * Retrieves the frustum far value.
	 * \return The frstum far value.
	 */
	NIFLIB_API float GetFrustumFar() const;

	/*!
	 * Sets the frustum far value.
	 * \param[in] value The new frstum far value.
	 */
	NIFLIB_API void SetFrustumFar( float value );

	/*!
	 * Determines whether perspective is used.  Orthographic means no perspective.
	 * \return True if projection is orthographic, false otherwise.
	 */
	NIFLIB_API bool GetUseOrthographicProjection() const;

	/*!
	 * Sets whether perspective is used.  Orthographic means no perspective.
	 * \param[in] value True if projection is to be orthographic, false otherwise.
	 */
	NIFLIB_API void SetUseOrthographicProjection( bool value );

	/*!
	 * Retrieves the viewport left value.
	 * \return The viewport left value.
	 */
	NIFLIB_API float GetViewportLeft() const;

	/*!
	 * Sets the viewport left value.
	 * \param[in] value The new viewport left value.
	 */
	NIFLIB_API void SetViewportLeft( float value );

	/*!
	 * Retrieves the viewport right value.
	 * \return The viewport right value.
	 */
	NIFLIB_API float GetViewportRight() const;

	/*!
	 * Sets the viewport right value.
	 * \param[in] value The new viewport right value.
	 */
	NIFLIB_API void SetViewportRight( float value );

	/*!
	 * Retrieves the viewport top value.
	 * \return The viewport top value.
	 */
	NIFLIB_API float GetViewportTop() const;

	/*!
	 * Sets the viewport top value.
	 * \param[in] value The new viewport top value.
	 */
	NIFLIB_API void SetViewportTop( float value );

	/*!
	 * Retrieves the viewport bottom value.
	 * \return The viewport bottom value.
	 */
	NIFLIB_API float GetViewportBottom() const;

	/*!
	 * Sets the viewport bottom value.
	 * \param[in] value The new viewport bottom value.
	 */
	NIFLIB_API void SetViewportBottom( float value );

	/*!
	 * Retrieves the level of detail adjustment value.
	 * \return The LOD adjustment value.
	 */
	NIFLIB_API float GetLodAdjust() const;

	/*!
	 * Sets the level of detail adjustment value.
	 * \param[in] value The new LOD adjustment value.
	 */
	NIFLIB_API void SetLodAdjust( float value );

protected:
	NI_CAMERA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
