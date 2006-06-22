/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "NIF_IO.h"
namespace Niflib {

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

/**
 * Read utility functions
 */
int ReadInt( istream& in ){

	int tmp;
	in.read( (char*)&tmp, 4 );
	return tmp;
}

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
float ReadFloat( istream &in ){

	float tmp;
	in.read( reinterpret_cast<char*>(&tmp), sizeof(tmp) );
	return tmp;
}

string ReadString( istream &in ) {
	uint len = ReadUInt( in );
	string out;
	if ( len > 10000 )
	    throw runtime_error("String too long. Not a NIF file or unsupported format?");
	if ( len > 0 ) {
	    out.resize(len);
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
void WriteInt( int val, ostream& out ){

	out.write( (char*)&val, 4 );
}

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

void WriteFloat( float val, ostream& out ){
	out.write( reinterpret_cast<char*>(&val), sizeof(val) );
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

//-- NifStream And ostream Functions --//
// The NifStream functions allow each built-in type to be streamed to and from a file.
// The ostream functions are for writing out a debug string.

//--Basic Types--//

//int
void NifStream( int & val, istream& in, uint version ) { val = ReadInt( in ); };
void NifStream( int const & val, ostream& out, uint version ) { WriteInt( val, out ); }

//uint
void NifStream( uint & val, istream& in, uint version ) { val = ReadUInt( in ); };
void NifStream( uint const & val, ostream& out, uint version ) { WriteUInt( val, out ); }

//ushort
void NifStream( ushort & val, istream& in, uint version ) { val = ReadUShort( in ); };
void NifStream( ushort const & val, ostream& out, uint version ) { WriteUShort( val, out ); }

//short
void NifStream( short & val, istream& in, uint version ) { val = ReadShort( in ); };
void NifStream( short const & val, ostream& out, uint version ) { WriteShort( val, out ); }

//byte
void NifStream( byte & val, istream& in, uint version ) { val = ReadByte( in ); };
void NifStream( byte const & val, ostream& out, uint version ) { WriteByte( val, out ); }

//bool
void NifStream( bool & val, istream& in, uint version ) { val = ReadBool( in, version ); };
void NifStream( bool const & val, ostream& out, uint version ) { WriteBool( val, out, version ); }

//float
void NifStream( float & val, istream& in, uint version ) { val = ReadFloat( in ); };
void NifStream( float const & val, ostream& out, uint version ) { WriteFloat( val, out ); }

//string
void NifStream( string & val, istream& in, uint version ) { val = ReadString( in ); };
void NifStream( string const & val, ostream& out, uint version ) { WriteString( val, out ); }

//--Structs--//

//HeaderString
void NifStream( HeaderString & val, istream& in, uint version ) {
	char tmp[64];
	in.getline( tmp, 64 );
	val.header = tmp;

        // make sure this is a NIF file
        if ( ( val.header.substr(0, 22) != "NetImmerse File Format" )
        && ( val.header.substr(0, 20) != "Gamebryo File Format" ) )
                throw runtime_error("Not a NIF file.");

        // detect old versions
        if ( ( val.header == "NetImmerse File Format, Version 3.1" )
        || ( val.header == "NetImmerse File Format, Version 3.03" )
        || ( val.header == "NetImmerse File Format, Version 3.0" )
        || ( val.header == "NetImmerse File Format, Version 2.3" ) )
                throw runtime_error("Unsupported: " + val.header);
};

void NifStream( HeaderString const & val, ostream& out, uint version ) {
	stringstream header_string;
	if ( version <= VER_10_0_1_0 ) {
		header_string << "NetImmerse File Format, Version ";
	} else {
		header_string << "Gamebryo File Format, Version ";
	}
	char * byte_ver = (char*)&version;
	int int_ver[4] = { byte_ver[3], byte_ver[2], byte_ver[1], byte_ver[0] };


	header_string << int_ver[0] << "." << int_ver[1] << "." << int_ver[2] << "." << int_ver[3];

	out << header_string.str() << "\n";
	WriteByte( 10, out ); // Unknown Byte = 10
};

ostream & operator<<( ostream & out, HeaderString const & val ) {
	return out << val.header;
}

//TexCoord
void NifStream( TexCoord & val, istream& in, uint version ) {
	val.u = ReadFloat( in );
	val.v = ReadFloat( in );
};

void NifStream( TexCoord const & val, ostream& out, uint version ) {
	WriteFloat( val.u, out );
	WriteFloat( val.v, out );
};

//Triangle
void NifStream( Triangle & val, istream& in, uint version ) {
	val.v1 = ReadUShort( in );
	val.v2 = ReadUShort( in );
	val.v3 = ReadUShort( in );
};

void NifStream( Triangle const & val, ostream& out, uint version ) {
	WriteUShort( val.v1, out );
	WriteUShort( val.v2, out );
	WriteUShort( val.v3, out );
};

//Vector3
void NifStream( Vector3 & val, istream& in, uint version ) {
	val.x = ReadFloat( in );
	val.y = ReadFloat( in );
	val.z = ReadFloat( in );
};

void NifStream( Vector3 const & val, ostream& out, uint version ) {
	WriteFloat( val.x, out );
	WriteFloat( val.y, out );
	WriteFloat( val.z, out );
};

//Float2
void NifStream( Float2 & val, istream& in, uint version ) {
	val.data[0] = ReadFloat( in );
	val.data[1] = ReadFloat( in );
};

void NifStream( Float2 const & val, ostream& out, uint version ) {
	WriteFloat( val.data[0], out );
	WriteFloat( val.data[1], out );
};

//Matrix22
void NifStream( Matrix22 & val, istream& in, uint version ) {
	for (int c = 0; c < 2; ++c) {
		for (int r = 0; r < 2; ++r) {
			val[r][c] = ReadFloat( in );
		}
	}
}

void NifStream( Matrix22 const & val, ostream& out, uint version ) {
	for (int c = 0; c < 2; ++c) {
		for (int r = 0; r < 2; ++r) {
			WriteFloat( val[r][c], out );
		}
	}
}

//Float3
void NifStream( Float3 & val, istream& in, uint version ) {
	val.data[0] = ReadFloat( in );
	val.data[1] = ReadFloat( in );
	val.data[2] = ReadFloat( in );
};

void NifStream( Float3 const & val, ostream& out, uint version ) {
	WriteFloat( val.data[0], out );
	WriteFloat( val.data[1], out );
	WriteFloat( val.data[2], out );
};

//Matrix33
void NifStream( Matrix33 & val, istream& in, uint version ) {
	for (int c = 0; c < 3; ++c) {
		for (int r = 0; r < 3; ++r) {
			val[r][c] = ReadFloat( in );
		}
	}
}

void NifStream( Matrix33 const & val, ostream& out, uint version ) {
	for (int c = 0; c < 3; ++c) {
		for (int r = 0; r < 3; ++r) {
			WriteFloat( val[r][c], out );
		}
	}
}

//Float4
void NifStream( Float4 & val, istream& in, uint version ) {
	val.data[0] = ReadFloat( in );
	val.data[1] = ReadFloat( in );
	val.data[2] = ReadFloat( in );
	val.data[3] = ReadFloat( in );
};

void NifStream( Float4 const & val, ostream& out, uint version ) {
	WriteFloat( val.data[0], out );
	WriteFloat( val.data[1], out );
	WriteFloat( val.data[2], out );
	WriteFloat( val.data[4], out );
};

//Matrix44
void NifStream( Matrix44 & val, istream& in, uint version ) {
	for (int c = 0; c < 4; ++c) {
		for (int r = 0; r < 4; ++r) {
			val[r][c] = ReadFloat( in );
		}
	}
}

void NifStream( Matrix44 const & val, ostream& out, uint version ) {
	for (int c = 0; c < 4; ++c) {
		for (int r = 0; r < 4; ++r) {
			WriteFloat( val[r][c], out );
		}
	}
}

//Color3
void NifStream( Color3 & val, istream& in, uint version ) {
	val.r = ReadFloat( in );
	val.g = ReadFloat( in );
	val.b = ReadFloat( in );
};

void NifStream( Color3 const & val, ostream& out, uint version ) {
	WriteFloat( val.r, out );
	WriteFloat( val.g, out );
	WriteFloat( val.b, out );
};

//Color4
void NifStream( Color4 & val, istream& in, uint version ) {
	val.r = ReadFloat( in );
	val.g = ReadFloat( in );
	val.b = ReadFloat( in );
	val.a = ReadFloat( in );
};

void NifStream( Color4 const & val, ostream& out, uint version ) {
	WriteFloat( val.r, out );
	WriteFloat( val.g, out );
	WriteFloat( val.b, out );
	WriteFloat( val.a, out );
};

//Quaternion
void NifStream( Quaternion & val, istream& in, uint version ) {
	val.w = ReadFloat( in );
	val.x = ReadFloat( in );
	val.y = ReadFloat( in );
	val.z = ReadFloat( in );
};

void NifStream( Quaternion const & val, ostream& out, uint version ) {
	WriteFloat( val.w, out );
	WriteFloat( val.x, out );
	WriteFloat( val.y, out );
	WriteFloat( val.z, out );
};

//--Enums--//

//TexType
void NifStream( TexType & val, istream& in, uint version ) { val = TexType(ReadUInt( in )); };
void NifStream( TexType const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, TexType const & val ) {
	switch ( val ) {
		case BASE_MAP: return out << "BASE_MAP";
		case DARK_MAP: return out << "DARK_MAP";
		case DETAIL_MAP: return out << "DETAIL_MAP";
		case GLOSS_MAP: return out << "GLOSS_MAP";
		case GLOW_MAP: return out << "GLOW_MAP";
		case BUMP_MAP: return out << "BUMP_MAP";
		case DECAL_0_MAP: return out << "DECAL_0_MAP";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//ApplyMode
void NifStream( ApplyMode & val, istream& in, uint version ) { val = ApplyMode(ReadUInt( in )); };
void NifStream( ApplyMode const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, ApplyMode const & val ) {
	switch ( val ) {
		case APPLY_REPLACE: return out << "APPLY_REPLACE";
		case APPLY_DECAL: return out << "APPLY_DECAL";
		case APPLY_MODULATE: return out << "APPLY_MODULATE";
		case APPLY_HILIGHT: return out << "APPLY_HILIGHT";
		case APPLY_HILIGHT2: return out << "APPLY_HILIGHT2";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//TexClampMode
void NifStream( TexClampMode & val, istream& in, uint version ) { val = TexClampMode(ReadUInt( in )); };
void NifStream( TexClampMode const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, TexClampMode const & val ) {
	switch ( val ) {
		case CLAMP_S_CLAMP_T: return out << "CLAMP_S_CLAMP_T";
		case CLAMP_S_WRAP_T: return out << "CLAMP_S_WRAP_T";
		case WRAP_S_CLAMP_T: return out << "WRAP_S_CLAMP_T";
		case WRAP_S_WRAP_T: return out << "WRAP_S_WRAP_T";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//TexFilterMode
void NifStream( TexFilterMode & val, istream& in, uint version ) { val = TexFilterMode(ReadUInt( in )); };
void NifStream( TexFilterMode const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, TexFilterMode const & val ) {
	switch ( val ) {
		case FILTER_NEAREST: return out << "FILTER_NEAREST";
		case FILTER_BILERP: return out << "FILTER_BILERP";
		case FILTER_TRILERP: return out << "FILTER_TRILERP";
		case FILTER_NEAREST_MIPNEAREST: return out << "FILTER_NEAREST_MIPNEAREST";
		case FILTER_NEAREST_MIPLERP: return out << "FILTER_NEAREST_MIPLERP";
		case FILTER_BILERP_MIPNEAREST: return out << "FILTER_BILERP_MIPNEAREST";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//AlphaFormat
void NifStream( AlphaFormat & val, istream& in, uint version ) { val = AlphaFormat(ReadUInt( in )); };
void NifStream( AlphaFormat const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, AlphaFormat const & val ) {
	switch ( val ) {
		case ALPHA_NONE: return out << "ALPHA_NONE";
		case ALPHA_BINARY: return out << "ALPHA_BINARY";
		case ALPHA_SMOOTH: return out << "ALPHA_SMOOTH";
		case ALPHA_DEFAULT: return out << "ALPHA_DEFAULT";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//KeyType
void NifStream( KeyType & val, istream& in, uint version ) { val = KeyType(ReadUInt( in )); };
void NifStream( KeyType const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, KeyType const & val ) {
	switch ( val ) {
		case LINEAR_KEY: return out << "LINEAR_KEY";
		case QUADRATIC_KEY: return out << "QUADRATIC_KEY";
		case TBC_KEY: return out << "TBC_KEY";
		case XYZ_ROTATION_KEY: return out << "XYZ_ROTATION_KEY";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//PixelFormat
void NifStream( PixelFormat & val, istream& in, uint version ) { val = PixelFormat(ReadUInt( in )); };
void NifStream( PixelFormat const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, PixelFormat const & val ) {
	switch ( val ) {
		case PX_FMT_RGB8: return out << "PX_FMT_RGB8";
		case PX_FMT_RGBA8: return out << "PX_FMT_RGBA8";
		case PX_FMT_PAL8: return out << "PX_FMT_PAL8";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//MipMapFormat
void NifStream( MipMapFormat & val, istream& in, uint version ) { val = MipMapFormat(ReadUInt( in )); };
void NifStream( MipMapFormat const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, MipMapFormat const & val ) {
	switch ( val ) {
		case MIP_FMT_NO: return out << "MIP_FMT_NO";
		case MIP_FMT_YES: return out << "MIP_FMT_YES";
		case MIP_FMT_DEFAULT: return out << "MIP_FMT_DEFAULT";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//PixelLayout
void NifStream( PixelLayout & val, istream& in, uint version ) { val = PixelLayout(ReadUInt( in )); };
void NifStream( PixelLayout const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, PixelLayout const & val ) {
	switch ( val ) {
		case PIX_LAY_PALETTISED: return out << "PIX_LAY_PALETTISED";
		case PIX_LAY_HIGH_COLOR_16: return out << "PIX_LAY_HIGH_COLOR_16";
		case PIX_LAY_TRUE_COLOR_32: return out << "PIX_LAY_TRUE_COLOR_32";
		case PIX_LAY_COMPRESSED: return out << "PIX_LAY_COMPRESSED";
		case PIX_LAY_BUMPMAP: return out << "PIX_LAY_BUMPMAP";
		case PIX_LAY_DEFAULT: return out << "PIX_LAY_DEFAULT";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//VertMode
void NifStream( VertMode & val, istream& in, uint version ) { val = VertMode(ReadUInt( in )); };
void NifStream( VertMode const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, VertMode const & val ) {
	switch ( val ) {
		case VERT_MODE_SRC_IGNORE: return out << "VERT_MODE_SRC_IGNORE";
		case VERT_MODE_SRC_EMISSIVE: return out << "VERT_MODE_SRC_EMISSIVE";
		case VERT_MODE_SRC_AMB_DIF: return out << "VERT_MODE_SRC_AMB_DIF";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//LightMode
void NifStream( LightMode & val, istream& in, uint version ) { val = LightMode(ReadUInt( in )); };
void NifStream( LightMode const & val, ostream& out, uint version ) { WriteUInt( val, out ); }
ostream & operator<<( ostream & out, LightMode const & val ) {
	switch ( val ) {
		case LIGHT_MODE_EMISSIVE: return out << "LIGHT_MODE_EMISSIVE";
		case LIGHT_MODE_EMI_AMB_DIF: return out << "LIGHT_MODE_EMI_AMB_DIF";
		default: return out << "Invalid Value! - " << uint(val);
	};
}

//The HexString function creates a formatted hex display of the given data for use in printing
//a debug string for information that is not understood
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

//Byte
ostream & operator<<( ostream & out, byte const & val ) {
	return out << uint(val);
}

void NifStream( Key<Quaternion> & key, istream& file, uint version, KeyType type ) {
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


void NifStream( Key<Quaternion> const & key, ostream& file, uint version,  KeyType type ) {
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

}
