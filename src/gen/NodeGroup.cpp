/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/NodeGroup.h"
#include "../../include/obj/NiNode.h"
using namespace Niflib;

//Constructor
NodeGroup::NodeGroup() : numNodes((unsigned int)0) {};

//Copy Constructor
NodeGroup::NodeGroup( const NodeGroup & src ) {
	*this = src;
};

//Copy Operator
NodeGroup & NodeGroup::operator=( const NodeGroup & src ) {
	this->numNodes = src.numNodes;
	this->nodes = src.nodes;
	return *this;
};

//Destructor
NodeGroup::~NodeGroup() {};
