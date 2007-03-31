/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _LODRANGE_H_
#define _LODRANGE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * The distance range where a specific level of detail applies.
 */
struct LODRange {
	/*! Default Constructor */
	NIFLIB_API LODRange();
	/*! Default Destructor */
	NIFLIB_API ~LODRange();
	/*! Copy Constructor */
	NIFLIB_API LODRange( const LODRange & src );
	//This operator give SWIG problems
	#ifndef SWIG
	/*! Copy Operator */
	NIFLIB_API LODRange & operator=( const LODRange & src );
	#endif
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
