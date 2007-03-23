// Swig module description file for a C dynamic library source file
// This header contains all the nifty details.

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

// print
%rename(__str__) asString;

// smart pointers via "()."
%rename(__call__) Ptr;

//Ignore the const versions of these functions
%ignore Niflib::DynamicCast( const Niflib::NiObject * object );
%ignore Niflib::StaticCast ( const Niflib::NiObject * object );

//Do not use smart pointer support as it doubles the size of the library
//and makes it take twice as long to be imported.
%ignore Niflib::Ref::operator->;
%ignore Niflib::Ref::operator=;

// At the moment, let us ignore some common functions that are
// not essential for NIF manipulating scripts.
// This will reduce the size of the wrapper file.

%ignore FixLinks;
%ignore Read;
%ignore Write;
%ignore operator=;
%ignore operator[];
%ignore TypeConst;
%ignore GetIDString;
%ignore IsSameType;
%ignore IsDerivedType;
%ignore NumObjectsInMemory;

// ignore things swig complains about
// (TODO)

// Import the symbols from these but do not include them in the wrapper
%import "../include/gen/obj_defines.h"
%import "../include/NIF_IO.h"
%import "../include/dll_export.h"
%import "../include/Type.h"

%{
// main header file
#include "../include/niflib.h"

// SWIG is very picky about namespaces. Using namespace Niflib throughout
// ensures that SWIG wraps all types in the right way.
using namespace Niflib;

// auxilary header files
#include "../include/Ref.h"
#include "../include/Type.h"
#include "../include/nif_math.h"
#include "../include/gen/obj_defines.h"
#include "../include/obj/NiObject.h"
#include "../include/obj/AKeyedData.h"
#include "../include/obj/AParticleModifier.h"
#include "../include/obj/bhkRefObject.h"
#include "../include/obj/bhkSerializable.h"
#include "../include/obj/AbhkConstraint.h"
#include "../include/obj/AbhkRagdollConstraint.h"
#include "../include/obj/bhkShape.h"
#include "../include/obj/AbhkShapeCollection.h"
#include "../include/obj/bhkSphereRepShape.h"
#include "../include/obj/bhkConvexShape.h"
#include "../include/obj/bhkWorldObject.h"
#include "../include/obj/bhkEntity.h"
#include "../include/obj/NiCollisionObject.h"
#include "../include/obj/NiExtraData.h"
#include "../include/obj/NiInterpolator.h"
#include "../include/obj/NiBlendInterpolator.h"
#include "../include/obj/NiBSplineInterpolator.h"
#include "../include/obj/NiObjectNET.h"
#include "../include/obj/NiAVObject.h"
#include "../include/obj/NiDynamicEffect.h"
#include "../include/obj/NiLight.h"
#include "../include/obj/NiProperty.h"
#include "../include/obj/NiPSysModifier.h"
#include "../include/obj/NiPSysEmitter.h"
#include "../include/obj/NiPSysVolumeEmitter.h"
#include "../include/obj/NiTimeController.h"
#include "../include/obj/ABoneLODController.h"
#include "../include/obj/NiSingleInterpolatorController.h"
#include "../include/obj/APSysCtlr.h"
#include "../include/obj/NiGeometry.h"
#include "../include/obj/NiTriBasedGeom.h"
#include "../include/obj/NiGeometryData.h"
#include "../include/obj/NiTriBasedGeomData.h"
#include "../include/obj/APSysData.h"
#include "../include/obj/bhkBlendCollisionObject.h"
#include "../include/obj/bhkBlendController.h"
#include "../include/obj/bhkBoxShape.h"
#include "../include/obj/bhkCapsuleShape.h"
#include "../include/obj/bhkCollisionObject.h"
#include "../include/obj/bhkConvexVerticesShape.h"
#include "../include/obj/bhkHingeConstraint.h"
#include "../include/obj/bhkLimitedHingeConstraint.h"
#include "../include/obj/bhkListShape.h"
#include "../include/obj/bhkMalleableConstraint.h"
#include "../include/obj/bhkMoppBvTreeShape.h"
#include "../include/obj/bhkMultiSphereShape.h"
#include "../include/obj/bhkNiTriStripsShape.h"
#include "../include/obj/bhkPackedNiTriStripsShape.h"
#include "../include/obj/bhkPrismaticConstraint.h"
#include "../include/obj/bhkRagdollConstraint.h"
#include "../include/obj/bhkRigidBody.h"
#include "../include/obj/bhkRigidBodyT.h"
#include "../include/obj/bhkSimpleShapePhantom.h"
#include "../include/obj/bhkSPCollisionObject.h"
#include "../include/obj/bhkSphereShape.h"
#include "../include/obj/bhkStiffSpringConstraint.h"
#include "../include/obj/bhkTransformShape.h"
#include "../include/obj/bhkConvexTransformShape.h"
#include "../include/obj/BSBound.h"
#include "../include/obj/BSFurnitureMarker.h"
#include "../include/obj/BSParentVelocityModifier.h"
#include "../include/obj/BSPSysArrayEmitter.h"
#include "../include/obj/BSXFlags.h"
#include "../include/obj/hkPackedNiTriStripsData.h"
#include "../include/obj/NiAlphaController.h"
#include "../include/obj/NiAlphaProperty.h"
#include "../include/obj/NiAmbientLight.h"
#include "../include/obj/NiAutoNormalParticlesData.h"
#include "../include/obj/NiBinaryExtraData.h"
#include "../include/obj/NiBlendBoolInterpolator.h"
#include "../include/obj/NiBlendFloatInterpolator.h"
#include "../include/obj/NiBlendPoint3Interpolator.h"
#include "../include/obj/NiBlendTransformInterpolator.h"
#include "../include/obj/NiBoneLODController.h"
#include "../include/obj/NiBoolData.h"
#include "../include/obj/NiBooleanExtraData.h"
#include "../include/obj/NiBoolInterpolator.h"
#include "../include/obj/NiBoolTimelineInterpolator.h"
#include "../include/obj/NiBSBoneLODController.h"
#include "../include/obj/NiBSplineBasisData.h"
#include "../include/obj/NiBSplineCompFloatInterpolator.h"
#include "../include/obj/NiBSplineCompPoint3Interpolator.h"
#include "../include/obj/NiBSplineCompTransformInterpolator.h"
#include "../include/obj/NiBSplineData.h"
#include "../include/obj/NiCamera.h"
#include "../include/obj/NiCollisionData.h"
#include "../include/obj/NiColorData.h"
#include "../include/obj/NiColorExtraData.h"
#include "../include/obj/NiControllerManager.h"
#include "../include/obj/NiControllerSequence.h"
#include "../include/obj/NiDefaultAVObjectPalette.h"
#include "../include/obj/NiDirectionalLight.h"
#include "../include/obj/NiDitherProperty.h"
#include "../include/obj/NiFlipController.h"
#include "../include/obj/NiFloatData.h"
#include "../include/obj/NiFloatExtraData.h"
#include "../include/obj/NiFloatExtraDataController.h"
#include "../include/obj/NiFloatInterpolator.h"
#include "../include/obj/NiFloatsExtraData.h"
#include "../include/obj/NiFogProperty.h"
#include "../include/obj/NiGeomMorpherController.h"
#include "../include/obj/NiGravity.h"
#include "../include/obj/NiIntegerExtraData.h"
#include "../include/obj/NiIntegersExtraData.h"
#include "../include/obj/NiKeyframeController.h"
#include "../include/obj/BSKeyframeController.h"
#include "../include/obj/NiKeyframeData.h"
#include "../include/obj/NiLightColorController.h"
#include "../include/obj/NiLightDimmerController.h"
#include "../include/obj/NiLookAtController.h"
#include "../include/obj/NiLookAtInterpolator.h"
#include "../include/obj/NiMaterialColorController.h"
#include "../include/obj/NiMaterialProperty.h"
#include "../include/obj/NiMeshPSysData.h"
#include "../include/obj/NiMorphData.h"
#include "../include/obj/NiMultiTargetTransformController.h"
#include "../include/obj/NiNode.h"
#include "../include/obj/AvoidNode.h"
#include "../include/obj/FxWidget.h"
#include "../include/obj/FxButton.h"
#include "../include/obj/FxRadioButton.h"
#include "../include/obj/NiBillboardNode.h"
#include "../include/obj/NiBSAnimationNode.h"
#include "../include/obj/NiBSParticleNode.h"
#include "../include/obj/NiLODNode.h"
#include "../include/obj/NiPalette.h"
#include "../include/obj/NiParticleBomb.h"
#include "../include/obj/NiParticleColorModifier.h"
#include "../include/obj/NiParticleGrowFade.h"
#include "../include/obj/NiParticleMeshModifier.h"
#include "../include/obj/NiParticleRotation.h"
#include "../include/obj/NiParticles.h"
#include "../include/obj/NiAutoNormalParticles.h"
#include "../include/obj/NiParticleMeshes.h"
#include "../include/obj/NiParticlesData.h"
#include "../include/obj/NiParticleMeshesData.h"
#include "../include/obj/NiParticleSystem.h"
#include "../include/obj/NiMeshParticleSystem.h"
#include "../include/obj/NiParticleSystemController.h"
#include "../include/obj/NiBSPArrayController.h"
#include "../include/obj/NiPathController.h"
#include "../include/obj/NiPathInterpolator.h"
#include "../include/obj/NiPixelData.h"
#include "../include/obj/NiPlanarCollider.h"
#include "../include/obj/NiPoint3Interpolator.h"
#include "../include/obj/NiPointLight.h"
#include "../include/obj/NiPosData.h"
#include "../include/obj/NiPSysAgeDeathModifier.h"
#include "../include/obj/NiPSysBombModifier.h"
#include "../include/obj/NiPSysBoundUpdateModifier.h"
#include "../include/obj/NiPSysBoxEmitter.h"
#include "../include/obj/NiPSysColliderManager.h"
#include "../include/obj/NiPSysColorModifier.h"
#include "../include/obj/NiPSysCylinderEmitter.h"
#include "../include/obj/NiPSysData.h"
#include "../include/obj/NiPSysDragModifier.h"
#include "../include/obj/NiPSysEmitterCtlr.h"
#include "../include/obj/NiPSysEmitterCtlrData.h"
#include "../include/obj/NiPSysEmitterDeclinationCtlr.h"
#include "../include/obj/NiPSysEmitterDeclinationVarCtlr.h"
#include "../include/obj/NiPSysEmitterInitialRadiusCtlr.h"
#include "../include/obj/NiPSysEmitterLifeSpanCtlr.h"
#include "../include/obj/NiPSysEmitterSpeedCtlr.h"
#include "../include/obj/NiPSysGravityModifier.h"
#include "../include/obj/NiPSysGravityStrengthCtlr.h"
#include "../include/obj/NiPSysGrowFadeModifier.h"
#include "../include/obj/NiPSysMeshEmitter.h"
#include "../include/obj/NiPSysMeshUpdateModifier.h"
#include "../include/obj/NiPSysModifierActiveCtlr.h"
#include "../include/obj/NiPSysPlanarCollider.h"
#include "../include/obj/NiPSysPositionModifier.h"
#include "../include/obj/NiPSysResetOnLoopCtlr.h"
#include "../include/obj/NiPSysRotationModifier.h"
#include "../include/obj/NiPSysSpawnModifier.h"
#include "../include/obj/NiPSysSphereEmitter.h"
#include "../include/obj/NiPSysUpdateCtlr.h"
#include "../include/obj/NiLODData.h"
#include "../include/obj/NiRangeLODData.h"
#include "../include/obj/NiScreenLODData.h"
#include "../include/obj/NiRotatingParticles.h"
#include "../include/obj/NiRotatingParticlesData.h"
#include "../include/obj/NiSequenceStreamHelper.h"
#include "../include/obj/NiShadeProperty.h"
#include "../include/obj/NiSkinData.h"
#include "../include/obj/NiSkinInstance.h"
#include "../include/obj/NiClodSkinInstance.h"
#include "../include/obj/NiSkinPartition.h"
#include "../include/obj/NiSourceTexture.h"
#include "../include/obj/NiSpecularProperty.h"
#include "../include/obj/NiSphericalCollider.h"
#include "../include/obj/NiSpotLight.h"
#include "../include/obj/NiStencilProperty.h"
#include "../include/obj/NiStringExtraData.h"
#include "../include/obj/NiStringPalette.h"
#include "../include/obj/NiStringsExtraData.h"
#include "../include/obj/NiTextKeyExtraData.h"
#include "../include/obj/NiTextureEffect.h"
#include "../include/obj/NiTextureTransformController.h"
#include "../include/obj/NiTextureModeProperty.h"
#include "../include/obj/NiImage.h"
#include "../include/obj/NiTextureProperty.h"
#include "../include/obj/NiTexturingProperty.h"
#include "../include/obj/NiTransformController.h"
#include "../include/obj/NiTransformData.h"
#include "../include/obj/NiTransformInterpolator.h"
#include "../include/obj/NiTriShape.h"
#include "../include/obj/NiTriShapeData.h"
#include "../include/obj/NiTriStrips.h"
#include "../include/obj/NiTriStripsData.h"
#include "../include/obj/NiClod.h"
#include "../include/obj/NiClodData.h"
#include "../include/obj/NiUVController.h"
#include "../include/obj/NiUVData.h"
#include "../include/obj/NiVectorExtraData.h"
#include "../include/obj/NiVertexColorProperty.h"
#include "../include/obj/NiVertWeightsExtraData.h"
#include "../include/obj/NiVisController.h"
#include "../include/obj/NiVisData.h"
#include "../include/obj/NiWireframeProperty.h"
#include "../include/obj/NiZBufferProperty.h"
#include "../include/obj/RootCollisionNode.h"
#include "../include/gen/ByteArray.h"
#include "../include/gen/Footer.h"
#include "../include/gen/LODRange.h"
#include "../include/gen/MatchGroup.h"
#include "../include/gen/MipMap.h"
#include "../include/gen/NodeGroup.h"
#include "../include/gen/QuaternionXYZW.h"
#include "../include/gen/SkinShape.h"
#include "../include/gen/SkinShapeGroup.h"
#include "../include/gen/SkinWeight.h"
#include "../include/gen/AVObject.h"
#include "../include/gen/ControllerLink.h"
#include "../include/gen/Header.h"
#include "../include/gen/StringPalette.h"
#include "../include/gen/TBC.h"
#include "../include/gen/KeyGroup.h"
#include "../include/gen/RotationKeyArray.h"
#include "../include/gen/TexDesc.h"
#include "../include/gen/ShaderTexDesc.h"
#include "../include/gen/TexSource.h"
#include "../include/gen/SkinPartition.h"
#include "../include/gen/BoundingBox.h"
#include "../include/gen/FurniturePosition.h"
#include "../include/gen/hkTriangle.h"
#include "../include/gen/Morph.h"
#include "../include/gen/Particle.h"
#include "../include/gen/SkinData.h"
#include "../include/gen/Sphere.h"
#include "../include/gen/RagDollDescriptor.h"
#include "../include/gen/LimitedHingeDescriptor.h"
%}

