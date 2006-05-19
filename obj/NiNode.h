/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NINODE_H_
#define _NINODE_H_

#include "NiAVObject.h"

/*
 * NiNode - A basic scene graph node.  Can have children.
 */

class NiNode;

typedef Ref<NiNode> NiNodeRef;

class NiNode : public NiAVObject {
public:
	NiNode() {}
	~NiNode() {}
	//Run-Time Type Information
	static const Type TYPE;

	//TODO:  Add functions to get and set children and store a list of NiObjectNET references
};

#endif