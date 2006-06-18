/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _LODRANGE_H_
#define _LODRANGE_H_

#include "../NIF_IO.h"

namespace NifLib {


/*!
 * The distance range where a specific level of detail applies.
 */
struct NIFLIB_API LODRange {
	/*! Default Constructor */
	LODRange();
	/*! Default Destructor */
	~LODRange();
	/*!
	 * Begining of range.
	 */
	float near;
	/*!
	 * End of Range.
	 */
	float far;
};

}
#endif
