/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

//To change this file, alter the niftools/docsys/gen_niflib.py Python script.

#ifndef _BHKCMSDCHUNK_H_
#define _BHKCMSDCHUNK_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!  */
struct bhkCMSDChunk {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDChunk();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDChunk();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDChunk( const bhkCMSDChunk & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDChunk & operator=( const bhkCMSDChunk & src );
	/*! Translation */
	Vector4 translation;
	/*! Index in parents material list */
	mutable unsigned int materialIndex;
	/*! Unknown */
	mutable unsigned short unknownShort1;
	/*! Index of parents transformation list */
	mutable unsigned short transformIndex;
	/*! Number of vertices */
	mutable unsigned int numVertices;
	/*! Vertices */
	vector<unsigned short > vertices;
	/*! Number of indices */
	mutable unsigned int numIndices;
	/*! indices */
	vector<unsigned short > indices;
	/*! Number of strips */
	mutable unsigned int numStrips;
	/*! Strips */
	vector<unsigned short > strips;
	/*! Number of indices2 (welding) */
	mutable unsigned int numIndices2;
	/*! Indices2 8welding) */
	vector<unsigned short > indices2;
  //--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
