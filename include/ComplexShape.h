/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _COMPLEX_SHAPE_H_
#define _COMPLEX_SHAPE_H_

#include "Ref.h"
#include "nif_math.h"
#include "nif_basic_types.h"
#include "obj/NiProperty.h"
#include "obj/NiNode.h"
#include "obj/NiAVObject.h"
#include "obj/NiTriBasedGeom.h"
#include <vector>

namespace Niflib {

using namespace std;

// Forward define of referenced classes
class NiProperty;
class NiNode;
class NiAVObject;
class NiTriBasedGeom;

const unsigned CS_NO_INDEX = 0xFFFFFFFF;

class ComplexShape {
public:

	struct SkinInfluence {
		SkinInfluence() : influenceIndex(CS_NO_INDEX) {}
		~SkinInfluence() {}
		unsigned int influenceIndex;
		float weight;
	};

	struct WeightedVertex {
		Vector3 position;
		vector<SkinInfluence> weights;
	};

	struct TexCoordIndex {
		TexCoordIndex() : texCoordSetIndex(CS_NO_INDEX), texCoordIndex(CS_NO_INDEX) {}
		~TexCoordIndex() {}
		unsigned int texCoordSetIndex;
		unsigned int texCoordIndex;
	};

	struct ComplexPoint {
		ComplexPoint() : vertexIndex(CS_NO_INDEX), normalIndex(CS_NO_INDEX), colorIndex(CS_NO_INDEX) {}
		~ComplexPoint() {}
		unsigned int vertexIndex;
		unsigned int normalIndex;
		unsigned int colorIndex;
		vector<TexCoordIndex> texCoordIndices;
	};

	struct ComplexFace {
		ComplexFace() : propGroupIndex(CS_NO_INDEX) {}
		~ComplexFace() {}
		vector<ComplexPoint> points;
		unsigned int propGroupIndex; 
	};

	struct TexCoordSet {
		TexType texType;
		vector<TexCoord> texCoords;
	};

	Ref<NiAVObject> Split( Ref<NiNode> & parent, Matrix44 & transform, int max_bones_per_partition = 4, bool stripify = false, bool tangent_space = false ) const;
	void Merge( const Ref<NiAVObject> & root );
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