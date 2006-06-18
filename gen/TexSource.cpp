/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "TexSource.h"
#include "../obj/NiObject.h"
#include "../obj/NiPixelData.h"
using namespace NifLib;

//Constructor
TexSource::TexSource() : useExternal((byte)0), unknownLink(NULL), unknownByte((byte)0), pixelData(NULL) {};

//Destructor
TexSource::~TexSource() {};
