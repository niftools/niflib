/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/RagDollDescriptor.h"
using namespace Niflib;

//Constructor
RagDollDescriptor::RagDollDescriptor() : coneMinAngle(0.0f), planeMinAngle(0.0f), planeMaxAngle(0.0f), twistMinAngle(0.0f), twistMaxAngle(0.0f), maxFriction(0.0f) {};

//Copy Constructor
RagDollDescriptor::RagDollDescriptor( const RagDollDescriptor & src ) {
	*this = src;
};

//Copy Operator
RagDollDescriptor & RagDollDescriptor::operator=( const RagDollDescriptor & src ) {
	this->pivotA = src.pivotA;
	this->planeA = src.planeA;
	this->twistA = src.twistA;
	this->pivotB = src.pivotB;
	this->planeB = src.planeB;
	this->twistB = src.twistB;
	this->coneMinAngle = src.coneMinAngle;
	this->planeMinAngle = src.planeMinAngle;
	this->planeMaxAngle = src.planeMaxAngle;
	this->twistMinAngle = src.twistMinAngle;
	this->twistMaxAngle = src.twistMaxAngle;
	this->maxFriction = src.maxFriction;
	return *this;
};

//Destructor
RagDollDescriptor::~RagDollDescriptor() {};
