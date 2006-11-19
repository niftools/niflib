/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/SkinShapeGroup.h"
#include "../../include/gen/SkinShape.h"
#include "../../include/obj/NiTriShape.h"
#include "../../include/obj/NiSkinInstance.h"
using namespace Niflib;

//Constructor
SkinShapeGroup::SkinShapeGroup() : numLinkPairs((uint)0) {};

//Copy Constructor
SkinShapeGroup::SkinShapeGroup( const SkinShapeGroup & src ) {
	*this = src;
};

//Copy Operator
SkinShapeGroup & SkinShapeGroup::operator=( const SkinShapeGroup & src ) {
	this->numLinkPairs = src.numLinkPairs;
	this->linkPairs = src.linkPairs;
	return *this;
};

//Destructor
SkinShapeGroup::~SkinShapeGroup() {};
