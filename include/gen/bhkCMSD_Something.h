/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BHKCMSD_SOMETHING_H_
#define _BHKCMSD_SOMETHING_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Unknown, used in bhkCompressedMeshShapeData */
struct bhkCMSD_Something {
	/*! Default Constructor */
	NIFLIB_API bhkCMSD_Something();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSD_Something();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSD_Something( const bhkCMSD_Something & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSD_Something & operator=( const bhkCMSD_Something & src );
	/*! Unknown */
	unsigned int largeInt;
	/*! Always 1? */
	unsigned int unknownInteger;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
