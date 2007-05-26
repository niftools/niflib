/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIMESHPSYSDATA_H_
#define _NIMESHPSYSDATA_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "NiPSysData.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiObject;
class NiNode;
class NiMeshPSysData;
typedef Ref<NiMeshPSysData> NiMeshPSysDataRef;

/*! Particle meshes data. */
class NiMeshPSysData : public NiPSysData {
public:
	/*! Constructor */
	NIFLIB_API NiMeshPSysData();

	/*! Destructor */
	NIFLIB_API virtual ~NiMeshPSysData();

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
	/*!
	 * Unknown. Seems to refer to particle modifiers, however at least one file has a
	 * NiNode here.  May indicate that this is really two separate links in different
	 * versions or some other problem.
	 */
	Ref<NiObject > modifier;
	/*! Unknown. */
	byte unknownByte2;
	/*! The number of unknown links that follow. */
	mutable unsigned int numUnknownLinks;
	/*! Unknown. Seems to refer to particle modifiers. */
	vector<Ref<NiObject > > unknownLinks;
	/*! Repeat of Vertex Count? */
	unsigned int numVertices2;
	/*! Unknown. 0? */
	byte unknownByte3;
	/*! Unknown.  1? */
	unsigned int unknownInt2;
	/*! Repeat of Vertex Count? */
	unsigned int numVertices3;
	/*! Links to a NiNode; but this NiNode doesn't seem to be a mesh? */
	Ref<NiNode > unknownLink2;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//
//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
