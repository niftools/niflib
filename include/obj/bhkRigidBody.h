/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _BHKRIGIDBODY_H_
#define _BHKRIGIDBODY_H_

#include "bhkEntity.h"

// Include structures
#include "../gen/QuaternionXYZW.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class bhkConstraint;

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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*!
	 * Retrieves what appears to be a copy of the layer value.
	 * \return The duplicate layer value.
	 */
	NIFLIB_API OblivionLayer GetLayerCopy() const;

	/*!
	 * Sets what appears to be a copy of the layer value.
	 * \param[in] value The new duplicate layer value.
	 */
	NIFLIB_API void SetLayerCopy( OblivionLayer value );

	/*!
	 * Gets the current translation of this rigid body.
	 * \return The translation of this rigid body.
	 */
	NIFLIB_API Vector3 GetTranslation() const;

	/*!
	 * Sets a new translation for this rigid body.
	 * \param[in] value  The new translation for this rigid body.
	 */
	NIFLIB_API void SetTranslation( const Vector3 & value );

	/*!
	 * Gets the current rotation of this rigid body.
	 * \return The rotation of this rigid body.
	 */
	NIFLIB_API QuaternionXYZW GetRotation() const;

	/*!
	 * Sets a new rotation for this rigid body.
	 * \param[in] value The new rotation for this rigid body.
	 */
	NIFLIB_API void SetRotation( const QuaternionXYZW & value );

	/*!
	 * Gets the current linear velocity of this rigid body.
	 * \return The linear velocity of this rigid body.
	 */
	NIFLIB_API Vector3 GetLinearVelocity() const;

	/*!
	 * Sets a new linear velocity for this rigid body.
	 * \param[in] value The new linear velocity for this rigid body.
	 */
	NIFLIB_API void SetLinearVelocity( const Vector3 & value );

	/*!
	 * Gets the current angular velocity of this rigid body.
	 * \return The angular velocity of this rigid body.
	 */
	NIFLIB_API Vector3 GetAngularVelocity() const;

	/*!
	 * Sets a new angular velocity for this rigid body.
	 * \param[in] value The new angular velocity for this rigid body.
	 */
	NIFLIB_API void SetAngularVelocity( const Vector3 & value );

	/*!
	 * Gets the current inertia of this rigid body.
	 * \return The inertia of this rigid body.
	 */
	NIFLIB_API array<12,float> GetInertia() const;

	/*!
	 * Sets a new inertia for this rigid body.
	 * \param[in] value The new inertia for this rigid body.
	 */
	NIFLIB_API void SetInertia( const array<12,float> & value );

	/*!
	 * Gets the current center point of this rigid body.
	 * \return The center point of this rigid body.
	 */
	NIFLIB_API Vector3 GetCenter() const;

	/*!
	 * Sets a new center point for this rigid body.
	 * \param[in] value The new center point for this rigid body.
	 */
	NIFLIB_API void SetCenter( const Vector3 & value );

	/*!
	 * Gets the current mass of this rigid body.
	 * \return The mass of this rigid body.
	 */
	NIFLIB_API float GetMass() const;

	/*!
	 * Sets a new mass for this rigid body.
	 * \param[in] value The new mass for this rigid body.
	 */
	NIFLIB_API void SetMass( float value );

	/*!
	 * Gets the current linear damping level of this rigid body.
	 * \return The linear damping level of this rigid body.
	 */
	NIFLIB_API float GetLinearDamping() const;

	/*!
	 * Sets a new linear damping level for this rigid body.
	 * \param[in] value The new linear damping level for this rigid body.
	 */
	NIFLIB_API void SetLinearDamping( float value );

	/*!
	 * Gets the current angular damping level of this rigid body.
	 * \return The angular damping level of this rigid body.
	 */
	NIFLIB_API float GetAngularDamping() const;

	/*!
	 * Sets a new angular damping level for this rigid body.
	 * \param[in] value The new angular damping level for this rigid body.
	 */
	NIFLIB_API void SetAngularDamping( float value );

	/*!
	 * Gets the current friction of this rigid body.
	 * \return The friction of this rigid body.
	 */
	NIFLIB_API float GetFriction() const;

	/*!
	 * Sets a new friction for this rigid body.
	 * \param[in] value The new friction for this rigid body.
	 */
	NIFLIB_API void SetFriction( float value );

	/*!
	 * Gets the current restitution of this rigid body.
	 * \return The restitution of this rigid body.
	 */
	NIFLIB_API float GetRestitution() const;

	/*!
	 * Sets a new restitution for this rigid body.
	 * \param[in] value The new restitution for this rigid body.
	 */
	NIFLIB_API void SetRestitution( float value );

	/*!
	 * Gets the current maximum linear velocity of this rigid body.
	 * \return The maximum linear velocity of this rigid body.
	 */
	NIFLIB_API float GetMaxLinearVelocity() const;

	/*!
	 * Sets a new maximum linear velocit for this rigid body.
	 * \param[in] value The new maximum linear velocity for this rigid body.
	 */
	NIFLIB_API void SetMaxLinearVelocity( float value );

	/*!
	 * Gets the current maximum angular velocity of this rigid body.
	 * \return The maximum angular velocity of this rigid body.
	 */
	NIFLIB_API float GetMaxAngularVelocity() const;

	/*!
	 * Sets a new maximum angular velocity for this rigid body.
	 * \param[in] value The new maximum angular velocit for this rigid body.
	 */
	NIFLIB_API void SetMaxAngularVelocity( float value );

	/*!
	 * Gets the current allowable penetration depth of this rigid body.
	 * \return The allowable penetration depth of this rigid body.
	 */
	NIFLIB_API float GetPenetrationDepth() const;

	/*!
	 * Sets a new allowable penetration depth for this rigid body.
	 * \param[in] value The new allowable penetration depth for this rigid body.
	 */
	NIFLIB_API void SetPenetrationDepth( float value );

	/*!
	 * Sets the current motion system for this rigid body.  Seems to override motion quality when set to keyframed.
	 * \return The current motion system setting of this rigid body.
	 */
	NIFLIB_API MotionSystem GetMotionSystem() const;

	/*!
	 * Gets the current motion system of this rigid body.  Seems to override motion quality when set to keyframed.
	 * \param[in] value The new motion system setting for this rigid body.
	 */
	NIFLIB_API void SetMotionSystem( MotionSystem value );

	/*!
	 * Sets the quality of the calculations used to detect collisions for this object.  Essentially, the faster the object goes, the higher quality of motion it will require.
	 * \return The current motion quality setting of this rigid body.
	 */
	NIFLIB_API MotionQuality GetQualityType() const;

	/*!
	 * Gets the quality of the calculations used to detect collisions for this object.  Essentially, the faster the object goes, the higher quality of motion it will require.
	 * \param[in] value The new motion quality setting for this rigid body.
	 */
	NIFLIB_API void SetQualityType( MotionQuality value );

	//--END CUSTOM CODE--//

protected:
	BHK_RIGID_BODY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
