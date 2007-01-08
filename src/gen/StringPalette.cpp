/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/StringPalette.h"
using namespace Niflib;

//Constructor
StringPalette::StringPalette() : length((unsigned int)0) {};

//Copy Constructor
StringPalette::StringPalette( const StringPalette & src ) {
	*this = src;
};

//Copy Operator
StringPalette & StringPalette::operator=( const StringPalette & src ) {
	this->palette = src.palette;
	this->length = src.length;
	return *this;
};

//Destructor
StringPalette::~StringPalette() {};
