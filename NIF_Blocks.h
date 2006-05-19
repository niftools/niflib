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
#include "NiObject.h"
#include "obj\NiObject.h"
#include "NIF_IO.h"

#include <vector>
#include <list>
#include <map>
#include <cmath>
#include <sstream>

//--Types--//
//typedef	pair<attr_ref, blk_ref> LinkPair;
//typedef multimap<attr_ref, blk_ref> LinkMap;
//typedef LinkMap::iterator LinkMapIt;
//typedef pair<LinkMapIt,LinkMapIt> LinkMapRange;

//--Constants--//

//Non-Public Interface IDs

//const int SkinInstInternal = -2;
//const int SkinDataInternal = -3;

class AControllable : public NiObject {
public:
	static const Type TYPE;
	AControllable();
	void Init() {}
	bool IsControllable() const { return true; }
	~AControllable() {}
};

const Type AControllable::TYPE("AControllable", &NiObject::TYPE);

class ANode : public AControllable {
public:
	static const Type TYPE;
	ANode();
	void Init() { 
		//Start the bind pose at an identity matrix
		bindPosition = Matrix44::IDENTITY;

		//Start the flags at "Not a skin influence"
		//GetAttr("Flags")->Set(8);
	
	};
	~ANode() {};
	void InitAttrs();
	void Read( istream& in, unsigned int version ) {
		NiObject::Read( in, version );
		Matrix44 transform;
		transform = GetLocalTransform();
		SetWorldBindPos( transform );
	}

	/*! 
	 * This is a conveniance function that allows you to retrieve the full 4x4 matrix transform of a node.  It accesses the "Rotation," "Translation," and "Scale" attributes and builds a complete 4x4 transformation matrix from them.
	 * \return A 4x4 transformation matrix built from the node's transform attributes.
	 * \sa INode::GetWorldTransform
	 */
	Matrix44 GetLocalTransform() const;

	/*! 
	 * This function will return a transform matrix that represents the location of this node in world space.  In other words, it concatenates all parent transforms up to the root of the scene to give the ultimate combined transform from the origin for this node.
	 * \return The 4x4 world transform matrix of this node.
	 * \sa INode::GetLocalTransform
	 */
	Matrix44 GetWorldTransform() const;

	/*!
	 * This function returns the bind position world matrix.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.
	 * \return The 4x4 world bind position matrix of this node.
	 * \sa INode::GetLocalBindPos, INode::SetWorldBindPos
	 */
	Matrix44 GetWorldBindPos() const;

	/*! This function returns the bind position world matrix of this node multiplied with the inverse of the bind position world matrix of its parent object if any.  Thus it returns the bind position of the object in local coordinates.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.
	 * \return The 4x4 local bind position matrix of this node.
	 * \sa INode::SetWorldBindPos, INode::GetWorldBindPos
	 */
	Matrix44 GetLocalBindPos() const;

	/*!
	 * This function sets the bind position of this object relative to the origin.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.  This function must be called on every object in a skin and bones system (the bones and the skinned shapes) in order for skinning information to be written to a Nif file.
	 * \param m The 4x4 world bind position matrix of this node
	 * \sa INode::GetLocalBindPos, INode::GetWorldBindPos
	 */
	void SetWorldBindPos( Matrix44 const & m );

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

class AController : public NiObject {
public:
	AController();
	void Init() {}
	bool IsController() { return true; }
	~AController() {}
};

class AData : public NiObject {
public:
	AData() {}
	void Init() {}
	~AData() {}
};

class AInterpolator : public NiObject {
public:
	AInterpolator();
	void Init() {}
	~AInterpolator() {}
};

class AParticleModifier : public NiObject {
public:
	AParticleModifier();
	void Init() {}
	~AParticleModifier() {}
};

class APSysModifier : public NiObject {
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
		//AddAttr( attr_string, "Name", VER_10_0_1_0 );
		//AddAttr( attr_link, "Next Extra Data", 0, VER_4_2_2_0 );
	}
	~AExtraData() {};
	void Read( istream& in, unsigned int version ) {
		//GetAttr("Name")->Read( in, version );
		//GetAttr("Next Extra Data")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		//GetAttr("Name")->Write( out, version );
		//GetAttr("Next Extra Data")->Write( out, version );
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
 * NiTexturingProperty - references all textures attatched to meshes which include it in their property list.
 */
class NiTexturingProperty : public AProperty {
public:
	NiTexturingProperty( ) { //AddAttr( attr_flags, "Flags", 0, VER_10_0_1_0 ); 
	}
	void Init() {}
	~NiTexturingProperty();
	string GetBlockType() const { return "NiTexturingProperty"; }

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	void FixLinks( const vector<blk_ref> & blocks );
	list<blk_ref> GetLinks() const;

	/*! Retrieves the number of texture slots defined by this texturing propery.  Texture slots may or may not actually contain textures, but each slot has a different meaning so the way a texture is used is dependant upon which slot it is in.
	 * \return The number of texture slots defined by this texturing property.
	 * \sa ITexturingProperty::SetTextureCount
	 */
	int GetTextureCount() const { return int(textures.size()); }

	/*! Sets the number of texture slots defined by this texturing propery.  Known valid values are 7 and 8.
	 * \param n The new size of the texture slot array.
	 * \sa ITexturingProperty::GetTextureCount
	 */
	void SetTextureCount( int new_count );

	/*! Retrieves the number of extra texture slots defined by this texturing propery.  These only exist in later Nif versions and their function is unknown.
	 * \return The number of extra texture slots defined by this texturing property.
	 * \sa ITexturingProperty::SetExtraTextureCount
	 */
	int GetExtraTextureCount() const { return int(extra_textures.size()); }

	/*! Sets the number of extra texture slots defined by this texturing propery.  Often zero.
	 * \param n The new size of the extra texture slot array.
	 * \sa ITexturingProperty::GetExtraTextureCount
	 */
	void SetExtraTextureCount( int new_count );

	/*! Retrieves the current apply mode for this texturing propery.  This enum value affects the way the textures will be drawn.
	 * \return The current apply mode for this texturing property.
	 * \sa ITexturingProperty::SetApplyMode
	 */
	ApplyMode GetApplyMode() const { return appl_mode; }

	/*! Sets the current apply mode for this texturing propery.  This enum value affects the way the textures will be drawn.
	 * \param new_val The new apply mode for this texturing property.
	 * \sa ITexturingProperty::GetApplyMode
	 */
	void SetApplyMode( ApplyMode new_val ) { appl_mode = new_val; }

	/*! Retrieves the texture desription structure that describes a texture by slot number.  The TexType enum is provided to make it easy to select the texture slot with the specific qualities that you want.
	 * \param n The slot number of the texture to get the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \sa ITexturingProperty::SetTexture, TexType
	 */
	TexDesc GetTexture( int n ) const { return textures[n]; }

	/*! Sets a new description for the texture in the given slot number.  The TexType enum is provided to make it easy to select the texture slot with the specific qualities that you want.
	 * \param n The slot number of the texture to set the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \param new_val Thew new texture descriptoin for the texture at the given slot number.
	 * \sa ITexturingProperty::GetTexture, TexType
	 */
	void SetTexture( int n, TexDesc & new_val );

	/*! Retrieves the texture desription structure that describes an extra texture by slot number.  These only exist in the later Nif versions and their function is unknown.
	 * \param n The slot number of the extra texture to get the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetExtraTextureCount.
	 * \sa ITexturingProperty::SetExtraTexture
	 */
	TexDesc GetExtraTexture( int n ) const { return extra_textures[n].first; }

	/*! Sets a new description for the texture in the given slot number.  These only exist in the later Nif versions and their function is unknown.
	 * \param n The slot number of the extra texture to set the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \param new_val Thew new texture descriptoin for the extra texture at the given slot number.
	 * \sa ITexturingProperty::GetTexture, TexType
	 */
	void SetExtraTexture( int n, TexDesc & new_val );

	/*! Retrieves the bump map luma offset.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return The bump map luma offset.
	 * \sa ITexturingProperty::SetLumaOffset
	 */
	float GetLumaOffset() const { return bmLumaOffset; }

	/*! Sets the bump map luma offset.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map luma offset.
	 * \sa ITexturingProperty::GetLumaOffset
	 */
	void SetLumaOffset( float new_val ) { bmLumaOffset = new_val; }

	/*! Retrieves the bump map luma scale.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return The bump map luma scale.
	 * \sa ITexturingProperty::SetLumaScale
	 */
	float GetLumaScale() const { return bmLumaScale; }

	/*! Sets the bump map luma scale.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map luma scale.
	 * \sa ITexturingProperty::GetLumaScale
	 */
	void SetLumaScale( float new_val ) { bmLumaScale = new_val; }

	/*! Retrieves the bump map matrix.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return the bump map matrix.
	 * \sa ITexturingProperty::SetBumpMapMatrix
	 */
	Matrix22 GetBumpMapMatrix() const { return bmMatrix; }

	/*! Sets the bump map matrix.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map matrix.
	 * \sa ITexturingProperty::GetBumpMapMatrix
	 */
	void SetBumpMapMatrix( Matrix22 & new_val ) { bmMatrix = new_val; }

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
class NiPixelData : public AData {
public:
	NiPixelData() {
		data = NULL;
		dataSize = 0;
		//AddAttr( attr_int, "Unknown Int" );
		//AddAttr( attr_link, "Palette" );

	}
	~NiPixelData() { if (data != NULL) delete [] data; }

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiPixelData"; }

	/*! Retrieves the height of the texture image stored in this block.
	 * \return The height of the texture image stored in this block.
	 * \sa IPixelData::GetWidth, IPixelData::GetPixelFormat
	 */
	int GetHeight() const;

	/*! Retrieves the width of the texture image stored in this block.
	 * \return The width of the texture image stored in this block.
	 * \sa IPixelData::GetHeight, IPixelData::GetPixelFormat
	 */
	int GetWidth() const;

    /*! Retrieves the pixel format of the texture image stored in this block.
	 * \return The pixel format of the texture image stored in this block.
	 * \sa IPixelData::GetWidth, IPixelData::GetHeight
	 */
	PixelFormat GetPixelFormat() const;

    /*! Deletes all image data and sets a new size and format in preparation for new data to be provided.
	 * \param new_width The width of the new texture image.
	 * \param new_height The height of the new texture image.
	 * \param px_fmt The pixel format of the new texture image.
	 * \sa IPixelData::GetWidth, IPixelData::GetHeight
	 */
	void Reset( int new_width, int new_height, PixelFormat px_fmt );
	
	/*! Retrieves the the pixels of the texture image stored in this block.  This function does not work on palettized textures.
	 * \return A vector containing the colors of each pixel in the texture image stored in this block, one row after another starting from the bottom of the image.  The width of the image must be used to interpret them correctly.
	 * \sa IPixelData::SetColors, IPixelData::GetWidth
	 */
	vector<Color4> GetColors() const;

	/*! Sets the the pixels of the texture image stored in this block and optionally generates mipmaps.  This function does not work for palettized textures.
	 * \param new_pixels A vector containing the colors of each new pixel to be set in the texture image stored in this block, one row after another starting from the botom of the image.
	 * \param generate_mipmaps If true, mipmaps will be generated for the new image and stored in the file.
	 * \sa IPixelData::GetColors, IPixelData::GetWidth
	 */
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
class AShapeData : public AData {
public:
	AShapeData() {
		//AddAttr( attr_string, "Name", VER_10_2_0_0 );
		//AddAttr( attr_link, "Unknown Link", VER_20_0_0_4 );
	}
	~AShapeData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	//--Counts--//

	/*! Returns the number of verticies that make up this mesh.  This is also the number of normals, colors, and UV coordinates if these are used.
	 * \return The number of vertices that make up this mesh.
	 * \sa IShapeData::SetVertexCount
	 */
	int GetVertexCount() const { return int(vertices.size()); }

	/*! Returns the number of texture coordinate sets used by this mesh.  For each UV set, there is a pair of texture coordinates for every vertex in the mesh.  Each set corresponds to a texture entry in the NiTexturingPropery block.
	 * \return The number of texture cooridnate sets used by this mesh.  Can be zero.
	 * \sa IShapeData::SetUVSetCount, ITexturingProperty
	 */
	short GetUVSetCount() const { return short(uv_sets.size()); }

	/*! Changes the number of vertices used by this mesh.  If the mesh already contains data, it will be retained so long as the new number is higher than the old number.  Otherwise any verticies above the new number will be deleted.  This also resizes any normal, color, or UV data associated with these verticies.  Triangles and triangle strips that may be attached via other interfaces are not culled of references to newly invalid vertices, however.
	 * \param n The new size of the vertex array.
	 * \sa IShapeData::GetVertexCount
	 */
	void SetVertexCount(int n);

	/*! Changes the number of UV sets used by this mesh.  If he new size is smaller, data at the end of the array will be lost.  Otherwise it will be retained.  The number of UV sets must correspond with the number of textures defined in the corresponding NiTexturingProperty block.
	 * \param n The new size of the uv set array.
	 * \sa IShapeData::GetUVSetCount, ITexturingProperty
	 */
	void SetUVSetCount(int n);

	//--Getters--//

	/*! Used to retrive the vertices used by this mesh.  The size of the vector will be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the vertices used by this mesh.
	 * \sa IShapeData::SetVertices, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	vector<Vector3> GetVertices() const { return vertices; }

	/*! Used to retrive the normals used by this mesh.  The size of the vector will either be zero if no normals are used, or be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the normals used by this mesh, if any.
	 * \sa IShapeData::SetNormals, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	vector<Vector3> GetNormals() const { return normals; }

	/*! Used to retrive the vertex colors used by this mesh.  The size of the vector will either be zero if no vertex colors are used, or be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the vertex colors used by this mesh, if any.
	 * \sa IShapeData::SetColors, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	vector<Color4> GetColors() const { return colors; }

	/*! Used to retrive the texture coordinates from one of the texture sets used by this mesh.  The function will throw an exception if a texture set index that does not exist is specified.  The size of the vector will be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \param index The index of the texture coordinate set to retrieve the texture coordinates from.  This index is zero based and must be a positive number smaller than that returned by the IShapeData::GetUVSetCount function.  If there are no texture coordinate sets, this function will throw an exception.
	 * \return A vector cntaining the the texture coordinates used by the requested texture coordinate set.
	 * \sa IShapeData::SetUVSet, IShapeData::GetUVSetCount, IShapeData::SetUVSetCount, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	vector<TexCoord> GetUVSet( int index ) const { return uv_sets[index]; }
	
//--Setters--//

	/*! Used to set the vertex data used by this mesh.  The size of the vector must be the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the vertices to replace those in the mesh with.  Note that there is no way to set vertices one at a time, they must be sent in one batch.
	 * \sa IShapeData::GetVertices, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	void SetVertices( const vector<Vector3> & in );

	/*! Used to set the normal data used by this mesh.  The size of the vector must either be zero, or the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the normals to replace those in the mesh with.  Note that there is no way to set normals one at a time, they must be sent in one batch.  Use an empty vector to signify that this mesh will not be using normals.
	 * \sa IShapeData::GetNormals, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	void SetNormals( const vector<Vector3> & in );

	/*! Used to set the vertex color data used by this mesh.  The size of the vector must either be zero, or the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the vertex colors to replace those in the mesh with.  Note that there is no way to set vertex colors one at a time, they must be sent in one batch.  Use an empty vector to signify that this mesh will not be using vertex colors.
	 * \sa IShapeData::GetColors, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	void SetColors( const vector<Color4> & in );

	/*! Used to set the texture coordinate data from one of the texture sets used by this mesh.  The function will throw an exception if a texture set index that does not exist is specified.  The size of the vector must be the same as the vertex count retrieved with the IShapeData::GetVertexCount function, or the function will throw an exception.
	 * \param index The index of the texture coordinate set to retrieve the texture coordinates from.  This index is zero based and must be a positive number smaller than that returned by the IShapeData::GetUVSetCount function.  If there are no texture coordinate sets, this function will throw an exception.
	 * \param in A vector containing the the new texture coordinates to replace those in the requested texture coordinate set.
	 * \sa IShapeData::GetUVSet, IShapeData::GetUVSetCount, IShapeData::SetUVSetCount, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
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
		//AddAttr( attr_link, "Modifier" );
		//AddAttr( attr_linkgroup, "Unknown Link Group", VER_10_2_0_0 );
		//AddAttr( attr_link, "Unknown Link 2", VER_10_2_0_0 );
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
		//AddAttr( attr_link, "Unknown Link 2" );
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
class NiTriShapeData : public AShapeData {
public:
	NiTriShapeData() : match_group_mode(false) {}
	~NiTriShapeData() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiTriShapeData"; }

	//--ITriShapeData--//

	//--Match Detection--//

	/*! Used to turn match detection mode on and off.  When match detection mode is on, a list of all the vertices that have identical positions are stored in the file.  This may improve performance but is not well understood.
	 * \param choice True to enable match detection mode, false to disable it.
	 * \sa ITriShapeData::GetMatchDetectionMode
	 */
	void SetMatchDetectionMode(bool choice) { match_group_mode = choice; }

	/*! Used to query the current match detection mode.  When match detection mode is on, a list of all the vertices that have identical positions are stored in the file.  This may improve performance but is not well understood.
	 * \return True if match detection mode is on, false otherwise.
	 * \sa ITriShapeData::GetMatchDetectionMode
	 */
	bool GetMatchDetectionMode() const { return match_group_mode; }

	//--Getters--//

	/*! Returns the triangle faces that make up this mesh.
	 * \return A vector containing the triangle faces that make up this mesh.
	 * \sa ITriShapeData::SetTriangles
	 */
	vector<Triangle> GetTriangles() const { return triangles; }

	//--Setters--//

	/*! Replaces the triangle face data in this mesh with new data.
	 * \param in A vector containing the new face data.  Maximum size is 65,535.
	 * \sa ITriShapeData::GetTriangles
	 */
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
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiTriStripsData"; }

	//--Counts--//

	/*! Used to get the number of triangle strips that this mesh is divided into.
	 * \return The number of triangle strips used by this mesh.
	 * \sa ITriStripData::SetStripCount
	 */
	short GetStripCount() const;

	/*! Used to resize the triangle strips array.  If the new size is smaller, strips at the end of the array will be deleted.
	 * \param n The new size of the triangle strips array.
	 * \sa ITriStripData::GetStripCount
	 */
	void SetStripCount(int n);
	
	//--Getters--//

	/*! Used to retrieve all the triangles from a specific triangle strip.
	 * \param index The index of the triangle strip to retrieve the triangles from.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
	 * \return A vector containing all the triangle faces from the triangle strip specified by index.
	 * \sa ITriStripsData::SetStrip, ITriStripsData::GetTriangles
	 */
	vector<short> GetStrip( int index ) const;

	/*! This is a conveniance function which returns all triangle faces in all triangle strips that make up this mesh.  It is similar to the ITriShapeData::GetTriangles function.
	 * \return A vector containing all the triangle faces from all the triangle strips that make up this mesh.
	 * \sa ITriShapeData::GetTriangles, ITriStripsData::GetStrip, ITriStripsData::SetStrip
	 */
	vector<Triangle> GetTriangles() const;

	//--Setter--/

	/*! Used to set the triangle face data in a specific triangle strip.
	 * \param index The index of the triangle strip to set the face data for.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
	 * \sa ITriStripsData::GetStrip, ITriStripsData::GetTriangles
	 */
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
	NiBSplineBasisData() { 
		//AddAttr( attr_int, "Unknown Int" );
	}
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

class NiPSysPlanarCollider : public NiObject {
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

class AKeyframeData : public AData {

public:

	AKeyframeData() {}
	~AKeyframeData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "AKeyframeData"; }

	//--Rotate--//

	/*! Retrieves the type of rotation interpolation being used.
		* \return The rotation key type specifing the type of interpolation being used.
		* \sa IKeyframeData::SetRotateType
		*/
	KeyType GetRotateType() const { return rotationType; }

	/*! Sets the type of rotation interpolation being used.  Does not affect existing key data.
	 * \param t The new rotation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetRotateType
	 */
	void SetRotateType( KeyType t ) { rotationType = t; }

	/*! Retrieves the rotation key data.
	 * \return A vector containing Key<Quaternion> data which specify rotation over time.
	 * \sa IKeyframeData::SetRotateKeys, Key
	 */
	vector< Key<Quaternion> > GetRotateKeys() const { return rotKeys; }

	/*! Sets the rotation key data.
	 * \param keys A vector containing new Key<Quaternion> data which will replace any existing data.
	 * \sa IKeyframeData::GetRotateKeys, Key
	 */
	void SetRotateKeys( const vector< Key<Quaternion> > & keys ) { rotKeys = keys; }

	//--Translate--//

	/*! Retrieves the type of translation interpolation being used.
	 * \return The translation key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetTranslateType
	 */
	KeyType GetTranslateType() const { return translationType; }

	/*! Sets the type of translation interpolation being used.  Does not affect existing key data.
	 * \param t The new translation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetTranslateType
	 */
	void SetTranslateType( KeyType t ) { translationType = t; }

	/*! Retrieves the translation key data.
	 * \return A vector containing Key<Vector3> data which specify translation over time.
	 * \sa IKeyframeData::SetTranslateKeys, Key
	 */
	vector< Key<Vector3> > GetTranslateKeys() const { return transKeys; }

	/*! Sets the translation key data.
	 * \param keys A vector containing new Key<Vector3> data which will replace any existing data.
	 * \sa IKeyframeData::GetTranslateKeys, Key
	 */
	void SetTranslateKeys( vector< Key<Vector3> > const & keys ) { transKeys = keys; }

	//--Scale--//

	/*! Retrieves the type of scale interpolation being used.
	 * \return The scale key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetTranslateType
	 */
	KeyType GetScaleType() const { return scaleType; }

	/*! Sets the type of scale interpolation being used.  Does not affect existing key data.
	 * \param t The new scale key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetScaleType
	 */
	void SetScaleType( KeyType t ) { scaleType = t; }

	/*! Retrieves the scale key data.
	 * \return A vector containing Key<float> data which specify scale over time.
	 * \sa IKeyframeData::SetScaleKeys, Key
	 */
	vector< Key<float> > GetScaleKeys() const { return scaleKeys; }

	/*! Sets the scale key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa IKeyframeData::GetScaleKeys, Key
	 */
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
 * NiPalette object.  Contains a color palette for internally stored paletized textures.
 */
class NiPalette : public AData {
public:
	NiPalette() {}
	void Init() {}
	~NiPalette() {}
	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiPalette"; }

	/*! Retrieves the palette data from this palette block.
	 * \return A vector containing the the colors stored in the palette.
	 * \sa IPalette::SetPalette
	 */
	vector<Color4> GetPalette() const;

	/*! Sets the palette data for this palette block.
	 * \param new_apl A vector containing the the new colors to be stored in the palette.
	 * \sa IPalette::GetPalette
	 */
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
	NiStringPalette() { 
		//AddAttr( attr_string, "Palette" ); 
	}
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

class NiSkinInstance : public AData {
public:
	NiSkinInstance(){
		//AddAttr( attr_link, "Data" );
		//AddAttr( attr_link, "Skin Partition", VER_10_2_0_0 );
		//AddAttr( attr_skeletonroot, "Skeleton Root" );
		//AddAttr( attr_bones, "Bones" );
	}
	~NiSkinInstance() {}
	string GetBlockType() const { return "NiSkinInstance"; }

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

class NiSkinData : public AData {

public:

	NiSkinData() { 
		//AddAttr( attr_link, "Skin Partition", 0, VER_10_1_0_0 );
		rotation = Matrix33::IDENTITY;
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

	//IBlockInternal
	void FixLinks( const vector<blk_ref> & blocks ); // This version of the function will copy the bones from the parent Skin Instance block and fix the links at the same time.
	void RemoveCrossLink( IBlock * block_to_remove );

	//ISkinDataInternal
	void RepositionTriShape( blk_ref & tri_shape );

	/*! Used to retrieve a list of all the bones that influence this skin
		* \return A vector containing references to all the node blocks which act as bone influences on this skin.
		* \sa ISkinData::AddBone, ISkinData::RemoveBone, ISkinData::GetWeights
		*/
	vector<blk_ref> GetBones() const;

	/*! Used to retrieve the skin weights associated with a specific bone
		* \param bone A blk_ref pointing to one of the node blocks which acts as a bone influence on this skin that's related weights are to be retrieved.
		* \return A map of ints to floats.  The integers are the vertex number and the floats are the percentage influence (between 0.0 and 1.0) that the specified bone has on that vertex.  Not all vertices will be influenced by all bones.
		* \sa ISkinData::GetBones, ISkinData::AddBone, ISkinData::RemoveBone
		*/
	map<int, float> GetWeights( const blk_ref & bone ) const;

	/*! Adds a new bone influence to this skin alone with all its weight information.  If a bone that already influences the skin is specified, the weight data will be overwritten.
	 * \param bone A blk_ref pointing to a node blocks which is to be added as a bone influence on this skin.
	 * \param in A map of ints to floats.  The integers are the vertex number and the floats are the percentage influence (between 0.0 and 1.0) that the specified bone has on that vertex.  Not all vertices need to be influenced by all bones.
	 * \sa ISkinData::RemoveBone, ISkinData::GetBones, ISkinData::GetWeights
	 */
	void AddBone( const blk_ref & bone, map<int, float> const & in );

	/*! Removes a bone influence and deletes associated vertex weight information.
	 * \param bone A blk_ref pointing to a node blocks which is to be removed as a bone influence on this skin.
	 * \sa ISkinData::AddBone, ISkinData::GetBones
	 */
	void RemoveBone( const blk_ref & bone );

	void ReassignCrossRefs( const map<string,blk_ref> & name_map );
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

/*! Contain an array of bool keys. */
class NiBoolData : public AData {
public:
	NiBoolData() {}
	~NiBoolData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiBoolData"; };

	/*! Retrieves the type of boolean interpolation being used.
	 * \return The boolean key type specifing the type of interpolation being used.
	 * \sa IBoolData::SetKeyType
	 */
	KeyType GetKeyType() const { return _type; }

	/*! Sets the type of boolean interpolation being used.  Does not affect existing key data.
	 * \param t The new boolean key type specifing the type of interpolation to be used.
	 * \sa IBoolData::GetKeyType
	 */
	void SetKeyType( KeyType t ) { _type = t; }

	/*! Retrieves the boolean key data.
	 * \return A vector containing Key<unsigned char> data which specify boolean values over time.
	 * \sa IBoolData::SetKeys, Key
	 */
	vector< Key<unsigned char> > GetKeys() const { return _keys; }

	/*! Sets the boolean key data.
	 * \param keys A vector containing new Key<unsigned char> data which will replace any existing data.
	 * \sa IBoolData::GetKeys, Key
	 */
	void SetKeys( vector< Key<unsigned char> > const & keys ) { _keys = keys; }

private:
	KeyType _type;
	vector< Key<byte> > _keys;
};

/*! Contains an array of color keys. */
class NiColorData : public AData {
public:
	NiColorData() {}
	~NiColorData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiColorData"; };

	/*! Retrieves the type of color interpolation being used.
	 * \return The color key type specifing the type of interpolation being used.
	 * \sa IColorData::SetKeyType
	 */
	KeyType GetKeyType() const { return _type; }

	/*! Sets the type of color interpolation being used.  Does not affect existing key data.
	 * \param t The new color key type specifing the type of interpolation to be used.
	 * \sa IColorData::GetKeyType
	 */
	void SetKeyType( KeyType t ) { _type = t; }

	/*! Retrieves the color key data.
	 * \return A vector containing Key<Color4> data which specify color over time.
	 * \sa IColorData::SetKeys, Key
	 */
	vector< Key<Color4> > GetKeys() const { return _keys; }

	/*! Sets the color key data.
	 * \param keys A vector containing new Key<Color4> data which will replace any existing data.
	 * \sa IColorData::GetKeys, Key
	 */
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
		//AddAttr( attr_string, "Name" );
		//AddAttr( attr_link, "String Palette", VER_10_2_0_0 );
	}
	~NiControllerSequence();

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;

	string GetBlockType() const { return "NiControllerSequence"; }

	void FixLinks( const vector<blk_ref> & blocks );
	list<blk_ref> GetLinks() const;

	/*! Sets the name and block reference to the NiTextKeyExtraData block which will be used by this controller sequence to specify the keyframe labels or "notes."
	 * \param new_name The name of the NiTextKeyExtraData block to use.
	 * \param new_link The block reference of the NiTextKeyExtraData block to use.
	 * \sa ITextKeyExtraData
	 */
	void SetTextKey( string new_name, blk_ref new_link );

	/*! Sets the name, block reference, and controller type to use as a new child to this Kf root node.  The controller type is unnecessary before version 10.2.0.0.  From that version on, these children must be interpolators.  Before that version they will be keyframe controllers.
	 * \param new_name The name to re-link this Kf file child to when it is merged with a Nif file.
	 * \param new_link The block reference of the new Kf file child.
	 * \param controller_type The original controller type that this Kf file child was connected to.  Only applies to versions which use interpolators.
	 * \sa IControllerSequence::ClearKfChildren
	 */
	void AddKfChild( string new_name, blk_ref new_link, string controller_type);

	/*! Removes all Kf file children from this Kf file root block.
	 * \sa IControllerSequence::AddKfChild
	 */
	void ClearKfChildren();
private:
	string GetSubStr( const string & pal, short offset ) const;

	struct KfChild {
		blk_ref block;
		string name;
		blk_ref unk_link;
		short name_offset;
		short property_offset;
		short controller_offset;
		short var1_offset;
		short var2_offset;
		short unk_short1, unk_short2, unk_short3, unk_short4, unk_short5;
		KfChild() : block(), name(), unk_link(),
		name_offset(-1), controller_offset(-1), property_offset(-1), var1_offset(-1), var2_offset(-1),
		unk_short1(0), unk_short2(0), unk_short3(0), unk_short4(0), unk_short5(0) {};
	};
	string txt_key_name;
	blk_ref txt_key_blk;
	vector< KfChild > children;

	uint unk_int1, unk_int2;
	float unk_float1, unk_float2, unk_4_floats[4];
	string unk_string;
};

/* Contains an array of float keys. */
class NiFloatData : public AData {
public:
	NiFloatData() {}
	~NiFloatData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiFloatData"; };

	/*! Retrieves the type of float interpolation being used.
	 * \return The float key type specifing the type of interpolation being used.
	 * \sa IFloatData::SetKeyType
	 */
	KeyType GetKeyType() const { return _type; }

	/*! Sets the type of float interpolation being used.  Does not affect existing key data.
	 * \param t The new float key type specifing the type of interpolation to be used.
	 * \sa IFloatData::GetKeyType
	 */
	void SetKeyType( KeyType t ) { _type = t; }

	/*! Retrieves the float key data.
	 * \return A vector containing Key<float> data which specify float values over time.
	 * \sa IFloatData::SetKeys, Key
	 */
	vector< Key<float> > GetKeys() const { return _keys; }

	/*! Sets the float key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa IFloatData::GetKeys, Key
	 */
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
		//AddAttr( attr_string, "String Data" );
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
		//AddAttr( attr_byte, "Boolean Data" );
	}
	~NiBooleanExtraData() {}
	string GetBlockType() const { return "NiBooleanExtraData"; };

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		//GetAttr("Boolean Data")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		AExtraData::Write( out, version );
		//GetAttr("Boolean Data")->Write( out, version );
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
		//AddAttr( attr_vector3, "Vector Data" );
		//AddAttr( attr_float, "Unknown Float" );
	}
	~NiVectorExtraData() {}
	string GetBlockType() const { return "NiVectorExtraData"; };

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		//GetAttr("Vector Data")->Read( in, version );
		//GetAttr("Unknown Float")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		//GetAttr("Vector Data")->Write( out, version );
		//GetAttr("Unknown Float")->Write( out, version );
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
		//AddAttr( attr_float, "Float Data" );
	}
	~NiFloatExtraData() {}
	string GetBlockType() const { return "NiFloatExtraData"; };

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		//GetAttr("Float Data")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		AExtraData::Write( out, version );
		//GetAttr("Float Data")->Write( out, version );
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
		//AddAttr( attr_int, "Integer Data" );
	}
	~NiIntegerExtraData() {}

	string GetBlockType() const { return "NiIntegerExtraData"; };

	void Read( istream& in, unsigned int version ) {
		AExtraData::Read( in, version );
		//GetAttr("Integer Data")->Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		AExtraData::Write( out, version );
		//GetAttr("Integer Data")->Write( out, version );
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

/*! Contains morphing animation data. */
class NiMorphData : public AData {
public:
	NiMorphData() {
		//AddAttr( attr_byte, "Unknown Byte" );
	}
	~NiMorphData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiMorphData"; };

	/*! Retrieves the number of verticies used in the morph targets.  This must be the same as the number of verticies in the base mesh that the morph controller for which this block stores data is attatched.  This is not done automatically by Niflib.
	 * \return The number of vertices used in the morph target meshes.
	 * \sa IMorphData::SetVertexCount
	 */
	int GetVertexCount() const { return vertCount; }

	/*! Sets the number of verticies used in the morph targets.  This must be the same as the number of verticies in the base mesh that the morph controller for which this block stores data is attatched.  This is not done automatically by Niflib.  If the new size is smaller, vertices at the ends of the morph targets will be lost.
	 * \param n The new size of the morph target's vertex arrays.
	 * \sa IMorphData::GetVertexCount
	 */
	void SetVertexCount( int n );

	/*! Retrieves the number of morph targets used by this morph controller data.
	 * \return The number of morph targets used by this morph controller data.
	 * \sa IMorphData::SetMorphCount
	 */
	int GetMorphCount() const { return int(morphs.size()); }

	/*! Resizes the morph target array used by this morph controller data.  If the new size is smaller, morph targets at the end of the array and all associated data will be lost.
	 * \param n The new size of the morph target array.
	 * \sa IMorphData::GetMorphCount
	 */
	void SetMorphCount( int n ) { morphs.resize( n ); }

	/*! Retrieves the type of morph interpolation being used by a specific morph target.
	 * \param n The index of the morph to get the interpolation key type from.  A zero-based positive value which must be less than that returned by IMoprhData::GetMorphCount.
	 * \return The morph key type specifing the type of interpolation being used by the specified morph target.
	 * \sa IMorphData::SetMorphKeyType
	 */
	KeyType GetMorphKeyType( int n ) const { return morphs[n]._type; }
	
	/*! Sets the type of morph interpolation being used by a specific morph target.  Does not affect existing key data.
	 * \param n The index of the morph to get the interpolation key type from.  A zero-based positive value which must be less than that returned by IMoprhData::GetMorphCount.
	 * \param t The new morph key type specifing the type of interpolation to be used by the specified morph target.
	 * \sa IMorphData::GetMorphKeyType
	 */
	void SetMorphKeyType( int n, KeyType t ) { morphs[n]._type = t; }

	/*! Retrieves the morph key data for a specified morph target.
	 * \return A vector containing Key<float> data which specify the influence of this morph target over time.
	 * \sa IMorphData::SetMorphKeys, Key
	 */
	vector< Key<float> > GetMorphKeys( int n ) const { return morphs[n].keys; }

	/*! Sets the morph key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data for this morph target.
	 * \sa IMorphData::GetMorphKeys, Key
	 */
	void SetMorphKeys( int n, vector< Key<float> > const & keys ) { morphs[n].keys = keys; }

	/*! Retrieves the vertex data from the specified morph target
	 * \param n The index of the morph target to retrieve vertex data for.  This is a zero-based index whoes value that must be less than that returned by IMorphData::GetMorphCount.
	 * \return A vector containing the vertices used by this morph target.  The size will be equal to the value returned by IMorphData::GetVertexCount.
	 * \sa IMorphData::SetMorphVerts
	 */
	vector<Vector3> GetMorphVerts( int n) const { return morphs[n].morph; }

	/*! Sets the vertex data for a specified morph target
	 * \param n The index of the morph target to set vertex data for.  This is a zero-based index whoes value that must be less than that returned by IMorphData::GetMorphCount.
	 * \param in A vector containing the new vertices to be used by this morph target.  The size will be equal to the value returned by IMorphData::GetVertexCount.
	 * \sa IMorphData::SetMorphVerts
	 */
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

/*! Contains an array of position keys. */
class NiPosData : public AData {
public:
	NiPosData() {}
	~NiPosData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiPosData"; }

	/*! Retrieves the type of position interpolation being used.
	 * \return The position key type specifing the type of interpolation being used.
	 * \sa IPosData::SetKeyType
	 */
	KeyType GetKeyType() const { return _type; }

	/*! Sets the type of position interpolation being used.  Does not affect existing key data.
	 * \param t The new position key type specifing the type of interpolation to be used.
	 * \sa IPosData::GetKeyType
	 */
	void SetKeyType( KeyType t ) { _type = t; }

	/*! Retrieves the position key data.
	 * \return A vector containing Key<Vector3> data which specify position over time.
	 * \sa IPosData::SetKeys, Key
	 */
	vector< Key<Vector3> > GetKeys() const { return _keys; }

	/*! Sets the position key data.
	 * \param keys A vector containing new Key<Vector3> data which will replace any existing data.
	 * \sa IPosData::GetKeys, Key
	 */
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

/*! Holds a list of textual notes and at which time they take effect which are used for designating the start and stop of animations and the triggering of sounds. */
class NiTextKeyExtraData : public AExtraData {
public:
	NiTextKeyExtraData() {
		//AddAttr( attr_int, "Unknown Int", 0, VER_4_2_2_0 );
	}
	~NiTextKeyExtraData() {}

	void Read( istream& in, unsigned int version );
	void Write( ostream& out, unsigned int version ) const;
	string asString() const;
	string GetBlockType() const { return "NiTextKeyExtraData"; }

	//--ITextKeyExtraData Functions--//
	
	/*! Retrieves the text note key data.
	 * \return A vector containing Key<string> data which specify text note over time.
	 * \sa IKeyframeData::SetKeys, Key
	 */
	virtual vector< Key<string> > GetKeys() const { return _keys; }

	/*! Sets the text note key data.
	 * \param keys A vector containing new Key<string> data which will replace any existing data.
	 * \sa IKeyframeData::GetKeys, Key
	 */
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

class UnknownBlock : public NiObject, public UnknownMixIn {
public:
	UnknownBlock( string block_type ) : UnknownMixIn(block_type) {}
	~UnknownBlock() {}
	void Read( istream& in, unsigned int version ) {
		//cout << endl << "Unknown Block Type found:  " << GetBlockType() << "\a" << endl;
		NiObject::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		NiObject::Write( out, version );
		UnknownMixIn::Write( out, version );
	}
	void asString( ostream & out ) {
		out << NiObject::asString();
		out << UnknownMixIn::asString();
	}
	string GetBlockType() const { return UnknownMixIn::GetBlockType(); }
};

class UnknownControllerBlock : public AController, public UnknownMixIn {
public:
	UnknownControllerBlock( string block_type ) : UnknownMixIn(block_type) {}
	~UnknownControllerBlock() {}
	void Read( istream& in, unsigned int version ) {
		NiObject::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		NiObject::Write( out, version );
		UnknownMixIn::Write( out, version );
	}
	string asString() {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << NiObject::asString();
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
		NiObject::Read( in, version );
		UnknownMixIn::Read( in, version );
	}
	void Write( ostream& out, unsigned int version ) const {
		NiObject::Write( out, version );
		UnknownMixIn::Write( out, version );
	}
	string asString() {
		stringstream out;
		out.setf(ios::fixed, ios::floatfield);
		out << setprecision(1);

		out << NiObject::asString();
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
