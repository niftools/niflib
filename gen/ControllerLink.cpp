/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "gen/ControllerLink.h"
#include "obj/NiInterpolator.h"
#include "obj/NiObject.h"
#include "obj/NiStringPalette.h"

//Constructor
ControllerLink::ControllerLink() : interpolator(NULL), unknownLink1(NULL), unknownLink2(NULL), unknownShort0((ushort)0), priority_((byte)0), stringPalette(NULL), nodeNameOffset((uint)0), propertyTypeOffset((uint)0), controllerTypeOffset((uint)0), variableOffset1((uint)0), variableOffset2((uint)0) {};

//Destructor
ControllerLink::~ControllerLink() {};
