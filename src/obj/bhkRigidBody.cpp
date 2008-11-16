/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/bhkShape.h"
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/bhkRigidBody.h"
#include "../../include/gen/QuaternionXYZW.h"
#include "../../include/obj/bhkSerializable.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRigidBody::TYPE("bhkRigidBody", &bhkEntity::TYPE );

bhkRigidBody::bhkRigidBody() : unknownInt1((int)0), unknownInt2((int)0x00000001), unknown3Ints(3,(int)0,(int)0,(int)0x80000000), collisionResponse_((hkResponseType)1), unknownByte((byte)0xbe), processContactCallbackDelay_((unsigned short)0xffff), unknown2Shorts(2,(unsigned short)35899,(unsigned short)16336), layerCopy((OblivionLayer)1), colFilterCopy((byte)0), unknown7Shorts(7,(unsigned short)0,(unsigned short)21280,(unsigned short)2481,(unsigned short)62977,(unsigned short)65535,(unsigned short)44,(unsigned short)0), mass(1.0f), linearDamping(0.1f), angularDamping(0.05f), friction(0.3f), restitution(0.3f), maxLinearVelocity(250.0f), maxAngularVelocity(31.4159f), penetrationDepth(0.15f), motionSystem((MotionSystem)1), deactivatorType((DeactivatorType)1), solverDeactivation((SolverDeactivation)1), qualityType((MotionQuality)0), autoRemoveLevel((unsigned int)0), userDatasInContactPointProperties_((unsigned int)0), forceCollideOntoPpu_((unsigned int)0), numConstraints((unsigned int)0), unknownInt9((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkRigidBody::~bhkRigidBody() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkRigidBody::GetType() const {
	return TYPE;
}

NiObject * bhkRigidBody::Create() {
	return new bhkRigidBody;
}

void bhkRigidBody::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkEntity::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknown3Ints[i1], in, info );
	};
	NifStream( collisionResponse_, in, info );
	NifStream( unknownByte, in, info );
	NifStream( processContactCallbackDelay_, in, info );
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknown2Shorts[i1], in, info );
	};
	NifStream( layerCopy, in, info );
	NifStream( colFilterCopy, in, info );
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		NifStream( unknown7Shorts[i1], in, info );
	};
	NifStream( translation, in, info );
	NifStream( rotation.x, in, info );
	NifStream( rotation.y, in, info );
	NifStream( rotation.z, in, info );
	NifStream( rotation.w, in, info );
	NifStream( linearVelocity, in, info );
	NifStream( angularVelocity, in, info );
	NifStream( inertia, in, info );
	NifStream( center, in, info );
	NifStream( mass, in, info );
	NifStream( linearDamping, in, info );
	NifStream( angularDamping, in, info );
	NifStream( friction, in, info );
	NifStream( restitution, in, info );
	NifStream( maxLinearVelocity, in, info );
	NifStream( maxAngularVelocity, in, info );
	NifStream( penetrationDepth, in, info );
	NifStream( motionSystem, in, info );
	NifStream( deactivatorType, in, info );
	NifStream( solverDeactivation, in, info );
	NifStream( qualityType, in, info );
	NifStream( autoRemoveLevel, in, info );
	NifStream( userDatasInContactPointProperties_, in, info );
	NifStream( forceCollideOntoPpu_, in, info );
	NifStream( numConstraints, in, info );
	constraints.resize(numConstraints);
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( unknownInt9, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkRigidBody::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkEntity::Write( out, link_map, info );
	numConstraints = (unsigned int)(constraints.size());
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknown3Ints[i1], out, info );
	};
	NifStream( collisionResponse_, out, info );
	NifStream( unknownByte, out, info );
	NifStream( processContactCallbackDelay_, out, info );
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknown2Shorts[i1], out, info );
	};
	NifStream( layerCopy, out, info );
	NifStream( colFilterCopy, out, info );
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		NifStream( unknown7Shorts[i1], out, info );
	};
	NifStream( translation, out, info );
	NifStream( rotation.x, out, info );
	NifStream( rotation.y, out, info );
	NifStream( rotation.z, out, info );
	NifStream( rotation.w, out, info );
	NifStream( linearVelocity, out, info );
	NifStream( angularVelocity, out, info );
	NifStream( inertia, out, info );
	NifStream( center, out, info );
	NifStream( mass, out, info );
	NifStream( linearDamping, out, info );
	NifStream( angularDamping, out, info );
	NifStream( friction, out, info );
	NifStream( restitution, out, info );
	NifStream( maxLinearVelocity, out, info );
	NifStream( maxAngularVelocity, out, info );
	NifStream( penetrationDepth, out, info );
	NifStream( motionSystem, out, info );
	NifStream( deactivatorType, out, info );
	NifStream( solverDeactivation, out, info );
	NifStream( qualityType, out, info );
	NifStream( autoRemoveLevel, out, info );
	NifStream( userDatasInContactPointProperties_, out, info );
	NifStream( forceCollideOntoPpu_, out, info );
	NifStream( numConstraints, out, info );
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		if ( info.version < VER_3_3_0_13 ) {
			NifStream( (unsigned int)&(*constraints[i1]), out, info );
		} else {
			if ( constraints[i1] != NULL ) {
				NifStream( link_map.find( StaticCast<NiObject>(constraints[i1]) )->second, out, info );
			} else {
				NifStream( 0xFFFFFFFF, out, info );
			}
		}
	};
	NifStream( unknownInt9, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkRigidBody::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkEntity::asString();
	numConstraints = (unsigned int)(constraints.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 3 Ints[" << i1 << "]:  " << unknown3Ints[i1] << endl;
		array_output_count++;
	};
	out << "  Collision Response?:  " << collisionResponse_ << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Process Contact Callback Delay?:  " << processContactCallbackDelay_ << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 2 Shorts[" << i1 << "]:  " << unknown2Shorts[i1] << endl;
		array_output_count++;
	};
	out << "  Layer Copy:  " << layerCopy << endl;
	out << "  Col Filter Copy:  " << colFilterCopy << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 7 Shorts[" << i1 << "]:  " << unknown7Shorts[i1] << endl;
		array_output_count++;
	};
	out << "  Translation:  " << translation << endl;
	out << "  x:  " << rotation.x << endl;
	out << "  y:  " << rotation.y << endl;
	out << "  z:  " << rotation.z << endl;
	out << "  w:  " << rotation.w << endl;
	out << "  Linear Velocity:  " << linearVelocity << endl;
	out << "  Angular Velocity:  " << angularVelocity << endl;
	out << "  Inertia:  " << inertia << endl;
	out << "  Center:  " << center << endl;
	out << "  Mass:  " << mass << endl;
	out << "  Linear Damping:  " << linearDamping << endl;
	out << "  Angular Damping:  " << angularDamping << endl;
	out << "  Friction:  " << friction << endl;
	out << "  Restitution:  " << restitution << endl;
	out << "  Max Linear Velocity:  " << maxLinearVelocity << endl;
	out << "  Max Angular Velocity:  " << maxAngularVelocity << endl;
	out << "  Penetration Depth:  " << penetrationDepth << endl;
	out << "  Motion System:  " << motionSystem << endl;
	out << "  Deactivator Type:  " << deactivatorType << endl;
	out << "  Solver Deactivation:  " << solverDeactivation << endl;
	out << "  Quality Type:  " << qualityType << endl;
	out << "  Auto Remove Level:  " << autoRemoveLevel << endl;
	out << "  User Datas In Contact Point Properties?:  " << userDatasInContactPointProperties_ << endl;
	out << "  Force Collide Onto Ppu?:  " << forceCollideOntoPpu_ << endl;
	out << "  Num Constraints:  " << numConstraints << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Constraints[" << i1 << "]:  " << constraints[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Int 9:  " << unknownInt9 << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkRigidBody::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkEntity::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		constraints[i1] = FixLink<bhkSerializable>( objects, link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkRigidBody::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkEntity::GetRefs();
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		if ( constraints[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(constraints[i1]));
	};
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

OblivionLayer bhkRigidBody::GetLayerCopy() const {
	return layerCopy;
}

void bhkRigidBody::SetLayerCopy( OblivionLayer value ) {
	layerCopy = value;
}

Vector4 bhkRigidBody::GetTranslation() const {
	return translation;
}

void bhkRigidBody::SetTranslation( const Vector4 & value ) {
	translation = value;
}

QuaternionXYZW bhkRigidBody::GetRotation() const {
	return rotation;
}

void bhkRigidBody::SetRotation( const QuaternionXYZW & value ) {
	rotation = value;
}

Vector4 bhkRigidBody::GetLinearVelocity() const {
	return linearVelocity;
}

void bhkRigidBody::SetLinearVelocity( const Vector4 & value ) {
	linearVelocity = value;
}

Vector4 bhkRigidBody::GetAngularVelocity() const {
	return angularVelocity;
}

void bhkRigidBody::SetAngularVelocity( const Vector4 & value ) {
	angularVelocity = value;
}

InertiaMatrix  bhkRigidBody::GetInertia() const {
	return inertia;
}

void bhkRigidBody::SetInertia( const InertiaMatrix&  value ) {
	inertia = value;
}

Vector4 bhkRigidBody::GetCenter() const {
	return center;
}

void bhkRigidBody::SetCenter( const Vector4 & value ) {
	center = value;
}

float bhkRigidBody::GetMass() const {
	return mass;
}

void bhkRigidBody::SetMass( float value ) {
	mass = value;
}

float bhkRigidBody::GetLinearDamping() const {
	return linearDamping;
}

void bhkRigidBody::SetLinearDamping( float value ) {
	linearDamping = value;
}

float bhkRigidBody::GetAngularDamping() const {
	return angularDamping;
}

void bhkRigidBody::SetAngularDamping( float value ) {
	angularDamping = value;
}

float bhkRigidBody::GetFriction() const {
	return friction;
}

void bhkRigidBody::SetFriction( float value ) {
	friction = value;
}

float bhkRigidBody::GetRestitution() const {
	return restitution;
}

void bhkRigidBody::SetRestitution( float value ) {
	restitution = value;
}

float bhkRigidBody::GetMaxLinearVelocity() const {
	return maxLinearVelocity;
}

void bhkRigidBody::SetMaxLinearVelocity( float value ) {
	maxLinearVelocity = value;
}

float bhkRigidBody::GetMaxAngularVelocity() const {
	return maxAngularVelocity;
}

void bhkRigidBody::SetMaxAngularVelocity( float value ) {
	maxAngularVelocity = value;
}

float bhkRigidBody::GetPenetrationDepth() const {
	return penetrationDepth;
}

void bhkRigidBody::SetPenetrationDepth( float value ) {
	penetrationDepth = value;
}

MotionSystem bhkRigidBody::GetMotionSystem() const {
	return motionSystem;
}

void bhkRigidBody::SetMotionSystem( MotionSystem value ) {
	motionSystem = value;
}

MotionQuality bhkRigidBody::GetQualityType() const {
	return qualityType;
}

void bhkRigidBody::SetQualityType( MotionQuality value ) {
	qualityType = value;
}

DeactivatorType bhkRigidBody::GetDeactivatorType() const {
	return deactivatorType;
}

void bhkRigidBody::SetDeactivatorType( const DeactivatorType & value ) {
	deactivatorType = value;
}

SolverDeactivation bhkRigidBody::GetSolverDeactivation() const {
	return solverDeactivation;
}

void bhkRigidBody::SetSolverDeactivation( const SolverDeactivation & value ) {
	solverDeactivation = value;
}



// Apply scale factor <scale> on data.
void bhkRigidBody::ApplyScale(float scale)
{
    // apply scale on transform
    translation *= scale;

    // apply scale on center of gravity
    center *= scale;

    // apply scale on inertia tensor
    inertia *= pow(scale, 2.0f);

    //# apply scale on all blocks down the hierarchy
    //ApplyScale(scale)
}

void bhkRigidBody::UpdateMassProperties(float density, bool solid, float mass)
{
    // Look at all the objects under this rigid body and update the mass
    //  center of gravity, and inertia tensor accordingly. If the C{mass} parameter
    //  is given then the C{density} argument is ignored.

	if (mass != 0.0f)
        density = 1.0f;

	if (shape != NULL)
	{
		float volume;
		Vector3 com;
		shape->CalcMassProperties(density, solid, this->mass, volume, com, inertia);
		center = com;
		if (mass != 0.0f)
		{
			float mass_correction = (this->mass != 0.0f) ? mass / this->mass : 1.0f;
			this->mass = mass;
			inertia *= mass_correction;
		}
	}
}

//--END CUSTOM CODE--//
