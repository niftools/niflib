/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../obj/NiObject.h"
using namespace Niflib;
using namespace std;

#include "../obj/bhkBlendCollisionObject.h"
#include "../obj/bhkBlendController.h"
#include "../obj/bhkBoxShape.h"
#include "../obj/bhkCapsuleShape.h"
#include "../obj/bhkCollisionObject.h"
#include "../obj/bhkConvexVerticesShape.h"
#include "../obj/bhkHingeConstraint.h"
#include "../obj/bhkLimitedHingeConstraint.h"
#include "../obj/bhkListShape.h"
#include "../obj/bhkMalleableConstraint.h"
#include "../obj/bhkMoppBvTreeShape.h"
#include "../obj/bhkMultiSphereShape.h"
#include "../obj/bhkNiTriStripsShape.h"
#include "../obj/bhkPackedNiTriStripsShape.h"
#include "../obj/bhkPrismaticConstraint.h"
#include "../obj/bhkRagdollConstraint.h"
#include "../obj/bhkRigidBody.h"
#include "../obj/bhkRigidBodyT.h"
#include "../obj/bhkSimpleShapePhantom.h"
#include "../obj/bhkSPCollisionObject.h"
#include "../obj/bhkSphereShape.h"
#include "../obj/bhkStiffSpringConstraint.h"
#include "../obj/bhkTransformShape.h"
#include "../obj/bhkConvexTransformShape.h"
#include "../obj/BSBound.h"
#include "../obj/BSFurnitureMarker.h"
#include "../obj/BSParentVelocityModifier.h"
#include "../obj/BSPSysArrayEmitter.h"
#include "../obj/BSXFlags.h"
#include "../obj/hkPackedNiTriStripsData.h"
#include "../obj/NiAlphaController.h"
#include "../obj/NiAlphaProperty.h"
#include "../obj/NiAmbientLight.h"
#include "../obj/NiAutoNormalParticlesData.h"
#include "../obj/NiBinaryExtraData.h"
#include "../obj/NiBlendBoolInterpolator.h"
#include "../obj/NiBlendFloatInterpolator.h"
#include "../obj/NiBlendPoint3Interpolator.h"
#include "../obj/NiBlendTransformInterpolator.h"
#include "../obj/NiBoneLODController.h"
#include "../obj/NiBoolData.h"
#include "../obj/NiBooleanExtraData.h"
#include "../obj/NiBoolInterpolator.h"
#include "../obj/NiBoolTimelineInterpolator.h"
#include "../obj/NiBSBoneLODController.h"
#include "../obj/NiBSplineBasisData.h"
#include "../obj/NiBSplineCompFloatInterpolator.h"
#include "../obj/NiBSplineCompPoint3Interpolator.h"
#include "../obj/NiBSplineCompTransformInterpolator.h"
#include "../obj/NiBSplineData.h"
#include "../obj/NiCamera.h"
#include "../obj/NiCollisionData.h"
#include "../obj/NiColorData.h"
#include "../obj/NiColorExtraData.h"
#include "../obj/NiControllerManager.h"
#include "../obj/NiControllerSequence.h"
#include "../obj/NiDefaultAVObjectPalette.h"
#include "../obj/NiDirectionalLight.h"
#include "../obj/NiDitherProperty.h"
#include "../obj/NiFlipController.h"
#include "../obj/NiFloatData.h"
#include "../obj/NiFloatExtraData.h"
#include "../obj/NiFloatExtraDataController.h"
#include "../obj/NiFloatInterpolator.h"
#include "../obj/NiFloatsExtraData.h"
#include "../obj/NiFogProperty.h"
#include "../obj/NiGeomMorpherController.h"
#include "../obj/NiGravity.h"
#include "../obj/NiIntegerExtraData.h"
#include "../obj/NiIntegersExtraData.h"
#include "../obj/NiKeyframeController.h"
#include "../obj/BSKeyframeController.h"
#include "../obj/NiKeyframeData.h"
#include "../obj/NiLightColorController.h"
#include "../obj/NiLightDimmerController.h"
#include "../obj/NiLookAtController.h"
#include "../obj/NiLookAtInterpolator.h"
#include "../obj/NiMaterialColorController.h"
#include "../obj/NiMaterialProperty.h"
#include "../obj/NiMeshPSysData.h"
#include "../obj/NiMorphData.h"
#include "../obj/NiMultiTargetTransformController.h"
#include "../obj/NiNode.h"
#include "../obj/AvoidNode.h"
#include "../obj/FxWidget.h"
#include "../obj/FxButton.h"
#include "../obj/FxRadioButton.h"
#include "../obj/NiBillboardNode.h"
#include "../obj/NiBSAnimationNode.h"
#include "../obj/NiBSParticleNode.h"
#include "../obj/NiLODNode.h"
#include "../obj/NiPalette.h"
#include "../obj/NiParticleBomb.h"
#include "../obj/NiParticleColorModifier.h"
#include "../obj/NiParticleGrowFade.h"
#include "../obj/NiParticleMeshModifier.h"
#include "../obj/NiParticleRotation.h"
#include "../obj/NiParticles.h"
#include "../obj/NiAutoNormalParticles.h"
#include "../obj/NiParticleMeshes.h"
#include "../obj/NiParticlesData.h"
#include "../obj/NiParticleMeshesData.h"
#include "../obj/NiParticleSystem.h"
#include "../obj/NiMeshParticleSystem.h"
#include "../obj/NiParticleSystemController.h"
#include "../obj/NiBSPArrayController.h"
#include "../obj/NiPathController.h"
#include "../obj/NiPathInterpolator.h"
#include "../obj/NiPixelData.h"
#include "../obj/NiPlanarCollider.h"
#include "../obj/NiPoint3Interpolator.h"
#include "../obj/NiPointLight.h"
#include "../obj/NiPosData.h"
#include "../obj/NiPSysAgeDeathModifier.h"
#include "../obj/NiPSysBombModifier.h"
#include "../obj/NiPSysBoundUpdateModifier.h"
#include "../obj/NiPSysBoxEmitter.h"
#include "../obj/NiPSysColliderManager.h"
#include "../obj/NiPSysColorModifier.h"
#include "../obj/NiPSysCylinderEmitter.h"
#include "../obj/NiPSysData.h"
#include "../obj/NiPSysDragModifier.h"
#include "../obj/NiPSysEmitterCtlr.h"
#include "../obj/NiPSysEmitterCtlrData.h"
#include "../obj/NiPSysEmitterDeclinationCtlr.h"
#include "../obj/NiPSysEmitterDeclinationVarCtlr.h"
#include "../obj/NiPSysEmitterInitialRadiusCtlr.h"
#include "../obj/NiPSysEmitterLifeSpanCtlr.h"
#include "../obj/NiPSysEmitterSpeedCtlr.h"
#include "../obj/NiPSysGravityModifier.h"
#include "../obj/NiPSysGravityStrengthCtlr.h"
#include "../obj/NiPSysGrowFadeModifier.h"
#include "../obj/NiPSysMeshEmitter.h"
#include "../obj/NiPSysMeshUpdateModifier.h"
#include "../obj/NiPSysModifierActiveCtlr.h"
#include "../obj/NiPSysPlanarCollider.h"
#include "../obj/NiPSysPositionModifier.h"
#include "../obj/NiPSysResetOnLoopCtlr.h"
#include "../obj/NiPSysRotationModifier.h"
#include "../obj/NiPSysSpawnModifier.h"
#include "../obj/NiPSysSphereEmitter.h"
#include "../obj/NiPSysUpdateCtlr.h"
#include "../obj/NiRangeLODData.h"
#include "../obj/NiRotatingParticles.h"
#include "../obj/NiRotatingParticlesData.h"
#include "../obj/NiScreenLODData.h"
#include "../obj/NiSequenceStreamHelper.h"
#include "../obj/NiShadeProperty.h"
#include "../obj/NiSkinData.h"
#include "../obj/NiSkinInstance.h"
#include "../obj/NiSkinPartition.h"
#include "../obj/NiSourceTexture.h"
#include "../obj/NiSpecularProperty.h"
#include "../obj/NiSphericalCollider.h"
#include "../obj/NiSpotLight.h"
#include "../obj/NiStencilProperty.h"
#include "../obj/NiStringExtraData.h"
#include "../obj/NiStringPalette.h"
#include "../obj/NiStringsExtraData.h"
#include "../obj/NiTextKeyExtraData.h"
#include "../obj/NiTextureEffect.h"
#include "../obj/NiTextureTransformController.h"
#include "../obj/NiTexturingProperty.h"
#include "../obj/NiTransformController.h"
#include "../obj/NiTransformData.h"
#include "../obj/NiTransformInterpolator.h"
#include "../obj/NiTriShape.h"
#include "../obj/NiTriShapeData.h"
#include "../obj/NiTriStrips.h"
#include "../obj/NiTriStripsData.h"
#include "../obj/NiUVController.h"
#include "../obj/NiUVData.h"
#include "../obj/NiVectorExtraData.h"
#include "../obj/NiVertexColorProperty.h"
#include "../obj/NiVertWeightsExtraData.h"
#include "../obj/NiVisController.h"
#include "../obj/NiVisData.h"
#include "../obj/NiWireframeProperty.h"
#include "../obj/NiZBufferProperty.h"
#include "../obj/RootCollisionNode.h"

void NiObject::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
}

void NiObject::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
}

std::string NiObject::InternalAsString( bool verbose ) const {
	stringstream out;
	return out.str();
}

void NiObject::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiObject::asString();
	return out.str();
}

void AKeyedData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiObject::asString();
	out << "  Next Modifier:  " << nextModifier << endl;
	out << "  Controller:  " << controller << endl;
	return out.str();
}

void AParticleModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		nextModifier = DynamicCast<AParticleModifier>(objects[link_stack.front()]);
		if ( nextModifier == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		nextModifier = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		controller = DynamicCast<NiParticleSystemController>(objects[link_stack.front()]);
		if ( controller == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		controller = NULL;
	link_stack.pop_front();
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
	out << NiObject::asString();
	return out.str();
}

void bhkRefObject::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkRefObject::asString();
	return out.str();
}

void bhkSerializable::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkSerializable::asString();
	numBodies = uint(bodies.size());
	out << "  Num Bodies:  " << numBodies << endl;
	for (uint i1 = 0; i1 < bodies.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Bodies[" << i1 << "]:  " << bodies[i1] << endl;
	};
	out << "  Priority:  " << priority << endl;
	return out.str();
}

void AbhkConstraint::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSerializable::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < bodies.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			bodies[i1] = DynamicCast<bhkShape>(objects[link_stack.front()]);
			if ( bodies[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			bodies[i1] = NULL;
		link_stack.pop_front();
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

void AbhkRagdollConstraint::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkSerializable::asString();
	return out.str();
}

void bhkShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkShape::asString();
	return out.str();
}

void AbhkShapeCollection::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkShape::asString();
	out << "  Material:  " << material << endl;
	return out.str();
}

void bhkSphereRepShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkSphereRepShape::asString();
	return out.str();
}

void bhkConvexShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkShape::asString();
	return out.str();
}

void bhkWorldObject::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
}

void bhkEntity::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkWorldObject::Write( out, link_map, version, user_version );
	if ( shape != NULL )
		NifStream( link_map[StaticCast<NiObject>(shape)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( layer, out, version );
}

std::string bhkEntity::InternalAsString( bool verbose ) const {
	stringstream out;
	out << bhkWorldObject::asString();
	out << "  Shape:  " << shape << endl;
	out << "  Layer:  " << layer << endl;
	return out.str();
}

void bhkEntity::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkWorldObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		shape = DynamicCast<bhkShape>(objects[link_stack.front()]);
		if ( shape == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		shape = NULL;
	link_stack.pop_front();
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
	out << NiObject::asString();
	out << "  Parent:  " << parent << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Body:  " << body << endl;
	return out.str();
}

void NiCollisionObject::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		parent = DynamicCast<NiAVObject>(objects[link_stack.front()]);
		if ( parent == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		parent = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		body = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( body == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		body = NULL;
	link_stack.pop_front();
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
	out << NiObject::asString();
	out << "  Name:  " << name << endl;
	out << "  Next Extra Data:  " << nextExtraData << endl;
	return out.str();
}

void NiExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x04020200 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			nextExtraData = DynamicCast<NiExtraData>(objects[link_stack.front()]);
			if ( nextExtraData == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			nextExtraData = NULL;
		link_stack.pop_front();
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
	out << NiObject::asString();
	return out.str();
}

void NiInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiInterpolator::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void NiBlendInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBlendInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	return refs;
}

void NiBSplineInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::Read( in, link_stack, version, user_version );
	NifStream( startTime, in, version );
	NifStream( stopTime, in, version );
}

void NiBSplineInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiInterpolator::Write( out, link_map, version, user_version );
	NifStream( startTime, out, version );
	NifStream( stopTime, out, version );
}

std::string NiBSplineInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiInterpolator::asString();
	out << "  Start Time:  " << startTime << endl;
	out << "  Stop Time:  " << stopTime << endl;
	return out.str();
}

void NiBSplineInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSplineInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
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
	out << NiObject::asString();
	numExtraDataList = uint(extraDataList.size());
	out << "  Name:  " << name << endl;
	out << "  Extra Data:  " << extraData << endl;
	out << "  Num Extra Data List:  " << numExtraDataList << endl;
	for (uint i1 = 0; i1 < extraDataList.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Extra Data List[" << i1 << "]:  " << extraDataList[i1] << endl;
	};
	out << "  Controller:  " << controller << endl;
	return out.str();
}

void NiObjectNET::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x04020200 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			extraData = DynamicCast<NiExtraData>(objects[link_stack.front()]);
			if ( extraData == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			extraData = NULL;
		link_stack.pop_front();
	};
	if ( version >= 0x0A000100 ) {
		for (uint i2 = 0; i2 < extraDataList.size(); i2++) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				extraDataList[i2] = DynamicCast<NiExtraData>(objects[link_stack.front()]);
				if ( extraDataList[i2] == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				extraDataList[i2] = NULL;
			link_stack.pop_front();
		};
	};
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		controller = DynamicCast<NiTimeController>(objects[link_stack.front()]);
		if ( controller == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		controller = NULL;
	link_stack.pop_front();
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
	out << NiObjectNET::asString();
	numProperties = uint(properties.size());
	out << "  Flags:  " << flags << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Velocity:  " << velocity << endl;
	out << "  Num Properties:  " << numProperties << endl;
	for (uint i1 = 0; i1 < properties.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Properties[" << i1 << "]:  " << properties[i1] << endl;
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

void NiAVObject::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObjectNET::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < properties.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			properties[i1] = DynamicCast<NiProperty>(objects[link_stack.front()]);
			if ( properties[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			properties[i1] = NULL;
		link_stack.pop_front();
	};
	if ( ( version >= 0x0A000100 ) && ( version <= 0x0A020000 ) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			collisionData = DynamicCast<NiCollisionData>(objects[link_stack.front()]);
			if ( collisionData == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			collisionData = NULL;
		link_stack.pop_front();
	};
	if ( version >= 0x14000004 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			collisionObject = DynamicCast<NiCollisionObject>(objects[link_stack.front()]);
			if ( collisionObject == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			collisionObject = NULL;
		link_stack.pop_front();
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
	if ( version <= 0x04000002 ) {
		NifStream( hasAffectedNodeList_, in, version );
		if ( (hasAffectedNodeList_ != 0) ) {
			NifStream( affectedNodeList_, in, version );
		};
	};
	if ( version >= 0x0A020000 ) {
		NifStream( switchState, in, version );
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
	numAffectedNodes = uint(affectedNodes.size());
	if ( version <= 0x04000002 ) {
		NifStream( hasAffectedNodeList_, out, version );
		if ( (hasAffectedNodeList_ != 0) ) {
			NifStream( affectedNodeList_, out, version );
		};
	};
	if ( version >= 0x0A020000 ) {
		NifStream( switchState, out, version );
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
	out << NiAVObject::asString();
	numAffectedNodes = uint(affectedNodes.size());
	out << "  Has Affected Node List?:  " << hasAffectedNodeList_ << endl;
	if ( (hasAffectedNodeList_ != 0) ) {
		out << "    Affected Node List?:  " << affectedNodeList_ << endl;
	};
	out << "  Switch State:  " << switchState << endl;
	out << "  Num Affected Nodes:  " << numAffectedNodes << endl;
	for (uint i1 = 0; i1 < affectedNodes.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Affected Nodes[" << i1 << "]:  " << affectedNodes[i1] << endl;
	};
	return out.str();
}

void NiDynamicEffect::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAVObject::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		for (uint i2 = 0; i2 < affectedNodes.size(); i2++) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				affectedNodes[i2] = DynamicCast<NiAVObject>(objects[link_stack.front()]);
				if ( affectedNodes[i2] == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				affectedNodes[i2] = NULL;
			link_stack.pop_front();
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
	out << NiDynamicEffect::asString();
	out << "  Dimmer:  " << dimmer << endl;
	out << "  Ambient Color:  " << ambientColor << endl;
	out << "  Diffuse Color:  " << diffuseColor << endl;
	out << "  Specular Color:  " << specularColor << endl;
	return out.str();
}

void NiLight::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiObjectNET::asString();
	return out.str();
}

void NiProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiObject::asString();
	out << "  Name:  " << name << endl;
	out << "  Order:  " << order << endl;
	out << "  Target:  " << target << endl;
	out << "  Active:  " << active << endl;
	return out.str();
}

void NiPSysModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		target = DynamicCast<NiParticleSystem>(objects[link_stack.front()]);
		if ( target == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		target = NULL;
	link_stack.pop_front();
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
	NifStream( radiusVariation, in, version );
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
	NifStream( radiusVariation, out, version );
	NifStream( lifeSpan, out, version );
	NifStream( lifeSpanVariation, out, version );
}

std::string NiPSysEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
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

void NiPSysEmitter::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	if ( version >= 0x14000004 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiPSysVolumeEmitter::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiPSysEmitter::Write( out, link_map, version, user_version );
	if ( version >= 0x14000004 ) {
		if ( emitterObject != NULL )
			NifStream( link_map[StaticCast<NiObject>(emitterObject)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiPSysVolumeEmitter::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiPSysEmitter::asString();
	out << "  Emitter Object:  " << emitterObject << endl;
	return out.str();
}

void NiPSysVolumeEmitter::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysEmitter::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x14000004 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			emitterObject = DynamicCast<NiNode>(objects[link_stack.front()]);
			if ( emitterObject == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			emitterObject = NULL;
		link_stack.pop_front();
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

void NiTimeController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		nextController = DynamicCast<NiTimeController>(objects[link_stack.front()]);
		if ( nextController == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		nextController = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		target = DynamicCast<NiObjectNET>(objects[link_stack.front()]);
		if ( target == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		target = NULL;
	link_stack.pop_front();
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
	NifStream( unknownInt2, in, version );
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
	NifStream( unknownInt2, out, version );
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
	out << NiTimeController::asString();
	numNodeGroups = uint(nodeGroups.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Num Node Groups:  " << numNodeGroups << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	for (uint i1 = 0; i1 < nodeGroups.size(); i1++) {
		nodeGroups[i1].numNodes = uint(nodeGroups[i1].nodes.size());
		out << "    Num Nodes:  " << nodeGroups[i1].numNodes << endl;
		for (uint i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Nodes[" << i2 << "]:  " << nodeGroups[i1].nodes[i2] << endl;
		};
	};
	return out.str();
}

void ABoneLODController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < nodeGroups.size(); i1++) {
		for (uint i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				nodeGroups[i1].nodes[i2] = DynamicCast<NiNode>(objects[link_stack.front()]);
				if ( nodeGroups[i1].nodes[i2] == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				nodeGroups[i1].nodes[i2] = NULL;
			link_stack.pop_front();
		};
	};
}

std::list<NiObjectRef> ABoneLODController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	for (uint i1 = 0; i1 < nodeGroups.size(); i1++) {
		for (uint i2 = 0; i2 < nodeGroups[i1].nodes.size(); i2++) {
			if ( nodeGroups[i1].nodes[i2] != NULL )
				refs.push_back(StaticCast<NiObject>(nodeGroups[i1].nodes[i2]));
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
	out << NiTimeController::asString();
	out << "  Interpolator:  " << interpolator << endl;
	return out.str();
}

void NiSingleInterpolatorController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A020000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			interpolator = DynamicCast<NiInterpolator>(objects[link_stack.front()]);
			if ( interpolator == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			interpolator = NULL;
		link_stack.pop_front();
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
	out << NiSingleInterpolatorController::asString();
	out << "  Modifier Name:  " << modifierName << endl;
	return out.str();
}

void APSysCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> APSysCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	return refs;
}

void NiTriBasedGeom::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiAVObject::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	if ( version >= 0x0A000100 ) {
		NifStream( hasShader, in, version );
		if ( (hasShader != 0) ) {
			NifStream( shaderName, in, version );
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
	};
}

void NiTriBasedGeom::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiAVObject::Write( out, link_map, version, user_version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( skinInstance != NULL )
		NifStream( link_map[StaticCast<NiObject>(skinInstance)], out, version );
	else
		NifStream( 0xffffffff, out, version );
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

std::string NiTriBasedGeom::InternalAsString( bool verbose ) const {
	stringstream out;
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

void NiTriBasedGeom::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAVObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiTriBasedGeomData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		skinInstance = DynamicCast<NiSkinInstance>(objects[link_stack.front()]);
		if ( skinInstance == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		skinInstance = NULL;
	link_stack.pop_front();
	if ( version >= 0x0A000100 ) {
		if ( (hasShader != 0) ) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]);
				if ( unknownLink == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				unknownLink = NULL;
			link_stack.pop_front();
		};
	};
}

std::list<NiObjectRef> NiTriBasedGeom::InternalGetRefs() const {
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

void NiTriBasedGeomData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiTriBasedGeomData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
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

std::string NiTriBasedGeomData::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiObject::asString();
	numUvSets = ushort(uvSets.size());
	numUvSets2 = byte(uvSets.size());
	numVertices = ushort(vertices.size());
	out << "  Name:  " << name << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Unknown Short 1:  " << unknownShort1 << endl;
	out << "  Has Vertices:  " << hasVertices << endl;
	if ( (hasVertices != 0) ) {
		for (uint i2 = 0; i2 < vertices.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Vertices[" << i2 << "]:  " << vertices[i2] << endl;
		};
	};
	out << "  Num UV Sets 2:  " << numUvSets2 << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Has Normals:  " << hasNormals << endl;
	if ( (hasNormals != 0) ) {
		for (uint i2 = 0; i2 < normals.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Normals[" << i2 << "]:  " << normals[i2] << endl;
		};
	};
	if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) {
		for (uint i2 = 0; i2 < unknownVectors1.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Vectors 1[" << i2 << "]:  " << unknownVectors1[i2] << endl;
		};
		for (uint i2 = 0; i2 < unknownVectors2.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Vectors 2[" << i2 << "]:  " << unknownVectors2[i2] << endl;
		};
	};
	out << "  Center:  " << center << endl;
	out << "  Radius:  " << radius << endl;
	out << "  Has Vertex Colors:  " << hasVertexColors << endl;
	if ( (hasVertexColors != 0) ) {
		for (uint i2 = 0; i2 < vertexColors.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Vertex Colors[" << i2 << "]:  " << vertexColors[i2] << endl;
		};
	};
	out << "  Num UV Sets:  " << numUvSets << endl;
	out << "  Has UV:  " << hasUv << endl;
	for (uint i1 = 0; i1 < uvSets.size(); i1++) {
		for (uint i2 = 0; i2 < uvSets[i1].size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      UV Sets[" << i1 << "][" << i2 << "]:  " << uvSets[i1][i2] << endl;
		};
	};
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiTriBasedGeomData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x14000004 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]);
			if ( unknownLink == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			unknownLink = NULL;
		link_stack.pop_front();
	};
}

std::list<NiObjectRef> NiTriBasedGeomData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void APSysData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::Read( in, link_stack, version, user_version );
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
	NifStream( unknownByte1, in, version );
}

void APSysData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTriBasedGeomData::Write( out, link_map, version, user_version );
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
	NifStream( unknownByte1, out, version );
}

std::string APSysData::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiTriBasedGeomData::asString();
	out << "  Has Unknown Floats 1:  " << hasUnknownFloats1 << endl;
	if ( (hasUnknownFloats1 != 0) ) {
		for (uint i2 = 0; i2 < unknownFloats1.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 1[" << i2 << "]:  " << unknownFloats1[i2] << endl;
		};
	};
	out << "  Unknown Short 3:  " << unknownShort3 << endl;
	out << "  Has Unknown Floats 2:  " << hasUnknownFloats2 << endl;
	if ( (hasUnknownFloats2 != 0) ) {
		for (uint i2 = 0; i2 < unknownFloats2.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 2[" << i2 << "]:  " << unknownFloats2[i2] << endl;
		};
	};
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	return out.str();
}

void APSysData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> APSysData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeomData::GetRefs();
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
	out << NiCollisionObject::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	return out.str();
}

void bhkBlendCollisionObject::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void bhkBlendController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void bhkBoxShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void bhkCapsuleShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiCollisionObject::asString();
	return out.str();
}

void bhkCollisionObject::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkSphereRepShape::asString();
	num2 = uint(unknownVectors2.size());
	num1 = uint(unknownVectors1.size());
	for (uint i1 = 0; i1 < 7; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats 1[" << i1 << "]:  " << unknownFloats1[i1] << endl;
	};
	out << "  Num 1:  " << num1 << endl;
	for (uint i1 = 0; i1 < unknownVectors1.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Vectors 1[" << i1 << "]:  " << unknownVectors1[i1] << endl;
	};
	out << "  Num 2:  " << num2 << endl;
	for (uint i1 = 0; i1 < unknownVectors2.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Vectors 2[" << i1 << "]:  " << unknownVectors2[i1] << endl;
	};
	return out.str();
}

void bhkConvexVerticesShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << AbhkConstraint::asString();
	for (uint i1 = 0; i1 < 5; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats[" << i1 << "][" << i2 << "]:  " << unknownFloats[i1][i2] << endl;
		};
	};
	return out.str();
}

void bhkHingeConstraint::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	NifStream( limitedHinge.axleA_, in, version );
	NifStream( limitedHinge.perp2axleina1, in, version );
	NifStream( limitedHinge.perp2axleina2, in, version );
	NifStream( limitedHinge.pivotB, in, version );
	NifStream( limitedHinge.axleB, in, version );
	NifStream( limitedHinge.unknownVector, in, version );
	NifStream( limitedHinge.minAngle, in, version );
	NifStream( limitedHinge.maxAngle, in, version );
	NifStream( limitedHinge.maxFriction, in, version );
}

void bhkLimitedHingeConstraint::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AbhkConstraint::Write( out, link_map, version, user_version );
	NifStream( limitedHinge.pivotA, out, version );
	NifStream( limitedHinge.axleA_, out, version );
	NifStream( limitedHinge.perp2axleina1, out, version );
	NifStream( limitedHinge.perp2axleina2, out, version );
	NifStream( limitedHinge.pivotB, out, version );
	NifStream( limitedHinge.axleB, out, version );
	NifStream( limitedHinge.unknownVector, out, version );
	NifStream( limitedHinge.minAngle, out, version );
	NifStream( limitedHinge.maxAngle, out, version );
	NifStream( limitedHinge.maxFriction, out, version );
}

std::string bhkLimitedHingeConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
	out << AbhkConstraint::asString();
	out << "  Pivot A:  " << limitedHinge.pivotA << endl;
	out << "  Axle A ?:  " << limitedHinge.axleA_ << endl;
	out << "  Perp2AxleInA1:  " << limitedHinge.perp2axleina1 << endl;
	out << "  Perp2AxleInA2:  " << limitedHinge.perp2axleina2 << endl;
	out << "  Pivot B:  " << limitedHinge.pivotB << endl;
	out << "  Axle B:  " << limitedHinge.axleB << endl;
	out << "  Unknown Vector:  " << limitedHinge.unknownVector << endl;
	out << "  Min Angle:  " << limitedHinge.minAngle << endl;
	out << "  Max Angle:  " << limitedHinge.maxAngle << endl;
	out << "  Max Friction:  " << limitedHinge.maxFriction << endl;
	return out.str();
}

void bhkLimitedHingeConstraint::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << AbhkShapeCollection::asString();
	numUnknownInts = uint(unknownInts.size());
	numSubShapes = uint(subShapes.size());
	out << "  Num Sub Shapes:  " << numSubShapes << endl;
	for (uint i1 = 0; i1 < subShapes.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Sub Shapes[" << i1 << "]:  " << subShapes[i1] << endl;
	};
	out << "  Material:  " << material << endl;
	for (uint i1 = 0; i1 < 6; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
	};
	out << "  Num Unknown Ints:  " << numUnknownInts << endl;
	for (uint i1 = 0; i1 < unknownInts.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Ints[" << i1 << "]:  " << unknownInts[i1] << endl;
	};
	return out.str();
}

void bhkListShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkShapeCollection::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < subShapes.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			subShapes[i1] = DynamicCast<bhkShape>(objects[link_stack.front()]);
			if ( subShapes[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			subShapes[i1] = NULL;
		link_stack.pop_front();
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
		NifStream( limitedHinge.axleA_, in, version );
		NifStream( limitedHinge.perp2axleina1, in, version );
		NifStream( limitedHinge.perp2axleina2, in, version );
		NifStream( limitedHinge.pivotB, in, version );
		NifStream( limitedHinge.axleB, in, version );
		NifStream( limitedHinge.unknownVector, in, version );
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
		NifStream( limitedHinge.axleA_, out, version );
		NifStream( limitedHinge.perp2axleina1, out, version );
		NifStream( limitedHinge.perp2axleina2, out, version );
		NifStream( limitedHinge.pivotB, out, version );
		NifStream( limitedHinge.axleB, out, version );
		NifStream( limitedHinge.unknownVector, out, version );
		NifStream( limitedHinge.minAngle, out, version );
		NifStream( limitedHinge.maxAngle, out, version );
		NifStream( limitedHinge.maxFriction, out, version );
	};
	NifStream( tau, out, version );
	NifStream( damping, out, version );
}

std::string bhkMalleableConstraint::InternalAsString( bool verbose ) const {
	stringstream out;
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
		out << "    Axle A ?:  " << limitedHinge.axleA_ << endl;
		out << "    Perp2AxleInA1:  " << limitedHinge.perp2axleina1 << endl;
		out << "    Perp2AxleInA2:  " << limitedHinge.perp2axleina2 << endl;
		out << "    Pivot B:  " << limitedHinge.pivotB << endl;
		out << "    Axle B:  " << limitedHinge.axleB << endl;
		out << "    Unknown Vector:  " << limitedHinge.unknownVector << endl;
		out << "    Min Angle:  " << limitedHinge.minAngle << endl;
		out << "    Max Angle:  " << limitedHinge.maxAngle << endl;
		out << "    Max Friction:  " << limitedHinge.maxFriction << endl;
	};
	out << "  Tau:  " << tau << endl;
	out << "  Damping:  " << damping << endl;
	return out.str();
}

void bhkMalleableConstraint::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkConstraint::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink1 = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( unknownLink1 == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink1 = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink2 = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( unknownLink2 == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink2 = NULL;
	link_stack.pop_front();
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
	out << bhkShape::asString();
	numUnknownBytes2 = uint(unknownBytes2.size());
	out << "  Shape:  " << shape << endl;
	out << "  Material:  " << material << endl;
	for (uint i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Bytes 1[" << i1 << "]:  " << unknownBytes1[i1] << endl;
	};
	out << "  Unknown Float:  " << unknownFloat << endl;
	out << "  Num Unknown Bytes 2:  " << numUnknownBytes2 << endl;
	for (uint i1 = 0; i1 < unknownBytes2.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Bytes 2[" << i1 << "]:  " << unknownBytes2[i1] << endl;
	};
	out << "  Unknown Vector:  " << unknownVector << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	return out.str();
}

void bhkMoppBvTreeShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkShape::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		shape = DynamicCast<bhkShape>(objects[link_stack.front()]);
		if ( shape == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		shape = NULL;
	link_stack.pop_front();
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
	NifStream( unknownInt2, in, version );
	for (uint i1 = 0; i1 < 8; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
}

void bhkMultiSphereShape::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	bhkSphereRepShape::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownFloat2, out, version );
	NifStream( unknownFloat3, out, version );
	NifStream( unknownInt2, out, version );
	for (uint i1 = 0; i1 < 8; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
}

std::string bhkMultiSphereShape::InternalAsString( bool verbose ) const {
	stringstream out;
	out << bhkSphereRepShape::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	for (uint i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
	};
	return out.str();
}

void bhkMultiSphereShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkSphereRepShape::asString();
	numUnknownInts2 = uint(unknownInts2.size());
	numStripsData = uint(stripsData.size());
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	for (uint i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Ints 1[" << i1 << "]:  " << unknownInts1[i1] << endl;
	};
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Num Strips Data:  " << numStripsData << endl;
	for (uint i1 = 0; i1 < stripsData.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Strips Data[" << i1 << "]:  " << stripsData[i1] << endl;
	};
	out << "  Num Unknown Ints 2:  " << numUnknownInts2 << endl;
	for (uint i1 = 0; i1 < unknownInts2.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Ints 2[" << i1 << "]:  " << unknownInts2[i1] << endl;
	};
	return out.str();
}

void bhkNiTriStripsShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < stripsData.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			stripsData[i1] = DynamicCast<NiTriStripsData>(objects[link_stack.front()]);
			if ( stripsData[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			stripsData[i1] = NULL;
		link_stack.pop_front();
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
	out << AbhkShapeCollection::asString();
	numSubparts = ushort(subparts.size());
	out << "  Num Subparts:  " << numSubparts << endl;
	for (uint i1 = 0; i1 < subparts.size(); i1++) {
		for (uint i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Subparts[" << i1 << "][" << i2 << "]:  " << subparts[i1][i2] << endl;
		};
	};
	for (uint i1 = 0; i1 < 9; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
	};
	out << "  Scale:  " << scale << endl;
	for (uint i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats 2[" << i1 << "]:  " << unknownFloats2[i1] << endl;
	};
	out << "  Data:  " << data << endl;
	return out.str();
}

void bhkPackedNiTriStripsShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AbhkShapeCollection::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<hkPackedNiTriStripsData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << AbhkConstraint::asString();
	for (uint i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Vectors[" << i1 << "]:  " << unknownVectors[i1] << endl;
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats 2[" << i1 << "]:  " << unknownFloats2[i1] << endl;
	};
	return out.str();
}

void bhkPrismaticConstraint::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << AbhkRagdollConstraint::asString();
	return out.str();
}

void bhkRagdollConstraint::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
		NifStream( unknownFloats1[i1], in, version );
	};
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknownShorts1[i1], in, version );
	};
	NifStream( layerCopy_, in, version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownShorts2[i1], in, version );
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
		NifStream( transform_[i1], in, version );
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
	NifStream( penDepth, in, version );
	NifStream( motionSystem_, in, version );
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
		NifStream( unknownFloats1[i1], out, version );
	};
	for (uint i1 = 0; i1 < 4; i1++) {
		NifStream( unknownShorts1[i1], out, version );
	};
	NifStream( layerCopy_, out, version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownShorts2[i1], out, version );
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
		NifStream( transform_[i1], out, version );
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
	NifStream( penDepth, out, version );
	NifStream( motionSystem_, out, version );
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
	out << bhkEntity::asString();
	numConstraints = uint(constraints.size());
	for (uint i1 = 0; i1 < 5; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats 1[" << i1 << "]:  " << unknownFloats1[i1] << endl;
	};
	for (uint i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Shorts 1[" << i1 << "]:  " << unknownShorts1[i1] << endl;
	};
	out << "  Layer Copy?:  " << layerCopy_ << endl;
	for (uint i1 = 0; i1 < 6; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Shorts 2[" << i1 << "]:  " << unknownShorts2[i1] << endl;
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
	for (uint i1 = 0; i1 < 12; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Transform?[" << i1 << "]:  " << transform_[i1] << endl;
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
	out << "  Pen Depth:  " << penDepth << endl;
	out << "  Motion System?:  " << motionSystem_ << endl;
	out << "  Unknown Byte 1:  " << unknownByte1 << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Quality Type:  " << qualityType << endl;
	out << "  Unknown Int 6:  " << unknownInt6 << endl;
	out << "  Unknown Int 7:  " << unknownInt7 << endl;
	out << "  Unknown Int 8:  " << unknownInt8 << endl;
	out << "  Num Constraints:  " << numConstraints << endl;
	for (uint i1 = 0; i1 < constraints.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Constraints[" << i1 << "]:  " << constraints[i1] << endl;
	};
	return out.str();
}

void bhkRigidBody::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkEntity::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < constraints.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			constraints[i1] = DynamicCast<AbhkConstraint>(objects[link_stack.front()]);
			if ( constraints[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			constraints[i1] = NULL;
		link_stack.pop_front();
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
	out << bhkRigidBody::asString();
	return out.str();
}

void bhkRigidBodyT::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkEntity::asString();
	for (uint i1 = 0; i1 < 7; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unkown Floats[" << i1 << "]:  " << unkownFloats[i1] << endl;
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		for (uint i2 = 0; i2 < 5; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 2[" << i1 << "][" << i2 << "]:  " << unknownFloats2[i1][i2] << endl;
		};
	};
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void bhkSimpleShapePhantom::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiCollisionObject::asString();
	return out.str();
}

void bhkSPCollisionObject::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkConvexShape::asString();
	out << "  Radius:  " << radius << endl;
	return out.str();
}

void bhkSphereShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << AbhkConstraint::asString();
	for (uint i1 = 0; i1 < 2; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats[" << i1 << "][" << i2 << "]:  " << unknownFloats[i1][i2] << endl;
		};
	};
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void bhkStiffSpringConstraint::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkEntity::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Transform:  " << transform << endl;
	return out.str();
}

void bhkTransformShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << bhkTransformShape::asString();
	return out.str();
}

void bhkConvexTransformShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	bhkTransformShape::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> bhkConvexTransformShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkTransformShape::GetRefs();
	return refs;
}

void BSBound::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiExtraData::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
}

void BSBound::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiExtraData::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
}

std::string BSBound::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiExtraData::asString();
	for (uint i1 = 0; i1 < 6; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
	};
	return out.str();
}

void BSBound::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	numPositions = uint(positions.size());
	out << "  Num Positions:  " << numPositions << endl;
	for (uint i1 = 0; i1 < positions.size(); i1++) {
		out << "    Offset:  " << positions[i1].offset << endl;
		out << "    Orientation:  " << positions[i1].orientation << endl;
		out << "    Position Ref 1:  " << positions[i1].positionRef1 << endl;
		out << "    Position Ref 2:  " << positions[i1].positionRef2 << endl;
	};
	return out.str();
}

void BSFurnitureMarker::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPSysModifier::asString();
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void BSParentVelocityModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPSysVolumeEmitter::asString();
	return out.str();
}

void BSPSysArrayEmitter::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void BSXFlags::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << AbhkShapeCollection::asString();
	numVertices = uint(vertices.size());
	numTriangles = uint(triangles.size());
	out << "  Num Triangles:  " << numTriangles << endl;
	for (uint i1 = 0; i1 < triangles.size(); i1++) {
		out << "    Triangle:  " << triangles[i1].triangle << endl;
		out << "    Unknown Short:  " << triangles[i1].unknownShort << endl;
		out << "    Normal:  " << triangles[i1].normal << endl;
	};
	out << "  Num Vertices:  " << numVertices << endl;
	for (uint i1 = 0; i1 < vertices.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Vertices[" << i1 << "]:  " << vertices[i1] << endl;
	};
	return out.str();
}

void hkPackedNiTriStripsData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiSingleInterpolatorController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiAlphaController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			data = DynamicCast<NiFloatData>(objects[link_stack.front()]);
			if ( data == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			data = NULL;
		link_stack.pop_front();
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
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Threshold:  " << threshold << endl;
	return out.str();
}

void NiAlphaProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiLight::asString();
	return out.str();
}

void NiAmbientLight::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiLight::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiAmbientLight::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiLight::GetRefs();
	return refs;
}

void NiAutoNormalParticlesData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::Read( in, link_stack, version, user_version );
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
	NiTriBasedGeomData::Write( out, link_map, version, user_version );
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
	out << NiTriBasedGeomData::asString();
	out << "  Num Particles:  " << numParticles << endl;
	out << "  Size:  " << size << endl;
	out << "  Num Active:  " << numActive << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Has Sizes:  " << hasSizes << endl;
	if ( (hasSizes != 0) ) {
		for (uint i2 = 0; i2 < sizes.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Sizes[" << i2 << "]:  " << sizes[i2] << endl;
		};
	};
	return out.str();
}

void NiAutoNormalParticlesData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiAutoNormalParticlesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeomData::GetRefs();
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
	out << NiExtraData::asString();
	binaryData.dataSize = uint(binaryData.data.size());
	out << "  Data Size:  " << binaryData.dataSize << endl;
	for (uint i1 = 0; i1 < binaryData.data.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Data[" << i1 << "]:  " << binaryData.data[i1] << endl;
	};
	return out.str();
}

void NiBinaryExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiBlendInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	return out.str();
}

void NiBlendBoolInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiBlendInterpolator::asString();
	out << "  Float Value:  " << floatValue << endl;
	return out.str();
}

void NiBlendFloatInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiBlendInterpolator::asString();
	out << "  Point Value:  " << pointValue << endl;
	return out.str();
}

void NiBlendPoint3Interpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiBlendInterpolator::asString();
	return out.str();
}

void NiBlendTransformInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << ABoneLODController::asString();
	numShapeGroups2 = uint(shapeGroups2.size());
	numShapeGroups = uint(shapeGroups1.size());
	out << "  Num Shape Groups:  " << numShapeGroups << endl;
	for (uint i1 = 0; i1 < shapeGroups1.size(); i1++) {
		shapeGroups1[i1].numLinkPairs = uint(shapeGroups1[i1].linkPairs.size());
		out << "    Num Link Pairs:  " << shapeGroups1[i1].numLinkPairs << endl;
		for (uint i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			out << "      Shape:  " << shapeGroups1[i1].linkPairs[i2].shape << endl;
			out << "      Skin Instance:  " << shapeGroups1[i1].linkPairs[i2].skinInstance << endl;
		};
	};
	out << "  Num Shape Groups 2:  " << numShapeGroups2 << endl;
	for (uint i1 = 0; i1 < shapeGroups2.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Shape Groups 2[" << i1 << "]:  " << shapeGroups2[i1] << endl;
	};
	return out.str();
}

void NiBoneLODController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	ABoneLODController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < shapeGroups1.size(); i1++) {
		for (uint i2 = 0; i2 < shapeGroups1[i1].linkPairs.size(); i2++) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				shapeGroups1[i1].linkPairs[i2].shape = DynamicCast<NiTriShape>(objects[link_stack.front()]);
				if ( shapeGroups1[i1].linkPairs[i2].shape == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				shapeGroups1[i1].linkPairs[i2].shape = NULL;
			link_stack.pop_front();
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				shapeGroups1[i1].linkPairs[i2].skinInstance = DynamicCast<NiSkinInstance>(objects[link_stack.front()]);
				if ( shapeGroups1[i1].linkPairs[i2].skinInstance == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				shapeGroups1[i1].linkPairs[i2].skinInstance = NULL;
			link_stack.pop_front();
		};
	};
	for (uint i1 = 0; i1 < shapeGroups2.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			shapeGroups2[i1] = DynamicCast<NiTriShape>(objects[link_stack.front()]);
			if ( shapeGroups2[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			shapeGroups2[i1] = NULL;
		link_stack.pop_front();
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
	out << AKeyedData::asString();
	data.numKeys = uint(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Keys[" << i1 << "]:  " << data.keys[i1] << endl;
	};
	return out.str();
}

void NiBoolData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	out << "  Boolean Data:  " << booleanData << endl;
	return out.str();
}

void NiBooleanExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiBoolInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiBoolData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << NiInterpolator::asString();
	out << "  Bool Value:  " << boolValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiBoolTimelineInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiBoolData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << ABoneLODController::asString();
	return out.str();
}

void NiBSBoneLODController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	ABoneLODController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSBoneLODController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = ABoneLODController::GetRefs();
	return refs;
}

void NiBSplineBasisData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( unknownInt, in, version );
}

void NiBSplineBasisData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	NifStream( unknownInt, out, version );
}

std::string NiBSplineBasisData::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiObject::asString();
	out << "  Unknown Int:  " << unknownInt << endl;
	return out.str();
}

void NiBSplineBasisData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSplineBasisData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

void NiBSplineCompFloatInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
}

void NiBSplineCompFloatInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBSplineInterpolator::Write( out, link_map, version, user_version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
}

std::string NiBSplineCompFloatInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiBSplineInterpolator::asString();
	for (uint i1 = 0; i1 < 6; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
	};
	return out.str();
}

void NiBSplineCompFloatInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiBSplineCompFloatInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	return refs;
}

void NiBSplineCompPoint3Interpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiBSplineInterpolator::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
}

void NiBSplineCompPoint3Interpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBSplineInterpolator::Write( out, link_map, version, user_version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( unknownLink != NULL )
		NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	for (uint i1 = 0; i1 < 6; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
}

std::string NiBSplineCompPoint3Interpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiBSplineInterpolator::asString();
	out << "  Data:  " << data << endl;
	out << "  Unknown Link:  " << unknownLink << endl;
	for (uint i1 = 0; i1 < 6; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
	};
	return out.str();
}

void NiBSplineCompPoint3Interpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiBSplineData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( unknownLink == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink = NULL;
	link_stack.pop_front();
}

std::list<NiObjectRef> NiBSplineCompPoint3Interpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	return refs;
}

void NiBSplineCompTransformInterpolator::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NiBSplineInterpolator::Read( in, link_stack, version, user_version );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	NifStream( block_num, in, version );
	link_stack.push_back( block_num );
	for (uint i1 = 0; i1 < 17; i1++) {
		NifStream( unknown4[i1], in, version );
	};
}

void NiBSplineCompTransformInterpolator::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiBSplineInterpolator::Write( out, link_map, version, user_version );
	if ( data != NULL )
		NifStream( link_map[StaticCast<NiObject>(data)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	if ( basisData != NULL )
		NifStream( link_map[StaticCast<NiObject>(basisData)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	for (uint i1 = 0; i1 < 17; i1++) {
		NifStream( unknown4[i1], out, version );
	};
}

std::string NiBSplineCompTransformInterpolator::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiBSplineInterpolator::asString();
	out << "  Data:  " << data << endl;
	out << "  Basis Data:  " << basisData << endl;
	for (uint i1 = 0; i1 < 17; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown4[" << i1 << "]:  " << unknown4[i1] << endl;
	};
	return out.str();
}

void NiBSplineCompTransformInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiBSplineData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		basisData = DynamicCast<NiBSplineBasisData>(objects[link_stack.front()]);
		if ( basisData == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		basisData = NULL;
	link_stack.pop_front();
}

std::list<NiObjectRef> NiBSplineCompTransformInterpolator::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBSplineInterpolator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	if ( basisData != NULL )
		refs.push_back(StaticCast<NiObject>(basisData));
	return refs;
}

void NiBSplineData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( unknownInt, in, version );
	NifStream( count, in, version );
	unknownData.resize(count);
	for (uint i1 = 0; i1 < unknownData.size(); i1++) {
		for (uint i2 = 0; i2 < 2; i2++) {
			NifStream( unknownData[i1][i2], in, version );
		};
	};
}

void NiBSplineData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	count = uint(unknownData.size());
	NifStream( unknownInt, out, version );
	NifStream( count, out, version );
	for (uint i1 = 0; i1 < unknownData.size(); i1++) {
		for (uint i2 = 0; i2 < 2; i2++) {
			NifStream( unknownData[i1][i2], out, version );
		};
	};
}

std::string NiBSplineData::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiObject::asString();
	count = uint(unknownData.size());
	out << "  Unknown Int:  " << unknownInt << endl;
	out << "  Count:  " << count << endl;
	for (uint i1 = 0; i1 < unknownData.size(); i1++) {
		for (uint i2 = 0; i2 < 2; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Data[" << i1 << "][" << i2 << "]:  " << unknownData[i1][i2] << endl;
		};
	};
	return out.str();
}

void NiBSplineData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiCamera::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAVObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink_ = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( unknownLink_ == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink_ = NULL;
	link_stack.pop_front();
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
	NifStream( unknown2, in, version );
	NifStream( unknown3, in, version );
	NifStream( collisionType, in, version );
	if ( (collisionType == 0) ) {
		NifStream( unknown5, in, version );
		NifStream( unknown7, in, version );
	};
	if ( (collisionType == 2) ) {
		for (uint i2 = 0; i2 < 8; i2++) {
			NifStream( unknown6[i2], in, version );
		};
	};
	if ( (collisionType == 1) ) {
		for (uint i2 = 0; i2 < 15; i2++) {
			NifStream( unknown8[i2], in, version );
		};
	};
}

void NiCollisionData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	if ( targetNode != NULL )
		NifStream( link_map[StaticCast<NiObject>(targetNode)], out, version );
	else
		NifStream( 0xffffffff, out, version );
	NifStream( unknown2, out, version );
	NifStream( unknown3, out, version );
	NifStream( collisionType, out, version );
	if ( (collisionType == 0) ) {
		NifStream( unknown5, out, version );
		NifStream( unknown7, out, version );
	};
	if ( (collisionType == 2) ) {
		for (uint i2 = 0; i2 < 8; i2++) {
			NifStream( unknown6[i2], out, version );
		};
	};
	if ( (collisionType == 1) ) {
		for (uint i2 = 0; i2 < 15; i2++) {
			NifStream( unknown8[i2], out, version );
		};
	};
}

std::string NiCollisionData::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiObject::asString();
	out << "  Target Node:  " << targetNode << endl;
	out << "  Unknown2:  " << unknown2 << endl;
	out << "  Unknown3:  " << unknown3 << endl;
	out << "  Collision Type:  " << collisionType << endl;
	if ( (collisionType == 0) ) {
		out << "    Unknown5:  " << unknown5 << endl;
		out << "    Unknown7:  " << unknown7 << endl;
	};
	if ( (collisionType == 2) ) {
		for (uint i2 = 0; i2 < 8; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown6[" << i2 << "]:  " << unknown6[i2] << endl;
		};
	};
	if ( (collisionType == 1) ) {
		for (uint i2 = 0; i2 < 15; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown8[" << i2 << "]:  " << unknown8[i2] << endl;
		};
	};
	return out.str();
}

void NiCollisionData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		targetNode = DynamicCast<NiNode>(objects[link_stack.front()]);
		if ( targetNode == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		targetNode = NULL;
	link_stack.pop_front();
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
	out << AKeyedData::asString();
	data.numKeys = uint(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Keys[" << i1 << "]:  " << data.keys[i1] << endl;
	};
	return out.str();
}

void NiColorData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiColorExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	numControllerSequences = uint(controllerSequences.size());
	out << "  Cumulative:  " << cumulative << endl;
	out << "  Num Controller Sequences:  " << numControllerSequences << endl;
	for (uint i1 = 0; i1 < controllerSequences.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Controller Sequences[" << i1 << "]:  " << controllerSequences[i1] << endl;
	};
	out << "  Object Palette:  " << objectPalette << endl;
	return out.str();
}

void NiControllerManager::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < controllerSequences.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			controllerSequences[i1] = DynamicCast<NiControllerSequence>(objects[link_stack.front()]);
			if ( controllerSequences[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			controllerSequences[i1] = NULL;
		link_stack.pop_front();
	};
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		objectPalette = DynamicCast<NiDefaultAVObjectPalette>(objects[link_stack.front()]);
		if ( objectPalette == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		objectPalette = NULL;
	link_stack.pop_front();
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
		};
		if ( version <= 0x0A01006A ) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
		if ( version >= 0x0A020000 ) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
		};
		if ( version >= 0x0A01006A ) {
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
		NifStream( unknownString, in, version );
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
		};
		if ( version <= 0x0A01006A ) {
			if ( controlledBlocks[i1].controller != NULL )
				NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i1].controller)], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
		if ( version >= 0x0A020000 ) {
			if ( controlledBlocks[i1].interpolator != NULL )
				NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i1].interpolator)], out, version );
			else
				NifStream( 0xffffffff, out, version );
		};
		if ( version >= 0x0A01006A ) {
			if ( controlledBlocks[i1].unknownLink1 != NULL )
				NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i1].unknownLink1)], out, version );
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
		NifStream( unknownString, out, version );
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
	out << NiObject::asString();
	numControlledBlocks = uint(controlledBlocks.size());
	out << "  Name:  " << name << endl;
	out << "  Text Keys Name:  " << textKeysName << endl;
	out << "  Text Keys:  " << textKeys << endl;
	out << "  Num Controlled Blocks:  " << numControlledBlocks << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	for (uint i1 = 0; i1 < controlledBlocks.size(); i1++) {
		out << "    Target Name:  " << controlledBlocks[i1].targetName << endl;
		out << "    Controller:  " << controlledBlocks[i1].controller << endl;
		out << "    Interpolator:  " << controlledBlocks[i1].interpolator << endl;
		out << "    Unknown Link 1:  " << controlledBlocks[i1].unknownLink1 << endl;
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
	out << "  Unknown String:  " << unknownString << endl;
	out << "  String Palette:  " << stringPalette << endl;
	return out.str();
}

void NiControllerSequence::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			textKeys = DynamicCast<NiTextKeyExtraData>(objects[link_stack.front()]);
			if ( textKeys == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			textKeys = NULL;
		link_stack.pop_front();
	};
	for (uint i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( version <= 0x0A01006A ) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				controlledBlocks[i1].controller = DynamicCast<NiTimeController>(objects[link_stack.front()]);
				if ( controlledBlocks[i1].controller == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				controlledBlocks[i1].controller = NULL;
			link_stack.pop_front();
		};
		if ( version >= 0x0A020000 ) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				controlledBlocks[i1].interpolator = DynamicCast<NiInterpolator>(objects[link_stack.front()]);
				if ( controlledBlocks[i1].interpolator == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				controlledBlocks[i1].interpolator = NULL;
			link_stack.pop_front();
		};
		if ( version >= 0x0A01006A ) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				controlledBlocks[i1].unknownLink1 = DynamicCast<NiObject>(objects[link_stack.front()]);
				if ( controlledBlocks[i1].unknownLink1 == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				controlledBlocks[i1].unknownLink1 = NULL;
			link_stack.pop_front();
		};
		if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				controlledBlocks[i1].unknownLink2 = DynamicCast<NiObject>(objects[link_stack.front()]);
				if ( controlledBlocks[i1].unknownLink2 == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				controlledBlocks[i1].unknownLink2 = NULL;
			link_stack.pop_front();
		};
		if ( version >= 0x0A020000 ) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				controlledBlocks[i1].stringPalette = DynamicCast<NiStringPalette>(objects[link_stack.front()]);
				if ( controlledBlocks[i1].stringPalette == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				controlledBlocks[i1].stringPalette = NULL;
			link_stack.pop_front();
		};
	};
	if ( version >= 0x0A01006A ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			textKeys = DynamicCast<NiTextKeyExtraData>(objects[link_stack.front()]);
			if ( textKeys == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			textKeys = NULL;
		link_stack.pop_front();
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			manager = DynamicCast<NiControllerManager>(objects[link_stack.front()]);
			if ( manager == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			manager = NULL;
		link_stack.pop_front();
	};
	if ( version >= 0x0A020000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			stringPalette = DynamicCast<NiStringPalette>(objects[link_stack.front()]);
			if ( stringPalette == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			stringPalette = NULL;
		link_stack.pop_front();
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
		if ( controlledBlocks[i1].unknownLink1 != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].unknownLink1));
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
		if ( objs[i1].object != NULL )
			NifStream( link_map[StaticCast<NiObject>(objs[i1].object)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiDefaultAVObjectPalette::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiObject::asString();
	numObjs = uint(objs.size());
	out << "  Unknown Int:  " << unknownInt << endl;
	out << "  Num Objs:  " << numObjs << endl;
	for (uint i1 = 0; i1 < objs.size(); i1++) {
		out << "    Name:  " << objs[i1].name << endl;
		out << "    Object:  " << objs[i1].object << endl;
	};
	return out.str();
}

void NiDefaultAVObjectPalette::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < objs.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			objs[i1].object = DynamicCast<NiAVObject>(objects[link_stack.front()]);
			if ( objs[i1].object == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			objs[i1].object = NULL;
		link_stack.pop_front();
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
	out << NiLight::asString();
	return out.str();
}

void NiDirectionalLight::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiDitherProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiSingleInterpolatorController::asString();
	numSources = uint(sources.size());
	out << "  Texture Slot:  " << textureSlot << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Delta:  " << delta << endl;
	out << "  Num Sources:  " << numSources << endl;
	for (uint i1 = 0; i1 < sources.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Sources[" << i1 << "]:  " << sources[i1] << endl;
	};
	return out.str();
}

void NiFlipController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < sources.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			sources[i1] = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
			if ( sources[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			sources[i1] = NULL;
		link_stack.pop_front();
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
	out << AKeyedData::asString();
	data.numKeys = uint(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Keys[" << i1 << "]:  " << data.keys[i1] << endl;
	};
	return out.str();
}

void NiFloatData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	out << "  Float Data:  " << floatData << endl;
	return out.str();
}

void NiFloatExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	out << "  Unknown String:  " << unknownString << endl;
	return out.str();
}

void NiFloatExtraDataController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x14000004 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]);
			if ( unknownLink == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			unknownLink = NULL;
		link_stack.pop_front();
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
	out << NiInterpolator::asString();
	out << "  Float Value:  " << floatValue << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiFloatInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiFloatData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << NiExtraData::asString();
	numFloats = uint(data.size());
	out << "  Num Floats:  " << numFloats << endl;
	for (uint i1 = 0; i1 < data.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Data[" << i1 << "]:  " << data[i1] << endl;
	};
	return out.str();
}

void NiFloatsExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Fog Depth:  " << fogDepth << endl;
	out << "  Fog Color:  " << fogColor << endl;
	return out.str();
}

void NiFogProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	numUnknownInts = uint(unknownInts.size());
	numInterpolators = uint(interpolators.size());
	out << "  Unknown:  " << unknown << endl;
	out << "  Unknown 2:  " << unknown2 << endl;
	out << "  Data:  " << data << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Num Interpolators:  " << numInterpolators << endl;
	for (uint i1 = 0; i1 < interpolators.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Interpolators[" << i1 << "]:  " << interpolators[i1] << endl;
	};
	out << "  Num Unknown Ints:  " << numUnknownInts << endl;
	for (uint i1 = 0; i1 < unknownInts.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Ints[" << i1 << "]:  " << unknownInts[i1] << endl;
	};
	return out.str();
}

void NiGeomMorpherController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiMorphData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
	if ( version >= 0x0A01006A ) {
		for (uint i2 = 0; i2 < interpolators.size(); i2++) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				interpolators[i2] = DynamicCast<NiInterpolator>(objects[link_stack.front()]);
				if ( interpolators[i2] == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				interpolators[i2] = NULL;
			link_stack.pop_front();
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
	out << AParticleModifier::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Force:  " << force << endl;
	out << "  Type:  " << type << endl;
	out << "  Position:  " << position << endl;
	out << "  Direction:  " << direction << endl;
	return out.str();
}

void NiGravity::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	out << "  Integer Data:  " << integerData << endl;
	return out.str();
}

void NiIntegerExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	numIntegers = uint(data.size());
	out << "  Num Integers:  " << numIntegers << endl;
	for (uint i1 = 0; i1 < data.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Data[" << i1 << "]:  " << data[i1] << endl;
	};
	return out.str();
}

void NiIntegersExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiKeyframeController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiKeyframeData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << NiKeyframeController::asString();
	out << "  Data 2:  " << data2 << endl;
	return out.str();
}

void BSKeyframeController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiKeyframeController::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data2 = DynamicCast<NiKeyframeData>(objects[link_stack.front()]);
		if ( data2 == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data2 = NULL;
	link_stack.pop_front();
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
	out << AKeyedData::asString();
	out << "  Num Rotation Keys:  " << numRotationKeys << endl;
	if ( (numRotationKeys != 0) ) {
		out << "    Rotation Type:  " << rotationType << endl;
	};
	if ( (rotationType != 4) ) {
		for (uint i2 = 0; i2 < quaternionKeys.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Quaternion Keys[" << i2 << "]:  " << quaternionKeys[i2] << endl;
		};
	};
	if ( (rotationType == 4) ) {
		out << "    Unknown Float:  " << unknownFloat << endl;
		for (uint i2 = 0; i2 < 3; i2++) {
			xyzRotations[i2].numKeys = uint(xyzRotations[i2].keys.size());
			out << "      Num Keys:  " << xyzRotations[i2].numKeys << endl;
			if ( (xyzRotations[i2].numKeys != 0) ) {
				out << "        Interpolation:  " << xyzRotations[i2].interpolation << endl;
			};
			for (uint i3 = 0; i3 < xyzRotations[i2].keys.size(); i3++) {
				if ( !verbose && ( i3 > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				out << "        Keys[" << i3 << "]:  " << xyzRotations[i2].keys[i3] << endl;
			};
		};
	};
	translations.numKeys = uint(translations.keys.size());
	out << "  Num Keys:  " << translations.numKeys << endl;
	if ( (translations.numKeys != 0) ) {
		out << "    Interpolation:  " << translations.interpolation << endl;
	};
	for (uint i1 = 0; i1 < translations.keys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Keys[" << i1 << "]:  " << translations.keys[i1] << endl;
	};
	scales.numKeys = uint(scales.keys.size());
	out << "  Num Keys:  " << scales.numKeys << endl;
	if ( (scales.numKeys != 0) ) {
		out << "    Interpolation:  " << scales.interpolation << endl;
	};
	for (uint i1 = 0; i1 < scales.keys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Keys[" << i1 << "]:  " << scales.keys[i1] << endl;
	};
	return out.str();
}

void NiKeyframeData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Data:  " << data << endl;
	out << "  Interpolator:  " << interpolator << endl;
	return out.str();
}

void NiLightColorController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			data = DynamicCast<NiPosData>(objects[link_stack.front()]);
			if ( data == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			data = NULL;
		link_stack.pop_front();
	};
	if ( version >= 0x0A020000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			interpolator = DynamicCast<NiPoint3Interpolator>(objects[link_stack.front()]);
			if ( interpolator == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			interpolator = NULL;
		link_stack.pop_front();
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
	out << NiTimeController::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	return out.str();
}

void NiLightDimmerController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink = DynamicCast<NiInterpolator>(objects[link_stack.front()]);
		if ( unknownLink == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink = NULL;
	link_stack.pop_front();
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
	out << NiTimeController::asString();
	out << "  Unknown1:  " << unknown1 << endl;
	out << "  Look At Node:  " << lookAtNode << endl;
	return out.str();
}

void NiLookAtController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		lookAtNode = DynamicCast<NiNode>(objects[link_stack.front()]);
		if ( lookAtNode == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		lookAtNode = NULL;
	link_stack.pop_front();
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

void NiLookAtInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		lookAt = DynamicCast<NiNode>(objects[link_stack.front()]);
		if ( lookAt == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		lookAt = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink1 = DynamicCast<NiPoint3Interpolator>(objects[link_stack.front()]);
		if ( unknownLink1 == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink1 = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink2 = DynamicCast<NiFloatInterpolator>(objects[link_stack.front()]);
		if ( unknownLink2 == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink2 = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink3 = DynamicCast<NiFloatInterpolator>(objects[link_stack.front()]);
		if ( unknownLink3 == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink3 = NULL;
	link_stack.pop_front();
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
		NifStream( unknown, in, version );
	};
	if ( version <= 0x0A010000 ) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiMaterialColorController::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiSingleInterpolatorController::Write( out, link_map, version, user_version );
	if ( version >= 0x0A010000 ) {
		NifStream( unknown, out, version );
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
	out << NiSingleInterpolatorController::asString();
	out << "  Unknown:  " << unknown << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiMaterialColorController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			data = DynamicCast<NiPosData>(objects[link_stack.front()]);
			if ( data == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			data = NULL;
		link_stack.pop_front();
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

void NiMaterialProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
		unknownFloats3.resize(numVertices);
		for (uint i2 = 0; i2 < unknownFloats3.size(); i2++) {
			for (uint i3 = 0; i3 < 4; i3++) {
				NifStream( unknownFloats3[i2][i3], in, version );
			};
		};
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
		for (uint i2 = 0; i2 < unknownFloats3.size(); i2++) {
			for (uint i3 = 0; i3 < 4; i3++) {
				NifStream( unknownFloats3[i2][i3], out, version );
			};
		};
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
	out << APSysData::asString();
	numUnknownLinks = uint(unknownLinks.size());
	out << "  Unknown Byte 11:  " << unknownByte11 << endl;
	for (uint i1 = 0; i1 < unknownFloats3.size(); i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 3[" << i1 << "][" << i2 << "]:  " << unknownFloats3[i1][i2] << endl;
		};
	};
	for (uint i1 = 0; i1 < unknownFloats4.size(); i1++) {
		for (uint i2 = 0; i2 < 10; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 4[" << i1 << "][" << i2 << "]:  " << unknownFloats4[i1][i2] << endl;
		};
	};
	for (uint i1 = 0; i1 < unknownFloats5.size(); i1++) {
		for (uint i2 = 0; i2 < 12; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 5[" << i1 << "][" << i2 << "]:  " << unknownFloats5[i1][i2] << endl;
		};
	};
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Modifier:  " << modifier << endl;
	out << "  Unknown Byte 2:  " << unknownByte2 << endl;
	out << "  Num Unknown Links:  " << numUnknownLinks << endl;
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Links[" << i1 << "]:  " << unknownLinks[i1] << endl;
	};
	out << "  Unknown Short 4:  " << unknownShort4 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	out << "  Unknown Byte 12:  " << unknownByte12 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	return out.str();
}

void NiMeshPSysData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysData::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x14000004 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			modifier = DynamicCast<NiPSysModifier>(objects[link_stack.front()]);
			if ( modifier == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			modifier = NULL;
		link_stack.pop_front();
	};
	if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) {
		for (uint i2 = 0; i2 < unknownLinks.size(); i2++) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				unknownLinks[i2] = DynamicCast<NiPSysModifier>(objects[link_stack.front()]);
				if ( unknownLinks[i2] == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				unknownLinks[i2] = NULL;
			link_stack.pop_front();
		};
	};
	if ( version >= 0x0A020000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			unknownLink2 = DynamicCast<NiNode>(objects[link_stack.front()]);
			if ( unknownLink2 == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			unknownLink2 = NULL;
		link_stack.pop_front();
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
		if ( version <= 0x0A000102 ) {
			NifStream( morphs[i1].numMorphKeys, in, version );
			NifStream( morphs[i1].morphInterpolation, in, version );
			morphs[i1].morphKeys.resize(morphs[i1].numMorphKeys);
			for (uint i3 = 0; i3 < morphs[i1].morphKeys.size(); i3++) {
				NifStream( morphs[i1].morphKeys[i3], in, version, morphs[i1].morphInterpolation );
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
		morphs[i1].numMorphKeys = uint(morphs[i1].morphKeys.size());
		if ( version >= 0x0A01006A ) {
			NifStream( morphs[i1].frameName, out, version );
		};
		if ( version <= 0x0A000102 ) {
			NifStream( morphs[i1].numMorphKeys, out, version );
			NifStream( morphs[i1].morphInterpolation, out, version );
			for (uint i3 = 0; i3 < morphs[i1].morphKeys.size(); i3++) {
				NifStream( morphs[i1].morphKeys[i3], out, version, morphs[i1].morphInterpolation );
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
	out << NiObject::asString();
	numMorphs = uint(morphs.size());
	out << "  Num Morphs:  " << numMorphs << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	for (uint i1 = 0; i1 < morphs.size(); i1++) {
		morphs[i1].numMorphKeys = uint(morphs[i1].morphKeys.size());
		out << "    Frame Name:  " << morphs[i1].frameName << endl;
		out << "    Num Morph Keys:  " << morphs[i1].numMorphKeys << endl;
		out << "    Morph Interpolation:  " << morphs[i1].morphInterpolation << endl;
		for (uint i2 = 0; i2 < morphs[i1].morphKeys.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Morph Keys[" << i2 << "]:  " << morphs[i1].morphKeys[i2] << endl;
		};
		out << "    Unknown Int:  " << morphs[i1].unknownInt << endl;
		for (uint i2 = 0; i2 < morphs[i1].vectors.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Vectors[" << i2 << "]:  " << morphs[i1].vectors[i2] << endl;
		};
	};
	return out.str();
}

void NiMorphData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	numExtraTargets = ushort(extraTargets.size());
	out << "  Num Extra Targets:  " << numExtraTargets << endl;
	for (uint i1 = 0; i1 < extraTargets.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Extra Targets[" << i1 << "]:  " << extraTargets[i1] << endl;
	};
	return out.str();
}

void NiMultiTargetTransformController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < extraTargets.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			extraTargets[i1] = DynamicCast<NiNode>(objects[link_stack.front()]);
			if ( extraTargets[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			extraTargets[i1] = NULL;
		link_stack.pop_front();
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
	out << NiAVObject::asString();
	numEffects = uint(effects.size());
	numChildren = uint(children.size());
	out << "  Num Children:  " << numChildren << endl;
	for (uint i1 = 0; i1 < children.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Children[" << i1 << "]:  " << children[i1] << endl;
	};
	out << "  Num Effects:  " << numEffects << endl;
	for (uint i1 = 0; i1 < effects.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Effects[" << i1 << "]:  " << effects[i1] << endl;
	};
	return out.str();
}

void NiNode::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiAVObject::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < children.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			children[i1] = DynamicCast<NiAVObject>(objects[link_stack.front()]);
			if ( children[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			children[i1] = NULL;
		link_stack.pop_front();
	};
	for (uint i1 = 0; i1 < effects.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			effects[i1] = DynamicCast<NiDynamicEffect>(objects[link_stack.front()]);
			if ( effects[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			effects[i1] = NULL;
		link_stack.pop_front();
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
	out << NiNode::asString();
	return out.str();
}

void AvoidNode::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiNode::asString();
	out << "  Unknown1:  " << unknown1 << endl;
	for (uint i1 = 0; i1 < 292; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown 292 Bytes[" << i1 << "]:  " << unknown292Bytes[i1] << endl;
	};
	return out.str();
}

void FxWidget::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << FxWidget::asString();
	return out.str();
}

void FxButton::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	NifStream( numUnknownLinks, in, version );
	unknownLinks.resize(numUnknownLinks);
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void FxRadioButton::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	FxWidget::Write( out, link_map, version, user_version );
	numUnknownLinks = uint(unknownLinks.size());
	NifStream( unknownInt1, out, version );
	NifStream( unknownInt2, out, version );
	NifStream( unknownInt3, out, version );
	NifStream( numUnknownLinks, out, version );
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( unknownLinks[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(unknownLinks[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string FxRadioButton::InternalAsString( bool verbose ) const {
	stringstream out;
	out << FxWidget::asString();
	numUnknownLinks = uint(unknownLinks.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int  2:  " << unknownInt2 << endl;
	out << "  Unknown Int 3:  " << unknownInt3 << endl;
	out << "  Num Unknown Links:  " << numUnknownLinks << endl;
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Links[" << i1 << "]:  " << unknownLinks[i1] << endl;
	};
	return out.str();
}

void FxRadioButton::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	FxWidget::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			unknownLinks[i1] = DynamicCast<NiObject>(objects[link_stack.front()]);
			if ( unknownLinks[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			unknownLinks[i1] = NULL;
		link_stack.pop_front();
	};
}

std::list<NiObjectRef> FxRadioButton::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = FxWidget::GetRefs();
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) {
		if ( unknownLinks[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(unknownLinks[i1]));
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
	out << NiNode::asString();
	out << "  Billboard Mode:  " << billboardMode << endl;
	return out.str();
}

void NiBillboardNode::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiNode::asString();
	return out.str();
}

void NiBSAnimationNode::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiNode::asString();
	return out.str();
}

void NiBSParticleNode::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	NifStream( lodType, in, version );
	if ( (lodType == 0) ) {
		NifStream( lodCenter, in, version );
		NifStream( numLodLevels, in, version );
		lodLevels.resize(numLodLevels);
		for (uint i2 = 0; i2 < lodLevels.size(); i2++) {
			NifStream( lodLevels[i2].nearExtent, in, version );
			NifStream( lodLevels[i2].farExtent, in, version );
		};
	};
	if ( (lodType == 1) ) {
		NifStream( unknownShort, in, version );
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void NiLODNode::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiNode::Write( out, link_map, version, user_version );
	numLodLevels = uint(lodLevels.size());
	NifStream( lodType, out, version );
	if ( (lodType == 0) ) {
		NifStream( lodCenter, out, version );
		NifStream( numLodLevels, out, version );
		for (uint i2 = 0; i2 < lodLevels.size(); i2++) {
			NifStream( lodLevels[i2].nearExtent, out, version );
			NifStream( lodLevels[i2].farExtent, out, version );
		};
	};
	if ( (lodType == 1) ) {
		NifStream( unknownShort, out, version );
		if ( rangeData != NULL )
			NifStream( link_map[StaticCast<NiObject>(rangeData)], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

std::string NiLODNode::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiNode::asString();
	numLodLevels = uint(lodLevels.size());
	out << "  LOD Type:  " << lodType << endl;
	if ( (lodType == 0) ) {
		out << "    LOD Center:  " << lodCenter << endl;
		out << "    Num LOD Levels:  " << numLodLevels << endl;
		for (uint i2 = 0; i2 < lodLevels.size(); i2++) {
			out << "      Near Extent:  " << lodLevels[i2].nearExtent << endl;
			out << "      Far Extent:  " << lodLevels[i2].farExtent << endl;
		};
	};
	if ( (lodType == 1) ) {
		out << "    Unknown Short:  " << unknownShort << endl;
		out << "    Range Data:  " << rangeData << endl;
	};
	return out.str();
}

void NiLODNode::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
	if ( (lodType == 1) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			rangeData = DynamicCast<NiRangeLODData>(objects[link_stack.front()]);
			if ( rangeData == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			rangeData = NULL;
		link_stack.pop_front();
	};
}

std::list<NiObjectRef> NiLODNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	if ( rangeData != NULL )
		refs.push_back(StaticCast<NiObject>(rangeData));
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
	out << NiObject::asString();
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Num Entries?:  " << numEntries_ << endl;
	for (uint i1 = 0; i1 < 256; i1++) {
		for (uint i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Palette[" << i1 << "][" << i2 << "]:  " << palette[i1][i2] << endl;
		};
	};
	return out.str();
}

void NiPalette::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiParticleBomb::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << AParticleModifier::asString();
	out << "  Color Data:  " << colorData << endl;
	return out.str();
}

void NiParticleColorModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		colorData = DynamicCast<NiColorData>(objects[link_stack.front()]);
		if ( colorData == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		colorData = NULL;
	link_stack.pop_front();
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
	out << AParticleModifier::asString();
	out << "  Grow:  " << grow << endl;
	out << "  Fade:  " << fade << endl;
	return out.str();
}

void NiParticleGrowFade::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << AParticleModifier::asString();
	numParticleMeshes = uint(particleMeshes.size());
	out << "  Num Particle Meshes:  " << numParticleMeshes << endl;
	for (uint i1 = 0; i1 < particleMeshes.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Particle Meshes[" << i1 << "]:  " << particleMeshes[i1] << endl;
	};
	return out.str();
}

void NiParticleMeshModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < particleMeshes.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			particleMeshes[i1] = DynamicCast<NiAVObject>(objects[link_stack.front()]);
			if ( particleMeshes[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			particleMeshes[i1] = NULL;
		link_stack.pop_front();
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
	out << AParticleModifier::asString();
	out << "  Unknown Byte:  " << unknownByte << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	return out.str();
}

void NiParticleRotation::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	AParticleModifier::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiParticleRotation::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = AParticleModifier::GetRefs();
	return refs;
}

void NiParticles::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::Read( in, link_stack, version, user_version );
}

void NiParticles::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiTriBasedGeom::Write( out, link_map, version, user_version );
}

std::string NiParticles::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiParticles::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiParticles::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
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
	out << NiParticles::asString();
	return out.str();
}

void NiAutoNormalParticles::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiParticles::asString();
	return out.str();
}

void NiParticleMeshes::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiAutoNormalParticlesData::asString();
	out << "  Num Active:  " << numActive << endl;
	out << "  Has Unknown Floats:  " << hasUnknownFloats << endl;
	if ( (hasUnknownFloats != 0) ) {
		for (uint i2 = 0; i2 < unknownFloats.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats[" << i2 << "]:  " << unknownFloats[i2] << endl;
		};
	};
	out << "  Has Rotations:  " << hasRotations << endl;
	if ( (hasRotations != 0) ) {
		for (uint i2 = 0; i2 < rotations.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Rotations[" << i2 << "]:  " << rotations[i2] << endl;
		};
	};
	return out.str();
}

void NiParticlesData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiParticlesData::asString();
	out << "  Unknown Link 2:  " << unknownLink2 << endl;
	return out.str();
}

void NiParticleMeshesData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticlesData::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink2 = DynamicCast<NiAVObject>(objects[link_stack.front()]);
		if ( unknownLink2 == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink2 = NULL;
	link_stack.pop_front();
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
	out << NiParticles::asString();
	numModifiers = uint(modifiers.size());
	out << "  Unknown Bool:  " << unknownBool << endl;
	out << "  Num Modifiers:  " << numModifiers << endl;
	for (uint i1 = 0; i1 < modifiers.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Modifiers[" << i1 << "]:  " << modifiers[i1] << endl;
	};
	return out.str();
}

void NiParticleSystem::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticles::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		for (uint i2 = 0; i2 < modifiers.size(); i2++) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				modifiers[i2] = DynamicCast<NiPSysModifier>(objects[link_stack.front()]);
				if ( modifiers[i2] == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				modifiers[i2] = NULL;
			link_stack.pop_front();
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
	out << NiParticleSystem::asString();
	return out.str();
}

void NiMeshParticleSystem::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	for (uint i1 = 0; i1 < particles.size(); i1++) {
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

void NiParticleSystemController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		emitter = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( emitter == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		emitter = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( unknownLink == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		particleExtra = DynamicCast<AParticleModifier>(objects[link_stack.front()]);
		if ( particleExtra == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		particleExtra = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink2 = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( unknownLink2 == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink2 = NULL;
	link_stack.pop_front();
}

std::list<NiObjectRef> NiParticleSystemController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( emitter != NULL )
		refs.push_back(StaticCast<NiObject>(emitter));
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
	out << NiParticleSystemController::asString();
	return out.str();
}

void NiBSPArrayController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiPathController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		posData = DynamicCast<NiPosData>(objects[link_stack.front()]);
		if ( posData == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		posData = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		floatData = DynamicCast<NiFloatData>(objects[link_stack.front()]);
		if ( floatData == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		floatData = NULL;
	link_stack.pop_front();
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
	out << NiBlendInterpolator::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Short 2:  " << unknownShort2 << endl;
	out << "  Pos Data:  " << posData << endl;
	out << "  Float Data:  " << floatData << endl;
	return out.str();
}

void NiPathInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		posData = DynamicCast<NiPosData>(objects[link_stack.front()]);
		if ( posData == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		posData = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		floatData = DynamicCast<NiFloatData>(objects[link_stack.front()]);
		if ( floatData == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		floatData = NULL;
	link_stack.pop_front();
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
	out << NiObject::asString();
	numMipmaps = uint(mipmaps.size());
	out << "  Pixel Format:  " << pixelFormat << endl;
	out << "  Red Mask:  " << redMask << endl;
	out << "  Green Mask:  " << greenMask << endl;
	out << "  Blue Mask:  " << blueMask << endl;
	out << "  Alpha Mask:  " << alphaMask << endl;
	out << "  Bits Per Pixel:  " << bitsPerPixel << endl;
	for (uint i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown 8 Bytes[" << i1 << "]:  " << unknown8Bytes[i1] << endl;
	};
	out << "  Unknown Int:  " << unknownInt << endl;
	for (uint i1 = 0; i1 < 54; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown 54 Bytes[" << i1 << "]:  " << unknown54Bytes[i1] << endl;
	};
	out << "  Palette:  " << palette << endl;
	out << "  Num Mipmaps:  " << numMipmaps << endl;
	out << "  Bytes Per Pixel:  " << bytesPerPixel << endl;
	for (uint i1 = 0; i1 < mipmaps.size(); i1++) {
		out << "    Width:  " << mipmaps[i1].width << endl;
		out << "    Height:  " << mipmaps[i1].height << endl;
		out << "    Offset:  " << mipmaps[i1].offset << endl;
	};
	pixelData.dataSize = uint(pixelData.data.size());
	out << "  Data Size:  " << pixelData.dataSize << endl;
	for (uint i1 = 0; i1 < pixelData.data.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Data[" << i1 << "]:  " << pixelData.data[i1] << endl;
	};
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	return out.str();
}

void NiPixelData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		palette = DynamicCast<NiPalette>(objects[link_stack.front()]);
		if ( palette == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		palette = NULL;
	link_stack.pop_front();
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

void NiPlanarCollider::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiInterpolator::asString();
	out << "  Point 3 Value:  " << point3Value << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiPoint3Interpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiPosData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << NiLight::asString();
	out << "  Constant Attenuation:  " << constantAttenuation << endl;
	out << "  Linear Attenuation:  " << linearAttenuation << endl;
	out << "  Quadratic Attenuation:  " << quadraticAttenuation << endl;
	return out.str();
}

void NiPointLight::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << AKeyedData::asString();
	data.numKeys = uint(data.keys.size());
	out << "  Num Keys:  " << data.numKeys << endl;
	if ( (data.numKeys != 0) ) {
		out << "    Interpolation:  " << data.interpolation << endl;
	};
	for (uint i1 = 0; i1 < data.keys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Keys[" << i1 << "]:  " << data.keys[i1] << endl;
	};
	return out.str();
}

void NiPosData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPSysModifier::asString();
	out << "  Spawn on Death:  " << spawnOnDeath << endl;
	out << "  Spawn Modifier:  " << spawnModifier << endl;
	return out.str();
}

void NiPSysAgeDeathModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		spawnModifier = DynamicCast<NiPSysSpawnModifier>(objects[link_stack.front()]);
		if ( spawnModifier == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		spawnModifier = NULL;
	link_stack.pop_front();
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
	out << NiPSysModifier::asString();
	out << "  Unknown Link:  " << unknownLink << endl;
	for (uint i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Ints 1[" << i1 << "]:  " << unknownInts1[i1] << endl;
	};
	for (uint i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
	};
	for (uint i1 = 0; i1 < 2; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Ints 2[" << i1 << "]:  " << unknownInts2[i1] << endl;
	};
	return out.str();
}

void NiPSysBombModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink = DynamicCast<NiNode>(objects[link_stack.front()]);
		if ( unknownLink == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink = NULL;
	link_stack.pop_front();
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
	out << NiPSysModifier::asString();
	out << "  Update Skip:  " << updateSkip << endl;
	return out.str();
}

void NiPSysBoundUpdateModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPSysVolumeEmitter::asString();
	out << "  Width:  " << width << endl;
	out << "  Height:  " << height << endl;
	out << "  Depth:  " << depth << endl;
	return out.str();
}

void NiPSysBoxEmitter::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPSysModifier::asString();
	out << "  Collider:  " << collider << endl;
	return out.str();
}

void NiPSysColliderManager::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		collider = DynamicCast<NiPSysPlanarCollider>(objects[link_stack.front()]);
		if ( collider == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		collider = NULL;
	link_stack.pop_front();
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
	out << NiPSysModifier::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiPSysColorModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiColorData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << NiPSysVolumeEmitter::asString();
	out << "  Radius:  " << radius << endl;
	out << "  Height:  " << height << endl;
	return out.str();
}

void NiPSysCylinderEmitter::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << APSysData::asString();
	for (uint i1 = 0; i1 < unknownFloats4.size(); i1++) {
		for (uint i2 = 0; i2 < 10; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown Floats 4[" << i1 << "][" << i2 << "]:  " << unknownFloats4[i1][i2] << endl;
		};
	};
	out << "  Unknown Bool 1:  " << unknownBool1 << endl;
	if ( (unknownBool1 != 0) ) {
		for (uint i2 = 0; i2 < unknownBytes.size(); i2++) {
			for (uint i3 = 0; i3 < 32; i3++) {
				if ( !verbose && ( i3 > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				out << "        Unknown Bytes[" << i2 << "][" << i3 << "]:  " << unknownBytes[i2][i3] << endl;
			};
		};
	};
	if ( (unknownBool1 == 0) ) {
		for (uint i2 = 0; i2 < unknownBytesAlt.size(); i2++) {
			for (uint i3 = 0; i3 < 28; i3++) {
				if ( !verbose && ( i3 > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				out << "        Unknown Bytes Alt[" << i2 << "][" << i3 << "]:  " << unknownBytesAlt[i2][i3] << endl;
			};
		};
	};
	out << "  Unknown Byte 3:  " << unknownByte3 << endl;
	out << "  Unknown Bool 2:  " << unknownBool2 << endl;
	if ( (unknownBool2 != 0) ) {
		for (uint i2 = 0; i2 < unknownBytes2.size(); i2++) {
			for (uint i3 = 0; i3 < 4; i3++) {
				if ( !verbose && ( i3 > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				out << "        Unknown Bytes 2[" << i2 << "][" << i3 << "]:  " << unknownBytes2[i2][i3] << endl;
			};
		};
	};
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	return out.str();
}

void NiPSysData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPSysModifier::asString();
	out << "  Parent:  " << parent << endl;
	out << "  Drag Axis:  " << dragAxis << endl;
	out << "  Percentage:  " << percentage << endl;
	out << "  Range:  " << range << endl;
	out << "  Range Falloff:  " << rangeFalloff << endl;
	return out.str();
}

void NiPSysDragModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		parent = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( parent == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		parent = NULL;
	link_stack.pop_front();
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
	out << APSysCtlr::asString();
	out << "  Data:  " << data << endl;
	out << "  Visibility Interpolator:  " << visibilityInterpolator << endl;
	return out.str();
}

void NiPSysEmitterCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			data = DynamicCast<NiPSysEmitterCtlrData>(objects[link_stack.front()]);
			if ( data == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			data = NULL;
		link_stack.pop_front();
	};
	if ( version >= 0x0A020000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			visibilityInterpolator = DynamicCast<NiInterpolator>(objects[link_stack.front()]);
			if ( visibilityInterpolator == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			visibilityInterpolator = NULL;
		link_stack.pop_front();
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
	out << NiObject::asString();
	numVisibilityKeys_ = uint(visibilityKeys_.size());
	floatKeys_.numKeys = uint(floatKeys_.keys.size());
	out << "  Num Keys:  " << floatKeys_.numKeys << endl;
	if ( (floatKeys_.numKeys != 0) ) {
		out << "    Interpolation:  " << floatKeys_.interpolation << endl;
	};
	for (uint i1 = 0; i1 < floatKeys_.keys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Keys[" << i1 << "]:  " << floatKeys_.keys[i1] << endl;
	};
	out << "  Num Visibility Keys?:  " << numVisibilityKeys_ << endl;
	for (uint i1 = 0; i1 < visibilityKeys_.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Visibility Keys?[" << i1 << "]:  " << visibilityKeys_[i1] << endl;
	};
	return out.str();
}

void NiPSysEmitterCtlrData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterDeclinationCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterDeclinationVarCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterInitialRadiusCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysEmitterInitialRadiusCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysEmitterLifeSpanCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::Read( in, link_stack, version, user_version );
}

void NiPSysEmitterLifeSpanCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
}

std::string NiPSysEmitterLifeSpanCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterLifeSpanCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysEmitterLifeSpanCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
	return refs;
}

void NiPSysEmitterSpeedCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::Read( in, link_stack, version, user_version );
}

void NiPSysEmitterSpeedCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
}

std::string NiPSysEmitterSpeedCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysEmitterSpeedCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysEmitterSpeedCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
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

void NiPSysGravityModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		gravityObject = DynamicCast<NiNode>(objects[link_stack.front()]);
		if ( gravityObject == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		gravityObject = NULL;
	link_stack.pop_front();
}

std::list<NiObjectRef> NiPSysGravityModifier::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

void NiPSysGravityStrengthCtlr::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::Read( in, link_stack, version, user_version );
}

void NiPSysGravityStrengthCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
}

std::string NiPSysGravityStrengthCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysGravityStrengthCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	APSysCtlr::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysGravityStrengthCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = APSysCtlr::GetRefs();
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
	out << NiPSysModifier::asString();
	out << "  Grow Time:  " << growTime << endl;
	out << "  Grow Generation:  " << growGeneration << endl;
	out << "  Fade Time:  " << fadeTime << endl;
	out << "  Fade Generation:  " << fadeGeneration << endl;
	return out.str();
}

void NiPSysGrowFadeModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPSysEmitter::asString();
	numEmitterMeshes = uint(emitterMeshes.size());
	out << "  Num Emitter Meshes:  " << numEmitterMeshes << endl;
	for (uint i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Emitter Meshes[" << i1 << "]:  " << emitterMeshes[i1] << endl;
	};
	out << "  Initial Velocity Type:  " << initialVelocityType << endl;
	out << "  Emission Type:  " << emissionType << endl;
	out << "  Emission Axis:  " << emissionAxis << endl;
	return out.str();
}

void NiPSysMeshEmitter::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysEmitter::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < emitterMeshes.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			emitterMeshes[i1] = DynamicCast<NiTriBasedGeom>(objects[link_stack.front()]);
			if ( emitterMeshes[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			emitterMeshes[i1] = NULL;
		link_stack.pop_front();
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
	out << NiPSysModifier::asString();
	numMeshes = uint(meshes.size());
	out << "  Num Meshes:  " << numMeshes << endl;
	for (uint i1 = 0; i1 < meshes.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Meshes[" << i1 << "]:  " << meshes[i1] << endl;
	};
	return out.str();
}

void NiPSysMeshUpdateModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiPSysModifier::FixLinks( objects, link_stack, version, user_version );
	for (uint i1 = 0; i1 < meshes.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			meshes[i1] = DynamicCast<NiNode>(objects[link_stack.front()]);
			if ( meshes[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			meshes[i1] = NULL;
		link_stack.pop_front();
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
}

void NiPSysModifierActiveCtlr::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	APSysCtlr::Write( out, link_map, version, user_version );
}

std::string NiPSysModifierActiveCtlr::InternalAsString( bool verbose ) const {
	stringstream out;
	out << APSysCtlr::asString();
	return out.str();
}

void NiPSysModifierActiveCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiPSysPlanarCollider::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		spawnModifier = DynamicCast<NiPSysSpawnModifier>(objects[link_stack.front()]);
		if ( spawnModifier == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		spawnModifier = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		parent = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( parent == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		parent = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		unknownLink_ = DynamicCast<NiObject>(objects[link_stack.front()]);
		if ( unknownLink_ == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		unknownLink_ = NULL;
	link_stack.pop_front();
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		colliderObject = DynamicCast<NiNode>(objects[link_stack.front()]);
		if ( colliderObject == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		colliderObject = NULL;
	link_stack.pop_front();
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
	out << NiPSysModifier::asString();
	return out.str();
}

void NiPSysPositionModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	return out.str();
}

void NiPSysResetOnLoopCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiPSysRotationModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiPSysSpawnModifier::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPSysVolumeEmitter::asString();
	out << "  Radius:  " << radius << endl;
	return out.str();
}

void NiPSysSphereEmitter::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTimeController::asString();
	return out.str();
}

void NiPSysUpdateCtlr::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiPSysUpdateCtlr::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	return refs;
}

void NiRangeLODData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	NifStream( lodCenter, in, version );
	NifStream( numLodLevels, in, version );
	lodLevels.resize(numLodLevels);
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) {
		NifStream( lodLevels[i1].nearExtent, in, version );
		NifStream( lodLevels[i1].farExtent, in, version );
	};
}

void NiRangeLODData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
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
	out << NiObject::asString();
	numLodLevels = uint(lodLevels.size());
	out << "  LOD Center:  " << lodCenter << endl;
	out << "  Num LOD Levels:  " << numLodLevels << endl;
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) {
		out << "    Near Extent:  " << lodLevels[i1].nearExtent << endl;
		out << "    Far Extent:  " << lodLevels[i1].farExtent << endl;
	};
	return out.str();
}

void NiRangeLODData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiRangeLODData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
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
	out << NiParticles::asString();
	return out.str();
}

void NiRotatingParticles::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiParticlesData::asString();
	return out.str();
}

void NiRotatingParticlesData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiParticlesData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiRotatingParticlesData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticlesData::GetRefs();
	return refs;
}

void NiScreenLODData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::Read( in, link_stack, version, user_version );
	for (uint i1 = 0; i1 < 8; i1++) {
		NifStream( unknownFloats[i1], in, version );
	};
	NifStream( unknownCount, in, version );
	unknownFloats2.resize(unknownCount);
	for (uint i1 = 0; i1 < unknownFloats2.size(); i1++) {
		NifStream( unknownFloats2[i1], in, version );
	};
}

void NiScreenLODData::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NiObject::Write( out, link_map, version, user_version );
	unknownCount = uint(unknownFloats2.size());
	for (uint i1 = 0; i1 < 8; i1++) {
		NifStream( unknownFloats[i1], out, version );
	};
	NifStream( unknownCount, out, version );
	for (uint i1 = 0; i1 < unknownFloats2.size(); i1++) {
		NifStream( unknownFloats2[i1], out, version );
	};
}

std::string NiScreenLODData::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiObject::asString();
	unknownCount = uint(unknownFloats2.size());
	for (uint i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl;
	};
	out << "  Unknown Count:  " << unknownCount << endl;
	for (uint i1 = 0; i1 < unknownFloats2.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Floats 2[" << i1 << "]:  " << unknownFloats2[i1] << endl;
	};
	return out.str();
}

void NiScreenLODData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiScreenLODData::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
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
	out << NiObjectNET::asString();
	return out.str();
}

void NiSequenceStreamHelper::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiShadeProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
		for (uint i2 = 0; i2 < 4; i2++) {
			NifStream( boneList[i1].unknown4Floats[i2], in, version );
		};
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
		for (uint i2 = 0; i2 < 4; i2++) {
			NifStream( boneList[i1].unknown4Floats[i2], out, version );
		};
		NifStream( boneList[i1].numVertices, out, version );
		for (uint i2 = 0; i2 < boneList[i1].vertexWeights.size(); i2++) {
			NifStream( boneList[i1].vertexWeights[i2].index, out, version );
			NifStream( boneList[i1].vertexWeights[i2].weight, out, version );
		};
	};
}

std::string NiSkinData::InternalAsString( bool verbose ) const {
	stringstream out;
	out << NiObject::asString();
	numBones = uint(boneList.size());
	out << "  Rotation:  " << rotation << endl;
	out << "  Translation:  " << translation << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Num Bones:  " << numBones << endl;
	out << "  Skin Partition:  " << skinPartition << endl;
	out << "  Unknown Byte:  " << unknownByte << endl;
	for (uint i1 = 0; i1 < boneList.size(); i1++) {
		boneList[i1].numVertices = ushort(boneList[i1].vertexWeights.size());
		out << "    Rotation:  " << boneList[i1].rotation << endl;
		out << "    Translation:  " << boneList[i1].translation << endl;
		out << "    Scale:  " << boneList[i1].scale << endl;
		for (uint i2 = 0; i2 < 4; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Unknown 4 Floats[" << i2 << "]:  " << boneList[i1].unknown4Floats[i2] << endl;
		};
		out << "    Num Vertices:  " << boneList[i1].numVertices << endl;
		for (uint i2 = 0; i2 < boneList[i1].vertexWeights.size(); i2++) {
			out << "      Index:  " << boneList[i1].vertexWeights[i2].index << endl;
			out << "      Weight:  " << boneList[i1].vertexWeights[i2].weight << endl;
		};
	};
	return out.str();
}

void NiSkinData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			skinPartition = DynamicCast<NiSkinPartition>(objects[link_stack.front()]);
			if ( skinPartition == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			skinPartition = NULL;
		link_stack.pop_front();
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
	out << NiObject::asString();
	numBones = uint(bones.size());
	out << "  Data:  " << data << endl;
	out << "  Skin Partition:  " << skinPartition << endl;
	out << "  Skeleton Root:  " << skeletonRoot << endl;
	out << "  Num Bones:  " << numBones << endl;
	for (uint i1 = 0; i1 < bones.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Bones[" << i1 << "]:  " << bones[i1] << endl;
	};
	return out.str();
}

void NiSkinInstance::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObject::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiSkinData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
	if ( version >= 0x0A020000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			skinPartition = DynamicCast<NiSkinPartition>(objects[link_stack.front()]);
			if ( skinPartition == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			skinPartition = NULL;
		link_stack.pop_front();
	};
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		skeletonRoot = DynamicCast<NiNode>(objects[link_stack.front()]);
		if ( skeletonRoot == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		skeletonRoot = NULL;
	link_stack.pop_front();
	for (uint i1 = 0; i1 < bones.size(); i1++) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			bones[i1] = DynamicCast<NiNode>(objects[link_stack.front()]);
			if ( bones[i1] == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			bones[i1] = NULL;
		link_stack.pop_front();
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
		skinPartitionBlocks[i1].numTriangles = skinPartitionBlocks[i1].CalcNumTriangles();
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
	out << NiObject::asString();
	numSkinPartitionBlocks = uint(skinPartitionBlocks.size());
	out << "  Num Skin Partition Blocks:  " << numSkinPartitionBlocks << endl;
	for (uint i1 = 0; i1 < skinPartitionBlocks.size(); i1++) {
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++)
			skinPartitionBlocks[i1].stripLengths[i2] = ushort(skinPartitionBlocks[i1].strips[i2].size());
		skinPartitionBlocks[i1].numWeightsPerVertex = ushort((skinPartitionBlocks[i1].vertexWeights.size() > 0) ? skinPartitionBlocks[i1].vertexWeights[0].size() : 0);
		skinPartitionBlocks[i1].numStrips = ushort(skinPartitionBlocks[i1].stripLengths.size());
		skinPartitionBlocks[i1].numBones = ushort(skinPartitionBlocks[i1].bones.size());
		skinPartitionBlocks[i1].numTriangles = skinPartitionBlocks[i1].CalcNumTriangles();
		skinPartitionBlocks[i1].numVertices = ushort(skinPartitionBlocks[i1].vertexMap.size());
		out << "    Num Vertices:  " << skinPartitionBlocks[i1].numVertices << endl;
		out << "    Num Triangles:  " << skinPartitionBlocks[i1].numTriangles << endl;
		out << "    Num Bones:  " << skinPartitionBlocks[i1].numBones << endl;
		out << "    Num Strips:  " << skinPartitionBlocks[i1].numStrips << endl;
		out << "    Num Weights Per Vertex:  " << skinPartitionBlocks[i1].numWeightsPerVertex << endl;
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].bones.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Bones[" << i2 << "]:  " << skinPartitionBlocks[i1].bones[i2] << endl;
		};
		out << "    Has Vertex Map:  " << skinPartitionBlocks[i1].hasVertexMap << endl;
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].vertexMap.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Vertex Map[" << i2 << "]:  " << skinPartitionBlocks[i1].vertexMap[i2] << endl;
		};
		out << "    Has Vertex Weights:  " << skinPartitionBlocks[i1].hasVertexWeights << endl;
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].vertexWeights.size(); i2++) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].vertexWeights[i2].size(); i3++) {
				if ( !verbose && ( i3 > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				out << "        Vertex Weights[" << i2 << "][" << i3 << "]:  " << skinPartitionBlocks[i1].vertexWeights[i2][i3] << endl;
			};
		};
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].stripLengths.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Strip Lengths[" << i2 << "]:  " << skinPartitionBlocks[i1].stripLengths[i2] << endl;
		};
		out << "    Has Strips:  " << skinPartitionBlocks[i1].hasStrips << endl;
		for (uint i2 = 0; i2 < skinPartitionBlocks[i1].strips.size(); i2++) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].stripLengths[i2]; i3++) {
				if ( !verbose && ( i3 > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				out << "        Strips[" << i2 << "][" << i3 << "]:  " << skinPartitionBlocks[i1].strips[i2][i3] << endl;
			};
		};
		if ( (skinPartitionBlocks[i1].numStrips == 0) ) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].triangles.size(); i3++) {
				if ( !verbose && ( i3 > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				out << "        Triangles[" << i3 << "]:  " << skinPartitionBlocks[i1].triangles[i3] << endl;
			};
		};
		out << "    Has Bone Indices:  " << skinPartitionBlocks[i1].hasBoneIndices << endl;
		if ( (skinPartitionBlocks[i1].hasBoneIndices != 0) ) {
			for (uint i3 = 0; i3 < skinPartitionBlocks[i1].boneIndices.size(); i3++) {
				for (uint i4 = 0; i4 < skinPartitionBlocks[i1].boneIndices[i3].size(); i4++) {
					if ( !verbose && ( i4 > MAXARRAYDUMP ) ) {
						out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
						break;
					};
					out << "          Bone Indices[" << i3 << "][" << i4 << "]:  " << skinPartitionBlocks[i1].boneIndices[i3][i4] << endl;
				};
			};
		};
	};
	return out.str();
}

void NiSkinPartition::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiSourceTexture::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiObjectNET::FixLinks( objects, link_stack, version, user_version );
	if ( version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]);
				if ( unknownLink == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				unknownLink = NULL;
			link_stack.pop_front();
		};
	};
	if ( (useExternal == 0) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			pixelData = DynamicCast<NiPixelData>(objects[link_stack.front()]);
			if ( pixelData == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			pixelData = NULL;
		link_stack.pop_front();
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
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiSpecularProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	NifStream( unknownShort, in, version );
	NifStream( unknownFloat2, in, version );
	NifStream( unknownFloat3, in, version );
	NifStream( unknownFloat4, in, version );
	NifStream( unknownFloat5, in, version );
}

void NiSphericalCollider::InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	AParticleModifier::Write( out, link_map, version, user_version );
	NifStream( unknownFloat1, out, version );
	NifStream( unknownShort, out, version );
	NifStream( unknownFloat2, out, version );
	NifStream( unknownFloat3, out, version );
	NifStream( unknownFloat4, out, version );
	NifStream( unknownFloat5, out, version );
}

std::string NiSphericalCollider::InternalAsString( bool verbose ) const {
	stringstream out;
	out << AParticleModifier::asString();
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Unknown Float 2:  " << unknownFloat2 << endl;
	out << "  Unknown Float 3:  " << unknownFloat3 << endl;
	out << "  Unknown Float 4:  " << unknownFloat4 << endl;
	out << "  Unknown Float 5:  " << unknownFloat5 << endl;
	return out.str();
}

void NiSphericalCollider::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiPointLight::asString();
	out << "  Cutoff Angle:  " << cutoffAngle << endl;
	out << "  Exponent:  " << exponent << endl;
	return out.str();
}

void NiSpotLight::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiStencilProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	out << "  Bytes Remaining:  " << bytesRemaining << endl;
	out << "  String Data:  " << stringData << endl;
	return out.str();
}

void NiStringExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiObject::asString();
	out << "  Palette:  " << palette.palette << endl;
	out << "  Length:  " << palette.length << endl;
	return out.str();
}

void NiStringPalette::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	numStrings = uint(data.size());
	out << "  Num Strings:  " << numStrings << endl;
	for (uint i1 = 0; i1 < data.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Data[" << i1 << "]:  " << data[i1] << endl;
	};
	return out.str();
}

void NiStringsExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	numTextKeys = uint(textKeys.size());
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Num Text Keys:  " << numTextKeys << endl;
	for (uint i1 = 0; i1 < textKeys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Text Keys[" << i1 << "]:  " << textKeys[i1] << endl;
	};
	return out.str();
}

void NiTextKeyExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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

void NiTextureEffect::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiDynamicEffect::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		sourceTexture = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
		if ( sourceTexture == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		sourceTexture = NULL;
	link_stack.pop_front();
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
	out << NiSingleInterpolatorController::asString();
	out << "  Unknown2:  " << unknown2 << endl;
	out << "  Texture Slot:  " << textureSlot << endl;
	out << "  Operation:  " << operation << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiTextureTransformController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			data = DynamicCast<NiFloatData>(objects[link_stack.front()]);
			if ( data == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			data = NULL;
		link_stack.pop_front();
	};
}

std::list<NiObjectRef> NiTextureTransformController::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSingleInterpolatorController::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
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
		NifStream( baseTexture.textureSet, in, version );
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
		NifStream( darkTexture.textureSet, in, version );
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
		NifStream( detailTexture.textureSet, in, version );
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
		NifStream( glossTexture.textureSet, in, version );
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
		NifStream( glowTexture.textureSet, in, version );
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
		NifStream( bumpMapTexture.textureSet, in, version );
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
		NifStream( decal0Texture.textureSet, in, version );
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
	if ( (textureCount == 8) ) {
		NifStream( hasDecal1Texture, in, version );
	};
	if ( version >= 0x14000004 ) {
		if ( (((textureCount == 8)) && ((hasDecal1Texture != 0))) ) {
			NifStream( block_num, in, version );
			link_stack.push_back( block_num );
			NifStream( decal1Texture.clampMode, in, version );
			NifStream( decal1Texture.filterMode, in, version );
			NifStream( decal1Texture.textureSet, in, version );
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
				NifStream( shaderTextures[i2].textureData.textureSet, in, version );
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
		NifStream( baseTexture.textureSet, out, version );
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
		NifStream( darkTexture.textureSet, out, version );
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
		NifStream( detailTexture.textureSet, out, version );
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
		NifStream( glossTexture.textureSet, out, version );
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
		NifStream( glowTexture.textureSet, out, version );
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
		NifStream( bumpMapTexture.textureSet, out, version );
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
		NifStream( decal0Texture.textureSet, out, version );
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
	if ( (textureCount == 8) ) {
		NifStream( hasDecal1Texture, out, version );
	};
	if ( version >= 0x14000004 ) {
		if ( (((textureCount == 8)) && ((hasDecal1Texture != 0))) ) {
			if ( decal1Texture.source != NULL )
				NifStream( link_map[StaticCast<NiObject>(decal1Texture.source)], out, version );
			else
				NifStream( 0xffffffff, out, version );
			NifStream( decal1Texture.clampMode, out, version );
			NifStream( decal1Texture.filterMode, out, version );
			NifStream( decal1Texture.textureSet, out, version );
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
				NifStream( shaderTextures[i2].textureData.textureSet, out, version );
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
		out << "    Texture Set:  " << baseTexture.textureSet << endl;
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
		out << "    Texture Set:  " << darkTexture.textureSet << endl;
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
		out << "    Texture Set:  " << detailTexture.textureSet << endl;
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
		out << "    Texture Set:  " << glossTexture.textureSet << endl;
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
		out << "    Texture Set:  " << glowTexture.textureSet << endl;
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
		out << "    Texture Set:  " << bumpMapTexture.textureSet << endl;
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
		out << "    Texture Set:  " << decal0Texture.textureSet << endl;
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
	if ( (textureCount == 8) ) {
		out << "    Has Decal 1 Texture:  " << hasDecal1Texture << endl;
	};
	if ( (((textureCount == 8)) && ((hasDecal1Texture != 0))) ) {
		out << "    Source:  " << decal1Texture.source << endl;
		out << "    Clamp Mode:  " << decal1Texture.clampMode << endl;
		out << "    Filter Mode:  " << decal1Texture.filterMode << endl;
		out << "    Texture Set:  " << decal1Texture.textureSet << endl;
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
	out << "  Num Shader Textures:  " << numShaderTextures << endl;
	for (uint i1 = 0; i1 < shaderTextures.size(); i1++) {
		out << "    Is Used:  " << shaderTextures[i1].isUsed << endl;
		if ( (shaderTextures[i1].isUsed != 0) ) {
			out << "      Source:  " << shaderTextures[i1].textureData.source << endl;
			out << "      Clamp Mode:  " << shaderTextures[i1].textureData.clampMode << endl;
			out << "      Filter Mode:  " << shaderTextures[i1].textureData.filterMode << endl;
			out << "      Texture Set:  " << shaderTextures[i1].textureData.textureSet << endl;
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

void NiTexturingProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiProperty::FixLinks( objects, link_stack, version, user_version );
	if ( (hasBaseTexture != 0) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			baseTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
			if ( baseTexture.source == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			baseTexture.source = NULL;
		link_stack.pop_front();
	};
	if ( (hasDarkTexture != 0) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			darkTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
			if ( darkTexture.source == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			darkTexture.source = NULL;
		link_stack.pop_front();
	};
	if ( (hasDetailTexture != 0) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			detailTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
			if ( detailTexture.source == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			detailTexture.source = NULL;
		link_stack.pop_front();
	};
	if ( (hasGlossTexture != 0) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			glossTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
			if ( glossTexture.source == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			glossTexture.source = NULL;
		link_stack.pop_front();
	};
	if ( (hasGlowTexture != 0) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			glowTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
			if ( glowTexture.source == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			glowTexture.source = NULL;
		link_stack.pop_front();
	};
	if ( (hasBumpMapTexture != 0) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			bumpMapTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
			if ( bumpMapTexture.source == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			bumpMapTexture.source = NULL;
		link_stack.pop_front();
	};
	if ( (hasDecal0Texture != 0) ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			decal0Texture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
			if ( decal0Texture.source == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			decal0Texture.source = NULL;
		link_stack.pop_front();
	};
	if ( version >= 0x14000004 ) {
		if ( (((textureCount == 8)) && ((hasDecal1Texture != 0))) ) {
			if (link_stack.empty())
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
			if (link_stack.front() != 0xffffffff) {
				decal1Texture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
				if ( decal1Texture.source == NULL )
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
			} else
				decal1Texture.source = NULL;
			link_stack.pop_front();
		};
	};
	if ( version >= 0x0A000100 ) {
		for (uint i2 = 0; i2 < shaderTextures.size(); i2++) {
			if ( (shaderTextures[i2].isUsed != 0) ) {
				if (link_stack.empty())
					throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
				if (link_stack.front() != 0xffffffff) {
					shaderTextures[i2].textureData.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]);
					if ( shaderTextures[i2].textureData.source == NULL )
						throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
				} else
					shaderTextures[i2].textureData.source = NULL;
				link_stack.pop_front();
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
	out << NiSingleInterpolatorController::asString();
	return out.str();
}

void NiTransformController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiKeyframeData::asString();
	return out.str();
}

void NiTransformData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiInterpolator::asString();
	out << "  Translation:  " << translation << endl;
	out << "  Rotation:  " << rotation << endl;
	out << "  Scale:  " << scale << endl;
	for (uint i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Unknown Bytes[" << i1 << "]:  " << unknownBytes[i1] << endl;
	};
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiTransformInterpolator::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiInterpolator::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiTransformData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiTriShape::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriShape::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
	return refs;
}

void NiTriShapeData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::Read( in, link_stack, version, user_version );
	NifStream( numTriangles, in, version );
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
	numTriangles = ushort(triangles.size());
	NifStream( numTriangles, out, version );
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
	out << NiTriBasedGeomData::asString();
	numMatchGroups = ushort(matchGroups.size());
	numTriangles = ushort(triangles.size());
	out << "  Num Triangles:  " << numTriangles << endl;
	out << "  Num Triangle Points:  " << numTrianglePoints << endl;
	out << "  Has Triangles:  " << hasTriangles << endl;
	for (uint i1 = 0; i1 < triangles.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Triangles[" << i1 << "]:  " << triangles[i1] << endl;
	};
	out << "  Num Match Groups:  " << numMatchGroups << endl;
	for (uint i1 = 0; i1 < matchGroups.size(); i1++) {
		matchGroups[i1].numVertices = ushort(matchGroups[i1].vertexIndices.size());
		out << "    Num Vertices:  " << matchGroups[i1].numVertices << endl;
		for (uint i2 = 0; i2 < matchGroups[i1].vertexIndices.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Vertex Indices[" << i2 << "]:  " << matchGroups[i1].vertexIndices[i2] << endl;
		};
	};
	return out.str();
}

void NiTriShapeData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiTriBasedGeom::asString();
	return out.str();
}

void NiTriStrips::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriStrips::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriBasedGeom::GetRefs();
	return refs;
}

void NiTriStripsData::InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::Read( in, link_stack, version, user_version );
	NifStream( numTriangles, in, version );
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
	NifStream( numTriangles, out, version );
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
	out << NiTriBasedGeomData::asString();
	for (uint i1 = 0; i1 < points.size(); i1++)
		stripLengths[i1] = ushort(points[i1].size());
	numStrips = ushort(stripLengths.size());
	out << "  Num Triangles:  " << numTriangles << endl;
	out << "  Num Strips:  " << numStrips << endl;
	for (uint i1 = 0; i1 < stripLengths.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Strip Lengths[" << i1 << "]:  " << stripLengths[i1] << endl;
	};
	out << "  Has Points:  " << hasPoints << endl;
	for (uint i1 = 0; i1 < points.size(); i1++) {
		for (uint i2 = 0; i2 < stripLengths[i1]; i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Points[" << i1 << "][" << i2 << "]:  " << points[i1][i2] << endl;
		};
	};
	return out.str();
}

void NiTriStripsData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> NiTriStripsData::InternalGetRefs() const {
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
	out << NiTimeController::asString();
	out << "  Unknown Short:  " << unknownShort << endl;
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiUVController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiTimeController::FixLinks( objects, link_stack, version, user_version );
	if (link_stack.empty())
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
	if (link_stack.front() != 0xffffffff) {
		data = DynamicCast<NiUVData>(objects[link_stack.front()]);
		if ( data == NULL )
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
	} else
		data = NULL;
	link_stack.pop_front();
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
	out << NiObject::asString();
	for (uint i1 = 0; i1 < 4; i1++) {
		uvGroups[i1].numKeys = uint(uvGroups[i1].keys.size());
		out << "    Num Keys:  " << uvGroups[i1].numKeys << endl;
		if ( (uvGroups[i1].numKeys != 0) ) {
			out << "      Interpolation:  " << uvGroups[i1].interpolation << endl;
		};
		for (uint i2 = 0; i2 < uvGroups[i1].keys.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Keys[" << i2 << "]:  " << uvGroups[i1].keys[i2] << endl;
		};
	};
	return out.str();
}

void NiUVData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	out << "  Vector Data:  " << vectorData << endl;
	out << "  Unknown Float:  " << unknownFloat << endl;
	return out.str();
}

void NiVectorExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Vertex Mode:  " << vertexMode << endl;
	out << "  Lighting Mode:  " << lightingMode << endl;
	return out.str();
}

void NiVertexColorProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiExtraData::asString();
	numVertices = ushort(weight.size());
	out << "  Num Bytes:  " << numBytes << endl;
	out << "  Num Vertices:  " << numVertices << endl;
	for (uint i1 = 0; i1 < weight.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Weight[" << i1 << "]:  " << weight[i1] << endl;
	};
	return out.str();
}

void NiVertWeightsExtraData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiSingleInterpolatorController::asString();
	out << "  Data:  " << data << endl;
	return out.str();
}

void NiVisController::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version );
	if ( version <= 0x0A010000 ) {
		if (link_stack.empty())
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug.");
		if (link_stack.front() != 0xffffffff) {
			data = DynamicCast<NiVisData>(objects[link_stack.front()]);
			if ( data == NULL )
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood.");
		} else
			data = NULL;
		link_stack.pop_front();
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
	out << AKeyedData::asString();
	numVisKeys = uint(visKeys.size());
	out << "  Num Vis Keys:  " << numVisKeys << endl;
	for (uint i1 = 0; i1 < visKeys.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Vis Keys[" << i1 << "]:  " << visKeys[i1] << endl;
	};
	return out.str();
}

void NiVisData::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();
}

void NiWireframeProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	out << "  Function:  " << function << endl;
	return out.str();
}

void NiZBufferProperty::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
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
	out << NiNode::asString();
	return out.str();
}

void RootCollisionNode::InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NiNode::FixLinks( objects, link_stack, version, user_version );
}

std::list<NiObjectRef> RootCollisionNode::InternalGetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	return refs;
}

