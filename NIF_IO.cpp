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

ostream & operator<<(ostream & lh, fVector2 & rh) {
	return lh << "(" << setw(5) << rh[0] << ", " << setw(5) << rh[1] << ")";
}

ostream & operator<<(ostream & lh, fVector3 & rh) {
	return lh << "(" << setw(5) << rh[0] << ", " << setw(5) << rh[1] << ", " << setw(5) << rh[2] << ")";
}

ostream & operator<<(ostream & lh, fVector4 & rh) {
	return lh << "(" << setw(5) << rh[0] << ", " << setw(5) << rh[1] << ", " << setw(5) << rh[2] << ", " << setw(5) << rh[3] << ")";
}

ostream & operator<<(ostream & lh, usVector3 & rh) {
	return lh << "(" << setw(4) << rh[0] << ", " << setw(4) << rh[1] << ", " << setw(4) << rh[2] << ")";
}

ostream & operator<<(ostream & lh, nifApplyMode & rh) {
	switch (int(rh)) {
		case 0: return lh << "Replace (0)";
		case 1: return lh << "Decal (1)";
		case 2: return lh << "Modulate (2)";
		case 3: return lh << "Hilight (3 - PS2 Only)";
		case 4: return lh << "Hilight2 (4 - PS2 Only)";
	}
	return lh;
}

ostream & operator<<(ostream & lh, nifPixelLayout & rh) {
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

ostream & operator<<(ostream & lh, nifMipMapFormat & rh) {
	switch (int(rh)) {
		case 0: return lh << "No (0)";
		case 1: return lh << "Yes (1)";
		case 2: return lh << "Default (2)";
	}
	return lh;
}

ostream & operator<<(ostream & lh, nifAlphaFormat & rh) {
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

void WriteUSVector3( usVector3& vec, ofstream& out ){

	WriteUShort( vec[0], out );
	WriteUShort( vec[1], out );
	WriteUShort( vec[2], out );
}

void WriteFloat( float val, ofstream& out ){

	out.write( reinterpret_cast<char*>(&val), sizeof(val) );
}

void WriteFVector2( fVector2& fvec, ofstream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
}

void WriteFVector3( fVector3& fvec, ofstream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
	WriteFloat( fvec[2], out );
}

void WriteFVector4( fVector4& fvec, ofstream& out ){

	WriteFloat( fvec[0], out );
	WriteFloat( fvec[1], out );
	WriteFloat( fvec[2], out );
	WriteFloat( fvec[3], out );
}

void WriteString( string val, ofstream& out ) {
	WriteUInt( uint(val.size()), out );
	out.write( val.c_str(), std::streamsize(val.size()) );
}

void WriteBlockName( const char* name, uint nameLength, ofstream& out ){

	WriteUInt( nameLength, out );
	out.write( name, nameLength );
}

ostream & operator<<(ostream & lh, nifIndex & rh) {
	if (rh._index != -1) {
		lh << "Block " << rh._index;
	} else {
		lh << "None";
	}
	return lh;
}