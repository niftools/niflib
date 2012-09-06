/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/bhkCMSDContainer.h"
#include "../../include/gen/bhkCMSDBigTris.h"
using namespace Niflib;

//Constructor
bhkCMSDContainer::bhkCMSDContainer() : unknownInt((unsigned int)0), unknownShort1((unsigned short)0), unknownShort2((unsigned short)0) {};

//Copy Constructor
bhkCMSDContainer::bhkCMSDContainer( const bhkCMSDContainer & src ) {
	*this = src;
};

//Copy Operator
bhkCMSDContainer & bhkCMSDContainer::operator=( const bhkCMSDContainer & src ) {
	this->unknownFloats = src.unknownFloats;
	this->unknownInt = src.unknownInt;
	this->unknownShort1 = src.unknownShort1;
	this->unknownShort2 = src.unknownShort2;
	this->shape = src.shape;
	return *this;
};

//Destructor
bhkCMSDContainer::~bhkCMSDContainer() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
