/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/obj/NiTriStripsData.h"
#include "../../NvTriStrip/NvTriStrip.h"
#include "../../TriStripper/tri_stripper.h"

using namespace Niflib;
using namespace triangle_stripper;

// Helper methods
typedef vector<unsigned short> TriStrip;
typedef	list<TriStrip> TriStrips;


//Definition of TYPE constant
const Type NiTriStripsData::TYPE("NiTriStripsData", &NI_TRI_STRIPS_DATA_PARENT::TypeConst() );

NiTriStripsData::NiTriStripsData() NI_TRI_STRIPS_DATA_CONSTRUCT {}

NiTriStripsData::~NiTriStripsData() {}

void NiTriStripsData::Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalRead( in, link_stack, version, user_version );
}

void NiTriStripsData::Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const {
	InternalWrite( out, link_map, version, user_version );
}

string NiTriStripsData::asString( bool verbose ) const {
	return InternalAsString( verbose );
}

void NiTriStripsData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version ) {
	InternalFixLinks( objects, link_stack, version, user_version );
}

list<NiObjectRef> NiTriStripsData::GetRefs() const {
	return InternalGetRefs();
}

const Type & NiTriStripsData::GetType() const {
	return TYPE;
};

NiTriStripsData::NiTriStripsData(const vector<Triangle> &tris, bool nvtristrips) {
   if (nvtristrips)
      SetNvTriangles(tris);
   else
      SetTSTriangles(tris);
}

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
				t.Set( (*it)[i - 2], (*it)[i - 1], (*it)[i] );
			} else {
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
   SetNvTriangles(in);
}

void NiTriStripsData::SetNvTriangles( const vector<Triangle> & in ) {
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

void NiTriStripsData::SetTSTriangles( const vector<Triangle> & in ) {
   if ( in.size() > 65535 || in.size() < 0 ) {
      throw runtime_error("Invalid Triangle Count: must be between 0 and 65535.");
   }

   points.clear();
   numTriangles = 0;

   TriStrips strips;
   vector<unsigned int> idcs(in.size()*3);
   size_t i, j;
   for (i=0; i<in.size(); i++)
   {
      idcs[i * 3 + 0] = in[i][0];
      idcs[i * 3 + 1] = in[i][1];
      idcs[i * 3 + 2] = in[i][2];
   }

   tri_stripper stripper(idcs);

   primitive_vector groups;
   stripper.Strip(&groups);

   // triangles left over
   vector<Triangle> stris;

   for (i=0; i<groups.size(); i++)
   {
      if (groups[i].Type == TRIANGLE_STRIP)
      {			
         strips.push_back(TriStrip(groups[i].Indices.size()));
         TriStrip &strip = strips.back();

         for (j=0; j<groups[i].Indices.size(); j++)
            strip[j] = groups[i].Indices[j];
      } else
      {
         int size = stris.size();
         stris.resize(size + groups[i].Indices.size()/3);
         for (j=(size>0)?(size-1):0; j<stris.size(); j++)
         {
            stris[j][0] = groups[i].Indices[j*3+0];
            stris[j][1] = groups[i].Indices[j*3+1];
            stris[j][2] = groups[i].Indices[j*3+2];
         }
      }
   }

   if (stris.size())
   {
      // stitch em
      TriStrip strip;
      if (strips.size() > 0)
      {
         strip.push_back(strips.back()[strips.back().size()-1]);
         strip.push_back(stris[0][0]);
      }
      for (i=0; i<stris.size(); i++)
      {
         if (i > 0)
         {
            strip.push_back(stris[i][0]);
            strip.push_back(stris[i][0]);
         }

         strip.push_back(stris[i][0]);
         strip.push_back(stris[i][1]);
         strip.push_back(stris[i][2]);
         if (i < stris.size()-1)
            strip.push_back(stris[i][2]);
      }
      strips.push_back(strip);
   }

   if (strips.size() > 0)
   {
      SetStripCount(strips.size());

      int i = 0;
      TriStrips::const_iterator it;
      for (it=strips.begin(); it!=strips.end(); ++it)
         SetStrip(i++, *it);
   }

   //Recalculate Triangle Count
   numTriangles = CalcTriangleCount();
}
