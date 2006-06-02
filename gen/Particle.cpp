/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "Particle.h"

//Constructor
Particle::Particle() : lifetime(0.0f), lifespan(0.0f), timestamp(0.0f), unknownShort((ushort)0), vertexId((ushort)0) {};

//Destructor
Particle::~Particle() {};
