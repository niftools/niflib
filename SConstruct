
import sys
import os
import time
from distutils import sysconfig

Help("""
'scons' to build niflib library and niflib python wrapper
'scons -c' to clean
""")

# detect platform
if sys.platform == 'linux2' or sys.platform == 'linux-i386':
    python_lib = ['python%d.%d' % sys.version_info[0:2]]
    python_libpath = [sysconfig.get_python_lib (0, 1) + '/config']
    python_include = [sysconfig.get_python_inc ()]
    cppflags = '-fPIC -Wall'
elif sys.platform == 'cygwin':
    python_lib = ['python%d.%d' % sys.version_info[0:2]]
    python_libpath = [sysconfig.get_python_lib (0, 1) + '/config']
    python_include = [sysconfig.get_python_inc ()]
    cppflags = '-Wall'
elif sys.platform == 'win32':
    python_include = [sysconfig.get_python_inc()]
    python_libpath = [sysconfig.get_python_lib(1, 1) + '/../libs']
    python_lib = ['python24']
    cppflags = '/EHsc /O2 /ML /GS /Zi /TP'
else:
    print "Error: Platform %s not supported."%sys.platform
    Exit(1)

env = Environment(ENV = os.environ)

# detect SWIG
try:
    env['SWIG']
except KeyError:
    print """
Error: SWIG not found.
Please install SWIG, it's needed to create the python wrapper.
You can get it from http://www.swig.org/"""
    if sys.platform == "win32": print "Also don't forget to add the SWIG directory to your %PATH%."
    Exit(1)

# build niflib and python wrapper

objfiles = 'obj/NiObject.cpp obj/AKeyedData.cpp obj/AParticleModifier.cpp obj/bhkRefObject.cpp obj/bhkSerializable.cpp obj/AbhkConstraint.cpp obj/AbhkRagdollConstraint.cpp obj/bhkShape.cpp obj/AbhkShapeCollection.cpp obj/bhkSphereRepShape.cpp obj/bhkConvexShape.cpp obj/bhkWorldObject.cpp obj/bhkEntity.cpp obj/NiCollisionObject.cpp obj/NiExtraData.cpp obj/NiInterpolator.cpp obj/NiBlendInterpolator.cpp obj/NiBSplineInterpolator.cpp obj/NiObjectNET.cpp obj/NiAVObject.cpp obj/NiDynamicEffect.cpp obj/NiLight.cpp obj/NiProperty.cpp obj/NiPSysModifier.cpp obj/NiPSysEmitter.cpp obj/NiPSysVolumeEmitter.cpp obj/NiTimeController.cpp obj/ABoneLODController.cpp obj/NiSingleInterpolatorController.cpp obj/APSysCtlr.cpp obj/NiTriBasedGeom.cpp obj/NiTriBasedGeomData.cpp obj/APSysData.cpp obj/bhkBlendCollisionObject.cpp obj/bhkBlendController.cpp obj/bhkBoxShape.cpp obj/bhkCapsuleShape.cpp obj/bhkCollisionObject.cpp obj/bhkConvexVerticesShape.cpp obj/bhkHingeConstraint.cpp obj/bhkLimitedHingeConstraint.cpp obj/bhkListShape.cpp obj/bhkMalleableConstraint.cpp obj/bhkMoppBvTreeShape.cpp obj/bhkMultiSphereShape.cpp obj/bhkNiTriStripsShape.cpp obj/bhkPackedNiTriStripsShape.cpp obj/bhkPrismaticConstraint.cpp obj/bhkRagdollConstraint.cpp obj/bhkRigidBody.cpp obj/bhkRigidBodyT.cpp obj/bhkSimpleShapePhantom.cpp obj/bhkSPCollisionObject.cpp obj/bhkSphereShape.cpp obj/bhkStiffSpringConstraint.cpp obj/bhkTransformShape.cpp obj/bhkConvexTransformShape.cpp obj/BSBound.cpp obj/BSFurnitureMarker.cpp obj/BSParentVelocityModifier.cpp obj/BSPSysArrayEmitter.cpp obj/BSXFlags.cpp obj/hkPackedNiTriStripsData.cpp obj/NiAlphaController.cpp obj/NiAlphaProperty.cpp obj/NiAmbientLight.cpp obj/NiAutoNormalParticlesData.cpp obj/NiBinaryExtraData.cpp obj/NiBlendBoolInterpolator.cpp obj/NiBlendFloatInterpolator.cpp obj/NiBlendPoint3Interpolator.cpp obj/NiBlendTransformInterpolator.cpp obj/NiBoneLODController.cpp obj/NiBoolData.cpp obj/NiBooleanExtraData.cpp obj/NiBoolInterpolator.cpp obj/NiBoolTimelineInterpolator.cpp obj/NiBSBoneLODController.cpp obj/NiBSplineBasisData.cpp obj/NiBSplineCompFloatInterpolator.cpp obj/NiBSplineCompPoint3Interpolator.cpp obj/NiBSplineCompTransformInterpolator.cpp obj/NiBSplineData.cpp obj/NiCamera.cpp obj/NiCollisionData.cpp obj/NiColorData.cpp obj/NiColorExtraData.cpp obj/NiControllerManager.cpp obj/NiControllerSequence.cpp obj/NiDefaultAVObjectPalette.cpp obj/NiDirectionalLight.cpp obj/NiDitherProperty.cpp obj/NiFlipController.cpp obj/NiFloatData.cpp obj/NiFloatExtraData.cpp obj/NiFloatExtraDataController.cpp obj/NiFloatInterpolator.cpp obj/NiFloatsExtraData.cpp obj/NiFogProperty.cpp obj/NiGeomMorpherController.cpp obj/NiGravity.cpp obj/NiIntegerExtraData.cpp obj/NiIntegersExtraData.cpp obj/NiKeyframeController.cpp obj/BSKeyframeController.cpp obj/NiKeyframeData.cpp obj/NiLightColorController.cpp obj/NiLightDimmerController.cpp obj/NiLookAtController.cpp obj/NiLookAtInterpolator.cpp obj/NiMaterialColorController.cpp obj/NiMaterialProperty.cpp obj/NiMeshPSysData.cpp obj/NiMorphData.cpp obj/NiMultiTargetTransformController.cpp obj/NiNode.cpp obj/AvoidNode.cpp obj/FxWidget.cpp obj/FxButton.cpp obj/FxRadioButton.cpp obj/NiBillboardNode.cpp obj/NiBSAnimationNode.cpp obj/NiBSParticleNode.cpp obj/NiLODNode.cpp obj/NiPalette.cpp obj/NiParticleBomb.cpp obj/NiParticleColorModifier.cpp obj/NiParticleGrowFade.cpp obj/NiParticleMeshModifier.cpp obj/NiParticleRotation.cpp obj/NiParticles.cpp obj/NiAutoNormalParticles.cpp obj/NiParticleMeshes.cpp obj/NiParticlesData.cpp obj/NiParticleMeshesData.cpp obj/NiParticleSystem.cpp obj/NiMeshParticleSystem.cpp obj/NiParticleSystemController.cpp obj/NiBSPArrayController.cpp obj/NiPathController.cpp obj/NiPathInterpolator.cpp obj/NiPixelData.cpp obj/NiPlanarCollider.cpp obj/NiPoint3Interpolator.cpp obj/NiPointLight.cpp obj/NiPosData.cpp obj/NiPSysAgeDeathModifier.cpp obj/NiPSysBombModifier.cpp obj/NiPSysBoundUpdateModifier.cpp obj/NiPSysBoxEmitter.cpp obj/NiPSysColliderManager.cpp obj/NiPSysColorModifier.cpp obj/NiPSysCylinderEmitter.cpp obj/NiPSysData.cpp obj/NiPSysDragModifier.cpp obj/NiPSysEmitterCtlr.cpp obj/NiPSysEmitterCtlrData.cpp obj/NiPSysEmitterDeclinationCtlr.cpp obj/NiPSysEmitterDeclinationVarCtlr.cpp obj/NiPSysEmitterInitialRadiusCtlr.cpp obj/NiPSysEmitterLifeSpanCtlr.cpp obj/NiPSysEmitterSpeedCtlr.cpp obj/NiPSysGravityModifier.cpp obj/NiPSysGravityStrengthCtlr.cpp obj/NiPSysGrowFadeModifier.cpp obj/NiPSysMeshEmitter.cpp obj/NiPSysMeshUpdateModifier.cpp obj/NiPSysModifierActiveCtlr.cpp obj/NiPSysPlanarCollider.cpp obj/NiPSysPositionModifier.cpp obj/NiPSysResetOnLoopCtlr.cpp obj/NiPSysRotationModifier.cpp obj/NiPSysSpawnModifier.cpp obj/NiPSysSphereEmitter.cpp obj/NiPSysUpdateCtlr.cpp obj/NiRangeLODData.cpp obj/NiRotatingParticles.cpp obj/NiRotatingParticlesData.cpp obj/NiScreenLODData.cpp obj/NiSequenceStreamHelper.cpp obj/NiShadeProperty.cpp obj/NiSkinData.cpp obj/NiSkinInstance.cpp obj/NiSkinPartition.cpp obj/NiSourceTexture.cpp obj/NiSpecularProperty.cpp obj/NiSphericalCollider.cpp obj/NiSpotLight.cpp obj/NiStencilProperty.cpp obj/NiStringExtraData.cpp obj/NiStringPalette.cpp obj/NiStringsExtraData.cpp obj/NiTextKeyExtraData.cpp obj/NiTextureEffect.cpp obj/NiTextureTransformController.cpp obj/NiTexturingProperty.cpp obj/NiTransformController.cpp obj/NiTransformData.cpp obj/NiTransformInterpolator.cpp obj/NiTriShape.cpp obj/NiTriShapeData.cpp obj/NiTriStrips.cpp obj/NiTriStripsData.cpp obj/NiUVController.cpp obj/NiUVData.cpp obj/NiVectorExtraData.cpp obj/NiVertexColorProperty.cpp obj/NiVertWeightsExtraData.cpp obj/NiVisController.cpp obj/NiVisData.cpp obj/NiWireframeProperty.cpp obj/NiZBufferProperty.cpp obj/RootCollisionNode.cpp '

niflib = env.StaticLibrary('niflib', Split('niflib.cpp nif_math.cpp NIF_IO.cpp kfm.cpp docsys_extract.cpp obj/Type.cpp ' + objfiles), CPPPATH = '.', CPPFLAGS = cppflags)
#nifshlib = env.SharedLibrary('_niflib', 'pyniflib.i', LIBS=['niflib'] + python_lib, LIBPATH=['.'] + python_libpath, SWIGFLAGS = '-c++ -python', CPPPATH = ['.'] + python_include, CPPFLAGS = cppflags, SHLIBPREFIX='')
# makes sure niflib.lib is built before trying to build _niflib.dll
#env.Depends(nifshlib, niflib)


# Here's how to compile niflyze:
#env.Program('niflyze', 'niflyze.cpp', LIBS=['niflib'], LIBPATH=['.'], CPPFLAGS = cppflags)

# A test program:
#env.Program('test', 'test.cpp', LIBS=['niflib'], LIBPATH=['.'], CPPFLAGS = cppflags)

