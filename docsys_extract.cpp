/* Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above
     copyright notice, this list of conditions and the following
     disclaimer in the documentation and/or other materials provided
     with the distribution.

   * Neither the name of the NIF File Format Library and Tools
     project nor the names of its contributors may be used to endorse
     or promote products derived from this software without specific
     prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

#include "obj/NiObject.h"

typedef NiObject*(*blk_factory_func)();
extern map<string, blk_factory_func> global_block_map;

//--Factory Functions--//

#include "obj/AvoidNode.h"
NiObject * CreateAvoidNode() {
	return new AvoidNode;
}

#include "obj/FxButton.h"
NiObject * CreateFxButton() {
	return new FxButton;
}

#include "obj/FxRadioButton.h"
NiObject * CreateFxRadioButton() {
	return new FxRadioButton;
}

#include "obj/FxWidget.h"
NiObject * CreateFxWidget() {
	return new FxWidget;
}

#include "obj/NiAlphaController.h"
NiObject * CreateNiAlphaController() {
	return new NiAlphaController;
}

#include "obj/NiAlphaProperty.h"
NiObject * CreateNiAlphaProperty() {
	return new NiAlphaProperty;
}

#include "obj/NiAmbientLight.h"
NiObject * CreateNiAmbientLight() {
	return new NiAmbientLight;
}

#include "obj/NiAutoNormalParticles.h"
NiObject * CreateNiAutoNormalParticles() {
	return new NiAutoNormalParticles;
}

#include "obj/NiAutoNormalParticlesData.h"
NiObject * CreateNiAutoNormalParticlesData() {
	return new NiAutoNormalParticlesData;
}

#include "obj/NiBillboardNode.h"
NiObject * CreateNiBillboardNode() {
	return new NiBillboardNode;
}

#include "obj/NiBinaryExtraData.h"
NiObject * CreateNiBinaryExtraData() {
	return new NiBinaryExtraData;
}

#include "obj/NiBoneLODController.h"
NiObject * CreateNiBoneLODController() {
	return new NiBoneLODController;
}

#include "obj/NiBoolData.h"
NiObject * CreateNiBoolData() {
	return new NiBoolData;
}

#include "obj/NiBooleanExtraData.h"
NiObject * CreateNiBooleanExtraData() {
	return new NiBooleanExtraData;
}

#include "obj/NiBoolInterpolator.h"
NiObject * CreateNiBoolInterpolator() {
	return new NiBoolInterpolator;
}

#include "obj/NiBSAnimationNode.h"
NiObject * CreateNiBSAnimationNode() {
	return new NiBSAnimationNode;
}

#include "obj/NiBSPArrayController.h"
NiObject * CreateNiBSPArrayController() {
	return new NiBSPArrayController;
}

#include "obj/NiBSParticleNode.h"
NiObject * CreateNiBSParticleNode() {
	return new NiBSParticleNode;
}

#include "obj/NiBSplineBasisData.h"
NiObject * CreateNiBSplineBasisData() {
	return new NiBSplineBasisData;
}

#include "obj/NiBSplineCompFloatInterpolator.h"
NiObject * CreateNiBSplineCompFloatInterpolator() {
	return new NiBSplineCompFloatInterpolator;
}

#include "obj/NiBSplineCompPoint3Interpolator.h"
NiObject * CreateNiBSplineCompPoint3Interpolator() {
	return new NiBSplineCompPoint3Interpolator;
}

#include "obj/NiBSplineCompTransformInterpolator.h"
NiObject * CreateNiBSplineCompTransformInterpolator() {
	return new NiBSplineCompTransformInterpolator;
}

#include "obj/NiBSplineData.h"
NiObject * CreateNiBSplineData() {
	return new NiBSplineData;
}

#include "obj/NiCamera.h"
NiObject * CreateNiCamera() {
	return new NiCamera;
}

#include "obj/NiCollisionData.h"
NiObject * CreateNiCollisionData() {
	return new NiCollisionData;
}

#include "obj/NiColorData.h"
NiObject * CreateNiColorData() {
	return new NiColorData;
}

#include "obj/NiColorExtraData.h"
NiObject * CreateNiColorExtraData() {
	return new NiColorExtraData;
}

#include "obj/NiControllerSequence.h"
NiObject * CreateNiControllerSequence() {
	return new NiControllerSequence;
}

#include "obj/NiDirectionalLight.h"
NiObject * CreateNiDirectionalLight() {
	return new NiDirectionalLight;
}

#include "obj/NiDitherProperty.h"
NiObject * CreateNiDitherProperty() {
	return new NiDitherProperty;
}

#include "obj/NiFlipController.h"
NiObject * CreateNiFlipController() {
	return new NiFlipController;
}

#include "obj/NiFloatData.h"
NiObject * CreateNiFloatData() {
	return new NiFloatData;
}

#include "obj/NiFloatExtraData.h"
NiObject * CreateNiFloatExtraData() {
	return new NiFloatExtraData;
}

#include "obj/NiFloatExtraDataController.h"
NiObject * CreateNiFloatExtraDataController() {
	return new NiFloatExtraDataController;
}

#include "obj/NiFloatInterpolator.h"
NiObject * CreateNiFloatInterpolator() {
	return new NiFloatInterpolator;
}

#include "obj/NiFloatsExtraData.h"
NiObject * CreateNiFloatsExtraData() {
	return new NiFloatsExtraData;
}

#include "obj/NiFogProperty.h"
NiObject * CreateNiFogProperty() {
	return new NiFogProperty;
}

#include "obj/NiGeomMorpherController.h"
NiObject * CreateNiGeomMorpherController() {
	return new NiGeomMorpherController;
}

#include "obj/NiGravity.h"
NiObject * CreateNiGravity() {
	return new NiGravity;
}

#include "obj/NiIntegerExtraData.h"
NiObject * CreateNiIntegerExtraData() {
	return new NiIntegerExtraData;
}

#include "obj/NiIntegersExtraData.h"
NiObject * CreateNiIntegersExtraData() {
	return new NiIntegersExtraData;
}

#include "obj/NiKeyframeController.h"
NiObject * CreateNiKeyframeController() {
	return new NiKeyframeController;
}

#include "obj/NiKeyframeData.h"
NiObject * CreateNiKeyframeData() {
	return new NiKeyframeData;
}

#include "obj/NiLightColorController.h"
NiObject * CreateNiLightColorController() {
	return new NiLightColorController;
}

#include "obj/NiLightDimmerController.h"
NiObject * CreateNiLightDimmerController() {
	return new NiLightDimmerController;
}

#include "obj/NiLODNode.h"
NiObject * CreateNiLODNode() {
	return new NiLODNode;
}

#include "obj/NiLookAtController.h"
NiObject * CreateNiLookAtController() {
	return new NiLookAtController;
}

#include "obj/NiLookAtInterpolator.h"
NiObject * CreateNiLookAtInterpolator() {
	return new NiLookAtInterpolator;
}

#include "obj/NiMaterialColorController.h"
NiObject * CreateNiMaterialColorController() {
	return new NiMaterialColorController;
}

#include "obj/NiMaterialProperty.h"
NiObject * CreateNiMaterialProperty() {
	return new NiMaterialProperty;
}

#include "obj/NiMeshParticleSystem.h"
NiObject * CreateNiMeshParticleSystem() {
	return new NiMeshParticleSystem;
}

#include "obj/NiMeshPSysData.h"
NiObject * CreateNiMeshPSysData() {
	return new NiMeshPSysData;
}

#include "obj/NiMorphData.h"
NiObject * CreateNiMorphData() {
	return new NiMorphData;
}

#include "obj/NiMultiTargetTransformController.h"
NiObject * CreateNiMultiTargetTransformController() {
	return new NiMultiTargetTransformController;
}

#include "obj/NiNode.h"
NiObject * CreateNiNode() {
	return new NiNode;
}

#include "obj/NiPalette.h"
NiObject * CreateNiPalette() {
	return new NiPalette;
}

#include "obj/NiParticleBomb.h"
NiObject * CreateNiParticleBomb() {
	return new NiParticleBomb;
}

#include "obj/NiParticleColorModifier.h"
NiObject * CreateNiParticleColorModifier() {
	return new NiParticleColorModifier;
}

#include "obj/NiParticleGrowFade.h"
NiObject * CreateNiParticleGrowFade() {
	return new NiParticleGrowFade;
}

#include "obj/NiParticleMeshes.h"
NiObject * CreateNiParticleMeshes() {
	return new NiParticleMeshes;
}

#include "obj/NiParticleMeshesData.h"
NiObject * CreateNiParticleMeshesData() {
	return new NiParticleMeshesData;
}

#include "obj/NiParticleMeshModifier.h"
NiObject * CreateNiParticleMeshModifier() {
	return new NiParticleMeshModifier;
}

#include "obj/NiParticleRotation.h"
NiObject * CreateNiParticleRotation() {
	return new NiParticleRotation;
}

#include "obj/NiParticles.h"
NiObject * CreateNiParticles() {
	return new NiParticles;
}

#include "obj/NiParticlesData.h"
NiObject * CreateNiParticlesData() {
	return new NiParticlesData;
}

#include "obj/NiParticleSystem.h"
NiObject * CreateNiParticleSystem() {
	return new NiParticleSystem;
}

#include "obj/NiParticleSystemController.h"
NiObject * CreateNiParticleSystemController() {
	return new NiParticleSystemController;
}

#include "obj/NiPathController.h"
NiObject * CreateNiPathController() {
	return new NiPathController;
}

#include "obj/NiPixelData.h"
NiObject * CreateNiPixelData() {
	return new NiPixelData;
}

#include "obj/NiPlanarCollider.h"
NiObject * CreateNiPlanarCollider() {
	return new NiPlanarCollider;
}

#include "obj/NiPoint3Interpolator.h"
NiObject * CreateNiPoint3Interpolator() {
	return new NiPoint3Interpolator;
}

#include "obj/NiPointLight.h"
NiObject * CreateNiPointLight() {
	return new NiPointLight;
}

#include "obj/NiPosData.h"
NiObject * CreateNiPosData() {
	return new NiPosData;
}

#include "obj/NiPSysAgeDeathModifier.h"
NiObject * CreateNiPSysAgeDeathModifier() {
	return new NiPSysAgeDeathModifier;
}

#include "obj/NiPSysBoundUpdateModifier.h"
NiObject * CreateNiPSysBoundUpdateModifier() {
	return new NiPSysBoundUpdateModifier;
}

#include "obj/NiPSysBoxEmitter.h"
NiObject * CreateNiPSysBoxEmitter() {
	return new NiPSysBoxEmitter;
}

#include "obj/NiPSysColliderManager.h"
NiObject * CreateNiPSysColliderManager() {
	return new NiPSysColliderManager;
}

#include "obj/NiPSysColorModifier.h"
NiObject * CreateNiPSysColorModifier() {
	return new NiPSysColorModifier;
}

#include "obj/NiPSysCylinderEmitter.h"
NiObject * CreateNiPSysCylinderEmitter() {
	return new NiPSysCylinderEmitter;
}

#include "obj/NiPSysData.h"
NiObject * CreateNiPSysData() {
	return new NiPSysData;
}

#include "obj/NiPSysEmitterCtlr.h"
NiObject * CreateNiPSysEmitterCtlr() {
	return new NiPSysEmitterCtlr;
}

#include "obj/NiPSysEmitterCtlrData.h"
NiObject * CreateNiPSysEmitterCtlrData() {
	return new NiPSysEmitterCtlrData;
}

#include "obj/NiPSysEmitterDeclinationVarCtlr.h"
NiObject * CreateNiPSysEmitterDeclinationVarCtlr() {
	return new NiPSysEmitterDeclinationVarCtlr;
}

#include "obj/NiPSysEmitterInitialRadiusCtlr.h"
NiObject * CreateNiPSysEmitterInitialRadiusCtlr() {
	return new NiPSysEmitterInitialRadiusCtlr;
}

#include "obj/NiPSysGravityModifier.h"
NiObject * CreateNiPSysGravityModifier() {
	return new NiPSysGravityModifier;
}

#include "obj/NiPSysGrowFadeModifier.h"
NiObject * CreateNiPSysGrowFadeModifier() {
	return new NiPSysGrowFadeModifier;
}

#include "obj/NiPSysMeshUpdateModifier.h"
NiObject * CreateNiPSysMeshUpdateModifier() {
	return new NiPSysMeshUpdateModifier;
}

#include "obj/NiPSysPlanarCollider.h"
NiObject * CreateNiPSysPlanarCollider() {
	return new NiPSysPlanarCollider;
}

#include "obj/NiPSysPositionModifier.h"
NiObject * CreateNiPSysPositionModifier() {
	return new NiPSysPositionModifier;
}

#include "obj/NiPSysResetOnLoopCtlr.h"
NiObject * CreateNiPSysResetOnLoopCtlr() {
	return new NiPSysResetOnLoopCtlr;
}

#include "obj/NiPSysRotationModifier.h"
NiObject * CreateNiPSysRotationModifier() {
	return new NiPSysRotationModifier;
}

#include "obj/NiPSysSpawnModifier.h"
NiObject * CreateNiPSysSpawnModifier() {
	return new NiPSysSpawnModifier;
}

#include "obj/NiPSysSphereEmitter.h"
NiObject * CreateNiPSysSphereEmitter() {
	return new NiPSysSphereEmitter;
}

#include "obj/NiPSysUpdateCtlr.h"
NiObject * CreateNiPSysUpdateCtlr() {
	return new NiPSysUpdateCtlr;
}

#include "obj/NiRangeLODData.h"
NiObject * CreateNiRangeLODData() {
	return new NiRangeLODData;
}

#include "obj/NiRotatingParticles.h"
NiObject * CreateNiRotatingParticles() {
	return new NiRotatingParticles;
}

#include "obj/NiRotatingParticlesData.h"
NiObject * CreateNiRotatingParticlesData() {
	return new NiRotatingParticlesData;
}

#include "obj/NiScreenLODData.h"
NiObject * CreateNiScreenLODData() {
	return new NiScreenLODData;
}

#include "obj/NiSequenceStreamHelper.h"
NiObject * CreateNiSequenceStreamHelper() {
	return new NiSequenceStreamHelper;
}

#include "obj/NiShadeProperty.h"
NiObject * CreateNiShadeProperty() {
	return new NiShadeProperty;
}

#include "obj/NiSkinData.h"
NiObject * CreateNiSkinData() {
	return new NiSkinData;
}

#include "obj/NiSkinInstance.h"
NiObject * CreateNiSkinInstance() {
	return new NiSkinInstance;
}

#include "obj/NiSkinPartition.h"
NiObject * CreateNiSkinPartition() {
	return new NiSkinPartition;
}

#include "obj/NiSourceTexture.h"
NiObject * CreateNiSourceTexture() {
	return new NiSourceTexture;
}

#include "obj/NiSpecularProperty.h"
NiObject * CreateNiSpecularProperty() {
	return new NiSpecularProperty;
}

#include "obj/NiSphericalCollider.h"
NiObject * CreateNiSphericalCollider() {
	return new NiSphericalCollider;
}

#include "obj/NiSpotLight.h"
NiObject * CreateNiSpotLight() {
	return new NiSpotLight;
}

#include "obj/NiStencilProperty.h"
NiObject * CreateNiStencilProperty() {
	return new NiStencilProperty;
}

#include "obj/NiStringExtraData.h"
NiObject * CreateNiStringExtraData() {
	return new NiStringExtraData;
}

#include "obj/NiStringPalette.h"
NiObject * CreateNiStringPalette() {
	return new NiStringPalette;
}

#include "obj/NiStringsExtraData.h"
NiObject * CreateNiStringsExtraData() {
	return new NiStringsExtraData;
}

#include "obj/NiTextKeyExtraData.h"
NiObject * CreateNiTextKeyExtraData() {
	return new NiTextKeyExtraData;
}

#include "obj/NiTextureEffect.h"
NiObject * CreateNiTextureEffect() {
	return new NiTextureEffect;
}

#include "obj/NiTextureTransformController.h"
NiObject * CreateNiTextureTransformController() {
	return new NiTextureTransformController;
}

#include "obj/NiTexturingProperty.h"
NiObject * CreateNiTexturingProperty() {
	return new NiTexturingProperty;
}

#include "obj/NiTransformController.h"
NiObject * CreateNiTransformController() {
	return new NiTransformController;
}

#include "obj/NiTransformData.h"
NiObject * CreateNiTransformData() {
	return new NiTransformData;
}

#include "obj/NiTransformInterpolator.h"
NiObject * CreateNiTransformInterpolator() {
	return new NiTransformInterpolator;
}

#include "obj/NiTriShape.h"
NiObject * CreateNiTriShape() {
	return new NiTriShape;
}

#include "obj/NiTriShapeData.h"
NiObject * CreateNiTriShapeData() {
	return new NiTriShapeData;
}

#include "obj/NiTriStrips.h"
NiObject * CreateNiTriStrips() {
	return new NiTriStrips;
}

#include "obj/NiTriStripsData.h"
NiObject * CreateNiTriStripsData() {
	return new NiTriStripsData;
}

#include "obj/NiUVController.h"
NiObject * CreateNiUVController() {
	return new NiUVController;
}

#include "obj/NiUVData.h"
NiObject * CreateNiUVData() {
	return new NiUVData;
}

#include "obj/NiVectorExtraData.h"
NiObject * CreateNiVectorExtraData() {
	return new NiVectorExtraData;
}

#include "obj/NiVertexColorProperty.h"
NiObject * CreateNiVertexColorProperty() {
	return new NiVertexColorProperty;
}

#include "obj/NiVertWeightsExtraData.h"
NiObject * CreateNiVertWeightsExtraData() {
	return new NiVertWeightsExtraData;
}

#include "obj/NiVisController.h"
NiObject * CreateNiVisController() {
	return new NiVisController;
}

#include "obj/NiVisData.h"
NiObject * CreateNiVisData() {
	return new NiVisData;
}

#include "obj/NiWireframeProperty.h"
NiObject * CreateNiWireframeProperty() {
	return new NiWireframeProperty;
}

#include "obj/NiZBufferProperty.h"
NiObject * CreateNiZBufferProperty() {
	return new NiZBufferProperty;
}

#include "obj/RootCollisionNode.h"
NiObject * CreateRootCollisionNode() {
	return new RootCollisionNode;
}

//This function registers the factory functions with global_block_map which is used by CreateBlock
void RegisterBlockFactories () {
	global_block_map["AvoidNode"] = CreateAvoidNode;
	global_block_map["FxButton"] = CreateFxButton;
	global_block_map["FxRadioButton"] = CreateFxRadioButton;
	global_block_map["FxWidget"] = CreateFxWidget;
	global_block_map["NiAlphaController"] = CreateNiAlphaController;
	global_block_map["NiAlphaProperty"] = CreateNiAlphaProperty;
	global_block_map["NiAmbientLight"] = CreateNiAmbientLight;
	global_block_map["NiAutoNormalParticles"] = CreateNiAutoNormalParticles;
	global_block_map["NiAutoNormalParticlesData"] = CreateNiAutoNormalParticlesData;
	global_block_map["NiBillboardNode"] = CreateNiBillboardNode;
	global_block_map["NiBinaryExtraData"] = CreateNiBinaryExtraData;
	global_block_map["NiBoneLODController"] = CreateNiBoneLODController;
	global_block_map["NiBoolData"] = CreateNiBoolData;
	global_block_map["NiBooleanExtraData"] = CreateNiBooleanExtraData;
	global_block_map["NiBoolInterpolator"] = CreateNiBoolInterpolator;
	global_block_map["NiBSAnimationNode"] = CreateNiBSAnimationNode;
	global_block_map["NiBSPArrayController"] = CreateNiBSPArrayController;
	global_block_map["NiBSParticleNode"] = CreateNiBSParticleNode;
	global_block_map["NiBSplineBasisData"] = CreateNiBSplineBasisData;
	global_block_map["NiBSplineCompFloatInterpolator"] = CreateNiBSplineCompFloatInterpolator;
	global_block_map["NiBSplineCompPoint3Interpolator"] = CreateNiBSplineCompPoint3Interpolator;
	global_block_map["NiBSplineCompTransformInterpolator"] = CreateNiBSplineCompTransformInterpolator;
	global_block_map["NiBSplineData"] = CreateNiBSplineData;
	global_block_map["NiCamera"] = CreateNiCamera;
	global_block_map["NiCollisionData"] = CreateNiCollisionData;
	global_block_map["NiColorData"] = CreateNiColorData;
	global_block_map["NiColorExtraData"] = CreateNiColorExtraData;
	global_block_map["NiControllerSequence"] = CreateNiControllerSequence;
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
	global_block_map["NiKeyframeData"] = CreateNiKeyframeData;
	global_block_map["NiLightColorController"] = CreateNiLightColorController;
	global_block_map["NiLightDimmerController"] = CreateNiLightDimmerController;
	global_block_map["NiLODNode"] = CreateNiLODNode;
	global_block_map["NiLookAtController"] = CreateNiLookAtController;
	global_block_map["NiLookAtInterpolator"] = CreateNiLookAtInterpolator;
	global_block_map["NiMaterialColorController"] = CreateNiMaterialColorController;
	global_block_map["NiMaterialProperty"] = CreateNiMaterialProperty;
	global_block_map["NiMeshParticleSystem"] = CreateNiMeshParticleSystem;
	global_block_map["NiMeshPSysData"] = CreateNiMeshPSysData;
	global_block_map["NiMorphData"] = CreateNiMorphData;
	global_block_map["NiMultiTargetTransformController"] = CreateNiMultiTargetTransformController;
	global_block_map["NiNode"] = CreateNiNode;
	global_block_map["NiPalette"] = CreateNiPalette;
	global_block_map["NiParticleBomb"] = CreateNiParticleBomb;
	global_block_map["NiParticleColorModifier"] = CreateNiParticleColorModifier;
	global_block_map["NiParticleGrowFade"] = CreateNiParticleGrowFade;
	global_block_map["NiParticleMeshes"] = CreateNiParticleMeshes;
	global_block_map["NiParticleMeshesData"] = CreateNiParticleMeshesData;
	global_block_map["NiParticleMeshModifier"] = CreateNiParticleMeshModifier;
	global_block_map["NiParticleRotation"] = CreateNiParticleRotation;
	global_block_map["NiParticles"] = CreateNiParticles;
	global_block_map["NiParticlesData"] = CreateNiParticlesData;
	global_block_map["NiParticleSystem"] = CreateNiParticleSystem;
	global_block_map["NiParticleSystemController"] = CreateNiParticleSystemController;
	global_block_map["NiPathController"] = CreateNiPathController;
	global_block_map["NiPixelData"] = CreateNiPixelData;
	global_block_map["NiPlanarCollider"] = CreateNiPlanarCollider;
	global_block_map["NiPoint3Interpolator"] = CreateNiPoint3Interpolator;
	global_block_map["NiPointLight"] = CreateNiPointLight;
	global_block_map["NiPosData"] = CreateNiPosData;
	global_block_map["NiPSysAgeDeathModifier"] = CreateNiPSysAgeDeathModifier;
	global_block_map["NiPSysBoundUpdateModifier"] = CreateNiPSysBoundUpdateModifier;
	global_block_map["NiPSysBoxEmitter"] = CreateNiPSysBoxEmitter;
	global_block_map["NiPSysColliderManager"] = CreateNiPSysColliderManager;
	global_block_map["NiPSysColorModifier"] = CreateNiPSysColorModifier;
	global_block_map["NiPSysCylinderEmitter"] = CreateNiPSysCylinderEmitter;
	global_block_map["NiPSysData"] = CreateNiPSysData;
	global_block_map["NiPSysEmitterCtlr"] = CreateNiPSysEmitterCtlr;
	global_block_map["NiPSysEmitterCtlrData"] = CreateNiPSysEmitterCtlrData;
	global_block_map["NiPSysEmitterDeclinationVarCtlr"] = CreateNiPSysEmitterDeclinationVarCtlr;
	global_block_map["NiPSysEmitterInitialRadiusCtlr"] = CreateNiPSysEmitterInitialRadiusCtlr;
	global_block_map["NiPSysGravityModifier"] = CreateNiPSysGravityModifier;
	global_block_map["NiPSysGrowFadeModifier"] = CreateNiPSysGrowFadeModifier;
	global_block_map["NiPSysMeshUpdateModifier"] = CreateNiPSysMeshUpdateModifier;
	global_block_map["NiPSysPlanarCollider"] = CreateNiPSysPlanarCollider;
	global_block_map["NiPSysPositionModifier"] = CreateNiPSysPositionModifier;
	global_block_map["NiPSysResetOnLoopCtlr"] = CreateNiPSysResetOnLoopCtlr;
	global_block_map["NiPSysRotationModifier"] = CreateNiPSysRotationModifier;
	global_block_map["NiPSysSpawnModifier"] = CreateNiPSysSpawnModifier;
	global_block_map["NiPSysSphereEmitter"] = CreateNiPSysSphereEmitter;
	global_block_map["NiPSysUpdateCtlr"] = CreateNiPSysUpdateCtlr;
	global_block_map["NiRangeLODData"] = CreateNiRangeLODData;
	global_block_map["NiRotatingParticles"] = CreateNiRotatingParticles;
	global_block_map["NiRotatingParticlesData"] = CreateNiRotatingParticlesData;
	global_block_map["NiScreenLODData"] = CreateNiScreenLODData;
	global_block_map["NiSequenceStreamHelper"] = CreateNiSequenceStreamHelper;
	global_block_map["NiShadeProperty"] = CreateNiShadeProperty;
	global_block_map["NiSkinData"] = CreateNiSkinData;
	global_block_map["NiSkinInstance"] = CreateNiSkinInstance;
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