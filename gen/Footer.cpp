/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "Footer.h"
#include "../obj/NiAVObject.h"
using namespace NifLib;

//Constructor
Footer::Footer() : numRoots((uint)0) {};

//Destructor
Footer::~Footer() {};

void Footer::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	uint block_num;
	NifStream( numRoots, in, version );
	roots.resize(numRoots);
	for (uint i1 = 0; i1 < roots.size(); i1++) {
		NifStream( block_num, in, version );
		link_stack.push_back( block_num );
	};
}

void Footer::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	numRoots = uint(roots.size());
	NifStream( numRoots, out, version );
	for (uint i1 = 0; i1 < roots.size(); i1++) {
		if ( roots[i1] != NULL )
			NifStream( link_map[StaticCast<NiObject>(roots[i1])], out, version );
		else
			NifStream( 0xffffffff, out, version );
	};
}

string Footer::asString( bool verbose ) const {
	stringstream out;
	numRoots = uint(roots.size());
	out << "  Num Roots:  " << numRoots << endl;
	for (uint i1 = 0; i1 < roots.size(); i1++) {
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Roots[" << i1 << "]:  " << roots[i1] << endl;
	};
	return out.str();
}
