/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "APSysData.h"

//Definition of TYPE constant
const Type APSysData::TYPE("APSysData", &A_P_SYS_DATA_PARENT::TYPE );

APSysData::APSysData() A_P_SYS_DATA_CONSTRUCT {}

APSysData::~APSysData() {}

void APSysData::Read( istream& in, list<uint> link_stack, unsigned int version ) {
	//A_P_SYS_DATA_READ
TriBasedGeomData::Read( in, link_stack, version ); \
ushort numVertices = ushort(vertices.size());
NifStream( hasUnknownFloats1, in, version ); \
if ( hasUnknownFloats1 != 0 ) { \
  unknownFloats1.resize(numVertices); \
  for (uint i1 = 0; i1 < numVertices; i1++) { \
    NifStream( unknownFloats1[i1], in, version ); \
  }; \
}; \
NifStream( unknownShort3, in, version ); \
NifStream( hasUnknownFloats2, in, version ); \
if ( hasUnknownFloats2 != 0 ) { \
  unknownFloats2.resize(numVertices); \
  for (uint i1 = 0; i1 < numVertices; i1++) { \
    NifStream( unknownFloats2[i1], in, version ); \
  }; \
}; \
NifStream( unknownByte1, in, version ); \
}

void APSysData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
	//A_P_SYS_DATA_WRITE
TriBasedGeomData::Write( out, link_map, version ); \
ushort numVertices = ushort(vertices.size());
NifStream( hasUnknownFloats1, out, version ); \
if ( hasUnknownFloats1 != 0 ) { \
  for (uint i1 = 0; i1 < numVertices; i1++) { \
    NifStream( unknownFloats1[i1], out, version ); \
  }; \
}; \
NifStream( unknownShort3, out, version ); \
NifStream( hasUnknownFloats2, out, version ); \
if ( hasUnknownFloats2 != 0 ) { \
  for (uint i1 = 0; i1 < numVertices; i1++) { \
    NifStream( unknownFloats2[i1], out, version ); \
  }; \
}; \
NifStream( unknownByte1, out, version ); \
}

string APSysData::asString( bool verbose ) const {
	//A_P_SYS_DATA_STRING
ushort numVertices = ushort(vertices.size());
stringstream out; \
out << TriBasedGeomData::asString(); \
out << "Has Unknown Floats 1:  " << hasUnknownFloats1 << endl; \
if ( hasUnknownFloats1 != 0 ) { \
  for (uint i1 = 0; i1 < numVertices; i1++) { \
    out << "    Unknown Floats 1[" << i1 << "]:  " << unknownFloats1[i1] << endl; \
  }; \
}; \
out << "Unknown Short 3:  " << unknownShort3 << endl; \
out << "Has Unknown Floats 2:  " << hasUnknownFloats2 << endl; \
if ( hasUnknownFloats2 != 0 ) { \
  for (uint i1 = 0; i1 < numVertices; i1++) { \
    out << "    Unknown Floats 2[" << i1 << "]:  " << unknownFloats2[i1] << endl; \
  }; \
}; \
out << "Unknown Byte 1:  " << unknownByte1 << endl; \
return out.str(); \
}

void APSysData::FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) {
	//A_P_SYS_DATA_FIXLINKS // no links
}

