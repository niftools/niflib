/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BHKCOMPRESSEDMESHSHAPEDATA_H_
#define _BHKCOMPRESSEDMESHSHAPEDATA_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiObject.h"

// Include structures
#include "../gen/bhkCMSD_Something.h"
#include "../gen/bhkCMSDData.h"
#include "../gen/bhkCMSD_Shape.h"
#include "../gen/bhkCMSDContainer.h"
namespace Niflib {

class bhkCompressedMeshShapeData;
typedef Ref<bhkCompressedMeshShapeData> bhkCompressedMeshShapeDataRef;

/*!  */
class bhkCompressedMeshShapeData : public NiObject {
public:
	/*! Constructor */
	NIFLIB_API bhkCompressedMeshShapeData();

	/*! Destructor */
	NIFLIB_API virtual ~bhkCompressedMeshShapeData();

	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;

	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();

	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;

	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
protected:
	/*! Unknown */
	unsigned int unknownInt1;
	/*! Unknown */
	unsigned int unknownInt2;
	/*! Unknown */
	unsigned short unknownShort1;
	/*! Unknown */
	unsigned short unknownShort2;
	/*! Unknown */
	unsigned short unknownShort3;
	/*! Unknown */
	unsigned short unknownShort4;
	/*! Unknown. */
	float unknownFloat1;
	/*! Unknown. */
	Vector4 unknownFloats1;
	/*! Unknown. */
	Vector4 unknownFloats2;
	/*! Unknown */
	byte unknownByte1;
	/*! Unknown */
	unsigned int unknownInt3;
	/*! Unknown */
	unsigned int unknownInt4;
	/*! Unknown */
	unsigned int unknownInt5;
	/*! Unknown */
	byte unknownByte2;
	/*! Number of bhkCMSDSomething */
	mutable unsigned int somethingCount;
	/*! Unknown */
	vector<bhkCMSD_Something > unknownIntSomething;
	/*! Unknown */
	unsigned int unknownInt6;
	/*! Format for vertices/? */
	mutable unsigned int numDataSet;
	/*! Unknown */
	unsigned int unknownInt7;
	/*! Unknown */
	unsigned int unknownInt8;
	/*! Unknown */
	unsigned int unknownInt9;
	/*! Unknown */
	vector<bhkCMSDData > dataSet1;
	/*! Unknown */
	vector<bhkCMSDData > dataSet2;
	/*! Unknown */
	float unknownFloat2;
	/*! Unknown */
	mutable unsigned int numVertices;
	/*! Compressed Vertices? */
	vector<Vector4 > vertices;
	/*! Unknown */
	mutable unsigned int numBytes2;
	/*! Unknown */
	vector< array<12,byte > > unknownBytes;
	/*! Unknown */
	mutable unsigned int numSubshapes;
	/*! Unknown */
	Vector3 unknownFloats3;
	/*! Unknown */
	unsigned int unknownInt10;
	/*! Unknown */
	unsigned int unknownInt11;
	/*! Unknown */
	float unknownFloat3;
	/*! Unknown */
	array<4,bhkCMSD_Shape > shapeSet1;
	/*! Unknown, The first set is always present if 1. */
	vector<bhkCMSDContainer > shapeSet2;
	/*! Unknown, end of block. */
	unsigned int unknownInt12;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//

//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
