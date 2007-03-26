import commands
import sys
import os
import time
from distutils import sysconfig
import nifxml

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



gen_objfiles = []
for n in nifxml.compound_names:
    x = nifxml.compound_types[n]
    if n[:3] != 'ns ' and not x.niflibtype and not x.template:
        gen_objfiles.append('src/gen/' + str(n) + '.cpp')

obj_objfiles = []
for n in nifxml.block_names:
    obj_objfiles.append('src/obj/' +  str(n) + '.cpp')

core_objfiles = Split("""
src/ComplexShape.cpp
src/niflib.cpp
src/nif_math.cpp
src/NIF_IO.cpp
src/kfm.cpp
src/Type.cpp
src/gen/obj_factories.cpp
src/gen/enums.cpp
src/gen/obj_impl.cpp
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

Export('env nifxml python_lib python_libpath python_include niflib')

# build python wrapper
if SWIG:
    niflib_swig = SConscript('swig/SConscript')
    Export('niflib_swig')

# build the test suite
if TEST:
    SConscript('test/SConscript')

