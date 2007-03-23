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
JOBS = 1                      # default number of jobs, if detection fails
DETECT_JOBS = True            # set this to False, if you are setting JOBS
DEBUG = True                  # turn on debugging info?
CFFLAGS_EXTRA_WARNING = False # extra compiler warnings
SWIG = True                   # build the swig python wrapper?
TEST = True                   # build test scripts?

# Setting up a basic default environment
# Theory is it can be expanded for versatility, like swig doesn't seem to like jobs of 4

env = Environment(ENV = os.environ)

env.Append(SWIGFLAGS = ' -c++ -python -fcompact -fvirtual')

# linux platform
if sys.platform in ['linux2', 'linux-i386', 'cygwin']:
    # set python environment
    python_lib = ['python%d.%d' % sys.version_info[0:2]]
    python_libpath = [sysconfig.get_python_lib (0, 1) + '/config']
    python_include = [sysconfig.get_python_inc ()]
    # set compiler flags
    env.Append(CCFLAGS = ' -Wall')
    if CFFLAGS_EXTRA_WARNING:
         env.Append(CCFLAGS = ' -Wextra')
    if sys.platform != 'cygwin':
        env.Append(CCFLAGS = ' -fPIC -pipe')
    # flags for debugging info
    if DEBUG:
         env.Append(CCFLAGS = ' -O0 -g3 -ggdb')
    # flags for tuning (only if DEBUG is False)
    else:
       env.Append(CCFLAGS = ' -O3')
       # architecture specific tuning
       # x86, x86_64, or what? (better way?)
       proc = commands.getoutput('uname -m')
       if proc == 'x86_64':
           arch = 'x86_64'
       #elif exp.match(proc): # broken
       elif proc in ['x86', 'i386', 'i486', 'i586', 'i686']:
           arch = 'x86'
       elif proc in ['Power Macintosh', 'ppc']:
           arch = 'ppc'
       else:
           arch = None
       # needs to be cleaned up and expanded to include Intel
       if arch == 'x86_64':
           if commands.getoutput('uname -i') == 'AuthenticAMD':
               env.Append(CCFLAGS = ' -mtune=k8')
           #elif commands.getoutput('uname -i') == 'GenuineIntel':
           #    env.Append(CCFLAGS = ' -mtune=nocona')
    # detect the number of processors, and set number of jobs accordingly
    if DETECT_JOBS:
        detected_jobs = int(commands.getoutput('cat /proc/cpuinfo | grep -c "^processor"'))
        if detected_jobs >= 2:
            JOBS = detected_jobs

# windows platform
elif sys.platform == 'win32':
    python_include = [sysconfig.get_python_inc()]
    python_libpath = [sysconfig.get_python_lib(1, 1) + '/../libs']
    python_lib = ['python24']
    env.Append(CCFLAGS = '/EHsc /GS /TP')
    if DEBUG:
        env.Append(CCFLAGS = ' /Zi')
    else:
        env.Append(CCFLAGS = ' /O2')

# other platforms
else:
    print "Error: Platform %s not supported."%sys.platform
    Exit(1)

# set number of jobs
env.SetOption('num_jobs', JOBS)

# detect SWIG
try:
    env['SWIG']
except KeyError:
    SWIG = False
    print """
Warning: SWIG not found. The python wrapper will not be built.
Please install SWIG to build the python wrapper."""
    if sys.platform == "win32": print "Also add the SWIG directory to your %PATH%."
    print "You can download SWIG from http://www.swig.org/\n"



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

# build niflib shared library
# (SCons bug: under windows, SharedLibrary should also build .lib file, but this is broken; so for now just build static one)
if sys.platform == 'win32':
    niflib = env.StaticLibrary('niflib', [core_objfiles, gen_objfiles, obj_objfiles, NvTriStrip_files, TriStripper_files] , LIBPATH='.', CPPPATH = '.')
else:
    niflib = env.SharedLibrary('niflib', [core_objfiles, gen_objfiles, obj_objfiles, NvTriStrip_files, TriStripper_files] , LIBPATH='.', CPPPATH = '.')

Export('env python_lib python_libpath python_include niflib')

# build python wrapper
if SWIG:
    niflib_swig = SConscript('swig/SConscript')
    Export('niflib_swig')

# build the test suite
if TEST:
    SConscript('test/SConscript')

