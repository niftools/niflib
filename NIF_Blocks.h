/* Copyright (c) 2005, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above
     copyright notice, this list of conditions and the following
     disclaimer in the documentation and/or other materials provided
     with the distribution.

   * Neither the name of the NIF File Format Library and Tools
     project nor the names of its contributors may be used to endorse
     or promote products derived from this software without specific
     prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

#ifndef _NIF_BLOCKS_H
#define _NIF_BLOCKS_H

/* INCLUDES */
#include "niflib.h"
#include "nif_math.h"
#include "NIF_IO.h"

#include <vector>
#include <list>
#include <map>
#include <cmath>
#include <sstream>

//--Types--//
typedef	pair<attr_ref, blk_ref> LinkPair;
typedef multimap<attr_ref, blk_ref> LinkMap;
typedef LinkMap::iterator LinkMapIt;
typedef pair<LinkMapIt,LinkMapIt> LinkMapRange;

//--Constants--//

//Non-Public Interface IDs
const int BlockInternal = -1;
const int SkinInstInternal = -2;
const int SkinDataInternal = -3;
const int NodeInternal = -4;


//void GetBuiltUpTransform(blk_ref block, Matrix & m/*, blk_ref stop*/);

class IBlockInternal {
public:
	//Cross Reference
	virtual void AddParent( blk_ref parent ) = 0;
	virtual void RemoveParent( IBlock * match ) = 0;
	virtual void SetBlockNum( int ) = 0;
	virtual void FixUpLinks( const vector<blk_ref> & blocks ) = 0;

	//File I/O
	virtual void Read( ifstream& in, unsigned int version ) = 0;
	virtual void Write( ofstream& out, unsigned int version ) = 0;	
};

class ABlock : public IBlock, public IBlockInternal {
public:
	ABlock();
	~ABlock();
	void AddAttr( AttrTypes type, string name, unsigned int first_ver = 0, unsigned int last_ver = 0xFFFFFFFF );
	attr_ref GetAttr(string attr_name);
	vector<attr_ref> GetAttrs();
	int GetBlockNum() { return _block_num; }
	string asString();

	//Links
	blk_ref GetParent();
	list<blk_ref> GetLinks();

	//Reference Counting
	void AddRef();
	void SubtractRef();

	//Interface
	void * QueryInterface( int id ) {
		if ( id == BlockInternal ) {
			return (void*)static_cast<IBlockInternal*>(this);;
		} else {
			return NULL;
		}
	}

	//Name Functions
	virtual bool Namable() { return _namable; }
	virtual void SetName( string & name ) { _name = name; }
	virtual string GetName() { return _name; }

	//--Internal Functions--//
	void AddParent( blk_ref parent);
	void RemoveParent( IBlock * match );
	void SetBlockNum( int n ) { _block_num = n; }
	void FixUpLinks( const vector<blk_ref> & blocks );

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
protected:
	map<string, attr_ref> _attr_map;
	vector<attr_ref> _attr_vect;
	int _block_num;
	unsigned int _ref_count;
	vector<IBlock*> _parents;
	bool _namable;
	unsigned int _first_named_ver;
	string _name;
};

class AControllable : public ABlock {
public:
	AControllable();
	void Init() {}
	~AControllable() {}
};

class ANamed : public AControllable {
public:
	ANamed();
	void Init() { _namable = true; }
	~ANamed() {}
};

class INodeInternal {
public:
	virtual void IncSkinRef( IBlock * skin_data ) = 0;
	virtual void DecSkinRef( IBlock * skin_data ) = 0;
};

class ANode : public ANamed, public INode, public INodeInternal {
public:
	ANode();
	void Init() { SetIdentity44(bindPosition); };
	~ANode();
	void InitAttrs();
	void * QueryInterface( int id );
	void Read( ifstream& in, unsigned int version ) {
		ABlock::Read( in, version );
		Matrix44 transform;
		transform = GetLocalTransform();
		SetBindPosition( transform );
	}

	//INode Functions
	Matrix44 GetLocalTransform();
	Matrix44 GetWorldTransform();
	Matrix44 GetBindPosition();
	Matrix44 GetLocalBindPos();
	void SetBindPosition( Matrix44 & m );

	//INodeInternal Functions
	void IncSkinRef( IBlock * skin_data );
	void DecSkinRef( IBlock * skin_data );

protected:
	Matrix44 bindPosition;
	list<IBlock*> skin_refs;
};

class AParentNode : public ANode {
public:
	AParentNode();
	void Init() {}
	~AParentNode() {}
};

class AShape : public ANode {
public:
	AShape();
	void Init() {}
	~AShape() {}
};

class AProperty : public ANamed {
public:
	AProperty();
	void Init() {}
	~AProperty() {}
};

class AController : public ABlock {
public:
	AController();
	void Init() {}
	~AController() {}
};

class AData : public ABlock {
public:
	AData() {}
	void Init() {}
	~AData() {}
};

class AExtraData : public AData {
public:
	AExtraData() {
		_namable = true;
		_first_named_ver = VER_10_0_1_0; //10.0.1.0
		AddAttr( attr_link, "Next Extra Data", 0, VER_4_2_2_0 );
	}
	~AExtraData() {};
};


class AParticleSystemController : public AController {
public:
	AParticleSystemController();
	void Init() {}
	~AParticleSystemController() {}
};

class ALight   : public ANode {
public:
	ALight();
	void Init() {}
	~ALight() {}
};

/**
 * NiNode - Root of each model component.
 */
class NiNode : public AParentNode {
public:

	NiNode();
	void Init() {}
	~NiNode() {}
	string GetBlockType() { return "NiNode"; }
	string asString();
};

/**
 * RootCollisionNode
 */
class RootCollisionNode : public AParentNode {
public:

	RootCollisionNode();
	void Init() {}
	~RootCollisionNode() {}

	string GetBlockType() { return "RootCollisionNode"; }
};

/**
 * AvoidNode
 */
class AvoidNode : public AParentNode {
public:

	AvoidNode();
	void Init() {}
	~AvoidNode() {}

	string GetBlockType() { return "AvoidNode"; }
};

/**
 * NiBillboardNode
 */
class NiBillboardNode : public AParentNode {
public:
	NiBillboardNode();
	void Init() {}
	~NiBillboardNode() {}

	string GetBlockType() { return "NiBillboardNode"; }
};

/**
 * NiBSAnimationNode
 */
class NiBSAnimationNode : public AParentNode {
public:
	NiBSAnimationNode();
	void Init() {}
	~NiBSAnimationNode() {}

	string GetBlockType() { return "NiBSAnimationNode"; }
};

/**
 * NiBSParticleNode
 */
class NiBSParticleNode : public AParentNode {
public:
	NiBSParticleNode();
	void Init() {}
	~NiBSParticleNode() {}

	string GetBlockType() { return "NiBSParticleNode"; }
};

/**
 * NiLODNode
 */
class NiLODNode : public AParentNode {
public:
	NiLODNode();
	void Init() {}
	~NiLODNode() {}

	string GetBlockType() { return "NiLODNode"; }
};

/**
 * ZBuffer data.
 */
class NiZBufferProperty : public AProperty {
public:
	NiZBufferProperty();
	void Init() {}
	~NiZBufferProperty() {}

	string GetBlockType() { return "NiZBufferProperty"; }
};

/**
 * NiShadeProperty
 */
class NiShadeProperty : public AProperty {
public:

	NiShadeProperty();
	void Init() {}
	~NiShadeProperty() {}

	string GetBlockType() { return "NiShadeProperty"; }
};

/**
 * ZBuffer data.NiWireframeProperty
 */
class NiWireframeProperty : public AProperty {
public:

	NiWireframeProperty();
	void Init() {}
	~NiWireframeProperty() {}

	string GetBlockType() { return "NiWireframeProperty"; }
};

/**
 * NiDitherProperty
 */
class NiDitherProperty : public AProperty {
public:

	NiDitherProperty();
	void Init() {}
	~NiDitherProperty() {}

	string GetBlockType() { return "NiDitherProperty"; }
};

/**
 * NiSequenceStreamHelper 
 */
class NiSequenceStreamHelper  : public ANamed {
public:

	NiSequenceStreamHelper ();
	void Init() {}
	~NiSequenceStreamHelper () {}

	string GetBlockType() { return "NiSequenceStreamHelper"; }
};

/**
 * NiVertexColorProperty - Vertex colour data.
 */
class NiVertexColorProperty : public AProperty{
public:

	NiVertexColorProperty();
	void Init() {}
	~NiVertexColorProperty() {}

	string GetBlockType() { return "NiVertexColorProperty"; }
};



/**
 * NiTriShape - 
 */
class NiTriShape : public AShape {
public:
	NiTriShape();
	void Init() {}
	~NiTriShape() {}

	string GetBlockType() { return "NiTriShape"; }
};

/**
 * NiTriStrips - 
 */
class NiTriStrips : public AShape {
public:
	NiTriStrips();
	void Init() {}
	~NiTriStrips() {}

	string GetBlockType() { return "NiTriStrips"; }
};

/**
 * NiTexturingProperty -
 */
class NiTexturingProperty : public AProperty {
public:
	NiTexturingProperty( );
	void Init() {}
	~NiTexturingProperty() {}
	string GetBlockType() { return "NiTexturingProperty"; }
};

/**
 * NiSourceTexture - Data for the associated texture, included in nif or external.
 */
class NiSourceTexture : public ANamed{
public:
	NiSourceTexture();
	void Init() {}
	~NiSourceTexture() {}
	string GetBlockType() { return "NiSourceTexture"; }
};



/**
 * NiPixelData - Texture data for an included texture.
 */
class NiPixelData : public AData {
public:
	NiPixelData() {
		AddAttr( attr_link, "Unknown Index" );
		data = NULL; }
	~NiPixelData() { if (data != NULL) delete [] data; }

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiPixelData"; }

private:
	struct MipMap {
		uint width, height, offset;
	};
	
	uint unknownInt, rMask, gMask, bMask, aMask, bpp;
	byte unknown8Bytes[8];
	uint bytesPerPixel;
	vector<MipMap> mipmaps;
	uint dataSize;
	byte * data;
};

/**
 * NiMaterialProperty - material properties
 */
class NiMaterialProperty : public AProperty{
public:
	NiMaterialProperty();
	void Init() {}
	~NiMaterialProperty() {}
	string GetBlockType() { return "NiMaterialProperty"; };
};

/**
 * NiSpecularProperty -
 */
class NiSpecularProperty : public AProperty {
public:
	NiSpecularProperty();
	void Init() {}
	~NiSpecularProperty() {}
	string GetBlockType() { return "NiSpecularProperty"; };
};

/**
 * NiStencilProperty -
 */
class NiStencilProperty : public AProperty {
public:
	NiStencilProperty();
	void Init() {}
	~NiStencilProperty() {}
	string GetBlockType() { return "NiStencilProperty"; };
};

/**
 * NiAlphaProperty - Does the mesh have alpha-blending enabled?
 */
class NiAlphaProperty : public AProperty {
public:
	NiAlphaProperty();
	void Init() {}
	~NiAlphaProperty() {}
	string GetBlockType() { return "NiAlphaProperty"; }
};

/**
 * AShapeData - Mesh data: vertices, vertex normals, etc.
 */
class AShapeData : public AData, public IShapeData {
public:
	AShapeData() {
		AddAttr( attr_float3, "Center" );
		AddAttr( attr_float, "Radius" );
	}
	~AShapeData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();

	void * QueryInterface( int id );

	//--IShapeData--//
	//Counts
	short GetVertexCount() { return short(vertices.size()); }
	short GetUVSetCount() { return short(uv_sets.size()); }
	void SetVertexCount(int n);
	void SetUVSetCount(int n);
	//Getters
	vector<Vector3> GetVertices() { return vertices; }
	vector<Vector3> GetNormals() { return normals; }
	vector<Color> GetColors() { return colors; }
	vector<UVCoord> GetUVSet( int index ) { return uv_sets[index]; }
	//Setters
	void SetVertices( const vector<Vector3> & in );
	void SetNormals( const vector<Vector3> & in );
	void SetColors( const vector<Color> & in );
	void SetUVSet( int index, const vector<UVCoord> & in );
protected:
	vector<Vector3> vertices;
	vector<Vector3> normals;
	vector<Color> colors;
	vector< vector<UVCoord> > uv_sets;
};

/**
 * AParticlesData - Generic particle system data block.
 */

class AParticlesData : public AShapeData {
public:
	AParticlesData() {
		AddAttr( attr_float, "Active Radius" );
		AddAttr( attr_short, "Unknown Short", VER_4_1_0_12 );
	}
	~AParticlesData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
protected:
	bool hasSizes;
	short numActive, numValid;
	vector<float> sizes;
};

/**
 * ARotatingParticlesData - Generic rotating particles data block. 
 */

class ARotatingParticlesData : public AParticlesData {
public:
	ARotatingParticlesData() {}
	~ARotatingParticlesData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
protected:
	bool hasRotations;
	vector<Quaternion> rotations;
};

/**
 * NiParticleMeshesData - Particle meshes data. 
 */

class NiParticleMeshesData : public ARotatingParticlesData {
public:
	NiParticleMeshesData() {
		AddAttr( attr_link, "Unknown Link" );
	}
	~NiParticleMeshesData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();

	string GetBlockType() { return "NiParticleMeshesData"; }
protected:
	
};

/**
 * NiAutoNormalParticlesData - Particle system data block (emits particles along vertex normals?).
 */

class NiAutoNormalParticlesData : public AParticlesData {
public:
	NiAutoNormalParticlesData() {}
	~NiAutoNormalParticlesData() {}
	string GetBlockType() { return "NiAutoNormalParticlesData"; }
};

/**
 * NiTriShapeData - Holds mesh data using a list of singular triangles.
 */
class NiTriShapeData : public AShapeData, public ITriShapeData {
public:
	NiTriShapeData() : match_group_mode(false) {}
	~NiTriShapeData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiTriShapeData"; }
	void * QueryInterface( int id );

	//--ITriShapeData--//
	//Counts
	short GetTriangleCount() { return short(triangles.size()); }
	void SetTriangleCount(int n);
	//Match Detection
	void SetMatchDetectionMode(bool choice) { match_group_mode = choice; }
	bool GetMatchDetectionMode() { return match_group_mode; }
	//Getters
	vector<Triangle> GetTriangles() { return triangles; }
	//Setters
	void SetTriangles( const vector<Triangle> & in );

private:
	vector<Triangle> triangles;
	bool match_group_mode;
};

/**
 * NiTriStripsData - Holds mesh data using strips of triangles.
 */
class NiTriStripsData : public AShapeData {
public:
	NiTriStripsData() {}
	~NiTriStripsData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();

	string GetBlockType() { return "NiTriStripsData"; }

private:
	vector< vector<short> > strips;
};

/**
 * NiCollisionData - Collision box.
 */
class NiCollisionData : public AData {
public:
	NiCollisionData() {
		AddAttr( attr_int, "Unknown Int 1" );
		AddAttr( attr_int, "Unknown Int 2" );
		AddAttr( attr_byte, "Unknown Byte" );
		AddAttr( attr_int, "Unknown Int 3" );
		AddAttr( attr_int, "Unknown Int 4" );
		AddAttr( attr_float3, "Radius" );
	}
	~NiCollisionData() {}

	string GetBlockType() { return "NiCollisionData"; }
};



/**
 * NiKeyframeController
 */
class NiKeyframeController : public AController {
public:
	NiKeyframeController();
	void Init() {}
	~NiKeyframeController() {}
	string GetBlockType() { return "NiKeyframeController"; }
};

/**
 * NiKeyframeController
 */
class NiLookAtController : public AController {
public:
	NiLookAtController();
	void Init() {}
	~NiLookAtController() {}
	string GetBlockType() { return "NiLookAtController"; }
};

/**
 * NiAlphaController
 */
class NiAlphaController : public AController {
public:
	NiAlphaController();
	void Init() {}
	~NiAlphaController() {}
	string GetBlockType() { return "NiAlphaController"; }
};

/**
 * NiFlipController
 */
class NiFlipController : public AController {
public:
	NiFlipController();
	void Init() {}
	~NiFlipController() {}
	string GetBlockType() { return "NiFlipController"; }
};

/**
 * NiVisController
 */
class NiVisController : public AController {
public:
	NiVisController();
	void Init() {}
	~NiVisController() {}
	string GetBlockType() { return "NiVisController"; }
};

/**
 * NiMaterialColorController
 */
class NiMaterialColorController : public AController {
public:
	NiMaterialColorController();
	void Init() {}
	~NiMaterialColorController() {}
	string GetBlockType() { return "NiMaterialColorController"; }
};

/**
 * NiUVController 
 */
class NiUVController : public AController {
public:
	NiUVController();
	void Init() {}
	~NiUVController() {}
	string GetBlockType() { return "NiUVController"; }
};

/**
 * NiPathController
 */

class NiPathController : public AController {
public:
	NiPathController();
	void Init() {}
	~NiPathController() {}
	string GetBlockType() { return "NiPathController"; }
};

/**
 * NiAmbientLight - Not found in any official NIF files
 */

class NiAmbientLight : public ALight {
public:
	NiAmbientLight();
	void Init() {}
	~NiAmbientLight() {}
	string GetBlockType() { return "NiAmbientLight"; }
};

/**
 * NiDirectionalLight - Not found in any official NIF files
 */

class NiDirectionalLight : public ALight {
public:
	NiDirectionalLight();
	void Init() {}
	~NiDirectionalLight() {}
	string GetBlockType() { return "NiDirectionalLight"; }
};

/**
 * NiAutoNormalParticles
 */

class NiAutoNormalParticles : public ANode {
public:
	NiAutoNormalParticles();
	void Init() {}
	~NiAutoNormalParticles() {}
	string GetBlockType() { return "NiAutoNormalParticles"; }
};

/**
 * NiRotatingParticles
 */

class NiRotatingParticles : public ANode {
public:
	NiRotatingParticles();
	void Init() {}
	~NiRotatingParticles() {}
	string GetBlockType() { return "NiRotatingParticles"; }
}; 

/**
 * NiTextureEffect
 */

class NiTextureEffect : public ANode {
public:
	NiTextureEffect();
	void Init() {}
	~NiTextureEffect() {}
	string GetBlockType() { return "NiTextureEffect"; }
}; 

/**
 * NiCamera
 */

class NiCamera : public ANode {
public:
	NiCamera();
	void Init() {}
	~NiCamera() {}
	string GetBlockType() { return "NiCamera"; }
}; 

/**
 * NiParticleMeshes
 */

class NiParticleMeshes : public ANode {
public:
	NiParticleMeshes();
	void Init() {}
	~NiParticleMeshes() {}
	string GetBlockType() { return "NiParticleMeshes"; }
}; 

/**
 * NiGravity
 */

class NiGravity : public AControllable {
public:
	NiGravity();
	void Init() {}
	~NiGravity() {}
	string GetBlockType() { return "NiGravity"; }
}; 

/**
 * NiParticleBomb
 */

class NiParticleBomb : public AControllable {
public:
	NiParticleBomb();
	void Init() {}
	~NiParticleBomb() {}
	string GetBlockType() { return "NiParticleBomb"; }
}; 

/**
 * NiPlanarCollider
 */

class NiPlanarCollider : public AControllable {
public:
	NiPlanarCollider();
	void Init() {}
	~NiPlanarCollider() {}
	string GetBlockType() { return "NiPlanarCollider"; }
}; 

/**
 * NiPlanarCollider
 */

class NiSphericalCollider : public AControllable {
public:
	NiSphericalCollider();
	void Init() {}
	~NiSphericalCollider() {}
	string GetBlockType() { return "NiSphericalCollider"; }
}; 

/**
 * NiParticleGrowFade
 */

class NiParticleGrowFade : public AControllable {
public:
	NiParticleGrowFade();
	void Init() {}
	~NiParticleGrowFade() {}
	string GetBlockType() { return "NiParticleGrowFade"; }
}; 

/**
 * NiParticleMeshModifier
 */

class NiParticleMeshModifier : public AControllable {
public:
	NiParticleMeshModifier();
	void Init() {}
	~NiParticleMeshModifier() {}
	string GetBlockType() { return "NiParticleMeshModifier"; }
}; 

/**
 * NiParticleColorModifier
 */

class NiParticleColorModifier : public AControllable {
public:
	NiParticleColorModifier();
	void Init() {}
	~NiParticleColorModifier() {}
	string GetBlockType() { return "NiParticleColorModifier"; }
}; 

/**
 * NiGravity
 */

class NiParticleRotation : public AControllable {
public:
	NiParticleRotation();
	void Init() {}
	~NiParticleRotation() {}
	string GetBlockType() { return "NiParticleRotation"; }
}; 

/**
 * NiKeyframeData -
 */
class NiKeyframeData : public AData, public IKeyframeData {

	public:

		NiKeyframeData() {}
		~NiKeyframeData() {}

		void Read( ifstream& in, unsigned int version );
		void Write( ofstream& out, unsigned int version );
		string asString();
		string GetBlockType() { return "NiKeyframeData"; }
		
		void * QueryInterface( int id ) {
			if ( id == ID_KEYFRAME_DATA ) {
				return (void*)static_cast<IKeyframeData*>(this);;
			} else {
				return ABlock::QueryInterface( id );
			}
		}

		//--IKeyframeData Functions--//
		KeyType GetRotateType() { return rotationType; }
		void SetRotateType( KeyType t ) { rotationType = t; }
		vector< Key<Quaternion> > GetRotateKeys() { return rotKeys; }
		void SetRotateKeys( vector< Key<Quaternion> > & keys ) { rotKeys = keys; }
		//Translate
		KeyType GetTranslateType() { return translationType; }
		void SetTranslateType( KeyType t ) { translationType = t; }
		vector< Key<Vector3> > GetTranslateKeys() { return transKeys; }
		void SetTranslateKeys( vector< Key<Vector3> > & keys ) { transKeys = keys; }
		//Scale
		KeyType GetScaleType() { return scaleType; }
		void SetScaleType( KeyType t ) { scaleType = t; }
		vector< Key<float> > GetScaleKeys() { return scaleKeys; }
		void SetScaleKeys( vector< Key<float> > & keys ) { scaleKeys = keys; }

	private:
		KeyType rotationType;
		vector< Key<Quaternion> > rotKeys;

		KeyType translationType;
		vector< Key<Vector3> >	transKeys;

		KeyType scaleType;
		vector< Key<float> > scaleKeys;
};

/**
 * NiPalette
 */

class NiPalette : public AData {
public:
	NiPalette() {}
	void Init() {}
	~NiPalette() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();

	string GetBlockType() { return "NiPalette"; }
private:
	byte unknownBytes[5];
	byte palette[256][4];
};

/**
 * NiSkinPartition
 */

class NiSkinPartition : public AData {
public:
	NiSkinPartition();
	void Init() {}
	~NiSkinPartition() {}
	string GetBlockType() { return "NiSkinPartition"; }
};


/**
 * NiSkinInstance
 */

//Non-Public interface to allow NiSkinData to get the bone list read by NiSkinInstance
class ISkinInstInternal {
public:
	virtual vector<int> GetBoneList() = 0;
	virtual void ReadBoneList( ifstream& in ) = 0;
};

class NiSkinInstance : public AData, public ISkinInstInternal {
public:
	NiSkinInstance(){
		AddAttr( attr_link, "Data" );
		AddAttr( attr_skeletonroot, "Skeleton Root" );
		AddAttr( attr_bones, "Bones" );
	}
	~NiSkinInstance() {}
	string GetBlockType() { return "NiSkinInstance"; }

	void * QueryInterface( int id ) {
		if ( id == SkinInstInternal ) {
			return (void*)static_cast<ISkinInstInternal*>(this);;
		} else {
			return ABlock::QueryInterface( id );
		}
	}

	//ISkinInstInternal

	vector<int> GetBoneList() { return bones; }

	void ReadBoneList( ifstream& in ) {
		int len = ReadUInt( in );
		bones.resize( len );
		for (int i = 0; i < len; ++i ) {
			bones[i] = ReadUInt( in );
		}
	}
private:
	vector<int> bones;
};

class ISkinDataInternal {
public:
	virtual void SetBones( vector<blk_ref> bone_blocks ) = 0;
	virtual void RepositionTriShape() = 0;
	virtual void StraightenSkeleton() = 0;
	virtual void RemoveBoneByPtr( IBlock * bone ) = 0;
};

class NiSkinData : public AData, public ISkinData, public ISkinDataInternal {

	public:

		NiSkinData() { 
			SetIdentity33(rotation);
			translation[0] = 0.0f;
			translation[1] = 0.0f;
			translation[2] = 0.0f;
			scale = 1.0f;
			unknownInt = -1;
			unknownByte = 1;
		}
		~NiSkinData();

		void Read( ifstream& in, unsigned int version );
		void Write( ofstream& out, unsigned int version );
		string asString();
		string GetBlockType() { return "NiSkinData"; }
		void * QueryInterface( int id );

		//ISkinDataInternal
		void SetBones( vector<blk_ref> bone_blocks );
		void RepositionTriShape();
		void StraightenSkeleton();
		void RemoveBoneByPtr( IBlock * bone );

        //ISkinData
		vector<blk_ref> GetBones();
		map<int, float> GetWeights( blk_ref bone );
		void AddBone( blk_ref bone, map<int, float> in );
		void RemoveBone( blk_ref bone );
	private:
		struct Bone {
			Matrix33 rotation;
			fVector3 translation;
			float scale;
			fVector4 unknown4Floats;
			map<int, float> weights;
		};

		void CalculateBoneOffsets();
		Matrix33 rotation;
		fVector3 translation;
		float  scale;
		int unknownInt;
		byte unknownByte;
		map<IBlock*, Bone> bone_map;
		vector<Bone> bones;		
};

//-- New Nodes--//

class NiGeomMorpherController : public AController{
public:
	NiGeomMorpherController();
	void Init() {}
	~NiGeomMorpherController() {}

	string asString();
	string GetBlockType() { return "NiGeomMorpherController"; }
};

class NiColorData : public AData {
public:
	NiColorData() {}
	~NiColorData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiColorData"; };

private:
	uint keyType;
	vector< Key<fVector4> > keys;
};

/**
 * NiControllerSequence - Root node in .kf files (version 10.0.1.0 and up).
 */
class NiControllerSequence : public AData {
public:
	NiControllerSequence() {
		_namable = true;
	}
	~NiControllerSequence() {}

	string GetBlockType() { return "NiControllerSequence"; }
private:
	vector< pair< string, blk_ref> > controllers;
};

class NiFloatData : public AData {
public:
	NiFloatData() {}
	~NiFloatData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiFloatData"; };

private:
	uint keyType;
	vector<Key<float> > keys;
};

class NiStringExtraData : public AExtraData {
public:
	NiStringExtraData() {
		AddAttr( attr_string, "String Data" );
	}
	~NiStringExtraData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiStringExtraData"; }
};

class NiBooleanExtraData : public AExtraData {
public:
	NiBooleanExtraData() {
		AddAttr( attr_byte, "Boolean Data" );
	}
	~NiBooleanExtraData() {}

	string GetBlockType() { return "NiBooleanExtraData"; };
};

class NiIntegerExtraData : public AExtraData {
public:
	NiIntegerExtraData() {
		AddAttr( attr_int, "Integer Data" );
	}
	~NiIntegerExtraData() {}

	string GetBlockType() { return "NiIntegerExtraData"; };
};

class NiMorphData : public AData, public IMorphData {
public:
	NiMorphData() {
		AddAttr( attr_byte, "Unknown Byte" );
	}
	~NiMorphData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiMorphData"; };

	void * QueryInterface( int id ) {
		if ( id == ID_MORPH_DATA ) {
			return (void*)static_cast<IMorphData*>(this);;
		} else {
			return ABlock::QueryInterface( id );
		}
	}

	//--IMorphData Functions --//
	int GetVertexCount() { return vertCount; }
	void SetVertexCount( int n );
	int GetMorphCount() { return int(morphs.size()); }
	void SetMorphCount( int n ) { morphs.resize( n ); }
	vector< Key<float> > GetMorphKeys( int n ) { return morphs[n].keys; }
	void SetMorphKeys( int n, vector< Key<float> > & keys ) { morphs[n].keys = keys; }
	vector<Vector3> GetMorphVerts( int n) { return morphs[n].morph; }
	void SetMorphVerts( int n, const vector<Vector3> & in );

private:
	struct Morph {
		Morph() :  keyType(QUADRATIC_KEY) {}
		~Morph() {}
		KeyType keyType;
		vector< Key<float> > keys;
		vector< Vector3 > morph;
	};
	
	uint vertCount;
	vector<Morph> morphs;
};

class NiPosData : public AData {
public:
	NiPosData() {}
	~NiPosData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiPosData"; }

private:
	uint keyType;
	vector<Key<fVector3> > keys;
};

class NiRotatingParticlesData : public ARotatingParticlesData {
public:
	NiRotatingParticlesData() {}
	~NiRotatingParticlesData() {}

	string GetBlockType() { return "NiRotationparticlesData"; }
};

class NiTextKeyExtraData : public AExtraData, public ITextKeyExtraData {
public:
	NiTextKeyExtraData() {
		AddAttr( attr_int, "Unknown Int", 0, VER_4_2_2_0 );
	}
	~NiTextKeyExtraData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiTextKeyExtraData"; }

	void * QueryInterface( int id ) {
		if ( id == ID_TEXT_KEY_EXTRA_DATA ) {
			return (void*)static_cast<ITextKeyExtraData*>(this);;
		} else {
			return AExtraData::QueryInterface( id );
		}
	}

	//--ITextKeyExtraData Functions--//
	virtual vector< Key<string> > GetRotateKeys() { return _keys; }
	virtual void SetRotateKeys( vector< Key<string> > & keys ) { _keys = keys; }

private:
	vector< Key<string> > _keys;
};

class NiUVData : public AData {
public:
	NiUVData() {}
	~NiUVData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiUVData"; }

private:
	struct UVGroup {
		uint keyType;
		vector<Key<float> > keys;
	};
	UVGroup groups[4];
};

class NiVertWeightsExtraData : public AExtraData{
public:
	NiVertWeightsExtraData() {}
	~NiVertWeightsExtraData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiVertWeightsExtraData"; }

private:
	uint bytes;
	vector<float> weights;
};

class NiVisData : public AData {
public:
	NiVisData() {}
	~NiVisData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return "NiVisData"; }

private:
	vector<Key<byte> > keys;
};

class UnknownMixIn {
public:
	UnknownMixIn( string block_type ){
		data = NULL;
		_block_type = block_type;
	}
	~UnknownMixIn() { if (data != NULL) delete [] data; }
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version );
	string asString();
	string GetBlockType() { return _block_type; }

private:
	string _block_type;
	int len;
	byte * data;
};

class UnknownBlock : public ABlock, public UnknownMixIn {
public:
	UnknownBlock( string block_type ) : UnknownMixIn(block_type) {}
	~UnknownBlock() {}
	void Read( ifstream& in, unsigned int version ) {
		//cout << endl << "Unknown Block Type found:  " << GetBlockType() << "\a" << endl;
		ABlock::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ofstream& out, unsigned int version ) {
		ABlock::Write( out, version );
		UnknownMixIn::Write( out, version );
	}
	void asString( ostream & out ) {
		out << ABlock::asString();
		out << UnknownMixIn::asString();
	}
	string GetBlockType() { return UnknownMixIn::GetBlockType(); }
};

class UnknownControllerBlock : public AController, public UnknownMixIn {
public:
	UnknownControllerBlock( string block_type ) : UnknownMixIn(block_type) {}
	~UnknownControllerBlock() {}
	void Read( ifstream& in, unsigned int version ) {
		ABlock::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ofstream& out, unsigned int version ) {
		ABlock::Write( out, version );
		UnknownMixIn::Write( out, version );
	}
	string asString() {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << ABlock::asString();
		out << UnknownMixIn::asString();

		return out.str();
	}
	string GetBlockType() { return UnknownMixIn::GetBlockType(); }
};

class UnknownPropertyBlock : public AProperty, public UnknownMixIn {
public:
	UnknownPropertyBlock( string block_type ) : UnknownMixIn(block_type) {}
	~UnknownPropertyBlock() {}
	void Read( ifstream& in, unsigned int version ) {
		ABlock::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ofstream& out, unsigned int version ) {
		ABlock::Write( out, version );
		UnknownMixIn::Write( out, version );
	}
	string asString() {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << ABlock::asString();
		out << UnknownMixIn::asString();

		return out.str();
	}
	string GetBlockType() { return UnknownMixIn::GetBlockType(); }
};

/**
 * NiParticleSystemController
 */
class NiParticleSystemController : public AParticleSystemController {
public:
	NiParticleSystemController();
	void Init() {}
	~NiParticleSystemController() {}
	string GetBlockType() { return "NiParticleSystemController"; }
};

/**
 * NiBSPArrayController
 */
class NiBSPArrayController : public AParticleSystemController {
public:
	NiBSPArrayController();
	void Init() {}
	~NiBSPArrayController() {}
	string GetBlockType() { return "NiBSPArrayController"; }
};

#endif
