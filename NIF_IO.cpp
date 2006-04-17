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

#include "NIF_IO.h"
//#include "NIF.h"
int BlockSearch( istream& in ) {

	//Get current file pos
	int data_start = in.tellg();

	//cout << "Current File Pos: " << data_start << endl;
	//cout << "Searching for next block..." << endl;

	//Find Next Block
	char tmp1 = 0, tmp2 = 0;
	uint next_name_len = 0;
	while (!in.eof()) {
		while (!in.eof() && !((tmp1 == 'N' && tmp2 == 'i') || (tmp1 == 'R' && tmp2 == 'o') || (tmp1 == 'A' && tmp2 == 'v')) ) {
			tmp1 = tmp2;
			in.read(&tmp2, 1);
		}
		if (in.eof())
			break;
		
		//Move back to before the uint that holds the length of the string
		in.seekg(-6, ios_base::cur);

		//Read the length of the string
		next_name_len = ReadUInt( in );

		//cout << "Matching Data:  " << tmp1 << tmp2 << endl;

		//if name length is > 40, then this is unlikley to be a real node. 
		if (next_name_len <= 40 && next_name_len >= 5) {
			//Read the string
			char* next_name = new char[next_name_len];
			in.read( next_name, next_name_len );
			
			//cout << "Found Match:  " << Str(next_name, next_name_len) << endl;

			//Move back to where we were before we read anything
			in.seekg( -(int(next_name_len) - 2), ios_base::cur);

			break;
		}
		else {
			//Move back to where we were before we read anything
			in.seekg(2, ios_base::cur);

			tmp1 = tmp2 = 0;
			//cout << "Found possible block at:  " << int(in.tellg()) - 6 << endl;
		}
	}

	//Note length of data
	int data_length = 0;
	if (in.eof()) {
		//cout << "Reached End of File.  Assuming no more blocks to find." << endl;
		in.clear();
		in.seekg(-8, ios_base::end);
		data_length = int(in.tellg()) - data_start;
		in.seekg(data_start, ios_base::beg);
	}
	else {
		in.seekg(-6, ios_base::cur);
		data_length = int(in.tellg()) - data_start;
		in.seekg(data_start, ios_base::beg);
	}

	//cout << "Unknown area (" << data_length << " bytes):" << endl;

	return data_length;
}

//--IO Stream Functions--//

ostream & operator<<(ostream & lh, fVector2 const & rh) {
	return lh << "(" << setw(5) << rh[0] << ", " << setw(5) << rh[1] << ")";
}

ostream & operator<<(ostream & lh, fVector3 const & rh) {
	return lh << "(" << setw(5) << rh[0] << ", " << setw(5) << rh[1] << ", " << setw(5) << rh[2] << ")";
}

ostream & operator<<(ostream & lh, fVector4 const & rh) {
	return lh << "(" << setw(5) << rh[0] << ", " << setw(5) << rh[1] << ", " << setw(5) << rh[2] << ", " << setw(5) << rh[3] << ")";
}

ostream & operator<<(ostream & lh, usVector3 const & rh) {
	return lh << "(" << setw(4) << rh[0] << ", " << setw(4) << rh[1] << ", " << setw(4) << rh[2] << ")";
}

/**
 * Read utility functions
 */
uint ReadUInt( istream& in ){

	uint tmp;
	in.read( (char*)&tmp, 4 );
	return tmp;
}

ushort ReadUShort( istream& in ){

	ushort tmp;
	in.read( (char*)&tmp, 2 );
	return tmp;
}

short ReadShort( istream& in ){

	short tmp;
	in.read( (char*)&tmp, 2 );
	return tmp;
}

byte ReadByte( istream& in ){

	byte tmp;
	in.read( (char*)&tmp, 1 );
	return tmp;
}

void ReadUSVector3( usVector3& vec, istream& in ){

	vec[0] = ReadUShort( in );
	vec[1] = ReadUShort( in );
	vec[2] = ReadUShort( in );
}

float ReadFloat( istream &in ){

	float tmp;
	in.read( reinterpret_cast<char*>(&tmp), sizeof(tmp) );
	return tmp;
}

void ReadFVector2( fVector2& fvec, istream& in ){

	fvec[0] = ReadFloat( in );
	fvec[1] = ReadFloat( in );
}

void ReadFVector3( fVector3& fvec, istream& in ){

	fvec[0] = ReadFloat( in );
	fvec[1] = ReadFloat( in );
	fvec[2] = ReadFloat( in );
}

void ReadFVector4( fVector4& fvec, istream& in ){

	fvec[0] = ReadFloat( in );
	fvec[1] = ReadFloat( in );
	fvec[2] = ReadFloat( in );
	fvec[3] = ReadFloat( in );
}

string ReadString( istream &in ) {
	uint len = ReadUInt( in );
	string out;
	if ( len > 0 ) {
		out.resize( len );
		in.read( (char*)&out[0], len );
	}
	return out;
}

bool ReadBool( istream &in, unsigned int version ) {
	if ( version <= 0x04010001 ) {
		//Bools are stored as integers before version 4.1.0.1
		return (ReadUInt( in ) != 0);
	} else {
		//And as bytes from 4.1.0.1 on
		return (ReadByte( in ) != 0);
	}
}

/**
 * Write utility functions.
 */
void WriteUInt( uint val, ostream& out ){

	out.write( (char*)&val, 4 );
}

void WriteUShort( ushort val, ostream& out ){

	out.write( (char*)&val, 2 );
}

void WriteShort( short val, ostream& out ){

	out.write( (char*)&val, 2 );
}

void WriteByte( byte val, ostream& out ){

	out.write( (char*)&val, 1 );
}

void WriteUSVector3( usVector3 const & vec, ostream& out ){

	WriteUShort( vec[0], out );
	WriteUShort( vec[1], out );
	WriteUShort( vec[2], out );
}

void WriteFloat( float val, ostream& out ){

	out.write( reinterpret_cast<char*>(&val), sizeof(val) );
}

void WriteFVector2( fVector2 const & fvec, ostream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
}

void WriteFVector3( fVector3 const & fvec, ostream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
	WriteFloat( fvec[2], out );
}

void WriteFVector4( fVector4 const & fvec, ostream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
	WriteFloat( fvec[2], out );
	WriteFloat( fvec[3], out );
}

void WriteString( string const & val, ostream& out ) {
	WriteUInt( uint(val.size()), out );
	out.write( val.c_str(), std::streamsize(val.size()) );
}

void WriteBool( bool val, ostream& out, unsigned int version ) {
	if ( version < 0x04010001 ) {
		//Bools are stored as integers before version 4.1.0.1
		if (val)
			WriteUInt( 1, out );
		else
			WriteUInt( 0, out );
	} else {
		//And as bytes from 4.1.0.1 on
		if (val)
			WriteByte( 1, out );
		else
			WriteByte( 0, out );
	}
}

void WriteBlockName( const char* name, uint nameLength, ostream& out ){

	WriteUInt( nameLength, out );
	out.write( name, nameLength );
}

ostream & operator<<(ostream & lh, nifIndex const & rh) {
	if (rh._index != -1) {
		lh << "Block " << rh._index;
	} else {
		lh << "None";
	}
	return lh;
}

ostream & operator<<(ostream & lh, Str const & rh) {
	//Fix string
	char * s = new char[rh._n + 1];
	strncpy(s, rh._c, rh._n);
	s[rh._n] = 0;
	lh << s;
	delete [] s;
	return lh;
}

ostream & operator<<(ostream & lh, Hex const & rh) {
	return lh << dec << rh._n << " (0x" << hex << uppercase << rh._n << ")" << dec;
}

ostream & operator<<(ostream & lh, Index const & rh) {
	if (int(rh._n) != -1)
		return lh << "Block " << rh._n;
	else
		return lh << "None";
}

ostream & operator<<(ostream & lh, Bin const & rh) {
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

//--Overloaded versions of Read/Write functions ReadData/WriteData

void NifStream( uint & val, istream& in ) { val = ReadUInt( in ); };
void NifStream( ushort & val, istream& in ) { val = ReadUShort( in ); };
void NifStream( short & val, istream& in ) { val = ReadShort( in ); };
void NifStream( byte & val, istream& in ) { val = ReadByte( in ); };
void NifStream( float & val, istream& in ) { val = ReadFloat( in ); };
void NifStream( string & val, istream& in ) { val = ReadString( in ); };
void NifStream( KeyType & val, istream& in ) { val = KeyType(ReadUInt( in )); };

void NifStream( Vector3 & val, istream& in ) {
	val.x = ReadFloat( in );
	val.y = ReadFloat( in );
	val.z = ReadFloat( in );
};

void NifStream( Quaternion & val, istream& in ) {
	val.w = ReadFloat( in );
	val.x = ReadFloat( in );
	val.y = ReadFloat( in );
	val.z = ReadFloat( in );
};

void NifStream( Color4 & val, istream& in ) {
	val.r = ReadFloat( in );
	val.g = ReadFloat( in );
	val.b = ReadFloat( in );
	val.a = ReadFloat( in );
};

void NifStream( Triangle & val, istream& in ) {
	val.v1 = ReadUShort( in );
	val.v2 = ReadUShort( in );
	val.v3 = ReadUShort( in );
};

void NifStream( LODRange & val, istream& in ) {
	val.near = ReadFloat( in );
	val.far = ReadFloat( in );
};

void NifStream( TexDesc & val, istream& in, uint version ) {
	val.isUsed = ReadBool( in, version );
	if ( val.isUsed ) {	
		//Read in link for TexSource
		val.source.set_index( ReadUInt( in ) );

		val.clampMode = TexClampMode( ReadUInt( in ) );
		val.filterMode = TexFilterMode( ReadUInt( in ) );
		val.textureSet = ReadUInt( in );

		//PS2 values exist up to version 10.2.0.0
		if ( version <= VER_10_2_0_0 ) {
			val.PS2_L = ReadUShort( in );
			val.PS2_K = ReadUShort( in );
		}

		//unknownShort exists up to version 4.1.0.12
		if ( version <= VER_4_1_0_12) {
			val.unknownShort = ReadUShort( in );
		}

		//From version 10.1.0.0 and up, this unknown val block may exist
		if ( version >= VER_10_1_0_0 ) {
			val.hasTextureTransform = ReadBool( in, version );
			if ( val.hasTextureTransform == true ) {
				val.translation.u = ReadFloat( in );
				val.translation.v = ReadFloat( in );
				val.tiling.u = ReadFloat( in );
				val.tiling.v = ReadFloat( in );
				val.w_rotation = ReadFloat( in );
				val.transform_type = ReadUInt( in );
				val.center_offset.u = ReadFloat( in );
				val.center_offset.v = ReadFloat( in );
			}
		}
	}
}



void NifStream( uint const & val, ostream& out ) { WriteUInt( val, out ); }
void NifStream( ushort const & val, ostream& out ) { WriteUShort( val, out ); }
void NifStream( short const & val, ostream& out ) { WriteShort( val, out ); }
void NifStream( byte const & val, ostream& out ) { WriteByte( val, out ); }
void NifStream( float const & val, ostream& out ) { WriteFloat( val, out ); }
void NifStream( string const & val, ostream& out ) { WriteString( val, out ); }
void NifStream( KeyType const & val, ostream& out ) { WriteUInt( val, out ); }
void NifStream( Vector3 const & val, ostream& out ) {
	WriteFloat( val.x, out );
	WriteFloat( val.y, out );
	WriteFloat( val.z, out );
};
void NifStream( Quaternion const & val, ostream& out ) {
	WriteFloat( val.w, out );
	WriteFloat( val.x, out );
	WriteFloat( val.y, out );
	WriteFloat( val.z, out );
};
void NifStream( Color4 const & val, ostream& out ) {
	WriteFloat( val.r, out );
	WriteFloat( val.g, out );
	WriteFloat( val.b, out );
	WriteFloat( val.a, out );
};
void NifStream( Triangle const & val, ostream& out ) {
	WriteUShort( val.v1, out );
	WriteUShort( val.v2, out );
	WriteUShort( val.v3, out );
};
void NifStream( LODRange const & val, ostream& out ) {
	WriteFloat( val.near, out );
	WriteFloat( val.far, out );
};
void NifStream( TexDesc const & val, ostream& out, uint version ) {
	WriteBool( val.isUsed, out, version );
	if ( val.isUsed ) {
		//Write link
		WriteUInt( val.source.get_index(), out );

		WriteUInt( val.clampMode, out );
		WriteUInt( val.filterMode, out );
		WriteUInt( val.textureSet, out );

		//PS2 values exist up to version 10.2.0.0
		if ( version <= VER_10_2_0_0 ) {
			WriteUShort( val.PS2_L, out );
			WriteUShort( val.PS2_K, out );
		}

		//unknownShort exists up to version 4.1.0.12
		if ( version <= VER_4_1_0_12 ) {
			WriteUShort( val.unknownShort, out );
		}

		//From version 10.1.0.0 and up, this unknown val block may exist
		if ( version >= VER_10_1_0_0 ) {
			WriteBool( val.hasTextureTransform, out, version );
			if ( val.hasTextureTransform == true ) {
				WriteFloat( val.translation.u, out );
				WriteFloat( val.translation.v, out );
				WriteFloat( val.tiling.u, out );
				WriteFloat( val.tiling.v, out );
				WriteFloat( val.w_rotation, out );
				WriteUInt( val.transform_type, out );
				WriteFloat( val.center_offset.u, out );
				WriteFloat( val.center_offset.v, out );
			}
		}
	}
};

string HexString( const byte * src, uint len ) {
	stringstream out;
	
	//Display Data in Hex form
	out << hex << setfill('0');

	for ( uint i = 0; i < len; ++i ) {
		out << uppercase << setw(2) << uint(src[i]);
		if (i % 16 == 15 || i == len - 1)
			out << endl;
		else if (i % 16 == 7)
			out << "   ";
		else if (i % 8 == 3)
			out << "  ";
		else
			out << " ";
	}

	return out.str();

}

//string indent( int level ) {
//	string tmp;
//	tmp.resize( level * 3 );
//	for ( uint i = 0; i < level * 3; ++i ) {
//		tmp[i] = ' ';
//	}
//	return tmp;
//}


////As String
//void NifString( uint const & val, stringstream& out, string heading, int ind_lvl ) {
//	out << indent(ind_lvl) << heading << val << endl;
//}
//
//void NifString( ushort const & val, stringstream& out, string heading, int ind_lvl ) {
//	out << indent(ind_lvl) << heading << val << endl;
//}
//
//void NifString( byte const & val, stringstream& out, string heading, int ind_lvl ) {
//	out << indent(ind_lvl) << heading << val << endl;
//}
//
//void NifString( float const & val, stringstream& out, string heading, int ind_lvl ) {
//	out << indent(ind_lvl) << heading << val << endl;
//}
//
//void NifString( string const & val, stringstream& out, string heading, int ind_lvl ) {
//	out << indent(ind_lvl) << heading << val << endl;
//}
//
//void NifString( Vector3 const & val, stringstream& out, string heading, int ind_lvl ) {
//	out << indent(ind_lvl) << heading << val.x <<  << endl;
//}
//
//void NifString( Quaternion const & val, stringstream& out, string heading, int ind_lvl ) {
//
//}
//
//void NifString( KeyType const & val, stringstream& out, string heading, int ind_lvl ) {
//
//}
//
//void NifString( Color4 const & val, stringstream& out, string heading, int ind_lvl ) {
//
//}
//
//void NifString( Triangle const & val, stringstream& out, string heading, int ind_lvl ) {
//
//}

 void StreamQuatKey( Key<Quaternion> & key, istream& file, KeyType type ) {
	key.time = ReadFloat( file );

	//If key type is not 1, 2, or 3, throw an exception
	if ( type < 1 || type > 3 ) {
		type = LINEAR_KEY;
		//throw runtime_error("Invalid key type.");
	}

	//Read data based on the type of key
	NifStream( key.data, file );
	if ( type == TBC_KEY ) {
		//Uses TBC interpolation
		key.tension = ReadFloat( file );
		key.bias = ReadFloat( file );
		key.continuity = ReadFloat( file );
	}
}


void StreamQuatKey( Key<Quaternion> const & key, ostream& file, KeyType type ) {
	WriteFloat( key.time, file );

	//If key type is not 1, 2, or 3, throw an exception
	if ( type < 1 || type > 3 ) {
		type = LINEAR_KEY;
		//throw runtime_error("Invalid key type.");
	}

	//Read data based on the type of key
	NifStream( key.data, file );
	if ( type == TBC_KEY ) {
		//Uses TBC interpolation
		WriteFloat( key.tension, file);
		WriteFloat( key.bias, file);
		WriteFloat( key.continuity, file);
	}
}
