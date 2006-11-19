/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/MipMap.h"
using namespace Niflib;

//Constructor
MipMap::MipMap() : width((uint)0), height((uint)0), offset((uint)0) {};

//Copy Constructor
MipMap::MipMap( const MipMap & src ) {
	*this = src;
};

//Copy Operator
MipMap & MipMap::operator=( const MipMap & src ) {
	this->width = src.width;
	this->height = src.height;
	this->offset = src.offset;
	return *this;
};

//Destructor
MipMap::~MipMap() {};
