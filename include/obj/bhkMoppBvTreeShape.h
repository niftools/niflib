/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BHKMOPPBVTREESHAPE_H_
#define _BHKMOPPBVTREESHAPE_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "bhkBvTreeShape.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class bhkShape;
class bhkMoppBvTreeShape;
typedef Ref<bhkMoppBvTreeShape> bhkMoppBvTreeShapeRef;

/*! Memory optimized partial polytope bounding volume tree shape (not an entity). */
class bhkMoppBvTreeShape : public bhkBvTreeShape {
public:
	/*! Constructor */
	NIFLIB_API bhkMoppBvTreeShape();

	/*! Destructor */
	NIFLIB_API virtual ~bhkMoppBvTreeShape();

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

	/*!
	 * Retrieves the shape object that this body is using.
	 * \return The shape object being used by this body.
	 */
	NIFLIB_API Ref<bhkShape > GetShape() const;

	/*!
	 * Sets the shape object that this body will use.
	 * \param[in] value The new shape object for this body to use.
	 */
	NIFLIB_API void SetShape( bhkShape * value );

	/*!
	 * Get the shape's material.  This determines the type of noises the object makes as it collides in Oblivion.
	 * \return The Oblivion material used by this collision shape.
	 */
	NIFLIB_API HavokMaterial GetMaterial() const;

	/*!
	 * Sets the shape's material.  This determines the type of noises the object makes as it collides in Oblivion.
	 * \param[in] value The new material for this shape to use.
	 */
	NIFLIB_API void SetMaterial( HavokMaterial value );

	//--END CUSTOM CODE--//
protected:
	/*! The shape. */
	Ref<bhkShape > shape;
	/*! The shape's material. */
	HavokMaterial material;
	/*! Unknown bytes, probably MOPP Header. */
	array<8,byte > unknown8Bytes;
	/*! Unknown float, might be scale. */
	float unknownFloat;
	/*! Number of bytes for MOPP data. */
	mutable unsigned int moppDataSize;
	/*! Corner of the object with min. coordinates. */
	Vector3 objectCorner;
	/*! The scaling factor to quantize the MOPP. Determined by 255*255*255 / size. */
	float scalingFactor;
	/*! The tree of bounding volume data. */
	vector<byte > moppData;
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
