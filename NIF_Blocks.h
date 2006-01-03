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
const int ChainLinkInternal = -5;


//void GetBuiltUpTransform(blk_ref block, Matrix & m/*, blk_ref stop*/);

class IBlockInternal {
public:
	IBlockInternal() {}
	virtual ~IBlockInternal() {}

	//Cross Reference
	virtual void AddParent( blk_ref parent ) = 0;
	virtual void RemoveParent( IBlock * match ) = 0;
	virtual void SetBlockNum( int ) = 0;
	virtual void FixUpLinks( const vector<blk_ref> & blocks ) = 0;

	//File I/O
	virtual void Read( ifstream& in, unsigned int version ) = 0;
	virtual void Write( ofstream& out, unsigned int version ) const = 0;	
};

class ABlock : public IBlock, public IBlockInternal {
public:
	ABlock();
	~ABlock();
	void AddAttr( AttrType type, string const & name, unsigned int first_ver = 0, unsigned int last_ver = 0xFFFFFFFF );
	attr_ref GetAttr(string const & attr_name) const;
	vector<attr_ref> GetAttrs() const;
	int GetBlockNum() const { return _block_num; }
	bool IsControllable() const { return false; }
	bool IsController() const { return false; }
	string asString() const;

	//Links
	blk_ref GetParent() const;
	list<blk_ref> GetLinks() const;

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

	void const * QueryInterface( int id ) const {
		if ( id == BlockInternal ) {
			return (void const *)static_cast<IBlockInternal const *>(this);;
		} else {
			return NULL;
		}
	}

	//--Internal Functions--//
	void AddParent( blk_ref parent);
	void RemoveParent( IBlock * match );
	void SetBlockNum( int n ) { _block_num = n; }
	void FixUpLinks( const vector<blk_ref> & blocks );

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
protected:
	map<string, attr_ref> _attr_map;
	vector<attr_ref> _attr_vect;
	int _block_num;
	unsigned int _ref_count;
	vector<IBlock*> _parents;
};

class AControllable : public ABlock {
public:
	AControllable();
	void Init() {}
	bool IsControllable() const { return true; }
	~AControllable() {}
};

class INodeInternal {
public:
	virtual void IncSkinRef( IBlock * skin_data ) = 0;
	virtual void DecSkinRef( IBlock * skin_data ) = 0;
};

class ANode : public AControllable, public INode, public INodeInternal {
public:
	ANode();
	void Init() { 
		//Start the bind pose at an identity matrix
		SetIdentity44(bindPosition);

		//Start the flags at "Not a skin influence"
		GetAttr("Flags")->Set(8);
	
	};
	~ANode();
	void InitAttrs();
	void * QueryInterface( int id );
	void const * QueryInterface( int id ) const;
	void Read( ifstream& in, unsigned int version ) {
		ABlock::Read( in, version );
		Matrix44 transform;
		transform = GetLocalTransform();
		SetWorldBindPos( transform );
	}

	//INode Functions
	Matrix44 GetLocalTransform() const;
	Matrix44 GetWorldTransform() const;
	Matrix44 GetWorldBindPos() const;
	Matrix44 GetLocalBindPos() const;
	void SetWorldBindPos( Matrix44 const & m );

	//INodeInternal Functions
	void IncSkinRef( IBlock * skin_data );
	void DecSkinRef( IBlock * skin_data );

protected:
	Matrix44 bindPosition;
	list<IBlock*> skin_refs;
};

/**
 * AParentNode
 */
class AParentNode : public ANode {
public:
	AParentNode();
	void Init() {}
	~AParentNode() {}
};

/**
 * AFx
 */
class AFx : public AParentNode {
public:

	AFx();
	void Init() {}
	~AFx() {}
};

class AParticleNode : public ANode {
public:
	AParticleNode();
	void Init() {}
	~AParticleNode() {}
};

class AShape : public ANode {
public:
	AShape();
	void Init() {}
	~AShape() {}
};

class AProperty : public AControllable {
public:
	AProperty();
	void Init() {}
	~AProperty() {}
};

class AController : public ABlock {
public:
	AController();
	void Init() {}
	bool IsController() { return true; }
	~AController() {}
};

class AData : public ABlock {
public:
	AData() {}
	void Init() {}
	~AData() {}
};

class AInterpolator : public ABlock {
public:
	AInterpolator();
	void Init() {}
	~AInterpolator() {}
};

class AParticleModifier : public ABlock {
public:
	AParticleModifier();
	void Init() {}
	~AParticleModifier() {}
};

class APSysModifier : public ABlock {
public:
	APSysModifier();
	void Init() {}
	~APSysModifier() {}
};

class AExtraData : public AData {
public:
	AExtraData() {
		AddAttr( attr_string, "Name", VER_10_0_1_0 );
		AddAttr( attr_link, "Next Extra Data", 0, VER_4_2_2_0 );
	}
	~AExtraData() {};
	void Read( ifstream& in, unsigned int version ) {
		GetAttr("Name")->Read( in, version );
		GetAttr("Next Extra Data")->Read( in, version );
	}
	void Write( ofstream& out, unsigned int version ) const {
		GetAttr("Name")->Write( out, version );
		GetAttr("Next Extra Data")->Write( out, version );
	}
	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << "Name:  " << GetAttr("Name")->asString() << endl
			<< "Next Extra Data:  " << GetAttr("Next Extra Data")->asString() << endl;

		return out.str();
	}
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
 * FxButton
 */
class FxButton : public AFx {
public:

	FxButton();
	void Init() {}
	~FxButton() {}

	string GetBlockType() const { return "FxButton"; }
};

/**
 * FxRadioButton
 */
class FxRadioButton : public AFx {
public:

	FxRadioButton();
	void Init() {}
	~FxRadioButton() {}

	string GetBlockType() const { return "FxRadioButton"; }
};

/**
 * FxWidget
 */
class FxWidget : public AFx {
public:

	FxWidget();
	void Init() {}
	~FxWidget() {}

	string GetBlockType() const { return "FxWidget"; }
};

/**
 * NiNode - Root of each model component.
 */
class NiNode : public AParentNode {
public:

	NiNode();
	void Init() {}
	~NiNode() {}
	string GetBlockType() const { return "NiNode"; }
	string asString() const;
};

/**
 * RootCollisionNode
 */
class RootCollisionNode : public AParentNode {
public:

	RootCollisionNode();
	void Init() {}
	~RootCollisionNode() {}

	string GetBlockType() const { return "RootCollisionNode"; }
};

/**
 * AvoidNode
 */
class AvoidNode : public AParentNode {
public:

	AvoidNode();
	void Init() {}
	~AvoidNode() {}

	string GetBlockType() const { return "AvoidNode"; }
};

/**
 * NiBillboardNode
 */
class NiBillboardNode : public AParentNode {
public:
	NiBillboardNode();
	void Init() {}
	~NiBillboardNode() {}

	string GetBlockType() const { return "NiBillboardNode"; }
};

/**
 * NiBSAnimationNode
 */
class NiBSAnimationNode : public AParentNode {
public:
	NiBSAnimationNode();
	void Init() {}
	~NiBSAnimationNode() {}

	string GetBlockType() const { return "NiBSAnimationNode"; }
};

/**
 * NiBSParticleNode
 */
class NiBSParticleNode : public AParentNode {
public:
	NiBSParticleNode();
	void Init() {}
	~NiBSParticleNode() {}

	string GetBlockType() const { return "NiBSParticleNode"; }
};

/**
 * NiLODNode
 */
class NiLODNode : public AParentNode {
public:
	NiLODNode();
	void Init() {}
	~NiLODNode() {}

	string GetBlockType() const { return "NiLODNode"; }
};

/**
 * ZBuffer data.
 */
class NiZBufferProperty : public AProperty {
public:
	NiZBufferProperty();
	void Init() {}
	~NiZBufferProperty() {}

	string GetBlockType() const { return "NiZBufferProperty"; }
};

/**
 * NiShadeProperty
 */
class NiShadeProperty : public AProperty {
public:

	NiShadeProperty();
	void Init() {}
	~NiShadeProperty() {}

	string GetBlockType() const { return "NiShadeProperty"; }
};

/**
 * ZBuffer data.NiWireframeProperty
 */
class NiWireframeProperty : public AProperty {
public:

	NiWireframeProperty();
	void Init() {}
	~NiWireframeProperty() {}

	string GetBlockType() const { return "NiWireframeProperty"; }
};

/**
 * NiDitherProperty
 */
class NiDitherProperty : public AProperty {
public:

	NiDitherProperty();
	void Init() {}
	~NiDitherProperty() {}

	string GetBlockType() const { return "NiDitherProperty"; }
};

/**
 * NiSequenceStreamHelper 
 */
class NiSequenceStreamHelper  : public AControllable {
public:

	NiSequenceStreamHelper ();
	void Init() {}
	~NiSequenceStreamHelper () {}

	string GetBlockType() const { return "NiSequenceStreamHelper"; }
};

/**
 * NiVertexColorProperty - Vertex colour data.
 */
class NiVertexColorProperty : public AProperty{
public:

	NiVertexColorProperty();
	void Init() {}
	~NiVertexColorProperty() {}

	string GetBlockType() const { return "NiVertexColorProperty"; }
};



/**
 * NiTriShape - 
 */
class NiTriShape : public AShape {
public:
	NiTriShape();
	void Init() {}
	~NiTriShape() {}

	string GetBlockType() const { return "NiTriShape"; }
};

/**
 * NiTriStrips - 
 */
class NiTriStrips : public AShape {
public:
	NiTriStrips();
	void Init() {}
	~NiTriStrips() {}

	string GetBlockType() const { return "NiTriStrips"; }
};

/**
 * NiTexturingProperty -
 */
class NiTexturingProperty : public AProperty {
public:
	NiTexturingProperty( );
	void Init() {}
	~NiTexturingProperty() {}
	string GetBlockType() const { return "NiTexturingProperty"; }
};

/**
 * NiSourceTexture - Data for the associated texture, included in nif or external.
 */
class NiSourceTexture : public AControllable{
public:
	NiSourceTexture();
	void Init() {}
	~NiSourceTexture() {}
	string GetBlockType() const { return "NiSourceTexture"; }
};



/**
 * NiPixelData - Texture data for an included texture.
 */
class NiPixelData : public AData {
public:
	NiPixelData() {
		data = NULL;
		AddAttr( attr_int, "Unknown Int" );
		AddAttr( attr_int, "Red Mask" );
		AddAttr( attr_int, "Blue Mask" );
		AddAttr( attr_int, "Green Mask" );
		AddAttr( attr_int, "Alpha Mask" );
		AddAttr( attr_int, "Bits Per Pixel" );
		AddAttr( attr_byte, "Unknown Byte 1" );
		AddAttr( attr_byte, "Unknown Byte 2" );
		AddAttr( attr_byte, "Unknown Byte 3" );
		AddAttr( attr_byte, "Unknown Byte 4" );
		AddAttr( attr_byte, "Unknown Byte 5" );
		AddAttr( attr_byte, "Unknown Byte 6" );
		AddAttr( attr_byte, "Unknown Byte 7" );
		AddAttr( attr_byte, "Unknown Byte 8" );
		AddAttr( attr_link, "Unknown Link" );
		AddAttr( attr_link, "Palette", VER_10_1_0_0);
	}
	~NiPixelData() { if (data != NULL) delete [] data; }

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiPixelData"; }

private:
	struct MipMap {
		uint width, height, offset;
	};
	
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
	string GetBlockType() const { return "NiMaterialProperty"; };
};

/**
 * NiSpecularProperty -
 */
class NiSpecularProperty : public AProperty {
public:
	NiSpecularProperty();
	void Init() {}
	~NiSpecularProperty() {}
	string GetBlockType() const { return "NiSpecularProperty"; };
};

/**
 * NiStencilProperty -
 */
class NiStencilProperty : public AProperty {
public:
	NiStencilProperty();
	void Init() {}
	~NiStencilProperty() {}
	string GetBlockType() const { return "NiStencilProperty"; };
};

/**
 * NiAlphaProperty - Does the mesh have alpha-blending enabled?
 */
class NiAlphaProperty : public AProperty {
public:
	NiAlphaProperty();
	void Init() {}
	~NiAlphaProperty() {}
	string GetBlockType() const { return "NiAlphaProperty"; }
};

/**
 * AShapeData - Mesh data: vertices, vertex normals, etc.
 */
class AShapeData : public AData, public IShapeData {
public:
	AShapeData() {
		AddAttr( attr_string, "Name", VER_10_2_0_0 );
		AddAttr( attr_float3, "Center" );
		AddAttr( attr_float, "Radius" );
		AddAttr( attr_link, "Unknown Link", VER_20_0_0_4 );
	}
	~AShapeData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;

	void * QueryInterface( int id );
	void const * QueryInterface( int id ) const;

	//--IShapeData--//
	//Counts
	short GetVertexCount() const { return short(vertices.size()); }
	short GetUVSetCount() const { return short(uv_sets.size()); }
	void SetVertexCount(int n);
	void SetUVSetCount(int n);
	//Getters
	vector<Vector3> GetVertices() const { return vertices; }
	vector<Vector3> GetNormals() const { return normals; }
	vector<Color4> GetColors() const { return colors; }
	vector<TexCoord> GetUVSet( int index ) const { return uv_sets[index]; }
	//Setters
	void SetVertices( const vector<Vector3> & in );
	void SetNormals( const vector<Vector3> & in );
	void SetColors( const vector<Color4> & in );
	void SetUVSet( int index, const vector<TexCoord> & in );
protected:
	vector<Vector3> vertices;
	vector<Vector3> normals;
	vector<Color4> colors;
	vector< vector<TexCoord> > uv_sets;
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
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
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
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
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
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiParticleMeshesData"; }
protected:
	
};

/**
 * NiAutoNormalParticlesData - Particle system data block (emits particles along vertex normals?).
 */

class NiAutoNormalParticlesData : public AParticlesData {
public:
	NiAutoNormalParticlesData() {}
	~NiAutoNormalParticlesData() {}
	string GetBlockType() const { return "NiAutoNormalParticlesData"; }
};

/**
 * NiTriShapeData - Holds mesh data using a list of singular triangles.
 */
class NiTriShapeData : public AShapeData, public ITriShapeData {
public:
	NiTriShapeData() : match_group_mode(false) {}
	~NiTriShapeData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiTriShapeData"; }
	void * QueryInterface( int id );
	void const * QueryInterface( int id ) const;

	//--ITriShapeData--//
	//Counts
	short GetTriangleCount() const { return short(triangles.size()); }
	void SetTriangleCount(int n);
	//Match Detection
	void SetMatchDetectionMode(bool choice) { match_group_mode = choice; }
	bool GetMatchDetectionMode() const { return match_group_mode; }
	//Getters
	vector<Triangle> GetTriangles() const { return triangles; }
	//Setters
	void SetTriangles( const vector<Triangle> & in );

private:
	vector<Triangle> triangles;
	bool match_group_mode;
};

/**
 * NiTriStripsData - Holds mesh data using strips of triangles.
 */
class NiTriStripsData : public AShapeData, public ITriStripsData {
public:
	NiTriStripsData() {}
	~NiTriStripsData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiTriStripsData"; }

	void * QueryInterface( int id );
	void const * QueryInterface( int id ) const;

	//--ITriStripsData--//
	//Counts
	short GetStripCount() const;
	void SetStripCount(int n);
	short GetTriangleCount() const;
	//Getters
	vector<short> GetStrip( int index ) const;
	vector<Triangle> GetTriangles() const;
	//Setter
	void SetStrip( int index, const vector<short> & in );

private:
	vector< vector<short> > strips;
};

/**
 * NiCollisionData - Collision box.
 */
class NiCollisionData : public AData {
public:
	NiCollisionData() {}
	~NiCollisionData() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiCollisionData"; }
private:
	int unknownInt1, collisionType, unknownInt2;
	byte unknownByte;
	fVector3 unknown3Floats;
	float unknown15Floats[15];
	float unknown8Floats[8]; 
};



/**
 * NiKeyframeController
 */
class NiKeyframeController : public AController {
public:
	NiKeyframeController();
	void Init() {}
	~NiKeyframeController() {}
	string GetBlockType() const { return "NiKeyframeController"; }
};

/**
 * NiLightColorController
 */
class NiLightColorController : public AController {
public:
	NiLightColorController();
	void Init() {}
	~NiLightColorController() {}
	string GetBlockType() const { return "NiLightColorController"; }
};

/**
 * NiKeyframeController
 */
class NiLookAtController : public AController {
public:
	NiLookAtController();
	void Init() {}
	~NiLookAtController() {}
	string GetBlockType() const { return "NiLookAtController"; }
};

/**
 * NiAlphaController
 */
class NiAlphaController : public AController {
public:
	NiAlphaController();
	void Init() {}
	~NiAlphaController() {}
	string GetBlockType() const { return "NiAlphaController"; }
};

/**
 * NiFlipController
 */
class NiFlipController : public AController {
public:
	NiFlipController();
	void Init() {}
	~NiFlipController() {}
	string GetBlockType() const { return "NiFlipController"; }
};

/**
 * NiVisController
 */
class NiVisController : public AController {
public:
	NiVisController();
	void Init() {}
	~NiVisController() {}
	string GetBlockType() const { return "NiVisController"; }
};

/**
 * NiMaterialColorController
 */
class NiMaterialColorController : public AController {
public:
	NiMaterialColorController();
	void Init() {}
	~NiMaterialColorController() {}
	string GetBlockType() const { return "NiMaterialColorController"; }
};

/**
 * NiPSysEmitterCtlr
 */
class NiPSysEmitterCtlr : public AController {
public:
	NiPSysEmitterCtlr();
	void Init() {}
	~NiPSysEmitterCtlr() {}
	string GetBlockType() const { return "NiPSysEmitterCtlr"; }
};

/**
 * NiPSysResetOnLoopCtlr
 */
class NiPSysResetOnLoopCtlr : public AController {
public:
	NiPSysResetOnLoopCtlr();
	void Init() {}
	~NiPSysResetOnLoopCtlr() {}
	string GetBlockType() const { return "NiPSysResetOnLoopCtlr"; }
};

/**
 * NiPSysUpdateCtlr
 */
class NiPSysUpdateCtlr : public AController {
public:
	NiPSysUpdateCtlr();
	void Init() {}
	~NiPSysUpdateCtlr() {}
	string GetBlockType() const { return "NiPSysUpdateCtlr"; }
};

/**
 * NiTextureTransformController
 */
class NiTextureTransformController : public AController {
public:
	NiTextureTransformController();
	void Init() {}
	~NiTextureTransformController() {}
	string GetBlockType() const { return "NiTextureTransformController"; }
};

/**
 * NiTransformController
 */
class NiTransformController : public AController {
public:
	NiTransformController();
	void Init() {}
	~NiTransformController() {}
	string GetBlockType() const { return "NiTransformController"; }
};

/**
 * NiUVController 
 */
class NiUVController : public AController {
public:
	NiUVController();
	void Init() {}
	~NiUVController() {}
	string GetBlockType() const { return "NiUVController"; }
};

/**
 * NiPathController
 */

class NiPathController : public AController {
public:
	NiPathController();
	void Init() {}
	~NiPathController() {}
	string GetBlockType() const { return "NiPathController"; }
};

/**
 * NiAmbientLight - Not found in any official NIF files
 */

class NiAmbientLight : public ALight {
public:
	NiAmbientLight();
	void Init() {}
	~NiAmbientLight() {}
	string GetBlockType() const { return "NiAmbientLight"; }
};

/**
 * NiDirectionalLight - Not found in any official NIF files
 */

class NiDirectionalLight : public ALight {
public:
	NiDirectionalLight();
	void Init() {}
	~NiDirectionalLight() {}
	string GetBlockType() const { return "NiDirectionalLight"; }
};

/**
 * NiPointLight
 */

class NiPointLight : public ALight {
public:
	NiPointLight();
	void Init() {}
	~NiPointLight() {}
	string GetBlockType() const { return "NiPointLight"; }
};

/**
 * NiParticles
 */

class NiParticles : public AParticleNode {
public:
	NiParticles();
	void Init() {}
	~NiParticles() {}
	string GetBlockType() const { return "NiParticles"; }
};

/**
 * NiParticleSystem
 */

class NiParticleSystem : public AParticleNode {
public:
	NiParticleSystem();
	void Init() {}
	~NiParticleSystem() {}
	string GetBlockType() const { return "NiParticleSystem"; }
};

/**
 * NiAutoNormalParticles
 */

class NiAutoNormalParticles : public AParticleNode {
public:
	NiAutoNormalParticles();
	void Init() {}
	~NiAutoNormalParticles() {}
	string GetBlockType() const { return "NiAutoNormalParticles"; }
};

/**
 * NiMeshParticleSystem
 */

class NiMeshParticleSystem : public AParticleNode {
public:
	NiMeshParticleSystem();
	void Init() {}
	~NiMeshParticleSystem() {}
	string GetBlockType() const { return "NiMeshParticleSystem"; }
};

/**
 * NiRotatingParticles
 */

class NiRotatingParticles : public AParticleNode {
public:
	NiRotatingParticles();
	void Init() {}
	~NiRotatingParticles() {}
	string GetBlockType() const { return "NiRotatingParticles"; }
}; 

/**
 * NiTextureEffect
 */

class NiTextureEffect : public ANode {
public:
	NiTextureEffect();
	void Init() {}
	~NiTextureEffect() {}
	string GetBlockType() const { return "NiTextureEffect"; }
}; 

/**
 * NiCamera
 */

class NiCamera : public ANode {
public:
	NiCamera();
	void Init() {}
	~NiCamera() {}
	string GetBlockType() const { return "NiCamera"; }
}; 

/**
 * NiParticleMeshes
 */

class NiParticleMeshes : public AParticleNode {
public:
	NiParticleMeshes();
	void Init() {}
	~NiParticleMeshes() {}
	string GetBlockType() const { return "NiParticleMeshes"; }
}; 

/**
 * NiGravity
 */

class NiGravity : public AParticleModifier {
public:
	NiGravity();
	void Init() {}
	~NiGravity() {}
	string GetBlockType() const { return "NiGravity"; }
}; 

/**
 * NiParticleBomb
 */

class NiParticleBomb : public AParticleModifier {
public:
	NiParticleBomb();
	void Init() {}
	~NiParticleBomb() {}
	string GetBlockType() const { return "NiParticleBomb"; }
}; 

/**
 * NiPlanarCollider
 */

class NiPlanarCollider : public AParticleModifier {
public:
	NiPlanarCollider();
	void Init() {}
	~NiPlanarCollider() {}
	string GetBlockType() const { return "NiPlanarCollider"; }
}; 

/**
 * NiSphericalCollider
 */

class NiSphericalCollider : public AParticleModifier {
public:
	NiSphericalCollider();
	void Init() {}
	~NiSphericalCollider() {}
	string GetBlockType() const { return "NiSphericalCollider"; }
}; 

/**
 * NiParticleGrowFade
 */

class NiParticleGrowFade : public AParticleModifier {
public:
	NiParticleGrowFade();
	void Init() {}
	~NiParticleGrowFade() {}
	string GetBlockType() const { return "NiParticleGrowFade"; }
}; 

/**
 * NiParticleMeshModifier
 */

class NiParticleMeshModifier : public AParticleModifier {
public:
	NiParticleMeshModifier();
	void Init() {}
	~NiParticleMeshModifier() {}
	string GetBlockType() const { return "NiParticleMeshModifier"; }
}; 

/**
 * NiParticleColorModifier
 */

class NiParticleColorModifier : public AParticleModifier {
public:
	NiParticleColorModifier();
	void Init() {}
	~NiParticleColorModifier() {}
	string GetBlockType() const { return "NiParticleColorModifier"; }
}; 

/**
 * NiGravity
 */

class NiParticleRotation : public AParticleModifier {
public:
	NiParticleRotation();
	void Init() {}
	~NiParticleRotation() {}
	string GetBlockType() const { return "NiParticleRotation"; }
}; 

/**
 * NiPSysPlanarCollider
 */

class NiPSysPlanarCollider : public ABlock {
public:
	NiPSysPlanarCollider();
	void Init() {}
	~NiPSysPlanarCollider() {}
	string GetBlockType() const { return "NiPSysPlanarCollider"; }
};

/**
 * NiPSysAgeDeathModifier
 */

class NiPSysAgeDeathModifier : public APSysModifier {
public:
	NiPSysAgeDeathModifier();
	void Init() {}
	~NiPSysAgeDeathModifier() {}
	string GetBlockType() const { return "NiPSysAgeDeathModifier"; }
}; 

/**
 * NiPSysBoundUpdateModifier
 */

class NiPSysBoundUpdateModifier : public APSysModifier {
public:
	NiPSysBoundUpdateModifier();
	void Init() {}
	~NiPSysBoundUpdateModifier() {}
	string GetBlockType() const { return "NiPSysBoundUpdateModifier"; }
}; 

/**
 * NiPSysBoxEmitter
 */

class NiPSysBoxEmitter : public APSysModifier {
public:
	NiPSysBoxEmitter();
	void Init() {}
	~NiPSysBoxEmitter() {}
	string GetBlockType() const { return "NiPSysBoxEmitter"; }
}; 

/**
 * NiPSysColliderManager
 */

class NiPSysColliderManager : public APSysModifier {
public:
	NiPSysColliderManager();
	void Init() {}
	~NiPSysColliderManager() {}
	string GetBlockType() const { return "NiPSysColliderManager"; }
}; 

/**
 * NiPSysColorModifier
 */

class NiPSysColorModifier : public APSysModifier {
public:
	NiPSysColorModifier();
	void Init() {}
	~NiPSysColorModifier() {}
	string GetBlockType() const { return "NiPSysColorModifier"; }
}; 

/**
 * NiPSysCylinderEmitter
 */

class NiPSysCylinderEmitter : public APSysModifier {
public:
	NiPSysCylinderEmitter();
	void Init() {}
	~NiPSysCylinderEmitter() {}
	string GetBlockType() const { return "NiPSysCylinderEmitter"; }
}; 

/**
 * NiPSysGravityModifier
 */

class NiPSysGravityModifier : public APSysModifier {
public:
	NiPSysGravityModifier();
	void Init() {}
	~NiPSysGravityModifier() {}
	string GetBlockType() const { return "NiPSysGravityModifier"; }
}; 

/**
 * NiPSysGrowFadeModifier
 */

class NiPSysGrowFadeModifier : public APSysModifier {
public:
	NiPSysGrowFadeModifier();
	void Init() {}
	~NiPSysGrowFadeModifier() {}
	string GetBlockType() const { return "NiPSysGrowFadeModifier"; }
}; 

/**
 * NiPSysMeshUpdateModifier
 */

class NiPSysMeshUpdateModifier : public APSysModifier {
public:
	NiPSysMeshUpdateModifier();
	void Init() {}
	~NiPSysMeshUpdateModifier() {}
	string GetBlockType() const { return "NiPSysMeshUpdateModifier"; }
}; 

/**
 * NiPSysPositionModifier
 */

class NiPSysPositionModifier : public APSysModifier {
public:
	NiPSysPositionModifier();
	void Init() {}
	~NiPSysPositionModifier() {}
	string GetBlockType() const { return "NiPSysPositionModifier"; }
}; 

/**
 * NiPSysRotationModifier
 */

class NiPSysRotationModifier : public APSysModifier {
public:
	NiPSysRotationModifier();
	void Init() {}
	~NiPSysRotationModifier() {}
	string GetBlockType() const { return "NiPSysRotationModifier"; }
}; 

/**
 * NiPSysSpawnModifier
 */

class NiPSysSpawnModifier : public APSysModifier {
public:
	NiPSysSpawnModifier();
	void Init() {}
	~NiPSysSpawnModifier() {}
	string GetBlockType() const { return "NiPSysSpawnModifier"; }
}; 

/**
 * NiKeyframeData -
 */

class NiKeyframeData : public AData, public IKeyframeData {

	public:

		NiKeyframeData() {}
		~NiKeyframeData() {}

		void Read( ifstream& in, unsigned int version );
		void Write( ofstream& out, unsigned int version ) const;
		string asString() const;
		string GetBlockType() const { return "NiKeyframeData"; }
		
		void * QueryInterface( int id ) {
			if ( id == ID_KEYFRAME_DATA ) {
				return (void*)static_cast<IKeyframeData*>(this);;
			} else {
				return ABlock::QueryInterface( id );
			}
		}
		void const * QueryInterface( int id ) const {
			if ( id == ID_KEYFRAME_DATA ) {
				return (void const *)static_cast<IKeyframeData const *>(this);;
			} else {
				return ABlock::QueryInterface( id );
			}
		}

		//--IKeyframeData Functions--//
		KeyType GetRotateType() const { return rotationType; }
		void SetRotateType( KeyType t ) { rotationType = t; }
		vector< Key<Quaternion> > GetRotateKeys() const { return rotKeys; }
		void SetRotateKeys( vector< Key<Quaternion> > const & keys ) { rotKeys = keys; }
		//Translate
		KeyType GetTranslateType() const { return translationType; }
		void SetTranslateType( KeyType t ) { translationType = t; }
		vector< Key<Vector3> > GetTranslateKeys() const { return transKeys; }
		void SetTranslateKeys( vector< Key<Vector3> > const & keys ) { transKeys = keys; }
		//Scale
		KeyType GetScaleType() const { return scaleType; }
		void SetScaleType( KeyType t ) { scaleType = t; }
		vector< Key<float> > GetScaleKeys() const { return scaleKeys; }
		void SetScaleKeys( vector< Key<float> > const & keys ) { scaleKeys = keys; }

	private:
		KeyType rotationType;
		vector< Key<Quaternion> > rotKeys;

		KeyType translationType;
		vector< Key<Vector3> >	transKeys;

		KeyType scaleType;
		vector< Key<float> > scaleKeys;

		KeyType xyzTypes[3];
		vector< Key<float> > xyzKeys[3];
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
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiPalette"; }
private:
	byte unknownBytes[5];
	byte palette[256][4];
};

/**
 * NiSkinPartition
 */

class NiSkinPartition : public AData {
public:
	NiSkinPartition() {}
	void Init() {}
	~NiSkinPartition() {}
	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiSkinPartition"; }
private:
	struct SkinPartition {
		vector<ushort> bones;
		vector<ushort> vertexMap;
		vector< vector<float> > vertexWeights;
		vector< vector<ushort> > strips;
		vector<Triangle> triangles;
		vector< vector<byte> > boneIndices;
	};
	vector<SkinPartition> partitions;
};


/**
 * NiSkinInstance
 */

//Non-Public interface to allow NiSkinData to get the bone list read by NiSkinInstance
class ISkinInstInternal {
public:
	virtual vector<int> GetBoneList() const = 0;
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
	string GetBlockType() const { return "NiSkinInstance"; }

	void * QueryInterface( int id ) {
		if ( id == SkinInstInternal ) {
			return (void*)static_cast<ISkinInstInternal*>(this);;
		} else {
			return ABlock::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == SkinInstInternal ) {
			return (void const *)static_cast<ISkinInstInternal const *>(this);;
		} else {
			return ABlock::QueryInterface( id );
		}
	}

	//ISkinInstInternal

	vector<int> GetBoneList() const { return bones; }

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
			AddAttr( attr_link, "Skin Partition" );
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
		void Write( ofstream& out, unsigned int version ) const;
		string asString() const;
		string GetBlockType() const { return "NiSkinData"; }
		void * QueryInterface( int id );
		void const * QueryInterface( int id ) const;

		//ISkinDataInternal
		void SetBones( vector<blk_ref> bone_blocks ); // not vector<blk_ref> const &, since we must cast the blk_ref's into (non-constant) IBlock * pointers
		void RepositionTriShape();
		void StraightenSkeleton();
		void RemoveBoneByPtr( IBlock * bone );

        //ISkinData
		vector<blk_ref> GetBones(); // cannot be const, since this changes the reference counts for the bone blocks!
		map<int, float> GetWeights( blk_ref const & bone ) const;
		void AddBone( blk_ref const & bone, map<int, float> const & in );
		void RemoveBone( blk_ref const & bone );
	private:
		struct Bone {
			Matrix33 rotation;
			fVector3 translation;
			float scale;
			fVector4 unknown4Floats;
			map<int, float> weights;
		};

		INode * GetNodeParent() const;
		void CalculateOverallOffset( Matrix33 & rot, fVector3 & tr, float & sc ) const;
		void CalculateBoneOffset( INode const * const par_node, IBlock const * const bone_block, Bone & result ) const;
		Matrix33 rotation;
		fVector3 translation;
		float  scale;
		int unknownInt;
		byte unknownByte;
		map<IBlock *, Bone > bone_map;
		vector<Bone> bones;
};

//-- New Nodes--//

class NiGeomMorpherController : public AController{
public:
	NiGeomMorpherController();
	void Init() {}
	~NiGeomMorpherController() {}

	string asString() const;
	string GetBlockType() const { return "NiGeomMorpherController"; }
};

class NiColorData : public AData, public IColorData {
public:
	NiColorData() {}
	~NiColorData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiColorData"; };

	void * QueryInterface( int id ) {
		if ( id == ID_COLOR_DATA ) {
			return (void*)static_cast<IColorData*>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_COLOR_DATA ) {
			return (void const *)static_cast<IColorData const *>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}

	//--IColorData Functions--//
	KeyType GetKeyType() const { return _type; }
	void SetKeyType( KeyType t ) { _type = t; }
	vector< Key<Color4> > GetKeys() const { return _keys; }
	void SetKeys( vector< Key<Color4> > const & keys ) { _keys = keys; }

private:
	KeyType _type;
	vector<Key<Color4> > _keys;
};

/**
 * NiControllerSequence - Root node in .kf files (version 10.0.1.0 and up).
 */
class NiControllerSequence : public AData {
public:
	NiControllerSequence() {
		AddAttr( attr_string, "Name" );
	}
	~NiControllerSequence() {}

	string GetBlockType() const { return "NiControllerSequence"; }
private:
	vector< pair< string, blk_ref> > controllers;
};

class NiFloatData : public AData, public IFloatData {
public:
	NiFloatData() {}
	~NiFloatData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiFloatData"; };

	void * QueryInterface( int id ) {
		if ( id == ID_FLOAT_DATA ) {
			return (void*)static_cast<IFloatData*>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_FLOAT_DATA ) {
			return (void const *)static_cast<IFloatData const *>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}

	//--IFloatData Functions--//
	KeyType GetKeyType() const { return _type; }
	void SetKeyType( KeyType t ) { _type = t; }
	vector< Key<float> > GetKeys() const { return _keys; }
	void SetKeys( vector< Key<float> > const & keys ) { _keys = keys; }

private:
	KeyType _type;
	vector<Key<float> > _keys;
};

class NiStringExtraData : public AExtraData {
public:
	NiStringExtraData() {
		AddAttr( attr_string, "String Data" );
	}
	~NiStringExtraData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiStringExtraData"; }
};

class NiBooleanExtraData : public AExtraData {
public:
	NiBooleanExtraData() {
		AddAttr( attr_byte, "Boolean Data" );
	}
	~NiBooleanExtraData() {}
	string GetBlockType() const { return "NiBooleanExtraData"; };

	void Read( ifstream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		GetAttr("Boolean Data")->Read( in, version );
	}
	void Write( ofstream& out, unsigned int version ) const {
		AExtraData::Write( out, version );
		GetAttr("Boolean Data")->Write( out, version );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Boolean Data:  " << GetAttr("Boolean Data")->asString() << endl;

		return out.str();
	}
	
};

class NiIntegerExtraData : public AExtraData {
public:
	NiIntegerExtraData() {
		AddAttr( attr_int, "Integer Data" );
	}
	~NiIntegerExtraData() {}

	string GetBlockType() const { return "NiIntegerExtraData"; };

		void Read( ifstream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		GetAttr("Integer Data")->Read( in, version );
	}
	void Write( ofstream& out, unsigned int version ) const {
		AExtraData::Write( out, version );
		GetAttr("Integer Data")->Write( out, version );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Boolean Data:  " << GetAttr("Integer Data")->asString() << endl;

		return out.str();
	}
};

class NiMorphData : public AData, public IMorphData {
public:
	NiMorphData() {
		AddAttr( attr_byte, "Unknown Byte" );
	}
	~NiMorphData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiMorphData"; };

	void * QueryInterface( int id ) {
		if ( id == ID_MORPH_DATA ) {
			return (void*)static_cast<IMorphData*>(this);;
		} else {
			return ABlock::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_MORPH_DATA ) {
			return (void const *)static_cast<IMorphData const *>(this);;
		} else {
			return ABlock::QueryInterface( id );
		}
	}

	//--IMorphData Functions --//
	int GetVertexCount() const { return vertCount; }
	void SetVertexCount( int n );
	int GetMorphCount() const { return int(morphs.size()); }
	void SetMorphCount( int n ) { morphs.resize( n ); }
	vector< Key<float> > GetMorphKeys( int n ) const { return morphs[n].keys; }
	void SetMorphKeys( int n, vector< Key<float> > const & keys ) { morphs[n].keys = keys; }
	vector<Vector3> GetMorphVerts( int n) const { return morphs[n].morph; }
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

class NiPosData : public AData, public IPosData {
public:
	NiPosData() {}
	~NiPosData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiPosData"; }

	void * QueryInterface( int id ) {
		if ( id == ID_POS_DATA ) {
			return (void*)static_cast<IPosData*>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_POS_DATA ) {
			return (void const *)static_cast<IPosData const *>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}

	//--IPosData Functions--//
	KeyType GetKeyType() const { return _type; }
	void SetKeyType( KeyType t ) { _type = t; }
	vector< Key<Vector3> > GetKeys() const { return _keys; }
	void SetKeys( vector< Key<Vector3> > const & keys ) { _keys = keys; }

private:
	KeyType _type;
	vector<Key<Vector3> > _keys;
};

class NiRotatingParticlesData : public ARotatingParticlesData {
public:
	NiRotatingParticlesData() {}
	~NiRotatingParticlesData() {}

	string GetBlockType() const { return "NiRotationparticlesData"; }
};

class NiParticlesData : public ARotatingParticlesData {
public:
	NiParticlesData() {}
	~NiParticlesData() {}

	string GetBlockType() const { return "NiParticlesData"; }
};


class NiTextKeyExtraData : public AExtraData, public ITextKeyExtraData {
public:
	NiTextKeyExtraData() {
		AddAttr( attr_int, "Unknown Int", 0, VER_4_2_2_0 );
	}
	~NiTextKeyExtraData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiTextKeyExtraData"; }

	void * QueryInterface( int id ) {
		if ( id == ID_TEXT_KEY_EXTRA_DATA ) {
			return (void*)static_cast<ITextKeyExtraData*>(this);;
		} else {
			return AExtraData::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_TEXT_KEY_EXTRA_DATA ) {
			return (void const *)static_cast<ITextKeyExtraData const *>(this);;
		} else {
			return AExtraData::QueryInterface( id );
		}
	}

	//--ITextKeyExtraData Functions--//
	virtual vector< Key<string> > GetKeys() const { return _keys; }
	virtual void SetKeys( vector< Key<string> > const & keys ) { _keys = keys; }

private:
	vector< Key<string> > _keys;
};

class NiUVData : public AData {
public:
	NiUVData() {}
	~NiUVData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiUVData"; }

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
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiVertWeightsExtraData"; }

private:
	uint bytes;
	vector<float> weights;
};

class NiVisData : public AData {
public:
	NiVisData() {}
	~NiVisData() {}

	void Read( ifstream& in, unsigned int version );
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiVisData"; }

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
	void Write( ofstream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return _block_type; }

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
	void Write( ofstream& out, unsigned int version ) const {
		ABlock::Write( out, version );
		UnknownMixIn::Write( out, version );
	}
	void asString( ostream & out ) {
		out << ABlock::asString();
		out << UnknownMixIn::asString();
	}
	string GetBlockType() const { return UnknownMixIn::GetBlockType(); }
};

class UnknownControllerBlock : public AController, public UnknownMixIn {
public:
	UnknownControllerBlock( string block_type ) : UnknownMixIn(block_type) {}
	~UnknownControllerBlock() {}
	void Read( ifstream& in, unsigned int version ) {
		ABlock::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ofstream& out, unsigned int version ) const {
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
	string GetBlockType() const { return UnknownMixIn::GetBlockType(); }
};

class UnknownPropertyBlock : public AProperty, public UnknownMixIn {
public:
	UnknownPropertyBlock( string block_type ) : UnknownMixIn(block_type) {}
	~UnknownPropertyBlock() {}
	void Read( ifstream& in, unsigned int version ) {
		ABlock::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ofstream& out, unsigned int version ) const {
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
	string GetBlockType() const { return UnknownMixIn::GetBlockType(); }
};

/**
 * NiParticleSystemController
 */
class NiParticleSystemController : public AParticleSystemController {
public:
	NiParticleSystemController();
	void Init() {}
	~NiParticleSystemController() {}
	string GetBlockType() const { return "NiParticleSystemController"; }
};

/**
 * NiBSPArrayController
 */
class NiBSPArrayController : public AParticleSystemController {
public:
	NiBSPArrayController();
	void Init() {}
	~NiBSPArrayController() {}
	string GetBlockType() const { return "NiBSPArrayController"; }
};

/**
 * NiBoolInterpolator
 */
class NiBoolInterpolator : public AInterpolator {
public:
	NiBoolInterpolator();
	void Init() {}
	~NiBoolInterpolator() {}
	string GetBlockType() const { return "NiBoolInterpolator"; }
};

/**
 * NiFloatInterpolator
 */
class NiFloatInterpolator : public AInterpolator {
public:
	NiFloatInterpolator();
	void Init() {}
	~NiFloatInterpolator() {}
	string GetBlockType() const { return "NiFloatInterpolator"; }
};

/**
 * NiLookAtInterpolator
 */
class NiLookAtInterpolator : public AInterpolator {
public:
	NiLookAtInterpolator();
	void Init() {}
	~NiLookAtInterpolator() {}
	string GetBlockType() const { return "NiLookAtInterpolator"; }
};

/**
 * NiPoint3Interpolator
 */
class NiPoint3Interpolator : public AInterpolator {
public:
	NiPoint3Interpolator();
	void Init() {}
	~NiPoint3Interpolator() {}
	string GetBlockType() const { return "NiPoint3Interpolator"; }
};

/**
 * NiTransformInterpolator
 */
class NiTransformInterpolator : public AInterpolator {
public:
	NiTransformInterpolator();
	void Init() {}
	~NiTransformInterpolator() {}
	string GetBlockType() const { return "NiTransformInterpolator"; }
};

#endif
