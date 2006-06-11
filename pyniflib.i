// Swig module description file for a C dynamic library source file
// Generate with: swig -c++ -python -o py_wrap.cpp pyniflib.i

/* Copyright (c) 2006, NIF File Format Library and Tools
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

%module niflib
%include "stl.i"
%include "std_map.i"
%include "exception.i"
%include "std_list.i"
%include "typemaps.i"

// enable string assignment in structure member functions
%typemap(in) std::string* ($*1_ltype tempstr) {
	char * temps; int templ;
 	if (PyString_AsStringAndSize($input, &temps, &templ)) return NULL;
 	tempstr = $*1_ltype(temps, templ);
 	$1 = &tempstr;
}
%typemap(out) std::string* "$result = PyString_FromStringAndSize($1->data(), $1->length());";

// we need a version of SWIG that has SWIG_CATCH_STDEXCEPT support
#if SWIG_VERSION >= 0x010322
%exception {
	try {
		$action
	}
	SWIG_CATCH_STDEXCEPT // catch std::exception
	catch (...) {
		SWIG_exception(SWIG_UnknownError, "Unknown exception");
	}
}
#endif

// we need to define this because the wrapper gets confused about NIFLIB_API'd functions otherwise
#define NIFLIB_API

%{
	#include "niflib.h"
%}

// we need the definition of the template classes before we define the template Python names below
template <class T> 
struct Key {
	float time;
	T data, forward_tangent, backward_tangent;
	float tension, bias, continuity;
};

%ignore Key;
%template(vector_bool) std::vector<bool>;
%template(vector_byte) std::vector<byte>;
%template(vector_uint) std::vector<uint>;
%template(vector_ushort) std::vector<ushort>;
%template(vector_AlphaFormat) std::vector<AlphaFormat>;
%template(vector_ApplyMode) std::vector<ApplyMode>;
%template(vector_ushort) std::vector<ushort>;
%template(vector_byte) std::vector<byte>;
%template(vector_uint) std::vector<uint>;
%template(vector_unsigned short) std::vector<unsigned short>;
%template(vector_float) std::vector<float>;
%template(vector_HeaderString) std::vector<HeaderString>;
%template(vector_KeyType) std::vector<KeyType>;
%template(vector_LightMode) std::vector<LightMode>;
%template(vector_uint) std::vector<uint>;
%template(vector_MipMapFormat) std::vector<MipMapFormat>;
%template(vector_PixelFormat) std::vector<PixelFormat>;
%template(vector_PixelLayout) std::vector<PixelLayout>;
%template(vector_uint) std::vector<uint>;
%template(vector_TexClampMode) std::vector<TexClampMode>;
%template(vector_TexFilterMode) std::vector<TexFilterMode>;
%template(vector_VertMode) std::vector<VertMode>;
%template(vector_ByteArray) std::vector<ByteArray>;
%template(vector_Color3) std::vector<Color3>;
%template(vector_Color4) std::vector<Color4>;
%template(vector_string) std::vector<string>;
%template(vector_Footer) std::vector<Footer>;
%template(vector_LODRange) std::vector<LODRange>;
%template(vector_MatchGroup) std::vector<MatchGroup>;
%template(vector_Matrix22) std::vector<Matrix22>;
%template(vector_Matrix33) std::vector<Matrix33>;
%template(vector_Matrix44) std::vector<Matrix44>;
%template(vector_MipMap) std::vector<MipMap>;
%template(vector_NodeGroup) std::vector<NodeGroup>;
%template(vector_Quaternion) std::vector<Quaternion>;
%template(vector_QuaternionXYZW) std::vector<QuaternionXYZW>;
%template(vector_ShortString) std::vector<ShortString>;
%template(vector_SkinShape) std::vector<SkinShape>;
%template(vector_SkinShapeGroup) std::vector<SkinShapeGroup>;
%template(vector_SkinWeight) std::vector<SkinWeight>;
%template(vector_string) std::vector<string>;
%template(vector_AVObject) std::vector<AVObject>;
%template(vector_ControllerLink) std::vector<ControllerLink>;
%template(vector_Header) std::vector<Header>;
%template(vector_StringPalette) std::vector<StringPalette>;
%template(vector_TBC) std::vector<TBC>;
%template(vector_ns_keyrotsub) std::vector<ns_keyrotsub>;
%template(vector_TexCoord) std::vector<TexCoord>;
%template(vector_TexDesc) std::vector<TexDesc>;
%template(vector_ShaderTexDesc) std::vector<ShaderTexDesc>;
%template(vector_TexSource) std::vector<TexSource>;
%template(vector_Triangle) std::vector<Triangle>;
%template(vector_SkinPartition) std::vector<SkinPartition>;
%template(vector_Vector3) std::vector<Vector3>;
%template(vector_BoundingBox) std::vector<BoundingBox>;
%template(vector_FurniturePosition) std::vector<FurniturePosition>;
%template(vector_hkTriangle) std::vector<hkTriangle>;
%template(vector_Morph) std::vector<Morph>;
%template(vector_Particle) std::vector<Particle>;
%template(vector_SkinData) std::vector<SkinData>;
%template(vector_Float4) std::vector<Float4>;
%template(vector_RagDollDescriptor) std::vector<RagDollDescriptor>;
%template(vector_LimitedHingeDescriptor) std::vector<LimitedHingeDescriptor>;
%template(vector_NiObject) std::vector<NiObject>;
%template(vector_AKeyedData) std::vector<AKeyedData>;
%template(vector_AParticleModifier) std::vector<AParticleModifier>;
%template(vector_bhkRefObject) std::vector<bhkRefObject>;
%template(vector_bhkSerializable) std::vector<bhkSerializable>;
%template(vector_AbhkConstraint) std::vector<AbhkConstraint>;
%template(vector_AbhkRagdollConstraint) std::vector<AbhkRagdollConstraint>;
%template(vector_bhkShape) std::vector<bhkShape>;
%template(vector_AbhkShapeCollection) std::vector<AbhkShapeCollection>;
%template(vector_bhkSphereRepShape) std::vector<bhkSphereRepShape>;
%template(vector_bhkConvexShape) std::vector<bhkConvexShape>;
%template(vector_bhkWorldObject) std::vector<bhkWorldObject>;
%template(vector_bhkEntity) std::vector<bhkEntity>;
%template(vector_NiCollisionObject) std::vector<NiCollisionObject>;
%template(vector_NiExtraData) std::vector<NiExtraData>;
%template(vector_NiInterpolator) std::vector<NiInterpolator>;
%template(vector_NiBlendInterpolator) std::vector<NiBlendInterpolator>;
%template(vector_NiBSplineInterpolator) std::vector<NiBSplineInterpolator>;
%template(vector_NiObjectNET) std::vector<NiObjectNET>;
%template(vector_NiAVObject) std::vector<NiAVObject>;
%template(vector_NiDynamicEffect) std::vector<NiDynamicEffect>;
%template(vector_NiLight) std::vector<NiLight>;
%template(vector_NiProperty) std::vector<NiProperty>;
%template(vector_NiPSysModifier) std::vector<NiPSysModifier>;
%template(vector_NiPSysEmitter) std::vector<NiPSysEmitter>;
%template(vector_NiPSysVolumeEmitter) std::vector<NiPSysVolumeEmitter>;
%template(vector_NiTimeController) std::vector<NiTimeController>;
%template(vector_ABoneLODController) std::vector<ABoneLODController>;
%template(vector_NiSingleInterpolatorController) std::vector<NiSingleInterpolatorController>;
%template(vector_APSysCtlr) std::vector<APSysCtlr>;
%template(vector_NiTriBasedGeom) std::vector<NiTriBasedGeom>;
%template(vector_NiTriBasedGeomData) std::vector<NiTriBasedGeomData>;
%template(vector_APSysData) std::vector<APSysData>;
%template(vector_bhkBlendCollisionObject) std::vector<bhkBlendCollisionObject>;
%template(vector_bhkBlendController) std::vector<bhkBlendController>;
%template(vector_bhkBoxShape) std::vector<bhkBoxShape>;
%template(vector_bhkCapsuleShape) std::vector<bhkCapsuleShape>;
%template(vector_bhkCollisionObject) std::vector<bhkCollisionObject>;
%template(vector_bhkConvexVerticesShape) std::vector<bhkConvexVerticesShape>;
%template(vector_bhkHingeConstraint) std::vector<bhkHingeConstraint>;
%template(vector_bhkLimitedHingeConstraint) std::vector<bhkLimitedHingeConstraint>;
%template(vector_bhkListShape) std::vector<bhkListShape>;
%template(vector_bhkMalleableConstraint) std::vector<bhkMalleableConstraint>;
%template(vector_bhkMoppBvTreeShape) std::vector<bhkMoppBvTreeShape>;
%template(vector_bhkMultiSphereShape) std::vector<bhkMultiSphereShape>;
%template(vector_bhkNiTriStripsShape) std::vector<bhkNiTriStripsShape>;
%template(vector_bhkPackedNiTriStripsShape) std::vector<bhkPackedNiTriStripsShape>;
%template(vector_bhkPrismaticConstraint) std::vector<bhkPrismaticConstraint>;
%template(vector_bhkRagdollConstraint) std::vector<bhkRagdollConstraint>;
%template(vector_bhkRigidBody) std::vector<bhkRigidBody>;
%template(vector_bhkRigidBodyT) std::vector<bhkRigidBodyT>;
%template(vector_bhkSimpleShapePhantom) std::vector<bhkSimpleShapePhantom>;
%template(vector_bhkSPCollisionObject) std::vector<bhkSPCollisionObject>;
%template(vector_bhkSphereShape) std::vector<bhkSphereShape>;
%template(vector_bhkStiffSpringConstraint) std::vector<bhkStiffSpringConstraint>;
%template(vector_bhkTransformShape) std::vector<bhkTransformShape>;
%template(vector_bhkConvexTransformShape) std::vector<bhkConvexTransformShape>;
%template(vector_BSBound) std::vector<BSBound>;
%template(vector_BSFurnitureMarker) std::vector<BSFurnitureMarker>;
%template(vector_BSParentVelocityModifier) std::vector<BSParentVelocityModifier>;
%template(vector_BSPSysArrayEmitter) std::vector<BSPSysArrayEmitter>;
%template(vector_BSXFlags) std::vector<BSXFlags>;
%template(vector_hkPackedNiTriStripsData) std::vector<hkPackedNiTriStripsData>;
%template(vector_NiAlphaController) std::vector<NiAlphaController>;
%template(vector_NiAlphaProperty) std::vector<NiAlphaProperty>;
%template(vector_NiAmbientLight) std::vector<NiAmbientLight>;
%template(vector_NiAutoNormalParticlesData) std::vector<NiAutoNormalParticlesData>;
%template(vector_NiBinaryExtraData) std::vector<NiBinaryExtraData>;
%template(vector_NiBlendBoolInterpolator) std::vector<NiBlendBoolInterpolator>;
%template(vector_NiBlendFloatInterpolator) std::vector<NiBlendFloatInterpolator>;
%template(vector_NiBlendPoint3Interpolator) std::vector<NiBlendPoint3Interpolator>;
%template(vector_NiBlendTransformInterpolator) std::vector<NiBlendTransformInterpolator>;
%template(vector_NiBoneLODController) std::vector<NiBoneLODController>;
%template(vector_NiBoolData) std::vector<NiBoolData>;
%template(vector_NiBooleanExtraData) std::vector<NiBooleanExtraData>;
%template(vector_NiBoolInterpolator) std::vector<NiBoolInterpolator>;
%template(vector_NiBoolTimelineInterpolator) std::vector<NiBoolTimelineInterpolator>;
%template(vector_NiBSBoneLODController) std::vector<NiBSBoneLODController>;
%template(vector_NiBSplineBasisData) std::vector<NiBSplineBasisData>;
%template(vector_NiBSplineCompFloatInterpolator) std::vector<NiBSplineCompFloatInterpolator>;
%template(vector_NiBSplineCompPoint3Interpolator) std::vector<NiBSplineCompPoint3Interpolator>;
%template(vector_NiBSplineCompTransformInterpolator) std::vector<NiBSplineCompTransformInterpolator>;
%template(vector_NiBSplineData) std::vector<NiBSplineData>;
%template(vector_NiCamera) std::vector<NiCamera>;
%template(vector_NiCollisionData) std::vector<NiCollisionData>;
%template(vector_NiColorData) std::vector<NiColorData>;
%template(vector_NiColorExtraData) std::vector<NiColorExtraData>;
%template(vector_NiControllerManager) std::vector<NiControllerManager>;
%template(vector_NiControllerSequence) std::vector<NiControllerSequence>;
%template(vector_NiDefaultAVObjectPalette) std::vector<NiDefaultAVObjectPalette>;
%template(vector_NiDirectionalLight) std::vector<NiDirectionalLight>;
%template(vector_NiDitherProperty) std::vector<NiDitherProperty>;
%template(vector_NiFlipController) std::vector<NiFlipController>;
%template(vector_NiFloatData) std::vector<NiFloatData>;
%template(vector_NiFloatExtraData) std::vector<NiFloatExtraData>;
%template(vector_NiFloatExtraDataController) std::vector<NiFloatExtraDataController>;
%template(vector_NiFloatInterpolator) std::vector<NiFloatInterpolator>;
%template(vector_NiFloatsExtraData) std::vector<NiFloatsExtraData>;
%template(vector_NiFogProperty) std::vector<NiFogProperty>;
%template(vector_NiGeomMorpherController) std::vector<NiGeomMorpherController>;
%template(vector_NiGravity) std::vector<NiGravity>;
%template(vector_NiIntegerExtraData) std::vector<NiIntegerExtraData>;
%template(vector_NiIntegersExtraData) std::vector<NiIntegersExtraData>;
%template(vector_NiKeyframeController) std::vector<NiKeyframeController>;
%template(vector_BSKeyframeController) std::vector<BSKeyframeController>;
%template(vector_NiKeyframeData) std::vector<NiKeyframeData>;
%template(vector_NiLightColorController) std::vector<NiLightColorController>;
%template(vector_NiLightDimmerController) std::vector<NiLightDimmerController>;
%template(vector_NiLookAtController) std::vector<NiLookAtController>;
%template(vector_NiLookAtInterpolator) std::vector<NiLookAtInterpolator>;
%template(vector_NiMaterialColorController) std::vector<NiMaterialColorController>;
%template(vector_NiMaterialProperty) std::vector<NiMaterialProperty>;
%template(vector_NiMeshPSysData) std::vector<NiMeshPSysData>;
%template(vector_NiMorphData) std::vector<NiMorphData>;
%template(vector_NiMultiTargetTransformController) std::vector<NiMultiTargetTransformController>;
%template(vector_NiNode) std::vector<NiNode>;
%template(vector_AvoidNode) std::vector<AvoidNode>;
%template(vector_FxWidget) std::vector<FxWidget>;
%template(vector_FxButton) std::vector<FxButton>;
%template(vector_FxRadioButton) std::vector<FxRadioButton>;
%template(vector_NiBillboardNode) std::vector<NiBillboardNode>;
%template(vector_NiBSAnimationNode) std::vector<NiBSAnimationNode>;
%template(vector_NiBSParticleNode) std::vector<NiBSParticleNode>;
%template(vector_NiLODNode) std::vector<NiLODNode>;
%template(vector_NiPalette) std::vector<NiPalette>;
%template(vector_NiParticleBomb) std::vector<NiParticleBomb>;
%template(vector_NiParticleColorModifier) std::vector<NiParticleColorModifier>;
%template(vector_NiParticleGrowFade) std::vector<NiParticleGrowFade>;
%template(vector_NiParticleMeshModifier) std::vector<NiParticleMeshModifier>;
%template(vector_NiParticleRotation) std::vector<NiParticleRotation>;
%template(vector_NiParticles) std::vector<NiParticles>;
%template(vector_NiAutoNormalParticles) std::vector<NiAutoNormalParticles>;
%template(vector_NiParticleMeshes) std::vector<NiParticleMeshes>;
%template(vector_NiParticlesData) std::vector<NiParticlesData>;
%template(vector_NiParticleMeshesData) std::vector<NiParticleMeshesData>;
%template(vector_NiParticleSystem) std::vector<NiParticleSystem>;
%template(vector_NiMeshParticleSystem) std::vector<NiMeshParticleSystem>;
%template(vector_NiParticleSystemController) std::vector<NiParticleSystemController>;
%template(vector_NiBSPArrayController) std::vector<NiBSPArrayController>;
%template(vector_NiPathController) std::vector<NiPathController>;
%template(vector_NiPathInterpolator) std::vector<NiPathInterpolator>;
%template(vector_NiPixelData) std::vector<NiPixelData>;
%template(vector_NiPlanarCollider) std::vector<NiPlanarCollider>;
%template(vector_NiPoint3Interpolator) std::vector<NiPoint3Interpolator>;
%template(vector_NiPointLight) std::vector<NiPointLight>;
%template(vector_NiPosData) std::vector<NiPosData>;
%template(vector_NiPSysAgeDeathModifier) std::vector<NiPSysAgeDeathModifier>;
%template(vector_NiPSysBombModifier) std::vector<NiPSysBombModifier>;
%template(vector_NiPSysBoundUpdateModifier) std::vector<NiPSysBoundUpdateModifier>;
%template(vector_NiPSysBoxEmitter) std::vector<NiPSysBoxEmitter>;
%template(vector_NiPSysColliderManager) std::vector<NiPSysColliderManager>;
%template(vector_NiPSysColorModifier) std::vector<NiPSysColorModifier>;
%template(vector_NiPSysCylinderEmitter) std::vector<NiPSysCylinderEmitter>;
%template(vector_NiPSysData) std::vector<NiPSysData>;
%template(vector_NiPSysDragModifier) std::vector<NiPSysDragModifier>;
%template(vector_NiPSysEmitterCtlr) std::vector<NiPSysEmitterCtlr>;
%template(vector_NiPSysEmitterCtlrData) std::vector<NiPSysEmitterCtlrData>;
%template(vector_NiPSysEmitterDeclinationCtlr) std::vector<NiPSysEmitterDeclinationCtlr>;
%template(vector_NiPSysEmitterDeclinationVarCtlr) std::vector<NiPSysEmitterDeclinationVarCtlr>;
%template(vector_NiPSysEmitterInitialRadiusCtlr) std::vector<NiPSysEmitterInitialRadiusCtlr>;
%template(vector_NiPSysEmitterLifeSpanCtlr) std::vector<NiPSysEmitterLifeSpanCtlr>;
%template(vector_NiPSysEmitterSpeedCtlr) std::vector<NiPSysEmitterSpeedCtlr>;
%template(vector_NiPSysGravityModifier) std::vector<NiPSysGravityModifier>;
%template(vector_NiPSysGravityStrengthCtlr) std::vector<NiPSysGravityStrengthCtlr>;
%template(vector_NiPSysGrowFadeModifier) std::vector<NiPSysGrowFadeModifier>;
%template(vector_NiPSysMeshEmitter) std::vector<NiPSysMeshEmitter>;
%template(vector_NiPSysMeshUpdateModifier) std::vector<NiPSysMeshUpdateModifier>;
%template(vector_NiPSysModifierActiveCtlr) std::vector<NiPSysModifierActiveCtlr>;
%template(vector_NiPSysPlanarCollider) std::vector<NiPSysPlanarCollider>;
%template(vector_NiPSysPositionModifier) std::vector<NiPSysPositionModifier>;
%template(vector_NiPSysResetOnLoopCtlr) std::vector<NiPSysResetOnLoopCtlr>;
%template(vector_NiPSysRotationModifier) std::vector<NiPSysRotationModifier>;
%template(vector_NiPSysSpawnModifier) std::vector<NiPSysSpawnModifier>;
%template(vector_NiPSysSphereEmitter) std::vector<NiPSysSphereEmitter>;
%template(vector_NiPSysUpdateCtlr) std::vector<NiPSysUpdateCtlr>;
%template(vector_NiRangeLODData) std::vector<NiRangeLODData>;
%template(vector_NiRotatingParticles) std::vector<NiRotatingParticles>;
%template(vector_NiRotatingParticlesData) std::vector<NiRotatingParticlesData>;
%template(vector_NiScreenLODData) std::vector<NiScreenLODData>;
%template(vector_NiSequenceStreamHelper) std::vector<NiSequenceStreamHelper>;
%template(vector_NiShadeProperty) std::vector<NiShadeProperty>;
%template(vector_NiSkinData) std::vector<NiSkinData>;
%template(vector_NiSkinInstance) std::vector<NiSkinInstance>;
%template(vector_NiSkinPartition) std::vector<NiSkinPartition>;
%template(vector_NiSourceTexture) std::vector<NiSourceTexture>;
%template(vector_NiSpecularProperty) std::vector<NiSpecularProperty>;
%template(vector_NiSphericalCollider) std::vector<NiSphericalCollider>;
%template(vector_NiSpotLight) std::vector<NiSpotLight>;
%template(vector_NiStencilProperty) std::vector<NiStencilProperty>;
%template(vector_NiStringExtraData) std::vector<NiStringExtraData>;
%template(vector_NiStringPalette) std::vector<NiStringPalette>;
%template(vector_NiStringsExtraData) std::vector<NiStringsExtraData>;
%template(vector_NiTextKeyExtraData) std::vector<NiTextKeyExtraData>;
%template(vector_NiTextureEffect) std::vector<NiTextureEffect>;
%template(vector_NiTextureTransformController) std::vector<NiTextureTransformController>;
%template(vector_NiTexturingProperty) std::vector<NiTexturingProperty>;
%template(vector_NiTransformController) std::vector<NiTransformController>;
%template(vector_NiTransformData) std::vector<NiTransformData>;
%template(vector_NiTransformInterpolator) std::vector<NiTransformInterpolator>;
%template(vector_NiTriShape) std::vector<NiTriShape>;
%template(vector_NiTriShapeData) std::vector<NiTriShapeData>;
%template(vector_NiTriStrips) std::vector<NiTriStrips>;
%template(vector_NiTriStripsData) std::vector<NiTriStripsData>;
%template(vector_NiUVController) std::vector<NiUVController>;
%template(vector_NiUVData) std::vector<NiUVData>;
%template(vector_NiVectorExtraData) std::vector<NiVectorExtraData>;
%template(vector_NiVertexColorProperty) std::vector<NiVertexColorProperty>;
%template(vector_NiVertWeightsExtraData) std::vector<NiVertWeightsExtraData>;
%template(vector_NiVisController) std::vector<NiVisController>;
%template(vector_NiVisData) std::vector<NiVisData>;
%template(vector_NiWireframeProperty) std::vector<NiWireframeProperty>;
%template(vector_NiZBufferProperty) std::vector<NiZBufferProperty>;
%template(vector_RootCollisionNode) std::vector<RootCollisionNode>;
%template(pair_int_float) std::pair<int, float>;
%template(map_int_float) std::map<int, float>;
%template(Key_Quaternion) Key<Quaternion>;
%template(vector_Key_Quaternion) std::vector< Key<Quaternion> >;
%template(Key_Vector3) Key<Vector3>;
%template(vector_Key_Vector3) std::vector< Key<Vector3> >;
%template(Key_float) Key<float>;
%template(vector_Key_float) std::vector< Key<float> >;
%template(Key_Color4) Key<Color4>;
%template(vector_Key_Color4) std::vector< Key<Color4> >;
%template(Key_string) Key<std::string>;
%template(vector_Key_string) std::vector< Key<std::string> >;

%include "niflib.h"
