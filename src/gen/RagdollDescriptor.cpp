/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#include "../../include/gen/RagdollDescriptor.h"
using namespace Niflib;

//Constructor
RagdollDescriptor::RagdollDescriptor() : coneMaxAngle(0.0f), planeMinAngle(0.0f), planeMaxAngle(0.0f), twistMinAngle(0.0f), twistMaxAngle(0.0f), maxFriction(0.0f), unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownFloat4(0.0f), unknownFloat5(0.0f), unknownFloat6(0.0f), unknownFloat7(0.0f) {};

//Copy Constructor
RagdollDescriptor::RagdollDescriptor( const RagdollDescriptor & src ) {
	*this = src;
};

//Copy Operator
RagdollDescriptor & RagdollDescriptor::operator=( const RagdollDescriptor & src ) {
	this->pivotA = src.pivotA;
	this->planeA = src.planeA;
	this->twistA = src.twistA;
	this->pivotB = src.pivotB;
	this->planeB = src.planeB;
	this->twistB = src.twistB;
	this->coneMaxAngle = src.coneMaxAngle;
	this->planeMinAngle = src.planeMinAngle;
	this->planeMaxAngle = src.planeMaxAngle;
	this->twistMinAngle = src.twistMinAngle;
	this->twistMaxAngle = src.twistMaxAngle;
	this->maxFriction = src.maxFriction;
	this->unknownFloat1 = src.unknownFloat1;
	this->unknownFloat2 = src.unknownFloat2;
	this->unknownFloat3 = src.unknownFloat3;
	this->unknownFloat4 = src.unknownFloat4;
	this->unknownFloat5 = src.unknownFloat5;
	this->unknownFloat6 = src.unknownFloat6;
	this->unknownFloat7 = src.unknownFloat7;
	return *this;
};

//Destructor
RagdollDescriptor::~RagdollDescriptor() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
