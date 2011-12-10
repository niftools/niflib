/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BHKCMSD_SHAPE_H_
#define _BHKCMSD_SHAPE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct bhkCMSD_Shape {
	/*! Default Constructor */
	NIFLIB_API bhkCMSD_Shape();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSD_Shape();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSD_Shape( const bhkCMSD_Shape & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSD_Shape & operator=( const bhkCMSD_Shape & src );
	/*! Unknown */
	mutable unsigned int numShape;
	/*! Unknown */
	vector<unsigned short > shape;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
