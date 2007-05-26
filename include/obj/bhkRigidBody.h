/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BHKRIGIDBODY_H_
#define _BHKRIGIDBODY_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "bhkEntity.h"

// Include structures
#include "../gen/QuaternionXYZW.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class bhkConstraint;
class bhkRigidBody;
typedef Ref<bhkRigidBody> bhkRigidBodyRef;

/*!
 * This is the default body type for all "normal" usable and static world objects.
 * The "T" suffix
 *         marks this body as active for translation and rotation, a normal
 * bhkRigidBody ignores those
 *         properties. Because the properties are equal, a bhkRigidBody may be
 * renamed
 *         into a bhkRigidBodyT and vice-versa.
 */
class bhkRigidBody : public bhkEntity {
public:
	/*! Constructor */
	NIFLIB_API bhkRigidBody();

	/*! Destructor */
	NIFLIB_API virtual ~bhkRigidBody();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

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
	/*! Unknown. */
	array<5,float > unknown5Floats;
	/*! Unknown. */
	array<4,unsigned short > unknown4Shorts;
	/*! Copy of Layer value? */
	OblivionLayer layerCopy;
	/*! Copy of Col Filter value? */
	byte colFilterCopy;
	/*! Unknown. */
	array<7,unsigned short > unknown7Shorts;
	/*!
	 * A vector that moves the body by the specified amount. Only enabled in
	 * bhkRigidBodyT objects.
	 */
	Vector3 translation;
	/*!
	 * This seems to often be 1 for single objects, or the first one in a
	 *             a linked object group. This may be due to those objects often being
	 * bhkRigidBodyT as well.
	 */
	float unknownFloat00;
	/*!
	 * The rotation Yaw/Pitch/Roll to apply to the body. Only enabled in bhkRigidBodyT
	 * objects.
	 */
	QuaternionXYZW rotation;
	/*! Linear velocity. */
	Vector3 linearVelocity;
	/*! Unknown. */
	float unknownFloat01;
	/*! Angular velocity. */
	Vector3 angularVelocity;
	/*! Unknown. */
	float unknownFloat02;
	/*! Defines how the mass is distributed among the body. */
	array<12,float > inertia;
	/*!
	 * This seems to be used to relocate the object's center of mass. Useful for
	 * balancing objects in contraints.
	 */
	Vector3 center;
	/*! Unknown float. */
	float unknownFloat03;
	/*! The body's mass. */
	float mass;
	/*!
	 * Damping value for linear movement. A value that is too small fixes the object in
	 * place.
	 */
	float linearDamping;
	/*! Damping value for angular movement. */
	float angularDamping;
	/*! The body's friction. */
	float friction;
	/*! The body's restitution (elasticity). */
	float restitution;
	/*! Maximal linear velocity. */
	float maxLinearVelocity;
	/*! Maximal angular velocity. Pi x 10? */
	float maxAngularVelocity;
	/*! Penetration depth. */
	float penetrationDepth;
	/*! Motion system? Overrides Quality when on Keyframed? */
	MotionSystem motionSystem;
	/*!
	 * Usually set to 1 for fixed objects, or set to 2 for moving ones.  Seems to
	 * always be same as Unknown Byte 2.
	 */
	byte unknownByte1;
	/*!
	 * Usually set to 1 for fixed objects, or set to 2 for moving ones.  Seems to
	 * always be same as Unknown Byte 1.
	 */
	byte unknownByte2;
	/*! The motion type. Determines quality of motion? */
	MotionQuality qualityType;
	/*! Unknown. */
	unsigned int unknownInt6;
	/*! Unknown. */
	unsigned int unknownInt7;
	/*! Unknown. */
	unsigned int unknownInt8;
	/*! The number of constraints this object is bound to. */
	mutable unsigned int numConstraints;
	/*! Unknown. */
	vector<Ref<bhkConstraint > > constraints;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//
//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
