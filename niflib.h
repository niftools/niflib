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
class IBoolData;
class IColorData;
class IFloatData;
class IPosData;
class IPalette;
class IPixelData;
class ITexturingProperty;
class INode;
class IControllerSequence;
class blk_ref;
class attr_ref;
struct blk_link;
struct Texture;
struct TextureSource;
struct BoundingBox;
struct ConditionalInt;
struct SkinWeight;
struct ControllerLink;
struct TexDesc;
struct LODRange;

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
const int ID_BOOL_DATA = 11; /*!< ID for IBoolData Interface */
const int ID_CONTROLLER_SEQUENCE = 12; /*!< ID for IControllerSequence Interface */
const int ID_PIXEL_DATA = 13; /*!< ID for IPixelData Interface */
const int ID_PALETTE = 14; /*!< ID for IPalette Interface */
const int ID_TEXTURING_PROPERTY = 15; /*!< ID for ITexturingProperty Interface */

/*!
 * This enum contains all the attribute types used by Niflib.
 */
enum AttrType {
	attr_int, /*!< Integer Attribute.  Holds a 32-bit integer. */  
	attr_short, /*!< Short Integer Attribute.  Holds a 16-bit integer. */ 
	attr_bool, /*!< A boolean value.  Size depends on version. */
	attr_byte, /*!< Byte Attribute.  Holds an 8-bit integer. */ 
	attr_float, /*!< Float Attribute.  Holds a 32-bit floating point number. */ 
	attr_float3, /*!< Float3 Attribute.  Holds a Float3 structure. */ 
	attr_float4, /*!< Float4 Attribute.  Holds a Float4 structure. */ 
	attr_string, /*!< String Attribute.  Holds a text string. */ 
	attr_link, /*!< Link Attribute.  Links to one other Nif block lower in the Nif tree. */
	attr_crossref, /*!< Cross Reference Attribute.  Links to one other Nif block higher in the Nif tree.  Will be automatically cleared if the block it links to is destroyed. */ 
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
	attr_modifiergroup, /*!< A link group conditioned on a boolean value. */
	attr_alphaformat, /*!< Alpha Format Attribute.  Holds an integer that corresponds to the alpha format. */ 
	attr_selflink,  /*!< Self Link Attribute.  Automatic. */ 
	attr_emitterobject,  /*!< Emitter Object Attribute.  Automatic. */ 
	attr_controllertarget, /*!< Controller Target Attribute.  Automatic. */ 
	attr_skeletonroot, /*!< Skeleton Root Attribute.  Automatic. */ 
	attr_particlegroup, /*!< Particle Group Attribute. */ 
	attr_lodinfo, /*!< Level of Detail Range Group Attribute. */ 
	attr_vector3, /*!< Vector3 Attribute.  Holds a Float3 structure that corresponds to a vector in 3D space. */ 
	attr_color3, /*!< Color3 Attribute.  Holds a Float3 structure that corresponds to an RGB color. */ 
	attr_color4, /*!< Color4 Attribute.  Holds a Float4 structure that corresponds to an RGBA color. */ 
	attr_quaternion, /*!< Quaternion Attribute.  Holds a Float4 structure that corresponds to a Quaternion. */ 
	attr_parent, /*!< Parent Attribute.  Automatic. */
	attr_targetgroup, /*!< A linkgroup that stores its count with a short instead of a long integer. */
	attr_unk292bytes, //Temporary
	attr_shader /*!< A string and a link that describe the shader used on a particular mesh.  */
};

//NIF Versions
const unsigned int VER_4_0_0_2     = 0x04000002; /*!< Nif Version 4.0.0.2 */ 
const unsigned int VER_4_1_0_12    = 0x0401000C; /*!< Nif Version 4.1.0.12 */ 
const unsigned int VER_4_2_0_2     = 0x04020002; /*!< Nif Version 4.2.0.2 */ 
const unsigned int VER_4_2_1_0     = 0x04020100; /*!< Nif Version 4.2.1.0 */ 
const unsigned int VER_4_2_2_0     = 0x04020200; /*!< Nif Version 4.2.2.0 */ 
const unsigned int VER_10_0_1_0    = 0x0A000100; /*!< Nif Version 10.0.1.0 */ 
const unsigned int VER_10_1_0_0    = 0x0A010000; /*!< Nif Version 10.1.0.0 */ 
const unsigned int VER_10_2_0_0    = 0x0A020000; /*!< Nif Version 10.2.0.0 */ 
const unsigned int VER_20_0_0_4    = 0x14000004; /*!< Nif Version 20.0.0.4 */ 
const unsigned int VER_UNSUPPORTED = 0xFFFFFFFF; /*!< Unsupported Nif Version */
const unsigned int VER_INVALID     = 0xFFFFFFFE; /*!< Not a Nif file */

/*! Lists the basic texture types availiable from the ITexturingProperty interface*/
enum TexType {
	BASE_MAP = 0, /*!< The basic texture used by most meshes. */ 
	DARK_MAP = 1, /*!< Used to darken the model with false lighting. */ 
	DETAIL_MAP = 2, /*!< Combined with base map for added detail. */ 
	GLOSS_MAP = 3, /*!< Allows the glossyness of an object to differ across its surface. */ 
	GLOW_MAP = 4, /*!< Creates a glowing effect. */ 
	BUMP_MAP = 5, /*!< Used to make the object appear to have more detail than it really does. */ 
	DECAL_0_MAP = 6 /*!< For placing images on the object like stickers. */ 
};

/*! Specifies the availiable texture apply modes.  Affects the way colors are composed together. */
enum ApplyMode {
   APPLY_REPLACE = 0, /*!< Replaces existing color */ 
   APPLY_DECAL = 1, /*!< For placing images on the object like stickers. */ 
   APPLY_MODULATE = 2, /*!< Modulates existing color. */ 
   APPLY_HILIGHT = 3, /*!< PS2 Only */
   APPLY_HILIGHT2 = 4 /*!< PS2 Only */
};

/*! Specifies the availiable texture clamp modes.  That is, the behavior of pixels outside the range of the texture.*/
enum TexClampMode {
	CLAMP_S_CLAMP_T = 0, /*!< Clamp in both directions. */ 
	CLAMP_S_WRAP_T = 1, /*!< Clamp in the S direction but wrap in the T direction. */ 
	WRAP_S_CLAMP_T = 2, /*!< Wrap in the S direction but clamp in the T direction. */ 
	WRAP_S_WRAP_T = 3 /*!< Wrap in both directions. */ 
};

/*! Specifies the availiable texture filter modes.  That is, the way pixels within a texture are blended together when textures are displayed on the screen at a size other than their original dimentions.*/
enum TexFilterMode {
	FILTER_NEAREST = 0, /*!< Simply uses the nearest pixel.  Very grainy. */ 
	FILTER_BILERP = 1, /*!< Uses bilinear filtering. */ 
	FILTER_TRILERP = 2, /*!< Uses trilinear filtering. */ 
	FILTER_NEAREST_MIPNEAREST = 3, /*!< Uses the nearest pixel from the mipmap that is closest to the display size. */ 
	FILTER_NEAREST_MIPLERP = 4, /*!< Blends the two mipmaps closest to the display size linearly, and then uses the nearest pixel from the result. */ 
	FILTER_BILERP_MIPNEAREST = 5, /*!< Uses the closest mipmap to the display size and then uses bilinear filtering on the pixels. */ 
};

#ifndef NULL
#define NULL 0  /*!< Definition used to detect null pointers. */ 
#endif

/*!
 * This enum contains all the animation key types used by Niflib.
 */
enum KeyType {
	LINEAR_KEY = 1, /*!< Use linear interpolation. */ 
	QUADRATIC_KEY = 2, /*!< Use quadratic interpolation.  Forward and back tangents will be stored.*/ 
	TBC_KEY = 3, /*!< Use Tension Bias Continuity interpolation.  Tension, bias, and continuity will be stored.*/ 
	XYZ_ROTATION_KEY = 4 /*!< For use only with rotation data.  Separate X, Y, and Z keys will be stored instead of using quaternions. */ 
};

/*!
 * Specifies the pixel format used by the NiPixelData block to store a texture.
 */
enum PixelFormat {
	PX_FMT_RGB8 = 0, /*!< 24-bit color: uses 8 bit to store each red, blue, and green component. */
	PX_FMT_RGBA8 = 1, /*!< 32-bit color with alpha: uses 8 bits to store each red, blue, green, and alpha component. */
	PX_FMT_PAL8 = 2 /*!< 8-bit palette index: uses 8 bits to store an index into the palette stored in a NiPallete block. */
};

//--Main Functions--//

/*!
 * Reads the header of the given file by file name and returns the NIF version. Call this
 * function prior to calling ReadNifList or ReadNifTree, if you need to make sure that the NIF file is supported.
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return The NIF version of the file, in hexadecimal format. If the file is not a NIF file, it returns VER_INVALID. If it is a NIF file, but its version is not supported by the library, it returns VER_UNSUPPORTED.
 * 
 * <b>Example:</b> 
 * \code
 * unsigned int ver = CheckNifHeader("test_in.nif");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * ver = CheckNifHeader("test_in.nif")
 * \endcode
 */
unsigned int CheckNifHeader( string const & file_name );

/*!
 * Reads the given file by file name and returns a vector of block references
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return A vector of block references that point to all the blocks read from the Nif file.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifList("test_in.nif");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifList("test_in.nif")
 * \endcode
 * 
 * \sa ReadNifTree, WriteNifTree
 */
vector<blk_ref> ReadNifList( string const & file_name );

/*!
 * Reads the given input stream and returns a vector of block references
 * \param stream The input stream to read NIF data from.
 * \return A vector of block references that point to all the blocks read from the stream.
 */
vector<blk_ref> ReadNifList( istream & in );

/*!
 * Reads the given file by file name and returns a reference to the root block.
 * \param file_name The name of the file to load, or the complete path if it is not in the working directory.
 * \return A block reference that points to the root of tree of data blocks contained in the NIF file.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * \endcode
 * 
 * \sa ReadNifList, WriteNifTree
 */
blk_ref ReadNifTree( string const & file_name );

/*!
 * Reads the given input stream and returns a reference to the root block.
 * \param stream The input stream to read NIF data from.
 * \return A block reference that points to the root of the tree of data blocks contained in the NIF file.
 */
blk_ref ReadNifTree( istream & in );

/*!
 * Creates a new NIF file of the given file name by crawling through the data tree starting with the root block given.  Automatically writes a kf file and an x/nif file if animation is present.
 * \param file_name The desired file name for the new NIF file.  The path is relative to the working directory unless a full path is specified.
 * \param root_block The root block to start from when writing out the NIF file.  All decedents of this block will be written to the file in tree-descending order.
 * \param version The version of the NIF format to use when writing a file.  Default is version 4.0.0.2.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * WriteNifTree( "test_out.nif", my_block );
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * WriteNifTree( "test_out.nif", my_block )
 * \endcode
 * 
 * \sa ReadNifList, WriteNifTree
 */
void WriteNifTree( string const & file_name, blk_ref const & root_block, unsigned int version = VER_4_0_0_2 );


/*!
 * Merges two Nif trees into one.  For standard Nif files, any blocks with the same name are merged.  For Kf files, blocks are attatched to those that match the name specified in the KF root block.
 * \param root1 The root block of the first Nif tree to merge.
 * \param root2 The root block of the second Nif tree to merge.
 */
void MergeNifTrees( blk_ref root1, blk_ref root2 );

//// Returns list of all blocks in the tree rooted by root block.
//list<blk_ref> GetNifTree( blk_ref const & root_block );

////Returns the NIF spec version of a file, given a file name.
//string GetFileVersion(string file_name);


/*!
 * Sets whether data/hex areas are shown by asString functions
 * \param val A boolean value that specifies whether verbose mode should be turned on.  True = Verbose, False = Brief.
 * 
 * <b>Example:</b> 
 * \code
 * SetVerboseMode(true);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * SetVerboseMode(True)
 * \endcode
 * 
 * \sa IBlock::asString, IAttr::asString
 */
void SetVerboseMode( bool val );

/*!
 * Creates a new block of the given type and returns a reference to it
 * \param block_type – The type of block you want to create.  This value is case sensitive and spelling is important.  Ex. NiNode, NiTriShapeData, NiParticleSystemController, etc.
 * \return This function will return a newly created block of the requested type.  Beware, if the block type is unrecognized, this function will return a featureless block with whatever you sent it as the type.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = CreateBlock("NiNode");
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = CreateBlock("NiNode")
 * \endcode
 * 
 * sa BlocksInMemory
 */
blk_ref CreateBlock( string block_type );

/*!
 * Returns the current total number of blocks in memory.
 * \return Returns the number of blocks currently in memory.  This includes both blocks loading from nif files and blocks created by the user.  Reference counting is used to ensure that multiple copies of the same block are not created, and blocks that are no longer being used are automatically freed.
 * 
 * <b>Example:</b> 
 * \code
 * unsigned int block_count = BlocksInMemory();
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * block_count = BlocksInMemory()
 * \endcode
 * 
 * \sa CreateBlock
 */
unsigned int BlocksInMemory();

//--Query Functions--//
// These are shorthands for using QueryInterface, and required for scripting languages

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_SHAPE_DATA ).  It queries the block for an IShapeData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IShapeData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IShapeData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IShapeData * shape_data = QueryShapeData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * shape_data = QueryShapeData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IShapeData * QueryShapeData( blk_ref & block );
IShapeData const * QueryShapeData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_TRI_SHAPE_DATA ).  It queries the block for an ITriShapeData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ITriShapeData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the ITriShapeData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * ITriShapeData * tri_shape_data = QueryTriShapeData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * tri_shape_data = QueryTriShapeData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
ITriShapeData * QueryTriShapeData( blk_ref & block );
ITriShapeData const * QueryTriShapeData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_SKIN_DATA ).  It queries the block for an ISkinData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ISkinData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the ISkinData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * ISkinData * skin_data = QuerySkinData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * skin_data = QuerySkinData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
ISkinData * QuerySkinData( blk_ref & block );
ISkinData const * QuerySkinData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_PIXEL_DATA).  It queries the block for an IPixelData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IPixelData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IPixelData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IPixelData * pixel_data = QueryPixelData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * pixel_data = QueryPixelData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IPixelData * QueryPixelData( blk_ref & block );
IPixelData const * QueryPixelData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_PALETTE).  It queries the block for an IPalette interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IPalette interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IPalette interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IPalette * palette = QueryPalette(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * palette = QueryPalette(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IPalette * QueryPalette( blk_ref & block );
IPalette const * QueryPalette( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_NODE).  It queries the block for an INode interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the INode interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the INode interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * INode * node = QueryNode(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * node = QueryNode(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
INode * QueryNode( blk_ref & block );
INode const * QueryNode( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_TEXTURING_PROPERTY).  It queries the block for an ITexturingProperty interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ITexturingProperty interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the ITexturingProperty interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * ITexturingProperty * tex_prop = QueryTexturingProperty(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * tex_prop = QueryTexturingProperty(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
ITexturingProperty * QueryTexturingProperty( blk_ref & block );
ITexturingProperty const * QueryTexturingProperty( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_CONTROLLER_SEQUENCE).  It queries the block for an IControllerSequence interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IControllerSequence interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IControllerSequence interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IControllerSequence * cont_seq = QueryControllerSequence(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * cont_seq = QueryControllerSequence(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IControllerSequence * QueryControllerSequence( blk_ref & block );
IControllerSequence const * QueryControllerSequence( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_KEYFRAME_DATA ).  It queries the block for an IKeyframeData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IKeyframeData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IKeyframeData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IKeyframeData * keyframe_data = QueryKeyframeData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * keyframe_data = QueryKeyframeData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IKeyframeData * QueryKeyframeData( blk_ref & block );
IKeyframeData const * QueryKeyframeData( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_TEXT_KEY_EXTRA_DATA ).  It queries the block for an ITextKeyExtraData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ITextKeyExtraData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the ITextKeyExtraData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * ITextKeyExtraData * text_key_extra_data = QueryTextKeyExtraData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * text_key_extra_data = QueryTextKeyExtraData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
ITextKeyExtraData * QueryTextKeyExtraData ( blk_ref & block );
ITextKeyExtraData const * QueryTextKeyExtraData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_MORPH_DATA ).  It queries the block for an IMorphData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IMorphData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IMorphData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IMorphData * morph_data = QueryMorphData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * morph_data = QueryMorphData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IMorphData * QueryMorphData ( blk_ref & block );
IMorphData const * QueryMorphData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_TRI_STRIPS_DATA ).  It queries the block for an ITriStripsData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the ITriStripsData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the ITriStripsData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * ITriStripsData * tri_strips_data = QueryTriStripsData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * tri_strips_data = QueryTriStripsData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
ITriStripsData * QueryTriStripsData ( blk_ref & block );
ITriStripsData const * QueryTriStripsData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_BOOL_DATA ).  It queries the block for an IBoolData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IBoolData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IBoolData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IBoolData * bool_data = QueryBoolData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * bool_data = QueryBoolData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IBoolData * QueryBoolData ( blk_ref & block );
IBoolData const * QueryBoolData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_COLOR_DATA ).  It queries the block for an IColorData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IColorData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IColorData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IColorData * color_data = QueryColorData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * color_data = QueryColorData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IColorData * QueryColorData ( blk_ref & block );
IColorData const * QueryColorData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_FLOAT_DATA ).  It queries the block for an IFloatData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IFloatData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IFloatData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IFloatData * float_data = QueryFloatData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * float_data = QueryFloatData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
 */
IFloatData * QueryFloatData ( blk_ref & block );
IFloatData const * QueryFloatData ( blk_ref const & block );

/*!  A convenience function equivalent to calling IBlock::QueryInterface( ID_POS_DATA ).  It queries the block for an IPosData interface, and returns a pointer to it if it is present.  Otherwise it returns zero.  In other words, it asks a block if it has the IPosData interface available.
 * \param block The block to query the interface from.
 * \return If the given block implements the IPosData interface, a pointer to this interface is returned.  Otherwise the function returns zero – a null pointer.
 * 
 * <b>Example:</b> 
 * \code
 * blk_ref my_block = ReadNifTree("test_in.nif");
 * IPosData * pos_data = QueryPosData(my_block);
 * \endcode
 * 
 * <b>In Python:</b>
 * \code
 * my_block = ReadNifTree("test_in.nif")
 * pos_data = QueryPosData(my_block);
 * \endcode
 * 
 * \sa IBlock::QueryInterface
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
	 * \param u The value to set U to.
	 * \param v The value to set V to.
	 */
	TexCoord(float u, float v) {
		this->u = u;
		this->v = v;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param u The value to set U to.
	 * \param v The value to set V to.
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
	 * \param v1 The index of the first vertex.
	 * \param v2 The index of the second vertex.
	 * \param v3 The index of the third vertex.
	 */
	Triangle(short v1, short v2, short v3) {
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param v1 The index of the first vertex.
	 * \param v2 The index of the second vertex.
	 * \param v3 The index of the third vertex.
	 */
	void Set(short v1, short v2, short v3) {
		this->v1 = v1;
		this->v2 = v2;
		this->v3 = v3;
	}

	/*! The bracket operator makes it possible to use this structure like a C++ array.
	 * \param n The index into the data array.  Should be 0, 1, or 2.
	 * \return The value at the given array index by reference so it can be read or set via the bracket operator.
	 */
	short & operator[](int n) {
		switch (n) {
			case 0: return v1; break;
			case 1: return v2; break;
			case 2: return v3; break;
			default: throw std::out_of_range("Index out of range for Triangle");
		};
	}
	short operator[](int n) const {
		switch (n) {
			case 0: return v1; break;
			case 1: return v2; break;
			case 2: return v3; break;
			default: throw std::out_of_range("Index out of range for Triangle");
		};
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
	 * \param x The value to set X to.
	 * \param y The value to set Y to.
	 * \param z The value to set Z to.
	 */
	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param x The value to set X to.
	 * \param y The value to set Y to.
	 * \param z The value to set Z to.
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
	 * \param n The index into the data array.  Should be 0 or 1.
	 * \return The value at the given array index by reference so it can be read or set via the bracket operator.
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
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 */
	Float2( float f1, float f2 ) {
		data[0] = f1;
		data[1] = f2;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
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
	 * \param n The index into the row array.  Should be 0 or 1.
	 * \return The Float2 structure for the given row index by reference so it can be read or set via the bracket operator.
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
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 */
	Matrix22(
		float m11, float m12,
		float m21, float m22
	) {
		rows[0][0] = m11; rows[0][1] = m12;
		rows[1][0] = m21; rows[1][1] = m22;
	}

	/*! This function can be used to set all values in this matrix at the same time.
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
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
	 * \param n The index into the data array.  Should be 0, 1, or 2.
	 * \return The value at the given array index by reference so it can be read or set via the bracket operator.
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
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 * \param f3 The value to set the third floating point number to.
	 */
	Float3( float f1, float f2, float f3 ) {
		data[0] = f1;
		data[1] = f2;
		data[2] = f3;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 * \param f3 The value to set the third floating point number to.
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
	 * \param n The index into the row array.  Should be 0, 1, or 2.
	 * \return The Float3 structure for the given row index by reference so it can be read or set via the bracket operator.
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
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m13 The value to set at row 1, column 3.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 * \param m23 The value to set at row 2, column 3.
	 * \param m31 The value to set at row 3, column 1.
	 * \param m32 The value to set at row 3, column 2.
	 * \param m33 The value to set at row 3, column 3.
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
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m13 The value to set at row 1, column 3.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 * \param m23 The value to set at row 2, column 3.
	 * \param m31 The value to set at row 3, column 1.
	 * \param m32 The value to set at row 3, column 2.
	 * \param m33 The value to set at row 3, column 3.
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
	 * \param n The index into the data array.  Should be 0, 1, 2, or 3.
	 * \return The value at the given array index by reference so it can be read or set via the bracket operator.
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
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 * \param f3 The value to set the third floating point number to.
	 * \param f4 The value to set the fourth floating point number to.
	 */
	Float4( float f1, float f2, float f3, float f4 ) {
		data[0] = f1;
		data[1] = f2;
		data[3] = f3;
		data[4] = f4;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param f1 The value to set the first floating point number to.
	 * \param f2 The value to set the second floating point number to.
	 * \param f3 The value to set the third floating point number to.
	 * \param f4 The value to set the fourth floating point number to.
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
	 * \param n The index into the row array.  Should be 0, 1, 2, or 3.
	 * \return The Float4 structure for the given row index by reference so it can be read or set via the bracket operator.
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
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m13 The value to set at row 1, column 3.
	 * \param m14 The value to set at row 1, column 4.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 * \param m23 The value to set at row 2, column 3.
	 * \param m24 The value to set at row 2, column 4.
	 * \param m31 The value to set at row 3, column 1.
	 * \param m32 The value to set at row 3, column 2.
	 * \param m33 The value to set at row 3, column 3.
	 * \param m34 The value to set at row 3, column 4.
	 * \param m41 The value to set at row 4, column 1.
	 * \param m42 The value to set at row 4, column 2.
	 * \param m43 The value to set at row 4, column 3.
	 * \param m44 The value to set at row 4, column 4.
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
	 * \param m11 The value to set at row 1, column 1.
	 * \param m12 The value to set at row 1, column 2.
	 * \param m13 The value to set at row 1, column 3.
	 * \param m14 The value to set at row 1, column 4.
	 * \param m21 The value to set at row 2, column 1.
	 * \param m22 The value to set at row 2, column 2.
	 * \param m23 The value to set at row 2, column 3.
	 * \param m24 The value to set at row 2, column 4.
	 * \param m31 The value to set at row 3, column 1.
	 * \param m32 The value to set at row 3, column 2.
	 * \param m33 The value to set at row 3, column 3.
	 * \param m34 The value to set at row 3, column 4.
	 * \param m41 The value to set at row 4, column 1.
	 * \param m42 The value to set at row 4, column 2.
	 * \param m43 The value to set at row 4, column 3.
	 * \param m44 The value to set at row 4, column 4.
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

	//undocumented
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

/*! Stores a color along with alpha translucency */
struct Color4 {
	float r; /*!< The red component of this color.  Should be between 0.0f and 1.0f. */ 
	float g; /*!< The green component of this color.  Should be between 0.0f and 1.0f. */ 
	float b; /*!< The blue component of this color.  Should be between 0.0f and 1.0f. */ 
	float a; /*!< The alpha translucency component of this color.  Should be between 0.0f and 1.0f. */ 

	/*! Default constructor */
	Color4() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param r The value to set the red component of this color to.  Should be between 0.0f and 1.0f.
	 * \param g The value to set the green component of this color to. Should be between 0.0f and 1.0f.
	 * \param b The value to set the blue component of this color to.  Should be between 0.0f and 1.0f.
	 * \param a The value to set the alpha translucency component of this color to.  Should be between 0.0f and 1.0f.
	 */
	Color4(float r, float g, float b, float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param r The value to set the red component of this color to.  Should be between 0.0f and 1.0f.
	 * \param g The value to set the green component of this color to. Should be between 0.0f and 1.0f.
	 * \param b The value to set the blue component of this color to.  Should be between 0.0f and 1.0f.
	 * \param a The value to set the alpha translucency component of this color to.  Should be between 0.0f and 1.0f.
	 */
	void Set(float r, float g, float b, float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

/*! Represents a quaternion - a 4D extention of complex numbers used as an alternitive to matrices to represent rotation.*/
struct Quaternion {
	float w; /*!< The W scalar component of this Quaternion. */ 
	float x; /*!< The X vector component of this Quaternion. */ 
	float y; /*!< The Y vector component of this Quaternion. */ 
	float z; /*!< The Z vector component of this Quaternion. */ 

	/*! Default constructor. */
	Quaternion() {}

	/*! This constructor can be used to set all values in this structure during initialization
	 * \param w The value to set the W scalar component of this quaternion to.
	 * \param x The value to set the X vector component of this quaternion to.
	 * \param y The value to set the Y vector component of this quaternion to.
	 * \param z The value to set the Z vector component of this quaternion to.
	 */
	Quaternion(float w, float x, float y, float z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	/*! This function can be used to set all values in the structure at the same time.
	 * \param w The value to set the W scalar component of this quaternion to.
	 * \param x The value to set the X vector component of this quaternion to.
	 * \param y The value to set the Y vector component of this quaternion to.
	 * \param z The value to set the Z vector component of this quaternion to.
	 */
	void Set(float w, float x, float y, float z) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

/*! Represents a bounding box - the smallest rectangular shape that a particular node can fit inside. */
struct BoundingBox {
	bool isUsed; /*!< Determines whether this bounding box is used or not.  If this value is true, the other members of this structure are significant.  If false, they are ignored. */ 
	int unknownInt; /*!< An integer whos function is still unknown. */
	Vector3 translation; /*!< The translation vector (position relative to the origin) of this bounding box. */
	Matrix33 rotation; /*!< The rotation of this bounding box expressed as a 3x3 matrix. */
	Vector3 radius; /*!< A vector containing the radius of this box in the direction of each axis, X, Y, and Z. */
};

/*! Holds an integer that may or may not be used. */
struct ConditionalInt {
	bool isUsed; /*!< Determines whether the integer contained within this structure is used or not.  If this value is true, the integer is significant.  If false, it is ignored. */ 
	int unknownInt; /*!< The integer value which may or may not be in use.  Its function is unknown. */ 
};

/*! Stores texture source data.  Specifies where to find the image data; in an external file, or within a NiPixelData block. */
struct TexSource {
	bool useExternal; /*!< Specifies whether to use an external file for the texture or not.  If true, an external file is used.  If false, the image data is stored within a NiPixelData block.  This block can be retrieved by using the asLink function on the same attribute. */ 
	unsigned char unknownByte; /*!< A byte whos function is unknown. */
	string fileName; /*!< The filename of the texture, if stored externally.  Can be an image file such as a TGA, BMP, or DDS file, or another NIF file which stores the image data within a NiPixelData block. */ 
};

/*! Stores one skin weight of a vertex by number. */
struct SkinWeight {
	unsigned short vertexNum; /*!< The vertex number that this weight is for. */
	float vertexWeight; /*!< The amount a particular bone affects the movement of this vertex.  Should be a number between 0.0f and 1.0f. */
};

#undef near
#undef far

/*! Represents the range where a Level of Detail is visible. */
struct LODRange {
	float near; /*!< The closest distance that an LOD range is visible. */
	float far; /*!< The farthest distance that an LOD range is visible. */
};

/*! Stores an animation key and the time in the animation that it takes affect. It is a template class so it can hold any kind of data as different blocks key different sorts of information to the animation timeline.*/
template <class T> 
struct Key {
	float time; /*!< The time on the animation timeline that this keyframe takes affect. */ 
	T data; /*!< The data being keyed to the timeline. */ 
	T forward_tangent; /*!< A piece of data of the same type as is being keyed to the time line used as the forward tangent in quadratic interpolation.  Ignored if key type is set as something else. */ 
	T backward_tangent; /*!< A piece of data of the same type as is being keyed to the time line used as the backward tangent in quadratic interpolation.  Ignored if key type is set as something else. */ 
	float tension; /*!< The amount of tension to use in tension, bias, continuity interpolation.  Ignored if key type is something else.*/
	float bias; /*!< The amount of bias to use in tension, bias, continuity interpolation.  Ignored if key type is something else.*/
	float continuity; /*!< The amount of continuity to use in tension, bias, continuity interpolation.  Ignored if key type is something else.*/
};

//--Main Interfaces--//

/*! The base interface for all NIF blocks. 
 * \sa blk_ref, CreateBlock
 */
class IBlock{
public:
	IBlock( ){}
	virtual ~IBlock() {}

	/*! Returns A new block that contains all the same data that this block does, but occupies a different part of memory.  The data stored in a NIF file varies from version to version.  Usually you are safe with the default option (the highest availiable version) but you may need to use an earlier version if you need to clone an obsolete piece of information.
	 * \param version The version number to use in the memory streaming operation.  Default is the highest version availiable.
	 * \return A cloned copy of this block as a new block.
	 * \sa CreateBlock
	 */
	virtual blk_ref Clone( unsigned int version = 0xFFFFFFFF ) = 0;

	/*! Returns the last known block number.  Block numbers are set automatically when a Nif file is first read and again each time a tree is written.
	 * \return The last known block number.  Will not update until the block is written to a file.
	 * \sa WriteNifTree, blk_ref::get_index
	 */
	virtual int GetBlockNum() const = 0;

	/*!
	 * Used to retrieve the first parent that was linked to this block.
	 * \return A block reference to the first parent that was linked to this block.  If there is no parent, a null reference is returned.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * blk_ref parent_blk = my_block->GetParent();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * parent_blk =  block.GetParent()
	 * \endcode
	 * 
	 * \sa IAttr::Set(blk_ref const &), IAttr::AddLink, IAttr::AddLinks, IAttr::RemoveLinks, IAttr::ClearLinks
	 */
	virtual blk_ref GetParent() const = 0;

	/*!
	 * Summarizes the information contained in this block in English.
	 * \return A string containing a summary of the information within the block in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * cout << my_block->asString();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * print block.asString()
	 * \endcode
	 * 
	 * \sa IAttr::asString, SetVerboseMode
	 */
	virtual string asString() const = 0;

	/*!
	 * Used to determine a block’s type.  These type strings are the same as the class names of the blocks in the <a href = "http://niftools.sourceforge.net/docsys/">NIF File Format Browser</a>.
	 * \return A string containing the type of the block.  Ex. NiNode, NiTriShapeData, NiParticleSystemController, etc.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * cout << my_block->GetBlockType();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * print block.GetBlockType()
	 * \endcode
	 * 
	 * \sa CreateBlock
	 */
	virtual string GetBlockType() const = 0;

	/*!
	 * Used to determine whether this block is controllable - i.e. a controller can animate it.  This means it decends from the AControllable class in the <a href = "http://niftools.sourceforge.net/docsys/">NIF File Format Browser</a>.
	 * \return True if the block is controllable.  False otherwise.
	 * \sa IBlock::IsController, QueryNode
	 */
	virtual bool IsControllable() const = 0;

	/*!
	 * Used to determine whether this block is an animation controller.  This means it decends from the AController class in the <a href = "http://niftools.sourceforge.net/docsys/">NIF File Format Browser</a>.
	 * \return True if the block is an animation controller.  False otherwise.
	 * \sa IBlock::IsControllable, QueryNode
	 */
	virtual bool IsController() const = 0;

	//--Attribute Functions--//

	/*!
	 * Used to get an attribute reference from a block by name.
	 * \param attr_name The name of the attribute you are requesting.  Ex. Translation, Bounding Box, Unknown Int 1, ec.
	 * \return If the attribute exits in the block, a reference to it is returned.  Otherwise a null reference is returned.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * attr_ref my_attr = my_block["NiNode"]; // Shortcut using [] operator
	 * my_attr = my_block->GetAttr("NiNode"); // Same thing but longer
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * my_attr = my_block["NiNode"] # Shortcut using __getitem__ operator
	 * my_attr = my_block.GetAttr("NiNode") # Same thing but longer
	 * \endcode
	 * 
	 * \sa IBlock::GetAttrs, attr_ref, blk_ref::operator[]
	 */
	virtual attr_ref GetAttr(string const & attr_name) const = 0;

	/*!
	 * Used to get a vector holding a reference to every all attribute contained in a block.
	 * \return A vector of references for the complete list of attributes contained within a block.  The list can then be used to visit each attribute.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * vector<attr_ref> attr_list = my_block->GetAttrs();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * attr_list = my_block.GetAttrs();
	 * \endcode
	 * 
	 * \sa IBlock::GetAttr, attr_ref
	 */
	virtual vector<attr_ref> GetAttrs() const = 0;

	//--Link Function--//

	/*!
	 * Used to retrieve all blocks that the current block is linked to through <i>all</i> attributes.
	 * \return A list of references to blocks that this attribute links its owner block to.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * list<blk_ref> attr_list = my_block->GetLinks();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * attr_list = my_block.GetLinks()
	 * \endcode
	 * 
	 * \sa IAttr::asLink, IAttr::asLinkList, IAttr::FindLink
	 */
	virtual list<blk_ref> GetLinks() const = 0;

	//--To check for specialized Interfaces--//

	/*!
	 * Used to query for advanced block interfaces such as INode and IShapeData.  This function is not availiable from Python; you will need to use one of the many shorthand Query functions such as QueryNode and QueryShapeData.
	 * \param id The ID constant of the interface you're querying, such as ID_NODE or ID_SHAPE_DATA.
	 * \return If this block implements the requested interface, a pointer to it is returned.  Otherwise zero is returned - a null pointer.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * block = CreateBlock("NiNode");
	 * INode * node = (INode*)block->QueryInterface(ID_NODE);
	 * \endcode
	 * 
	 * \sa QueryShapeData, QueryTriShapeData, QuerySkinData, QueryNode, QueryKeyframeData, QueryTextKeyExtraData, QueryMorphData, QueryTriStripsData, QueryColorData, QueryFloatData, QueryPosData
	 */
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

/*! The base interface for all NIF attributes.
 * \sa attr_ref
 */
class IAttr {
public:
	IAttr() {}
	virtual ~IAttr() {}

	/*!
	 * Used to determine the type of an attribute at runtime.
	 * \return An AttrType constant reffering to the type of the attribute. Ex. attr_float, attr_texture, attr_byte, etc.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * AttrType attr_type = my_block["Scale"]->GetType();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * attr_type = my_block["Scale"].GetType()
	 * \endcode
	 * 
	 * \sa IBlock::GetBlockType
	 */
	virtual AttrType GetType() const = 0;

	/*!
	 * Used to determine an attribute’s friendly name.
	 * \return A string that contains the friendly name of the attribute.  This is the same name used with the IBlock::GetAttr function to retrieve an attribute. Ex. Scale, Texture, Skeleton Root, etc.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * vector<attr_ref> attr_list = my_block->GetAttrs();
	 * for ( int i = 0; i < attr_list.size(); ++i ) {
     *	cout << attr_list[i]->GetName() << endl;
	 * }
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * attr_list = my_block.GetAttrs()
	 * for attr in attr_list:
     *	print attr.GetName()
	 * \endcode
	 * 
	 * \sa IBlock::GetBlockType
	 */
	virtual string GetName() const = 0;

	virtual void Read( istream& in, unsigned int version ) = 0;
	virtual void Write( ostream& out, unsigned int version ) const = 0;

	//--Getters--//

	/*!
	 * Used to get a copy of the integer value stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the integer value stored in this attribute.
	 */
	virtual int asInt() const = 0;

	/*!
	 * Used to get a copy of the floating point value stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the floating point value stored in this attribute.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * float scale = my_block["Scale"]; // Shortcut using overloaded float operator
	 * scale = my_block["Scale"]->asFloat();  // Same thing but longer
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * scale = my_block["Scale"].asFloat() # shortcut not available due to Python assignment semantics
	 * \endcode
	 */
	virtual float asFloat() const = 0;

	/*!
	 * Used to get a copy of the Float3 structure stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the Float3 structure stored in this attribute.
	 */
	virtual Float3 asFloat3() const = 0;

	/*!
	 * Used to get a copy of the Float4 structure stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the Float4 structure stored in this attribute.
	 */
	virtual Float4 asFloat4() const = 0;

	/*!
	 * Used to get a copy of the text string stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the text string stored in this attribute.
	 */
	virtual string asString() const = 0;

	/*!
	 * Used to get a copy of the Matrix33 structure stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the Matrix33 structure stored in this attribute.
	 */
	virtual Matrix33 asMatrix33() const = 0;

	/*!
	 * Used to get a block reference to the block linked through this attribute to its owner block.  Raises an exception if the attribute does not store this type of value.
	 * \return A block reference to the block linked through this attribute to its owner block.  If no block is linked through this attribute, a null reference is returned.
	 */
	virtual blk_ref asLink() const = 0;

	/*!
	 * Used to get a copy of the TexSource structure stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the TexSource structure stored in this attribute.
	 */
	virtual TexSource asTexSource() const = 0;

	/*!
	 * Used to get a copy of the BoundingBox structure stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the BoundingBox structure stored in this attribute.
	 */
	virtual BoundingBox asBoundingBox() const = 0;

	/*!
	 * Used to get a copy of the ConditionalInt structure stored in an attribute.  Raises an exception if the attribute does not store this type of value.
	 * \return A copy of the ConditionalInt structure stored in this attribute.
	 */
	virtual ConditionalInt asConditionalInt() const = 0;

	/*!
	 * Used to retrieve a list of all the blocks linked through this attribute to its owner block.  Raises an exception if the attribute does not store this type of value.
	 * \return A list of all the blocks linked through this attribute to its owner block. The list will be empty if no blocks are linked through this attribute.
	 */
	virtual list<blk_ref> asLinkList() const = 0;

	//--Setters--//

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 */
	virtual void Set( int val ) = 0;

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 * 
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * my_block["Scale"] = 0.7f; //Shortcut using overloaded = operator
	 * my_block["Scale"]->Set(0.7f);  //Same thing but longer
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * my_block["Scale"] = 0.7 # Shortcut using overloaded __setitem__ operator
	 * my_block["Scale"].Set(0.7) # Same thing but longer
	 * \endcode
	 */
	virtual void Set( float val ) = 0;

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 */
	virtual void Set( Float3 const & val ) = 0;

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 */
	virtual void Set( Float4 const & val ) = 0;

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 */
	virtual void Set( string const & val ) = 0;

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 */
	virtual void Set( Matrix33 const & val ) = 0;

	/*!
	 * Used to retrieve the block that the current block is linked to through this attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This is the block to be linked to the block which owns this attribute. Passing a null block reference will break the link.
	 *
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * blk_ref new_controller = CreateBlock("NiKeyframeController");
	 * my_block["Controller"] = new_controller; //Shortcut using overloaded = operator
	 * my_block["Controller"]->Set(new_controller);  //Same thing but longer
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * new_controller = CreateBlock("NiKeyframeController")
	 * my_block["Controller"].Set(new_controller) #shortcuts not available
	 * \endcode
	 */
	virtual void Set( blk_ref const & val ) = 0;

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 */
	virtual void Set( TexSource const & val ) = 0;

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 */
	virtual void Set( BoundingBox const & val ) = 0;

	/*!
	 * Used to change the value stored in an attribute.  Raises an exception if the attribute does not store the type of value that the Set function is called on.
	 * \param val This value will be copied into the attribute and stored.
	 */
	virtual void Set( ConditionalInt const & val ) = 0;

	//--Link functions--//

	/*!
	 * Used to determine whether this attribute can store links or not.  Several attribute types can store links, but with this function you can quickly tell if any links are within an attribute.
	 * \return True if this attribute can store one or more links. False if it cannot store any links.
	 * \sa IAttr:Set( blk_ref const & ), IAttr::asLink, IAttr::asLinkList, IAttr::AddLink, IAttr::AddLinks, IAttr::ClearLinks, IAttr::RemoveLinks, IAttr::FindLink
	 */
	virtual bool HasLinks() const = 0;

	/*!
	 * Used to add a link to this attribute’s list of blocks that are linked to its owner block.
	 * \param block A reference to the block to add to the list of blocks that are linked to this attribute’s owner block.
	 *
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * blk_ref block2 = CreateBlock("NiNode");
	 * my_block["Children"]->AddLink(block2);
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * block2 = CreateBlock("NiNode")
	 * my_block["Children"].AddLink(block2);
	 * \endcode
	 * \sa IAttr:Set( blk_ref const & ), IAttr::HasLinks, IAttr::asLink, IAttr::asLinkList, IAttr::AddLinks, IAttr::ClearLinks, IAttr::RemoveLinks, IAttr::FindLink
	 */
	virtual void AddLink( blk_ref const & block ) = 0;

	/*!
	 * Used to add several links at once to this attribute’s list of blocks that are linked to its owner block.
	 * \param new_links A list of block references to add to the list of blocks that are linked to this attribute’s owner block.
	 *
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * list<blk_ref> blk_list;
	 * blk_list.push_back( CreateBlock("NiNode") );
	 * blk_list.push_back( CreateBlock("NiTriShape") );
	 * my_block["Children"]->AddLinks(blk_list);
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * blk_list = ( CreateBlock("NiNode"), CreateBlock("NiTriShape") )
	 * my_block["Children"].AddLinks(blk_list)
	 * \endcode
	 * \sa IAttr:Set( blk_ref const & ), IAttr::HasLinks, IAttr::asLink, IAttr::asLinkList, IAttr::AddLink, IAttr::ClearLinks, IAttr::RemoveLinks, IAttr::FindLink
	 */
	virtual void AddLinks( list<blk_ref> const & new_links ) = 0;

	/*!
	 * Used to remove <i>all</i> links from the owner block of this attribute to any other block.
	 *
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * my_block->ClearLinks();
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * my_block.ClearLinks();
	 * \endcode
	 * \sa IAttr:Set( blk_ref const & ), IAttr::HasLinks, IAttr::asLink, IAttr::asLinkList, IAttr::AddLink, IAttr::AddLinks, IAttr::RemoveLinks, IAttr::FindLink
	 */
	virtual void ClearLinks() = 0;

	/*!
	 * Used to remove all links between a particular block and this attribute’s owner block.  A block should never be linked multiple times to the same block, but this function will remove any accidental duplicates.
	 * \param block A reference to the block whose links are to be removed from this block.
	 *
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * blk_ref block2 = CreateBlock("NiNode");
	 * my_block["Children"]->AddLink(block2);
	 * my_block["Children"]->RemoveLinks(block2);
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * block2 = CreateBlock("NiNode")
	 * my_block.["Children"].AddLink(block2);
	 * my_block.["Children"].RemoveLinks(block2);
	 * \endcode
	 * \sa IAttr:Set( blk_ref const & ), IAttr::HasLinks, IAttr::asLink, IAttr::asLinkList, IAttr::AddLink, IAttr::AddLinks, IAttr::ClearLinks, IAttr::FindLink
	 */
	virtual void RemoveLinks( blk_ref const & block ) = 0;

	/*!
	 * Used to conveniently find the first link of a particular block type.  Especially convenient for property groups which should have only one property of each type.
	 * \param block_type The type of block to search for. Ex. NiMaterialProperty, NiTexturingProperty, NiShadeProperty, etc.
	 *
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * blk_ref material = my_block->FindLink("NiMaterialProperty");
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * material = my_block.FindLink("NiMaterialProperty")
	 * \endcode
	 * \sa IAttr:Set( blk_ref const & ), IAttr::HasLinks, IAttr::asLink, IAttr::asLinkList, IAttr::AddLink, IAttr::AddLinks, IAttr::ClearLinks, IAttr::RemoveLinks, IAttr::FindLink
	 */
	virtual blk_ref FindLink( string const & block_type ) const = 0;

	//Python Operator Overloads
	string __str__() {
		return asString();
	};
};

/*! 
 * An advanced interface for blocks that are nodes.
 * \sa IBlock::QueryInterface, QueryNode
 */
class INode {
public:
	INode() {}
	virtual ~INode() {}

	/*! 
	 * This is a conveniance function that allows you to retrieve the full 4x4 matrix transform of a node.  It accesses the "Rotation," "Translation," and "Scale" attributes and builds a complete 4x4 transformation matrix from them.
	 * \return A 4x4 transformation matrix built from the node's transform attributes.
	 * \sa INode::GetWorldTransform
	 */
	virtual Matrix44 GetLocalTransform() const = 0;

	/*! 
	 * This function will return a transform matrix that represents the location of this node in world space.  In other words, it concatenates all parent transforms up to the root of the scene to give the ultimate combined transform from the origin for this node.
	 * \return The 4x4 world transform matrix of this node.
	 * \sa INode::GetLocalTransform
	 */
	virtual Matrix44 GetWorldTransform() const = 0;

	/*!
	 * This function returns the bind position world matrix.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.
	 * \return The 4x4 world bind position matrix of this node.
	 * \sa INode::GetLocalBindPos, INode::SetWorldBindPos
	 */
	virtual Matrix44 GetWorldBindPos() const = 0;

	/*!
	 * This function sets the bind position of this object relative to the origin.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.  This function must be called on every object in a skin and bones system (the bones and the skinned shapes) in order for skinning information to be written to a Nif file.
	 * \param m The 4x4 world bind position matrix of this node
	 * \sa INode::GetLocalBindPos, INode::GetWorldBindPos
	 */
	virtual void SetWorldBindPos( const Matrix44 & m ) = 0;

	/*! This function returns the bind position world matrix of this node multiplied with the inverse of the bind position world matrix of its parent object if any.  Thus it returns the bind position of the object in local coordinates.  The bind position (also called the rest position) is the position of an object in a skin and bones system before any posing has been done.
	 * \return The 4x4 local bind position matrix of this node.
	 * \sa INode::SetWorldBindPos, INode::GetWorldBindPos
	 */
	virtual Matrix44 GetLocalBindPos() const = 0;
};

/*! An advanced interface for blocks which contain mesh data.
 * \sa IBlock::QueryInterface, QueryShapeData, ITriShapeData, ITriStripsData
 */
class IShapeData {
public:
	IShapeData() {}
	virtual ~IShapeData() {}
	//Counts

	/*! Returns the number of verticies that make up this mesh.  This is also the number of normals, colors, and UV coordinates if these are used.
	 * \return The number of vertices that make up this mesh.
	 * \sa IShapeData::SetVertexCount
	 */
	virtual int GetVertexCount() const = 0;

	/*! Returns the number of texture coordinate sets used by this mesh.  For each UV set, there is a pair of texture coordinates for every vertex in the mesh.  Each set corresponds to a texture entry in the NiTexturingPropery block.
	 * \return The number of texture cooridnate sets used by this mesh.  Can be zero.
	 * \sa IShapeData::SetUVSetCount, ITexturingProperty
	 */
	virtual short GetUVSetCount() const = 0;

	/*! Changes the number of vertices used by this mesh.  If the mesh already contains data, it will be retained so long as the new number is higher than the old number.  Otherwise any verticies above the new number will be deleted.  This also resizes any normal, color, or UV data associated with these verticies.  Triangles and triangle strips that may be attached via other interfaces are not culled of references to newly invalid vertices, however.
	 * \param n The new size of the vertex array.
	 * \sa IShapeData::GetVertexCount
	 */
	virtual void SetVertexCount(int n) = 0;

	/*! Changes the number of UV sets used by this mesh.  If he new size is smaller, data at the end of the array will be lost.  Otherwise it will be retained.  The number of UV sets must correspond with the number of textures defined in the corresponding NiTexturingProperty block.
	 * \param n The new size of the uv set array.
	 * \sa IShapeData::GetUVSetCount, ITexturingProperty
	 */
	virtual void SetUVSetCount(int n) = 0;

	//Getters

	/*! Used to retrive the vertices used by this mesh.  The size of the vector will be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the vertices used by this mesh.
	 * \sa IShapeData::SetVertices, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	virtual vector<Vector3> GetVertices() const = 0;

	/*! Used to retrive the normals used by this mesh.  The size of the vector will either be zero if no normals are used, or be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the normals used by this mesh, if any.
	 * \sa IShapeData::SetNormals, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	virtual vector<Vector3> GetNormals() const = 0;

	/*! Used to retrive the vertex colors used by this mesh.  The size of the vector will either be zero if no vertex colors are used, or be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \return A vector cntaining the vertex colors used by this mesh, if any.
	 * \sa IShapeData::SetColors, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	virtual vector<Color4> GetColors() const = 0;

	/*! Used to retrive the texture coordinates from one of the texture sets used by this mesh.  The function will throw an exception if a texture set index that does not exist is specified.  The size of the vector will be the same as the vertex count retrieved with the IShapeData::GetVertexCount function.
	 * \param index The index of the texture coordinate set to retrieve the texture coordinates from.  This index is zero based and must be a positive number smaller than that returned by the IShapeData::GetUVSetCount function.  If there are no texture coordinate sets, this function will throw an exception.
	 * \return A vector cntaining the the texture coordinates used by the requested texture coordinate set.
	 * \sa IShapeData::SetUVSet, IShapeData::GetUVSetCount, IShapeData::SetUVSetCount, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	virtual vector<TexCoord> GetUVSet( int index ) const = 0;

	//Setters

	/*! Used to set the vertex data used by this mesh.  The size of the vector must be the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the vertices to replace those in the mesh with.  Note that there is no way to set vertices one at a time, they must be sent in one batch.
	 * \sa IShapeData::GetVertices, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	virtual void SetVertices( const vector<Vector3> & in ) = 0;

	/*! Used to set the normal data used by this mesh.  The size of the vector must either be zero, or the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the normals to replace those in the mesh with.  Note that there is no way to set normals one at a time, they must be sent in one batch.  Use an empty vector to signify that this mesh will not be using normals.
	 * \sa IShapeData::GetNormals, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	virtual void SetNormals( const vector<Vector3> & in ) = 0;

	/*! Used to set the vertex color data used by this mesh.  The size of the vector must either be zero, or the same as the vertex count retrieved with the IShapeData::GetVertexCount function or the function will throw an exception.
	 * \param in A vector containing the vertex colors to replace those in the mesh with.  Note that there is no way to set vertex colors one at a time, they must be sent in one batch.  Use an empty vector to signify that this mesh will not be using vertex colors.
	 * \sa IShapeData::GetColors, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	virtual void SetColors( const vector<Color4> & in ) = 0;

	/*! Used to set the texture coordinate data from one of the texture sets used by this mesh.  The function will throw an exception if a texture set index that does not exist is specified.  The size of the vector must be the same as the vertex count retrieved with the IShapeData::GetVertexCount function, or the function will throw an exception.
	 * \param index The index of the texture coordinate set to retrieve the texture coordinates from.  This index is zero based and must be a positive number smaller than that returned by the IShapeData::GetUVSetCount function.  If there are no texture coordinate sets, this function will throw an exception.
	 * \param in A vector containing the the new texture coordinates to replace those in the requested texture coordinate set.
	 * \sa IShapeData::GetUVSet, IShapeData::GetUVSetCount, IShapeData::SetUVSetCount, IShapeData::GetVertexCount, IShapeData::SetVertexCount.
	 */
	virtual void SetUVSet( int index, const vector<TexCoord> & in ) = 0;
};

/*! An advanced interface for blocks which contain mesh data which includes triangle faces.
 * \sa IBlock::QueryInterface, QueryTriShapeData, IShapeData, ITriStripsData
 */
class ITriShapeData {
public:
	ITriShapeData() {}
	virtual ~ITriShapeData () {}

	//Match Detection

	/*! Used to turn match detection mode on and off.  When match detection mode is on, a list of all the vertices that have identical positions are stored in the file.  This may improve performance but is not well understood.
	 * \param choice True to enable match detection mode, false to disable it.
	 * \sa ITriShapeData::GetMatchDetectionMode
	 */
	virtual void SetMatchDetectionMode( bool choice ) = 0;

	/*! Used to query the current match detection mode.  When match detection mode is on, a list of all the vertices that have identical positions are stored in the file.  This may improve performance but is not well understood.
	 * \return True if match detection mode is on, false otherwise.
	 * \sa ITriShapeData::GetMatchDetectionMode
	 */
	virtual bool GetMatchDetectionMode() const = 0;
	
	//Getters

	/*! Returns the triangle faces that make up this mesh.
	 * \return A vector containing the triangle faces that make up this mesh.
	 * \sa ITriShapeData::SetTriangles
	 */
	virtual vector<Triangle> GetTriangles() const = 0;

	//Setters

	/*! Replaces the triangle face data in this mesh with new data.
	 * \param in A vector containing the new face data.  Maximum size is 65,535.
	 * \sa ITriShapeData::GetTriangles
	 */
	virtual void SetTriangles( const vector<Triangle> & in ) = 0;
};

/*! An advanced interface for blocks which contain mesh data which includes triangle faces arranged into strips for better performance.  Apparently cannot be used for meshes whos triangles are used in collision tests.
 * \sa IBlock::QueryInterface, QueryTriStripsData, IShapeData, ITriShapeData
 */
class ITriStripsData {
public:
	ITriStripsData() {}
	virtual ~ITriStripsData () {}

	//Counts

	/*! Used to get the number of triangle strips that this mesh is divided into.
	 * \return The number of triangle strips used by this mesh.
	 * \sa ITriStripData::SetStripCount
	 */
	virtual short GetStripCount() const = 0;

	/*! Used to resize the triangle strips array.  If the new size is smaller, strips at the end of the array will be deleted.
	 * \param n The new size of the triangle strips array.
	 * \sa ITriStripData::GetStripCount
	 */
	virtual void SetStripCount( int n ) = 0;

	//Getters

	/*! This is a conveniance function which returns all triangle faces in all triangle strips that make up this mesh.  It is similar to the ITriShapeData::GetTriangles function.
	 * \return A vector containing all the triangle faces from all the triangle strips that make up this mesh.
	 * \sa ITriShapeData::GetTriangles, ITriStripsData::GetStrip, ITriStripsData::SetStrip
	 */
	virtual vector<Triangle> GetTriangles() const = 0;

	/*! Used to retrieve all the triangles from a specific triangle strip.
	 * \param index The index of the triangle strip to retrieve the triangles from.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
	 * \return A vector containing all the triangle faces from the triangle strip specified by index.
	 * \sa ITriStripsData::SetStrip, ITriStripsData::GetTriangles
	 */
	virtual vector<short> GetStrip( int index ) const = 0;
	
	//Setter

	/*! Used to set the triangle face data in a specific triangle strip.
	 * \param index The index of the triangle strip to set the face data for.  This is a zero-based index which must be a positive number less than that returned by NiTriStripsData::GetStripCount.
	 * \sa ITriStripsData::GetStrip, ITriStripsData::GetTriangles
	 */
	virtual void SetStrip( int index, const vector<short> & in ) = 0;
};

/*! An advanced interface for blocks which contain skin weight and bone data.
 * \sa IBlock::QueryInterface, QuerySkinData, IShapeData, ITriShapeData
 */
class ISkinData {
public:
	ISkinData() {}
	virtual ~ISkinData () {}

	/*! Used to retrieve a list of all the bones that influence this skin
	 * \return A vector containing references to all the node blocks which act as bone influences on this skin.
	 * \sa ISkinData::AddBone, ISkinData::RemoveBone, ISkinData::GetWeights
	 */
	virtual vector<blk_ref> GetBones() const = 0;

	/*! Used to retrieve the skin weights associated with a specific bone
	 * \param bone A blk_ref pointing to one of the node blocks which acts as a bone influence on this skin that's related weights are to be retrieved.
	 * \return A map of ints to floats.  The integers are the vertex number and the floats are the percentage influence (between 0.0 and 1.0) that the specified bone has on that vertex.  Not all vertices will be influenced by all bones.
	 * \sa ISkinData::GetBones, ISkinData::AddBone, ISkinData::RemoveBone
	 */
	virtual map<int, float> GetWeights( const blk_ref & bone ) const = 0;

	/*! Adds a new bone influence to this skin alone with all its weight information.  If a bone that already influences the skin is specified, the weight data will be overwritten.
	 * \param bone A blk_ref pointing to a node blocks which is to be added as a bone influence on this skin.
	 * \param in A map of ints to floats.  The integers are the vertex number and the floats are the percentage influence (between 0.0 and 1.0) that the specified bone has on that vertex.  Not all vertices need to be influenced by all bones.
	 * \sa ISkinData::RemoveBone, ISkinData::GetBones, ISkinData::GetWeights
	 */
	virtual void AddBone( const blk_ref & bone, map<int, float> const & in ) = 0;

	/*! Removes a bone influence and deletes associated vertex weight information.
	 * \param bone A blk_ref pointing to a node blocks which is to be removed as a bone influence on this skin.
	 * \sa ISkinData::AddBone, ISkinData::GetBones
	 */
	virtual void RemoveBone( const blk_ref & bone ) = 0;
};

/*! An advanced interface for blocks with keyframe data.
 * \sa IBlock::QueryInterface, QueryKeyframeData
 */
class IKeyframeData {
public:
	IKeyframeData() {}
	virtual ~IKeyframeData () {}

	//Rotate

	/*! Retrieves the type of rotation interpolation being used.
	 * \return The rotation key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetRotateType
	 */
	virtual KeyType GetRotateType() const = 0;

	/*! Sets the type of rotation interpolation being used.  Does not affect existing key data.
	 * \param t The new rotation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetRotateType
	 */
	virtual void SetRotateType( KeyType t ) = 0;

	/*! Retrieves the rotation key data.
	 * \return A vector containing Key<Quaternion> data which specify rotation over time.
	 * \sa IKeyframeData::SetRotateKeys, Key
	 */
	virtual vector< Key<Quaternion> > GetRotateKeys() const = 0;

	/*! Sets the rotation key data.
	 * \param keys A vector containing new Key<Quaternion> data which will replace any existing data.
	 * \sa IKeyframeData::GetRotateKeys, Key
	 */
	virtual void SetRotateKeys( const vector< Key<Quaternion> > & keys ) = 0;

	//Translate

	/*! Retrieves the type of translation interpolation being used.
	 * \return The translation key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetTranslateType
	 */
	virtual KeyType GetTranslateType() const = 0;

	/*! Sets the type of translation interpolation being used.  Does not affect existing key data.
	 * \param t The new translation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetTranslateType
	 */
	virtual void SetTranslateType( KeyType t ) = 0;

	/*! Retrieves the translation key data.
	 * \return A vector containing Key<Vector3> data which specify translation over time.
	 * \sa IKeyframeData::SetTranslateKeys, Key
	 */
	virtual vector< Key<Vector3> > GetTranslateKeys() const = 0;

	/*! Sets the translation key data.
	 * \param keys A vector containing new Key<Vector3> data which will replace any existing data.
	 * \sa IKeyframeData::GetTranslateKeys, Key
	 */
	virtual void SetTranslateKeys( const vector< Key<Vector3> > & keys ) = 0;

	//Scale

	/*! Retrieves the type of scale interpolation being used.
	 * \return The scale key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetTranslateType
	 */
	virtual KeyType GetScaleType() const = 0;

	/*! Sets the type of scale interpolation being used.  Does not affect existing key data.
	 * \param t The new scale key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetScaleType
	 */
	virtual void SetScaleType( KeyType t ) = 0;

	/*! Retrieves the scale key data.
	 * \return A vector containing Key<float> data which specify scale over time.
	 * \sa IKeyframeData::SetScaleKeys, Key
	 */
	virtual vector< Key<float> > GetScaleKeys() const = 0;

	/*! Sets the scale key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa IKeyframeData::GetScaleKeys, Key
	 */
	virtual void SetScaleKeys( const vector< Key<float> > & keys ) = 0;
};

/*! An advanced interface for NiTextKeyExtraData blocks.  These blocks hold a list of textual notes and at which time they take effect which are used for designating the start and stop of animations and the triggering of sounds.
 * \sa IBlock::QueryInterface, QueryTextKeyExtraData
 */
class ITextKeyExtraData {
public:
	ITextKeyExtraData() {}
	virtual ~ITextKeyExtraData () {}

	/*! Retrieves the text note key data.
	 * \return A vector containing Key<string> data which specify text note over time.
	 * \sa IKeyframeData::SetKeys, Key
	 */
	virtual vector< Key<string> > GetKeys() const = 0;

	/*! Sets the text note key data.
	 * \param keys A vector containing new Key<string> data which will replace any existing data.
	 * \sa IKeyframeData::GetKeys, Key
	 */
	virtual void SetKeys( const vector< Key<string> > & keys ) = 0;

};

/*! An advanced interface for NiBoolData blocks.  These blocks contain an array of bool keys.
 * \sa IBlock::QueryInterface, QueryBoolData
 */
class IBoolData {
public:
	IBoolData() {}
	virtual ~IBoolData () {}

	/*! Retrieves the type of boolean interpolation being used.
	 * \return The boolean key type specifing the type of interpolation being used.
	 * \sa IBoolData::SetKeyType
	 */
	virtual KeyType GetKeyType() const = 0;

	/*! Sets the type of boolean interpolation being used.  Does not affect existing key data.
	 * \param t The new boolean key type specifing the type of interpolation to be used.
	 * \sa IBoolData::GetKeyType
	 */
	virtual void SetKeyType( KeyType t ) = 0;

	/*! Retrieves the boolean key data.
	 * \return A vector containing Key<unsigned char> data which specify boolean values over time.
	 * \sa IBoolData::SetKeys, Key
	 */
	virtual vector< Key<unsigned char> > GetKeys() const = 0;

	/*! Sets the boolean key data.
	 * \param keys A vector containing new Key<unsigned char> data which will replace any existing data.
	 * \sa IBoolData::GetKeys, Key
	 */
	virtual void SetKeys( const vector< Key<unsigned char> > & keys ) = 0;
};

/*! An advanced interface for NiColorData blocks.  These blocks contain an array of color keys.
 * \sa IBlock::QueryInterface, QueryColorData
 */
class IColorData {
public:
	IColorData() {}
	virtual ~IColorData () {}

	/*! Retrieves the type of color interpolation being used.
	 * \return The color key type specifing the type of interpolation being used.
	 * \sa IColorData::SetKeyType
	 */
	virtual KeyType GetKeyType() const = 0;

	/*! Sets the type of color interpolation being used.  Does not affect existing key data.
	 * \param t The new color key type specifing the type of interpolation to be used.
	 * \sa IColorData::GetKeyType
	 */
	virtual void SetKeyType( KeyType t ) = 0;

	/*! Retrieves the color key data.
	 * \return A vector containing Key<Color4> data which specify color over time.
	 * \sa IColorData::SetKeys, Key
	 */
	virtual vector< Key<Color4> > GetKeys() const = 0;

	/*! Sets the color key data.
	 * \param keys A vector containing new Key<Color4> data which will replace any existing data.
	 * \sa IColorData::GetKeys, Key
	 */
	virtual void SetKeys( const vector< Key<Color4> > & keys ) = 0;
};

/*! An advanced interface for NiBoolData blocks.  These blocks contain an array of float keys.
 * \sa IBlock::QueryInterface, QueryFloatData
 */
class IFloatData {
public:
	IFloatData() {}
	virtual ~IFloatData () {}

	/*! Retrieves the type of float interpolation being used.
	 * \return The float key type specifing the type of interpolation being used.
	 * \sa IFloatData::SetKeyType
	 */
	virtual KeyType GetKeyType() const = 0;

	/*! Sets the type of float interpolation being used.  Does not affect existing key data.
	 * \param t The new float key type specifing the type of interpolation to be used.
	 * \sa IFloatData::GetKeyType
	 */
	virtual void SetKeyType( KeyType t ) = 0;

	/*! Retrieves the float key data.
	 * \return A vector containing Key<float> data which specify float values over time.
	 * \sa IFloatData::SetKeys, Key
	 */
	virtual vector< Key<float> > GetKeys() const = 0;

	/*! Sets the float key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa IFloatData::GetKeys, Key
	 */
	virtual void SetKeys( const vector< Key<float> > & keys ) = 0;
};

/*! An advanced interface for NiPosData blocks.  These blocks contain an array of position keys.
 * \sa IBlock::QueryInterface, QueryPosData
 */
class IPosData {
public:
	IPosData() {}
	virtual ~IPosData () {}

	/*! Retrieves the type of position interpolation being used.
	 * \return The position key type specifing the type of interpolation being used.
	 * \sa IPosData::SetKeyType
	 */
	virtual KeyType GetKeyType() const = 0;

	/*! Sets the type of position interpolation being used.  Does not affect existing key data.
	 * \param t The new position key type specifing the type of interpolation to be used.
	 * \sa IPosData::GetKeyType
	 */
	virtual void SetKeyType( KeyType t ) = 0;

	/*! Retrieves the position key data.
	 * \return A vector containing Key<Vector3> data which specify position over time.
	 * \sa IPosData::SetKeys, Key
	 */
	virtual vector< Key<Vector3> > GetKeys() const = 0;

	/*! Sets the position key data.
	 * \param keys A vector containing new Key<Vector3> data which will replace any existing data.
	 * \sa IPosData::GetKeys, Key
	 */
	virtual void SetKeys( const vector< Key<Vector3> > & keys ) = 0;
};

/*! An advanced interface for blocks which contain morphing animation data.
 * \sa IBlock::QueryInterface, QueryMorphData
 */
class IMorphData {
public:
	IMorphData() {}
	virtual ~IMorphData () {}

	//Counts

	/*! Retrieves the number of verticies used in the morph targets.  This must be the same as the number of verticies in the base mesh that the morph controller for which this block stores data is attatched.  This is not done automatically by Niflib.
	 * \return The number of vertices used in the morph target meshes.
	 * \sa IMorphData::SetVertexCount
	 */
	virtual int GetVertexCount() const = 0;

	/*! Sets the number of verticies used in the morph targets.  This must be the same as the number of verticies in the base mesh that the morph controller for which this block stores data is attatched.  This is not done automatically by Niflib.  If the new size is smaller, vertices at the ends of the morph targets will be lost.
	 * \param n The new size of the morph target's vertex arrays.
	 * \sa IMorphData::GetVertexCount
	 */
	virtual void SetVertexCount( int n ) = 0;

	/*! Retrieves the number of morph targets used by this morph controller data.
	 * \return The number of morph targets used by this morph controller data.
	 * \sa IMorphData::SetMorphCount
	 */
	virtual int GetMorphCount() const = 0;

	/*! Resizes the morph target array used by this morph controller data.  If the new size is smaller, morph targets at the end of the array and all associated data will be lost.
	 * \param n The new size of the morph target array.
	 * \sa IMorphData::GetMorphCount
	 */
	virtual void SetMorphCount( int n ) = 0;

	//Keys

	/*! Retrieves the type of morph interpolation being used by a specific morph target.
	 * \param n The index of the morph to get the interpolation key type from.  A zero-based positive value which must be less than that returned by IMoprhData::GetMorphCount.
	 * \return The morph key type specifing the type of interpolation being used by the specified morph target.
	 * \sa IMorphData::SetMorphKeyType
	 */
	virtual KeyType GetMorphKeyType( int n ) const = 0;

	/*! Sets the type of morph interpolation being used by a specific morph target.  Does not affect existing key data.
	 * \param n The index of the morph to get the interpolation key type from.  A zero-based positive value which must be less than that returned by IMoprhData::GetMorphCount.
	 * \param t The new morph key type specifing the type of interpolation to be used by the specified morph target.
	 * \sa IMorphData::GetMorphKeyType
	 */
	virtual void SetMorphKeyType( int n, KeyType t ) = 0;

	/*! Retrieves the morph key data for a specified morph target.
	 * \return A vector containing Key<float> data which specify the influence of this morph target over time.
	 * \sa IMorphData::SetMorphKeys, Key
	 */
	virtual vector< Key<float> > GetMorphKeys( int n ) const = 0;

	/*! Sets the morph key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data for this morph target.
	 * \sa IMorphData::GetMorphKeys, Key
	 */
	virtual void SetMorphKeys( int n, const vector< Key<float> > & keys ) = 0;
	
	//Morph Targets

	/*! Retrieves the vertex data from the specified morph target
	 * \param n The index of the morph target to retrieve vertex data for.  This is a zero-based index whoes value that must be less than that returned by IMorphData::GetMorphCount.
	 * \return A vector containing the vertices used by this morph target.  The size will be equal to the value returned by IMorphData::GetVertexCount.
	 * \sa IMorphData::SetMorphVerts
	 */
	virtual vector<Vector3> GetMorphVerts( int n) const = 0;

	/*! Sets the vertex data for a specified morph target
	 * \param n The index of the morph target to set vertex data for.  This is a zero-based index whoes value that must be less than that returned by IMorphData::GetMorphCount.
	 * \param in A vector containing the new vertices to be used by this morph target.  The size will be equal to the value returned by IMorphData::GetVertexCount.
	 * \sa IMorphData::SetMorphVerts
	 */
	virtual void SetMorphVerts( int n, const vector<Vector3> & in ) = 0;
};

/*! An advanced interface for NiControllerSequence blocks which serve as the root of KF files in later Nif versions.
 * \sa IBlock::QueryInterface, QueryControllerSequence
 */
class IControllerSequence {
public:
	IControllerSequence() {}
	virtual ~IControllerSequence () {}

	/*! Sets the name and block reference to the NiTextKeyExtraData block which will be used by this controller sequence to specify the keyframe labels or "notes."
	 * \param new_name The name of the NiTextKeyExtraData block to use.
	 * \param new_link The block reference of the NiTextKeyExtraData block to use.
	 * \sa ITextKeyExtraData
	 */
	virtual void SetTextKey( string new_name, blk_ref new_link ) = 0;

	/*! Sets the name, block reference, and controller type to use as a new child to this Kf root node.  The controller type is unnecessary before version 10.2.0.0.  From that version on, these children must be interpolators.  Before that version they will be keyframe controllers.
	 * \param new_name The name to re-link this Kf file child to when it is merged with a Nif file.
	 * \param new_link The block reference of the new Kf file child.
	 * \param controller_type The original controller type that this Kf file child was connected to.  Only applies to versions which use interpolators.
	 * \sa IControllerSequence::ClearKfChildren
	 */
	virtual void AddKfChild( string new_name, blk_ref new_link, string controller_type = "" ) = 0;
	
	/*! Removes all Kf file children from this Kf file root block.
	 * \sa IControllerSequence::AddKfChild
	 */
	virtual void ClearKfChildren() = 0;
};

/*! An advanced interface for the IPalette block which contains a color palette for internally stored paletized textures.
 * \sa IBlock::QueryInterface, QueryPalette
 */
class IPalette {
public:
	IPalette() {}
	virtual ~IPalette() {}

	/*! Retrieves the palette data from this palette block.
	 * \return A vector containing the the colors stored in the palette.
	 * \sa IPalette::SetPalette
	 */
	virtual vector<Color4> GetPalette() const = 0;

	/*! Sets the palette data for this palette block.
	 * \param new_apl A vector containing the the new colors to be stored in the palette.
	 * \sa IPalette::GetPalette
	 */
	virtual void SetPalette( const vector<Color4> & new_pal ) = 0;
};

/*! An advanced interface for the IPixelData block which stores internal textures.
 * \sa IBlock::QueryInterface, QueryPixelData
 */
class IPixelData {
public:
	IPixelData() {}
	virtual ~IPixelData() {}

	/*! Retrieves the height of the texture image stored in this block.
	 * \return The height of the texture image stored in this block.
	 * \sa IPixelData::GetWidth, IPixelData::GetPixelFormat
	 */
	virtual int GetHeight() const = 0;

	/*! Retrieves the width of the texture image stored in this block.
	 * \return The width of the texture image stored in this block.
	 * \sa IPixelData::GetHeight, IPixelData::GetPixelFormat
	 */
	virtual int GetWidth() const = 0;

	/*! Retrieves the pixel format of the texture image stored in this block.
	 * \return The pixel format of the texture image stored in this block.
	 * \sa IPixelData::GetWidth, IPixelData::GetHeight
	 */
	virtual PixelFormat GetPixelFormat() const = 0;

	/*! Deletes all image data and sets a new size and format in preparation for new data to be provided.
	 * \param new_width The width of the new texture image.
	 * \param new_height The height of the new texture image.
	 * \param px_fmt The pixel format of the new texture image.
	 * \sa IPixelData::GetWidth, IPixelData::GetHeight
	 */
	virtual void Reset( int new_width, int new_height, PixelFormat px_fmt ) = 0;
	
	/*! Retrieves the the pixels of the texture image stored in this block.  This function does not work on palettized textures.
	 * \return A vector containing the colors of each pixel in the texture image stored in this block, one row after another starting from the bottom of the image.  The width of the image must be used to interpret them correctly.
	 * \sa IPixelData::SetColors, IPixelData::GetWidth
	 */
	virtual vector<Color4> GetColors() const = 0;

	/*! Sets the the pixels of the texture image stored in this block and optionally generates mipmaps.  This function does not work for palettized textures.
	 * \param new_pixels A vector containing the colors of each new pixel to be set in the texture image stored in this block, one row after another starting from the botom of the image.
	 * \param generate_mipmaps If true, mipmaps will be generated for the new image and stored in the file.
	 * \sa IPixelData::GetColors, IPixelData::GetWidth
	 */
	virtual void SetColors( const vector<Color4> & new_pixels, bool generate_mipmaps ) = 0;
};

/*! An advanced interface for the NiTexturingProperty block which references all textures attatched to meshes which include it in their property list.
 * \sa IBlock::QueryInterface, QueryTexturingProperty, IShapeData
 */
class ITexturingProperty {
public:
	ITexturingProperty() {}
	virtual ~ITexturingProperty () {}

	//Counts

	/*! Retrieves the number of texture slots defined by this texturing propery.  Texture slots may or may not actually contain textures, but each slot has a different meaning so the way a texture is used is dependant upon which slot it is in.
	 * \return The number of texture slots defined by this texturing property.
	 * \sa ITexturingProperty::SetTextureCount
	 */
	virtual int GetTextureCount() const = 0;

	/*! Sets the number of texture slots defined by this texturing propery.  Known valid values are 7 and 8.
	 * \param n The new size of the texture slot array.
	 * \sa ITexturingProperty::GetTextureCount
	 */
	virtual void SetTextureCount( int new_count ) = 0;

	/*! Retrieves the number of extra texture slots defined by this texturing propery.  These only exist in later Nif versions and their function is unknown.
	 * \return The number of extra texture slots defined by this texturing property.
	 * \sa ITexturingProperty::SetExtraTextureCount
	 */
	virtual int GetExtraTextureCount() const = 0;

	/*! Sets the number of extra texture slots defined by this texturing propery.  Often zero.
	 * \param n The new size of the extra texture slot array.
	 * \sa ITexturingProperty::GetExtraTextureCount
	 */
	virtual void SetExtraTextureCount( int new_count ) = 0;
	
	//Textures

	/*! Retrieves the current apply mode for this texturing propery.  This enum value affects the way the textures will be drawn.
	 * \return The current apply mode for this texturing property.
	 * \sa ITexturingProperty::SetApplyMode
	 */
	virtual ApplyMode GetApplyMode() const = 0;

	/*! Sets the current apply mode for this texturing propery.  This enum value affects the way the textures will be drawn.
	 * \param new_val The new apply mode for this texturing property.
	 * \sa ITexturingProperty::GetApplyMode
	 */
	virtual void SetApplyMode( ApplyMode new_val ) = 0;

	/*! Retrieves the texture desription structure that describes a texture by slot number.  The TexType enum is provided to make it easy to select the texture slot with the specific qualities that you want.
	 * \param n The slot number of the texture to get the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \sa ITexturingProperty::SetTexture, TexType
	 */
	virtual TexDesc GetTexture( int n ) const = 0;

	/*! Sets a new description for the texture in the given slot number.  The TexType enum is provided to make it easy to select the texture slot with the specific qualities that you want.
	 * \param n The slot number of the texture to set the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \param new_val Thew new texture descriptoin for the texture at the given slot number.
	 * \sa ITexturingProperty::GetTexture, TexType
	 */
	virtual void SetTexture( int n, TexDesc & new_val ) = 0;

	/*! Retrieves the texture desription structure that describes an extra texture by slot number.  These only exist in the later Nif versions and their function is unknown.
	 * \param n The slot number of the extra texture to get the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetExtraTextureCount.
	 * \sa ITexturingProperty::SetExtraTexture
	 */
	virtual TexDesc GetExtraTexture( int n ) const = 0;

	/*! Sets a new description for the texture in the given slot number.  These only exist in the later Nif versions and their function is unknown.
	 * \param n The slot number of the extra texture to set the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \param new_val Thew new texture descriptoin for the extra texture at the given slot number.
	 * \sa ITexturingProperty::GetTexture, TexType
	 */
	virtual void SetExtraTexture( int n, TexDesc & new_val ) = 0;
	
	//Bump Map

	/*! Retrieves the bump map matrix.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return the bump map matrix.
	 * \sa ITexturingProperty::SetBumpMapMatrix
	 */
	virtual Matrix22 GetBumpMapMatrix() const = 0;

	/*! Sets the bump map matrix.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map matrix.
	 * \sa ITexturingProperty::GetBumpMapMatrix
	 */
	virtual void SetBumpMapMatrix( Matrix22 & new_val ) = 0;

	/*! Retrieves the bump map luma offset.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return The bump map luma offset.
	 * \sa ITexturingProperty::SetLumaOffset
	 */
	virtual float GetLumaOffset() const = 0;

	/*! Sets the bump map luma offset.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map luma offset.
	 * \sa ITexturingProperty::GetLumaOffset
	 */
	virtual void SetLumaOffset( float new_val ) = 0;

	/*! Retrieves the bump map luma scale.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return The bump map luma scale.
	 * \sa ITexturingProperty::SetLumaScale
	 */
	virtual float GetLumaScale() const = 0;

	/*! Sets the bump map luma scale.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map luma scale.
	 * \sa ITexturingProperty::GetLumaScale
	 */
	virtual void SetLumaScale( float new_val ) = 0;
};

//struct ComplexVertex {
//	ComplexVertex() : has_color(false), has_normal(false), vertex_index(0), normal_index(0), color_index(0) {}
//	~ComplexVertex();
//	bool has_color, has_normal;
//	int vertex_index, color_index, normal_index;
//	bool has_base_uv, has_glow_uv;
//	int base_uv_index, glow_uv_index;
//}
//
//struct ComplexFace {
//	vector<ComplexVertex> points;
//	int base_map_index;
//	int glow_map_index;
//};
//
//class ComplexShape {
//	void SetVertices( vector<Vector3> & vertices );
//	void SetUVs( vector<TexCoord> & uvs );
//	void SetColors( vector<Color4> & colors );
//	void SetNormals( vector<Vector3> & normals );
//	void SetBones( vector<blk_ref> & bones );
//	void SetFaces( list< vector< ComplexVertex > > & faces );
//
//	vector<Vector3> GetVertices();
//	vector<TexCoord> GetUVs();
//	vector<Color4> GetColors();
//	vector<Vector3> GetNormals();
//	vector<blk_ref> GetBones();
//	list< vector< ComplexVertex > > GetFaces();
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

//--Attribute Reference--//
/*!
 * Stores a reference to an attribute in a NIF block and offers functions to help use it.
 * \sa IAttr
 */
class attr_ref {
public:
	/*! Default constructor.  Initializes the attribute reference in null state. */
	attr_ref() : _attr(NULL) {}

	attr_ref( IAttr * ptr ) : _attr(ptr) {}

	/*! This operator allows you to use an attribute reference as if it were a pointer to an IAttr interface.  You can call any IAttr function by using it.
	 * \return An IAttr pointer which can be used to call functions.
	 * \sa IAttr
	 */
	IAttr * operator->() const {
		if ( _attr == NULL ) {
			//pointer has not been fixed, throw exception
			throw runtime_error("Attempted to dereference a null Attribute reference.");
		} else {
			return _attr;
		}
	}

	/*!
	 * Used to determine whether an attribute reference is null, i.e. it points to nothing and thus no functions can be called on it.
	 * \return True if the attribute is null and false otherwise.
	 *
	 * <b>Example:</b> 
	 * \code
	 * blk_ref my_block = ReadNifTree("test_in.nif");
	 * attr_ref my_attr = my_block["NiNode"];
	 * if ( my_attr.is_null() == true )
	 *      cout << "Null Attribute" << endl;
	 * \endcode
	 * 
	 * <b>In Python:</b>
	 * \code
	 * my_block = ReadNifTree("test_in.nif")
	 * my_attr = my_block["NiNode"]
	 * if attr.is_null() == True:
	 *      print "Null Attribute"
	 * \endcode
	 */
	bool is_null() const {
		if (_attr == NULL )
			return true;
		else
			return false;
	}
	IAttr * ptr() const {
		return _attr;
	}

	//--Comparison operators--//

	/*! This operator allows you to compare two attribute references to see if they point to the same attribute.  It does not compare the values held by the attributes.
	 * \param rh The right hand operand to the == operator.
	 * \return True if both references point to the same attribute.  False otherwise.
	 */
	bool operator==(attr_ref & rh) const {
		if (_attr == rh._attr)
			return true;
		else
			return false;
	}

	/*! This operator alows you to compare two attribute references to see if they <i>do not</i> point to the same attribute.  It does not compare the values held by the attributes.
	 * \param rh The right hand operand to the != operator.
	 * \return True if both references <i>do not</i> point to the same attribute.  False otherwise.
	 */
	bool operator!=(attr_ref & rh) const {
		if (_attr != rh._attr)
			return true;
		else
			return false;
	}

	/*! This operator is provided to allow associative STL containers to use attribute references as keys.  The comparison is based on the value of the IAtter pointer held by each reference.
	 * \param rh The right hand operand to the < operator.
	 * \return True if the pointer value of the left hand reference holds a pointer value that is less than that held by the right hand operand.  False otherwise.
	 */
	bool operator<(attr_ref & rh) const {
		if (_attr < rh._attr)
			return true;
		else
			return false;
	}

	//--Assignment operators--//

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(int n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(float n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(Float3 const & n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(Float4 const & n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(string const & n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(const char * n) {
		_attr->Set( string(n) );
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(Matrix33 const & n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(blk_ref const & n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(TexSource const & n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(BoundingBox const & n) {
		_attr->Set(n);
		return *this;
	}

	/*! The assignment operators are shorthand for using the IAttr::Set function.  They allow you to set the value contained by the attribute pointed to by this reference by using the = operator instead of calling their Set function through the -> operator.
	 * \param n The new value to set the IAttr attribute to using its Set function.
	 * \return a reference to this attr_ref object.
	 */
	attr_ref & operator=(ConditionalInt const & n) {
		_attr->Set(n);
		return *this;
	}

	//--Conversion fuctions--//

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator int() const { return _attr->asInt(); }

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator float() const { return _attr->asFloat(); }

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator Float3() const { return _attr->asFloat3(); }

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator Float4() const { return _attr->asFloat4(); }

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator string() const { return _attr->asString(); }
	
	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator Matrix33() const { return _attr->asMatrix33(); }

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator blk_ref() const;

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator TexSource() const;

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator BoundingBox() const;

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
	operator ConditionalInt() const;

	/*! The type operators are shorthand for using the IAttr::AsType functions.  They allow you to retrieve the value contained by the attribute pointed to by this reference by using the = operator instead of calling their asType function through the -> operator.
	 * \return the value stored in the attribute stored in this reference by calling its asType function.
	 */
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

/*! An automatic pointer that stores a reference to a particular NIF block.  It uses reference counting to keep track of when a block should be destroyed. 
 * \sa IBlock
 */
class blk_ref {
public:
	/*! Default constructor.  Initializes reference to null state. */
	blk_ref() : _index(-1), _block(NULL) {}
	blk_ref( int index ) : _index(index), _block(NULL) {}
	
	//--Copy Constructor--//

	/*! The copy constructor allows you to copy one block reference to another.  It does not actually makea copy of the data, it only creates a new pointer and increments the reference count of the existing data.
	 * \param rh The right hand operand to the = operator
	 */
	blk_ref(const blk_ref & rh ) {
		_block = rh._block;
		_index = rh._index;

		if ( _block != NULL ) {
			//cout << "Copying from another reference - ";
			//Increment reference count
			_block->AddRef();
		}
	}

	//--Asignment Operator--//

	/*! The asignment operator allows you to assign one block reference to another.  It does not actually make a copy of the data, it only changes the value of one pointer, causing the reference count on the block it originally pointed to to go down, and the reference count of the new block it points to to go up.
	 * \param rh The right hand operand to the = operator
	 * \return a reference to this object.
	 */
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

	//--Equality Operator--//

	/*! The equality operator allows you to determine whether two references point to the same block.  It does not compare data within the blocks.
	 * \param rh The right hand operand to the == opearator.
	 * \return True if both references point to the same block.  False otherwise.
	 */
	bool operator==(const blk_ref & rh) const {
		if ( _block == rh._block && _index == rh._index )
			return true;
		else
			return false;
	}

	// Inequality Operator

	/*! The inequality operator allows you to determine whether two references <i>do not</i> point to the same block.  It does not compare data within the blocks.
	 * \param rh The right hand operand to the != opearator.
	 * \return True if both references <i>do not</i> point to the same block.  False otherwise.
	 */
	bool operator!=(const blk_ref & rh) const {
		return !(*this == rh);
	}

	// Less-Than Operator

	/*! The less-than opearator is provided to allow associative STL containers to use block references as keys.  The comparison is based on the value of the IBlock pointer held by each reference.
	 * \param rh The right hand operand to the < operator.
	 * \return True if the pointer value of the left hand reference holds a pointer value that is less than that held by the right hand operand.  False otherwise.
	 */
	bool operator<( const blk_ref & rh ) const {
		return ( _block < rh._block );
	}
	
	/*!
	 * Used to determine whether a block reference is null, i.e. it points to nothing and thus no functions can be called on it.
	 * \return True if the attribute is null and false otherwise.
	 */
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

	/*! Default destructor.  Automatically decrements reference counts, causing the IBlock to destroy itself if the count drops to zero. */
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

	/*! The dereference operator allows you to use a block reference as if it were a pointer to an IBlock interface.  You can call any IBlock function by using it.
	 * \return An IBlock pointer which can be used to call functions.
	 * \sa IBlock
	 */
	IBlock * operator->() const {
		if ( _block == NULL ) {
			//pointer has not been fixed, throw exception
			cout << *this << endl;
			throw runtime_error("Attempted to dereference a block reference that has not been fixed.");
		} else {
			return _block;
		}
	}

	/*! The bracket operator allows you to use a block reference as if it were an associative array of attribute values.  It is shorthand for calling the IBlock::GetAttr function with the name of the attribute you want to retrieve.
	 * \param index The name of the attribute you want to retrieve with the GetAttr function.  Ex. "Scale," "Skeleton Root," "Controller," etc.
	 * \return An attribute reference pointing to the attribute that was requested.  If the attribute is not present, a null reference is returned.
	 * \sa IBlock::GetAttr
	 */
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

	/*! The << stream operator allows you to use a block reference in standard C++ string stream operations.  It causes a short description of the block that is pointed to by this reference to be writen to the given ostream.  Ex:  NiNode(Block 14) [Pelvis]
	 * \param lh The left hand operand to the << operator, the ostream to write the short description to.
	 * \param rh The right hand operand to the << operator, the blk_ref whos short description is to be written.
	 * \return The same ostream that was given in lh so that stream operations can be concatenated.
	 */
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
	void __setitem__(string index, Float4 value) {
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
	void __setitem__(string index, TexSource const & value) {
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
protected:
	int _index;
	IBlock * _block;
};

/*! Represents a texture description that specifies various properties of the texture that it refers to. The NiTextureSource block that this description refers to can be retrieved by calling asLink on the same attribute. */
struct TexDesc {
	/*! Default constructor.  Sets isUsed to false, clampMode to WRAP_S_WRAP_T, filterMode to FILTER_TRILERP, testureSet to 0, PS2_L to zero, PS2_K to 0xFFB5, and unknownShort to 0x0101.*/
	TexDesc() : isUsed(false), clampMode(WRAP_S_WRAP_T), filterMode(FILTER_TRILERP), textureSet(0),  PS2_L(0), PS2_K(0xFFB5), unknownShort(0x0101) {}
	string asString() const;
	bool isUsed; /*!< Determines whether this texture description is used or not.  If this value is true, the other members of this structure are significant.  If false, they are ignored. */ 
	blk_ref source; /*!< The NiTextureSource block which points to the texture data. > */
	TexClampMode clampMode;  /*!< The texture wraping/clamping mode. */ 
	TexFilterMode filterMode; /*!< The texture filtering mode. */ 
	int textureSet; /*!< Texture set? Usually 0. */ 
	unsigned short PS2_L; /*!< Something to do with Play Station 2 texture filtering.  Usually 0.  Exists up to version 10.2.0.0 */ 
	unsigned short PS2_K; /*!< Something to do with Play Station 2 texture filtering.  Usually 0xFFB5.  Exists up to version 10.2.0.0 */ 
	short unknownShort;  /*!< An unknown short value. Exists up to version 4.1.0.12 */
	//Unknown Block in version 10.1.0.0 and up
	bool hasUnknownData; /*!< If this is true, the unknown5Floats, unknownInt, unknownFloat1, and unknownFloat2 members are significant.  These properties only exist after version 10.1.0.0. */ 
	float unknown5Floats[5]; /*!< 5 unkown floating point values that exist from version 10.1.0.0 on. */ 
	int unknownInt; /*!< An unknown integer value that exists from version 10.1.0.0 on. */ 
	float unknownFloat1; /*!< An unknown floating point value that exists from version 10.1.0.0 on. */ 
	float unknownFloat2; /*!< An unknown floating point value that exists from version 10.1.0.0 on. */ 
};

//--USER GUIDE DOCUMENTATION--//

/*! \mainpage Niflib Documentation
\section user_guide User Guide
- \ref intro_page
- \ref starting_out
- \ref attrs
- \ref link_blks
- \ref adv_interf
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page intro_page Introduction

\section include Including the Library

You probably already know how to include a library, but here’s the basic gist if you don’t:

\subsection cpp C++

If you’re going to use the pre-compiled header file, make sure it is referenced in your project or make file.  Otherwise, make sure all the source code is included in your compile process. Also, make sure you add the location that you place niflib.h to your include directory paths.  With that out of the way, simply include this line at the top of your source code:

\code
#include "niflib.h"
\endcode

\subsection py Python

You should follow the instructions in the readme file that comes with the pre-compiled version of the Python SWIG wrapper for Windows.  Briefly, you will place the _niflib.dll and the niflib.py files in your Python folder.  If you want to compile them yourself you will need to get SWIG 1.3.25 or higher.  There is a make file provided for this purpose.  Once you have these files in the proper position in the Python directory, you can use the library in either of the two standard Python ways:

\code
from niflib import *
\endcode
or
\code
import niflib
\endcode

To save space I will assume in the examples that you have used the first method.  Of course if you use the second, you will have to preface all function calls with niflib.  For example, ReadNifTree() becomes niflib.ReadNifTree().

\section exept Exceptions

Niflib is a very much a C++ library, and therefore it uses exceptions rather than error return codes.  These are a lot more convenient in that you don’t have to use as many if statements, but not everyone understands what they are, so I thought I’d provide enough of an intro to get you along.  C++ exceptions should be mapped to Python exceptions transparently, so this only applies to people using the library via C++.

Very very basically, if you want to check if a Niflib function has failed, and why, wrap it in a try block like this:

\code
try {
    //Niflib Function Call
    blocks = ReadNifList( current_file );
}
catch( exception & e ) {
    cout << "Error: " << e.what() << endl;
    cout << "\a";
    return 0;
}
catch( ... ) {
    cout << "Unknown Exception." << endl;
    return 0;
}
\endcode

The really nice thing about exceptions is that you can place all of your Niflib calls within the try block, and if any one of them fails, execution will jump to the catch block.  If the exception is of the standard C++ type, which Niflib’s are, the first block will catch it, and an error message can be extracted and printed.  Otherwise, it will go to the second block, which is a catch-all statement that will end your program for any other reason.  There are ways to recover from exceptions, but this should be enough to allow you to at least exit gracefully if a function signals an error.

\section stl_temp STL & Templates

Niflib makes quite a bit of use of the standard template library, and also includes at least one template of its own.  You should be familiar with the template syntax for defining variables (ex: template<type>) You should also be familiar with at least the following STL built-in types:  string, vector, list, map.  These types map to Python types seamlessly (string, tuple, tuple, and dictionary respectively), so no understanding of C++ is required for Python users.
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page starting_out Starting Out with Niflib

\section blk_basics NIF Block Basics

NIF files consist of several types of data blocks that store various things and are linked together.  These blocks are stored using blk_ref variables.  blk_ref is short for “Block Reference” and the blk_ref class is a kind of auto pointer similar to a C++ reference in that it does not need to be deleted, but more like a pointer in that it can be changed to point to a new block at any time.

The member functions of the blk_ref class will be covered in detail as they are needed.  There are also overloaded operators that make most of them unnecessary when working through C++.

As long as there is a blk_ref somewhere pointing to a particular block, it will remain in memory.  Therefore, you do not have to worry about freeing the blocks yourself.  You may be curious how many blocks are loaded into memory by the library at any particular time.  You can check with the \ref BlocksInMemory function.

\section rw_files Reading and Writing NIF Files

To check whether NIF file has a valid header, and to make sure that its version is supported, call the \ref CheckNifHeader function. There are two ways to read in a NIF file – as a list of blocks in the order they appear in the file and as the root block of a tree arranged correctly.  Most of the time you will probably want to use the tree method, as this is the only one eligible for writing.  The list method is provided for uses such as Niflyze that need to retrieve all blocks.  Un-supported blocks may not be included in the tree representation if no other blocks reference them.  So you’re going to want to call the \ref ReadNifTree function.

That’s all there is to reading in a NIF file.  If all goes well with the reading process (no exception was thrown), you will have at least one block in memory – the root block of the tree.  You can pass this same block to the \ref WriteNifTree function to create a new NIF file from the representation in memory.  WARNING:  Some features of the NIF format are still un-supported by Niflib, therefore in some cases the exported NIF may either be different from the original, or completely unusable.  DO NOT OVERWRITE THE ORIGINAL NIF FILE.

\section work_blk Working with Blocks

New blocks don’t have to just come from loaded NIF files.  To create a block yourself, you need to know the type of the block you want to create, for example a NiNode, and call the \ref CreateBlock function.

To actually do anything with these blocks, you need to know about the \ref IBlock interface that the block references (blk_ref variables) provide access to.  An interface is a class that consists completely of virtual functions, but all you have to know are the public functions it provides.

\ref IBlock has a lot of functions and I’ll cover each one as they come up.  You can access these functions through a blk_ref variable as if using a pointer by using the -> operator.  In Python you can simply use the dot (.) operator.

You might want a quick summary of what one of the blocks you have read in contains; in this case you can use the \ref IBlock::asString function to get the contents as an English summary.

You will probably also want to know the type of a block at some point.  You can retrieve this with the \ref IBlock::GetBlockType function.

<center>\ref attrs "Next Section >>>"</center>
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page attrs Attributes

Of course, the interesting thing about blocks is the data they contain.  For all the basic block types, this data is stored in attributes.  Each block contains a list of attributes that you can iterate through, examine, and change.  Attributes are passed around in the library via the attr_ref.  Similar to blk_ref, attr_ref contains a reference to a particular attribute and gives you several overloaded operators to make them seem almost like normal variables of all sorts of different types.

You do not create attributes; they are added to NIF blocks automatically when they are created either by reading a NIF file or by the \ref CreateBlock function.  The attributes that a particular block will have depend on its type.  The names of these attributes are analogous to those found in our <a href = "http://niftools.sourceforge.net/docsys/">NIF File Format Browser</a>.  To get an attribute from a block, you generally ask for it by name using the \ref IBlock::GetAttr function.

As you may have noticed from the example if you clicked the link to that function, the attr_ref class has a handy overloaded bracket operator that allows you to get attributes by using bracket notation instead of actually typing out the name of the \ref IBlock::GetAttr function.

You may also have noticed that this function will return a null reference if the attribute you requested does not exist in a particular block.  A null reference is one that points to nothing, and no functions can be called on it.  You can determine whether a particular attr_ref is null by calling the \ref attr_ref::is_null function.

The reason that the GetAttr function does not simply throw an exception if the attribute doesn’t exist is that it can be useful to ask a block whether it has an attribute without ever knowing what it is.  For example, many blocks have identical attributes because they inherit them from abstract blocks in the format documentation.  It might be useful to loop through all blocks in a file and call the \ref IBlock::GetAttr function on each one requesting the “Translate” attribute.  You would then do whatever it was you were trying to do only if the function did not return a null attribute.

You can also get a list of all attributes in a block in the form of an STL vector of attr_ref variables by calling the \ref IBlock::GetAttrs function.

So what are attributes good for?  Basically, they serve as a generic container for different types of data.  An attribute could be a string, or an integer number, or even a whole structure.  I will list the different types of data an attribute can store.


<table><tr><th>Basic C++ Types</th><th>Niflib Basic Types</th><th>Niflib Structures</th></tr>
<tr><td>int<br>
float<br>
string<br>
</td><td>
blk_ref<br>
list<blk_ref><br>
</td><td>
Float3<br>
Matrix33<br>
TexSource<br>
BoundingBox<br>
ConditionalInt<br>
TexDesc<br>
</td></tr></table>

Most of the time, attributes will hold simple data types like C++ types, blk_ref references, or a list of references.  However, sometimes they hold structures.  You may want to take a moment to familiarize yourself with these structures by clicking on their names in the table above.

So how is data stored in Attributes manipulated?  For that we must understand the IAttr interface to which atter_ref variables contain a reference to.

Did you click the link?  Wow, that’s a lot of functions!  But don’t worry, as you may have noticed most of them just do exactly the same thing but for different data types – They get and set data stored within the attribute.  Each data type that I listed above has an asType function and a matching Set function.  Once you understand one, you understand them all.

For example, check out the IAttr::Set(float) function and the IAttr::asFloat function.

From the C++ side, most of this is almost automatic because you can use the overloaded = operator to set attributes, and every type has an overloaded operator for that type so you can omit the function call and everything will usually work out fine.  If you have any trouble, though, you may want to try spelling it out explicitly.  Python has similar shortcuts, but they only work if you access the attribute using a block's bracket operator.  Otherwise, you will have to type out the whole function name.

There are several types of attributes, more than the list above, and each type stores a different type (or types) of values.  Following is a list of attribute types and the type of values they hold:

<table><tr><th>Attribute Type</th><th>Value Types held</th></tr>
<tr><td>attr_alphaformat</td><td>int</td></tr>
<tr><td>attr_applymode</td><td>int</td></tr>
<tr><td>attr_bbox</td><td>BoundingBox</td></tr>
<tr><td>attr_bones</td><td>Automatic.</td></tr>
<tr><td>attr_bumpmap</td><td>TexDesc & blk_ref</td></tr>
<tr><td>attr_byte</td><td>int</td></tr>
<tr><td>attr_color3</td><td>Float3</td></tr>
<tr><td>attr_condint</td><td>ConditionalInt</td></tr>
<tr><td>attr_controllertarget</td><td>Automatic.</td></tr>
<tr><td>attr_flags</td><td>int</td></tr>
<tr><td>attr_float</td><td>float</td></tr>
<tr><td>attr_float3</td><td>Float3</td></tr>
<tr><td>attr_int</td><td>int</td></tr>
<tr><td>attr_lightmode</td><td>int</td></tr>
<tr><td>attr_link</td><td>blk_ref</td></tr>
<tr><td>attr_linkgroup</td><td>vector<blk_ref></td></tr>
<tr><td>attr_lodinfo</td><td>Coming Soon.</td></tr>
<tr><td>attr_matrix33</td><td>Matrix33</td></tr>
<tr><td>attr_mipmapformat</td><td>int</td></tr>
<tr><td>attr_parent</td><td>Automatic.</td></tr>
<tr><td>attr_particlegroup</td><td>Coming Soon.</td></tr>
<tr><td>attr_pixellayout</td><td>int</td></tr>
<tr><td>attr_short</td><td>int</td></tr>
<tr><td>attr_skeletonroot</td><td>Automatic.</td></tr>
<tr><td>attr_string</td><td>string</td></tr>
<tr><td>attr_texsource</td><td>TexSource</td></tr>
<tr><td>attr_texture</td><td>TexDesc & blk_ref</td></tr>
<tr><td>attr_vector3</td><td>Float3</td></tr>
<tr><td>attr_vertmode</td><td>int</td></tr>
</table>

To determine the type of an attribute, you can call the IAttr::GetType function.

You may also want to get the name of an attribute at runtime, say if you’re iterating through a list of all the attributes in a block to print out something about each one and you’d like to know the name.  For this you can call the IAttr::GetName function.

One other function that all attributes have in common is the IAttr::asString function.  Similarly to the function by the same name of the IBlock interface, this function returns a string that contains a formatted printout of the information held by a specific attribute.  The IBlock::asString function actually loops through its own attributes calling the IAttr::GetName and the IAttr::asString function for each one to create its output.

<center>\ref starting_out "<< Previous Section"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\ref link_blks "Next Section >>>"</center>
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page link_blks Linking Blocks

Niflib views the NIF file as a group of interconnected blocks.  Technically a NIF file is a directed acyclic graph, and not a pure tree.  Basically this means that some nodes in the graph can have multiple parents, but loops cannot be formed.  There are two main categories of blocks in a nif file, Nodes and Non-Nodes.  Both types may have simple connect points for other nodes.  These are attributes which store a single block reference (blk_ref).  In order to link blocks together, you use these attributes in much the same way as other attributes that store data, but you call the IAttr::asLink and IAttr::Set(blk_ref const &) functions.  These functions will not only change the data inside the attribute, but they will have the affect of linking the two blocks together.  Niflib is aware of these connections and will not destroy a block that is connected to another, even if the variable expires in your code.  The WriteNifTree function uses these connections to determine the proper order and indexing to use when writing out a NIF file.

Once the blocks are linked, the child will now be aware of its new parent.  You can query the child block for the first parent it receives by calling the IBlock::GetParent function on that block.  Niflib keeps track of all parents, but usually the first one is the only one that’s important so this is what the IBlock::GetParent function returns.

Node blocks are always arranged in a tree fashion via the “Children” attribute and will always have one parent.  The “Children” attribute is an attr_linkgroup type attribute which stores a vector of block references (vector<blk_ref>) .  “Properties” is another common example of an attr_linkgroup type attribute.  These linkgroup attributes have a few more functions specific to them.  First of all, instead of having just one link, these blocks can have several or none.  So you need to use the IAttr::asLinkList function to get all the links contained within the attribute.

What if you wanted to follow all the links of a block? Say if you were trying to descend the entire graph easily.  In that case, you can use the IBlock::GetLinks function.  This will return a list of all blocks linked through any attribute within that block.

Instead of setting a linkgroup attribute all at once, you add or subtract links as necessary.  You can add links one at a time with the IAttr::AddLink function, or in a group with the IAttr::AddLinks function.  You can remove all links to a specific block by calling the IAttr::RemoveLinks function.  The IAttr::ClearLinks function will remove all the links.  Finally, it can sometimes be handy to find a link based on its block type (NiNode, for instance).  For that you can use the IAttr::FindLink function.

<center>\ref attrs "<< Previous Section"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\ref adv_interf "Next Section >>>"</center>
*/

///////////////////////////////////////////////////////////////////////////////

/*! \page adv_interf Advanced Block Interfaces

You now know how to access and change the information in most of the NIF blocks.  You know how to link blocks and unlink them, and you know how to read and write NIF files.  But if you take a close look at the types of attributes available, you will notice some apparent omissions.  Where are the lists of vertices?  How do you set up animation keys?  What about skin weights?  All these features are available through advanced block interfaces which you can query from simple block references.

Because calling the IBlock::QueryInterface function yourself can get a little messy (and is impossible from Python), several query functions are provided, one for each type of advanced block interface.  All of these functions work the same way, so I’ll just use one example to illustrate the rest.

The INode interface is an advanced interface that is present in all blocks that are nodes.  Blocks can have more than one advanced interface; you can use the QueryNode function to determine if INode is one of them.  Bear in mind that interfaces must be stored in pointers, so the return value of QueryNode is a pointer to an INode interface.  That is, it’s type is INode*.  This is not important for Python users to know, but C++ users must be able to declare a variable to hold their newly queried advanced interface.

Node data blocks in NIF files are arranged in a pure tree.  This tree defines a transform hierarchy… in other words, if a block’s parent is moved to a position in 3D space, its children will move to the same position.  Therefore, any 3D transform on the child is relative to its parent… and its parent, all the way back to the root node.  This can be a lot to keep track of, so Niflib does it for you.  Using the functions of the INode interface, you can get a full 4x4 transform matrix for both local (relative to the parent) and world (relative to the origin) coordinates.  To do this, you call the INode::GetLocalTransform and INode::GetWorldTransform functions respectively.  

<center>\ref link_blks "<< Previous Section"</center>

*/

#endif
