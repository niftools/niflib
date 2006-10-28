######
## Generate Py++ inclusion header
######

import wrapper_config

# Set the paths to be searched for header files
header_paths = [
    wrapper_config.niflib_path + "/include",
    wrapper_config.niflib_path + "/include/gen",
    wrapper_config.niflib_path + "/include/obj"
]

# Set explicit includes
header_include = [
    wrapper_config.niflib_path + "/include/niflib.h",
    wrapper_config.niflib_path + "/include/Ref.h",
    wrapper_config.niflib_path + "/include/Type.h",
    wrapper_config.niflib_path + "/include/nif_math.h",
    wrapper_config.niflib_path + "/include/Key.h",
    wrapper_config.niflib_path + "/include/nif_basic_types.h"
]

# Set the regexps for file exclusion
header_exclude = [
    "niflib/include/[a-zA-Z\.\_\-]+\.h"
]

####

import os, re

def hasExtension(file, ext):
    fext = file.rsplit('.', -1)[-1]
    return (fext in ext)

header = []
pattern = "|".join(header_exclude)
p = re.compile(pattern)

for path in header_paths:
    dir_files = os.listdir(path)
    for file in dir_files:
        m = p.match(path + '/' + file)
        if m:
            continue
        if hasExtension(file, ['h', 'hpp']):
            header_include.append(path +'/' + file)

for file in header_include:
    header.append("#include \"%s\"\n" % file)

#header.append("using namespace Niflib;\n\n");
header.append("\n");
header.append("/* This namespace is not going to be exported */\n")
header.append("namespace NoExport {\n\n")
header.append("  /* Auxiliary function for template export */\n")
header.append("  inline void export_obj_templates() {\n")
header.append("    Niflib::NiObjectRef CastObj;\n\n")

NiObjects = []
for obj in os.listdir(wrapper_config.niflib_path + "/include/obj"):
    obj_ = obj.split('.', 2)[0]
    if hasExtension(obj, 'h') and not obj_ in NiObjects:
        NiObjects.append(obj_)

for obj in NiObjects:
    header.append("  /* Object %s */\n" % obj)
    #header.append("    typedef Niflib::Ref<Niflib::%s> %sRef;\n" % (obj, obj))
    #header.append("    sizeof(%sRef);\n" % obj)
    header.append("    sizeof(Niflib::Ref<Niflib::%s>);\n" % obj)
    header.append("    Niflib::DynamicCast<Niflib::%s>(CastObj);\n" % obj)
    header.append("    Niflib::StaticCast <Niflib::%s>(CastObj);\n" % obj)
    header.append("    \n")
    
header.append("  /* Internal Containers */\n")
for int_cont in wrapper_config.internal_containers:
	header.append("    sizeof(%s);\n" % int_cont)
header.append("\n")

header.append("  }\n\n")
header.append("}\n\n")

headerfile = open("pyNiflib.h","w")
headerfile.writelines(header)
headerfile.close()

project_files = [ r"pyNiflib.h" ]
for hfile in header_include:
    basename = hfile.rsplit(".", 2)[0]
    #project_files.append(r"%s.cpp" % basename)
