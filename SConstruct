import sys
import os
from distutils import sysconfig

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
    print "platform %s not supported"%sys.platform

env = Environment(ENV = os.environ)

env.StaticLibrary('niflib', Split('niflib.cpp nif_math.cpp NIF_Blocks.cpp NIF_IO.cpp docsys_extract.cpp'), CPPPATH = '.', CPPFLAGS = cppflags)
env.SharedLibrary('_niflib', 'pyniflib.i', LIBS=['niflib'] + python_lib, LIBPATH=['.'] + python_libpath, SWIGFLAGS = '-c++ -python', CPPPATH = ['.'] + python_include, CPPFLAGS = cppflags, SHLIBPREFIX='')

# Here's how to compile niflyze:
env.Program('niflyze', 'niflyze.cpp', LIBS=['niflib'], LIBPATH=['.'], CPPFLAGS = cppflags)

# A test program:
env.Program('test', 'test.cpp', LIBS=['niflib'], LIBPATH=['.'], CPPFLAGS = cppflags)
