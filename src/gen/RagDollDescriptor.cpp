/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/RagDollDescriptor.h"
using namespace Niflib;

//Constructor
RagDollDescriptor::RagDollDescriptor() : coneMinAngle(0.0f), planeMinAngle(0.0f), planeMaxAngle(0.0f), twistMinAngle(0.0f), twistMaxAngle(0.0f), maxFriction(0.0f) {};

//Destructor
RagDollDescriptor::~RagDollDescriptor() {};
