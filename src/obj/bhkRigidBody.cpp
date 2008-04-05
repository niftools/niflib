/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/bhkRigidBody.h"
#include "../../include/gen/QuaternionXYZW.h"
#include "../../include/gen/InertiaMatrix.h"
#include "../../include/obj/bhkConstraint.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkRigidBody::TYPE("bhkRigidBody", &bhkEntity::TYPE );

bhkRigidBody::bhkRigidBody() : layerCopy((OblivionLayer)1), colFilterCopy((byte)0), unknownFloat00(0.0f), unknownFloat01(0.0f), unknownFloat02(0.0f), unknownFloat03(0.0f), mass(0.0f), linearDamping(0.1f), angularDamping(0.1f), friction(0.3f), restitution(0.3f), maxLinearVelocity(250.0f), maxAngularVelocity(31.415926535f), penetrationDepth(0.15f), motionSystem((MotionSystem)7), unknownByte1((byte)1), unknownByte2((byte)1), qualityType((MotionQuality)1), unknownInt6((unsigned int)0), unknownInt7((unsigned int)0), unknownInt8((unsigned int)0), numConstraints((unsigned int)0), unknownInt9((unsigned int)0) {
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
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		NifStream( unknown5Floats[i1], in, info );
	};
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Shorts[i1], in, info );
	};
	NifStream( layerCopy, in, info );
	NifStream( colFilterCopy, in, info );
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		NifStream( unknown7Shorts[i1], in, info );
	};
	NifStream( translation, in, info );
	NifStream( unknownFloat00, in, info );
	NifStream( rotation.x, in, info );
	NifStream( rotation.y, in, info );
	NifStream( rotation.z, in, info );
	NifStream( rotation.w, in, info );
	NifStream( linearVelocity, in, info );
	NifStream( unknownFloat01, in, info );
	NifStream( angularVelocity, in, info );
	NifStream( unknownFloat02, in, info );
	NifStream( inertia.m11, in, info );
	NifStream( inertia.m12, in, info );
	NifStream( inertia.m13, in, info );
	NifStream( inertia.m14, in, info );
	NifStream( inertia.m21, in, info );
	NifStream( inertia.m22, in, info );
	NifStream( inertia.m23, in, info );
	NifStream( inertia.m24, in, info );
	NifStream( inertia.m31, in, info );
	NifStream( inertia.m32, in, info );
	NifStream( inertia.m33, in, info );
	NifStream( inertia.m34, in, info );
	NifStream( center, in, info );
	NifStream( unknownFloat03, in, info );
	NifStream( mass, in, info );
	NifStream( linearDamping, in, info );
	NifStream( angularDamping, in, info );
	NifStream( friction, in, info );
	NifStream( restitution, in, info );
	NifStream( maxLinearVelocity, in, info );
	NifStream( maxAngularVelocity, in, info );
	NifStream( penetrationDepth, in, info );
	NifStream( motionSystem, in, info );
	NifStream( unknownByte1, in, info );
	NifStream( unknownByte2, in, info );
	NifStream( qualityType, in, info );
	NifStream( unknownInt6, in, info );
	NifStream( unknownInt7, in, info );
	NifStream( unknownInt8, in, info );
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
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		NifStream( unknown5Floats[i1], out, info );
	};
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Shorts[i1], out, info );
	};
	NifStream( layerCopy, out, info );
	NifStream( colFilterCopy, out, info );
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		NifStream( unknown7Shorts[i1], out, info );
	};
	NifStream( translation, out, info );
	NifStream( unknownFloat00, out, info );
	NifStream( rotation.x, out, info );
	NifStream( rotation.y, out, info );
	NifStream( rotation.z, out, info );
	NifStream( rotation.w, out, info );
	NifStream( linearVelocity, out, info );
	NifStream( unknownFloat01, out, info );
	NifStream( angularVelocity, out, info );
	NifStream( unknownFloat02, out, info );
	NifStream( inertia.m11, out, info );
	NifStream( inertia.m12, out, info );
	NifStream( inertia.m13, out, info );
	NifStream( inertia.m14, out, info );
	NifStream( inertia.m21, out, info );
	NifStream( inertia.m22, out, info );
	NifStream( inertia.m23, out, info );
	NifStream( inertia.m24, out, info );
	NifStream( inertia.m31, out, info );
	NifStream( inertia.m32, out, info );
	NifStream( inertia.m33, out, info );
	NifStream( inertia.m34, out, info );
	NifStream( center, out, info );
	NifStream( unknownFloat03, out, info );
	NifStream( mass, out, info );
	NifStream( linearDamping, out, info );
	NifStream( angularDamping, out, info );
	NifStream( friction, out, info );
	NifStream( restitution, out, info );
	NifStream( maxLinearVelocity, out, info );
	NifStream( maxAngularVelocity, out, info );
	NifStream( penetrationDepth, out, info );
	NifStream( motionSystem, out, info );
	NifStream( unknownByte1, out, info );
	NifStream( unknownByte2, out, info );
	NifStream( qualityType, out, info );
	NifStream( unknownInt6, out, info );
	NifStream( unknownInt7, out, info );
	NifStream( unknownInt8, out, info );
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
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 5 Floats[" << i1 << "]:  " << unknown5Floats[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 4 Shorts[" << i1 << "]:  " << unknown4Shorts[i1] << endl;
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
	out << "  Unknown Float 00:  " << unknownFloat00 << endl;
	out << "  x:  " << rotation.x << endl;
	out << "  y:  " << rotation.y << endl;
	out << "  z:  " << rotation.z << endl;
	out << "  w:  " << rotation.w << endl;
	out << "  Linear Velocity:  " << linearVelocity << endl;
	out << "  Unknown Float 01:  " << unknownFloat01 << endl;
	out << "  Angular Velocity:  " << angularVelocity << endl;
	out << "  Unknown Float 02:  " << unknownFloat02 << endl;
	out << "  m11:  " << inertia.m11 << endl;
	out << "  m12:  " << inertia.m12 << endl;
	out << "  m13:  " << inertia.m13 << endl;
	out << "  m14:  " << inertia.m14 << endl;
	out << "  m21:  " << inertia.m21 << endl;
	out << "  m22:  " << inertia.m22 << endl;
	out << "  m23:  " << inertia.m23 << endl;
	out << "  m24:  " << inertia.m24 << endl;
	out << "  m31:  " << inertia.m31 << endl;
	out << "  m32:  " << inertia.m32 << endl;
	out << "  m33:  " << inertia.m33 << endl;
	out << "  m34:  " << inertia.m34 << endl;
	out << "  Center:  " << center << endl;
	out << "  Unknown Float 03:  " << unknownFloat03 << endl;
	out << "  Mass:  " << mass << endl;
	out << "  Linear Damping:  " << linearDamping << endl;
	out << "  Angular Damping:  " << angularDamping << endl;
	out << "  Friction:  " << friction << endl;
	out << "  Restitution:  " << restitution << endl;
	out << "  Max Linear Velocity:  " << maxLinearVelocity << endl;
	out << "  Max Angular Velocity:  " << maxAngularVelocity << endl;
	out << "  Penetration Depth:  " << penetrationDepth << endl;
	out << "  Motion System:  " << motionSystem << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Quality Type:  " << qualityType << endl;
	out << "  Unknown Int 6:  " << unknownInt6 << endl;
	out << "  Unknown Int 7:  " << unknownInt7 << endl;
	out << "  Unknown Int 8:  " << unknownInt8 << endl;
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
		constraints[i1] = FixLink<bhkConstraint>( objects, link_stack, info );
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

Vector3 bhkRigidBody::GetTranslation() const {
	return translation;
}

void bhkRigidBody::SetTranslation( const Vector3 & value ) {
	translation = value;
}

QuaternionXYZW bhkRigidBody::GetRotation() const {
	return rotation;
}

void bhkRigidBody::SetRotation( const QuaternionXYZW & value ) {
	rotation = value;
}

Vector3 bhkRigidBody::GetLinearVelocity() const {
	return linearVelocity;
}

void bhkRigidBody::SetLinearVelocity( const Vector3 & value ) {
	linearVelocity = value;
}

Vector3 bhkRigidBody::GetAngularVelocity() const {
	return angularVelocity;
}

void bhkRigidBody::SetAngularVelocity( const Vector3 & value ) {
	angularVelocity = value;
}

array<12,float>  bhkRigidBody::GetInertia() const {
	return inertia;
}

void bhkRigidBody::SetInertia( const array<12,float>&  value ) {
	inertia = value;
}

Vector3 bhkRigidBody::GetCenter() const {
	return center;
}

void bhkRigidBody::SetCenter( const Vector3 & value ) {
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

//--END CUSTOM CODE--//
