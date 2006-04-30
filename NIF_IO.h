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

#ifndef _NIF_IO_H
#define _NIF_IO_H

/* INCLUDES */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "niflib.h"
using namespace std;

struct HeaderString {
	string header;
};

typedef unsigned char	byte;
typedef unsigned short	ushort;
typedef unsigned int	uint;

typedef ushort usVector3[3];

typedef float fVector2[2];
typedef float fVector3[3];
typedef float fVector4[4];

#ifndef NULL
#define NULL 0
#endif

//--New Nodes--//



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
void ReadUSVector3( usVector3& vec, istream& in );
void ReadFVector2( fVector2& fvec, istream& in );
void ReadFVector3( fVector3& fvec, istream& in );
void ReadFVector4( fVector4& fvec, istream& in );

/**
 * Write utility functions.
 */
void WriteInt( int val, ostream& out );
void WriteUInt( uint val, ostream& out );
void WriteUShort( ushort val, ostream& out );
void WriteShort( short val, ostream& out );
void WriteByte( byte val, ostream& out );
void WriteUSVector3( usVector3 const & fvec, ostream& out );
void WriteFloat( float val, ostream& out );
void WriteString( string const & val, ostream& out );
void WriteBool( bool val, ostream& out, unsigned int version );
void WriteFVector2( fVector2 const & fvec, ostream& out );
void WriteFVector3( fVector3 const & fvec, ostream& out );
void WriteFVector4( fVector4 const & fvec, ostream& out );

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

//HeaderString
void NifStream( HeaderString & val, istream& in, uint version = 0 );
void NifStream( HeaderString const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, HeaderString const & val );

//TexCoord
void NifStream( TexCoord & val, istream& in, uint version = 0 );
void NifStream( TexCoord const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, TexCoord const & val );

//Triangle
void NifStream( Triangle & val, istream& in, uint version = 0 );
void NifStream( Triangle const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, Triangle const & val );

//Vector3
void NifStream( Vector3 & val, istream& in, uint version = 0 );
void NifStream( Vector3 const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, Vector3 const & val );

//Float2
void NifStream( Float2 & val, istream& in, uint version = 0 );
void NifStream( Float2 const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, Float2 const & val );

//Matrix22
void NifStream( Matrix22 & val, istream& in, uint version = 0 );
void NifStream( Matrix22 const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, Matrix22 const & val );

//Float3
void NifStream( Float3 & val, istream& in, uint version = 0 );
void NifStream( Float3 const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, Float3 const & val );

//Matrix33
void NifStream( Matrix33 & val, istream& in, uint version = 0 );
void NifStream( Matrix33 const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, Matrix33 const & val );

//Float4
void NifStream( Float4 & val, istream& in, uint version = 0 );
void NifStream( Float4 const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, Float4 const & val );

//Matrix44
void NifStream( Matrix44 & val, istream& in, uint version = 0 );
void NifStream( Matrix44 const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, Matrix44 const & val );

//Color4
void NifStream( Color4 & val, istream& in, uint version = 0 );
void NifStream( Color4 const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, Color4 const & val );

//Quaternion
void NifStream( Quaternion & val, istream& in, uint version = 0 );
void NifStream( Quaternion const & val, ostream& out, uint version = 0  );
ostream & operator<<( ostream & out, Quaternion const & val );

//BoundingBox
void NifStream( BoundingBox & val, istream& in, uint version = 0 );
void NifStream( BoundingBox const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, BoundingBox const & val );

//Not going to implement ConditionalInt.  Should not be needed anymore.

//SkinWeight
void NifStream( SkinWeight & val, istream& in, uint version = 0 );
void NifStream( SkinWeight const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, SkinWeight const & val );

//LODRange
void NifStream( LODRange & val, istream& in, uint version = 0 );
void NifStream( LODRange const & val, ostream& out, uint version = 0 );
ostream & operator<<( ostream & out, LODRange const & val );

//TexDesc
void NifStream( TexDesc & val, istream& in, uint version );  // version is significant
void NifStream( TexDesc const & val, ostream& out, uint version ); // version is significant
ostream & operator<<( ostream & out, TexDesc const & val );

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

//--Templates--//

//Key<T>
template <class T> 
void NifStream( Key<T> & key, istream& file, KeyType type ) {
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
void NifStream( Key<T> const & key, ostream& file, KeyType type ) {
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

//Key<Quaternion>
void StreamQuatKey( Key<Quaternion> & key, istream& file, KeyType type );
void StreamQuatKey( Key<Quaternion> const & key, ostream& file, KeyType type );

//vector<T>
//This version of NifStream allows whole vectors of data to be streamed
//Should probably be extended to work on all STL containers
template <class T>
void NifStream( vector<T> & val, istream& file, uint version = 0 ) {
	typename vector<T>::iterator it;
	for ( it = val.begin(); it != val.end(); ++it ) {
		NifStream( *it, file, version );
	}
}

template <class T>
void NifStream( vector<T> const & val, ostream& file, uint version = 0 ) {
	typename vector<T>::const_iterator it;
	for ( it = val.begin(); it != val.end(); ++it ) {
		NifStream( *it, file, version );
	}
}

//The HexString function creates a formatted hex display of the given data for use in printing
//a debug string for information that is not understood
string HexString( const byte * src, uint len );

#endif
