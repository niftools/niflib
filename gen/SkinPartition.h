/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _SKINPARTITION_H_
#define _SKINPARTITION_H_

#include "../NIF_IO.h"


/*!
 * Skinning data for a submesh, optimized for hardware skinning. Part of
 * NiSkinPartition.
 */
struct DLLEXPORT SkinPartition {
	/*! Default Constructor */
	SkinPartition();
	/*! Default Destructor */
	~SkinPartition();
	/*!
	 * Number of vertices in this submesh.
	 */
	ushort numVertices;
	/*!
	 * Number of triangles in this submesh.
	 */
	ushort numTriangles;
	/*!
	 * Number of bones influencing this submesh.
	 */
	ushort numBones;
	/*!
	 * Number of strips in this submesh (zero if not stripped).
	 */
	ushort numStrips;
	/*!
	 * Number of weight coefficients per vertex.
	 */
	ushort numWeightsPerVertex;
	/*!
	 * List of bones.
	 */
	vector<ushort > bones;
	/*!
	 * Do we have a vertex map?
	 */
	bool hasVertexMap;
	/*!
	 * Maps the weight/influence lists in this submesh to the vertices in the
	 * shape being skinned.
	 */
	vector<ushort > vertexMap;
	/*!
	 * Do we have vertex weights?
	 */
	bool hasVertexWeights;
	/*!
	 * The vertex weights.
	 */
	vector<vector<float > > vertexWeights;
	/*!
	 * The strip lengths.
	 */
	vector<ushort > stripLengths;
	/*!
	 * Do we have strip data?
	 */
	bool hasStrips;
	/*!
	 * The strips.
	 */
	vector<vector<ushort > > strips;
	/*!
	 * The triangles.
	 */
	vector<Triangle > triangles;
	/*!
	 * Do we have bone indices?
	 */
	bool hasBoneIndices;
	/*!
	 * Bone indices, they index into 'Bones'.
	 */
	vector<vector<byte > > boneIndices;
};

#endif
