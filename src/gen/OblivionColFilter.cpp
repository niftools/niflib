/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/OblivionColFilter.h"
using namespace Niflib;

//Constructor
OblivionColFilter::OblivionColFilter() : colFilter((byte)0), unknownShort((ushort)0) {};

//Copy Constructor
OblivionColFilter::OblivionColFilter( const OblivionColFilter & src ) {
	*this = src;
};

//Copy Operator
OblivionColFilter & OblivionColFilter::operator=( const OblivionColFilter & src ) {
	this->layer = src.layer;
	this->colFilter = src.colFilter;
	this->unknownShort = src.unknownShort;
	return *this;
};

//Destructor
OblivionColFilter::~OblivionColFilter() {};
