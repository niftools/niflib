/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NODEGROUP_H_
#define _NODEGROUP_H_

#include "../NIF_IO.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiNode;

/*!
 * A group of NiNodes references.
 */
struct DLLEXPORT NodeGroup {
	/*! Default Constructor */
	NodeGroup();
	/*! Default Destructor */
	~NodeGroup();
	/*!
	 * Number of node references that follow.
	 */
	uint numNodes;
	/*!
	 * The list of NiNode references.
	 */
	vector<Ref<NiNode > > nodes;
};

#endif
