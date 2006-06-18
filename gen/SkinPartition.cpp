/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "SkinPartition.h"
using namespace Niflib;

//Constructor
SkinPartition::SkinPartition() : numVertices((ushort)0), numTriangles((ushort)0), numBones((ushort)0), numStrips((ushort)0), numWeightsPerVertex((ushort)0), hasVertexMap(false), hasVertexWeights(false), hasStrips(false), hasBoneIndices(false) {};

//Destructor
SkinPartition::~SkinPartition() {};

// needs to be moved elsewhere but this will work for now
ushort SkinPartition::CalcNumTriangles() const {
   ushort size = 0;
   if (stripLengths.empty()) {
      size = (ushort)triangles.size();
   } else {
      for (size_t i=0; i<stripLengths.size(); ++i)
         size += (ushort)stripLengths[i];
      size -= 2;
   }
   return size;
}