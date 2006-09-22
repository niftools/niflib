/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/Header.h"
using namespace Niflib;

//Constructor
Header::Header() : version((uint)0x04000002), endianType((byte)1), userVersion((uint)0), numBlocks((uint)0), userVersion2((uint)0), numBlockTypes((ushort)0), unknownInt2((uint)0) {};

//Destructor
Header::~Header() {};
void Header::Read( istream& in ) {
	NifStream( headerString, in, version );
	if ( version >= 0x0303000D ) {
		NifStream( version, in, version );
	};
	if ( version >= 0x14000004 ) {
		NifStream( endianType, in, version );
	};
	if ( version >= 0x0A010000 ) {
		NifStream( userVersion, in, version );
	};
	if ( version >= 0x0303000D ) {
		NifStream( numBlocks, in, version );
	};
	if ( ( version >= 0x0A000102 ) && ( version <= 0x0A000102 ) ) {
		NifStream( userVersion, in, version );
	};
	if ( version >= 0x0A010000 ) {
		if ( (userVersion != 0) ) {
			NifStream( userVersion2, in, version );
		};
	};
	if ( version >= 0x0A000102 ) {
		if ( (userVersion != 0) ) {
			NifStream( creator, in, version );
			NifStream( exportInfo1, in, version );
			NifStream( exportInfo2, in, version );
		};
	};
	if ( version >= 0x0A000100 ) {
		NifStream( numBlockTypes, in, version );
		blockTypes.resize(numBlockTypes);
		for (uint i2 = 0; i2 < blockTypes.size(); i2++) {
			NifStream( blockTypes[i2], in, version );
		};
		blockTypeIndex.resize(numBlocks);
		for (uint i2 = 0; i2 < blockTypeIndex.size(); i2++) {
			NifStream( blockTypeIndex[i2], in, version );
		};
		NifStream( unknownInt2, in, version );
	};
}

void Header::Write( ostream& out ) const {
	numBlockTypes = ushort(blockTypes.size());
	numBlocks = uint(blockTypeIndex.size());
	NifStream( headerString, out, version );
	if ( version >= 0x0303000D ) {
		NifStream( version, out, version );
	};
	if ( version >= 0x14000004 ) {
		NifStream( endianType, out, version );
	};
	if ( version >= 0x0A010000 ) {
		NifStream( userVersion, out, version );
	};
	if ( version >= 0x0303000D ) {
		NifStream( numBlocks, out, version );
	};
	if ( ( version >= 0x0A000102 ) && ( version <= 0x0A000102 ) ) {
		NifStream( userVersion, out, version );
	};
	if ( version >= 0x0A010000 ) {
		if ( (userVersion != 0) ) {
			NifStream( userVersion2, out, version );
		};
	};
	if ( version >= 0x0A000102 ) {
		if ( (userVersion != 0) ) {
			NifStream( creator, out, version );
			NifStream( exportInfo1, out, version );
			NifStream( exportInfo2, out, version );
		};
	};
	if ( version >= 0x0A000100 ) {
		NifStream( numBlockTypes, out, version );
		for (uint i2 = 0; i2 < blockTypes.size(); i2++) {
			NifStream( blockTypes[i2], out, version );
		};
		for (uint i2 = 0; i2 < blockTypeIndex.size(); i2++) {
			NifStream( blockTypeIndex[i2], out, version );
		};
		NifStream( unknownInt2, out, version );
	};
}

string Header::asString( bool verbose ) const {
	stringstream out;
	numBlockTypes = ushort(blockTypes.size());
	numBlocks = uint(blockTypeIndex.size());
	out << "  Header String:  " << headerString << endl;
	out << "  Version:  " << version << endl;
	out << "  Endian Type:  " << endianType << endl;
	out << "  User Version:  " << userVersion << endl;
	out << "  Num Blocks:  " << numBlocks << endl;
	if ( (userVersion != 0) ) {
		out << "    User Version 2:  " << userVersion2 << endl;
		out << "    Creator:  " << creator << endl;
		out << "    Export Info 1:  " << exportInfo1 << endl;
		out << "    Export Info 2:  " << exportInfo2 << endl;
	};
	out << "  Num Block Types:  " << numBlockTypes << endl;
	for (uint i1 = 0; i1 < blockTypes.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Block Types[" << i1 << "]:  " << blockTypes[i1] << endl;
	};
	for (uint i1 = 0; i1 < blockTypeIndex.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Block Type Index[" << i1 << "]:  " << blockTypeIndex[i1] << endl;
	};
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	return out.str();
}
