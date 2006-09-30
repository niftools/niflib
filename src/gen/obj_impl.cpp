/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

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
#include "../../include/obj/NiControllerSequence.h"
#include "../../include/obj/NiDefaultAVObjectPalette.h"
#include "../../include/obj/NiDirectionalLight.h"
#include "../../include/obj/NiDitherProperty.h"
#include "../../include/obj/NiFlipController.h"
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

const char FIX_LINK_POP_ERROR[] = "Trying to pop a link from empty stack. This is probably a bug.";
const char FIX_LINK_INDEX_ERROR[] = "Object index was not found in object map.  This NIF file may be invalid or imporperly supported.";
const char FIX_LINK_CAST_ERROR[] = "Link could not be cast to required type during file read. This NIF file may be invalid or improperly supported.";

template <class T>
Ref<T> FixLink( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned version ) {
	if (link_stack.empty()) {
		throw runtime_error(FIX_LINK_POP_ERROR);
	}
	unsigned index = link_stack.front();
	link_stack.pop_front();

	//Check if link is NULL
	if ( index == 0xFFFFFFFF) {
		return NULL;
	}

	map<unsigned,NiObjectRef>::const_iterator it = objects.find(index);
	if ( it == objects.end() ) {
		throw runtime_error(FIX_LINK_INDEX_ERROR);
	}
		
	Ref<T> object = DynamicCast<T>(it->second);
	if ( object == NULL ) {
		throw runtime_error(FIX_LINK_CAST_ERROR);
	}

	return object;
}

void NiObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
}

void NiObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
}

std::string NiObject::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	return out.str();
}

void NiObject::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
}

std::list<NiObjectRef> NiObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	return refs;
}

void AKeyedData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
}

void AKeyedData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
}

std::string AKeyedData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	return out.str();
}

void AKeyedData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> AKeyedData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void AParticleModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void AParticleModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	if ( nextModifier != NULL )
		NifStream( link_map[StaticCast<NiObject>(nextModifier)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( controller != NULL )
		NifStream( link_map[StaticCast<NiObject>(controller)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string AParticleModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	out << "  Next Modifier:  " << nextModifier << endl;
	out << "  Controller:  " << controller << endl;
	return out.str();
}

void AParticleModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	nextModifier = FixLink<AParticleModifier>( objects, link_stack, version );
	controller = FixLink<NiParticleSystemController>( objects, link_stack, version );
}

std::list<NiObjectRef> AParticleModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextModifier != NULL )
		refs.push_back(StaticCast<NiObject>(nextModifier));
	return refs;
}

void bhkRefObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
}

void bhkRefObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
}

std::string bhkRefObject::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	return out.str();
}

void bhkRefObject::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkRefObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void bhkSerializable::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkRefObject::Read( in, link_stack, version, user_version );
}

void bhkSerializable::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkRefObject::Write( out, link_map, version, user_version );
}

std::string bhkSerializable::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkRefObject::asString();
	return out.str();
}

void bhkSerializable::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkRefObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkSerializable::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkRefObject::GetRefs();
	return refs;
}

void AbhkConstraint::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	bhkSerializable::Read( in, link_stack, version, user_version );
	NifStream( numBodies, in, version );
	bodies.resize(numBodies);
	for (uint i1 = 0; i1 < bodies.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( priority, in, version );
}

void AbhkConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkSerializable::Write( out, link_map, version, user_version );
	numBodies = uint(bodies.size());
	NifStream( numBodies, out, version );
	for (uint i1 = 0; i1 < bodies.size(); i1++) {
		if ( bodies[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(bodies[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	NifStream( priority, out, version );
}

std::string AbhkConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkSerializable::asString();
	numBodies = uint(bodies.size());
	out << "  Num Bodies:  " << numBodies << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < bodies.size(); i1++) {
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

void AbhkConstraint::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSerializable::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < bodies.size(); i1++) {
		bodies[i1] = FixLink<bhkShape>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> AbhkConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSerializable::GetRefs();
	for (uint i1 = 0; i1 < bodies.size(); i1++) {
	};
	return refs;
}

void AbhkRagdollConstraint::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::Read( in, link_stack, version, user_version );
	NifStream( pivotA, in, version );
	NifStream( planeA, in, version );
	NifStream( twistA, in, version );
	NifStream( pivotB, in, version );
	NifStream( planeB, in, version );
	NifStream( twistB, in, version );
	NifStream( coneMinAngle, in, version );
	NifStream( planeMinAngle, in, version );
	NifStream( planeMaxAngle, in, version );
	NifStream( twistMinAngle, in, version );
	NifStream( twistMaxAngle, in, version );
	NifStream( maxFriction, in, version );
}

void AbhkRagdollConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkConstraint::Write( out, link_map, version, user_version );
	NifStream( pivotA, out, version );
	NifStream( planeA, out, version );
	NifStream( twistA, out, version );
	NifStream( pivotB, out, version );
	NifStream( planeB, out, version );
	NifStream( twistB, out, version );
	NifStream( coneMinAngle, out, version );
	NifStream( planeMinAngle, out, version );
	NifStream( planeMaxAngle, out, version );
	NifStream( twistMinAngle, out, version );
	NifStream( twistMaxAngle, out, version );
	NifStream( maxFriction, out, version );
}

std::string AbhkRagdollConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AbhkConstraint::asString();
	out << "  Pivot A:  " << pivotA << endl;
	out << "  Plane A:  " << planeA << endl;
	out << "  Twist A:  " << twistA << endl;
	out << "  Pivot B:  " << pivotB << endl;
	out << "  Plane B:  " << planeB << endl;
	out << "  Twist B:  " << twistB << endl;
	out << "  Cone Min Angle:  " << coneMinAngle << endl;
	out << "  Plane Min Angle:  " << planeMinAngle << endl;
	out << "  Plane Max Angle:  " << planeMaxAngle << endl;
	out << "  Twist Min Angle:  " << twistMinAngle << endl;
	out << "  Twist Max Angle:  " << twistMaxAngle << endl;
	out << "  Max Friction:  " << maxFriction << endl;
	return out.str();
}

void AbhkRagdollConstraint::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> AbhkRagdollConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSerializable::Read( in, link_stack, version, user_version );
}

void bhkShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkSerializable::Write( out, link_map, version, user_version );
}

std::string bhkShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkSerializable::asString();
	return out.str();
}

void bhkShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSerializable::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSerializable::GetRefs();
	return refs;
}

void AbhkShapeCollection::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkShape::Read( in, link_stack, version, user_version );
}

void AbhkShapeCollection::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkShape::Write( out, link_map, version, user_version );
}

std::string AbhkShapeCollection::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkShape::asString();
	return out.str();
}

void AbhkShapeCollection::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> AbhkShapeCollection::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	return refs;
}

void bhkSphereRepShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkShape::Read( in, link_stack, version, user_version );
	NifStream( material, in, version );
}

void bhkSphereRepShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkShape::Write( out, link_map, version, user_version );
	NifStream( material, out, version );
}

std::string bhkSphereRepShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkShape::asString();
	out << "  Material:  " << material << endl;
	return out.str();
}

void bhkSphereRepShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkSphereRepShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	return refs;
}

void bhkConvexShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSphereRepShape::Read( in, link_stack, version, user_version );
}

void bhkConvexShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkSphereRepShape::Write( out, link_map, version, user_version );
}

std::string bhkConvexShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkSphereRepShape::asString();
	return out.str();
}

void bhkConvexShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkConvexShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	return refs;
}

void bhkWorldObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkShape::Read( in, link_stack, version, user_version );
}

void bhkWorldObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkShape::Write( out, link_map, version, user_version );
}

std::string bhkWorldObject::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkShape::asString();
	return out.str();
}

void bhkWorldObject::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkWorldObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	return refs;
}

void bhkEntity::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	bhkWorldObject::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( layer, in, version );
	NifStream( colFilter, in, version );
	NifStream( unknownShort, in, version );
}

void bhkEntity::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkWorldObject::Write( out, link_map, version, user_version );
	if ( shape != NULL )
		NifStream( link_map[StaticCast<NiObject>(shape)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( layer, out, version );
	NifStream( colFilter, out, version );
	NifStream( unknownShort, out, version );
}

std::string bhkEntity::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkWorldObject::asString();
	out << "  Shape:  " << shape << endl;
	out << "  Layer:  " << layer << endl;
	out << "  Col Filter:  " << colFilter << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	return out.str();
}

void bhkEntity::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkWorldObject::FixLinks( objects, link_stack, version, user_version );
	shape = FixLink<bhkShape>( objects, link_stack, version );
}

std::list<NiObjectRef> bhkEntity::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkWorldObject::GetRefs();
	if ( shape != NULL )
		refs.push_back(StaticCast<NiObject>(shape));
	return refs;
}

void NiCollisionObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( unknownShort, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiCollisionObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	if ( parent != NULL )
		NifStream( link_map[StaticCast<NiObject>(parent)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( unknownShort, out, version );
	if ( body != NULL )
		NifStream( link_map[StaticCast<NiObject>(body)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiCollisionObject::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	out << "  Parent:  " << parent << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Body:  " << body << endl;
	return out.str();
}

void NiCollisionObject::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	parent = FixLink<NiAVObject>( objects, link_stack, version );
	body = FixLink<NiObject>( objects, link_stack, version );
}

std::list<NiObjectRef> NiCollisionObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( body != NULL )
		refs.push_back(StaticCast<NiObject>(body));
	return refs;
}

void NiExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A000100 ) {
		NifStream( name, in, version );
	};
	if ( version <= 0x04020200 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	if ( version >= 0x0A000100 ) {
		NifStream( name, out, version );
	};
	if ( version <= 0x04020200 ) {
		if ( nextExtraData != NULL )
			NifStream( link_map[StaticCast<NiObject>(nextExtraData)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	out << "  Name:  " << name << endl;
	out << "  Next Extra Data:  " << nextExtraData << endl;
	return out.str();
}

void NiExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x04020200 ) {
		nextExtraData = FixLink<NiExtraData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextExtraData != NULL )
		refs.push_back(StaticCast<NiObject>(nextExtraData));
	return refs;
}

void NiInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
}

void NiInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
}

std::string NiInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	return out.str();
}

void NiInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiBlendInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( unknownShort, in, version );
	NifStream( unknownInt, in, version );
}

void NiBlendInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( unknownShort, out, version );
	NifStream( unknownInt, out, version );
}

std::string NiBlendInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void NiBlendInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBlendInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	return refs;
}

void NiBSplineInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( startTime, in, version );
	NifStream( stopTime, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiBSplineInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( startTime, out, version );
	NifStream( stopTime, out, version );
	if ( splineData != NULL )
		NifStream( link_map[StaticCast<NiObject>(splineData)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( basisData != NULL )
		NifStream( link_map[StaticCast<NiObject>(basisData)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiBSplineInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Start Time:  " << startTime << endl;
	out << "  Stop Time:  " << stopTime << endl;
	out << "  Spline Data:  " << splineData << endl;
	out << "  Basis Data:  " << basisData << endl;
	return out.str();
}

void NiBSplineInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	splineData = FixLink<NiBSplineData>( objects, link_stack, version );
	basisData = FixLink<NiBSplineBasisData>( objects, link_stack, version );
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

void NiObjectNET::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( name, in, version );
	if ( version <= 0x04020200 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	if ( version >= 0x0A000100 ) {
		NifStream( numExtraDataList, in, version );
		extraDataList.resize(numExtraDataList);
		for (uint i2 = 0; i2 < extraDataList.size(); i2++) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiObjectNET::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numExtraDataList = uint(extraDataList.size());
	NifStream( name, out, version );
	if ( version <= 0x04020200 ) {
		if ( extraData != NULL )
			NifStream( link_map[StaticCast<NiObject>(extraData)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( version >= 0x0A000100 ) {
		NifStream( numExtraDataList, out, version );
		for (uint i2 = 0; i2 < extraDataList.size(); i2++) {
			if ( extraDataList[i2] != NULL )
				NifStream( link_map[StaticCast<NiObject>(extraDataList[i2])], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
	if ( controller != NULL )
		NifStream( link_map[StaticCast<NiObject>(controller)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiObjectNET::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numExtraDataList = uint(extraDataList.size());
	out << "  Name:  " << name << endl;
	out << "  Extra Data:  " << extraData << endl;
	out << "  Num Extra Data List:  " << numExtraDataList << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < extraDataList.size(); i1++) {
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

void NiObjectNET::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x04020200 ) {
		extraData = FixLink<NiExtraData>( objects, link_stack, version );
	};
	if ( version >= 0x0A000100 ) {
		for (uint i2 = 0; i2 < extraDataList.size(); i2++) {
			extraDataList[i2] = FixLink<NiExtraData>( objects, link_stack, version );
		};
	};
	controller = FixLink<NiTimeController>( objects, link_stack, version );
}

std::list<NiObjectRef> NiObjectNET::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( extraData != NULL )
		refs.push_back(StaticCast<NiObject>(extraData));
	for (uint i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( extraDataList[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(extraDataList[i1]));
	};
	if ( controller != NULL )
		refs.push_back(StaticCast<NiObject>(controller));
	return refs;
}

void NiAVObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObjectNET::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
	NifStream( translation, in, version );
	NifStream( rotation, in, version );
	NifStream( scale, in, version );
	if ( version <= 0x04020200 ) {
		NifStream( velocity, in, version );
	};
	NifStream( numProperties, in, version );
	properties.resize(numProperties);
	for (uint i1 = 0; i1 < properties.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	if ( version <= 0x04020200 ) {
		NifStream( hasBoundingBox, in, version );
		if ( (hasBoundingBox != 0) ) {
			NifStream( boundingBox.unknownInt, in, version );
			NifStream( boundingBox.translation, in, version );
			NifStream( boundingBox.rotation, in, version );
			NifStream( boundingBox.radius, in, version );
		};
	};
	if ( ( version >= 0x0A000100 ) && ( version <= 0x0A020000 ) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	if ( version >= 0x14000004 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiAVObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObjectNET::Write( out, link_map, version, user_version );
	numProperties = uint(properties.size());
	NifStream( flags, out, version );
	NifStream( translation, out, version );
	NifStream( rotation, out, version );
	NifStream( scale, out, version );
	if ( version <= 0x04020200 ) {
		NifStream( velocity, out, version );
	};
	NifStream( numProperties, out, version );
	for (uint i1 = 0; i1 < properties.size(); i1++) {
		if ( properties[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(properties[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( version <= 0x04020200 ) {
		NifStream( hasBoundingBox, out, version );
		if ( (hasBoundingBox != 0) ) {
			NifStream( boundingBox.unknownInt, out, version );
			NifStream( boundingBox.translation, out, version );
			NifStream( boundingBox.rotation, out, version );
			NifStream( boundingBox.radius, out, version );
		};
	};
	if ( ( version >= 0x0A000100 ) && ( version <= 0x0A020000 ) ) {
		if ( collisionData != NULL )
			NifStream( link_map[StaticCast<NiObject>(collisionData)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( version >= 0x14000004 ) {
		if ( collisionObject != NULL )
			NifStream( link_map[StaticCast<NiObject>(collisionObject)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiAVObject::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObjectNET::asString();
	numProperties = uint(properties.size());
	out << "  Flags:  " << flags << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Velocity:  " << velocity << endl;
	out << "  Num Properties:  " << numProperties << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < properties.size(); i1++) {
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

void NiAVObject::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObjectNET::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < properties.size(); i1++) {
		properties[i1] = FixLink<NiProperty>( objects, link_stack, version );
	};
	if ( ( version >= 0x0A000100 ) && ( version <= 0x0A020000 ) ) {
		collisionData = FixLink<NiCollisionData>( objects, link_stack, version );
	};
	if ( version >= 0x14000004 ) {
		collisionObject = FixLink<NiCollisionObject>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiAVObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	for (uint i1 = 0; i1 < properties.size(); i1++) {
		if ( properties[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(properties[i1]));
	};
	if ( collisionData != NULL )
		refs.push_back(StaticCast<NiObject>(collisionData));
	if ( collisionObject != NULL )
		refs.push_back(StaticCast<NiObject>(collisionObject));
	return refs;
}

void NiDynamicEffect::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiAVObject::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A020000 ) {
		NifStream( switchState, in, version );
	};
	if ( version <= 0x04000002 ) {
		NifStream( numAffectedNodes, in, version );
		affectedNodeListPointers.resize(numAffectedNodes);
		for (uint i2 = 0; i2 < affectedNodeListPointers.size(); i2++) {
			NifStream( affectedNodeListPointers[i2], in, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		NifStream( numAffectedNodes, in, version );
		affectedNodes.resize(numAffectedNodes);
		for (uint i2 = 0; i2 < affectedNodes.size(); i2++) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
}

void NiDynamicEffect::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiAVObject::Write( out, link_map, version, user_version );
	numAffectedNodes = uint(affectedNodeListPointers.size());
	if ( version >= 0x0A020000 ) {
		NifStream( switchState, out, version );
	};
	if ( version <= 0x04000002 ) {
		NifStream( numAffectedNodes, out, version );
		for (uint i2 = 0; i2 < affectedNodeListPointers.size(); i2++) {
			NifStream( affectedNodeListPointers[i2], out, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		NifStream( numAffectedNodes, out, version );
		for (uint i2 = 0; i2 < affectedNodes.size(); i2++) {
			if ( affectedNodes[i2] != NULL )
				NifStream( link_map[StaticCast<NiObject>(affectedNodes[i2])], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
}

std::string NiDynamicEffect::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiAVObject::asString();
	numAffectedNodes = uint(affectedNodeListPointers.size());
	out << "  Switch State:  " << switchState << endl;
	out << "  Num Affected Nodes:  " << numAffectedNodes << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < affectedNodeListPointers.size(); i1++) {
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
	for (uint i1 = 0; i1 < affectedNodes.size(); i1++) {
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

void NiDynamicEffect::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAVObject::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		for (uint i2 = 0; i2 < affectedNodes.size(); i2++) {
			affectedNodes[i2] = FixLink<NiAVObject>( objects, link_stack, version );
		};
	};
}

std::list<NiObjectRef> NiDynamicEffect::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	for (uint i1 = 0; i1 < affectedNodes.size(); i1++) {
		if ( affectedNodes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(affectedNodes[i1]));
	};
	return refs;
}

void NiLight::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiDynamicEffect::Read( in, link_stack, version, user_version );
	NifStream( dimmer, in, version );
	NifStream( ambientColor, in, version );
	NifStream( diffuseColor, in, version );
	NifStream( specularColor, in, version );
}

void NiLight::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiDynamicEffect::Write( out, link_map, version, user_version );
	NifStream( dimmer, out, version );
	NifStream( ambientColor, out, version );
	NifStream( diffuseColor, out, version );
	NifStream( specularColor, out, version );
}

std::string NiLight::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiDynamicEffect::asString();
	out << "  Dimmer:  " << dimmer << endl;
	out << "  Ambient Color:  " << ambientColor << endl;
	out << "  Diffuse Color:  " << diffuseColor << endl;
	out << "  Specular Color:  " << specularColor << endl;
	return out.str();
}

void NiLight::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiDynamicEffect::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiDynamicEffect::GetRefs();
	return refs;
}

void NiProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObjectNET::Read( in, link_stack, version, user_version );
}

void NiProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObjectNET::Write( out, link_map, version, user_version );
}

std::string NiProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObjectNET::asString();
	return out.str();
}

void NiProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObjectNET::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	return refs;
}

void NiPSysModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( name, in, version );
	NifStream( order, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( active, in, version );
}

void NiPSysModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	NifStream( name, out, version );
	NifStream( order, out, version );
	if ( target != NULL )
		NifStream( link_map[StaticCast<NiObject>(target)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( active, out, version );
}

std::string NiPSysModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	out << "  Name:  " << name << endl;
	out << "  Order:  " << order << endl;
	out << "  Target:  " << target << endl;
	out << "  Active:  " << active << endl;
	return out.str();
}

void NiPSysModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	target = FixLink<NiParticleSystem>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPSysModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiPSysEmitter::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( speed, in, version );
	NifStream( speedVariation, in, version );
	NifStream( declination, in, version );
	NifStream( declinationVariation, in, version );
	NifStream( planarAngle, in, version );
	NifStream( planarAngleVariation, in, version );
	NifStream( initialColor, in, version );
	NifStream( initialRadius, in, version );
	if ( version >= 0x14000004 ) {
		NifStream( radiusVariation, in, version );
	};
	NifStream( lifeSpan, in, version );
	NifStream( lifeSpanVariation, in, version );
}

void NiPSysEmitter::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	NifStream( speed, out, version );
	NifStream( speedVariation, out, version );
	NifStream( declination, out, version );
	NifStream( declinationVariation, out, version );
	NifStream( planarAngle, out, version );
	NifStream( planarAngleVariation, out, version );
	NifStream( initialColor, out, version );
	NifStream( initialRadius, out, version );
	if ( version >= 0x14000004 ) {
		NifStream( radiusVariation, out, version );
	};
	NifStream( lifeSpan, out, version );
	NifStream( lifeSpanVariation, out, version );
}

std::string NiPSysEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiPSysEmitter::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysVolumeEmitter::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysEmitter::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiPSysVolumeEmitter::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysEmitter::Write( out, link_map, version, user_version );
	if ( version >= 0x0A010000 ) {
		if ( emitterObject != NULL )
			NifStream( link_map[StaticCast<NiObject>(emitterObject)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiPSysVolumeEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysEmitter::asString();
	out << "  Emitter Object:  " << emitterObject << endl;
	return out.str();
}

void NiPSysVolumeEmitter::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysEmitter::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		emitterObject = FixLink<NiNode>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiPSysVolumeEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysEmitter::GetRefs();
	return refs;
}

void NiTimeController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( flags, in, version );
	NifStream( frequency, in, version );
	NifStream( phase, in, version );
	NifStream( startTime, in, version );
	NifStream( stopTime, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiTimeController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	if ( nextController != NULL )
		NifStream( link_map[StaticCast<NiObject>(nextController)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( flags, out, version );
	NifStream( frequency, out, version );
	NifStream( phase, out, version );
	NifStream( startTime, out, version );
	NifStream( stopTime, out, version );
	if ( target != NULL )
		NifStream( link_map[StaticCast<NiObject>(target)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiTimeController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiTimeController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	nextController = FixLink<NiTimeController>( objects, link_stack, version );
	target = FixLink<NiObjectNET>( objects, link_stack, version );
}

std::list<NiObjectRef> NiTimeController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( nextController != NULL )
		refs.push_back(StaticCast<NiObject>(nextController));
	return refs;
}

void ABoneLODController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	NifStream( unknownInt1, in, version );
	NifStream( numNodeGroups, in, version );
	NifStream( numNodeGroups2, in, version );
	nodeGroups.resize(numNodeGroups);
	for (uint i1 = 0; i1 < nodeGroups.size(); i1++) {
		NifStream( nodeGroups[i1].numNodes, in, version );
		nodeGroups[i1].nodes.resize(nodeGroups[i1].numNodes);
		for (uint i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
}

void ABoneLODController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	numNodeGroups = uint(nodeGroups.size());
	NifStream( unknownInt1, out, version );
	NifStream( numNodeGroups, out, version );
	NifStream( numNodeGroups2, out, version );
	for (uint i1 = 0; i1 < nodeGroups.size(); i1++) {
		nodeGroups[i1].numNodes = uint(nodeGroups[i1].nodes.size());
		NifStream( nodeGroups[i1].numNodes, out, version );
		for (uint i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			if ( nodeGroups[i1].nodes[i2] != NULL )
				NifStream( link_map[StaticCast<NiObject>(nodeGroups[i1].nodes[i2])], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
}

std::string ABoneLODController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	numNodeGroups = uint(nodeGroups.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Num Node Groups:  " << numNodeGroups << endl;
	out << "  Num Node Groups 2:  " << numNodeGroups2 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < nodeGroups.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		nodeGroups[i1].numNodes = uint(nodeGroups[i1].nodes.size());
		out << "    Num Nodes:  " << nodeGroups[i1].numNodes << endl;
		array_output_count = 0;
		for (uint i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
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

void ABoneLODController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < nodeGroups.size(); i1++) {
		for (uint i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			nodeGroups[i1].nodes[i2] = FixLink<NiNode>( objects, link_stack, version );
		};
	};
}

std::list<NiObjectRef> ABoneLODController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	for (uint i1 = 0; i1 < nodeGroups.size(); i1++) {
		for (uint i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
		};
	};
	return refs;
}

void NiSingleInterpolatorController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A020000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiSingleInterpolatorController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	if ( version >= 0x0A020000 ) {
		if ( interpolator != NULL )
			NifStream( link_map[StaticCast<NiObject>(interpolator)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiSingleInterpolatorController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Interpolator:  " << interpolator << endl;
	return out.str();
}

void NiSingleInterpolatorController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A020000 ) {
		interpolator = FixLink<NiInterpolator>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiSingleInterpolatorController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( interpolator != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator));
	return refs;
}

void APSysCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::Read( in, link_stack, version, user_version );
	NifStream( modifierName, in, version );
}

void APSysCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSingleInterpolatorController::Write( out, link_map, version, user_version );
	NifStream( modifierName, out, version );
}

std::string APSysCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Modifier Name:  " << modifierName << endl;
	return out.str();
}

void APSysCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> APSysCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	return refs;
}

void NiGeometry::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiAVObject::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	if ( version >= 0x0303000D ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	if ( version >= 0x0A000100 ) {
		NifStream( hasShader, in, version );
		if ( (hasShader != 0) ) {
			NifStream( shaderName, in, version );
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
}

void NiGeometry::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiAVObject::Write( out, link_map, version, user_version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( version >= 0x0303000D ) {
		if ( skinInstance != NULL )
			NifStream( link_map[StaticCast<NiObject>(skinInstance)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( version >= 0x0A000100 ) {
		NifStream( hasShader, out, version );
		if ( (hasShader != 0) ) {
			NifStream( shaderName, out, version );
			if ( unknownLink != NULL )
				NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
}

std::string NiGeometry::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiGeometry::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAVObject::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiGeometryData>( objects, link_stack, version );
	if ( version >= 0x0303000D ) {
		skinInstance = FixLink<NiSkinInstance>( objects, link_stack, version );
	};
	if ( version >= 0x0A000100 ) {
		if ( (hasShader != 0) ) {
			unknownLink = FixLink<NiObject>( objects, link_stack, version );
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

void NiTriBasedGeom::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometry::Read( in, link_stack, version, user_version );
}

void NiTriBasedGeom::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiGeometry::Write( out, link_map, version, user_version );
}

std::string NiTriBasedGeom::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiGeometry::asString();
	return out.str();
}

void NiTriBasedGeom::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometry::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriBasedGeom::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometry::GetRefs();
	return refs;
}

void NiGeometryData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A020000 ) {
		NifStream( name, in, version );
	};
	NifStream( numVertices, in, version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknownShort1, in, version );
	};
	NifStream( hasVertices, in, version );
	if ( (hasVertices != 0) ) {
		vertices.resize(numVertices);
		for (uint i2 = 0; i2 < vertices.size(); i2++) {
			NifStream( vertices[i2], in, version );
		};
	};
	if ( version >= 0x0A000100 ) {
		NifStream( numUvSets2, in, version );
		NifStream( unknownByte, in, version );
	};
	NifStream( hasNormals, in, version );
	if ( (hasNormals != 0) ) {
		normals.resize(numVertices);
		for (uint i2 = 0; i2 < normals.size(); i2++) {
			NifStream( normals[i2], in, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) {
			unknownVectors1.resize(numVertices);
			for (uint i3 = 0; i3 < unknownVectors1.size(); i3++) {
				NifStream( unknownVectors1[i3], in, version );
			};
			unknownVectors2.resize(numVertices);
			for (uint i3 = 0; i3 < unknownVectors2.size(); i3++) {
				NifStream( unknownVectors2[i3], in, version );
			};
		};
	};
	NifStream( center, in, version );
	NifStream( radius, in, version );
	NifStream( hasVertexColors, in, version );
	if ( (hasVertexColors != 0) ) {
		vertexColors.resize(numVertices);
		for (uint i2 = 0; i2 < vertexColors.size(); i2++) {
			NifStream( vertexColors[i2], in, version );
		};
	};
	if ( version <= 0x04020200 ) {
		NifStream( numUvSets, in, version );
	};
	if ( version <= 0x04000002 ) {
		NifStream( hasUv, in, version );
	};
	if ( version <= 0x04020200 ) {
		uvSets.resize(numUvSets);
		for (uint i2 = 0; i2 < uvSets.size(); i2++) {
			uvSets[i2].resize(numVertices);
			for (uint i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], in, version );
			};
		};
	};
	if ( version >= 0x0A000100 ) {
		uvSets.resize((numUvSets2 & 63));
		for (uint i2 = 0; i2 < uvSets.size(); i2++) {
			uvSets[i2].resize(numVertices);
			for (uint i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], in, version );
			};
		};
		NifStream( unknownShort2, in, version );
	};
	if ( version >= 0x14000004 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiGeometryData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numUvSets = ushort(uvSets.size());
	numUvSets2 = byte(uvSets.size());
	numVertices = ushort(vertices.size());
	if ( version >= 0x0A020000 ) {
		NifStream( name, out, version );
	};
	NifStream( numVertices, out, version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknownShort1, out, version );
	};
	NifStream( hasVertices, out, version );
	if ( (hasVertices != 0) ) {
		for (uint i2 = 0; i2 < vertices.size(); i2++) {
			NifStream( vertices[i2], out, version );
		};
	};
	if ( version >= 0x0A000100 ) {
		NifStream( numUvSets2, out, version );
		NifStream( unknownByte, out, version );
	};
	NifStream( hasNormals, out, version );
	if ( (hasNormals != 0) ) {
		for (uint i2 = 0; i2 < normals.size(); i2++) {
			NifStream( normals[i2], out, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) {
			for (uint i3 = 0; i3 < unknownVectors1.size(); i3++) {
				NifStream( unknownVectors1[i3], out, version );
			};
			for (uint i3 = 0; i3 < unknownVectors2.size(); i3++) {
				NifStream( unknownVectors2[i3], out, version );
			};
		};
	};
	NifStream( center, out, version );
	NifStream( radius, out, version );
	NifStream( hasVertexColors, out, version );
	if ( (hasVertexColors != 0) ) {
		for (uint i2 = 0; i2 < vertexColors.size(); i2++) {
			NifStream( vertexColors[i2], out, version );
		};
	};
	if ( version <= 0x04020200 ) {
		NifStream( numUvSets, out, version );
	};
	if ( version <= 0x04000002 ) {
		NifStream( hasUv, out, version );
	};
	if ( version <= 0x04020200 ) {
		for (uint i2 = 0; i2 < uvSets.size(); i2++) {
			for (uint i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], out, version );
			};
		};
	};
	if ( version >= 0x0A000100 ) {
		for (uint i2 = 0; i2 < uvSets.size(); i2++) {
			for (uint i3 = 0; i3 < uvSets[i2].size(); i3++) {
				NifStream( uvSets[i2][i3], out, version );
			};
		};
		NifStream( unknownShort2, out, version );
	};
	if ( version >= 0x14000004 ) {
		if ( unknownLink != NULL )
			NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiGeometryData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numUvSets = ushort(uvSets.size());
	numUvSets2 = byte(uvSets.size());
	numVertices = ushort(vertices.size());
	out << "  Name:  " << name << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Has Vertices:  " << hasVertices << endl;
	if ( (hasVertices != 0) ) {
		array_output_count = 0;
		for (uint i2 = 0; i2 < vertices.size(); i2++) {
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
		for (uint i2 = 0; i2 < normals.size(); i2++) {
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
		for (uint i2 = 0; i2 < unknownVectors1.size(); i2++) {
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
		for (uint i2 = 0; i2 < unknownVectors2.size(); i2++) {
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
		for (uint i2 = 0; i2 < vertexColors.size(); i2++) {
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
	for (uint i1 = 0; i1 < uvSets.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < uvSets[i1].size(); i2++) {
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

void NiGeometryData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x14000004 ) {
		unknownLink = FixLink<NiObject>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiGeometryData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiTriBasedGeomData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometryData::Read( in, link_stack, version, user_version );
	NifStream( numTriangles, in, version );
}

void NiTriBasedGeomData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiGeometryData::Write( out, link_map, version, user_version );
	NifStream( numTriangles, out, version );
}

std::string NiTriBasedGeomData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiGeometryData::asString();
	out << "  Num Triangles:  " << numTriangles << endl;
	return out.str();
}

void NiTriBasedGeomData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometryData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriBasedGeomData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometryData::GetRefs();
	return refs;
}

void APSysData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometryData::Read( in, link_stack, version, user_version );
	NifStream( hasUnknownFloats1, in, version );
	if ( (hasUnknownFloats1 != 0) ) {
		unknownFloats1.resize(numVertices);
		for (uint i2 = 0; i2 < unknownFloats1.size(); i2++) {
			NifStream( unknownFloats1[i2], in, version );
		};
	};
	NifStream( unknownShort3, in, version );
	NifStream( hasUnknownFloats2, in, version );
	if ( (hasUnknownFloats2 != 0) ) {
		unknownFloats2.resize(numVertices);
		for (uint i2 = 0; i2 < unknownFloats2.size(); i2++) {
			NifStream( unknownFloats2[i2], in, version );
		};
	};
	NifStream( hasUnknownFloats3, in, version );
	if ( (hasUnknownFloats3 != 0) ) {
		unknownFloats3.resize(numVertices);
		for (uint i2 = 0; i2 < unknownFloats3.size(); i2++) {
			for (uint i3 = 0; i3 < 4; i3++) {
				NifStream( unknownFloats3[i2][i3], in, version );
			};
		};
	};
}

void APSysData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiGeometryData::Write( out, link_map, version, user_version );
	NifStream( hasUnknownFloats1, out, version );
	if ( (hasUnknownFloats1 != 0) ) {
		for (uint i2 = 0; i2 < unknownFloats1.size(); i2++) {
			NifStream( unknownFloats1[i2], out, version );
		};
	};
	NifStream( unknownShort3, out, version );
	NifStream( hasUnknownFloats2, out, version );
	if ( (hasUnknownFloats2 != 0) ) {
		for (uint i2 = 0; i2 < unknownFloats2.size(); i2++) {
			NifStream( unknownFloats2[i2], out, version );
		};
	};
	NifStream( hasUnknownFloats3, out, version );
	if ( (hasUnknownFloats3 != 0) ) {
		for (uint i2 = 0; i2 < unknownFloats3.size(); i2++) {
			for (uint i3 = 0; i3 < 4; i3++) {
				NifStream( unknownFloats3[i2][i3], out, version );
			};
		};
	};
}

std::string APSysData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiGeometryData::asString();
	out << "  Has Unknown Floats 1:  " << hasUnknownFloats1 << endl;
	if ( (hasUnknownFloats1 != 0) ) {
		array_output_count = 0;
		for (uint i2 = 0; i2 < unknownFloats1.size(); i2++) {
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
		for (uint i2 = 0; i2 < unknownFloats2.size(); i2++) {
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
		for (uint i2 = 0; i2 < unknownFloats3.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (uint i3 = 0; i3 < 4; i3++) {
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

void APSysData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometryData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> APSysData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometryData::GetRefs();
	return refs;
}

void bhkBlendCollisionObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiCollisionObject::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownFloat2, in, version );
}

void bhkBlendCollisionObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiCollisionObject::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownFloat2, out, version );
}

std::string bhkBlendCollisionObject::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiCollisionObject::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	return out.str();
}

void bhkBlendCollisionObject::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiCollisionObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkBlendCollisionObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiCollisionObject::GetRefs();
	return refs;
}

void bhkBlendController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::Read( in, link_stack, version, user_version );
	NifStream( unknownInt, in, version );
}

void bhkBlendController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	NifStream( unknownInt, out, version );
}

std::string bhkBlendController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void bhkBlendController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkBlendController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	return refs;
}

void bhkBoxShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkConvexShape::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownShort1, in, version );
	NifStream( unknownShort2, in, version );
	NifStream( unknownShort3, in, version );
	NifStream( unknownShort4, in, version );
	NifStream( dimensions, in, version );
	NifStream( unknownFloat2, in, version );
}

void bhkBoxShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkConvexShape::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownShort1, out, version );
	NifStream( unknownShort2, out, version );
	NifStream( unknownShort3, out, version );
	NifStream( unknownShort4, out, version );
	NifStream( dimensions, out, version );
	NifStream( unknownFloat2, out, version );
}

std::string bhkBoxShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkConvexShape::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  Dimensions:  " << dimensions << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	return out.str();
}

void bhkBoxShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkConvexShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkBoxShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConvexShape::GetRefs();
	return refs;
}

void bhkCapsuleShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkConvexShape::Read( in, link_stack, version, user_version );
	NifStream( radius, in, version );
	NifStream( unknownShort1, in, version );
	NifStream( unknownShort2, in, version );
	NifStream( unknownShort3, in, version );
	NifStream( unknownShort4, in, version );
	NifStream( firstPoint, in, version );
	NifStream( radius1, in, version );
	NifStream( secondPoint, in, version );
	NifStream( radius2, in, version );
}

void bhkCapsuleShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkConvexShape::Write( out, link_map, version, user_version );
	NifStream( radius, out, version );
	NifStream( unknownShort1, out, version );
	NifStream( unknownShort2, out, version );
	NifStream( unknownShort3, out, version );
	NifStream( unknownShort4, out, version );
	NifStream( firstPoint, out, version );
	NifStream( radius1, out, version );
	NifStream( secondPoint, out, version );
	NifStream( radius2, out, version );
}

std::string bhkCapsuleShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void bhkCapsuleShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkConvexShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkCapsuleShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConvexShape::GetRefs();
	return refs;
}

void bhkCollisionObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiCollisionObject::Read( in, link_stack, version, user_version );
}

void bhkCollisionObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiCollisionObject::Write( out, link_map, version, user_version );
}

std::string bhkCollisionObject::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiCollisionObject::asString();
	return out.str();
}

void bhkCollisionObject::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiCollisionObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkCollisionObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiCollisionObject::GetRefs();
	return refs;
}

void bhkConvexVerticesShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSphereRepShape::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 7; i1++) {
		NifStream( unknownFloats1[i1], in, version );
	};
	NifStream( num1, in, version );
	unknownVectors1.resize(num1);
	for (uint i1 = 0; i1 < unknownVectors1.size(); i1++) {
		NifStream( unknownVectors1[i1], in, version );
	};
	NifStream( num2, in, version );
	unknownVectors2.resize(num2);
	for (uint i1 = 0; i1 < unknownVectors2.size(); i1++) {
		NifStream( unknownVectors2[i1], in, version );
	};
}

void bhkConvexVerticesShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkSphereRepShape::Write( out, link_map, version, user_version );
	num2 = uint(unknownVectors2.size());
	num1 = uint(unknownVectors1.size());
	for (uint i1 = 0; i1 < 7; i1++) {
		NifStream( unknownFloats1[i1], out, version );
	};
	NifStream( num1, out, version );
	for (uint i1 = 0; i1 < unknownVectors1.size(); i1++) {
		NifStream( unknownVectors1[i1], out, version );
	};
	NifStream( num2, out, version );
	for (uint i1 = 0; i1 < unknownVectors2.size(); i1++) {
		NifStream( unknownVectors2[i1], out, version );
	};
}

std::string bhkConvexVerticesShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkSphereRepShape::asString();
	num2 = uint(unknownVectors2.size());
	num1 = uint(unknownVectors1.size());
	array_output_count = 0;
	for (uint i1 = 0; i1 < 7; i1++) {
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
	out << "  Num 1:  " << num1 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownVectors1.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Vectors 1[" << i1 << "]:  " << unknownVectors1[i1] << endl;
		array_output_count++;
	};
	out << "  Num 2:  " << num2 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownVectors2.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Vectors 2[" << i1 << "]:  " << unknownVectors2[i1] << endl;
		array_output_count++;
	};
	return out.str();
}

void bhkConvexVerticesShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkConvexVerticesShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	return refs;
}

void bhkHingeConstraint::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 5; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			NifStream( unknownFloats[i1][i2], in, version );
		};
	};
}

void bhkHingeConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkConstraint::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 5; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			NifStream( unknownFloats[i1][i2], out, version );
		};
	};
}

std::string bhkHingeConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AbhkConstraint::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < 5; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats[" << i2 << "]:  " << unknownFloats[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void bhkHingeConstraint::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkHingeConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkLimitedHingeConstraint::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::Read( in, link_stack, version, user_version );
	NifStream( limitedHinge.pivotA, in, version );
	NifStream( limitedHinge.axleA, in, version );
	NifStream( limitedHinge.perp2axleina1, in, version );
	NifStream( limitedHinge.perp2axleina2, in, version );
	NifStream( limitedHinge.pivotB, in, version );
	NifStream( limitedHinge.axleB, in, version );
	NifStream( limitedHinge.perp2axleinb2, in, version );
	NifStream( limitedHinge.minAngle, in, version );
	NifStream( limitedHinge.maxAngle, in, version );
	NifStream( limitedHinge.maxFriction, in, version );
}

void bhkLimitedHingeConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkConstraint::Write( out, link_map, version, user_version );
	NifStream( limitedHinge.pivotA, out, version );
	NifStream( limitedHinge.axleA, out, version );
	NifStream( limitedHinge.perp2axleina1, out, version );
	NifStream( limitedHinge.perp2axleina2, out, version );
	NifStream( limitedHinge.pivotB, out, version );
	NifStream( limitedHinge.axleB, out, version );
	NifStream( limitedHinge.perp2axleinb2, out, version );
	NifStream( limitedHinge.minAngle, out, version );
	NifStream( limitedHinge.maxAngle, out, version );
	NifStream( limitedHinge.maxFriction, out, version );
}

std::string bhkLimitedHingeConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void bhkLimitedHingeConstraint::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkLimitedHingeConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkListShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	AbhkShapeCollection::Read( in, link_stack, version, user_version );
	NifStream( numSubShapes, in, version );
	subShapes.resize(numSubShapes);
	for (uint i1 = 0; i1 < subShapes.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( material, in, version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
	NifStream( numUnknownInts, in, version );
	unknownInts.resize(numUnknownInts);
	for (uint i1 = 0; i1 < unknownInts.size(); i1++) {
		NifStream( unknownInts[i1], in, version );
	};
}

void bhkListShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkShapeCollection::Write( out, link_map, version, user_version );
	numUnknownInts = uint(unknownInts.size());
	numSubShapes = uint(subShapes.size());
	NifStream( numSubShapes, out, version );
	for (uint i1 = 0; i1 < subShapes.size(); i1++) {
		if ( subShapes[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(subShapes[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	NifStream( material, out, version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
	NifStream( numUnknownInts, out, version );
	for (uint i1 = 0; i1 < unknownInts.size(); i1++) {
		NifStream( unknownInts[i1], out, version );
	};
}

std::string bhkListShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AbhkShapeCollection::asString();
	numUnknownInts = uint(unknownInts.size());
	numSubShapes = uint(subShapes.size());
	out << "  Num Sub Shapes:  " << numSubShapes << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < subShapes.size(); i1++) {
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
	for (uint i1 = 0; i1 < 6; i1++) {
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
	for (uint i1 = 0; i1 < unknownInts.size(); i1++) {
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

void bhkListShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkShapeCollection::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < subShapes.size(); i1++) {
		subShapes[i1] = FixLink<bhkShape>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> bhkListShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkShapeCollection::GetRefs();
	for (uint i1 = 0; i1 < subShapes.size(); i1++) {
		if ( subShapes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(subShapes[i1]));
	};
	return refs;
}

void bhkMalleableConstraint::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	AbhkConstraint::Read( in, link_stack, version, user_version );
	NifStream( type, in, version );
	NifStream( unknownInt2, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( unknownInt3, in, version );
	if ( (type == 7) ) {
		NifStream( ragdoll.pivotA, in, version );
		NifStream( ragdoll.planeA, in, version );
		NifStream( ragdoll.twistA, in, version );
		NifStream( ragdoll.pivotB, in, version );
		NifStream( ragdoll.planeB, in, version );
		NifStream( ragdoll.twistB, in, version );
		NifStream( ragdoll.coneMinAngle, in, version );
		NifStream( ragdoll.planeMinAngle, in, version );
		NifStream( ragdoll.planeMaxAngle, in, version );
		NifStream( ragdoll.twistMinAngle, in, version );
		NifStream( ragdoll.twistMaxAngle, in, version );
		NifStream( ragdoll.maxFriction, in, version );
	};
	if ( (type == 2) ) {
		NifStream( limitedHinge.pivotA, in, version );
		NifStream( limitedHinge.axleA, in, version );
		NifStream( limitedHinge.perp2axleina1, in, version );
		NifStream( limitedHinge.perp2axleina2, in, version );
		NifStream( limitedHinge.pivotB, in, version );
		NifStream( limitedHinge.axleB, in, version );
		NifStream( limitedHinge.perp2axleinb2, in, version );
		NifStream( limitedHinge.minAngle, in, version );
		NifStream( limitedHinge.maxAngle, in, version );
		NifStream( limitedHinge.maxFriction, in, version );
	};
	NifStream( tau, in, version );
	NifStream( damping, in, version );
}

void bhkMalleableConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkConstraint::Write( out, link_map, version, user_version );
	NifStream( type, out, version );
	NifStream( unknownInt2, out, version );
	if ( unknownLink1 != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink1)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( unknownLink2 != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( unknownInt3, out, version );
	if ( (type == 7) ) {
		NifStream( ragdoll.pivotA, out, version );
		NifStream( ragdoll.planeA, out, version );
		NifStream( ragdoll.twistA, out, version );
		NifStream( ragdoll.pivotB, out, version );
		NifStream( ragdoll.planeB, out, version );
		NifStream( ragdoll.twistB, out, version );
		NifStream( ragdoll.coneMinAngle, out, version );
		NifStream( ragdoll.planeMinAngle, out, version );
		NifStream( ragdoll.planeMaxAngle, out, version );
		NifStream( ragdoll.twistMinAngle, out, version );
		NifStream( ragdoll.twistMaxAngle, out, version );
		NifStream( ragdoll.maxFriction, out, version );
	};
	if ( (type == 2) ) {
		NifStream( limitedHinge.pivotA, out, version );
		NifStream( limitedHinge.axleA, out, version );
		NifStream( limitedHinge.perp2axleina1, out, version );
		NifStream( limitedHinge.perp2axleina2, out, version );
		NifStream( limitedHinge.pivotB, out, version );
		NifStream( limitedHinge.axleB, out, version );
		NifStream( limitedHinge.perp2axleinb2, out, version );
		NifStream( limitedHinge.minAngle, out, version );
		NifStream( limitedHinge.maxAngle, out, version );
		NifStream( limitedHinge.maxFriction, out, version );
	};
	NifStream( tau, out, version );
	NifStream( damping, out, version );
}

std::string bhkMalleableConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void bhkMalleableConstraint::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::FixLinks( objects, link_stack, version, user_version );
	unknownLink1 = FixLink<NiObject>( objects, link_stack, version );
	unknownLink2 = FixLink<NiObject>( objects, link_stack, version );
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

void bhkMoppBvTreeShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	bhkShape::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( material, in, version );
	for (uint i1 = 0; i1 < 8; i1++) {
		NifStream( unknownBytes1[i1], in, version );
	};
	NifStream( unknownFloat, in, version );
	NifStream( numUnknownBytes2, in, version );
	unknownBytes2.resize(numUnknownBytes2);
	for (uint i1 = 0; i1 < unknownBytes2.size(); i1++) {
		NifStream( unknownBytes2[i1], in, version );
	};
	NifStream( unknownVector, in, version );
	NifStream( unknownFloat2, in, version );
}

void bhkMoppBvTreeShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkShape::Write( out, link_map, version, user_version );
	numUnknownBytes2 = uint(unknownBytes2.size());
	if ( shape != NULL )
		NifStream( link_map[StaticCast<NiObject>(shape)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( material, out, version );
	for (uint i1 = 0; i1 < 8; i1++) {
		NifStream( unknownBytes1[i1], out, version );
	};
	NifStream( unknownFloat, out, version );
	NifStream( numUnknownBytes2, out, version );
	for (uint i1 = 0; i1 < unknownBytes2.size(); i1++) {
		NifStream( unknownBytes2[i1], out, version );
	};
	NifStream( unknownVector, out, version );
	NifStream( unknownFloat2, out, version );
}

std::string bhkMoppBvTreeShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkShape::asString();
	numUnknownBytes2 = uint(unknownBytes2.size());
	out << "  Shape:  " << shape << endl;
	out << "  Material:  " << material << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Bytes 1[" << i1 << "]:  " << unknownBytes1[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  Num Unknown Bytes 2:  " << numUnknownBytes2 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownBytes2.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unknown Bytes 2[" << i1 << "]:  " << unknownBytes2[i1] << endl;
		array_output_count++;
	};
	out << "  Unknown Vector:  " << unknownVector << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	return out.str();
}

void bhkMoppBvTreeShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkShape::FixLinks( objects, link_stack, version, user_version );
	shape = FixLink<bhkShape>( objects, link_stack, version );
}

std::list<NiObjectRef> bhkMoppBvTreeShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	if ( shape != NULL )
		refs.push_back(StaticCast<NiObject>(shape));
	return refs;
}

void bhkMultiSphereShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSphereRepShape::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownFloat2, in, version );
	NifStream( unknownFloat3, in, version );
	NifStream( numSpheres, in, version );
	spheres.resize(numSpheres);
	for (uint i1 = 0; i1 < spheres.size(); i1++) {
		NifStream( spheres[i1].center, in, version );
		NifStream( spheres[i1].radius, in, version );
	};
}

void bhkMultiSphereShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkSphereRepShape::Write( out, link_map, version, user_version );
	numSpheres = uint(spheres.size());
	NifStream( unknownFloat1, out, version );
	NifStream( unknownFloat2, out, version );
	NifStream( unknownFloat3, out, version );
	NifStream( numSpheres, out, version );
	for (uint i1 = 0; i1 < spheres.size(); i1++) {
		NifStream( spheres[i1].center, out, version );
		NifStream( spheres[i1].radius, out, version );
	};
}

std::string bhkMultiSphereShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkSphereRepShape::asString();
	numSpheres = uint(spheres.size());
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Num Spheres:  " << numSpheres << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < spheres.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Center:  " << spheres[i1].center << endl;
		out << "    Radius:  " << spheres[i1].radius << endl;
	};
	return out.str();
}

void bhkMultiSphereShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkMultiSphereShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	return refs;
}

void bhkNiTriStripsShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	bhkSphereRepShape::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownInt1, in, version );
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknownInts1[i1], in, version );
	};
	NifStream( unknownInt2, in, version );
	NifStream( scale, in, version );
	NifStream( unknownInt3, in, version );
	NifStream( numStripsData, in, version );
	stripsData.resize(numStripsData);
	for (uint i1 = 0; i1 < stripsData.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( numUnknownInts2, in, version );
	unknownInts2.resize(numUnknownInts2);
	for (uint i1 = 0; i1 < unknownInts2.size(); i1++) {
		NifStream( unknownInts2[i1], in, version );
	};
}

void bhkNiTriStripsShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkSphereRepShape::Write( out, link_map, version, user_version );
	numUnknownInts2 = uint(unknownInts2.size());
	numStripsData = uint(stripsData.size());
	NifStream( unknownFloat1, out, version );
	NifStream( unknownInt1, out, version );
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknownInts1[i1], out, version );
	};
	NifStream( unknownInt2, out, version );
	NifStream( scale, out, version );
	NifStream( unknownInt3, out, version );
	NifStream( numStripsData, out, version );
	for (uint i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(stripsData[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	NifStream( numUnknownInts2, out, version );
	for (uint i1 = 0; i1 < unknownInts2.size(); i1++) {
		NifStream( unknownInts2[i1], out, version );
	};
}

std::string bhkNiTriStripsShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkSphereRepShape::asString();
	numUnknownInts2 = uint(unknownInts2.size());
	numStripsData = uint(stripsData.size());
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < 4; i1++) {
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
	for (uint i1 = 0; i1 < stripsData.size(); i1++) {
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
	out << "  Num Unknown Ints 2:  " << numUnknownInts2 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownInts2.size(); i1++) {
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

void bhkNiTriStripsShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < stripsData.size(); i1++) {
		stripsData[i1] = FixLink<NiTriStripsData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> bhkNiTriStripsShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSphereRepShape::GetRefs();
	for (uint i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(stripsData[i1]));
	};
	return refs;
}

void bhkPackedNiTriStripsShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	AbhkShapeCollection::Read( in, link_stack, version, user_version );
	NifStream( numSubparts, in, version );
	subparts.resize(numSubparts);
	for (uint i1 = 0; i1 < subparts.size(); i1++) {
		for (uint i2 = 0; i2 < 3; i2++) {
			NifStream( subparts[i1][i2], in, version );
		};
	};
	for (uint i1 = 0; i1 < 9; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
	NifStream( scale, in, version );
	for (uint i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], in, version );
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void bhkPackedNiTriStripsShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkShapeCollection::Write( out, link_map, version, user_version );
	numSubparts = ushort(subparts.size());
	NifStream( numSubparts, out, version );
	for (uint i1 = 0; i1 < subparts.size(); i1++) {
		for (uint i2 = 0; i2 < 3; i2++) {
			NifStream( subparts[i1][i2], out, version );
		};
	};
	for (uint i1 = 0; i1 < 9; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
	NifStream( scale, out, version );
	for (uint i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], out, version );
	};
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string bhkPackedNiTriStripsShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AbhkShapeCollection::asString();
	numSubparts = ushort(subparts.size());
	out << "  Num Subparts:  " << numSubparts << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < subparts.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Subparts[" << i2 << "]:  " << subparts[i1][i2] << endl;
			array_output_count++;
		};
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < 9; i1++) {
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
	for (uint i1 = 0; i1 < 3; i1++) {
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

void bhkPackedNiTriStripsShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkShapeCollection::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<hkPackedNiTriStripsData>( objects, link_stack, version );
}

std::list<NiObjectRef> bhkPackedNiTriStripsShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkShapeCollection::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void bhkPrismaticConstraint::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 8; i1++) {
		NifStream( unknownVectors[i1], in, version );
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], in, version );
	};
}

void bhkPrismaticConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkConstraint::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 8; i1++) {
		NifStream( unknownVectors[i1], out, version );
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats2[i1], out, version );
	};
}

std::string bhkPrismaticConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AbhkConstraint::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < 8; i1++) {
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
	for (uint i1 = 0; i1 < 3; i1++) {
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

void bhkPrismaticConstraint::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkPrismaticConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkRagdollConstraint::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkRagdollConstraint::Read( in, link_stack, version, user_version );
}

void bhkRagdollConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkRagdollConstraint::Write( out, link_map, version, user_version );
}

std::string bhkRagdollConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AbhkRagdollConstraint::asString();
	return out.str();
}

void bhkRagdollConstraint::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkRagdollConstraint::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkRagdollConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkRagdollConstraint::GetRefs();
	return refs;
}

void bhkRigidBody::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	bhkEntity::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 5; i1++) {
		NifStream( unknown5Floats[i1], in, version );
	};
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Shorts[i1], in, version );
	};
	NifStream( layerCopy, in, version );
	NifStream( colFilterCopy, in, version );
	for (uint i1 = 0; i1 < 7; i1++) {
		NifStream( unknown7Shorts[i1], in, version );
	};
	NifStream( translation, in, version );
	NifStream( unknownFloat00, in, version );
	NifStream( rotation.x, in, version );
	NifStream( rotation.y, in, version );
	NifStream( rotation.z, in, version );
	NifStream( rotation.w, in, version );
	NifStream( linearVelocity, in, version );
	NifStream( unknownFloat01, in, version );
	NifStream( angularVelocity, in, version );
	NifStream( unknownFloat02, in, version );
	for (uint i1 = 0; i1 < 12; i1++) {
		NifStream( transform[i1], in, version );
	};
	NifStream( center, in, version );
	NifStream( unknownFloat03, in, version );
	NifStream( mass, in, version );
	NifStream( linearDamping, in, version );
	NifStream( angularDamping, in, version );
	NifStream( friction, in, version );
	NifStream( restitution, in, version );
	NifStream( maxLinearVelocity, in, version );
	NifStream( maxAngularVelocity, in, version );
	NifStream( penetrationDepth, in, version );
	NifStream( motionSystem, in, version );
	NifStream( unknownByte1, in, version );
	NifStream( unknownByte2, in, version );
	NifStream( qualityType, in, version );
	NifStream( unknownInt6, in, version );
	NifStream( unknownInt7, in, version );
	NifStream( unknownInt8, in, version );
	NifStream( numConstraints, in, version );
	constraints.resize(numConstraints);
	for (uint i1 = 0; i1 < constraints.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( unknownInt6, in, version );
}

void bhkRigidBody::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkEntity::Write( out, link_map, version, user_version );
	numConstraints = uint(constraints.size());
	for (uint i1 = 0; i1 < 5; i1++) {
		NifStream( unknown5Floats[i1], out, version );
	};
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Shorts[i1], out, version );
	};
	NifStream( layerCopy, out, version );
	NifStream( colFilterCopy, out, version );
	for (uint i1 = 0; i1 < 7; i1++) {
		NifStream( unknown7Shorts[i1], out, version );
	};
	NifStream( translation, out, version );
	NifStream( unknownFloat00, out, version );
	NifStream( rotation.x, out, version );
	NifStream( rotation.y, out, version );
	NifStream( rotation.z, out, version );
	NifStream( rotation.w, out, version );
	NifStream( linearVelocity, out, version );
	NifStream( unknownFloat01, out, version );
	NifStream( angularVelocity, out, version );
	NifStream( unknownFloat02, out, version );
	for (uint i1 = 0; i1 < 12; i1++) {
		NifStream( transform[i1], out, version );
	};
	NifStream( center, out, version );
	NifStream( unknownFloat03, out, version );
	NifStream( mass, out, version );
	NifStream( linearDamping, out, version );
	NifStream( angularDamping, out, version );
	NifStream( friction, out, version );
	NifStream( restitution, out, version );
	NifStream( maxLinearVelocity, out, version );
	NifStream( maxAngularVelocity, out, version );
	NifStream( penetrationDepth, out, version );
	NifStream( motionSystem, out, version );
	NifStream( unknownByte1, out, version );
	NifStream( unknownByte2, out, version );
	NifStream( qualityType, out, version );
	NifStream( unknownInt6, out, version );
	NifStream( unknownInt7, out, version );
	NifStream( unknownInt8, out, version );
	NifStream( numConstraints, out, version );
	for (uint i1 = 0; i1 < constraints.size(); i1++) {
		if ( constraints[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(constraints[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	NifStream( unknownInt6, out, version );
}

std::string bhkRigidBody::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkEntity::asString();
	numConstraints = uint(constraints.size());
	array_output_count = 0;
	for (uint i1 = 0; i1 < 5; i1++) {
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
	for (uint i1 = 0; i1 < 4; i1++) {
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
	for (uint i1 = 0; i1 < 7; i1++) {
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
	for (uint i1 = 0; i1 < 12; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Transform[" << i1 << "]:  " << transform[i1] << endl;
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
	for (uint i1 = 0; i1 < constraints.size(); i1++) {
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

void bhkRigidBody::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkEntity::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < constraints.size(); i1++) {
		constraints[i1] = FixLink<AbhkConstraint>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> bhkRigidBody::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkEntity::GetRefs();
	for (uint i1 = 0; i1 < constraints.size(); i1++) {
		if ( constraints[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(constraints[i1]));
	};
	return refs;
}

void bhkRigidBodyT::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkRigidBody::Read( in, link_stack, version, user_version );
}

void bhkRigidBodyT::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkRigidBody::Write( out, link_map, version, user_version );
}

std::string bhkRigidBodyT::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkRigidBody::asString();
	return out.str();
}

void bhkRigidBodyT::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkRigidBody::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkRigidBodyT::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkRigidBody::GetRefs();
	return refs;
}

void bhkSimpleShapePhantom::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkEntity::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 7; i1++) {
		NifStream( unkownFloats[i1], in, version );
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		for (uint i2 = 0; i2 < 5; i2++) {
			NifStream( unknownFloats2[i1][i2], in, version );
		};
	};
	NifStream( unknownFloat, in, version );
}

void bhkSimpleShapePhantom::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkEntity::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 7; i1++) {
		NifStream( unkownFloats[i1], out, version );
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		for (uint i2 = 0; i2 < 5; i2++) {
			NifStream( unknownFloats2[i1][i2], out, version );
		};
	};
	NifStream( unknownFloat, out, version );
}

std::string bhkSimpleShapePhantom::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkEntity::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < 7; i1++) {
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
	for (uint i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 5; i2++) {
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

void bhkSimpleShapePhantom::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkEntity::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkSimpleShapePhantom::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkEntity::GetRefs();
	return refs;
}

void bhkSPCollisionObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiCollisionObject::Read( in, link_stack, version, user_version );
}

void bhkSPCollisionObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiCollisionObject::Write( out, link_map, version, user_version );
}

std::string bhkSPCollisionObject::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiCollisionObject::asString();
	return out.str();
}

void bhkSPCollisionObject::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiCollisionObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkSPCollisionObject::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiCollisionObject::GetRefs();
	return refs;
}

void bhkSphereShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkConvexShape::Read( in, link_stack, version, user_version );
	NifStream( radius, in, version );
}

void bhkSphereShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkConvexShape::Write( out, link_map, version, user_version );
	NifStream( radius, out, version );
}

std::string bhkSphereShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkConvexShape::asString();
	out << "  Radius:  " << radius << endl;
	return out.str();
}

void bhkSphereShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkConvexShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkSphereShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConvexShape::GetRefs();
	return refs;
}

void bhkStiffSpringConstraint::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 2; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			NifStream( unknownFloats[i1][i2], in, version );
		};
	};
	NifStream( unknownFloat, in, version );
}

void bhkStiffSpringConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkConstraint::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 2; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			NifStream( unknownFloats[i1][i2], out, version );
		};
	};
	NifStream( unknownFloat, out, version );
}

std::string bhkStiffSpringConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AbhkConstraint::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats[" << i2 << "]:  " << unknownFloats[i1][i2] << endl;
			array_output_count++;
		};
	};
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void bhkStiffSpringConstraint::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkStiffSpringConstraint::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkConstraint::GetRefs();
	return refs;
}

void bhkTransformShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkEntity::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownFloat2, in, version );
	NifStream( unknownFloat3, in, version );
	NifStream( transform, in, version );
}

void bhkTransformShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkEntity::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownFloat2, out, version );
	NifStream( unknownFloat3, out, version );
	NifStream( transform, out, version );
}

std::string bhkTransformShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkEntity::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Transform:  " << transform << endl;
	return out.str();
}

void bhkTransformShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkEntity::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkTransformShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkEntity::GetRefs();
	return refs;
}

void bhkConvexTransformShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkTransformShape::Read( in, link_stack, version, user_version );
}

void bhkConvexTransformShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkTransformShape::Write( out, link_map, version, user_version );
}

std::string bhkConvexTransformShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << bhkTransformShape::asString();
	return out.str();
}

void bhkConvexTransformShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkTransformShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkConvexTransformShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkTransformShape::GetRefs();
	return refs;
}

void BSBound::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( center, in, version );
	NifStream( dimensions, in, version );
}

void BSBound::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	NifStream( center, out, version );
	NifStream( dimensions, out, version );
}

std::string BSBound::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Center:  " << center << endl;
	out << "  Dimensions:  " << dimensions << endl;
	return out.str();
}

void BSBound::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> BSBound::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void BSFurnitureMarker::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( numPositions, in, version );
	positions.resize(numPositions);
	for (uint i1 = 0; i1 < positions.size(); i1++) {
		NifStream( positions[i1].offset, in, version );
		NifStream( positions[i1].orientation, in, version );
		NifStream( positions[i1].positionRef1, in, version );
		NifStream( positions[i1].positionRef2, in, version );
	};
}

void BSFurnitureMarker::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	numPositions = uint(positions.size());
	NifStream( numPositions, out, version );
	for (uint i1 = 0; i1 < positions.size(); i1++) {
		NifStream( positions[i1].offset, out, version );
		NifStream( positions[i1].orientation, out, version );
		NifStream( positions[i1].positionRef1, out, version );
		NifStream( positions[i1].positionRef2, out, version );
	};
}

std::string BSFurnitureMarker::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	numPositions = uint(positions.size());
	out << "  Num Positions:  " << numPositions << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < positions.size(); i1++) {
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

void BSFurnitureMarker::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> BSFurnitureMarker::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void BSParentVelocityModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat, in, version );
}

void BSParentVelocityModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	NifStream( unknownFloat, out, version );
}

std::string BSParentVelocityModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void BSParentVelocityModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> BSParentVelocityModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void BSPSysArrayEmitter::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysVolumeEmitter::Read( in, link_stack, version, user_version );
}

void BSPSysArrayEmitter::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysVolumeEmitter::Write( out, link_map, version, user_version );
}

std::string BSPSysArrayEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysVolumeEmitter::asString();
	return out.str();
}

void BSPSysArrayEmitter::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysVolumeEmitter::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> BSPSysArrayEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysVolumeEmitter::GetRefs();
	return refs;
}

void BSXFlags::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
}

void BSXFlags::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
}

std::string BSXFlags::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void BSXFlags::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> BSXFlags::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void hkPackedNiTriStripsData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkShapeCollection::Read( in, link_stack, version, user_version );
	NifStream( numTriangles, in, version );
	triangles.resize(numTriangles);
	for (uint i1 = 0; i1 < triangles.size(); i1++) {
		NifStream( triangles[i1].triangle, in, version );
		NifStream( triangles[i1].unknownShort, in, version );
		NifStream( triangles[i1].normal, in, version );
	};
	NifStream( numVertices, in, version );
	vertices.resize(numVertices);
	for (uint i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], in, version );
	};
}

void hkPackedNiTriStripsData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkShapeCollection::Write( out, link_map, version, user_version );
	numVertices = uint(vertices.size());
	numTriangles = uint(triangles.size());
	NifStream( numTriangles, out, version );
	for (uint i1 = 0; i1 < triangles.size(); i1++) {
		NifStream( triangles[i1].triangle, out, version );
		NifStream( triangles[i1].unknownShort, out, version );
		NifStream( triangles[i1].normal, out, version );
	};
	NifStream( numVertices, out, version );
	for (uint i1 = 0; i1 < vertices.size(); i1++) {
		NifStream( vertices[i1], out, version );
	};
}

std::string hkPackedNiTriStripsData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AbhkShapeCollection::asString();
	numVertices = uint(vertices.size());
	numTriangles = uint(triangles.size());
	out << "  Num Triangles:  " << numTriangles << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < triangles.size(); i1++) {
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
	for (uint i1 = 0; i1 < vertices.size(); i1++) {
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

void hkPackedNiTriStripsData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkShapeCollection::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> hkPackedNiTriStripsData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AbhkShapeCollection::GetRefs();
	return refs;
}

void NiAlphaController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiSingleInterpolatorController::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiAlphaController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSingleInterpolatorController::Write( out, link_map, version, user_version );
	if ( version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map[StaticCast<NiObject>(data)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiAlphaController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiAlphaController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		data = FixLink<NiFloatData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiAlphaController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiAlphaProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
	NifStream( threshold, in, version );
}

void NiAlphaProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
	NifStream( threshold, out, version );
}

std::string NiAlphaProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Threshold:  " << threshold << endl;
	return out.str();
}

void NiAlphaProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiAlphaProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiAmbientLight::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLight::Read( in, link_stack, version, user_version );
}

void NiAmbientLight::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiLight::Write( out, link_map, version, user_version );
}

std::string NiAmbientLight::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiLight::asString();
	return out.str();
}

void NiAmbientLight::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLight::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiAmbientLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLight::GetRefs();
	return refs;
}

void NiAutoNormalParticlesData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometryData::Read( in, link_stack, version, user_version );
	if ( version <= 0x04000002 ) {
		NifStream( numParticles, in, version );
	};
	if ( version <= 0x0A000100 ) {
		NifStream( size, in, version );
	};
	if ( version <= 0x04000002 ) {
		NifStream( numActive, in, version );
	};
	if ( ( version >= 0x0401000C ) && ( version <= 0x0A000100 ) ) {
		NifStream( unknownShort, in, version );
	};
	NifStream( hasSizes, in, version );
	if ( (hasSizes != 0) ) {
		sizes.resize(numVertices);
		for (uint i2 = 0; i2 < sizes.size(); i2++) {
			NifStream( sizes[i2], in, version );
		};
	};
}

void NiAutoNormalParticlesData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiGeometryData::Write( out, link_map, version, user_version );
	if ( version <= 0x04000002 ) {
		NifStream( numParticles, out, version );
	};
	if ( version <= 0x0A000100 ) {
		NifStream( size, out, version );
	};
	if ( version <= 0x04000002 ) {
		NifStream( numActive, out, version );
	};
	if ( ( version >= 0x0401000C ) && ( version <= 0x0A000100 ) ) {
		NifStream( unknownShort, out, version );
	};
	NifStream( hasSizes, out, version );
	if ( (hasSizes != 0) ) {
		for (uint i2 = 0; i2 < sizes.size(); i2++) {
			NifStream( sizes[i2], out, version );
		};
	};
}

std::string NiAutoNormalParticlesData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiGeometryData::asString();
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Size:  " << size << endl;
	out << "  Num Active:  " << numActive << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Has Sizes:  " << hasSizes << endl;
	if ( (hasSizes != 0) ) {
		array_output_count = 0;
		for (uint i2 = 0; i2 < sizes.size(); i2++) {
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

void NiAutoNormalParticlesData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometryData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiAutoNormalParticlesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometryData::GetRefs();
	return refs;
}

void NiBinaryExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( binaryData.dataSize, in, version );
	binaryData.data.resize(binaryData.dataSize);
	for (uint i1 = 0; i1 < binaryData.data.size(); i1++) {
		NifStream( binaryData.data[i1], in, version );
	};
}

void NiBinaryExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	binaryData.dataSize = uint(binaryData.data.size());
	NifStream( binaryData.dataSize, out, version );
	for (uint i1 = 0; i1 < binaryData.data.size(); i1++) {
		NifStream( binaryData.data[i1], out, version );
	};
}

std::string NiBinaryExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	binaryData.dataSize = uint(binaryData.data.size());
	out << "  Data Size:  " << binaryData.dataSize << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < binaryData.data.size(); i1++) {
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

void NiBinaryExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBinaryExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiBlendBoolInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::Read( in, link_stack, version, user_version );
	NifStream( boolValue, in, version );
}

void NiBlendBoolInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBlendInterpolator::Write( out, link_map, version, user_version );
	NifStream( boolValue, out, version );
}

std::string NiBlendBoolInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	return out.str();
}

void NiBlendBoolInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBlendBoolInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

void NiBlendFloatInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::Read( in, link_stack, version, user_version );
	NifStream( floatValue, in, version );
}

void NiBlendFloatInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBlendInterpolator::Write( out, link_map, version, user_version );
	NifStream( floatValue, out, version );
}

std::string NiBlendFloatInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Float Value:  " << floatValue << endl;
	return out.str();
}

void NiBlendFloatInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBlendFloatInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

void NiBlendPoint3Interpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::Read( in, link_stack, version, user_version );
	NifStream( pointValue, in, version );
}

void NiBlendPoint3Interpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBlendInterpolator::Write( out, link_map, version, user_version );
	NifStream( pointValue, out, version );
}

std::string NiBlendPoint3Interpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Point Value:  " << pointValue << endl;
	return out.str();
}

void NiBlendPoint3Interpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBlendPoint3Interpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

void NiBlendTransformInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::Read( in, link_stack, version, user_version );
}

void NiBlendTransformInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBlendInterpolator::Write( out, link_map, version, user_version );
}

std::string NiBlendTransformInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiBlendInterpolator::asString();
	return out.str();
}

void NiBlendTransformInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBlendTransformInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

void NiBoneLODController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	ABoneLODController::Read( in, link_stack, version, user_version );
	NifStream( numShapeGroups, in, version );
	shapeGroups1.resize(numShapeGroups);
	for (uint i1 = 0; i1 < shapeGroups1.size(); i1++) {
		NifStream( shapeGroups1[i1].numLinkPairs, in, version );
		shapeGroups1[i1].linkPairs.resize(shapeGroups1[i1].numLinkPairs);
		for (uint i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
	NifStream( numShapeGroups2, in, version );
	shapeGroups2.resize(numShapeGroups2);
	for (uint i1 = 0; i1 < shapeGroups2.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiBoneLODController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	ABoneLODController::Write( out, link_map, version, user_version );
	numShapeGroups2 = uint(shapeGroups2.size());
	numShapeGroups = uint(shapeGroups1.size());
	NifStream( numShapeGroups, out, version );
	for (uint i1 = 0; i1 < shapeGroups1.size(); i1++) {
		shapeGroups1[i1].numLinkPairs = uint(shapeGroups1[i1].linkPairs.size());
		NifStream( shapeGroups1[i1].numLinkPairs, out, version );
		for (uint i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			if ( shapeGroups1[i1].linkPairs[i2].shape != NULL )
				NifStream( link_map[StaticCast<NiObject>(shapeGroups1[i1].linkPairs[i2].shape)], out, version );
			else
				NifStream( 0xffffffff, out, version );
			if ( shapeGroups1[i1].linkPairs[i2].skinInstance != NULL )
				NifStream( link_map[StaticCast<NiObject>(shapeGroups1[i1].linkPairs[i2].skinInstance)], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
	NifStream( numShapeGroups2, out, version );
	for (uint i1 = 0; i1 < shapeGroups2.size(); i1++) {
		if ( shapeGroups2[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(shapeGroups2[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiBoneLODController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << ABoneLODController::asString();
	numShapeGroups2 = uint(shapeGroups2.size());
	numShapeGroups = uint(shapeGroups1.size());
	out << "  Num Shape Groups:  " << numShapeGroups << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < shapeGroups1.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		shapeGroups1[i1].numLinkPairs = uint(shapeGroups1[i1].linkPairs.size());
		out << "    Num Link Pairs:  " << shapeGroups1[i1].numLinkPairs << endl;
		array_output_count = 0;
		for (uint i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
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
	for (uint i1 = 0; i1 < shapeGroups2.size(); i1++) {
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

void NiBoneLODController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	ABoneLODController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < shapeGroups1.size(); i1++) {
		for (uint i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			shapeGroups1[i1].linkPairs[i2].shape = FixLink<NiTriShape>( objects, link_stack, version );
			shapeGroups1[i1].linkPairs[i2].skinInstance = FixLink<NiSkinInstance>( objects, link_stack, version );
		};
	};
	for (uint i1 = 0; i1 < shapeGroups2.size(); i1++) {
		shapeGroups2[i1] = FixLink<NiTriShape>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiBoneLODController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = ABoneLODController::GetRefs();
	for (uint i1 = 0; i1 < shapeGroups1.size(); i1++) {
		for (uint i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			if ( shapeGroups1[i1].linkPairs[i2].shape != NULL )
				refs.push_back(StaticCast<NiObject>(shapeGroups1[i1].linkPairs[i2].shape));
			if ( shapeGroups1[i1].linkPairs[i2].skinInstance != NULL )
				refs.push_back(StaticCast<NiObject>(shapeGroups1[i1].linkPairs[i2].skinInstance));
		};
	};
	for (uint i1 = 0; i1 < shapeGroups2.size(); i1++) {
		if ( shapeGroups2[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(shapeGroups2[i1]));
	};
	return refs;
}

void NiBoolData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::Read( in, link_stack, version, user_version );
	NifStream( data.numKeys, in, version );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, in, version );
	};
	data.keys.resize(data.numKeys);
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], in, version, data.interpolation );
	};
}

void NiBoolData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AKeyedData::Write( out, link_map, version, user_version );
	data.numKeys = uint(data.keys.size());
	NifStream( data.numKeys, out, version );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, out, version );
	};
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], out, version, data.interpolation );
	};
}

std::string NiBoolData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AKeyedData::asString();
	data.numKeys = uint(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
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

void NiBoolData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBoolData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiBooleanExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( booleanData, in, version );
}

void NiBooleanExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	NifStream( booleanData, out, version );
}

std::string NiBooleanExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Boolean Data:  " << booleanData << endl;
	return out.str();
}

void NiBooleanExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBooleanExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiBoolInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( boolValue, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiBoolInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( boolValue, out, version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiBoolInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiBoolInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiBoolData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiBoolInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiBoolTimelineInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( boolValue, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiBoolTimelineInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( boolValue, out, version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiBoolTimelineInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiBoolTimelineInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiBoolData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiBoolTimelineInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiBSBoneLODController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	ABoneLODController::Read( in, link_stack, version, user_version );
}

void NiBSBoneLODController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	ABoneLODController::Write( out, link_map, version, user_version );
}

std::string NiBSBoneLODController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << ABoneLODController::asString();
	return out.str();
}

void NiBSBoneLODController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	ABoneLODController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSBoneLODController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = ABoneLODController::GetRefs();
	return refs;
}

void NiBSplineBasisData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( numControlPt, in, version );
}

void NiBSplineBasisData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	NifStream( numControlPt, out, version );
}

std::string NiBSplineBasisData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	out << "  Num Control Pt:  " << numControlPt << endl;
	return out.str();
}

void NiBSplineBasisData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSplineBasisData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiBSplineCompFloatInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
}

void NiBSplineCompFloatInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBSplineInterpolator::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
}

std::string NiBSplineCompFloatInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiBSplineInterpolator::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < 4; i1++) {
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

void NiBSplineCompFloatInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSplineCompFloatInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	return refs;
}

void NiBSplineCompPoint3Interpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
}

void NiBSplineCompPoint3Interpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBSplineInterpolator::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
}

std::string NiBSplineCompPoint3Interpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiBSplineInterpolator::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < 6; i1++) {
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

void NiBSplineCompPoint3Interpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSplineCompPoint3Interpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	return refs;
}

void NiBSplineCompTransformInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::Read( in, link_stack, version, user_version );
	NifStream( translation, in, version );
	NifStream( rotation, in, version );
	NifStream( scale, in, version );
	NifStream( translateOffset, in, version );
	NifStream( rotateOffset, in, version );
	NifStream( scaleOffset, in, version );
	NifStream( translateBias, in, version );
	NifStream( translateMultiplier, in, version );
	NifStream( rotationBias, in, version );
	NifStream( rotationMultiplier, in, version );
	NifStream( scaleBias, in, version );
	NifStream( scaleMultiplier, in, version );
}

void NiBSplineCompTransformInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBSplineInterpolator::Write( out, link_map, version, user_version );
	NifStream( translation, out, version );
	NifStream( rotation, out, version );
	NifStream( scale, out, version );
	NifStream( translateOffset, out, version );
	NifStream( rotateOffset, out, version );
	NifStream( scaleOffset, out, version );
	NifStream( translateBias, out, version );
	NifStream( translateMultiplier, out, version );
	NifStream( rotationBias, out, version );
	NifStream( rotationMultiplier, out, version );
	NifStream( scaleBias, out, version );
	NifStream( scaleMultiplier, out, version );
}

std::string NiBSplineCompTransformInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiBSplineCompTransformInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSplineCompTransformInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	return refs;
}

void NiBSplineData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( unknownInt, in, version );
	NifStream( count, in, version );
	controlPoints.resize(count);
	for (uint i1 = 0; i1 < controlPoints.size(); i1++) {
		NifStream( controlPoints[i1], in, version );
	};
}

void NiBSplineData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	count = uint(controlPoints.size());
	NifStream( unknownInt, out, version );
	NifStream( count, out, version );
	for (uint i1 = 0; i1 < controlPoints.size(); i1++) {
		NifStream( controlPoints[i1], out, version );
	};
}

std::string NiBSplineData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	count = uint(controlPoints.size());
	out << "  Unknown Int:  " << unknownInt << endl;
	out << "  Count:  " << count << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < controlPoints.size(); i1++) {
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

void NiBSplineData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSplineData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiCamera::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiAVObject::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknownShort, in, version );
	};
	NifStream( frustumLeft, in, version );
	NifStream( frustumRight, in, version );
	NifStream( frustumTop, in, version );
	NifStream( frustumBottom, in, version );
	NifStream( frustumNear, in, version );
	NifStream( frustumFar, in, version );
	if ( version >= 0x0A010000 ) {
		NifStream( useOrthographicProjection, in, version );
	};
	NifStream( viewportLeft, in, version );
	NifStream( viewportRight, in, version );
	NifStream( viewportTop, in, version );
	NifStream( viewportBottom, in, version );
	NifStream( lodAdjust, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( unknownInt, in, version );
	if ( version >= 0x04020100 ) {
		NifStream( unknownInt2, in, version );
	};
}

void NiCamera::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiAVObject::Write( out, link_map, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknownShort, out, version );
	};
	NifStream( frustumLeft, out, version );
	NifStream( frustumRight, out, version );
	NifStream( frustumTop, out, version );
	NifStream( frustumBottom, out, version );
	NifStream( frustumNear, out, version );
	NifStream( frustumFar, out, version );
	if ( version >= 0x0A010000 ) {
		NifStream( useOrthographicProjection, out, version );
	};
	NifStream( viewportLeft, out, version );
	NifStream( viewportRight, out, version );
	NifStream( viewportTop, out, version );
	NifStream( viewportBottom, out, version );
	NifStream( lodAdjust, out, version );
	if ( unknownLink_ != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink_)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( unknownInt, out, version );
	if ( version >= 0x04020100 ) {
		NifStream( unknownInt2, out, version );
	};
}

std::string NiCamera::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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
	return out.str();
}

void NiCamera::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAVObject::FixLinks( objects, link_stack, version, user_version );
	unknownLink_ = FixLink<NiObject>( objects, link_stack, version );
}

std::list<NiObjectRef> NiCamera::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	if ( unknownLink_ != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink_));
	return refs;
}

void NiCollisionData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( unknownInt1, in, version );
	if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) {
		NifStream( unknownInt2, in, version );
	};
	NifStream( unknownByte, in, version );
	NifStream( collisionType, in, version );
	if ( (collisionType == 0) ) {
		NifStream( unknownInt2, in, version );
		NifStream( unknownVector, in, version );
	};
	if ( (collisionType == 2) ) {
		for (uint i2 = 0; i2 < 8; i2++) {
			NifStream( unknownFloat1[i2], in, version );
		};
	};
	if ( (collisionType == 1) ) {
		for (uint i2 = 0; i2 < 15; i2++) {
			NifStream( unknownFloat2[i2], in, version );
		};
	};
}

void NiCollisionData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	if ( targetNode != NULL )
		NifStream( link_map[StaticCast<NiObject>(targetNode)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( unknownInt1, out, version );
	if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) {
		NifStream( unknownInt2, out, version );
	};
	NifStream( unknownByte, out, version );
	NifStream( collisionType, out, version );
	if ( (collisionType == 0) ) {
		NifStream( unknownInt2, out, version );
		NifStream( unknownVector, out, version );
	};
	if ( (collisionType == 2) ) {
		for (uint i2 = 0; i2 < 8; i2++) {
			NifStream( unknownFloat1[i2], out, version );
		};
	};
	if ( (collisionType == 1) ) {
		for (uint i2 = 0; i2 < 15; i2++) {
			NifStream( unknownFloat2[i2], out, version );
		};
	};
}

std::string NiCollisionData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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
		for (uint i2 = 0; i2 < 8; i2++) {
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
		for (uint i2 = 0; i2 < 15; i2++) {
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

void NiCollisionData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	targetNode = FixLink<NiNode>( objects, link_stack, version );
}

std::list<NiObjectRef> NiCollisionData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiColorData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::Read( in, link_stack, version, user_version );
	NifStream( data.numKeys, in, version );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, in, version );
	};
	data.keys.resize(data.numKeys);
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], in, version, data.interpolation );
	};
}

void NiColorData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AKeyedData::Write( out, link_map, version, user_version );
	data.numKeys = uint(data.keys.size());
	NifStream( data.numKeys, out, version );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, out, version );
	};
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], out, version, data.interpolation );
	};
}

std::string NiColorData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AKeyedData::asString();
	data.numKeys = uint(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
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

void NiColorData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiColorData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiColorExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( data, in, version );
}

void NiColorExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	NifStream( data, out, version );
}

std::string NiColorExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiColorExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiColorExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiControllerManager::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	NifStream( cumulative, in, version );
	NifStream( numControllerSequences, in, version );
	controllerSequences.resize(numControllerSequences);
	for (uint i1 = 0; i1 < controllerSequences.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiControllerManager::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	numControllerSequences = uint(controllerSequences.size());
	NifStream( cumulative, out, version );
	NifStream( numControllerSequences, out, version );
	for (uint i1 = 0; i1 < controllerSequences.size(); i1++) {
		if ( controllerSequences[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(controllerSequences[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( objectPalette != NULL )
		NifStream( link_map[StaticCast<NiObject>(objectPalette)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiControllerManager::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	numControllerSequences = uint(controllerSequences.size());
	out << "  Cumulative:  " << cumulative << endl;
	out << "  Num Controller Sequences:  " << numControllerSequences << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < controllerSequences.size(); i1++) {
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

void NiControllerManager::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < controllerSequences.size(); i1++) {
		controllerSequences[i1] = FixLink<NiControllerSequence>( objects, link_stack, version );
	};
	objectPalette = FixLink<NiDefaultAVObjectPalette>( objects, link_stack, version );
}

std::list<NiObjectRef> NiControllerManager::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	for (uint i1 = 0; i1 < controllerSequences.size(); i1++) {
		if ( controllerSequences[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(controllerSequences[i1]));
	};
	if ( objectPalette != NULL )
		refs.push_back(StaticCast<NiObject>(objectPalette));
	return refs;
}

void NiControllerSequence::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( name, in, version );
	if ( version <= 0x0A010000 ) {
		NifStream( textKeysName, in, version );
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( numControlledBlocks, in, version );
	if ( version >= 0x0A01006A ) {
		NifStream( unknownInt1, in, version );
	};
	controlledBlocks.resize(numControlledBlocks);
	for (uint i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( version <= 0x0A010000 ) {
			NifStream( controlledBlocks[i1].targetName, in, version );
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
		if ( version >= 0x0A01006A ) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
			NifStream( controlledBlocks[i1].unknownShort0, in, version );
		};
		if ( ( version >= 0x0A01006A ) && ( user_version == 10 ) ) {
			NifStream( controlledBlocks[i1].priority_, in, version );
		};
		if ( ( version >= 0x0A01006A ) && ( user_version == 11 ) ) {
			NifStream( controlledBlocks[i1].priority_, in, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].nodeName, in, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].nodeNameOffset, in, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].propertyType, in, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].propertyTypeOffset, in, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].controllerType, in, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].controllerTypeOffset, in, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].variable1, in, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].variableOffset1, in, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].variable2, in, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].variableOffset2, in, version );
		};
	};
	if ( version >= 0x0A01006A ) {
		NifStream( weight, in, version );
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( cycleType, in, version );
	};
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
		NifStream( unknownInt0, in, version );
	};
	if ( version >= 0x0A01006A ) {
		NifStream( frequency, in, version );
		NifStream( startTime, in, version );
		NifStream( stopTime, in, version );
	};
	if ( ( version >= 0x0A020000 ) && ( version <= 0x0A020000 ) ) {
		NifStream( unknownFloat2, in, version );
	};
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
		NifStream( unknownByte, in, version );
	};
	if ( version >= 0x0A01006A ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( targetName, in, version );
	};
	if ( version >= 0x0A020000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiControllerSequence::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numControlledBlocks = uint(controlledBlocks.size());
	NifStream( name, out, version );
	if ( version <= 0x0A010000 ) {
		NifStream( textKeysName, out, version );
		if ( textKeys != NULL )
			NifStream( link_map[StaticCast<NiObject>(textKeys)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	NifStream( numControlledBlocks, out, version );
	if ( version >= 0x0A01006A ) {
		NifStream( unknownInt1, out, version );
	};
	for (uint i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( version <= 0x0A010000 ) {
			NifStream( controlledBlocks[i1].targetName, out, version );
			if ( controlledBlocks[i1].controller != NULL )
				NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i1].controller)], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
		if ( version >= 0x0A01006A ) {
			if ( controlledBlocks[i1].interpolator != NULL )
				NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i1].interpolator)], out, version );
			else
				NifStream( 0xffffffff, out, version );
			if ( controlledBlocks[i1].controller != NULL )
				NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i1].controller)], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			if ( controlledBlocks[i1].unknownLink2 != NULL )
				NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i1].unknownLink2)], out, version );
			else
				NifStream( 0xffffffff, out, version );
			NifStream( controlledBlocks[i1].unknownShort0, out, version );
		};
		if ( ( version >= 0x0A01006A ) && ( user_version == 10 ) ) {
			NifStream( controlledBlocks[i1].priority_, out, version );
		};
		if ( ( version >= 0x0A01006A ) && ( user_version == 11 ) ) {
			NifStream( controlledBlocks[i1].priority_, out, version );
		};
		if ( version >= 0x0A020000 ) {
			if ( controlledBlocks[i1].stringPalette != NULL )
				NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i1].stringPalette)], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].nodeName, out, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].nodeNameOffset, out, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].propertyType, out, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].propertyTypeOffset, out, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].controllerType, out, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].controllerTypeOffset, out, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].variable1, out, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].variableOffset1, out, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( controlledBlocks[i1].variable2, out, version );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( controlledBlocks[i1].variableOffset2, out, version );
		};
	};
	if ( version >= 0x0A01006A ) {
		NifStream( weight, out, version );
		if ( textKeys != NULL )
			NifStream( link_map[StaticCast<NiObject>(textKeys)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( cycleType, out, version );
	};
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
		NifStream( unknownInt0, out, version );
	};
	if ( version >= 0x0A01006A ) {
		NifStream( frequency, out, version );
		NifStream( startTime, out, version );
		NifStream( stopTime, out, version );
	};
	if ( ( version >= 0x0A020000 ) && ( version <= 0x0A020000 ) ) {
		NifStream( unknownFloat2, out, version );
	};
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
		NifStream( unknownByte, out, version );
	};
	if ( version >= 0x0A01006A ) {
		if ( manager != NULL )
			NifStream( link_map[StaticCast<NiObject>(manager)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( targetName, out, version );
	};
	if ( version >= 0x0A020000 ) {
		if ( stringPalette != NULL )
			NifStream( link_map[StaticCast<NiObject>(stringPalette)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiControllerSequence::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numControlledBlocks = uint(controlledBlocks.size());
	out << "  Name:  " << name << endl;
	out << "  Text Keys Name:  " << textKeysName << endl;
	out << "  Text Keys:  " << textKeys << endl;
	out << "  Num Controlled Blocks:  " << numControlledBlocks << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < controlledBlocks.size(); i1++) {
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
	out << "  Weight:  " << weight << endl;
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

void NiControllerSequence::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		textKeys = FixLink<NiTextKeyExtraData>( objects, link_stack, version );
	};
	for (uint i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( version <= 0x0A010000 ) {
			controlledBlocks[i1].controller = FixLink<NiTimeController>( objects, link_stack, version );
		};
		if ( version >= 0x0A01006A ) {
			controlledBlocks[i1].interpolator = FixLink<NiInterpolator>( objects, link_stack, version );
			controlledBlocks[i1].controller = FixLink<NiTimeController>( objects, link_stack, version );
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			controlledBlocks[i1].unknownLink2 = FixLink<NiObject>( objects, link_stack, version );
		};
		if ( version >= 0x0A020000 ) {
			controlledBlocks[i1].stringPalette = FixLink<NiStringPalette>( objects, link_stack, version );
		};
	};
	if ( version >= 0x0A01006A ) {
		textKeys = FixLink<NiTextKeyExtraData>( objects, link_stack, version );
		manager = FixLink<NiControllerManager>( objects, link_stack, version );
	};
	if ( version >= 0x0A020000 ) {
		stringPalette = FixLink<NiStringPalette>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiControllerSequence::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( textKeys != NULL )
		refs.push_back(StaticCast<NiObject>(textKeys));
	for (uint i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( controlledBlocks[i1].controller != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].controller));
		if ( controlledBlocks[i1].interpolator != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].interpolator));
		if ( controlledBlocks[i1].unknownLink2 != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].unknownLink2));
		if ( controlledBlocks[i1].stringPalette != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].stringPalette));
	};
	if ( stringPalette != NULL )
		refs.push_back(StaticCast<NiObject>(stringPalette));
	return refs;
}

void NiDefaultAVObjectPalette::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( unknownInt, in, version );
	NifStream( numObjs, in, version );
	objs.resize(numObjs);
	for (uint i1 = 0; i1 < objs.size(); i1++) {
		NifStream( objs[i1].name, in, version );
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiDefaultAVObjectPalette::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numObjs = uint(objs.size());
	NifStream( unknownInt, out, version );
	NifStream( numObjs, out, version );
	for (uint i1 = 0; i1 < objs.size(); i1++) {
		NifStream( objs[i1].name, out, version );
		if ( objs[i1].avObject != NULL )
			NifStream( link_map[StaticCast<NiObject>(objs[i1].avObject)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiDefaultAVObjectPalette::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numObjs = uint(objs.size());
	out << "  Unknown Int:  " << unknownInt << endl;
	out << "  Num Objs:  " << numObjs << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < objs.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Name:  " << objs[i1].name << endl;
		out << "    AV Object:  " << objs[i1].avObject << endl;
	};
	return out.str();
}

void NiDefaultAVObjectPalette::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < objs.size(); i1++) {
		objs[i1].avObject = FixLink<NiAVObject>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiDefaultAVObjectPalette::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	for (uint i1 = 0; i1 < objs.size(); i1++) {
	};
	return refs;
}

void NiDirectionalLight::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLight::Read( in, link_stack, version, user_version );
}

void NiDirectionalLight::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiLight::Write( out, link_map, version, user_version );
}

std::string NiDirectionalLight::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiLight::asString();
	return out.str();
}

void NiDirectionalLight::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLight::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiDirectionalLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLight::GetRefs();
	return refs;
}

void NiDitherProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
}

void NiDitherProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
}

std::string NiDitherProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiDitherProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiDitherProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiFlipController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiSingleInterpolatorController::Read( in, link_stack, version, user_version );
	NifStream( textureSlot, in, version );
	if ( version <= 0x0A010000 ) {
		NifStream( unknownInt2, in, version );
		NifStream( delta, in, version );
	};
	NifStream( numSources, in, version );
	sources.resize(numSources);
	for (uint i1 = 0; i1 < sources.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiFlipController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSingleInterpolatorController::Write( out, link_map, version, user_version );
	numSources = uint(sources.size());
	NifStream( textureSlot, out, version );
	if ( version <= 0x0A010000 ) {
		NifStream( unknownInt2, out, version );
		NifStream( delta, out, version );
	};
	NifStream( numSources, out, version );
	for (uint i1 = 0; i1 < sources.size(); i1++) {
		if ( sources[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(sources[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiFlipController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	numSources = uint(sources.size());
	out << "  Texture Slot:  " << textureSlot << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Delta:  " << delta << endl;
	out << "  Num Sources:  " << numSources << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < sources.size(); i1++) {
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
	return out.str();
}

void NiFlipController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < sources.size(); i1++) {
		sources[i1] = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiFlipController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	for (uint i1 = 0; i1 < sources.size(); i1++) {
		if ( sources[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(sources[i1]));
	};
	return refs;
}

void NiFloatData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::Read( in, link_stack, version, user_version );
	NifStream( data.numKeys, in, version );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, in, version );
	};
	data.keys.resize(data.numKeys);
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], in, version, data.interpolation );
	};
}

void NiFloatData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AKeyedData::Write( out, link_map, version, user_version );
	data.numKeys = uint(data.keys.size());
	NifStream( data.numKeys, out, version );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, out, version );
	};
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], out, version, data.interpolation );
	};
}

std::string NiFloatData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AKeyedData::asString();
	data.numKeys = uint(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
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

void NiFloatData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiFloatData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiFloatExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( floatData, in, version );
}

void NiFloatExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	NifStream( floatData, out, version );
}

std::string NiFloatExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Float Data:  " << floatData << endl;
	return out.str();
}

void NiFloatExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiFloatExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiFloatExtraDataController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	if ( version >= 0x14000004 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( unknownString, in, version );
	};
}

void NiFloatExtraDataController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	if ( version >= 0x14000004 ) {
		if ( unknownLink != NULL )
			NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( unknownString, out, version );
	};
}

std::string NiFloatExtraDataController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	out << "  Unknown String:  " << unknownString << endl;
	return out.str();
}

void NiFloatExtraDataController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x14000004 ) {
		unknownLink = FixLink<NiObject>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiFloatExtraDataController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiFloatInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( floatValue, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiFloatInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( floatValue, out, version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiFloatInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Float Value:  " << floatValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiFloatInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiFloatData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiFloatInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiFloatsExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( numFloats, in, version );
	data.resize(numFloats);
	for (uint i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], in, version );
	};
}

void NiFloatsExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	numFloats = uint(data.size());
	NifStream( numFloats, out, version );
	for (uint i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], out, version );
	};
}

std::string NiFloatsExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	numFloats = uint(data.size());
	out << "  Num Floats:  " << numFloats << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < data.size(); i1++) {
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

void NiFloatsExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiFloatsExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiFogProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
	NifStream( fogDepth, in, version );
	NifStream( fogColor, in, version );
}

void NiFogProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
	NifStream( fogDepth, out, version );
	NifStream( fogColor, out, version );
}

std::string NiFogProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Fog Depth:  " << fogDepth << endl;
	out << "  Fog Color:  " << fogColor << endl;
	return out.str();
}

void NiFogProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiFogProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiGeomMorpherController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknown, in, version );
	};
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
		NifStream( unknown2, in, version );
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( unknownByte, in, version );
	if ( version >= 0x0A01006A ) {
		NifStream( numInterpolators, in, version );
		interpolators.resize(numInterpolators);
		for (uint i2 = 0; i2 < interpolators.size(); i2++) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
	if ( version >= 0x0A020000 ) {
		NifStream( numUnknownInts, in, version );
		unknownInts.resize(numUnknownInts);
		for (uint i2 = 0; i2 < unknownInts.size(); i2++) {
			NifStream( unknownInts[i2], in, version );
		};
	};
}

void NiGeomMorpherController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	numUnknownInts = uint(unknownInts.size());
	numInterpolators = uint(interpolators.size());
	if ( version >= 0x0A010000 ) {
		NifStream( unknown, out, version );
	};
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
		NifStream( unknown2, out, version );
	};
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( unknownByte, out, version );
	if ( version >= 0x0A01006A ) {
		NifStream( numInterpolators, out, version );
		for (uint i2 = 0; i2 < interpolators.size(); i2++) {
			if ( interpolators[i2] != NULL )
				NifStream( link_map[StaticCast<NiObject>(interpolators[i2])], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
	if ( version >= 0x0A020000 ) {
		NifStream( numUnknownInts, out, version );
		for (uint i2 = 0; i2 < unknownInts.size(); i2++) {
			NifStream( unknownInts[i2], out, version );
		};
	};
}

std::string NiGeomMorpherController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	numUnknownInts = uint(unknownInts.size());
	numInterpolators = uint(interpolators.size());
	out << "  Unknown:  " << unknown << endl;
	out << "  Unknown 2:  " << unknown2 << endl;
	out << "  Data:  " << data << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Num Interpolators:  " << numInterpolators << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < interpolators.size(); i1++) {
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
	for (uint i1 = 0; i1 < unknownInts.size(); i1++) {
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

void NiGeomMorpherController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiMorphData>( objects, link_stack, version );
	if ( version >= 0x0A01006A ) {
		for (uint i2 = 0; i2 < interpolators.size(); i2++) {
			interpolators[i2] = FixLink<NiInterpolator>( objects, link_stack, version );
		};
	};
}

std::list<NiObjectRef> NiGeomMorpherController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	for (uint i1 = 0; i1 < interpolators.size(); i1++) {
		if ( interpolators[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(interpolators[i1]));
	};
	return refs;
}

void NiGravity::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( force, in, version );
	NifStream( type, in, version );
	NifStream( position, in, version );
	NifStream( direction, in, version );
}

void NiGravity::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( force, out, version );
	NifStream( type, out, version );
	NifStream( position, out, version );
	NifStream( direction, out, version );
}

std::string NiGravity::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Force:  " << force << endl;
	out << "  Type:  " << type << endl;
	out << "  Position:  " << position << endl;
	out << "  Direction:  " << direction << endl;
	return out.str();
}

void NiGravity::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiGravity::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiIntegerExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( integerData, in, version );
}

void NiIntegerExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	NifStream( integerData, out, version );
}

std::string NiIntegerExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Integer Data:  " << integerData << endl;
	return out.str();
}

void NiIntegerExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiIntegerExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiIntegersExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( numIntegers, in, version );
	data.resize(numIntegers);
	for (uint i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], in, version );
	};
}

void NiIntegersExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	numIntegers = uint(data.size());
	NifStream( numIntegers, out, version );
	for (uint i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], out, version );
	};
}

std::string NiIntegersExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	numIntegers = uint(data.size());
	out << "  Num Integers:  " << numIntegers << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < data.size(); i1++) {
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

void NiIntegersExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiIntegersExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiKeyframeController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiKeyframeController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiKeyframeController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiKeyframeController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiKeyframeData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiKeyframeController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void BSKeyframeController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiKeyframeController::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void BSKeyframeController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiKeyframeController::Write( out, link_map, version, user_version );
	if ( data2 != NULL )
		NifStream( link_map[StaticCast<NiObject>(data2)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string BSKeyframeController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiKeyframeController::asString();
	out << "  Data 2:  " << data2 << endl;
	return out.str();
}

void BSKeyframeController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiKeyframeController::FixLinks( objects, link_stack, version, user_version );
	data2 = FixLink<NiKeyframeData>( objects, link_stack, version );
}

std::list<NiObjectRef> BSKeyframeController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyframeController::GetRefs();
	if ( data2 != NULL )
		refs.push_back(StaticCast<NiObject>(data2));
	return refs;
}

void NiKeyframeData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::Read( in, link_stack, version, user_version );
	NifStream( numRotationKeys, in, version );
	if ( (numRotationKeys != 0) ) {
		NifStream( rotationType, in, version );
	};
	if ( (rotationType != 4) ) {
		quaternionKeys.resize(numRotationKeys);
		for (uint i2 = 0; i2 < quaternionKeys.size(); i2++) {
			NifStream( quaternionKeys[i2], in, version, rotationType );
		};
	};
	if ( version <= 0x0A010000 ) {
		if ( (rotationType == 4) ) {
			NifStream( unknownFloat, in, version );
		};
	};
	if ( (rotationType == 4) ) {
		for (uint i2 = 0; i2 < 3; i2++) {
			NifStream( xyzRotations[i2].numKeys, in, version );
			if ( (xyzRotations[i2].numKeys != 0) ) {
				NifStream( xyzRotations[i2].interpolation, in, version );
			};
			xyzRotations[i2].keys.resize(xyzRotations[i2].numKeys);
			for (uint i3 = 0; i3 < xyzRotations[i2].keys.size(); i3++) {
				NifStream( xyzRotations[i2].keys[i3], in, version, xyzRotations[i2].interpolation );
			};
		};
	};
	NifStream( translations.numKeys, in, version );
	if ( (translations.numKeys != 0) ) {
		NifStream( translations.interpolation, in, version );
	};
	translations.keys.resize(translations.numKeys);
	for (uint i1 = 0; i1 < translations.keys.size(); i1++) {
		NifStream( translations.keys[i1], in, version, translations.interpolation );
	};
	NifStream( scales.numKeys, in, version );
	if ( (scales.numKeys != 0) ) {
		NifStream( scales.interpolation, in, version );
	};
	scales.keys.resize(scales.numKeys);
	for (uint i1 = 0; i1 < scales.keys.size(); i1++) {
		NifStream( scales.keys[i1], in, version, scales.interpolation );
	};
}

void NiKeyframeData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AKeyedData::Write( out, link_map, version, user_version );
	NifStream( numRotationKeys, out, version );
	if ( (numRotationKeys != 0) ) {
		NifStream( rotationType, out, version );
	};
	if ( (rotationType != 4) ) {
		for (uint i2 = 0; i2 < quaternionKeys.size(); i2++) {
			NifStream( quaternionKeys[i2], out, version, rotationType );
		};
	};
	if ( version <= 0x0A010000 ) {
		if ( (rotationType == 4) ) {
			NifStream( unknownFloat, out, version );
		};
	};
	if ( (rotationType == 4) ) {
		for (uint i2 = 0; i2 < 3; i2++) {
			xyzRotations[i2].numKeys = uint(xyzRotations[i2].keys.size());
			NifStream( xyzRotations[i2].numKeys, out, version );
			if ( (xyzRotations[i2].numKeys != 0) ) {
				NifStream( xyzRotations[i2].interpolation, out, version );
			};
			for (uint i3 = 0; i3 < xyzRotations[i2].keys.size(); i3++) {
				NifStream( xyzRotations[i2].keys[i3], out, version, xyzRotations[i2].interpolation );
			};
		};
	};
	translations.numKeys = uint(translations.keys.size());
	NifStream( translations.numKeys, out, version );
	if ( (translations.numKeys != 0) ) {
		NifStream( translations.interpolation, out, version );
	};
	for (uint i1 = 0; i1 < translations.keys.size(); i1++) {
		NifStream( translations.keys[i1], out, version, translations.interpolation );
	};
	scales.numKeys = uint(scales.keys.size());
	NifStream( scales.numKeys, out, version );
	if ( (scales.numKeys != 0) ) {
		NifStream( scales.interpolation, out, version );
	};
	for (uint i1 = 0; i1 < scales.keys.size(); i1++) {
		NifStream( scales.keys[i1], out, version, scales.interpolation );
	};
}

std::string NiKeyframeData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AKeyedData::asString();
	out << "  Num Rotation Keys:  " << numRotationKeys << endl;
	if ( (numRotationKeys != 0) ) {
		out << "    Rotation Type:  " << rotationType << endl;
	};
	if ( (rotationType != 4) ) {
		array_output_count = 0;
		for (uint i2 = 0; i2 < quaternionKeys.size(); i2++) {
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
		for (uint i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			xyzRotations[i2].numKeys = uint(xyzRotations[i2].keys.size());
			out << "      Num Keys:  " << xyzRotations[i2].numKeys << endl;
			if ( (xyzRotations[i2].numKeys != 0) ) {
				out << "        Interpolation:  " << xyzRotations[i2].interpolation << endl;
			};
			array_output_count = 0;
			for (uint i3 = 0; i3 < xyzRotations[i2].keys.size(); i3++) {
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
	translations.numKeys = uint(translations.keys.size());
	out << "  Num Keys:  " << translations.numKeys << endl;
	if ( (translations.numKeys != 0) ) {
		out << "    Interpolation:  " << translations.interpolation << endl;
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < translations.keys.size(); i1++) {
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
	scales.numKeys = uint(scales.keys.size());
	out << "  Num Keys:  " << scales.numKeys << endl;
	if ( (scales.numKeys != 0) ) {
		out << "    Interpolation:  " << scales.interpolation << endl;
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < scales.keys.size(); i1++) {
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

void NiKeyframeData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiKeyframeData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiLightColorController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) {
		NifStream( unknownShort, in, version );
	};
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	if ( version >= 0x0A020000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( unknownShort, in, version );
	};
}

void NiLightColorController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) {
		NifStream( unknownShort, out, version );
	};
	if ( version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map[StaticCast<NiObject>(data)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( version >= 0x0A020000 ) {
		if ( interpolator != NULL )
			NifStream( link_map[StaticCast<NiObject>(interpolator)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( unknownShort, out, version );
	};
}

std::string NiLightColorController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Data:  " << data << endl;
	out << "  Interpolator:  " << interpolator << endl;
	return out.str();
}

void NiLightColorController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		data = FixLink<NiPosData>( objects, link_stack, version );
	};
	if ( version >= 0x0A020000 ) {
		interpolator = FixLink<NiPoint3Interpolator>( objects, link_stack, version );
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

void NiLightDimmerController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiLightDimmerController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	if ( unknownLink != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiLightDimmerController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiLightDimmerController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	unknownLink = FixLink<NiInterpolator>( objects, link_stack, version );
}

std::list<NiObjectRef> NiLightDimmerController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiLookAtController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknown1, in, version );
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiLookAtController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknown1, out, version );
	};
	if ( lookAtNode != NULL )
		NifStream( link_map[StaticCast<NiObject>(lookAtNode)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiLookAtController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown1:  " << unknown1 << endl;
	out << "  Look At Node:  " << lookAtNode << endl;
	return out.str();
}

void NiLookAtController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	lookAtNode = FixLink<NiNode>( objects, link_stack, version );
}

std::list<NiObjectRef> NiLookAtController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( lookAtNode != NULL )
		refs.push_back(StaticCast<NiObject>(lookAtNode));
	return refs;
}

void NiLookAtInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( unknownShort, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( unknownFloat, in, version );
	NifStream( translation, in, version );
	NifStream( rotation, in, version );
	NifStream( scale, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiLookAtInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( unknownShort, out, version );
	if ( lookAt != NULL )
		NifStream( link_map[StaticCast<NiObject>(lookAt)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( unknownFloat, out, version );
	NifStream( translation, out, version );
	NifStream( rotation, out, version );
	NifStream( scale, out, version );
	if ( unknownLink1 != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink1)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( unknownLink2 != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( unknownLink3 != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink3)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiLookAtInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiLookAtInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	lookAt = FixLink<NiNode>( objects, link_stack, version );
	unknownLink1 = FixLink<NiPoint3Interpolator>( objects, link_stack, version );
	unknownLink2 = FixLink<NiFloatInterpolator>( objects, link_stack, version );
	unknownLink3 = FixLink<NiFloatInterpolator>( objects, link_stack, version );
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

void NiMaterialColorController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiSingleInterpolatorController::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( targetColor, in, version );
	};
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiMaterialColorController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSingleInterpolatorController::Write( out, link_map, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( targetColor, out, version );
	};
	if ( version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map[StaticCast<NiObject>(data)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiMaterialColorController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Target Color:  " << targetColor << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiMaterialColorController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		data = FixLink<NiPosData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiMaterialColorController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiMaterialProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A000102 ) {
		NifStream( flags, in, version );
	};
	NifStream( ambientColor, in, version );
	NifStream( diffuseColor, in, version );
	NifStream( specularColor, in, version );
	NifStream( emissiveColor, in, version );
	NifStream( glossiness, in, version );
	NifStream( alpha, in, version );
}

void NiMaterialProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	if ( version <= 0x0A000102 ) {
		NifStream( flags, out, version );
	};
	NifStream( ambientColor, out, version );
	NifStream( diffuseColor, out, version );
	NifStream( specularColor, out, version );
	NifStream( emissiveColor, out, version );
	NifStream( glossiness, out, version );
	NifStream( alpha, out, version );
}

std::string NiMaterialProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiMaterialProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiMaterialProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiMeshPSysData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	APSysData::Read( in, link_stack, version, user_version );
	if ( version >= 0x14000005 ) {
		NifStream( unknownByte11, in, version );
	};
	if ( version <= 0x14000004 ) {
		unknownFloats4.resize(numVertices);
		for (uint i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (uint i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats4[i2][i3], in, version );
			};
		};
	};
	if ( version >= 0x14000005 ) {
		unknownFloats5.resize(numVertices);
		for (uint i2 = 0; i2 < unknownFloats5.size(); i2++) {
			for (uint i3 = 0; i3 < 12; i3++) {
				NifStream( unknownFloats5[i2][i3], in, version );
			};
		};
	};
	NifStream( unknownInt1, in, version );
	if ( version <= 0x14000004 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) {
		NifStream( unknownByte2, in, version );
		NifStream( numUnknownLinks, in, version );
		unknownLinks.resize(numUnknownLinks);
		for (uint i2 = 0; i2 < unknownLinks.size(); i2++) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
	if ( version >= 0x14000005 ) {
		NifStream( unknownShort4, in, version );
		NifStream( unknownInt2, in, version );
		NifStream( unknownByte12, in, version );
		NifStream( unknownInt3, in, version );
		NifStream( unknownInt4, in, version );
	};
	if ( version >= 0x0A020000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiMeshPSysData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysData::Write( out, link_map, version, user_version );
	numUnknownLinks = uint(unknownLinks.size());
	if ( version >= 0x14000005 ) {
		NifStream( unknownByte11, out, version );
	};
	if ( version <= 0x14000004 ) {
		for (uint i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (uint i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats4[i2][i3], out, version );
			};
		};
	};
	if ( version >= 0x14000005 ) {
		for (uint i2 = 0; i2 < unknownFloats5.size(); i2++) {
			for (uint i3 = 0; i3 < 12; i3++) {
				NifStream( unknownFloats5[i2][i3], out, version );
			};
		};
	};
	NifStream( unknownInt1, out, version );
	if ( version <= 0x14000004 ) {
		if ( modifier != NULL )
			NifStream( link_map[StaticCast<NiObject>(modifier)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) {
		NifStream( unknownByte2, out, version );
		NifStream( numUnknownLinks, out, version );
		for (uint i2 = 0; i2 < unknownLinks.size(); i2++) {
			if ( unknownLinks[i2] != NULL )
				NifStream( link_map[StaticCast<NiObject>(unknownLinks[i2])], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
	if ( version >= 0x14000005 ) {
		NifStream( unknownShort4, out, version );
		NifStream( unknownInt2, out, version );
		NifStream( unknownByte12, out, version );
		NifStream( unknownInt3, out, version );
		NifStream( unknownInt4, out, version );
	};
	if ( version >= 0x0A020000 ) {
		if ( unknownLink2 != NULL )
			NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiMeshPSysData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysData::asString();
	numUnknownLinks = uint(unknownLinks.size());
	out << "  Unknown Byte 11:  " << unknownByte11 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownFloats4.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 10; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 4[" << i2 << "]:  " << unknownFloats4[i1][i2] << endl;
			array_output_count++;
		};
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownFloats5.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 12; i2++) {
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
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) {
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

void NiMeshPSysData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysData::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x14000004 ) {
		modifier = FixLink<NiObject>( objects, link_stack, version );
	};
	if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) {
		for (uint i2 = 0; i2 < unknownLinks.size(); i2++) {
			unknownLinks[i2] = FixLink<NiObject>( objects, link_stack, version );
		};
	};
	if ( version >= 0x0A020000 ) {
		unknownLink2 = FixLink<NiNode>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiMeshPSysData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysData::GetRefs();
	if ( modifier != NULL )
		refs.push_back(StaticCast<NiObject>(modifier));
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( unknownLinks[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(unknownLinks[i1]));
	};
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	return refs;
}

void NiMorphData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( numMorphs, in, version );
	NifStream( numVertices, in, version );
	NifStream( unknownByte, in, version );
	morphs.resize(numMorphs);
	for (uint i1 = 0; i1 < morphs.size(); i1++) {
		if ( version >= 0x0A01006A ) {
			NifStream( morphs[i1].frameName, in, version );
		};
		if ( version <= 0x0A010000 ) {
			NifStream( morphs[i1].numKeys, in, version );
			NifStream( morphs[i1].interpolation, in, version );
			morphs[i1].keys.resize(morphs[i1].numKeys);
			for (uint i3 = 0; i3 < morphs[i1].keys.size(); i3++) {
				NifStream( morphs[i1].keys[i3], in, version, morphs[i1].interpolation );
			};
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( morphs[i1].unknownInt, in, version );
		};
		morphs[i1].vectors.resize(numVertices);
		for (uint i2 = 0; i2 < morphs[i1].vectors.size(); i2++) {
			NifStream( morphs[i1].vectors[i2], in, version );
		};
	};
}

void NiMorphData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numMorphs = uint(morphs.size());
	NifStream( numMorphs, out, version );
	NifStream( numVertices, out, version );
	NifStream( unknownByte, out, version );
	for (uint i1 = 0; i1 < morphs.size(); i1++) {
		morphs[i1].numKeys = uint(morphs[i1].keys.size());
		if ( version >= 0x0A01006A ) {
			NifStream( morphs[i1].frameName, out, version );
		};
		if ( version <= 0x0A010000 ) {
			NifStream( morphs[i1].numKeys, out, version );
			NifStream( morphs[i1].interpolation, out, version );
			for (uint i3 = 0; i3 < morphs[i1].keys.size(); i3++) {
				NifStream( morphs[i1].keys[i3], out, version, morphs[i1].interpolation );
			};
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			NifStream( morphs[i1].unknownInt, out, version );
		};
		for (uint i2 = 0; i2 < morphs[i1].vectors.size(); i2++) {
			NifStream( morphs[i1].vectors[i2], out, version );
		};
	};
}

std::string NiMorphData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numMorphs = uint(morphs.size());
	out << "  Num Morphs:  " << numMorphs << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < morphs.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		morphs[i1].numKeys = uint(morphs[i1].keys.size());
		out << "    Frame Name:  " << morphs[i1].frameName << endl;
		out << "    Num Keys:  " << morphs[i1].numKeys << endl;
		out << "    Interpolation:  " << morphs[i1].interpolation << endl;
		array_output_count = 0;
		for (uint i2 = 0; i2 < morphs[i1].keys.size(); i2++) {
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
		for (uint i2 = 0; i2 < morphs[i1].vectors.size(); i2++) {
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

void NiMorphData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiMorphData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiMultiTargetTransformController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	NifStream( numExtraTargets, in, version );
	extraTargets.resize(numExtraTargets);
	for (uint i1 = 0; i1 < extraTargets.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiMultiTargetTransformController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	numExtraTargets = ushort(extraTargets.size());
	NifStream( numExtraTargets, out, version );
	for (uint i1 = 0; i1 < extraTargets.size(); i1++) {
		if ( extraTargets[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(extraTargets[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiMultiTargetTransformController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	numExtraTargets = ushort(extraTargets.size());
	out << "  Num Extra Targets:  " << numExtraTargets << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < extraTargets.size(); i1++) {
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

void NiMultiTargetTransformController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < extraTargets.size(); i1++) {
		extraTargets[i1] = FixLink<NiNode>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiMultiTargetTransformController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	for (uint i1 = 0; i1 < extraTargets.size(); i1++) {
	};
	return refs;
}

void NiNode::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiAVObject::Read( in, link_stack, version, user_version );
	NifStream( numChildren, in, version );
	children.resize(numChildren);
	for (uint i1 = 0; i1 < children.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( numEffects, in, version );
	effects.resize(numEffects);
	for (uint i1 = 0; i1 < effects.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiNode::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiAVObject::Write( out, link_map, version, user_version );
	numEffects = uint(effects.size());
	numChildren = uint(children.size());
	NifStream( numChildren, out, version );
	for (uint i1 = 0; i1 < children.size(); i1++) {
		if ( children[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(children[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	NifStream( numEffects, out, version );
	for (uint i1 = 0; i1 < effects.size(); i1++) {
		if ( effects[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(effects[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiNode::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiAVObject::asString();
	numEffects = uint(effects.size());
	numChildren = uint(children.size());
	out << "  Num Children:  " << numChildren << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < children.size(); i1++) {
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
	for (uint i1 = 0; i1 < effects.size(); i1++) {
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

void NiNode::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAVObject::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < children.size(); i1++) {
		children[i1] = FixLink<NiAVObject>( objects, link_stack, version );
	};
	for (uint i1 = 0; i1 < effects.size(); i1++) {
		effects[i1] = FixLink<NiDynamicEffect>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAVObject::GetRefs();
	for (uint i1 = 0; i1 < children.size(); i1++) {
		if ( children[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(children[i1]));
	};
	for (uint i1 = 0; i1 < effects.size(); i1++) {
		if ( effects[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(effects[i1]));
	};
	return refs;
}

void AvoidNode::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::Read( in, link_stack, version, user_version );
}

void AvoidNode::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiNode::Write( out, link_map, version, user_version );
}

std::string AvoidNode::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiNode::asString();
	return out.str();
}

void AvoidNode::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> AvoidNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void FxWidget::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::Read( in, link_stack, version, user_version );
	NifStream( unknown1, in, version );
	for (uint i1 = 0; i1 < 292; i1++) {
		NifStream( unknown292Bytes[i1], in, version );
	};
}

void FxWidget::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiNode::Write( out, link_map, version, user_version );
	NifStream( unknown1, out, version );
	for (uint i1 = 0; i1 < 292; i1++) {
		NifStream( unknown292Bytes[i1], out, version );
	};
}

std::string FxWidget::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiNode::asString();
	out << "  Unknown1:  " << unknown1 << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < 292; i1++) {
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

void FxWidget::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> FxWidget::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void FxButton::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	FxWidget::Read( in, link_stack, version, user_version );
}

void FxButton::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	FxWidget::Write( out, link_map, version, user_version );
}

std::string FxButton::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << FxWidget::asString();
	return out.str();
}

void FxButton::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	FxWidget::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> FxButton::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = FxWidget::GetRefs();
	return refs;
}

void FxRadioButton::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	FxWidget::Read( in, link_stack, version, user_version );
	NifStream( unknownInt1, in, version );
	NifStream( unknownInt2, in, version );
	NifStream( unknownInt3, in, version );
	NifStream( numButtons, in, version );
	buttons.resize(numButtons);
	for (uint i1 = 0; i1 < buttons.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void FxRadioButton::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	FxWidget::Write( out, link_map, version, user_version );
	numButtons = uint(buttons.size());
	NifStream( unknownInt1, out, version );
	NifStream( unknownInt2, out, version );
	NifStream( unknownInt3, out, version );
	NifStream( numButtons, out, version );
	for (uint i1 = 0; i1 < buttons.size(); i1++) {
		if ( buttons[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(buttons[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string FxRadioButton::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << FxWidget::asString();
	numButtons = uint(buttons.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int  2:  " << unknownInt2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Num Buttons:  " << numButtons << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < buttons.size(); i1++) {
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

void FxRadioButton::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	FxWidget::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < buttons.size(); i1++) {
		buttons[i1] = FixLink<FxRadioButton>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> FxRadioButton::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = FxWidget::GetRefs();
	for (uint i1 = 0; i1 < buttons.size(); i1++) {
	};
	return refs;
}

void NiBillboardNode::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( billboardMode, in, version );
	};
}

void NiBillboardNode::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiNode::Write( out, link_map, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( billboardMode, out, version );
	};
}

std::string NiBillboardNode::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiNode::asString();
	out << "  Billboard Mode:  " << billboardMode << endl;
	return out.str();
}

void NiBillboardNode::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBillboardNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void NiBSAnimationNode::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::Read( in, link_stack, version, user_version );
}

void NiBSAnimationNode::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiNode::Write( out, link_map, version, user_version );
}

std::string NiBSAnimationNode::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiNode::asString();
	return out.str();
}

void NiBSAnimationNode::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSAnimationNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void NiBSParticleNode::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::Read( in, link_stack, version, user_version );
}

void NiBSParticleNode::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiNode::Write( out, link_map, version, user_version );
}

std::string NiBSParticleNode::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiNode::asString();
	return out.str();
}

void NiBSParticleNode::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSParticleNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

void NiLODNode::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiNode::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Bytes[i1], in, version );
	};
	if ( version <= 0x0A000100 ) {
		NifStream( lodCenter, in, version );
		NifStream( numLodLevels, in, version );
		lodLevels.resize(numLodLevels);
		for (uint i2 = 0; i2 < lodLevels.size(); i2++) {
			NifStream( lodLevels[i2].nearExtent, in, version );
			NifStream( lodLevels[i2].farExtent, in, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		NifStream( unknownShort, in, version );
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiLODNode::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiNode::Write( out, link_map, version, user_version );
	numLodLevels = uint(lodLevels.size());
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Bytes[i1], out, version );
	};
	if ( version <= 0x0A000100 ) {
		NifStream( lodCenter, out, version );
		NifStream( numLodLevels, out, version );
		for (uint i2 = 0; i2 < lodLevels.size(); i2++) {
			NifStream( lodLevels[i2].nearExtent, out, version );
			NifStream( lodLevels[i2].farExtent, out, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		NifStream( unknownShort, out, version );
		if ( lodLevelData != NULL )
			NifStream( link_map[StaticCast<NiObject>(lodLevelData)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiLODNode::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiNode::asString();
	numLodLevels = uint(lodLevels.size());
	array_output_count = 0;
	for (uint i1 = 0; i1 < 4; i1++) {
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
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Near Extent:  " << lodLevels[i1].nearExtent << endl;
		out << "    Far Extent:  " << lodLevels[i1].farExtent << endl;
	};
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  LOD Level Data:  " << lodLevelData << endl;
	return out.str();
}

void NiLODNode::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		lodLevelData = FixLink<NiLODData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiLODNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	if ( lodLevelData != NULL )
		refs.push_back(StaticCast<NiObject>(lodLevelData));
	return refs;
}

void NiPalette::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( unknownByte, in, version );
	NifStream( numEntries_, in, version );
	for (uint i1 = 0; i1 < 256; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			NifStream( palette[i1][i2], in, version );
		};
	};
}

void NiPalette::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	NifStream( unknownByte, out, version );
	NifStream( numEntries_, out, version );
	for (uint i1 = 0; i1 < 256; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			NifStream( palette[i1][i2], out, version );
		};
	};
}

std::string NiPalette::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Num Entries?:  " << numEntries_ << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < 256; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Palette[" << i2 << "]:  " << palette[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiPalette::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPalette::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiParticleBomb::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownFloat2, in, version );
	NifStream( unknownFloat3, in, version );
	NifStream( unknownFloat4, in, version );
	NifStream( unknownInt1, in, version );
	NifStream( unknownInt2, in, version );
	NifStream( unknownFloat5, in, version );
	NifStream( unknownFloat6, in, version );
	NifStream( unknownFloat7, in, version );
	NifStream( unknownFloat8, in, version );
	NifStream( unknownFloat9, in, version );
	NifStream( unknownFloat10, in, version );
}

void NiParticleBomb::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownFloat2, out, version );
	NifStream( unknownFloat3, out, version );
	NifStream( unknownFloat4, out, version );
	NifStream( unknownInt1, out, version );
	NifStream( unknownInt2, out, version );
	NifStream( unknownFloat5, out, version );
	NifStream( unknownFloat6, out, version );
	NifStream( unknownFloat7, out, version );
	NifStream( unknownFloat8, out, version );
	NifStream( unknownFloat9, out, version );
	NifStream( unknownFloat10, out, version );
}

std::string NiParticleBomb::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiParticleBomb::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiParticleBomb::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiParticleColorModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	AParticleModifier::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiParticleColorModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	if ( colorData != NULL )
		NifStream( link_map[StaticCast<NiObject>(colorData)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiParticleColorModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Color Data:  " << colorData << endl;
	return out.str();
}

void NiParticleColorModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
	colorData = FixLink<NiColorData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiParticleColorModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	if ( colorData != NULL )
		refs.push_back(StaticCast<NiObject>(colorData));
	return refs;
}

void NiParticleGrowFade::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::Read( in, link_stack, version, user_version );
	NifStream( grow, in, version );
	NifStream( fade, in, version );
}

void NiParticleGrowFade::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	NifStream( grow, out, version );
	NifStream( fade, out, version );
}

std::string NiParticleGrowFade::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Grow:  " << grow << endl;
	out << "  Fade:  " << fade << endl;
	return out.str();
}

void NiParticleGrowFade::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiParticleGrowFade::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiParticleMeshModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	AParticleModifier::Read( in, link_stack, version, user_version );
	NifStream( numParticleMeshes, in, version );
	particleMeshes.resize(numParticleMeshes);
	for (uint i1 = 0; i1 < particleMeshes.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiParticleMeshModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	numParticleMeshes = uint(particleMeshes.size());
	NifStream( numParticleMeshes, out, version );
	for (uint i1 = 0; i1 < particleMeshes.size(); i1++) {
		if ( particleMeshes[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(particleMeshes[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiParticleMeshModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AParticleModifier::asString();
	numParticleMeshes = uint(particleMeshes.size());
	out << "  Num Particle Meshes:  " << numParticleMeshes << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < particleMeshes.size(); i1++) {
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

void NiParticleMeshModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < particleMeshes.size(); i1++) {
		particleMeshes[i1] = FixLink<NiAVObject>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiParticleMeshModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	for (uint i1 = 0; i1 < particleMeshes.size(); i1++) {
		if ( particleMeshes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(particleMeshes[i1]));
	};
	return refs;
}

void NiParticleRotation::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::Read( in, link_stack, version, user_version );
	NifStream( unknownByte, in, version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownFloat2, in, version );
	NifStream( unknownFloat3, in, version );
	NifStream( unknownFloat4, in, version );
}

void NiParticleRotation::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	NifStream( unknownByte, out, version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownFloat2, out, version );
	NifStream( unknownFloat3, out, version );
	NifStream( unknownFloat4, out, version );
}

std::string NiParticleRotation::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AParticleModifier::asString();
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	return out.str();
}

void NiParticleRotation::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiParticleRotation::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiParticles::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometry::Read( in, link_stack, version, user_version );
}

void NiParticles::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiGeometry::Write( out, link_map, version, user_version );
}

std::string NiParticles::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiGeometry::asString();
	return out.str();
}

void NiParticles::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiGeometry::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiParticles::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiGeometry::GetRefs();
	return refs;
}

void NiAutoNormalParticles::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticles::Read( in, link_stack, version, user_version );
}

void NiAutoNormalParticles::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiParticles::Write( out, link_map, version, user_version );
}

std::string NiAutoNormalParticles::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiParticles::asString();
	return out.str();
}

void NiAutoNormalParticles::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticles::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiAutoNormalParticles::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	return refs;
}

void NiParticleMeshes::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticles::Read( in, link_stack, version, user_version );
}

void NiParticleMeshes::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiParticles::Write( out, link_map, version, user_version );
}

std::string NiParticleMeshes::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiParticles::asString();
	return out.str();
}

void NiParticleMeshes::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticles::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiParticleMeshes::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	return refs;
}

void NiParticlesData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAutoNormalParticlesData::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( numActive, in, version );
		NifStream( hasUnknownFloats, in, version );
		if ( (hasUnknownFloats != 0) ) {
			unknownFloats.resize(numVertices);
			for (uint i3 = 0; i3 < unknownFloats.size(); i3++) {
				NifStream( unknownFloats[i3], in, version );
			};
		};
	};
	NifStream( hasRotations, in, version );
	if ( (hasRotations != 0) ) {
		rotations.resize(numVertices);
		for (uint i2 = 0; i2 < rotations.size(); i2++) {
			NifStream( rotations[i2], in, version );
		};
	};
}

void NiParticlesData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiAutoNormalParticlesData::Write( out, link_map, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( numActive, out, version );
		NifStream( hasUnknownFloats, out, version );
		if ( (hasUnknownFloats != 0) ) {
			for (uint i3 = 0; i3 < unknownFloats.size(); i3++) {
				NifStream( unknownFloats[i3], out, version );
			};
		};
	};
	NifStream( hasRotations, out, version );
	if ( (hasRotations != 0) ) {
		for (uint i2 = 0; i2 < rotations.size(); i2++) {
			NifStream( rotations[i2], out, version );
		};
	};
}

std::string NiParticlesData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiAutoNormalParticlesData::asString();
	out << "  Num Active:  " << numActive << endl;
	out << "  Has Unknown Floats:  " << hasUnknownFloats << endl;
	if ( (hasUnknownFloats != 0) ) {
		array_output_count = 0;
		for (uint i2 = 0; i2 < unknownFloats.size(); i2++) {
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
		for (uint i2 = 0; i2 < rotations.size(); i2++) {
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

void NiParticlesData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAutoNormalParticlesData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiParticlesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiAutoNormalParticlesData::GetRefs();
	return refs;
}

void NiParticleMeshesData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiParticlesData::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiParticleMeshesData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiParticlesData::Write( out, link_map, version, user_version );
	if ( unknownLink2 != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiParticleMeshesData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiParticlesData::asString();
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	return out.str();
}

void NiParticleMeshesData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticlesData::FixLinks( objects, link_stack, version, user_version );
	unknownLink2 = FixLink<NiAVObject>( objects, link_stack, version );
}

std::list<NiObjectRef> NiParticleMeshesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticlesData::GetRefs();
	if ( unknownLink2 != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink2));
	return refs;
}

void NiParticleSystem::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiParticles::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknownBool, in, version );
		NifStream( numModifiers, in, version );
		modifiers.resize(numModifiers);
		for (uint i2 = 0; i2 < modifiers.size(); i2++) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
}

void NiParticleSystem::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiParticles::Write( out, link_map, version, user_version );
	numModifiers = uint(modifiers.size());
	if ( version >= 0x0A010000 ) {
		NifStream( unknownBool, out, version );
		NifStream( numModifiers, out, version );
		for (uint i2 = 0; i2 < modifiers.size(); i2++) {
			if ( modifiers[i2] != NULL )
				NifStream( link_map[StaticCast<NiObject>(modifiers[i2])], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
}

std::string NiParticleSystem::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiParticles::asString();
	numModifiers = uint(modifiers.size());
	out << "  Unknown Bool:  " << unknownBool << endl;
	out << "  Num Modifiers:  " << numModifiers << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < modifiers.size(); i1++) {
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

void NiParticleSystem::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticles::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		for (uint i2 = 0; i2 < modifiers.size(); i2++) {
			modifiers[i2] = FixLink<NiPSysModifier>( objects, link_stack, version );
		};
	};
}

std::list<NiObjectRef> NiParticleSystem::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	for (uint i1 = 0; i1 < modifiers.size(); i1++) {
		if ( modifiers[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(modifiers[i1]));
	};
	return refs;
}

void NiMeshParticleSystem::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticleSystem::Read( in, link_stack, version, user_version );
}

void NiMeshParticleSystem::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiParticleSystem::Write( out, link_map, version, user_version );
}

std::string NiMeshParticleSystem::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiParticleSystem::asString();
	return out.str();
}

void NiMeshParticleSystem::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticleSystem::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiMeshParticleSystem::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticleSystem::GetRefs();
	return refs;
}

void NiParticleSystemController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	NifStream( speed, in, version );
	NifStream( speedRandom, in, version );
	NifStream( verticalDirection, in, version );
	NifStream( verticalAngle, in, version );
	NifStream( horizontalDirection, in, version );
	NifStream( horizontalAngle, in, version );
	NifStream( unknownFloat5, in, version );
	NifStream( unknownFloat6, in, version );
	NifStream( unknownFloat7, in, version );
	NifStream( unknownFloat8, in, version );
	NifStream( unknownFloat9, in, version );
	NifStream( unknownFloat10, in, version );
	NifStream( unknownFloat11, in, version );
	NifStream( size, in, version );
	NifStream( emitStartTime, in, version );
	NifStream( emitStopTime, in, version );
	NifStream( unknownByte, in, version );
	NifStream( emitRate, in, version );
	NifStream( lifetime, in, version );
	NifStream( lifetimeRandom, in, version );
	NifStream( emitFlags, in, version );
	NifStream( startRandom, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( unknownShort2_, in, version );
	NifStream( unknownFloat13_, in, version );
	NifStream( unknownInt1_, in, version );
	NifStream( unknownInt2_, in, version );
	NifStream( unknownShort3_, in, version );
	NifStream( numParticles, in, version );
	NifStream( numValid, in, version );
	particles.resize(numParticles);
	for (uint i1 = 0; i1 < particles.size(); i1++) {
		NifStream( particles[i1].velocity, in, version );
		NifStream( particles[i1].unknownVector, in, version );
		NifStream( particles[i1].lifetime, in, version );
		NifStream( particles[i1].lifespan, in, version );
		NifStream( particles[i1].timestamp, in, version );
		NifStream( particles[i1].unknownShort, in, version );
		NifStream( particles[i1].vertexId, in, version );
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( trailer, in, version );
}

void NiParticleSystemController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	numParticles = ushort(particles.size());
	NifStream( speed, out, version );
	NifStream( speedRandom, out, version );
	NifStream( verticalDirection, out, version );
	NifStream( verticalAngle, out, version );
	NifStream( horizontalDirection, out, version );
	NifStream( horizontalAngle, out, version );
	NifStream( unknownFloat5, out, version );
	NifStream( unknownFloat6, out, version );
	NifStream( unknownFloat7, out, version );
	NifStream( unknownFloat8, out, version );
	NifStream( unknownFloat9, out, version );
	NifStream( unknownFloat10, out, version );
	NifStream( unknownFloat11, out, version );
	NifStream( size, out, version );
	NifStream( emitStartTime, out, version );
	NifStream( emitStopTime, out, version );
	NifStream( unknownByte, out, version );
	NifStream( emitRate, out, version );
	NifStream( lifetime, out, version );
	NifStream( lifetimeRandom, out, version );
	NifStream( emitFlags, out, version );
	NifStream( startRandom, out, version );
	if ( emitter != NULL )
		NifStream( link_map[StaticCast<NiObject>(emitter)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( unknownShort2_, out, version );
	NifStream( unknownFloat13_, out, version );
	NifStream( unknownInt1_, out, version );
	NifStream( unknownInt2_, out, version );
	NifStream( unknownShort3_, out, version );
	NifStream( numParticles, out, version );
	NifStream( numValid, out, version );
	for (uint i1 = 0; i1 < particles.size(); i1++) {
		NifStream( particles[i1].velocity, out, version );
		NifStream( particles[i1].unknownVector, out, version );
		NifStream( particles[i1].lifetime, out, version );
		NifStream( particles[i1].lifespan, out, version );
		NifStream( particles[i1].timestamp, out, version );
		NifStream( particles[i1].unknownShort, out, version );
		NifStream( particles[i1].vertexId, out, version );
	};
	if ( unknownLink != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( particleExtra != NULL )
		NifStream( link_map[StaticCast<NiObject>(particleExtra)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( unknownLink2 != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( trailer, out, version );
}

std::string NiParticleSystemController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	numParticles = ushort(particles.size());
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
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Num Valid:  " << numValid << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < particles.size(); i1++) {
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
	return out.str();
}

void NiParticleSystemController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	emitter = FixLink<NiObject>( objects, link_stack, version );
	unknownLink = FixLink<NiObject>( objects, link_stack, version );
	particleExtra = FixLink<AParticleModifier>( objects, link_stack, version );
	unknownLink2 = FixLink<NiObject>( objects, link_stack, version );
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
	return refs;
}

void NiBSPArrayController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticleSystemController::Read( in, link_stack, version, user_version );
}

void NiBSPArrayController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiParticleSystemController::Write( out, link_map, version, user_version );
}

std::string NiBSPArrayController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiParticleSystemController::asString();
	return out.str();
}

void NiBSPArrayController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticleSystemController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSPArrayController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticleSystemController::GetRefs();
	return refs;
}

void NiPathController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknownShort2, in, version );
	};
	NifStream( unknownInt1, in, version );
	NifStream( unknownInt2, in, version );
	NifStream( unknownInt3, in, version );
	NifStream( unknownShort, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiPathController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknownShort2, out, version );
	};
	NifStream( unknownInt1, out, version );
	NifStream( unknownInt2, out, version );
	NifStream( unknownInt3, out, version );
	NifStream( unknownShort, out, version );
	if ( posData != NULL )
		NifStream( link_map[StaticCast<NiObject>(posData)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( floatData != NULL )
		NifStream( link_map[StaticCast<NiObject>(floatData)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiPathController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiPathController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	posData = FixLink<NiPosData>( objects, link_stack, version );
	floatData = FixLink<NiFloatData>( objects, link_stack, version );
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

void NiPathInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiBlendInterpolator::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownFloat2, in, version );
	NifStream( unknownShort2, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiPathInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBlendInterpolator::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownFloat2, out, version );
	NifStream( unknownShort2, out, version );
	if ( posData != NULL )
		NifStream( link_map[StaticCast<NiObject>(posData)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( floatData != NULL )
		NifStream( link_map[StaticCast<NiObject>(floatData)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiPathInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Pos Data:  " << posData << endl;
	out << "  Float Data:  " << floatData << endl;
	return out.str();
}

void NiPathInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version );
	posData = FixLink<NiPosData>( objects, link_stack, version );
	floatData = FixLink<NiFloatData>( objects, link_stack, version );
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

void NiPixelData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( pixelFormat, in, version );
	if ( version <= 0x0A020000 ) {
		NifStream( redMask, in, version );
		NifStream( greenMask, in, version );
		NifStream( blueMask, in, version );
		NifStream( alphaMask, in, version );
		NifStream( bitsPerPixel, in, version );
		for (uint i2 = 0; i2 < 8; i2++) {
			NifStream( unknown8Bytes[i2], in, version );
		};
	};
	if ( ( version >= 0x0A010000 ) && ( version <= 0x0A020000 ) ) {
		NifStream( unknownInt, in, version );
	};
	if ( version >= 0x14000004 ) {
		for (uint i2 = 0; i2 < 54; i2++) {
			NifStream( unknown54Bytes[i2], in, version );
		};
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( numMipmaps, in, version );
	NifStream( bytesPerPixel, in, version );
	mipmaps.resize(numMipmaps);
	for (uint i1 = 0; i1 < mipmaps.size(); i1++) {
		NifStream( mipmaps[i1].width, in, version );
		NifStream( mipmaps[i1].height, in, version );
		NifStream( mipmaps[i1].offset, in, version );
	};
	NifStream( pixelData.dataSize, in, version );
	pixelData.data.resize(pixelData.dataSize);
	for (uint i1 = 0; i1 < pixelData.data.size(); i1++) {
		NifStream( pixelData.data[i1], in, version );
	};
	if ( version >= 0x14000004 ) {
		NifStream( unknownInt2, in, version );
	};
}

void NiPixelData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numMipmaps = uint(mipmaps.size());
	NifStream( pixelFormat, out, version );
	if ( version <= 0x0A020000 ) {
		NifStream( redMask, out, version );
		NifStream( greenMask, out, version );
		NifStream( blueMask, out, version );
		NifStream( alphaMask, out, version );
		NifStream( bitsPerPixel, out, version );
		for (uint i2 = 0; i2 < 8; i2++) {
			NifStream( unknown8Bytes[i2], out, version );
		};
	};
	if ( ( version >= 0x0A010000 ) && ( version <= 0x0A020000 ) ) {
		NifStream( unknownInt, out, version );
	};
	if ( version >= 0x14000004 ) {
		for (uint i2 = 0; i2 < 54; i2++) {
			NifStream( unknown54Bytes[i2], out, version );
		};
	};
	if ( palette != NULL )
		NifStream( link_map[StaticCast<NiObject>(palette)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( numMipmaps, out, version );
	NifStream( bytesPerPixel, out, version );
	for (uint i1 = 0; i1 < mipmaps.size(); i1++) {
		NifStream( mipmaps[i1].width, out, version );
		NifStream( mipmaps[i1].height, out, version );
		NifStream( mipmaps[i1].offset, out, version );
	};
	pixelData.dataSize = uint(pixelData.data.size());
	NifStream( pixelData.dataSize, out, version );
	for (uint i1 = 0; i1 < pixelData.data.size(); i1++) {
		NifStream( pixelData.data[i1], out, version );
	};
	if ( version >= 0x14000004 ) {
		NifStream( unknownInt2, out, version );
	};
}

std::string NiPixelData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numMipmaps = uint(mipmaps.size());
	out << "  Pixel Format:  " << pixelFormat << endl;
	out << "  Red Mask:  " << redMask << endl;
	out << "  Green Mask:  " << greenMask << endl;
	out << "  Blue Mask:  " << blueMask << endl;
	out << "  Alpha Mask:  " << alphaMask << endl;
	out << "  Bits Per Pixel:  " << bitsPerPixel << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < 8; i1++) {
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
	for (uint i1 = 0; i1 < 54; i1++) {
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
	for (uint i1 = 0; i1 < mipmaps.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Width:  " << mipmaps[i1].width << endl;
		out << "    Height:  " << mipmaps[i1].height << endl;
		out << "    Offset:  " << mipmaps[i1].offset << endl;
	};
	pixelData.dataSize = uint(pixelData.data.size());
	out << "  Data Size:  " << pixelData.dataSize << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < pixelData.data.size(); i1++) {
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

void NiPixelData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	palette = FixLink<NiPalette>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPixelData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( palette != NULL )
		refs.push_back(StaticCast<NiObject>(palette));
	return refs;
}

void NiPlanarCollider::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::Read( in, link_stack, version, user_version );
	if ( version >= 0x0A000100 ) {
		NifStream( unknownShort, in, version );
	};
	NifStream( unknownFloat1, in, version );
	NifStream( unknownFloat2, in, version );
	if ( ( version >= 0x04020200 ) && ( version <= 0x04020200 ) ) {
		NifStream( unknownShort2, in, version );
	};
	NifStream( unknownFloat3, in, version );
	NifStream( unknownFloat4, in, version );
	NifStream( unknownFloat5, in, version );
	NifStream( unknownFloat6, in, version );
	NifStream( unknownFloat7, in, version );
	NifStream( unknownFloat8, in, version );
	NifStream( unknownFloat9, in, version );
	NifStream( unknownFloat10, in, version );
	NifStream( unknownFloat11, in, version );
	NifStream( unknownFloat12, in, version );
	NifStream( unknownFloat13, in, version );
	NifStream( unknownFloat14, in, version );
	NifStream( unknownFloat15, in, version );
	NifStream( unknownFloat16, in, version );
}

void NiPlanarCollider::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	if ( version >= 0x0A000100 ) {
		NifStream( unknownShort, out, version );
	};
	NifStream( unknownFloat1, out, version );
	NifStream( unknownFloat2, out, version );
	if ( ( version >= 0x04020200 ) && ( version <= 0x04020200 ) ) {
		NifStream( unknownShort2, out, version );
	};
	NifStream( unknownFloat3, out, version );
	NifStream( unknownFloat4, out, version );
	NifStream( unknownFloat5, out, version );
	NifStream( unknownFloat6, out, version );
	NifStream( unknownFloat7, out, version );
	NifStream( unknownFloat8, out, version );
	NifStream( unknownFloat9, out, version );
	NifStream( unknownFloat10, out, version );
	NifStream( unknownFloat11, out, version );
	NifStream( unknownFloat12, out, version );
	NifStream( unknownFloat13, out, version );
	NifStream( unknownFloat14, out, version );
	NifStream( unknownFloat15, out, version );
	NifStream( unknownFloat16, out, version );
}

std::string NiPlanarCollider::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiPlanarCollider::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPlanarCollider::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiPoint3Interpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( point3Value, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiPoint3Interpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( point3Value, out, version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiPoint3Interpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Point 3 Value:  " << point3Value << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiPoint3Interpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiPosData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPoint3Interpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiPointLight::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLight::Read( in, link_stack, version, user_version );
	NifStream( constantAttenuation, in, version );
	NifStream( linearAttenuation, in, version );
	NifStream( quadraticAttenuation, in, version );
}

void NiPointLight::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiLight::Write( out, link_map, version, user_version );
	NifStream( constantAttenuation, out, version );
	NifStream( linearAttenuation, out, version );
	NifStream( quadraticAttenuation, out, version );
}

std::string NiPointLight::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiLight::asString();
	out << "  Constant Attenuation:  " << constantAttenuation << endl;
	out << "  Linear Attenuation:  " << linearAttenuation << endl;
	out << "  Quadratic Attenuation:  " << quadraticAttenuation << endl;
	return out.str();
}

void NiPointLight::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLight::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPointLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLight::GetRefs();
	return refs;
}

void NiPosData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::Read( in, link_stack, version, user_version );
	NifStream( data.numKeys, in, version );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, in, version );
	};
	data.keys.resize(data.numKeys);
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], in, version, data.interpolation );
	};
}

void NiPosData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AKeyedData::Write( out, link_map, version, user_version );
	data.numKeys = uint(data.keys.size());
	NifStream( data.numKeys, out, version );
	if ( (data.numKeys != 0) ) {
		NifStream( data.interpolation, out, version );
	};
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		NifStream( data.keys[i1], out, version, data.interpolation );
	};
}

std::string NiPosData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AKeyedData::asString();
	data.numKeys = uint(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
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

void NiPosData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPosData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiPSysAgeDeathModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( spawnOnDeath, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiPSysAgeDeathModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	NifStream( spawnOnDeath, out, version );
	if ( spawnModifier != NULL )
		NifStream( link_map[StaticCast<NiObject>(spawnModifier)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiPSysAgeDeathModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Spawn on Death:  " << spawnOnDeath << endl;
	out << "  Spawn Modifier:  " << spawnModifier << endl;
	return out.str();
}

void NiPSysAgeDeathModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	spawnModifier = FixLink<NiPSysSpawnModifier>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPSysAgeDeathModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	if ( spawnModifier != NULL )
		refs.push_back(StaticCast<NiObject>(spawnModifier));
	return refs;
}

void NiPSysBombModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	for (uint i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts1[i1], in, version );
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
	for (uint i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts2[i1], in, version );
	};
}

void NiPSysBombModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	if ( unknownLink != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	for (uint i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts1[i1], out, version );
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
	for (uint i1 = 0; i1 < 2; i1++) {
		NifStream( unknownInts2[i1], out, version );
	};
}

std::string NiPSysBombModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < 2; i1++) {
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
	for (uint i1 = 0; i1 < 3; i1++) {
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
	for (uint i1 = 0; i1 < 2; i1++) {
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

void NiPSysBombModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	unknownLink = FixLink<NiNode>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPSysBombModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysBoundUpdateModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( updateSkip, in, version );
}

void NiPSysBoundUpdateModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	NifStream( updateSkip, out, version );
}

std::string NiPSysBoundUpdateModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Update Skip:  " << updateSkip << endl;
	return out.str();
}

void NiPSysBoundUpdateModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysBoundUpdateModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysBoxEmitter::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysVolumeEmitter::Read( in, link_stack, version, user_version );
	NifStream( width, in, version );
	NifStream( height, in, version );
	NifStream( depth, in, version );
}

void NiPSysBoxEmitter::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysVolumeEmitter::Write( out, link_map, version, user_version );
	NifStream( width, out, version );
	NifStream( height, out, version );
	NifStream( depth, out, version );
}

std::string NiPSysBoxEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysVolumeEmitter::asString();
	out << "  Width:  " << width << endl;
	out << "  Height:  " << height << endl;
	out << "  Depth:  " << depth << endl;
	return out.str();
}

void NiPSysBoxEmitter::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysVolumeEmitter::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysBoxEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysVolumeEmitter::GetRefs();
	return refs;
}

void NiPSysColliderManager::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiPSysColliderManager::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	if ( collider != NULL )
		NifStream( link_map[StaticCast<NiObject>(collider)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiPSysColliderManager::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Collider:  " << collider << endl;
	return out.str();
}

void NiPSysColliderManager::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	collider = FixLink<NiPSysPlanarCollider>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPSysColliderManager::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	if ( collider != NULL )
		refs.push_back(StaticCast<NiObject>(collider));
	return refs;
}

void NiPSysColorModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiPSysColorModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiPSysColorModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiPSysColorModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiColorData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPSysColorModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiPSysCylinderEmitter::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysVolumeEmitter::Read( in, link_stack, version, user_version );
	NifStream( radius, in, version );
	NifStream( height, in, version );
}

void NiPSysCylinderEmitter::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysVolumeEmitter::Write( out, link_map, version, user_version );
	NifStream( radius, out, version );
	NifStream( height, out, version );
}

std::string NiPSysCylinderEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysVolumeEmitter::asString();
	out << "  Radius:  " << radius << endl;
	out << "  Height:  " << height << endl;
	return out.str();
}

void NiPSysCylinderEmitter::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysVolumeEmitter::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysCylinderEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysVolumeEmitter::GetRefs();
	return refs;
}

void NiPSysData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysData::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A020000 ) {
		unknownFloats4.resize(numVertices);
		for (uint i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (uint i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats4[i2][i3], in, version );
			};
		};
	};
	if ( version >= 0x14000004 ) {
		NifStream( unknownBool1, in, version );
		if ( (unknownBool1 != 0) ) {
			unknownBytes.resize(numVertices);
			for (uint i3 = 0; i3 < unknownBytes.size(); i3++) {
				for (uint i4 = 0; i4 < 32; i4++) {
					NifStream( unknownBytes[i3][i4], in, version );
				};
			};
		};
		if ( (unknownBool1 == 0) ) {
			unknownBytesAlt.resize(numVertices);
			for (uint i3 = 0; i3 < unknownBytesAlt.size(); i3++) {
				for (uint i4 = 0; i4 < 28; i4++) {
					NifStream( unknownBytesAlt[i3][i4], in, version );
				};
			};
		};
		NifStream( unknownByte3, in, version );
		NifStream( unknownBool2, in, version );
		if ( (unknownBool2 != 0) ) {
			unknownBytes2.resize(numVertices);
			for (uint i3 = 0; i3 < unknownBytes2.size(); i3++) {
				for (uint i4 = 0; i4 < 4; i4++) {
					NifStream( unknownBytes2[i3][i4], in, version );
				};
			};
		};
	};
	NifStream( unknownInt1, in, version );
}

void NiPSysData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysData::Write( out, link_map, version, user_version );
	if ( version <= 0x0A020000 ) {
		for (uint i2 = 0; i2 < unknownFloats4.size(); i2++) {
			for (uint i3 = 0; i3 < 10; i3++) {
				NifStream( unknownFloats4[i2][i3], out, version );
			};
		};
	};
	if ( version >= 0x14000004 ) {
		NifStream( unknownBool1, out, version );
		if ( (unknownBool1 != 0) ) {
			for (uint i3 = 0; i3 < unknownBytes.size(); i3++) {
				for (uint i4 = 0; i4 < 32; i4++) {
					NifStream( unknownBytes[i3][i4], out, version );
				};
			};
		};
		if ( (unknownBool1 == 0) ) {
			for (uint i3 = 0; i3 < unknownBytesAlt.size(); i3++) {
				for (uint i4 = 0; i4 < 28; i4++) {
					NifStream( unknownBytesAlt[i3][i4], out, version );
				};
			};
		};
		NifStream( unknownByte3, out, version );
		NifStream( unknownBool2, out, version );
		if ( (unknownBool2 != 0) ) {
			for (uint i3 = 0; i3 < unknownBytes2.size(); i3++) {
				for (uint i4 = 0; i4 < 4; i4++) {
					NifStream( unknownBytes2[i3][i4], out, version );
				};
			};
		};
	};
	NifStream( unknownInt1, out, version );
}

std::string NiPSysData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysData::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownFloats4.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 10; i2++) {
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
		for (uint i2 = 0; i2 < unknownBytes.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (uint i3 = 0; i3 < 32; i3++) {
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
		for (uint i2 = 0; i2 < unknownBytesAlt.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (uint i3 = 0; i3 < 28; i3++) {
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
		for (uint i2 = 0; i2 < unknownBytes2.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (uint i3 = 0; i3 < 4; i3++) {
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

void NiPSysData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysData::GetRefs();
	return refs;
}

void NiPSysDragModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( dragAxis, in, version );
	NifStream( percentage, in, version );
	NifStream( range, in, version );
	NifStream( rangeFalloff, in, version );
}

void NiPSysDragModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	if ( parent != NULL )
		NifStream( link_map[StaticCast<NiObject>(parent)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( dragAxis, out, version );
	NifStream( percentage, out, version );
	NifStream( range, out, version );
	NifStream( rangeFalloff, out, version );
}

std::string NiPSysDragModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Parent:  " << parent << endl;
	out << "  Drag Axis:  " << dragAxis << endl;
	out << "  Percentage:  " << percentage << endl;
	out << "  Range:  " << range << endl;
	out << "  Range Falloff:  " << rangeFalloff << endl;
	return out.str();
}

void NiPSysDragModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	parent = FixLink<NiObject>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPSysDragModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysEmitterCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	APSysCtlr::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	if ( version >= 0x0A020000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiPSysEmitterCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
	if ( version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map[StaticCast<NiObject>(data)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( version >= 0x0A020000 ) {
		if ( visibilityInterpolator != NULL )
			NifStream( link_map[StaticCast<NiObject>(visibilityInterpolator)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiPSysEmitterCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Data:  " << data << endl;
	out << "  Visibility Interpolator:  " << visibilityInterpolator << endl;
	return out.str();
}

void NiPSysEmitterCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		data = FixLink<NiPSysEmitterCtlrData>( objects, link_stack, version );
	};
	if ( version >= 0x0A020000 ) {
		visibilityInterpolator = FixLink<NiInterpolator>( objects, link_stack, version );
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

void NiPSysEmitterCtlrData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( floatKeys_.numKeys, in, version );
	if ( (floatKeys_.numKeys != 0) ) {
		NifStream( floatKeys_.interpolation, in, version );
	};
	floatKeys_.keys.resize(floatKeys_.numKeys);
	for (uint i1 = 0; i1 < floatKeys_.keys.size(); i1++) {
		NifStream( floatKeys_.keys[i1], in, version, floatKeys_.interpolation );
	};
	NifStream( numVisibilityKeys_, in, version );
	visibilityKeys_.resize(numVisibilityKeys_);
	for (uint i1 = 0; i1 < visibilityKeys_.size(); i1++) {
		NifStream( visibilityKeys_[i1], in, version, 1 );
	};
}

void NiPSysEmitterCtlrData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numVisibilityKeys_ = uint(visibilityKeys_.size());
	floatKeys_.numKeys = uint(floatKeys_.keys.size());
	NifStream( floatKeys_.numKeys, out, version );
	if ( (floatKeys_.numKeys != 0) ) {
		NifStream( floatKeys_.interpolation, out, version );
	};
	for (uint i1 = 0; i1 < floatKeys_.keys.size(); i1++) {
		NifStream( floatKeys_.keys[i1], out, version, floatKeys_.interpolation );
	};
	NifStream( numVisibilityKeys_, out, version );
	for (uint i1 = 0; i1 < visibilityKeys_.size(); i1++) {
		NifStream( visibilityKeys_[i1], out, version, 1 );
	};
}

std::string NiPSysEmitterCtlrData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numVisibilityKeys_ = uint(visibilityKeys_.size());
	floatKeys_.numKeys = uint(floatKeys_.keys.size());
	out << "  Num Keys:  " << floatKeys_.numKeys << endl;
	if ( (floatKeys_.numKeys != 0) ) {
		out << "    Interpolation:  " << floatKeys_.interpolation << endl;
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < floatKeys_.keys.size(); i1++) {
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
	for (uint i1 = 0; i1 < visibilityKeys_.size(); i1++) {
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

void NiPSysEmitterCtlrData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysEmitterCtlrData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiPSysEmitterDeclinationCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::Read( in, link_stack, version, user_version );
}

void NiPSysEmitterDeclinationCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
}

std::string NiPSysEmitterDeclinationCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterDeclinationCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysEmitterDeclinationCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysEmitterDeclinationVarCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::Read( in, link_stack, version, user_version );
}

void NiPSysEmitterDeclinationVarCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
}

std::string NiPSysEmitterDeclinationVarCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterDeclinationVarCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysEmitterDeclinationVarCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysEmitterInitialRadiusCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::Read( in, link_stack, version, user_version );
}

void NiPSysEmitterInitialRadiusCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
}

std::string NiPSysEmitterInitialRadiusCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterInitialRadiusCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysEmitterInitialRadiusCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysEmitterLifeSpanCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	APSysCtlr::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiPSysEmitterLifeSpanCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
	if ( version <= 0x0A010000 ) {
		if ( unknownLink != NULL )
			NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiPSysEmitterLifeSpanCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiPSysEmitterLifeSpanCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		unknownLink = FixLink<NiFloatData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiPSysEmitterLifeSpanCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiPSysEmitterSpeedCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	APSysCtlr::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiPSysEmitterSpeedCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
	if ( version <= 0x0A010000 ) {
		if ( unknownLink != NULL )
			NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiPSysEmitterSpeedCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiPSysEmitterSpeedCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		unknownLink = FixLink<NiFloatData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiPSysEmitterSpeedCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiPSysGravityModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( gravityAxis, in, version );
	NifStream( decay, in, version );
	NifStream( strength, in, version );
	NifStream( forceType, in, version );
	NifStream( turbulence, in, version );
	NifStream( turbulenceScale, in, version );
}

void NiPSysGravityModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	if ( gravityObject != NULL )
		NifStream( link_map[StaticCast<NiObject>(gravityObject)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( gravityAxis, out, version );
	NifStream( decay, out, version );
	NifStream( strength, out, version );
	NifStream( forceType, out, version );
	NifStream( turbulence, out, version );
	NifStream( turbulenceScale, out, version );
}

std::string NiPSysGravityModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiPSysGravityModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	gravityObject = FixLink<NiNode>( objects, link_stack, version );
}

std::list<NiObjectRef> NiPSysGravityModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysGravityStrengthCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	APSysCtlr::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiPSysGravityStrengthCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
	if ( version <= 0x0A010000 ) {
		if ( unknownLink != NULL )
			NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiPSysGravityStrengthCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiPSysGravityStrengthCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		unknownLink = FixLink<NiFloatData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiPSysGravityStrengthCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiPSysGrowFadeModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( growTime, in, version );
	NifStream( growGeneration, in, version );
	NifStream( fadeTime, in, version );
	NifStream( fadeGeneration, in, version );
}

void NiPSysGrowFadeModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	NifStream( growTime, out, version );
	NifStream( growGeneration, out, version );
	NifStream( fadeTime, out, version );
	NifStream( fadeGeneration, out, version );
}

std::string NiPSysGrowFadeModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	out << "  Grow Time:  " << growTime << endl;
	out << "  Grow Generation:  " << growGeneration << endl;
	out << "  Fade Time:  " << fadeTime << endl;
	out << "  Fade Generation:  " << fadeGeneration << endl;
	return out.str();
}

void NiPSysGrowFadeModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysGrowFadeModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysMeshEmitter::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysEmitter::Read( in, link_stack, version, user_version );
	NifStream( numEmitterMeshes, in, version );
	emitterMeshes.resize(numEmitterMeshes);
	for (uint i1 = 0; i1 < emitterMeshes.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( initialVelocityType, in, version );
	NifStream( emissionType, in, version );
	NifStream( emissionAxis, in, version );
}

void NiPSysMeshEmitter::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysEmitter::Write( out, link_map, version, user_version );
	numEmitterMeshes = uint(emitterMeshes.size());
	NifStream( numEmitterMeshes, out, version );
	for (uint i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( emitterMeshes[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(emitterMeshes[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	NifStream( initialVelocityType, out, version );
	NifStream( emissionType, out, version );
	NifStream( emissionAxis, out, version );
}

std::string NiPSysMeshEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysEmitter::asString();
	numEmitterMeshes = uint(emitterMeshes.size());
	out << "  Num Emitter Meshes:  " << numEmitterMeshes << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < emitterMeshes.size(); i1++) {
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

void NiPSysMeshEmitter::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysEmitter::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < emitterMeshes.size(); i1++) {
		emitterMeshes[i1] = FixLink<NiTriBasedGeom>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiPSysMeshEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysEmitter::GetRefs();
	for (uint i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( emitterMeshes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(emitterMeshes[i1]));
	};
	return refs;
}

void NiPSysMeshUpdateModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( numMeshes, in, version );
	meshes.resize(numMeshes);
	for (uint i1 = 0; i1 < meshes.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiPSysMeshUpdateModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	numMeshes = uint(meshes.size());
	NifStream( numMeshes, out, version );
	for (uint i1 = 0; i1 < meshes.size(); i1++) {
		if ( meshes[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(meshes[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiPSysMeshUpdateModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	numMeshes = uint(meshes.size());
	out << "  Num Meshes:  " << numMeshes << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < meshes.size(); i1++) {
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

void NiPSysMeshUpdateModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < meshes.size(); i1++) {
		meshes[i1] = FixLink<NiNode>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiPSysMeshUpdateModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	for (uint i1 = 0; i1 < meshes.size(); i1++) {
		if ( meshes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(meshes[i1]));
	};
	return refs;
}

void NiPSysModifierActiveCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		NifStream( unknownInt, in, version );
	};
}

void NiPSysModifierActiveCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
	if ( version <= 0x0A010000 ) {
		NifStream( unknownInt, out, version );
	};
}

std::string NiPSysModifierActiveCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << APSysCtlr::asString();
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void NiPSysModifierActiveCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysModifierActiveCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysPlanarCollider::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( bounce, in, version );
	NifStream( spawnOnCollide, in, version );
	NifStream( dieOnCollide, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( width, in, version );
	NifStream( height, in, version );
	NifStream( xAxis, in, version );
	NifStream( yAxis, in, version );
}

void NiPSysPlanarCollider::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	NifStream( bounce, out, version );
	NifStream( spawnOnCollide, out, version );
	NifStream( dieOnCollide, out, version );
	if ( spawnModifier != NULL )
		NifStream( link_map[StaticCast<NiObject>(spawnModifier)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( parent != NULL )
		NifStream( link_map[StaticCast<NiObject>(parent)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( unknownLink_ != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink_)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( colliderObject != NULL )
		NifStream( link_map[StaticCast<NiObject>(colliderObject)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( width, out, version );
	NifStream( height, out, version );
	NifStream( xAxis, out, version );
	NifStream( yAxis, out, version );
}

std::string NiPSysPlanarCollider::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiPSysPlanarCollider::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	spawnModifier = FixLink<NiPSysSpawnModifier>( objects, link_stack, version );
	parent = FixLink<NiObject>( objects, link_stack, version );
	unknownLink_ = FixLink<NiObject>( objects, link_stack, version );
	colliderObject = FixLink<NiNode>( objects, link_stack, version );
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

void NiPSysPositionModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::Read( in, link_stack, version, user_version );
}

void NiPSysPositionModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
}

std::string NiPSysPositionModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysModifier::asString();
	return out.str();
}

void NiPSysPositionModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysPositionModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysResetOnLoopCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::Read( in, link_stack, version, user_version );
}

void NiPSysResetOnLoopCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
}

std::string NiPSysResetOnLoopCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	return out.str();
}

void NiPSysResetOnLoopCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysResetOnLoopCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	return refs;
}

void NiPSysRotationModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( initialRotationSpeed, in, version );
	if ( version >= 0x14000004 ) {
		NifStream( initialRotationSpeedVariation, in, version );
		NifStream( initialRotationAngle, in, version );
		NifStream( initialRotationAngleVariation, in, version );
		NifStream( randomRotSpeedSign, in, version );
	};
	NifStream( randomInitialAxis, in, version );
	NifStream( initialAxis, in, version );
}

void NiPSysRotationModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	NifStream( initialRotationSpeed, out, version );
	if ( version >= 0x14000004 ) {
		NifStream( initialRotationSpeedVariation, out, version );
		NifStream( initialRotationAngle, out, version );
		NifStream( initialRotationAngleVariation, out, version );
		NifStream( randomRotSpeedSign, out, version );
	};
	NifStream( randomInitialAxis, out, version );
	NifStream( initialAxis, out, version );
}

std::string NiPSysRotationModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiPSysRotationModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysRotationModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysSpawnModifier::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::Read( in, link_stack, version, user_version );
	NifStream( numSpawnGenerations, in, version );
	NifStream( percentageSpawned, in, version );
	NifStream( minNumToSpawn, in, version );
	NifStream( maxNumToSpawn, in, version );
	NifStream( spawnSpeedChaos, in, version );
	NifStream( spawnDirChaos, in, version );
	NifStream( lifeSpan, in, version );
	NifStream( lifeSpanVariation, in, version );
}

void NiPSysSpawnModifier::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysModifier::Write( out, link_map, version, user_version );
	NifStream( numSpawnGenerations, out, version );
	NifStream( percentageSpawned, out, version );
	NifStream( minNumToSpawn, out, version );
	NifStream( maxNumToSpawn, out, version );
	NifStream( spawnSpeedChaos, out, version );
	NifStream( spawnDirChaos, out, version );
	NifStream( lifeSpan, out, version );
	NifStream( lifeSpanVariation, out, version );
}

std::string NiPSysSpawnModifier::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiPSysSpawnModifier::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysSpawnModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysSphereEmitter::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysVolumeEmitter::Read( in, link_stack, version, user_version );
	NifStream( radius, in, version );
}

void NiPSysSphereEmitter::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysVolumeEmitter::Write( out, link_map, version, user_version );
	NifStream( radius, out, version );
}

std::string NiPSysSphereEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPSysVolumeEmitter::asString();
	out << "  Radius:  " << radius << endl;
	return out.str();
}

void NiPSysSphereEmitter::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysVolumeEmitter::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysSphereEmitter::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysVolumeEmitter::GetRefs();
	return refs;
}

void NiPSysUpdateCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::Read( in, link_stack, version, user_version );
}

void NiPSysUpdateCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
}

std::string NiPSysUpdateCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	return out.str();
}

void NiPSysUpdateCtlr::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysUpdateCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	return refs;
}

void NiLODData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
}

void NiLODData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
}

std::string NiLODData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	return out.str();
}

void NiLODData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiLODData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiRangeLODData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLODData::Read( in, link_stack, version, user_version );
	NifStream( lodCenter, in, version );
	NifStream( numLodLevels, in, version );
	lodLevels.resize(numLodLevels);
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) {
		NifStream( lodLevels[i1].nearExtent, in, version );
		NifStream( lodLevels[i1].farExtent, in, version );
	};
}

void NiRangeLODData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiLODData::Write( out, link_map, version, user_version );
	numLodLevels = uint(lodLevels.size());
	NifStream( lodCenter, out, version );
	NifStream( numLodLevels, out, version );
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) {
		NifStream( lodLevels[i1].nearExtent, out, version );
		NifStream( lodLevels[i1].farExtent, out, version );
	};
}

std::string NiRangeLODData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiLODData::asString();
	numLodLevels = uint(lodLevels.size());
	out << "  LOD Center:  " << lodCenter << endl;
	out << "  Num LOD Levels:  " << numLodLevels << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Near Extent:  " << lodLevels[i1].nearExtent << endl;
		out << "    Far Extent:  " << lodLevels[i1].farExtent << endl;
	};
	return out.str();
}

void NiRangeLODData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLODData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiRangeLODData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLODData::GetRefs();
	return refs;
}

void NiScreenLODData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLODData::Read( in, link_stack, version, user_version );
	NifStream( boundCenter, in, version );
	NifStream( boundRadius, in, version );
	NifStream( worldCenter, in, version );
	NifStream( worldRadius, in, version );
	NifStream( proportionCount, in, version );
	proportionLevels.resize(proportionCount);
	for (uint i1 = 0; i1 < proportionLevels.size(); i1++) {
		NifStream( proportionLevels[i1], in, version );
	};
}

void NiScreenLODData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiLODData::Write( out, link_map, version, user_version );
	proportionCount = uint(proportionLevels.size());
	NifStream( boundCenter, out, version );
	NifStream( boundRadius, out, version );
	NifStream( worldCenter, out, version );
	NifStream( worldRadius, out, version );
	NifStream( proportionCount, out, version );
	for (uint i1 = 0; i1 < proportionLevels.size(); i1++) {
		NifStream( proportionLevels[i1], out, version );
	};
}

std::string NiScreenLODData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiLODData::asString();
	proportionCount = uint(proportionLevels.size());
	out << "  Bound Center:  " << boundCenter << endl;
	out << "  Bound Radius:  " << boundRadius << endl;
	out << "  World Center:  " << worldCenter << endl;
	out << "  World Radius:  " << worldRadius << endl;
	out << "  Proportion Count:  " << proportionCount << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < proportionLevels.size(); i1++) {
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

void NiScreenLODData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLODData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiScreenLODData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLODData::GetRefs();
	return refs;
}

void NiRotatingParticles::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticles::Read( in, link_stack, version, user_version );
}

void NiRotatingParticles::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiParticles::Write( out, link_map, version, user_version );
}

std::string NiRotatingParticles::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiParticles::asString();
	return out.str();
}

void NiRotatingParticles::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticles::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiRotatingParticles::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticles::GetRefs();
	return refs;
}

void NiRotatingParticlesData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticlesData::Read( in, link_stack, version, user_version );
}

void NiRotatingParticlesData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiParticlesData::Write( out, link_map, version, user_version );
}

std::string NiRotatingParticlesData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiParticlesData::asString();
	return out.str();
}

void NiRotatingParticlesData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticlesData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiRotatingParticlesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticlesData::GetRefs();
	return refs;
}

void NiSequenceStreamHelper::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObjectNET::Read( in, link_stack, version, user_version );
}

void NiSequenceStreamHelper::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObjectNET::Write( out, link_map, version, user_version );
}

std::string NiSequenceStreamHelper::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObjectNET::asString();
	return out.str();
}

void NiSequenceStreamHelper::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObjectNET::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiSequenceStreamHelper::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObjectNET::GetRefs();
	return refs;
}

void NiShadeProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
}

void NiShadeProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
}

std::string NiShadeProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiShadeProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiShadeProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiSkinData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( rotation, in, version );
	NifStream( translation, in, version );
	NifStream( scale, in, version );
	NifStream( numBones, in, version );
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	if ( version >= 0x04020100 ) {
		NifStream( unknownByte, in, version );
	};
	boneList.resize(numBones);
	for (uint i1 = 0; i1 < boneList.size(); i1++) {
		NifStream( boneList[i1].rotation, in, version );
		NifStream( boneList[i1].translation, in, version );
		NifStream( boneList[i1].scale, in, version );
		NifStream( boneList[i1].boundingSphereOffset, in, version );
		NifStream( boneList[i1].boundingSphereRadius, in, version );
		NifStream( boneList[i1].numVertices, in, version );
		boneList[i1].vertexWeights.resize(boneList[i1].numVertices);
		for (uint i2 = 0; i2 < boneList[i1].vertexWeights.size(); i2++) {
			NifStream( boneList[i1].vertexWeights[i2].index, in, version );
			NifStream( boneList[i1].vertexWeights[i2].weight, in, version );
		};
	};
}

void NiSkinData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numBones = uint(boneList.size());
	NifStream( rotation, out, version );
	NifStream( translation, out, version );
	NifStream( scale, out, version );
	NifStream( numBones, out, version );
	if ( version <= 0x0A010000 ) {
		if ( skinPartition != NULL )
			NifStream( link_map[StaticCast<NiObject>(skinPartition)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( version >= 0x04020100 ) {
		NifStream( unknownByte, out, version );
	};
	for (uint i1 = 0; i1 < boneList.size(); i1++) {
		boneList[i1].numVertices = ushort(boneList[i1].vertexWeights.size());
		NifStream( boneList[i1].rotation, out, version );
		NifStream( boneList[i1].translation, out, version );
		NifStream( boneList[i1].scale, out, version );
		NifStream( boneList[i1].boundingSphereOffset, out, version );
		NifStream( boneList[i1].boundingSphereRadius, out, version );
		NifStream( boneList[i1].numVertices, out, version );
		for (uint i2 = 0; i2 < boneList[i1].vertexWeights.size(); i2++) {
			NifStream( boneList[i1].vertexWeights[i2].index, out, version );
			NifStream( boneList[i1].vertexWeights[i2].weight, out, version );
		};
	};
}

std::string NiSkinData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numBones = uint(boneList.size());
	out << "  Rotation:  " << rotation << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Num Bones:  " << numBones << endl;
	out << "  Skin Partition:  " << skinPartition << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < boneList.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		boneList[i1].numVertices = ushort(boneList[i1].vertexWeights.size());
		out << "    Rotation:  " << boneList[i1].rotation << endl;
		out << "    Translation:  " << boneList[i1].translation << endl;
		out << "    Scale:  " << boneList[i1].scale << endl;
		out << "    Bounding Sphere Offset:  " << boneList[i1].boundingSphereOffset << endl;
		out << "    Bounding Sphere Radius:  " << boneList[i1].boundingSphereRadius << endl;
		out << "    Num Vertices:  " << boneList[i1].numVertices << endl;
		array_output_count = 0;
		for (uint i2 = 0; i2 < boneList[i1].vertexWeights.size(); i2++) {
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

void NiSkinData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		skinPartition = FixLink<NiSkinPartition>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiSkinData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( skinPartition != NULL )
		refs.push_back(StaticCast<NiObject>(skinPartition));
	return refs;
}

void NiSkinInstance::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	if ( version >= 0x0A020000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( numBones, in, version );
	bones.resize(numBones);
	for (uint i1 = 0; i1 < bones.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiSkinInstance::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numBones = uint(bones.size());
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( version >= 0x0A020000 ) {
		if ( skinPartition != NULL )
			NifStream( link_map[StaticCast<NiObject>(skinPartition)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	if ( skeletonRoot != NULL )
		NifStream( link_map[StaticCast<NiObject>(skeletonRoot)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( numBones, out, version );
	for (uint i1 = 0; i1 < bones.size(); i1++) {
		if ( bones[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(bones[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiSkinInstance::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numBones = uint(bones.size());
	out << "  Data:  " << data << endl;
	out << "  Skin Partition:  " << skinPartition << endl;
	out << "  Skeleton Root:  " << skeletonRoot << endl;
	out << "  Num Bones:  " << numBones << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < bones.size(); i1++) {
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

void NiSkinInstance::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiSkinData>( objects, link_stack, version );
	if ( version >= 0x0A020000 ) {
		skinPartition = FixLink<NiSkinPartition>( objects, link_stack, version );
	};
	skeletonRoot = FixLink<NiNode>( objects, link_stack, version );
	for (uint i1 = 0; i1 < bones.size(); i1++) {
		bones[i1] = FixLink<NiNode>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiSkinInstance::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( skinPartition != NULL )
		refs.push_back(StaticCast<NiObject>(skinPartition));
	for (uint i1 = 0; i1 < bones.size(); i1++) {
	};
	return refs;
}

void NiClodSkinInstance::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSkinInstance::Read( in, link_stack, version, user_version );
}

void NiClodSkinInstance::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSkinInstance::Write( out, link_map, version, user_version );
}

std::string NiClodSkinInstance::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiSkinInstance::asString();
	return out.str();
}

void NiClodSkinInstance::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSkinInstance::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiClodSkinInstance::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSkinInstance::GetRefs();
	return refs;
}

void NiSkinPartition::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( numSkinPartitionBlocks, in, version );
	skinPartitionBlocks.resize(numSkinPartitionBlocks);
	for (uint i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		NifStream( skinPartitionBlocks[i1].numVertices, in, version );
		NifStream( skinPartitionBlocks[i1].numTriangles, in, version );
		NifStream( skinPartitionBlocks[i1].numBones, in, version );
		NifStream( skinPartitionBlocks[i1].numStrips, in, version );
		NifStream( skinPartitionBlocks[i1].numWeightsPerVertex, in, version );
		skinPartitionBlocks[i1].bones.resize(skinPartitionBlocks[i1].numBones);
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].bones[i2], in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasVertexMap, in, version );
		};
		if ( version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].vertexMap.resize(skinPartitionBlocks[i1].numVertices);
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].vertexMap.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].vertexMap[i3], in, version );
			};
		};
		if ( version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexMap != 0) ) {
				skinPartitionBlocks[i1].vertexMap.resize(skinPartitionBlocks[i1].numVertices);
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].vertexMap.size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexMap[i4], in, version );
				};
			};
			NifStream( skinPartitionBlocks[i1].hasVertexWeights, in, version );
		};
		if ( version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].vertexWeights.resize(skinPartitionBlocks[i1].numVertices);
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights.size(); i3++) {
				skinPartitionBlocks[i1].vertexWeights[i3].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexWeights[i3][i4], in, version );
				};
			};
		};
		if ( version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexWeights != 0) ) {
				skinPartitionBlocks[i1].vertexWeights.resize(skinPartitionBlocks[i1].numVertices);
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights.size(); i4++) {
					skinPartitionBlocks[i1].vertexWeights[i4].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
					for (uint i5 = 0; i5 < skinPartitionBlocks[i1].vertexWeights[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i1].vertexWeights[i4][i5], in, version );
					};
				};
			};
		};
		skinPartitionBlocks[i1].stripLengths.resize(skinPartitionBlocks[i1].numStrips);
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].stripLengths[i2], in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasStrips, in, version );
		};
		if ( version <= 0x0A000102 ) {
			skinPartitionBlocks[i1].strips.resize(skinPartitionBlocks[i1].numStrips);
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].strips.size(); i3++) {
				skinPartitionBlocks[i1].strips[i3].resize(skinPartitionBlocks[i1].stripLengths[i3]);
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].stripLengths[i3]; i4++) {
					NifStream( skinPartitionBlocks[i1].strips[i3][i4], in, version );
				};
			};
		};
		if ( version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasStrips != 0) ) {
				skinPartitionBlocks[i1].strips.resize(skinPartitionBlocks[i1].numStrips);
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].strips.size(); i4++) {
					skinPartitionBlocks[i1].strips[i4].resize(skinPartitionBlocks[i1].stripLengths[i4]);
					for (uint i5 = 0; i5 < skinPartitionBlocks[i1].stripLengths[i4]; i5++) {
						NifStream( skinPartitionBlocks[i1].strips[i4][i5], in, version );
					};
				};
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			skinPartitionBlocks[i1].triangles.resize(skinPartitionBlocks[i1].numTriangles);
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].triangles[i3], in, version );
			};
		};
		NifStream( skinPartitionBlocks[i1].hasBoneIndices, in, version );
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			skinPartitionBlocks[i1].boneIndices.resize(skinPartitionBlocks[i1].numVertices);
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				skinPartitionBlocks[i1].boneIndices[i3].resize(skinPartitionBlocks[i1].numWeightsPerVertex);
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].boneIndices[i3][i4], in, version );
				};
			};
		};
	};
}

void NiSkinPartition::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	numSkinPartitionBlocks = uint(skinPartitionBlocks.size());
	NifStream( numSkinPartitionBlocks, out, version );
	for (uint i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++)
			skinPartitionBlocks[i1].stripLengths[i2] = ushort(skinPartitionBlocks[i1].strips[i2].size());
		skinPartitionBlocks[i1].numWeightsPerVertex = ushort((skinPartitionBlocks[i1].vertexWeights.size() > 0) ? skinPartitionBlocks[i1].vertexWeights[0].size() : 0);
		skinPartitionBlocks[i1].numStrips = ushort(skinPartitionBlocks[i1].stripLengths.size());
		skinPartitionBlocks[i1].numBones = ushort(skinPartitionBlocks[i1].bones.size());
		skinPartitionBlocks[i1].numTriangles = ushort(skinPartitionBlocks[i1].triangles.size());
		skinPartitionBlocks[i1].numVertices = ushort(skinPartitionBlocks[i1].vertexMap.size());
		NifStream( skinPartitionBlocks[i1].numVertices, out, version );
		NifStream( skinPartitionBlocks[i1].numTriangles, out, version );
		NifStream( skinPartitionBlocks[i1].numBones, out, version );
		NifStream( skinPartitionBlocks[i1].numStrips, out, version );
		NifStream( skinPartitionBlocks[i1].numWeightsPerVertex, out, version );
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].bones[i2], out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasVertexMap, out, version );
		};
		if ( version <= 0x0A000102 ) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].vertexMap.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].vertexMap[i3], out, version );
			};
		};
		if ( version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexMap != 0) ) {
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].vertexMap.size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexMap[i4], out, version );
				};
			};
			NifStream( skinPartitionBlocks[i1].hasVertexWeights, out, version );
		};
		if ( version <= 0x0A000102 ) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights.size(); i3++) {
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].vertexWeights[i3][i4], out, version );
				};
			};
		};
		if ( version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasVertexWeights != 0) ) {
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].vertexWeights.size(); i4++) {
					for (uint i5 = 0; i5 < skinPartitionBlocks[i1].vertexWeights[i4].size(); i5++) {
						NifStream( skinPartitionBlocks[i1].vertexWeights[i4][i5], out, version );
					};
				};
			};
		};
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			NifStream( skinPartitionBlocks[i1].stripLengths[i2], out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( skinPartitionBlocks[i1].hasStrips, out, version );
		};
		if ( version <= 0x0A000102 ) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].strips.size(); i3++) {
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].stripLengths[i3]; i4++) {
					NifStream( skinPartitionBlocks[i1].strips[i3][i4], out, version );
				};
			};
		};
		if ( version >= 0x0A010000 ) {
			if ( (skinPartitionBlocks[i1].hasStrips != 0) ) {
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].strips.size(); i4++) {
					for (uint i5 = 0; i5 < skinPartitionBlocks[i1].stripLengths[i4]; i5++) {
						NifStream( skinPartitionBlocks[i1].strips[i4][i5], out, version );
					};
				};
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				NifStream( skinPartitionBlocks[i1].triangles[i3], out, version );
			};
		};
		NifStream( skinPartitionBlocks[i1].hasBoneIndices, out, version );
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					NifStream( skinPartitionBlocks[i1].boneIndices[i3][i4], out, version );
				};
			};
		};
	};
}

std::string NiSkinPartition::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	numSkinPartitionBlocks = uint(skinPartitionBlocks.size());
	out << "  Num Skin Partition Blocks:  " << numSkinPartitionBlocks << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++)
			skinPartitionBlocks[i1].stripLengths[i2] = ushort(skinPartitionBlocks[i1].strips[i2].size());
		skinPartitionBlocks[i1].numWeightsPerVertex = ushort((skinPartitionBlocks[i1].vertexWeights.size() > 0) ? skinPartitionBlocks[i1].vertexWeights[0].size() : 0);
		skinPartitionBlocks[i1].numStrips = ushort(skinPartitionBlocks[i1].stripLengths.size());
		skinPartitionBlocks[i1].numBones = ushort(skinPartitionBlocks[i1].bones.size());
		skinPartitionBlocks[i1].numTriangles = ushort(skinPartitionBlocks[i1].triangles.size());
		skinPartitionBlocks[i1].numVertices = ushort(skinPartitionBlocks[i1].vertexMap.size());
		out << "    Num Vertices:  " << skinPartitionBlocks[i1].numVertices << endl;
		out << "    Num Triangles:  " << skinPartitionBlocks[i1].numTriangles << endl;
		out << "    Num Bones:  " << skinPartitionBlocks[i1].numBones << endl;
		out << "    Num Strips:  " << skinPartitionBlocks[i1].numStrips << endl;
		out << "    Num Weights Per Vertex:  " << skinPartitionBlocks[i1].numWeightsPerVertex << endl;
		array_output_count = 0;
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
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
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].vertexMap.size(); i2++) {
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
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].vertexWeights.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights[i2].size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Vertex Weights[" << i3 << "]:  " << skinPartitionBlocks[i1].vertexWeights[i2][i3] << endl;
				array_output_count++;
			};
		};
		array_output_count = 0;
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
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
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].stripLengths[i2]; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Strips[" << i3 << "]:  " << skinPartitionBlocks[i1].strips[i2][i3] << endl;
				array_output_count++;
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			array_output_count = 0;
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
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
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
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

void NiSkinPartition::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiSkinPartition::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiSourceTexture::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiObjectNET::Read( in, link_stack, version, user_version );
	NifStream( useExternal, in, version );
	if ( (useExternal == 1) ) {
		NifStream( fileName, in, version );
	};
	if ( version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
	if ( version <= 0x0A000100 ) {
		if ( (useExternal == 0) ) {
			NifStream( unknownByte, in, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		if ( (useExternal == 0) ) {
			NifStream( originalFileName_, in, version );
		};
	};
	if ( (useExternal == 0) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
	NifStream( pixelLayout, in, version );
	NifStream( useMipmaps, in, version );
	NifStream( alphaFormat, in, version );
	NifStream( unknownByte, in, version );
	if ( version >= 0x0A01006A ) {
		NifStream( unknownByte2, in, version );
	};
}

void NiSourceTexture::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObjectNET::Write( out, link_map, version, user_version );
	NifStream( useExternal, out, version );
	if ( (useExternal == 1) ) {
		NifStream( fileName, out, version );
	};
	if ( version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			if ( unknownLink != NULL )
				NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
	};
	if ( version <= 0x0A000100 ) {
		if ( (useExternal == 0) ) {
			NifStream( unknownByte, out, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		if ( (useExternal == 0) ) {
			NifStream( originalFileName_, out, version );
		};
	};
	if ( (useExternal == 0) ) {
		if ( pixelData != NULL )
			NifStream( link_map[StaticCast<NiObject>(pixelData)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
	NifStream( pixelLayout, out, version );
	NifStream( useMipmaps, out, version );
	NifStream( alphaFormat, out, version );
	NifStream( unknownByte, out, version );
	if ( version >= 0x0A01006A ) {
		NifStream( unknownByte2, out, version );
	};
}

std::string NiSourceTexture::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiSourceTexture::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObjectNET::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			unknownLink = FixLink<NiObject>( objects, link_stack, version );
		};
	};
	if ( (useExternal == 0) ) {
		pixelData = FixLink<NiPixelData>( objects, link_stack, version );
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

void NiSpecularProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
}

void NiSpecularProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
}

std::string NiSpecularProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiSpecularProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiSpecularProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiSphericalCollider::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::Read( in, link_stack, version, user_version );
	NifStream( unknownFloat1, in, version );
	NifStream( unknownShort1, in, version );
	NifStream( unknownFloat2, in, version );
	if ( version <= 0x04020002 ) {
		NifStream( unknownShort2, in, version );
	};
	if ( version >= 0x04020100 ) {
		NifStream( unknownFloat3, in, version );
	};
	NifStream( unknownFloat4, in, version );
	NifStream( unknownFloat5, in, version );
}

void NiSphericalCollider::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownShort1, out, version );
	NifStream( unknownFloat2, out, version );
	if ( version <= 0x04020002 ) {
		NifStream( unknownShort2, out, version );
	};
	if ( version >= 0x04020100 ) {
		NifStream( unknownFloat3, out, version );
	};
	NifStream( unknownFloat4, out, version );
	NifStream( unknownFloat5, out, version );
}

std::string NiSphericalCollider::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiSphericalCollider::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiSphericalCollider::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiSpotLight::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPointLight::Read( in, link_stack, version, user_version );
	NifStream( cutoffAngle, in, version );
	NifStream( exponent, in, version );
}

void NiSpotLight::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPointLight::Write( out, link_map, version, user_version );
	NifStream( cutoffAngle, out, version );
	NifStream( exponent, out, version );
}

std::string NiSpotLight::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiPointLight::asString();
	out << "  Cutoff Angle:  " << cutoffAngle << endl;
	out << "  Exponent:  " << exponent << endl;
	return out.str();
}

void NiSpotLight::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPointLight::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiSpotLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPointLight::GetRefs();
	return refs;
}

void NiStencilProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A000102 ) {
		NifStream( flags, in, version );
	};
	NifStream( stencilEnabled, in, version );
	NifStream( stencilFunction, in, version );
	NifStream( stencilRef, in, version );
	NifStream( stencilMask, in, version );
	NifStream( failAction, in, version );
	NifStream( zFailAction, in, version );
	NifStream( passAction, in, version );
	NifStream( drawMode, in, version );
}

void NiStencilProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	if ( version <= 0x0A000102 ) {
		NifStream( flags, out, version );
	};
	NifStream( stencilEnabled, out, version );
	NifStream( stencilFunction, out, version );
	NifStream( stencilRef, out, version );
	NifStream( stencilMask, out, version );
	NifStream( failAction, out, version );
	NifStream( zFailAction, out, version );
	NifStream( passAction, out, version );
	NifStream( drawMode, out, version );
}

std::string NiStencilProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiStencilProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiStencilProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiStringExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	if ( version <= 0x04020200 ) {
		NifStream( bytesRemaining, in, version );
	};
	NifStream( stringData, in, version );
}

void NiStringExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	if ( version <= 0x04020200 ) {
		NifStream( bytesRemaining, out, version );
	};
	NifStream( stringData, out, version );
}

std::string NiStringExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Bytes Remaining:  " << bytesRemaining << endl;
	out << "  String Data:  " << stringData << endl;
	return out.str();
}

void NiStringExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiStringExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiStringPalette::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( palette.palette, in, version );
	NifStream( palette.length, in, version );
}

void NiStringPalette::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	NifStream( palette.palette, out, version );
	NifStream( palette.length, out, version );
}

std::string NiStringPalette::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	out << "  Palette:  " << palette.palette << endl;
	out << "  Length:  " << palette.length << endl;
	return out.str();
}

void NiStringPalette::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiStringPalette::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiStringsExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( numStrings, in, version );
	data.resize(numStrings);
	for (uint i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], in, version );
	};
}

void NiStringsExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	numStrings = uint(data.size());
	NifStream( numStrings, out, version );
	for (uint i1 = 0; i1 < data.size(); i1++) {
		NifStream( data[i1], out, version );
	};
}

std::string NiStringsExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	numStrings = uint(data.size());
	out << "  Num Strings:  " << numStrings << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < data.size(); i1++) {
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

void NiStringsExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiStringsExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiTextKeyExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	if ( version <= 0x04020200 ) {
		NifStream( unknownInt1, in, version );
	};
	NifStream( numTextKeys, in, version );
	textKeys.resize(numTextKeys);
	for (uint i1 = 0; i1 < textKeys.size(); i1++) {
		NifStream( textKeys[i1], in, version, 1 );
	};
}

void NiTextKeyExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	numTextKeys = uint(textKeys.size());
	if ( version <= 0x04020200 ) {
		NifStream( unknownInt1, out, version );
	};
	NifStream( numTextKeys, out, version );
	for (uint i1 = 0; i1 < textKeys.size(); i1++) {
		NifStream( textKeys[i1], out, version, 1 );
	};
}

std::string NiTextKeyExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	numTextKeys = uint(textKeys.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Num Text Keys:  " << numTextKeys << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < textKeys.size(); i1++) {
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

void NiTextKeyExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTextKeyExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiTextureEffect::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiDynamicEffect::Read( in, link_stack, version, user_version );
	NifStream( modelProjectionMatrix, in, version );
	NifStream( modelProjectionTransform, in, version );
	NifStream( textureFiltering, in, version );
	NifStream( textureClamping, in, version );
	NifStream( textureType, in, version );
	NifStream( coordinateGenerationType, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( clippingPlane, in, version );
	NifStream( unknownVector, in, version );
	NifStream( unknownFloat, in, version );
	if ( version <= 0x0A020000 ) {
		NifStream( ps2L, in, version );
		NifStream( ps2K, in, version );
	};
	if ( version <= 0x0401000C ) {
		NifStream( unknownShort, in, version );
	};
}

void NiTextureEffect::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiDynamicEffect::Write( out, link_map, version, user_version );
	NifStream( modelProjectionMatrix, out, version );
	NifStream( modelProjectionTransform, out, version );
	NifStream( textureFiltering, out, version );
	NifStream( textureClamping, out, version );
	NifStream( textureType, out, version );
	NifStream( coordinateGenerationType, out, version );
	if ( sourceTexture != NULL )
		NifStream( link_map[StaticCast<NiObject>(sourceTexture)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( clippingPlane, out, version );
	NifStream( unknownVector, out, version );
	NifStream( unknownFloat, out, version );
	if ( version <= 0x0A020000 ) {
		NifStream( ps2L, out, version );
		NifStream( ps2K, out, version );
	};
	if ( version <= 0x0401000C ) {
		NifStream( unknownShort, out, version );
	};
}

std::string NiTextureEffect::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
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

void NiTextureEffect::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiDynamicEffect::FixLinks( objects, link_stack, version, user_version );
	sourceTexture = FixLink<NiSourceTexture>( objects, link_stack, version );
}

std::list<NiObjectRef> NiTextureEffect::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiDynamicEffect::GetRefs();
	if ( sourceTexture != NULL )
		refs.push_back(StaticCast<NiObject>(sourceTexture));
	return refs;
}

void NiTextureTransformController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiSingleInterpolatorController::Read( in, link_stack, version, user_version );
	NifStream( unknown2, in, version );
	NifStream( textureSlot, in, version );
	NifStream( operation, in, version );
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiTextureTransformController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSingleInterpolatorController::Write( out, link_map, version, user_version );
	NifStream( unknown2, out, version );
	NifStream( textureSlot, out, version );
	NifStream( operation, out, version );
	if ( version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map[StaticCast<NiObject>(data)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiTextureTransformController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Unknown2:  " << unknown2 << endl;
	out << "  Texture Slot:  " << textureSlot << endl;
	out << "  Operation:  " << operation << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiTextureTransformController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		data = FixLink<NiFloatData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiTextureTransformController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiTextureModeProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 3; i1++) {
		NifStream( unknown3Shorts[i1], in, version );
	};
}

void NiTextureModeProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 3; i1++) {
		NifStream( unknown3Shorts[i1], out, version );
	};
}

std::string NiTextureModeProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < 3; i1++) {
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

void NiTextureModeProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTextureModeProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiImage::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( external_, in, version );
	NifStream( file, in, version );
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Shorts[i1], in, version );
	};
}

void NiImage::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	NifStream( external_, out, version );
	NifStream( file, out, version );
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknown4Shorts[i1], out, version );
	};
}

std::string NiImage::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	out << "  External ?:  " << external_ << endl;
	out << "  File:  " << file << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < 4; i1++) {
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

void NiImage::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiImage::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiTextureProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiTextureProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
	if ( image != NULL )
		NifStream( link_map[StaticCast<NiObject>(image)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiTextureProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Image:  " << image << endl;
	return out.str();
}

void NiTextureProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
	image = FixLink<NiImage>( objects, link_stack, version );
}

std::list<NiObjectRef> NiTextureProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	if ( image != NULL )
		refs.push_back(StaticCast<NiObject>(image));
	return refs;
}

void NiTexturingProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiProperty::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A000102 ) {
		NifStream( flags, in, version );
	};
	NifStream( applyMode, in, version );
	NifStream( textureCount, in, version );
	NifStream( hasBaseTexture, in, version );
	if ( (hasBaseTexture != 0) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( baseTexture.clampMode, in, version );
		NifStream( baseTexture.filterMode, in, version );
		NifStream( baseTexture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( baseTexture.ps2L, in, version );
			NifStream( baseTexture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( baseTexture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( baseTexture.hasTextureTransform, in, version );
			if ( (baseTexture.hasTextureTransform != 0) ) {
				NifStream( baseTexture.translation, in, version );
				NifStream( baseTexture.tiling, in, version );
				NifStream( baseTexture.wRotation, in, version );
				NifStream( baseTexture.transformType_, in, version );
				NifStream( baseTexture.centerOffset, in, version );
			};
		};
	};
	NifStream( hasDarkTexture, in, version );
	if ( (hasDarkTexture != 0) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( darkTexture.clampMode, in, version );
		NifStream( darkTexture.filterMode, in, version );
		NifStream( darkTexture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( darkTexture.ps2L, in, version );
			NifStream( darkTexture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( darkTexture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( darkTexture.hasTextureTransform, in, version );
			if ( (darkTexture.hasTextureTransform != 0) ) {
				NifStream( darkTexture.translation, in, version );
				NifStream( darkTexture.tiling, in, version );
				NifStream( darkTexture.wRotation, in, version );
				NifStream( darkTexture.transformType_, in, version );
				NifStream( darkTexture.centerOffset, in, version );
			};
		};
	};
	NifStream( hasDetailTexture, in, version );
	if ( (hasDetailTexture != 0) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( detailTexture.clampMode, in, version );
		NifStream( detailTexture.filterMode, in, version );
		NifStream( detailTexture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( detailTexture.ps2L, in, version );
			NifStream( detailTexture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( detailTexture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( detailTexture.hasTextureTransform, in, version );
			if ( (detailTexture.hasTextureTransform != 0) ) {
				NifStream( detailTexture.translation, in, version );
				NifStream( detailTexture.tiling, in, version );
				NifStream( detailTexture.wRotation, in, version );
				NifStream( detailTexture.transformType_, in, version );
				NifStream( detailTexture.centerOffset, in, version );
			};
		};
	};
	NifStream( hasGlossTexture, in, version );
	if ( (hasGlossTexture != 0) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( glossTexture.clampMode, in, version );
		NifStream( glossTexture.filterMode, in, version );
		NifStream( glossTexture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( glossTexture.ps2L, in, version );
			NifStream( glossTexture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( glossTexture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( glossTexture.hasTextureTransform, in, version );
			if ( (glossTexture.hasTextureTransform != 0) ) {
				NifStream( glossTexture.translation, in, version );
				NifStream( glossTexture.tiling, in, version );
				NifStream( glossTexture.wRotation, in, version );
				NifStream( glossTexture.transformType_, in, version );
				NifStream( glossTexture.centerOffset, in, version );
			};
		};
	};
	NifStream( hasGlowTexture, in, version );
	if ( (hasGlowTexture != 0) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( glowTexture.clampMode, in, version );
		NifStream( glowTexture.filterMode, in, version );
		NifStream( glowTexture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( glowTexture.ps2L, in, version );
			NifStream( glowTexture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( glowTexture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( glowTexture.hasTextureTransform, in, version );
			if ( (glowTexture.hasTextureTransform != 0) ) {
				NifStream( glowTexture.translation, in, version );
				NifStream( glowTexture.tiling, in, version );
				NifStream( glowTexture.wRotation, in, version );
				NifStream( glowTexture.transformType_, in, version );
				NifStream( glowTexture.centerOffset, in, version );
			};
		};
	};
	NifStream( hasBumpMapTexture, in, version );
	if ( (hasBumpMapTexture != 0) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( bumpMapTexture.clampMode, in, version );
		NifStream( bumpMapTexture.filterMode, in, version );
		NifStream( bumpMapTexture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( bumpMapTexture.ps2L, in, version );
			NifStream( bumpMapTexture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( bumpMapTexture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( bumpMapTexture.hasTextureTransform, in, version );
			if ( (bumpMapTexture.hasTextureTransform != 0) ) {
				NifStream( bumpMapTexture.translation, in, version );
				NifStream( bumpMapTexture.tiling, in, version );
				NifStream( bumpMapTexture.wRotation, in, version );
				NifStream( bumpMapTexture.transformType_, in, version );
				NifStream( bumpMapTexture.centerOffset, in, version );
			};
		};
		NifStream( bumpMapLumaScale, in, version );
		NifStream( bumpMapLumaOffset, in, version );
		NifStream( bumpMapMatrix, in, version );
	};
	NifStream( hasDecal0Texture, in, version );
	if ( (hasDecal0Texture != 0) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( decal0Texture.clampMode, in, version );
		NifStream( decal0Texture.filterMode, in, version );
		NifStream( decal0Texture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( decal0Texture.ps2L, in, version );
			NifStream( decal0Texture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( decal0Texture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( decal0Texture.hasTextureTransform, in, version );
			if ( (decal0Texture.hasTextureTransform != 0) ) {
				NifStream( decal0Texture.translation, in, version );
				NifStream( decal0Texture.tiling, in, version );
				NifStream( decal0Texture.wRotation, in, version );
				NifStream( decal0Texture.transformType_, in, version );
				NifStream( decal0Texture.centerOffset, in, version );
			};
		};
	};
	if ( (textureCount >= 8) ) {
		NifStream( hasDecal1Texture, in, version );
	};
	if ( (((textureCount >= 8)) && ((hasDecal1Texture != 0))) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( decal1Texture.clampMode, in, version );
		NifStream( decal1Texture.filterMode, in, version );
		NifStream( decal1Texture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( decal1Texture.ps2L, in, version );
			NifStream( decal1Texture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( decal1Texture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( decal1Texture.hasTextureTransform, in, version );
			if ( (decal1Texture.hasTextureTransform != 0) ) {
				NifStream( decal1Texture.translation, in, version );
				NifStream( decal1Texture.tiling, in, version );
				NifStream( decal1Texture.wRotation, in, version );
				NifStream( decal1Texture.transformType_, in, version );
				NifStream( decal1Texture.centerOffset, in, version );
			};
		};
	};
	if ( (textureCount >= 9) ) {
		NifStream( hasDecal2Texture, in, version );
	};
	if ( (((textureCount >= 9)) && ((hasDecal2Texture != 0))) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( decal2Texture.clampMode, in, version );
		NifStream( decal2Texture.filterMode, in, version );
		NifStream( decal2Texture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( decal2Texture.ps2L, in, version );
			NifStream( decal2Texture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( decal2Texture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( decal2Texture.hasTextureTransform, in, version );
			if ( (decal2Texture.hasTextureTransform != 0) ) {
				NifStream( decal2Texture.translation, in, version );
				NifStream( decal2Texture.tiling, in, version );
				NifStream( decal2Texture.wRotation, in, version );
				NifStream( decal2Texture.transformType_, in, version );
				NifStream( decal2Texture.centerOffset, in, version );
			};
		};
	};
	if ( (textureCount >= 10) ) {
		NifStream( hasDecal3Texture, in, version );
	};
	if ( (((textureCount >= 10)) && ((hasDecal3Texture != 0))) ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
		NifStream( decal3Texture.clampMode, in, version );
		NifStream( decal3Texture.filterMode, in, version );
		NifStream( decal3Texture.uvSet, in, version );
		if ( version <= 0x0A020000 ) {
			NifStream( decal3Texture.ps2L, in, version );
			NifStream( decal3Texture.ps2K, in, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( decal3Texture.unknown1, in, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( decal3Texture.hasTextureTransform, in, version );
			if ( (decal3Texture.hasTextureTransform != 0) ) {
				NifStream( decal3Texture.translation, in, version );
				NifStream( decal3Texture.tiling, in, version );
				NifStream( decal3Texture.wRotation, in, version );
				NifStream( decal3Texture.transformType_, in, version );
				NifStream( decal3Texture.centerOffset, in, version );
			};
		};
	};
	if ( version >= 0x0A000100 ) {
		NifStream( numShaderTextures, in, version );
		shaderTextures.resize(numShaderTextures);
		for (uint i2 = 0; i2 < shaderTextures.size(); i2++) {
			NifStream( shaderTextures[i2].isUsed, in, version );
			if ( (shaderTextures[i2].isUsed != 0) ) {
				NifStream( block_num, in, version );
				link_stack.push_back( block_num );
				NifStream( shaderTextures[i2].textureData.clampMode, in, version );
				NifStream( shaderTextures[i2].textureData.filterMode, in, version );
				NifStream( shaderTextures[i2].textureData.uvSet, in, version );
				if ( version <= 0x0A020000 ) {
					NifStream( shaderTextures[i2].textureData.ps2L, in, version );
					NifStream( shaderTextures[i2].textureData.ps2K, in, version );
				};
				if ( version <= 0x0401000C ) {
					NifStream( shaderTextures[i2].textureData.unknown1, in, version );
				};
				if ( version >= 0x0A010000 ) {
					NifStream( shaderTextures[i2].textureData.hasTextureTransform, in, version );
					if ( (shaderTextures[i2].textureData.hasTextureTransform != 0) ) {
						NifStream( shaderTextures[i2].textureData.translation, in, version );
						NifStream( shaderTextures[i2].textureData.tiling, in, version );
						NifStream( shaderTextures[i2].textureData.wRotation, in, version );
						NifStream( shaderTextures[i2].textureData.transformType_, in, version );
						NifStream( shaderTextures[i2].textureData.centerOffset, in, version );
					};
				};
				NifStream( shaderTextures[i2].unknownInt, in, version );
			};
		};
	};
}

void NiTexturingProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	numShaderTextures = uint(shaderTextures.size());
	if ( version <= 0x0A000102 ) {
		NifStream( flags, out, version );
	};
	NifStream( applyMode, out, version );
	NifStream( textureCount, out, version );
	NifStream( hasBaseTexture, out, version );
	if ( (hasBaseTexture != 0) ) {
		if ( baseTexture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(baseTexture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( baseTexture.clampMode, out, version );
		NifStream( baseTexture.filterMode, out, version );
		NifStream( baseTexture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( baseTexture.ps2L, out, version );
			NifStream( baseTexture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( baseTexture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( baseTexture.hasTextureTransform, out, version );
			if ( (baseTexture.hasTextureTransform != 0) ) {
				NifStream( baseTexture.translation, out, version );
				NifStream( baseTexture.tiling, out, version );
				NifStream( baseTexture.wRotation, out, version );
				NifStream( baseTexture.transformType_, out, version );
				NifStream( baseTexture.centerOffset, out, version );
			};
		};
	};
	NifStream( hasDarkTexture, out, version );
	if ( (hasDarkTexture != 0) ) {
		if ( darkTexture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(darkTexture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( darkTexture.clampMode, out, version );
		NifStream( darkTexture.filterMode, out, version );
		NifStream( darkTexture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( darkTexture.ps2L, out, version );
			NifStream( darkTexture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( darkTexture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( darkTexture.hasTextureTransform, out, version );
			if ( (darkTexture.hasTextureTransform != 0) ) {
				NifStream( darkTexture.translation, out, version );
				NifStream( darkTexture.tiling, out, version );
				NifStream( darkTexture.wRotation, out, version );
				NifStream( darkTexture.transformType_, out, version );
				NifStream( darkTexture.centerOffset, out, version );
			};
		};
	};
	NifStream( hasDetailTexture, out, version );
	if ( (hasDetailTexture != 0) ) {
		if ( detailTexture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(detailTexture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( detailTexture.clampMode, out, version );
		NifStream( detailTexture.filterMode, out, version );
		NifStream( detailTexture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( detailTexture.ps2L, out, version );
			NifStream( detailTexture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( detailTexture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( detailTexture.hasTextureTransform, out, version );
			if ( (detailTexture.hasTextureTransform != 0) ) {
				NifStream( detailTexture.translation, out, version );
				NifStream( detailTexture.tiling, out, version );
				NifStream( detailTexture.wRotation, out, version );
				NifStream( detailTexture.transformType_, out, version );
				NifStream( detailTexture.centerOffset, out, version );
			};
		};
	};
	NifStream( hasGlossTexture, out, version );
	if ( (hasGlossTexture != 0) ) {
		if ( glossTexture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(glossTexture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( glossTexture.clampMode, out, version );
		NifStream( glossTexture.filterMode, out, version );
		NifStream( glossTexture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( glossTexture.ps2L, out, version );
			NifStream( glossTexture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( glossTexture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( glossTexture.hasTextureTransform, out, version );
			if ( (glossTexture.hasTextureTransform != 0) ) {
				NifStream( glossTexture.translation, out, version );
				NifStream( glossTexture.tiling, out, version );
				NifStream( glossTexture.wRotation, out, version );
				NifStream( glossTexture.transformType_, out, version );
				NifStream( glossTexture.centerOffset, out, version );
			};
		};
	};
	NifStream( hasGlowTexture, out, version );
	if ( (hasGlowTexture != 0) ) {
		if ( glowTexture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(glowTexture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( glowTexture.clampMode, out, version );
		NifStream( glowTexture.filterMode, out, version );
		NifStream( glowTexture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( glowTexture.ps2L, out, version );
			NifStream( glowTexture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( glowTexture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( glowTexture.hasTextureTransform, out, version );
			if ( (glowTexture.hasTextureTransform != 0) ) {
				NifStream( glowTexture.translation, out, version );
				NifStream( glowTexture.tiling, out, version );
				NifStream( glowTexture.wRotation, out, version );
				NifStream( glowTexture.transformType_, out, version );
				NifStream( glowTexture.centerOffset, out, version );
			};
		};
	};
	NifStream( hasBumpMapTexture, out, version );
	if ( (hasBumpMapTexture != 0) ) {
		if ( bumpMapTexture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(bumpMapTexture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( bumpMapTexture.clampMode, out, version );
		NifStream( bumpMapTexture.filterMode, out, version );
		NifStream( bumpMapTexture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( bumpMapTexture.ps2L, out, version );
			NifStream( bumpMapTexture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( bumpMapTexture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( bumpMapTexture.hasTextureTransform, out, version );
			if ( (bumpMapTexture.hasTextureTransform != 0) ) {
				NifStream( bumpMapTexture.translation, out, version );
				NifStream( bumpMapTexture.tiling, out, version );
				NifStream( bumpMapTexture.wRotation, out, version );
				NifStream( bumpMapTexture.transformType_, out, version );
				NifStream( bumpMapTexture.centerOffset, out, version );
			};
		};
		NifStream( bumpMapLumaScale, out, version );
		NifStream( bumpMapLumaOffset, out, version );
		NifStream( bumpMapMatrix, out, version );
	};
	NifStream( hasDecal0Texture, out, version );
	if ( (hasDecal0Texture != 0) ) {
		if ( decal0Texture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(decal0Texture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( decal0Texture.clampMode, out, version );
		NifStream( decal0Texture.filterMode, out, version );
		NifStream( decal0Texture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( decal0Texture.ps2L, out, version );
			NifStream( decal0Texture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( decal0Texture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( decal0Texture.hasTextureTransform, out, version );
			if ( (decal0Texture.hasTextureTransform != 0) ) {
				NifStream( decal0Texture.translation, out, version );
				NifStream( decal0Texture.tiling, out, version );
				NifStream( decal0Texture.wRotation, out, version );
				NifStream( decal0Texture.transformType_, out, version );
				NifStream( decal0Texture.centerOffset, out, version );
			};
		};
	};
	if ( (textureCount >= 8) ) {
		NifStream( hasDecal1Texture, out, version );
	};
	if ( (((textureCount >= 8)) && ((hasDecal1Texture != 0))) ) {
		if ( decal1Texture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(decal1Texture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( decal1Texture.clampMode, out, version );
		NifStream( decal1Texture.filterMode, out, version );
		NifStream( decal1Texture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( decal1Texture.ps2L, out, version );
			NifStream( decal1Texture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( decal1Texture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( decal1Texture.hasTextureTransform, out, version );
			if ( (decal1Texture.hasTextureTransform != 0) ) {
				NifStream( decal1Texture.translation, out, version );
				NifStream( decal1Texture.tiling, out, version );
				NifStream( decal1Texture.wRotation, out, version );
				NifStream( decal1Texture.transformType_, out, version );
				NifStream( decal1Texture.centerOffset, out, version );
			};
		};
	};
	if ( (textureCount >= 9) ) {
		NifStream( hasDecal2Texture, out, version );
	};
	if ( (((textureCount >= 9)) && ((hasDecal2Texture != 0))) ) {
		if ( decal2Texture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(decal2Texture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( decal2Texture.clampMode, out, version );
		NifStream( decal2Texture.filterMode, out, version );
		NifStream( decal2Texture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( decal2Texture.ps2L, out, version );
			NifStream( decal2Texture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( decal2Texture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( decal2Texture.hasTextureTransform, out, version );
			if ( (decal2Texture.hasTextureTransform != 0) ) {
				NifStream( decal2Texture.translation, out, version );
				NifStream( decal2Texture.tiling, out, version );
				NifStream( decal2Texture.wRotation, out, version );
				NifStream( decal2Texture.transformType_, out, version );
				NifStream( decal2Texture.centerOffset, out, version );
			};
		};
	};
	if ( (textureCount >= 10) ) {
		NifStream( hasDecal3Texture, out, version );
	};
	if ( (((textureCount >= 10)) && ((hasDecal3Texture != 0))) ) {
		if ( decal3Texture.source != NULL )
			NifStream( link_map[StaticCast<NiObject>(decal3Texture.source)], out, version );
		else
			NifStream( 0xffffffff, out, version );
		NifStream( decal3Texture.clampMode, out, version );
		NifStream( decal3Texture.filterMode, out, version );
		NifStream( decal3Texture.uvSet, out, version );
		if ( version <= 0x0A020000 ) {
			NifStream( decal3Texture.ps2L, out, version );
			NifStream( decal3Texture.ps2K, out, version );
		};
		if ( version <= 0x0401000C ) {
			NifStream( decal3Texture.unknown1, out, version );
		};
		if ( version >= 0x0A010000 ) {
			NifStream( decal3Texture.hasTextureTransform, out, version );
			if ( (decal3Texture.hasTextureTransform != 0) ) {
				NifStream( decal3Texture.translation, out, version );
				NifStream( decal3Texture.tiling, out, version );
				NifStream( decal3Texture.wRotation, out, version );
				NifStream( decal3Texture.transformType_, out, version );
				NifStream( decal3Texture.centerOffset, out, version );
			};
		};
	};
	if ( version >= 0x0A000100 ) {
		NifStream( numShaderTextures, out, version );
		for (uint i2 = 0; i2 < shaderTextures.size(); i2++) {
			NifStream( shaderTextures[i2].isUsed, out, version );
			if ( (shaderTextures[i2].isUsed != 0) ) {
				if ( shaderTextures[i2].textureData.source != NULL )
					NifStream( link_map[StaticCast<NiObject>(shaderTextures[i2].textureData.source)], out, version );
				else
					NifStream( 0xffffffff, out, version );
				NifStream( shaderTextures[i2].textureData.clampMode, out, version );
				NifStream( shaderTextures[i2].textureData.filterMode, out, version );
				NifStream( shaderTextures[i2].textureData.uvSet, out, version );
				if ( version <= 0x0A020000 ) {
					NifStream( shaderTextures[i2].textureData.ps2L, out, version );
					NifStream( shaderTextures[i2].textureData.ps2K, out, version );
				};
				if ( version <= 0x0401000C ) {
					NifStream( shaderTextures[i2].textureData.unknown1, out, version );
				};
				if ( version >= 0x0A010000 ) {
					NifStream( shaderTextures[i2].textureData.hasTextureTransform, out, version );
					if ( (shaderTextures[i2].textureData.hasTextureTransform != 0) ) {
						NifStream( shaderTextures[i2].textureData.translation, out, version );
						NifStream( shaderTextures[i2].textureData.tiling, out, version );
						NifStream( shaderTextures[i2].textureData.wRotation, out, version );
						NifStream( shaderTextures[i2].textureData.transformType_, out, version );
						NifStream( shaderTextures[i2].textureData.centerOffset, out, version );
					};
				};
				NifStream( shaderTextures[i2].unknownInt, out, version );
			};
		};
	};
}

std::string NiTexturingProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	numShaderTextures = uint(shaderTextures.size());
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
	for (uint i1 = 0; i1 < shaderTextures.size(); i1++) {
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

void NiTexturingProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
	if ( (hasBaseTexture != 0) ) {
		baseTexture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (hasDarkTexture != 0) ) {
		darkTexture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (hasDetailTexture != 0) ) {
		detailTexture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (hasGlossTexture != 0) ) {
		glossTexture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (hasGlowTexture != 0) ) {
		glowTexture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (hasBumpMapTexture != 0) ) {
		bumpMapTexture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (hasDecal0Texture != 0) ) {
		decal0Texture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (((textureCount >= 8)) && ((hasDecal1Texture != 0))) ) {
		decal1Texture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (((textureCount >= 9)) && ((hasDecal2Texture != 0))) ) {
		decal2Texture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( (((textureCount >= 10)) && ((hasDecal3Texture != 0))) ) {
		decal3Texture.source = FixLink<NiSourceTexture>( objects, link_stack, version );
	};
	if ( version >= 0x0A000100 ) {
		for (uint i2 = 0; i2 < shaderTextures.size(); i2++) {
			if ( (shaderTextures[i2].isUsed != 0) ) {
				shaderTextures[i2].textureData.source = FixLink<NiSourceTexture>( objects, link_stack, version );
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
	for (uint i1 = 0; i1 < shaderTextures.size(); i1++) {
		if ( shaderTextures[i1].textureData.source != NULL )
			refs.push_back(StaticCast<NiObject>(shaderTextures[i1].textureData.source));
	};
	return refs;
}

void NiTransformController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::Read( in, link_stack, version, user_version );
}

void NiTransformController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSingleInterpolatorController::Write( out, link_map, version, user_version );
}

std::string NiTransformController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	return out.str();
}

void NiTransformController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTransformController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	return refs;
}

void NiTransformData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiKeyframeData::Read( in, link_stack, version, user_version );
}

void NiTransformData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiKeyframeData::Write( out, link_map, version, user_version );
}

std::string NiTransformData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiKeyframeData::asString();
	return out.str();
}

void NiTransformData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiKeyframeData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTransformData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyframeData::GetRefs();
	return refs;
}

void NiTransformInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( translation, in, version );
	NifStream( rotation, in, version );
	NifStream( scale, in, version );
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
		for (uint i2 = 0; i2 < 3; i2++) {
			NifStream( unknownBytes[i2], in, version );
		};
	};
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiTransformInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( translation, out, version );
	NifStream( rotation, out, version );
	NifStream( scale, out, version );
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
		for (uint i2 = 0; i2 < 3; i2++) {
			NifStream( unknownBytes[i2], out, version );
		};
	};
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiTransformInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiInterpolator::asString();
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < 3; i1++) {
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

void NiTransformInterpolator::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiTransformData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiTransformInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiTriShape::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::Read( in, link_stack, version, user_version );
}

void NiTriShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTriBasedGeom::Write( out, link_map, version, user_version );
}

std::string NiTriShape::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiTriShape::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
	return refs;
}

void NiTriShapeData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::Read( in, link_stack, version, user_version );
	NifStream( numTrianglePoints, in, version );
	if ( version >= 0x0A010000 ) {
		NifStream( hasTriangles, in, version );
	};
	if ( version <= 0x0A000102 ) {
		triangles.resize(numTriangles);
		for (uint i2 = 0; i2 < triangles.size(); i2++) {
			NifStream( triangles[i2], in, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		if ( (hasTriangles != 0) ) {
			triangles.resize(numTriangles);
			for (uint i3 = 0; i3 < triangles.size(); i3++) {
				NifStream( triangles[i3], in, version );
			};
		};
	};
	NifStream( numMatchGroups, in, version );
	matchGroups.resize(numMatchGroups);
	for (uint i1 = 0; i1 < matchGroups.size(); i1++) {
		NifStream( matchGroups[i1].numVertices, in, version );
		matchGroups[i1].vertexIndices.resize(matchGroups[i1].numVertices);
		for (uint i2 = 0; i2 < matchGroups[i1].vertexIndices.size(); i2++) {
			NifStream( matchGroups[i1].vertexIndices[i2], in, version );
		};
	};
}

void NiTriShapeData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTriBasedGeomData::Write( out, link_map, version, user_version );
	numMatchGroups = ushort(matchGroups.size());
	NifStream( numTrianglePoints, out, version );
	if ( version >= 0x0A010000 ) {
		NifStream( hasTriangles, out, version );
	};
	if ( version <= 0x0A000102 ) {
		for (uint i2 = 0; i2 < triangles.size(); i2++) {
			NifStream( triangles[i2], out, version );
		};
	};
	if ( version >= 0x0A010000 ) {
		if ( (hasTriangles != 0) ) {
			for (uint i3 = 0; i3 < triangles.size(); i3++) {
				NifStream( triangles[i3], out, version );
			};
		};
	};
	NifStream( numMatchGroups, out, version );
	for (uint i1 = 0; i1 < matchGroups.size(); i1++) {
		matchGroups[i1].numVertices = ushort(matchGroups[i1].vertexIndices.size());
		NifStream( matchGroups[i1].numVertices, out, version );
		for (uint i2 = 0; i2 < matchGroups[i1].vertexIndices.size(); i2++) {
			NifStream( matchGroups[i1].vertexIndices[i2], out, version );
		};
	};
}

std::string NiTriShapeData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTriBasedGeomData::asString();
	numMatchGroups = ushort(matchGroups.size());
	out << "  Num Triangle Points:  " << numTrianglePoints << endl;
	out << "  Has Triangles:  " << hasTriangles << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < triangles.size(); i1++) {
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
	for (uint i1 = 0; i1 < matchGroups.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		matchGroups[i1].numVertices = ushort(matchGroups[i1].vertexIndices.size());
		out << "    Num Vertices:  " << matchGroups[i1].numVertices << endl;
		array_output_count = 0;
		for (uint i2 = 0; i2 < matchGroups[i1].vertexIndices.size(); i2++) {
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

void NiTriShapeData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriShapeData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeomData::GetRefs();
	return refs;
}

void NiTriStrips::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::Read( in, link_stack, version, user_version );
}

void NiTriStrips::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTriBasedGeom::Write( out, link_map, version, user_version );
}

std::string NiTriStrips::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiTriStrips::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriStrips::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
	return refs;
}

void NiTriStripsData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::Read( in, link_stack, version, user_version );
	NifStream( numStrips, in, version );
	stripLengths.resize(numStrips);
	for (uint i1 = 0; i1 < stripLengths.size(); i1++) {
		NifStream( stripLengths[i1], in, version );
	};
	if ( version >= 0x0A010000 ) {
		NifStream( hasPoints, in, version );
	};
	if ( version <= 0x0A000102 ) {
		points.resize(numStrips);
		for (uint i2 = 0; i2 < points.size(); i2++) {
			points[i2].resize(stripLengths[i2]);
			for (uint i3 = 0; i3 < stripLengths[i2]; i3++) {
				NifStream( points[i2][i3], in, version );
			};
		};
	};
	if ( version >= 0x0A010000 ) {
		if ( (hasPoints != 0) ) {
			points.resize(numStrips);
			for (uint i3 = 0; i3 < points.size(); i3++) {
				points[i3].resize(stripLengths[i3]);
				for (uint i4 = 0; i4 < stripLengths[i3]; i4++) {
					NifStream( points[i3][i4], in, version );
				};
			};
		};
	};
}

void NiTriStripsData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTriBasedGeomData::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < points.size(); i1++)
		stripLengths[i1] = ushort(points[i1].size());
	numStrips = ushort(stripLengths.size());
	NifStream( numStrips, out, version );
	for (uint i1 = 0; i1 < stripLengths.size(); i1++) {
		NifStream( stripLengths[i1], out, version );
	};
	if ( version >= 0x0A010000 ) {
		NifStream( hasPoints, out, version );
	};
	if ( version <= 0x0A000102 ) {
		for (uint i2 = 0; i2 < points.size(); i2++) {
			for (uint i3 = 0; i3 < stripLengths[i2]; i3++) {
				NifStream( points[i2][i3], out, version );
			};
		};
	};
	if ( version >= 0x0A010000 ) {
		if ( (hasPoints != 0) ) {
			for (uint i3 = 0; i3 < points.size(); i3++) {
				for (uint i4 = 0; i4 < stripLengths[i3]; i4++) {
					NifStream( points[i3][i4], out, version );
				};
			};
		};
	};
}

std::string NiTriStripsData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTriBasedGeomData::asString();
	for (uint i1 = 0; i1 < points.size(); i1++)
		stripLengths[i1] = ushort(points[i1].size());
	numStrips = ushort(stripLengths.size());
	out << "  Num Strips:  " << numStrips << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < stripLengths.size(); i1++) {
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
	for (uint i1 = 0; i1 < points.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < stripLengths[i1]; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Points[" << i2 << "]:  " << points[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiTriStripsData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriStripsData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeomData::GetRefs();
	return refs;
}

void NiClod::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::Read( in, link_stack, version, user_version );
}

void NiClod::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTriBasedGeom::Write( out, link_map, version, user_version );
}

std::string NiClod::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiClod::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiClod::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
	return refs;
}

void NiClodData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::Read( in, link_stack, version, user_version );
	NifStream( unknownShorts, in, version );
	NifStream( unknownCount1, in, version );
	NifStream( unknownCount2, in, version );
	NifStream( unknownCount3, in, version );
	NifStream( unknownFloat, in, version );
	NifStream( unknownShort, in, version );
	unknownClodShorts1.resize(unknownCount1);
	for (uint i1 = 0; i1 < unknownClodShorts1.size(); i1++) {
		for (uint i2 = 0; i2 < 6; i2++) {
			NifStream( unknownClodShorts1[i1][i2], in, version );
		};
	};
	unknownClodShorts2.resize(unknownCount2);
	for (uint i1 = 0; i1 < unknownClodShorts2.size(); i1++) {
		NifStream( unknownClodShorts2[i1], in, version );
	};
	unknownClodShorts3.resize(unknownCount3);
	for (uint i1 = 0; i1 < unknownClodShorts3.size(); i1++) {
		for (uint i2 = 0; i2 < 6; i2++) {
			NifStream( unknownClodShorts3[i1][i2], in, version );
		};
	};
}

void NiClodData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTriBasedGeomData::Write( out, link_map, version, user_version );
	unknownCount3 = ushort(unknownClodShorts3.size());
	unknownCount2 = ushort(unknownClodShorts2.size());
	unknownCount1 = ushort(unknownClodShorts1.size());
	NifStream( unknownShorts, out, version );
	NifStream( unknownCount1, out, version );
	NifStream( unknownCount2, out, version );
	NifStream( unknownCount3, out, version );
	NifStream( unknownFloat, out, version );
	NifStream( unknownShort, out, version );
	for (uint i1 = 0; i1 < unknownClodShorts1.size(); i1++) {
		for (uint i2 = 0; i2 < 6; i2++) {
			NifStream( unknownClodShorts1[i1][i2], out, version );
		};
	};
	for (uint i1 = 0; i1 < unknownClodShorts2.size(); i1++) {
		NifStream( unknownClodShorts2[i1], out, version );
	};
	for (uint i1 = 0; i1 < unknownClodShorts3.size(); i1++) {
		for (uint i2 = 0; i2 < 6; i2++) {
			NifStream( unknownClodShorts3[i1][i2], out, version );
		};
	};
}

std::string NiClodData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTriBasedGeomData::asString();
	unknownCount3 = ushort(unknownClodShorts3.size());
	unknownCount2 = ushort(unknownClodShorts2.size());
	unknownCount1 = ushort(unknownClodShorts1.size());
	out << "  Unknown Shorts:  " << unknownShorts << endl;
	out << "  Unknown Count 1:  " << unknownCount1 << endl;
	out << "  Unknown Count 2:  " << unknownCount2 << endl;
	out << "  Unknown Count 3:  " << unknownCount3 << endl;
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownClodShorts1.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 6; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Clod Shorts 1[" << i2 << "]:  " << unknownClodShorts1[i1][i2] << endl;
			array_output_count++;
		};
	};
	array_output_count = 0;
	for (uint i1 = 0; i1 < unknownClodShorts2.size(); i1++) {
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
	for (uint i1 = 0; i1 < unknownClodShorts3.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		for (uint i2 = 0; i2 < 6; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Clod Shorts 3[" << i2 << "]:  " << unknownClodShorts3[i1][i2] << endl;
			array_output_count++;
		};
	};
	return out.str();
}

void NiClodData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiClodData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeomData::GetRefs();
	return refs;
}

void NiUVController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiTimeController::Read( in, link_stack, version, user_version );
	NifStream( unknownShort, in, version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
}

void NiUVController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTimeController::Write( out, link_map, version, user_version );
	NifStream( unknownShort, out, version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
}

std::string NiUVController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiTimeController::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiUVController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	data = FixLink<NiUVData>( objects, link_stack, version );
}

std::list<NiObjectRef> NiUVController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiUVData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( uvGroups[i1].numKeys, in, version );
		if ( (uvGroups[i1].numKeys != 0) ) {
			NifStream( uvGroups[i1].interpolation, in, version );
		};
		uvGroups[i1].keys.resize(uvGroups[i1].numKeys);
		for (uint i2 = 0; i2 < uvGroups[i1].keys.size(); i2++) {
			NifStream( uvGroups[i1].keys[i2], in, version, uvGroups[i1].interpolation );
		};
	};
}

void NiUVData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 4; i1++) {
		uvGroups[i1].numKeys = uint(uvGroups[i1].keys.size());
		NifStream( uvGroups[i1].numKeys, out, version );
		if ( (uvGroups[i1].numKeys != 0) ) {
			NifStream( uvGroups[i1].interpolation, out, version );
		};
		for (uint i2 = 0; i2 < uvGroups[i1].keys.size(); i2++) {
			NifStream( uvGroups[i1].keys[i2], out, version, uvGroups[i1].interpolation );
		};
	};
}

std::string NiUVData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiObject::asString();
	array_output_count = 0;
	for (uint i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		uvGroups[i1].numKeys = uint(uvGroups[i1].keys.size());
		out << "    Num Keys:  " << uvGroups[i1].numKeys << endl;
		if ( (uvGroups[i1].numKeys != 0) ) {
			out << "      Interpolation:  " << uvGroups[i1].interpolation << endl;
		};
		array_output_count = 0;
		for (uint i2 = 0; i2 < uvGroups[i1].keys.size(); i2++) {
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

void NiUVData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiUVData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiVectorExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( vectorData, in, version );
	NifStream( unknownFloat, in, version );
}

void NiVectorExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	NifStream( vectorData, out, version );
	NifStream( unknownFloat, out, version );
}

std::string NiVectorExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	out << "  Vector Data:  " << vectorData << endl;
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void NiVectorExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiVectorExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiVertexColorProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
	NifStream( vertexMode, in, version );
	NifStream( lightingMode, in, version );
}

void NiVertexColorProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
	NifStream( vertexMode, out, version );
	NifStream( lightingMode, out, version );
}

std::string NiVertexColorProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Vertex Mode:  " << vertexMode << endl;
	out << "  Lighting Mode:  " << lightingMode << endl;
	return out.str();
}

void NiVertexColorProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiVertexColorProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiVertWeightsExtraData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	NifStream( numBytes, in, version );
	NifStream( numVertices, in, version );
	weight.resize(numVertices);
	for (uint i1 = 0; i1 < weight.size(); i1++) {
		NifStream( weight[i1], in, version );
	};
}

void NiVertWeightsExtraData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	numVertices = ushort(weight.size());
	NifStream( numBytes, out, version );
	NifStream( numVertices, out, version );
	for (uint i1 = 0; i1 < weight.size(); i1++) {
		NifStream( weight[i1], out, version );
	};
}

std::string NiVertWeightsExtraData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiExtraData::asString();
	numVertices = ushort(weight.size());
	out << "  Num Bytes:  " << numBytes << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < weight.size(); i1++) {
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

void NiVertWeightsExtraData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiVertWeightsExtraData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiExtraData::GetRefs();
	return refs;
}

void NiVisController::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiSingleInterpolatorController::Read( in, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiVisController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSingleInterpolatorController::Write( out, link_map, version, user_version );
	if ( version <= 0x0A010000 ) {
		if ( data != NULL )
			NifStream( link_map[StaticCast<NiObject>(data)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiVisController::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiSingleInterpolatorController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiVisController::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		data = FixLink<NiVisData>( objects, link_stack, version );
	};
}

std::list<NiObjectRef> NiVisController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

void NiVisData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::Read( in, link_stack, version, user_version );
	NifStream( numVisKeys, in, version );
	visKeys.resize(numVisKeys);
	for (uint i1 = 0; i1 < visKeys.size(); i1++) {
		NifStream( visKeys[i1], in, version, 1 );
	};
}

void NiVisData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AKeyedData::Write( out, link_map, version, user_version );
	numVisKeys = uint(visKeys.size());
	NifStream( numVisKeys, out, version );
	for (uint i1 = 0; i1 < visKeys.size(); i1++) {
		NifStream( visKeys[i1], out, version, 1 );
	};
}

std::string NiVisData::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << AKeyedData::asString();
	numVisKeys = uint(visKeys.size());
	out << "  Num Vis Keys:  " << numVisKeys << endl;
	array_output_count = 0;
	for (uint i1 = 0; i1 < visKeys.size(); i1++) {
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

void NiVisData::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AKeyedData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiVisData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AKeyedData::GetRefs();
	return refs;
}

void NiWireframeProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
}

void NiWireframeProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
}

std::string NiWireframeProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiWireframeProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiWireframeProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void NiZBufferProperty::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::Read( in, link_stack, version, user_version );
	NifStream( flags, in, version );
	if ( version >= 0x0401000C ) {
		NifStream( function, in, version );
	};
}

void NiZBufferProperty::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiProperty::Write( out, link_map, version, user_version );
	NifStream( flags, out, version );
	if ( version >= 0x0401000C ) {
		NifStream( function, out, version );
	};
}

std::string NiZBufferProperty::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Function:  " << function << endl;
	return out.str();
}

void NiZBufferProperty::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiZBufferProperty::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

void RootCollisionNode::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::Read( in, link_stack, version, user_version );
}

void RootCollisionNode::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiNode::Write( out, link_map, version, user_version );
}

std::string RootCollisionNode::InternalAsString( bool verbose ) const {
	stringstream out;
	uint array_output_count = 0;
	out << NiNode::asString();
	return out.str();
}

void RootCollisionNode::InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> RootCollisionNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

