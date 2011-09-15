/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _ADDITIONALDATAINFO_H_
#define _ADDITIONALDATAINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct AdditionalDataInfo {
	/*! Default Constructor */
	NIFLIB_API AdditionalDataInfo();
	/*! Default Destructor */
	NIFLIB_API ~AdditionalDataInfo();
	/*! Copy Constructor */
	NIFLIB_API AdditionalDataInfo( const AdditionalDataInfo & src );
	/*! Copy Operator */
	NIFLIB_API AdditionalDataInfo & operator=( const AdditionalDataInfo & src );
	/*! Type of data */
	int dataType;
	/*! Size of Block */
	int blockSize;
	/*! Unknown */
	int numBlocks;
	/*! Unknown */
	int blockSize2;
	/*! Unknown */
	int blockIndex;
	/*! Unknown */
	int unknownInt1;
	/*! Unknown */
	byte unknownByte1;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
