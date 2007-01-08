/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * particle array entry
 */
struct NIFLIB_API Particle {
	/*! Default Constructor */
	Particle();
	/*! Copy Constructor */
	Particle( const Particle & src );
	/*! Copy Operator */
	Particle & operator=( const Particle & src );
	/*! Default Destructor */
	~Particle();
	/*!
	 * Particle velocity
	 */
	Vector3 velocity;
	/*!
	 * Unknown
	 */
	Vector3 unknownVector;
	/*!
	 * The particle's age.
	 */
	float lifetime;
	/*!
	 * Maximum age of the particle.
	 */
	float lifespan;
	/*!
	 * Timestamp of the last update.
	 */
	float timestamp;
	/*!
	 * Unknown short (=0)
	 */
	unsigned short unknownShort;
	/*!
	 * Particle/vertex index matches array index
	 */
	unsigned short vertexId;
};

}
#endif
