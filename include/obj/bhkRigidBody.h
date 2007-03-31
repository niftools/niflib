/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKRIGIDBODY_H_
#define _BHKRIGIDBODY_H_

#include "bhkEntity.h"

// Include structures
#include "../gen/QuaternionXYZW.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class AbhkConstraint;

//#include "../gen/obj_defines.h"

class bhkRigidBody;
typedef Ref<bhkRigidBody> bhkRigidBodyRef;

/*!
 * bhkRigidBody - Describes physical properties of an object.
 */

class bhkRigidBody : public BHK_RIGID_BODY_PARENT {
public:
	NIFLIB_API bhkRigidBody();
	NIFLIB_API ~bhkRigidBody();
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
	 * Copy of layer value?
	 */
	NIFLIB_API OblivionLayer GetLayerCopy() const;
	NIFLIB_API void SetLayerCopy( OblivionLayer value );

	/*!
	 * Translation.
	 */
	NIFLIB_API Vector3 GetTranslation() const;
	NIFLIB_API void SetTranslation( const Vector3 & value );

	/*!
	 * Rotation.
	 */
	NIFLIB_API QuaternionXYZW GetRotation() const;
	NIFLIB_API void SetRotation( const QuaternionXYZW & value );

	/*!
	 * Linear velocity.
	 */
	NIFLIB_API Vector3 GetLinearVelocity() const;
	NIFLIB_API void SetLinearVelocity( const Vector3 & value );

	/*!
	 * Angular velocity.
	 */
	NIFLIB_API Vector3 GetAngularVelocity() const;
	NIFLIB_API void SetAngularVelocity( const Vector3 & value );

	/*!
	 * Seems to be some kind of transformation matrix, scale or translation?
	 */
	NIFLIB_API array<12,float>  GetInertia() const;
	NIFLIB_API void SetInertia( const array<12,float>&  value );

	/*!
	 * The object's center.
	 */
	NIFLIB_API Vector3 GetCenter() const;
	NIFLIB_API void SetCenter( const Vector3 & value );

	/*!
	 * Object mass.
	 */
	NIFLIB_API float GetMass() const;
	NIFLIB_API void SetMass( float value );

	/*!
	 * Linear damping level.
	 */
	NIFLIB_API float GetLinearDamping() const;
	NIFLIB_API void SetLinearDamping( float value );

	/*!
	 * Angular Dampling level.
	 */
	NIFLIB_API float GetAngularDamping() const;
	NIFLIB_API void SetAngularDamping( float value );

	/*!
	 * The object's friction.
	 */
	NIFLIB_API float GetFriction() const;
	NIFLIB_API void SetFriction( float value );

	/*!
	 * The object's restitution (elasticity).
	 */
	NIFLIB_API float GetRestitution() const;
	NIFLIB_API void SetRestitution( float value );

	/*!
	 * Maximal linear velocity.
	 */
	NIFLIB_API float GetMaxLinearVelocity() const;
	NIFLIB_API void SetMaxLinearVelocity( float value );

	/*!
	 * Maximal angular velocity. Pi x 10?
	 */
	NIFLIB_API float GetMaxAngularVelocity() const;
	NIFLIB_API void SetMaxAngularVelocity( float value );

	/*!
	 * Penetration depth.
	 */
	NIFLIB_API float GetPenetrationDepth() const;
	NIFLIB_API void SetPenetrationDepth( float value );

	/*!
	 * Motion system? Overrides Quality when on Keyframed?
    * 0: Keyframed
    * 1: Box
    * 2: Sphere
    * 3: Sphere
    * 4: Box
    * 5: Box
    * 6: Keyframed
	 * 7: Keyframed
    * 8: Box
    * 9+: Keyframed?
	 */
	NIFLIB_API MotionSystem GetMotionSystem() const;
	NIFLIB_API void SetMotionSystem( MotionSystem value );

	/*!
	 * The motion type. Determines quality of motion?
    * 0: Moving
	 * 1: Fixed
    * 2: Keyframed
    * 3-4: Moving(?)
	 * 5: Critical
    * 6: Bullet
    * 7: User
    * 8+: Null
	 */
	NIFLIB_API MotionQuality GetQualityType() const;
	NIFLIB_API void SetQualityType( MotionQuality value );

protected:
	BHK_RIGID_BODY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
