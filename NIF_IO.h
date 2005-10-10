/**********************************************************

NIFlib - library for loading and saving NIF 3d model files.
Author: Taharez ( taharez@gdnmail.net )

For details on file structure, see the latest NIF format
description document available at NIFLA:
http://games.groups.yahoo.com/group/nifla

**********************************************************/

#ifndef TAH_NIF_LIB_NIF_IO_H
#define TAH_NIF_LIB_NIF_IO_H


/* INCLUDES */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
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

#define NULL 0

/* Valid values for some texturingproperty attributes. */
typedef enum {
   APPLY_REPLACE = 0x00000000,
   APPLY_DECAL = 1,
   APPLY_MODULATE = 2,
   APPLY_HILIGHT = 3,    // PS2 Only
   APPLY_HILIGHT2 = 4    // PS2 Only
} nifApplyMode;

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
	friend ostream & operator<<(ostream & lh, Str & rh) {
		//Fix string
		char * s = new char[rh._n + 1];
		strncpy(s, rh._c, rh._n);
		s[rh._n] = 0;
		lh << s;
		delete [] s;
		return lh;
	}
private:
	const char * _c;
	uint _n;
};

class Hex {
public:
	Hex(uint & n) { _n = n; }
	Hex(ushort & n) { _n = uint(n); }
	Hex(byte & n) { _n = uint(n); }
	friend ostream & operator<<(ostream & lh, Hex & rh) {
		return lh << dec << rh._n << " (0x" << hex << uppercase << rh._n << ")" << dec;
	}
private:
	uint _n;
};

class Index {
public:
	Index(uint & n) { _n = n; }
	Index(ushort & n) { _n = uint(n); }
	Index(byte & n) { _n = uint(n); }
	friend ostream & operator<<(ostream & lh, Index & rh) {
		if (int(rh._n) != -1)
			return lh << "Block " << rh._n;
		else
			return lh << "None";
	}
private:
	uint _n;
};

class Bin {
public:
	Bin(uint &  n) { _n = n; _w = 32; }
	Bin(ushort & n) {_n = uint(n); _w = 16; }
	Bin(byte & n) { _n = uint(n); _w = 8; }
	friend ostream & operator<<(ostream & lh, Bin & rh) {
		uint x = rh._n;
		for (uint i = 0; i < rh._w; i++) {
			if((x & 0x80) !=0) {
				lh << "1";
			}
			else {
				lh << "0";
			}
			x <<= 1;
		}
		return lh;
	}
private:
	uint _n;
	uint _w;
};

ostream & operator<<(ostream & lh, fVector2 & rh);
ostream & operator<<(ostream & lh, fVector3 & rh);
ostream & operator<<(ostream & lh, fVector4 & rh);
ostream & operator<<(ostream & lh, usVector3 & rh);
ostream & operator<<(ostream & lh, nifApplyMode & rh);

ostream & operator<<(ostream & lh, nifPixelLayout & rh);
ostream & operator<<(ostream & lh, nifMipMapFormat & rh);
ostream & operator<<(ostream & lh, nifAlphaFormat & rh);

/**
 * Read utility functions
 */
uint ReadUInt( ifstream& in );

ushort ReadUShort( ifstream& in );

byte ReadByte( ifstream& in );

float ReadFloat( ifstream &in );

string ReadString( ifstream &in );

void ReadUSVector3( usVector3& vec, ifstream& in );

void ReadFVector2( fVector2& fvec, ifstream& in );

void ReadFVector3( fVector3& fvec, ifstream& in );

void ReadFVector4( fVector4& fvec, ifstream& in );

/**
 * Write utility functions.
 */
void WriteUInt( uint val, ofstream& out );

void WriteUShort( ushort val, ofstream& out );

void WriteByte( byte val, ofstream& out );

void WriteUSVector3( usVector3& fvec, ofstream& out );

void WriteFloat( float val, ofstream& out );

void WriteString( string val, ofstream& out );

void WriteFVector2( fVector2& fvec, ofstream& out );

void WriteFVector3( fVector3& fvec, ofstream& out );

void WriteFVector4( fVector4& fvec, ofstream& out );

void WriteBlockName( const char* name, uint nameLength, ofstream& out );

class NIF;

class nifIndex {
public:
	nifIndex(){}
	~nifIndex() {};
	uint GetIndex() { return _index; }
	uint SetIndex( int index ) {
		_index = index;
	}
	void Read( ifstream &in ) {
		_index = ReadUInt( in );
	}
	void Write( ofstream &out ) {
		WriteUInt( _index, out );
	}
	friend ostream & operator<<(ostream & lh, nifIndex & rh);

private:
	int _index;
};



#endif // TAH_NIF_LIB_NIF_IO_H