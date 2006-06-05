/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _MATCHGROUP_H_
#define _MATCHGROUP_H_

#include "../NIF_IO.h"


/*!
 * Group of vertex indices of vertices that match.
 */
struct MatchGroup {
	/*! Default Constructor */
	MatchGroup();
	/*! Default Destructor */
	~MatchGroup();
	/*!
	 * Number of vertices in this group.
	 */
	ushort numVertices;
	/*!
	 * The vertex indices.
	 */
	vector<ushort > vertexIndices;
};

#endif
