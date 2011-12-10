/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/bhkCMSD_Shape.h"
using namespace Niflib;

//Constructor
bhkCMSD_Shape::bhkCMSD_Shape() : numShape((unsigned int)0) {};

//Copy Constructor
bhkCMSD_Shape::bhkCMSD_Shape( const bhkCMSD_Shape & src ) {
	*this = src;
};

//Copy Operator
bhkCMSD_Shape & bhkCMSD_Shape::operator=( const bhkCMSD_Shape & src ) {
	this->numShape = src.numShape;
	this->shape = src.shape;
	return *this;
};

//Destructor
bhkCMSD_Shape::~bhkCMSD_Shape() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
