/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/SkinData.h"
#include "../../include/gen/SkinWeight.h"
using namespace Niflib;

//Constructor
SkinData::SkinData() : scale(0.0f), boundingSphereRadius(0.0f), numVertices((ushort)0) {};

//Copy Constructor
SkinData::SkinData( const SkinData & src ) {
	*this = src;
};

//Copy Operator
SkinData & SkinData::operator=( const SkinData & src ) {
	this->rotation = src.rotation;
	this->translation = src.translation;
	this->scale = src.scale;
	this->boundingSphereOffset = src.boundingSphereOffset;
	this->boundingSphereRadius = src.boundingSphereRadius;
	this->numVertices = src.numVertices;
	this->vertexWeights = src.vertexWeights;
	return *this;
};

//Destructor
SkinData::~SkinData() {};
