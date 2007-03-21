#ifndef _PYNIFLIB_H_
#define _PYNIFLIB_H_

#include "../include/niflib.h"
#include "../include/obj/NiObject.h"
#include "../include/obj/NiNode.h"

namespace Niflib {

using namespace std;

Niflib::NiNodeRef CreateNiNode() { return Niflib::NiNodeRef(new Niflib::NiNode); }

// SWIG does not like ReadNifTree; so far I have no idea why.
// As a workaround, you can use this wrapper function.
Niflib::NiObjectRef ReadNifFile( string name, Niflib::NifInfo * nifinfo) { return Niflib::ReadNifTree(name, nifinfo);}

};

#endif
