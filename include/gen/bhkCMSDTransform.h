/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BHKCMSDTRANSFORM_H_
#define _BHKCMSDTRANSFORM_H_

#include "../NIF_IO.h"
#include "QuaternionXYZW.h"

namespace Niflib {


/*!  */
struct bhkCMSDTransform {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDTransform();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDTransform();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDTransform( const bhkCMSDTransform & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDTransform & operator=( const bhkCMSDTransform & src );
	/*! Translation */
	Vector4   translation;
	/*! Rotation */
	QuaternionXYZW  rotation;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
