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
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "niflib.h"
using namespace std;

/* TYPE DEFINITIONS */
//typedef enum {
//   TYPE_UINT,
//   TYPE_USHORT,
//   TYPE_BYTE,
//   TYPE_FLOAT,
//   TYPE_FVEC2,
//   TYPE_FVEC3,
//   TYPE_FVEC4,
//
//} nifValueType;
//
//class I_NifProperty {
//public:
//	virtual void read(istream & in);
//	virtual void write(ostream & out);
//	string str();


//class NifString {
//public:
//	friend ostream & operator<<(ostream & lh, NifString & rh) {
//		out.write( (char*)&val, 4 );
//	}
//	friend istream & operator>>(istream & lh, NifString & rh) {
//		return rh.read( (char*)&rh, 4 );
//	}
//private:
//	string _str; // string data
//}

typedef unsigned char	byte;
typedef unsigned short	ushort;
typedef unsigned int	uint;

typedef ushort usVector3[3];

typedef float fVector2[2];
typedef float fVector3[3];
typedef float fVector4[4];

typedef uint readResult;
typedef uint writeResult;

//typedef uint	nifIndex;
typedef ushort	nifFlags;

#ifndef NULL
#define NULL 0
#endif

/* Valid values for some sourcetexture attributes. */
typedef enum {
   PALETTISED = 0x00000000,
   HIGH_COLOR_16 = 1,
   TRUE_COLOR_32 = 2,
   COMPRESSED = 3,
   BUMPMAP = 4,
   PIX_DEFAULT = 5
} nifPixelLayout;

typedef enum {
   MIPMAP_NO = 0x00000000,
   MIPMAP_YES = 1,
   MIPMAP_MIP_DEFAULT = 2,
} nifMipMapFormat;

typedef enum {
   ALPHA_NONE = 0x00000000,
   ALPHA_BINARY = 1,
   ALPHA_SMOOTH = 2,
   ALPHA_DEFAULT = 3
} nifAlphaFormat;

//--New Nodes--//



//--IO Functions--//

int BlockSearch( ifstream& in );

class Str {
public:
	Str(const char * c, int n) { _c = c; _n = n; }
	friend ostream & operator<<(ostream & lh, Str const & rh);
private:
	const char * _c;
	uint _n;
};

class Hex {
public:
	Hex(uint const & n) { _n = n; }
	Hex(ushort const & n) { _n = uint(n); }
	Hex(byte const & n) { _n = uint(n); }
	friend ostream & operator<<(ostream & lh, Hex const & rh);
private:
	uint _n;
};

class Index {
public:
	Index(uint const & n) { _n = n; }
	Index(ushort const & n) { _n = uint(n); }
	Index(byte const & n) { _n = uint(n); }
	friend ostream & operator<<(ostream & lh, Index const & rh);
private:
	uint _n;
};

class Bin {
public:
	Bin(uint const &  n) { _n = n; _w = 32; }
	Bin(ushort const & n) {_n = uint(n); _w = 16; }
	Bin(byte const & n) { _n = uint(n); _w = 8; }
	friend ostream & operator<<(ostream & lh, Bin const & rh);
private:
	uint _n;
	uint _w;
};

ostream & operator<<(ostream & lh, fVector2 const & rh);
ostream & operator<<(ostream & lh, fVector3 const & rh);
ostream & operator<<(ostream & lh, fVector4 const & rh);
ostream & operator<<(ostream & lh, usVector3 const & rh);
ostream & operator<<(ostream & lh, ApplyMode const & rh);


ostream & operator<<(ostream & lh, nifPixelLayout const & rh);
ostream & operator<<(ostream & lh, nifMipMapFormat const & rh);
ostream & operator<<(ostream & lh, nifAlphaFormat const & rh);

/**
 * Read utility functions
 */
uint ReadUInt( ifstream& in );
ushort ReadUShort( ifstream& in );
byte ReadByte( ifstream& in );
float ReadFloat( ifstream &in );
string ReadString( ifstream &in );
bool ReadBool( ifstream &in, unsigned int version );
void ReadUSVector3( usVector3& vec, ifstream& in );
void ReadFVector2( fVector2& fvec, ifstream& in );
void ReadFVector3( fVector3& fvec, ifstream& in );
void ReadFVector4( fVector4& fvec, ifstream& in );

//Read
void NifStream( uint & val, ifstream& in );
void NifStream( ushort & val, ifstream& in );
void NifStream( byte & val, ifstream& in );
void NifStream( float & val, ifstream& in );
void NifStream( string & val, ifstream& in );
void NifStream( Vector3 & val, ifstream& in );
void NifStream( Quaternion & val, ifstream& in );
void NifStream( KeyType & val, ifstream& in );
void NifStream( Color4 & val, ifstream& in );
void NifStream( Triangle & val, ifstream& in );
void NifStream( TexDesc & val, ifstream& in, uint version );


template <class T> 
void NifStream( Key<T> & key, ifstream& file, KeyType type ) {
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
void NifStream( vector<T> & val, ifstream& file ) {
	typename vector<T>::iterator it;
	for ( it = val.begin(); it != val.end(); ++it ) {
		NifStream( *it, file );
	}
}


/**
 * Write utility functions.
 */
void WriteUInt( uint val, ofstream& out );

void WriteUShort( ushort val, ofstream& out );

void WriteByte( byte val, ofstream& out );

void WriteUSVector3( usVector3 const & fvec, ofstream& out );

void WriteFloat( float val, ofstream& out );

void WriteString( string const & val, ofstream& out );

void WriteBool( bool val, ofstream& out, unsigned int version );

void WriteFVector2( fVector2 const & fvec, ofstream& out );

void WriteFVector3( fVector3 const & fvec, ofstream& out );

void WriteFVector4( fVector4 const & fvec, ofstream& out );

void WriteBlockName( const char* name, uint nameLength, ofstream& out );

//Write
void NifStream( uint const & val, ofstream& out );
void NifStream( ushort const & val, ofstream& out );
void NifStream( byte const & val, ofstream& out );
void NifStream( float const & val, ofstream& out );
void NifStream( string const & val, ofstream& out );
void NifStream( Vector3 const & val, ofstream& out );
void NifStream( Quaternion const & val, ofstream& out );
void NifStream( KeyType const & val, ofstream& out );
void NifStream( Color4 const & val, ofstream& out );
void NifStream( Triangle const & val, ofstream& out );
void NifStream( TexDesc const & val, ofstream& out, uint version );

template <class T> 
void NifStream( Key<T> const & key, ofstream& file, KeyType type ) {
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
void NifStream( vector<T> const & val, ofstream& file ) {
	typename vector<T>::const_iterator it;
	for ( it = val.begin(); it != val.end(); ++it ) {
		NifStream( *it, file );
	}
}

//string indent( int level );

////As String
//void NifString( uint const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( ushort const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( byte const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( float const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( string const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( Vector3 const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( Quaternion const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( KeyType const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( Color4 const & val, stringstream& out, string heading, int ind_lvl = 0 );
//void NifString( Triangle const & val, stringstream& out, string heading, int ind_lvl = 0 );

string HexString( const byte * src, uint len );

class NIF;

class nifIndex {
public:
	nifIndex(){}
	~nifIndex() {};
	uint GetIndex() const { return _index; }
	void SetIndex( int index ) {
		_index = index;
	}
	void Read( ifstream &in ) {
		_index = ReadUInt( in );
	}
	void Write( ofstream &out ) const {
		WriteUInt( _index, out );
	}
	friend ostream & operator<<(ostream & lh, nifIndex const & rh);

private:
	int _index;
};

#endif
