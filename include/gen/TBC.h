/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _TBC_H_
#define _TBC_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Tension, bias, continuity.
 */
struct NIFLIB_API TBC {
	/*! Default Constructor */
	TBC();
	/*! Copy Constructor */
	TBC( const TBC & src );
	/*! Copy Operator */
	TBC & operator=( const TBC & src );
	/*! Default Destructor */
	~TBC();
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
