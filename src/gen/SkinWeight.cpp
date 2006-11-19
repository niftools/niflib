/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/SkinWeight.h"
using namespace Niflib;

//Constructor
SkinWeight::SkinWeight() : index((ushort)0), weight(0.0f) {};

//Copy Constructor
SkinWeight::SkinWeight( const SkinWeight & src ) {
	*this = src;
};

//Copy Operator
SkinWeight & SkinWeight::operator=( const SkinWeight & src ) {
	this->index = src.index;
	this->weight = src.weight;
	return *this;
};

//Destructor
SkinWeight::~SkinWeight() {};
