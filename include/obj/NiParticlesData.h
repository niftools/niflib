/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _NIPARTICLESDATA_H_
#define _NIPARTICLESDATA_H_

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiAdditionalGeometryData;
class NiParticlesData;
typedef Ref<NiParticlesData> NiParticlesDataRef;

/*! Generic rotating particles data object. */
class NiParticlesData : public NiObject {
public:
	/*! Constructor */
	NIFLIB_API NiParticlesData();

	/*! Destructor */
	NIFLIB_API virtual ~NiParticlesData();

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
	/*! Name of this object. */
	IndexString name;
	/*!
	 * Number of vertices. For NiPSysData this is max particles. (For Fallout 3 this is
	 * always zero)
	 */
	mutable unsigned short numVertices;
	/*! Used with NiCollision objects when OBB or TRI is set. */
	byte keepFlags;
	/*! Unknown. */
	byte compressFlags;
	/*! Is the vertex array present? (Always non-zero.) */
	bool hasVertices;
	/*! The mesh vertices. */
	vector<Vector3 > vertices;
	/*! Texture flags in lower byte. */
	mutable byte numUvSets;
	/*! Methods for saving binormals and tangents saved in upper byte. */
	byte tspaceFlag;
	/*!
	 * Do we have lighting normals? These are essential for proper lighting: if not
	 * present, the model will only be influenced by ambient light.
	 */
	bool hasNormals;
	/*! The lighting normals. */
	vector<Vector3 > normals;
	/*!
	 * Unknown. Binormal & tangents? has_normals must be set as well for this field to
	 * be present.
	 */
	vector<Vector3 > binormals;
	/*! Unknown. Binormal & tangents? */
	vector<Vector3 > tangents;
	/*!
	 * Center of the bounding box (smallest box that contains all vertices) of the
	 * mesh.
	 */
	Vector3 center;
	/*!
	 * Radius of the mesh: maximal Euclidean distance between the center and all
	 * vertices.
	 */
	float radius;
	/*!
	 * Do we have vertex colors? These are usually used to fine-tune the lighting of
	 * the model.
	 * 
	 *             Note: how vertex colors influence the model can be controlled by
	 * having a NiVertexColorProperty object as a property child of the root node. If
	 * this property object is not present, the vertex colors fine-tune lighting.
	 * 
	 *             Note 2: set to either 0 or 0xFFFFFFFF for NifTexture compatibility.
	 */
	bool hasVertexColors;
	/*! The vertex colors. */
	vector<Color4 > vertexColors;
	/*!
	 * Do we have UV coordinates?
	 * 
	 *             Note: for compatibility with NifTexture, set this value to either
	 * 0x00000000 or 0xFFFFFFFF.
	 */
	bool hasUv;
	/*!
	 * The UV texture coordinates. They follow the OpenGL standard: some programs may
	 * require you to flip the second coordinate.
	 */
	vector< vector<TexCoord > > uvSets;
	/*! Consistency Flags */
	ConsistencyType consistencyFlags;
	/*! Unknown. */
	Ref<NiAdditionalGeometryData > additionalData;
	/*! The maximum number of particles (matches the number of vertices). */
	unsigned short numParticles;
	/*! The particles' size. */
	float particleRadius;
	/*! Is the particle size array present? */
	bool hasRadii;
	/*! The individual particel sizes. */
	vector<float > radii;
	/*!
	 * The number of active particles at the time the system was saved. This is also
	 * the number of valid entries in the following arrays.
	 */
	unsigned short numActive;
	/*! Is the particle size array present? */
	bool hasSizes;
	/*! The individual particel sizes. */
	vector<float > sizes;
	/*! Is the particle rotation array present? */
	bool hasRotations;
	/*! The individual particle rotations. */
	vector<Quaternion > rotations;
	/*! Are the angles of rotation present? */
	bool hasRotationAngles;
	/*! Angles of rotation */
	vector<float > rotationAngles;
	/*! Are axes of rotation present? */
	bool hasRotationAxes;
	/*! Unknown */
	vector<Vector3 > rotationAxes;
	/*! Unknown ushort */
	bool hasUnknownStuff1;
	/*! Unknown */
	mutable short numUnknownStuff1;
	/*! Unknown */
	vector<Vector4 > unknownStuff1;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//
//--END CUSTOM CODE--//

} //End Niflib namespace
#endif
