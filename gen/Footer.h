/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _FOOTER_H_
#define _FOOTER_H_

#include "../NIF_IO.h"
#include "../obj/NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiObject;

/*!
 * The NIF file footer.
 */
struct NIFLIB_API Footer {
	/*! Default Constructor */
	Footer();
	/*! Default Destructor */
	~Footer();
	/*!
	 * The number of root references.
	 */
	mutable uint numRoots;
	/*!
	 * List of root blocks. If there is a camera, for 1st person view, then
	 * this block is referred to as well in this list, even if it is not a
	 * root block (usually we want the camera to be attached to the Bip Head
	 * node).
	 */
	vector<Ref<NiObject > > roots;
	void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string asString( bool verbose = false ) const;
};

}
#endif
