/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/bhkCMSD_Something.h"
using namespace Niflib;

//Constructor
bhkCMSD_Something::bhkCMSD_Something() : largeInt((unsigned int)0), unknownInteger((unsigned int)0) {};

//Copy Constructor
bhkCMSD_Something::bhkCMSD_Something( const bhkCMSD_Something & src ) {
	*this = src;
};

//Copy Operator
bhkCMSD_Something & bhkCMSD_Something::operator=( const bhkCMSD_Something & src ) {
	this->largeInt = src.largeInt;
	this->unknownInteger = src.unknownInteger;
	return *this;
};

//Destructor
bhkCMSD_Something::~bhkCMSD_Something() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
