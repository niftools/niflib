/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "gen/Header.h"
#include "gen/ShortString.h"
#include "gen/ShortString.h"
#include "gen/ShortString.h"

//Constructor
Header::Header() : version((uint)0x04000002), endianType((byte)1), userVersion((uint)0), numBlocks((uint)0), unknownInt1((uint)0), unknownInt3((uint)0), numBlockTypes((ushort)0), unknownInt2((uint)0) {};

//Destructor
Header::~Header() {};
