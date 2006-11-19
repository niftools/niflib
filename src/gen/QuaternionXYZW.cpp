/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/QuaternionXYZW.h"
using namespace Niflib;

//Constructor
QuaternionXYZW::QuaternionXYZW() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {};

//Copy Constructor
QuaternionXYZW::QuaternionXYZW( const QuaternionXYZW & src ) {
	*this = src;
};

//Copy Operator
QuaternionXYZW & QuaternionXYZW::operator=( const QuaternionXYZW & src ) {
	this->x = src.x;
	this->y = src.y;
	this->z = src.z;
	this->w = src.w;
	return *this;
};

//Destructor
QuaternionXYZW::~QuaternionXYZW() {};
