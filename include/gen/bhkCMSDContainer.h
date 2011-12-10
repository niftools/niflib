/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BHKCMSDCONTAINER_H_
#define _BHKCMSDCONTAINER_H_

#include "../NIF_IO.h"

// Include structures
#include "bhkCMSD_Shape.h"
namespace Niflib {


/*!  */
struct bhkCMSDContainer {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDContainer();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDContainer();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDContainer( const bhkCMSDContainer & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDContainer & operator=( const bhkCMSDContainer & src );
	/*! Unknown */
	Vector4 unknownFloats;
	/*! Unknown */
	unsigned int unknownInt;
	/*! Unknown */
	unsigned short unknownShort1;
	/*! Unknown */
	unsigned short unknownShort2;
	/*! Unknown */
	array<4,bhkCMSD_Shape > shape;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
