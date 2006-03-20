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
niflib = env.StaticLibrary('niflib', Split('niflib.cpp nif_math.cpp NIF_Blocks.cpp NIF_IO.cpp docsys_extract.cpp kfm.cpp'), CPPPATH = '.', CPPFLAGS = cppflags)
nifshlib = env.SharedLibrary('_niflib', 'pyniflib.i', LIBS=['niflib'] + python_lib, LIBPATH=['.'] + python_libpath, SWIGFLAGS = '-c++ -python', CPPPATH = ['.'] + python_include, CPPFLAGS = cppflags, SHLIBPREFIX='')
# makes sure niflib.lib is built before trying to build _niflib.dll
env.Depends(nifshlib, niflib)


# Here's how to compile niflyze:
#env.Program('niflyze', 'niflyze.cpp', LIBS=['niflib'], LIBPATH=['.'], CPPFLAGS = cppflags)

# A test program:
#env.Program('test', 'test.cpp', LIBS=['niflib'], LIBPATH=['.'], CPPFLAGS = cppflags)
