/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _OBLIVIONCOLFILTER_H_
#define _OBLIVIONCOLFILTER_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Oblivion's ColFilter property for Havok.
 */
struct OblivionColFilter {
	/*! Default Constructor */
	NIFLIB_API OblivionColFilter();
	/*! Default Destructor */
	NIFLIB_API ~OblivionColFilter();
	/*! Copy Constructor */
	NIFLIB_API OblivionColFilter( const OblivionColFilter & src );
	//This operator give SWIG problems
	#ifndef SWIG
	/*! Copy Operator */
	NIFLIB_API OblivionColFilter & operator=( const OblivionColFilter & src );
	#endif
	/*!
	 * Sets mesh color in Oblivion Construction Set.
	 */
	OblivionLayer layer;
	/*!
	 * The first bit sets the LINK property and controls whether this body is
	 * physically linked to others. The next bit turns collision off. Then,
	 * the next bit sets the SCALED property in Oblivion. The next five bits
	 * make up the number of this part in a linked body list.
	 */
	byte colFilter;
	/*!
	 * Unknown.
	 */
	unsigned short unknownShort;
};

}
#endif
