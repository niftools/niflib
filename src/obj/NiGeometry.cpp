/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiGeometry.h"
#include "../../include/obj/NiGeometryData.h"
#include "../../include/obj/NiSkinInstance.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiNode.h"
#include "../../include/obj/NiSkinData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiGeometry::TYPE("NiGeometry", &NI_GEOMETRY_PARENT::TypeConst() );

NiGeometry::NiGeometry() NI_GEOMETRY_CONSTRUCT {}

NiGeometry::~NiGeometry() {}

void NiGeometry::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiGeometry::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiGeometry::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiGeometry::FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiGeometry::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiGeometry::GetType() const {
	return TYPE;
};

Ref<NiGeometryData> NiGeometry::GetData() const {
	return data;
}

void NiGeometry::SetData( const Ref<NiGeometryData> & n ) {
	data = n;
}

Ref<NiObject> NiGeometry::GetUnknownLink() const {
	return unknownLink;
}

void NiGeometry::SetUnknownLink( const Ref<NiObject> & n ) {
	unknownLink = n;
}

string NiGeometry::GetShader() const {
	return shaderName;
}

void NiGeometry::SetShader( const string & n ) {
	//Check if name is blank, if so clear shader
	if ( n.size() == 0 ) {
		hasShader = false;
		shaderName.clear();
	} else {
		shaderName = n;
	}
}

Ref<NiSkinInstance> NiGeometry::GetSkinInstance() const {
	return skinInstance;
}

void NiGeometry::BindSkin( vector< Ref<NiNode> > bone_nodes, bool bind_to_scene ) {
	//Ensure skin is not aleady bound
	if ( skinInstance != 0 ) {
		throw runtime_error("You have attempted to re-bind a skin that is already bound.  Unbind it first.");
	}

	//Ensure that some bones are given
	if ( bone_nodes.size() == 0 ) {
		throw runtime_error("You must specify at least one bone node.");
	}

	//--Find a suitable skeleton root--//

	//create lists of nodes that have an influence and this TriBasedGeom
	//as decendents
	int num_lists = int(bone_nodes.size()) + 1;
	vector< list<NiNodeRef> > ancestors( num_lists );

	if ( GetParent() == NULL ) {
		throw runtime_error("Attempted to bind skin on a shape with no parent.");
	}

	ancestors[bone_nodes.size()] = ListAncestors( GetParent() );
	
	for ( unsigned int i = 0; i < bone_nodes.size(); ++i ) {
		NiNodeRef bonePar = bone_nodes[i]->GetParent();
		if ( bonePar == NULL ) {
			throw runtime_error("Attempted to bind skin to a bone with no parent.  A skeleton root cannot be a bone so all bones must have at least one parent.");
		}
		ancestors[i] = ListAncestors( bonePar );
	}

	if ( ancestors[0].size() == 0 ) {
		throw runtime_error("Shape and all skin influence bones must be part of the same tree before skin bind can take place.");
	}

	NiNodeRef skeleton_root;
   if (bind_to_scene) {
      // Just parent to the scene
      NiNodeRef parent = GetParent();
      while (parent != NULL) {
         skeleton_root = parent;
         parent = parent->GetParent();
      }

   } else {
      skeleton_root = ancestors[0].front();

	   //Make sure bone and shapes are part of the same tree
	   for ( int i = 1; i < num_lists; ++i ) {
		   if ( ancestors[i].size() == 0 ) {
			   throw runtime_error("Shape and all skin influence bones must be part of the same tree before skin bind can take place.");
		   }
		   if ( ancestors[i].front() != skeleton_root ) {
			   throw runtime_error("Shape and all skin influence bones must be part of the same tree before skin bind can take place.");
		   }
	   }

	   //Since the first items have been shown to match, pop all the stacks
	   for ( int i = 0; i < num_lists; ++i ) {
		   ancestors[i].pop_front();
	   }

	   //Now search for the common ancestor

	   while(true) {
		   bool all_same = true;
		   if ( ancestors[0].size() == 0 ) {
			   //This list is over, so the last top is the common ancestor
			   //break out of the loop
			   break;
		   }
		   NiNodeRef first_ancestor = ancestors[0].front();
		   for ( int i = 1; i < num_lists; ++i ) {
			   if ( ancestors[i].size() == 0 ) {
				   //This list is over, so the last top is the common ancestor
				   //break out of the loop
				   all_same = false;
				   break;
			   }
			   if ( ancestors[i].front() != first_ancestor ) {
				   all_same = false;
			   }
		   }

		   if ( all_same == true ) {
			   //They're all the same, so set the top, pop all the stacks
			   //and look again
   			
			   skeleton_root = ancestors[0].front();
			   for ( int i = 0; i < num_lists; ++i ) {
				   ancestors[i].pop_front();
			   }
		   } else {
			   //One is different, so the last top is the common ancestor.
			   //break out of the loop
			   break;
		   }
	   }
   }

	if ( skeleton_root == NULL ) {
		throw runtime_error("Failed to find suitable skeleton root.");
	}

	//Create a skin instance using the bone and root data
	skinInstance = new NiSkinInstance( skeleton_root, bone_nodes );

	//Create a NiSkinData object based on this mesh
	skinInstance->SetSkinData( new NiSkinData( this ) );
};

list< Ref<NiNode> > NiGeometry::ListAncestors( const Ref<NiNode> & leaf ) const {
	if ( leaf == NULL ) {
		throw runtime_error("ListAncestors called with a NULL leaf NiNode Ref");
	}
	
	list<NiNodeRef> ancestors;

	NiNodeRef niNode = leaf;
	while (true) {
		ancestors.push_front(niNode);
		if ( niNode->GetParent() == NULL ) {
			break;
		} else {
			niNode = niNode->GetParent();
		}
	}

	return ancestors;
}

void NiGeometry::UnbindSkin() {
	//Clear skin instance
	skinInstance = NULL;
}

void NiGeometry::GetSkinDeformation( vector<Vector3> & vertices, vector<Vector3> & normals ) const{
	//--Get required data & insure validity--//

	NiGeometryDataRef geom_data = GetData();

	if ( geom_data == NULL ) {
		throw runtime_error("This NiGeometry has no NiGeometryData so there are no vertices to get.");
	}

	NiSkinInstanceRef skin_inst = GetSkinInstance();
	

	if ( skin_inst == NULL ) {
		throw runtime_error("This NiGeometry is not influenced by a skin.");
	}

	NiSkinDataRef skin_data = skin_inst->GetSkinData();

	if ( skin_data == NULL ) {
		throw runtime_error("Skin Data is missing, cannot calculate skin influenced vertex position.");
	}

	//Ensure that skin instance bone count & skin data bone count match
	if ( skin_inst->GetBoneCount() != skin_data->GetBoneCount() ) {
		throw runtime_error("Skin Instance and Skin Data bone count do not match.");
	}

	//Get skeleton root
	NiNodeRef skel_root = skin_inst->GetSkeletonRoot();
	if ( skel_root == NULL ) {
		throw runtime_error("Skin Instance is not bound to a skeleton root.");
	}

	//Get the vertices & bone nodes
	vector<Vector3> in_verts = geom_data->GetVertices();
	vector<Vector3> in_norms = geom_data->GetNormals();

	vector<NiNodeRef> bone_nodes = skin_inst->GetBones();

	//Set up output arrays to hold the transformed vertices and normals
	vertices.resize( in_verts.size() );
	normals.resize( in_norms.size() );

	//Transform vertices into position based on skin data
	Matrix44 root_world = skel_root->GetWorldTransform();
	Matrix44 geom_world = GetWorldTransform();
	for ( uint i = 0; i < skin_data->GetBoneCount(); ++i ) {
		Matrix44 bone_world = bone_nodes[i]->GetWorldTransform();
		Matrix44 bone_offset = skin_data->GetBoneTransform(i);
		vector<SkinWeight> weights = skin_data->GetBoneWeights(i);
		Matrix44 vert_trans =  bone_offset * bone_world;
		Matrix44 norm_trans = Matrix44( vert_trans.GetRotation() );
		for ( uint j = 0; j < weights.size(); ++j ) {
			uint index = weights[j].index;
			float weight = weights[j].weight;
			if ( index < vertices.size() ) {
				vertices[index] += (vert_trans * in_verts[index] ) * weight;
			}
			if ( index < normals.size() ) {
				normals[index] += (norm_trans * in_norms[index] ) * weight;
			}
		}
	}

	//Transform all vertices to final position
	Matrix44 geom_world_inv = geom_world.Inverse();
	Matrix44 geom_world_inv_rot = Matrix44( geom_world_inv.GetRotation() );
	for ( uint i = 0; i < vertices.size(); ++i ) {
		vertices[i] = geom_world_inv * vertices[i];
	}
	for ( uint i = 0; i < normals.size(); ++i ) {
		normals[i] = geom_world_inv_rot * normals[i];
		//normals[i] = normals[i].Normalized();
	}
}

// Calculate bounding sphere using minimum-volume axis-align bounding box.  Its fast but not a very good fit.
static void CalcAxisAlignedBox(const vector<SkinWeight> & n, const vector<Vector3>& vertices, Vector3& center, float& radius)
{
   //--Calculate center & radius--//

   //Set lows and highs to first vertex
   Vector3 lows = vertices[ n[0].index ];
   Vector3 highs = vertices[ n[0].index ];

   //Iterate through the vertices, adjusting the stored values
   //if a vertex with lower or higher values is found
   for ( unsigned int i = 0; i < n.size(); ++i ) {
      const Vector3 & v = vertices[ n[i].index ];

      if ( v.x > highs.x ) highs.x = v.x;
      else if ( v.x < lows.x ) lows.x = v.x;

      if ( v.y > highs.y ) highs.y = v.y;
      else if ( v.y < lows.y ) lows.y = v.y;

      if ( v.z > highs.z ) highs.z = v.z;
      else if ( v.z < lows.z ) lows.z = v.z;
   }

   //Now we know the extent of the shape, so the center will be the average
   //of the lows and highs
   center = (highs + lows) / 2.0f;

   //The radius will be the largest distance from the center
   Vector3 diff;
   float dist2(0.0f), maxdist2(0.0f);
   for ( unsigned int i = 0; i < n.size(); ++i ) {
      const Vector3 & v = vertices[ n[i].index ];

      diff = center - v;
      dist2 = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
      if ( dist2 > maxdist2 ) maxdist2 = dist2;
   };
   radius = sqrt(maxdist2);
}

// Calculate bounding sphere using average position of the points.  Better fit but slower.
static void CalcCenteredSphere(const vector<SkinWeight> & n, const vector<Vector3>& vertices, Vector3& center, float& radius)
{
   size_t nv = n.size();
   Vector3 sum;
   for (size_t i=0; i<nv; ++i)
      sum += vertices[ n[i].index ];
   center = sum / float(nv);
   radius = 0.0f;
   for (size_t i=0; i<nv; ++i){
      Vector3 diff = vertices[ n[i].index ] - center;
      float mag = diff.Magnitude();
      radius = max(radius, mag);
   }
}

void NiGeometry::SetBoneWeights( uint bone_index, const vector<SkinWeight> & n ) {
	
	if ( n.size() == 0 ) {
		throw runtime_error( "You must specify at least one weight value." );
	}

	NiSkinInstanceRef skinInst = GetSkinInstance();

	if ( skinInst == NULL ) {
		throw runtime_error( "You must bind a skin before setting vertex weights.  No NiSkinInstance found." );
	}

	NiSkinDataRef skinData = skinInst->GetSkinData();

	if ( skinData == NULL ) {
		throw runtime_error( "You must bind a skin before setting vertex weights.  No NiSkinData found." );
	}

	NiGeometryDataRef geomData = GetData();

	if ( geomData == NULL ) {
		throw runtime_error( "Attempted to set weights on a mesh with no geometry data." );
	}

	//Get vertex array
	vector<Vector3> vertices = geomData->GetVertices();

   Vector3 center; float radius;
   //CalcCenteredSphere(n, vertices, center, radius);
   CalcAxisAlignedBox(n, vertices, center, radius);

	//Translate center by bone matrix
	center = skinData->GetBoneTransform( bone_index ) * center;

	skinData->SetBoneWeights( bone_index, n, center, radius );
}
