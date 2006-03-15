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
//const int BlockInternal = -1;
const int SkinInstInternal = -2;
const int SkinDataInternal = -3;
//const int NodeInternal = -4;




//void GetBuiltUpTransform(blk_ref block, Matrix & m/*, blk_ref stop*/);

class IBlockInternal {
public:
	IBlockInternal() {}
	virtual ~IBlockInternal() {}

	//Link Tracking
	virtual void AddParent( IBlock * parent ) = 0;
	virtual void RemoveParent( IBlock * match ) = 0;
	virtual void SetBlockNum( int ) = 0;
	virtual void SetBlockTypeNum( int n ) = 0;
	virtual int GetBlockTypeNum() = 0;
	virtual void FixLinks( const vector<blk_ref> & blocks ) = 0;
	virtual void AddChild( IBlock * new_child ) = 0;
	virtual void RemoveChild( IBlock * old_child ) = 0;

	//Cross Link Tracking
	virtual void RemoveCrossLink( IBlock * block_to_remove ) = 0;

	virtual void IncCrossRef( IBlock * block ) = 0;
	virtual void DecCrossRef( IBlock * block ) = 0;

	//File I/O
	virtual void Read( istream& in, unsigned int version ) = 0;
	virtual void Write( ostream& out, unsigned int version ) const = 0;	
};

class ABlock : public IBlock/*, public IBlockInternal*/ {
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
		/*if ( id == BlockInternal ) {
			return (void*)static_cast<IBlockInternal*>(this);;
		} else {*/
			return NULL;
		/*}*/
	}

	void const * QueryInterface( int id ) const {
		/*if ( id == BlockInternal ) {
			return (void const *)static_cast<IBlockInternal const *>(this);;
		} else {*/
			return NULL;
		/*}*/
	}

	//--Internal Functions--//
	void AddParent( IBlock * new_parent);
	void RemoveParent( IBlock * match );
	void SetBlockNum( int n ) { _block_num = n; }
	virtual void FixLinks( const vector<blk_ref> & blocks );
	void SetBlockTypeNum( int n ) { _block_type_num = n; }
	int GetBlockTypeNum() { return _block_type_num; }

	void AddChild( IBlock * new_child );
	void RemoveChild( IBlock * old_child );

	virtual void RemoveCrossLink( IBlock * block_to_remove );

	void IncCrossRef( IBlock * block );
	void DecCrossRef( IBlock * block );

	virtual void Read( istream& in, unsigned int version );
	virtual void Write( ostream& out, unsigned int version ) const;
protected:
	map<string, attr_ref> _attr_map;
	vector<attr_ref> _attr_vect;
	int _block_num;
	int _block_type_num;
	unsigned int _ref_count;
	vector<IBlock*> _parents;
	list<IBlock*> _cross_refs;
};

class AControllable : public ABlock {
public:
	AControllable();
	void Init() {}
	bool IsControllable() const { return true; }
	~AControllable() {}
};

//class INodeInternal {
//public:
//	virtual void IncSkinRef( IBlock * skin_data ) = 0;
//	virtual void DecSkinRef( IBlock * skin_data ) = 0;
//};

class ANode : public AControllable, public INode/*, public INodeInternal*/ {
public:
	ANode();
	void Init() { 
		//Start the bind pose at an identity matrix
		SetIdentity44(bindPosition);

		//Start the flags at "Not a skin influence"
		GetAttr("Flags")->Set(8);
	
	};
	~ANode() {};
	void InitAttrs();
	void * QueryInterface( int id );
	void const * QueryInterface( int id ) const;
	void Read( istream& in, unsigned int version ) {
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

	//IBlockInternal Functions
	void IncCrossRef( IBlock * block );
	void DecCrossRef( IBlock * block );

protected:
	void ResetSkinnedFlag();
	Matrix44 bindPosition;
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

class AShape : public ANode {
public:
	AShape();
	void Init() {}
	~AShape() {}
};

class AParticleNode : public AShape {
public:
	AParticleNode();
	void Init() {}
	~AParticleNode() {}
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

class APSysEmitter : public APSysModifier {
public:
	APSysEmitter();
	void Init() {}
	~APSysEmitter() {}
};

class APSysVolumeEmitter : public APSysEmitter {
public:
	APSysVolumeEmitter();
	void Init() {}
	~APSysVolumeEmitter() {}
};

class AExtraData : public AData {
public:
	AExtraData() {
		AddAttr( attr_string, "Name", VER_10_0_1_0 );
		AddAttr( attr_link, "Next Extra Data", 0, VER_4_2_2_0 );
	}
	~AExtraData() {};
	void Read( istream& in, unsigned int version ) {
		GetAttr("Name")->Read( in, version );
		GetAttr("Next Extra Data")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
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

class ADynamicEffect   : public ANode {
public:
	ADynamicEffect();
	void Init() {}
	~ADynamicEffect() {}
};

class ALight   : public ADynamicEffect {
public:
	ALight();
	void Init() {}
	~ALight() {}
};

class APointLight   : public ALight {
public:
	APointLight();
	void Init() {}
	~APointLight() {}
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
 * NiFogProperty
 */
class NiFogProperty : public AProperty {
public:

	NiFogProperty();
	void Init() {}
	~NiFogProperty() {}

	string GetBlockType() const { return "NiFogProperty"; }
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
class NiTexturingProperty : public AProperty, public ITexturingProperty {
public:
	NiTexturingProperty( ) { AddAttr( attr_flags, "Flags", 0, VER_10_0_1_0 ); }
	void Init() {}
	~NiTexturingProperty();
	string GetBlockType() const { return "NiTexturingProperty"; }

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	void FixLinks( const vector<blk_ref> & blocks );
	list<blk_ref> GetLinks() const;

	// ITexturingProperty functions
	int GetTextureCount() const { return int(textures.size()); }
	void SetTextureCount( int new_count );
	int GetExtraTextureCount() const { return int(extra_textures.size()); }
	void SetExtraTextureCount( int new_count );
	ApplyMode GetApplyMode() const { return appl_mode; }
	void SetApplyMode( ApplyMode new_val ) { appl_mode = new_val; }
	TexDesc GetTexture( int n ) const { return textures[n]; }
	void SetTexture( int n, TexDesc & new_val );
	TexDesc GetExtraTexture( int n ) const { return extra_textures[n].first; }
	void SetExtraTexture( int n, TexDesc & new_val );
	float GetLumaOffset() const { return bmLumaOffset; }
	void SetLumaOffset( float new_val ) { bmLumaOffset = new_val; }
	float GetLumaScale() const { return bmLumaScale; }
	void SetLumaScale( float new_val ) { bmLumaScale = new_val; }
	Matrix22 GetBumpMapMatrix() const { return bmMatrix; }
	void SetBumpMapMatrix( Matrix22 & new_val ) { bmMatrix = new_val; }

	void * QueryInterface( int id ) {
		if ( id == ID_TEXTURING_PROPERTY ) {
			return (void*)static_cast<ITexturingProperty*>(this);;
		} else {
			return AProperty::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_TEXTURING_PROPERTY ) {
			return (void const *)static_cast<ITexturingProperty const *>(this);;
		} else {
			return AProperty::QueryInterface( id );
		}
	}

private:
	ApplyMode appl_mode;
	vector<TexDesc> textures; //the main textures, base, gloss, glow, etc.
	vector< pair<TexDesc,uint> > extra_textures; //extra texture group

	//Bitmap info - only used if a bitmap texture is present
	float bmLumaOffset; // The bitmap luma offset.  Unsure of function.
	float bmLumaScale; // The bitmap luma scale.  Unsure of function.  
	Matrix22 bmMatrix; // The bitmap 2x2 matrix.  Unsure of function.
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
class NiPixelData : public AData, public IPixelData {
public:
	NiPixelData() {
		data = NULL;
		dataSize = 0;
		AddAttr( attr_int, "Unknown Int" );
		AddAttr( attr_link, "Palette" );

	}
	~NiPixelData() { if (data != NULL) delete [] data; }

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiPixelData"; }

	void * QueryInterface( int id ) {
		if ( id == ID_PIXEL_DATA ) {
			return (void*)static_cast<IPixelData*>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_PIXEL_DATA ) {
			return (void const *)static_cast<IPixelData const *>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}

	//IPixelData Functions
	int GetHeight() const;
	int GetWidth() const;
	PixelFormat GetPixelFormat() const;

	void Reset( int new_width, int new_height, PixelFormat px_fmt );
	
	vector<Color4> GetColors() const;
	void SetColors( const vector<Color4> & new_pixels, bool generate_mipmaps );

private:
	struct MipMap {
		uint width, height, offset;
	};
	
	PixelFormat pxFormat;
	uint redMask, blueMask, greenMask, alphaMask, bpp, unkInt;
	byte unk8Bytes[8];
	vector<MipMap> mipmaps;
	uint dataSize;
	byte * data;
	byte unk54Bytes[54];
	uint unkInt2;
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
		AddAttr( attr_link, "Unknown Link", VER_20_0_0_4 );
	}
	~AShapeData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	void * QueryInterface( int id );
	void const * QueryInterface( int id ) const;

	//--IShapeData--//
	//Counts
	int GetVertexCount() const { return int(vertices.size()); }
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
	vector<Vector3> unk_vects;
	vector< vector<TexCoord> > uv_sets;
	void CalcCentAndRad( Vector3 & center, float & radius ) const;
};

/**
 * AParticlesData - Generic particle system data block.
 */

class AParticlesData : public AShapeData {
public:
	AParticlesData() {}
	~AParticlesData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
protected:
	bool hasSizes;
	ushort numActive, unkShort;
	float size;
	vector<float> sizes;
};

/**
 * APSysData - New generic particle system data block.
 */

class APSysData : public AShapeData {
public:
	APSysData() {}
	~APSysData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
protected:
	vector<float> unkFloats1;
	ushort unkShort;
	vector<float> unkFloats2;
	byte unkByte;
};

/**
 * NiMeshPSysData
 */

class NiMeshPSysData : public APSysData {
public:
	NiMeshPSysData() {
		AddAttr( attr_link, "Modifier" );
		AddAttr( attr_linkgroup, "Unknown Link Group", VER_10_2_0_0 );
		AddAttr( attr_link, "Unknown Link 2", VER_10_2_0_0 );
	}
	~NiMeshPSysData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiMeshPSysData"; };
protected:
	vector<float> unkFloats;
	uint unkInt;
	byte unkByte;
	uint unk3Ints[3];
};

/**
 * NiPSysData
 */

class NiPSysData : public APSysData {
public:
	NiPSysData() {}
	~NiPSysData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiPSysData"; };
protected:
	vector<float> unkFloats;
	uint unkInt;
	bool unkBool1;
	vector<byte> unkBytes1;
	byte unkByte;
	bool unkBool2;
	vector<byte> unkBytes2;
};

/**
 * ARotatingParticlesData - Generic rotating particles data block. 
 */

class ARotatingParticlesData : public AParticlesData {
public:
	ARotatingParticlesData() {}
	~ARotatingParticlesData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
protected:
	ushort numActiveRot;
	vector<float> unkFloats;
	vector<Quaternion> rotations;
};

/**
 * NiParticleMeshesData - Particle meshes data. 
 */

class NiParticleMeshesData : public ARotatingParticlesData {
public:
	NiParticleMeshesData() {
		AddAttr( attr_link, "Unknown Link 2" );
	}
	~NiParticleMeshesData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiTriShapeData"; }
	void * QueryInterface( int id );
	void const * QueryInterface( int id ) const;

	//--ITriShapeData--//

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
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiTriStripsData"; }

	void * QueryInterface( int id );
	void const * QueryInterface( int id ) const;

	//--ITriStripsData--//
	//Counts
	short GetStripCount() const;
	void SetStripCount(int n);
	
	//Getters
	vector<short> GetStrip( int index ) const;
	vector<Triangle> GetTriangles() const;
	//Setter
	void SetStrip( int index, const vector<short> & in );

private:
	short GetTriangleCount() const;
	vector< vector<short> > strips;
};

/**
 * NiBSplineBasisData - Collision box.
 */
class NiBSplineBasisData : public AData {
public:
	NiBSplineBasisData() { AddAttr( attr_int, "Unknown Int" ); }
	~NiBSplineBasisData() {}

	string GetBlockType() const { return "NiBSplineBasisData"; }
};

/**
 * NiBSplineData - Collision box.
 */
class NiBSplineData : public AData {
public:
	NiBSplineData() {}
	~NiBSplineData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiBSplineData"; }
private:
	uint unkInt;
	vector<ushort> unkShorts;
};

/**
 * NiCollisionData - Collision box.
 */
class NiCollisionData : public AData {
public:
	NiCollisionData() {}
	~NiCollisionData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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
 * NiLightDimmerController
 */
class NiLightDimmerController : public AController {
public:
	NiLightDimmerController();
	void Init() {}
	~NiLightDimmerController() {}
	string GetBlockType() const { return "NiLightDimmerController"; }
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
 * NiBoneLODController
 */
class NiBoneLODController : public AController {
public:
	NiBoneLODController() {}
	~NiBoneLODController();
	string GetBlockType() const { return "NiBoneLODController"; }

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	void FixLinks( const vector<blk_ref> & blocks );
	list<blk_ref> GetLinks() const;

private:
	uint unkInt1, unkInt2;
	vector< vector<blk_ref> > _node_groups;
	vector< vector< pair<blk_ref,blk_ref> > > _shape_groups;
	vector<blk_ref> _shape_group2;
};

/**
 * NiRangeLODData
 */
class NiRangeLODData : public AData {
public:
	NiRangeLODData() {}
	~NiRangeLODData() {}
	string GetBlockType() const { return "NiRangeLODData"; }

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

private:
	Vector3 _center;
	vector<LODRange> ranges;
};

class NiScreenLODData : public AData {
public:
	NiScreenLODData() {}
	~NiScreenLODData() {}

	string GetBlockType() const { return "NiScreenLODData"; }

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	private:
	float unk_floats[8];
	vector<float> unk_float_list;
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
 * NiFloatExtraDataController
 */
class NiFloatExtraDataController : public AController {
public:
	NiFloatExtraDataController();
	void Init() {}
	~NiFloatExtraDataController() {}
	string GetBlockType() const { return "NiFloatExtraDataController"; }
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
 * NiMultiTargetTransformController
 */
class NiMultiTargetTransformController : public AController {
public:
	NiMultiTargetTransformController();
	void Init() {}
	~NiMultiTargetTransformController() {}
	string GetBlockType() const { return "NiMultiTargetTransformController"; }
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
 * NiPSysEmitterDeclinationVarCtlr
 */
class NiPSysEmitterDeclinationVarCtlr : public AController {
public:
	NiPSysEmitterDeclinationVarCtlr();
	void Init() {}
	~NiPSysEmitterDeclinationVarCtlr() {}
	string GetBlockType() const { return "NiPSysEmitterDeclinationVarCtlr"; }
};

/**
 * NiPSysEmitterInitialRadiusCtlr
 */
class NiPSysEmitterInitialRadiusCtlr : public AController {
public:
	NiPSysEmitterInitialRadiusCtlr();
	void Init() {}
	~NiPSysEmitterInitialRadiusCtlr() {}
	string GetBlockType() const { return "NiPSysEmitterInitialRadiusCtlr"; }
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

class NiPointLight : public APointLight {
public:
	NiPointLight();
	void Init() {}
	~NiPointLight() {}
	string GetBlockType() const { return "NiPointLight"; }
};

/**
 * NiSpotLight
 */

class NiSpotLight : public APointLight {
public:
	NiSpotLight();
	void Init() {}
	~NiSpotLight() {}
	string GetBlockType() const { return "NiSpotLight"; }
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

class NiTextureEffect : public ADynamicEffect {
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

class NiPSysBoxEmitter : public APSysVolumeEmitter {
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

class NiPSysCylinderEmitter : public APSysVolumeEmitter {
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
 * NiPSysSphereEmitter
 */

class NiPSysSphereEmitter : public APSysVolumeEmitter {
public:
	NiPSysSphereEmitter();
	void Init() {}
	~NiPSysSphereEmitter() {}
	string GetBlockType() const { return "NiPSysSphereEmitter"; }
}; 

/**
 * NiPSysEmitterCtlrData
 */
class NiPSysEmitterCtlrData : public AData {
public:
	NiPSysEmitterCtlrData() {}
	~NiPSysEmitterCtlrData() {}

	string GetBlockType() const { return "NiPSysEmitterCtlrData"; }
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
private:
	KeyType f_key_type;
	vector< Key<float> > float_keys;
	vector< Key<byte> > byte_keys;
};

/**
 * AKeyframeData -
 */

class AKeyframeData : public AData, public IKeyframeData {

	public:

		AKeyframeData() {}
		~AKeyframeData() {}

		void Read( istream& in, unsigned int version );
		void Write( ostream& out, unsigned int version ) const;
		string asString() const;
		string GetBlockType() const { return "AKeyframeData"; }
		
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
		void SetRotateKeys( const vector< Key<Quaternion> > & keys ) { rotKeys = keys; }
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
 * NiKeyframeData
 */

class NiKeyframeData : public AKeyframeData {
public:
	NiKeyframeData() {}
	~NiKeyframeData() {}

	string GetBlockType() const { return "NiKeyframeData"; }
};

/**
 * NiTransformData
 */

class NiTransformData : public AKeyframeData {
public:
	NiTransformData() {}
	~NiTransformData() {}

	string GetBlockType() const { return "NiTransformData"; }
};

/**
 * NiPalette
 */

class NiPalette : public AData, public IPalette {
public:
	NiPalette() {}
	void Init() {}
	~NiPalette() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiPalette"; }

	
	void * QueryInterface( int id ) {
		if ( id == ID_PALETTE ) {
			return (void*)static_cast<IPalette*>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_PALETTE ) {
			return (void const *)static_cast<IPalette const *>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}

	//IPalette Functions
	vector<Color4> GetPalette() const;
	void SetPalette( const vector<Color4> & new_pal );

private:
	byte unkByte;
	uint numEntries;
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
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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
 * NiStringPalette
 */

class NiStringPalette : public AData {
public:
	NiStringPalette() { AddAttr( attr_string, "Palette" ); }
	void Init() {}
	~NiStringPalette() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiStringPalette"; }
};


/**
 * NiSkinInstance
 */

//Non-Public interface to allow NiSkinData to get the bone list read by NiSkinInstance
class ISkinInstInternal {
public:
	virtual vector<int> GetBoneList() const = 0;
	virtual void ReadBoneList( istream& in ) = 0;
};

class NiSkinInstance : public AData, public ISkinInstInternal {
public:
	NiSkinInstance(){
		AddAttr( attr_link, "Data" );
		AddAttr( attr_link, "Skin Partition", VER_10_2_0_0 );
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

	void ReadBoneList( istream& in ) {
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
	//virtual void SetBones( vector<blk_ref> bone_blocks ) = 0;
	virtual void RepositionTriShape( blk_ref & tri_shape ) = 0;
	//virtual void StraightenSkeleton() = 0;
	//virtual void RemoveBoneByPtr( IBlock * bone ) = 0;
};

class NiSkinData : public AData, public ISkinData, public ISkinDataInternal {

	public:

		NiSkinData() { 
			AddAttr( attr_link, "Skin Partition", 0, VER_10_1_0_0 );
			SetIdentity33(rotation);
			translation[0] = 0.0f;
			translation[1] = 0.0f;
			translation[2] = 0.0f;
			scale = 1.0f;
			unknownInt = -1;
			unknownByte = 1;
		}
		~NiSkinData();

		void Read( istream& in, unsigned int version );
		void Write( ostream& out, unsigned int version ) const;
		string asString() const;
		string GetBlockType() const { return "NiSkinData"; }
		void * QueryInterface( int id );
		void const * QueryInterface( int id ) const;

		//IBlockInternal
		void FixLinks( const vector<blk_ref> & blocks ); // This version of the function will copy the bones from the parent Skin Instance block and fix the links at the same time.
		void RemoveCrossLink( IBlock * block_to_remove );

		//ISkinDataInternal
		void RepositionTriShape( blk_ref & tri_shape );

        //ISkinData
		vector<blk_ref> GetBones() const;
		map<int, float> GetWeights( const blk_ref & bone ) const;
		void AddBone( const blk_ref & bone, map<int, float> const & in );
		void RemoveBone( const blk_ref & bone );
	private:
		void SetBones( const vector<blk_ref> & bone_blocks );
		void StraightenSkeleton();
		struct Bone {
			Matrix33 rotation;
			fVector3 translation;
			float scale;
			fVector4 unknown4Floats;
			map<int, float> weights;
		};

		INode * GetNodeParent() const;
		void CalculateOverallOffset( Matrix33 & rot, fVector3 & tr, float & sc ) const;
		void CalculateBoneOffset( const INode * const par_node, const IBlock * const bone_block, Bone & result ) const;
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

class NiBoolData : public AData, public IBoolData {
public:
	NiBoolData() {}
	~NiBoolData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiBoolData"; };

	void * QueryInterface( int id ) {
		if ( id == ID_BOOL_DATA ) {
			return (void*)static_cast<IBoolData*>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_BOOL_DATA ) {
			return (void const *)static_cast<IBoolData const *>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}

	//--IBoolData Functions--//
	KeyType GetKeyType() const { return _type; }
	void SetKeyType( KeyType t ) { _type = t; }
	vector< Key<unsigned char> > GetKeys() const { return _keys; }
	void SetKeys( vector< Key<unsigned char> > const & keys ) { _keys = keys; }

private:
	KeyType _type;
	vector< Key<byte> > _keys;
};

class NiColorData : public AData, public IColorData {
public:
	NiColorData() {}
	~NiColorData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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
class NiControllerSequence : public AData, public IControllerSequence {
public:
	NiControllerSequence() {
		AddAttr( attr_string, "Name" );
		AddAttr( attr_link, "String Palette", VER_10_2_0_0 );
	}
	~NiControllerSequence();

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiControllerSequence"; }

	void FixLinks( const vector<blk_ref> & blocks );
	list<blk_ref> GetLinks() const;

	void * QueryInterface( int id ) {
		if ( id == ID_CONTROLLER_SEQUENCE ) {
			return (void*)static_cast<IControllerSequence*>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}
	void const * QueryInterface( int id ) const {
		if ( id == ID_CONTROLLER_SEQUENCE ) {
			return (void const *)static_cast<IControllerSequence const *>(this);;
		} else {
			return AData::QueryInterface( id );
		}
	}

	//IControllerSequence Functions
	void SetTextKey( string new_name, blk_ref new_link );
	void AddKfChild( string new_name, blk_ref new_link, string controller_type);
	void ClearKfChildren();
private:
	string GetSubStr( const string & pal, short offset ) const;

	struct KfChild {
		blk_ref block;
		string name;
		short name_offset;
		short controller_offset;
		blk_ref unk_link;
		short unk_offs1, unk_offs2, unk_offs3, unk_offs4, unk_offs5, unk_offs6, unk_offs7, unk_offs8;
		KfChild() : block(), name(), name_offset(-1), controller_offset(-1), unk_link(),
		unk_offs1(-1), unk_offs2(-1), unk_offs3(-1), unk_offs4(-1),
		unk_offs5(-1), unk_offs6(-1), unk_offs7(-1), unk_offs8(-1) {};
	};
	string txt_key_name;
	blk_ref txt_key_blk;
	vector< KfChild > children;

	uint unk_int1, unk_int2;
	float unk_float1, unk_float2, unk_4_floats[4];
	string unk_string;
};

class NiFloatData : public AData, public IFloatData {
public:
	NiFloatData() {}
	~NiFloatData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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

class NiStringsExtraData : public AExtraData {
public:
	NiStringsExtraData() {}
	~NiStringsExtraData() {}
	string GetBlockType() const { return "NiStringsExtraData"; };

	void Read( istream& file, unsigned int version ) {
		AExtraData::Read( file, version );
		uint count = ReadUInt( file );
		string_data.resize( count );
		NifStream( string_data, file );
	}
	void Write( ostream& file, unsigned int version ) const {
		AExtraData::Write( file, version );
		WriteUInt( uint(string_data.size()), file );
		NifStream( string_data, file );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Strings:  " << uint(string_data.size()) << endl;

		for ( uint i = 0; i < string_data.size(); ++i ) {
			out << "   " << i << ":  " << string_data[i] << endl;
		}

		return out.str();
	}
private:
	vector<string> string_data;
};

class NiStringExtraData : public AExtraData {
public:
	NiStringExtraData() {
		AddAttr( attr_string, "String Data" );
	}
	~NiStringExtraData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		GetAttr("Boolean Data")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
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

class NiBinaryExtraData : public AExtraData {
public:
	NiBinaryExtraData() {}
	~NiBinaryExtraData() {}
	string GetBlockType() const { return "NiBinaryExtraData"; };

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		
		uint numBytes = ReadUInt( in );
		binData.resize( numBytes );
		NifStream( binData, in );

	}
	void Write( ostream& out, unsigned int version ) const {
		AExtraData::Write( out, version );
		
		WriteUInt( uint(binData.size()), out );
		NifStream( binData, out );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Binary Data (" << uint(binData.size()) << " bytes):" << endl;

		for ( uint i = 0; i < binData.size(); ++i ) {
			out << "   " << i << ":  " << binData[i] << endl;
		}

		return out.str();
	}
private:
	vector<byte> binData;
	
};

class NiVectorExtraData : public AExtraData {
public:
	NiVectorExtraData() {
		AddAttr( attr_vector3, "Vector Data" );
		AddAttr( attr_float, "Unknown Float" );
	}
	~NiVectorExtraData() {}
	string GetBlockType() const { return "NiVectorExtraData"; };

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		GetAttr("Vector Data")->Read( in, version );
		GetAttr("Unknown Float")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		GetAttr("Vector Data")->Write( out, version );
		GetAttr("Unknown Float")->Write( out, version );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Vector Data:  " << GetAttr("Vector Data")->asString() << endl
			<< "Unknown Float:  " << GetAttr("Unknown Float")->asString() << endl;

		return out.str();
	}
	
};

class NiColorExtraData : public AExtraData {
public:
	NiColorExtraData() {}
	~NiColorExtraData() {}
	string GetBlockType() const { return "NiColorExtraData"; };

	void Read( istream& file, unsigned int version ) {
		AExtraData::Read( file, version );
		NifStream( color, file );
	}
	void Write( ostream& file, unsigned int version ) const {
		AExtraData::Write( file, version );
		NifStream( color, file );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Color Data:  (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")" << endl;

		return out.str();
	}
private:
	Color4 color;	
};

class NiFloatExtraData : public AExtraData {
public:
	NiFloatExtraData() {
		AddAttr( attr_float, "Float Data" );
	}
	~NiFloatExtraData() {}
	string GetBlockType() const { return "NiFloatExtraData"; };

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		GetAttr("Float Data")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		AExtraData::Write( out, version );
		GetAttr("Float Data")->Write( out, version );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Float Data:  " << GetAttr("Float Data")->asString() << endl;

		return out.str();
	}
	
};

class NiFloatsExtraData : public AExtraData {
public:
	NiFloatsExtraData() {}
	~NiFloatsExtraData() {}
	string GetBlockType() const { return "NiFloatsExtraData"; };

	void Read( istream& file, unsigned int version ) {
		AExtraData::Read( file, version );
		uint count = ReadUInt( file );
		float_data.resize( count );
		NifStream( float_data, file );
	}
	void Write( ostream& file, unsigned int version ) const {
		AExtraData::Write( file, version );
		WriteUInt( uint(float_data.size()), file );
		NifStream( float_data, file );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Floats:  " << uint(float_data.size()) << endl;

		for ( uint i = 0; i < float_data.size(); ++i ) {
			out << "   " << i << ":  " << float_data[i] << endl;
		}

		return out.str();
	}
private:
	vector<float> float_data;
};

class NiIntegersExtraData : public AExtraData {
public:
	NiIntegersExtraData() {}
	~NiIntegersExtraData() {}
	string GetBlockType() const { return "NiIntegersExtraData"; };

	void Read( istream& file, unsigned int version ) {
		AExtraData::Read( file, version );
		uint count = ReadUInt( file );
		int_data.resize( count );
		NifStream( int_data, file );
	}
	void Write( ostream& file, unsigned int version ) const {
		AExtraData::Write( file, version );
		WriteUInt( uint(int_data.size()), file );
		NifStream( int_data, file );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Ints:  " << uint(int_data.size()) << endl;

		for ( uint i = 0; i < int_data.size(); ++i ) {
			out << "   " << i << ":  " << int_data[i] << endl;
		}

		return out.str();
	}
private:
	vector<uint> int_data;
};

class NiIntegerExtraData : public AExtraData {
public:
	NiIntegerExtraData() {
		AddAttr( attr_int, "Integer Data" );
	}
	~NiIntegerExtraData() {}

	string GetBlockType() const { return "NiIntegerExtraData"; };

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		GetAttr("Integer Data")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		AExtraData::Write( out, version );
		GetAttr("Integer Data")->Write( out, version );
	}

	string asString() const {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << AExtraData::asString()
			<< "Integer Data:  " << GetAttr("Integer Data")->asString() << endl;

		return out.str();
	}
};

class NiMorphData : public AData, public IMorphData {
public:
	NiMorphData() {
		AddAttr( attr_byte, "Unknown Byte" );
	}
	~NiMorphData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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
	KeyType GetMorphKeyType( int n ) const { return morphs[n]._type; }
	void SetMorphKeyType( int n, KeyType t ) { morphs[n]._type = t; }
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
		Morph() :  _type(QUADRATIC_KEY) {}
		~Morph() {}
		KeyType _type;
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

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
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
	void Read( istream& in, unsigned int version ) {
		//cout << endl << "Unknown Block Type found:  " << GetBlockType() << "\a" << endl;
		ABlock::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
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
	void Read( istream& in, unsigned int version ) {
		ABlock::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
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
	void Read( istream& in, unsigned int version ) {
		ABlock::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
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
 * NiBSplineCompFloatInterpolator
 */
class NiBSplineCompFloatInterpolator : public AInterpolator {
public:
	NiBSplineCompFloatInterpolator();
	void Init() {}
	~NiBSplineCompFloatInterpolator() {}
	string GetBlockType() const { return "NiBSplineCompFloatInterpolator"; }
};

/**
 * NiBSplineCompPoint3Interpolator
 */
class NiBSplineCompPoint3Interpolator : public AInterpolator {
public:
	NiBSplineCompPoint3Interpolator();
	void Init() {}
	~NiBSplineCompPoint3Interpolator() {}
	string GetBlockType() const { return "NiBSplineCompPoint3Interpolator"; }
};

/**
 * NiBSplineCompTransformInterpolator
 */
class NiBSplineCompTransformInterpolator : public AInterpolator {
public:
	NiBSplineCompTransformInterpolator();
	void Init() {}
	~NiBSplineCompTransformInterpolator() {}
	string GetBlockType() const { return "NiBSplineCompTransformInterpolator"; }
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
	//	AddAttr( attr_short, "Unknown Short", 0, 0xFFFFFFFF );

	//	AddAttr( attr_link, "Unknown Link", 0, 0xFFFFFFFF );
	//	Init();
	//}

	//void Read( istream& in, unsigned int version );
	//void Write( ostream& out, unsigned int version ) const;
	//string asString() const;

	void Init() {}
	~NiLookAtInterpolator() {}
	string GetBlockType() const { return "NiLookAtInterpolator"; }
private:
	vector<float> unkFloats;
	byte unkBytes[8];

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
