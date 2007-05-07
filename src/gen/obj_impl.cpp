/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/nifxml_niflib.py Python script.

#include "../../include/obj/NiObject.h"
using namespace Niflib;
using namespace std;

#include "../../include/obj/bhkBlendCollisionObject.h"
#include "../../include/obj/bhkBlendController.h"
#include "../../include/obj/bhkBoxShape.h"
#include "../../include/obj/bhkCapsuleShape.h"
#include "../../include/obj/bhkCollisionObject.h"
#include "../../include/obj/bhkConvexVerticesShape.h"
#include "../../include/obj/bhkHingeConstraint.h"
#include "../../include/obj/bhkLimitedHingeConstraint.h"
#include "../../include/obj/bhkListShape.h"
#include "../../include/obj/bhkMalleableConstraint.h"
#include "../../include/obj/bhkMoppBvTreeShape.h"
#include "../../include/obj/bhkMultiSphereShape.h"
#include "../../include/obj/bhkNiTriStripsShape.h"
#include "../../include/obj/bhkMeshShape.h"
#include "../../include/obj/bhkPackedNiTriStripsShape.h"
#include "../../include/obj/bhkPrismaticConstraint.h"
#include "../../include/obj/bhkRagdollConstraint.h"
#include "../../include/obj/bhkRigidBody.h"
#include "../../include/obj/bhkRigidBodyT.h"
#include "../../include/obj/bhkSimpleShapePhantom.h"
#include "../../include/obj/bhkSPCollisionObject.h"
#include "../../include/obj/bhkSphereShape.h"
#include "../../include/obj/bhkStiffSpringConstraint.h"
#include "../../include/obj/bhkTransformShape.h"
#include "../../include/obj/bhkConvexTransformShape.h"
#include "../../include/obj/BSBound.h"
#include "../../include/obj/BSFurnitureMarker.h"
#include "../../include/obj/BSParentVelocityModifier.h"
#include "../../include/obj/BSPSysArrayEmitter.h"
#include "../../include/obj/BSXFlags.h"
#include "../../include/obj/hkPackedNiTriStripsData.h"
#include "../../include/obj/NiAlphaController.h"
#include "../../include/obj/NiAlphaProperty.h"
#include "../../include/obj/NiAmbientLight.h"
#include "../../include/obj/NiAutoNormalParticlesData.h"
#include "../../include/obj/NiBinaryExtraData.h"
#include "../../include/obj/NiBlendBoolInterpolator.h"
#include "../../include/obj/NiBlendFloatInterpolator.h"
#include "../../include/obj/NiBlendPoint3Interpolator.h"
#include "../../include/obj/NiBlendTransformInterpolator.h"
#include "../../include/obj/NiBoneLODController.h"
#include "../../include/obj/NiBoolData.h"
#include "../../include/obj/NiBooleanExtraData.h"
#include "../../include/obj/NiBoolInterpolator.h"
#include "../../include/obj/NiBoolTimelineInterpolator.h"
#include "../../include/obj/NiBSBoneLODController.h"
#include "../../include/obj/NiBSplineBasisData.h"
#include "../../include/obj/NiBSplineCompFloatInterpolator.h"
#include "../../include/obj/NiBSplineCompPoint3Interpolator.h"
#include "../../include/obj/NiBSplineCompTransformInterpolator.h"
#include "../../include/obj/NiBSplineData.h"
#include "../../include/obj/NiCamera.h"
#include "../../include/obj/NiCollisionData.h"
#include "../../include/obj/NiColorData.h"
#include "../../include/obj/NiColorExtraData.h"
#include "../../include/obj/NiControllerManager.h"
#include "../../include/obj/NiSequence.h"
#include "../../include/obj/NiControllerSequence.h"
#include "../../include/obj/NiDefaultAVObjectPalette.h"
#include "../../include/obj/NiDirectionalLight.h"
#include "../../include/obj/NiDitherProperty.h"
#include "../../include/obj/NiFlipController.h"
#include "../../include/obj/NiRollController.h"
#include "../../include/obj/NiFloatData.h"
#include "../../include/obj/NiFloatExtraData.h"
#include "../../include/obj/NiFloatExtraDataController.h"
#include "../../include/obj/NiFloatInterpolator.h"
#include "../../include/obj/NiFloatsExtraData.h"
#include "../../include/obj/NiFogProperty.h"
#include "../../include/obj/NiGeomMorpherController.h"
#include "../../include/obj/NiGravity.h"
#include "../../include/obj/NiIntegerExtraData.h"
#include "../../include/obj/NiIntegersExtraData.h"
#include "../../include/obj/NiKeyframeController.h"
#include "../../include/obj/BSKeyframeController.h"
#include "../../include/obj/NiKeyframeData.h"
#include "../../include/obj/NiLightColorController.h"
#include "../../include/obj/NiLightDimmerController.h"
#include "../../include/obj/NiLookAtController.h"
#include "../../include/obj/NiLookAtInterpolator.h"
#include "../../include/obj/NiMaterialColorController.h"
#include "../../include/obj/NiMaterialProperty.h"
#include "../../include/obj/NiMeshPSysData.h"
#include "../../include/obj/NiMorphData.h"
#include "../../include/obj/NiMultiTargetTransformController.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/AvoidNode.h"
#include "../../include/obj/FxWidget.h"
#include "../../include/obj/FxButton.h"
#include "../../include/obj/FxRadioButton.h"
#include "../../include/obj/NiBillboardNode.h"
#include "../../include/obj/NiBSAnimationNode.h"
#include "../../include/obj/NiBSParticleNode.h"
#include "../../include/obj/NiLODNode.h"
#include "../../include/obj/NiPalette.h"
#include "../../include/obj/NiParticleBomb.h"
#include "../../include/obj/NiParticleColorModifier.h"
#include "../../include/obj/NiParticleGrowFade.h"
#include "../../include/obj/NiParticleMeshModifier.h"
#include "../../include/obj/NiParticleRotation.h"
#include "../../include/obj/NiParticles.h"
#include "../../include/obj/NiAutoNormalParticles.h"
#include "../../include/obj/NiParticleMeshes.h"
#include "../../include/obj/NiParticlesData.h"
#include "../../include/obj/NiParticleMeshesData.h"
#include "../../include/obj/NiParticleSystem.h"
#include "../../include/obj/NiMeshParticleSystem.h"
#include "../../include/obj/NiParticleSystemController.h"
#include "../../include/obj/NiBSPArrayController.h"
#include "../../include/obj/NiPathController.h"
#include "../../include/obj/NiPathInterpolator.h"
#include "../../include/obj/NiPixelData.h"
#include "../../include/obj/NiPlanarCollider.h"
#include "../../include/obj/NiPoint3Interpolator.h"
#include "../../include/obj/NiPointLight.h"
#include "../../include/obj/NiPosData.h"
#include "../../include/obj/NiPSysAgeDeathModifier.h"
#include "../../include/obj/NiPSysBombModifier.h"
#include "../../include/obj/NiPSysBoundUpdateModifier.h"
#include "../../include/obj/NiPSysBoxEmitter.h"
#include "../../include/obj/NiPSysColliderManager.h"
#include "../../include/obj/NiPSysColorModifier.h"
#include "../../include/obj/NiPSysCylinderEmitter.h"
#include "../../include/obj/NiPSysData.h"
#include "../../include/obj/NiPSysDragModifier.h"
#include "../../include/obj/NiPSysEmitterCtlr.h"
#include "../../include/obj/NiPSysEmitterCtlrData.h"
#include "../../include/obj/NiPSysEmitterDeclinationCtlr.h"
#include "../../include/obj/NiPSysEmitterDeclinationVarCtlr.h"
#include "../../include/obj/NiPSysEmitterInitialRadiusCtlr.h"
#include "../../include/obj/NiPSysEmitterLifeSpanCtlr.h"
#include "../../include/obj/NiPSysEmitterSpeedCtlr.h"
#include "../../include/obj/NiPSysGravityModifier.h"
#include "../../include/obj/NiPSysGravityStrengthCtlr.h"
#include "../../include/obj/NiPSysGrowFadeModifier.h"
#include "../../include/obj/NiPSysMeshEmitter.h"
#include "../../include/obj/NiPSysMeshUpdateModifier.h"
#include "../../include/obj/NiPSysModifierActiveCtlr.h"
#include "../../include/obj/NiPSysPlanarCollider.h"
#include "../../include/obj/NiPSysPositionModifier.h"
#include "../../include/obj/NiPSysResetOnLoopCtlr.h"
#include "../../include/obj/NiPSysRotationModifier.h"
#include "../../include/obj/NiPSysSpawnModifier.h"
#include "../../include/obj/NiPSysSphereEmitter.h"
#include "../../include/obj/NiPSysUpdateCtlr.h"
#include "../../include/obj/NiRangeLODData.h"
#include "../../include/obj/NiScreenLODData.h"
#include "../../include/obj/NiRotatingParticles.h"
#include "../../include/obj/NiRotatingParticlesData.h"
#include "../../include/obj/NiSequenceStreamHelper.h"
#include "../../include/obj/NiShadeProperty.h"
#include "../../include/obj/NiSkinData.h"
#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiClodSkinInstance.h"
#include "../../include/obj/NiSkinPartition.h"
#include "../../include/obj/NiSourceTexture.h"
#include "../../include/obj/NiSpecularProperty.h"
#include "../../include/obj/NiSphericalCollider.h"
#include "../../include/obj/NiSpotLight.h"
#include "../../include/obj/NiStencilProperty.h"
#include "../../include/obj/NiStringExtraData.h"
#include "../../include/obj/NiStringPalette.h"
#include "../../include/obj/NiStringsExtraData.h"
#include "../../include/obj/NiTextKeyExtraData.h"
#include "../../include/obj/NiTextureEffect.h"
#include "../../include/obj/NiTextureTransformController.h"
#include "../../include/obj/NiTextureModeProperty.h"
#include "../../include/obj/NiImage.h"
#include "../../include/obj/NiTextureProperty.h"
#include "../../include/obj/NiMultiTextureProperty.h"
#include "../../include/obj/NiTexturingProperty.h"
#include "../../include/obj/NiTransformController.h"
#include "../../include/obj/NiTransformData.h"
#include "../../include/obj/NiTransformInterpolator.h"
#include "../../include/obj/NiTriShape.h"
#include "../../include/obj/NiTriShapeData.h"
#include "../../include/obj/NiTriStrips.h"
#include "../../include/obj/NiTriStripsData.h"
#include "../../include/obj/NiClod.h"
#include "../../include/obj/NiClodData.h"
#include "../../include/obj/NiUVController.h"
#include "../../include/obj/NiUVData.h"
#include "../../include/obj/NiVectorExtraData.h"
#include "../../include/obj/NiVertexColorProperty.h"
#include "../../include/obj/NiVertWeightsExtraData.h"
#include "../../include/obj/NiVisController.h"
#include "../../include/obj/NiVisData.h"
#include "../../include/obj/NiWireframeProperty.h"
#include "../../include/obj/NiZBufferProperty.h"
#include "../../include/obj/RootCollisionNode.h"
#include "../../include/obj/NiRawImageData.h"

const char FIX_LINK_POP_ERROR[] = "Trying to pop a link from empty stack. This is probably a bug.";
const char FIX_LINK_INDEX_ERROR[] = "Object index was not found in object map.  This NIF file may be invalid or imporperly supported.";
const char FIX_LINK_CAST_ERROR[] = "Link could not be cast to required type during file read. This NIF file may be invalid or improperly supported.";

template <class T>
Ref<T> FixLink( const map<unsigned,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	if (link_stack.empty()) {
		throw runtime_error(FIX_LINK_POP_ERROR);
	}
	unsigned int index = link_stack.front();
	link_stack.pop_front();

	//Check if link is NULL
	if ( info.version >= VER_3_3_0_13) {
		if ( index == 0xFFFFFFFF) {
			return NULL;
		}
	} else {
		if ( index == 0 ) {
			return NULL;
		}
	}

	map<unsigned int,NiObjectRef>::const_iterator it = objects.find(index);
	if ( it == objects.end() ) {
		throw runtime_error(FIX_LINK_INDEX_ERROR);
	}
		
	Ref<T> object = DynamicCast<T>(it->second);
	if ( object == NULL ) {
		stringstream ss;
		ss << FIX_LINK_CAST_ERROR << endl;
		ss << "Type of object with index " << index << " was:  " << it->second->GetType().GetTypeName() << endl;
		ss << "Required type was:  " << T::TYPE.GetTypeName() << endl;
		throw runtime_error( ss.str().c_str() );
	}

	return object;
}

void NiObject::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
}

void NiObject::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
}

std::string NiObject::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	return out.str();
}

void NiObject::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
}

std::list<NiObjectRef> NiObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	return refs;
}

void AKeyedData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
}

void AKeyedData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
}

std::string AKeyedData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	return out.str();
}

void AKeyedData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> AKeyedData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void AParticleModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x04000002 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void AParticleModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	if ( nextModifier != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(nextModifier) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x04000002 ) {
		if ( controller != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(controller) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string AParticleModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Next Modifier:  " << nextModifier << endl;
	out << "  Controller:  " << controller << endl;
	return out.str();
}

void AParticleModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	nextModifier = FixLink<AParticleModifier>( objects, link_stack, info );
	if ( info.version >= 0x04000002 ) {
		controller = FixLink<NiParticleSystemController>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> AParticleModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextModifier != NULL )
		refs.push_back(StaticCast<NiObject>(nextModifier));
	return refs;
}

void bhkRefObject::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
}

void bhkRefObject::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
}

std::string bhkRefObject::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	return out.str();
}

void bhkRefObject::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkRefObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void bhkSerializable::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkRefObject::Read( in, link_stack, info );
}

void bhkSerializable::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkRefObject::Write( out, link_map, info );
}

std::string bhkSerializable::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkRefObject::asString();
	return out.str();
}

void bhkSerializable::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkRefObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkSerializable::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkRefObject::GetRefs();
	return refs;
}

void AbhkConstraint::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	bhkSerializable::Read( in, link_stack, info );
	NifStream( numBodies, in, info );
	bodies.resize(numBodies);
	for (unsigned int i1 = 0; i1 < bodies.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( priority, in, info );
}

void AbhkConstraint::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkSerializable::Write( out, link_map, info );
	numBodies = (unsigned int)(bodies.size());
	NifStream( numBodies, out, info );
	for (unsigned int i1 = 0; i1 < bodies.size(); i1++) {
		if ( bodies[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(bodies[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( priority, out, info );
}

std::string AbhkConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSerializable::asString();
	numBodies = (unsigned int)(bodies.size());
	out << "  Num Bodies:  " << numBodies << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < bodies.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Bodies[" << i1 << "]:  " << bodies[i1] << endl;
		array_output_count++;
	};
	out << "  Priority:  " << priority << endl;
	return out.str();
}

void AbhkConstraint::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSerializable::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < bodies.size(); i1++) {
		bodies[i1] = FixLink<bhkShape>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> AbhkConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSerializable::GetRefs();
	for (unsigned int i1 = 0; i1 < bodies.size(); i1++) {
	};
	return refs;
}

void AbhkRagdollConstraint::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::Read( in, link_stack, info );
	NifStream( ragdoll.pivotA, in, info );
	NifStream( ragdoll.planeA, in, info );
	NifStream( ragdoll.twistA, in, info );
	NifStream( ragdoll.pivotB, in, info );
	NifStream( ragdoll.planeB, in, info );
	NifStream( ragdoll.twistB, in, info );
	NifStream( ragdoll.coneMinAngle, in, info );
	NifStream( ragdoll.planeMinAngle, in, info );
	NifStream( ragdoll.planeMaxAngle, in, info );
	NifStream( ragdoll.twistMinAngle, in, info );
	NifStream( ragdoll.twistMaxAngle, in, info );
	NifStream( ragdoll.maxFriction, in, info );
}

void AbhkRagdollConstraint::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkConstraint::Write( out, link_map, info );
	NifStream( ragdoll.pivotA, out, info );
	NifStream( ragdoll.planeA, out, info );
	NifStream( ragdoll.twistA, out, info );
	NifStream( ragdoll.pivotB, out, info );
	NifStream( ragdoll.planeB, out, info );
	NifStream( ragdoll.twistB, out, info );
	NifStream( ragdoll.coneMinAngle, out, info );
	NifStream( ragdoll.planeMinAngle, out, info );
	NifStream( ragdoll.planeMaxAngle, out, info );
	NifStream( ragdoll.twistMinAngle, out, info );
	NifStream( ragdoll.twistMaxAngle, out, info );
	NifStream( ragdoll.maxFriction, out, info );
}

std::string AbhkRagdollConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkConstraint::asString();
	out << "  Pivot A:  " << ragdoll.pivotA << endl;
	out << "  Plane A:  " << ragdoll.planeA << endl;
	out << "  Twist A:  " << ragdoll.twistA << endl;
	out << "  Pivot B:  " << ragdoll.pivotB << endl;
	out << "  Plane B:  " << ragdoll.planeB << endl;
	out << "  Twist B:  " << ragdoll.twistB << endl;
	out << "  Cone Min Angle:  " << ragdoll.coneMinAngle << endl;
	out << "  Plane Min Angle:  " << ragdoll.planeMinAngle << endl;
	out << "  Plane Max Angle:  " << ragdoll.planeMaxAngle << endl;
	out << "  Twist Min Angle:  " << ragdoll.twistMinAngle << endl;
	out << "  Twist Max Angle:  " << ragdoll.twistMaxAngle << endl;
	out << "  Max Friction:  " << ragdoll.maxFriction << endl;
	return out.str();
}

void AbhkRagdollConstraint::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> AbhkRagdollConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSerializable::Read( in, link_stack, info );
}

void bhkShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkSerializable::Write( out, link_map, info );
}

std::string bhkShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSerializable::asString();
	return out.str();
}

void bhkShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSerializable::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSerializable::GetRefs();
	return refs;
}

void AbhkShapeCollection::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkShape::Read( in, link_stack, info );
}

void AbhkShapeCollection::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkShape::Write( out, link_map, info );
}

std::string AbhkShapeCollection::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShape::asString();
	return out.str();
}

void AbhkShapeCollection::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> AbhkShapeCollection::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	return refs;
}

void bhkSphereRepShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkShape::Read( in, link_stack, info );
	NifStream( material, in, info );
}

void bhkSphereRepShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkShape::Write( out, link_map, info );
	NifStream( material, out, info );
}

std::string bhkSphereRepShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShape::asString();
	out << "  Material:  " << material << endl;
	return out.str();
}

void bhkSphereRepShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkSphereRepShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	return refs;
}

void bhkConvexShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSphereRepShape::Read( in, link_stack, info );
}

void bhkConvexShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkSphereRepShape::Write( out, link_map, info );
}

std::string bhkConvexShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSphereRepShape::asString();
	return out.str();
}

void bhkConvexShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkConvexShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	return refs;
}

void bhkWorldObject::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkShape::Read( in, link_stack, info );
}

void bhkWorldObject::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkShape::Write( out, link_map, info );
}

std::string bhkWorldObject::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShape::asString();
	return out.str();
}

void bhkWorldObject::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkWorldObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	return refs;
}

void bhkEntity::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	bhkWorldObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( layer, in, info );
	NifStream( colFilter, in, info );
	NifStream( unknownShort, in, info );
}

void bhkEntity::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkWorldObject::Write( out, link_map, info );
	if ( shape != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(shape) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( layer, out, info );
	NifStream( colFilter, out, info );
	NifStream( unknownShort, out, info );
}

std::string bhkEntity::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkWorldObject::asString();
	out << "  Shape:  " << shape << endl;
	out << "  Layer:  " << layer << endl;
	out << "  Col Filter:  " << colFilter << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	return out.str();
}

void bhkEntity::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkWorldObject::FixLinks( objects, link_stack, info );
	shape = FixLink<bhkShape>( objects, link_stack, info );
}

std::list<NiObjectRef> bhkEntity::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkWorldObject::GetRefs();
	if ( shape != NULL )
		refs.push_back(StaticCast<NiObject>(shape));
	return refs;
}

void NiCollisionObject::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownShort, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiCollisionObject::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	if ( parent != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(parent) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownShort, out, info );
	if ( body != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(body) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiCollisionObject::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Parent:  " << parent << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Body:  " << body << endl;
	return out.str();
}

void NiCollisionObject::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	parent = FixLink<NiAVObject>( objects, link_stack, info );
	body = FixLink<NiObject>( objects, link_stack, info );
}

std::list<NiObjectRef> NiCollisionObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( body != NULL )
		refs.push_back(StaticCast<NiObject>(body));
	return refs;
}

void NiExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	if ( info.version >= 0x0A000100 ) {
		NifStream( name, in, info );
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	if ( info.version >= 0x0A000100 ) {
		NifStream( name, out, info );
	};
	if ( info.version <= 0x04020200 ) {
		if ( nextExtraData != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(nextExtraData) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Name:  " << name << endl;
	out << "  Next Extra Data:  " << nextExtraData << endl;
	return out.str();
}

void NiExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x04020200 ) {
		nextExtraData = FixLink<NiExtraData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextExtraData != NULL )
		refs.push_back(StaticCast<NiObject>(nextExtraData));
	return refs;
}

void NiInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
}

void NiInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
}

std::string NiInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	return out.str();
}

void NiInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiBlendInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::Read( in, link_stack, info );
	NifStream( unknownShort, in, info );
	NifStream( unknownInt, in, info );
}

void NiBlendInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiInterpolator::Write( out, link_map, info );
	NifStream( unknownShort, out, info );
	NifStream( unknownInt, out, info );
}

std::string NiBlendInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void NiBlendInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBlendInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	return refs;
}

void NiBSplineInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( startTime, in, info );
	NifStream( stopTime, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiBSplineInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiInterpolator::Write( out, link_map, info );
	NifStream( startTime, out, info );
	NifStream( stopTime, out, info );
	if ( splineData != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(splineData) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( basisData != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(basisData) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiBSplineInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Start Time:  " << startTime << endl;
	out << "  Stop Time:  " << stopTime << endl;
	out << "  Spline Data:  " << splineData << endl;
	out << "  Basis Data:  " << basisData << endl;
	return out.str();
}

void NiBSplineInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::FixLinks( objects, link_stack, info );
	splineData = FixLink<NiBSplineData>( objects, link_stack, info );
	basisData = FixLink<NiBSplineBasisData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSplineInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( splineData != NULL )
		refs.push_back(StaticCast<NiObject>(splineData));
	if ( basisData != NULL )
		refs.push_back(StaticCast<NiObject>(basisData));
	return refs;
}

void NiObjectNET::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( name, in, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numExtraDataList, in, info );
		extraDataList.resize(numExtraDataList);
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiObjectNET::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numExtraDataList = (unsigned int)(extraDataList.size());
	NifStream( name, out, info );
	if ( info.version <= 0x04020200 ) {
		if ( extraData != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(extraData) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numExtraDataList, out, info );
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			if ( extraDataList[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(extraDataList[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
	if ( controller != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(controller) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiObjectNET::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numExtraDataList = (unsigned int)(extraDataList.size());
	out << "  Name:  " << name << endl;
	out << "  Extra Data:  " << extraData << endl;
	out << "  Num Extra Data List:  " << numExtraDataList << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Extra Data List[" << i1 << "]:  " << extraDataList[i1] << endl;
		array_output_count++;
	};
	out << "  Controller:  " << controller << endl;
	return out.str();
}

void NiObjectNET::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x04020200 ) {
		extraData = FixLink<NiExtraData>( objects, link_stack, info );
	};
	if ( info.version >= 0x0A000100 ) {
		for (unsigned int i2 = 0; i2 < extraDataList.size(); i2++) {
			extraDataList[i2] = FixLink<NiExtraData>( objects, link_stack, info );
		};
	};
	controller = FixLink<NiTimeController>( objects, link_stack, info );
}

std::list<NiObjectRef> NiObjectNET::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( extraData != NULL )
		refs.push_back(StaticCast<NiObject>(extraData));
	for (unsigned int i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( extraDataList[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(extraDataList[i1]));
	};
	if ( controller != NULL )
		refs.push_back(StaticCast<NiObject>(controller));
	return refs;
}

void NiAVObject::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObjectNET::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( translation, in, info );
	NifStream( rotation, in, info );
	NifStream( scale, in, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( velocity, in, info );
	};
	NifStream( numProperties, in, info );
	properties.resize(numProperties);
	for (unsigned int i1 = 0; i1 < properties.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( hasBoundingBox, in, info );
		if ( (hasBoundingBox != 0) ) {
			NifStream( boundingBox.unknownInt, in, info );
			NifStream( boundingBox.translation, in, info );
			NifStream( boundingBox.rotation, in, info );
			NifStream( boundingBox.radius, in, info );
		};
	};
	if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x0A020000 ) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiAVObject::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObjectNET::Write( out, link_map, info );
	numProperties = (unsigned int)(properties.size());
	NifStream( flags, out, info );
	NifStream( translation, out, info );
	NifStream( rotation, out, info );
	NifStream( scale, out, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( velocity, out, info );
	};
	NifStream( numProperties, out, info );
	for (unsigned int i1 = 0; i1 < properties.size(); i1++) {
		if ( properties[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(properties[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( hasBoundingBox, out, info );
		if ( (hasBoundingBox != 0) ) {
			NifStream( boundingBox.unknownInt, out, info );
			NifStream( boundingBox.translation, out, info );
			NifStream( boundingBox.rotation, out, info );
			NifStream( boundingBox.radius, out, info );
		};
	};
	if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x0A020000 ) ) {
		if ( collisionData != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(collisionData) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( info.version >= 0x14000004 ) {
		if ( collisionObject != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(collisionObject) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiAVObject::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObjectNET::asString();
	numProperties = (unsigned int)(properties.size());
	out << "  Flags:  " << flags << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Velocity:  " << velocity << endl;
	out << "  Num Properties:  " << numProperties << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < properties.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Properties[" << i1 << "]:  " << properties[i1] << endl;
		array_output_count++;
	};
	out << "  Has Bounding Box:  " << hasBoundingBox << endl;
	if ( (hasBoundingBox != 0) ) {
		out << "    Unknown Int:  " << boundingBox.unknownInt << endl;
		out << "    Translation:  " << boundingBox.translation << endl;
		out << "    Rotation:  " << boundingBox.rotation << endl;
		out << "    Radius:  " << boundingBox.radius << endl;
	};
	out << "  Collision Data:  " << collisionData << endl;
	out << "  Collision Object:  " << collisionObject << endl;
	return out.str();
}

void NiAVObject::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObjectNET::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < properties.size(); i1++) {
		properties[i1] = FixLink<NiProperty>( objects, link_stack, info );
	};
	if ( ( info.version >= 0x0A000100 ) && ( info.version <= 0x0A020000 ) ) {
		collisionData = FixLink<NiCollisionData>( objects, link_stack, info );
	};
	if ( info.version >= 0x14000004 ) {
		collisionObject = FixLink<NiCollisionObject>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiAVObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	for (unsigned int i1 = 0; i1 < properties.size(); i1++) {
		if ( properties[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(properties[i1]));
	};
	if ( collisionData != NULL )
		refs.push_back(StaticCast<NiObject>(collisionData));
	if ( collisionObject != NULL )
		refs.push_back(StaticCast<NiObject>(collisionObject));
	return refs;
}

void NiDynamicEffect::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		NifStream( switchState, in, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( numAffectedNodes, in, info );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( numAffectedNodes, in, info );
	};
	if ( info.version <= 0x04000002 ) {
		affectedNodeListPointers.resize(numAffectedNodes);
		for (unsigned int i2 = 0; i2 < affectedNodeListPointers.size(); i2++) {
			NifStream( affectedNodeListPointers[i2], in, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		affectedNodes.resize(numAffectedNodes);
		for (unsigned int i2 = 0; i2 < affectedNodes.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
}

void NiDynamicEffect::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiAVObject::Write( out, link_map, info );
	numAffectedNodes = (unsigned int)(affectedNodeListPointers.size());
	if ( info.version >= 0x0A020000 ) {
		NifStream( switchState, out, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( numAffectedNodes, out, info );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( numAffectedNodes, out, info );
	};
	if ( info.version <= 0x04000002 ) {
		for (unsigned int i2 = 0; i2 < affectedNodeListPointers.size(); i2++) {
			NifStream( affectedNodeListPointers[i2], out, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		for (unsigned int i2 = 0; i2 < affectedNodes.size(); i2++) {
			if ( affectedNodes[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(affectedNodes[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
}

std::string NiDynamicEffect::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObject::asString();
	numAffectedNodes = (unsigned int)(affectedNodeListPointers.size());
	out << "  Switch State:  " << switchState << endl;
	out << "  Num Affected Nodes:  " << numAffectedNodes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < affectedNodeListPointers.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Affected Node List Pointers[" << i1 << "]:  " << affectedNodeListPointers[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < affectedNodes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Affected Nodes[" << i1 << "]:  " << affectedNodes[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiDynamicEffect::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiAVObject::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		for (unsigned int i2 = 0; i2 < affectedNodes.size(); i2++) {
			affectedNodes[i2] = FixLink<NiAVObject>( objects, link_stack, info );
		};
	};
}

std::list<NiObjectRef> NiDynamicEffect::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	for (unsigned int i1 = 0; i1 < affectedNodes.size(); i1++) {
		if ( affectedNodes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(affectedNodes[i1]));
	};
	return refs;
}

void NiLight::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiDynamicEffect::Read( in, link_stack, info );
	NifStream( dimmer, in, info );
	NifStream( ambientColor, in, info );
	NifStream( diffuseColor, in, info );
	NifStream( specularColor, in, info );
}

void NiLight::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiDynamicEffect::Write( out, link_map, info );
	NifStream( dimmer, out, info );
	NifStream( ambientColor, out, info );
	NifStream( diffuseColor, out, info );
	NifStream( specularColor, out, info );
}

std::string NiLight::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiDynamicEffect::asString();
	out << "  Dimmer:  " << dimmer << endl;
	out << "  Ambient Color:  " << ambientColor << endl;
	out << "  Diffuse Color:  " << diffuseColor << endl;
	out << "  Specular Color:  " << specularColor << endl;
	return out.str();
}

void NiLight::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiDynamicEffect::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiDynamicEffect::GetRefs();
	return refs;
}

void NiProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObjectNET::Read( in, link_stack, info );
}

void NiProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObjectNET::Write( out, link_map, info );
}

std::string NiProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObjectNET::asString();
	return out.str();
}

void NiProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObjectNET::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	return refs;
}

void NiPSysModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( name, in, info );
	NifStream( order, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( active, in, info );
}

void NiPSysModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	NifStream( name, out, info );
	NifStream( order, out, info );
	if ( target != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(target) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( active, out, info );
}

std::string NiPSysModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Name:  " << name << endl;
	out << "  Order:  " << order << endl;
	out << "  Target:  " << target << endl;
	out << "  Active:  " << active << endl;
	return out.str();
}

void NiPSysModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	target = FixLink<NiParticleSystem>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiPSysEmitter::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( speed, in, info );
	NifStream( speedVariation, in, info );
	NifStream( declination, in, info );
	NifStream( declinationVariation, in, info );
	NifStream( planarAngle, in, info );
	NifStream( planarAngleVariation, in, info );
	NifStream( initialColor, in, info );
	NifStream( initialRadius, in, info );
	if ( info.version >= 0x14000004 ) {
		NifStream( radiusVariation, in, info );
	};
	NifStream( lifeSpan, in, info );
	NifStream( lifeSpanVariation, in, info );
}

void NiPSysEmitter::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	NifStream( speed, out, info );
	NifStream( speedVariation, out, info );
	NifStream( declination, out, info );
	NifStream( declinationVariation, out, info );
	NifStream( planarAngle, out, info );
	NifStream( planarAngleVariation, out, info );
	NifStream( initialColor, out, info );
	NifStream( initialRadius, out, info );
	if ( info.version >= 0x14000004 ) {
		NifStream( radiusVariation, out, info );
	};
	NifStream( lifeSpan, out, info );
	NifStream( lifeSpanVariation, out, info );
}

std::string NiPSysEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Speed:  " << speed << endl;
	out << "  Speed Variation:  " << speedVariation << endl;
	out << "  Declination:  " << declination << endl;
	out << "  Declination Variation:  " << declinationVariation << endl;
	out << "  Planar Angle:  " << planarAngle << endl;
	out << "  Planar Angle Variation:  " << planarAngleVariation << endl;
	out << "  Initial Color:  " << initialColor << endl;
	out << "  Initial Radius:  " << initialRadius << endl;
	out << "  Radius Variation:  " << radiusVariation << endl;
	out << "  Life Span:  " << lifeSpan << endl;
	out << "  Life Span Variation:  " << lifeSpanVariation << endl;
	return out.str();
}

void NiPSysEmitter::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysVolumeEmitter::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysEmitter::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiPSysVolumeEmitter::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysEmitter::Write( out, link_map, info );
	if ( info.version >= 0x0A010000 ) {
		if ( emitterObject != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(emitterObject) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiPSysVolumeEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysEmitter::asString();
	out << "  Emitter Object:  " << emitterObject << endl;
	return out.str();
}

void NiPSysVolumeEmitter::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysEmitter::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		emitterObject = FixLink<NiNode>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiPSysVolumeEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysEmitter::GetRefs();
	return refs;
}

void NiTimeController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( flags, in, info );
	NifStream( frequency, in, info );
	NifStream( phase, in, info );
	NifStream( startTime, in, info );
	NifStream( stopTime, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiTimeController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	if ( nextController != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(nextController) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( flags, out, info );
	NifStream( frequency, out, info );
	NifStream( phase, out, info );
	NifStream( startTime, out, info );
	NifStream( stopTime, out, info );
	if ( target != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(target) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiTimeController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Next Controller:  " << nextController << endl;
	out << "  Flags:  " << flags << endl;
	out << "  Frequency:  " << frequency << endl;
	out << "  Phase:  " << phase << endl;
	out << "  Start Time:  " << startTime << endl;
	out << "  Stop Time:  " << stopTime << endl;
	out << "  Target:  " << target << endl;
	return out.str();
}

void NiTimeController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	nextController = FixLink<NiTimeController>( objects, link_stack, info );
	target = FixLink<NiObjectNET>( objects, link_stack, info );
}

std::list<NiObjectRef> NiTimeController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextController != NULL )
		refs.push_back(StaticCast<NiObject>(nextController));
	return refs;
}

void ABoneLODController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( numNodeGroups, in, info );
	NifStream( numNodeGroups2, in, info );
	nodeGroups.resize(numNodeGroups);
	for (unsigned int i1 = 0; i1 < nodeGroups.size(); i1++) {
		NifStream( nodeGroups[i1].numNodes, in, info );
		nodeGroups[i1].nodes.resize(nodeGroups[i1].numNodes);
		for (unsigned int i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
}

void ABoneLODController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	numNodeGroups = (unsigned int)(nodeGroups.size());
	NifStream( unknownInt1, out, info );
	NifStream( numNodeGroups, out, info );
	NifStream( numNodeGroups2, out, info );
	for (unsigned int i1 = 0; i1 < nodeGroups.size(); i1++) {
		nodeGroups[i1].numNodes = (unsigned int)(nodeGroups[i1].nodes.size());
		NifStream( nodeGroups[i1].numNodes, out, info );
		for (unsigned int i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			if ( nodeGroups[i1].nodes[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(nodeGroups[i1].nodes[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
}

std::string ABoneLODController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	numNodeGroups = (unsigned int)(nodeGroups.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Num Node Groups:  " << numNodeGroups << endl;
	out << "  Num Node Groups 2:  " << numNodeGroups2 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < nodeGroups.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		nodeGroups[i1].numNodes = (unsigned int)(nodeGroups[i1].nodes.size());
		out << "    Num Nodes:  " << nodeGroups[i1].numNodes << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Nodes[" << i2 << "]:  " << nodeGroups[i1].nodes[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void ABoneLODController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < nodeGroups.size(); i1++) {
		for (unsigned int i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			nodeGroups[i1].nodes[i2] = FixLink<NiNode>( objects, link_stack, info );
		};
	};
}

std::list<NiObjectRef> ABoneLODController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	for (unsigned int i1 = 0; i1 < nodeGroups.size(); i1++) {
		for (unsigned int i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
		};
	};
	return refs;
}

void NiSingleInterpolatorController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiSingleInterpolatorController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	if ( info.version >= 0x0A020000 ) {
		if ( interpolator != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(interpolator) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiSingleInterpolatorController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Interpolator:  " << interpolator << endl;
	return out.str();
}

void NiSingleInterpolatorController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		interpolator = FixLink<NiInterpolator>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiSingleInterpolatorController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( interpolator != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator));
	return refs;
}

void APSysCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::Read( in, link_stack, info );
	NifStream( modifierName, in, info );
}

void APSysCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSingleInterpolatorController::Write( out, link_map, info );
	NifStream( modifierName, out, info );
}

std::string APSysCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Modifier Name:  " << modifierName << endl;
	return out.str();
}

void APSysCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> APSysCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	return refs;
}

void NiGeometry::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x0303000D ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( hasShader, in, info );
		if ( (hasShader != 0) ) {
			NifStream( shaderName, in, info );
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
}

void NiGeometry::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiAVObject::Write( out, link_map, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x0303000D ) {
		if ( skinInstance != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(skinInstance) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( hasShader, out, info );
		if ( (hasShader != 0) ) {
			NifStream( shaderName, out, info );
			if ( unknownLink != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
}

std::string NiGeometry::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObject::asString();
	out << "  Data:  " << data << endl;
	out << "  Skin Instance:  " << skinInstance << endl;
	out << "  Has Shader:  " << hasShader << endl;
	if ( (hasShader != 0) ) {
		out << "    Shader Name:  " << shaderName << endl;
		out << "    Unknown Link:  " << unknownLink << endl;
	};
	return out.str();
}

void NiGeometry::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiAVObject::FixLinks( objects, link_stack, info );
	data = FixLink<NiGeometryData>( objects, link_stack, info );
	if ( info.version >= 0x0303000D ) {
		skinInstance = FixLink<NiSkinInstance>( objects, link_stack, info );
	};
	if ( info.version >= 0x0A000100 ) {
		if ( (hasShader != 0) ) {
			unknownLink = FixLink<NiObject>( objects, link_stack, info );
		};
	};
}

std::list<NiObjectRef> NiGeometry::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( skinInstance != NULL )
		refs.push_back(StaticCast<NiObject>(skinInstance));
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiTriBasedGeom::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometry::Read( in, link_stack, info );
}

void NiTriBasedGeom::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiGeometry::Write( out, link_map, info );
}

std::string NiTriBasedGeom::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiGeometry::asString();
	return out.str();
}

void NiTriBasedGeom::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometry::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTriBasedGeom::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometry::GetRefs();
	return refs;
}

void NiGeometryData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		NifStream( name, in, info );
	};
	NifStream( numVertices, in, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort1, in, info );
	};
	NifStream( hasVertices, in, info );
	if ( (hasVertices != 0) ) {
		vertices.resize(numVertices);
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			NifStream( vertices[i2], in, info );
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numUvSets2, in, info );
		NifStream( unknownByte, in, info );
	};
	NifStream( hasNormals, in, info );
	if ( (hasNormals != 0) ) {
		normals.resize(numVertices);
		for (unsigned int i2 = 0; i2 < normals.size(); i2++) {
			NifStream( normals[i2], in, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) {
			unknownVectors1.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownVectors1.size(); i3++) {
				NifStream( unknownVectors1[i3], in, info );
			};
			unknownVectors2.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownVectors2.size(); i3++) {
				NifStream( unknownVectors2[i3], in, info );
			};
		};
	};
	NifStream( center, in, info );
	NifStream( radius, in, info );
	NifStream( hasVertexColors, in, info );
	if ( (hasVertexColors != 0) ) {
		vertexColors.resize(numVertices);
		for (unsigned int i2 = 0; i2 < vertexColors.size(); i2++) {
			NifStream( vertexColors[i2], in, info );
		};
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( numUvSets, in, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( hasUv, in, info );
	};
	if ( info.version <= 0x04020200 ) {
		uvSets.resize(numUvSets);
		for (unsigned int i2 = 0; i2 < uvSets.size(); i2++) {
			uvSets[i2].resize(numVertices);
			for (unsigned int i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		uvSets.resize((numUvSets2 & 63));
		for (unsigned int i2 = 0; i2 < uvSets.size(); i2++) {
			uvSets[i2].resize(numVertices);
			for (unsigned int i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], in, info );
			};
		};
		NifStream( unknownShort2, in, info );
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiGeometryData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numUvSets = (unsigned short)(uvSets.size());
	numUvSets2 = (byte)(uvSets.size());
	numVertices = (unsigned short)(vertices.size());
	if ( info.version >= 0x0A020000 ) {
		NifStream( name, out, info );
	};
	NifStream( numVertices, out, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort1, out, info );
	};
	NifStream( hasVertices, out, info );
	if ( (hasVertices != 0) ) {
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			NifStream( vertices[i2], out, info );
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numUvSets2, out, info );
		NifStream( unknownByte, out, info );
	};
	NifStream( hasNormals, out, info );
	if ( (hasNormals != 0) ) {
		for (unsigned int i2 = 0; i2 < normals.size(); i2++) {
			NifStream( normals[i2], out, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) {
			for (unsigned int i3 = 0; i3 < unknownVectors1.size(); i3++) {
				NifStream( unknownVectors1[i3], out, info );
			};
			for (unsigned int i3 = 0; i3 < unknownVectors2.size(); i3++) {
				NifStream( unknownVectors2[i3], out, info );
			};
		};
	};
	NifStream( center, out, info );
	NifStream( radius, out, info );
	NifStream( hasVertexColors, out, info );
	if ( (hasVertexColors != 0) ) {
		for (unsigned int i2 = 0; i2 < vertexColors.size(); i2++) {
			NifStream( vertexColors[i2], out, info );
		};
	};
	if ( info.version <= 0x04020200 ) {
		NifStream( numUvSets, out, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( hasUv, out, info );
	};
	if ( info.version <= 0x04020200 ) {
		for (unsigned int i2 = 0; i2 < uvSets.size(); i2++) {
			for (unsigned int i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		for (unsigned int i2 = 0; i2 < uvSets.size(); i2++) {
			for (unsigned int i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], out, info );
			};
		};
		NifStream( unknownShort2, out, info );
	};
	if ( info.version >= 0x14000004 ) {
		if ( unknownLink != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiGeometryData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numUvSets = (unsigned short)(uvSets.size());
	numUvSets2 = (byte)(uvSets.size());
	numVertices = (unsigned short)(vertices.size());
	out << "  Name:  " << name << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Has Vertices:  " << hasVertices << endl;
	if ( (hasVertices != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertices[" << i2 << "]:  " << vertices[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num UV Sets 2:  " << numUvSets2 << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Has Normals:  " << hasNormals << endl;
	if ( (hasNormals != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < normals.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Normals[" << i2 << "]:  " << normals[i2] << endl;
			array_output_count++;
		};
	};
	if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownVectors1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Vectors 1[" << i2 << "]:  " << unknownVectors1[i2] << endl;
			array_output_count++;
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownVectors2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Vectors 2[" << i2 << "]:  " << unknownVectors2[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Center:  " << center << endl;
	out << "  Radius:  " << radius << endl;
	out << "  Has Vertex Colors:  " << hasVertexColors << endl;
	if ( (hasVertexColors != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < vertexColors.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Colors[" << i2 << "]:  " << vertexColors[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num UV Sets:  " << numUvSets << endl;
	out << "  Has UV:  " << hasUv << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < uvSets.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < uvSets[i1].size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      UV Sets[" << i2 << "]:  " << uvSets[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiGeometryData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x14000004 ) {
		unknownLink = FixLink<NiObject>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiGeometryData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiTriBasedGeomData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometryData::Read( in, link_stack, info );
	NifStream( numTriangles, in, info );
}

void NiTriBasedGeomData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiGeometryData::Write( out, link_map, info );
	NifStream( numTriangles, out, info );
}

std::string NiTriBasedGeomData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiGeometryData::asString();
	out << "  Num Triangles:  " << numTriangles << endl;
	return out.str();
}

void NiTriBasedGeomData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometryData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTriBasedGeomData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometryData::GetRefs();
	return refs;
}

void APSysData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometryData::Read( in, link_stack, info );
	NifStream( hasUnknownFloats1, in, info );
	if ( (hasUnknownFloats1 != 0) ) {
		unknownFloats1.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats1.size(); i2++) {
			NifStream( unknownFloats1[i2], in, info );
		};
	};
	NifStream( unknownShort3, in, info );
	NifStream( hasUnknownFloats2, in, info );
	if ( (hasUnknownFloats2 != 0) ) {
		unknownFloats2.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats2.size(); i2++) {
			NifStream( unknownFloats2[i2], in, info );
		};
	};
	NifStream( hasUnknownFloats3, in, info );
	if ( (hasUnknownFloats3 != 0) ) {
		unknownFloats3.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats3.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				NifStream( unknownFloats3[i2][i3], in, info );
			};
		};
	};
}

void APSysData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiGeometryData::Write( out, link_map, info );
	NifStream( hasUnknownFloats1, out, info );
	if ( (hasUnknownFloats1 != 0) ) {
		for (unsigned int i2 = 0; i2 < unknownFloats1.size(); i2++) {
			NifStream( unknownFloats1[i2], out, info );
		};
	};
	NifStream( unknownShort3, out, info );
	NifStream( hasUnknownFloats2, out, info );
	if ( (hasUnknownFloats2 != 0) ) {
		for (unsigned int i2 = 0; i2 < unknownFloats2.size(); i2++) {
			NifStream( unknownFloats2[i2], out, info );
		};
	};
	NifStream( hasUnknownFloats3, out, info );
	if ( (hasUnknownFloats3 != 0) ) {
		for (unsigned int i2 = 0; i2 < unknownFloats3.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				NifStream( unknownFloats3[i2][i3], out, info );
			};
		};
	};
}

std::string APSysData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiGeometryData::asString();
	out << "  Has Unknown Floats 1:  " << hasUnknownFloats1 << endl;
	if ( (hasUnknownFloats1 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownFloats1.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 1[" << i2 << "]:  " << unknownFloats1[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Has Unknown Floats 2:  " << hasUnknownFloats2 << endl;
	if ( (hasUnknownFloats2 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownFloats2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 2[" << i2 << "]:  " << unknownFloats2[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Unknown Floats 3:  " << hasUnknownFloats3 << endl;
	if ( (hasUnknownFloats3 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownFloats3.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Unknown Floats 3[" << i3 << "]:  " << unknownFloats3[i2][i3] << endl;
				array_output_count++;
			};
		};
	};
	return out.str();
}

void APSysData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometryData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> APSysData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometryData::GetRefs();
	return refs;
}

void bhkBlendCollisionObject::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiCollisionObject::Read( in, link_stack, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloat2, in, info );
}

void bhkBlendCollisionObject::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiCollisionObject::Write( out, link_map, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloat2, out, info );
}

std::string bhkBlendCollisionObject::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiCollisionObject::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	return out.str();
}

void bhkBlendCollisionObject::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiCollisionObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkBlendCollisionObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiCollisionObject::GetRefs();
	return refs;
}

void bhkBlendController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::Read( in, link_stack, info );
	NifStream( unknownInt, in, info );
}

void bhkBlendController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	NifStream( unknownInt, out, info );
}

std::string bhkBlendController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void bhkBlendController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkBlendController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	return refs;
}

void bhkBoxShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkConvexShape::Read( in, link_stack, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownShort2, in, info );
	NifStream( unknownShort3, in, info );
	NifStream( unknownShort4, in, info );
	NifStream( dimensions, in, info );
	NifStream( min_Size, in, info );
}

void bhkBoxShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkConvexShape::Write( out, link_map, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownShort2, out, info );
	NifStream( unknownShort3, out, info );
	NifStream( unknownShort4, out, info );
	NifStream( dimensions, out, info );
	NifStream( min_Size, out, info );
}

std::string bhkBoxShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConvexShape::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  Dimensions:  " << dimensions << endl;
	out << "  Min. size:  " << min_Size << endl;
	return out.str();
}

void bhkBoxShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkConvexShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkBoxShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConvexShape::GetRefs();
	return refs;
}

void bhkCapsuleShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkConvexShape::Read( in, link_stack, info );
	NifStream( radius, in, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownShort2, in, info );
	NifStream( unknownShort3, in, info );
	NifStream( unknownShort4, in, info );
	NifStream( firstPoint, in, info );
	NifStream( radius1, in, info );
	NifStream( secondPoint, in, info );
	NifStream( radius2, in, info );
}

void bhkCapsuleShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkConvexShape::Write( out, link_map, info );
	NifStream( radius, out, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownShort2, out, info );
	NifStream( unknownShort3, out, info );
	NifStream( unknownShort4, out, info );
	NifStream( firstPoint, out, info );
	NifStream( radius1, out, info );
	NifStream( secondPoint, out, info );
	NifStream( radius2, out, info );
}

std::string bhkCapsuleShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConvexShape::asString();
	out << "  Radius:  " << radius << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  First Point:  " << firstPoint << endl;
	out << "  Radius 1:  " << radius1 << endl;
	out << "  Second Point:  " << secondPoint << endl;
	out << "  Radius 2:  " << radius2 << endl;
	return out.str();
}

void bhkCapsuleShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkConvexShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkCapsuleShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConvexShape::GetRefs();
	return refs;
}

void bhkCollisionObject::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiCollisionObject::Read( in, link_stack, info );
}

void bhkCollisionObject::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiCollisionObject::Write( out, link_map, info );
}

std::string bhkCollisionObject::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiCollisionObject::asString();
	return out.str();
}

void bhkCollisionObject::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiCollisionObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkCollisionObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiCollisionObject::GetRefs();
	return refs;
}

void bhkConvexVerticesShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSphereRepShape::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		NifStream( unknownFloats1[i1], in, info );
	};
	NifStream( numVertices, in, info );
	vertices.resize(numVertices);
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], in, info );
	};
	NifStream( numNormals, in, info );
	normals.resize(numNormals);
	for (unsigned int i1 = 0; i1 < normals.size(); i1++) {
		NifStream( normals[i1], in, info );
	};
}

void bhkConvexVerticesShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkSphereRepShape::Write( out, link_map, info );
	numNormals = (unsigned int)(normals.size());
	numVertices = (unsigned int)(vertices.size());
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		NifStream( unknownFloats1[i1], out, info );
	};
	NifStream( numVertices, out, info );
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], out, info );
	};
	NifStream( numNormals, out, info );
	for (unsigned int i1 = 0; i1 < normals.size(); i1++) {
		NifStream( normals[i1], out, info );
	};
}

std::string bhkConvexVerticesShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSphereRepShape::asString();
	numNormals = (unsigned int)(normals.size());
	numVertices = (unsigned int)(vertices.size());
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats 1[" << i1 << "]:  " << unknownFloats1[i1] << endl;
		array_output_count++;
	};
	out << "  Num Vertices:  " << numVertices << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Vertices[" << i1 << "]:  " << vertices[i1] << endl;
		array_output_count++;
	};
	out << "  Num Normals:  " << numNormals << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < normals.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Normals[" << i1 << "]:  " << normals[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void bhkConvexVerticesShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkConvexVerticesShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	return refs;
}

void bhkHingeConstraint::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::Read( in, link_stack, info );
	NifStream( pivotA, in, info );
	NifStream( perp2axleina1, in, info );
	NifStream( perp2axleina2, in, info );
	NifStream( pivotB, in, info );
	NifStream( axleB, in, info );
}

void bhkHingeConstraint::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkConstraint::Write( out, link_map, info );
	NifStream( pivotA, out, info );
	NifStream( perp2axleina1, out, info );
	NifStream( perp2axleina2, out, info );
	NifStream( pivotB, out, info );
	NifStream( axleB, out, info );
}

std::string bhkHingeConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkConstraint::asString();
	out << "  Pivot A:  " << pivotA << endl;
	out << "  Perp2AxleInA1:  " << perp2axleina1 << endl;
	out << "  Perp2AxleInA2:  " << perp2axleina2 << endl;
	out << "  Pivot B:  " << pivotB << endl;
	out << "  Axle B:  " << axleB << endl;
	return out.str();
}

void bhkHingeConstraint::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkHingeConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkLimitedHingeConstraint::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::Read( in, link_stack, info );
	NifStream( limitedHinge.pivotA, in, info );
	NifStream( limitedHinge.axleA, in, info );
	NifStream( limitedHinge.perp2axleina1, in, info );
	NifStream( limitedHinge.perp2axleina2, in, info );
	NifStream( limitedHinge.pivotB, in, info );
	NifStream( limitedHinge.axleB, in, info );
	NifStream( limitedHinge.perp2axleinb2, in, info );
	NifStream( limitedHinge.minAngle, in, info );
	NifStream( limitedHinge.maxAngle, in, info );
	NifStream( limitedHinge.maxFriction, in, info );
}

void bhkLimitedHingeConstraint::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkConstraint::Write( out, link_map, info );
	NifStream( limitedHinge.pivotA, out, info );
	NifStream( limitedHinge.axleA, out, info );
	NifStream( limitedHinge.perp2axleina1, out, info );
	NifStream( limitedHinge.perp2axleina2, out, info );
	NifStream( limitedHinge.pivotB, out, info );
	NifStream( limitedHinge.axleB, out, info );
	NifStream( limitedHinge.perp2axleinb2, out, info );
	NifStream( limitedHinge.minAngle, out, info );
	NifStream( limitedHinge.maxAngle, out, info );
	NifStream( limitedHinge.maxFriction, out, info );
}

std::string bhkLimitedHingeConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkConstraint::asString();
	out << "  Pivot A:  " << limitedHinge.pivotA << endl;
	out << "  Axle A:  " << limitedHinge.axleA << endl;
	out << "  Perp2AxleInA1:  " << limitedHinge.perp2axleina1 << endl;
	out << "  Perp2AxleInA2:  " << limitedHinge.perp2axleina2 << endl;
	out << "  Pivot B:  " << limitedHinge.pivotB << endl;
	out << "  Axle B:  " << limitedHinge.axleB << endl;
	out << "  Perp2AxleInB2:  " << limitedHinge.perp2axleinb2 << endl;
	out << "  Min Angle:  " << limitedHinge.minAngle << endl;
	out << "  Max Angle:  " << limitedHinge.maxAngle << endl;
	out << "  Max Friction:  " << limitedHinge.maxFriction << endl;
	return out.str();
}

void bhkLimitedHingeConstraint::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkLimitedHingeConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkListShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	AbhkShapeCollection::Read( in, link_stack, info );
	NifStream( numSubShapes, in, info );
	subShapes.resize(numSubShapes);
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( material, in, info );
	for (unsigned int i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], in, info );
	};
	NifStream( numUnknownInts, in, info );
	unknownInts.resize(numUnknownInts);
	for (unsigned int i1 = 0; i1 < unknownInts.size(); i1++) {
		NifStream( unknownInts[i1], in, info );
	};
}

void bhkListShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkShapeCollection::Write( out, link_map, info );
	numUnknownInts = (unsigned int)(unknownInts.size());
	numSubShapes = (unsigned int)(subShapes.size());
	NifStream( numSubShapes, out, info );
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		if ( subShapes[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(subShapes[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( material, out, info );
	for (unsigned int i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], out, info );
	};
	NifStream( numUnknownInts, out, info );
	for (unsigned int i1 = 0; i1 < unknownInts.size(); i1++) {
		NifStream( unknownInts[i1], out, info );
	};
}

std::string bhkListShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkShapeCollection::asString();
	numUnknownInts = (unsigned int)(unknownInts.size());
	numSubShapes = (unsigned int)(subShapes.size());
	out << "  Num Sub Shapes:  " << numSubShapes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Sub Shapes[" << i1 << "]:  " << subShapes[i1] << endl;
		array_output_count++;
	};
	out << "  Material:  " << material << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 6; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
		array_output_count++;
	};
	out << "  Num Unknown Ints:  " << numUnknownInts << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownInts.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints[" << i1 << "]:  " << unknownInts[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void bhkListShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkShapeCollection::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		subShapes[i1] = FixLink<bhkShape>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> bhkListShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkShapeCollection::GetRefs();
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		if ( subShapes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(subShapes[i1]));
	};
	return refs;
}

void bhkMalleableConstraint::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	AbhkConstraint::Read( in, link_stack, info );
	NifStream( type, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownInt3, in, info );
	if ( (type == 7) ) {
		NifStream( ragdoll.pivotA, in, info );
		NifStream( ragdoll.planeA, in, info );
		NifStream( ragdoll.twistA, in, info );
		NifStream( ragdoll.pivotB, in, info );
		NifStream( ragdoll.planeB, in, info );
		NifStream( ragdoll.twistB, in, info );
		NifStream( ragdoll.coneMinAngle, in, info );
		NifStream( ragdoll.planeMinAngle, in, info );
		NifStream( ragdoll.planeMaxAngle, in, info );
		NifStream( ragdoll.twistMinAngle, in, info );
		NifStream( ragdoll.twistMaxAngle, in, info );
		NifStream( ragdoll.maxFriction, in, info );
	};
	if ( (type == 2) ) {
		NifStream( limitedHinge.pivotA, in, info );
		NifStream( limitedHinge.axleA, in, info );
		NifStream( limitedHinge.perp2axleina1, in, info );
		NifStream( limitedHinge.perp2axleina2, in, info );
		NifStream( limitedHinge.pivotB, in, info );
		NifStream( limitedHinge.axleB, in, info );
		NifStream( limitedHinge.perp2axleinb2, in, info );
		NifStream( limitedHinge.minAngle, in, info );
		NifStream( limitedHinge.maxAngle, in, info );
		NifStream( limitedHinge.maxFriction, in, info );
	};
	NifStream( tau, in, info );
	NifStream( damping, in, info );
}

void bhkMalleableConstraint::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkConstraint::Write( out, link_map, info );
	NifStream( type, out, info );
	NifStream( unknownInt2, out, info );
	if ( unknownLink1 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink1) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownInt3, out, info );
	if ( (type == 7) ) {
		NifStream( ragdoll.pivotA, out, info );
		NifStream( ragdoll.planeA, out, info );
		NifStream( ragdoll.twistA, out, info );
		NifStream( ragdoll.pivotB, out, info );
		NifStream( ragdoll.planeB, out, info );
		NifStream( ragdoll.twistB, out, info );
		NifStream( ragdoll.coneMinAngle, out, info );
		NifStream( ragdoll.planeMinAngle, out, info );
		NifStream( ragdoll.planeMaxAngle, out, info );
		NifStream( ragdoll.twistMinAngle, out, info );
		NifStream( ragdoll.twistMaxAngle, out, info );
		NifStream( ragdoll.maxFriction, out, info );
	};
	if ( (type == 2) ) {
		NifStream( limitedHinge.pivotA, out, info );
		NifStream( limitedHinge.axleA, out, info );
		NifStream( limitedHinge.perp2axleina1, out, info );
		NifStream( limitedHinge.perp2axleina2, out, info );
		NifStream( limitedHinge.pivotB, out, info );
		NifStream( limitedHinge.axleB, out, info );
		NifStream( limitedHinge.perp2axleinb2, out, info );
		NifStream( limitedHinge.minAngle, out, info );
		NifStream( limitedHinge.maxAngle, out, info );
		NifStream( limitedHinge.maxFriction, out, info );
	};
	NifStream( tau, out, info );
	NifStream( damping, out, info );
}

std::string bhkMalleableConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkConstraint::asString();
	out << "  Type:  " << type << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Link 1:  " << unknownLink1 << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	if ( (type == 7) ) {
		out << "    Pivot A:  " << ragdoll.pivotA << endl;
		out << "    Plane A:  " << ragdoll.planeA << endl;
		out << "    Twist A:  " << ragdoll.twistA << endl;
		out << "    Pivot B:  " << ragdoll.pivotB << endl;
		out << "    Plane B:  " << ragdoll.planeB << endl;
		out << "    Twist B:  " << ragdoll.twistB << endl;
		out << "    Cone Min Angle:  " << ragdoll.coneMinAngle << endl;
		out << "    Plane Min Angle:  " << ragdoll.planeMinAngle << endl;
		out << "    Plane Max Angle:  " << ragdoll.planeMaxAngle << endl;
		out << "    Twist Min Angle:  " << ragdoll.twistMinAngle << endl;
		out << "    Twist Max Angle:  " << ragdoll.twistMaxAngle << endl;
		out << "    Max Friction:  " << ragdoll.maxFriction << endl;
	};
	if ( (type == 2) ) {
		out << "    Pivot A:  " << limitedHinge.pivotA << endl;
		out << "    Axle A:  " << limitedHinge.axleA << endl;
		out << "    Perp2AxleInA1:  " << limitedHinge.perp2axleina1 << endl;
		out << "    Perp2AxleInA2:  " << limitedHinge.perp2axleina2 << endl;
		out << "    Pivot B:  " << limitedHinge.pivotB << endl;
		out << "    Axle B:  " << limitedHinge.axleB << endl;
		out << "    Perp2AxleInB2:  " << limitedHinge.perp2axleinb2 << endl;
		out << "    Min Angle:  " << limitedHinge.minAngle << endl;
		out << "    Max Angle:  " << limitedHinge.maxAngle << endl;
		out << "    Max Friction:  " << limitedHinge.maxFriction << endl;
	};
	out << "  Tau:  " << tau << endl;
	out << "  Damping:  " << damping << endl;
	return out.str();
}

void bhkMalleableConstraint::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::FixLinks( objects, link_stack, info );
	unknownLink1 = FixLink<NiObject>( objects, link_stack, info );
	unknownLink2 = FixLink<NiObject>( objects, link_stack, info );
}

std::list<NiObjectRef> bhkMalleableConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	if ( unknownLink1 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink1));
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	return refs;
}

void bhkMoppBvTreeShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	bhkShape::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( material, in, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unknown8Bytes[i1], in, info );
	};
	NifStream( unknownFloat, in, info );
	NifStream( moppDataSize, in, info );
	if ( info.version >= 0x14000005 ) {
		NifStream( objectCorner, in, info );
		NifStream( scalingFactor, in, info );
	};
	moppData.resize(moppDataSize);
	for (unsigned int i1 = 0; i1 < moppData.size(); i1++) {
		NifStream( moppData[i1], in, info );
	};
}

void bhkMoppBvTreeShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkShape::Write( out, link_map, info );
	moppDataSize = (unsigned int)(moppData.size());
	if ( shape != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(shape) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( material, out, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unknown8Bytes[i1], out, info );
	};
	NifStream( unknownFloat, out, info );
	NifStream( moppDataSize, out, info );
	if ( info.version >= 0x14000005 ) {
		NifStream( objectCorner, out, info );
		NifStream( scalingFactor, out, info );
	};
	for (unsigned int i1 = 0; i1 < moppData.size(); i1++) {
		NifStream( moppData[i1], out, info );
	};
}

std::string bhkMoppBvTreeShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShape::asString();
	moppDataSize = (unsigned int)(moppData.size());
	out << "  Shape:  " << shape << endl;
	out << "  Material:  " << material << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 8 Bytes[" << i1 << "]:  " << unknown8Bytes[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  MOPP Data Size:  " << moppDataSize << endl;
	out << "  Object Corner:  " << objectCorner << endl;
	out << "  Scaling Factor:  " << scalingFactor << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < moppData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    MOPP Data[" << i1 << "]:  " << moppData[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void bhkMoppBvTreeShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkShape::FixLinks( objects, link_stack, info );
	shape = FixLink<bhkShape>( objects, link_stack, info );
}

std::list<NiObjectRef> bhkMoppBvTreeShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	if ( shape != NULL )
		refs.push_back(StaticCast<NiObject>(shape));
	return refs;
}

void bhkMultiSphereShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSphereRepShape::Read( in, link_stack, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloat2, in, info );
	NifStream( unknownFloat3, in, info );
	NifStream( numSpheres, in, info );
	spheres.resize(numSpheres);
	for (unsigned int i1 = 0; i1 < spheres.size(); i1++) {
		NifStream( spheres[i1].center, in, info );
		NifStream( spheres[i1].radius, in, info );
	};
}

void bhkMultiSphereShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkSphereRepShape::Write( out, link_map, info );
	numSpheres = (unsigned int)(spheres.size());
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloat2, out, info );
	NifStream( unknownFloat3, out, info );
	NifStream( numSpheres, out, info );
	for (unsigned int i1 = 0; i1 < spheres.size(); i1++) {
		NifStream( spheres[i1].center, out, info );
		NifStream( spheres[i1].radius, out, info );
	};
}

std::string bhkMultiSphereShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSphereRepShape::asString();
	numSpheres = (unsigned int)(spheres.size());
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Num Spheres:  " << numSpheres << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < spheres.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Center:  " << spheres[i1].center << endl;
		out << "    Radius:  " << spheres[i1].radius << endl;
	};
	return out.str();
}

void bhkMultiSphereShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkMultiSphereShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	return refs;
}

void bhkNiTriStripsShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	bhkSphereRepShape::Read( in, link_stack, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownInt1, in, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknownInts1[i1], in, info );
	};
	NifStream( unknownInt2, in, info );
	NifStream( scale, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( numStripsData, in, info );
	stripsData.resize(numStripsData);
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numDataLayers, in, info );
	dataLayers.resize(numDataLayers);
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		NifStream( dataLayers[i1].layer, in, info );
		NifStream( dataLayers[i1].colFilter, in, info );
		NifStream( dataLayers[i1].unknownShort, in, info );
	};
}

void bhkNiTriStripsShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkSphereRepShape::Write( out, link_map, info );
	numDataLayers = (unsigned int)(dataLayers.size());
	numStripsData = (unsigned int)(stripsData.size());
	NifStream( unknownFloat1, out, info );
	NifStream( unknownInt1, out, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknownInts1[i1], out, info );
	};
	NifStream( unknownInt2, out, info );
	NifStream( scale, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( numStripsData, out, info );
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(stripsData[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( numDataLayers, out, info );
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		NifStream( dataLayers[i1].layer, out, info );
		NifStream( dataLayers[i1].colFilter, out, info );
		NifStream( dataLayers[i1].unknownShort, out, info );
	};
}

std::string bhkNiTriStripsShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSphereRepShape::asString();
	numDataLayers = (unsigned int)(dataLayers.size());
	numStripsData = (unsigned int)(stripsData.size());
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints 1[" << i1 << "]:  " << unknownInts1[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Num Strips Data:  " << numStripsData << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Strips Data[" << i1 << "]:  " << stripsData[i1] << endl;
		array_output_count++;
	};
	out << "  Num Data Layers:  " << numDataLayers << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Layer:  " << dataLayers[i1].layer << endl;
		out << "    Col Filter:  " << dataLayers[i1].colFilter << endl;
		out << "    Unknown Short:  " << dataLayers[i1].unknownShort << endl;
	};
	return out.str();
}

void bhkNiTriStripsShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		stripsData[i1] = FixLink<NiTriStripsData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> bhkNiTriStripsShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(stripsData[i1]));
	};
	return refs;
}

void bhkMeshShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	bhkSphereRepShape::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unknown[i1], in, info );
	};
	NifStream( unknownCount, in, info );
	unknownFloats.resize(unknownCount);
	for (unsigned int i1 = 0; i1 < unknownFloats.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			NifStream( unknownFloats[i1][i2], in, info );
		};
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknown[i1], in, info );
	};
	NifStream( numStripsData, in, info );
	stripsData.resize(numStripsData);
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void bhkMeshShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkSphereRepShape::Write( out, link_map, info );
	numStripsData = (unsigned int)(stripsData.size());
	unknownCount = (int)(unknownFloats.size());
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unknown[i1], out, info );
	};
	NifStream( unknownCount, out, info );
	for (unsigned int i1 = 0; i1 < unknownFloats.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			NifStream( unknownFloats[i1][i2], out, info );
		};
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknown[i1], out, info );
	};
	NifStream( numStripsData, out, info );
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(stripsData[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string bhkMeshShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSphereRepShape::asString();
	numStripsData = (unsigned int)(stripsData.size());
	unknownCount = (int)(unknownFloats.size());
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    unknown[" << i1 << "]:  " << unknown[i1] << endl;
		array_output_count++;
	};
	out << "  unknown count:  " << unknownCount << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownFloats.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      unknown floats[" << i2 << "]:  " << unknownFloats[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Strips Data:  " << numStripsData << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Strips Data[" << i1 << "]:  " << stripsData[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void bhkMeshShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		stripsData[i1] = FixLink<NiTriStripsData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> bhkMeshShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(stripsData[i1]));
	};
	return refs;
}

void bhkPackedNiTriStripsShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	AbhkShapeCollection::Read( in, link_stack, info );
	NifStream( numSubShapes, in, info );
	subShapes.resize(numSubShapes);
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		NifStream( subShapes[i1].layer, in, info );
		NifStream( subShapes[i1].colFilter, in, info );
		NifStream( subShapes[i1].unknownShort, in, info );
		NifStream( subShapes[i1].vertexCount___, in, info );
		NifStream( subShapes[i1].material, in, info );
	};
	for (unsigned int i1 = 0; i1 < 9; i1++) {
		NifStream( unknownFloats[i1], in, info );
	};
	NifStream( scale, in, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], in, info );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void bhkPackedNiTriStripsShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkShapeCollection::Write( out, link_map, info );
	numSubShapes = (unsigned short)(subShapes.size());
	NifStream( numSubShapes, out, info );
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		NifStream( subShapes[i1].layer, out, info );
		NifStream( subShapes[i1].colFilter, out, info );
		NifStream( subShapes[i1].unknownShort, out, info );
		NifStream( subShapes[i1].vertexCount___, out, info );
		NifStream( subShapes[i1].material, out, info );
	};
	for (unsigned int i1 = 0; i1 < 9; i1++) {
		NifStream( unknownFloats[i1], out, info );
	};
	NifStream( scale, out, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], out, info );
	};
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string bhkPackedNiTriStripsShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkShapeCollection::asString();
	numSubShapes = (unsigned short)(subShapes.size());
	out << "  Num Sub Shapes:  " << numSubShapes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Layer:  " << subShapes[i1].layer << endl;
		out << "    Col Filter:  " << subShapes[i1].colFilter << endl;
		out << "    Unknown Short:  " << subShapes[i1].unknownShort << endl;
		out << "    Vertex Count (?):  " << subShapes[i1].vertexCount___ << endl;
		out << "    Material:  " << subShapes[i1].material << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 9; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
		array_output_count++;
	};
	out << "  Scale:  " << scale << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats 2[" << i1 << "]:  " << unknownFloats2[i1] << endl;
		array_output_count++;
	};
	out << "  Data:  " << data << endl;
	return out.str();
}

void bhkPackedNiTriStripsShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkShapeCollection::FixLinks( objects, link_stack, info );
	data = FixLink<hkPackedNiTriStripsData>( objects, link_stack, info );
}

std::list<NiObjectRef> bhkPackedNiTriStripsShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkShapeCollection::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void bhkPrismaticConstraint::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unknownVectors[i1], in, info );
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], in, info );
	};
}

void bhkPrismaticConstraint::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkConstraint::Write( out, link_map, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unknownVectors[i1], out, info );
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], out, info );
	};
}

std::string bhkPrismaticConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkConstraint::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Vectors[" << i1 << "]:  " << unknownVectors[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats 2[" << i1 << "]:  " << unknownFloats2[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void bhkPrismaticConstraint::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkPrismaticConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkRagdollConstraint::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkRagdollConstraint::Read( in, link_stack, info );
}

void bhkRagdollConstraint::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkRagdollConstraint::Write( out, link_map, info );
}

std::string bhkRagdollConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkRagdollConstraint::asString();
	return out.str();
}

void bhkRagdollConstraint::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkRagdollConstraint::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkRagdollConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkRagdollConstraint::GetRefs();
	return refs;
}

void bhkRigidBody::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	bhkEntity::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		NifStream( unknown5Floats[i1], in, info );
	};
	if ( info.version >= 0x14000004 ) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( unknown4Shorts[i2], in, info );
		};
		NifStream( layerCopy, in, info );
		NifStream( colFilterCopy, in, info );
		for (unsigned int i2 = 0; i2 < 7; i2++) {
			NifStream( unknown7Shorts[i2], in, info );
		};
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
	for (unsigned int i1 = 0; i1 < 12; i1++) {
		NifStream( inertia[i1], in, info );
	};
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
	NifStream( unknownInt6, in, info );
}

void bhkRigidBody::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkEntity::Write( out, link_map, info );
	numConstraints = (unsigned int)(constraints.size());
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		NifStream( unknown5Floats[i1], out, info );
	};
	if ( info.version >= 0x14000004 ) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( unknown4Shorts[i2], out, info );
		};
		NifStream( layerCopy, out, info );
		NifStream( colFilterCopy, out, info );
		for (unsigned int i2 = 0; i2 < 7; i2++) {
			NifStream( unknown7Shorts[i2], out, info );
		};
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
	for (unsigned int i1 = 0; i1 < 12; i1++) {
		NifStream( inertia[i1], out, info );
	};
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
		if ( constraints[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(constraints[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( unknownInt6, out, info );
}

std::string bhkRigidBody::InternalAsString( bool verbose ) const {
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
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 12; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Inertia[" << i1 << "]:  " << inertia[i1] << endl;
		array_output_count++;
	};
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
	return out.str();
}

void bhkRigidBody::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkEntity::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		constraints[i1] = FixLink<AbhkConstraint>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> bhkRigidBody::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkEntity::GetRefs();
	for (unsigned int i1 = 0; i1 < constraints.size(); i1++) {
		if ( constraints[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(constraints[i1]));
	};
	return refs;
}

void bhkRigidBodyT::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkRigidBody::Read( in, link_stack, info );
}

void bhkRigidBodyT::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkRigidBody::Write( out, link_map, info );
}

std::string bhkRigidBodyT::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkRigidBody::asString();
	return out.str();
}

void bhkRigidBodyT::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkRigidBody::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkRigidBodyT::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkRigidBody::GetRefs();
	return refs;
}

void bhkSimpleShapePhantom::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkEntity::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		NifStream( unkownFloats[i1], in, info );
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		for (unsigned int i2 = 0; i2 < 5; i2++) {
			NifStream( unknownFloats2[i1][i2], in, info );
		};
	};
	NifStream( unknownFloat, in, info );
}

void bhkSimpleShapePhantom::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkEntity::Write( out, link_map, info );
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		NifStream( unkownFloats[i1], out, info );
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		for (unsigned int i2 = 0; i2 < 5; i2++) {
			NifStream( unknownFloats2[i1][i2], out, info );
		};
	};
	NifStream( unknownFloat, out, info );
}

std::string bhkSimpleShapePhantom::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkEntity::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 7; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unkown Floats[" << i1 << "]:  " << unkownFloats[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 5; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 2[" << i2 << "]:  " << unknownFloats2[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void bhkSimpleShapePhantom::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkEntity::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkSimpleShapePhantom::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkEntity::GetRefs();
	return refs;
}

void bhkSPCollisionObject::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiCollisionObject::Read( in, link_stack, info );
}

void bhkSPCollisionObject::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiCollisionObject::Write( out, link_map, info );
}

std::string bhkSPCollisionObject::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiCollisionObject::asString();
	return out.str();
}

void bhkSPCollisionObject::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiCollisionObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkSPCollisionObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiCollisionObject::GetRefs();
	return refs;
}

void bhkSphereShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkConvexShape::Read( in, link_stack, info );
	NifStream( radius, in, info );
}

void bhkSphereShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkConvexShape::Write( out, link_map, info );
	NifStream( radius, out, info );
}

std::string bhkSphereShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkConvexShape::asString();
	out << "  Radius:  " << radius << endl;
	return out.str();
}

void bhkSphereShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkConvexShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkSphereShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConvexShape::GetRefs();
	return refs;
}

void bhkStiffSpringConstraint::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::Read( in, link_stack, info );
	NifStream( pivotA, in, info );
	NifStream( pivotB, in, info );
	NifStream( length, in, info );
}

void bhkStiffSpringConstraint::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkConstraint::Write( out, link_map, info );
	NifStream( pivotA, out, info );
	NifStream( pivotB, out, info );
	NifStream( length, out, info );
}

std::string bhkStiffSpringConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkConstraint::asString();
	out << "  Pivot A:  " << pivotA << endl;
	out << "  Pivot B:  " << pivotB << endl;
	out << "  Length:  " << length << endl;
	return out.str();
}

void bhkStiffSpringConstraint::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkConstraint::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkStiffSpringConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkTransformShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkEntity::Read( in, link_stack, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloat2, in, info );
	NifStream( unknownFloat3, in, info );
	NifStream( transform, in, info );
}

void bhkTransformShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkEntity::Write( out, link_map, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloat2, out, info );
	NifStream( unknownFloat3, out, info );
	NifStream( transform, out, info );
}

std::string bhkTransformShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkEntity::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Transform:  " << transform << endl;
	return out.str();
}

void bhkTransformShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkEntity::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkTransformShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkEntity::GetRefs();
	return refs;
}

void bhkConvexTransformShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkTransformShape::Read( in, link_stack, info );
}

void bhkConvexTransformShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	bhkTransformShape::Write( out, link_map, info );
}

std::string bhkConvexTransformShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkTransformShape::asString();
	return out.str();
}

void bhkConvexTransformShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	bhkTransformShape::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> bhkConvexTransformShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkTransformShape::GetRefs();
	return refs;
}

void BSBound::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( center, in, info );
	NifStream( dimensions, in, info );
}

void BSBound::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	NifStream( center, out, info );
	NifStream( dimensions, out, info );
}

std::string BSBound::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Center:  " << center << endl;
	out << "  Dimensions:  " << dimensions << endl;
	return out.str();
}

void BSBound::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> BSBound::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void BSFurnitureMarker::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( numPositions, in, info );
	positions.resize(numPositions);
	for (unsigned int i1 = 0; i1 < positions.size(); i1++) {
		NifStream( positions[i1].offset, in, info );
		NifStream( positions[i1].orientation, in, info );
		NifStream( positions[i1].positionRef1, in, info );
		NifStream( positions[i1].positionRef2, in, info );
	};
}

void BSFurnitureMarker::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	numPositions = (unsigned int)(positions.size());
	NifStream( numPositions, out, info );
	for (unsigned int i1 = 0; i1 < positions.size(); i1++) {
		NifStream( positions[i1].offset, out, info );
		NifStream( positions[i1].orientation, out, info );
		NifStream( positions[i1].positionRef1, out, info );
		NifStream( positions[i1].positionRef2, out, info );
	};
}

std::string BSFurnitureMarker::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	numPositions = (unsigned int)(positions.size());
	out << "  Num Positions:  " << numPositions << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < positions.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Offset:  " << positions[i1].offset << endl;
		out << "    Orientation:  " << positions[i1].orientation << endl;
		out << "    Position Ref 1:  " << positions[i1].positionRef1 << endl;
		out << "    Position Ref 2:  " << positions[i1].positionRef2 << endl;
	};
	return out.str();
}

void BSFurnitureMarker::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> BSFurnitureMarker::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void BSParentVelocityModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( unknownFloat, in, info );
}

void BSParentVelocityModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	NifStream( unknownFloat, out, info );
}

std::string BSParentVelocityModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void BSParentVelocityModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> BSParentVelocityModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void BSPSysArrayEmitter::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysVolumeEmitter::Read( in, link_stack, info );
}

void BSPSysArrayEmitter::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysVolumeEmitter::Write( out, link_map, info );
}

std::string BSPSysArrayEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysVolumeEmitter::asString();
	return out.str();
}

void BSPSysArrayEmitter::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysVolumeEmitter::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> BSPSysArrayEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysVolumeEmitter::GetRefs();
	return refs;
}

void BSXFlags::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( flags, in, info );
}

void BSXFlags::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	NifStream( flags, out, info );
}

std::string BSXFlags::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void BSXFlags::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> BSXFlags::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void hkPackedNiTriStripsData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkShapeCollection::Read( in, link_stack, info );
	NifStream( numTriangles, in, info );
	triangles.resize(numTriangles);
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		NifStream( triangles[i1].triangle, in, info );
		NifStream( triangles[i1].unknownShort, in, info );
		NifStream( triangles[i1].normal, in, info );
	};
	NifStream( numVertices, in, info );
	vertices.resize(numVertices);
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], in, info );
	};
}

void hkPackedNiTriStripsData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AbhkShapeCollection::Write( out, link_map, info );
	numVertices = (unsigned int)(vertices.size());
	numTriangles = (unsigned int)(triangles.size());
	NifStream( numTriangles, out, info );
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		NifStream( triangles[i1].triangle, out, info );
		NifStream( triangles[i1].unknownShort, out, info );
		NifStream( triangles[i1].normal, out, info );
	};
	NifStream( numVertices, out, info );
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], out, info );
	};
}

std::string hkPackedNiTriStripsData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AbhkShapeCollection::asString();
	numVertices = (unsigned int)(vertices.size());
	numTriangles = (unsigned int)(triangles.size());
	out << "  Num Triangles:  " << numTriangles << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Triangle:  " << triangles[i1].triangle << endl;
		out << "    Unknown Short:  " << triangles[i1].unknownShort << endl;
		out << "    Normal:  " << triangles[i1].normal << endl;
	};
	out << "  Num Vertices:  " << numVertices << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < vertices.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Vertices[" << i1 << "]:  " << vertices[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void hkPackedNiTriStripsData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AbhkShapeCollection::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> hkPackedNiTriStripsData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkShapeCollection::GetRefs();
	return refs;
}

void NiAlphaController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiSingleInterpolatorController::Read( in, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiAlphaController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSingleInterpolatorController::Write( out, link_map, info );
	if ( info.version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiAlphaController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiAlphaController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		data = FixLink<NiFloatData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiAlphaController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiAlphaProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( threshold, in, info );
}

void NiAlphaProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
	NifStream( threshold, out, info );
}

std::string NiAlphaProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Threshold:  " << threshold << endl;
	return out.str();
}

void NiAlphaProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiAlphaProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiAmbientLight::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLight::Read( in, link_stack, info );
}

void NiAmbientLight::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiLight::Write( out, link_map, info );
}

std::string NiAmbientLight::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiLight::asString();
	return out.str();
}

void NiAmbientLight::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLight::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiAmbientLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLight::GetRefs();
	return refs;
}

void NiAutoNormalParticlesData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometryData::Read( in, link_stack, info );
	if ( info.version <= 0x04000002 ) {
		NifStream( numParticles, in, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( size, in, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( numActive, in, info );
	};
	if ( ( info.version >= 0x0401000C ) && ( info.version <= 0x0A000100 ) ) {
		NifStream( unknownShort, in, info );
	};
	NifStream( hasSizes, in, info );
	if ( (hasSizes != 0) ) {
		sizes.resize(numVertices);
		for (unsigned int i2 = 0; i2 < sizes.size(); i2++) {
			NifStream( sizes[i2], in, info );
		};
	};
}

void NiAutoNormalParticlesData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiGeometryData::Write( out, link_map, info );
	if ( info.version <= 0x04000002 ) {
		NifStream( numParticles, out, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( size, out, info );
	};
	if ( info.version <= 0x04000002 ) {
		NifStream( numActive, out, info );
	};
	if ( ( info.version >= 0x0401000C ) && ( info.version <= 0x0A000100 ) ) {
		NifStream( unknownShort, out, info );
	};
	NifStream( hasSizes, out, info );
	if ( (hasSizes != 0) ) {
		for (unsigned int i2 = 0; i2 < sizes.size(); i2++) {
			NifStream( sizes[i2], out, info );
		};
	};
}

std::string NiAutoNormalParticlesData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiGeometryData::asString();
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Size:  " << size << endl;
	out << "  Num Active:  " << numActive << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Has Sizes:  " << hasSizes << endl;
	if ( (hasSizes != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < sizes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Sizes[" << i2 << "]:  " << sizes[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiAutoNormalParticlesData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometryData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiAutoNormalParticlesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometryData::GetRefs();
	return refs;
}

void NiBinaryExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( binaryData.dataSize, in, info );
	binaryData.data.resize(binaryData.dataSize);
	for (unsigned int i1 = 0; i1 < binaryData.data.size(); i1++) {
		NifStream( binaryData.data[i1], in, info );
	};
}

void NiBinaryExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	binaryData.dataSize = (unsigned int)(binaryData.data.size());
	NifStream( binaryData.dataSize, out, info );
	for (unsigned int i1 = 0; i1 < binaryData.data.size(); i1++) {
		NifStream( binaryData.data[i1], out, info );
	};
}

std::string NiBinaryExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	binaryData.dataSize = (unsigned int)(binaryData.data.size());
	out << "  Data Size:  " << binaryData.dataSize << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < binaryData.data.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Data[" << i1 << "]:  " << binaryData.data[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiBinaryExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBinaryExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiBlendBoolInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::Read( in, link_stack, info );
	NifStream( boolValue, in, info );
}

void NiBlendBoolInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiBlendInterpolator::Write( out, link_map, info );
	NifStream( boolValue, out, info );
}

std::string NiBlendBoolInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	return out.str();
}

void NiBlendBoolInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBlendBoolInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

void NiBlendFloatInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::Read( in, link_stack, info );
	NifStream( floatValue, in, info );
}

void NiBlendFloatInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiBlendInterpolator::Write( out, link_map, info );
	NifStream( floatValue, out, info );
}

std::string NiBlendFloatInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Float Value:  " << floatValue << endl;
	return out.str();
}

void NiBlendFloatInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBlendFloatInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

void NiBlendPoint3Interpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::Read( in, link_stack, info );
	NifStream( pointValue, in, info );
}

void NiBlendPoint3Interpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiBlendInterpolator::Write( out, link_map, info );
	NifStream( pointValue, out, info );
}

std::string NiBlendPoint3Interpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Point Value:  " << pointValue << endl;
	return out.str();
}

void NiBlendPoint3Interpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBlendPoint3Interpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

void NiBlendTransformInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::Read( in, link_stack, info );
}

void NiBlendTransformInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiBlendInterpolator::Write( out, link_map, info );
}

std::string NiBlendTransformInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBlendInterpolator::asString();
	return out.str();
}

void NiBlendTransformInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBlendTransformInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

void NiBoneLODController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	ABoneLODController::Read( in, link_stack, info );
	NifStream( numShapeGroups, in, info );
	shapeGroups1.resize(numShapeGroups);
	for (unsigned int i1 = 0; i1 < shapeGroups1.size(); i1++) {
		NifStream( shapeGroups1[i1].numLinkPairs, in, info );
		shapeGroups1[i1].linkPairs.resize(shapeGroups1[i1].numLinkPairs);
		for (unsigned int i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	NifStream( numShapeGroups2, in, info );
	shapeGroups2.resize(numShapeGroups2);
	for (unsigned int i1 = 0; i1 < shapeGroups2.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiBoneLODController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	ABoneLODController::Write( out, link_map, info );
	numShapeGroups2 = (unsigned int)(shapeGroups2.size());
	numShapeGroups = (unsigned int)(shapeGroups1.size());
	NifStream( numShapeGroups, out, info );
	for (unsigned int i1 = 0; i1 < shapeGroups1.size(); i1++) {
		shapeGroups1[i1].numLinkPairs = (unsigned int)(shapeGroups1[i1].linkPairs.size());
		NifStream( shapeGroups1[i1].numLinkPairs, out, info );
		for (unsigned int i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			if ( shapeGroups1[i1].linkPairs[i2].shape != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(shapeGroups1[i1].linkPairs[i2].shape) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
			if ( shapeGroups1[i1].linkPairs[i2].skinInstance != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(shapeGroups1[i1].linkPairs[i2].skinInstance) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
	NifStream( numShapeGroups2, out, info );
	for (unsigned int i1 = 0; i1 < shapeGroups2.size(); i1++) {
		if ( shapeGroups2[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(shapeGroups2[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiBoneLODController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << ABoneLODController::asString();
	numShapeGroups2 = (unsigned int)(shapeGroups2.size());
	numShapeGroups = (unsigned int)(shapeGroups1.size());
	out << "  Num Shape Groups:  " << numShapeGroups << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < shapeGroups1.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		shapeGroups1[i1].numLinkPairs = (unsigned int)(shapeGroups1[i1].linkPairs.size());
		out << "    Num Link Pairs:  " << shapeGroups1[i1].numLinkPairs << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Shape:  " << shapeGroups1[i1].linkPairs[i2].shape << endl;
			out << "      Skin Instance:  " << shapeGroups1[i1].linkPairs[i2].skinInstance << endl;
		};
	};
	out << "  Num Shape Groups 2:  " << numShapeGroups2 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < shapeGroups2.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Shape Groups 2[" << i1 << "]:  " << shapeGroups2[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiBoneLODController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	ABoneLODController::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < shapeGroups1.size(); i1++) {
		for (unsigned int i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			shapeGroups1[i1].linkPairs[i2].shape = FixLink<NiTriShape>( objects, link_stack, info );
			shapeGroups1[i1].linkPairs[i2].skinInstance = FixLink<NiSkinInstance>( objects, link_stack, info );
		};
	};
	for (unsigned int i1 = 0; i1 < shapeGroups2.size(); i1++) {
		shapeGroups2[i1] = FixLink<NiTriShape>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiBoneLODController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = ABoneLODController::GetRefs();
	for (unsigned int i1 = 0; i1 < shapeGroups1.size(); i1++) {
		for (unsigned int i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			if ( shapeGroups1[i1].linkPairs[i2].shape != NULL )
				refs.push_back(StaticCast<NiObject>(shapeGroups1[i1].linkPairs[i2].shape));
			if ( shapeGroups1[i1].linkPairs[i2].skinInstance != NULL )
				refs.push_back(StaticCast<NiObject>(shapeGroups1[i1].linkPairs[i2].skinInstance));
		};
	};
	for (unsigned int i1 = 0; i1 < shapeGroups2.size(); i1++) {
		if ( shapeGroups2[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(shapeGroups2[i1]));
	};
	return refs;
}

void NiBoolData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::Read( in, link_stack, info );
	NifStream( data.numKeys, in, info );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, in, info );
	};
	data.keys.resize(data.numKeys);
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], in, info, data.interpolation );
	};
}

void NiBoolData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AKeyedData::Write( out, link_map, info );
	data.numKeys = (unsigned int)(data.keys.size());
	NifStream( data.numKeys, out, info );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, out, info );
	};
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], out, info, data.interpolation );
	};
}

std::string NiBoolData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AKeyedData::asString();
	data.numKeys = (unsigned int)(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Keys[" << i1 << "]:  " << data.keys[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiBoolData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBoolData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiBooleanExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( booleanData, in, info );
}

void NiBooleanExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	NifStream( booleanData, out, info );
}

std::string NiBooleanExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Boolean Data:  " << booleanData << endl;
	return out.str();
}

void NiBooleanExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBooleanExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiBoolInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( boolValue, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiBoolInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiInterpolator::Write( out, link_map, info );
	NifStream( boolValue, out, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiBoolInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiBoolInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::FixLinks( objects, link_stack, info );
	data = FixLink<NiBoolData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiBoolInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiBoolTimelineInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( boolValue, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiBoolTimelineInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiInterpolator::Write( out, link_map, info );
	NifStream( boolValue, out, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiBoolTimelineInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiBoolTimelineInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::FixLinks( objects, link_stack, info );
	data = FixLink<NiBoolData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiBoolTimelineInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiBSBoneLODController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	ABoneLODController::Read( in, link_stack, info );
}

void NiBSBoneLODController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	ABoneLODController::Write( out, link_map, info );
}

std::string NiBSBoneLODController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << ABoneLODController::asString();
	return out.str();
}

void NiBSBoneLODController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	ABoneLODController::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSBoneLODController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = ABoneLODController::GetRefs();
	return refs;
}

void NiBSplineBasisData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( numControlPt, in, info );
}

void NiBSplineBasisData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	NifStream( numControlPt, out, info );
}

std::string NiBSplineBasisData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Num Control Pt:  " << numControlPt << endl;
	return out.str();
}

void NiBSplineBasisData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSplineBasisData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiBSplineCompFloatInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBSplineInterpolator::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknownFloats[i1], in, info );
	};
}

void NiBSplineCompFloatInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiBSplineInterpolator::Write( out, link_map, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknownFloats[i1], out, info );
	};
}

std::string NiBSplineCompFloatInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBSplineInterpolator::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiBSplineCompFloatInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSplineCompFloatInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	return refs;
}

void NiBSplineCompPoint3Interpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBSplineInterpolator::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], in, info );
	};
}

void NiBSplineCompPoint3Interpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiBSplineInterpolator::Write( out, link_map, info );
	for (unsigned int i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], out, info );
	};
}

std::string NiBSplineCompPoint3Interpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBSplineInterpolator::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 6; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiBSplineCompPoint3Interpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSplineCompPoint3Interpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	return refs;
}

void NiBSplineCompTransformInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBSplineInterpolator::Read( in, link_stack, info );
	NifStream( translation, in, info );
	NifStream( rotation, in, info );
	NifStream( scale, in, info );
	NifStream( translateOffset, in, info );
	NifStream( rotateOffset, in, info );
	NifStream( scaleOffset, in, info );
	NifStream( translateBias, in, info );
	NifStream( translateMultiplier, in, info );
	NifStream( rotationBias, in, info );
	NifStream( rotationMultiplier, in, info );
	NifStream( scaleBias, in, info );
	NifStream( scaleMultiplier, in, info );
}

void NiBSplineCompTransformInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiBSplineInterpolator::Write( out, link_map, info );
	NifStream( translation, out, info );
	NifStream( rotation, out, info );
	NifStream( scale, out, info );
	NifStream( translateOffset, out, info );
	NifStream( rotateOffset, out, info );
	NifStream( scaleOffset, out, info );
	NifStream( translateBias, out, info );
	NifStream( translateMultiplier, out, info );
	NifStream( rotationBias, out, info );
	NifStream( rotationMultiplier, out, info );
	NifStream( scaleBias, out, info );
	NifStream( scaleMultiplier, out, info );
}

std::string NiBSplineCompTransformInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBSplineInterpolator::asString();
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Translate Offset:  " << translateOffset << endl;
	out << "  Rotate Offset:  " << rotateOffset << endl;
	out << "  Scale Offset:  " << scaleOffset << endl;
	out << "  Translate Bias:  " << translateBias << endl;
	out << "  Translate Multiplier:  " << translateMultiplier << endl;
	out << "  Rotation Bias:  " << rotationBias << endl;
	out << "  Rotation Multiplier:  " << rotationMultiplier << endl;
	out << "  Scale Bias:  " << scaleBias << endl;
	out << "  Scale Multiplier:  " << scaleMultiplier << endl;
	return out.str();
}

void NiBSplineCompTransformInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSplineCompTransformInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	return refs;
}

void NiBSplineData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( unknownInt, in, info );
	NifStream( count, in, info );
	controlPoints.resize(count);
	for (unsigned int i1 = 0; i1 < controlPoints.size(); i1++) {
		NifStream( controlPoints[i1], in, info );
	};
}

void NiBSplineData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	count = (unsigned int)(controlPoints.size());
	NifStream( unknownInt, out, info );
	NifStream( count, out, info );
	for (unsigned int i1 = 0; i1 < controlPoints.size(); i1++) {
		NifStream( controlPoints[i1], out, info );
	};
}

std::string NiBSplineData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	count = (unsigned int)(controlPoints.size());
	out << "  Unknown Int:  " << unknownInt << endl;
	out << "  Count:  " << count << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < controlPoints.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Control Points[" << i1 << "]:  " << controlPoints[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiBSplineData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSplineData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiCamera::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort, in, info );
	};
	NifStream( frustumLeft, in, info );
	NifStream( frustumRight, in, info );
	NifStream( frustumTop, in, info );
	NifStream( frustumBottom, in, info );
	NifStream( frustumNear, in, info );
	NifStream( frustumFar, in, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( useOrthographicProjection, in, info );
	};
	NifStream( viewportLeft, in, info );
	NifStream( viewportRight, in, info );
	NifStream( viewportTop, in, info );
	NifStream( viewportBottom, in, info );
	NifStream( lodAdjust, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownInt, in, info );
	if ( info.version >= 0x04020100 ) {
		NifStream( unknownInt2, in, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( unknownInt3, in, info );
	};
}

void NiCamera::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiAVObject::Write( out, link_map, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort, out, info );
	};
	NifStream( frustumLeft, out, info );
	NifStream( frustumRight, out, info );
	NifStream( frustumTop, out, info );
	NifStream( frustumBottom, out, info );
	NifStream( frustumNear, out, info );
	NifStream( frustumFar, out, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( useOrthographicProjection, out, info );
	};
	NifStream( viewportLeft, out, info );
	NifStream( viewportRight, out, info );
	NifStream( viewportTop, out, info );
	NifStream( viewportBottom, out, info );
	NifStream( lodAdjust, out, info );
	if ( unknownLink_ != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink_) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownInt, out, info );
	if ( info.version >= 0x04020100 ) {
		NifStream( unknownInt2, out, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( unknownInt3, out, info );
	};
}

std::string NiCamera::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObject::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Frustum Left:  " << frustumLeft << endl;
	out << "  Frustum Right:  " << frustumRight << endl;
	out << "  Frustum Top:  " << frustumTop << endl;
	out << "  Frustum Bottom:  " << frustumBottom << endl;
	out << "  Frustum Near:  " << frustumNear << endl;
	out << "  Frustum Far:  " << frustumFar << endl;
	out << "  Use Orthographic Projection:  " << useOrthographicProjection << endl;
	out << "  Viewport Left:  " << viewportLeft << endl;
	out << "  Viewport Right:  " << viewportRight << endl;
	out << "  Viewport Top:  " << viewportTop << endl;
	out << "  Viewport Bottom:  " << viewportBottom << endl;
	out << "  LOD Adjust:  " << lodAdjust << endl;
	out << "  Unknown Link?:  " << unknownLink_ << endl;
	out << "  Unknown Int:  " << unknownInt << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	return out.str();
}

void NiCamera::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiAVObject::FixLinks( objects, link_stack, info );
	unknownLink_ = FixLink<NiObject>( objects, link_stack, info );
}

std::list<NiObjectRef> NiCamera::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	if ( unknownLink_ != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink_));
	return refs;
}

void NiCollisionData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownInt1, in, info );
	if ( ( info.version >= 0x0A010000 ) && ( info.version <= 0x0A010000 ) ) {
		NifStream( unknownInt2, in, info );
	};
	NifStream( unknownByte, in, info );
	NifStream( collisionType, in, info );
	if ( (collisionType == 0) ) {
		NifStream( unknownInt2, in, info );
		NifStream( unknownVector, in, info );
	};
	if ( (collisionType == 2) ) {
		for (unsigned int i2 = 0; i2 < 8; i2++) {
			NifStream( unknownFloat1[i2], in, info );
		};
	};
	if ( (collisionType == 1) ) {
		for (unsigned int i2 = 0; i2 < 15; i2++) {
			NifStream( unknownFloat2[i2], in, info );
		};
	};
}

void NiCollisionData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	if ( targetNode != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(targetNode) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownInt1, out, info );
	if ( ( info.version >= 0x0A010000 ) && ( info.version <= 0x0A010000 ) ) {
		NifStream( unknownInt2, out, info );
	};
	NifStream( unknownByte, out, info );
	NifStream( collisionType, out, info );
	if ( (collisionType == 0) ) {
		NifStream( unknownInt2, out, info );
		NifStream( unknownVector, out, info );
	};
	if ( (collisionType == 2) ) {
		for (unsigned int i2 = 0; i2 < 8; i2++) {
			NifStream( unknownFloat1[i2], out, info );
		};
	};
	if ( (collisionType == 1) ) {
		for (unsigned int i2 = 0; i2 < 15; i2++) {
			NifStream( unknownFloat2[i2], out, info );
		};
	};
}

std::string NiCollisionData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Target Node:  " << targetNode << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Collision Type:  " << collisionType << endl;
	if ( (collisionType == 0) ) {
		out << "    Unknown Vector:  " << unknownVector << endl;
	};
	if ( (collisionType == 2) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 8; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Float 1[" << i2 << "]:  " << unknownFloat1[i2] << endl;
			array_output_count++;
		};
	};
	if ( (collisionType == 1) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 15; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Float 2[" << i2 << "]:  " << unknownFloat2[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiCollisionData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	targetNode = FixLink<NiNode>( objects, link_stack, info );
}

std::list<NiObjectRef> NiCollisionData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiColorData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::Read( in, link_stack, info );
	NifStream( data.numKeys, in, info );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, in, info );
	};
	data.keys.resize(data.numKeys);
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], in, info, data.interpolation );
	};
}

void NiColorData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AKeyedData::Write( out, link_map, info );
	data.numKeys = (unsigned int)(data.keys.size());
	NifStream( data.numKeys, out, info );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, out, info );
	};
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], out, info, data.interpolation );
	};
}

std::string NiColorData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AKeyedData::asString();
	data.numKeys = (unsigned int)(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Keys[" << i1 << "]:  " << data.keys[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiColorData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiColorData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiColorExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( data, in, info );
}

void NiColorExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	NifStream( data, out, info );
}

std::string NiColorExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiColorExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiColorExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiControllerManager::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( cumulative, in, info );
	NifStream( numControllerSequences, in, info );
	controllerSequences.resize(numControllerSequences);
	for (unsigned int i1 = 0; i1 < controllerSequences.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiControllerManager::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	numControllerSequences = (unsigned int)(controllerSequences.size());
	NifStream( cumulative, out, info );
	NifStream( numControllerSequences, out, info );
	for (unsigned int i1 = 0; i1 < controllerSequences.size(); i1++) {
		if ( controllerSequences[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(controllerSequences[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( objectPalette != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(objectPalette) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiControllerManager::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	numControllerSequences = (unsigned int)(controllerSequences.size());
	out << "  Cumulative:  " << cumulative << endl;
	out << "  Num Controller Sequences:  " << numControllerSequences << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < controllerSequences.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Controller Sequences[" << i1 << "]:  " << controllerSequences[i1] << endl;
		array_output_count++;
	};
	out << "  Object Palette:  " << objectPalette << endl;
	return out.str();
}

void NiControllerManager::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < controllerSequences.size(); i1++) {
		controllerSequences[i1] = FixLink<NiControllerSequence>( objects, link_stack, info );
	};
	objectPalette = FixLink<NiDefaultAVObjectPalette>( objects, link_stack, info );
}

std::list<NiObjectRef> NiControllerManager::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	for (unsigned int i1 = 0; i1 < controllerSequences.size(); i1++) {
		if ( controllerSequences[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(controllerSequences[i1]));
	};
	if ( objectPalette != NULL )
		refs.push_back(StaticCast<NiObject>(objectPalette));
	return refs;
}

void NiSequence::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( name, in, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( textKeysName, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numControlledBlocks, in, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( unknownInt1, in, info );
	};
	controlledBlocks.resize(numControlledBlocks);
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( info.version <= 0x0A010000 ) {
			NifStream( controlledBlocks[i1].targetName, in, info );
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( info.version >= 0x0A01006A ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
			NifStream( controlledBlocks[i1].unknownShort0, in, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.userVersion == 10 ) ) {
			NifStream( controlledBlocks[i1].priority_, in, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.userVersion == 11 ) ) {
			NifStream( controlledBlocks[i1].priority_, in, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].nodeName, in, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].nodeNameOffset, in, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].propertyType, in, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].propertyTypeOffset, in, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].controllerType, in, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].controllerTypeOffset, in, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].variable1, in, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].variableOffset1, in, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].variable2, in, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].variableOffset2, in, info );
		};
	};
}

void NiSequence::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numControlledBlocks = (unsigned int)(controlledBlocks.size());
	NifStream( name, out, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( textKeysName, out, info );
		if ( textKeys != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(textKeys) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( numControlledBlocks, out, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( unknownInt1, out, info );
	};
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( info.version <= 0x0A010000 ) {
			NifStream( controlledBlocks[i1].targetName, out, info );
			if ( controlledBlocks[i1].controller != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(controlledBlocks[i1].controller) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
		if ( info.version >= 0x0A01006A ) {
			if ( controlledBlocks[i1].interpolator != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(controlledBlocks[i1].interpolator) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
			if ( controlledBlocks[i1].controller != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(controlledBlocks[i1].controller) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			if ( controlledBlocks[i1].unknownLink2 != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(controlledBlocks[i1].unknownLink2) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
			NifStream( controlledBlocks[i1].unknownShort0, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.userVersion == 10 ) ) {
			NifStream( controlledBlocks[i1].priority_, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.userVersion == 11 ) ) {
			NifStream( controlledBlocks[i1].priority_, out, info );
		};
		if ( info.version >= 0x0A020000 ) {
			if ( controlledBlocks[i1].stringPalette != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(controlledBlocks[i1].stringPalette) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].nodeName, out, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].nodeNameOffset, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].propertyType, out, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].propertyTypeOffset, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].controllerType, out, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].controllerTypeOffset, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].variable1, out, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].variableOffset1, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].variable2, out, info );
		};
		if ( info.version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].variableOffset2, out, info );
		};
	};
}

std::string NiSequence::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numControlledBlocks = (unsigned int)(controlledBlocks.size());
	out << "  Name:  " << name << endl;
	out << "  Text Keys Name:  " << textKeysName << endl;
	out << "  Text Keys:  " << textKeys << endl;
	out << "  Num Controlled Blocks:  " << numControlledBlocks << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Target Name:  " << controlledBlocks[i1].targetName << endl;
		out << "    Controller:  " << controlledBlocks[i1].controller << endl;
		out << "    Interpolator:  " << controlledBlocks[i1].interpolator << endl;
		out << "    Unknown Link 2:  " << controlledBlocks[i1].unknownLink2 << endl;
		out << "    Unknown Short 0:  " << controlledBlocks[i1].unknownShort0 << endl;
		out << "    Priority?:  " << controlledBlocks[i1].priority_ << endl;
		out << "    String Palette:  " << controlledBlocks[i1].stringPalette << endl;
		out << "    Node Name:  " << controlledBlocks[i1].nodeName << endl;
		out << "    Node Name Offset:  " << controlledBlocks[i1].nodeNameOffset << endl;
		out << "    Property Type:  " << controlledBlocks[i1].propertyType << endl;
		out << "    Property Type Offset:  " << controlledBlocks[i1].propertyTypeOffset << endl;
		out << "    Controller Type:  " << controlledBlocks[i1].controllerType << endl;
		out << "    Controller Type Offset:  " << controlledBlocks[i1].controllerTypeOffset << endl;
		out << "    Variable 1:  " << controlledBlocks[i1].variable1 << endl;
		out << "    Variable Offset 1:  " << controlledBlocks[i1].variableOffset1 << endl;
		out << "    Variable 2:  " << controlledBlocks[i1].variable2 << endl;
		out << "    Variable Offset 2:  " << controlledBlocks[i1].variableOffset2 << endl;
	};
	return out.str();
}

void NiSequence::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		textKeys = FixLink<NiTextKeyExtraData>( objects, link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( info.version <= 0x0A010000 ) {
			controlledBlocks[i1].controller = FixLink<NiTimeController>( objects, link_stack, info );
		};
		if ( info.version >= 0x0A01006A ) {
			controlledBlocks[i1].interpolator = FixLink<NiInterpolator>( objects, link_stack, info );
			controlledBlocks[i1].controller = FixLink<NiTimeController>( objects, link_stack, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			controlledBlocks[i1].unknownLink2 = FixLink<NiObject>( objects, link_stack, info );
		};
		if ( info.version >= 0x0A020000 ) {
			controlledBlocks[i1].stringPalette = FixLink<NiStringPalette>( objects, link_stack, info );
		};
	};
}

std::list<NiObjectRef> NiSequence::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( textKeys != NULL )
		refs.push_back(StaticCast<NiObject>(textKeys));
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( controlledBlocks[i1].controller != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].controller));
		if ( controlledBlocks[i1].interpolator != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].interpolator));
		if ( controlledBlocks[i1].unknownLink2 != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].unknownLink2));
		if ( controlledBlocks[i1].stringPalette != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].stringPalette));
	};
	return refs;
}

void NiControllerSequence::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiSequence::Read( in, link_stack, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( weight, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( cycleType, in, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknownInt0, in, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( frequency, in, info );
		NifStream( startTime, in, info );
		NifStream( stopTime, in, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) ) {
		NifStream( unknownFloat2, in, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknownByte, in, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( targetName, in, info );
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiControllerSequence::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSequence::Write( out, link_map, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( weight, out, info );
		if ( textKeys != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(textKeys) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( cycleType, out, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknownInt0, out, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( frequency, out, info );
		NifStream( startTime, out, info );
		NifStream( stopTime, out, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x0A020000 ) ) {
		NifStream( unknownFloat2, out, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknownByte, out, info );
	};
	if ( info.version >= 0x0A01006A ) {
		if ( manager != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(manager) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( targetName, out, info );
	};
	if ( info.version >= 0x0A020000 ) {
		if ( stringPalette != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(stringPalette) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiControllerSequence::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSequence::asString();
	out << "  Weight:  " << weight << endl;
	out << "  Text Keys:  " << textKeys << endl;
	out << "  Cycle Type:  " << cycleType << endl;
	out << "  Unknown Int 0:  " << unknownInt0 << endl;
	out << "  Frequency:  " << frequency << endl;
	out << "  Start Time:  " << startTime << endl;
	out << "  Stop Time:  " << stopTime << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Manager:  " << manager << endl;
	out << "  Target Name:  " << targetName << endl;
	out << "  String Palette:  " << stringPalette << endl;
	return out.str();
}

void NiControllerSequence::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSequence::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x0A01006A ) {
		textKeys = FixLink<NiTextKeyExtraData>( objects, link_stack, info );
		manager = FixLink<NiControllerManager>( objects, link_stack, info );
	};
	if ( info.version >= 0x0A020000 ) {
		stringPalette = FixLink<NiStringPalette>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiControllerSequence::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSequence::GetRefs();
	if ( textKeys != NULL )
		refs.push_back(StaticCast<NiObject>(textKeys));
	if ( stringPalette != NULL )
		refs.push_back(StaticCast<NiObject>(stringPalette));
	return refs;
}

void NiDefaultAVObjectPalette::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( unknownInt, in, info );
	NifStream( numObjs, in, info );
	objs.resize(numObjs);
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
		NifStream( objs[i1].name, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiDefaultAVObjectPalette::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numObjs = (unsigned int)(objs.size());
	NifStream( unknownInt, out, info );
	NifStream( numObjs, out, info );
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
		NifStream( objs[i1].name, out, info );
		if ( objs[i1].avObject != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(objs[i1].avObject) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiDefaultAVObjectPalette::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numObjs = (unsigned int)(objs.size());
	out << "  Unknown Int:  " << unknownInt << endl;
	out << "  Num Objs:  " << numObjs << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Name:  " << objs[i1].name << endl;
		out << "    AV Object:  " << objs[i1].avObject << endl;
	};
	return out.str();
}

void NiDefaultAVObjectPalette::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
		objs[i1].avObject = FixLink<NiAVObject>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiDefaultAVObjectPalette::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	for (unsigned int i1 = 0; i1 < objs.size(); i1++) {
	};
	return refs;
}

void NiDirectionalLight::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLight::Read( in, link_stack, info );
}

void NiDirectionalLight::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiLight::Write( out, link_map, info );
}

std::string NiDirectionalLight::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiLight::asString();
	return out.str();
}

void NiDirectionalLight::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLight::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiDirectionalLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLight::GetRefs();
	return refs;
}

void NiDitherProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
}

void NiDitherProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
}

std::string NiDitherProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiDitherProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiDitherProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiFlipController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiSingleInterpolatorController::Read( in, link_stack, info );
	NifStream( textureSlot, in, info );
	if ( ( info.version >= 0x04000000 ) && ( info.version <= 0x0A010000 ) ) {
		NifStream( unknownInt2, in, info );
	};
	if ( info.version <= 0x0A010000 ) {
		NifStream( delta, in, info );
	};
	NifStream( numSources, in, info );
	if ( info.version >= 0x04000000 ) {
		sources.resize(numSources);
		for (unsigned int i2 = 0; i2 < sources.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version <= 0x03010000 ) {
		image.resize(numSources);
		for (unsigned int i2 = 0; i2 < image.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
}

void NiFlipController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSingleInterpolatorController::Write( out, link_map, info );
	numSources = (unsigned int)(sources.size());
	NifStream( textureSlot, out, info );
	if ( ( info.version >= 0x04000000 ) && ( info.version <= 0x0A010000 ) ) {
		NifStream( unknownInt2, out, info );
	};
	if ( info.version <= 0x0A010000 ) {
		NifStream( delta, out, info );
	};
	NifStream( numSources, out, info );
	if ( info.version >= 0x04000000 ) {
		for (unsigned int i2 = 0; i2 < sources.size(); i2++) {
			if ( sources[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(sources[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
	if ( info.version <= 0x03010000 ) {
		for (unsigned int i2 = 0; i2 < image.size(); i2++) {
			if ( image[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(image[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
}

std::string NiFlipController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	numSources = (unsigned int)(sources.size());
	out << "  Texture Slot:  " << textureSlot << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Delta:  " << delta << endl;
	out << "  Num Sources:  " << numSources << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < sources.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Sources[" << i1 << "]:  " << sources[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < image.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Image[" << i1 << "]:  " << image[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiFlipController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x04000000 ) {
		for (unsigned int i2 = 0; i2 < sources.size(); i2++) {
			sources[i2] = FixLink<NiSourceTexture>( objects, link_stack, info );
		};
	};
	if ( info.version <= 0x03010000 ) {
		for (unsigned int i2 = 0; i2 < image.size(); i2++) {
			image[i2] = FixLink<NiImage>( objects, link_stack, info );
		};
	};
}

std::list<NiObjectRef> NiFlipController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	for (unsigned int i1 = 0; i1 < sources.size(); i1++) {
		if ( sources[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(sources[i1]));
	};
	for (unsigned int i1 = 0; i1 < image.size(); i1++) {
		if ( image[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(image[i1]));
	};
	return refs;
}

void NiRollController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiSingleInterpolatorController::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiRollController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSingleInterpolatorController::Write( out, link_map, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiRollController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiRollController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, info );
	data = FixLink<NiFloatData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiRollController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiFloatData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::Read( in, link_stack, info );
	NifStream( data.numKeys, in, info );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, in, info );
	};
	data.keys.resize(data.numKeys);
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], in, info, data.interpolation );
	};
}

void NiFloatData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AKeyedData::Write( out, link_map, info );
	data.numKeys = (unsigned int)(data.keys.size());
	NifStream( data.numKeys, out, info );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, out, info );
	};
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], out, info, data.interpolation );
	};
}

std::string NiFloatData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AKeyedData::asString();
	data.numKeys = (unsigned int)(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Keys[" << i1 << "]:  " << data.keys[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiFloatData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiFloatData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiFloatExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( floatData, in, info );
}

void NiFloatExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	NifStream( floatData, out, info );
}

std::string NiFloatExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Float Data:  " << floatData << endl;
	return out.str();
}

void NiFloatExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiFloatExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiFloatExtraDataController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	if ( info.version >= 0x14000004 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( unknownString, in, info );
	};
}

void NiFloatExtraDataController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	if ( info.version >= 0x14000004 ) {
		if ( unknownLink != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( unknownString, out, info );
	};
}

std::string NiFloatExtraDataController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	out << "  Unknown String:  " << unknownString << endl;
	return out.str();
}

void NiFloatExtraDataController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x14000004 ) {
		unknownLink = FixLink<NiObject>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiFloatExtraDataController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiFloatInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( floatValue, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiFloatInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiInterpolator::Write( out, link_map, info );
	NifStream( floatValue, out, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiFloatInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Float Value:  " << floatValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiFloatInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::FixLinks( objects, link_stack, info );
	data = FixLink<NiFloatData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiFloatInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiFloatsExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( numFloats, in, info );
	data.resize(numFloats);
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], in, info );
	};
}

void NiFloatsExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	numFloats = (unsigned int)(data.size());
	NifStream( numFloats, out, info );
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], out, info );
	};
}

std::string NiFloatsExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	numFloats = (unsigned int)(data.size());
	out << "  Num Floats:  " << numFloats << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Data[" << i1 << "]:  " << data[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiFloatsExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiFloatsExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiFogProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( fogDepth, in, info );
	NifStream( fogColor, in, info );
}

void NiFogProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
	NifStream( fogDepth, out, info );
	NifStream( fogColor, out, info );
}

std::string NiFogProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Fog Depth:  " << fogDepth << endl;
	out << "  Fog Color:  " << fogColor << endl;
	return out.str();
}

void NiFogProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiFogProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiGeomMorpherController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknown, in, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknown2, in, info );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownByte, in, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( numInterpolators, in, info );
		interpolators.resize(numInterpolators);
		for (unsigned int i2 = 0; i2 < interpolators.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( numUnknownInts, in, info );
		unknownInts.resize(numUnknownInts);
		for (unsigned int i2 = 0; i2 < unknownInts.size(); i2++) {
			NifStream( unknownInts[i2], in, info );
		};
	};
}

void NiGeomMorpherController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	numUnknownInts = (unsigned int)(unknownInts.size());
	numInterpolators = (unsigned int)(interpolators.size());
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknown, out, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( unknown2, out, info );
	};
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownByte, out, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( numInterpolators, out, info );
		for (unsigned int i2 = 0; i2 < interpolators.size(); i2++) {
			if ( interpolators[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(interpolators[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( numUnknownInts, out, info );
		for (unsigned int i2 = 0; i2 < unknownInts.size(); i2++) {
			NifStream( unknownInts[i2], out, info );
		};
	};
}

std::string NiGeomMorpherController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	numUnknownInts = (unsigned int)(unknownInts.size());
	numInterpolators = (unsigned int)(interpolators.size());
	out << "  Unknown:  " << unknown << endl;
	out << "  Unknown 2:  " << unknown2 << endl;
	out << "  Data:  " << data << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Num Interpolators:  " << numInterpolators << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < interpolators.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Interpolators[" << i1 << "]:  " << interpolators[i1] << endl;
		array_output_count++;
	};
	out << "  Num Unknown Ints:  " << numUnknownInts << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownInts.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints[" << i1 << "]:  " << unknownInts[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiGeomMorpherController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	data = FixLink<NiMorphData>( objects, link_stack, info );
	if ( info.version >= 0x0A01006A ) {
		for (unsigned int i2 = 0; i2 < interpolators.size(); i2++) {
			interpolators[i2] = FixLink<NiInterpolator>( objects, link_stack, info );
		};
	};
}

std::list<NiObjectRef> NiGeomMorpherController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	for (unsigned int i1 = 0; i1 < interpolators.size(); i1++) {
		if ( interpolators[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(interpolators[i1]));
	};
	return refs;
}

void NiGravity::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::Read( in, link_stack, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownFloat1, in, info );
	};
	NifStream( force, in, info );
	NifStream( type, in, info );
	NifStream( position, in, info );
	NifStream( direction, in, info );
}

void NiGravity::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AParticleModifier::Write( out, link_map, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownFloat1, out, info );
	};
	NifStream( force, out, info );
	NifStream( type, out, info );
	NifStream( position, out, info );
	NifStream( direction, out, info );
}

std::string NiGravity::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Force:  " << force << endl;
	out << "  Type:  " << type << endl;
	out << "  Position:  " << position << endl;
	out << "  Direction:  " << direction << endl;
	return out.str();
}

void NiGravity::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiGravity::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiIntegerExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( integerData, in, info );
}

void NiIntegerExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	NifStream( integerData, out, info );
}

std::string NiIntegerExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Integer Data:  " << integerData << endl;
	return out.str();
}

void NiIntegerExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiIntegerExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiIntegersExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( numIntegers, in, info );
	data.resize(numIntegers);
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], in, info );
	};
}

void NiIntegersExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	numIntegers = (unsigned int)(data.size());
	NifStream( numIntegers, out, info );
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], out, info );
	};
}

std::string NiIntegersExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	numIntegers = (unsigned int)(data.size());
	out << "  Num Integers:  " << numIntegers << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Data[" << i1 << "]:  " << data[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiIntegersExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiIntegersExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiKeyframeController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiKeyframeController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiKeyframeController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiKeyframeController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	data = FixLink<NiKeyframeData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiKeyframeController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void BSKeyframeController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiKeyframeController::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void BSKeyframeController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiKeyframeController::Write( out, link_map, info );
	if ( data2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string BSKeyframeController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiKeyframeController::asString();
	out << "  Data 2:  " << data2 << endl;
	return out.str();
}

void BSKeyframeController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiKeyframeController::FixLinks( objects, link_stack, info );
	data2 = FixLink<NiKeyframeData>( objects, link_stack, info );
}

std::list<NiObjectRef> BSKeyframeController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyframeController::GetRefs();
	if ( data2 != NULL )
		refs.push_back(StaticCast<NiObject>(data2));
	return refs;
}

void NiKeyframeData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::Read( in, link_stack, info );
	NifStream( numRotationKeys, in, info );
	if ( (numRotationKeys != 0) ) {
		NifStream( rotationType, in, info );
	};
	if ( (rotationType != 4) ) {
		quaternionKeys.resize(numRotationKeys);
		for (unsigned int i2 = 0; i2 < quaternionKeys.size(); i2++) {
			NifStream( quaternionKeys[i2], in, info, rotationType );
		};
	};
	if ( info.version <= 0x0A010000 ) {
		if ( (rotationType == 4) ) {
			NifStream( unknownFloat, in, info );
		};
	};
	if ( (rotationType == 4) ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			NifStream( xyzRotations[i2].numKeys, in, info );
			if ( (xyzRotations[i2].numKeys != 0) ) {
				NifStream( xyzRotations[i2].interpolation, in, info );
			};
			xyzRotations[i2].keys.resize(xyzRotations[i2].numKeys);
			for (unsigned int i3 = 0; i3 < xyzRotations[i2].keys.size(); i3++) {
				NifStream( xyzRotations[i2].keys[i3], in, info, xyzRotations[i2].interpolation );
			};
		};
	};
	NifStream( translations.numKeys, in, info );
	if ( (translations.numKeys != 0) ) {
		NifStream( translations.interpolation, in, info );
	};
	translations.keys.resize(translations.numKeys);
	for (unsigned int i1 = 0; i1 < translations.keys.size(); i1++) {
		NifStream( translations.keys[i1], in, info, translations.interpolation );
	};
	NifStream( scales.numKeys, in, info );
	if ( (scales.numKeys != 0) ) {
		NifStream( scales.interpolation, in, info );
	};
	scales.keys.resize(scales.numKeys);
	for (unsigned int i1 = 0; i1 < scales.keys.size(); i1++) {
		NifStream( scales.keys[i1], in, info, scales.interpolation );
	};
}

void NiKeyframeData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AKeyedData::Write( out, link_map, info );
	NifStream( numRotationKeys, out, info );
	if ( (numRotationKeys != 0) ) {
		NifStream( rotationType, out, info );
	};
	if ( (rotationType != 4) ) {
		for (unsigned int i2 = 0; i2 < quaternionKeys.size(); i2++) {
			NifStream( quaternionKeys[i2], out, info, rotationType );
		};
	};
	if ( info.version <= 0x0A010000 ) {
		if ( (rotationType == 4) ) {
			NifStream( unknownFloat, out, info );
		};
	};
	if ( (rotationType == 4) ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			xyzRotations[i2].numKeys = (unsigned int)(xyzRotations[i2].keys.size());
			NifStream( xyzRotations[i2].numKeys, out, info );
			if ( (xyzRotations[i2].numKeys != 0) ) {
				NifStream( xyzRotations[i2].interpolation, out, info );
			};
			for (unsigned int i3 = 0; i3 < xyzRotations[i2].keys.size(); i3++) {
				NifStream( xyzRotations[i2].keys[i3], out, info, xyzRotations[i2].interpolation );
			};
		};
	};
	translations.numKeys = (unsigned int)(translations.keys.size());
	NifStream( translations.numKeys, out, info );
	if ( (translations.numKeys != 0) ) {
		NifStream( translations.interpolation, out, info );
	};
	for (unsigned int i1 = 0; i1 < translations.keys.size(); i1++) {
		NifStream( translations.keys[i1], out, info, translations.interpolation );
	};
	scales.numKeys = (unsigned int)(scales.keys.size());
	NifStream( scales.numKeys, out, info );
	if ( (scales.numKeys != 0) ) {
		NifStream( scales.interpolation, out, info );
	};
	for (unsigned int i1 = 0; i1 < scales.keys.size(); i1++) {
		NifStream( scales.keys[i1], out, info, scales.interpolation );
	};
}

std::string NiKeyframeData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AKeyedData::asString();
	out << "  Num Rotation Keys:  " << numRotationKeys << endl;
	if ( (numRotationKeys != 0) ) {
		out << "    Rotation Type:  " << rotationType << endl;
	};
	if ( (rotationType != 4) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < quaternionKeys.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Quaternion Keys[" << i2 << "]:  " << quaternionKeys[i2] << endl;
			array_output_count++;
		};
	};
	if ( (rotationType == 4) ) {
		out << "    Unknown Float:  " << unknownFloat << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			xyzRotations[i2].numKeys = (unsigned int)(xyzRotations[i2].keys.size());
			out << "      Num Keys:  " << xyzRotations[i2].numKeys << endl;
			if ( (xyzRotations[i2].numKeys != 0) ) {
				out << "        Interpolation:  " << xyzRotations[i2].interpolation << endl;
			};
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < xyzRotations[i2].keys.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Keys[" << i3 << "]:  " << xyzRotations[i2].keys[i3] << endl;
				array_output_count++;
			};
		};
	};
	translations.numKeys = (unsigned int)(translations.keys.size());
	out << "  Num Keys:  " << translations.numKeys << endl;
	if ( (translations.numKeys != 0) ) {
		out << "    Interpolation:  " << translations.interpolation << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < translations.keys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Keys[" << i1 << "]:  " << translations.keys[i1] << endl;
		array_output_count++;
	};
	scales.numKeys = (unsigned int)(scales.keys.size());
	out << "  Num Keys:  " << scales.numKeys << endl;
	if ( (scales.numKeys != 0) ) {
		out << "    Interpolation:  " << scales.interpolation << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < scales.keys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Keys[" << i1 << "]:  " << scales.keys[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiKeyframeData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiKeyframeData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiLightColorController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	if ( ( info.version >= 0x0A010000 ) && ( info.version <= 0x0A010000 ) ) {
		NifStream( unknownShort, in, info );
	};
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( unknownShort, in, info );
	};
}

void NiLightColorController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	if ( ( info.version >= 0x0A010000 ) && ( info.version <= 0x0A010000 ) ) {
		NifStream( unknownShort, out, info );
	};
	if ( info.version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( info.version >= 0x0A020000 ) {
		if ( interpolator != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(interpolator) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( unknownShort, out, info );
	};
}

std::string NiLightColorController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Data:  " << data << endl;
	out << "  Interpolator:  " << interpolator << endl;
	return out.str();
}

void NiLightColorController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		data = FixLink<NiPosData>( objects, link_stack, info );
	};
	if ( info.version >= 0x0A020000 ) {
		interpolator = FixLink<NiPoint3Interpolator>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiLightColorController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( interpolator != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator));
	return refs;
}

void NiLightDimmerController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiLightDimmerController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	if ( unknownLink != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiLightDimmerController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiLightDimmerController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	unknownLink = FixLink<NiInterpolator>( objects, link_stack, info );
}

std::list<NiObjectRef> NiLightDimmerController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiLookAtController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknown1, in, info );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiLookAtController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknown1, out, info );
	};
	if ( lookAtNode != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(lookAtNode) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiLookAtController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown1:  " << unknown1 << endl;
	out << "  Look At Node:  " << lookAtNode << endl;
	return out.str();
}

void NiLookAtController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	lookAtNode = FixLink<NiNode>( objects, link_stack, info );
}

std::list<NiObjectRef> NiLookAtController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( lookAtNode != NULL )
		refs.push_back(StaticCast<NiObject>(lookAtNode));
	return refs;
}

void NiLookAtInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( unknownShort, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownFloat, in, info );
	NifStream( translation, in, info );
	NifStream( rotation, in, info );
	NifStream( scale, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiLookAtInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiInterpolator::Write( out, link_map, info );
	NifStream( unknownShort, out, info );
	if ( lookAt != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(lookAt) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownFloat, out, info );
	NifStream( translation, out, info );
	NifStream( rotation, out, info );
	NifStream( scale, out, info );
	if ( unknownLink1 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink1) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink3 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink3) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiLookAtInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Look At:  " << lookAt << endl;
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Unknown Link 1:  " << unknownLink1 << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	out << "  Unknown Link 3:  " << unknownLink3 << endl;
	return out.str();
}

void NiLookAtInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::FixLinks( objects, link_stack, info );
	lookAt = FixLink<NiNode>( objects, link_stack, info );
	unknownLink1 = FixLink<NiPoint3Interpolator>( objects, link_stack, info );
	unknownLink2 = FixLink<NiFloatInterpolator>( objects, link_stack, info );
	unknownLink3 = FixLink<NiFloatInterpolator>( objects, link_stack, info );
}

std::list<NiObjectRef> NiLookAtInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( lookAt != NULL )
		refs.push_back(StaticCast<NiObject>(lookAt));
	if ( unknownLink1 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink1));
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	if ( unknownLink3 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink3));
	return refs;
}

void NiMaterialColorController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiSingleInterpolatorController::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( targetColor, in, info );
	};
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiMaterialColorController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSingleInterpolatorController::Write( out, link_map, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( targetColor, out, info );
	};
	if ( info.version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiMaterialColorController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Target Color:  " << targetColor << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiMaterialColorController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		data = FixLink<NiPosData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiMaterialColorController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiMaterialProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, in, info );
	};
	NifStream( ambientColor, in, info );
	NifStream( diffuseColor, in, info );
	NifStream( specularColor, in, info );
	NifStream( emissiveColor, in, info );
	NifStream( glossiness, in, info );
	NifStream( alpha, in, info );
}

void NiMaterialProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, out, info );
	};
	NifStream( ambientColor, out, info );
	NifStream( diffuseColor, out, info );
	NifStream( specularColor, out, info );
	NifStream( emissiveColor, out, info );
	NifStream( glossiness, out, info );
	NifStream( alpha, out, info );
}

std::string NiMaterialProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Ambient Color:  " << ambientColor << endl;
	out << "  Diffuse Color:  " << diffuseColor << endl;
	out << "  Specular Color:  " << specularColor << endl;
	out << "  Emissive Color:  " << emissiveColor << endl;
	out << "  Glossiness:  " << glossiness << endl;
	out << "  Alpha:  " << alpha << endl;
	return out.str();
}

void NiMaterialProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiMaterialProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiMeshPSysData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	APSysData::Read( in, link_stack, info );
	if ( info.version >= 0x14000005 ) {
		NifStream( unknownByte11, in, info );
	};
	if ( info.version <= 0x14000004 ) {
		unknownFloats4.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats4[i2][i3], in, info );
			};
		};
	};
	if ( info.version >= 0x14000005 ) {
		unknownFloats5.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats5.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 12; i3++) {
				NifStream( unknownFloats5[i2][i3], in, info );
			};
		};
	};
	NifStream( unknownInt1, in, info );
	if ( info.version <= 0x14000004 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14000004 ) ) {
		NifStream( unknownByte2, in, info );
		NifStream( numUnknownLinks, in, info );
		unknownLinks.resize(numUnknownLinks);
		for (unsigned int i2 = 0; i2 < unknownLinks.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version >= 0x14000005 ) {
		NifStream( unknownShort4, in, info );
		NifStream( unknownInt2, in, info );
		NifStream( unknownByte12, in, info );
		NifStream( unknownInt3, in, info );
		NifStream( unknownInt4, in, info );
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiMeshPSysData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysData::Write( out, link_map, info );
	numUnknownLinks = (unsigned int)(unknownLinks.size());
	if ( info.version >= 0x14000005 ) {
		NifStream( unknownByte11, out, info );
	};
	if ( info.version <= 0x14000004 ) {
		for (unsigned int i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats4[i2][i3], out, info );
			};
		};
	};
	if ( info.version >= 0x14000005 ) {
		for (unsigned int i2 = 0; i2 < unknownFloats5.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 12; i3++) {
				NifStream( unknownFloats5[i2][i3], out, info );
			};
		};
	};
	NifStream( unknownInt1, out, info );
	if ( info.version <= 0x14000004 ) {
		if ( modifier != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(modifier) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14000004 ) ) {
		NifStream( unknownByte2, out, info );
		NifStream( numUnknownLinks, out, info );
		for (unsigned int i2 = 0; i2 < unknownLinks.size(); i2++) {
			if ( unknownLinks[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(unknownLinks[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
	if ( info.version >= 0x14000005 ) {
		NifStream( unknownShort4, out, info );
		NifStream( unknownInt2, out, info );
		NifStream( unknownByte12, out, info );
		NifStream( unknownInt3, out, info );
		NifStream( unknownInt4, out, info );
	};
	if ( info.version >= 0x0A020000 ) {
		if ( unknownLink2 != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiMeshPSysData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysData::asString();
	numUnknownLinks = (unsigned int)(unknownLinks.size());
	out << "  Unknown Byte 11:  " << unknownByte11 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownFloats4.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 10; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 4[" << i2 << "]:  " << unknownFloats4[i1][i2] << endl;
			array_output_count++;
		};
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownFloats5.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 12; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 5[" << i2 << "]:  " << unknownFloats5[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Modifier:  " << modifier << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Num Unknown Links:  " << numUnknownLinks << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Links[" << i1 << "]:  " << unknownLinks[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Byte 12:  " << unknownByte12 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	return out.str();
}

void NiMeshPSysData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysData::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x14000004 ) {
		modifier = FixLink<NiObject>( objects, link_stack, info );
	};
	if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14000004 ) ) {
		for (unsigned int i2 = 0; i2 < unknownLinks.size(); i2++) {
			unknownLinks[i2] = FixLink<NiObject>( objects, link_stack, info );
		};
	};
	if ( info.version >= 0x0A020000 ) {
		unknownLink2 = FixLink<NiNode>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiMeshPSysData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysData::GetRefs();
	if ( modifier != NULL )
		refs.push_back(StaticCast<NiObject>(modifier));
	for (unsigned int i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( unknownLinks[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(unknownLinks[i1]));
	};
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	return refs;
}

void NiMorphData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( numMorphs, in, info );
	NifStream( numVertices, in, info );
	NifStream( unknownByte, in, info );
	morphs.resize(numMorphs);
	for (unsigned int i1 = 0; i1 < morphs.size(); i1++) {
		if ( info.version >= 0x0A01006A ) {
			NifStream( morphs[i1].frameName, in, info );
		};
		if ( info.version <= 0x0A010000 ) {
			NifStream( morphs[i1].numKeys, in, info );
			NifStream( morphs[i1].interpolation, in, info );
			morphs[i1].keys.resize(morphs[i1].numKeys);
			for (unsigned int i3 = 0; i3 < morphs[i1].keys.size(); i3++) {
				NifStream( morphs[i1].keys[i3], in, info, morphs[i1].interpolation );
			};
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( morphs[i1].unknownInt, in, info );
		};
		morphs[i1].vectors.resize(numVertices);
		for (unsigned int i2 = 0; i2 < morphs[i1].vectors.size(); i2++) {
			NifStream( morphs[i1].vectors[i2], in, info );
		};
	};
}

void NiMorphData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numMorphs = (unsigned int)(morphs.size());
	NifStream( numMorphs, out, info );
	NifStream( numVertices, out, info );
	NifStream( unknownByte, out, info );
	for (unsigned int i1 = 0; i1 < morphs.size(); i1++) {
		morphs[i1].numKeys = (unsigned int)(morphs[i1].keys.size());
		if ( info.version >= 0x0A01006A ) {
			NifStream( morphs[i1].frameName, out, info );
		};
		if ( info.version <= 0x0A010000 ) {
			NifStream( morphs[i1].numKeys, out, info );
			NifStream( morphs[i1].interpolation, out, info );
			for (unsigned int i3 = 0; i3 < morphs[i1].keys.size(); i3++) {
				NifStream( morphs[i1].keys[i3], out, info, morphs[i1].interpolation );
			};
		};
		if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
			NifStream( morphs[i1].unknownInt, out, info );
		};
		for (unsigned int i2 = 0; i2 < morphs[i1].vectors.size(); i2++) {
			NifStream( morphs[i1].vectors[i2], out, info );
		};
	};
}

std::string NiMorphData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numMorphs = (unsigned int)(morphs.size());
	out << "  Num Morphs:  " << numMorphs << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < morphs.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		morphs[i1].numKeys = (unsigned int)(morphs[i1].keys.size());
		out << "    Frame Name:  " << morphs[i1].frameName << endl;
		out << "    Num Keys:  " << morphs[i1].numKeys << endl;
		out << "    Interpolation:  " << morphs[i1].interpolation << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < morphs[i1].keys.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Keys[" << i2 << "]:  " << morphs[i1].keys[i2] << endl;
			array_output_count++;
		};
		out << "    Unknown Int:  " << morphs[i1].unknownInt << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < morphs[i1].vectors.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vectors[" << i2 << "]:  " << morphs[i1].vectors[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiMorphData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiMorphData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiMultiTargetTransformController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( numExtraTargets, in, info );
	extraTargets.resize(numExtraTargets);
	for (unsigned int i1 = 0; i1 < extraTargets.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiMultiTargetTransformController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	numExtraTargets = (unsigned short)(extraTargets.size());
	NifStream( numExtraTargets, out, info );
	for (unsigned int i1 = 0; i1 < extraTargets.size(); i1++) {
		if ( extraTargets[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(extraTargets[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiMultiTargetTransformController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	numExtraTargets = (unsigned short)(extraTargets.size());
	out << "  Num Extra Targets:  " << numExtraTargets << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < extraTargets.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Extra Targets[" << i1 << "]:  " << extraTargets[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiMultiTargetTransformController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < extraTargets.size(); i1++) {
		extraTargets[i1] = FixLink<NiNode>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiMultiTargetTransformController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	for (unsigned int i1 = 0; i1 < extraTargets.size(); i1++) {
	};
	return refs;
}

void NiNode::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiAVObject::Read( in, link_stack, info );
	NifStream( numChildren, in, info );
	children.resize(numChildren);
	for (unsigned int i1 = 0; i1 < children.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numEffects, in, info );
	effects.resize(numEffects);
	for (unsigned int i1 = 0; i1 < effects.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiNode::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiAVObject::Write( out, link_map, info );
	numEffects = (unsigned int)(effects.size());
	numChildren = (unsigned int)(children.size());
	NifStream( numChildren, out, info );
	for (unsigned int i1 = 0; i1 < children.size(); i1++) {
		if ( children[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(children[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( numEffects, out, info );
	for (unsigned int i1 = 0; i1 < effects.size(); i1++) {
		if ( effects[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(effects[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiNode::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAVObject::asString();
	numEffects = (unsigned int)(effects.size());
	numChildren = (unsigned int)(children.size());
	out << "  Num Children:  " << numChildren << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < children.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Children[" << i1 << "]:  " << children[i1] << endl;
		array_output_count++;
	};
	out << "  Num Effects:  " << numEffects << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < effects.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Effects[" << i1 << "]:  " << effects[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiNode::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiAVObject::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < children.size(); i1++) {
		children[i1] = FixLink<NiAVObject>( objects, link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < effects.size(); i1++) {
		effects[i1] = FixLink<NiDynamicEffect>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	for (unsigned int i1 = 0; i1 < children.size(); i1++) {
		if ( children[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(children[i1]));
	};
	for (unsigned int i1 = 0; i1 < effects.size(); i1++) {
		if ( effects[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(effects[i1]));
	};
	return refs;
}

void AvoidNode::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::Read( in, link_stack, info );
}

void AvoidNode::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiNode::Write( out, link_map, info );
}

std::string AvoidNode::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	return out.str();
}

void AvoidNode::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> AvoidNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void FxWidget::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::Read( in, link_stack, info );
	NifStream( unknown1, in, info );
	for (unsigned int i1 = 0; i1 < 292; i1++) {
		NifStream( unknown292Bytes[i1], in, info );
	};
}

void FxWidget::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiNode::Write( out, link_map, info );
	NifStream( unknown1, out, info );
	for (unsigned int i1 = 0; i1 < 292; i1++) {
		NifStream( unknown292Bytes[i1], out, info );
	};
}

std::string FxWidget::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	out << "  Unknown1:  " << unknown1 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 292; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 292 Bytes[" << i1 << "]:  " << unknown292Bytes[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void FxWidget::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> FxWidget::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void FxButton::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	FxWidget::Read( in, link_stack, info );
}

void FxButton::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	FxWidget::Write( out, link_map, info );
}

std::string FxButton::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << FxWidget::asString();
	return out.str();
}

void FxButton::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	FxWidget::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> FxButton::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = FxWidget::GetRefs();
	return refs;
}

void FxRadioButton::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	FxWidget::Read( in, link_stack, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( numButtons, in, info );
	buttons.resize(numButtons);
	for (unsigned int i1 = 0; i1 < buttons.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void FxRadioButton::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	FxWidget::Write( out, link_map, info );
	numButtons = (unsigned int)(buttons.size());
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( numButtons, out, info );
	for (unsigned int i1 = 0; i1 < buttons.size(); i1++) {
		if ( buttons[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(buttons[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string FxRadioButton::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << FxWidget::asString();
	numButtons = (unsigned int)(buttons.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int  2:  " << unknownInt2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Num Buttons:  " << numButtons << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < buttons.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Buttons[" << i1 << "]:  " << buttons[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void FxRadioButton::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	FxWidget::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < buttons.size(); i1++) {
		buttons[i1] = FixLink<FxRadioButton>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> FxRadioButton::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = FxWidget::GetRefs();
	for (unsigned int i1 = 0; i1 < buttons.size(); i1++) {
	};
	return refs;
}

void NiBillboardNode::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( billboardMode, in, info );
	};
}

void NiBillboardNode::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiNode::Write( out, link_map, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( billboardMode, out, info );
	};
}

std::string NiBillboardNode::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	out << "  Billboard Mode:  " << billboardMode << endl;
	return out.str();
}

void NiBillboardNode::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBillboardNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void NiBSAnimationNode::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::Read( in, link_stack, info );
}

void NiBSAnimationNode::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiNode::Write( out, link_map, info );
}

std::string NiBSAnimationNode::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	return out.str();
}

void NiBSAnimationNode::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSAnimationNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void NiBSParticleNode::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::Read( in, link_stack, info );
}

void NiBSParticleNode::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiNode::Write( out, link_map, info );
}

std::string NiBSParticleNode::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	return out.str();
}

void NiBSParticleNode::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSParticleNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void NiLODNode::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiNode::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Bytes[i1], in, info );
	};
	if ( ( info.version >= 0x04000002 ) && ( info.version <= 0x0A000100 ) ) {
		NifStream( lodCenter, in, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( numLodLevels, in, info );
		lodLevels.resize(numLodLevels);
		for (unsigned int i2 = 0; i2 < lodLevels.size(); i2++) {
			NifStream( lodLevels[i2].nearExtent, in, info );
			NifStream( lodLevels[i2].farExtent, in, info );
			if ( info.version <= 0x03010000 ) {
				for (unsigned int i4 = 0; i4 < 3; i4++) {
					NifStream( lodLevels[i2].unknownInts[i4], in, info );
				};
			};
		};
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiLODNode::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiNode::Write( out, link_map, info );
	numLodLevels = (unsigned int)(lodLevels.size());
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Bytes[i1], out, info );
	};
	if ( ( info.version >= 0x04000002 ) && ( info.version <= 0x0A000100 ) ) {
		NifStream( lodCenter, out, info );
	};
	if ( info.version <= 0x0A000100 ) {
		NifStream( numLodLevels, out, info );
		for (unsigned int i2 = 0; i2 < lodLevels.size(); i2++) {
			NifStream( lodLevels[i2].nearExtent, out, info );
			NifStream( lodLevels[i2].farExtent, out, info );
			if ( info.version <= 0x03010000 ) {
				for (unsigned int i4 = 0; i4 < 3; i4++) {
					NifStream( lodLevels[i2].unknownInts[i4], out, info );
				};
			};
		};
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort, out, info );
		if ( lodLevelData != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(lodLevelData) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiLODNode::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	numLodLevels = (unsigned int)(lodLevels.size());
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 4 Bytes[" << i1 << "]:  " << unknown4Bytes[i1] << endl;
		array_output_count++;
	};
	out << "  LOD Center:  " << lodCenter << endl;
	out << "  Num LOD Levels:  " << numLodLevels << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < lodLevels.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Near Extent:  " << lodLevels[i1].nearExtent << endl;
		out << "    Far Extent:  " << lodLevels[i1].farExtent << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Ints[" << i2 << "]:  " << lodLevels[i1].unknownInts[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  LOD Level Data:  " << lodLevelData << endl;
	return out.str();
}

void NiLODNode::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		lodLevelData = FixLink<NiLODData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiLODNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	if ( lodLevelData != NULL )
		refs.push_back(StaticCast<NiObject>(lodLevelData));
	return refs;
}

void NiPalette::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( unknownByte, in, info );
	NifStream( numEntries_, in, info );
	for (unsigned int i1 = 0; i1 < 256; i1++) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( palette[i1][i2], in, info );
		};
	};
}

void NiPalette::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	NifStream( unknownByte, out, info );
	NifStream( numEntries_, out, info );
	for (unsigned int i1 = 0; i1 < 256; i1++) {
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			NifStream( palette[i1][i2], out, info );
		};
	};
}

std::string NiPalette::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Num Entries?:  " << numEntries_ << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 256; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Palette[" << i2 << "]:  " << palette[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiPalette::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPalette::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiParticleBomb::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::Read( in, link_stack, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloat2, in, info );
	NifStream( unknownFloat3, in, info );
	NifStream( unknownFloat4, in, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( unknownFloat5, in, info );
	NifStream( unknownFloat6, in, info );
	NifStream( unknownFloat7, in, info );
	NifStream( unknownFloat8, in, info );
	NifStream( unknownFloat9, in, info );
	NifStream( unknownFloat10, in, info );
}

void NiParticleBomb::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AParticleModifier::Write( out, link_map, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloat2, out, info );
	NifStream( unknownFloat3, out, info );
	NifStream( unknownFloat4, out, info );
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	NifStream( unknownFloat5, out, info );
	NifStream( unknownFloat6, out, info );
	NifStream( unknownFloat7, out, info );
	NifStream( unknownFloat8, out, info );
	NifStream( unknownFloat9, out, info );
	NifStream( unknownFloat10, out, info );
}

std::string NiParticleBomb::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Float 5:  " << unknownFloat5 << endl;
	out << "  Unknown Float 6:  " << unknownFloat6 << endl;
	out << "  Unknown Float 7:  " << unknownFloat7 << endl;
	out << "  Unknown Float 8:  " << unknownFloat8 << endl;
	out << "  Unknown Float 9:  " << unknownFloat9 << endl;
	out << "  Unknown Float 10:  " << unknownFloat10 << endl;
	return out.str();
}

void NiParticleBomb::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiParticleBomb::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiParticleColorModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	AParticleModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiParticleColorModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AParticleModifier::Write( out, link_map, info );
	if ( colorData != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(colorData) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiParticleColorModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Color Data:  " << colorData << endl;
	return out.str();
}

void NiParticleColorModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::FixLinks( objects, link_stack, info );
	colorData = FixLink<NiColorData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiParticleColorModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	if ( colorData != NULL )
		refs.push_back(StaticCast<NiObject>(colorData));
	return refs;
}

void NiParticleGrowFade::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::Read( in, link_stack, info );
	NifStream( grow, in, info );
	NifStream( fade, in, info );
}

void NiParticleGrowFade::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AParticleModifier::Write( out, link_map, info );
	NifStream( grow, out, info );
	NifStream( fade, out, info );
}

std::string NiParticleGrowFade::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Grow:  " << grow << endl;
	out << "  Fade:  " << fade << endl;
	return out.str();
}

void NiParticleGrowFade::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiParticleGrowFade::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiParticleMeshModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	AParticleModifier::Read( in, link_stack, info );
	NifStream( numParticleMeshes, in, info );
	particleMeshes.resize(numParticleMeshes);
	for (unsigned int i1 = 0; i1 < particleMeshes.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiParticleMeshModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AParticleModifier::Write( out, link_map, info );
	numParticleMeshes = (unsigned int)(particleMeshes.size());
	NifStream( numParticleMeshes, out, info );
	for (unsigned int i1 = 0; i1 < particleMeshes.size(); i1++) {
		if ( particleMeshes[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(particleMeshes[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiParticleMeshModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AParticleModifier::asString();
	numParticleMeshes = (unsigned int)(particleMeshes.size());
	out << "  Num Particle Meshes:  " << numParticleMeshes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < particleMeshes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Particle Meshes[" << i1 << "]:  " << particleMeshes[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiParticleMeshModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < particleMeshes.size(); i1++) {
		particleMeshes[i1] = FixLink<NiAVObject>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiParticleMeshModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	for (unsigned int i1 = 0; i1 < particleMeshes.size(); i1++) {
		if ( particleMeshes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(particleMeshes[i1]));
	};
	return refs;
}

void NiParticleRotation::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::Read( in, link_stack, info );
	NifStream( unknownByte, in, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloat2, in, info );
	NifStream( unknownFloat3, in, info );
	NifStream( unknownFloat4, in, info );
}

void NiParticleRotation::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AParticleModifier::Write( out, link_map, info );
	NifStream( unknownByte, out, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloat2, out, info );
	NifStream( unknownFloat3, out, info );
	NifStream( unknownFloat4, out, info );
}

std::string NiParticleRotation::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	return out.str();
}

void NiParticleRotation::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiParticleRotation::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiParticles::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometry::Read( in, link_stack, info );
}

void NiParticles::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiGeometry::Write( out, link_map, info );
}

std::string NiParticles::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiGeometry::asString();
	return out.str();
}

void NiParticles::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiGeometry::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiParticles::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometry::GetRefs();
	return refs;
}

void NiAutoNormalParticles::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticles::Read( in, link_stack, info );
}

void NiAutoNormalParticles::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiParticles::Write( out, link_map, info );
}

std::string NiAutoNormalParticles::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticles::asString();
	return out.str();
}

void NiAutoNormalParticles::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticles::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiAutoNormalParticles::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	return refs;
}

void NiParticleMeshes::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticles::Read( in, link_stack, info );
}

void NiParticleMeshes::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiParticles::Write( out, link_map, info );
}

std::string NiParticleMeshes::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticles::asString();
	return out.str();
}

void NiParticleMeshes::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticles::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiParticleMeshes::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	return refs;
}

void NiParticlesData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiAutoNormalParticlesData::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( numActive, in, info );
		NifStream( hasUnknownFloats, in, info );
		if ( (hasUnknownFloats != 0) ) {
			unknownFloats.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownFloats.size(); i3++) {
				NifStream( unknownFloats[i3], in, info );
			};
		};
	};
	NifStream( hasRotations, in, info );
	if ( (hasRotations != 0) ) {
		rotations.resize(numVertices);
		for (unsigned int i2 = 0; i2 < rotations.size(); i2++) {
			NifStream( rotations[i2], in, info );
		};
	};
}

void NiParticlesData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiAutoNormalParticlesData::Write( out, link_map, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( numActive, out, info );
		NifStream( hasUnknownFloats, out, info );
		if ( (hasUnknownFloats != 0) ) {
			for (unsigned int i3 = 0; i3 < unknownFloats.size(); i3++) {
				NifStream( unknownFloats[i3], out, info );
			};
		};
	};
	NifStream( hasRotations, out, info );
	if ( (hasRotations != 0) ) {
		for (unsigned int i2 = 0; i2 < rotations.size(); i2++) {
			NifStream( rotations[i2], out, info );
		};
	};
}

std::string NiParticlesData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiAutoNormalParticlesData::asString();
	out << "  Num Active:  " << numActive << endl;
	out << "  Has Unknown Floats:  " << hasUnknownFloats << endl;
	if ( (hasUnknownFloats != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownFloats.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats[" << i2 << "]:  " << unknownFloats[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Has Rotations:  " << hasRotations << endl;
	if ( (hasRotations != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotations.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotations[" << i2 << "]:  " << rotations[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiParticlesData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiAutoNormalParticlesData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiParticlesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAutoNormalParticlesData::GetRefs();
	return refs;
}

void NiParticleMeshesData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiParticlesData::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiParticleMeshesData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiParticlesData::Write( out, link_map, info );
	if ( unknownLink2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiParticleMeshesData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticlesData::asString();
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	return out.str();
}

void NiParticleMeshesData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticlesData::FixLinks( objects, link_stack, info );
	unknownLink2 = FixLink<NiAVObject>( objects, link_stack, info );
}

std::list<NiObjectRef> NiParticleMeshesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticlesData::GetRefs();
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	return refs;
}

void NiParticleSystem::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiParticles::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownBool, in, info );
		NifStream( numModifiers, in, info );
		modifiers.resize(numModifiers);
		for (unsigned int i2 = 0; i2 < modifiers.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
}

void NiParticleSystem::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiParticles::Write( out, link_map, info );
	numModifiers = (unsigned int)(modifiers.size());
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownBool, out, info );
		NifStream( numModifiers, out, info );
		for (unsigned int i2 = 0; i2 < modifiers.size(); i2++) {
			if ( modifiers[i2] != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(modifiers[i2]) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
}

std::string NiParticleSystem::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticles::asString();
	numModifiers = (unsigned int)(modifiers.size());
	out << "  Unknown Bool:  " << unknownBool << endl;
	out << "  Num Modifiers:  " << numModifiers << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < modifiers.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Modifiers[" << i1 << "]:  " << modifiers[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiParticleSystem::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticles::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		for (unsigned int i2 = 0; i2 < modifiers.size(); i2++) {
			modifiers[i2] = FixLink<NiPSysModifier>( objects, link_stack, info );
		};
	};
}

std::list<NiObjectRef> NiParticleSystem::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	for (unsigned int i1 = 0; i1 < modifiers.size(); i1++) {
		if ( modifiers[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(modifiers[i1]));
	};
	return refs;
}

void NiMeshParticleSystem::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticleSystem::Read( in, link_stack, info );
}

void NiMeshParticleSystem::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiParticleSystem::Write( out, link_map, info );
}

std::string NiMeshParticleSystem::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticleSystem::asString();
	return out.str();
}

void NiMeshParticleSystem::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticleSystem::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiMeshParticleSystem::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticleSystem::GetRefs();
	return refs;
}

void NiParticleSystemController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( speed, in, info );
	NifStream( speedRandom, in, info );
	NifStream( verticalDirection, in, info );
	NifStream( verticalAngle, in, info );
	NifStream( horizontalDirection, in, info );
	NifStream( horizontalAngle, in, info );
	NifStream( unknownFloat5, in, info );
	NifStream( unknownFloat6, in, info );
	NifStream( unknownFloat7, in, info );
	NifStream( unknownFloat8, in, info );
	NifStream( unknownFloat9, in, info );
	NifStream( unknownFloat10, in, info );
	NifStream( unknownFloat11, in, info );
	NifStream( size, in, info );
	NifStream( emitStartTime, in, info );
	NifStream( emitStopTime, in, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownByte, in, info );
	};
	NifStream( emitRate, in, info );
	NifStream( lifetime, in, info );
	NifStream( lifetimeRandom, in, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( emitFlags, in, info );
	};
	NifStream( startRandom, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownShort2_, in, info );
		NifStream( unknownFloat13_, in, info );
		NifStream( unknownInt1_, in, info );
		NifStream( unknownInt2_, in, info );
		NifStream( unknownShort3_, in, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( particle.velocity, in, info );
		NifStream( particle.unknownVector, in, info );
		NifStream( particle.lifetime, in, info );
		NifStream( particle.lifespan, in, info );
		NifStream( particle.timestamp, in, info );
		NifStream( particle.unknownShort, in, info );
		NifStream( particle.vertexId, in, info );
	};
	if ( info.version >= 0x04000002 ) {
		NifStream( numParticles, in, info );
		NifStream( numValid, in, info );
		particles.resize(numParticles);
		for (unsigned int i2 = 0; i2 < particles.size(); i2++) {
			NifStream( particles[i2].velocity, in, info );
			NifStream( particles[i2].unknownVector, in, info );
			NifStream( particles[i2].lifetime, in, info );
			NifStream( particles[i2].lifespan, in, info );
			NifStream( particles[i2].timestamp, in, info );
			NifStream( particles[i2].unknownShort, in, info );
			NifStream( particles[i2].vertexId, in, info );
		};
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x04000002 ) {
		NifStream( trailer, in, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( unkownFloats[i2], in, info );
		};
	};
}

void NiParticleSystemController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	numParticles = (unsigned short)(particles.size());
	NifStream( speed, out, info );
	NifStream( speedRandom, out, info );
	NifStream( verticalDirection, out, info );
	NifStream( verticalAngle, out, info );
	NifStream( horizontalDirection, out, info );
	NifStream( horizontalAngle, out, info );
	NifStream( unknownFloat5, out, info );
	NifStream( unknownFloat6, out, info );
	NifStream( unknownFloat7, out, info );
	NifStream( unknownFloat8, out, info );
	NifStream( unknownFloat9, out, info );
	NifStream( unknownFloat10, out, info );
	NifStream( unknownFloat11, out, info );
	NifStream( size, out, info );
	NifStream( emitStartTime, out, info );
	NifStream( emitStopTime, out, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownByte, out, info );
	};
	NifStream( emitRate, out, info );
	NifStream( lifetime, out, info );
	NifStream( lifetimeRandom, out, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( emitFlags, out, info );
	};
	NifStream( startRandom, out, info );
	if ( emitter != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(emitter) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( unknownShort2_, out, info );
		NifStream( unknownFloat13_, out, info );
		NifStream( unknownInt1_, out, info );
		NifStream( unknownInt2_, out, info );
		NifStream( unknownShort3_, out, info );
	};
	if ( info.version <= 0x03010000 ) {
		NifStream( particle.velocity, out, info );
		NifStream( particle.unknownVector, out, info );
		NifStream( particle.lifetime, out, info );
		NifStream( particle.lifespan, out, info );
		NifStream( particle.timestamp, out, info );
		NifStream( particle.unknownShort, out, info );
		NifStream( particle.vertexId, out, info );
	};
	if ( info.version >= 0x04000002 ) {
		NifStream( numParticles, out, info );
		NifStream( numValid, out, info );
		for (unsigned int i2 = 0; i2 < particles.size(); i2++) {
			NifStream( particles[i2].velocity, out, info );
			NifStream( particles[i2].unknownVector, out, info );
			NifStream( particles[i2].lifetime, out, info );
			NifStream( particles[i2].lifespan, out, info );
			NifStream( particles[i2].timestamp, out, info );
			NifStream( particles[i2].unknownShort, out, info );
			NifStream( particles[i2].vertexId, out, info );
		};
		if ( unknownLink != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( particleExtra != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(particleExtra) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink2 != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink2) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x04000002 ) {
		NifStream( trailer, out, info );
	};
	if ( info.version <= 0x03010000 ) {
		if ( colorData != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(colorData) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		for (unsigned int i2 = 0; i2 < 2; i2++) {
			NifStream( unkownFloats[i2], out, info );
		};
	};
}

std::string NiParticleSystemController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	numParticles = (unsigned short)(particles.size());
	out << "  Speed:  " << speed << endl;
	out << "  Speed Random:  " << speedRandom << endl;
	out << "  Vertical Direction:  " << verticalDirection << endl;
	out << "  Vertical Angle:  " << verticalAngle << endl;
	out << "  Horizontal Direction:  " << horizontalDirection << endl;
	out << "  Horizontal Angle:  " << horizontalAngle << endl;
	out << "  Unknown Float 5:  " << unknownFloat5 << endl;
	out << "  Unknown Float 6:  " << unknownFloat6 << endl;
	out << "  Unknown Float 7:  " << unknownFloat7 << endl;
	out << "  Unknown Float 8:  " << unknownFloat8 << endl;
	out << "  Unknown Float 9:  " << unknownFloat9 << endl;
	out << "  Unknown Float 10:  " << unknownFloat10 << endl;
	out << "  Unknown Float 11:  " << unknownFloat11 << endl;
	out << "  Size:  " << size << endl;
	out << "  Emit Start Time:  " << emitStartTime << endl;
	out << "  Emit Stop Time:  " << emitStopTime << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Emit Rate:  " << emitRate << endl;
	out << "  Lifetime:  " << lifetime << endl;
	out << "  Lifetime Random:  " << lifetimeRandom << endl;
	out << "  Emit Flags:  " << emitFlags << endl;
	out << "  Start Random:  " << startRandom << endl;
	out << "  Emitter:  " << emitter << endl;
	out << "  Unknown Short 2?:  " << unknownShort2_ << endl;
	out << "  Unknown Float 13?:  " << unknownFloat13_ << endl;
	out << "  Unknown Int 1?:  " << unknownInt1_ << endl;
	out << "  Unknown Int 2?:  " << unknownInt2_ << endl;
	out << "  Unknown Short 3?:  " << unknownShort3_ << endl;
	out << "  Velocity:  " << particle.velocity << endl;
	out << "  Unknown Vector:  " << particle.unknownVector << endl;
	out << "  Lifetime:  " << particle.lifetime << endl;
	out << "  Lifespan:  " << particle.lifespan << endl;
	out << "  Timestamp:  " << particle.timestamp << endl;
	out << "  Unknown Short:  " << particle.unknownShort << endl;
	out << "  Vertex ID:  " << particle.vertexId << endl;
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Num Valid:  " << numValid << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < particles.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Velocity:  " << particles[i1].velocity << endl;
		out << "    Unknown Vector:  " << particles[i1].unknownVector << endl;
		out << "    Lifetime:  " << particles[i1].lifetime << endl;
		out << "    Lifespan:  " << particles[i1].lifespan << endl;
		out << "    Timestamp:  " << particles[i1].timestamp << endl;
		out << "    Unknown Short:  " << particles[i1].unknownShort << endl;
		out << "    Vertex ID:  " << particles[i1].vertexId << endl;
	};
	out << "  Unknown Link:  " << unknownLink << endl;
	out << "  Particle Extra:  " << particleExtra << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	out << "  Trailer:  " << trailer << endl;
	out << "  Color Data:  " << colorData << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unkown Floats[" << i1 << "]:  " << unkownFloats[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiParticleSystemController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	emitter = FixLink<NiObject>( objects, link_stack, info );
	if ( info.version >= 0x04000002 ) {
		unknownLink = FixLink<NiObject>( objects, link_stack, info );
	};
	particleExtra = FixLink<AParticleModifier>( objects, link_stack, info );
	unknownLink2 = FixLink<NiObject>( objects, link_stack, info );
	if ( info.version <= 0x03010000 ) {
		colorData = FixLink<NiColorData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiParticleSystemController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	if ( particleExtra != NULL )
		refs.push_back(StaticCast<NiObject>(particleExtra));
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	if ( colorData != NULL )
		refs.push_back(StaticCast<NiObject>(colorData));
	return refs;
}

void NiBSPArrayController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticleSystemController::Read( in, link_stack, info );
}

void NiBSPArrayController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiParticleSystemController::Write( out, link_map, info );
}

std::string NiBSPArrayController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticleSystemController::asString();
	return out.str();
}

void NiBSPArrayController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticleSystemController::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiBSPArrayController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticleSystemController::GetRefs();
	return refs;
}

void NiPathController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort2, in, info );
	};
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( unknownInt3, in, info );
	NifStream( unknownShort, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiPathController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( unknownShort2, out, info );
	};
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownShort, out, info );
	if ( posData != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(posData) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( floatData != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(floatData) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiPathController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Pos Data:  " << posData << endl;
	out << "  Float Data:  " << floatData << endl;
	return out.str();
}

void NiPathController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	posData = FixLink<NiPosData>( objects, link_stack, info );
	floatData = FixLink<NiFloatData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPathController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( posData != NULL )
		refs.push_back(StaticCast<NiObject>(posData));
	if ( floatData != NULL )
		refs.push_back(StaticCast<NiObject>(floatData));
	return refs;
}

void NiPathInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiBlendInterpolator::Read( in, link_stack, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloat2, in, info );
	NifStream( unknownShort2, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiPathInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiBlendInterpolator::Write( out, link_map, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloat2, out, info );
	NifStream( unknownShort2, out, info );
	if ( posData != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(posData) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( floatData != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(floatData) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiPathInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Pos Data:  " << posData << endl;
	out << "  Float Data:  " << floatData << endl;
	return out.str();
}

void NiPathInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, info );
	posData = FixLink<NiPosData>( objects, link_stack, info );
	floatData = FixLink<NiFloatData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPathInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	if ( posData != NULL )
		refs.push_back(StaticCast<NiObject>(posData));
	if ( floatData != NULL )
		refs.push_back(StaticCast<NiObject>(floatData));
	return refs;
}

void NiPixelData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( pixelFormat, in, info );
	if ( info.version <= 0x0A020000 ) {
		NifStream( redMask, in, info );
		NifStream( greenMask, in, info );
		NifStream( blueMask, in, info );
		NifStream( alphaMask, in, info );
		NifStream( bitsPerPixel, in, info );
		for (unsigned int i2 = 0; i2 < 8; i2++) {
			NifStream( unknown8Bytes[i2], in, info );
		};
	};
	if ( ( info.version >= 0x0A010000 ) && ( info.version <= 0x0A020000 ) ) {
		NifStream( unknownInt, in, info );
	};
	if ( info.version >= 0x14000004 ) {
		for (unsigned int i2 = 0; i2 < 54; i2++) {
			NifStream( unknown54Bytes[i2], in, info );
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( numMipmaps, in, info );
	NifStream( bytesPerPixel, in, info );
	mipmaps.resize(numMipmaps);
	for (unsigned int i1 = 0; i1 < mipmaps.size(); i1++) {
		NifStream( mipmaps[i1].width, in, info );
		NifStream( mipmaps[i1].height, in, info );
		NifStream( mipmaps[i1].offset, in, info );
	};
	NifStream( pixelData.dataSize, in, info );
	pixelData.data.resize(pixelData.dataSize);
	for (unsigned int i1 = 0; i1 < pixelData.data.size(); i1++) {
		NifStream( pixelData.data[i1], in, info );
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( unknownInt2, in, info );
	};
}

void NiPixelData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numMipmaps = (unsigned int)(mipmaps.size());
	NifStream( pixelFormat, out, info );
	if ( info.version <= 0x0A020000 ) {
		NifStream( redMask, out, info );
		NifStream( greenMask, out, info );
		NifStream( blueMask, out, info );
		NifStream( alphaMask, out, info );
		NifStream( bitsPerPixel, out, info );
		for (unsigned int i2 = 0; i2 < 8; i2++) {
			NifStream( unknown8Bytes[i2], out, info );
		};
	};
	if ( ( info.version >= 0x0A010000 ) && ( info.version <= 0x0A020000 ) ) {
		NifStream( unknownInt, out, info );
	};
	if ( info.version >= 0x14000004 ) {
		for (unsigned int i2 = 0; i2 < 54; i2++) {
			NifStream( unknown54Bytes[i2], out, info );
		};
	};
	if ( palette != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(palette) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( numMipmaps, out, info );
	NifStream( bytesPerPixel, out, info );
	for (unsigned int i1 = 0; i1 < mipmaps.size(); i1++) {
		NifStream( mipmaps[i1].width, out, info );
		NifStream( mipmaps[i1].height, out, info );
		NifStream( mipmaps[i1].offset, out, info );
	};
	pixelData.dataSize = (unsigned int)(pixelData.data.size());
	NifStream( pixelData.dataSize, out, info );
	for (unsigned int i1 = 0; i1 < pixelData.data.size(); i1++) {
		NifStream( pixelData.data[i1], out, info );
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( unknownInt2, out, info );
	};
}

std::string NiPixelData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numMipmaps = (unsigned int)(mipmaps.size());
	out << "  Pixel Format:  " << pixelFormat << endl;
	out << "  Red Mask:  " << redMask << endl;
	out << "  Green Mask:  " << greenMask << endl;
	out << "  Blue Mask:  " << blueMask << endl;
	out << "  Alpha Mask:  " << alphaMask << endl;
	out << "  Bits Per Pixel:  " << bitsPerPixel << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 8 Bytes[" << i1 << "]:  " << unknown8Bytes[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Int:  " << unknownInt << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 54; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 54 Bytes[" << i1 << "]:  " << unknown54Bytes[i1] << endl;
		array_output_count++;
	};
	out << "  Palette:  " << palette << endl;
	out << "  Num Mipmaps:  " << numMipmaps << endl;
	out << "  Bytes Per Pixel:  " << bytesPerPixel << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < mipmaps.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Width:  " << mipmaps[i1].width << endl;
		out << "    Height:  " << mipmaps[i1].height << endl;
		out << "    Offset:  " << mipmaps[i1].offset << endl;
	};
	pixelData.dataSize = (unsigned int)(pixelData.data.size());
	out << "  Data Size:  " << pixelData.dataSize << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < pixelData.data.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Data[" << i1 << "]:  " << pixelData.data[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	return out.str();
}

void NiPixelData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	palette = FixLink<NiPalette>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPixelData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( palette != NULL )
		refs.push_back(StaticCast<NiObject>(palette));
	return refs;
}

void NiPlanarCollider::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::Read( in, link_stack, info );
	if ( info.version >= 0x0A000100 ) {
		NifStream( unknownShort, in, info );
	};
	NifStream( unknownFloat1, in, info );
	NifStream( unknownFloat2, in, info );
	if ( ( info.version >= 0x04020200 ) && ( info.version <= 0x04020200 ) ) {
		NifStream( unknownShort2, in, info );
	};
	NifStream( unknownFloat3, in, info );
	NifStream( unknownFloat4, in, info );
	NifStream( unknownFloat5, in, info );
	NifStream( unknownFloat6, in, info );
	NifStream( unknownFloat7, in, info );
	NifStream( unknownFloat8, in, info );
	NifStream( unknownFloat9, in, info );
	NifStream( unknownFloat10, in, info );
	NifStream( unknownFloat11, in, info );
	NifStream( unknownFloat12, in, info );
	NifStream( unknownFloat13, in, info );
	NifStream( unknownFloat14, in, info );
	NifStream( unknownFloat15, in, info );
	NifStream( unknownFloat16, in, info );
}

void NiPlanarCollider::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AParticleModifier::Write( out, link_map, info );
	if ( info.version >= 0x0A000100 ) {
		NifStream( unknownShort, out, info );
	};
	NifStream( unknownFloat1, out, info );
	NifStream( unknownFloat2, out, info );
	if ( ( info.version >= 0x04020200 ) && ( info.version <= 0x04020200 ) ) {
		NifStream( unknownShort2, out, info );
	};
	NifStream( unknownFloat3, out, info );
	NifStream( unknownFloat4, out, info );
	NifStream( unknownFloat5, out, info );
	NifStream( unknownFloat6, out, info );
	NifStream( unknownFloat7, out, info );
	NifStream( unknownFloat8, out, info );
	NifStream( unknownFloat9, out, info );
	NifStream( unknownFloat10, out, info );
	NifStream( unknownFloat11, out, info );
	NifStream( unknownFloat12, out, info );
	NifStream( unknownFloat13, out, info );
	NifStream( unknownFloat14, out, info );
	NifStream( unknownFloat15, out, info );
	NifStream( unknownFloat16, out, info );
}

std::string NiPlanarCollider::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	out << "  Unknown Float 5:  " << unknownFloat5 << endl;
	out << "  Unknown Float 6:  " << unknownFloat6 << endl;
	out << "  Unknown Float 7:  " << unknownFloat7 << endl;
	out << "  Unknown Float 8:  " << unknownFloat8 << endl;
	out << "  Unknown Float 9:  " << unknownFloat9 << endl;
	out << "  Unknown Float 10:  " << unknownFloat10 << endl;
	out << "  Unknown Float 11:  " << unknownFloat11 << endl;
	out << "  Unknown Float 12:  " << unknownFloat12 << endl;
	out << "  Unknown Float 13:  " << unknownFloat13 << endl;
	out << "  Unknown Float 14:  " << unknownFloat14 << endl;
	out << "  Unknown Float 15:  " << unknownFloat15 << endl;
	out << "  Unknown Float 16:  " << unknownFloat16 << endl;
	return out.str();
}

void NiPlanarCollider::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPlanarCollider::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiPoint3Interpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( point3Value, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiPoint3Interpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiInterpolator::Write( out, link_map, info );
	NifStream( point3Value, out, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiPoint3Interpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Point 3 Value:  " << point3Value << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiPoint3Interpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::FixLinks( objects, link_stack, info );
	data = FixLink<NiPosData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPoint3Interpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiPointLight::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLight::Read( in, link_stack, info );
	NifStream( constantAttenuation, in, info );
	NifStream( linearAttenuation, in, info );
	NifStream( quadraticAttenuation, in, info );
}

void NiPointLight::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiLight::Write( out, link_map, info );
	NifStream( constantAttenuation, out, info );
	NifStream( linearAttenuation, out, info );
	NifStream( quadraticAttenuation, out, info );
}

std::string NiPointLight::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiLight::asString();
	out << "  Constant Attenuation:  " << constantAttenuation << endl;
	out << "  Linear Attenuation:  " << linearAttenuation << endl;
	out << "  Quadratic Attenuation:  " << quadraticAttenuation << endl;
	return out.str();
}

void NiPointLight::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLight::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPointLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLight::GetRefs();
	return refs;
}

void NiPosData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::Read( in, link_stack, info );
	NifStream( data.numKeys, in, info );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, in, info );
	};
	data.keys.resize(data.numKeys);
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], in, info, data.interpolation );
	};
}

void NiPosData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AKeyedData::Write( out, link_map, info );
	data.numKeys = (unsigned int)(data.keys.size());
	NifStream( data.numKeys, out, info );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, out, info );
	};
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], out, info, data.interpolation );
	};
}

std::string NiPosData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AKeyedData::asString();
	data.numKeys = (unsigned int)(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < data.keys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Keys[" << i1 << "]:  " << data.keys[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiPosData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPosData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiPSysAgeDeathModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( spawnOnDeath, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiPSysAgeDeathModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	NifStream( spawnOnDeath, out, info );
	if ( spawnModifier != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(spawnModifier) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiPSysAgeDeathModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Spawn on Death:  " << spawnOnDeath << endl;
	out << "  Spawn Modifier:  " << spawnModifier << endl;
	return out.str();
}

void NiPSysAgeDeathModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
	spawnModifier = FixLink<NiPSysSpawnModifier>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysAgeDeathModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	if ( spawnModifier != NULL )
		refs.push_back(StaticCast<NiObject>(spawnModifier));
	return refs;
}

void NiPSysBombModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts1[i1], in, info );
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats[i1], in, info );
	};
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts2[i1], in, info );
	};
}

void NiPSysBombModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	if ( unknownLink != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts1[i1], out, info );
	};
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats[i1], out, info );
	};
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts2[i1], out, info );
	};
}

std::string NiPSysBombModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints 1[" << i1 << "]:  " << unknownInts1[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Ints 2[" << i1 << "]:  " << unknownInts2[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiPSysBombModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
	unknownLink = FixLink<NiNode>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysBombModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysBoundUpdateModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( updateSkip, in, info );
}

void NiPSysBoundUpdateModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	NifStream( updateSkip, out, info );
}

std::string NiPSysBoundUpdateModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Update Skip:  " << updateSkip << endl;
	return out.str();
}

void NiPSysBoundUpdateModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysBoundUpdateModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysBoxEmitter::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysVolumeEmitter::Read( in, link_stack, info );
	NifStream( width, in, info );
	NifStream( height, in, info );
	NifStream( depth, in, info );
}

void NiPSysBoxEmitter::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysVolumeEmitter::Write( out, link_map, info );
	NifStream( width, out, info );
	NifStream( height, out, info );
	NifStream( depth, out, info );
}

std::string NiPSysBoxEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysVolumeEmitter::asString();
	out << "  Width:  " << width << endl;
	out << "  Height:  " << height << endl;
	out << "  Depth:  " << depth << endl;
	return out.str();
}

void NiPSysBoxEmitter::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysVolumeEmitter::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysBoxEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysVolumeEmitter::GetRefs();
	return refs;
}

void NiPSysColliderManager::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiPSysColliderManager::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	if ( collider != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(collider) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiPSysColliderManager::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Collider:  " << collider << endl;
	return out.str();
}

void NiPSysColliderManager::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
	collider = FixLink<NiPSysPlanarCollider>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysColliderManager::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	if ( collider != NULL )
		refs.push_back(StaticCast<NiObject>(collider));
	return refs;
}

void NiPSysColorModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiPSysColorModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiPSysColorModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiPSysColorModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
	data = FixLink<NiColorData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysColorModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiPSysCylinderEmitter::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysVolumeEmitter::Read( in, link_stack, info );
	NifStream( radius, in, info );
	NifStream( height, in, info );
}

void NiPSysCylinderEmitter::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysVolumeEmitter::Write( out, link_map, info );
	NifStream( radius, out, info );
	NifStream( height, out, info );
}

std::string NiPSysCylinderEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysVolumeEmitter::asString();
	out << "  Radius:  " << radius << endl;
	out << "  Height:  " << height << endl;
	return out.str();
}

void NiPSysCylinderEmitter::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysVolumeEmitter::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysCylinderEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysVolumeEmitter::GetRefs();
	return refs;
}

void NiPSysData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysData::Read( in, link_stack, info );
	if ( info.version <= 0x0A020000 ) {
		unknownFloats4.resize(numVertices);
		for (unsigned int i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats4[i2][i3], in, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( unknownBool1, in, info );
		if ( (unknownBool1 != 0) ) {
			unknownBytes.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownBytes.size(); i3++) {
				for (unsigned int i4 = 0; i4 < 32; i4++) {
					NifStream( unknownBytes[i3][i4], in, info );
				};
			};
		};
		if ( (unknownBool1 == 0) ) {
			unknownBytesAlt.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownBytesAlt.size(); i3++) {
				for (unsigned int i4 = 0; i4 < 28; i4++) {
					NifStream( unknownBytesAlt[i3][i4], in, info );
				};
			};
		};
		NifStream( unknownByte3, in, info );
		NifStream( unknownBool2, in, info );
		if ( (unknownBool2 != 0) ) {
			unknownBytes2.resize(numVertices);
			for (unsigned int i3 = 0; i3 < unknownBytes2.size(); i3++) {
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					NifStream( unknownBytes2[i3][i4], in, info );
				};
			};
		};
	};
	NifStream( unknownInt1, in, info );
}

void NiPSysData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysData::Write( out, link_map, info );
	if ( info.version <= 0x0A020000 ) {
		for (unsigned int i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (unsigned int i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats4[i2][i3], out, info );
			};
		};
	};
	if ( info.version >= 0x14000004 ) {
		NifStream( unknownBool1, out, info );
		if ( (unknownBool1 != 0) ) {
			for (unsigned int i3 = 0; i3 < unknownBytes.size(); i3++) {
				for (unsigned int i4 = 0; i4 < 32; i4++) {
					NifStream( unknownBytes[i3][i4], out, info );
				};
			};
		};
		if ( (unknownBool1 == 0) ) {
			for (unsigned int i3 = 0; i3 < unknownBytesAlt.size(); i3++) {
				for (unsigned int i4 = 0; i4 < 28; i4++) {
					NifStream( unknownBytesAlt[i3][i4], out, info );
				};
			};
		};
		NifStream( unknownByte3, out, info );
		NifStream( unknownBool2, out, info );
		if ( (unknownBool2 != 0) ) {
			for (unsigned int i3 = 0; i3 < unknownBytes2.size(); i3++) {
				for (unsigned int i4 = 0; i4 < 4; i4++) {
					NifStream( unknownBytes2[i3][i4], out, info );
				};
			};
		};
	};
	NifStream( unknownInt1, out, info );
}

std::string NiPSysData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysData::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownFloats4.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 10; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 4[" << i2 << "]:  " << unknownFloats4[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Bool 1:  " << unknownBool1 << endl;
	if ( (unknownBool1 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownBytes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < 32; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Unknown Bytes[" << i3 << "]:  " << unknownBytes[i2][i3] << endl;
				array_output_count++;
			};
		};
	};
	if ( (unknownBool1 == 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownBytesAlt.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < 28; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Unknown Bytes Alt[" << i3 << "]:  " << unknownBytesAlt[i2][i3] << endl;
				array_output_count++;
			};
		};
	};
	out << "  Unknown Byte 3:  " << unknownByte3 << endl;
	out << "  Unknown Bool 2:  " << unknownBool2 << endl;
	if ( (unknownBool2 != 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < unknownBytes2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < 4; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Unknown Bytes 2[" << i3 << "]:  " << unknownBytes2[i2][i3] << endl;
				array_output_count++;
			};
		};
	};
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	return out.str();
}

void NiPSysData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysData::GetRefs();
	return refs;
}

void NiPSysDragModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( dragAxis, in, info );
	NifStream( percentage, in, info );
	NifStream( range, in, info );
	NifStream( rangeFalloff, in, info );
}

void NiPSysDragModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	if ( parent != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(parent) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( dragAxis, out, info );
	NifStream( percentage, out, info );
	NifStream( range, out, info );
	NifStream( rangeFalloff, out, info );
}

std::string NiPSysDragModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Parent:  " << parent << endl;
	out << "  Drag Axis:  " << dragAxis << endl;
	out << "  Percentage:  " << percentage << endl;
	out << "  Range:  " << range << endl;
	out << "  Range Falloff:  " << rangeFalloff << endl;
	return out.str();
}

void NiPSysDragModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
	parent = FixLink<NiObject>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysDragModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysEmitterCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	APSysCtlr::Read( in, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiPSysEmitterCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysCtlr::Write( out, link_map, info );
	if ( info.version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( info.version >= 0x0A020000 ) {
		if ( visibilityInterpolator != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(visibilityInterpolator) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiPSysEmitterCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Data:  " << data << endl;
	out << "  Visibility Interpolator:  " << visibilityInterpolator << endl;
	return out.str();
}

void NiPSysEmitterCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		data = FixLink<NiPSysEmitterCtlrData>( objects, link_stack, info );
	};
	if ( info.version >= 0x0A020000 ) {
		visibilityInterpolator = FixLink<NiInterpolator>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiPSysEmitterCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( visibilityInterpolator != NULL )
		refs.push_back(StaticCast<NiObject>(visibilityInterpolator));
	return refs;
}

void NiPSysEmitterCtlrData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( floatKeys_.numKeys, in, info );
	if ( (floatKeys_.numKeys != 0) ) {
		NifStream( floatKeys_.interpolation, in, info );
	};
	floatKeys_.keys.resize(floatKeys_.numKeys);
	for (unsigned int i1 = 0; i1 < floatKeys_.keys.size(); i1++) {
		NifStream( floatKeys_.keys[i1], in, info, floatKeys_.interpolation );
	};
	NifStream( numVisibilityKeys_, in, info );
	visibilityKeys_.resize(numVisibilityKeys_);
	for (unsigned int i1 = 0; i1 < visibilityKeys_.size(); i1++) {
		NifStream( visibilityKeys_[i1], in, info, 1 );
	};
}

void NiPSysEmitterCtlrData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numVisibilityKeys_ = (unsigned int)(visibilityKeys_.size());
	floatKeys_.numKeys = (unsigned int)(floatKeys_.keys.size());
	NifStream( floatKeys_.numKeys, out, info );
	if ( (floatKeys_.numKeys != 0) ) {
		NifStream( floatKeys_.interpolation, out, info );
	};
	for (unsigned int i1 = 0; i1 < floatKeys_.keys.size(); i1++) {
		NifStream( floatKeys_.keys[i1], out, info, floatKeys_.interpolation );
	};
	NifStream( numVisibilityKeys_, out, info );
	for (unsigned int i1 = 0; i1 < visibilityKeys_.size(); i1++) {
		NifStream( visibilityKeys_[i1], out, info, 1 );
	};
}

std::string NiPSysEmitterCtlrData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numVisibilityKeys_ = (unsigned int)(visibilityKeys_.size());
	floatKeys_.numKeys = (unsigned int)(floatKeys_.keys.size());
	out << "  Num Keys:  " << floatKeys_.numKeys << endl;
	if ( (floatKeys_.numKeys != 0) ) {
		out << "    Interpolation:  " << floatKeys_.interpolation << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < floatKeys_.keys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Keys[" << i1 << "]:  " << floatKeys_.keys[i1] << endl;
		array_output_count++;
	};
	out << "  Num Visibility Keys?:  " << numVisibilityKeys_ << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < visibilityKeys_.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Visibility Keys?[" << i1 << "]:  " << visibilityKeys_[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiPSysEmitterCtlrData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysEmitterCtlrData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiPSysEmitterDeclinationCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::Read( in, link_stack, info );
}

void NiPSysEmitterDeclinationCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysCtlr::Write( out, link_map, info );
}

std::string NiPSysEmitterDeclinationCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterDeclinationCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysEmitterDeclinationCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysEmitterDeclinationVarCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::Read( in, link_stack, info );
}

void NiPSysEmitterDeclinationVarCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysCtlr::Write( out, link_map, info );
}

std::string NiPSysEmitterDeclinationVarCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterDeclinationVarCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysEmitterDeclinationVarCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysEmitterInitialRadiusCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::Read( in, link_stack, info );
}

void NiPSysEmitterInitialRadiusCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysCtlr::Write( out, link_map, info );
}

std::string NiPSysEmitterInitialRadiusCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterInitialRadiusCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysEmitterInitialRadiusCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysEmitterLifeSpanCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	APSysCtlr::Read( in, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiPSysEmitterLifeSpanCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysCtlr::Write( out, link_map, info );
	if ( info.version <= 0x0A010000 ) {
		if ( unknownLink != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiPSysEmitterLifeSpanCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiPSysEmitterLifeSpanCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		unknownLink = FixLink<NiFloatData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiPSysEmitterLifeSpanCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiPSysEmitterSpeedCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	APSysCtlr::Read( in, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiPSysEmitterSpeedCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysCtlr::Write( out, link_map, info );
	if ( info.version <= 0x0A010000 ) {
		if ( unknownLink != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiPSysEmitterSpeedCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiPSysEmitterSpeedCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		unknownLink = FixLink<NiFloatData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiPSysEmitterSpeedCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiPSysGravityModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( gravityAxis, in, info );
	NifStream( decay, in, info );
	NifStream( strength, in, info );
	NifStream( forceType, in, info );
	NifStream( turbulence, in, info );
	NifStream( turbulenceScale, in, info );
}

void NiPSysGravityModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	if ( gravityObject != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(gravityObject) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( gravityAxis, out, info );
	NifStream( decay, out, info );
	NifStream( strength, out, info );
	NifStream( forceType, out, info );
	NifStream( turbulence, out, info );
	NifStream( turbulenceScale, out, info );
}

std::string NiPSysGravityModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Gravity Object:  " << gravityObject << endl;
	out << "  Gravity Axis:  " << gravityAxis << endl;
	out << "  Decay:  " << decay << endl;
	out << "  Strength:  " << strength << endl;
	out << "  Force Type:  " << forceType << endl;
	out << "  Turbulence:  " << turbulence << endl;
	out << "  Turbulence Scale:  " << turbulenceScale << endl;
	return out.str();
}

void NiPSysGravityModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
	gravityObject = FixLink<NiNode>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysGravityModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysGravityStrengthCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	APSysCtlr::Read( in, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiPSysGravityStrengthCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysCtlr::Write( out, link_map, info );
	if ( info.version <= 0x0A010000 ) {
		if ( unknownLink != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiPSysGravityStrengthCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiPSysGravityStrengthCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		unknownLink = FixLink<NiFloatData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiPSysGravityStrengthCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiPSysGrowFadeModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( growTime, in, info );
	NifStream( growGeneration, in, info );
	NifStream( fadeTime, in, info );
	NifStream( fadeGeneration, in, info );
}

void NiPSysGrowFadeModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	NifStream( growTime, out, info );
	NifStream( growGeneration, out, info );
	NifStream( fadeTime, out, info );
	NifStream( fadeGeneration, out, info );
}

std::string NiPSysGrowFadeModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Grow Time:  " << growTime << endl;
	out << "  Grow Generation:  " << growGeneration << endl;
	out << "  Fade Time:  " << fadeTime << endl;
	out << "  Fade Generation:  " << fadeGeneration << endl;
	return out.str();
}

void NiPSysGrowFadeModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysGrowFadeModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysMeshEmitter::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysEmitter::Read( in, link_stack, info );
	NifStream( numEmitterMeshes, in, info );
	emitterMeshes.resize(numEmitterMeshes);
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( initialVelocityType, in, info );
	NifStream( emissionType, in, info );
	NifStream( emissionAxis, in, info );
}

void NiPSysMeshEmitter::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysEmitter::Write( out, link_map, info );
	numEmitterMeshes = (unsigned int)(emitterMeshes.size());
	NifStream( numEmitterMeshes, out, info );
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( emitterMeshes[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(emitterMeshes[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( initialVelocityType, out, info );
	NifStream( emissionType, out, info );
	NifStream( emissionAxis, out, info );
}

std::string NiPSysMeshEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysEmitter::asString();
	numEmitterMeshes = (unsigned int)(emitterMeshes.size());
	out << "  Num Emitter Meshes:  " << numEmitterMeshes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Emitter Meshes[" << i1 << "]:  " << emitterMeshes[i1] << endl;
		array_output_count++;
	};
	out << "  Initial Velocity Type:  " << initialVelocityType << endl;
	out << "  Emission Type:  " << emissionType << endl;
	out << "  Emission Axis:  " << emissionAxis << endl;
	return out.str();
}

void NiPSysMeshEmitter::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysEmitter::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		emitterMeshes[i1] = FixLink<NiTriBasedGeom>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiPSysMeshEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysEmitter::GetRefs();
	for (unsigned int i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( emitterMeshes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(emitterMeshes[i1]));
	};
	return refs;
}

void NiPSysMeshUpdateModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( numMeshes, in, info );
	meshes.resize(numMeshes);
	for (unsigned int i1 = 0; i1 < meshes.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiPSysMeshUpdateModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	numMeshes = (unsigned int)(meshes.size());
	NifStream( numMeshes, out, info );
	for (unsigned int i1 = 0; i1 < meshes.size(); i1++) {
		if ( meshes[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(meshes[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiPSysMeshUpdateModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	numMeshes = (unsigned int)(meshes.size());
	out << "  Num Meshes:  " << numMeshes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < meshes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Meshes[" << i1 << "]:  " << meshes[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiPSysMeshUpdateModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < meshes.size(); i1++) {
		meshes[i1] = FixLink<NiNode>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiPSysMeshUpdateModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	for (unsigned int i1 = 0; i1 < meshes.size(); i1++) {
		if ( meshes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(meshes[i1]));
	};
	return refs;
}

void NiPSysModifierActiveCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::Read( in, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( unknownInt, in, info );
	};
}

void NiPSysModifierActiveCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	APSysCtlr::Write( out, link_map, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( unknownInt, out, info );
	};
}

std::string NiPSysModifierActiveCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void NiPSysModifierActiveCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	APSysCtlr::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysModifierActiveCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysPlanarCollider::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( bounce, in, info );
	NifStream( spawnOnCollide, in, info );
	NifStream( dieOnCollide, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( width, in, info );
	NifStream( height, in, info );
	NifStream( xAxis, in, info );
	NifStream( yAxis, in, info );
}

void NiPSysPlanarCollider::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	NifStream( bounce, out, info );
	NifStream( spawnOnCollide, out, info );
	NifStream( dieOnCollide, out, info );
	if ( spawnModifier != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(spawnModifier) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( parent != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(parent) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( unknownLink_ != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(unknownLink_) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( colliderObject != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(colliderObject) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( width, out, info );
	NifStream( height, out, info );
	NifStream( xAxis, out, info );
	NifStream( yAxis, out, info );
}

std::string NiPSysPlanarCollider::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Bounce:  " << bounce << endl;
	out << "  Spawn on Collide:  " << spawnOnCollide << endl;
	out << "  Die on Collide:  " << dieOnCollide << endl;
	out << "  Spawn Modifier:  " << spawnModifier << endl;
	out << "  Parent:  " << parent << endl;
	out << "  Unknown Link?:  " << unknownLink_ << endl;
	out << "  Collider Object:  " << colliderObject << endl;
	out << "  Width:  " << width << endl;
	out << "  Height:  " << height << endl;
	out << "  X Axis:  " << xAxis << endl;
	out << "  Y Axis:  " << yAxis << endl;
	return out.str();
}

void NiPSysPlanarCollider::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	spawnModifier = FixLink<NiPSysSpawnModifier>( objects, link_stack, info );
	parent = FixLink<NiObject>( objects, link_stack, info );
	unknownLink_ = FixLink<NiObject>( objects, link_stack, info );
	colliderObject = FixLink<NiNode>( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysPlanarCollider::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( spawnModifier != NULL )
		refs.push_back(StaticCast<NiObject>(spawnModifier));
	if ( unknownLink_ != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink_));
	if ( colliderObject != NULL )
		refs.push_back(StaticCast<NiObject>(colliderObject));
	return refs;
}

void NiPSysPositionModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::Read( in, link_stack, info );
}

void NiPSysPositionModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
}

std::string NiPSysPositionModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	return out.str();
}

void NiPSysPositionModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysPositionModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysResetOnLoopCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::Read( in, link_stack, info );
}

void NiPSysResetOnLoopCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
}

std::string NiPSysResetOnLoopCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	return out.str();
}

void NiPSysResetOnLoopCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysResetOnLoopCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	return refs;
}

void NiPSysRotationModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( initialRotationSpeed, in, info );
	if ( info.version >= 0x14000004 ) {
		NifStream( initialRotationSpeedVariation, in, info );
		NifStream( initialRotationAngle, in, info );
		NifStream( initialRotationAngleVariation, in, info );
		NifStream( randomRotSpeedSign, in, info );
	};
	NifStream( randomInitialAxis, in, info );
	NifStream( initialAxis, in, info );
}

void NiPSysRotationModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	NifStream( initialRotationSpeed, out, info );
	if ( info.version >= 0x14000004 ) {
		NifStream( initialRotationSpeedVariation, out, info );
		NifStream( initialRotationAngle, out, info );
		NifStream( initialRotationAngleVariation, out, info );
		NifStream( randomRotSpeedSign, out, info );
	};
	NifStream( randomInitialAxis, out, info );
	NifStream( initialAxis, out, info );
}

std::string NiPSysRotationModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Initial Rotation Speed:  " << initialRotationSpeed << endl;
	out << "  Initial Rotation Speed Variation:  " << initialRotationSpeedVariation << endl;
	out << "  Initial Rotation Angle:  " << initialRotationAngle << endl;
	out << "  Initial Rotation Angle Variation:  " << initialRotationAngleVariation << endl;
	out << "  Random Rot Speed Sign:  " << randomRotSpeedSign << endl;
	out << "  Random Initial Axis:  " << randomInitialAxis << endl;
	out << "  Initial Axis:  " << initialAxis << endl;
	return out.str();
}

void NiPSysRotationModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysRotationModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysSpawnModifier::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( numSpawnGenerations, in, info );
	NifStream( percentageSpawned, in, info );
	NifStream( minNumToSpawn, in, info );
	NifStream( maxNumToSpawn, in, info );
	NifStream( spawnSpeedChaos, in, info );
	NifStream( spawnDirChaos, in, info );
	NifStream( lifeSpan, in, info );
	NifStream( lifeSpanVariation, in, info );
}

void NiPSysSpawnModifier::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysModifier::Write( out, link_map, info );
	NifStream( numSpawnGenerations, out, info );
	NifStream( percentageSpawned, out, info );
	NifStream( minNumToSpawn, out, info );
	NifStream( maxNumToSpawn, out, info );
	NifStream( spawnSpeedChaos, out, info );
	NifStream( spawnDirChaos, out, info );
	NifStream( lifeSpan, out, info );
	NifStream( lifeSpanVariation, out, info );
}

std::string NiPSysSpawnModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Num Spawn Generations:  " << numSpawnGenerations << endl;
	out << "  Percentage Spawned:  " << percentageSpawned << endl;
	out << "  Min Num to Spawn:  " << minNumToSpawn << endl;
	out << "  Max Num to Spawn:  " << maxNumToSpawn << endl;
	out << "  Spawn Speed Chaos:  " << spawnSpeedChaos << endl;
	out << "  Spawn Dir Chaos:  " << spawnDirChaos << endl;
	out << "  Life Span:  " << lifeSpan << endl;
	out << "  Life Span Variation:  " << lifeSpanVariation << endl;
	return out.str();
}

void NiPSysSpawnModifier::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysSpawnModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysSphereEmitter::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysVolumeEmitter::Read( in, link_stack, info );
	NifStream( radius, in, info );
}

void NiPSysSphereEmitter::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPSysVolumeEmitter::Write( out, link_map, info );
	NifStream( radius, out, info );
}

std::string NiPSysSphereEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPSysVolumeEmitter::asString();
	out << "  Radius:  " << radius << endl;
	return out.str();
}

void NiPSysSphereEmitter::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPSysVolumeEmitter::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysSphereEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysVolumeEmitter::GetRefs();
	return refs;
}

void NiPSysUpdateCtlr::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::Read( in, link_stack, info );
}

void NiPSysUpdateCtlr::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
}

std::string NiPSysUpdateCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	return out.str();
}

void NiPSysUpdateCtlr::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiPSysUpdateCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	return refs;
}

void NiLODData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
}

void NiLODData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
}

std::string NiLODData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	return out.str();
}

void NiLODData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiLODData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiRangeLODData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLODData::Read( in, link_stack, info );
	NifStream( lodCenter, in, info );
	NifStream( numLodLevels, in, info );
	lodLevels.resize(numLodLevels);
	for (unsigned int i1 = 0; i1 < lodLevels.size(); i1++) {
		NifStream( lodLevels[i1].nearExtent, in, info );
		NifStream( lodLevels[i1].farExtent, in, info );
		if ( info.version <= 0x03010000 ) {
			for (unsigned int i3 = 0; i3 < 3; i3++) {
				NifStream( lodLevels[i1].unknownInts[i3], in, info );
			};
		};
	};
}

void NiRangeLODData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiLODData::Write( out, link_map, info );
	numLodLevels = (unsigned int)(lodLevels.size());
	NifStream( lodCenter, out, info );
	NifStream( numLodLevels, out, info );
	for (unsigned int i1 = 0; i1 < lodLevels.size(); i1++) {
		NifStream( lodLevels[i1].nearExtent, out, info );
		NifStream( lodLevels[i1].farExtent, out, info );
		if ( info.version <= 0x03010000 ) {
			for (unsigned int i3 = 0; i3 < 3; i3++) {
				NifStream( lodLevels[i1].unknownInts[i3], out, info );
			};
		};
	};
}

std::string NiRangeLODData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiLODData::asString();
	numLodLevels = (unsigned int)(lodLevels.size());
	out << "  LOD Center:  " << lodCenter << endl;
	out << "  Num LOD Levels:  " << numLodLevels << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < lodLevels.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Near Extent:  " << lodLevels[i1].nearExtent << endl;
		out << "    Far Extent:  " << lodLevels[i1].farExtent << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Ints[" << i2 << "]:  " << lodLevels[i1].unknownInts[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiRangeLODData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLODData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiRangeLODData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLODData::GetRefs();
	return refs;
}

void NiScreenLODData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLODData::Read( in, link_stack, info );
	NifStream( boundCenter, in, info );
	NifStream( boundRadius, in, info );
	NifStream( worldCenter, in, info );
	NifStream( worldRadius, in, info );
	NifStream( proportionCount, in, info );
	proportionLevels.resize(proportionCount);
	for (unsigned int i1 = 0; i1 < proportionLevels.size(); i1++) {
		NifStream( proportionLevels[i1], in, info );
	};
}

void NiScreenLODData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiLODData::Write( out, link_map, info );
	proportionCount = (unsigned int)(proportionLevels.size());
	NifStream( boundCenter, out, info );
	NifStream( boundRadius, out, info );
	NifStream( worldCenter, out, info );
	NifStream( worldRadius, out, info );
	NifStream( proportionCount, out, info );
	for (unsigned int i1 = 0; i1 < proportionLevels.size(); i1++) {
		NifStream( proportionLevels[i1], out, info );
	};
}

std::string NiScreenLODData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiLODData::asString();
	proportionCount = (unsigned int)(proportionLevels.size());
	out << "  Bound Center:  " << boundCenter << endl;
	out << "  Bound Radius:  " << boundRadius << endl;
	out << "  World Center:  " << worldCenter << endl;
	out << "  World Radius:  " << worldRadius << endl;
	out << "  Proportion Count:  " << proportionCount << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < proportionLevels.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Proportion Levels[" << i1 << "]:  " << proportionLevels[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiScreenLODData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiLODData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiScreenLODData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLODData::GetRefs();
	return refs;
}

void NiRotatingParticles::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticles::Read( in, link_stack, info );
}

void NiRotatingParticles::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiParticles::Write( out, link_map, info );
}

std::string NiRotatingParticles::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticles::asString();
	return out.str();
}

void NiRotatingParticles::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticles::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiRotatingParticles::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	return refs;
}

void NiRotatingParticlesData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticlesData::Read( in, link_stack, info );
}

void NiRotatingParticlesData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiParticlesData::Write( out, link_map, info );
}

std::string NiRotatingParticlesData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticlesData::asString();
	return out.str();
}

void NiRotatingParticlesData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiParticlesData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiRotatingParticlesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticlesData::GetRefs();
	return refs;
}

void NiSequenceStreamHelper::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObjectNET::Read( in, link_stack, info );
}

void NiSequenceStreamHelper::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObjectNET::Write( out, link_map, info );
}

std::string NiSequenceStreamHelper::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObjectNET::asString();
	return out.str();
}

void NiSequenceStreamHelper::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObjectNET::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiSequenceStreamHelper::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	return refs;
}

void NiShadeProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
}

void NiShadeProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
}

std::string NiShadeProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiShadeProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiShadeProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiSkinData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( rotation, in, info );
	NifStream( translation, in, info );
	NifStream( scale, in, info );
	NifStream( numBones, in, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x04020100 ) {
		NifStream( unknownByte, in, info );
	};
	boneList.resize(numBones);
	for (unsigned int i1 = 0; i1 < boneList.size(); i1++) {
		NifStream( boneList[i1].rotation, in, info );
		NifStream( boneList[i1].translation, in, info );
		NifStream( boneList[i1].scale, in, info );
		NifStream( boneList[i1].boundingSphereOffset, in, info );
		NifStream( boneList[i1].boundingSphereRadius, in, info );
		NifStream( boneList[i1].numVertices, in, info );
		boneList[i1].vertexWeights.resize(boneList[i1].numVertices);
		for (unsigned int i2 = 0; i2 < boneList[i1].vertexWeights.size(); i2++) {
			NifStream( boneList[i1].vertexWeights[i2].index, in, info );
			NifStream( boneList[i1].vertexWeights[i2].weight, in, info );
		};
	};
}

void NiSkinData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numBones = (unsigned int)(boneList.size());
	NifStream( rotation, out, info );
	NifStream( translation, out, info );
	NifStream( scale, out, info );
	NifStream( numBones, out, info );
	if ( info.version <= 0x0A010000 ) {
		if ( skinPartition != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(skinPartition) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( info.version >= 0x04020100 ) {
		NifStream( unknownByte, out, info );
	};
	for (unsigned int i1 = 0; i1 < boneList.size(); i1++) {
		boneList[i1].numVertices = (unsigned short)(boneList[i1].vertexWeights.size());
		NifStream( boneList[i1].rotation, out, info );
		NifStream( boneList[i1].translation, out, info );
		NifStream( boneList[i1].scale, out, info );
		NifStream( boneList[i1].boundingSphereOffset, out, info );
		NifStream( boneList[i1].boundingSphereRadius, out, info );
		NifStream( boneList[i1].numVertices, out, info );
		for (unsigned int i2 = 0; i2 < boneList[i1].vertexWeights.size(); i2++) {
			NifStream( boneList[i1].vertexWeights[i2].index, out, info );
			NifStream( boneList[i1].vertexWeights[i2].weight, out, info );
		};
	};
}

std::string NiSkinData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numBones = (unsigned int)(boneList.size());
	out << "  Rotation:  " << rotation << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Num Bones:  " << numBones << endl;
	out << "  Skin Partition:  " << skinPartition << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < boneList.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		boneList[i1].numVertices = (unsigned short)(boneList[i1].vertexWeights.size());
		out << "    Rotation:  " << boneList[i1].rotation << endl;
		out << "    Translation:  " << boneList[i1].translation << endl;
		out << "    Scale:  " << boneList[i1].scale << endl;
		out << "    Bounding Sphere Offset:  " << boneList[i1].boundingSphereOffset << endl;
		out << "    Bounding Sphere Radius:  " << boneList[i1].boundingSphereRadius << endl;
		out << "    Num Vertices:  " << boneList[i1].numVertices << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < boneList[i1].vertexWeights.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Index:  " << boneList[i1].vertexWeights[i2].index << endl;
			out << "      Weight:  " << boneList[i1].vertexWeights[i2].weight << endl;
		};
	};
	return out.str();
}

void NiSkinData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		skinPartition = FixLink<NiSkinPartition>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiSkinData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( skinPartition != NULL )
		refs.push_back(StaticCast<NiObject>(skinPartition));
	return refs;
}

void NiSkinInstance::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( info.version >= 0x0A020000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( numBones, in, info );
	bones.resize(numBones);
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiSkinInstance::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numBones = (unsigned int)(bones.size());
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	if ( info.version >= 0x0A020000 ) {
		if ( skinPartition != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(skinPartition) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	if ( skeletonRoot != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(skeletonRoot) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( numBones, out, info );
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		if ( bones[i1] != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(bones[i1]) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiSkinInstance::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numBones = (unsigned int)(bones.size());
	out << "  Data:  " << data << endl;
	out << "  Skin Partition:  " << skinPartition << endl;
	out << "  Skeleton Root:  " << skeletonRoot << endl;
	out << "  Num Bones:  " << numBones << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Bones[" << i1 << "]:  " << bones[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiSkinInstance::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
	data = FixLink<NiSkinData>( objects, link_stack, info );
	if ( info.version >= 0x0A020000 ) {
		skinPartition = FixLink<NiSkinPartition>( objects, link_stack, info );
	};
	skeletonRoot = FixLink<NiNode>( objects, link_stack, info );
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
		bones[i1] = FixLink<NiNode>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiSkinInstance::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( skinPartition != NULL )
		refs.push_back(StaticCast<NiObject>(skinPartition));
	for (unsigned int i1 = 0; i1 < bones.size(); i1++) {
	};
	return refs;
}

void NiClodSkinInstance::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSkinInstance::Read( in, link_stack, info );
}

void NiClodSkinInstance::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSkinInstance::Write( out, link_map, info );
}

std::string NiClodSkinInstance::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSkinInstance::asString();
	return out.str();
}

void NiClodSkinInstance::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSkinInstance::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiClodSkinInstance::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSkinInstance::GetRefs();
	return refs;
}

void NiSkinPartition::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( numSkinPartitionBlocks, in, info );
	skinPartitionBlocks.resize(numSkinPartitionBlocks);
	for (unsigned int i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		NifStream( skinPartitionBlocks[i1].numVertices, in, info );
		NifStream( skinPartitionBlocks[i1].numTriangles, in, info );
		NifStream( skinPartitionBlocks[i1].numBones, in, info );
		NifStream( skinPartitionBlocks[i1].numStrips, in, info );
		NifStream( skinPartitionBlocks[i1].numWeightsPerVertex, in, info );
		skinPartitionBlocks[i1].bones.resize(skinPartitionBlocks[i1].numBones);
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].bones[i2], in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasVertexMap, in, info );
		};
		if ( info.version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].vertexMap.resize(skinPartitionBlocks[i1].numVertices);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexMap.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].vertexMap[i3], in, info );
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexMap != 0) ) {
				skinPartitionBlocks[i1].vertexMap.resize(skinPartitionBlocks[i1].numVertices);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexMap.size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexMap[i4], in, info );
				};
			};
			NifStream( skinPartitionBlocks[i1].hasVertexWeights, in, info );
		};
		if ( info.version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].vertexWeights.resize(skinPartitionBlocks[i1].numVertices);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights.size(); i3++) {
				skinPartitionBlocks[i1].vertexWeights[i3].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexWeights[i3][i4], in, info );
				};
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexWeights != 0) ) {
				skinPartitionBlocks[i1].vertexWeights.resize(skinPartitionBlocks[i1].numVertices);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights.size(); i4++) {
					skinPartitionBlocks[i1].vertexWeights[i4].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i1].vertexWeights[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i1].vertexWeights[i4][i5], in, info );
					};
				};
			};
		};
		skinPartitionBlocks[i1].stripLengths.resize(skinPartitionBlocks[i1].numStrips);
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].stripLengths[i2], in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasStrips, in, info );
		};
		if ( info.version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].strips.resize(skinPartitionBlocks[i1].numStrips);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].strips.size(); i3++) {
				skinPartitionBlocks[i1].strips[i3].resize(skinPartitionBlocks[i1].stripLengths[i3]);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].stripLengths[i3]; i4++) {
					NifStream( skinPartitionBlocks[i1].strips[i3][i4], in, info );
				};
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasStrips != 0) ) {
				skinPartitionBlocks[i1].strips.resize(skinPartitionBlocks[i1].numStrips);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].strips.size(); i4++) {
					skinPartitionBlocks[i1].strips[i4].resize(skinPartitionBlocks[i1].stripLengths[i4]);
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i1].stripLengths[i4]; i5++) {
						NifStream( skinPartitionBlocks[i1].strips[i4][i5], in, info );
					};
				};
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			skinPartitionBlocks[i1].triangles.resize(skinPartitionBlocks[i1].numTriangles);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].triangles[i3], in, info );
			};
		};
		NifStream( skinPartitionBlocks[i1].hasBoneIndices, in, info );
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			skinPartitionBlocks[i1].boneIndices.resize(skinPartitionBlocks[i1].numVertices);
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				skinPartitionBlocks[i1].boneIndices[i3].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].boneIndices[i3][i4], in, info );
				};
			};
		};
	};
}

void NiSkinPartition::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	numSkinPartitionBlocks = (unsigned int)(skinPartitionBlocks.size());
	NifStream( numSkinPartitionBlocks, out, info );
	for (unsigned int i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++)
			skinPartitionBlocks[i1].stripLengths[i2] = (unsigned short)(skinPartitionBlocks[i1].strips[i2].size());
		skinPartitionBlocks[i1].numWeightsPerVertex = (unsigned short)((skinPartitionBlocks[i1].vertexWeights.size() > 0) ? skinPartitionBlocks[i1].vertexWeights[0].size() : 0);
		skinPartitionBlocks[i1].numStrips = (unsigned short)(skinPartitionBlocks[i1].stripLengths.size());
		skinPartitionBlocks[i1].numBones = (unsigned short)(skinPartitionBlocks[i1].bones.size());
		skinPartitionBlocks[i1].numTriangles = (unsigned short)(skinPartitionBlocks[i1].triangles.size());
		skinPartitionBlocks[i1].numVertices = (unsigned short)(skinPartitionBlocks[i1].vertexMap.size());
		NifStream( skinPartitionBlocks[i1].numVertices, out, info );
		NifStream( skinPartitionBlocks[i1].numTriangles, out, info );
		NifStream( skinPartitionBlocks[i1].numBones, out, info );
		NifStream( skinPartitionBlocks[i1].numStrips, out, info );
		NifStream( skinPartitionBlocks[i1].numWeightsPerVertex, out, info );
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].bones[i2], out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasVertexMap, out, info );
		};
		if ( info.version <= 0x0A000102 ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexMap.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].vertexMap[i3], out, info );
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexMap != 0) ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexMap.size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexMap[i4], out, info );
				};
			};
			NifStream( skinPartitionBlocks[i1].hasVertexWeights, out, info );
		};
		if ( info.version <= 0x0A000102 ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights.size(); i3++) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexWeights[i3][i4], out, info );
				};
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexWeights != 0) ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights.size(); i4++) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i1].vertexWeights[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i1].vertexWeights[i4][i5], out, info );
					};
				};
			};
		};
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].stripLengths[i2], out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasStrips, out, info );
		};
		if ( info.version <= 0x0A000102 ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].strips.size(); i3++) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].stripLengths[i3]; i4++) {
					NifStream( skinPartitionBlocks[i1].strips[i3][i4], out, info );
				};
			};
		};
		if ( info.version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasStrips != 0) ) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].strips.size(); i4++) {
					for (unsigned int i5 = 0; i5 < skinPartitionBlocks[i1].stripLengths[i4]; i5++) {
						NifStream( skinPartitionBlocks[i1].strips[i4][i5], out, info );
					};
				};
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].triangles[i3], out, info );
			};
		};
		NifStream( skinPartitionBlocks[i1].hasBoneIndices, out, info );
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].boneIndices[i3][i4], out, info );
				};
			};
		};
	};
}

std::string NiSkinPartition::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numSkinPartitionBlocks = (unsigned int)(skinPartitionBlocks.size());
	out << "  Num Skin Partition Blocks:  " << numSkinPartitionBlocks << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++)
			skinPartitionBlocks[i1].stripLengths[i2] = (unsigned short)(skinPartitionBlocks[i1].strips[i2].size());
		skinPartitionBlocks[i1].numWeightsPerVertex = (unsigned short)((skinPartitionBlocks[i1].vertexWeights.size() > 0) ? skinPartitionBlocks[i1].vertexWeights[0].size() : 0);
		skinPartitionBlocks[i1].numStrips = (unsigned short)(skinPartitionBlocks[i1].stripLengths.size());
		skinPartitionBlocks[i1].numBones = (unsigned short)(skinPartitionBlocks[i1].bones.size());
		skinPartitionBlocks[i1].numTriangles = (unsigned short)(skinPartitionBlocks[i1].triangles.size());
		skinPartitionBlocks[i1].numVertices = (unsigned short)(skinPartitionBlocks[i1].vertexMap.size());
		out << "    Num Vertices:  " << skinPartitionBlocks[i1].numVertices << endl;
		out << "    Num Triangles:  " << skinPartitionBlocks[i1].numTriangles << endl;
		out << "    Num Bones:  " << skinPartitionBlocks[i1].numBones << endl;
		out << "    Num Strips:  " << skinPartitionBlocks[i1].numStrips << endl;
		out << "    Num Weights Per Vertex:  " << skinPartitionBlocks[i1].numWeightsPerVertex << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Bones[" << i2 << "]:  " << skinPartitionBlocks[i1].bones[i2] << endl;
			array_output_count++;
		};
		out << "    Has Vertex Map:  " << skinPartitionBlocks[i1].hasVertexMap << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].vertexMap.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Map[" << i2 << "]:  " << skinPartitionBlocks[i1].vertexMap[i2] << endl;
			array_output_count++;
		};
		out << "    Has Vertex Weights:  " << skinPartitionBlocks[i1].hasVertexWeights << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].vertexWeights.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights[i2].size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Vertex Weights[" << i3 << "]:  " << skinPartitionBlocks[i1].vertexWeights[i2][i3] << endl;
				array_output_count++;
			};
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Strip Lengths[" << i2 << "]:  " << skinPartitionBlocks[i1].stripLengths[i2] << endl;
			array_output_count++;
		};
		out << "    Has Strips:  " << skinPartitionBlocks[i1].hasStrips << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].stripLengths[i2]; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Strips[" << i3 << "]:  " << skinPartitionBlocks[i1].strips[i2][i3] << endl;
				array_output_count++;
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Triangles[" << i3 << "]:  " << skinPartitionBlocks[i1].triangles[i3] << endl;
				array_output_count++;
			};
		};
		out << "    Has Bone Indices:  " << skinPartitionBlocks[i1].hasBoneIndices << endl;
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				for (unsigned int i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
						break;
					};
					out << "          Bone Indices[" << i4 << "]:  " << skinPartitionBlocks[i1].boneIndices[i3][i4] << endl;
					array_output_count++;
				};
			};
		};
	};
	return out.str();
}

void NiSkinPartition::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiSkinPartition::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiSourceTexture::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiObjectNET::Read( in, link_stack, info );
	NifStream( useExternal, in, info );
	if ( (useExternal == 1) ) {
		NifStream( fileName, in, info );
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version <= 0x0A000100 ) {
		if ( (useExternal == 0) ) {
			NifStream( unknownByte, in, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 0) ) {
			NifStream( originalFileName_, in, info );
		};
	};
	if ( (useExternal == 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( pixelLayout, in, info );
	NifStream( useMipmaps, in, info );
	NifStream( alphaFormat, in, info );
	NifStream( unknownByte, in, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( unknownByte2, in, info );
	};
}

void NiSourceTexture::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObjectNET::Write( out, link_map, info );
	NifStream( useExternal, out, info );
	if ( (useExternal == 1) ) {
		NifStream( fileName, out, info );
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			if ( unknownLink != NULL )
				NifStream( link_map.find( StaticCast<NiObject>(unknownLink) )->second, out, info );
			else
				NifStream( 0xffffffff, out, info );
		};
	};
	if ( info.version <= 0x0A000100 ) {
		if ( (useExternal == 0) ) {
			NifStream( unknownByte, out, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 0) ) {
			NifStream( originalFileName_, out, info );
		};
	};
	if ( (useExternal == 0) ) {
		if ( pixelData != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(pixelData) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
	NifStream( pixelLayout, out, info );
	NifStream( useMipmaps, out, info );
	NifStream( alphaFormat, out, info );
	NifStream( unknownByte, out, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( unknownByte2, out, info );
	};
}

std::string NiSourceTexture::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObjectNET::asString();
	out << "  Use External:  " << useExternal << endl;
	if ( (useExternal == 1) ) {
		out << "    File Name:  " << fileName << endl;
		out << "    Unknown Link:  " << unknownLink << endl;
	};
	if ( (useExternal == 0) ) {
		out << "    Unknown Byte:  " << unknownByte << endl;
		out << "    Original File Name?:  " << originalFileName_ << endl;
		out << "    Pixel Data:  " << pixelData << endl;
	};
	out << "  Pixel Layout:  " << pixelLayout << endl;
	out << "  Use Mipmaps:  " << useMipmaps << endl;
	out << "  Alpha Format:  " << alphaFormat << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	return out.str();
}

void NiSourceTexture::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObjectNET::FixLinks( objects, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			unknownLink = FixLink<NiObject>( objects, link_stack, info );
		};
	};
	if ( (useExternal == 0) ) {
		pixelData = FixLink<NiPixelData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiSourceTexture::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	if ( pixelData != NULL )
		refs.push_back(StaticCast<NiObject>(pixelData));
	return refs;
}

void NiSpecularProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
}

void NiSpecularProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
}

std::string NiSpecularProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiSpecularProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiSpecularProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiSphericalCollider::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::Read( in, link_stack, info );
	NifStream( unknownFloat1, in, info );
	NifStream( unknownShort1, in, info );
	NifStream( unknownFloat2, in, info );
	if ( info.version <= 0x04020002 ) {
		NifStream( unknownShort2, in, info );
	};
	if ( info.version >= 0x04020100 ) {
		NifStream( unknownFloat3, in, info );
	};
	NifStream( unknownFloat4, in, info );
	NifStream( unknownFloat5, in, info );
}

void NiSphericalCollider::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AParticleModifier::Write( out, link_map, info );
	NifStream( unknownFloat1, out, info );
	NifStream( unknownShort1, out, info );
	NifStream( unknownFloat2, out, info );
	if ( info.version <= 0x04020002 ) {
		NifStream( unknownShort2, out, info );
	};
	if ( info.version >= 0x04020100 ) {
		NifStream( unknownFloat3, out, info );
	};
	NifStream( unknownFloat4, out, info );
	NifStream( unknownFloat5, out, info );
}

std::string NiSphericalCollider::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	out << "  Unknown Float 5:  " << unknownFloat5 << endl;
	return out.str();
}

void NiSphericalCollider::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AParticleModifier::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiSphericalCollider::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiSpotLight::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPointLight::Read( in, link_stack, info );
	NifStream( cutoffAngle, in, info );
	NifStream( exponent, in, info );
}

void NiSpotLight::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiPointLight::Write( out, link_map, info );
	NifStream( cutoffAngle, out, info );
	NifStream( exponent, out, info );
}

std::string NiSpotLight::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPointLight::asString();
	out << "  Cutoff Angle:  " << cutoffAngle << endl;
	out << "  Exponent:  " << exponent << endl;
	return out.str();
}

void NiSpotLight::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiPointLight::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiSpotLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPointLight::GetRefs();
	return refs;
}

void NiStencilProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, in, info );
	};
	NifStream( stencilEnabled, in, info );
	NifStream( stencilFunction, in, info );
	NifStream( stencilRef, in, info );
	NifStream( stencilMask, in, info );
	NifStream( failAction, in, info );
	NifStream( zFailAction, in, info );
	NifStream( passAction, in, info );
	NifStream( drawMode, in, info );
}

void NiStencilProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, out, info );
	};
	NifStream( stencilEnabled, out, info );
	NifStream( stencilFunction, out, info );
	NifStream( stencilRef, out, info );
	NifStream( stencilMask, out, info );
	NifStream( failAction, out, info );
	NifStream( zFailAction, out, info );
	NifStream( passAction, out, info );
	NifStream( drawMode, out, info );
}

std::string NiStencilProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Stencil Enabled:  " << stencilEnabled << endl;
	out << "  Stencil Function:  " << stencilFunction << endl;
	out << "  Stencil Ref:  " << stencilRef << endl;
	out << "  Stencil Mask:  " << stencilMask << endl;
	out << "  Fail Action:  " << failAction << endl;
	out << "  Z Fail Action:  " << zFailAction << endl;
	out << "  Pass Action:  " << passAction << endl;
	out << "  Draw Mode:  " << drawMode << endl;
	return out.str();
}

void NiStencilProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiStencilProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiStringExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( bytesRemaining, in, info );
	};
	NifStream( stringData, in, info );
}

void NiStringExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( bytesRemaining, out, info );
	};
	NifStream( stringData, out, info );
}

std::string NiStringExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Bytes Remaining:  " << bytesRemaining << endl;
	out << "  String Data:  " << stringData << endl;
	return out.str();
}

void NiStringExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiStringExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiStringPalette::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( palette.palette, in, info );
	NifStream( palette.length, in, info );
}

void NiStringPalette::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	NifStream( palette.palette, out, info );
	NifStream( palette.length, out, info );
}

std::string NiStringPalette::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Palette:  " << palette.palette << endl;
	out << "  Length:  " << palette.length << endl;
	return out.str();
}

void NiStringPalette::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiStringPalette::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiStringsExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( numStrings, in, info );
	data.resize(numStrings);
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], in, info );
	};
}

void NiStringsExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	numStrings = (unsigned int)(data.size());
	NifStream( numStrings, out, info );
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], out, info );
	};
}

std::string NiStringsExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	numStrings = (unsigned int)(data.size());
	out << "  Num Strings:  " << numStrings << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < data.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Data[" << i1 << "]:  " << data[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiStringsExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiStringsExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiTextKeyExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	if ( info.version <= 0x04020200 ) {
		NifStream( unknownInt1, in, info );
	};
	NifStream( numTextKeys, in, info );
	textKeys.resize(numTextKeys);
	for (unsigned int i1 = 0; i1 < textKeys.size(); i1++) {
		NifStream( textKeys[i1], in, info, 1 );
	};
}

void NiTextKeyExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	numTextKeys = (unsigned int)(textKeys.size());
	if ( info.version <= 0x04020200 ) {
		NifStream( unknownInt1, out, info );
	};
	NifStream( numTextKeys, out, info );
	for (unsigned int i1 = 0; i1 < textKeys.size(); i1++) {
		NifStream( textKeys[i1], out, info, 1 );
	};
}

std::string NiTextKeyExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	numTextKeys = (unsigned int)(textKeys.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Num Text Keys:  " << numTextKeys << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < textKeys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Text Keys[" << i1 << "]:  " << textKeys[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiTextKeyExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTextKeyExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiTextureEffect::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiDynamicEffect::Read( in, link_stack, info );
	NifStream( modelProjectionMatrix, in, info );
	NifStream( modelProjectionTransform, in, info );
	NifStream( textureFiltering, in, info );
	NifStream( textureClamping, in, info );
	NifStream( textureType, in, info );
	NifStream( coordinateGenerationType, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( clippingPlane, in, info );
	NifStream( unknownVector, in, info );
	NifStream( unknownFloat, in, info );
	if ( info.version <= 0x0A020000 ) {
		NifStream( ps2L, in, info );
		NifStream( ps2K, in, info );
	};
	if ( info.version <= 0x0401000C ) {
		NifStream( unknownShort, in, info );
	};
}

void NiTextureEffect::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiDynamicEffect::Write( out, link_map, info );
	NifStream( modelProjectionMatrix, out, info );
	NifStream( modelProjectionTransform, out, info );
	NifStream( textureFiltering, out, info );
	NifStream( textureClamping, out, info );
	NifStream( textureType, out, info );
	NifStream( coordinateGenerationType, out, info );
	if ( sourceTexture != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(sourceTexture) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( clippingPlane, out, info );
	NifStream( unknownVector, out, info );
	NifStream( unknownFloat, out, info );
	if ( info.version <= 0x0A020000 ) {
		NifStream( ps2L, out, info );
		NifStream( ps2K, out, info );
	};
	if ( info.version <= 0x0401000C ) {
		NifStream( unknownShort, out, info );
	};
}

std::string NiTextureEffect::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiDynamicEffect::asString();
	out << "  Model Projection Matrix:  " << modelProjectionMatrix << endl;
	out << "  Model Projection Transform:  " << modelProjectionTransform << endl;
	out << "  Texture Filtering:  " << textureFiltering << endl;
	out << "  Texture Clamping:  " << textureClamping << endl;
	out << "  Texture Type:  " << textureType << endl;
	out << "  Coordinate Generation Type:  " << coordinateGenerationType << endl;
	out << "  Source Texture:  " << sourceTexture << endl;
	out << "  Clipping Plane:  " << clippingPlane << endl;
	out << "  Unknown Vector:  " << unknownVector << endl;
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  PS2 L:  " << ps2L << endl;
	out << "  PS2 K:  " << ps2K << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	return out.str();
}

void NiTextureEffect::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiDynamicEffect::FixLinks( objects, link_stack, info );
	sourceTexture = FixLink<NiSourceTexture>( objects, link_stack, info );
}

std::list<NiObjectRef> NiTextureEffect::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiDynamicEffect::GetRefs();
	if ( sourceTexture != NULL )
		refs.push_back(StaticCast<NiObject>(sourceTexture));
	return refs;
}

void NiTextureTransformController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiSingleInterpolatorController::Read( in, link_stack, info );
	NifStream( unknown2, in, info );
	NifStream( textureSlot, in, info );
	NifStream( operation, in, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiTextureTransformController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSingleInterpolatorController::Write( out, link_map, info );
	NifStream( unknown2, out, info );
	NifStream( textureSlot, out, info );
	NifStream( operation, out, info );
	if ( info.version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiTextureTransformController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Unknown2:  " << unknown2 << endl;
	out << "  Texture Slot:  " << textureSlot << endl;
	out << "  Operation:  " << operation << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiTextureTransformController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		data = FixLink<NiFloatData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiTextureTransformController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiTextureModeProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknown3Shorts[i1], in, info );
	};
}

void NiTextureModeProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unknown3Shorts[i1], out, info );
	};
}

std::string NiTextureModeProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown 3 Shorts[" << i1 << "]:  " << unknown3Shorts[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiTextureModeProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTextureModeProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiImage::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( external_, in, info );
	NifStream( file, in, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Shorts[i1], in, info );
	};
}

void NiImage::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	NifStream( external_, out, info );
	NifStream( file, out, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Shorts[i1], out, info );
	};
}

std::string NiImage::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  External ?:  " << external_ << endl;
	out << "  File:  " << file << endl;
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
	return out.str();
}

void NiImage::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiImage::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiTextureProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiTextureProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
	if ( image != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(image) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiTextureProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Image:  " << image << endl;
	return out.str();
}

void NiTextureProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
	image = FixLink<NiImage>( objects, link_stack, info );
}

std::list<NiObjectRef> NiTextureProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	if ( image != NULL )
		refs.push_back(StaticCast<NiObject>(image));
	return refs;
}

void NiMultiTextureProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownInt3, in, info );
	NifStream( unknownInt4, in, info );
	NifStream( unknownInt5, in, info );
	for (unsigned int i1 = 0; i1 < 11; i1++) {
		NifStream( unknownShorts[i1], in, info );
	};
	if ( (unknownInt5 == 0) ) {
		for (unsigned int i2 = 0; i2 < 11; i2++) {
			NifStream( unknownExtraShorts[i2], in, info );
		};
	};
}

void NiMultiTextureProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	if ( image != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(image) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
	NifStream( unknownInt3, out, info );
	NifStream( unknownInt4, out, info );
	NifStream( unknownInt5, out, info );
	for (unsigned int i1 = 0; i1 < 11; i1++) {
		NifStream( unknownShorts[i1], out, info );
	};
	if ( (unknownInt5 == 0) ) {
		for (unsigned int i2 = 0; i2 < 11; i2++) {
			NifStream( unknownExtraShorts[i2], out, info );
		};
	};
}

std::string NiMultiTextureProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Image:  " << image << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 11; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Shorts[" << i1 << "]:  " << unknownShorts[i1] << endl;
		array_output_count++;
	};
	if ( (unknownInt5 == 0) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 11; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Extra Shorts[" << i2 << "]:  " << unknownExtraShorts[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiMultiTextureProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
	image = FixLink<NiImage>( objects, link_stack, info );
}

std::list<NiObjectRef> NiMultiTextureProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	if ( image != NULL )
		refs.push_back(StaticCast<NiObject>(image));
	return refs;
}

void NiTexturingProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiProperty::Read( in, link_stack, info );
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, in, info );
	};
	NifStream( applyMode, in, info );
	NifStream( textureCount, in, info );
	NifStream( hasBaseTexture, in, info );
	if ( (hasBaseTexture != 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( baseTexture.clampMode, in, info );
		NifStream( baseTexture.filterMode, in, info );
		NifStream( baseTexture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( baseTexture.ps2L, in, info );
			NifStream( baseTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( baseTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( baseTexture.hasTextureTransform, in, info );
			if ( (baseTexture.hasTextureTransform != 0) ) {
				NifStream( baseTexture.translation, in, info );
				NifStream( baseTexture.tiling, in, info );
				NifStream( baseTexture.wRotation, in, info );
				NifStream( baseTexture.transformType_, in, info );
				NifStream( baseTexture.centerOffset, in, info );
			};
		};
	};
	NifStream( hasDarkTexture, in, info );
	if ( (hasDarkTexture != 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( darkTexture.clampMode, in, info );
		NifStream( darkTexture.filterMode, in, info );
		NifStream( darkTexture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( darkTexture.ps2L, in, info );
			NifStream( darkTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( darkTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( darkTexture.hasTextureTransform, in, info );
			if ( (darkTexture.hasTextureTransform != 0) ) {
				NifStream( darkTexture.translation, in, info );
				NifStream( darkTexture.tiling, in, info );
				NifStream( darkTexture.wRotation, in, info );
				NifStream( darkTexture.transformType_, in, info );
				NifStream( darkTexture.centerOffset, in, info );
			};
		};
	};
	NifStream( hasDetailTexture, in, info );
	if ( (hasDetailTexture != 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( detailTexture.clampMode, in, info );
		NifStream( detailTexture.filterMode, in, info );
		NifStream( detailTexture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( detailTexture.ps2L, in, info );
			NifStream( detailTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( detailTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( detailTexture.hasTextureTransform, in, info );
			if ( (detailTexture.hasTextureTransform != 0) ) {
				NifStream( detailTexture.translation, in, info );
				NifStream( detailTexture.tiling, in, info );
				NifStream( detailTexture.wRotation, in, info );
				NifStream( detailTexture.transformType_, in, info );
				NifStream( detailTexture.centerOffset, in, info );
			};
		};
	};
	NifStream( hasGlossTexture, in, info );
	if ( (hasGlossTexture != 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( glossTexture.clampMode, in, info );
		NifStream( glossTexture.filterMode, in, info );
		NifStream( glossTexture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( glossTexture.ps2L, in, info );
			NifStream( glossTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( glossTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( glossTexture.hasTextureTransform, in, info );
			if ( (glossTexture.hasTextureTransform != 0) ) {
				NifStream( glossTexture.translation, in, info );
				NifStream( glossTexture.tiling, in, info );
				NifStream( glossTexture.wRotation, in, info );
				NifStream( glossTexture.transformType_, in, info );
				NifStream( glossTexture.centerOffset, in, info );
			};
		};
	};
	NifStream( hasGlowTexture, in, info );
	if ( (hasGlowTexture != 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( glowTexture.clampMode, in, info );
		NifStream( glowTexture.filterMode, in, info );
		NifStream( glowTexture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( glowTexture.ps2L, in, info );
			NifStream( glowTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( glowTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( glowTexture.hasTextureTransform, in, info );
			if ( (glowTexture.hasTextureTransform != 0) ) {
				NifStream( glowTexture.translation, in, info );
				NifStream( glowTexture.tiling, in, info );
				NifStream( glowTexture.wRotation, in, info );
				NifStream( glowTexture.transformType_, in, info );
				NifStream( glowTexture.centerOffset, in, info );
			};
		};
	};
	NifStream( hasBumpMapTexture, in, info );
	if ( (hasBumpMapTexture != 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( bumpMapTexture.clampMode, in, info );
		NifStream( bumpMapTexture.filterMode, in, info );
		NifStream( bumpMapTexture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( bumpMapTexture.ps2L, in, info );
			NifStream( bumpMapTexture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( bumpMapTexture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( bumpMapTexture.hasTextureTransform, in, info );
			if ( (bumpMapTexture.hasTextureTransform != 0) ) {
				NifStream( bumpMapTexture.translation, in, info );
				NifStream( bumpMapTexture.tiling, in, info );
				NifStream( bumpMapTexture.wRotation, in, info );
				NifStream( bumpMapTexture.transformType_, in, info );
				NifStream( bumpMapTexture.centerOffset, in, info );
			};
		};
		NifStream( bumpMapLumaScale, in, info );
		NifStream( bumpMapLumaOffset, in, info );
		NifStream( bumpMapMatrix, in, info );
	};
	NifStream( hasDecal0Texture, in, info );
	if ( (hasDecal0Texture != 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( decal0Texture.clampMode, in, info );
		NifStream( decal0Texture.filterMode, in, info );
		NifStream( decal0Texture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( decal0Texture.ps2L, in, info );
			NifStream( decal0Texture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal0Texture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal0Texture.hasTextureTransform, in, info );
			if ( (decal0Texture.hasTextureTransform != 0) ) {
				NifStream( decal0Texture.translation, in, info );
				NifStream( decal0Texture.tiling, in, info );
				NifStream( decal0Texture.wRotation, in, info );
				NifStream( decal0Texture.transformType_, in, info );
				NifStream( decal0Texture.centerOffset, in, info );
			};
		};
	};
	if ( (textureCount >= 8) ) {
		NifStream( hasDecal1Texture, in, info );
	};
	if ( (((textureCount >= 8)) && ((hasDecal1Texture != 0))) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( decal1Texture.clampMode, in, info );
		NifStream( decal1Texture.filterMode, in, info );
		NifStream( decal1Texture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( decal1Texture.ps2L, in, info );
			NifStream( decal1Texture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal1Texture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal1Texture.hasTextureTransform, in, info );
			if ( (decal1Texture.hasTextureTransform != 0) ) {
				NifStream( decal1Texture.translation, in, info );
				NifStream( decal1Texture.tiling, in, info );
				NifStream( decal1Texture.wRotation, in, info );
				NifStream( decal1Texture.transformType_, in, info );
				NifStream( decal1Texture.centerOffset, in, info );
			};
		};
	};
	if ( (textureCount >= 9) ) {
		NifStream( hasDecal2Texture, in, info );
	};
	if ( (((textureCount >= 9)) && ((hasDecal2Texture != 0))) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( decal2Texture.clampMode, in, info );
		NifStream( decal2Texture.filterMode, in, info );
		NifStream( decal2Texture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( decal2Texture.ps2L, in, info );
			NifStream( decal2Texture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal2Texture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal2Texture.hasTextureTransform, in, info );
			if ( (decal2Texture.hasTextureTransform != 0) ) {
				NifStream( decal2Texture.translation, in, info );
				NifStream( decal2Texture.tiling, in, info );
				NifStream( decal2Texture.wRotation, in, info );
				NifStream( decal2Texture.transformType_, in, info );
				NifStream( decal2Texture.centerOffset, in, info );
			};
		};
	};
	if ( (textureCount >= 10) ) {
		NifStream( hasDecal3Texture, in, info );
	};
	if ( (((textureCount >= 10)) && ((hasDecal3Texture != 0))) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( decal3Texture.clampMode, in, info );
		NifStream( decal3Texture.filterMode, in, info );
		NifStream( decal3Texture.uvSet, in, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( decal3Texture.ps2L, in, info );
			NifStream( decal3Texture.ps2K, in, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal3Texture.unknown1, in, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal3Texture.hasTextureTransform, in, info );
			if ( (decal3Texture.hasTextureTransform != 0) ) {
				NifStream( decal3Texture.translation, in, info );
				NifStream( decal3Texture.tiling, in, info );
				NifStream( decal3Texture.wRotation, in, info );
				NifStream( decal3Texture.transformType_, in, info );
				NifStream( decal3Texture.centerOffset, in, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numShaderTextures, in, info );
		shaderTextures.resize(numShaderTextures);
		for (unsigned int i2 = 0; i2 < shaderTextures.size(); i2++) {
			NifStream( shaderTextures[i2].isUsed, in, info );
			if ( (shaderTextures[i2].isUsed != 0) ) {
				NifStream( block_num, in, info );
				link_stack.push_back( block_num );
				NifStream( shaderTextures[i2].textureData.clampMode, in, info );
				NifStream( shaderTextures[i2].textureData.filterMode, in, info );
				NifStream( shaderTextures[i2].textureData.uvSet, in, info );
				if ( info.version <= 0x0A020000 ) {
					NifStream( shaderTextures[i2].textureData.ps2L, in, info );
					NifStream( shaderTextures[i2].textureData.ps2K, in, info );
				};
				if ( info.version <= 0x0401000C ) {
					NifStream( shaderTextures[i2].textureData.unknown1, in, info );
				};
				if ( info.version >= 0x0A010000 ) {
					NifStream( shaderTextures[i2].textureData.hasTextureTransform, in, info );
					if ( (shaderTextures[i2].textureData.hasTextureTransform != 0) ) {
						NifStream( shaderTextures[i2].textureData.translation, in, info );
						NifStream( shaderTextures[i2].textureData.tiling, in, info );
						NifStream( shaderTextures[i2].textureData.wRotation, in, info );
						NifStream( shaderTextures[i2].textureData.transformType_, in, info );
						NifStream( shaderTextures[i2].textureData.centerOffset, in, info );
					};
				};
				NifStream( shaderTextures[i2].unknownInt, in, info );
			};
		};
	};
}

void NiTexturingProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	numShaderTextures = (unsigned int)(shaderTextures.size());
	if ( info.version <= 0x0A000102 ) {
		NifStream( flags, out, info );
	};
	NifStream( applyMode, out, info );
	NifStream( textureCount, out, info );
	NifStream( hasBaseTexture, out, info );
	if ( (hasBaseTexture != 0) ) {
		if ( baseTexture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(baseTexture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( baseTexture.clampMode, out, info );
		NifStream( baseTexture.filterMode, out, info );
		NifStream( baseTexture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( baseTexture.ps2L, out, info );
			NifStream( baseTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( baseTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( baseTexture.hasTextureTransform, out, info );
			if ( (baseTexture.hasTextureTransform != 0) ) {
				NifStream( baseTexture.translation, out, info );
				NifStream( baseTexture.tiling, out, info );
				NifStream( baseTexture.wRotation, out, info );
				NifStream( baseTexture.transformType_, out, info );
				NifStream( baseTexture.centerOffset, out, info );
			};
		};
	};
	NifStream( hasDarkTexture, out, info );
	if ( (hasDarkTexture != 0) ) {
		if ( darkTexture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(darkTexture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( darkTexture.clampMode, out, info );
		NifStream( darkTexture.filterMode, out, info );
		NifStream( darkTexture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( darkTexture.ps2L, out, info );
			NifStream( darkTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( darkTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( darkTexture.hasTextureTransform, out, info );
			if ( (darkTexture.hasTextureTransform != 0) ) {
				NifStream( darkTexture.translation, out, info );
				NifStream( darkTexture.tiling, out, info );
				NifStream( darkTexture.wRotation, out, info );
				NifStream( darkTexture.transformType_, out, info );
				NifStream( darkTexture.centerOffset, out, info );
			};
		};
	};
	NifStream( hasDetailTexture, out, info );
	if ( (hasDetailTexture != 0) ) {
		if ( detailTexture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(detailTexture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( detailTexture.clampMode, out, info );
		NifStream( detailTexture.filterMode, out, info );
		NifStream( detailTexture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( detailTexture.ps2L, out, info );
			NifStream( detailTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( detailTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( detailTexture.hasTextureTransform, out, info );
			if ( (detailTexture.hasTextureTransform != 0) ) {
				NifStream( detailTexture.translation, out, info );
				NifStream( detailTexture.tiling, out, info );
				NifStream( detailTexture.wRotation, out, info );
				NifStream( detailTexture.transformType_, out, info );
				NifStream( detailTexture.centerOffset, out, info );
			};
		};
	};
	NifStream( hasGlossTexture, out, info );
	if ( (hasGlossTexture != 0) ) {
		if ( glossTexture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(glossTexture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( glossTexture.clampMode, out, info );
		NifStream( glossTexture.filterMode, out, info );
		NifStream( glossTexture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( glossTexture.ps2L, out, info );
			NifStream( glossTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( glossTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( glossTexture.hasTextureTransform, out, info );
			if ( (glossTexture.hasTextureTransform != 0) ) {
				NifStream( glossTexture.translation, out, info );
				NifStream( glossTexture.tiling, out, info );
				NifStream( glossTexture.wRotation, out, info );
				NifStream( glossTexture.transformType_, out, info );
				NifStream( glossTexture.centerOffset, out, info );
			};
		};
	};
	NifStream( hasGlowTexture, out, info );
	if ( (hasGlowTexture != 0) ) {
		if ( glowTexture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(glowTexture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( glowTexture.clampMode, out, info );
		NifStream( glowTexture.filterMode, out, info );
		NifStream( glowTexture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( glowTexture.ps2L, out, info );
			NifStream( glowTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( glowTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( glowTexture.hasTextureTransform, out, info );
			if ( (glowTexture.hasTextureTransform != 0) ) {
				NifStream( glowTexture.translation, out, info );
				NifStream( glowTexture.tiling, out, info );
				NifStream( glowTexture.wRotation, out, info );
				NifStream( glowTexture.transformType_, out, info );
				NifStream( glowTexture.centerOffset, out, info );
			};
		};
	};
	NifStream( hasBumpMapTexture, out, info );
	if ( (hasBumpMapTexture != 0) ) {
		if ( bumpMapTexture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(bumpMapTexture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( bumpMapTexture.clampMode, out, info );
		NifStream( bumpMapTexture.filterMode, out, info );
		NifStream( bumpMapTexture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( bumpMapTexture.ps2L, out, info );
			NifStream( bumpMapTexture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( bumpMapTexture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( bumpMapTexture.hasTextureTransform, out, info );
			if ( (bumpMapTexture.hasTextureTransform != 0) ) {
				NifStream( bumpMapTexture.translation, out, info );
				NifStream( bumpMapTexture.tiling, out, info );
				NifStream( bumpMapTexture.wRotation, out, info );
				NifStream( bumpMapTexture.transformType_, out, info );
				NifStream( bumpMapTexture.centerOffset, out, info );
			};
		};
		NifStream( bumpMapLumaScale, out, info );
		NifStream( bumpMapLumaOffset, out, info );
		NifStream( bumpMapMatrix, out, info );
	};
	NifStream( hasDecal0Texture, out, info );
	if ( (hasDecal0Texture != 0) ) {
		if ( decal0Texture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(decal0Texture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( decal0Texture.clampMode, out, info );
		NifStream( decal0Texture.filterMode, out, info );
		NifStream( decal0Texture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( decal0Texture.ps2L, out, info );
			NifStream( decal0Texture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal0Texture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal0Texture.hasTextureTransform, out, info );
			if ( (decal0Texture.hasTextureTransform != 0) ) {
				NifStream( decal0Texture.translation, out, info );
				NifStream( decal0Texture.tiling, out, info );
				NifStream( decal0Texture.wRotation, out, info );
				NifStream( decal0Texture.transformType_, out, info );
				NifStream( decal0Texture.centerOffset, out, info );
			};
		};
	};
	if ( (textureCount >= 8) ) {
		NifStream( hasDecal1Texture, out, info );
	};
	if ( (((textureCount >= 8)) && ((hasDecal1Texture != 0))) ) {
		if ( decal1Texture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(decal1Texture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( decal1Texture.clampMode, out, info );
		NifStream( decal1Texture.filterMode, out, info );
		NifStream( decal1Texture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( decal1Texture.ps2L, out, info );
			NifStream( decal1Texture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal1Texture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal1Texture.hasTextureTransform, out, info );
			if ( (decal1Texture.hasTextureTransform != 0) ) {
				NifStream( decal1Texture.translation, out, info );
				NifStream( decal1Texture.tiling, out, info );
				NifStream( decal1Texture.wRotation, out, info );
				NifStream( decal1Texture.transformType_, out, info );
				NifStream( decal1Texture.centerOffset, out, info );
			};
		};
	};
	if ( (textureCount >= 9) ) {
		NifStream( hasDecal2Texture, out, info );
	};
	if ( (((textureCount >= 9)) && ((hasDecal2Texture != 0))) ) {
		if ( decal2Texture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(decal2Texture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( decal2Texture.clampMode, out, info );
		NifStream( decal2Texture.filterMode, out, info );
		NifStream( decal2Texture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( decal2Texture.ps2L, out, info );
			NifStream( decal2Texture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal2Texture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal2Texture.hasTextureTransform, out, info );
			if ( (decal2Texture.hasTextureTransform != 0) ) {
				NifStream( decal2Texture.translation, out, info );
				NifStream( decal2Texture.tiling, out, info );
				NifStream( decal2Texture.wRotation, out, info );
				NifStream( decal2Texture.transformType_, out, info );
				NifStream( decal2Texture.centerOffset, out, info );
			};
		};
	};
	if ( (textureCount >= 10) ) {
		NifStream( hasDecal3Texture, out, info );
	};
	if ( (((textureCount >= 10)) && ((hasDecal3Texture != 0))) ) {
		if ( decal3Texture.source != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(decal3Texture.source) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
		NifStream( decal3Texture.clampMode, out, info );
		NifStream( decal3Texture.filterMode, out, info );
		NifStream( decal3Texture.uvSet, out, info );
		if ( info.version <= 0x0A020000 ) {
			NifStream( decal3Texture.ps2L, out, info );
			NifStream( decal3Texture.ps2K, out, info );
		};
		if ( info.version <= 0x0401000C ) {
			NifStream( decal3Texture.unknown1, out, info );
		};
		if ( info.version >= 0x0A010000 ) {
			NifStream( decal3Texture.hasTextureTransform, out, info );
			if ( (decal3Texture.hasTextureTransform != 0) ) {
				NifStream( decal3Texture.translation, out, info );
				NifStream( decal3Texture.tiling, out, info );
				NifStream( decal3Texture.wRotation, out, info );
				NifStream( decal3Texture.transformType_, out, info );
				NifStream( decal3Texture.centerOffset, out, info );
			};
		};
	};
	if ( info.version >= 0x0A000100 ) {
		NifStream( numShaderTextures, out, info );
		for (unsigned int i2 = 0; i2 < shaderTextures.size(); i2++) {
			NifStream( shaderTextures[i2].isUsed, out, info );
			if ( (shaderTextures[i2].isUsed != 0) ) {
				if ( shaderTextures[i2].textureData.source != NULL )
					NifStream( link_map.find( StaticCast<NiObject>(shaderTextures[i2].textureData.source) )->second, out, info );
				else
					NifStream( 0xffffffff, out, info );
				NifStream( shaderTextures[i2].textureData.clampMode, out, info );
				NifStream( shaderTextures[i2].textureData.filterMode, out, info );
				NifStream( shaderTextures[i2].textureData.uvSet, out, info );
				if ( info.version <= 0x0A020000 ) {
					NifStream( shaderTextures[i2].textureData.ps2L, out, info );
					NifStream( shaderTextures[i2].textureData.ps2K, out, info );
				};
				if ( info.version <= 0x0401000C ) {
					NifStream( shaderTextures[i2].textureData.unknown1, out, info );
				};
				if ( info.version >= 0x0A010000 ) {
					NifStream( shaderTextures[i2].textureData.hasTextureTransform, out, info );
					if ( (shaderTextures[i2].textureData.hasTextureTransform != 0) ) {
						NifStream( shaderTextures[i2].textureData.translation, out, info );
						NifStream( shaderTextures[i2].textureData.tiling, out, info );
						NifStream( shaderTextures[i2].textureData.wRotation, out, info );
						NifStream( shaderTextures[i2].textureData.transformType_, out, info );
						NifStream( shaderTextures[i2].textureData.centerOffset, out, info );
					};
				};
				NifStream( shaderTextures[i2].unknownInt, out, info );
			};
		};
	};
}

std::string NiTexturingProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	numShaderTextures = (unsigned int)(shaderTextures.size());
	out << "  Flags:  " << flags << endl;
	out << "  Apply Mode:  " << applyMode << endl;
	out << "  Texture Count:  " << textureCount << endl;
	out << "  Has Base Texture:  " << hasBaseTexture << endl;
	if ( (hasBaseTexture != 0) ) {
		out << "    Source:  " << baseTexture.source << endl;
		out << "    Clamp Mode:  " << baseTexture.clampMode << endl;
		out << "    Filter Mode:  " << baseTexture.filterMode << endl;
		out << "    UV Set:  " << baseTexture.uvSet << endl;
		out << "    PS2 L:  " << baseTexture.ps2L << endl;
		out << "    PS2 K:  " << baseTexture.ps2K << endl;
		out << "    Unknown1:  " << baseTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << baseTexture.hasTextureTransform << endl;
		if ( (baseTexture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << baseTexture.translation << endl;
			out << "      Tiling:  " << baseTexture.tiling << endl;
			out << "      W Rotation:  " << baseTexture.wRotation << endl;
			out << "      Transform Type?:  " << baseTexture.transformType_ << endl;
			out << "      Center Offset:  " << baseTexture.centerOffset << endl;
		};
	};
	out << "  Has Dark Texture:  " << hasDarkTexture << endl;
	if ( (hasDarkTexture != 0) ) {
		out << "    Source:  " << darkTexture.source << endl;
		out << "    Clamp Mode:  " << darkTexture.clampMode << endl;
		out << "    Filter Mode:  " << darkTexture.filterMode << endl;
		out << "    UV Set:  " << darkTexture.uvSet << endl;
		out << "    PS2 L:  " << darkTexture.ps2L << endl;
		out << "    PS2 K:  " << darkTexture.ps2K << endl;
		out << "    Unknown1:  " << darkTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << darkTexture.hasTextureTransform << endl;
		if ( (darkTexture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << darkTexture.translation << endl;
			out << "      Tiling:  " << darkTexture.tiling << endl;
			out << "      W Rotation:  " << darkTexture.wRotation << endl;
			out << "      Transform Type?:  " << darkTexture.transformType_ << endl;
			out << "      Center Offset:  " << darkTexture.centerOffset << endl;
		};
	};
	out << "  Has Detail Texture:  " << hasDetailTexture << endl;
	if ( (hasDetailTexture != 0) ) {
		out << "    Source:  " << detailTexture.source << endl;
		out << "    Clamp Mode:  " << detailTexture.clampMode << endl;
		out << "    Filter Mode:  " << detailTexture.filterMode << endl;
		out << "    UV Set:  " << detailTexture.uvSet << endl;
		out << "    PS2 L:  " << detailTexture.ps2L << endl;
		out << "    PS2 K:  " << detailTexture.ps2K << endl;
		out << "    Unknown1:  " << detailTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << detailTexture.hasTextureTransform << endl;
		if ( (detailTexture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << detailTexture.translation << endl;
			out << "      Tiling:  " << detailTexture.tiling << endl;
			out << "      W Rotation:  " << detailTexture.wRotation << endl;
			out << "      Transform Type?:  " << detailTexture.transformType_ << endl;
			out << "      Center Offset:  " << detailTexture.centerOffset << endl;
		};
	};
	out << "  Has Gloss Texture:  " << hasGlossTexture << endl;
	if ( (hasGlossTexture != 0) ) {
		out << "    Source:  " << glossTexture.source << endl;
		out << "    Clamp Mode:  " << glossTexture.clampMode << endl;
		out << "    Filter Mode:  " << glossTexture.filterMode << endl;
		out << "    UV Set:  " << glossTexture.uvSet << endl;
		out << "    PS2 L:  " << glossTexture.ps2L << endl;
		out << "    PS2 K:  " << glossTexture.ps2K << endl;
		out << "    Unknown1:  " << glossTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << glossTexture.hasTextureTransform << endl;
		if ( (glossTexture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << glossTexture.translation << endl;
			out << "      Tiling:  " << glossTexture.tiling << endl;
			out << "      W Rotation:  " << glossTexture.wRotation << endl;
			out << "      Transform Type?:  " << glossTexture.transformType_ << endl;
			out << "      Center Offset:  " << glossTexture.centerOffset << endl;
		};
	};
	out << "  Has Glow Texture:  " << hasGlowTexture << endl;
	if ( (hasGlowTexture != 0) ) {
		out << "    Source:  " << glowTexture.source << endl;
		out << "    Clamp Mode:  " << glowTexture.clampMode << endl;
		out << "    Filter Mode:  " << glowTexture.filterMode << endl;
		out << "    UV Set:  " << glowTexture.uvSet << endl;
		out << "    PS2 L:  " << glowTexture.ps2L << endl;
		out << "    PS2 K:  " << glowTexture.ps2K << endl;
		out << "    Unknown1:  " << glowTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << glowTexture.hasTextureTransform << endl;
		if ( (glowTexture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << glowTexture.translation << endl;
			out << "      Tiling:  " << glowTexture.tiling << endl;
			out << "      W Rotation:  " << glowTexture.wRotation << endl;
			out << "      Transform Type?:  " << glowTexture.transformType_ << endl;
			out << "      Center Offset:  " << glowTexture.centerOffset << endl;
		};
	};
	out << "  Has Bump Map Texture:  " << hasBumpMapTexture << endl;
	if ( (hasBumpMapTexture != 0) ) {
		out << "    Source:  " << bumpMapTexture.source << endl;
		out << "    Clamp Mode:  " << bumpMapTexture.clampMode << endl;
		out << "    Filter Mode:  " << bumpMapTexture.filterMode << endl;
		out << "    UV Set:  " << bumpMapTexture.uvSet << endl;
		out << "    PS2 L:  " << bumpMapTexture.ps2L << endl;
		out << "    PS2 K:  " << bumpMapTexture.ps2K << endl;
		out << "    Unknown1:  " << bumpMapTexture.unknown1 << endl;
		out << "    Has Texture Transform:  " << bumpMapTexture.hasTextureTransform << endl;
		if ( (bumpMapTexture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << bumpMapTexture.translation << endl;
			out << "      Tiling:  " << bumpMapTexture.tiling << endl;
			out << "      W Rotation:  " << bumpMapTexture.wRotation << endl;
			out << "      Transform Type?:  " << bumpMapTexture.transformType_ << endl;
			out << "      Center Offset:  " << bumpMapTexture.centerOffset << endl;
		};
		out << "    Bump Map Luma Scale:  " << bumpMapLumaScale << endl;
		out << "    Bump Map Luma Offset:  " << bumpMapLumaOffset << endl;
		out << "    Bump Map Matrix:  " << bumpMapMatrix << endl;
	};
	out << "  Has Decal 0 Texture:  " << hasDecal0Texture << endl;
	if ( (hasDecal0Texture != 0) ) {
		out << "    Source:  " << decal0Texture.source << endl;
		out << "    Clamp Mode:  " << decal0Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal0Texture.filterMode << endl;
		out << "    UV Set:  " << decal0Texture.uvSet << endl;
		out << "    PS2 L:  " << decal0Texture.ps2L << endl;
		out << "    PS2 K:  " << decal0Texture.ps2K << endl;
		out << "    Unknown1:  " << decal0Texture.unknown1 << endl;
		out << "    Has Texture Transform:  " << decal0Texture.hasTextureTransform << endl;
		if ( (decal0Texture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << decal0Texture.translation << endl;
			out << "      Tiling:  " << decal0Texture.tiling << endl;
			out << "      W Rotation:  " << decal0Texture.wRotation << endl;
			out << "      Transform Type?:  " << decal0Texture.transformType_ << endl;
			out << "      Center Offset:  " << decal0Texture.centerOffset << endl;
		};
	};
	if ( (textureCount >= 8) ) {
		out << "    Has Decal 1 Texture:  " << hasDecal1Texture << endl;
	};
	if ( (((textureCount >= 8)) && ((hasDecal1Texture != 0))) ) {
		out << "    Source:  " << decal1Texture.source << endl;
		out << "    Clamp Mode:  " << decal1Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal1Texture.filterMode << endl;
		out << "    UV Set:  " << decal1Texture.uvSet << endl;
		out << "    PS2 L:  " << decal1Texture.ps2L << endl;
		out << "    PS2 K:  " << decal1Texture.ps2K << endl;
		out << "    Unknown1:  " << decal1Texture.unknown1 << endl;
		out << "    Has Texture Transform:  " << decal1Texture.hasTextureTransform << endl;
		if ( (decal1Texture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << decal1Texture.translation << endl;
			out << "      Tiling:  " << decal1Texture.tiling << endl;
			out << "      W Rotation:  " << decal1Texture.wRotation << endl;
			out << "      Transform Type?:  " << decal1Texture.transformType_ << endl;
			out << "      Center Offset:  " << decal1Texture.centerOffset << endl;
		};
	};
	if ( (textureCount >= 9) ) {
		out << "    Has Decal 2 Texture:  " << hasDecal2Texture << endl;
	};
	if ( (((textureCount >= 9)) && ((hasDecal2Texture != 0))) ) {
		out << "    Source:  " << decal2Texture.source << endl;
		out << "    Clamp Mode:  " << decal2Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal2Texture.filterMode << endl;
		out << "    UV Set:  " << decal2Texture.uvSet << endl;
		out << "    PS2 L:  " << decal2Texture.ps2L << endl;
		out << "    PS2 K:  " << decal2Texture.ps2K << endl;
		out << "    Unknown1:  " << decal2Texture.unknown1 << endl;
		out << "    Has Texture Transform:  " << decal2Texture.hasTextureTransform << endl;
		if ( (decal2Texture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << decal2Texture.translation << endl;
			out << "      Tiling:  " << decal2Texture.tiling << endl;
			out << "      W Rotation:  " << decal2Texture.wRotation << endl;
			out << "      Transform Type?:  " << decal2Texture.transformType_ << endl;
			out << "      Center Offset:  " << decal2Texture.centerOffset << endl;
		};
	};
	if ( (textureCount >= 10) ) {
		out << "    Has Decal 3 Texture:  " << hasDecal3Texture << endl;
	};
	if ( (((textureCount >= 10)) && ((hasDecal3Texture != 0))) ) {
		out << "    Source:  " << decal3Texture.source << endl;
		out << "    Clamp Mode:  " << decal3Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal3Texture.filterMode << endl;
		out << "    UV Set:  " << decal3Texture.uvSet << endl;
		out << "    PS2 L:  " << decal3Texture.ps2L << endl;
		out << "    PS2 K:  " << decal3Texture.ps2K << endl;
		out << "    Unknown1:  " << decal3Texture.unknown1 << endl;
		out << "    Has Texture Transform:  " << decal3Texture.hasTextureTransform << endl;
		if ( (decal3Texture.hasTextureTransform != 0) ) {
			out << "      Translation:  " << decal3Texture.translation << endl;
			out << "      Tiling:  " << decal3Texture.tiling << endl;
			out << "      W Rotation:  " << decal3Texture.wRotation << endl;
			out << "      Transform Type?:  " << decal3Texture.transformType_ << endl;
			out << "      Center Offset:  " << decal3Texture.centerOffset << endl;
		};
	};
	out << "  Num Shader Textures:  " << numShaderTextures << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < shaderTextures.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Is Used:  " << shaderTextures[i1].isUsed << endl;
		if ( (shaderTextures[i1].isUsed != 0) ) {
			out << "      Source:  " << shaderTextures[i1].textureData.source << endl;
			out << "      Clamp Mode:  " << shaderTextures[i1].textureData.clampMode << endl;
			out << "      Filter Mode:  " << shaderTextures[i1].textureData.filterMode << endl;
			out << "      UV Set:  " << shaderTextures[i1].textureData.uvSet << endl;
			out << "      PS2 L:  " << shaderTextures[i1].textureData.ps2L << endl;
			out << "      PS2 K:  " << shaderTextures[i1].textureData.ps2K << endl;
			out << "      Unknown1:  " << shaderTextures[i1].textureData.unknown1 << endl;
			out << "      Has Texture Transform:  " << shaderTextures[i1].textureData.hasTextureTransform << endl;
			if ( (shaderTextures[i1].textureData.hasTextureTransform != 0) ) {
				out << "        Translation:  " << shaderTextures[i1].textureData.translation << endl;
				out << "        Tiling:  " << shaderTextures[i1].textureData.tiling << endl;
				out << "        W Rotation:  " << shaderTextures[i1].textureData.wRotation << endl;
				out << "        Transform Type?:  " << shaderTextures[i1].textureData.transformType_ << endl;
				out << "        Center Offset:  " << shaderTextures[i1].textureData.centerOffset << endl;
			};
			out << "      Unknown Int:  " << shaderTextures[i1].unknownInt << endl;
		};
	};
	return out.str();
}

void NiTexturingProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
	if ( (hasBaseTexture != 0) ) {
		baseTexture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (hasDarkTexture != 0) ) {
		darkTexture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (hasDetailTexture != 0) ) {
		detailTexture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (hasGlossTexture != 0) ) {
		glossTexture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (hasGlowTexture != 0) ) {
		glowTexture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (hasBumpMapTexture != 0) ) {
		bumpMapTexture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (hasDecal0Texture != 0) ) {
		decal0Texture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (((textureCount >= 8)) && ((hasDecal1Texture != 0))) ) {
		decal1Texture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (((textureCount >= 9)) && ((hasDecal2Texture != 0))) ) {
		decal2Texture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( (((textureCount >= 10)) && ((hasDecal3Texture != 0))) ) {
		decal3Texture.source = FixLink<NiSourceTexture>( objects, link_stack, info );
	};
	if ( info.version >= 0x0A000100 ) {
		for (unsigned int i2 = 0; i2 < shaderTextures.size(); i2++) {
			if ( (shaderTextures[i2].isUsed != 0) ) {
				shaderTextures[i2].textureData.source = FixLink<NiSourceTexture>( objects, link_stack, info );
			};
		};
	};
}

std::list<NiObjectRef> NiTexturingProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	if ( baseTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(baseTexture.source));
	if ( darkTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(darkTexture.source));
	if ( detailTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(detailTexture.source));
	if ( glossTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(glossTexture.source));
	if ( glowTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(glowTexture.source));
	if ( bumpMapTexture.source != NULL )
		refs.push_back(StaticCast<NiObject>(bumpMapTexture.source));
	if ( decal0Texture.source != NULL )
		refs.push_back(StaticCast<NiObject>(decal0Texture.source));
	if ( decal1Texture.source != NULL )
		refs.push_back(StaticCast<NiObject>(decal1Texture.source));
	if ( decal2Texture.source != NULL )
		refs.push_back(StaticCast<NiObject>(decal2Texture.source));
	if ( decal3Texture.source != NULL )
		refs.push_back(StaticCast<NiObject>(decal3Texture.source));
	for (unsigned int i1 = 0; i1 < shaderTextures.size(); i1++) {
		if ( shaderTextures[i1].textureData.source != NULL )
			refs.push_back(StaticCast<NiObject>(shaderTextures[i1].textureData.source));
	};
	return refs;
}

void NiTransformController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::Read( in, link_stack, info );
}

void NiTransformController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSingleInterpolatorController::Write( out, link_map, info );
}

std::string NiTransformController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	return out.str();
}

void NiTransformController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTransformController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	return refs;
}

void NiTransformData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiKeyframeData::Read( in, link_stack, info );
}

void NiTransformData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiKeyframeData::Write( out, link_map, info );
}

std::string NiTransformData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiKeyframeData::asString();
	return out.str();
}

void NiTransformData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiKeyframeData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTransformData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyframeData::GetRefs();
	return refs;
}

void NiTransformInterpolator::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( translation, in, info );
	NifStream( rotation, in, info );
	NifStream( scale, in, info );
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			NifStream( unknownBytes[i2], in, info );
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiTransformInterpolator::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiInterpolator::Write( out, link_map, info );
	NifStream( translation, out, info );
	NifStream( rotation, out, info );
	NifStream( scale, out, info );
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			NifStream( unknownBytes[i2], out, info );
		};
	};
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiTransformInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Bytes[" << i1 << "]:  " << unknownBytes[i1] << endl;
		array_output_count++;
	};
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiTransformInterpolator::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiInterpolator::FixLinks( objects, link_stack, info );
	data = FixLink<NiTransformData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiTransformInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiTriShape::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeom::Read( in, link_stack, info );
}

void NiTriShape::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTriBasedGeom::Write( out, link_map, info );
}

std::string NiTriShape::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiTriShape::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTriShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
	return refs;
}

void NiTriShapeData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeomData::Read( in, link_stack, info );
	NifStream( numTrianglePoints, in, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( hasTriangles, in, info );
	};
	if ( info.version <= 0x0A000102 ) {
		triangles.resize(numTriangles);
		for (unsigned int i2 = 0; i2 < triangles.size(); i2++) {
			NifStream( triangles[i2], in, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (hasTriangles != 0) ) {
			triangles.resize(numTriangles);
			for (unsigned int i3 = 0; i3 < triangles.size(); i3++) {
				NifStream( triangles[i3], in, info );
			};
		};
	};
	NifStream( numMatchGroups, in, info );
	matchGroups.resize(numMatchGroups);
	for (unsigned int i1 = 0; i1 < matchGroups.size(); i1++) {
		NifStream( matchGroups[i1].numVertices, in, info );
		matchGroups[i1].vertexIndices.resize(matchGroups[i1].numVertices);
		for (unsigned int i2 = 0; i2 < matchGroups[i1].vertexIndices.size(); i2++) {
			NifStream( matchGroups[i1].vertexIndices[i2], in, info );
		};
	};
}

void NiTriShapeData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTriBasedGeomData::Write( out, link_map, info );
	numMatchGroups = (unsigned short)(matchGroups.size());
	NifStream( numTrianglePoints, out, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( hasTriangles, out, info );
	};
	if ( info.version <= 0x0A000102 ) {
		for (unsigned int i2 = 0; i2 < triangles.size(); i2++) {
			NifStream( triangles[i2], out, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (hasTriangles != 0) ) {
			for (unsigned int i3 = 0; i3 < triangles.size(); i3++) {
				NifStream( triangles[i3], out, info );
			};
		};
	};
	NifStream( numMatchGroups, out, info );
	for (unsigned int i1 = 0; i1 < matchGroups.size(); i1++) {
		matchGroups[i1].numVertices = (unsigned short)(matchGroups[i1].vertexIndices.size());
		NifStream( matchGroups[i1].numVertices, out, info );
		for (unsigned int i2 = 0; i2 < matchGroups[i1].vertexIndices.size(); i2++) {
			NifStream( matchGroups[i1].vertexIndices[i2], out, info );
		};
	};
}

std::string NiTriShapeData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriBasedGeomData::asString();
	numMatchGroups = (unsigned short)(matchGroups.size());
	out << "  Num Triangle Points:  " << numTrianglePoints << endl;
	out << "  Has Triangles:  " << hasTriangles << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < triangles.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Triangles[" << i1 << "]:  " << triangles[i1] << endl;
		array_output_count++;
	};
	out << "  Num Match Groups:  " << numMatchGroups << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < matchGroups.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		matchGroups[i1].numVertices = (unsigned short)(matchGroups[i1].vertexIndices.size());
		out << "    Num Vertices:  " << matchGroups[i1].numVertices << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < matchGroups[i1].vertexIndices.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Vertex Indices[" << i2 << "]:  " << matchGroups[i1].vertexIndices[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiTriShapeData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTriShapeData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeomData::GetRefs();
	return refs;
}

void NiTriStrips::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeom::Read( in, link_stack, info );
}

void NiTriStrips::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTriBasedGeom::Write( out, link_map, info );
}

std::string NiTriStrips::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiTriStrips::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTriStrips::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
	return refs;
}

void NiTriStripsData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeomData::Read( in, link_stack, info );
	NifStream( numStrips, in, info );
	stripLengths.resize(numStrips);
	for (unsigned int i1 = 0; i1 < stripLengths.size(); i1++) {
		NifStream( stripLengths[i1], in, info );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( hasPoints, in, info );
	};
	if ( info.version <= 0x0A000102 ) {
		points.resize(numStrips);
		for (unsigned int i2 = 0; i2 < points.size(); i2++) {
			points[i2].resize(stripLengths[i2]);
			for (unsigned int i3 = 0; i3 < stripLengths[i2]; i3++) {
				NifStream( points[i2][i3], in, info );
			};
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (hasPoints != 0) ) {
			points.resize(numStrips);
			for (unsigned int i3 = 0; i3 < points.size(); i3++) {
				points[i3].resize(stripLengths[i3]);
				for (unsigned int i4 = 0; i4 < stripLengths[i3]; i4++) {
					NifStream( points[i3][i4], in, info );
				};
			};
		};
	};
}

void NiTriStripsData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTriBasedGeomData::Write( out, link_map, info );
	for (unsigned int i1 = 0; i1 < points.size(); i1++)
		stripLengths[i1] = (unsigned short)(points[i1].size());
	numStrips = (unsigned short)(stripLengths.size());
	NifStream( numStrips, out, info );
	for (unsigned int i1 = 0; i1 < stripLengths.size(); i1++) {
		NifStream( stripLengths[i1], out, info );
	};
	if ( info.version >= 0x0A010000 ) {
		NifStream( hasPoints, out, info );
	};
	if ( info.version <= 0x0A000102 ) {
		for (unsigned int i2 = 0; i2 < points.size(); i2++) {
			for (unsigned int i3 = 0; i3 < stripLengths[i2]; i3++) {
				NifStream( points[i2][i3], out, info );
			};
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (hasPoints != 0) ) {
			for (unsigned int i3 = 0; i3 < points.size(); i3++) {
				for (unsigned int i4 = 0; i4 < stripLengths[i3]; i4++) {
					NifStream( points[i3][i4], out, info );
				};
			};
		};
	};
}

std::string NiTriStripsData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriBasedGeomData::asString();
	for (unsigned int i1 = 0; i1 < points.size(); i1++)
		stripLengths[i1] = (unsigned short)(points[i1].size());
	numStrips = (unsigned short)(stripLengths.size());
	out << "  Num Strips:  " << numStrips << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < stripLengths.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Strip Lengths[" << i1 << "]:  " << stripLengths[i1] << endl;
		array_output_count++;
	};
	out << "  Has Points:  " << hasPoints << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < points.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < stripLengths[i1]; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Points[" << i2 << "]:  " << points[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiTriStripsData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiTriStripsData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeomData::GetRefs();
	return refs;
}

void NiClod::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeom::Read( in, link_stack, info );
}

void NiClod::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTriBasedGeom::Write( out, link_map, info );
}

std::string NiClod::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiClod::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiClod::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
	return refs;
}

void NiClodData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeomData::Read( in, link_stack, info );
	NifStream( unknownShorts, in, info );
	NifStream( unknownCount1, in, info );
	NifStream( unknownCount2, in, info );
	NifStream( unknownCount3, in, info );
	NifStream( unknownFloat, in, info );
	NifStream( unknownShort, in, info );
	unknownClodShorts1.resize(unknownCount1);
	for (unsigned int i1 = 0; i1 < unknownClodShorts1.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			NifStream( unknownClodShorts1[i1][i2], in, info );
		};
	};
	unknownClodShorts2.resize(unknownCount2);
	for (unsigned int i1 = 0; i1 < unknownClodShorts2.size(); i1++) {
		NifStream( unknownClodShorts2[i1], in, info );
	};
	unknownClodShorts3.resize(unknownCount3);
	for (unsigned int i1 = 0; i1 < unknownClodShorts3.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			NifStream( unknownClodShorts3[i1][i2], in, info );
		};
	};
}

void NiClodData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTriBasedGeomData::Write( out, link_map, info );
	unknownCount3 = (unsigned short)(unknownClodShorts3.size());
	unknownCount2 = (unsigned short)(unknownClodShorts2.size());
	unknownCount1 = (unsigned short)(unknownClodShorts1.size());
	NifStream( unknownShorts, out, info );
	NifStream( unknownCount1, out, info );
	NifStream( unknownCount2, out, info );
	NifStream( unknownCount3, out, info );
	NifStream( unknownFloat, out, info );
	NifStream( unknownShort, out, info );
	for (unsigned int i1 = 0; i1 < unknownClodShorts1.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			NifStream( unknownClodShorts1[i1][i2], out, info );
		};
	};
	for (unsigned int i1 = 0; i1 < unknownClodShorts2.size(); i1++) {
		NifStream( unknownClodShorts2[i1], out, info );
	};
	for (unsigned int i1 = 0; i1 < unknownClodShorts3.size(); i1++) {
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			NifStream( unknownClodShorts3[i1][i2], out, info );
		};
	};
}

std::string NiClodData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriBasedGeomData::asString();
	unknownCount3 = (unsigned short)(unknownClodShorts3.size());
	unknownCount2 = (unsigned short)(unknownClodShorts2.size());
	unknownCount1 = (unsigned short)(unknownClodShorts1.size());
	out << "  Unknown Shorts:  " << unknownShorts << endl;
	out << "  Unknown Count 1:  " << unknownCount1 << endl;
	out << "  Unknown Count 2:  " << unknownCount2 << endl;
	out << "  Unknown Count 3:  " << unknownCount3 << endl;
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownClodShorts1.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Clod Shorts 1[" << i2 << "]:  " << unknownClodShorts1[i1][i2] << endl;
			array_output_count++;
		};
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownClodShorts2.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Clod Shorts 2[" << i1 << "]:  " << unknownClodShorts2[i1] << endl;
		array_output_count++;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < unknownClodShorts3.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < 6; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Clod Shorts 3[" << i2 << "]:  " << unknownClodShorts3[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiClodData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiClodData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeomData::GetRefs();
	return refs;
}

void NiUVController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( unknownShort, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
}

void NiUVController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiTimeController::Write( out, link_map, info );
	NifStream( unknownShort, out, info );
	if ( data != NULL )
		NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
	else
		NifStream( 0xffffffff, out, info );
}

std::string NiUVController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiUVController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiTimeController::FixLinks( objects, link_stack, info );
	data = FixLink<NiUVData>( objects, link_stack, info );
}

std::list<NiObjectRef> NiUVController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiUVData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( uvGroups[i1].numKeys, in, info );
		if ( (uvGroups[i1].numKeys != 0) ) {
			NifStream( uvGroups[i1].interpolation, in, info );
		};
		uvGroups[i1].keys.resize(uvGroups[i1].numKeys);
		for (unsigned int i2 = 0; i2 < uvGroups[i1].keys.size(); i2++) {
			NifStream( uvGroups[i1].keys[i2], in, info, uvGroups[i1].interpolation );
		};
	};
}

void NiUVData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		uvGroups[i1].numKeys = (unsigned int)(uvGroups[i1].keys.size());
		NifStream( uvGroups[i1].numKeys, out, info );
		if ( (uvGroups[i1].numKeys != 0) ) {
			NifStream( uvGroups[i1].interpolation, out, info );
		};
		for (unsigned int i2 = 0; i2 < uvGroups[i1].keys.size(); i2++) {
			NifStream( uvGroups[i1].keys[i2], out, info, uvGroups[i1].interpolation );
		};
	};
}

std::string NiUVData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		uvGroups[i1].numKeys = (unsigned int)(uvGroups[i1].keys.size());
		out << "    Num Keys:  " << uvGroups[i1].numKeys << endl;
		if ( (uvGroups[i1].numKeys != 0) ) {
			out << "      Interpolation:  " << uvGroups[i1].interpolation << endl;
		};
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < uvGroups[i1].keys.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Keys[" << i2 << "]:  " << uvGroups[i1].keys[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiUVData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiUVData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiVectorExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( vectorData, in, info );
	NifStream( unknownFloat, in, info );
}

void NiVectorExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	NifStream( vectorData, out, info );
	NifStream( unknownFloat, out, info );
}

std::string NiVectorExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Vector Data:  " << vectorData << endl;
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void NiVectorExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiVectorExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiVertexColorProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( vertexMode, in, info );
	NifStream( lightingMode, in, info );
}

void NiVertexColorProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
	NifStream( vertexMode, out, info );
	NifStream( lightingMode, out, info );
}

std::string NiVertexColorProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Vertex Mode:  " << vertexMode << endl;
	out << "  Lighting Mode:  " << lightingMode << endl;
	return out.str();
}

void NiVertexColorProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiVertexColorProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiVertWeightsExtraData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::Read( in, link_stack, info );
	NifStream( numBytes, in, info );
	NifStream( numVertices, in, info );
	weight.resize(numVertices);
	for (unsigned int i1 = 0; i1 < weight.size(); i1++) {
		NifStream( weight[i1], in, info );
	};
}

void NiVertWeightsExtraData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiExtraData::Write( out, link_map, info );
	numVertices = (unsigned short)(weight.size());
	NifStream( numBytes, out, info );
	NifStream( numVertices, out, info );
	for (unsigned int i1 = 0; i1 < weight.size(); i1++) {
		NifStream( weight[i1], out, info );
	};
}

std::string NiVertWeightsExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiExtraData::asString();
	numVertices = (unsigned short)(weight.size());
	out << "  Num Bytes:  " << numBytes << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < weight.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Weight[" << i1 << "]:  " << weight[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiVertWeightsExtraData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiExtraData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiVertWeightsExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiVisController::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	unsigned int block_num;
	NiSingleInterpolatorController::Read( in, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
}

void NiVisController::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiSingleInterpolatorController::Write( out, link_map, info );
	if ( info.version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map.find( StaticCast<NiObject>(data) )->second, out, info );
		else
			NifStream( 0xffffffff, out, info );
	};
}

std::string NiVisController::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiVisController::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, info );
	if ( info.version <= 0x0A010000 ) {
		data = FixLink<NiVisData>( objects, link_stack, info );
	};
}

std::list<NiObjectRef> NiVisController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiVisData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::Read( in, link_stack, info );
	NifStream( numVisKeys, in, info );
	visKeys.resize(numVisKeys);
	for (unsigned int i1 = 0; i1 < visKeys.size(); i1++) {
		NifStream( visKeys[i1], in, info, 1 );
	};
}

void NiVisData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	AKeyedData::Write( out, link_map, info );
	numVisKeys = (unsigned int)(visKeys.size());
	NifStream( numVisKeys, out, info );
	for (unsigned int i1 = 0; i1 < visKeys.size(); i1++) {
		NifStream( visKeys[i1], out, info, 1 );
	};
}

std::string NiVisData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << AKeyedData::asString();
	numVisKeys = (unsigned int)(visKeys.size());
	out << "  Num Vis Keys:  " << numVisKeys << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < visKeys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Vis Keys[" << i1 << "]:  " << visKeys[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void NiVisData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	AKeyedData::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiVisData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiWireframeProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
}

void NiWireframeProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
}

std::string NiWireframeProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiWireframeProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiWireframeProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiZBufferProperty::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );
	if ( info.version >= 0x0401000C ) {
		NifStream( function, in, info );
	};
}

void NiZBufferProperty::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );
	if ( info.version >= 0x0401000C ) {
		NifStream( function, out, info );
	};
}

std::string NiZBufferProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Function:  " << function << endl;
	return out.str();
}

void NiZBufferProperty::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiProperty::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiZBufferProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void RootCollisionNode::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::Read( in, link_stack, info );
}

void RootCollisionNode::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiNode::Write( out, link_map, info );
}

std::string RootCollisionNode::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	return out.str();
}

void RootCollisionNode::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiNode::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> RootCollisionNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void NiRawImageData::InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::Read( in, link_stack, info );
	NifStream( width, in, info );
	NifStream( height, in, info );
	NifStream( unknownInt, in, info );
	imageData.resize(width);
	for (unsigned int i1 = 0; i1 < imageData.size(); i1++) {
		imageData[i1].resize(height);
		for (unsigned int i2 = 0; i2 < imageData[i1].size(); i2++) {
			NifStream( imageData[i1][i2].r, in, info );
			NifStream( imageData[i1][i2].g, in, info );
			NifStream( imageData[i1][i2].b, in, info );
		};
	};
}

void NiRawImageData::InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	NiObject::Write( out, link_map, info );
	height = (unsigned int)((imageData.size() > 0) ? imageData[0].size() : 0);
	width = (unsigned int)(imageData.size());
	NifStream( width, out, info );
	NifStream( height, out, info );
	NifStream( unknownInt, out, info );
	for (unsigned int i1 = 0; i1 < imageData.size(); i1++) {
		for (unsigned int i2 = 0; i2 < imageData[i1].size(); i2++) {
			NifStream( imageData[i1][i2].r, out, info );
			NifStream( imageData[i1][i2].g, out, info );
			NifStream( imageData[i1][i2].b, out, info );
		};
	};
}

std::string NiRawImageData::InternalAsString( bool verbose ) const {
	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	height = (unsigned int)((imageData.size() > 0) ? imageData[0].size() : 0);
	width = (unsigned int)(imageData.size());
	out << "  Width:  " << width << endl;
	out << "  Height:  " << height << endl;
	out << "  Unknown Int:  " << unknownInt << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < imageData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (unsigned int i2 = 0; i2 < imageData[i1].size(); i2++) {
			out << "      r:  " << imageData[i1][i2].r << endl;
			out << "      g:  " << imageData[i1][i2].g << endl;
			out << "      b:  " << imageData[i1][i2].b << endl;
		};
	};
	return out.str();
}

void NiRawImageData::InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	NiObject::FixLinks( objects, link_stack, info );
}

std::list<NiObjectRef> NiRawImageData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

