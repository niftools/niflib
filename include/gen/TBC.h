/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _TBC_H_
#define _TBC_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Tension, bias, continuity.
 */
struct TBC {
	/*! Default Constructor */
	NIFLIB_API TBC();
	/*! Default Destructor */
	NIFLIB_API ~TBC();
	/*! Copy Constructor */
	NIFLIB_API TBC( const TBC & src );
	//This operator give SWIG problems
	#ifndef SWIG
	/*! Copy Operator */
	NIFLIB_API TBC & operator=( const TBC & src );
	#endif
	/*!
	 * Tension.
	 */
	float t;
	/*!
	 * Bias.
	 */
	float b;
	/*!
	 * Continuity.
	 */
	float c;
};

}
#endif
