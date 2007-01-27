import commands
import sys
import os
import time
from distutils import sysconfig

Help("""
'scons' to build niflib library and niflib python wrapper
'scons -c' to clean
""")

##Global Vars, should add cc, cxx, build, etc eventually...
##May want to turn Jobs down, we will try and detect an appropriate JOB rate for linux
JOBS ='1'
DETECT_JOBS = 'yes'  #Set this to no, if you are setting JOBS!!
DEBUG ='no'
TUNE ='yes'
CFFLAGS_EXTRA_WARNING ='no'


#Setting up a basic default environment
#Theory is it can be expanded for versatility, like swig doesn't seem to like jobs of 4
#env = Environment(ENV = os.environ)

env = Environment(ENV = os.environ)


#OLD detect platform
if sys.platform == 'linux2' or sys.platform == 'linux-i386':
    OS = 'linux'
    python_lib = ['python%d.%d' % sys.version_info[0:2]]
    python_libpath = [sysconfig.get_python_lib (0, 1) + '/config']
    python_include = [sysconfig.get_python_inc ()]
    env.Append(CCFLAGS = ' -Iinclude -fPIC -Wall -pipe')
elif sys.platform == 'cygwin':
    python_lib = ['python%d.%d' % sys.version_info[0:2]]
    python_libpath = [sysconfig.get_python_lib (0, 1) + '/config']
    python_include = [sysconfig.get_python_inc ()]
    env.Append(CCFLAGS = ' -Wall')
elif sys.platform == 'win32':
    python_include = [sysconfig.get_python_inc()]
    python_libpath = [sysconfig.get_python_lib(1, 1) + '/../libs']
    python_lib = ['python24']
    env.Append(CCFLAGS = '/EHsc /O2 /GS /Zi /TP')
else:
    print "Error: Platform %s not supported."%sys.platform
    Exit(1)



#Debug, Extra, 02 checks
if (sys.platform == 'linux2' or sys.platform == 'linux-i386') or sys.platform == 'cygwin':
    if DEBUG == 'yes':
         env.Append(CCFLAGS = ' -g3')
    if CFFLAGS_EXTRA_WARNING == 'yes':
         env.Append(CCFLAGS = ' -Wextra')
    if TUNE == 'yes':
       env.Append(CCFLAGS = ' -O2')
    if TUNE == 'yes' and DEBUG == 'yes' :
	print "TUNE and DEBUG may conflict!!"



# Proc x86, x86_64, or what? Better way?
proc = commands.getoutput('uname -m')
if proc == 'x86_64':
  arch = 'x86_64'
elif exp.match(proc):
  arch = 'x86'
elif proc == 'Power Macintosh' or proc == 'ppc':
  arch = 'ppc'
else:
  arch = 'cpu'

#This is ugly, needs to be cleaned up and expanded to include Intel.
#
if arch == 'x86_64' and TUNE == 'yes':
   if commands.getoutput('uname -i') == 'AuthenticAMD':
      env.Append(CCFLAGS = ' -mtune=k8')
#   if commands.getoutput('uname -i') == 'GenuineIntel':
#	env.Append(CCFLAGS = ' -mtune=nocona')
#Should cover 64 bit versions of Intel chips, but don't have one and never bothered to look into it



#We want to detect the number of jobs! Although some folks depending on sys load may want to set it more aggressively.
if DETECT_JOBS == 'yes' and OS == 'linux':
	detected_jobs = commands.getoutput('cat /proc/cpuinfo | grep -c processor')
	if detected_jobs >= '2' :
		print "Detected Jobs: %s"%detected_jobs
		JOBS = detected_jobs
		print "Detected Jobs changing to %s"%JOBS
	else :
		print "Error Detecting jobs!"


env.SetOption('num_jobs', JOBS)


# detect SWIG
#try:
#    env['SWIG']
#except KeyError:
#    print """
#Error: SWIG not found.
#Please install SWIG, it's needed to create the python wrapper.
#You can get it from http://www.swig.org/"""
#    if sys.platform == "win32": print "Also don't forget to add the SWIG #directory to your %PATH%."
#    Exit(1)


gen_objfiles = Split("""
src/gen/ByteArray.cpp
src/gen/Footer.cpp
src/gen/LODRange.cpp
src/gen/MatchGroup.cpp
src/gen/MipMap.cpp
src/gen/NodeGroup.cpp
src/gen/QuaternionXYZW.cpp
src/gen/SkinShape.cpp
src/gen/SkinShapeGroup.cpp
src/gen/SkinWeight.cpp
src/gen/AVObject.cpp
src/gen/ControllerLink.cpp
src/gen/Header.cpp
src/gen/StringPalette.cpp
src/gen/TBC.cpp
src/gen/TexDesc.cpp
src/gen/ShaderTexDesc.cpp
src/gen/TexSource.cpp
src/gen/SkinPartition.cpp
src/gen/BoundingBox.cpp
src/gen/FurniturePosition.cpp
src/gen/hkTriangle.cpp
src/gen/Morph.cpp
src/gen/Particle.cpp
src/gen/SkinData.cpp
src/gen/RagDollDescriptor.cpp
src/gen/LimitedHingeDescriptor.cpp
src/gen/Sphere.cpp
src/gen/enums.cpp
src/gen/obj_impl.cpp
src/gen/OblivionColFilter.cpp
src/gen/OblivionSubShape.cpp
""")

obj_objfiles = Split("""
src/obj/NiObject.cpp
src/obj/AKeyedData.cpp
src/obj/AParticleModifier.cpp
src/obj/bhkRefObject.cpp
src/obj/bhkSerializable.cpp
src/obj/AbhkConstraint.cpp
src/obj/AbhkRagdollConstraint.cpp
src/obj/bhkShape.cpp
src/obj/AbhkShapeCollection.cpp
src/obj/bhkSphereRepShape.cpp
src/obj/bhkConvexShape.cpp
src/obj/bhkWorldObject.cpp
src/obj/bhkEntity.cpp
src/obj/NiCollisionObject.cpp
src/obj/NiExtraData.cpp
src/obj/NiInterpolator.cpp
src/obj/NiBlendInterpolator.cpp
src/obj/NiBSplineInterpolator.cpp
src/obj/NiObjectNET.cpp
src/obj/NiAVObject.cpp
src/obj/NiDynamicEffect.cpp
src/obj/NiLight.cpp
src/obj/NiProperty.cpp
src/obj/NiPSysModifier.cpp
src/obj/NiPSysEmitter.cpp
src/obj/NiPSysVolumeEmitter.cpp
src/obj/NiTimeController.cpp
src/obj/ABoneLODController.cpp
src/obj/NiSingleInterpolatorController.cpp
src/obj/APSysCtlr.cpp src/obj/NiTriBasedGeom.cpp
src/obj/NiTriBasedGeomData.cpp
src/obj/APSysData.cpp
src/obj/bhkBlendCollisionObject.cpp
src/obj/bhkBlendController.cpp
src/obj/bhkBoxShape.cpp
src/obj/bhkCapsuleShape.cpp
src/obj/bhkCollisionObject.cpp
src/obj/bhkConvexVerticesShape.cpp
src/obj/bhkHingeConstraint.cpp
src/obj/bhkLimitedHingeConstraint.cpp
src/obj/bhkListShape.cpp
src/obj/bhkMalleableConstraint.cpp
src/obj/bhkMoppBvTreeShape.cpp
src/obj/bhkMultiSphereShape.cpp
src/obj/bhkNiTriStripsShape.cpp
src/obj/bhkPackedNiTriStripsShape.cpp
src/obj/bhkPrismaticConstraint.cpp
src/obj/bhkRagdollConstraint.cpp
src/obj/bhkRigidBody.cpp
src/obj/bhkRigidBodyT.cpp
src/obj/bhkSimpleShapePhantom.cpp
src/obj/bhkSPCollisionObject.cpp
src/obj/bhkSphereShape.cpp
src/obj/bhkStiffSpringConstraint.cpp
src/obj/bhkTransformShape.cpp
src/obj/bhkConvexTransformShape.cpp
src/obj/BSBound.cpp
src/obj/BSFurnitureMarker.cpp
src/obj/BSParentVelocityModifier.cpp
src/obj/BSPSysArrayEmitter.cpp
src/obj/BSXFlags.cpp
src/obj/hkPackedNiTriStripsData.cpp
src/obj/NiAlphaController.cpp
src/obj/NiAlphaProperty.cpp
src/obj/NiAmbientLight.cpp
src/obj/NiAutoNormalParticlesData.cpp
src/obj/NiBinaryExtraData.cpp
src/obj/NiBlendBoolInterpolator.cpp
src/obj/NiBlendFloatInterpolator.cpp
src/obj/NiBlendPoint3Interpolator.cpp
src/obj/NiBlendTransformInterpolator.cpp
src/obj/NiBoneLODController.cpp
src/obj/NiBoolData.cpp
src/obj/NiBooleanExtraData.cpp
src/obj/NiBoolInterpolator.cpp
src/obj/NiBoolTimelineInterpolator.cpp
src/obj/NiBSBoneLODController.cpp
src/obj/NiBSplineBasisData.cpp
src/obj/NiBSplineCompFloatInterpolator.cpp
src/obj/NiBSplineCompPoint3Interpolator.cpp
src/obj/NiBSplineCompTransformInterpolator.cpp
src/obj/NiBSplineData.cpp
src/obj/NiCamera.cpp src/obj/NiCollisionData.cpp
src/obj/NiColorData.cpp
src/obj/NiColorExtraData.cpp
src/obj/NiControllerManager.cpp
src/obj/NiControllerSequence.cpp
src/obj/NiDefaultAVObjectPalette.cpp
src/obj/NiDirectionalLight.cpp
src/obj/NiDitherProperty.cpp
src/obj/NiFlipController.cpp
src/obj/NiFloatData.cpp
src/obj/NiFloatExtraData.cpp
src/obj/NiFloatExtraDataController.cpp
src/obj/NiFloatInterpolator.cpp
src/obj/NiFloatsExtraData.cpp
src/obj/NiFogProperty.cpp
src/obj/NiGeomMorpherController.cpp
src/obj/NiGravity.cpp
src/obj/NiIntegerExtraData.cpp
src/obj/NiIntegersExtraData.cpp
src/obj/NiKeyframeController.cpp
src/obj/BSKeyframeController.cpp
src/obj/NiKeyframeData.cpp
src/obj/NiLightColorController.cpp
src/obj/NiLightDimmerController.cpp
src/obj/NiLookAtController.cpp
src/obj/NiLookAtInterpolator.cpp
src/obj/NiMaterialColorController.cpp
src/obj/NiMaterialProperty.cpp
src/obj/NiMeshPSysData.cpp
src/obj/NiMorphData.cpp
src/obj/NiMultiTargetTransformController.cpp
src/obj/NiNode.cpp
src/obj/AvoidNode.cpp
src/obj/FxWidget.cpp
src/obj/FxButton.cpp
src/obj/FxRadioButton.cpp
src/obj/NiBillboardNode.cpp
src/obj/NiBSAnimationNode.cpp
src/obj/NiBSParticleNode.cpp
src/obj/NiLODNode.cpp
src/obj/NiPalette.cpp
src/obj/NiParticleBomb.cpp
src/obj/NiParticleColorModifier.cpp
src/obj/NiParticleGrowFade.cpp
src/obj/NiParticleMeshModifier.cpp
src/obj/NiParticleRotation.cpp
src/obj/NiParticles.cpp
src/obj/NiAutoNormalParticles.cpp
src/obj/NiParticleMeshes.cpp
src/obj/NiParticlesData.cpp
src/obj/NiParticleMeshesData.cpp
src/obj/NiParticleSystem.cpp
src/obj/NiMeshParticleSystem.cpp
src/obj/NiParticleSystemController.cpp
src/obj/NiBSPArrayController.cpp
src/obj/NiPathController.cpp
src/obj/NiPathInterpolator.cpp
src/obj/NiPixelData.cpp
src/obj/NiPlanarCollider.cpp
src/obj/NiPoint3Interpolator.cpp
src/obj/NiPointLight.cpp
src/obj/NiPosData.cpp
src/obj/NiPSysAgeDeathModifier.cpp
src/obj/NiPSysBombModifier.cpp
src/obj/NiPSysBoundUpdateModifier.cpp
src/obj/NiPSysBoxEmitter.cpp
src/obj/NiPSysColliderManager.cpp
src/obj/NiPSysColorModifier.cpp
src/obj/NiPSysCylinderEmitter.cpp
src/obj/NiPSysData.cpp
src/obj/NiPSysDragModifier.cpp
src/obj/NiPSysEmitterCtlr.cpp
src/obj/NiPSysEmitterCtlrData.cpp
src/obj/NiPSysEmitterDeclinationCtlr.cpp
src/obj/NiPSysEmitterDeclinationVarCtlr.cpp
src/obj/NiPSysEmitterInitialRadiusCtlr.cpp
src/obj/NiPSysEmitterLifeSpanCtlr.cpp
src/obj/NiPSysEmitterSpeedCtlr.cpp
src/obj/NiPSysGravityModifier.cpp
src/obj/NiPSysGravityStrengthCtlr.cpp
src/obj/NiPSysGrowFadeModifier.cpp
src/obj/NiPSysMeshEmitter.cpp
src/obj/NiPSysMeshUpdateModifier.cpp
src/obj/NiPSysModifierActiveCtlr.cpp
src/obj/NiPSysPlanarCollider.cpp
src/obj/NiPSysPositionModifier.cpp
src/obj/NiPSysResetOnLoopCtlr.cpp
src/obj/NiPSysRotationModifier.cpp
src/obj/NiPSysSpawnModifier.cpp
src/obj/NiPSysSphereEmitter.cpp
src/obj/NiPSysUpdateCtlr.cpp
src/obj/NiRangeLODData.cpp
src/obj/NiRotatingParticles.cpp
src/obj/NiRotatingParticlesData.cpp
src/obj/NiScreenLODData.cpp
src/obj/NiSequenceStreamHelper.cpp
src/obj/NiShadeProperty.cpp
src/obj/NiSkinData.cpp
src/obj/NiSkinInstance.cpp
src/obj/NiSkinPartition.cpp
src/obj/NiSourceTexture.cpp
src/obj/NiSpecularProperty.cpp
src/obj/NiSphericalCollider.cpp
src/obj/NiSpotLight.cpp
src/obj/NiStencilProperty.cpp
src/obj/NiStringExtraData.cpp
src/obj/NiStringPalette.cpp
src/obj/NiStringsExtraData.cpp
src/obj/NiTextKeyExtraData.cpp
src/obj/NiTextureEffect.cpp
src/obj/NiTextureTransformController.cpp
src/obj/NiTexturingProperty.cpp
src/obj/NiTransformController.cpp
src/obj/NiTransformData.cpp
src/obj/NiTransformInterpolator.cpp
src/obj/NiTriShape.cpp
src/obj/NiTriShapeData.cpp
src/obj/NiTriStrips.cpp
src/obj/NiTriStripsData.cpp
src/obj/NiUVController.cpp
src/obj/NiUVData.cpp
src/obj/NiVectorExtraData.cpp
src/obj/NiVertexColorProperty.cpp
src/obj/NiVertWeightsExtraData.cpp
src/obj/NiVisController.cpp
src/obj/NiVisData.cpp
src/obj/NiWireframeProperty.cpp
src/obj/NiZBufferProperty.cpp
src/obj/RootCollisionNode.cpp
src/obj/NiClod.cpp
src/obj/NiClodData.cpp
src/obj/NiClodSkinInstance.cpp
src/obj/NiGeometry.cpp
src/obj/NiTextureModeProperty.cpp
src/obj/NiLODData.cpp
src/obj/NiGeometryData.cpp
src/obj/NiTextureProperty.cpp
src/obj/NiImage.cpp
""")

core_objfiles = Split("""
src/ComplexShape.cpp
src/niflib.cpp
src/nif_math.cpp
src/NIF_IO.cpp
src/kfm.cpp
src/Type.cpp
src/gen/obj_factories.cpp
""")

TriStripper_files = Split("""
TriStripper/connectivity_graph.cpp
TriStripper/policy.cpp
TriStripper/tri_stripper.cpp
""")

NvTriStrip_files = Split("""
NvTriStrip/NvTriStrip.cpp
NvTriStrip/NvTriStripObjects.cpp
NvTriStrip/VertexCache.cpp
""")

nif_converter = Split("""
blender/blender_niflib.cpp
""")

niflib = env.SharedLibrary('niflib', [core_objfiles, gen_objfiles, obj_objfiles, NvTriStrip_files, TriStripper_files], LIBPATH=['.'], CPPPATH = '.')


##
#nifshlib = env.SharedLibrary('_niflib', 'pyniflib.i', LIBS=['niflib'] + python_lib, LIBPATH=['.'] + python_libpath, SWIGFLAGS = '-c++ -python', CPPPATH = ['.'] + python_include, CPPFLAGS = cppflags, SHLIBPREFIX='')
# makes sure niflib.lib is built before trying to build _niflib.dll
#env.Depends(nifshlib, niflib)


# Here's how to compile niflyze:
#env.Program('niflyze', 'niflyze.cpp', LIBS=['niflib'], LIBPATH=['.'], CPPFLAGS = cppflags)

# A test program:
#env.Program('test', 'test.cpp', LIBS=['niflib'], LIBPATH=['.'], CPPFLAGS = cppflags) 