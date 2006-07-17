/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _COMPLEX_SHAPE_H_
#define _COMPLEX_SHAPE_H_

#include "Ref.h"
#include "nif_math.h"
#include "nif_basic_types.h"

namespace Niflib {

// Forward define of referenced classes
class NiProperty;
class NiNode;
class NiAVObject;

class ComplexShape {
public:

	struct SkinInfluence {
		unsigned int influenceIndex;
		float weight;
	};

	struct WeightedVertex {
		Vector3 position;
		vector<SkinInfluence> weights;
	};

	struct TexCoordIndex {
		unsigned int texCoordSetIndex;
		unsigned int texCoordIndex;
	};

	struct ComplexPoint {
		unsigned int vertexIndex;
		unsigned int normalIndex;
		unsigned int colorIndex;
		vector<TexCoordIndex> texCoordIndices;
	};

	struct ComplexFace {
		vector<ComplexPoint> points;
		unsigned int propGroupIndex; 
	};

	struct TexCoordSet {
		TexType texType;
		vector<TexCoord> texCoords;
	};

	Ref<NiAVObject> Split( Ref<NiNode> & parent ) const;

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