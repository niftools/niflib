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

#include "../gen/obj_defines.h"

class bhkRigidBody;
typedef Ref<bhkRigidBody> bhkRigidBodyRef;

/*!
 * bhkRigidBody - Describes physical properties of an object.
 */

class NIFLIB_API bhkRigidBody : public BHK_RIGID_BODY_PARENT {
public:
	bhkRigidBody();
	~bhkRigidBody();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Copy of layer value?
	 */
	OblivionLayer GetLayerCopy() const;
	void SetLayerCopy( OblivionLayer value );

	/*!
	 * Translation.
	 */
	Vector3 GetTranslation() const;
	void SetTranslation( const Vector3 & value );

	/*!
	 * Rotation.
	 */
	QuaternionXYZW GetRotation() const;
	void SetRotation( const QuaternionXYZW & value );

	/*!
	 * Linear velocity.
	 */
	Vector3 GetLinearVelocity() const;
	void SetLinearVelocity( const Vector3 & value );

	/*!
	 * Angular velocity.
	 */
	Vector3 GetAngularVelocity() const;
	void SetAngularVelocity( const Vector3 & value );

	/*!
	 * Seems to be some kind of transformation matrix, scale or translation?
	 */
	array<float,12>  GetTransform() const;
	void SetTransform( const array<float,12>&  value );

	/*!
	 * The object's center.
	 */
	Vector3 GetCenter() const;
	void SetCenter( const Vector3 & value );

	/*!
	 * Object mass.
	 */
	float GetMass() const;
	void SetMass( float value );

	/*!
	 * Linear damping level.
	 */
	float GetLinearDamping() const;
	void SetLinearDamping( float value );

	/*!
	 * Angular Dampling level.
	 */
	float GetAngularDamping() const;
	void SetAngularDamping( float value );

	/*!
	 * The object's friction.
	 */
	float GetFriction() const;
	void SetFriction( float value );

	/*!
	 * The object's restitution (elasticity).
	 */
	float GetRestitution() const;
	void SetRestitution( float value );

	/*!
	 * Maximal linear velocity.
	 */
	float GetMaxLinearVelocity() const;
	void SetMaxLinearVelocity( float value );

	/*!
	 * Maximal angular velocity. Pi x 10?
	 */
	float GetMaxAngularVelocity() const;
	void SetMaxAngularVelocity( float value );

	/*!
	 * Penetration depth.
	 */
	float GetPenetrationDepth() const;
	void SetPenetrationDepth( float value );

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
	byte GetMotionSystem() const;
	void SetMotionSystem( byte value );

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
	MotionQuality GetQualityType() const;
	void SetQualityType( MotionQuality value );

protected:
	BHK_RIGID_BODY_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
