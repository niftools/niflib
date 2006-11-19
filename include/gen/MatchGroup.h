/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _MATCHGROUP_H_
#define _MATCHGROUP_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Group of vertex indices of vertices that match.
 */
struct NIFLIB_API MatchGroup {
	/*! Default Constructor */
	MatchGroup();
	/*! Copy Constructor */
	MatchGroup( const MatchGroup & src );
	/*! Copy Operator */
	MatchGroup & operator=( const MatchGroup & src );
	/*! Default Destructor */
	~MatchGroup();
	/*!
	 * Number of vertices in this group.
	 */
	mutable ushort numVertices;
	/*!
	 * The vertex indices.
	 */
	vector<ushort > vertexIndices;
};

}
#endif
