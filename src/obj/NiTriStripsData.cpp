/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTriStripsData.h"
#include "../../NvTriStrip/NvTriStrip.h"

using namespace Niflib;

//Definition of TYPE constant
const Type NiTriStripsData::TYPE("NiTriStripsData", &NI_TRI_STRIPS_DATA_PARENT::TypeConst() );

NiTriStripsData::NiTriStripsData() NI_TRI_STRIPS_DATA_CONSTRUCT {}

NiTriStripsData::~NiTriStripsData() {}

void NiTriStripsData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_STRIPS_DATA_READ
}

void NiTriStripsData::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const {
	NI_TRI_STRIPS_DATA_WRITE
}

string NiTriStripsData::asString( bool verbose ) const {
	NI_TRI_STRIPS_DATA_STRING
}

void NiTriStripsData::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	NI_TRI_STRIPS_DATA_FIXLINKS
}

list<NiObjectRef> NiTriStripsData::GetRefs() const {
	NI_TRI_STRIPS_DATA_GETREFS
}

const Type & NiTriStripsData::GetType() const {
	return TYPE;
};

ushort NiTriStripsData::GetStripCount() const {
	return ushort(points.size());
}

void NiTriStripsData::SetStripCount(int n) {
	points.resize( n );
   stripLengths.resize( n );
   hasPoints = (n != 0);

	//Recalculate Triangle Count
	numTriangles = CalcTriangleCount();
}

//Getters
vector<ushort> NiTriStripsData::GetStrip( int index ) const {
	return points[index];
}

vector<Triangle> NiTriStripsData::GetTriangles() const {

	//Create a vector to hold the triangles
	vector<Triangle> triangles;
	int n = 0; // Current triangle

	//Cycle through all strips
	vector< vector<ushort> >::const_iterator it;
	Triangle t;
	for (it = points.begin(); it != points.end(); ++it ) {
		//The first three values in the strip are the first triangle
		t.Set( (*it)[0], (*it)[1], (*it)[2] );

		//Only add triangles to the list if none of the vertices match
		if ( t[0] != t[1] && t[0] != t[2] && t[1] != t[2] ) {
			triangles.push_back(t);
		}

		//Move to the next triangle
		++n;

		//The remaining triangles use the previous two indices as their first two indices.
		for( uint i = 3; i < it->size(); ++i ) {
			//Odd numbered triangles need to be reversed to keep the vertices in counter-clockwise order
			if ( i % 2 == 0 ) {
				//cout << (*it)[i - 2] << ", " << (*it)[i - 1] << ", " << (*it)[i] << endl;
				t.Set( (*it)[i - 2], (*it)[i - 1], (*it)[i] );
			} else {
				//cout << (*it)[i] << ", " << (*it)[i - 1] << ", " << (*it)[i - 2] << endl;
				t.Set( (*it)[i], (*it)[i - 1], (*it)[i - 2] );
			}

			//Only add triangles to the list if none of the vertices match
			if ( t[0] != t[1] && t[0] != t[2] && t[1] != t[2] ) {
				triangles.push_back(t);
			}

			//Move to the next triangle
			++n;
		}
	}

	return triangles;
}

//Setter
void NiTriStripsData::SetStrip( int index, const vector<ushort> & in ) {
	points[index] = in;

	//Recalculate Triangle Count
	numTriangles = CalcTriangleCount();
}

ushort NiTriStripsData::CalcTriangleCount() const {

	//Calculate number of triangles
	//Sum of length of each strip - 2
	ushort numTriangles = 0;
	for ( uint i = 0; i < points.size(); ++i ) {
		numTriangles += ushort(points[i].size() - 2);
	}

	return numTriangles;
}

void NiTriStripsData::SetTriangles( const vector<Triangle> & in ) {
   if ( in.size() > 65535 || in.size() < 0 ) {
      throw runtime_error("Invalid Triangle Count: must be between 0 and 65535.");
   }
   points.clear();
   numTriangles = 0;

   unsigned short *data = new unsigned short[in.size() * 3 * 2];
   for (size_t i=0; i< in.size(); i++) {
      data[i * 3 + 0] = in[i][0];
      data[i * 3 + 1] = in[i][1];
      data[i * 3 + 2] = in[i][2];
   }

   PrimitiveGroup * groups = 0;
   unsigned short numGroups = 0;

   // GF 3+
   SetCacheSize(CACHESIZE_GEFORCE3);
   // don't generate hundreds of strips
   SetStitchStrips(true);
   GenerateStrips(data, in.size()*3, &groups, &numGroups);

   delete [] data;

   if (!groups)
      return;

   SetStripCount(numGroups);
   for (int g=0; g<numGroups; g++) {
      if (groups[g].type == PT_STRIP) {
         vector<Niflib::ushort> strip(groups[g].numIndices);
         for (size_t s=0; s<groups[g].numIndices; s++)
            strip[s] = groups[g].indices[s];
         SetStrip(g, strip);
      }
   }
   delete [] groups;

   //Recalculate Triangle Count
   numTriangles = CalcTriangleCount();
}

