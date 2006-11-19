/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/LODRange.h"
using namespace Niflib;

//Constructor
LODRange::LODRange() : nearExtent(0.0f), farExtent(0.0f) {};

//Copy Constructor
LODRange::LODRange( const LODRange & src ) {
	*this = src;
};

//Copy Operator
LODRange & LODRange::operator=( const LODRange & src ) {
	this->nearExtent = src.nearExtent;
	this->farExtent = src.farExtent;
	return *this;
};

//Destructor
LODRange::~LODRange() {};
