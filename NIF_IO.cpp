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
int BlockSearch( ifstream& in ) {

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

ostream & operator<<(ostream & lh, ApplyMode const & rh) {
	switch (int(rh)) {
		case 0: return lh << "Replace (0)";
		case 1: return lh << "Decal (1)";
		case 2: return lh << "Modulate (2)";
		case 3: return lh << "Hilight (3 - PS2 Only)";
		case 4: return lh << "Hilight2 (4 - PS2 Only)";
	}
	return lh;
}

ostream & operator<<(ostream & lh, nifPixelLayout const & rh) {
	switch (int(rh)) {
		case 0: return lh << "Palettised (0)";
		case 1: return lh << "16-bit High Color (1)";
		case 2: return lh << "32-bit True Color (2)";
		case 3: return lh << "Compressed (3)";
		case 4: return lh << "Bump Map (4)";
		case 5: return lh << "Default (5)";
	}
	return lh;
}

ostream & operator<<(ostream & lh, nifMipMapFormat const & rh) {
	switch (int(rh)) {
		case 0: return lh << "No (0)";
		case 1: return lh << "Yes (1)";
		case 2: return lh << "Default (2)";
	}
	return lh;
}

ostream & operator<<(ostream & lh, nifAlphaFormat const & rh) {
	switch (int(rh)) {
		case 0: return lh << "None (0)";
		case 1: return lh << "Binary (1)";
		case 2: return lh << "Smooth (2)";
		case 3: return lh << "Default (3)";
	}
	return lh;
}

/**
 * Read utility functions
 */
uint ReadUInt( ifstream& in ){

	uint tmp;
	in.read( (char*)&tmp, 4 );
	return tmp;
}

ushort ReadUShort( ifstream& in ){

	ushort tmp;
	in.read( (char*)&tmp, 2 );
	return tmp;
}

byte ReadByte( ifstream& in ){

	byte tmp;
	in.read( (char*)&tmp, 1 );
	return tmp;
}

void ReadUSVector3( usVector3& vec, ifstream& in ){

	vec[0] = ReadUShort( in );
	vec[1] = ReadUShort( in );
	vec[2] = ReadUShort( in );
}

float ReadFloat( ifstream &in ){

	float tmp;
	in.read( reinterpret_cast<char*>(&tmp), sizeof(tmp) );
	return tmp;
}

void ReadFVector2( fVector2& fvec, ifstream& in ){

	fvec[0] = ReadFloat( in );
	fvec[1] = ReadFloat( in );
}

void ReadFVector3( fVector3& fvec, ifstream& in ){

	fvec[0] = ReadFloat( in );
	fvec[1] = ReadFloat( in );
	fvec[2] = ReadFloat( in );
}

void ReadFVector4( fVector4& fvec, ifstream& in ){

	fvec[0] = ReadFloat( in );
	fvec[1] = ReadFloat( in );
	fvec[2] = ReadFloat( in );
	fvec[3] = ReadFloat( in );
}

string ReadString( ifstream &in ) {
	uint len = ReadUInt( in );
	char * str = new char[len + 1];
	in.read( str, len );
	str[len] = 0;
	string out = str;
	delete [] str;
	return out;
}

bool ReadBool( ifstream &in, unsigned int version ) {
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
void WriteUInt( uint val, ofstream& out ){

	out.write( (char*)&val, 4 );
}

void WriteUShort( ushort val, ofstream& out ){

	out.write( (char*)&val, 2 );
}

void WriteByte( byte val, ofstream& out ){

	out.write( (char*)&val, 1 );
}

void WriteUSVector3( usVector3 const & vec, ofstream& out ){

	WriteUShort( vec[0], out );
	WriteUShort( vec[1], out );
	WriteUShort( vec[2], out );
}

void WriteFloat( float val, ofstream& out ){

	out.write( reinterpret_cast<char*>(&val), sizeof(val) );
}

void WriteFVector2( fVector2 const & fvec, ofstream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
}

void WriteFVector3( fVector3 const & fvec, ofstream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
	WriteFloat( fvec[2], out );
}

void WriteFVector4( fVector4 const & fvec, ofstream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
	WriteFloat( fvec[2], out );
	WriteFloat( fvec[3], out );
}

void WriteString( string const & val, ofstream& out ) {
	WriteUInt( uint(val.size()), out );
	out.write( val.c_str(), std::streamsize(val.size()) );
}

void WriteBool( bool val, ofstream& out, unsigned int version ) {
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

void WriteBlockName( const char* name, uint nameLength, ofstream& out ){

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

void NifStream( uint & val, ifstream& in ) { val = ReadUInt( in ); };
void NifStream( ushort & val, ifstream& in ) { val = ReadUShort( in ); };
void NifStream( byte & val, ifstream& in ) { val = ReadByte( in ); };
void NifStream( float & val, ifstream& in ) { val = ReadFloat( in ); };
void NifStream( string & val, ifstream& in ) { val = ReadString( in ); };
void NifStream( KeyType & val, ifstream& in ) { val = KeyType(ReadUInt( in )); };

void NifStream( Vector3 & val, ifstream& in ) {
	val.x = ReadFloat( in );
	val.y = ReadFloat( in );
	val.z = ReadFloat( in );
};

void NifStream( Quaternion & val, ifstream& in ) {
	val.w = ReadFloat( in );
	val.x = ReadFloat( in );
	val.y = ReadFloat( in );
	val.z = ReadFloat( in );
};

void NifStream( Color4 & val, ifstream& in ) {
	val.r = ReadFloat( in );
	val.g = ReadFloat( in );
	val.b = ReadFloat( in );
	val.a = ReadFloat( in );
};

void NifStream( Triangle & val, ifstream& in ) {
	val.v1 = ReadUShort( in );
	val.v2 = ReadUShort( in );
	val.v3 = ReadUShort( in );
};

void NifStream( TexDesc & val, ifstream& in, uint version ) {
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
			val.hasUnknownData = ReadBool( in, version );
			if ( val.hasUnknownData == true ) {
				for (int i = 0; i < 5; ++i ) {
					val.unknown5Floats[i] = ReadFloat( in );;
				}
				val.unknownInt = ReadUInt( in );
				val.unknownFloat1 = ReadFloat( in );
				val.unknownFloat2 = ReadFloat( in );
			}
		}
	}
}



void NifStream( uint const & val, ofstream& out ) { WriteUInt( val, out ); }
void NifStream( ushort const & val, ofstream& out ) { WriteUShort( val, out ); }
void NifStream( byte const & val, ofstream& out ) { WriteByte( val, out ); }
void NifStream( float const & val, ofstream& out ) { WriteFloat( val, out ); }
void NifStream( string const & val, ofstream& out ) { WriteString( val, out ); }
void NifStream( KeyType const & val, ofstream& out ) { WriteUInt( val, out ); }
void NifStream( Vector3 const & val, ofstream& out ) {
	WriteFloat( val.x, out );
	WriteFloat( val.y, out );
	WriteFloat( val.z, out );
};
void NifStream( Quaternion const & val, ofstream& out ) {
	WriteFloat( val.w, out );
	WriteFloat( val.x, out );
	WriteFloat( val.y, out );
	WriteFloat( val.z, out );
};
void NifStream( Color4 const & val, ofstream& out ) {
	WriteFloat( val.r, out );
	WriteFloat( val.g, out );
	WriteFloat( val.b, out );
	WriteFloat( val.a, out );
};
void NifStream( Triangle const & val, ofstream& out ) {
	WriteUShort( val.v1, out );
	WriteUShort( val.v2, out );
	WriteUShort( val.v3, out );
};
void NifStream( TexDesc const & val, ofstream& out, uint version ) {
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
			WriteBool( val.hasUnknownData, out, version );
			if ( val.hasUnknownData == true ) {
				for (int i = 0; i < 5; ++i ) {
					WriteFloat( val.unknown5Floats[i], out );;
				}
				WriteUInt( val.unknownInt, out );
				WriteFloat( val.unknownFloat1, out );
				WriteFloat( val.unknownFloat2, out );
			}
		}
	}
};

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


