/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/ByteArray.h"
using namespace Niflib;

//Constructor
ByteArray::ByteArray() : dataSize((uint)0) {};

//Copy Constructor
ByteArray::ByteArray( const ByteArray & src ) {
	*this = src;
};

//Copy Operator
ByteArray & ByteArray::operator=( const ByteArray & src ) {
	this->dataSize = src.dataSize;
	this->data = src.data;
	return *this;
};

//Destructor
ByteArray::~ByteArray() {};
