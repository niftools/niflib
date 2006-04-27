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

// !!!TEMPORARY TO SUPRESS COMPILER ERRORS!!!
typedef blk_ref link_ref;
typedef string HeaderString;
// !!!TEMPORARY TO SUPRESS COMPILER ERRORS!!!

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

//--New Nodes--//



//--IO Functions--//

int BlockSearch( istream& in );

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

//Read
void NifStream( int & val, istream& in, uint version = 0 );
void NifStream( uint & val, istream& in, uint version = 0 );
void NifStream( ushort & val, istream& in, uint version = 0 );
void NifStream( short & val, istream& in, uint version = 0 );
void NifStream( byte & val, istream& in, uint version = 0 );
void NifStream( bool & val, istream& in, uint version );  // version is significant
void NifStream( float & val, istream& in, uint version = 0 );
void NifStream( string & val, istream& in, uint version = 0 );
void NifStream( Vector3 & val, istream& in, uint version = 0 );
void NifStream( Quaternion & val, istream& in, uint version = 0 );
void NifStream( KeyType & val, istream& in, uint version = 0 );
void NifStream( Color4 & val, istream& in, uint version = 0 );
void NifStream( Triangle & val, istream& in, uint version = 0 );
void NifStream( TexDesc & val, istream& in, uint version );  // version is significant
void NifStream( LODRange & val, istream& in, uint version = 0 );
void NifStream( IBlock * val, istream& in, uint version = 0 );

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

//template<> void f<char>(char c)


void StreamQuatKey( Key<Quaternion> & key, istream& file, KeyType type );

template <class T>
void NifStream( vector<T> & val, istream& file, uint version = 0 ) {
	typename vector<T>::iterator it;
	for ( it = val.begin(); it != val.end(); ++it ) {
		NifStream( *it, file, version );
	}
}


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
void WriteBlockName( const char* name, uint nameLength, ostream& out );

//Write
void NifStream( int const & val, ostream& out, uint version = 0  );
void NifStream( uint const & val, ostream& out, uint version = 0  );
void NifStream( ushort const & val, ostream& out, uint version = 0  );
void NifStream( short const & val, ostream& out, uint version = 0  );
void NifStream( byte const & val, ostream& out, uint version = 0  );
void NifStream( bool const & val, ostream& out, uint version ); // version is significant
void NifStream( float const & val, ostream& out, uint version = 0  );
void NifStream( string const & val, ostream& out, uint version = 0  );
void NifStream( Vector3 const & val, ostream& out, uint version = 0  );
void NifStream( Quaternion const & val, ostream& out, uint version = 0  );
void NifStream( KeyType const & val, ostream& out, uint version = 0  );
void NifStream( Color4 const & val, ostream& out, uint version = 0  );
void NifStream( Triangle const & val, ostream& out, uint version = 0 );
void NifStream( TexDesc const & val, ostream& out, uint version ); // version is significant
void NifStream( LODRange const & val, ostream& out, uint version = 0 );
void NifStream( IBlock const * const val, ostream& out, uint version = 0 );

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


void StreamQuatKey( Key<Quaternion> const & key, ostream& file, KeyType type );

template <class T>
void NifStream( vector<T> const & val, ostream& file, uint version = 0 ) {
	typename vector<T>::const_iterator it;
	for ( it = val.begin(); it != val.end(); ++it ) {
		NifStream( *it, file, version );
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
	void Read( istream &in ) {
		_index = ReadUInt( in );
	}
	void Write( ostream &out ) const {
		WriteUInt( _index, out );
	}
	friend ostream & operator<<(ostream & lh, nifIndex const & rh);

private:
	int _index;
};

#endif
