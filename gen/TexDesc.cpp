/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "TexDesc.h"
#include "../obj/NiSourceTexture.h"

//Constructor
TexDesc::TexDesc() : source(NULL), clampMode((TexClampMode)WRAP_S_WRAP_T), filterMode((TexFilterMode)FILTER_TRILERP), textureSet((uint)0), ps2L((ushort)0), ps2K((ushort)0xFFB5), unknown1((ushort)0), hasTextureTransform(false), wRotation(0.0f), transformType_((uint)0) {};

//Destructor
TexDesc::~TexDesc() {};
