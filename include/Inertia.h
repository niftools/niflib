/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIF_INERTIA_H
#define _NIF_INERTIA_H
#pragma once

//--Includes--//
#include "nif_math.h"
#include <vector>

namespace Niflib {

class Inertia {
public:

	/*! Return mass and inertia matrix for a sphere of given radius and
	 *	density.
	 */
	static void GetMassInertiaSphere(float radius, float density, 
		bool solid, float& mass, InertiaMatrix &inertia);

	/*! Return mass and inertia matrix for a box of given size and
	 *   density.
	 */
	static void GetMassInertiaBox(Vector3 size, float density, 
		bool solid, float& mass, InertiaMatrix &inertia);
	/*! Return mass and inertia matrix for a cylinder of given radius, 
	 *   height and density.
	 */
	static void GetMassInertiaCylinder(float radius, float height, 
		float density, bool solid,
		float& mass, InertiaMatrix &inertia);

	/*! Return mass and inertia matrix for a capsule of given radius, 
	 *	height and density.
	 */
	static void GetMassInertiaCapsule(float radius, float height, 
		float density, bool solid,
		float& mass, InertiaMatrix &inertia);

	/*! Return mass and inertia matrix for a capsule of given radius, 
	 *	height and density.
	 */
	static void GetMassCenterInertiaPolyhedron(
		const std::vector<Niflib::Vector3>& vertices, 
		const std::vector<Niflib::Triangle>& triangles, 
		float density, bool solid,
		float& mass, Niflib::Vector3& center, InertiaMatrix &inertia);

private:
	explicit Inertia();
};

}
#endif