/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/HingeDescriptor.h"
using namespace Niflib;

//Constructor
HingeDescriptor::HingeDescriptor() : unknownFloat1(0.0f), unknownInt2(0.0f), unknownInt3(0.0f), unknownInt4(0.0f), unknownInt5(0.0f), unknownInt6(0.0f), unknownInt7(0.0f), unknownInt8(0.0f), unknownInt9(0.0f), unknownInt10(0.0f), unknownByte1((byte)0), unknownByte2((byte)0), unknownByte3((byte)0) {};

//Copy Constructor
HingeDescriptor::HingeDescriptor( const HingeDescriptor & src ) {
	*this = src;
};

//Copy Operator
HingeDescriptor & HingeDescriptor::operator=( const HingeDescriptor & src ) {
	this->pivotA = src.pivotA;
	this->perp2AxleInA1 = src.perp2AxleInA1;
	this->perp2AxleInA2 = src.perp2AxleInA2;
	this->pivotB = src.pivotB;
	this->axleB = src.axleB;
	this->unknownFloat1 = src.unknownFloat1;
	this->unknownInt2 = src.unknownInt2;
	this->unknownInt3 = src.unknownInt3;
	this->unknownInt4 = src.unknownInt4;
	this->unknownInt5 = src.unknownInt5;
	this->unknownInt6 = src.unknownInt6;
	this->unknownInt7 = src.unknownInt7;
	this->unknownInt8 = src.unknownInt8;
	this->unknownInt9 = src.unknownInt9;
	this->unknownInt10 = src.unknownInt10;
	this->unknownByte1 = src.unknownByte1;
	this->unknownByte2 = src.unknownByte2;
	this->unknownByte3 = src.unknownByte3;
	return *this;
};

//Destructor
HingeDescriptor::~HingeDescriptor() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
