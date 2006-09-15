/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "../../include/gen/SkinPartition.h"
using namespace Niflib;

//Constructor
SkinPartition::SkinPartition() : numVertices((ushort)0), numTriangles((ushort)0), numBones((ushort)0), numStrips((ushort)0), numWeightsPerVertex((ushort)0), hasVertexMap(false), hasVertexWeights(false), hasStrips(false), hasBoneIndices(false) {};

//Destructor
SkinPartition::~SkinPartition() {};
