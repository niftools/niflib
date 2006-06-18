/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "Header.h"
#include "ShortString.h"
#include "ShortString.h"
#include "ShortString.h"
using namespace NifLib;

//Constructor
Header::Header() : version((uint)0x04000002), endianType((byte)1), userVersion((uint)0), numBlocks((uint)0), unknownInt1((uint)0), unknownInt3((uint)0), numBlockTypes((ushort)0), unknownInt2((uint)0) {};

//Destructor
Header::~Header() {};
void Header::Read( istream& in ) {
	NifStream( headerString, in, version );
	NifStream( version, in, version );
	if ( version >= 0x14000004 ) {
		NifStream( endianType, in, version );
	};
	if ( version >= 0x0A010000 ) {
		NifStream( userVersion, in, version );
	};
	NifStream( numBlocks, in, version );
	if ( ( version >= 0x0A000102 ) && ( version <= 0x0A000102 ) ) {
		NifStream( unknownInt1, in, version );
	};
	if ( version >= 0x0A010000 ) {
		if ( (userVersion != 0) ) {
			NifStream( unknownInt3, in, version );
		};
	};
	if ( version >= 0x0A000102 ) {
		if ( (userVersion != 0) ) {
			NifStream( creator_.length, in, version );
			creator_.value.resize(creator_.length);
			for (uint i3 = 0; i3 < creator_.value.size(); i3++) {
				NifStream( creator_.value[i3], in, version );
			};
			NifStream( exportType_.length, in, version );
			exportType_.value.resize(exportType_.length);
			for (uint i3 = 0; i3 < exportType_.value.size(); i3++) {
				NifStream( exportType_.value[i3], in, version );
			};
			NifStream( exportScript_.length, in, version );
			exportScript_.value.resize(exportScript_.length);
			for (uint i3 = 0; i3 < exportScript_.value.size(); i3++) {
				NifStream( exportScript_.value[i3], in, version );
			};
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
	NifStream( version, out, version );
	if ( version >= 0x14000004 ) {
		NifStream( endianType, out, version );
	};
	if ( version >= 0x0A010000 ) {
		NifStream( userVersion, out, version );
	};
	NifStream( numBlocks, out, version );
	if ( ( version >= 0x0A000102 ) && ( version <= 0x0A000102 ) ) {
		NifStream( unknownInt1, out, version );
	};
	if ( version >= 0x0A010000 ) {
		if ( (userVersion != 0) ) {
			NifStream( unknownInt3, out, version );
		};
	};
	if ( version >= 0x0A000102 ) {
		if ( (userVersion != 0) ) {
			creator_.length = byte(creator_.value.size());
			NifStream( creator_.length, out, version );
			for (uint i3 = 0; i3 < creator_.value.size(); i3++) {
				NifStream( creator_.value[i3], out, version );
			};
			exportType_.length = byte(exportType_.value.size());
			NifStream( exportType_.length, out, version );
			for (uint i3 = 0; i3 < exportType_.value.size(); i3++) {
				NifStream( exportType_.value[i3], out, version );
			};
			exportScript_.length = byte(exportScript_.value.size());
			NifStream( exportScript_.length, out, version );
			for (uint i3 = 0; i3 < exportScript_.value.size(); i3++) {
				NifStream( exportScript_.value[i3], out, version );
			};
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
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	if ( (userVersion != 0) ) {
		out << "    Unknown Int 3:  " << unknownInt3 << endl;
		creator_.length = byte(creator_.value.size());
		out << "    Length:  " << creator_.length << endl;
		for (uint i2 = 0; i2 < creator_.value.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Value[" << i2 << "]:  " << creator_.value[i2] << endl;
		};
		exportType_.length = byte(exportType_.value.size());
		out << "    Length:  " << exportType_.length << endl;
		for (uint i2 = 0; i2 < exportType_.value.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Value[" << i2 << "]:  " << exportType_.value[i2] << endl;
		};
		exportScript_.length = byte(exportScript_.value.size());
		out << "    Length:  " << exportScript_.length << endl;
		for (uint i2 = 0; i2 < exportScript_.value.size(); i2++) {
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Value[" << i2 << "]:  " << exportScript_.value[i2] << endl;
		};
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
