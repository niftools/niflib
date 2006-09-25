/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiObject.h"
using namespace Niflib;
using namespace std;
namespace Niflib {
typedef NiObject*(*blk_factory_func)();
extern map<string, blk_factory_func> global_block_map;
}

#include "../../include/obj/bhkBlendCollisionObject.h"
NiObject * CreatebhkBlendCollisionObject() { return new bhkBlendCollisionObject; }
#include "../../include/obj/bhkBlendController.h"
NiObject * CreatebhkBlendController() { return new bhkBlendController; }
#include "../../include/obj/bhkBoxShape.h"
NiObject * CreatebhkBoxShape() { return new bhkBoxShape; }
#include "../../include/obj/bhkCapsuleShape.h"
NiObject * CreatebhkCapsuleShape() { return new bhkCapsuleShape; }
#include "../../include/obj/bhkCollisionObject.h"
NiObject * CreatebhkCollisionObject() { return new bhkCollisionObject; }
#include "../../include/obj/bhkConvexVerticesShape.h"
NiObject * CreatebhkConvexVerticesShape() { return new bhkConvexVerticesShape; }
#include "../../include/obj/bhkHingeConstraint.h"
NiObject * CreatebhkHingeConstraint() { return new bhkHingeConstraint; }
#include "../../include/obj/bhkLimitedHingeConstraint.h"
NiObject * CreatebhkLimitedHingeConstraint() { return new bhkLimitedHingeConstraint; }
#include "../../include/obj/bhkListShape.h"
NiObject * CreatebhkListShape() { return new bhkListShape; }
#include "../../include/obj/bhkMalleableConstraint.h"
NiObject * CreatebhkMalleableConstraint() { return new bhkMalleableConstraint; }
#include "../../include/obj/bhkMoppBvTreeShape.h"
NiObject * CreatebhkMoppBvTreeShape() { return new bhkMoppBvTreeShape; }
#include "../../include/obj/bhkMultiSphereShape.h"
NiObject * CreatebhkMultiSphereShape() { return new bhkMultiSphereShape; }
#include "../../include/obj/bhkNiTriStripsShape.h"
NiObject * CreatebhkNiTriStripsShape() { return new bhkNiTriStripsShape; }
#include "../../include/obj/bhkPackedNiTriStripsShape.h"
NiObject * CreatebhkPackedNiTriStripsShape() { return new bhkPackedNiTriStripsShape; }
#include "../../include/obj/bhkPrismaticConstraint.h"
NiObject * CreatebhkPrismaticConstraint() { return new bhkPrismaticConstraint; }
#include "../../include/obj/bhkRagdollConstraint.h"
NiObject * CreatebhkRagdollConstraint() { return new bhkRagdollConstraint; }
#include "../../include/obj/bhkRigidBody.h"
NiObject * CreatebhkRigidBody() { return new bhkRigidBody; }
#include "../../include/obj/bhkRigidBodyT.h"
NiObject * CreatebhkRigidBodyT() { return new bhkRigidBodyT; }
#include "../../include/obj/bhkSimpleShapePhantom.h"
NiObject * CreatebhkSimpleShapePhantom() { return new bhkSimpleShapePhantom; }
#include "../../include/obj/bhkSPCollisionObject.h"
NiObject * CreatebhkSPCollisionObject() { return new bhkSPCollisionObject; }
#include "../../include/obj/bhkSphereShape.h"
NiObject * CreatebhkSphereShape() { return new bhkSphereShape; }
#include "../../include/obj/bhkStiffSpringConstraint.h"
NiObject * CreatebhkStiffSpringConstraint() { return new bhkStiffSpringConstraint; }
#include "../../include/obj/bhkTransformShape.h"
NiObject * CreatebhkTransformShape() { return new bhkTransformShape; }
#include "../../include/obj/bhkConvexTransformShape.h"
NiObject * CreatebhkConvexTransformShape() { return new bhkConvexTransformShape; }
#include "../../include/obj/BSBound.h"
NiObject * CreateBSBound() { return new BSBound; }
#include "../../include/obj/BSFurnitureMarker.h"
NiObject * CreateBSFurnitureMarker() { return new BSFurnitureMarker; }
#include "../../include/obj/BSParentVelocityModifier.h"
NiObject * CreateBSParentVelocityModifier() { return new BSParentVelocityModifier; }
#include "../../include/obj/BSPSysArrayEmitter.h"
NiObject * CreateBSPSysArrayEmitter() { return new BSPSysArrayEmitter; }
#include "../../include/obj/BSXFlags.h"
NiObject * CreateBSXFlags() { return new BSXFlags; }
#include "../../include/obj/hkPackedNiTriStripsData.h"
NiObject * CreatehkPackedNiTriStripsData() { return new hkPackedNiTriStripsData; }
#include "../../include/obj/NiAlphaController.h"
NiObject * CreateNiAlphaController() { return new NiAlphaController; }
#include "../../include/obj/NiAlphaProperty.h"
NiObject * CreateNiAlphaProperty() { return new NiAlphaProperty; }
#include "../../include/obj/NiAmbientLight.h"
NiObject * CreateNiAmbientLight() { return new NiAmbientLight; }
#include "../../include/obj/NiAutoNormalParticlesData.h"
NiObject * CreateNiAutoNormalParticlesData() { return new NiAutoNormalParticlesData; }
#include "../../include/obj/NiBinaryExtraData.h"
NiObject * CreateNiBinaryExtraData() { return new NiBinaryExtraData; }
#include "../../include/obj/NiBlendBoolInterpolator.h"
NiObject * CreateNiBlendBoolInterpolator() { return new NiBlendBoolInterpolator; }
#include "../../include/obj/NiBlendFloatInterpolator.h"
NiObject * CreateNiBlendFloatInterpolator() { return new NiBlendFloatInterpolator; }
#include "../../include/obj/NiBlendPoint3Interpolator.h"
NiObject * CreateNiBlendPoint3Interpolator() { return new NiBlendPoint3Interpolator; }
#include "../../include/obj/NiBlendTransformInterpolator.h"
NiObject * CreateNiBlendTransformInterpolator() { return new NiBlendTransformInterpolator; }
#include "../../include/obj/NiBoneLODController.h"
NiObject * CreateNiBoneLODController() { return new NiBoneLODController; }
#include "../../include/obj/NiBoolData.h"
NiObject * CreateNiBoolData() { return new NiBoolData; }
#include "../../include/obj/NiBooleanExtraData.h"
NiObject * CreateNiBooleanExtraData() { return new NiBooleanExtraData; }
#include "../../include/obj/NiBoolInterpolator.h"
NiObject * CreateNiBoolInterpolator() { return new NiBoolInterpolator; }
#include "../../include/obj/NiBoolTimelineInterpolator.h"
NiObject * CreateNiBoolTimelineInterpolator() { return new NiBoolTimelineInterpolator; }
#include "../../include/obj/NiBSBoneLODController.h"
NiObject * CreateNiBSBoneLODController() { return new NiBSBoneLODController; }
#include "../../include/obj/NiBSplineBasisData.h"
NiObject * CreateNiBSplineBasisData() { return new NiBSplineBasisData; }
#include "../../include/obj/NiBSplineCompFloatInterpolator.h"
NiObject * CreateNiBSplineCompFloatInterpolator() { return new NiBSplineCompFloatInterpolator; }
#include "../../include/obj/NiBSplineCompPoint3Interpolator.h"
NiObject * CreateNiBSplineCompPoint3Interpolator() { return new NiBSplineCompPoint3Interpolator; }
#include "../../include/obj/NiBSplineCompTransformInterpolator.h"
NiObject * CreateNiBSplineCompTransformInterpolator() { return new NiBSplineCompTransformInterpolator; }
#include "../../include/obj/NiBSplineData.h"
NiObject * CreateNiBSplineData() { return new NiBSplineData; }
#include "../../include/obj/NiCamera.h"
NiObject * CreateNiCamera() { return new NiCamera; }
#include "../../include/obj/NiCollisionData.h"
NiObject * CreateNiCollisionData() { return new NiCollisionData; }
#include "../../include/obj/NiColorData.h"
NiObject * CreateNiColorData() { return new NiColorData; }
#include "../../include/obj/NiColorExtraData.h"
NiObject * CreateNiColorExtraData() { return new NiColorExtraData; }
#include "../../include/obj/NiControllerManager.h"
NiObject * CreateNiControllerManager() { return new NiControllerManager; }
#include "../../include/obj/NiControllerSequence.h"
NiObject * CreateNiControllerSequence() { return new NiControllerSequence; }
#include "../../include/obj/NiDefaultAVObjectPalette.h"
NiObject * CreateNiDefaultAVObjectPalette() { return new NiDefaultAVObjectPalette; }
#include "../../include/obj/NiDirectionalLight.h"
NiObject * CreateNiDirectionalLight() { return new NiDirectionalLight; }
#include "../../include/obj/NiDitherProperty.h"
NiObject * CreateNiDitherProperty() { return new NiDitherProperty; }
#include "../../include/obj/NiFlipController.h"
NiObject * CreateNiFlipController() { return new NiFlipController; }
#include "../../include/obj/NiFloatData.h"
NiObject * CreateNiFloatData() { return new NiFloatData; }
#include "../../include/obj/NiFloatExtraData.h"
NiObject * CreateNiFloatExtraData() { return new NiFloatExtraData; }
#include "../../include/obj/NiFloatExtraDataController.h"
NiObject * CreateNiFloatExtraDataController() { return new NiFloatExtraDataController; }
#include "../../include/obj/NiFloatInterpolator.h"
NiObject * CreateNiFloatInterpolator() { return new NiFloatInterpolator; }
#include "../../include/obj/NiFloatsExtraData.h"
NiObject * CreateNiFloatsExtraData() { return new NiFloatsExtraData; }
#include "../../include/obj/NiFogProperty.h"
NiObject * CreateNiFogProperty() { return new NiFogProperty; }
#include "../../include/obj/NiGeomMorpherController.h"
NiObject * CreateNiGeomMorpherController() { return new NiGeomMorpherController; }
#include "../../include/obj/NiGravity.h"
NiObject * CreateNiGravity() { return new NiGravity; }
#include "../../include/obj/NiIntegerExtraData.h"
NiObject * CreateNiIntegerExtraData() { return new NiIntegerExtraData; }
#include "../../include/obj/NiIntegersExtraData.h"
NiObject * CreateNiIntegersExtraData() { return new NiIntegersExtraData; }
#include "../../include/obj/NiKeyframeController.h"
NiObject * CreateNiKeyframeController() { return new NiKeyframeController; }
#include "../../include/obj/BSKeyframeController.h"
NiObject * CreateBSKeyframeController() { return new BSKeyframeController; }
#include "../../include/obj/NiKeyframeData.h"
NiObject * CreateNiKeyframeData() { return new NiKeyframeData; }
#include "../../include/obj/NiLightColorController.h"
NiObject * CreateNiLightColorController() { return new NiLightColorController; }
#include "../../include/obj/NiLightDimmerController.h"
NiObject * CreateNiLightDimmerController() { return new NiLightDimmerController; }
#include "../../include/obj/NiLookAtController.h"
NiObject * CreateNiLookAtController() { return new NiLookAtController; }
#include "../../include/obj/NiLookAtInterpolator.h"
NiObject * CreateNiLookAtInterpolator() { return new NiLookAtInterpolator; }
#include "../../include/obj/NiMaterialColorController.h"
NiObject * CreateNiMaterialColorController() { return new NiMaterialColorController; }
#include "../../include/obj/NiMaterialProperty.h"
NiObject * CreateNiMaterialProperty() { return new NiMaterialProperty; }
#include "../../include/obj/NiMeshPSysData.h"
NiObject * CreateNiMeshPSysData() { return new NiMeshPSysData; }
#include "../../include/obj/NiMorphData.h"
NiObject * CreateNiMorphData() { return new NiMorphData; }
#include "../../include/obj/NiMultiTargetTransformController.h"
NiObject * CreateNiMultiTargetTransformController() { return new NiMultiTargetTransformController; }
#include "../../include/obj/NiNode.h"
NiObject * CreateNiNode() { return new NiNode; }
#include "../../include/obj/AvoidNode.h"
NiObject * CreateAvoidNode() { return new AvoidNode; }
#include "../../include/obj/FxWidget.h"
NiObject * CreateFxWidget() { return new FxWidget; }
#include "../../include/obj/FxButton.h"
NiObject * CreateFxButton() { return new FxButton; }
#include "../../include/obj/FxRadioButton.h"
NiObject * CreateFxRadioButton() { return new FxRadioButton; }
#include "../../include/obj/NiBillboardNode.h"
NiObject * CreateNiBillboardNode() { return new NiBillboardNode; }
#include "../../include/obj/NiBSAnimationNode.h"
NiObject * CreateNiBSAnimationNode() { return new NiBSAnimationNode; }
#include "../../include/obj/NiBSParticleNode.h"
NiObject * CreateNiBSParticleNode() { return new NiBSParticleNode; }
#include "../../include/obj/NiLODNode.h"
NiObject * CreateNiLODNode() { return new NiLODNode; }
#include "../../include/obj/NiPalette.h"
NiObject * CreateNiPalette() { return new NiPalette; }
#include "../../include/obj/NiParticleBomb.h"
NiObject * CreateNiParticleBomb() { return new NiParticleBomb; }
#include "../../include/obj/NiParticleColorModifier.h"
NiObject * CreateNiParticleColorModifier() { return new NiParticleColorModifier; }
#include "../../include/obj/NiParticleGrowFade.h"
NiObject * CreateNiParticleGrowFade() { return new NiParticleGrowFade; }
#include "../../include/obj/NiParticleMeshModifier.h"
NiObject * CreateNiParticleMeshModifier() { return new NiParticleMeshModifier; }
#include "../../include/obj/NiParticleRotation.h"
NiObject * CreateNiParticleRotation() { return new NiParticleRotation; }
#include "../../include/obj/NiParticles.h"
NiObject * CreateNiParticles() { return new NiParticles; }
#include "../../include/obj/NiAutoNormalParticles.h"
NiObject * CreateNiAutoNormalParticles() { return new NiAutoNormalParticles; }
#include "../../include/obj/NiParticleMeshes.h"
NiObject * CreateNiParticleMeshes() { return new NiParticleMeshes; }
#include "../../include/obj/NiParticlesData.h"
NiObject * CreateNiParticlesData() { return new NiParticlesData; }
#include "../../include/obj/NiParticleMeshesData.h"
NiObject * CreateNiParticleMeshesData() { return new NiParticleMeshesData; }
#include "../../include/obj/NiParticleSystem.h"
NiObject * CreateNiParticleSystem() { return new NiParticleSystem; }
#include "../../include/obj/NiMeshParticleSystem.h"
NiObject * CreateNiMeshParticleSystem() { return new NiMeshParticleSystem; }
#include "../../include/obj/NiParticleSystemController.h"
NiObject * CreateNiParticleSystemController() { return new NiParticleSystemController; }
#include "../../include/obj/NiBSPArrayController.h"
NiObject * CreateNiBSPArrayController() { return new NiBSPArrayController; }
#include "../../include/obj/NiPathController.h"
NiObject * CreateNiPathController() { return new NiPathController; }
#include "../../include/obj/NiPathInterpolator.h"
NiObject * CreateNiPathInterpolator() { return new NiPathInterpolator; }
#include "../../include/obj/NiPixelData.h"
NiObject * CreateNiPixelData() { return new NiPixelData; }
#include "../../include/obj/NiPlanarCollider.h"
NiObject * CreateNiPlanarCollider() { return new NiPlanarCollider; }
#include "../../include/obj/NiPoint3Interpolator.h"
NiObject * CreateNiPoint3Interpolator() { return new NiPoint3Interpolator; }
#include "../../include/obj/NiPointLight.h"
NiObject * CreateNiPointLight() { return new NiPointLight; }
#include "../../include/obj/NiPosData.h"
NiObject * CreateNiPosData() { return new NiPosData; }
#include "../../include/obj/NiPSysAgeDeathModifier.h"
NiObject * CreateNiPSysAgeDeathModifier() { return new NiPSysAgeDeathModifier; }
#include "../../include/obj/NiPSysBombModifier.h"
NiObject * CreateNiPSysBombModifier() { return new NiPSysBombModifier; }
#include "../../include/obj/NiPSysBoundUpdateModifier.h"
NiObject * CreateNiPSysBoundUpdateModifier() { return new NiPSysBoundUpdateModifier; }
#include "../../include/obj/NiPSysBoxEmitter.h"
NiObject * CreateNiPSysBoxEmitter() { return new NiPSysBoxEmitter; }
#include "../../include/obj/NiPSysColliderManager.h"
NiObject * CreateNiPSysColliderManager() { return new NiPSysColliderManager; }
#include "../../include/obj/NiPSysColorModifier.h"
NiObject * CreateNiPSysColorModifier() { return new NiPSysColorModifier; }
#include "../../include/obj/NiPSysCylinderEmitter.h"
NiObject * CreateNiPSysCylinderEmitter() { return new NiPSysCylinderEmitter; }
#include "../../include/obj/NiPSysData.h"
NiObject * CreateNiPSysData() { return new NiPSysData; }
#include "../../include/obj/NiPSysDragModifier.h"
NiObject * CreateNiPSysDragModifier() { return new NiPSysDragModifier; }
#include "../../include/obj/NiPSysEmitterCtlr.h"
NiObject * CreateNiPSysEmitterCtlr() { return new NiPSysEmitterCtlr; }
#include "../../include/obj/NiPSysEmitterCtlrData.h"
NiObject * CreateNiPSysEmitterCtlrData() { return new NiPSysEmitterCtlrData; }
#include "../../include/obj/NiPSysEmitterDeclinationCtlr.h"
NiObject * CreateNiPSysEmitterDeclinationCtlr() { return new NiPSysEmitterDeclinationCtlr; }
#include "../../include/obj/NiPSysEmitterDeclinationVarCtlr.h"
NiObject * CreateNiPSysEmitterDeclinationVarCtlr() { return new NiPSysEmitterDeclinationVarCtlr; }
#include "../../include/obj/NiPSysEmitterInitialRadiusCtlr.h"
NiObject * CreateNiPSysEmitterInitialRadiusCtlr() { return new NiPSysEmitterInitialRadiusCtlr; }
#include "../../include/obj/NiPSysEmitterLifeSpanCtlr.h"
NiObject * CreateNiPSysEmitterLifeSpanCtlr() { return new NiPSysEmitterLifeSpanCtlr; }
#include "../../include/obj/NiPSysEmitterSpeedCtlr.h"
NiObject * CreateNiPSysEmitterSpeedCtlr() { return new NiPSysEmitterSpeedCtlr; }
#include "../../include/obj/NiPSysGravityModifier.h"
NiObject * CreateNiPSysGravityModifier() { return new NiPSysGravityModifier; }
#include "../../include/obj/NiPSysGravityStrengthCtlr.h"
NiObject * CreateNiPSysGravityStrengthCtlr() { return new NiPSysGravityStrengthCtlr; }
#include "../../include/obj/NiPSysGrowFadeModifier.h"
NiObject * CreateNiPSysGrowFadeModifier() { return new NiPSysGrowFadeModifier; }
#include "../../include/obj/NiPSysMeshEmitter.h"
NiObject * CreateNiPSysMeshEmitter() { return new NiPSysMeshEmitter; }
#include "../../include/obj/NiPSysMeshUpdateModifier.h"
NiObject * CreateNiPSysMeshUpdateModifier() { return new NiPSysMeshUpdateModifier; }
#include "../../include/obj/NiPSysModifierActiveCtlr.h"
NiObject * CreateNiPSysModifierActiveCtlr() { return new NiPSysModifierActiveCtlr; }
#include "../../include/obj/NiPSysPlanarCollider.h"
NiObject * CreateNiPSysPlanarCollider() { return new NiPSysPlanarCollider; }
#include "../../include/obj/NiPSysPositionModifier.h"
NiObject * CreateNiPSysPositionModifier() { return new NiPSysPositionModifier; }
#include "../../include/obj/NiPSysResetOnLoopCtlr.h"
NiObject * CreateNiPSysResetOnLoopCtlr() { return new NiPSysResetOnLoopCtlr; }
#include "../../include/obj/NiPSysRotationModifier.h"
NiObject * CreateNiPSysRotationModifier() { return new NiPSysRotationModifier; }
#include "../../include/obj/NiPSysSpawnModifier.h"
NiObject * CreateNiPSysSpawnModifier() { return new NiPSysSpawnModifier; }
#include "../../include/obj/NiPSysSphereEmitter.h"
NiObject * CreateNiPSysSphereEmitter() { return new NiPSysSphereEmitter; }
#include "../../include/obj/NiPSysUpdateCtlr.h"
NiObject * CreateNiPSysUpdateCtlr() { return new NiPSysUpdateCtlr; }
#include "../../include/obj/NiRangeLODData.h"
NiObject * CreateNiRangeLODData() { return new NiRangeLODData; }
#include "../../include/obj/NiScreenLODData.h"
NiObject * CreateNiScreenLODData() { return new NiScreenLODData; }
#include "../../include/obj/NiRotatingParticles.h"
NiObject * CreateNiRotatingParticles() { return new NiRotatingParticles; }
#include "../../include/obj/NiRotatingParticlesData.h"
NiObject * CreateNiRotatingParticlesData() { return new NiRotatingParticlesData; }
#include "../../include/obj/NiSequenceStreamHelper.h"
NiObject * CreateNiSequenceStreamHelper() { return new NiSequenceStreamHelper; }
#include "../../include/obj/NiShadeProperty.h"
NiObject * CreateNiShadeProperty() { return new NiShadeProperty; }
#include "../../include/obj/NiSkinData.h"
NiObject * CreateNiSkinData() { return new NiSkinData; }
#include "../../include/obj/NiSkinInstance.h"
NiObject * CreateNiSkinInstance() { return new NiSkinInstance; }
#include "../../include/obj/NiClodSkinInstance.h"
NiObject * CreateNiClodSkinInstance() { return new NiClodSkinInstance; }
#include "../../include/obj/NiSkinPartition.h"
NiObject * CreateNiSkinPartition() { return new NiSkinPartition; }
#include "../../include/obj/NiSourceTexture.h"
NiObject * CreateNiSourceTexture() { return new NiSourceTexture; }
#include "../../include/obj/NiSpecularProperty.h"
NiObject * CreateNiSpecularProperty() { return new NiSpecularProperty; }
#include "../../include/obj/NiSphericalCollider.h"
NiObject * CreateNiSphericalCollider() { return new NiSphericalCollider; }
#include "../../include/obj/NiSpotLight.h"
NiObject * CreateNiSpotLight() { return new NiSpotLight; }
#include "../../include/obj/NiStencilProperty.h"
NiObject * CreateNiStencilProperty() { return new NiStencilProperty; }
#include "../../include/obj/NiStringExtraData.h"
NiObject * CreateNiStringExtraData() { return new NiStringExtraData; }
#include "../../include/obj/NiStringPalette.h"
NiObject * CreateNiStringPalette() { return new NiStringPalette; }
#include "../../include/obj/NiStringsExtraData.h"
NiObject * CreateNiStringsExtraData() { return new NiStringsExtraData; }
#include "../../include/obj/NiTextKeyExtraData.h"
NiObject * CreateNiTextKeyExtraData() { return new NiTextKeyExtraData; }
#include "../../include/obj/NiTextureEffect.h"
NiObject * CreateNiTextureEffect() { return new NiTextureEffect; }
#include "../../include/obj/NiTextureTransformController.h"
NiObject * CreateNiTextureTransformController() { return new NiTextureTransformController; }
#include "../../include/obj/NiTexturingProperty.h"
NiObject * CreateNiTexturingProperty() { return new NiTexturingProperty; }
#include "../../include/obj/NiTransformController.h"
NiObject * CreateNiTransformController() { return new NiTransformController; }
#include "../../include/obj/NiTransformData.h"
NiObject * CreateNiTransformData() { return new NiTransformData; }
#include "../../include/obj/NiTransformInterpolator.h"
NiObject * CreateNiTransformInterpolator() { return new NiTransformInterpolator; }
#include "../../include/obj/NiTriShape.h"
NiObject * CreateNiTriShape() { return new NiTriShape; }
#include "../../include/obj/NiTriShapeData.h"
NiObject * CreateNiTriShapeData() { return new NiTriShapeData; }
#include "../../include/obj/NiTriStrips.h"
NiObject * CreateNiTriStrips() { return new NiTriStrips; }
#include "../../include/obj/NiTriStripsData.h"
NiObject * CreateNiTriStripsData() { return new NiTriStripsData; }
#include "../../include/obj/NiClod.h"
NiObject * CreateNiClod() { return new NiClod; }
#include "../../include/obj/NiClodData.h"
NiObject * CreateNiClodData() { return new NiClodData; }
#include "../../include/obj/NiUVController.h"
NiObject * CreateNiUVController() { return new NiUVController; }
#include "../../include/obj/NiUVData.h"
NiObject * CreateNiUVData() { return new NiUVData; }
#include "../../include/obj/NiVectorExtraData.h"
NiObject * CreateNiVectorExtraData() { return new NiVectorExtraData; }
#include "../../include/obj/NiVertexColorProperty.h"
NiObject * CreateNiVertexColorProperty() { return new NiVertexColorProperty; }
#include "../../include/obj/NiVertWeightsExtraData.h"
NiObject * CreateNiVertWeightsExtraData() { return new NiVertWeightsExtraData; }
#include "../../include/obj/NiVisController.h"
NiObject * CreateNiVisController() { return new NiVisController; }
#include "../../include/obj/NiVisData.h"
NiObject * CreateNiVisData() { return new NiVisData; }
#include "../../include/obj/NiWireframeProperty.h"
NiObject * CreateNiWireframeProperty() { return new NiWireframeProperty; }
#include "../../include/obj/NiZBufferProperty.h"
NiObject * CreateNiZBufferProperty() { return new NiZBufferProperty; }
#include "../../include/obj/RootCollisionNode.h"
NiObject * CreateRootCollisionNode() { return new RootCollisionNode; }

namespace Niflib {
//This function registers the factory functions with global_block_map which is used by CreateNiObject
void RegisterBlockFactories() {
	global_block_map["bhkBlendCollisionObject"] = CreatebhkBlendCollisionObject;
	global_block_map["bhkBlendController"] = CreatebhkBlendController;
	global_block_map["bhkBoxShape"] = CreatebhkBoxShape;
	global_block_map["bhkCapsuleShape"] = CreatebhkCapsuleShape;
	global_block_map["bhkCollisionObject"] = CreatebhkCollisionObject;
	global_block_map["bhkConvexVerticesShape"] = CreatebhkConvexVerticesShape;
	global_block_map["bhkHingeConstraint"] = CreatebhkHingeConstraint;
	global_block_map["bhkLimitedHingeConstraint"] = CreatebhkLimitedHingeConstraint;
	global_block_map["bhkListShape"] = CreatebhkListShape;
	global_block_map["bhkMalleableConstraint"] = CreatebhkMalleableConstraint;
	global_block_map["bhkMoppBvTreeShape"] = CreatebhkMoppBvTreeShape;
	global_block_map["bhkMultiSphereShape"] = CreatebhkMultiSphereShape;
	global_block_map["bhkNiTriStripsShape"] = CreatebhkNiTriStripsShape;
	global_block_map["bhkPackedNiTriStripsShape"] = CreatebhkPackedNiTriStripsShape;
	global_block_map["bhkPrismaticConstraint"] = CreatebhkPrismaticConstraint;
	global_block_map["bhkRagdollConstraint"] = CreatebhkRagdollConstraint;
	global_block_map["bhkRigidBody"] = CreatebhkRigidBody;
	global_block_map["bhkRigidBodyT"] = CreatebhkRigidBodyT;
	global_block_map["bhkSimpleShapePhantom"] = CreatebhkSimpleShapePhantom;
	global_block_map["bhkSPCollisionObject"] = CreatebhkSPCollisionObject;
	global_block_map["bhkSphereShape"] = CreatebhkSphereShape;
	global_block_map["bhkStiffSpringConstraint"] = CreatebhkStiffSpringConstraint;
	global_block_map["bhkTransformShape"] = CreatebhkTransformShape;
	global_block_map["bhkConvexTransformShape"] = CreatebhkConvexTransformShape;
	global_block_map["BSBound"] = CreateBSBound;
	global_block_map["BSFurnitureMarker"] = CreateBSFurnitureMarker;
	global_block_map["BSParentVelocityModifier"] = CreateBSParentVelocityModifier;
	global_block_map["BSPSysArrayEmitter"] = CreateBSPSysArrayEmitter;
	global_block_map["BSXFlags"] = CreateBSXFlags;
	global_block_map["hkPackedNiTriStripsData"] = CreatehkPackedNiTriStripsData;
	global_block_map["NiAlphaController"] = CreateNiAlphaController;
	global_block_map["NiAlphaProperty"] = CreateNiAlphaProperty;
	global_block_map["NiAmbientLight"] = CreateNiAmbientLight;
	global_block_map["NiAutoNormalParticlesData"] = CreateNiAutoNormalParticlesData;
	global_block_map["NiBinaryExtraData"] = CreateNiBinaryExtraData;
	global_block_map["NiBlendBoolInterpolator"] = CreateNiBlendBoolInterpolator;
	global_block_map["NiBlendFloatInterpolator"] = CreateNiBlendFloatInterpolator;
	global_block_map["NiBlendPoint3Interpolator"] = CreateNiBlendPoint3Interpolator;
	global_block_map["NiBlendTransformInterpolator"] = CreateNiBlendTransformInterpolator;
	global_block_map["NiBoneLODController"] = CreateNiBoneLODController;
	global_block_map["NiBoolData"] = CreateNiBoolData;
	global_block_map["NiBooleanExtraData"] = CreateNiBooleanExtraData;
	global_block_map["NiBoolInterpolator"] = CreateNiBoolInterpolator;
	global_block_map["NiBoolTimelineInterpolator"] = CreateNiBoolTimelineInterpolator;
	global_block_map["NiBSBoneLODController"] = CreateNiBSBoneLODController;
	global_block_map["NiBSplineBasisData"] = CreateNiBSplineBasisData;
	global_block_map["NiBSplineCompFloatInterpolator"] = CreateNiBSplineCompFloatInterpolator;
	global_block_map["NiBSplineCompPoint3Interpolator"] = CreateNiBSplineCompPoint3Interpolator;
	global_block_map["NiBSplineCompTransformInterpolator"] = CreateNiBSplineCompTransformInterpolator;
	global_block_map["NiBSplineData"] = CreateNiBSplineData;
	global_block_map["NiCamera"] = CreateNiCamera;
	global_block_map["NiCollisionData"] = CreateNiCollisionData;
	global_block_map["NiColorData"] = CreateNiColorData;
	global_block_map["NiColorExtraData"] = CreateNiColorExtraData;
	global_block_map["NiControllerManager"] = CreateNiControllerManager;
	global_block_map["NiControllerSequence"] = CreateNiControllerSequence;
	global_block_map["NiDefaultAVObjectPalette"] = CreateNiDefaultAVObjectPalette;
	global_block_map["NiDirectionalLight"] = CreateNiDirectionalLight;
	global_block_map["NiDitherProperty"] = CreateNiDitherProperty;
	global_block_map["NiFlipController"] = CreateNiFlipController;
	global_block_map["NiFloatData"] = CreateNiFloatData;
	global_block_map["NiFloatExtraData"] = CreateNiFloatExtraData;
	global_block_map["NiFloatExtraDataController"] = CreateNiFloatExtraDataController;
	global_block_map["NiFloatInterpolator"] = CreateNiFloatInterpolator;
	global_block_map["NiFloatsExtraData"] = CreateNiFloatsExtraData;
	global_block_map["NiFogProperty"] = CreateNiFogProperty;
	global_block_map["NiGeomMorpherController"] = CreateNiGeomMorpherController;
	global_block_map["NiGravity"] = CreateNiGravity;
	global_block_map["NiIntegerExtraData"] = CreateNiIntegerExtraData;
	global_block_map["NiIntegersExtraData"] = CreateNiIntegersExtraData;
	global_block_map["NiKeyframeController"] = CreateNiKeyframeController;
	global_block_map["BSKeyframeController"] = CreateBSKeyframeController;
	global_block_map["NiKeyframeData"] = CreateNiKeyframeData;
	global_block_map["NiLightColorController"] = CreateNiLightColorController;
	global_block_map["NiLightDimmerController"] = CreateNiLightDimmerController;
	global_block_map["NiLookAtController"] = CreateNiLookAtController;
	global_block_map["NiLookAtInterpolator"] = CreateNiLookAtInterpolator;
	global_block_map["NiMaterialColorController"] = CreateNiMaterialColorController;
	global_block_map["NiMaterialProperty"] = CreateNiMaterialProperty;
	global_block_map["NiMeshPSysData"] = CreateNiMeshPSysData;
	global_block_map["NiMorphData"] = CreateNiMorphData;
	global_block_map["NiMultiTargetTransformController"] = CreateNiMultiTargetTransformController;
	global_block_map["NiNode"] = CreateNiNode;
	global_block_map["AvoidNode"] = CreateAvoidNode;
	global_block_map["FxWidget"] = CreateFxWidget;
	global_block_map["FxButton"] = CreateFxButton;
	global_block_map["FxRadioButton"] = CreateFxRadioButton;
	global_block_map["NiBillboardNode"] = CreateNiBillboardNode;
	global_block_map["NiBSAnimationNode"] = CreateNiBSAnimationNode;
	global_block_map["NiBSParticleNode"] = CreateNiBSParticleNode;
	global_block_map["NiLODNode"] = CreateNiLODNode;
	global_block_map["NiPalette"] = CreateNiPalette;
	global_block_map["NiParticleBomb"] = CreateNiParticleBomb;
	global_block_map["NiParticleColorModifier"] = CreateNiParticleColorModifier;
	global_block_map["NiParticleGrowFade"] = CreateNiParticleGrowFade;
	global_block_map["NiParticleMeshModifier"] = CreateNiParticleMeshModifier;
	global_block_map["NiParticleRotation"] = CreateNiParticleRotation;
	global_block_map["NiParticles"] = CreateNiParticles;
	global_block_map["NiAutoNormalParticles"] = CreateNiAutoNormalParticles;
	global_block_map["NiParticleMeshes"] = CreateNiParticleMeshes;
	global_block_map["NiParticlesData"] = CreateNiParticlesData;
	global_block_map["NiParticleMeshesData"] = CreateNiParticleMeshesData;
	global_block_map["NiParticleSystem"] = CreateNiParticleSystem;
	global_block_map["NiMeshParticleSystem"] = CreateNiMeshParticleSystem;
	global_block_map["NiParticleSystemController"] = CreateNiParticleSystemController;
	global_block_map["NiBSPArrayController"] = CreateNiBSPArrayController;
	global_block_map["NiPathController"] = CreateNiPathController;
	global_block_map["NiPathInterpolator"] = CreateNiPathInterpolator;
	global_block_map["NiPixelData"] = CreateNiPixelData;
	global_block_map["NiPlanarCollider"] = CreateNiPlanarCollider;
	global_block_map["NiPoint3Interpolator"] = CreateNiPoint3Interpolator;
	global_block_map["NiPointLight"] = CreateNiPointLight;
	global_block_map["NiPosData"] = CreateNiPosData;
	global_block_map["NiPSysAgeDeathModifier"] = CreateNiPSysAgeDeathModifier;
	global_block_map["NiPSysBombModifier"] = CreateNiPSysBombModifier;
	global_block_map["NiPSysBoundUpdateModifier"] = CreateNiPSysBoundUpdateModifier;
	global_block_map["NiPSysBoxEmitter"] = CreateNiPSysBoxEmitter;
	global_block_map["NiPSysColliderManager"] = CreateNiPSysColliderManager;
	global_block_map["NiPSysColorModifier"] = CreateNiPSysColorModifier;
	global_block_map["NiPSysCylinderEmitter"] = CreateNiPSysCylinderEmitter;
	global_block_map["NiPSysData"] = CreateNiPSysData;
	global_block_map["NiPSysDragModifier"] = CreateNiPSysDragModifier;
	global_block_map["NiPSysEmitterCtlr"] = CreateNiPSysEmitterCtlr;
	global_block_map["NiPSysEmitterCtlrData"] = CreateNiPSysEmitterCtlrData;
	global_block_map["NiPSysEmitterDeclinationCtlr"] = CreateNiPSysEmitterDeclinationCtlr;
	global_block_map["NiPSysEmitterDeclinationVarCtlr"] = CreateNiPSysEmitterDeclinationVarCtlr;
	global_block_map["NiPSysEmitterInitialRadiusCtlr"] = CreateNiPSysEmitterInitialRadiusCtlr;
	global_block_map["NiPSysEmitterLifeSpanCtlr"] = CreateNiPSysEmitterLifeSpanCtlr;
	global_block_map["NiPSysEmitterSpeedCtlr"] = CreateNiPSysEmitterSpeedCtlr;
	global_block_map["NiPSysGravityModifier"] = CreateNiPSysGravityModifier;
	global_block_map["NiPSysGravityStrengthCtlr"] = CreateNiPSysGravityStrengthCtlr;
	global_block_map["NiPSysGrowFadeModifier"] = CreateNiPSysGrowFadeModifier;
	global_block_map["NiPSysMeshEmitter"] = CreateNiPSysMeshEmitter;
	global_block_map["NiPSysMeshUpdateModifier"] = CreateNiPSysMeshUpdateModifier;
	global_block_map["NiPSysModifierActiveCtlr"] = CreateNiPSysModifierActiveCtlr;
	global_block_map["NiPSysPlanarCollider"] = CreateNiPSysPlanarCollider;
	global_block_map["NiPSysPositionModifier"] = CreateNiPSysPositionModifier;
	global_block_map["NiPSysResetOnLoopCtlr"] = CreateNiPSysResetOnLoopCtlr;
	global_block_map["NiPSysRotationModifier"] = CreateNiPSysRotationModifier;
	global_block_map["NiPSysSpawnModifier"] = CreateNiPSysSpawnModifier;
	global_block_map["NiPSysSphereEmitter"] = CreateNiPSysSphereEmitter;
	global_block_map["NiPSysUpdateCtlr"] = CreateNiPSysUpdateCtlr;
	global_block_map["NiRangeLODData"] = CreateNiRangeLODData;
	global_block_map["NiScreenLODData"] = CreateNiScreenLODData;
	global_block_map["NiRotatingParticles"] = CreateNiRotatingParticles;
	global_block_map["NiRotatingParticlesData"] = CreateNiRotatingParticlesData;
	global_block_map["NiSequenceStreamHelper"] = CreateNiSequenceStreamHelper;
	global_block_map["NiShadeProperty"] = CreateNiShadeProperty;
	global_block_map["NiSkinData"] = CreateNiSkinData;
	global_block_map["NiSkinInstance"] = CreateNiSkinInstance;
	global_block_map["NiClodSkinInstance"] = CreateNiClodSkinInstance;
	global_block_map["NiSkinPartition"] = CreateNiSkinPartition;
	global_block_map["NiSourceTexture"] = CreateNiSourceTexture;
	global_block_map["NiSpecularProperty"] = CreateNiSpecularProperty;
	global_block_map["NiSphericalCollider"] = CreateNiSphericalCollider;
	global_block_map["NiSpotLight"] = CreateNiSpotLight;
	global_block_map["NiStencilProperty"] = CreateNiStencilProperty;
	global_block_map["NiStringExtraData"] = CreateNiStringExtraData;
	global_block_map["NiStringPalette"] = CreateNiStringPalette;
	global_block_map["NiStringsExtraData"] = CreateNiStringsExtraData;
	global_block_map["NiTextKeyExtraData"] = CreateNiTextKeyExtraData;
	global_block_map["NiTextureEffect"] = CreateNiTextureEffect;
	global_block_map["NiTextureTransformController"] = CreateNiTextureTransformController;
	global_block_map["NiTexturingProperty"] = CreateNiTexturingProperty;
	global_block_map["NiTransformController"] = CreateNiTransformController;
	global_block_map["NiTransformData"] = CreateNiTransformData;
	global_block_map["NiTransformInterpolator"] = CreateNiTransformInterpolator;
	global_block_map["NiTriShape"] = CreateNiTriShape;
	global_block_map["NiTriShapeData"] = CreateNiTriShapeData;
	global_block_map["NiTriStrips"] = CreateNiTriStrips;
	global_block_map["NiTriStripsData"] = CreateNiTriStripsData;
	global_block_map["NiClod"] = CreateNiClod;
	global_block_map["NiClodData"] = CreateNiClodData;
	global_block_map["NiUVController"] = CreateNiUVController;
	global_block_map["NiUVData"] = CreateNiUVData;
	global_block_map["NiVectorExtraData"] = CreateNiVectorExtraData;
	global_block_map["NiVertexColorProperty"] = CreateNiVertexColorProperty;
	global_block_map["NiVertWeightsExtraData"] = CreateNiVertWeightsExtraData;
	global_block_map["NiVisController"] = CreateNiVisController;
	global_block_map["NiVisData"] = CreateNiVisData;
	global_block_map["NiWireframeProperty"] = CreateNiWireframeProperty;
	global_block_map["NiZBufferProperty"] = CreateNiZBufferProperty;
	global_block_map["RootCollisionNode"] = CreateRootCollisionNode;
}
}
