Import('*')

# set up environment

env_niflib = env.Copy()

if sys.platform == 'win32':
    env_niflib.Append(CCFLAGS = '/D "BUILDING_NIFLIB_DLL"')
else:
    env_niflib.Append(CCFLAGS = '-DBUILDING_NIFLIB_DLL')

# generate code

os.system('cd ' + os.path.join('..', 'docsys') + ' && python nifxml_niflib.py -p ' + os.path.join('..' , 'niflib'))

# list source files

src_files = []

for n in nifxml.compound_names:
    x = nifxml.compound_types[n]
    if n[:3] != 'ns ' and not x.niflibtype and not x.template:
        src_files.append('src/gen/' + str(n) + '.cpp')

for n in nifxml.block_names:
    src_files.append('src/obj/' +  str(n) + '.cpp')

src_files.extend(Split("""
src/ComplexShape.cpp
src/niflib.cpp
src/nif_math.cpp
src/NIF_IO.cpp
src/kfm.cpp
src/Type.cpp
src/gen/obj_factories.cpp
src/gen/enums.cpp
src/gen/obj_impl.cpp
TriStripper/connectivity_graph.cpp
TriStripper/policy.cpp
TriStripper/tri_stripper.cpp
NvTriStrip/NvTriStrip.cpp
NvTriStrip/NvTriStripObjects.cpp
NvTriStrip/VertexCache.cpp
"""))

# build niflib

niflib = env_niflib.SharedLibrary('niflib', src_files)

Export('niflib')
