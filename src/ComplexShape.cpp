/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../include/ComplexShape.h"
#include "../include/obj/NiNode.h"
#include "../include/obj/NiProperty.h"
#include "../include/obj/NiAVObject.h"
#include "../include/obj/NiTriBasedGeom.h"
#include "../include/obj/NiTriShape.h"
#include "../include/obj/NiTriStrips.h"
#include "../include/obj/NiTriStripsData.h"
#include "../include/obj/NiTriShapeData.h"
#include "../include/obj/NiTexturingProperty.h"
#include "../include/obj/NiSkinInstance.h"
#include "../include/obj/NiSkinData.h"
#include "../include/obj/NiTextureProperty.h"
#include "../include/gen/SkinWeight.h"

#include <stdlib.h>

using namespace Niflib;

//Wrape these in the Niflib namespace so they don't polute the Class View
namespace Niflib {

struct VertNorm {
	Vector3 position;
	Vector3 normal;
	map<NiNodeRef, float> weights;

	VertNorm() {}
	~VertNorm() {}
	VertNorm( const VertNorm & n ) {
		*this = n;
	}
	VertNorm & operator=( const VertNorm & n ) {
		position = n.position;
		normal = n.normal;
		weights = n.weights;
		return *this;
	}
	bool operator==( const VertNorm & n ) {
		if ( abs(position.x - n.position.x) > 0.001 || abs(position.y - n.position.y) > 0.001 || abs(position.z - n.position.z) > 0.001 ) {
			return false;
		}
		if ( abs(normal.x - n.normal.x) > 0.001 || abs(normal.y - n.normal.y) > 0.001 || abs(normal.z - n.normal.z) > 0.001 ) {
			return false;
		}
		//if ( weights != n.weights ) {
		//	return false;
		//}

		return true;
	}
};


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
		if ( color != n.color ) {
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

struct MergeLookUp {
	unsigned int vertIndex;
	unsigned int normIndex;
	unsigned int colorIndex;
	map<unsigned int, unsigned int> uvIndices; //TexCoordSet Index, TexCoord Index
};

} //End namespace

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

vector<WeightedVertex> ComplexShape::GetVertices() const {
	return vertices;
}

vector<Color4> ComplexShape::GetColors() const {
	return colors;
}

vector<Vector3> ComplexShape::GetNormals() const {
	return normals;
}

vector<TexCoordSet> ComplexShape::GetTexCoordSets() const {
	return texCoordSets;
}

vector<ComplexFace> ComplexShape::GetFaces() const {
	return faces;
}

vector< vector< Ref<NiProperty > > > ComplexShape::GetPropGroups() const {
	return propGroups;
}

vector< Ref<NiNode> > ComplexShape::GetSkinInfluences() const {
	return skinInfluences;
}

void ComplexShape::Clear() {
	vertices.clear();
	colors.clear();
	normals.clear();
	texCoordSets.clear();
	faces.clear();
	propGroups.clear();
	skinInfluences.clear();
	name.clear();
}

void ComplexShape::Merge( NiAVObject * root ) {

	if ( root == NULL ) {
		throw runtime_error("Called ComplexShape::Merge with a null root reference.");
	}

	vector<NiTriBasedGeomRef> shapes;

	//Determine root type
	if ( root->IsDerivedType( NiTriBasedGeom::TYPE ) ) {
		//The function was called on a single shape.
		//Add it to the list
		shapes.push_back( DynamicCast<NiTriBasedGeom>(root) );
	} else if ( root->IsDerivedType( NiNode::TYPE ) ) {
		//The function was called on a NiNOde.  Search for
		//shape children
		NiNodeRef nodeRoot = DynamicCast<NiNode>(root);
		vector<NiAVObjectRef> children = nodeRoot->GetChildren();
		for ( unsigned int child = 0; child < children.size(); ++child ) {
			if ( children[child]->IsDerivedType( NiTriBasedGeom::TYPE ) ) {
				shapes.push_back( DynamicCast<NiTriBasedGeom>(children[child]) );
			}
		}

		if ( shapes.size() == 0 ) {
			throw runtime_error("The NiNode passed to ComplexShape::Merge has no shape children.");
		}
	} else {
		throw runtime_error(" The ComplexShape::Merge function requies either a NiNode or a NiTriBasedGeom AVObject.");
	}

	//The vector of VertNorm struts allows us to to refuse
	//to merge vertices that have different normals.
	vector<VertNorm> vns;

	//Clear all existing data
	Clear();

	//Merge in data from each shape
	bool has_any_verts = false;
	bool has_any_norms = false;
	propGroups.resize( shapes.size() );
	unsigned int prop_group_index = 0;
	for ( vector<NiTriBasedGeomRef>::iterator geom = shapes.begin(); geom != shapes.end(); ++geom ) {
	
		//Get properties of this shape
		propGroups[prop_group_index] = (*geom)->GetProperties();
		
		
		NiTriBasedGeomDataRef geomData = DynamicCast<NiTriBasedGeomData>( (*geom)->GetData() );

		if ( geomData == NULL ) {
			throw runtime_error("One of the NiTriBasedGeom found by ComplexShape::Merge with a NiTriBasedGeom has no NiTriBasedGeomData attached.");
		}

		//Get Data
		vector<Vector3> shapeVerts;	
		vector<Vector3> shapeNorms;
		//If this is a skin influenced mesh, get vertices from niGeom
		if ( (*geom)->GetSkinInstance() != NULL ) {
			(*geom)->GetSkinDeformation( shapeVerts, shapeNorms );
		} else {
			shapeVerts = geomData->GetVertices();
			shapeNorms = geomData->GetNormals();
		}

		
		vector<Color4> shapeColors = geomData->GetColors();
		vector< vector<TexCoord> > shapeUVs( geomData->GetUVSetCount() );
		for ( unsigned int i = 0; i < shapeUVs.size(); ++i ) {
			shapeUVs[i] = geomData->GetUVSet(i);
		}
		vector<Triangle> shapeTris= geomData->GetTriangles();

		//Lookup table
		vector<MergeLookUp> lookUp( geomData->GetVertexCount() );

		//Vertices and normals
		if ( shapeVerts.size() != 0 ) {
			has_any_verts = true;
		}

		bool shape_has_norms = ( shapeNorms.size() == shapeVerts.size() );

		if ( shape_has_norms ) {
			has_any_norms = true;
		}
		for ( unsigned int v = 0; v < shapeVerts.size(); ++v ) {
			VertNorm newVert;

			newVert.position = shapeVerts[v];
			if ( shape_has_norms ) {
				newVert.normal = shapeNorms[v];
			}

			//Search for matching vert/norm
			bool match_found = false;
			for ( unsigned int vn_index = 0; vn_index < vns.size(); ++vn_index ) {
				if ( vns[vn_index] == newVert ) {
					//Match found, use existing index
					lookUp[v].vertIndex = vn_index;
					if ( shapeNorms.size() != 0 ) {
						lookUp[v].normIndex = vn_index;
					}
					match_found = true;
					//Stop searching
					break;
				}
			}

			if ( match_found == false ) {
				//No match found, add this vert/norm to the list
				vns.push_back(newVert);
				//Record new index
				lookUp[v].vertIndex = (unsigned int)(vns.size()) - 1;
				if ( shapeNorms.size() != 0 ) {
					lookUp[v].normIndex = (unsigned int)(vns.size()) - 1;
				}
			}
		}

		//Colors
		for ( unsigned int c = 0; c < shapeColors.size(); ++c ) {
			Color4 newColor;

			newColor = shapeColors[c];

			//Search for matching color
			bool match_found = false;
			for ( unsigned int c_index = 0; c_index < colors.size(); ++c_index ) {
				if ( colors[c_index].r == newColor.r && colors[c_index].g == newColor.g && colors[c_index].b == newColor.b && colors[c_index].a == newColor.a ) {
					//Match found, use existing index
					lookUp[c].colorIndex = c_index;
					match_found = true;
					//Stop searching
					break;
				}
			}

			if ( match_found == false ) {
				//No match found, add this color to the list
				colors.push_back(newColor);
				//Record new index
				lookUp[c].colorIndex = (unsigned int)(colors.size()) - 1;
			}
		}

		//Texture Coordinates

		//Create UV set list
		vector<TexType> uvSetList( shapeUVs.size() );
		//Initialize to base
		for ( unsigned int tex = 0; tex < uvSetList.size(); ++tex ) {
			uvSetList[tex] = BASE_MAP;
		}
		NiPropertyRef niProp = (*geom)->GetPropertyByType( NiTexturingProperty::TYPE );
		NiTexturingPropertyRef niTexingProp;
		if ( niProp != NULL ) {
			niTexingProp = DynamicCast<NiTexturingProperty>(niProp);
		}
		niProp = (*geom)->GetPropertyByType( NiTextureProperty::TYPE );
		NiTexturePropertyRef niTexProp;
		if ( niProp != NULL ) {
			niTexProp = DynamicCast<NiTextureProperty>(niProp);
		}

		//Create a list of UV sets to check
		//pair.first = Texture Type
		//pair.second = UV Set ID
		vector< pair<TexType, unsigned int> > uvSets;

		if ( shapeUVs.size() != 0 && (niTexingProp != NULL || niTexProp != NULL) ) {
			if ( niTexingProp != NULL ) {
				//Add the UV set to the list for every type of texture slot that uses it
				for ( int tex = 0; tex < 8; ++tex ) {
					if ( niTexingProp->HasTexture(tex) == true ) {
						TexDesc td;
						td = niTexingProp->GetTexture(tex);
						
						uvSets.push_back( pair<TexType, unsigned int>( TexType(tex), td.uvSet ) );
					}
				}
			} else if ( niTexProp != NULL ) {
				//Add the base UV set to the list and just use zero.
				uvSets.push_back( pair<TexType, unsigned int>( BASE_MAP, 0 ) );
			}

			//Add the UV set to the list for every type of texture slot that uses it
			for ( size_t i = 0; i < uvSets.size(); ++i ) {

				TexType newType = uvSets[i].first;
				unsigned int set = uvSets[i].second;

				//Search for matching UV set
				bool match_found = false;
				unsigned int uvSetIndex;
				for ( unsigned int set_index = 0; set_index < texCoordSets.size(); ++set_index ) {
					if ( texCoordSets[set_index].texType  == newType ) {
						//Match found, use existing index
						uvSetIndex = set_index;
						match_found = true;
						//Stop searching
						break;
					}
				}

				if ( match_found == false ) {
					//No match found, add this UV set to the list
					TexCoordSet newTCS;
					newTCS.texType = newType;
					texCoordSets.push_back( newTCS );
					//Record new index
					uvSetIndex = (unsigned int)(texCoordSets.size()) - 1;
				}

				//Loop through texture cooridnates in this set
				if ( set >= shapeUVs.size() || set < 0 ) {
					throw runtime_error("One of the UV sets specified in the NiTexturingProperty did not exist in the NiTriBasedGeomData.");
				}
				for ( unsigned int v = 0; v < shapeUVs[set].size(); ++v ) {
					TexCoord newCoord;

					newCoord = shapeUVs[set][v];

					//Search for matching texture cooridnate
					bool match_found = false;
					for ( unsigned int tc_index = 0; tc_index < texCoordSets[uvSetIndex].texCoords.size(); ++tc_index ) {
						if ( texCoordSets[uvSetIndex].texCoords[tc_index]  == newCoord ) {
							//Match found, use existing index
							lookUp[v].uvIndices[uvSetIndex] = tc_index;
							match_found = true;
							//Stop searching
							break;
						}
					}

					//Done with loop, check if match was found
					if ( match_found == false ) {
						//No match found, add this texture coordinate to the list
						texCoordSets[uvSetIndex].texCoords.push_back( newCoord );
						//Record new index
						lookUp[v].uvIndices[uvSetIndex] = (unsigned int)(texCoordSets[uvSetIndex].texCoords.size()) - 1;
					}
				}
			}
		}

		//Use look up table to build list of faces
		for ( unsigned int t = 0; t < shapeTris.size(); ++t ) {
			ComplexFace newFace;
			newFace.propGroupIndex = prop_group_index;
			newFace.points.resize(3);
			const Triangle & tri = shapeTris[t];
			for ( unsigned int p = 0; p < 3; ++p ) {
				if ( shapeVerts.size() != 0 ) {
					newFace.points[p].vertexIndex = lookUp[ tri[p] ].vertIndex;
				}
				if ( shapeNorms.size() != 0 ) {
					newFace.points[p].normalIndex = lookUp[ tri[p] ].normIndex;
				}
				if ( shapeColors.size() != 0 ) {
					newFace.points[p].colorIndex = lookUp[ tri[p] ].colorIndex;
				}
				for ( map<unsigned int,unsigned int>::iterator set = lookUp[ tri[p] ].uvIndices.begin(); set != lookUp[ tri[p] ].uvIndices.end(); ++set ) {
					TexCoordIndex tci;
					tci.texCoordSetIndex = set->first;
					tci.texCoordIndex = set->second;
					newFace.points[p].texCoordIndices.push_back(tci);
				}
			}
			faces.push_back(newFace);
		}

		//Use look up table to set vertex weights, if any
		NiSkinInstanceRef skinInst = (*geom)->GetSkinInstance();

		if ( skinInst != NULL ) {

			NiSkinDataRef skinData = skinInst->GetSkinData();

			if ( skinData !=NULL ) {
				//Get influence list
				vector<NiNodeRef> shapeBones = skinInst->GetBones();

				//Get weights
				vector<SkinWeight> shapeWeights;
				for ( unsigned int b = 0; b < shapeBones.size(); ++b ) {
					shapeWeights = skinData->GetBoneWeights(b);
					for ( unsigned int w = 0; w < shapeWeights.size(); ++w ) {
						unsigned int vn_index = lookUp[ shapeWeights[w].index ].vertIndex;
						NiNodeRef boneRef = shapeBones[b];
						float weight = shapeWeights[w].weight;

						vns[vn_index].weights[boneRef] = weight;
					}
				}
			}
		}

		//Next Shape
		++prop_group_index;
	}

	//Finished with all shapes.  Build up a list of influences
	map<NiNodeRef,unsigned int> boneLookUp;
	for ( unsigned int v = 0; v < vns.size(); ++v ) {
		for ( map<NiNodeRef,float>::iterator w = vns[v].weights.begin(); w != vns[v].weights.end(); ++w ) {
			boneLookUp[w->first] = 0; //will change later
		}
	}

	skinInfluences.resize( boneLookUp.size() );
	unsigned int si_index = 0;
	for ( map<NiNodeRef,unsigned int>::iterator si = boneLookUp.begin(); si != boneLookUp.end(); ++si ) {
		si->second = si_index;
		skinInfluences[si_index] = si->first;
		++si_index;
	}
	
	//Copy vns data to vertices and normals
	if ( has_any_verts ) {
		vertices.resize( vns.size() );
	}
	if ( has_any_norms ) {
		normals.resize( vns.size() );
	}

	for ( unsigned int v = 0; v < vns.size(); ++v ) {
		if ( has_any_verts ) {
			vertices[v].position = vns[v].position;
			vertices[v].weights.resize( vns[v].weights.size() );
			unsigned int weight_index = 0;
			for ( map<NiNodeRef,float>::iterator w = vns[v].weights.begin(); w != vns[v].weights.end(); ++w ) {
				vertices[v].weights[weight_index].influenceIndex = boneLookUp[w->first];
				vertices[v].weights[weight_index].weight = w->second;
				++weight_index;
			}
		}
		if ( has_any_norms ) {
			normals[v] = vns[v].normal;
		}
	}
	//Done Merging
}

Ref<NiAVObject> ComplexShape::Split( NiNode * parent, Matrix44 & transform, int max_bones_per_partition, bool stripify, bool tangent_space, float min_vertex_weight ) const {

	//Make sure parent is not NULL
	if ( parent == NULL ) {
		throw runtime_error ("A parent is necessary to split a complex shape.");
	}

	//There will be one NiTriShape per property group
	//with a minimum of 1
	unsigned int num_shapes = (unsigned int)(propGroups.size());
	if ( num_shapes == 0 ) {
		num_shapes = 1;
	}

	vector<NiTriBasedGeomRef> shapes(num_shapes);

	//Loop through each shape slot and create a NiTriShape
	for ( unsigned int shape_num = 0; shape_num < shapes.size(); ++shape_num ) {
		if ( stripify ) {
			shapes[shape_num] = new NiTriStrips;
		} else {
			shapes[shape_num] = new NiTriShape;
		}
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

	//Set transfrm of root
	root->SetLocalTransform( transform );

	//Create NiTriShapeData and fill it out with all data that is relevant
	//to this shape based on the material.
	for ( unsigned int shape_num = 0; shape_num < shapes.size(); ++shape_num ) {

		NiTriBasedGeomDataRef niData;
		
		if ( stripify ) {
			niData = new NiTriStripsData;
		} else {
			niData = new NiTriShapeData;
		}
		shapes[shape_num]->SetData( StaticCast<NiGeometryData>(niData) );

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
					shapeFacePoints.push_back( (unsigned int)(compVerts.size()) - 1 );
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
		NiPropertyRef niProp = shapes[shape_num]->GetPropertyByType( NiTexturingProperty::TYPE );
		NiTexturingPropertyRef niTexProp;
		if ( niProp != NULL ) {
			niTexProp = DynamicCast<NiTexturingProperty>(niProp);
		}
		if ( niTexProp != NULL ) {
			for ( int tex_num = 0; tex_num < 8; ++tex_num ) {
				if (niTexProp->HasTexture(tex_num)) {
					shapeTexCoordSets.push_back(tex_num);
					TexDesc td = niTexProp->GetTexture(tex_num);
					td.uvSet = int(shapeTexCoordSets.size()) - 1;
					niTexProp->SetTexture(tex_num, td);
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
		unsigned int vert_index = 0;
		for ( vector<CompoundVertex>::iterator cv = compVerts.begin(); cv != compVerts.end(); ++cv ) {
			shapeVerts[vert_index] = cv->position;
			shapeColors[vert_index] = cv->color;
			shapeNorms[vert_index] = cv->normal;
			shapeNorms[vert_index] = cv->normal;
			unsigned int tex_index = 0;
			for ( list<int>::iterator tex = shapeTexCoordSets.begin(); tex != shapeTexCoordSets.end(); ++tex ) {
				if ( cv->texCoords.find( TexType(*tex) ) != cv->texCoords.end() ) {
					shapeTCs[tex_index][vert_index] = cv->texCoords[ TexType(*tex) ];
				}
				tex_index++;
			}
			SkinWeight sk;
			for ( map<NiNodeRef, float>::iterator wt = cv->weights.begin(); wt != cv->weights.end(); ++wt ) {
				//Only record influences that make a noticable contribution
				if ( wt->second > min_vertex_weight ) {
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

			for ( unsigned int inf = 0; inf < shapeInfluences.size(); ++inf ) {
				shapes[shape_num]->SetBoneWeights( inf, shapeWeights[ shapeInfluences[inf] ] );
			}

			shapes[shape_num]->NormalizeSkinWeights();

			if ( max_bones_per_partition > 0 ) {
				shapes[shape_num]->GenHardwareSkinInfo( max_bones_per_partition, 4, stripify);
			}

			//NiSkinInstanceRef skinInst = shapes[shape_num]->GetSkinInstance();

			//if ( skinInst != NULL ) {
			//	NiSkinDataRef skinData = skinInst->GetSkinData();

			//	if ( skinData != NULL ) {
			//		for ( unsigned int inf = 0; inf < shapeInfluences.size(); ++inf ) {
			//			skinData->SetBoneWeights( inf, shapeWeights[ shapeInfluences[inf] ] );
			//		}
			//	}
			//}
		}

		//If tangent space was requested, generate it
		if ( tangent_space ) {
			shapes[shape_num]->UpdateTangentSpace();
		}
		
		//Next Shape
	}

	return root;
}
