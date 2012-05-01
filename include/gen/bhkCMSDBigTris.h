/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BHKCMSDBIGTRIS_H_
#define _BHKCMSDBIGTRIS_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct bhkCMSDBigTris {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDBigTris();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDBigTris();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDBigTris( const bhkCMSDBigTris & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDBigTris & operator=( const bhkCMSDBigTris & src );
	/*! Index of triangle vertiex 1 */
	mutable unsigned short triangle1;
	/*! Index of triangle vertiex 2 */
	mutable unsigned short triangle2;
	/*! Index of triangle vertiex 3 */
	mutable unsigned short triangle3;
	/*! Unknown */
	mutable unsigned int unknownInt1;
	/*! Unknown */
	mutable unsigned short unknownShort1;
  //--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
