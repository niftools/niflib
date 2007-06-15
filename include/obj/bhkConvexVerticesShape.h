/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BHKCONVEXVERTICESSHAPE_H_
#define _BHKCONVEXVERTICESSHAPE_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "bhkConvexShape.h"
namespace Niflib {

class bhkConvexVerticesShape;
typedef Ref<bhkConvexVerticesShape> bhkConvexVerticesShapeRef;

/*! A convex shape built from vertices? */
class bhkConvexVerticesShape : public bhkConvexShape {
public:
	/*! Constructor */
	NIFLIB_API bhkConvexVerticesShape();

	/*! Destructor */
	NIFLIB_API virtual ~bhkConvexVerticesShape();

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
	* Returns the number of vertices that make up this mesh.  This is also the number of normals, colors, and UV coordinates if these are used.
	* \return The number of vertices that make up this mesh.
	*/
	NIFLIB_API int GetVertexCount() const;

	/*! 
	* Used to retrieve the vertices used by this mesh.  The size of the vector will be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	* \return A vector containing the vertices used by this mesh.
	*/
	NIFLIB_API vector<Vector3> GetVertices() const;

	/*! 
	* Used to retrieve the normals used by this mesh.  The size of the vector will either be zero if no normals are used, or be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	* \return A vector containing the normals used by this mesh, if any.
	*/
	NIFLIB_API vector<Vector3> GetNormals() const;

	//--END CUSTOM CODE--//
protected:
	/*! Unknown. */
	array<6,float > unknown6Floats;
	/*! Number of vertices. */
	mutable unsigned int numVertices;
	/*! Vertices. Fourth component is 0. */
	vector<Float4 > vertices;
	/*! The number of normals. */
	mutable unsigned int numNormals;
	/*!
	 * The normals of the shape's outer faces. Fourth component is the distance from
	 * center, negative.
	 */
	vector<Float4 > normals;
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
