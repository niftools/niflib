/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * A sphere.
 */
struct NIFLIB_API Sphere {
	/*! Default Constructor */
	Sphere();
	/*! Default Destructor */
	~Sphere();
	/*!
	 * The sphere's center.
	 */
	Vector3 center;
	/*!
	 * The sphere's radius.
	 */
	float radius;
};

}
#endif
