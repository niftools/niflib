/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/OblivionSubShape.h"
using namespace Niflib;

//Constructor
OblivionSubShape::OblivionSubShape() : colFilter((byte)0), unknownShort((ushort)0), vertexCount___((uint)0) {};

//Copy Constructor
OblivionSubShape::OblivionSubShape( const OblivionSubShape & src ) {
	*this = src;
};

//Copy Operator
OblivionSubShape & OblivionSubShape::operator=( const OblivionSubShape & src ) {
	this->layer = src.layer;
	this->colFilter = src.colFilter;
	this->unknownShort = src.unknownShort;
	this->vertexCount___ = src.vertexCount___;
	this->material = src.material;
	return *this;
};

//Destructor
OblivionSubShape::~OblivionSubShape() {};
