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

#ifndef _NIFLIB_H_
#define _NIFLIB_H_

//--Includes--//
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <list>
#include <map>
using namespace std;

//--Forward Declarations of Classes & Structs--//
class IAttr;
class IBlock;
class IShapeData;
class ITriShapeData;
class ISkinData;
class IKeyframeData;
class ITextKeyExtraData;
class IMorphData;
class ITriStripsData;
class IColorData;
class IFloatData;
class IPosData;
class INode;
class blk_ref;
class attr_ref;
struct blk_link;
struct Texture;
struct TextureSource;
struct BoundingBox;
struct ConditionalInt;
struct SkinWeight;

//--Constants--//

//Interface IDs
const int ID_TRI_SHAPE_DATA = 0; /*!< ID for ITriShapeData Interface */  
const int ID_SKIN_DATA = 1; /*!< ID for ISkinData Interface */ 
const int ID_NODE = 2; /*!< ID for INode Interface */ 
const int ID_KEYFRAME_DATA = 3; /*!< ID for IKeyframeData Interface */ 
const int ID_TEXT_KEY_EXTRA_DATA = 4; /*!< ID for ITextKeyExtraData Interface */ 
const int ID_MORPH_DATA = 5; /*!< ID for IMorphData Interface */ 
const int ID_SHAPE_DATA = 6; /*!< ID for IShapeData Interface */ 
const int ID_TRI_STRIPS_DATA = 7; /*!< ID for ITriStripsData Interface */ 
const int ID_COLOR_DATA = 8; /*!< ID for IColorData Interface */ 
const int ID_FLOAT_DATA = 9; /*!< ID for IFloatData Interface */ 
const int ID_POS_DATA = 10; /*!< ID for IPosData Interface */ 

//!  Attribute types
/*!
  This enum contains all the attribute types used by Niflib.
*/
enum AttrType {
	attr_int, /*!< Integer Attribute.  Holds a 32-bit integer. */  
	attr_short, /*!< Short Integer Attribute.  Holds a 16-bit integer. */ 
	attr_byte, /*!< Byte Attribute.  Holds an 8-bit integer. */ 
	attr_float, /*!< Float Attribute.  Holds a 32-bit floating point number. */ 
	attr_float3, /*!< Float3 Attribute.  Holds a Float3 structure. */ 
	attr_string, /*!< String Attribute.  Holds a text string. */ 
	attr_link, /*!< Link Attribute.  Links to one other Nif block lower in the Nif tree. */ 
	attr_flags, /*!< Flags Attribute.  Holds a set of 16 bit flags whos function depends on the block that uses them. */ 
	attr_matrix33, /*!< Matrix33 Attribute.  Holds a Matrix33 structure. */ 
	attr_linkgroup, /*!< Link Group Attribute.  Links to several other Nif blocks lower in the Nif tree. */ 
	attr_bones, /*!< Bones Attribute.  Automatic. */ 
	attr_bbox, /*!< Bounding Box Attribute.  Holds a BoundingBox structure. */ 
	attr_condint, /*!< Conditional Integer Attribute.  Holds a ConditionalInt structure. */ 
	attr_vertmode, /*!< Vertex Mode Attribute.  Holds an integer that corresponds to the vertex mode. */ 
	attr_lightmode, /*!< Light Mode Attribute.  Holds an integer that corresponds to the light mode. */ 
	attr_texture, /*!< Texture Attribute.  Holds a Texture structure but ignores the bump map information. */ 
	attr_bumpmap, /*!< Bump Map Atrribute  Holds a Texture structure and uses the bump map information. */ 
	attr_applymode, /*!< Apply Mode Attribute.  Holds an integer that corresponds to the apply mode. */ 
	attr_texsource, /*!< Texture Source Attribute.  Holds a Texture Source structure. */ 
	attr_pixellayout, /*!< Light Mode Attribute.  Holds an integer that corresponds to the light mode. */ 
	attr_mipmapformat, /*!< Mipmap Format Attribute.  Holds an integer that corresponds to the mipmap format. */ 
	attr_alphaformat, /*!< Alpha Format Attribute.  Holds an integer that corresponds to the alpha format. */ 
	attr_controllertarget, /*!< Controller Target Attribute.  Automatic. */ 
	attr_skeletonroot, /*!< Skeleton Root Attribute.  Automatic. */ 
	attr_particlegroup, /*!< Particle Group Attribute. */ 
	attr_lodrangegroup, /*!< Level of Detail Range Group Attribute. */ 
	attr_vector3, /*!< Vector3 Attribute.  Holds a Float3 structure that corresponds to a vector in 3D space. */ 
	attr_color3, /*!< Color3 Attribute.  Holds a Float3 structure that corresponds to an RGB color. */ 
	attr_parent /*!< Parent Attribute.  Automatic. */ 
};

//NIF Versions
const unsigned int VER_4_0_0_2 = 0x04000002; /*!< Nif Version 4.0.0.2 */ 
const unsigned int VER_4_1_0_12 = 0x0401000C; /*!< Nif Version 4.1.0.12 */ 
const unsigned int VER_4_2_0_2 = 0x04020002; /*!< Nif Version 4.2.0.2 */ 
const unsigned int VER_4_2_1_0 = 0x04020100; /*!< Nif Version 4.2.1.0 */ 
const unsigned int VER_4_2_2_0 = 0x04020200; /*!< Nif Version 4.2.2.0 */ 
const unsigned int VER_10_0_1_0 = 0x0A000100; /*!< Nif Version 10.0.1.0 */ 
const unsigned int VER_10_1_0_0 = 0x0A010000; /*!< Nif Version 10.1.0.0 */ 
const unsigned int VER_10_2_0_0 = 0x0A020000; /*!< Nif Version 10.2.0.0 */ 
const unsigned int VER_20_0_0_4 = 0x14000004; /*!< Nif Version 20.0.0.4 */ 

#ifndef NULL
#define NULL 0
#endif

//!  Key Types
/*!
  This enum contains all the animation key types used by Niflib.
*/
enum KeyType {
	LINEAR_KEY = 1, /*!< Use linear interpolation. */ 
	QUADRATIC_KEY = 2, /*!< Use quadratic interpolation.  Forward and back tangents will be stored.*/ 
	TBC_KEY = 3, /*!< Use Tension Bias Continuity interpolation.  Tension, bias, and continuity will be stored.*/ 
	XYZ_ROTATION_KEY = 4 /*!< For use only with rotation data.  Separate X, Y, and Z keys will be stored instead of using quaternions. */ 
};

//--Main Functions--//

/*!
Reads the given file by file name and returns a vector of block references
\param file_name The name of the file to load, or the complete path if it is not in the working directory.
\return A vector of block references that point to all the blocks read from the Nif file.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifList("test_in.nif");
\endcode

<b>In Python:</b>
\code
my_block = ReadNifList("test_in.nif")
\endcode

\sa ReadNifTree, WriteNifTree
*/
vector<blk_ref> ReadNifList( string const & file_name );

/*!
Reads the given file by file name and returns a reference to the root block.
\param file_name The name of the file to load, or the complete path if it is not in the working directory.
\return A block reference that points to the root of tree of data blocks contained in the NIF file.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
\endcode

\sa ReadNifList, WriteNifTree
*/
blk_ref ReadNifTree( string const & file_name );

/*!
Creates a new NIF file of the given file name by crawling through the data tree starting with the root block given.  Automatically writes a kf file and an x/nif file if animation is present.
\param file_name The desired file name for the new NIF file.  The path is relative to the working directory unless a full path is specified.
\param root_block The root block to start from when writing out the NIF file.  All decedents of this block will be written to the file in tree-descending order.
\param version The version of the NIF format to use when writing a file.  Default is version 4.0.0.2.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
WriteNifTree( "test_out.nif", my_block );
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
WriteNifTree( "test_out.nif", my_block )
\endcode

\sa ReadNifList, WriteNifTree
*/
void WriteNifTree( string const & file_name, blk_ref const & root_block, unsigned int version = VER_4_0_0_2 );

//// Returns list of all blocks in the tree rooted by root block.
//list<blk_ref> GetNifTree( blk_ref const & root_block );

////Returns the NIF spec version of a file, given a file name.
//string GetFileVersion(string file_name);

//... yes it uses a global right now <sigh>
/*!
Sets whether data/hex areas are shown by asString functions
\param val A boolean value that specifies whether verbose mode should be turned on.  True = Verbose, False = Brief.

<b>Example:</b> 
\code
SetVerboseMode(true);
\endcode

<b>In Python:</b>
\code
SetVerboseMode(True)
\endcode

\sa IBlock::asString, IAttr::asString
*/
void SetVerboseMode( bool val );

/*!
Creates a new block of the given type and returns a reference to it
\param block_type – The type of block you want to create.  This value is case sensitive and spelling is important.  Ex. NiNode, NiTriShapeData, NiParticleSystemController, etc.
\return This function will return a newly created block of the requested type.  Beware, if the block type is unrecognized, this function will return a featureless block with whatever you sent it as the type.

<b>Example:</b> 
\code
blk_ref my_block = CreateBlock("NiNode");
\endcode

<b>In Python:</b>
\code
my_block = CreateBlock("NiNode")
\endcode

\sa BlocksInMemory
*/
blk_ref CreateBlock( string block_type );

/*!
Returns the current total number of blocks in memory.
\return Returns the number of blocks currently in memory.  This includes both blocks loading from nif files and blocks created by the user.  Reference counting is used to ensure that multiple copies of the same block are not created, and blocks that are no longer being used are automatically freed.

<b>Example:</b> 
\code
unsigned int block_count = BlocksInMemory();
\endcode

<b>In Python:</b>
\code
block_count = BlocksInMemory()
\endcode

\sa CreateBlock
*/
//Retrns total number of blocks in memory
unsigned int BlocksInMemory();

//--Query Functions--//
// These are shorthands for using QueryInterface, and required for scripting languages

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_SHAPE_DATA ).  It queries the block for an IShapeData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IShapeData interface available.
\param block The block to query the interface from.
\return If the given block implements the IShapeData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
IShapeData * shape_data = QueryShapeData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
shape_data = QueryShapeData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
IShapeData * QueryShapeData( blk_ref & block );
IShapeData const * QueryShapeData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_TRI_SHAPE_DATA ).  It queries the block for an ITriShapeData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ITriShapeData interface available.
\param block The block to query the interface from.
\return If the given block implements the ITriShapeData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
ITriShapeData * tri_shape_data = QueryTriShapeData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
tri_shape_data = QueryTriShapeData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
ITriShapeData * QueryTriShapeData( blk_ref & block );
ITriShapeData const * QueryTriShapeData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_SKIN_DATA ).  It queries the block for an ISkinData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ISkinData interface available.
\param block The block to query the interface from.
\return If the given block implements the ISkinData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
ISkinData * skin_data = QuerySkinData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
skin_data = QuerySkinData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
ISkinData * QuerySkinData( blk_ref & block );
ISkinData const * QuerySkinData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_NODE).  It queries the block for an INode interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the INode interface available.
\param block The block to query the interface from.
\return If the given block implements the INode interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
INode * node = QueryNode(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
node = QueryNode(my_block);
\endcode

\sa IBlock::QueryInterface
*/
INode * QueryNode( blk_ref & block );
INode const * QueryNode( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_KEYFRAME_DATA ).  It queries the block for an IKeyframeData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IKeyframeData interface available.
\param block The block to query the interface from.
\return If the given block implements the IKeyframeData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
IKeyframeData * keyframe_data = QueryKeyframeData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
keyframe_data = QueryKeyframeData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
IKeyframeData * QueryKeyframeData( blk_ref & block );
IKeyframeData const * QueryKeyframeData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_TEXT_KEY_EXTRA_DATA ).  It queries the block for an ITextKeyExtraData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ITextKeyExtraData interface available.
\param block The block to query the interface from.
\return If the given block implements the ITextKeyExtraData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
ITextKeyExtraData * text_key_extra_data = QueryTextKeyExtraData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
text_key_extra_data = QueryTextKeyExtraData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
ITextKeyExtraData * QueryTextKeyExtraData ( blk_ref & block );
ITextKeyExtraData const * QueryTextKeyExtraData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_MORPH_DATA ).  It queries the block for an IMorphData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IMorphData interface available.
\param block The block to query the interface from.
\return If the given block implements the IMorphData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
IMorphData * morph_data = QueryMorphData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
morph_data = QueryMorphData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
IMorphData * QueryMorphData ( blk_ref & block );
IMorphData const * QueryMorphData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_TRI_STRIPS_DATA ).  It queries the block for an ITriStripsData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ITriStripsData interface available.
\param block The block to query the interface from.
\return If the given block implements the ITriStripsData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
ITriStripsData * tri_strips_data = QueryTriStripsData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
tri_strips_data = QueryTriStripsData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
ITriStripsData * QueryTriStripsData ( blk_ref & block );
ITriStripsData const * QueryTriStripsData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_COLOR_DATA ).  It queries the block for an IColorData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IColorData interface available.
\param block The block to query the interface from.
\return If the given block implements the IColorData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
IColorData * color_data = QueryColorData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
color_data = QueryColorData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
IColorData * QueryColorData ( blk_ref & block );
IColorData const * QueryColorData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_FLOAT_DATA ).  It queries the block for an IFloatData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IFloatData interface available.
\param block The block to query the interface from.
\return If the given block implements the IFloatData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
IFloatData * float_data = QueryFloatData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
float_data = QueryFloatData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
IFloatData * QueryFloatData ( blk_ref & block );
IFloatData const * QueryFloatData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_POS_DATA ).  It queries the block for an IPosData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IPosData interface available.
\param block The block to query the interface from.
\return If the given block implements the IPosData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.

<b>Example:</b> 
\code
blk_ref my_block = ReadNifTree("test_in.nif");
IPosData * pos_data = QueryPosData(my_block);
\endcode

<b>In Python:</b>
\code
my_block = ReadNifTree("test_in.nif")
pos_data = QueryPosData(my_block);
\endcode

\sa IBlock::QueryInterface
*/
IPosData * QueryPosData ( blk_ref & block );
IPosData const * QueryPosData ( blk_ref const & block );

//--Simple Structures--//

/*! Stores 2D texture coordinates – two floating point variables, u and v. */
struct TexCoord {
	float u; /*!< The U value in this coordinate pair. */ 
	float v; /*!< The V value in this coordinate pair. */ 

	/*! Default constructor	*/
	TexCoord() {}

	/*! This constructor can be used to set all values in this structure during initialization
	\param u The value to set U to.
	\param v The value to set V to.
	*/
	TexCoord(float u, float v) {
		this->u = u;
		this->v = v;
	}

	/*! This function can be used to set all values in the structure at the same time.
	\param u The value to set U to.
	\param v The value to set V to.
	*/
	void Set(float u, float v) {
		this->u = u;
		this->v = v;
	}
};

/*! Represents a triangle face formed between three vertices referenced by number */
struct Triangle {
	short v1; /*!< The index of the first vertex. */ 
	short v2; /*!< The index of the second vertex. */ 
	short v3; /*!< The index of the third vertex. */ 

	/*! Default constructor */
	Triangle() {}

	/*! This constructor can be used to set all values in this structure during initialization
	\param v1 The index of the first vertex.
	\param v2 The index of the second vertex.
	\param v3 The index of the third vertex.
	*/
	Triangle(short v1, short v2, short v3) {
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
	}

	/*! This function can be used to set all values in the structure at the same time.
	\param v1 The index of the first vertex.
	\param v2 The index of the second vertex.
	\param v3 The index of the third vertex.
	*/
	void Set(short v1, short v2, short v3) {
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
	}
};

/*!Represents a position or direction in 3D space*/
struct Vector3 {
	float x; /*!< The X component of this vector. */ 
	float y; /*!< The Y component of this vector. */ 
	float z; /*!< The Z component of this vector. */ 

	/*!Default constructor.*/
	Vector3() {}

	/*! This constructor can be used to set all values in this structure during initialization
	\param x The value to set X to.
	\param y The value to set Y to.
	\param z The value to set Z to.
	*/
	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/*! This function can be used to set all values in the structure at the same time.
	\param x The value to set X to.
	\param y The value to set Y to.
	\param z The value to set Z to.
	*/
	void Set(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

/* Stores two floating point numbers.  Used as a row of a Matrix22 */
struct Float2 {
	float data[2]; /*!< The two floating point numbers stored as an array. */ 
	
	/*! The bracket operator makes it possible to use this structure like a C++ array.
	\param n The index into the data array.  Should be 0 or 1.
	\return The value at the given array index by reference so it can be read or set via the bracket operator.
	*/
	float & operator[](int n) {
		return data[n];
	}
	float operator[](int n) const {
		return data[n];
	}

	/*! Default constructor. */
	Float2() {}

	/*! This constructor can be used to set all values in this structure during initialization
	\param f1 The value to set the first floating point number to.
	\param f2 The value to set the second floating point number to.
	*/
	Float2( float f1, float f2 ) {
		data[0] = f1;
		data[1] = f2;
	}

	/*! This function can be used to set all values in the structure at the same time.
	\param f1 The value to set the first floating point number to.
	\param f2 The value to set the second floating point number to.
	*/
	void Set( float f1, float f2 ) {
		data[0] = f1;
		data[1] = f2;
	}

	//Python Operator Overloads
	float __getitem__(int n) {
		if (n > 1 || n < 0)
			throw std::out_of_range("Index out of range for MatrixRow3");
        return data[n];
    }
	void __setitem__(int n, float value) {
		if (n > 1 || n < 0)
			throw std::out_of_range("Index out of range for MatrixRow3");
		data[n] = value;
	}
};

/*! Stores a 2 by 2 matrix used for bump maps. */
struct Matrix22 {
	Float2 rows[2];  /*!< The two rows of Float2 structures which hold two floating point numbers each. */ 
	
	/*! The bracket operator makes it possible to use this structure like a 2x2 C++ array.
	\param n The index into the row array.  Should be 0 or 1.
	\return The Float2 structure for the given row index by reference so it can be read or set via the bracket operator.
	*/
	Float2 & operator[](int n) {
		return rows[n];
	}
	const Float2 & operator[](int n) const {
		return rows[n];
	}

	/*! Default Constructor */
	Matrix22() {}

	/*! This constructor can be used to set all values in this matrix during initialization
	\param m11 The value to set at row 1, column 1.
	\param m12 The value to set at row 1, column 2.
	\param m21 The value to set at row 2, column 1.
	\param m22 The value to set at row 2, column 2.
	*/
	Matrix22(
		float m11, float m12,
		float m21, float m22
	) {
		rows[0][0] = m11; rows[0][1] = m12;
		rows[1][0] = m21; rows[1][1] = m22;
	}

	/*! This function can be used to set all values in this matrix at the same time.
	\param m11 The value to set at row 1, column 1.
	\param m12 The value to set at row 1, column 2.
	\param m21 The value to set at row 2, column 1.
	\param m22 The value to set at row 2, column 2.
	*/
	void Set(
		float m11, float m12,
		float m21, float m22
	) {
		rows[0][0] = m11; rows[0][1] = m12;
		rows[1][0] = m21; rows[1][1] = m22;
	}

	//Python Operator Overloads
	Float2 & __getitem__(int n) {
		if (n > 1 || n < 0)
			throw std::out_of_range("Index out of range for MatrixRow3");
        return rows[n];
    }
};

/* Stores three floating point numbers.  Used as a row of a Matrix33 and to store the data in attr_vector3 and attr_color3 type attributes. */
struct Float3 {
	float data[3]; /*!< The three floating point numbers stored as an array. */ 

	/*! The bracket operator makes it possible to use this structure like a C++ array.
	\param n The index into the data array.  Should be 0, 1, or 2.
	\return The value at the given array index by reference so it can be read or set via the bracket operator.
	*/
	float & operator[](int n) {
		return data[n];
	}
	float operator[](int n) const {
		return data[n];
	}

	/*!Default constructor.*/
	Float3() {}

	/*! This constructor can be used to set all values in this structure during initialization
	\param f1 The value to set the first floating point number to.
	\param f2 The value to set the second floating point number to.
	\param f3 The value to set the third floating point number to.
	*/
	Float3( float f1, float f2, float f3 ) {
		data[0] = f1;
		data[1] = f2;
		data[2] = f3;
	}

	/*! This function can be used to set all values in the structure at the same time.
	\param f1 The value to set the first floating point number to.
	\param f2 The value to set the second floating point number to.
	\param f3 The value to set the third floating point number to.
	*/
	void Set( float f1, float f2, float f3 ) {
		data[0] = f1;
		data[1] = f2;
		data[2] = f3;
	}

	//Python Operator Overloads
	float __getitem__(int n) {
		if (n > 2 || n < 0)
			throw std::out_of_range("Index out of range for Float3");
		return data[n];
	}
	void __setitem__(int n, float value) {
		if (n > 2 || n < 0)
			throw std::out_of_range("Index out of range for Float3");
		data[n] = value;
	}
};

/*! Stores a 3 by 3 matrix used for rotation. */
struct Matrix33 {
	Float3 rows[3]; /*!< The three rows of Float3 structures which hold three floating point numbers each. */ 
	
	/*! The bracket operator makes it possible to use this structure like a 3x3 C++ array.
	\param n The index into the row array.  Should be 0, 1, or 2.
	\return The Float3 structure for the given row index by reference so it can be read or set via the bracket operator.
	*/
	Float3 & operator[](int n) {
		return rows[n];
	}
	const Float3 & operator[](int n) const {
		return rows[n];
	}

	/*! Default constructor. */
	Matrix33() {}

	/*! This constructor can be used to set all values in this matrix during initialization
	\param m11 The value to set at row 1, column 1.
	\param m12 The value to set at row 1, column 2.
	\param m13 The value to set at row 1, column 3.
	\param m21 The value to set at row 2, column 1.
	\param m22 The value to set at row 2, column 2.
	\param m23 The value to set at row 2, column 3.
	\param m31 The value to set at row 3, column 1.
	\param m32 The value to set at row 3, column 2.
	\param m33 The value to set at row 3, column 3.
	*/
	Matrix33(
		float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33
	) {
		rows[0][0] = m11; rows[0][1] = m12; rows[0][2] = m13;
		rows[1][0] = m21; rows[1][1] = m22; rows[1][2] = m23;
		rows[2][0] = m31; rows[2][1] = m32; rows[2][2] = m33;
	}

	/*! This function can be used to set all values in this matrix at the same time.
	\param m11 The value to set at row 1, column 1.
	\param m12 The value to set at row 1, column 2.
	\param m13 The value to set at row 1, column 3.
	\param m21 The value to set at row 2, column 1.
	\param m22 The value to set at row 2, column 2.
	\param m23 The value to set at row 2, column 3.
	\param m31 The value to set at row 3, column 1.
	\param m32 The value to set at row 3, column 2.
	\param m33 The value to set at row 3, column 3.
	*/
	void Set(
		float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33
	) {
		rows[0][0] = m11; rows[0][1] = m12; rows[0][2] = m13;
		rows[1][0] = m21; rows[1][1] = m22; rows[1][2] = m23;
		rows[2][0] = m31; rows[2][1] = m32; rows[2][2] = m33;
	}

	void AsFloatArr( float out[3][3] ) {
		out[0][0] = rows[0][0]; out[0][1] = rows[0][1]; out[0][2] = rows[0][2];
		out[1][0] = rows[1][0]; out[1][1] = rows[1][1]; out[1][2] = rows[1][2];
		out[2][0] = rows[2][0]; out[2][1] = rows[2][1]; out[2][2] = rows[2][2];
	}

	//Python Operator Overloads
	Float3 & __getitem__(int n) {
		if (n > 2 || n < 0)
			throw std::out_of_range("Index out of range for MatrixRow3");
        return rows[n];
    }
};

/* Stores four floating point numbers.  Used as a row of a Matrix44. */
struct Float4 {
	float data[4]; /*!< The four floating point numbers stored as an array. */ 

	/*! The bracket operator makes it possible to use this structure like a C++ array.
	\param n The index into the data array.  Should be 0, 1, 2, or 3.
	\return The value at the given array index by reference so it can be read or set via the bracket operator.
	*/
	float & operator[](int n) {
		return data[n];
	}
	float operator[](int n) const {
		return data[n];
	}

	/*! Default Constructor.*/
	Float4() {}

	/*! This constructor can be used to set all values in this structure during initialization
	\param f1 The value to set the first floating point number to.
	\param f2 The value to set the second floating point number to.
	\param f3 The value to set the third floating point number to.
	\param f4 The value to set the fourth floating point number to.
	*/
	Float4( float f1, float f2, float f3, float f4 ) {
		data[0] = f1;
		data[1] = f2;
		data[3] = f3;
		data[4] = f4;
	}

	/*! This function can be used to set all values in the structure at the same time.
	\param f1 The value to set the first floating point number to.
	\param f2 The value to set the second floating point number to.
	\param f3 The value to set the third floating point number to.
	\param f4 The value to set the fourth floating point number to.
	*/
	void Set( float f1, float f2, float f3, float f4 ) {
		data[0] = f1;
		data[1] = f2;
		data[3] = f3;
		data[4] = f4;
	}

	//Python Operator Overloads
	float __getitem__(int n) {
		if (n > 3 || n < 0)
			throw std::out_of_range("Index out of range for Float4");
        return data[n];
    }
	void __setitem__(int n, float value) {
		if (n > 3 || n < 0)
			throw std::out_of_range("Index out of range for Float4");
		data[n] = value;
	}
};

/*! Stores a 4 by 4 matrix used for combined transformations. */
struct Matrix44 {
	Float4 rows[4]; /*!< The three rows of Float3 structures which hold three floating point numbers each. */ 
	
	/*! The bracket operator makes it possible to use this structure like a 4x4 C++ array.
	\param n The index into the row array.  Should be 0, 1, 2, or 3.
	\return The Float4 structure for the given row index by reference so it can be read or set via the bracket operator.
	*/
	Float4 & operator[](int n) {
		return rows[n];
	}
	Float4 const & operator[](int n) const {
		return rows[n];
	}

	/*! Default constructor. */
	Matrix44() {}

	/*! This constructor can be used to set all values in this matrix during initialization
	\param m11 The value to set at row 1, column 1.
	\param m12 The value to set at row 1, column 2.
	\param m13 The value to set at row 1, column 3.
	\param m14 The value to set at row 1, column 4.
	\param m21 The value to set at row 2, column 1.
	\param m22 The value to set at row 2, column 2.
	\param m23 The value to set at row 2, column 3.
	\param m24 The value to set at row 2, column 4.
	\param m31 The value to set at row 3, column 1.
	\param m32 The value to set at row 3, column 2.
	\param m33 The value to set at row 3, column 3.
	\param m34 The value to set at row 3, column 4.
	\param m41 The value to set at row 4, column 1.
	\param m42 The value to set at row 4, column 2.
	\param m43 The value to set at row 4, column 3.
	\param m44 The value to set at row 4, column 4.
	*/
	Matrix44(
		float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44
	) {
		rows[0][0] = m11; rows[0][1] = m12; rows[0][2] = m13; rows[0][3] = m14;
		rows[1][0] = m21; rows[1][1] = m22; rows[1][2] = m23; rows[1][3] = m24;
		rows[2][0] = m31; rows[2][1] = m32; rows[2][2] = m33; rows[2][3] = m34;
		rows[3][0] = m41; rows[3][1] = m42; rows[3][2] = m43; rows[3][3] = m44;
	}

	/*! This function can be used to set all values in this matrix at the same time.
	\param m11 The value to set at row 1, column 1.
	\param m12 The value to set at row 1, column 2.
	\param m13 The value to set at row 1, column 3.
	\param m14 The value to set at row 1, column 4.
	\param m21 The value to set at row 2, column 1.
	\param m22 The value to set at row 2, column 2.
	\param m23 The value to set at row 2, column 3.
	\param m24 The value to set at row 2, column 4.
	\param m31 The value to set at row 3, column 1.
	\param m32 The value to set at row 3, column 2.
	\param m33 The value to set at row 3, column 3.
	\param m34 The value to set at row 3, column 4.
	\param m41 The value to set at row 4, column 1.
	\param m42 The value to set at row 4, column 2.
	\param m43 The value to set at row 4, column 3.
	\param m44 The value to set at row 4, column 4.
	*/
	void Set(
		float m11, float m12, float m13, float m14,
		float m21, float m22, float m23, float m24,
		float m31, float m32, float m33, float m34,
		float m41, float m42, float m43, float m44
	) {
		rows[0][0] = m11; rows[0][1] = m12; rows[0][2] = m13; rows[0][3] = m14;
		rows[1][0] = m21; rows[1][1] = m22; rows[1][2] = m23; rows[1][3] = m24;
		rows[2][0] = m31; rows[2][1] = m32; rows[2][2] = m33; rows[2][3] = m34;
		rows[3][0] = m41; rows[3][1] = m42; rows[3][2] = m43; rows[3][3] = m44;
	}

	void AsFloatArr( float out[4][4] ) {
		out[0][0] = rows[0][0]; out[0][1] = rows[0][1]; out[0][2] = rows[0][2]; out[0][3] = rows[0][3];
		out[1][0] = rows[1][0]; out[1][1] = rows[1][1]; out[1][2] = rows[1][2]; out[1][3] = rows[1][3];
		out[2][0] = rows[2][0]; out[2][1] = rows[2][1]; out[2][2] = rows[2][2]; out[2][3] = rows[2][3];
		out[3][0] = rows[3][0]; out[3][1] = rows[3][1]; out[3][2] = rows[3][2]; out[3][3] = rows[3][3];
	}

	//Python Operator Overloads
	Float4 & __getitem__(int n) {
		if (n > 3 || n < 0)
			throw std::out_of_range("Index out of range for Matrix44");
        return rows[n];
    }
};

struct Color4 {
	float r, g, b, a;
	Color4() {}
	Color4(float r, float g, float b, float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
	void Set(float r, float g, float b, float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

struct Quaternion {
	float w, x, y, z;
	Quaternion() {}
	Quaternion(float w, float x, float y, float z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void Set(float w, float x, float y, float z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}
};


template <class T> 
struct Key {
	float time;
	T data, forward_tangent, backward_tangent;
	float tension, bias, continuity;
};

//--Main Interfaces--//

/**
 * Interface for most Ni-blocks.
 */
class IBlock{
public:

	IBlock( ){}
	virtual ~IBlock() {}

	virtual int GetBlockNum() const = 0;
	virtual blk_ref GetParent() const = 0;
	virtual string asString() const = 0;
	virtual string GetBlockType() const = 0;
	virtual bool IsControllable() const = 0;
	virtual bool IsController() const = 0;

	//Attribute Functions
	virtual attr_ref GetAttr(string const & attr_name) const = 0;
	virtual vector<attr_ref> GetAttrs() const = 0;

	//Link Functions
	virtual list<blk_ref> GetLinks() const = 0;

	//To check for specialized Interfaces
	virtual void * QueryInterface( int id ) = 0;
	virtual void const * QueryInterface( int id ) const = 0;
	
	// Python Operator Overloads
	string __str__() const {
		return asString();
	};
	
protected:
	friend class blk_ref;
	virtual void AddRef() = 0;
	virtual void SubtractRef() = 0;
};

class IAttr {
public:
	IAttr() {}
	virtual ~IAttr() {}
	virtual AttrType GetType() const = 0;
	virtual string GetName() const = 0;
	virtual void Read( ifstream& in, unsigned int version ) = 0;
	virtual void Write( ofstream& out, unsigned int version ) const = 0;
	//Getters
	virtual int asInt() const = 0;
	virtual float asFloat() const = 0;
	virtual Float3 asFloat3() const = 0;
	virtual string asString() const = 0;
	virtual Matrix33 asMatrix33() const = 0;
	virtual blk_ref asLink() const = 0;
	virtual TextureSource asTextureSource() const = 0;
	virtual BoundingBox asBoundingBox() const = 0;
	virtual ConditionalInt asConditionalInt() const = 0;
	virtual Texture asTexture() const = 0;
	virtual list<blk_ref> asLinkList() const = 0;
	//Setters
	virtual void Set(int) = 0;
	virtual void Set(float) = 0;
	virtual void Set(Float3 const &) = 0;
	virtual void Set(string const &) = 0;
	virtual void Set(Matrix33 const &) = 0;
	virtual void Set( blk_ref const & n ) = 0;
	virtual void Set(TextureSource const &) = 0;
	virtual void Set(BoundingBox const &) = 0;
	virtual void Set(ConditionalInt const &) = 0;
	virtual void Set(Texture const &) = 0;
	//Link functions
	virtual bool HasLinks() const = 0;
	virtual void AddLink( blk_ref const & block ) = 0;
	virtual void AddLinks( list<blk_ref> const & new_links ) = 0;
	virtual void ClearLinks() = 0;
	virtual void RemoveLinks( blk_ref const & block ) = 0;
	virtual blk_ref FindLink( string const & block_type ) const = 0;

	// Python Operator Overloads
	string __str__() {
		return asString();
	};
};



class INode {
public:
	INode() {}
	virtual ~INode() {}
	virtual Matrix44 GetLocalTransform() const = 0;
	virtual Matrix44 GetWorldTransform() const = 0;
	virtual Matrix44 GetBindPosition() const = 0;
	virtual void SetBindPosition( Matrix44 const & m ) = 0;
	virtual Matrix44 GetLocalBindPos() const = 0;
};

class IShapeData {
public:
	IShapeData() {}
	virtual ~IShapeData() {}
	//Counts
	virtual short GetVertexCount() const = 0;
	virtual short GetUVSetCount() const = 0;
	virtual void SetVertexCount(int n) = 0;
	virtual void SetUVSetCount(int n) = 0;
	//Getters
	virtual vector<Vector3> GetVertices() const = 0;
	virtual vector<Vector3> GetNormals() const = 0;
	virtual vector<Color4> GetColors() const = 0;
	virtual vector<TexCoord> GetUVSet( int index ) const = 0;
	//Setters
	virtual void SetVertices( const vector<Vector3> & in ) = 0;
	virtual void SetNormals( const vector<Vector3> & in ) = 0;
	virtual void SetColors( const vector<Color4> & in ) = 0;
	virtual void SetUVSet( int index, const vector<TexCoord> & in ) = 0;
};

class ITriShapeData {
public:
	ITriShapeData() {}
	virtual ~ITriShapeData () {}
	//Counts
	virtual short GetTriangleCount() const = 0;
	virtual void SetTriangleCount(int n) = 0;
	//Match Detection
	virtual void SetMatchDetectionMode(bool choice) = 0;
	virtual bool GetMatchDetectionMode() const = 0;
	//Getters
	virtual vector<Triangle> GetTriangles() const = 0;
	//Setters
	virtual void SetTriangles( const vector<Triangle> & in ) = 0;
};

class ITriStripsData {
public:
	ITriStripsData() {}
	virtual ~ITriStripsData () {}
	//Counts
	virtual short GetTriangleCount() const = 0;
	virtual short GetStripCount() const = 0;
	virtual void SetStripCount(int n) = 0;
	//Getter
	virtual vector<short> GetStrip( int index ) const = 0;
	virtual vector<Triangle> GetTriangles() const = 0;
	//Setter
	virtual void SetStrip( int index, const vector<short> & in ) = 0;
};

class ISkinData {
public:
	ISkinData() {}
	virtual ~ISkinData () {}
	virtual vector<blk_ref> GetBones() = 0; // Can't be const, since it changes the bone blk_ref reference 
	virtual map<int, float> GetWeights( blk_ref const & bone ) const = 0;
	virtual void AddBone( blk_ref const & bone, map<int, float> const & in ) = 0;
	virtual void RemoveBone( blk_ref const & bone ) = 0;
};

class IKeyframeData {
public:
	IKeyframeData() {}
	virtual ~IKeyframeData () {}
	//Rotate
	virtual KeyType GetRotateType() const = 0;
	virtual void SetRotateType( KeyType t ) = 0;
	virtual vector< Key<Quaternion> > GetRotateKeys() const = 0;
	virtual void SetRotateKeys( vector< Key<Quaternion> > const & keys ) = 0;
	//Translate
	virtual KeyType GetTranslateType() const = 0;
	virtual void SetTranslateType( KeyType t ) = 0;
	virtual vector< Key<Vector3> > GetTranslateKeys() const = 0;
	virtual void SetTranslateKeys( vector< Key<Vector3> > const & keys ) = 0;
	//Scale
	virtual KeyType GetScaleType() const = 0;
	virtual void SetScaleType( KeyType t ) = 0;
	virtual vector< Key<float> > GetScaleKeys() const = 0;
	virtual void SetScaleKeys( vector< Key<float> > const & keys ) = 0;
};

class ITextKeyExtraData {
public:
	ITextKeyExtraData() {}
	virtual ~ITextKeyExtraData () {}
	virtual vector< Key<string> > GetKeys() const = 0;
	virtual void SetKeys( vector< Key<string> > const & keys ) = 0;

};

class IColorData {
public:
	IColorData() {}
	virtual ~IColorData () {}
	virtual KeyType GetKeyType() const = 0;
	virtual void SetKeyType( KeyType t ) = 0;
	virtual vector< Key<Color4> > GetKeys() const = 0;
	virtual void SetKeys( vector< Key<Color4> > const & keys ) = 0;
};

class IFloatData {
public:
	IFloatData() {}
	virtual ~IFloatData () {}
	virtual KeyType GetKeyType() const = 0;
	virtual void SetKeyType( KeyType t ) = 0;
	virtual vector< Key<float> > GetKeys() const = 0;
	virtual void SetKeys( vector< Key<float> > const & keys ) = 0;
};

class IPosData {
public:
	IPosData() {}
	virtual ~IPosData () {}
	virtual KeyType GetKeyType() const = 0;
	virtual void SetKeyType( KeyType t ) = 0;
	virtual vector< Key<Vector3> > GetKeys() const = 0;
	virtual void SetKeys( vector< Key<Vector3> > const & keys ) = 0;
};


class IMorphData {
public:
	IMorphData() {}
	virtual ~IMorphData () {}
	virtual int GetVertexCount() const = 0;
	virtual void SetVertexCount( int n ) = 0;
	virtual int GetMorphCount() const = 0;
	virtual void SetMorphCount( int n ) = 0;
	virtual vector< Key<float> > GetMorphKeys( int n ) const = 0;
	virtual void SetMorphKeys( int n, vector< Key<float> > const & keys ) = 0;
	virtual vector<Vector3> GetMorphVerts( int n) const = 0;
	virtual void SetMorphVerts( int n, vector<Vector3> const & in ) = 0;
};

//struct ComplexVertex {
//	ComplexVertex() : has_color(false), has_normal(false), vertex_index(0), normal_index(0), color_index(0) {}
//	~ComplexVertex();
//	bool has_color, has_normal;
//	int vertex_index, color_index, normal_index;
//	vector<int> uv_indices;
//}
//
//struct ComplexFace {
//	vector<ComplexVertex> points;
//	int base_map_index;
//	int glow_map_index;
//};
//
//class ComplexShape {
//
//	void CombineTriShapes( list<blk_ref> & tri_shapes );
////	void SetVertices( vector<Vector3> & vertices );
////	void SetUVs( vector<TexCoord> & uvs );
////	void SetColors( vector<Color4> & colors );
////	void SetNormals( vector<Vector3> & normals );
////	void SetBones( vector<blk_ref> & bones );
////	void SetFaces( list< vector< ComplexVertex > > & faces );
////
////	vector<Vector3> GetVertices();
////	vector<TexCoord> GetUVs();
////	vector<Color4> GetColors();
////	vector<Vector3> GetNormals();
////	vector<blk_ref> GetBones();
////	list< vector< ComplexVertex > > GetFaces();
//
//private:
//	vector<Vector3> _vertices;
//	vector<Color4> _colors;
//	vector<Vector3> _normals;
//	list<ComplexFace> _faces;
//	map<string, blk_ref> _materials;
//	map<string, vector<TexCoord> > _uvs;
//	map<blk_ref, map<int, float> > _bones;
//};
//
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
//				if ( tx_prop[attr_name]->asTexture().isUsed == true ) {
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

//--Attribute Reference--//
class attr_ref {
public:
	attr_ref() : _attr(NULL) {}
	attr_ref( IAttr * ptr ) : _attr(ptr) {}
	IAttr * operator->() const {
		if ( _attr == NULL ) {
			//pointer has not been fixed, throw exception
			throw runtime_error("Attempted to dereference a null Attribute reference.");
		} else {
			return _attr;
		}
	}
	bool is_null() const {
		if (_attr == NULL )
			return true;
		else
			return false;
	}
	IAttr * ptr() const {
		return _attr;
	}
	//Comparison operators
	bool operator==(attr_ref & rh) const {
		if (_attr == rh._attr)
			return true;
		else
			return false;
	}
	bool operator!=(attr_ref & rh) const {
		if (_attr != rh._attr)
			return true;
		else
			return false;
	}
	bool operator<(attr_ref & rh) const {
		if (_attr < rh._attr)
			return true;
		else
			return false;
	}

	//Assignment operators
	attr_ref & operator=(int n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(float n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(Float3 const & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(string const & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(const char * n) {
		_attr->Set( string(n) );
		return *this;
	}
	attr_ref & operator=(Matrix33 const & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(blk_ref const & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(TextureSource const & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(BoundingBox const & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(ConditionalInt const & n) {
		_attr->Set(n);
		return *this;
	}
	attr_ref & operator=(Texture const & n) {
		_attr->Set(n);
		return *this;
	}

	//Conversion fuctions
	operator int() const { return _attr->asInt(); }
	operator float() const { return _attr->asFloat(); }
	operator Float3() const { return _attr->asFloat3(); }
	operator string() const { return _attr->asString(); }
	
	operator Matrix33() const { return _attr->asMatrix33(); }
	operator blk_ref() const;
	operator TextureSource() const;
	operator BoundingBox() const;
	operator ConditionalInt() const;
	operator Texture() const;
	operator list<blk_ref>() const { return _attr->asLinkList(); }

	//friend ostream & operator<<(ostream & lh, const attr_ref & rh) {
	//	if ( rh._attr == NULL )
	//		lh << "Null Attribute";
	//	else
	//		lh << rh->GetName() << ":  " << rh->asString();
	//	}
	//	return lh;
	//}

private:
	IAttr * _attr;
};

//--Block Reference--//

class blk_ref {
public:
	blk_ref() : _index(-1), _block(NULL) {}
	blk_ref( int index ) : _index(index), _block(NULL) {}
	//Copy Constructor
	blk_ref(const blk_ref & rh ) {
		_block = rh._block;
		_index = rh._index;

		if ( _block != NULL ) {
			//cout << "Copying from another reference - ";
			//Increment reference count
			_block->AddRef();
		}
	}
	//Asignment Operator
	blk_ref & operator=(const blk_ref & rh ) {
		//Make sure it's not already equal
		if (_block == rh._block && get_index() == rh.get_index() ) {
			// already equal
			return *this;
		}

		// the incoming reference is different
		if ( _block != NULL ) {
			//Decrement reference count
			//cout << "This reference was overwritten by another - ";
			_block->SubtractRef();
		}
		_block = rh._block;
		_index = rh._index;
		if (_block != NULL ) {
			//rhcrement reference count
			//cout << "Copied from another reference using = - ";
			_block->AddRef();
		}

		return *this;
	}
	// Equality Operator
	bool operator==(const blk_ref & rh) const {
		if ( _block == rh._block && _index == rh._index )
			return true;
		else
			return false;
	}
	// Less-Than Operator
	bool operator<( const blk_ref & rh ) const {
		if ( get_index() < rh.get_index() )
			return true;
		else
			return false;
	}
	// Non-Equality Operator
	bool operator!=(const blk_ref & rh) const {
		return !(*this == rh);
	}
	bool is_null() const {
		if (_block == NULL && _index == -1)
			return true;
		else
			return false;
	}
	blk_ref( IBlock * block ) : _index(-1), _block(block) {

		//Increment reference count
		//cout << "Creating from block - ";
		_block->AddRef();
	}
	~blk_ref() {
		//If pointer has been fixed
		if ( _block != NULL ) {
			//Decrement reference count
			//cout << "Reference deleted - ";
			_block->SubtractRef();
		}
	}
	void set_block( IBlock * block ) {
		//Use assignment operator code
		*this = blk_ref( block );
	}
	IBlock * operator->() const {
		if ( _block == NULL ) {
			//pointer has not been fixed, throw exception
			cout << *this << endl;
			throw runtime_error("Attempted to dereference a block reference that has not been fixed.");
		} else {
			return _block;
		}
	}
	attr_ref operator[] ( string const & index ) const {
		return _block->GetAttr(index);
	}
	int get_index() const {

		if (_block != NULL)
			return _block->GetBlockNum();
		else
			return _index; 
	}
	IBlock * get_block() const {
		return _block;
	}
	void set_index( int index ) { 
		//Use assigntment operator code
		*this = blk_ref( index );
	}
	bool is_fixed() const {
		if ( _block == NULL )
			return false;
		else
			return true;
	}
	friend ostream & operator<<(ostream & lh, const blk_ref & rh) {
		if (rh._block != NULL) {
			lh << rh._block->GetBlockType() << "(Block " << rh._block->GetBlockNum() << ")";
			
			attr_ref attr = rh._block->GetAttr("Name");
			if ( attr.is_null() == false ) {
				lh << " [" << attr->asString() << "]";
			}
		} else {
			if (rh._index == -1)
				lh << "Null (-1)";
			else
				lh << "Block " << rh._index;
		}
		return lh;
	}
	//Python Operator Overloads
	attr_ref __getitem__(string index) {
		return _block->GetAttr(index);
	}
	void __setitem__(string index, int value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, float value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, Float3 value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, string value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, Matrix33 value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, blk_ref value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, TextureSource const & value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, BoundingBox const & value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, ConditionalInt const & value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
	void __setitem__(string index, Texture const & value) {
		attr_ref attr = _block->GetAttr(index);
		if ( attr.is_null() == true )
			throw std::out_of_range("Tried to set an attribute via [] that does not exist in this block.");
		attr->Set(value);
	}
protected:
	int _index;
	IBlock * _block;
};

enum TexClampMode {
	CLAMP_S_CLAMP_T = 0,
	CLAMP_S_WRAP_T = 1,
	WRAP_S_CLAMP_T = 2,
	WRAP_S_WRAP_T = 3
};

enum TexFilterMode {
	FILTER_NEAREST = 0,
	FILTER_BILERP = 1,
	FILTER_TRILERP = 2,
	FILTER_NEAREST_MIPNEAREST = 3,
	FILTER_NEAREST_MIPLERP = 4,
	FILTER_BILERP_MIPNEAREST = 5,
};

//--Structures--//

struct blk_link {
	blk_ref block;
	attr_ref attr;
};

struct BoundingBox {
	bool isUsed;
	int unknownInt;
	Vector3 translation;
	Matrix33 rotation;
	Vector3 radius;
};

struct ConditionalInt {
	bool isUsed;
	int unknownInt;
};

struct Texture {
	Texture() : isUsed(false), clampMode(WRAP_S_WRAP_T), filterMode(FILTER_TRILERP), textureSet(0),  PS2_L(0), PS2_K(0xFFB5), unknownShort(0x0101) {}
	bool isUsed;
	TexClampMode clampMode;
	TexFilterMode filterMode;
	int textureSet;
	unsigned short PS2_L;
	unsigned short PS2_K;
	short unknownShort;  //exists up to version 4.1.0.12
	//Unknown Block in version 10.1.0.0 and up
	bool hasUnknownData;
	float unknown5Floats[5];
	int unknownInt;
	float unknownFloat1, unknownFloat2;
	//Bitmap block - only exists if this texture is in the bitmap slot
	float bmLumaOffset;
	float bmLumaScale;
	Matrix22 bmMatrix;
};

struct TextureSource {
	bool useExternal;
	unsigned char unknownByte;
	string fileName;
};

struct SkinWeight {
	unsigned short vertexNum;
	float vertexWeight;
};

#endif
