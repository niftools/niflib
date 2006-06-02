/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIF_IO_H
#define _NIF_IO_H

/* INCLUDES */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "nif_math.h"
using namespace std;

#ifndef NULL
#define NULL 0
#endif

//--Constants--//

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
const unsigned int VER_20_0_0_5    = 0x14000005; /*!< Nif Version 20.0.0.4 */ 
const unsigned int VER_UNSUPPORTED = 0xFFFFFFFF; /*!< Unsupported Nif Version */
const unsigned int VER_INVALID     = 0xFFFFFFFE; /*!< Not a Nif file */



/*! Keyframe trees are game dependent, so here we define a few games. */
enum NifGame {
	KF_MW = 0, /*!< keyframe files: NiSequenceStreamHelper header, .kf extension */
	KF_DAOC = 1, /*!< keyframe files: NiNode header, .kfa extension */
	KF_CIV4 = 2 /*!< keyframe files: NiControllerSequence header, .kf extension */
};

/*! Export options. */
enum ExportOptions { 
	EXPORT_NIF = 0, /*!< NIF */
	EXPORT_NIF_KF = 1, /*!< NIF + single KF + KFM */
	EXPORT_NIF_KF_MULTI = 2, /*!< NIF + multiple KF + KFM */
	EXPORT_KF = 3, /*!< single KF */
	EXPORT_KF_MULTI = 4 /*!< multiple KF */
};


//--Non-mathematical Basic Types--//

typedef unsigned char	byte;
typedef unsigned short	ushort;
typedef unsigned int	uint;

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

/*! Used to enable static arrays to be members of vectors */
template<class T, int size>
struct array {
	T data[size];
	T & operator[]( uint index ) {
		return data[index];
	}
	T operator[]( uint index ) const {
		return data[index];
	}
};


struct HeaderString {
	string header;
};

//TODO:  This is temporary to make it compile.  Should eventually be adjusted to display 1's and 0's insted of as an int.
typedef ushort Flags;

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

/*! Specifies the availiable alpha formats.  That is, the type of alpha blending (transparency) that will be used on a particular texture.*/
enum AlphaFormat {
   ALPHA_NONE = 0, /*!< No alpha blending, the texture is fully opaque */ 
   ALPHA_BINARY = 1, /*!< Texture is either fully transparent or fully opaque.  There are no partially transparent areas. */ 
   ALPHA_SMOOTH = 2, /*!< Full range of alpha values can be used from fully transparent to fully opaque including all partially transparent values in between. */ 
   ALPHA_DEFAULT = 3 /*!< Use default setting. */ 
};

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

/*!
 * Specifies the mip map format of a texture.
 */
enum MipMapFormat {
	MIP_FMT_NO = 0, /*!< Texture does not use mip maps. */
	MIP_FMT_YES = 1,/*!< Texture uses mip maps. */
	MIP_FMT_DEFAULT = 2, /*!< Use default setting. */
};

/*!
 * Specifies the pixel layout of a texture.  That is, the format of the image data.
 */
enum PixelLayout {
	PIX_LAY_PALETTISED = 0, /*!< Texture is in 8-bit paletized format. */
	PIX_LAY_HIGH_COLOR_16 = 1, /*!< Texture is in 16-bit high color format. */
	PIX_LAY_TRUE_COLOR_32 = 2, /*!< Texture is in 32-bit true color format. */
	PIX_LAY_COMPRESSED = 3, /*!< Texture is compressed. */
	PIX_LAY_BUMPMAP = 4, /*!< Texture is a grayscale bump map. */
	PIX_LAY_DEFAULT = 5 /*!< Use default setting. */
};

/*!
 * Specifies what type of light is active on the shape.
 */
enum VertMode {
	VERT_MODE_SRC_IGNORE = 0, /*!< Source Ignore. */
	VERT_MODE_SRC_EMISSIVE = 1, /*!< Source Emissive. */
	VERT_MODE_SRC_AMB_DIF = 2, /*!< Source Ambient/Diffuse. */
};

/*!
 * Specifies the light mode.
 */
enum LightMode {
	LIGHT_MODE_EMISSIVE = 0, /*!< Emissive. */
	LIGHT_MODE_EMI_AMB_DIF = 1, /*!< Emissive + Ambient + Diffuse. */
};

//--IO Functions--//

int BlockSearch( istream& in );

/**
 * Read utility functions
 */
int ReadInt( istream& in );
uint ReadUInt( istream& in );
ushort ReadUShort( istream& in );
short ReadShort( istream& in );
byte ReadByte( istream& in );
float ReadFloat( istream &in );
string ReadString( istream &in );
bool ReadBool( istream &in, unsigned int version );

/**
 * Write utility functions.
 */
void WriteInt( int val, ostream& out );
void WriteUInt( uint val, ostream& out );
void WriteUShort( ushort val, ostream& out );
void WriteShort( short val, ostream& out );
void WriteByte( byte val, ostream& out );
void WriteFloat( float val, ostream& out );
void WriteString( string const & val, ostream& out );
void WriteBool( bool val, ostream& out, unsigned int version );

//-- NifStream And ostream Functions --//
// The NifStream functions allow each built-in type to be streamed to and from a file.
// The ostream functions are for writing out a debug string.

//--Basic Types--//

//int
void NifStream( int & val, istream& in, uint version = 0 );
void NifStream( int const & val, ostream& out, uint version = 0  );

//uint
void NifStream( uint & val, istream& in, uint version = 0 );
void NifStream( uint const & val, ostream& out, uint version = 0  );

//ushort
void NifStream( ushort & val, istream& in, uint version = 0 );
void NifStream( ushort const & val, ostream& out, uint version = 0  );

//short
void NifStream( short & val, istream& in, uint version = 0 );
void NifStream( short const & val, ostream& out, uint version = 0  );

//byte
void NifStream( byte & val, istream& in, uint version = 0 );
void NifStream( byte const & val, ostream& out, uint version = 0  );

//bool
void NifStream( bool & val, istream& in, uint version );  // version is significant
void NifStream( bool const & val, ostream& out, uint version ); // version is significant

//float
void NifStream( float & val, istream& in, uint version = 0 );
void NifStream( float const & val, ostream& out, uint version = 0  );

//string
void NifStream( string & val, istream& in, uint version = 0 );
void NifStream( string const & val, ostream& out, uint version = 0  );

//--Structs--//

////HeaderString
//void NifStream( HeaderString & val, istream& in, uint version = 0 );
//void NifStream( HeaderString const & val, ostream& out, uint version = 0 );
//ostream & operator<<( ostream & out, HeaderString const & val );

//TexCoord
void NifStream( TexCoord & val, istream& in, uint version = 0 );
void NifStream( TexCoord const & val, ostream& out, uint version = 0 );

//Triangle
void NifStream( Triangle & val, istream& in, uint version = 0 );
void NifStream( Triangle const & val, ostream& out, uint version = 0 );

//Vector3
void NifStream( Vector3 & val, istream& in, uint version = 0 );
void NifStream( Vector3 const & val, ostream& out, uint version = 0  );

//Float2
void NifStream( Float2 & val, istream& in, uint version = 0 );
void NifStream( Float2 const & val, ostream& out, uint version = 0  );

//Matrix22
void NifStream( Matrix22 & val, istream& in, uint version = 0 );
void NifStream( Matrix22 const & val, ostream& out, uint version = 0 );

//Float3
void NifStream( Float3 & val, istream& in, uint version = 0 );
void NifStream( Float3 const & val, ostream& out, uint version = 0  );

//Matrix33
void NifStream( Matrix33 & val, istream& in, uint version = 0 );
void NifStream( Matrix33 const & val, ostream& out, uint version = 0 );

//Float4
void NifStream( Float4 & val, istream& in, uint version = 0 );
void NifStream( Float4 const & val, ostream& out, uint version = 0  );

//Matrix44
void NifStream( Matrix44 & val, istream& in, uint version = 0 );
void NifStream( Matrix44 const & val, ostream& out, uint version = 0 );

//Color4
void NifStream( Color4 & val, istream& in, uint version = 0 );
void NifStream( Color4 const & val, ostream& out, uint version = 0  );

//Quaternion
void NifStream( Quaternion & val, istream& in, uint version = 0 );
void NifStream( Quaternion const & val, ostream& out, uint version = 0  );

//--Enums--//

//TexType
void NifStream( TexType & val, istream& in, uint version = 0 );
void NifStream( TexType const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, TexType const & val );

//ApplyMode
void NifStream( ApplyMode & val, istream& in, uint version = 0 );
void NifStream( ApplyMode const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, ApplyMode const & val );

//TexClampMode
void NifStream( TexClampMode & val, istream& in, uint version = 0 );
void NifStream( TexClampMode const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, TexClampMode const & val );

//TexFilterMode
void NifStream( TexFilterMode & val, istream& in, uint version = 0 );
void NifStream( TexFilterMode const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, TexFilterMode const & val );

//AlphaFormat
void NifStream( AlphaFormat & val, istream& in, uint version = 0 );
void NifStream( AlphaFormat const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, AlphaFormat const & val );

//KeyType
void NifStream( KeyType & val, istream& in, uint version = 0 );
void NifStream( KeyType const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, KeyType const & val );

//PixelFormat
void NifStream( PixelFormat & val, istream& in, uint version = 0 );
void NifStream( PixelFormat const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, PixelFormat const & val );

//MipMapFormat
void NifStream( MipMapFormat & val, istream& in, uint version = 0 );
void NifStream( MipMapFormat const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, MipMapFormat const & val );

//PixelLayout
void NifStream( PixelLayout & val, istream& in, uint version = 0 );
void NifStream( PixelLayout const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, PixelLayout const & val );

//VertMode
void NifStream( VertMode & val, istream& in, uint version = 0 );
void NifStream( VertMode const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, VertMode const & val );

//LightMode
void NifStream( LightMode & val, istream& in, uint version = 0 );
void NifStream( LightMode const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, LightMode const & val );

//--Templates--//

//Key<T>
template <class T> 
void NifStream( Key<T> & key, istream& file, uint version, KeyType type ) {
	key.time = ReadFloat( file );

	//If key type is not 1, 2, or 3, throw an exception
	if ( type < 1 || type > 3 ) {
		type = LINEAR_KEY;
		//throw runtime_error("Invalid key type.");
	}

	//Read data based on the type of key
	NifStream( key.data, file );
	if ( type == QUADRATIC_KEY ) {
		//Uses Quadratic interpolation
		NifStream( key.forward_tangent, file );
		NifStream( key.backward_tangent, file );
	} else if ( type == TBC_KEY ) {
		//Uses TBC interpolation
		key.tension = ReadFloat( file );
		key.bias = ReadFloat( file );
		key.continuity = ReadFloat( file );
	}
}

template <class T> 
void NifStream( Key<T> & key, istream & file, uint version, int type ) {
	NifStream( key, file, version, (KeyType)type );
}

template <class T> 
void NifStream( Key<T> const & key, ostream& file, uint version, KeyType type ) {
	WriteFloat( key.time, file );

	//If key type is not 1, 2, or 3, throw an exception
	if ( type < 1 || type > 3 ) {
		type = LINEAR_KEY;
		//throw runtime_error("Invalid key type.");
	}

	//Read data based on the type of key
	NifStream( key.data, file );
	if ( type == QUADRATIC_KEY ) {
		//Uses Quadratic interpolation
		NifStream( key.forward_tangent, file );
		NifStream( key.backward_tangent, file );
	} else if ( type == TBC_KEY ) {
		//Uses TBC interpolation
		WriteFloat( key.tension, file);
		WriteFloat( key.bias, file);
		WriteFloat( key.continuity, file);
	}
}

template <class T> 
void NifStream( Key<T> const & key, ostream & file, uint version, int type ) {
	NifStream( key, file, version, (KeyType)type );
}

ostream & operator<<( ostream & out, PixelLayout const & val );
template <class T> 
ostream & operator<<( ostream & out, Key<T> const & val ) {
	return out << "Time:  " << val.time << endl
			   << "Data:  " << val.data << endl
			   << "Forward Tangent:  " << val.forward_tangent << endl
			   << "Backward Tangent:  " << val.backward_tangent << endl
			   << "Bias:  " << val.bias << endl
			   << "Continuity:  " << val.continuity << endl;
}

//Key<Quaternion>
void StreamQuatKey( Key<Quaternion> & key, istream& file, uint version, KeyType type );
void StreamQuatKey( Key<Quaternion> const & key, ostream& file, uint version, KeyType type );

//The HexString function creates a formatted hex display of the given data for use in printing
//a debug string for information that is not understood
string HexString( const byte * src, uint len );

//Byte
ostream & operator<<( ostream & out, byte const & val );

#endif
