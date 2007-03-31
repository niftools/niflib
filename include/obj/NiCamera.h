/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICAMERA_H_
#define _NICAMERA_H_

#include "NiAVObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
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
	NIFLIB_API static const Type & TypeConst();
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
	 * Frustrum left.
	 */
	NIFLIB_API float GetFrustumLeft() const;
	NIFLIB_API void SetFrustumLeft( float value );

	/*!
	 * Frustrum right.
	 */
	NIFLIB_API float GetFrustumRight() const;
	NIFLIB_API void SetFrustumRight( float value );

	/*!
	 * Frustrum top.
	 */
	NIFLIB_API float GetFrustumTop() const;
	NIFLIB_API void SetFrustumTop( float value );

	/*!
	 * Frustrum bottom.
	 */
	NIFLIB_API float GetFrustumBottom() const;
	NIFLIB_API void SetFrustumBottom( float value );

	/*!
	 * Frustrum near.
	 */
	NIFLIB_API float GetFrustumNear() const;
	NIFLIB_API void SetFrustumNear( float value );

	/*!
	 * Frustrum far.
	 */
	NIFLIB_API float GetFrustumFar() const;
	NIFLIB_API void SetFrustumFar( float value );

	/*!
	 * Determines whether perspective is used.  Orthographic means no
	 * perspective.
	 */
	NIFLIB_API bool GetUseOrthographicProjection() const;
	NIFLIB_API void SetUseOrthographicProjection( bool value );

	/*!
	 * Viewport left.
	 */
	NIFLIB_API float GetViewportLeft() const;
	NIFLIB_API void SetViewportLeft( float value );

	/*!
	 * Viewport right.
	 */
	NIFLIB_API float GetViewportRight() const;
	NIFLIB_API void SetViewportRight( float value );

	/*!
	 * Viewport top.
	 */
	NIFLIB_API float GetViewportTop() const;
	NIFLIB_API void SetViewportTop( float value );

	/*!
	 * Viewport bottom.
	 */
	NIFLIB_API float GetViewportBottom() const;
	NIFLIB_API void SetViewportBottom( float value );

	/*!
	 * Level of detail adjust.
	 */
	NIFLIB_API float GetLodAdjust() const;
	NIFLIB_API void SetLodAdjust( float value );

protected:
	NI_CAMERA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
