/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _COMPLEX_SHAPE_H_
#define _COMPLEX_SHAPE_H_

#include "Ref.h"
#include "nif_math.h"
#include "nif_basic_types.h"
#include <vector>

namespace Niflib {

using namespace std;

// Forward define of referenced classes
class NiProperty;
class NiNode;
class NiAVObject;
class NiTriBasedGeom;

/*! Marks empty data indices */
const unsigned int CS_NO_INDEX = 0xFFFFFFFF;

/*!
 * This class is a helper object to ease the process of converting between the
 * 3D model format of a NIF file, which is optimized for real time display via
 * OpenGL or DirectX, and the more compact, complex format usually prefered by
 * 3D modeling software.
 * 
 * It is capable of mering multiple NiTriShape objects into one multi-material
 * object with indexed data, or taking such an object and splitting it up into
 * multiple NiTriShape objects.
 */
class ComplexShape {
public:

	/*!
	 * Used by the ComplexShape::WeightedVertex strut to store a single
	 * skin-weight/bone influence combination for a vertex.
	 */
	struct SkinInfluence {
		/*! Constructor */
		SkinInfluence() : influenceIndex(CS_NO_INDEX) {}
		/*! Destructor */
		~SkinInfluence() {}
		/*! 
		 * Index into the ComplexShape::skinInfluences array of the bone
		 * influence for this skin weight.
		 */
		unsigned int influenceIndex;
		/*! 
		 * The amount of influence the indexed bone has on this vertex, between
		 * 0.0 and 1.0
		 */
		float weight;
	};

	/*!
	 * Used by the ComplexShape class to store a single vertex and any
	 * Associated skin weights
	 */
	struct WeightedVertex {
		/*! The 3D position of this vertex. */
		Vector3 position;
		/*! A list of weight/influence index pairs for this vertex. */
		vector<SkinInfluence> weights;
	};

	/*!
	 * Used by the ComplexShape::ComplexPoint struct to store a single texture
	 * cooridinate set/texture coordinate pair of indices.
	 */
	struct TexCoordIndex {
		/*! Constructor */
		TexCoordIndex() : texCoordSetIndex(CS_NO_INDEX), texCoordIndex(CS_NO_INDEX) {}
		/*! Destructor */
		~TexCoordIndex() {}
		/*!
		 * Index into the ComplexShape::texCoordSets array of texture
		 * coordinate sets.
		 */
		unsigned int texCoordSetIndex;

		/*!
		 * Index into the ComplexShape::TexCoordSet::texCoords array of the
		 * texture coordinate set referenced by texCoordSetIndex.
		 */
		unsigned int texCoordIndex;
	};

	/*!
	 * Used by ComplexShape::ComplexFace class to describe a single point in
	 * the 3D model.  Points share their data in case of duplication, so all
	 * information, such as position, normal vector, texture coordinates, etc.,
	 * are stored as indices into the asociated data arrays.
	 */
	struct ComplexPoint {
		/*! Constructor */
		ComplexPoint() : vertexIndex(CS_NO_INDEX), normalIndex(CS_NO_INDEX), colorIndex(CS_NO_INDEX) {}
		/*! Destructor */
		~ComplexPoint() {}
		/*! 
		 * Index into the ComplexShape::vertices array which stores the
		 * position and any associated skin weights for this point.
		 */
		unsigned int vertexIndex;
		/*! 
		 * Index into the ComplexShape::normals array which stores the normal
		 * vector for this point.
		 */
		unsigned int normalIndex;
		/*!
		 * Index into the ComplexShape::colors array which stores the vertex
		 * color for this point
		 */
		unsigned int colorIndex;
		/*!
		 * An array of texture coordinate set/texture coordinate index pairs
		 * describing all the UV coordinates for this point.
		 */
		vector<TexCoordIndex> texCoordIndices;
	};

	/*! 
	 * Used by ComplexShape to describe a single polygon.  Complex shape
	 * polygons can have more than three points, unlike the triangels required
	 * within the NIF format.  Each face may also be associated with a
	 * different set of NiProperty classes, enabling each face to have unique
	 * material settings.
	 */
	struct ComplexFace {
		/*! Constructor */
		ComplexFace() : propGroupIndex(CS_NO_INDEX) {}
		/*! Destructor */
		~ComplexFace() {}
		/*! A list of points which make up this polygon */
		vector<ComplexPoint> points;
		/*!
		 * Index into the ComplexShape::propGroups array which specifies which
		 * set of NiProperty classes to apply to this face.
		 */
		unsigned int propGroupIndex; 
	};

	/*!
	 * Used by ComplexShape to store texture coordinate data and the
	 * associated type of texture, such as base, detail, or dark map.
	 */
	struct TexCoordSet {
		/*!
		 * The type of the texture such as base, detail, bump, etc.
		 */
		TexType texType;
		/*!
		 * A list of all the texture cooridnates for this texture set.
		 */
		vector<TexCoord> texCoords;
	};

	/*!
	 * This function splits the contents of the ComplexShape into multiple
	 * NiTriBasedGeom objects.
	 * \param parent The parent NiNode that the resulting NiTriBasedGeom
	 * objects will be attached to.
	 * \param transform The transform for the resulting object or group of
	 * objects
	 * \param max_bones_per_partition The maximum number of bones to allow in
	 * each skin partition.  Set to zero to skip creation of partition.
	 * \param stripify Whether or not to generate efficient triangle strips.
	 * \param tangent_space Whether or not to generate Oblivion tangent space
	 * information.
	 * \return A referene to the root NiAVObject that was created.
	 */
	Ref<NiAVObject> Split( 
		Ref<NiNode> & parent,
		Matrix44 & transform,
		int max_bones_per_partition = 4,
		bool stripify = false,
		bool tangent_space = false
	) const;

	/* 
	 * Merges together multiple NiTriBasedGeom objects and stores their data
	 * in this ComplexShape object.
	 * \param root The root NiAVObject to which all of the NiTriBasedGeom
	 * objects to be merged are attached.  It could be a single NiTribasedGeom
	 * or a NiNode that is a split mesh proxy.
	 * \sa NiNode::IsSplitMeshProxy
	 */
	void Merge( const Ref<NiAVObject> & root );
	
	/* 
	 * Clears out all the data stored in this ComplexShape
	 */
	void Clear();

	//Setters
	void SetName( const string & n );
	void SetVertices( const vector<WeightedVertex> & n );
	void SetColors( const vector<Color4> & n );
	void SetNormals( const vector<Vector3> & n );
	void SetTexCoordSets( const vector<TexCoordSet> & n );
	void SetFaces( const vector<ComplexFace> & n );
	void SetPropGroups( const vector< vector< Ref<NiProperty> > > & n ); 
	void SetSkinInfluences( const vector< Ref<NiNode> > & n );

	//Getters
	string GetName() const;
	vector<WeightedVertex> GetVertices() const;
	vector<Color4> GetColors() const;
	vector<Vector3> GetNormals() const;
	vector<TexCoordSet> GetTexCoordSets() const;
	vector<ComplexFace> GetFaces() const;
	vector< vector< Ref<NiProperty> > > GetPropGroups() const;
	vector< Ref<NiNode> > GetSkinInfluences() const;

private:
	vector<WeightedVertex> vertices;
	vector<Color4> colors;
	vector<Vector3> normals;
	vector<TexCoordSet> texCoordSets;
	vector<ComplexFace> faces;
	vector< vector< Ref<NiProperty> > > propGroups;
	vector< Ref<NiNode> > skinInfluences;
	string name;
};

}

#endif
