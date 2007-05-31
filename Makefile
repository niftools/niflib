#
# Simple Makefile for niflib
# 
# 
# 
#
CC     		= gcc
CXX 		= g++
# -g<1-3> (ex: -g3) for debugging extra's may or may not be compatible with the broad spectrum of gcc features included with the various 
# -O series of options 
#
# Please Read: http://gcc.gnu.org/onlinedocs/gcc-4.1.1/gcc/Debugging-Options.html#Debugging-Options for more info on GCC debugging options
DEBUGGING	=
#
# CFLAGS 		= -O2 -Wall -Wextra -fPIC -Wunreachable-code $(DEBUGGING)
# -Wextra and -Wunreachable-code can be useful and can also be spammy... 
#
# IF you don't know what -02 is, read here: http://gcc.gnu.org/onlinedocs/gcc-4.1.1/gcc/Optimize-Options.html#Optimize-Options
#
# IF you want Processor enahncements for _YOUR_ processor compiled into the lib,
# you can try -mtune OR the more aggressive -march. Keep in mind, that enhancing it for a pentium4 
# will potentially cause it to break when run on non-pentium4's.
# NOTE: -march inherits -mtune features.
# Example: -march=k8 would generate enhancements for the k8 family (opterons and some athlons).or -march=pentium4 for a pentium4
# For more info read this: http://gcc.gnu.org/onlinedocs/gcc-4.1.1/gcc/i386-and-x86_002d64-Options.html#i386-and-x86_002d64-Options
#
CFLAGS 		= -O2 -Wall -fPIC $(DEBUGGING) -Iinclude
CXXFLAGS	= $(CFLAGS)
#IT should find the libs used, but if it doesn't specify here. Ex: -lm for libm.so.<whatever>
LIBS		=
L_FLAGS 	= -shared -Wl,-soname,libniflib.so.0
VERSION		= 0.7
VERSION_MIN	= 0.7
TARGET  	= libniflib.so.0$(VERSION)

TARGETA       = libniflib.a
TARGETD       = libniflib.so.0$(VERSION)
TARGET0       = libniflib.so
TARGET1       = libniflib.so.0
TARGET2       = libniflib.so.0.$(VERSION_MIN)





OBJ_FILES = src/ComplexShape.o \
           src/kfm.o \
           src/MatTexCollection.o \
           src/niflib.o \
           src/NIF_IO.o \
           src/nif_math.o \
           src/ObjectRegistry.o \
           src/pch.o \
           src/Type.o \
           src/obj/AParticleModifier.o \
           src/obj/AvoidNode.o \
           src/obj/bhkBlendCollisionObject.o \
           src/obj/bhkBlendController.o \
           src/obj/bhkBoxShape.o \
           src/obj/bhkBvTreeShape.o \
           src/obj/bhkCapsuleShape.o \
           src/obj/bhkCollisionObject.o \
           src/obj/bhkConstraint.o \
           src/obj/bhkConvexShape.o \
           src/obj/bhkConvexTransformShape.o \
           src/obj/bhkConvexVerticesShape.o \
           src/obj/bhkEntity.o \
           src/obj/bhkHingeConstraint.o \
           src/obj/bhkLimitedHingeConstraint.o \
           src/obj/bhkListShape.o \
           src/obj/bhkMalleableConstraint.o \
           src/obj/bhkMoppBvTreeShape.o \
           src/obj/bhkMultiSphereShape.o \
           src/obj/bhkNiCollisionObject.o \
           src/obj/bhkNiTriStripsShape.o \
           src/obj/bhkPackedNiTriStripsShape.o \
           src/obj/bhkPCollisionObject.o \
           src/obj/bhkPhantom.o \
           src/obj/bhkPrismaticConstraint.o \
           src/obj/bhkRagdollConstraint.o \
           src/obj/bhkRefObject.o \
           src/obj/bhkRigidBody.o \
           src/obj/bhkRigidBodyT.o \
           src/obj/bhkSerializable.o \
           src/obj/bhkShape.o \
           src/obj/bhkShapeCollection.o \
           src/obj/bhkShapePhantom.o \
           src/obj/bhkSimpleShapePhantom.o \
           src/obj/bhkSPCollisionObject.o \
           src/obj/bhkSphereRepShape.o \
           src/obj/bhkSphereShape.o \
           src/obj/bhkStiffSpringConstraint.o \
           src/obj/bhkTransformShape.o \
           src/obj/bhkWorldObject.o \
           src/obj/BSBound.o \
           src/obj/BSFurnitureMarker.o \
           src/obj/BSKeyframeController.o \
           src/obj/BSParentVelocityModifier.o \
           src/obj/BSPSysArrayEmitter.o \
           src/obj/BSWindModifier.o \
           src/obj/BSXFlags.o \
           src/obj/FxButton.o \
           src/obj/FxRadioButton.o \
           src/obj/FxWidget.o \
           src/obj/hkPackedNiTriStripsData.o \
           src/obj/NiAlphaController.o \
           src/obj/NiAlphaProperty.o \
           src/obj/NiAmbientLight.o \
           src/obj/NiAutoNormalParticles.o \
           src/obj/NiAutoNormalParticlesData.o \
           src/obj/NiAVObject.o \
           src/obj/NiAVObjectPalette.o \
           src/obj/NiBillboardNode.o \
           src/obj/NiBinaryExtraData.o \
           src/obj/NiBinaryVoxelData.o \
           src/obj/NiBinaryVoxelExtraData.o \
           src/obj/NiBlendBoolInterpolator.o \
           src/obj/NiBlendFloatInterpolator.o \
           src/obj/NiBlendInterpolator.o \
           src/obj/NiBlendPoint3Interpolator.o \
           src/obj/NiBlendTransformInterpolator.o \
           src/obj/NiBone.o \
           src/obj/NiBoneLODController.o \
           src/obj/NiBoolData.o \
           src/obj/NiBooleanExtraData.o \
           src/obj/NiBoolInterpController.o \
           src/obj/NiBoolInterpolator.o \
           src/obj/NiBoolTimelineInterpolator.o \
           src/obj/NiBSAnimationNode.o \
           src/obj/NiBSBoneLODController.o \
           src/obj/NiBSPArrayController.o \
           src/obj/NiBSParticleNode.o \
           src/obj/NiBSplineBasisData.o \
           src/obj/NiBSplineCompFloatInterpolator.o \
           src/obj/NiBSplineCompPoint3Interpolator.o \
           src/obj/NiBSplineCompTransformInterpolator.o \
           src/obj/NiBSplineData.o \
           src/obj/NiBSplineFloatInterpolator.o \
           src/obj/NiBSplineInterpolator.o \
           src/obj/NiBSplinePoint3Interpolator.o \
           src/obj/NiBSplineTransformInterpolator.o \
           src/obj/NiCamera.o \
           src/obj/NiClod.o \
           src/obj/NiClodData.o \
           src/obj/NiClodSkinInstance.o \
           src/obj/NiCollisionData.o \
           src/obj/NiCollisionObject.o \
           src/obj/NiColorData.o \
           src/obj/NiColorExtraData.o \
           src/obj/NiControllerManager.o \
           src/obj/NiControllerSequence.o \
           src/obj/NiDefaultAVObjectPalette.o \
           src/obj/NiDirectionalLight.o \
           src/obj/NiDitherProperty.o \
           src/obj/NiDynamicEffect.o \
           src/obj/NiExtraData.o \
           src/obj/NiExtraDataController.o \
           src/obj/NiFlipController.o \
           src/obj/NiFloatData.o \
           src/obj/NiFloatExtraData.o \
           src/obj/NiFloatExtraDataController.o \
           src/obj/NiFloatInterpController.o \
           src/obj/NiFloatInterpolator.o \
           src/obj/NiFloatsExtraData.o \
           src/obj/NiFogProperty.o \
           src/obj/NiGeometry.o \
           src/obj/NiGeometryData.o \
           src/obj/NiGeomMorpherController.o \
           src/obj/NiGravity.o \
           src/obj/NiImage.o \
           src/obj/NiIntegerExtraData.o \
           src/obj/NiIntegersExtraData.o \
           src/obj/NiInterpController.o \
           src/obj/NiInterpolator.o \
           src/obj/NiKeyBasedInterpolator.o \
           src/obj/NiKeyframeController.o \
           src/obj/NiKeyframeData.o \
           src/obj/NiLight.o \
           src/obj/NiLightColorController.o \
           src/obj/NiLightDimmerController.o \
           src/obj/NiLODData.o \
           src/obj/NiLODNode.o \
           src/obj/NiLookAtController.o \
           src/obj/NiLookAtInterpolator.o \
           src/obj/NiMaterialColorController.o \
           src/obj/NiMaterialProperty.o \
           src/obj/NiMeshParticleSystem.o \
           src/obj/NiMeshPSysData.o \
           src/obj/NiMorphData.o \
           src/obj/NiMultiTargetTransformController.o \
           src/obj/NiMultiTextureProperty.o \
           src/obj/NiNode.o \
           src/obj/NiObject.o \
           src/obj/NiObjectNET.o \
           src/obj/NiPalette.o \
           src/obj/NiParticleBomb.o \
           src/obj/NiParticleColorModifier.o \
           src/obj/NiParticleGrowFade.o \
           src/obj/NiParticleMeshes.o \
           src/obj/NiParticleMeshesData.o \
           src/obj/NiParticleMeshModifier.o \
           src/obj/NiParticleRotation.o \
           src/obj/NiParticles.o \
           src/obj/NiParticlesData.o \
           src/obj/NiParticleSystem.o \
           src/obj/NiParticleSystemController.o \
           src/obj/NiPathController.o \
           src/obj/NiPathInterpolator.o \
           src/obj/NiPixelData.o \
           src/obj/NiPlanarCollider.o \
           src/obj/NiPoint3InterpController.o \
           src/obj/NiPoint3Interpolator.o \
           src/obj/NiPointLight.o \
           src/obj/NiPosData.o \
           src/obj/NiProperty.o \
           src/obj/NiPSysAgeDeathModifier.o \
           src/obj/NiPSysBombModifier.o \
           src/obj/NiPSysBoundUpdateModifier.o \
           src/obj/NiPSysBoxEmitter.o \
           src/obj/NiPSysCollider.o \
           src/obj/NiPSysColliderManager.o \
           src/obj/NiPSysColorModifier.o \
           src/obj/NiPSysCylinderEmitter.o \
           src/obj/NiPSysData.o \
           src/obj/NiPSysDragModifier.o \
           src/obj/NiPSysEmitter.o \
           src/obj/NiPSysEmitterCtlr.o \
           src/obj/NiPSysEmitterCtlrData.o \
           src/obj/NiPSysEmitterDeclinationCtlr.o \
           src/obj/NiPSysEmitterDeclinationVarCtlr.o \
           src/obj/NiPSysEmitterInitialRadiusCtlr.o \
           src/obj/NiPSysEmitterLifeSpanCtlr.o \
           src/obj/NiPSysEmitterSpeedCtlr.o \
           src/obj/NiPSysGravityModifier.o \
           src/obj/NiPSysGravityStrengthCtlr.o \
           src/obj/NiPSysGrowFadeModifier.o \
           src/obj/NiPSysMeshEmitter.o \
           src/obj/NiPSysMeshUpdateModifier.o \
           src/obj/NiPSysModifier.o \
           src/obj/NiPSysModifierActiveCtlr.o \
           src/obj/NiPSysModifierBoolCtlr.o \
           src/obj/NiPSysModifierCtlr.o \
           src/obj/NiPSysModifierFloatCtlr.o \
           src/obj/NiPSysPlanarCollider.o \
           src/obj/NiPSysPositionModifier.o \
           src/obj/NiPSysResetOnLoopCtlr.o \
           src/obj/NiPSysRotationModifier.o \
           src/obj/NiPSysSpawnModifier.o \
           src/obj/NiPSysSphereEmitter.o \
           src/obj/NiPSysSphericalCollider.o \
           src/obj/NiPSysUpdateCtlr.o \
           src/obj/NiPSysVolumeEmitter.o \
           src/obj/NiRangeLODData.o \
           src/obj/NiRawImageData.o \
           src/obj/NiRollController.o \
           src/obj/NiRotatingParticles.o \
           src/obj/NiRotatingParticlesData.o \
           src/obj/NiScreenLODData.o \
           src/obj/NiSequence.o \
           src/obj/NiSequenceStreamHelper.o \
           src/obj/NiShadeProperty.o \
           src/obj/NiSingleInterpController.o \
           src/obj/NiSkinData.o \
           src/obj/NiSkinInstance.o \
           src/obj/NiSkinPartition.o \
           src/obj/NiSourceTexture.o \
           src/obj/NiSpecularProperty.o \
           src/obj/NiSphericalCollider.o \
           src/obj/NiSpotLight.o \
           src/obj/NiStencilProperty.o \
           src/obj/NiStringExtraData.o \
           src/obj/NiStringPalette.o \
           src/obj/NiStringsExtraData.o \
           src/obj/NiSwitchNode.o \
           src/obj/NiTextKeyExtraData.o \
           src/obj/NiTexture.o \
           src/obj/NiTextureEffect.o \
           src/obj/NiTextureModeProperty.o \
           src/obj/NiTextureProperty.o \
           src/obj/NiTextureTransformController.o \
           src/obj/NiTexturingProperty.o \
           src/obj/NiTimeController.o \
           src/obj/NiTransformController.o \
           src/obj/NiTransformData.o \
           src/obj/NiTransformInterpolator.o \
           src/obj/NiTriBasedGeom.o \
           src/obj/NiTriBasedGeomData.o \
           src/obj/NiTriShape.o \
           src/obj/NiTriShapeData.o \
           src/obj/NiTriShapeSkinController.o \
           src/obj/NiTriStrips.o \
           src/obj/NiTriStripsData.o \
           src/obj/NiUVController.o \
           src/obj/NiUVData.o \
           src/obj/NiVectorExtraData.o \
           src/obj/NiVertexColorProperty.o \
           src/obj/NiVertWeightsExtraData.o \
           src/obj/NiVisController.o \
           src/obj/NiVisData.o \
           src/obj/NiWireframeProperty.o \
           src/obj/NiZBufferProperty.o \
           src/obj/RootCollisionNode.o \
           src/gen/AVObject.o \
           src/gen/BoundingBox.o \
           src/gen/ByteArray.o \
           src/gen/ByteColor3.o \
           src/gen/ByteColor4.o \
           src/gen/ControllerLink.o \
           src/gen/enums.o \
           src/gen/Footer.o \
           src/gen/FurniturePosition.o \
           src/gen/Header.o \
           src/gen/hkTriangle.o \
           src/gen/LimitedHingeDescriptor.o \
           src/gen/LODRange.o \
           src/gen/MatchGroup.o \
           src/gen/MipMap.o \
           src/gen/Morph.o \
           src/gen/MultiTextureElement.o \
           src/gen/NodeGroup.o \
           src/gen/OblivionColFilter.o \
           src/gen/OblivionSubShape.o \
           src/gen/OldSkinData.o \
           src/gen/Particle.o \
           src/gen/QuaternionXYZW.o \
           src/gen/RagDollDescriptor.o \
           src/gen/register.o \
           src/gen/ShaderTexDesc.o \
           src/gen/SkinData.o \
           src/gen/SkinPartition.o \
           src/gen/SkinShape.o \
           src/gen/SkinShapeGroup.o \
           src/gen/SkinWeight.o \
           src/gen/Sphere.o \
           src/gen/StringPalette.o \
           src/gen/TBC.o \
           src/gen/TexDesc.o \
           src/gen/TexSource.o

all: Makefile  $(TARGET)

$(TARGET):  $(OBJ_FILES)
	rm -f $(TARGET)
	$(CXX) $(L_FLAGS) -o $(TARGET) $(OBJ_FILES) $(LIBS)
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)

clean: clean
	rm -f $(TARGET)
	rm -f src/*.o
	rm -f src/gen/*.o
	rm -f src/obj/*.o	
	rm -f $(TARGETA)
	rm -f $(TARGETD)
	rm -f $(TARGET0)
	rm -f $(TARGET1)
	rm -f $(TARGET2)
