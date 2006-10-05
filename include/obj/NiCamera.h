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

#include "../gen/obj_defines.h"

class NiCamera;
typedef Ref<NiCamera> NiCameraRef;

/*!
 * NiCamera - Camera object.
 */

class NIFLIB_API NiCamera : public NI_CAMERA_PARENT {
public:
	NiCamera();
	~NiCamera();
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
	 * Frustrum left.
	 */
	float GetFrustumLeft() const;
	void SetFrustumLeft( float value );

	/*!
	 * Frustrum right.
	 */
	float GetFrustumRight() const;
	void SetFrustumRight( float value );

	/*!
	 * Frustrum top.
	 */
	float GetFrustumTop() const;
	void SetFrustumTop( float value );

	/*!
	 * Frustrum bottom.
	 */
	float GetFrustumBottom() const;
	void SetFrustumBottom( float value );

	/*!
	 * Frustrum near.
	 */
	float GetFrustumNear() const;
	void SetFrustumNear( float value );

	/*!
	 * Frustrum far.
	 */
	float GetFrustumFar() const;
	void SetFrustumFar( float value );

	/*!
	 * Determines whether perspective is used.  Orthographic means no
	 * perspective.
	 */
	bool GetUseOrthographicProjection() const;
	void SetUseOrthographicProjection( bool value );

	/*!
	 * Viewport left.
	 */
	float GetViewportLeft() const;
	void SetViewportLeft( float value );

	/*!
	 * Viewport right.
	 */
	float GetViewportRight() const;
	void SetViewportRight( float value );

	/*!
	 * Viewport top.
	 */
	float GetViewportTop() const;
	void SetViewportTop( float value );

	/*!
	 * Viewport bottom.
	 */
	float GetViewportBottom() const;
	void SetViewportBottom( float value );

	/*!
	 * Level of detail adjust.
	 */
	float GetLodAdjust() const;
	void SetLodAdjust( float value );

protected:
	NI_CAMERA_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
