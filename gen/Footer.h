/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _FOOTER_H_
#define _FOOTER_H_

#include "NIF_IO.h"
#include "Ref.h"
#include "obj/NiAVObject.h"

/*!
 * The NIF file footer.
 */
struct Footer {
	/*! Default Constructor */
	Footer();
	/*! Default Destructor */
	~Footer();
	/*!
	 * The number of root references.
	 */
	uint numRoots;
	/*!
	 * List of root blocks. If there is a camera, for 1st person view, then
	 * this block is referred to as well in this list, even if it is not a
	 * root block (usually we want the camera to be attached to the Bip Head
	 * node).
	 */
	vector<Ref<NiAVObject > > roots;
};

#endif
