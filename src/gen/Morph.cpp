/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/Morph.h"
using namespace Niflib;

//Constructor
Morph::Morph() : numKeys((unsigned int)0), unknownInt((unsigned int)0) {};

//Copy Constructor
Morph::Morph( const Morph & src ) {
	*this = src;
};

//Copy Operator
Morph & Morph::operator=( const Morph & src ) {
	this->frameName = src.frameName;
	this->numKeys = src.numKeys;
	this->interpolation = src.interpolation;
	this->keys = src.keys;
	this->unknownInt = src.unknownInt;
	this->vectors = src.vectors;
	return *this;
};

//Destructor
Morph::~Morph() {};
