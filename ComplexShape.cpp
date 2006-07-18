/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "ComplexShape.h"
#include "obj/NiNode.h"
#include "obj/NiProperty.h"
#include "obj/NiAVObject.h"
#include "obj/NiTriShape.h"
#include "obj/NiTriShapeData.h"
#include "obj/NiTexturingProperty.h"
#include "obj/NiSkinInstance.h"
#include "obj/NiSkinData.h"
#include "gen/SkinWeight.h"
#include <stdlib.h>

using namespace Niflib;

struct CompoundVertex {
	Vector3 position;
	Vector3 normal;
	Color4 color;
	map<TexType, TexCoord> texCoords;
	map<NiNodeRef, float> weights;

	CompoundVertex() {}
	~CompoundVertex() {}
	CompoundVertex( const CompoundVertex & n ) {
		*this = n;
	}
	CompoundVertex & operator=( const CompoundVertex & n ) {
		position = n.position;
		normal = n.normal;
		color = n.color;
		texCoords = n.texCoords;
		weights = n.weights;
		return *this;
	}
	bool operator==( const CompoundVertex & n ) {
		if ( position != n.position ) {
			return false;
		}
		if ( normal != n.normal ) {
			return false;
		}
		if ( color.r != n.color.r && color.g != n.color.g && color.b != n.color.b && color.a != n.color.a ) {
			return false;
		}
		if ( texCoords != n.texCoords ) {
			return false;
		}
		if ( weights != n.weights ) {
			return false;
		}

		return true;
	}
};

void ComplexShape::SetName( const string & n ) {
	name = n;
}

void ComplexShape::SetVertices( const vector<WeightedVertex> & n ) {
	vertices = n;
}

void ComplexShape::SetColors( const vector<Color4> & n ) {
	colors = n;
}

void ComplexShape::SetNormals( const vector<Vector3> & n ) {
	normals = n;
}

void ComplexShape::SetTexCoordSets( const vector<TexCoordSet> & n ) {
	texCoordSets = n;
}

void ComplexShape::SetFaces( const vector< ComplexFace > & n ) {
	faces = n;
}

void ComplexShape::SetPropGroups( const vector< vector< Ref<NiProperty> > > & n ) {
	propGroups = n;
} 

void ComplexShape::SetSkinInfluences( const vector< Ref<NiNode> > & n ) {
	skinInfluences = n;
}


string ComplexShape::GetName() const {
	return name;
}

vector<ComplexShape::WeightedVertex> ComplexShape::GetVertices() const {
	return vertices;
}

vector<Color4> ComplexShape::GetColors() const {
	return colors;
}

vector<Vector3> ComplexShape::GetNormals() const {
	return normals;
}

vector<ComplexShape::TexCoordSet> ComplexShape::GetTexCoordSets() const {
	return texCoordSets;
}

vector< ComplexShape::ComplexFace > ComplexShape::GetFaces() const {
	return faces;
}

vector< vector< Ref<NiProperty > > > ComplexShape::GetPropGroups() const {
	return propGroups;
}

vector< Ref<NiNode> > ComplexShape::GetSkinInfluences() const {
	return skinInfluences;
}

//void ComplexShape::CombineTriShapes( list<blk_ref> & tri_shapes ) {
//	//Clear all internal datea
//	_vertices.clear();
//	_colors.clear();
//	_normals.clear();
//	_materials.clear();
//	_uvs.clear();
//	_faces.clear();
//	_bones.clear();
//
//	//Create a temporary spot to hold the triangle lists from each TriShape
//	vector< vector<Triangle> > ts_faces;
//
//	//Create lists to hold the lookup tables
//	vector<int> tri_lookup, nor_lookup, col_lookup;
//	map<string, vector<int> > mat_lookup, uv_lookup;
//	
//	//--Cycle through all the TriShapes, adding their data to the lists--//
//	list<blk_ref>::iterator it;
//
//	for (it = tri_shapes.begin(); it != tri_shapes.end(); ++it) {
//		ITriShapeData * data = QueryTriShapeData(*it);
//
//		//Vertices
//		vector<Vector3> ts_verts = data->GetVertices();
//		_vertices.insert(_vertices.end(), ts_verts.begin(), ts_verts.end();
//
//		//Normals
//		vector<Vector3> ts_norms = data->GetNormals();
//		_normals.insert(_normals.end(), ts_norms.begin(), ts_norms.end();
//		
//		//Colors
//		vector<Colors> ts_cols = data->GetColors();
//		_colors.insert(_colors.end(), ts_colors.begin(), ts_colors.end();
//
//		//Triangles
//		ts_faces[i] = data->GetTriangles();
//
//		//UV Coords
//		vector< vector<TexCoords> > uvs(data->GetUVSetCount());
//		for (int i = 0; i < data->GetUVSetCount(); ++i) {
//			uvs[i] = data->GetUVSet(i);
//		}
//
//		//Associate UV Coord Data with proper map name
//		blk_ref tx_prop = par["Properties"]->FindLink( "NiTexturingProperty");
//		if ( tx_prop.is_null() == false ) {
//			int uv_set = 0;
//			for (int i = 0; i < 7; ++i) {
//				string attr_name, map;
//				switch(i) {
//					case 0:	attr_name = "Base Texture";     map = "map1";   break;
//					case 1:	attr_name = "Dark Texture";     map = "dark";   break;
//					case 2:	attr_name = "Detail Texture";   map = "detail"; break;
//					case 3:	attr_name = "Gloss Texture";    map = "gloss";  break;
//					case 4:	attr_name = "Glow Texture";     map = "glow";   break;
//					case 5:	attr_name = "Bump Map Texture"; map = "bump";   break;
//					case 6:	attr_name = "Decal 0 Texture";  map = "decal0";
//				}
//
//				if ( tx_prop[attr_name]->asTexDesc().isUsed == true ) {
//					//How to merge all UVs?
//				}
//
//		}
//
//
//		//blk_ref material = (*it)->GetAttr("Propreties")->FindLink("NiMaterialProperty");
//		//blk_ref skin_inst = (*it)->GetAttr("Skin Instance")->asLink();
//		//blk_ref skin_data;
//		//vector<blk_ref> bones;
//		//map<int, float> weights;
//		//if ( skin_inst.is_null() == false ) {
//		//	skin_block = skin_inst->GetAttr("Data");
//		//	if (skin_block.is_null() == false ) {
//		//		ISkinData * skin_data = QuerySkinData(skin_block);
//		//		weights = skin_data->GetWeights();
//		//		bones = skin_data->GetBones();
//		//	}
//		//}
//
//	}
//}

Ref<NiAVObject> ComplexShape::Split( Ref<NiNode> & parent ) const {

	//Make sure parent is not NULL
	if ( parent == NULL ) {
		throw runtime_error ("A parent is necessary to split a complex shape.");
	}

	//There will be one NiTriShape per property group
	//with a minimum of 1
	unsigned int num_shapes = unsigned int(propGroups.size());
	if ( num_shapes == 0 ) {
		num_shapes = 1;
	}

	vector<NiTriShapeRef> shapes(num_shapes);

	//Loop through each shape slot and create a NiTriShape
	for ( unsigned int shape_num = 0; shape_num < shapes.size(); ++shape_num ) {
		shapes[shape_num] = new NiTriShape;
	}

	NiAVObjectRef root;

	//If there is just one shape, return it.  Otherwise
	//create a node, parent all shapes to it, and return
	// that
	if ( shapes.size() == 1 ) {
		//One shape
		shapes[0]->SetName(name);
		root = StaticCast<NiAVObject>(shapes[0]);
	} else {
		//Multiple shapes
		NiNodeRef niNode = new NiNode;
		niNode->SetName(name);
		for ( unsigned int i = 0; i < shapes.size(); ++i ) {
			niNode->AddChild( StaticCast<NiAVObject>(shapes[i]) );

			//Set Shape Name
			stringstream shapeName;
			shapeName << name << " " << i;
			shapes[i]->SetName( shapeName.str() );
		}
		root = StaticCast<NiAVObject>(niNode);
	}

	parent->AddChild( root );

	//Create NiTriShapeData and fill it out with all data that is relevant
	//to this shape based on the material.
	for ( unsigned int shape_num = 0; shape_num < shapes.size(); ++shape_num ) {

		NiTriShapeDataRef niData = new NiTriShapeData;
		shapes[shape_num]->SetData( StaticCast<NiTriBasedGeomData>(niData) );

		//Create a list of CompoundVertex to make it easier to
		//test for the need to clone a vertex
		vector<CompoundVertex> compVerts;

		//List of triangles for the final shape to use
		vector<Triangle> shapeTriangles;

		//Loop through all faces, and all points on each face
		//to set the vertices in the CompoundVertex list
		for ( vector<ComplexFace>::const_iterator face = faces.begin(); face != faces.end(); ++face ) {
			//Ignore faces with less than 3 vertices
			if ( face->points.size() < 3 ) {
				continue;
			}

			//Skip this face if the material does not relate to this shape
			if ( face->propGroupIndex != shape_num ) {
				continue;
			}

			vector<unsigned short> shapeFacePoints;
			for ( vector<ComplexPoint>::const_iterator point = face->points.begin(); point != face->points.end(); ++point ) {

				//--Set up Compound vertex--//
				CompoundVertex cv;

				if ( vertices.size() > 0 ) {
					const WeightedVertex & wv = vertices[point->vertexIndex];
					cv.position = wv.position;

					if ( skinInfluences.size() > 0 ) {
						for ( unsigned int i = 0; i < wv.weights.size(); ++i ) {
							const SkinInfluence & inf = wv.weights[i];

							cv.weights[ skinInfluences[inf.influenceIndex] ] = inf.weight;
						}
					}
				}

				if ( normals.size() > 0 ) {
					cv.normal = normals[point->normalIndex];
				}
				if ( colors.size() > 0 ) {
					cv.color = colors[point->colorIndex];
				}

				if ( texCoordSets.size() > 0 ) {
					for ( unsigned int i = 0; i < point->texCoordIndices.size(); ++i ) {
						const TexCoordSet & set = texCoordSets[ point->texCoordIndices[i].texCoordSetIndex ];

						cv.texCoords[ set.texType ] = set.texCoords[ point->texCoordIndices[i].texCoordIndex ];
					}
				}
				
				bool found_match = false;
				//Search for an identical vertex in the list
				for ( unsigned short cv_index = 0; cv_index < compVerts.size(); ++cv_index ) {
					if ( compVerts[cv_index] == cv ) {
						//We found a match, push its index into the face list
						found_match = true;
						shapeFacePoints.push_back(cv_index);
						break;
					}
				}

				//If no match was found, append this vertex to the list
				if ( found_match == false ) {
					compVerts.push_back(cv);
					//put the new vertex into the face point list
					shapeFacePoints.push_back( unsigned int(compVerts.size()) - 1 );
				}
				
				//Next Point
			}

			//Starting from vertex 0, create a fan of triangles to fill
			//in non-triangle polygons
			Triangle new_face;
			for ( unsigned int i = 0; i < shapeFacePoints.size() - 2; ++i ) {
				new_face[0] = shapeFacePoints[0];
				new_face[1] = shapeFacePoints[i+1];
				new_face[2] = shapeFacePoints[i+2];

				//Push the face into the face list
				shapeTriangles.push_back(new_face);
			}

			//Next Face
		}

		//Attatch properties if any
		if ( propGroups.size() > 0 ) {
			for ( vector<NiPropertyRef>::const_iterator prop = propGroups[shape_num].begin(); prop != propGroups[shape_num].end(); ++prop ) {
				shapes[shape_num]->AddProperty( *prop );						
			}
		}

		//--Set Shape Data--//

		//lists to hold data
		vector<Vector3> shapeVerts( compVerts.size() );
		vector<Vector3> shapeNorms( compVerts.size() );
		vector<Color4> shapeColors( compVerts.size() );
		vector< vector<TexCoord> > shapeTCs;
		list<int> shapeTexCoordSets;
		map<NiNodeRef, vector<SkinWeight> > shapeWeights;

		//Search for a NiTexturingProperty to build list of
		//texture cooridinate sets to create
		NiPropertyRef niProp = shapes[shape_num]->GetPropertyByType( NiTexturingProperty::TypeConst() );
		NiTexturingPropertyRef niTexProp;
		if ( niProp != NULL ) {
			niTexProp = DynamicCast<NiTexturingProperty>(niProp);
		}
		if ( niTexProp != NULL ) {
			for ( int tex_num = 0; tex_num < 8; ++tex_num ) {
				if (niTexProp->HasTexture(tex_num)) {
					shapeTexCoordSets.push_back(tex_num);
				}
			}
		} else {
			//Always include the base map if it's there, whether there's a
			//texture or not
			shapeTexCoordSets.push_back( BASE_MAP );
		}
		shapeTCs.resize( shapeTexCoordSets.size() );
		for ( vector< vector<TexCoord> >::iterator set = shapeTCs.begin(); set != shapeTCs.end(); ++set ) {
			set->resize( compVerts.size() );
		}

		//Loop through all compound vertices, adding the data
		//to the correct arrays.
		uint vert_index = 0;
		for ( vector<CompoundVertex>::iterator cv = compVerts.begin(); cv != compVerts.end(); ++cv ) {
			shapeVerts[vert_index] = cv->position;
			shapeColors[vert_index] = cv->color;
			shapeNorms[vert_index] = cv->normal;
			shapeNorms[vert_index] = cv->normal;
			uint tex_index = 0;
			for ( list<int>::iterator tex = shapeTexCoordSets.begin(); tex != shapeTexCoordSets.end(); ++tex ) {
				if ( cv->texCoords.find( TexType(*tex) ) != cv->texCoords.end() ) {
					shapeTCs[tex_index][vert_index] = cv->texCoords[ TexType(*tex) ];
				}
				tex_index++;
			}
			SkinWeight sk;
			for ( map<NiNodeRef, float>::iterator wt = cv->weights.begin(); wt != cv->weights.end(); ++wt ) {
				//Only record influences that make a noticable contribution
				if ( wt->second > 0.0f ) {
					sk.index = vert_index;
					sk.weight = wt->second;
					if ( shapeWeights.find( wt->first ) == shapeWeights.end() ) {
						shapeWeights[wt->first] = vector<SkinWeight>();
					}
					shapeWeights[wt->first].push_back( sk );
				}
			}

			++vert_index;
		}

		//Finally, set the data into the NiTriShapeData
		if ( vertices.size() > 0 ) {
			niData->SetVertices( shapeVerts );
			niData->SetTriangles( shapeTriangles );
		}
		if ( normals.size() > 0 ) {
			niData->SetNormals( shapeNorms );
		}
		if ( colors.size() > 0 ) {
			niData->SetVertexColors( shapeColors );
		}
		if ( texCoordSets.size() > 0 ) {
			niData->SetUVSetCount( int(shapeTCs.size()) );
			for ( unsigned int tex_index = 0; tex_index < shapeTCs.size(); ++tex_index ) {
				niData->SetUVSet( tex_index, shapeTCs[tex_index] );
			}
		}

		//If there are any skin influences, bind the skin
		if ( shapeWeights.size() > 0 ) {
			vector<NiNodeRef> shapeInfluences;
			for ( map<NiNodeRef, vector<SkinWeight> >::iterator inf = shapeWeights.begin(); inf != shapeWeights.end(); ++inf ) {
				shapeInfluences.push_back( inf->first );
			}

			shapes[shape_num]->BindSkin( shapeInfluences );

			NiSkinInstanceRef skinInst = shapes[shape_num]->GetSkinInstance();

			if ( skinInst != NULL ) {
				NiSkinDataRef skinData = skinInst->GetSkinData();

				if ( skinData != NULL ) {
					for ( unsigned int inf = 0; inf < shapeInfluences.size(); ++inf ) {
						skinData->SetBoneWeights( inf, shapeWeights[ shapeInfluences[inf] ] );
					}
				}
			}
		}
		
		//Next Shape
	}

	return root;
}