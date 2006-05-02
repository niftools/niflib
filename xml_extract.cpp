/* --------------------------------------------------------------------------
 * xml_extract.cpp: C++ code for raw reading, writing, and printing
 *                  NetImmerse and Gamebryo files (.nif & .kf & .kfa)
 * --------------------------------------------------------------------------
 * ***** BEGIN LICENSE BLOCK *****
 *
 * Copyright (c) 2005, NIF File Format Library and Tools
 * All rights reserved.
 * 
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *
 *    * Neither the name of the NIF File Format Library and Tools
 *      project nor the names of its contributors may be used to endorse
 *      or promote products derived from this software without specific
 *      prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ***** END LICENCE BLOCK *****
 * --------------------------------------------------------------------------
 */

#include "xml_extract.h"

ostream & operator<<( ostream & out, Bones const & val ) {
  out << "           Num Bones:  -- calculated --" << endl;
  out << "               Bones:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, ByteArray const & val ) {
  out << "                Size:  -- calculated --" << endl;
  out << "         Unknown Int:  " << val.unknownInt << endl;
  out << "                Data:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, CondInt const & val ) {
  out << "             Is Used:  " << val.isUsed << endl;
  out << "         Unknown Int:  " << val.unknownInt << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, KeyArray<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, LinkGroup const & val ) {
  out << "         Num Indices:  -- calculated --" << endl;
  out << "             Indices:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, Footer const & val ) {
  out << "               Roots:  " << val.roots << endl;
  return out;
};

ostream & operator<<( ostream & out, MatchGroup const & val ) {
  out << "        Num Vertices:  -- calculated --" << endl;
  out << "      Vertex Indices:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, MipMap const & val ) {
  out << "               Width:  " << val.width << endl;
  out << "              Height:  " << val.height << endl;
  out << "              Offset:  " << val.offset << endl;
  return out;
};

ostream & operator<<( ostream & out, ModifierGroup const & val ) {
  out << "       Has Modifiers:  " << val.hasModifiers << endl;
  out << "           Modifiers:  " << val.modifiers << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, ns_keylin<T> const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "               Value:  " << val.value << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, ns_keyarray<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, ns_keytan<T> const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "               Value:  " << val.value << endl;
  out << "             Forward:  " << val.forward << endl;
  out << "            Backward:  " << val.backward << endl;
  return out;
};

ostream & operator<<( ostream & out, QuaternionXYZW const & val ) {
  out << "                   x:  " << val.x << endl;
  out << "                   y:  " << val.y << endl;
  out << "                   z:  " << val.z << endl;
  out << "                   w:  " << val.w << endl;
  return out;
};

ostream & operator<<( ostream & out, ShortString const & val ) {
  out << "              Length:  -- calculated --" << endl;
  out << "               Value:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, SkinShapeGroup const & val ) {
  out << "      Num Link Pairs:  -- calculated --" << endl;
  out << "          Link Pairs:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, AVObject const & val ) {
  out << "                Name:  " << val.name << endl;
  out << "              Object:  " << val.object << endl;
  return out;
};

ostream & operator<<( ostream & out, ControllerLink const & val ) {
  out << "                Name:  " << val.name << endl;
  out << "        Interpolator:  " << val.interpolator << endl;
  out << "      Unknown Link 1:  " << val.unknownLink1 << endl;
  out << "      Unknown Link 2:  " << val.unknownLink2 << endl;
  out << "     Unknown Short 0:  " << val.unknownShort0 << endl;
  out << "           Priority?:  " << val.priority_ << endl;
  out << "      String Palette:  " << val.stringPalette << endl;
  out << "           Node Name:  " << val.nodeName << endl;
  out << "    Node Name Offset:  " << val.nodeNameOffset << endl;
  out << "     Unknown Short 1:  " << val.unknownShort1 << endl;
  out << "       Property Type:  " << val.propertyType << endl;
  out << "Property Type Offset:  " << val.propertyTypeOffset << endl;
  out << "     Unknown Short 2:  " << val.unknownShort2 << endl;
  out << "     Controller Type:  " << val.controllerType << endl;
  out << "Controller Type Offset:  " << val.controllerTypeOffset << endl;
  out << "     Unknown Short 3:  " << val.unknownShort3 << endl;
  out << "          Variable 1:  " << val.variable1 << endl;
  out << "   Variable Offset 1:  " << val.variableOffset1 << endl;
  out << "     Unknown Short 4:  " << val.unknownShort4 << endl;
  out << "          Variable 2:  " << val.variable2 << endl;
  out << "   Variable Offset 2:  " << val.variableOffset2 << endl;
  out << "     Unknown Short 5:  " << val.unknownShort5 << endl;
  return out;
};

ostream & operator<<( ostream & out, Header const & val ) {
  out << "       Header String:  " << val.headerString << endl;
  out << "             Version:  " << val.version << endl;
  out << "         Endian Type:  " << val.endianType << endl;
  out << "        User Version:  " << val.userVersion << endl;
  out << "          Num Blocks:  -- calculated --" << endl;
  out << "       Unknown Int 1:  " << val.unknownInt1 << endl;
  out << "       Unknown Int 3:  " << val.unknownInt3 << endl;
  out << "            Creator?:  " << val.creator_ << endl;
  out << "        Export Type?:  " << val.exportType_ << endl;
  out << "      Export Script?:  " << val.exportScript_ << endl;
  out << "     Num Block Types:  -- calculated --" << endl;
  out << "         Block Types:  -- data not shown --" << endl;
  out << "    Block Type Index:  -- data not shown --" << endl;
  out << "       Unknown Int 2:  " << val.unknownInt2 << endl;
  return out;
};

ostream & operator<<( ostream & out, Shader const & val ) {
  out << "          Has Shader:  " << val.hasShader << endl;
  out << "         Shader Name:  " << val.shaderName << endl;
  out << "        Unknown Link:  " << val.unknownLink << endl;
  return out;
};

ostream & operator<<( ostream & out, StringPalette const & val ) {
  out << "             Palette:  " << val.palette << endl;
  out << "              Length:  " << val.length << endl;
  return out;
};

ostream & operator<<( ostream & out, TargetGroup const & val ) {
  out << "         Num Indices:  -- calculated --" << endl;
  out << "             Indices:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, TBC const & val ) {
  out << "                   t:  " << val.t << endl;
  out << "                   b:  " << val.b << endl;
  out << "                   c:  " << val.c << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, ns_keytbc<T> const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "               Value:  " << val.value << endl;
  out << "                 TBC:  " << val.tbc << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, ns_keyvecarray<T> const & val ) {
  out << "            Num Keys:  " << val.numKeys << endl;
  out << "            Key Type:  " << val.keyType << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, ns_keyrotsub const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "            Sub Keys:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, ns_keyrotarray<T> const & val ) {
  out << "            Num Keys:  " << val.numKeys << endl;
  out << "            Key Type:  " << val.keyType << endl;
  out << "                Keys:  -- data not shown --" << endl;
  out << "            Keys Sub:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, ns_keyvecarraytyp<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "            Key Type:  " << val.keyType << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, BumpMap const & val ) {
  out << "             Is Used:  " << val.isUsed << endl;
  out << "             Texture:  " << val.texture << endl;
  out << " Bump Map Luma Scale:  " << val.bumpMapLumaScale << endl;
  out << "Bump Map Luma Offset:  " << val.bumpMapLumaOffset << endl;
  out << "              Matrix:  " << val.matrix << endl;
  return out;
};

ostream & operator<<( ostream & out, Texture const & val ) {
  out << "             Is Used:  " << val.isUsed << endl;
  out << "        Texture Data:  " << val.textureData << endl;
  return out;
};

ostream & operator<<( ostream & out, Texture2 const & val ) {
  out << "             Is Used:  " << val.isUsed << endl;
  out << "        Texture Data:  " << val.textureData << endl;
  out << "         Unknown Int:  " << val.unknownInt << endl;
  return out;
};

ostream & operator<<( ostream & out, ExtraTextureGroup const & val ) {
  out << "        Num Textures:  -- calculated --" << endl;
  out << "            Textures:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, SkinPartition const & val ) {
  out << "        Num Vertices:  -- calculated --" << endl;
  out << "       Num Triangles:  -- calculated --" << endl;
  out << "           Num Bones:  -- calculated --" << endl;
  out << "          Num Strips:  " << val.numStrips << endl;
  out << "Num Weights Per Vertex:  -- calculated --" << endl;
  out << "               Bones:  -- data not shown --" << endl;
  out << "      Has Vertex Map:  " << val.hasVertexMap << endl;
  out << "          Vertex Map:  -- data not shown --" << endl;
  out << "  Has Vertex Weights:  " << val.hasVertexWeights << endl;
  out << "      Vertex Weights:  -- data not shown --" << endl;
  out << "       Strip Lengths:  -- calculated --" << endl;
  out << "          Has Strips:  " << val.hasStrips << endl;
  out << "              Strips:  -- data not shown --" << endl;
  out << "           Triangles:  -- data not shown --" << endl;
  out << "    Has Bone Indices:  " << val.hasBoneIndices << endl;
  out << "        Bone Indices:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, unk292bytes const & val ) {
  out << "   Unknown 292 Bytes:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, FurniturePosition const & val ) {
  out << "      Unknown Vector:  " << val.unknownVector << endl;
  out << "       Unknown Short:  " << val.unknownShort << endl;
  out << "     Position Ref 1?:  " << val.positionRef1_ << endl;
  out << "     Position Ref 2?:  " << val.positionRef2_ << endl;
  return out;
};

ostream & operator<<( ostream & out, hkTriangle const & val ) {
  out << "            Triangle:  " << val.triangle << endl;
  out << "       Unknown Short:  " << val.unknownShort << endl;
  out << "              Normal:  " << val.normal << endl;
  return out;
};

ostream & operator<<( ostream & out, LODInfo const & val ) {
  out << "            LOD Type:  " << val.lodType << endl;
  out << "          LOD Center:  " << val.lodCenter << endl;
  out << "      Num LOD Levels:  -- calculated --" << endl;
  out << "          LOD Levels:  -- data not shown --" << endl;
  out << "       Unknown Short:  " << val.unknownShort << endl;
  out << "          Range Data:  " << val.rangeData << endl;
  return out;
};

ostream & operator<<( ostream & out, Particle const & val ) {
  out << "            Velocity:  " << val.velocity << endl;
  out << "      Unknown Vector:  " << val.unknownVector << endl;
  out << "            Lifetime:  " << val.lifetime << endl;
  out << "            Lifespan:  " << val.lifespan << endl;
  out << "           Timestamp:  " << val.timestamp << endl;
  out << "       Unknown Short:  " << val.unknownShort << endl;
  out << "           Vertex ID:  " << val.vertexId << endl;
  return out;
};

ostream & operator<<( ostream & out, ParticleGroup const & val ) {
  out << "       Num Particles:  -- calculated --" << endl;
  out << "           Num Valid:  " << val.numValid << endl;
  out << "           Particles:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, SkinData const & val ) {
  out << "            Rotation:  " << val.rotation << endl;
  out << "         Translation:  " << val.translation << endl;
  out << "               Scale:  " << val.scale << endl;
  out << "    Unknown 4 Floats:  -- data not shown --" << endl;
  out << "        Num Vertices:  -- calculated --" << endl;
  out << "      Vertex Weights:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, TypedVectorKeyArray<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "            Key Type:  " << val.keyType << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, Morph const & val ) {
  out << "          Frame Name:  " << val.frameName << endl;
  out << "              Frames:  " << val.frames << endl;
  out << "         Unknown Int:  " << val.unknownInt << endl;
  out << "             Vectors:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, VectorKeyArray<T> const & val ) {
  out << "            Num Keys:  " << val.numKeys << endl;
  out << "            Key Type:  " << val.keyType << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, RotationKeyArray<T> const & val ) {
  out << "            Num Keys:  " << val.numKeys << endl;
  out << "            Key Type:  " << val.keyType << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

