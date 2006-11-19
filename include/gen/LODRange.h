/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _LODRANGE_H_
#define _LODRANGE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * The distance range where a specific level of detail applies.
 */
struct NIFLIB_API LODRange {
	/*! Default Constructor */
	LODRange();
	/*! Copy Constructor */
	LODRange( const LODRange & src );
	/*! Copy Operator */
	LODRange & operator=( const LODRange & src );
	/*! Default Destructor */
	~LODRange();
	/*!
	 * Begining of range.
	 */
	float nearExtent;
	/*!
	 * End of Range.
	 */
	float farExtent;
};

}
#endif
