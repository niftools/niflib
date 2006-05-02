/* --------------------------------------------------------------------------
 * xml_extract.h: C++ header file for raw reading, writing, and printing
 *                NetImmerse and Gamebryo files (.nif & .kf & .kfa)
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

#ifndef _XML_EXTRACT_H_
#define _XML_EXTRACT_H_

#include "niflib.h"
#include "NIF_IO.h"
#include "NIF_Blocks.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 
// This is a list of bone influences.  It points to blocks higher in the hierarchy so ints are used to represent the indices.
//
struct Bones {
  // Block indicies of the bones.
  vector<CrossRef > bones;
  Bones() {};
};

void NifStream( Bones & val, istream & in, uint version ) {
  uint numBones;
  NifStream( numBones, in, version );
  val.bones.resize(numBones);
  NifStream( val.bones, in, version );
};

void NifStream( Bones const & val, ostream & out, uint version ) {
  uint numBones;
  numBones = uint(val.bones.size());
  NifStream( numBones, out, version );
  NifStream( val.bones, out, version );
};

ostream & operator<<( ostream & out, Bones const & val );

// 
// An array of bytes.
//
struct ByteArray {
  // Unknown.
  uint unknownInt;
  // The bytes which make up the array
  vector<byte > data;
  ByteArray() {};
};

void NifStream( ByteArray & val, istream & in, uint version ) {
  uint size;
  NifStream( size, in, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.unknownInt, in, version );
  };
  val.data.resize(size);
  NifStream( val.data, in, version );
};

void NifStream( ByteArray const & val, ostream & out, uint version ) {
  uint size;
  size = uint(val.data.size());
  NifStream( size, out, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.unknownInt, out, version );
  };
  NifStream( val.data, out, version );
};

ostream & operator<<( ostream & out, ByteArray const & val );

// 
// An integer value that may or may not be used.
//
struct CondInt {
  // Non-Zero if the following Integer appears.  Otherwise, the integer does not appear.
  bool isUsed;
  // An unknown integer.
  uint unknownInt;
  CondInt() {};
};

void NifStream( CondInt & val, istream & in, uint version ) {
  NifStream( val.isUsed, in, version );
  if ( val.isUsed != 0 ) {
    NifStream( val.unknownInt, in, version );
  };
};

void NifStream( CondInt const & val, ostream & out, uint version ) {
  NifStream( val.isUsed, out, version );
  if ( val.isUsed != 0 ) {
    NifStream( val.unknownInt, out, version );
  };
};

ostream & operator<<( ostream & out, CondInt const & val );

// 
// An array of (untyped) keys.
//
template <class T >
struct KeyArray {
  // The keys.
  vector<Key<T > > keys;
  KeyArray() {};
};

template <class T >
void NifStream( KeyArray<T> & val, istream & in, uint version ) {
  uint numKeys;
  NifStream( numKeys, in, version );
  val.keys.resize(numKeys);
  NifStream( val.keys, in, version );
};

template <class T >
void NifStream( KeyArray<T> const & val, ostream & out, uint version ) {
  uint numKeys;
  numKeys = uint(val.keys.size());
  NifStream( numKeys, out, version );
  NifStream( val.keys, out, version );
};

template <class T >
ostream & operator<<( ostream & out, KeyArray<T> const & val );

// 
// List of block indices.
//
struct LinkGroup {
  // The list of block indices.
  vector<Link > indices;
  LinkGroup() {};
};

void NifStream( LinkGroup & val, istream & in, uint version ) {
  uint numIndices;
  NifStream( numIndices, in, version );
  val.indices.resize(numIndices);
  NifStream( val.indices, in, version );
};

void NifStream( LinkGroup const & val, ostream & out, uint version ) {
  uint numIndices;
  numIndices = uint(val.indices.size());
  NifStream( numIndices, out, version );
  NifStream( val.indices, out, version );
};

ostream & operator<<( ostream & out, LinkGroup const & val );

// 
// The NIF file footer.
//
struct Footer {
  // List of root blocks. If there is a camera, for 1st person view, then this block is referred to as well in this list, even if it is not a root block (usually we want the camera to be attached to the Bip Head node).
  LinkGroup roots;
  Footer() {};
};

void NifStream( Footer & val, istream & in, uint version ) {
  NifStream( val.roots, in, version );
};

void NifStream( Footer const & val, ostream & out, uint version ) {
  NifStream( val.roots, out, version );
};

ostream & operator<<( ostream & out, Footer const & val );

// 
// Group of vertex indices of vertices that match.
//
struct MatchGroup {
  // The vertex indices.
  vector<ushort > vertexIndices;
  MatchGroup() {};
};

void NifStream( MatchGroup & val, istream & in, uint version ) {
  ushort numVertices;
  NifStream( numVertices, in, version );
  val.vertexIndices.resize(numVertices);
  NifStream( val.vertexIndices, in, version );
};

void NifStream( MatchGroup const & val, ostream & out, uint version ) {
  ushort numVertices;
  numVertices = ushort(val.vertexIndices.size());
  NifStream( numVertices, out, version );
  NifStream( val.vertexIndices, out, version );
};

ostream & operator<<( ostream & out, MatchGroup const & val );

// 
// Description of a MipMap within a NiPixelData block.
//
struct MipMap {
  // Width of the mipmap image.
  uint width;
  // Height of the mipmap image.
  uint height;
  // Offset into the pixel data array where this mipmap starts.
  uint offset;
  MipMap() {};
};

void NifStream( MipMap & val, istream & in, uint version ) {
  NifStream( val.width, in, version );
  NifStream( val.height, in, version );
  NifStream( val.offset, in, version );
};

void NifStream( MipMap const & val, ostream & out, uint version ) {
  NifStream( val.width, out, version );
  NifStream( val.height, out, version );
  NifStream( val.offset, out, version );
};

ostream & operator<<( ostream & out, MipMap const & val );

// 
// A link group conditioned on a boolean value.
//
struct ModifierGroup {
  // Determines whether or not the link group is present.
  bool hasModifiers;
  // The list of particle modifiers.
  LinkGroup modifiers;
  ModifierGroup() {};
};

void NifStream( ModifierGroup & val, istream & in, uint version ) {
  NifStream( val.hasModifiers, in, version );
  NifStream( val.modifiers, in, version );
};

void NifStream( ModifierGroup const & val, ostream & out, uint version ) {
  NifStream( val.hasModifiers, out, version );
  NifStream( val.modifiers, out, version );
};

ostream & operator<<( ostream & out, ModifierGroup const & val );

// 
// Linear key type (!!! for NifSkope optimizer only, use key, keyrot, or keyvec for regular use).
//
template <class T >
struct ns_keylin {
  // Key time.
  float time;
  // The key value.
  T value;
  ns_keylin() {};
};

template <class T >
void NifStream( ns_keylin<T> & val, istream & in, uint version ) {
  NifStream( val.time, in, version );
  NifStream( val.value, in, version );
};

template <class T >
void NifStream( ns_keylin<T> const & val, ostream & out, uint version ) {
  NifStream( val.time, out, version );
  NifStream( val.value, out, version );
};

template <class T >
ostream & operator<<( ostream & out, ns_keylin<T> const & val );

// 
// Array of keys, not interpolated (!!! for NifSkope only, use keyarray for regular use).
//
template <class T >
struct ns_keyarray {
  // The keys.
  vector<ns_keylin<T > > keys;
  ns_keyarray() {};
};

template <class T >
void NifStream( ns_keyarray<T> & val, istream & in, uint version ) {
  uint numKeys;
  NifStream( numKeys, in, version );
  val.keys.resize(numKeys);
  NifStream( val.keys, in, version );
};

template <class T >
void NifStream( ns_keyarray<T> const & val, ostream & out, uint version ) {
  uint numKeys;
  numKeys = uint(val.keys.size());
  NifStream( numKeys, out, version );
  NifStream( val.keys, out, version );
};

template <class T >
ostream & operator<<( ostream & out, ns_keyarray<T> const & val );

// 
// Key with tangents (!!! for NifSkope only, use keyvec instead for regular purposes).
//
template <class T >
struct ns_keytan {
  // The key time.
  float time;
  // The key value.
  T value;
  // Forward tangent.
  T forward;
  // Backward tangent.
  T backward;
  ns_keytan() {};
};

template <class T >
void NifStream( ns_keytan<T> & val, istream & in, uint version ) {
  NifStream( val.time, in, version );
  NifStream( val.value, in, version );
  NifStream( val.forward, in, version );
  NifStream( val.backward, in, version );
};

template <class T >
void NifStream( ns_keytan<T> const & val, ostream & out, uint version ) {
  NifStream( val.time, out, version );
  NifStream( val.value, out, version );
  NifStream( val.forward, out, version );
  NifStream( val.backward, out, version );
};

template <class T >
ostream & operator<<( ostream & out, ns_keytan<T> const & val );

// 
// A quaternion as it appears in the havok blocks.
//
struct QuaternionXYZW {
  // The x-coordinate.
  float x;
  // The y-coordinate.
  float y;
  // The z-coordinate.
  float z;
  // The w-coordinate.
  float w;
  QuaternionXYZW() {};
};

void NifStream( QuaternionXYZW & val, istream & in, uint version ) {
  NifStream( val.x, in, version );
  NifStream( val.y, in, version );
  NifStream( val.z, in, version );
  NifStream( val.w, in, version );
};

void NifStream( QuaternionXYZW const & val, ostream & out, uint version ) {
  NifStream( val.x, out, version );
  NifStream( val.y, out, version );
  NifStream( val.z, out, version );
  NifStream( val.w, out, version );
};

ostream & operator<<( ostream & out, QuaternionXYZW const & val );

// 
// Another string format, for short strings.  Specific to Bethesda-specific header tags.
//
struct ShortString {
  // The string itself, null terminated (the null terminator is taken into account in the length byte).
  vector<byte > value;
  ShortString() {};
};

void NifStream( ShortString & val, istream & in, uint version ) {
  byte length;
  NifStream( length, in, version );
  val.value.resize(length);
  NifStream( val.value, in, version );
};

void NifStream( ShortString const & val, ostream & out, uint version ) {
  byte length;
  length = byte(val.value.size());
  NifStream( length, out, version );
  NifStream( val.value, out, version );
};

ostream & operator<<( ostream & out, ShortString const & val );

// 
// Unknown.
//
struct SkinShapeGroup {
  // First link is a NiTriShape block.
  // Second link is a NiSkinInstance block.
  vector<vector<Link > > linkPairs;
  SkinShapeGroup() {};
};

void NifStream( SkinShapeGroup & val, istream & in, uint version ) {
  uint numLinkPairs;
  NifStream( numLinkPairs, in, version );
  val.linkPairs.resize(numLinkPairs);
  for (uint i = 0; i < numLinkPairs; i++) {
    val.linkPairs[i].resize(2);
  };
  NifStream( val.linkPairs, in, version );
};

void NifStream( SkinShapeGroup const & val, ostream & out, uint version ) {
  uint numLinkPairs;
  numLinkPairs = uint(val.linkPairs.size());
  NifStream( numLinkPairs, out, version );
  NifStream( val.linkPairs, out, version );
};

ostream & operator<<( ostream & out, SkinShapeGroup const & val );

// 
// Used in NiDefaultAVObjectPalette.
//
struct AVObject {
  // Object name.
  string name;
  // Object reference.
  CrossRef object;
  AVObject() {};
};

void NifStream( AVObject & val, istream & in, uint version ) {
  NifStream( val.name, in, version );
  NifStream( val.object, in, version );
};

void NifStream( AVObject const & val, ostream & out, uint version ) {
  NifStream( val.name, out, version );
  NifStream( val.object, out, version );
};

ostream & operator<<( ostream & out, AVObject const & val );

// 
// In a .kf file, this links to a controllable block, via its name (or for version 10.2.0.0 and up, a link and offset to a NiStringPalette that contains the name), and a sequence of interpolators that apply to this controllable block, via links.
//
struct ControllerLink {
  // Name of a controllable block in another NIF file.
  string name;
  // Link to an interpolator.
  Link interpolator;
  // Unknown link. Usually -1.
  Link unknownLink1;
  // Unknown.
  Link unknownLink2;
  // Unknown.
  ushort unknownShort0;
  // Idle animations tend to have low values for this, and blocks that have high values tend to correspond with the important parts of the animation. WARNING: BREAKS CIV4 NIF FILES! Only observed in Oblivion NIF files so far.
  byte priority_;
  // Refers to the NiStringPalette which contains the name of the controlled block.
  Link stringPalette;
  // The name of the animated node.
  string nodeName;
  // Offset in the string palette where the name of the controlled node (NiNode, NiTriShape, ...) starts.
  ushort nodeNameOffset;
  // Unknown, always 0.
  ushort unknownShort1;
  // Name of the property (NiMaterialProperty, ...), if this controller controls a property.
  string propertyType;
  // Offset in the string palette where the property (NiMaterialProperty, ...) starts, if this controller controls a property. Otherwise, -1.
  ushort propertyTypeOffset;
  // Unknown, usually 0, but sometimes also 0xFFFF.
  ushort unknownShort2;
  // Probably the block type name of the controller in the NIF file that is child of the controlled block.
  string controllerType;
  // Apparently the offset in the string palette of some type of controller related to Interpolator (for example, a 'NiTransformInterpolator' will have here a 'NiTransformController', etc.). Sometimes the type of controller that links to the interpolator. Probably it refers to the controller in the NIF file that is child of the controlled block, via its type name.
  ushort controllerTypeOffset;
  // Unknown, always 0.
  ushort unknownShort3;
  // Some variable string (such as 'SELF_ILLUM', '0-0-TT_TRANSLATE_U', 'tongue_out', etc.).
  string variable1;
  // Offset in the string palette where some variable string starts (such as 'SELF_ILLUM', '0-0-TT_TRANSLATE_U', 'tongue_out', etc.). Usually, -1.
  ushort variableOffset1;
  // Unknown, usually 0, but sometimes 0xFFFF.
  ushort unknownShort4;
  // Another variable string, apparently used for particle system controllers.
  string variable2;
  // Offset in the string palette where some variable string starts (so far only 'EmitterActive' and 'BirthRate' have been observed in official files, used for particle system controllers). Usually, -1.
  ushort variableOffset2;
  // Unknown, usually 0, but sometimes 0xFFFF.
  ushort unknownShort5;
  ControllerLink() {};
};

void NifStream( ControllerLink & val, istream & in, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.name, in, version );
  };
  NifStream( val.interpolator, in, version );
  if ( version >= 0x0A01006A ) {
    NifStream( val.unknownLink1, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknownLink2, in, version );
    NifStream( val.unknownShort0, in, version );
  };
  if ( version >= 0x0A01006A ) {
    NifStream( val.priority_, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.stringPalette, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.nodeName, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.nodeNameOffset, in, version );
    NifStream( val.unknownShort1, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.propertyType, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.propertyTypeOffset, in, version );
    NifStream( val.unknownShort2, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.controllerType, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.controllerTypeOffset, in, version );
    NifStream( val.unknownShort3, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.variable1, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.variableOffset1, in, version );
    NifStream( val.unknownShort4, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.variable2, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.variableOffset2, in, version );
    NifStream( val.unknownShort5, in, version );
  };
};

void NifStream( ControllerLink const & val, ostream & out, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.name, out, version );
  };
  NifStream( val.interpolator, out, version );
  if ( version >= 0x0A01006A ) {
    NifStream( val.unknownLink1, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknownLink2, out, version );
    NifStream( val.unknownShort0, out, version );
  };
  if ( version >= 0x0A01006A ) {
    NifStream( val.priority_, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.stringPalette, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.nodeName, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.nodeNameOffset, out, version );
    NifStream( val.unknownShort1, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.propertyType, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.propertyTypeOffset, out, version );
    NifStream( val.unknownShort2, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.controllerType, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.controllerTypeOffset, out, version );
    NifStream( val.unknownShort3, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.variable1, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.variableOffset1, out, version );
    NifStream( val.unknownShort4, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.variable2, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.variableOffset2, out, version );
    NifStream( val.unknownShort5, out, version );
  };
};

ostream & operator<<( ostream & out, ControllerLink const & val );

// 
// The NIF file header.
//
struct Header {
  // 'NetImmerse File Format x.x.x.x' (versions <= 10.0.1.2) or 'Gamebryo File Format x.x.x.x' (versions >= 10.1.0.0), with x.x.x.x the version written out. Ends with a newline character (0x0A).
  HeaderString headerString;
  // The NIF version, in hexadecimal notation: 0x04000002, 0x0401000C, 0x04020002, 0x04020100, 0x04020200, 0x0A000100, 0x0A010000, 0x0A020000, 0x14000004, ...
  uint version;
  // Determines the endian-ness of the data.
  // 
  // 1 = little endian (default)
  // 0 = big endian
  byte endianType;
  // An extra version number, for companies that decide to modify the file format.
  uint userVersion;
  // Unknown.
  uint unknownInt1;
  // Unknown.
  uint unknownInt3;
  // Could be the name of the creator of the NIF file?
  ShortString creator_;
  // Unknown. Can be something like 'TriStrip Process Script'.
  ShortString exportType_;
  // Unknown. Possibly the selected option of the export script. Can be something like 'Default Export Script'.
  ShortString exportScript_;
  // List of all block types used in this NIF file.
  vector<string > blockTypes;
  // Maps file blocks on their corresponding type: first file block is of type block_types[block_type_index[0]], the second of block_types[block_type_index[1]], etc.
  vector<ushort > blockTypeIndex;
  // Unknown.
  uint unknownInt2;
  Header() : version(0x04000002), endianType(1) {};
};

void NifStream( Header & val, istream & in, uint version ) {
  uint numBlocks;
  ushort numBlockTypes;
  NifStream( val.headerString, in, version );
  NifStream( val.version, in, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.endianType, in, version );
  };
  if ( version >= 0x0A010000 ) {
    NifStream( val.userVersion, in, version );
  };
  NifStream( numBlocks, in, version );
  if ( ( version >= 0x0A000102 ) && ( version <= 0x0A000102 ) ) {
    NifStream( val.unknownInt1, in, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.userVersion != 0 ) {
      NifStream( val.unknownInt3, in, version );
    };
  };
  if ( version >= 0x0A000102 ) {
    if ( val.userVersion != 0 ) {
      NifStream( val.creator_, in, version );
      NifStream( val.exportType_, in, version );
      NifStream( val.exportScript_, in, version );
    };
  };
  if ( version >= 0x0A000100 ) {
    NifStream( numBlockTypes, in, version );
    val.blockTypes.resize(numBlockTypes);
    NifStream( val.blockTypes, in, version );
    val.blockTypeIndex.resize(numBlocks);
    NifStream( val.blockTypeIndex, in, version );
    NifStream( val.unknownInt2, in, version );
  };
};

void NifStream( Header const & val, ostream & out, uint version ) {
  uint numBlocks;
  ushort numBlockTypes;
  numBlocks = uint(val.blockTypeIndex.size());
  numBlockTypes = ushort(val.blockTypes.size());
  NifStream( val.headerString, out, version );
  NifStream( val.version, out, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.endianType, out, version );
  };
  if ( version >= 0x0A010000 ) {
    NifStream( val.userVersion, out, version );
  };
  NifStream( numBlocks, out, version );
  if ( ( version >= 0x0A000102 ) && ( version <= 0x0A000102 ) ) {
    NifStream( val.unknownInt1, out, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.userVersion != 0 ) {
      NifStream( val.unknownInt3, out, version );
    };
  };
  if ( version >= 0x0A000102 ) {
    if ( val.userVersion != 0 ) {
      NifStream( val.creator_, out, version );
      NifStream( val.exportType_, out, version );
      NifStream( val.exportScript_, out, version );
    };
  };
  if ( version >= 0x0A000100 ) {
    NifStream( numBlockTypes, out, version );
    NifStream( val.blockTypes, out, version );
    NifStream( val.blockTypeIndex, out, version );
    NifStream( val.unknownInt2, out, version );
  };
};

ostream & operator<<( ostream & out, Header const & val );

// 
// Describes a shader.
//
struct Shader {
  // Do we have a shader?
  bool hasShader;
  // The shader name.
  string shaderName;
  // Unknown link, usually -1.
  Link unknownLink;
  Shader() {};
};

void NifStream( Shader & val, istream & in, uint version ) {
  NifStream( val.hasShader, in, version );
  if ( val.hasShader != 0 ) {
    NifStream( val.shaderName, in, version );
    NifStream( val.unknownLink, in, version );
  };
};

void NifStream( Shader const & val, ostream & out, uint version ) {
  NifStream( val.hasShader, out, version );
  if ( val.hasShader != 0 ) {
    NifStream( val.shaderName, out, version );
    NifStream( val.unknownLink, out, version );
  };
};

ostream & operator<<( ostream & out, Shader const & val );

// 
// A list of \\0 terminated strings.
//
struct StringPalette {
  // A bunch of 0x00 seperated strings.
  string palette;
  // Length of the palette string is repeated here.
  uint length;
  StringPalette() {};
};

void NifStream( StringPalette & val, istream & in, uint version ) {
  NifStream( val.palette, in, version );
  NifStream( val.length, in, version );
};

void NifStream( StringPalette const & val, ostream & out, uint version ) {
  NifStream( val.palette, out, version );
  NifStream( val.length, out, version );
};

ostream & operator<<( ostream & out, StringPalette const & val );

// 
// A list of node targets.
//
struct TargetGroup {
  // The list of block indices.
  vector<CrossRef > indices;
  TargetGroup() {};
};

void NifStream( TargetGroup & val, istream & in, uint version ) {
  ushort numIndices;
  NifStream( numIndices, in, version );
  val.indices.resize(numIndices);
  NifStream( val.indices, in, version );
};

void NifStream( TargetGroup const & val, ostream & out, uint version ) {
  ushort numIndices;
  numIndices = ushort(val.indices.size());
  NifStream( numIndices, out, version );
  NifStream( val.indices, out, version );
};

ostream & operator<<( ostream & out, TargetGroup const & val );

// 
// Tension, bias, continuity.
//
struct TBC {
  // Tension.
  float t;
  // Bias.
  float b;
  // Continuity.
  float c;
  TBC() {};
};

void NifStream( TBC & val, istream & in, uint version ) {
  NifStream( val.t, in, version );
  NifStream( val.b, in, version );
  NifStream( val.c, in, version );
};

void NifStream( TBC const & val, ostream & out, uint version ) {
  NifStream( val.t, out, version );
  NifStream( val.b, out, version );
  NifStream( val.c, out, version );
};

ostream & operator<<( ostream & out, TBC const & val );

// 
// A TBC key (!!! for NifSkope only, use keyvec for regular purposes).
//
template <class T >
struct ns_keytbc {
  // The key time.
  float time;
  // The key value.
  T value;
  // Tension, bias, continuity.
  TBC tbc;
  ns_keytbc() {};
};

template <class T >
void NifStream( ns_keytbc<T> & val, istream & in, uint version ) {
  NifStream( val.time, in, version );
  NifStream( val.value, in, version );
  NifStream( val.tbc, in, version );
};

template <class T >
void NifStream( ns_keytbc<T> const & val, ostream & out, uint version ) {
  NifStream( val.time, out, version );
  NifStream( val.value, out, version );
  NifStream( val.tbc, out, version );
};

template <class T >
ostream & operator<<( ostream & out, ns_keytbc<T> const & val );

// 
// Array of interpolable keys (!!! for NifSkope only, use keyvecarray for regular use).
//     
//     
//     
//     Interpolated keys, using tangents.
//     Keys, interpolated with tension, bias, continuity.
//     Another type of linear key?
//
template <class T >
struct ns_keyvecarray {
  // Number of keys.
  uint numKeys;
  // The key type (1, 2, or 3).
  uint keyType;
  // Linearly interpolated keys.
  vector<ns_keylin<T > > keys;
  ns_keyvecarray() {};
};

template <class T >
void NifStream( ns_keyvecarray<T> & val, istream & in, uint version ) {
  NifStream( val.numKeys, in, version );
  if ( val.numKeys != 0 ) {
    NifStream( val.keyType, in, version );
  };
  if ( val.keyType == 1 ) {
    val.keys.resize(val.numKeys);
    NifStream( val.keys, in, version );
  };
  if ( val.keyType == 2 ) {
    val.keys.resize(val.numKeys);
    NifStream( val.keys, in, version );
  };
  if ( val.keyType == 3 ) {
    val.keys.resize(val.numKeys);
    NifStream( val.keys, in, version );
  };
  if ( val.keyType == 5 ) {
    val.keys.resize(val.numKeys);
    NifStream( val.keys, in, version );
  };
};

template <class T >
void NifStream( ns_keyvecarray<T> const & val, ostream & out, uint version ) {
  NifStream( val.numKeys, out, version );
  if ( val.numKeys != 0 ) {
    NifStream( val.keyType, out, version );
  };
  if ( val.keyType == 1 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.keyType == 2 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.keyType == 3 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.keyType == 5 ) {
    NifStream( val.keys, out, version );
  };
};

template <class T >
ostream & operator<<( ostream & out, ns_keyvecarray<T> const & val );

// 
// Rotation subkey (!!! Nifskope only).
//
struct ns_keyrotsub {
  // Time.
  float time;
  // The sub keys, one for every axis.
  vector<ns_keyvecarray<float > > subKeys;
  ns_keyrotsub() {};
};

void NifStream( ns_keyrotsub & val, istream & in, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.time, in, version );
  };
  val.subKeys.resize(3);
  NifStream( val.subKeys, in, version );
};

void NifStream( ns_keyrotsub const & val, ostream & out, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.time, out, version );
  };
  NifStream( val.subKeys, out, version );
};

ostream & operator<<( ostream & out, ns_keyrotsub const & val );

// 
// Array of rotation keys (!!! for NifSkope only, use keyrotarray for regular use).
//     
//     
//     
//     Linear keys (yes, rotations don't have type 2 tangent keys!).
//     TBC keys.
//
template <class T >
struct ns_keyrotarray {
  // Number of rotation keys.
  uint numKeys;
  // The key type (1, 2, 3, or 4).
  uint keyType;
  // Linear keys.
  vector<ns_keylin<T > > keys;
  // Special rotation keys (3 float arrays, one for each axis).
  vector<ns_keyrotsub > keysSub;
  ns_keyrotarray() {};
};

template <class T >
void NifStream( ns_keyrotarray<T> & val, istream & in, uint version ) {
  NifStream( val.numKeys, in, version );
  if ( val.numKeys != 0 ) {
    NifStream( val.keyType, in, version );
  };
  if ( val.keyType == 1 ) {
    val.keys.resize(val.numKeys);
    NifStream( val.keys, in, version );
  };
  if ( val.keyType == 2 ) {
    val.keys.resize(val.numKeys);
    NifStream( val.keys, in, version );
  };
  if ( val.keyType == 3 ) {
    val.keys.resize(val.numKeys);
    NifStream( val.keys, in, version );
  };
  if ( val.keyType == 4 ) {
    val.keysSub.resize(val.numKeys);
    NifStream( val.keysSub, in, version );
  };
};

template <class T >
void NifStream( ns_keyrotarray<T> const & val, ostream & out, uint version ) {
  NifStream( val.numKeys, out, version );
  if ( val.numKeys != 0 ) {
    NifStream( val.keyType, out, version );
  };
  if ( val.keyType == 1 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.keyType == 2 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.keyType == 3 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.keyType == 4 ) {
    NifStream( val.keysSub, out, version );
  };
};

template <class T >
ostream & operator<<( ostream & out, ns_keyrotarray<T> const & val );

// 
// Array of interpolable keys (!!! for NifSkope only, use keyvecarraytyp for regular use)
//     
//     
//     
//     Interpolated keys, using tangents.
//     Keys, interpolated with tension, bias, continuity.
//
template <class T >
struct ns_keyvecarraytyp {
  // The key type (1, 2, 3)
  uint keyType;
  // Linearly interpolated keys.
  vector<ns_keylin<T > > keys;
  ns_keyvecarraytyp() {};
};

template <class T >
void NifStream( ns_keyvecarraytyp<T> & val, istream & in, uint version ) {
  uint numKeys;
  NifStream( numKeys, in, version );
  NifStream( val.keyType, in, version );
  if ( val.keyType == 1 ) {
    val.keys.resize(numKeys);
    NifStream( val.keys, in, version );
  };
  if ( val.keyType == 2 ) {
    val.keys.resize(numKeys);
    NifStream( val.keys, in, version );
  };
  if ( val.keyType == 3 ) {
    val.keys.resize(numKeys);
    NifStream( val.keys, in, version );
  };
};

template <class T >
void NifStream( ns_keyvecarraytyp<T> const & val, ostream & out, uint version ) {
  uint numKeys;
  numKeys = uint(val.keys.size());
  NifStream( numKeys, out, version );
  NifStream( val.keyType, out, version );
  if ( val.keyType == 1 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.keyType == 2 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.keyType == 3 ) {
    NifStream( val.keys, out, version );
  };
};

template <class T >
ostream & operator<<( ostream & out, ns_keyvecarraytyp<T> const & val );

// 
// A texture that happens to be a bump map.  Contains extra data.
//
struct BumpMap {
  // Determines whether this bumpmap contains any information. If Non-Zero the following data is present, otherwise it is not.
  bool isUsed;
  // The bump map texture description.
  TexDesc texture;
  // ?
  float bumpMapLumaScale;
  // ?
  float bumpMapLumaOffset;
  // ?
  Matrix22 matrix;
  BumpMap() {};
};

void NifStream( BumpMap & val, istream & in, uint version ) {
  NifStream( val.isUsed, in, version );
  if ( val.isUsed != 0 ) {
    NifStream( val.texture, in, version );
    NifStream( val.bumpMapLumaScale, in, version );
    NifStream( val.bumpMapLumaOffset, in, version );
    NifStream( val.matrix, in, version );
  };
};

void NifStream( BumpMap const & val, ostream & out, uint version ) {
  NifStream( val.isUsed, out, version );
  if ( val.isUsed != 0 ) {
    NifStream( val.texture, out, version );
    NifStream( val.bumpMapLumaScale, out, version );
    NifStream( val.bumpMapLumaOffset, out, version );
    NifStream( val.matrix, out, version );
  };
};

ostream & operator<<( ostream & out, BumpMap const & val );

// 
// A texture that is not a bumpmap.
//
struct Texture {
  // Determines whether this texture contains any information. If Non-Zero the following data is present, otherwise it is not.
  bool isUsed;
  // The texture description.
  TexDesc textureData;
  Texture() {};
};

void NifStream( Texture & val, istream & in, uint version ) {
  NifStream( val.isUsed, in, version );
  if ( val.isUsed != 0 ) {
    NifStream( val.textureData, in, version );
  };
};

void NifStream( Texture const & val, ostream & out, uint version ) {
  NifStream( val.isUsed, out, version );
  if ( val.isUsed != 0 ) {
    NifStream( val.textureData, out, version );
  };
};

ostream & operator<<( ostream & out, Texture const & val );

// 
// An extended version of texture.
//
struct Texture2 {
  // Is it used?
  bool isUsed;
  // The texture data.
  TexDesc textureData;
  // Unknown.
  uint unknownInt;
  Texture2() {};
};

void NifStream( Texture2 & val, istream & in, uint version ) {
  NifStream( val.isUsed, in, version );
  if ( val.isUsed != 0 ) {
    NifStream( val.textureData, in, version );
    NifStream( val.unknownInt, in, version );
  };
};

void NifStream( Texture2 const & val, ostream & out, uint version ) {
  NifStream( val.isUsed, out, version );
  if ( val.isUsed != 0 ) {
    NifStream( val.textureData, out, version );
    NifStream( val.unknownInt, out, version );
  };
};

ostream & operator<<( ostream & out, Texture2 const & val );

// 
// Group of extra textures.
//
struct ExtraTextureGroup {
  // The textures.
  vector<Texture2 > textures;
  ExtraTextureGroup() {};
};

void NifStream( ExtraTextureGroup & val, istream & in, uint version ) {
  uint numTextures;
  NifStream( numTextures, in, version );
  val.textures.resize(numTextures);
  NifStream( val.textures, in, version );
};

void NifStream( ExtraTextureGroup const & val, ostream & out, uint version ) {
  uint numTextures;
  numTextures = uint(val.textures.size());
  NifStream( numTextures, out, version );
  NifStream( val.textures, out, version );
};

ostream & operator<<( ostream & out, ExtraTextureGroup const & val );

// 
// Skinning data for a submesh, optimized for hardware skinning. Part of NiSkinPartition.
//     
//     
//     
//     
//     
//     
//     
//     
//     Maps the weight/influence lists in this submesh to the vertices in the shape being skinned.
//     
//     
//     The vertex weights.
//     
//     
//     
//     The strips.
//
struct SkinPartition {
  // Number of strips in this submesh (zero if not stripped).
  ushort numStrips;
  // List of bones.
  vector<ushort > bones;
  // Do we have a vertex map?
  bool hasVertexMap;
  // Maps the weight/influence lists in this submesh to the vertices in the shape being skinned.
  vector<ushort > vertexMap;
  // Do we have vertex weights?
  bool hasVertexWeights;
  // The vertex weights.
  vector<vector<float > > vertexWeights;
  // Do we have strip data?
  bool hasStrips;
  // The strips.
  vector<vector<ushort > > strips;
  // The triangles.
  vector<Triangle > triangles;
  // Do we have bone indices?
  bool hasBoneIndices;
  // Bone indices, they index into 'Bones'.
  vector<vector<byte > > boneIndices;
  SkinPartition() {};
};

void NifStream( SkinPartition & val, istream & in, uint version ) {
  ushort numVertices;
  ushort numTriangles;
  ushort numBones;
  ushort numWeightsPerVertex;
  vector<ushort > stripLengths;
  NifStream( numVertices, in, version );
  NifStream( numTriangles, in, version );
  NifStream( numBones, in, version );
  NifStream( val.numStrips, in, version );
  NifStream( numWeightsPerVertex, in, version );
  val.bones.resize(numBones);
  NifStream( val.bones, in, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.hasVertexMap, in, version );
  };
  if ( version <= 0x0A000102 ) {
    val.vertexMap.resize(numVertices);
    NifStream( val.vertexMap, in, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.hasVertexMap != 0 ) {
      val.vertexMap.resize(numVertices);
      NifStream( val.vertexMap, in, version );
    };
    NifStream( val.hasVertexWeights, in, version );
  };
  if ( version <= 0x0A000102 ) {
    val.vertexWeights.resize(numVertices);
    for (uint i = 0; i < numVertices; i++) {
      val.vertexWeights[i].resize(numWeightsPerVertex);
    };
    NifStream( val.vertexWeights, in, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.hasVertexWeights != 0 ) {
      val.vertexWeights.resize(numVertices);
      for (uint i = 0; i < numVertices; i++) {
        val.vertexWeights[i].resize(numWeightsPerVertex);
      };
      NifStream( val.vertexWeights, in, version );
    };
  };
  stripLengths.resize(val.numStrips);
  NifStream( stripLengths, in, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.hasStrips, in, version );
  };
  if ( version <= 0x0A000102 ) {
    val.strips.resize(val.numStrips);
    for (uint i = 0; i < val.numStrips; i++) {
      val.strips[i].resize(stripLengths[i]);
    };
    NifStream( val.strips, in, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.hasStrips != 0 ) {
      val.strips.resize(val.numStrips);
      for (uint i = 0; i < val.numStrips; i++) {
        val.strips[i].resize(stripLengths[i]);
      };
      NifStream( val.strips, in, version );
    };
  };
  if ( val.numStrips == 0 ) {
    val.triangles.resize(numTriangles);
    NifStream( val.triangles, in, version );
  };
  NifStream( val.hasBoneIndices, in, version );
  if ( val.hasBoneIndices != 0 ) {
    val.boneIndices.resize(numVertices);
    for (uint i = 0; i < numVertices; i++) {
      val.boneIndices[i].resize(numWeightsPerVertex);
    };
    NifStream( val.boneIndices, in, version );
  };
};

void NifStream( SkinPartition const & val, ostream & out, uint version ) {
  ushort numVertices;
  ushort numTriangles;
  ushort numBones;
  ushort numWeightsPerVertex;
  vector<ushort > stripLengths;
  numVertices = ushort(val.vertexMap.size());
  numTriangles = ushort(val.triangles.size());
  numBones = ushort(val.bones.size());
  numWeightsPerVertex = ushort(val.vertexWeights.size());
  stripLengths.resize(val.strips.size()); for (uint i = 0; i < val.strips.size(); i++) stripLengths[i] = ushort(val.strips[i].size());
  NifStream( numVertices, out, version );
  NifStream( numTriangles, out, version );
  NifStream( numBones, out, version );
  NifStream( val.numStrips, out, version );
  NifStream( numWeightsPerVertex, out, version );
  NifStream( val.bones, out, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.hasVertexMap, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.vertexMap, out, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.hasVertexMap != 0 ) {
      NifStream( val.vertexMap, out, version );
    };
    NifStream( val.hasVertexWeights, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.vertexWeights, out, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.hasVertexWeights != 0 ) {
      NifStream( val.vertexWeights, out, version );
    };
  };
  NifStream( stripLengths, out, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.hasStrips, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.strips, out, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.hasStrips != 0 ) {
      NifStream( val.strips, out, version );
    };
  };
  if ( val.numStrips == 0 ) {
    NifStream( val.triangles, out, version );
  };
  NifStream( val.hasBoneIndices, out, version );
  if ( val.hasBoneIndices != 0 ) {
    NifStream( val.boneIndices, out, version );
  };
};

ostream & operator<<( ostream & out, SkinPartition const & val );

// 
// Unknown.
//
struct unk292bytes {
  // Unknown.
  vector<vector<byte > > unknown292Bytes;
  unk292bytes() {};
};

void NifStream( unk292bytes & val, istream & in, uint version ) {
  val.unknown292Bytes.resize(73);
  for (uint i = 0; i < 73; i++) {
    val.unknown292Bytes[i].resize(4);
  };
  NifStream( val.unknown292Bytes, in, version );
};

void NifStream( unk292bytes const & val, ostream & out, uint version ) {
  NifStream( val.unknown292Bytes, out, version );
};

ostream & operator<<( ostream & out, unk292bytes const & val );

// 
// Describes a furniture position?
//
struct FurniturePosition {
  // Unknown. Position?
  Vector3 unknownVector;
  // Unknown.
  ushort unknownShort;
  // This might refer to a furnituremarkerxx.nif file.
  byte positionRef1_;
  // This might also refer to a furnituremarkerxx.nif file.
  byte positionRef2_;
  FurniturePosition() {};
};

void NifStream( FurniturePosition & val, istream & in, uint version ) {
  NifStream( val.unknownVector, in, version );
  NifStream( val.unknownShort, in, version );
  NifStream( val.positionRef1_, in, version );
  NifStream( val.positionRef2_, in, version );
};

void NifStream( FurniturePosition const & val, ostream & out, uint version ) {
  NifStream( val.unknownVector, out, version );
  NifStream( val.unknownShort, out, version );
  NifStream( val.positionRef1_, out, version );
  NifStream( val.positionRef2_, out, version );
};

ostream & operator<<( ostream & out, FurniturePosition const & val );

// 
// A triangle with extra data used for physics.
//
struct hkTriangle {
  // The triangle.
  Triangle triangle;
  // Another short, doesn't look like a vertex index.
  ushort unknownShort;
  // This appears to be a normalized vector, so probably it is a normal or a tangent vector or something like that.
  Vector3 normal;
  hkTriangle() {};
};

void NifStream( hkTriangle & val, istream & in, uint version ) {
  NifStream( val.triangle, in, version );
  NifStream( val.unknownShort, in, version );
  NifStream( val.normal, in, version );
};

void NifStream( hkTriangle const & val, ostream & out, uint version ) {
  NifStream( val.triangle, out, version );
  NifStream( val.unknownShort, out, version );
  NifStream( val.normal, out, version );
};

ostream & operator<<( ostream & out, hkTriangle const & val );

// 
// Info about level of detail ranges.
//
struct LODInfo {
  // Type of LOD info (0=regular, 1=info is in a NiRangeLODData block).
  uint lodType;
  // ?
  Vector3 lodCenter;
  // The ranges of distance that each level of detail applies in.
  vector<LODRange > lodLevels;
  // Zero?
  ushort unknownShort;
  // Refers to NiRangeLODData block.
  Link rangeData;
  LODInfo() {};
};

void NifStream( LODInfo & val, istream & in, uint version ) {
  uint numLodLevels;
  NifStream( val.lodType, in, version );
  if ( val.lodType == 0 ) {
    NifStream( val.lodCenter, in, version );
    NifStream( numLodLevels, in, version );
    val.lodLevels.resize(numLodLevels);
    NifStream( val.lodLevels, in, version );
  };
  if ( val.lodType == 1 ) {
    NifStream( val.unknownShort, in, version );
    NifStream( val.rangeData, in, version );
  };
};

void NifStream( LODInfo const & val, ostream & out, uint version ) {
  uint numLodLevels;
  numLodLevels = uint(val.lodLevels.size());
  NifStream( val.lodType, out, version );
  if ( val.lodType == 0 ) {
    NifStream( val.lodCenter, out, version );
    NifStream( numLodLevels, out, version );
    NifStream( val.lodLevels, out, version );
  };
  if ( val.lodType == 1 ) {
    NifStream( val.unknownShort, out, version );
    NifStream( val.rangeData, out, version );
  };
};

ostream & operator<<( ostream & out, LODInfo const & val );

// 
// particle array entry
//
struct Particle {
  // Particle velocity
  Vector3 velocity;
  // Unknown
  Vector3 unknownVector;
  // The particle's age.
  float lifetime;
  // Maximum age of the particle.
  float lifespan;
  // Timestamp of the last update.
  float timestamp;
  // Unknown short (=0)
  ushort unknownShort;
  // Particle/vertex index matches array index
  ushort vertexId;
  Particle() {};
};

void NifStream( Particle & val, istream & in, uint version ) {
  NifStream( val.velocity, in, version );
  NifStream( val.unknownVector, in, version );
  NifStream( val.lifetime, in, version );
  NifStream( val.lifespan, in, version );
  NifStream( val.timestamp, in, version );
  NifStream( val.unknownShort, in, version );
  NifStream( val.vertexId, in, version );
};

void NifStream( Particle const & val, ostream & out, uint version ) {
  NifStream( val.velocity, out, version );
  NifStream( val.unknownVector, out, version );
  NifStream( val.lifetime, out, version );
  NifStream( val.lifespan, out, version );
  NifStream( val.timestamp, out, version );
  NifStream( val.unknownShort, out, version );
  NifStream( val.vertexId, out, version );
};

ostream & operator<<( ostream & out, Particle const & val );

// 
// Data for several particles.
//
struct ParticleGroup {
  // Number of valid entries in the following array.
  // (number of active particles at the time the system was saved)
  ushort numValid;
  // Individual particle modifiers?
  vector<Particle > particles;
  ParticleGroup() {};
};

void NifStream( ParticleGroup & val, istream & in, uint version ) {
  ushort numParticles;
  NifStream( numParticles, in, version );
  NifStream( val.numValid, in, version );
  val.particles.resize(numParticles);
  NifStream( val.particles, in, version );
};

void NifStream( ParticleGroup const & val, ostream & out, uint version ) {
  ushort numParticles;
  numParticles = ushort(val.particles.size());
  NifStream( numParticles, out, version );
  NifStream( val.numValid, out, version );
  NifStream( val.particles, out, version );
};

ostream & operator<<( ostream & out, ParticleGroup const & val );

// 
// Skinning data component.
//
struct SkinData {
  // Rotation offset of the skin from this bone in bind position.
  Matrix33 rotation;
  // Translation offset of the skin from this bone in bind position.
  Vector3 translation;
  // Scale offset of the skin from this bone in bind position. (Assumption - this is always 1.0 so far)
  float scale;
  // This has been verified not to be a normalized quaternion.  They may or may not be related to each other so their specification as an array of 4 floats may be misleading.
  vector<float > unknown4Floats;
  // The vertex weights.
  vector<SkinWeight > vertexWeights;
  SkinData() {};
};

void NifStream( SkinData & val, istream & in, uint version ) {
  ushort numVertices;
  NifStream( val.rotation, in, version );
  NifStream( val.translation, in, version );
  NifStream( val.scale, in, version );
  val.unknown4Floats.resize(4);
  NifStream( val.unknown4Floats, in, version );
  NifStream( numVertices, in, version );
  val.vertexWeights.resize(numVertices);
  NifStream( val.vertexWeights, in, version );
};

void NifStream( SkinData const & val, ostream & out, uint version ) {
  ushort numVertices;
  numVertices = ushort(val.vertexWeights.size());
  NifStream( val.rotation, out, version );
  NifStream( val.translation, out, version );
  NifStream( val.scale, out, version );
  NifStream( val.unknown4Floats, out, version );
  NifStream( numVertices, out, version );
  NifStream( val.vertexWeights, out, version );
};

ostream & operator<<( ostream & out, SkinData const & val );

// 
// An array of keys. This one always has a Key Type.
//
template <class T >
struct TypedVectorKeyArray {
  // The key type.
  KeyType keyType;
  // The keys.
  vector<Key<T > > keys;
  TypedVectorKeyArray() {};
};

template <class T >
void NifStream( TypedVectorKeyArray<T> & val, istream & in, uint version ) {
  uint numKeys;
  NifStream( numKeys, in, version );
  NifStream( val.keyType, in, version );
  val.keys.resize(numKeys);
  NifStream( val.keys, in, version, val.keyType );
};

template <class T >
void NifStream( TypedVectorKeyArray<T> const & val, ostream & out, uint version ) {
  uint numKeys;
  numKeys = uint(val.keys.size());
  NifStream( numKeys, out, version );
  NifStream( val.keyType, out, version );
  NifStream( val.keys, out, version, val.keyType );
};

template <class T >
ostream & operator<<( ostream & out, TypedVectorKeyArray<T> const & val );

// 
// Geometry morphing data component.
//
struct Morph {
  // Name of the frame.
  string frameName;
  // The morphing keyframes.
  TypedVectorKeyArray<float > frames;
  // Unknown.
  uint unknownInt;
  // Morph vectors.
  vector<Vector3 > vectors;
  Morph() {};
};

void NifStream( Morph & val, istream & in, uint version, uint attr_arg ) {
  if ( version >= 0x0A01006A ) {
    NifStream( val.frameName, in, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.frames, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknownInt, in, version );
  };
  val.vectors.resize(attr_arg);
  NifStream( val.vectors, in, version );
};

void NifStream( Morph const & val, ostream & out, uint version, uint attr_arg ) {
  if ( version >= 0x0A01006A ) {
    NifStream( val.frameName, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.frames, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknownInt, out, version );
  };
  NifStream( val.vectors, out, version );
};

ostream & operator<<( ostream & out, Morph const & val );

// 
// Array of vector keys (anything that can be interpolated, except rotations).
//
template <class T >
struct VectorKeyArray {
  // Number of keys in the array.
  uint numKeys;
  // The key type.
  KeyType keyType;
  // The keys.
  vector<Key<T > > keys;
  VectorKeyArray() {};
};

template <class T >
void NifStream( VectorKeyArray<T> & val, istream & in, uint version ) {
  NifStream( val.numKeys, in, version );
  if ( val.numKeys != 0 ) {
    NifStream( val.keyType, in, version );
  };
  val.keys.resize(val.numKeys);
  NifStream( val.keys, in, version, val.keyType );
};

template <class T >
void NifStream( VectorKeyArray<T> const & val, ostream & out, uint version ) {
  NifStream( val.numKeys, out, version );
  if ( val.numKeys != 0 ) {
    NifStream( val.keyType, out, version );
  };
  NifStream( val.keys, out, version, val.keyType );
};

template <class T >
ostream & operator<<( ostream & out, VectorKeyArray<T> const & val );

// 
// Rotation key array.
//
template <class T >
struct RotationKeyArray {
  // Number of keys.
  uint numKeys;
  // Key type (1, 2, 3, or 4).
  KeyType keyType;
  // The rotation keys.
  vector<Key<T > > keys;
  RotationKeyArray() {};
};

template <class T >
void NifStream( RotationKeyArray<T> & val, istream & in, uint version ) {
  NifStream( val.numKeys, in, version );
  if ( val.numKeys != 0 ) {
    NifStream( val.keyType, in, version );
  };
  val.keys.resize(val.numKeys);
  NifStream( val.keys, in, version, val.keyType );
};

template <class T >
void NifStream( RotationKeyArray<T> const & val, ostream & out, uint version ) {
  NifStream( val.numKeys, out, version );
  if ( val.numKeys != 0 ) {
    NifStream( val.keyType, out, version );
  };
  NifStream( val.keys, out, version, val.keyType );
};

template <class T >
ostream & operator<<( ostream & out, RotationKeyArray<T> const & val );

// 
// A block that can be controlled by a controller.
//
// - Name of this controllable block, used to refer to the block in .kf files.
// - Extra data block index. (The first in a chain)
// - List of extra data indices.
// - Controller block index. (The first in a chain)
#define A_CONTROLLABLE_MEMBERS \
string name; \
Link extraData; \
LinkGroup extraDataList; \
Link controller; \

#define A_CONTROLLABLE_GETATTR \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Extra Data" ) \
  return attr_ref(extraData); \
if ( attr_name == "Controller" ) \
  return attr_ref(controller); \
return attr_ref(); \

#define A_CONTROLLABLE_PARENTS ABlock

#define A_CONTROLLABLE_CONSTRUCT

#define A_CONTROLLABLE_READ \
NifStream( name, in, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( extraData, in, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( extraDataList, in, version ); \
}; \
NifStream( controller, in, version ); \

#define A_CONTROLLABLE_WRITE \
NifStream( name, out, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( extraData, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( extraDataList, out, version ); \
}; \
NifStream( controller, out, version ); \

#define A_CONTROLLABLE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << "                Name:  " << name << endl; \
out << "          Extra Data:  " << extraData << endl; \
out << "     Extra Data List:  " << extraDataList << endl; \
out << "          Controller:  " << controller << endl; \
return out.str(); \

// 
// A generic time controller block.
//
// - Index of the next controller.
// - Controller flags (usually 0x000C).
// - Frequency (is usually 1.0).
// - Phase (usually 0.0).
// - Controller start time.
// - Controller stop time.
// - Controller target (block index of the first controllable ancestor of this block).
#define A_CONTROLLER_MEMBERS \
Link nextController; \
Flags flags; \
float frequency; \
float phase; \
float startTime; \
float stopTime; \
uint target; \

#define A_CONTROLLER_GETATTR \
if ( attr_name == "Next Controller" ) \
  return attr_ref(nextController); \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Frequency" ) \
  return attr_ref(frequency); \
if ( attr_name == "Phase" ) \
  return attr_ref(phase); \
if ( attr_name == "Start Time" ) \
  return attr_ref(startTime); \
if ( attr_name == "Stop Time" ) \
  return attr_ref(stopTime); \
if ( attr_name == "Target" ) \
  return attr_ref(target); \
return attr_ref(); \

#define A_CONTROLLER_PARENTS ABlock

#define A_CONTROLLER_CONSTRUCT

#define A_CONTROLLER_READ \
NifStream( nextController, in, version ); \
NifStream( flags, in, version ); \
NifStream( frequency, in, version ); \
NifStream( phase, in, version ); \
NifStream( startTime, in, version ); \
NifStream( stopTime, in, version ); \
NifStream( target, in, version ); \

#define A_CONTROLLER_WRITE \
NifStream( nextController, out, version ); \
NifStream( flags, out, version ); \
NifStream( frequency, out, version ); \
NifStream( phase, out, version ); \
NifStream( startTime, out, version ); \
NifStream( stopTime, out, version ); \
NifStream( target, out, version ); \

#define A_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << "     Next Controller:  " << nextController << endl; \
out << "               Flags:  " << flags << endl; \
out << "           Frequency:  " << frequency << endl; \
out << "               Phase:  " << phase << endl; \
out << "          Start Time:  " << startTime << endl; \
out << "           Stop Time:  " << stopTime << endl; \
out << "              Target:  " << target << endl; \
return out.str(); \

// 
// Level of detail controller for bones?
//
// - Unknown.
// - Unknown.
// - A list of node groups (each group a sequence of bones?).
#define A_BONE_L_O_D_CONTROLLER_MEMBERS \
uint unknownInt1; \
uint unknownInt2; \
vector<LinkGroup > nodeGroups; \

#define A_BONE_L_O_D_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
return attr_ref(); \

#define A_BONE_L_O_D_CONTROLLER_PARENTS AController

#define A_BONE_L_O_D_CONTROLLER_CONSTRUCT

#define A_BONE_L_O_D_CONTROLLER_READ \
uint numNodeGroups; \
AController::Read( in, version ); \
NifStream( unknownInt1, in, version ); \
NifStream( numNodeGroups, in, version ); \
NifStream( unknownInt2, in, version ); \
nodeGroups.resize(numNodeGroups); \
NifStream( nodeGroups, in, version ); \

#define A_BONE_L_O_D_CONTROLLER_WRITE \
uint numNodeGroups; \
AController::Write( out, version ); \
numNodeGroups = uint(nodeGroups.size()); \
NifStream( unknownInt1, out, version ); \
NifStream( numNodeGroups, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( nodeGroups, out, version ); \

#define A_BONE_L_O_D_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "     Num Node Groups:  -- calculated --" << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
out << "         Node Groups:  -- data not shown --" << endl; \
return out.str(); \

// 
// A group of blocks that contain complex data.  Implemented using block-specific interfaces in Niflib.
//
#define A_DATA_MEMBERS \

#define A_DATA_GETATTR \
return attr_ref(); \

#define A_DATA_PARENTS ABlock

#define A_DATA_CONSTRUCT

#define A_DATA_READ \

#define A_DATA_WRITE \

#define A_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
return out.str(); \

// 
// Describes a physical constraint.
//
// - The bodies affected by this constraint.
// - Usually 1.
#define ABHK_CONSTRAINT_MEMBERS \
vector<CrossRef > bodies; \
uint unknownInt; \

#define ABHK_CONSTRAINT_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
return attr_ref(); \

#define ABHK_CONSTRAINT_PARENTS AData

#define ABHK_CONSTRAINT_CONSTRUCT

#define ABHK_CONSTRAINT_READ \
uint numBodies; \
AData::Read( in, version ); \
NifStream( numBodies, in, version ); \
bodies.resize(numBodies); \
NifStream( bodies, in, version ); \
NifStream( unknownInt, in, version ); \

#define ABHK_CONSTRAINT_WRITE \
uint numBodies; \
AData::Write( out, version ); \
numBodies = uint(bodies.size()); \
NifStream( numBodies, out, version ); \
NifStream( bodies, out, version ); \
NifStream( unknownInt, out, version ); \

#define ABHK_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "          Num Bodies:  -- calculated --" << endl; \
out << "              Bodies:  -- data not shown --" << endl; \
out << "         Unknown Int:  " << unknownInt << endl; \
return out.str(); \

// 
// Ragdoll constraint.
//
// - Unknown floats.
// - Unknown.
// - Unknown.
#define ABHK_RAGDOLL_CONSTRAINT_MEMBERS \
vector<vector<float > > unknownFloats; \
float unknownFloat1; \
float unknownFloat2; \

#define ABHK_RAGDOLL_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
return attr_ref(); \

#define ABHK_RAGDOLL_CONSTRAINT_PARENTS AbhkConstraint

#define ABHK_RAGDOLL_CONSTRAINT_CONSTRUCT

#define ABHK_RAGDOLL_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
unknownFloats.resize(7); \
NifStream( unknownFloats, in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \

#define ABHK_RAGDOLL_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( unknownFloats, out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \

#define ABHK_RAGDOLL_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkConstraint::asString(); \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
return out.str(); \

// 
// Describes physical properties of an object?
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     
//     Unknown.
//
// - The rigid body's shape.
// - The lower 4 bits select the color of the collision mesh in the construction set:
// 
// 1 : red (statics)
// 2 : purple
// 3 : white
// 4 : light blue (clutter)
// 5 : orange (weapons)
// 6 : light orange
// 7 : turkoise
// 8 : green (creatures)
// - Unknown.
// - Unknown.
// - The flags, repeated?
// - Unknown.
// - Translation.
// - Unknown.
// - Rotation.
// - Unknown.
// - Seems to be some kind of transformation matrix, scale or translation?
// - The object's center.
// - Unknown float.
// - Object mass.
// - Unknown.
// - Unknown.
// - The object's friction.
// - The object's elasticity.
// - Unknown.
// - Unknown. Pi x 10?
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define ABHK_RIGID_BODY_MEMBERS \
Link shape; \
uint flags; \
vector<float > unknownFloats1; \
vector<ushort > unknownShorts1; \
uint flags2; \
vector<ushort > unknownShorts2; \
Vector3 translation; \
float unknownFloat00; \
QuaternionXYZW rotation; \
vector<float > unknownFloats2; \
vector<float > transform_; \
Vector3 center; \
float unknownFloat01; \
float mass; \
float unknownFloat0; \
float unknownFloat1; \
float friction; \
float elasticity; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \
vector<byte > unknownBytes5; \
uint unknownInt6; \
uint unknownInt7; \
uint unknownInt8; \
LinkGroup constraints; \

#define ABHK_RIGID_BODY_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Shape" ) \
  return attr_ref(shape); \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Flags 2" ) \
  return attr_ref(flags2); \
if ( attr_name == "Translation" ) \
  return attr_ref(translation); \
if ( attr_name == "Unknown Float 00" ) \
  return attr_ref(unknownFloat00); \
if ( attr_name == "Center" ) \
  return attr_ref(center); \
if ( attr_name == "Unknown Float 01" ) \
  return attr_ref(unknownFloat01); \
if ( attr_name == "Mass" ) \
  return attr_ref(mass); \
if ( attr_name == "Unknown Float 0" ) \
  return attr_ref(unknownFloat0); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Friction" ) \
  return attr_ref(friction); \
if ( attr_name == "Elasticity" ) \
  return attr_ref(elasticity); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknownFloat3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknownFloat4); \
if ( attr_name == "Unknown Int 6" ) \
  return attr_ref(unknownInt6); \
if ( attr_name == "Unknown Int 7" ) \
  return attr_ref(unknownInt7); \
if ( attr_name == "Unknown Int 8" ) \
  return attr_ref(unknownInt8); \
return attr_ref(); \

#define ABHK_RIGID_BODY_PARENTS AData

#define ABHK_RIGID_BODY_CONSTRUCT

#define ABHK_RIGID_BODY_READ \
AData::Read( in, version ); \
NifStream( shape, in, version ); \
NifStream( flags, in, version ); \
unknownFloats1.resize(5); \
NifStream( unknownFloats1, in, version ); \
unknownShorts1.resize(4); \
NifStream( unknownShorts1, in, version ); \
NifStream( flags2, in, version ); \
unknownShorts2.resize(6); \
NifStream( unknownShorts2, in, version ); \
NifStream( translation, in, version ); \
NifStream( unknownFloat00, in, version ); \
NifStream( rotation, in, version ); \
unknownFloats2.resize(8); \
NifStream( unknownFloats2, in, version ); \
transform_.resize(12); \
NifStream( transform_, in, version ); \
NifStream( center, in, version ); \
NifStream( unknownFloat01, in, version ); \
NifStream( mass, in, version ); \
NifStream( unknownFloat0, in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( friction, in, version ); \
NifStream( elasticity, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \
unknownBytes5.resize(4); \
NifStream( unknownBytes5, in, version ); \
NifStream( unknownInt6, in, version ); \
NifStream( unknownInt7, in, version ); \
NifStream( unknownInt8, in, version ); \
NifStream( constraints, in, version ); \
NifStream( unknownInt6, in, version ); \

#define ABHK_RIGID_BODY_WRITE \
AData::Write( out, version ); \
NifStream( shape, out, version ); \
NifStream( flags, out, version ); \
NifStream( unknownFloats1, out, version ); \
NifStream( unknownShorts1, out, version ); \
NifStream( flags2, out, version ); \
NifStream( unknownShorts2, out, version ); \
NifStream( translation, out, version ); \
NifStream( unknownFloat00, out, version ); \
NifStream( rotation, out, version ); \
NifStream( unknownFloats2, out, version ); \
NifStream( transform_, out, version ); \
NifStream( center, out, version ); \
NifStream( unknownFloat01, out, version ); \
NifStream( mass, out, version ); \
NifStream( unknownFloat0, out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( friction, out, version ); \
NifStream( elasticity, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \
NifStream( unknownBytes5, out, version ); \
NifStream( unknownInt6, out, version ); \
NifStream( unknownInt7, out, version ); \
NifStream( unknownInt8, out, version ); \
NifStream( constraints, out, version ); \
NifStream( unknownInt6, out, version ); \

#define ABHK_RIGID_BODY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "               Shape:  " << shape << endl; \
out << "               Flags:  " << flags << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "    Unknown Shorts 1:  -- data not shown --" << endl; \
out << "             Flags 2:  " << flags2 << endl; \
out << "    Unknown Shorts 2:  -- data not shown --" << endl; \
out << "         Translation:  " << translation << endl; \
out << "    Unknown Float 00:  " << unknownFloat00 << endl; \
out << "            Rotation:  " << rotation << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
out << "          Transform?:  -- data not shown --" << endl; \
out << "              Center:  " << center << endl; \
out << "    Unknown Float 01:  " << unknownFloat01 << endl; \
out << "                Mass:  " << mass << endl; \
out << "     Unknown Float 0:  " << unknownFloat0 << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "            Friction:  " << friction << endl; \
out << "          Elasticity:  " << elasticity << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "     Unknown Float 3:  " << unknownFloat3 << endl; \
out << "     Unknown Float 4:  " << unknownFloat4 << endl; \
out << "     Unknown Bytes 5:  -- data not shown --" << endl; \
out << "       Unknown Int 6:  " << unknownInt6 << endl; \
out << "       Unknown Int 7:  " << unknownInt7 << endl; \
out << "       Unknown Int 8:  " << unknownInt8 << endl; \
out << "         Constraints:  " << constraints << endl; \
return out.str(); \

// 
// Havok shape.
//
#define ABHK_SHAPE_MEMBERS \

#define ABHK_SHAPE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
return attr_ref(); \

#define ABHK_SHAPE_PARENTS AData

#define ABHK_SHAPE_CONSTRUCT

#define ABHK_SHAPE_READ \
AData::Read( in, version ); \

#define ABHK_SHAPE_WRITE \
AData::Write( out, version ); \

#define ABHK_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
return out.str(); \

// 
// Shape modifier?
//
// - The shape affected by the transform?
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - A transform matrix.
#define ABHK_TRANSFORM_SHAPE_MEMBERS \
Link subShape; \
uint unknownInt; \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
Matrix44 transform; \

#define ABHK_TRANSFORM_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Sub Shape" ) \
  return attr_ref(subShape); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknownFloat3); \
if ( attr_name == "Transform" ) \
  return attr_ref(transform); \
return attr_ref(); \

#define ABHK_TRANSFORM_SHAPE_PARENTS AbhkShape

#define ABHK_TRANSFORM_SHAPE_CONSTRUCT

#define ABHK_TRANSFORM_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( subShape, in, version ); \
NifStream( unknownInt, in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( transform, in, version ); \

#define ABHK_TRANSFORM_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( subShape, out, version ); \
NifStream( unknownInt, out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( transform, out, version ); \

#define ABHK_TRANSFORM_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "           Sub Shape:  " << subShape << endl; \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "     Unknown Float 3:  " << unknownFloat3 << endl; \
out << "           Transform:  " << transform << endl; \
return out.str(); \

// 
// Unknown.
//
// - Links to the node parent.
// - Unknown.
// - Unknown. Links to the collision object data?
#define A_COLLISION_OBJECT_MEMBERS \
uint parent; \
ushort unknownShort; \
Link body; \

#define A_COLLISION_OBJECT_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Parent" ) \
  return attr_ref(parent); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Body" ) \
  return attr_ref(body); \
return attr_ref(); \

#define A_COLLISION_OBJECT_PARENTS AData

#define A_COLLISION_OBJECT_CONSTRUCT

#define A_COLLISION_OBJECT_READ \
AData::Read( in, version ); \
NifStream( parent, in, version ); \
NifStream( unknownShort, in, version ); \
NifStream( body, in, version ); \

#define A_COLLISION_OBJECT_WRITE \
AData::Write( out, version ); \
NifStream( parent, out, version ); \
NifStream( unknownShort, out, version ); \
NifStream( body, out, version ); \

#define A_COLLISION_OBJECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "              Parent:  " << parent << endl; \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "                Body:  " << body << endl; \
return out.str(); \

// 
// A generic extra data block.
//
// - Name of this block.
// - Block number of the next extra data block.
#define A_EXTRA_DATA_MEMBERS \
string name; \
Link nextExtraData; \

#define A_EXTRA_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Next Extra Data" ) \
  return attr_ref(nextExtraData); \
return attr_ref(); \

#define A_EXTRA_DATA_PARENTS AData

#define A_EXTRA_DATA_CONSTRUCT

#define A_EXTRA_DATA_READ \
AData::Read( in, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( name, in, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( nextExtraData, in, version ); \
}; \

#define A_EXTRA_DATA_WRITE \
AData::Write( out, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( name, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( nextExtraData, out, version ); \
}; \

#define A_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "     Next Extra Data:  " << nextExtraData << endl; \
return out.str(); \

// 
// Interpolator blocks - function unknown.
//
#define A_INTERPOLATOR_MEMBERS \

#define A_INTERPOLATOR_GETATTR \
return attr_ref(); \

#define A_INTERPOLATOR_PARENTS ABlock

#define A_INTERPOLATOR_CONSTRUCT

#define A_INTERPOLATOR_READ \

#define A_INTERPOLATOR_WRITE \

#define A_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
return out.str(); \

// 
// An extended type of interpolater.
//
// - Unknown.
// - Unknown.
#define A_BLEND_INTERPOLATOR_MEMBERS \
ushort unknownShort; \
uint unknownInt; \

#define A_BLEND_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
return attr_ref(); \

#define A_BLEND_INTERPOLATOR_PARENTS AInterpolator

#define A_BLEND_INTERPOLATOR_CONSTRUCT

#define A_BLEND_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( unknownShort, in, version ); \
NifStream( unknownInt, in, version ); \

#define A_BLEND_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( unknownShort, out, version ); \
NifStream( unknownInt, out, version ); \

#define A_BLEND_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "         Unknown Int:  " << unknownInt << endl; \
return out.str(); \

// 
// A B-spline (component?) interpolator.
//
// - Animation start time.
// - Animation stop time.
#define A_B_SPLINE_COMP_INTERPOLATOR_MEMBERS \
float startTime; \
float stopTime; \

#define A_B_SPLINE_COMP_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Start Time" ) \
  return attr_ref(startTime); \
if ( attr_name == "Stop Time" ) \
  return attr_ref(stopTime); \
return attr_ref(); \

#define A_B_SPLINE_COMP_INTERPOLATOR_PARENTS AInterpolator

#define A_B_SPLINE_COMP_INTERPOLATOR_CONSTRUCT

#define A_B_SPLINE_COMP_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( startTime, in, version ); \
NifStream( stopTime, in, version ); \

#define A_B_SPLINE_COMP_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( startTime, out, version ); \
NifStream( stopTime, out, version ); \

#define A_B_SPLINE_COMP_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "          Start Time:  " << startTime << endl; \
out << "           Stop Time:  " << stopTime << endl; \
return out.str(); \

// 
// Single items of data linked to particular key times.
//
#define A_KEYED_DATA_MEMBERS \

#define A_KEYED_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
return attr_ref(); \

#define A_KEYED_DATA_PARENTS AData

#define A_KEYED_DATA_CONSTRUCT

#define A_KEYED_DATA_READ \
AData::Read( in, version ); \

#define A_KEYED_DATA_WRITE \
AData::Write( out, version ); \

#define A_KEYED_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
return out.str(); \

// 
// A time controller block for animation key frames.
//
// - Keyframe controller data index.
#define A_KEYFRAME_CONTROLLER_MEMBERS \
Link data; \

#define A_KEYFRAME_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
return attr_ref(); \

#define A_KEYFRAME_CONTROLLER_PARENTS AController

#define A_KEYFRAME_CONTROLLER_CONSTRUCT

#define A_KEYFRAME_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( data, in, version ); \

#define A_KEYFRAME_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( data, out, version ); \

#define A_KEYFRAME_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Keyframes for mesh animation.
//
// - Rotation keyframes.
// - Translation keys.
// - Scale keys.
#define A_KEYFRAME_DATA_MEMBERS \
RotationKeyArray<Quaternion > rotations; \
VectorKeyArray<Vector3 > translations; \
VectorKeyArray<float > scales; \

#define A_KEYFRAME_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
return attr_ref(); \

#define A_KEYFRAME_DATA_PARENTS AData

#define A_KEYFRAME_DATA_CONSTRUCT

#define A_KEYFRAME_DATA_READ \
AData::Read( in, version ); \
NifStream( rotations, in, version ); \
NifStream( translations, in, version ); \
NifStream( scales, in, version ); \

#define A_KEYFRAME_DATA_WRITE \
AData::Write( out, version ); \
NifStream( rotations, out, version ); \
NifStream( translations, out, version ); \
NifStream( scales, out, version ); \

#define A_KEYFRAME_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "           Rotations:  " << rotations << endl; \
out << "        Translations:  " << translations << endl; \
out << "              Scales:  " << scales << endl; \
return out.str(); \

// 
// Generic node block.
//
// - Some flags; commonly 0x000C or 0x000A.
// - The translation vector.
// - The rotation part of the transformation matrix.
// - Scaling part (only uniform scaling is supported).
// - Unknown function. Always seems to be (0, 0, 0)
// - List of node properties.
// - The bounding box.
// - Bounding box: refers to NiCollisionData
#define A_NODE_MEMBERS \
Flags flags; \
Vector3 translation; \
Matrix33 rotation; \
float scale; \
Vector3 velocity; \
LinkGroup properties; \
BoundingBox boundingBox; \
Link collisionData; \

#define A_NODE_GETATTR \
attr_ref attr = AControllable::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Translation" ) \
  return attr_ref(translation); \
if ( attr_name == "Rotation" ) \
  return attr_ref(rotation); \
if ( attr_name == "Scale" ) \
  return attr_ref(scale); \
if ( attr_name == "Velocity" ) \
  return attr_ref(velocity); \
if ( attr_name == "Bounding Box" ) \
  return attr_ref(boundingBox); \
if ( attr_name == "Collision Data" ) \
  return attr_ref(collisionData); \
return attr_ref(); \

#define A_NODE_PARENTS AControllable

#define A_NODE_CONSTRUCT scale(1.0)

#define A_NODE_READ \
AControllable::Read( in, version ); \
NifStream( flags, in, version ); \
NifStream( translation, in, version ); \
NifStream( rotation, in, version ); \
NifStream( scale, in, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( velocity, in, version ); \
}; \
NifStream( properties, in, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( boundingBox, in, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( collisionData, in, version ); \
}; \

#define A_NODE_WRITE \
AControllable::Write( out, version ); \
NifStream( flags, out, version ); \
NifStream( translation, out, version ); \
NifStream( rotation, out, version ); \
NifStream( scale, out, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( velocity, out, version ); \
}; \
NifStream( properties, out, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( boundingBox, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( collisionData, out, version ); \
}; \

#define A_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AControllable::asString(); \
out << "               Flags:  " << flags << endl; \
out << "         Translation:  " << translation << endl; \
out << "            Rotation:  " << rotation << endl; \
out << "               Scale:  " << scale << endl; \
out << "            Velocity:  " << velocity << endl; \
out << "          Properties:  " << properties << endl; \
out << "        Bounding Box:  " << boundingBox << endl; \
out << "      Collision Data:  " << collisionData << endl; \
return out.str(); \

// 
// A dynamic effect such as a light or environment map.
//
// - This is probably the list of affected nodes. For some reason i do not know the max exporter seems to write pointers instead of links. But it doesn't matter because at least in version 4.0.0.2 the list is automagically updated by the engine during the load stage.
// - Turns effect on and off?  Switches list to list of unaffected nodes?
// - The list of affected nodes?
#define A_DYNAMIC_EFFECT_MEMBERS \
CondInt affectedNodeList_; \
bool switchState; \
LinkGroup affectedNodes; \

#define A_DYNAMIC_EFFECT_GETATTR \
attr_ref attr = ANode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Switch State" ) \
  return attr_ref(switchState); \
return attr_ref(); \

#define A_DYNAMIC_EFFECT_PARENTS ANode

#define A_DYNAMIC_EFFECT_CONSTRUCT

#define A_DYNAMIC_EFFECT_READ \
ANode::Read( in, version ); \
if ( version <= 0x04000002 ) { \
  NifStream( affectedNodeList_, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( switchState, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  NifStream( affectedNodes, in, version ); \
}; \

#define A_DYNAMIC_EFFECT_WRITE \
ANode::Write( out, version ); \
if ( version <= 0x04000002 ) { \
  NifStream( affectedNodeList_, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( switchState, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  NifStream( affectedNodes, out, version ); \
}; \

#define A_DYNAMIC_EFFECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ANode::asString(); \
out << " Affected Node List?:  " << affectedNodeList_ << endl; \
out << "        Switch State:  " << switchState << endl; \
out << "      Affected Nodes:  " << affectedNodes << endl; \
return out.str(); \

// 
// Light source.
//
// - Dimmer.
// - Ambient color.
// - Diffuse color.
// - Specular color.
#define A_LIGHT_MEMBERS \
float dimmer; \
Color3 ambientColor; \
Color3 diffuseColor; \
Color3 specularColor; \

#define A_LIGHT_GETATTR \
attr_ref attr = ADynamicEffect::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Dimmer" ) \
  return attr_ref(dimmer); \
if ( attr_name == "Ambient Color" ) \
  return attr_ref(ambientColor); \
if ( attr_name == "Diffuse Color" ) \
  return attr_ref(diffuseColor); \
if ( attr_name == "Specular Color" ) \
  return attr_ref(specularColor); \
return attr_ref(); \

#define A_LIGHT_PARENTS ADynamicEffect

#define A_LIGHT_CONSTRUCT

#define A_LIGHT_READ \
ADynamicEffect::Read( in, version ); \
NifStream( dimmer, in, version ); \
NifStream( ambientColor, in, version ); \
NifStream( diffuseColor, in, version ); \
NifStream( specularColor, in, version ); \

#define A_LIGHT_WRITE \
ADynamicEffect::Write( out, version ); \
NifStream( dimmer, out, version ); \
NifStream( ambientColor, out, version ); \
NifStream( diffuseColor, out, version ); \
NifStream( specularColor, out, version ); \

#define A_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ADynamicEffect::asString(); \
out << "              Dimmer:  " << dimmer << endl; \
out << "       Ambient Color:  " << ambientColor << endl; \
out << "       Diffuse Color:  " << diffuseColor << endl; \
out << "      Specular Color:  " << specularColor << endl; \
return out.str(); \

// 
// Generic node block for grouping.
//
// - List of child node block indices.
// - List of node effects.
#define A_PARENT_NODE_MEMBERS \
LinkGroup children; \
LinkGroup effects; \

#define A_PARENT_NODE_GETATTR \
attr_ref attr = ANode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
return attr_ref(); \

#define A_PARENT_NODE_PARENTS ANode

#define A_PARENT_NODE_CONSTRUCT

#define A_PARENT_NODE_READ \
ANode::Read( in, version ); \
NifStream( children, in, version ); \
NifStream( effects, in, version ); \

#define A_PARENT_NODE_WRITE \
ANode::Write( out, version ); \
NifStream( children, out, version ); \
NifStream( effects, out, version ); \

#define A_PARENT_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ANode::asString(); \
out << "            Children:  " << children << endl; \
out << "             Effects:  " << effects << endl; \
return out.str(); \

// 
// Firaxis-specific UI widgets?
//
// - Unknown.
// - Looks like 9 links and some string data.
#define A_FX_MEMBERS \
byte unknown1; \
unk292bytes unknown2; \

#define A_FX_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown1" ) \
  return attr_ref(unknown1); \
return attr_ref(); \

#define A_FX_PARENTS AParentNode

#define A_FX_CONSTRUCT

#define A_FX_READ \
AParentNode::Read( in, version ); \
NifStream( unknown1, in, version ); \
NifStream( unknown2, in, version ); \

#define A_FX_WRITE \
AParentNode::Write( out, version ); \
NifStream( unknown1, out, version ); \
NifStream( unknown2, out, version ); \

#define A_FX_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
out << "            Unknown1:  " << unknown1 << endl; \
out << "            Unknown2:  " << unknown2 << endl; \
return out.str(); \

// 
// A particle system modifier.
//
// - Next particle modifier.
// - Previous particle modifier.
#define A_PARTICLE_MODIFIER_MEMBERS \
Link nextModifier; \
uint previousModifier; \

#define A_PARTICLE_MODIFIER_GETATTR \
if ( attr_name == "Next Modifier" ) \
  return attr_ref(nextModifier); \
if ( attr_name == "Previous Modifier" ) \
  return attr_ref(previousModifier); \
return attr_ref(); \

#define A_PARTICLE_MODIFIER_PARENTS ABlock

#define A_PARTICLE_MODIFIER_CONSTRUCT

#define A_PARTICLE_MODIFIER_READ \
NifStream( nextModifier, in, version ); \
NifStream( previousModifier, in, version ); \

#define A_PARTICLE_MODIFIER_WRITE \
NifStream( nextModifier, out, version ); \
NifStream( previousModifier, out, version ); \

#define A_PARTICLE_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << "       Next Modifier:  " << nextModifier << endl; \
out << "   Previous Modifier:  " << previousModifier << endl; \
return out.str(); \

// 
// A generic particle system time controller block.
//
// - Particle speed
// - Particle random speed modifier
// - vertical emit direction [radians]
// 0.0 : up
// 1.6 : horizontal
// 3.1416 : down
// - emitter's vertical opening angle [radians]
// - horizontal emit direction
// - emitter's horizontal opening angle
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Particle size
// - Particle emit start time
// - Particle emit stop time
// - Unknown byte, (=0)
// - Particle emission rate (particles per second)
// - Particle lifetime
// - Particle lifetime random modifier
// - Bit 0: Emit Rate toggle bit (0 = auto adjust, 1 = use Emit Rate value)
// - Particle random start translation vector
// - This index targets the particle emitter block.
// - ? short=0 ?
// - ? float=1.0 ?
// - ? int=1 ?
// - ? int=0 ?
// - ? short=0 ?
// - Particle data.
// - unknown int (=0xffffffff)
// - Link to some optional particle modifiers (NiGravity, NiParticleGrowFade, NiParticleBomb, ...)
// - Unknown int (=0xffffffff)
// - Trailing null byte
#define A_PARTICLE_SYSTEM_CONTROLLER_MEMBERS \
float speed; \
float speedRandom; \
float verticalDirection; \
float verticalAngle; \
float horizontalDirection; \
float horizontalAngle; \
float unknownFloat5; \
float unknownFloat6; \
float unknownFloat7; \
float unknownFloat8; \
float unknownFloat9; \
float unknownFloat10; \
float unknownFloat11; \
float size; \
float emitStartTime; \
float emitStopTime; \
byte unknownByte; \
float emitRate; \
float lifetime; \
float lifetimeRandom; \
ushort emitFlags; \
Vector3 startRandom; \
Link emitter; \
ushort unknownShort2_; \
float unknownFloat13_; \
uint unknownInt1_; \
uint unknownInt2_; \
ushort unknownShort3_; \
ParticleGroup particles; \
Link unknownLink; \
Link particleExtra; \
Link unknownLink2; \
byte trailer; \

#define A_PARTICLE_SYSTEM_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Speed" ) \
  return attr_ref(speed); \
if ( attr_name == "Speed Random" ) \
  return attr_ref(speedRandom); \
if ( attr_name == "Vertical Direction" ) \
  return attr_ref(verticalDirection); \
if ( attr_name == "Vertical Angle" ) \
  return attr_ref(verticalAngle); \
if ( attr_name == "Horizontal Direction" ) \
  return attr_ref(horizontalDirection); \
if ( attr_name == "Horizontal Angle" ) \
  return attr_ref(horizontalAngle); \
if ( attr_name == "Unknown Float 5" ) \
  return attr_ref(unknownFloat5); \
if ( attr_name == "Unknown Float 6" ) \
  return attr_ref(unknownFloat6); \
if ( attr_name == "Unknown Float 7" ) \
  return attr_ref(unknownFloat7); \
if ( attr_name == "Unknown Float 8" ) \
  return attr_ref(unknownFloat8); \
if ( attr_name == "Unknown Float 9" ) \
  return attr_ref(unknownFloat9); \
if ( attr_name == "Unknown Float 10" ) \
  return attr_ref(unknownFloat10); \
if ( attr_name == "Unknown Float 11" ) \
  return attr_ref(unknownFloat11); \
if ( attr_name == "Size" ) \
  return attr_ref(size); \
if ( attr_name == "Emit Start Time" ) \
  return attr_ref(emitStartTime); \
if ( attr_name == "Emit Stop Time" ) \
  return attr_ref(emitStopTime); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
if ( attr_name == "Emit Rate" ) \
  return attr_ref(emitRate); \
if ( attr_name == "Lifetime" ) \
  return attr_ref(lifetime); \
if ( attr_name == "Lifetime Random" ) \
  return attr_ref(lifetimeRandom); \
if ( attr_name == "Emit Flags" ) \
  return attr_ref(emitFlags); \
if ( attr_name == "Start Random" ) \
  return attr_ref(startRandom); \
if ( attr_name == "Emitter" ) \
  return attr_ref(emitter); \
if ( attr_name == "Unknown Short 2?" ) \
  return attr_ref(unknownShort2_); \
if ( attr_name == "Unknown Float 13?" ) \
  return attr_ref(unknownFloat13_); \
if ( attr_name == "Unknown Int 1?" ) \
  return attr_ref(unknownInt1_); \
if ( attr_name == "Unknown Int 2?" ) \
  return attr_ref(unknownInt2_); \
if ( attr_name == "Unknown Short 3?" ) \
  return attr_ref(unknownShort3_); \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknownLink); \
if ( attr_name == "Particle Extra" ) \
  return attr_ref(particleExtra); \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknownLink2); \
if ( attr_name == "Trailer" ) \
  return attr_ref(trailer); \
return attr_ref(); \

#define A_PARTICLE_SYSTEM_CONTROLLER_PARENTS AController

#define A_PARTICLE_SYSTEM_CONTROLLER_CONSTRUCT

#define A_PARTICLE_SYSTEM_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( speed, in, version ); \
NifStream( speedRandom, in, version ); \
NifStream( verticalDirection, in, version ); \
NifStream( verticalAngle, in, version ); \
NifStream( horizontalDirection, in, version ); \
NifStream( horizontalAngle, in, version ); \
NifStream( unknownFloat5, in, version ); \
NifStream( unknownFloat6, in, version ); \
NifStream( unknownFloat7, in, version ); \
NifStream( unknownFloat8, in, version ); \
NifStream( unknownFloat9, in, version ); \
NifStream( unknownFloat10, in, version ); \
NifStream( unknownFloat11, in, version ); \
NifStream( size, in, version ); \
NifStream( emitStartTime, in, version ); \
NifStream( emitStopTime, in, version ); \
NifStream( unknownByte, in, version ); \
NifStream( emitRate, in, version ); \
NifStream( lifetime, in, version ); \
NifStream( lifetimeRandom, in, version ); \
NifStream( emitFlags, in, version ); \
NifStream( startRandom, in, version ); \
NifStream( emitter, in, version ); \
NifStream( unknownShort2_, in, version ); \
NifStream( unknownFloat13_, in, version ); \
NifStream( unknownInt1_, in, version ); \
NifStream( unknownInt2_, in, version ); \
NifStream( unknownShort3_, in, version ); \
NifStream( particles, in, version ); \
NifStream( unknownLink, in, version ); \
NifStream( particleExtra, in, version ); \
NifStream( unknownLink2, in, version ); \
NifStream( trailer, in, version ); \

#define A_PARTICLE_SYSTEM_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( speed, out, version ); \
NifStream( speedRandom, out, version ); \
NifStream( verticalDirection, out, version ); \
NifStream( verticalAngle, out, version ); \
NifStream( horizontalDirection, out, version ); \
NifStream( horizontalAngle, out, version ); \
NifStream( unknownFloat5, out, version ); \
NifStream( unknownFloat6, out, version ); \
NifStream( unknownFloat7, out, version ); \
NifStream( unknownFloat8, out, version ); \
NifStream( unknownFloat9, out, version ); \
NifStream( unknownFloat10, out, version ); \
NifStream( unknownFloat11, out, version ); \
NifStream( size, out, version ); \
NifStream( emitStartTime, out, version ); \
NifStream( emitStopTime, out, version ); \
NifStream( unknownByte, out, version ); \
NifStream( emitRate, out, version ); \
NifStream( lifetime, out, version ); \
NifStream( lifetimeRandom, out, version ); \
NifStream( emitFlags, out, version ); \
NifStream( startRandom, out, version ); \
NifStream( emitter, out, version ); \
NifStream( unknownShort2_, out, version ); \
NifStream( unknownFloat13_, out, version ); \
NifStream( unknownInt1_, out, version ); \
NifStream( unknownInt2_, out, version ); \
NifStream( unknownShort3_, out, version ); \
NifStream( particles, out, version ); \
NifStream( unknownLink, out, version ); \
NifStream( particleExtra, out, version ); \
NifStream( unknownLink2, out, version ); \
NifStream( trailer, out, version ); \

#define A_PARTICLE_SYSTEM_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "               Speed:  " << speed << endl; \
out << "        Speed Random:  " << speedRandom << endl; \
out << "  Vertical Direction:  " << verticalDirection << endl; \
out << "      Vertical Angle:  " << verticalAngle << endl; \
out << "Horizontal Direction:  " << horizontalDirection << endl; \
out << "    Horizontal Angle:  " << horizontalAngle << endl; \
out << "     Unknown Float 5:  " << unknownFloat5 << endl; \
out << "     Unknown Float 6:  " << unknownFloat6 << endl; \
out << "     Unknown Float 7:  " << unknownFloat7 << endl; \
out << "     Unknown Float 8:  " << unknownFloat8 << endl; \
out << "     Unknown Float 9:  " << unknownFloat9 << endl; \
out << "    Unknown Float 10:  " << unknownFloat10 << endl; \
out << "    Unknown Float 11:  " << unknownFloat11 << endl; \
out << "                Size:  " << size << endl; \
out << "     Emit Start Time:  " << emitStartTime << endl; \
out << "      Emit Stop Time:  " << emitStopTime << endl; \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "           Emit Rate:  " << emitRate << endl; \
out << "            Lifetime:  " << lifetime << endl; \
out << "     Lifetime Random:  " << lifetimeRandom << endl; \
out << "          Emit Flags:  " << emitFlags << endl; \
out << "        Start Random:  " << startRandom << endl; \
out << "             Emitter:  " << emitter << endl; \
out << "    Unknown Short 2?:  " << unknownShort2_ << endl; \
out << "   Unknown Float 13?:  " << unknownFloat13_ << endl; \
out << "      Unknown Int 1?:  " << unknownInt1_ << endl; \
out << "      Unknown Int 2?:  " << unknownInt2_ << endl; \
out << "    Unknown Short 3?:  " << unknownShort3_ << endl; \
out << "           Particles:  " << particles << endl; \
out << "        Unknown Link:  " << unknownLink << endl; \
out << "      Particle Extra:  " << particleExtra << endl; \
out << "      Unknown Link 2:  " << unknownLink2 << endl; \
out << "             Trailer:  " << trailer << endl; \
return out.str(); \

// 
// A type of light.
//
// - Constant Attenuation
// - Linear Attenuation
// - Quadratic Attenuation (see glLight)
#define A_POINT_LIGHT_MEMBERS \
float constantAttenuation; \
float linearAttenuation; \
float quadraticAttenuation; \

#define A_POINT_LIGHT_GETATTR \
attr_ref attr = ALight::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Constant Attenuation" ) \
  return attr_ref(constantAttenuation); \
if ( attr_name == "Linear Attenuation" ) \
  return attr_ref(linearAttenuation); \
if ( attr_name == "Quadratic Attenuation" ) \
  return attr_ref(quadraticAttenuation); \
return attr_ref(); \

#define A_POINT_LIGHT_PARENTS ALight

#define A_POINT_LIGHT_CONSTRUCT

#define A_POINT_LIGHT_READ \
ALight::Read( in, version ); \
NifStream( constantAttenuation, in, version ); \
NifStream( linearAttenuation, in, version ); \
NifStream( quadraticAttenuation, in, version ); \

#define A_POINT_LIGHT_WRITE \
ALight::Write( out, version ); \
NifStream( constantAttenuation, out, version ); \
NifStream( linearAttenuation, out, version ); \
NifStream( quadraticAttenuation, out, version ); \

#define A_POINT_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ALight::asString(); \
out << "Constant Attenuation:  " << constantAttenuation << endl; \
out << "  Linear Attenuation:  " << linearAttenuation << endl; \
out << "Quadratic Attenuation:  " << quadraticAttenuation << endl; \
return out.str(); \

// 
// A generic property block.
//
#define A_PROPERTY_MEMBERS \

#define A_PROPERTY_GETATTR \
attr_ref attr = AControllable::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
return attr_ref(); \

#define A_PROPERTY_PARENTS AControllable

#define A_PROPERTY_CONSTRUCT

#define A_PROPERTY_READ \
AControllable::Read( in, version ); \

#define A_PROPERTY_WRITE \
AControllable::Write( out, version ); \

#define A_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AControllable::asString(); \
return out.str(); \

// 
// Generic particle system modifier block.
//
// - The block name.
// - Modifier ID in the particle modifier chain (always a multiple of 1000)?
// - NiParticleSystem parent of this modifier.
// - Whether the modifier is currently in effect?  Usually true.
#define A_P_SYS_MODIFIER_MEMBERS \
string name; \
uint order; \
uint target; \
bool active; \

#define A_P_SYS_MODIFIER_GETATTR \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Order" ) \
  return attr_ref(order); \
if ( attr_name == "Target" ) \
  return attr_ref(target); \
if ( attr_name == "Active" ) \
  return attr_ref(active); \
return attr_ref(); \

#define A_P_SYS_MODIFIER_PARENTS ABlock

#define A_P_SYS_MODIFIER_CONSTRUCT

#define A_P_SYS_MODIFIER_READ \
NifStream( name, in, version ); \
NifStream( order, in, version ); \
NifStream( target, in, version ); \
NifStream( active, in, version ); \

#define A_P_SYS_MODIFIER_WRITE \
NifStream( name, out, version ); \
NifStream( order, out, version ); \
NifStream( target, out, version ); \
NifStream( active, out, version ); \

#define A_P_SYS_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << "                Name:  " << name << endl; \
out << "               Order:  " << order << endl; \
out << "              Target:  " << target << endl; \
out << "              Active:  " << active << endl; \
return out.str(); \

// 
// A particle emitter modifier?
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define A_P_SYS_EMITTER_MEMBERS \
float speed; \
float speedVariation; \
float declination; \
float declinationVariation; \
float planarAngle; \
float planarAngleVariation; \
Color4 initialColor; \
float initialRadius; \
float radiusVariation; \
float lifeSpan; \
float lifeSpanVariation; \

#define A_P_SYS_EMITTER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Speed" ) \
  return attr_ref(speed); \
if ( attr_name == "Speed Variation" ) \
  return attr_ref(speedVariation); \
if ( attr_name == "Declination" ) \
  return attr_ref(declination); \
if ( attr_name == "Declination Variation" ) \
  return attr_ref(declinationVariation); \
if ( attr_name == "Planar Angle" ) \
  return attr_ref(planarAngle); \
if ( attr_name == "Planar Angle Variation" ) \
  return attr_ref(planarAngleVariation); \
if ( attr_name == "Initial Color" ) \
  return attr_ref(initialColor); \
if ( attr_name == "Initial Radius" ) \
  return attr_ref(initialRadius); \
if ( attr_name == "Radius Variation" ) \
  return attr_ref(radiusVariation); \
if ( attr_name == "Life Span" ) \
  return attr_ref(lifeSpan); \
if ( attr_name == "Life Span Variation" ) \
  return attr_ref(lifeSpanVariation); \
return attr_ref(); \

#define A_P_SYS_EMITTER_PARENTS APSysModifier

#define A_P_SYS_EMITTER_CONSTRUCT

#define A_P_SYS_EMITTER_READ \
APSysModifier::Read( in, version ); \
NifStream( speed, in, version ); \
NifStream( speedVariation, in, version ); \
NifStream( declination, in, version ); \
NifStream( declinationVariation, in, version ); \
NifStream( planarAngle, in, version ); \
NifStream( planarAngleVariation, in, version ); \
NifStream( initialColor, in, version ); \
NifStream( initialRadius, in, version ); \
NifStream( radiusVariation, in, version ); \
NifStream( lifeSpan, in, version ); \
NifStream( lifeSpanVariation, in, version ); \

#define A_P_SYS_EMITTER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( speed, out, version ); \
NifStream( speedVariation, out, version ); \
NifStream( declination, out, version ); \
NifStream( declinationVariation, out, version ); \
NifStream( planarAngle, out, version ); \
NifStream( planarAngleVariation, out, version ); \
NifStream( initialColor, out, version ); \
NifStream( initialRadius, out, version ); \
NifStream( radiusVariation, out, version ); \
NifStream( lifeSpan, out, version ); \
NifStream( lifeSpanVariation, out, version ); \

#define A_P_SYS_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "               Speed:  " << speed << endl; \
out << "     Speed Variation:  " << speedVariation << endl; \
out << "         Declination:  " << declination << endl; \
out << "Declination Variation:  " << declinationVariation << endl; \
out << "        Planar Angle:  " << planarAngle << endl; \
out << "Planar Angle Variation:  " << planarAngleVariation << endl; \
out << "       Initial Color:  " << initialColor << endl; \
out << "      Initial Radius:  " << initialRadius << endl; \
out << "    Radius Variation:  " << radiusVariation << endl; \
out << "           Life Span:  " << lifeSpan << endl; \
out << " Life Span Variation:  " << lifeSpanVariation << endl; \
return out.str(); \

// 
// An emitter that emits meshes?
//
// - Node parent of this modifier?
#define A_P_SYS_VOLUME_EMITTER_MEMBERS \
uint emitterObject; \

#define A_P_SYS_VOLUME_EMITTER_GETATTR \
attr_ref attr = APSysEmitter::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Emitter Object" ) \
  return attr_ref(emitterObject); \
return attr_ref(); \

#define A_P_SYS_VOLUME_EMITTER_PARENTS APSysEmitter

#define A_P_SYS_VOLUME_EMITTER_CONSTRUCT

#define A_P_SYS_VOLUME_EMITTER_READ \
APSysEmitter::Read( in, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( emitterObject, in, version ); \
}; \

#define A_P_SYS_VOLUME_EMITTER_WRITE \
APSysEmitter::Write( out, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( emitterObject, out, version ); \
}; \

#define A_P_SYS_VOLUME_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysEmitter::asString(); \
out << "      Emitter Object:  " << emitterObject << endl; \
return out.str(); \

// 
// Describes a mesh, built from triangles.
//
// - Data index (NiTriShapeData/NiTriStripData).
// - Skin instance index.
// - Shader.
#define A_SHAPE_MEMBERS \
Link data; \
Link skinInstance; \
Shader shader; \

#define A_SHAPE_GETATTR \
attr_ref attr = ANode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Skin Instance" ) \
  return attr_ref(skinInstance); \
return attr_ref(); \

#define A_SHAPE_PARENTS ANode

#define A_SHAPE_CONSTRUCT

#define A_SHAPE_READ \
ANode::Read( in, version ); \
NifStream( data, in, version ); \
NifStream( skinInstance, in, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( shader, in, version ); \
}; \

#define A_SHAPE_WRITE \
ANode::Write( out, version ); \
NifStream( data, out, version ); \
NifStream( skinInstance, out, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( shader, out, version ); \
}; \

#define A_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ANode::asString(); \
out << "                Data:  " << data << endl; \
out << "       Skin Instance:  " << skinInstance << endl; \
out << "              Shader:  " << shader << endl; \
return out.str(); \

// 
// Generic particle system node.
//
#define A_PARTICLE_NODE_MEMBERS \

#define A_PARTICLE_NODE_GETATTR \
attr_ref attr = AShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
return attr_ref(); \

#define A_PARTICLE_NODE_PARENTS AShape

#define A_PARTICLE_NODE_CONSTRUCT

#define A_PARTICLE_NODE_READ \
AShape::Read( in, version ); \

#define A_PARTICLE_NODE_WRITE \
AShape::Write( out, version ); \

#define A_PARTICLE_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShape::asString(); \
return out.str(); \

// 
// Mesh data: vertices, vertex normals, etc.
//
// - Name of this block.
// - Unknown.
// - Is the vertex array present? (Always non-zero.)
// - The mesh vertices.
// - The lower 6 (or less?) bits of this field represent the number of UV texture sets. The other bits are probably flag bits.
// - Unknown. If bit 4 is set then extra vectors are present after the normals.
// - Do we have lighting normals? These are essential for proper lighting: if not present, the model will only be influenced by ambient light.
// - The lighting normals.
// - Unknown. Binormal & tangents? has_normals must be set as well for this field to be present.
// - Unknown. Binormal & tangents?
// - Do we have vertex colors? These are usually used to fine-tune the lighting of the model.
// 
// Note: how vertex colors influence the model can be controlled by having a NiVertexColorProperty block as a property child of the root node. If this property block is not present, the vertex colors fine-tune lighting.
// 
// Note 2: set to either 0 or 0xFFFFFFFF for NifTexture compatibility.
// - The vertex colors.
// - Do we have UV coordinates?
// 
// Note: for compatibility with NifTexture, set this value to either 0x00000000 or 0xFFFFFFFF.
// - The UV texture coordinates. They follow the OpenGL standard: some programs may require you to flip the second coordinate.
// - Same as above, but needs to be repeated due to 'UV Sets' moving to a different position.
// - Unknown. Usually zero.
// - Unknown.
#define A_SHAPE_DATA_MEMBERS \
string name; \
ushort unknownShort1; \
bool hasVertices; \
vector<Vector3 > vertices; \
byte numUvSets2; \
byte unknownByte; \
bool hasNormals; \
vector<Vector3 > normals; \
vector<vector<Vector3 > > unknownVectors1; \
vector<vector<Vector3 > > unknownVectors2; \
bool hasVertexColors; \
vector<Color4 > vertexColors; \
bool hasUv; \
vector<vector<TexCoord > > uvSets; \
vector<vector<TexCoord > > uvSets2; \
ushort unknownShort2; \
Link unknownLink; \

#define A_SHAPE_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Unknown Short 1" ) \
  return attr_ref(unknownShort1); \
if ( attr_name == "Has Vertices" ) \
  return attr_ref(hasVertices); \
if ( attr_name == "Num UV Sets 2" ) \
  return attr_ref(numUvSets2); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
if ( attr_name == "Has Normals" ) \
  return attr_ref(hasNormals); \
if ( attr_name == "Has Vertex Colors" ) \
  return attr_ref(hasVertexColors); \
if ( attr_name == "Has UV" ) \
  return attr_ref(hasUv); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknownShort2); \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknownLink); \
return attr_ref(); \

#define A_SHAPE_DATA_PARENTS AData

#define A_SHAPE_DATA_CONSTRUCT

#define A_SHAPE_DATA_READ \
ushort numVertices; \
Vector3 center; \
float radius; \
ushort numUvSets; \
AData::Read( in, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( name, in, version ); \
}; \
NifStream( numVertices, in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknownShort1, in, version ); \
}; \
NifStream( hasVertices, in, version ); \
if ( hasVertices != 0 ) { \
  vertices.resize(numVertices); \
  NifStream( vertices, in, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( numUvSets2, in, version ); \
  NifStream( unknownByte, in, version ); \
}; \
NifStream( hasNormals, in, version ); \
if ( hasNormals != 0 ) { \
  normals.resize(numVertices); \
  NifStream( normals, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( unknownByte & 16 ) { \
    unknownVectors1.resize(hasNormals); \
    NifStream( unknownVectors1, in, version ); \
    unknownVectors2.resize(hasNormals); \
    NifStream( unknownVectors2, in, version ); \
  }; \
}; \
NifStream( hasVertexColors, in, version ); \
if ( hasVertexColors != 0 ) { \
  vertexColors.resize(numVertices); \
  NifStream( vertexColors, in, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( numUvSets, in, version ); \
}; \
if ( version <= 0x04000002 ) { \
  NifStream( hasUv, in, version ); \
}; \
if ( version <= 0x04020200 ) { \
  uvSets.resize(numUvSets); \
  NifStream( uvSets, in, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  uvSets2.resize(numUvSets2 & 63); \
  NifStream( uvSets2, in, version ); \
  NifStream( unknownShort2, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknownLink, in, version ); \
}; \

#define A_SHAPE_DATA_WRITE \
ushort numVertices; \
Vector3 center; \
float radius; \
ushort numUvSets; \
AData::Write( out, version ); \
numVertices = ushort(vertices.size()); \
center = Center(); \
radius = Radius(); \
numUvSets = ushort(uvSets.size()); \
if ( version >= 0x0A020000 ) { \
  NifStream( name, out, version ); \
}; \
NifStream( numVertices, out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknownShort1, out, version ); \
}; \
NifStream( hasVertices, out, version ); \
if ( hasVertices != 0 ) { \
  NifStream( vertices, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( numUvSets2, out, version ); \
  NifStream( unknownByte, out, version ); \
}; \
NifStream( hasNormals, out, version ); \
if ( hasNormals != 0 ) { \
  NifStream( normals, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( unknownByte & 16 ) { \
    NifStream( unknownVectors1, out, version ); \
    NifStream( unknownVectors2, out, version ); \
  }; \
}; \
NifStream( hasVertexColors, out, version ); \
if ( hasVertexColors != 0 ) { \
  NifStream( vertexColors, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( numUvSets, out, version ); \
}; \
if ( version <= 0x04000002 ) { \
  NifStream( hasUv, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( uvSets, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( uvSets2, out, version ); \
  NifStream( unknownShort2, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknownLink, out, version ); \
}; \

#define A_SHAPE_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "        Num Vertices:  -- calculated --" << endl; \
out << "     Unknown Short 1:  " << unknownShort1 << endl; \
out << "        Has Vertices:  " << hasVertices << endl; \
out << "            Vertices:  -- data not shown --" << endl; \
out << "       Num UV Sets 2:  " << numUvSets2 << endl; \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "         Has Normals:  " << hasNormals << endl; \
out << "             Normals:  -- data not shown --" << endl; \
out << "   Unknown Vectors 1:  -- data not shown --" << endl; \
out << "   Unknown Vectors 2:  -- data not shown --" << endl; \
out << "              Center:  -- calculated --" << endl; \
out << "              Radius:  -- calculated --" << endl; \
out << "   Has Vertex Colors:  " << hasVertexColors << endl; \
out << "       Vertex Colors:  -- data not shown --" << endl; \
out << "         Num UV Sets:  -- calculated --" << endl; \
out << "              Has UV:  " << hasUv << endl; \
out << "             UV Sets:  -- data not shown --" << endl; \
out << "           UV Sets 2:  -- data not shown --" << endl; \
out << "     Unknown Short 2:  " << unknownShort2 << endl; \
out << "        Unknown Link:  " << unknownLink << endl; \
return out.str(); \

// 
// Generic particle system data block.
//
// - The maximum number of particles (matches the number of vertices).
// - The particles' size.
// - The number of active particles at the time the system was saved. This is also the number of valid entries in the following arrays.
// - Unknown.
// - Is the particle size array present?
// - The individual particel sizes.
#define A_PARTICLES_DATA_MEMBERS \
ushort numParticles; \
float size; \
ushort numActive; \
ushort unknownShort; \
bool hasSizes; \
vector<float > sizes; \

#define A_PARTICLES_DATA_GETATTR \
attr_ref attr = AShapeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Particles" ) \
  return attr_ref(numParticles); \
if ( attr_name == "Size" ) \
  return attr_ref(size); \
if ( attr_name == "Num Active" ) \
  return attr_ref(numActive); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Has Sizes" ) \
  return attr_ref(hasSizes); \
return attr_ref(); \

#define A_PARTICLES_DATA_PARENTS AShapeData

#define A_PARTICLES_DATA_CONSTRUCT

#define A_PARTICLES_DATA_READ \
AShapeData::Read( in, version ); \
if ( version <= 0x04000002 ) { \
  NifStream( numParticles, in, version ); \
}; \
if ( version <= 0x0A000100 ) { \
  NifStream( size, in, version ); \
}; \
if ( version <= 0x04000002 ) { \
  NifStream( numActive, in, version ); \
}; \
if ( ( version >= 0x0401000C ) && ( version <= 0x0A000100 ) ) { \
  NifStream( unknownShort, in, version ); \
}; \
NifStream( hasSizes, in, version ); \
if ( hasSizes != 0 ) { \
  sizes.resize(numVertices); \
  NifStream( sizes, in, version ); \
}; \

#define A_PARTICLES_DATA_WRITE \
AShapeData::Write( out, version ); \
if ( version <= 0x04000002 ) { \
  NifStream( numParticles, out, version ); \
}; \
if ( version <= 0x0A000100 ) { \
  NifStream( size, out, version ); \
}; \
if ( version <= 0x04000002 ) { \
  NifStream( numActive, out, version ); \
}; \
if ( ( version >= 0x0401000C ) && ( version <= 0x0A000100 ) ) { \
  NifStream( unknownShort, out, version ); \
}; \
NifStream( hasSizes, out, version ); \
if ( hasSizes != 0 ) { \
  NifStream( sizes, out, version ); \
}; \

#define A_PARTICLES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShapeData::asString(); \
out << "       Num Particles:  " << numParticles << endl; \
out << "                Size:  " << size << endl; \
out << "          Num Active:  " << numActive << endl; \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "           Has Sizes:  " << hasSizes << endl; \
out << "               Sizes:  -- data not shown --" << endl; \
return out.str(); \

// 
// Particle system data.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define A_P_SYS_DATA_MEMBERS \
bool hasUnknownFloats1; \
vector<float > unknownFloats1; \
ushort unknownShort3; \
bool hasUnknownFloats2; \
vector<float > unknownFloats2; \
byte unknownByte1; \

#define A_P_SYS_DATA_GETATTR \
attr_ref attr = AShapeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Has Unknown Floats 1" ) \
  return attr_ref(hasUnknownFloats1); \
if ( attr_name == "Unknown Short 3" ) \
  return attr_ref(unknownShort3); \
if ( attr_name == "Has Unknown Floats 2" ) \
  return attr_ref(hasUnknownFloats2); \
if ( attr_name == "Unknown Byte 1" ) \
  return attr_ref(unknownByte1); \
return attr_ref(); \

#define A_P_SYS_DATA_PARENTS AShapeData

#define A_P_SYS_DATA_CONSTRUCT

#define A_P_SYS_DATA_READ \
AShapeData::Read( in, version ); \
NifStream( hasUnknownFloats1, in, version ); \
if ( hasUnknownFloats1 != 0 ) { \
  unknownFloats1.resize(numVertices); \
  NifStream( unknownFloats1, in, version ); \
}; \
NifStream( unknownShort3, in, version ); \
NifStream( hasUnknownFloats2, in, version ); \
if ( hasUnknownFloats2 != 0 ) { \
  unknownFloats2.resize(numVertices); \
  NifStream( unknownFloats2, in, version ); \
}; \
NifStream( unknownByte1, in, version ); \

#define A_P_SYS_DATA_WRITE \
AShapeData::Write( out, version ); \
NifStream( hasUnknownFloats1, out, version ); \
if ( hasUnknownFloats1 != 0 ) { \
  NifStream( unknownFloats1, out, version ); \
}; \
NifStream( unknownShort3, out, version ); \
NifStream( hasUnknownFloats2, out, version ); \
if ( hasUnknownFloats2 != 0 ) { \
  NifStream( unknownFloats2, out, version ); \
}; \
NifStream( unknownByte1, out, version ); \

#define A_P_SYS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShapeData::asString(); \
out << "Has Unknown Floats 1:  " << hasUnknownFloats1 << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "     Unknown Short 3:  " << unknownShort3 << endl; \
out << "Has Unknown Floats 2:  " << hasUnknownFloats2 << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
out << "      Unknown Byte 1:  " << unknownByte1 << endl; \
return out.str(); \

// 
// Generic rotating particles data block.
//
// - The number of active/valid particle entries.
// - Unknown
// - Unknown
// - Is the particle rotation array present?
// - The individual particle rotations.
#define A_ROTATING_PARTICLES_DATA_MEMBERS \
ushort numActive; \
bool hasUnknownFloats; \
vector<float > unknownFloats; \
bool hasRotations; \
vector<Quaternion > rotations; \

#define A_ROTATING_PARTICLES_DATA_GETATTR \
attr_ref attr = AParticlesData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Active" ) \
  return attr_ref(numActive); \
if ( attr_name == "Has Unknown Floats" ) \
  return attr_ref(hasUnknownFloats); \
if ( attr_name == "Has Rotations" ) \
  return attr_ref(hasRotations); \
return attr_ref(); \

#define A_ROTATING_PARTICLES_DATA_PARENTS AParticlesData

#define A_ROTATING_PARTICLES_DATA_CONSTRUCT

#define A_ROTATING_PARTICLES_DATA_READ \
AParticlesData::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( numActive, in, version ); \
  NifStream( hasUnknownFloats, in, version ); \
  if ( hasUnknownFloats != 0 ) { \
    unknownFloats.resize(numVertices); \
    NifStream( unknownFloats, in, version ); \
  }; \
}; \
NifStream( hasRotations, in, version ); \
if ( hasRotations != 0 ) { \
  rotations.resize(numVertices); \
  NifStream( rotations, in, version ); \
}; \

#define A_ROTATING_PARTICLES_DATA_WRITE \
AParticlesData::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( numActive, out, version ); \
  NifStream( hasUnknownFloats, out, version ); \
  if ( hasUnknownFloats != 0 ) { \
    NifStream( unknownFloats, out, version ); \
  }; \
}; \
NifStream( hasRotations, out, version ); \
if ( hasRotations != 0 ) { \
  NifStream( rotations, out, version ); \
}; \

#define A_ROTATING_PARTICLES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticlesData::asString(); \
out << "          Num Active:  " << numActive << endl; \
out << "  Has Unknown Floats:  " << hasUnknownFloats << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "       Has Rotations:  " << hasRotations << endl; \
out << "           Rotations:  -- data not shown --" << endl; \
return out.str(); \

// 
// A controller referring to an interpolator.
//
// - Link to interpolator.
#define A_SINGLE_INTERPOLATOR_CONTROLLER_MEMBERS \
Link interpolator; \

#define A_SINGLE_INTERPOLATOR_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Interpolator" ) \
  return attr_ref(interpolator); \
return attr_ref(); \

#define A_SINGLE_INTERPOLATOR_CONTROLLER_PARENTS AController

#define A_SINGLE_INTERPOLATOR_CONTROLLER_CONSTRUCT

#define A_SINGLE_INTERPOLATOR_CONTROLLER_READ \
AController::Read( in, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( interpolator, in, version ); \
}; \

#define A_SINGLE_INTERPOLATOR_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( interpolator, out, version ); \
}; \

#define A_SINGLE_INTERPOLATOR_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "        Interpolator:  " << interpolator << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown. Seems to refer to some block by its name?
#define A_P_SYS_CTLR_MEMBERS \
string unknownString; \

#define A_P_SYS_CTLR_GETATTR \
attr_ref attr = ASingleInterpolatorController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown String" ) \
  return attr_ref(unknownString); \
return attr_ref(); \

#define A_P_SYS_CTLR_PARENTS ASingleInterpolatorController

#define A_P_SYS_CTLR_CONSTRUCT

#define A_P_SYS_CTLR_READ \
ASingleInterpolatorController::Read( in, version ); \
NifStream( unknownString, in, version ); \

#define A_P_SYS_CTLR_WRITE \
ASingleInterpolatorController::Write( out, version ); \
NifStream( unknownString, out, version ); \

#define A_P_SYS_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ASingleInterpolatorController::asString(); \
out << "      Unknown String:  " << unknownString << endl; \
return out.str(); \

// 
// Morrowind specific?
//
#define AVOID_NODE_MEMBERS \

#define AVOID_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define AVOID_NODE_PARENTS AParentNode

#define AVOID_NODE_CONSTRUCT

#define AVOID_NODE_READ \
AParentNode::Read( in, version ); \

#define AVOID_NODE_WRITE \
AParentNode::Write( out, version ); \

#define AVOID_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
return out.str(); \

// 
// Unknown.
//
// - Blending parameter?
// - Another blending parameter?
#define BHK_BLEND_COLLISION_OBJECT_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \

#define BHK_BLEND_COLLISION_OBJECT_GETATTR \
attr_ref attr = ACollisionObject::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_BLEND_COLLISION_OBJECT_PARENTS ACollisionObject

#define BHK_BLEND_COLLISION_OBJECT_CONSTRUCT

#define BHK_BLEND_COLLISION_OBJECT_READ \
ACollisionObject::Read( in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \

#define BHK_BLEND_COLLISION_OBJECT_WRITE \
ACollisionObject::Write( out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \

#define BHK_BLEND_COLLISION_OBJECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ACollisionObject::asString(); \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
return out.str(); \

// 
// Unknown. Is apparently only used in skeleton.nif files.
//
// - Seems to be always zero.
#define BHK_BLEND_CONTROLLER_MEMBERS \
uint unknownInt; \

#define BHK_BLEND_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_BLEND_CONTROLLER_PARENTS AController

#define BHK_BLEND_CONTROLLER_CONSTRUCT

#define BHK_BLEND_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( unknownInt, in, version ); \

#define BHK_BLEND_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( unknownInt, out, version ); \

#define BHK_BLEND_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
return out.str(); \

// 
// A box.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Looks like this could be the box size.
// - Unknown.
#define BHK_BOX_SHAPE_MEMBERS \
uint unknownInt; \
float unknownFloat1; \
ushort unknownShort1; \
ushort unknownShort2; \
ushort unknownShort3; \
ushort unknownShort4; \
Vector3 unknownVector; \
float unknownFloat2; \

#define BHK_BOX_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Short 1" ) \
  return attr_ref(unknownShort1); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknownShort2); \
if ( attr_name == "Unknown Short 3" ) \
  return attr_ref(unknownShort3); \
if ( attr_name == "Unknown Short 4" ) \
  return attr_ref(unknownShort4); \
if ( attr_name == "Unknown Vector" ) \
  return attr_ref(unknownVector); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_BOX_SHAPE_PARENTS AbhkShape

#define BHK_BOX_SHAPE_CONSTRUCT

#define BHK_BOX_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( unknownInt, in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownShort1, in, version ); \
NifStream( unknownShort2, in, version ); \
NifStream( unknownShort3, in, version ); \
NifStream( unknownShort4, in, version ); \
NifStream( unknownVector, in, version ); \
NifStream( unknownFloat2, in, version ); \

#define BHK_BOX_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( unknownInt, out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownShort1, out, version ); \
NifStream( unknownShort2, out, version ); \
NifStream( unknownShort3, out, version ); \
NifStream( unknownShort4, out, version ); \
NifStream( unknownVector, out, version ); \
NifStream( unknownFloat2, out, version ); \

#define BHK_BOX_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Short 1:  " << unknownShort1 << endl; \
out << "     Unknown Short 2:  " << unknownShort2 << endl; \
out << "     Unknown Short 3:  " << unknownShort3 << endl; \
out << "     Unknown Short 4:  " << unknownShort4 << endl; \
out << "      Unknown Vector:  " << unknownVector << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
return out.str(); \

// 
// A capsule.
//
// - Unknown.
// - Apparently the capsule's radius.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown. Matches Radius.
// - Unknown.
// - Unknown. Matches Radius.
#define BHK_CAPSULE_SHAPE_MEMBERS \
uint unknownInt1; \
float radius; \
ushort unknownShort1; \
ushort unknownShort2; \
ushort unknownShort3; \
ushort unknownShort4; \
Vector3 unknownVector1; \
float radius1; \
Vector3 unknownVector2; \
float radius2; \

#define BHK_CAPSULE_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
if ( attr_name == "Radius" ) \
  return attr_ref(radius); \
if ( attr_name == "Unknown Short 1" ) \
  return attr_ref(unknownShort1); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknownShort2); \
if ( attr_name == "Unknown Short 3" ) \
  return attr_ref(unknownShort3); \
if ( attr_name == "Unknown Short 4" ) \
  return attr_ref(unknownShort4); \
if ( attr_name == "Unknown Vector 1" ) \
  return attr_ref(unknownVector1); \
if ( attr_name == "Radius 1" ) \
  return attr_ref(radius1); \
if ( attr_name == "Unknown Vector 2" ) \
  return attr_ref(unknownVector2); \
if ( attr_name == "Radius 2" ) \
  return attr_ref(radius2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_CAPSULE_SHAPE_PARENTS AbhkShape

#define BHK_CAPSULE_SHAPE_CONSTRUCT

#define BHK_CAPSULE_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( unknownInt1, in, version ); \
NifStream( radius, in, version ); \
NifStream( unknownShort1, in, version ); \
NifStream( unknownShort2, in, version ); \
NifStream( unknownShort3, in, version ); \
NifStream( unknownShort4, in, version ); \
NifStream( unknownVector1, in, version ); \
NifStream( radius1, in, version ); \
NifStream( unknownVector2, in, version ); \
NifStream( radius2, in, version ); \

#define BHK_CAPSULE_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( unknownInt1, out, version ); \
NifStream( radius, out, version ); \
NifStream( unknownShort1, out, version ); \
NifStream( unknownShort2, out, version ); \
NifStream( unknownShort3, out, version ); \
NifStream( unknownShort4, out, version ); \
NifStream( unknownVector1, out, version ); \
NifStream( radius1, out, version ); \
NifStream( unknownVector2, out, version ); \
NifStream( radius2, out, version ); \

#define BHK_CAPSULE_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "              Radius:  " << radius << endl; \
out << "     Unknown Short 1:  " << unknownShort1 << endl; \
out << "     Unknown Short 2:  " << unknownShort2 << endl; \
out << "     Unknown Short 3:  " << unknownShort3 << endl; \
out << "     Unknown Short 4:  " << unknownShort4 << endl; \
out << "    Unknown Vector 1:  " << unknownVector1 << endl; \
out << "            Radius 1:  " << radius1 << endl; \
out << "    Unknown Vector 2:  " << unknownVector2 << endl; \
out << "            Radius 2:  " << radius2 << endl; \
return out.str(); \

// 
// Unknown.
//
#define BHK_COLLISION_OBJECT_MEMBERS \

#define BHK_COLLISION_OBJECT_GETATTR \
attr_ref attr = ACollisionObject::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_COLLISION_OBJECT_PARENTS ACollisionObject

#define BHK_COLLISION_OBJECT_CONSTRUCT

#define BHK_COLLISION_OBJECT_READ \
ACollisionObject::Read( in, version ); \

#define BHK_COLLISION_OBJECT_WRITE \
ACollisionObject::Write( out, version ); \

#define BHK_COLLISION_OBJECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ACollisionObject::asString(); \
return out.str(); \

// 
// A convex transformed shape?
//
#define BHK_CONVEX_TRANSFORM_SHAPE_MEMBERS \

#define BHK_CONVEX_TRANSFORM_SHAPE_GETATTR \
attr_ref attr = AbhkTransformShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_CONVEX_TRANSFORM_SHAPE_PARENTS AbhkTransformShape

#define BHK_CONVEX_TRANSFORM_SHAPE_CONSTRUCT

#define BHK_CONVEX_TRANSFORM_SHAPE_READ \
AbhkTransformShape::Read( in, version ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_WRITE \
AbhkTransformShape::Write( out, version ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkTransformShape::asString(); \
return out.str(); \

// 
// A convex shape built from vertices?
//
// - Unknown.
// - Unknown.
// - Unknown. Vertices?
// - Unknown. More vertices?
#define BHK_CONVEX_VERTICES_SHAPE_MEMBERS \
uint unknownInt; \
vector<float > unknownFloats1; \
vector<Float4 > unknownVectors1; \
vector<Float4 > unknownVectors2; \

#define BHK_CONVEX_VERTICES_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_CONVEX_VERTICES_SHAPE_PARENTS AbhkShape

#define BHK_CONVEX_VERTICES_SHAPE_CONSTRUCT

#define BHK_CONVEX_VERTICES_SHAPE_READ \
uint num1; \
uint num2; \
AbhkShape::Read( in, version ); \
NifStream( unknownInt, in, version ); \
unknownFloats1.resize(7); \
NifStream( unknownFloats1, in, version ); \
NifStream( num1, in, version ); \
unknownVectors1.resize(num1); \
NifStream( unknownVectors1, in, version ); \
NifStream( num2, in, version ); \
unknownVectors2.resize(num2); \
NifStream( unknownVectors2, in, version ); \

#define BHK_CONVEX_VERTICES_SHAPE_WRITE \
uint num1; \
uint num2; \
AbhkShape::Write( out, version ); \
num1 = uint(unknownVectors1.size()); \
num2 = uint(unknownVectors2.size()); \
NifStream( unknownInt, out, version ); \
NifStream( unknownFloats1, out, version ); \
NifStream( num1, out, version ); \
NifStream( unknownVectors1, out, version ); \
NifStream( num2, out, version ); \
NifStream( unknownVectors2, out, version ); \

#define BHK_CONVEX_VERTICES_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "               Num 1:  -- calculated --" << endl; \
out << "   Unknown Vectors 1:  -- data not shown --" << endl; \
out << "               Num 2:  -- calculated --" << endl; \
out << "   Unknown Vectors 2:  -- data not shown --" << endl; \
return out.str(); \

// 
// A hinge constraint.
//
// - Unknown.
#define BHK_HINGE_CONSTRAINT_MEMBERS \
vector<vector<float > > unknownFloats; \

#define BHK_HINGE_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_HINGE_CONSTRAINT_PARENTS AbhkConstraint

#define BHK_HINGE_CONSTRAINT_CONSTRUCT

#define BHK_HINGE_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
unknownFloats.resize(5); \
NifStream( unknownFloats, in, version ); \

#define BHK_HINGE_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( unknownFloats, out, version ); \

#define BHK_HINGE_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkConstraint::asString(); \
out << "      Unknown Floats:  -- data not shown --" << endl; \
return out.str(); \

// 
// Hinge constraint.
//
// - Could also be a float. Zero usually.
#define BHK_LIMITED_HINGE_CONSTRAINT_MEMBERS \
uint unknownInt; \

#define BHK_LIMITED_HINGE_CONSTRAINT_GETATTR \
attr_ref attr = AbhkRagdollConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_LIMITED_HINGE_CONSTRAINT_PARENTS AbhkRagdollConstraint

#define BHK_LIMITED_HINGE_CONSTRAINT_CONSTRUCT

#define BHK_LIMITED_HINGE_CONSTRAINT_READ \
AbhkRagdollConstraint::Read( in, version ); \
NifStream( unknownInt, in, version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_WRITE \
AbhkRagdollConstraint::Write( out, version ); \
NifStream( unknownInt, out, version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkRagdollConstraint::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
return out.str(); \

// 
// A list of shapes.
//
// - List of shapes.
// - Unknown.
// - Unknown.
// - Unknown.
#define BHK_LIST_SHAPE_MEMBERS \
LinkGroup subShapes; \
uint unknownInt; \
vector<float > unknownFloats; \
vector<uint > unknownInts; \

#define BHK_LIST_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_LIST_SHAPE_PARENTS AbhkShape

#define BHK_LIST_SHAPE_CONSTRUCT

#define BHK_LIST_SHAPE_READ \
uint numUnknownInts; \
AbhkShape::Read( in, version ); \
NifStream( subShapes, in, version ); \
NifStream( unknownInt, in, version ); \
unknownFloats.resize(6); \
NifStream( unknownFloats, in, version ); \
NifStream( numUnknownInts, in, version ); \
unknownInts.resize(numUnknownInts); \
NifStream( unknownInts, in, version ); \

#define BHK_LIST_SHAPE_WRITE \
uint numUnknownInts; \
AbhkShape::Write( out, version ); \
numUnknownInts = uint(unknownInts.size()); \
NifStream( subShapes, out, version ); \
NifStream( unknownInt, out, version ); \
NifStream( unknownFloats, out, version ); \
NifStream( numUnknownInts, out, version ); \
NifStream( unknownInts, out, version ); \

#define BHK_LIST_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "          Sub Shapes:  " << subShapes << endl; \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "    Num Unknown Ints:  -- calculated --" << endl; \
out << "        Unknown Ints:  -- data not shown --" << endl; \
return out.str(); \

// 
// A malleable constraint.
//
// - Type of constraint.
// - Unknown.
// - Usually -1?
// - Usually -1?
// - Unknown. 1?
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define BHK_MALLEABLE_CONSTRAINT_MEMBERS \
uint type; \
uint unknownInt2; \
Link unknownLink1; \
Link unknownLink2; \
uint unknownInt3; \
vector<float > unknownFloats1; \
vector<vector<float > > unknownFloats; \
float unknownFloat1; \
float unknownFloat2; \

#define BHK_MALLEABLE_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Type" ) \
  return attr_ref(type); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
if ( attr_name == "Unknown Link 1" ) \
  return attr_ref(unknownLink1); \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknownLink2); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknownInt3); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_MALLEABLE_CONSTRAINT_PARENTS AbhkConstraint

#define BHK_MALLEABLE_CONSTRAINT_CONSTRUCT

#define BHK_MALLEABLE_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
NifStream( type, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( unknownLink1, in, version ); \
NifStream( unknownLink2, in, version ); \
NifStream( unknownInt3, in, version ); \
unknownFloats1.resize(3); \
NifStream( unknownFloats1, in, version ); \
unknownFloats.resize(7); \
NifStream( unknownFloats, in, version ); \
NifStream( unknownFloat1, in, version ); \
if ( type == 2 ) { \
  NifStream( unknownFloat2, in, version ); \
}; \

#define BHK_MALLEABLE_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( type, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( unknownLink1, out, version ); \
NifStream( unknownLink2, out, version ); \
NifStream( unknownInt3, out, version ); \
NifStream( unknownFloats1, out, version ); \
NifStream( unknownFloats, out, version ); \
NifStream( unknownFloat1, out, version ); \
if ( type == 2 ) { \
  NifStream( unknownFloat2, out, version ); \
}; \

#define BHK_MALLEABLE_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkConstraint::asString(); \
out << "                Type:  " << type << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
out << "      Unknown Link 1:  " << unknownLink1 << endl; \
out << "      Unknown Link 2:  " << unknownLink2 << endl; \
out << "       Unknown Int 3:  " << unknownInt3 << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Links to another shape.
// - Unknown. 0?
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define BHK_MOPP_BV_TREE_SHAPE_MEMBERS \
Link shape; \
uint unknownInt; \
vector<byte > unknownBytes1; \
float unknownFloat; \
vector<byte > unknownBytes2; \
vector<float > unknownFloats; \

#define BHK_MOPP_BV_TREE_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Shape" ) \
  return attr_ref(shape); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknownFloat); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_MOPP_BV_TREE_SHAPE_PARENTS AbhkShape

#define BHK_MOPP_BV_TREE_SHAPE_CONSTRUCT

#define BHK_MOPP_BV_TREE_SHAPE_READ \
uint numUnknownBytes2; \
AbhkShape::Read( in, version ); \
NifStream( shape, in, version ); \
NifStream( unknownInt, in, version ); \
unknownBytes1.resize(8); \
NifStream( unknownBytes1, in, version ); \
NifStream( unknownFloat, in, version ); \
NifStream( numUnknownBytes2, in, version ); \
unknownBytes2.resize(numUnknownBytes2); \
NifStream( unknownBytes2, in, version ); \
unknownFloats.resize(4); \
NifStream( unknownFloats, in, version ); \

#define BHK_MOPP_BV_TREE_SHAPE_WRITE \
uint numUnknownBytes2; \
AbhkShape::Write( out, version ); \
numUnknownBytes2 = uint(unknownBytes2.size()); \
NifStream( shape, out, version ); \
NifStream( unknownInt, out, version ); \
NifStream( unknownBytes1, out, version ); \
NifStream( unknownFloat, out, version ); \
NifStream( numUnknownBytes2, out, version ); \
NifStream( unknownBytes2, out, version ); \
NifStream( unknownFloats, out, version ); \

#define BHK_MOPP_BV_TREE_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "               Shape:  " << shape << endl; \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "     Unknown Bytes 1:  -- data not shown --" << endl; \
out << "       Unknown Float:  " << unknownFloat << endl; \
out << " Num Unknown Bytes 2:  -- calculated --" << endl; \
out << "     Unknown Bytes 2:  -- data not shown --" << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define BHK_MULTI_SPHERE_SHAPE_MEMBERS \
uint unknownInt; \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
uint unknownInt2; \
vector<float > unknownFloats; \

#define BHK_MULTI_SPHERE_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknownFloat3); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_MULTI_SPHERE_SHAPE_PARENTS AbhkShape

#define BHK_MULTI_SPHERE_SHAPE_CONSTRUCT

#define BHK_MULTI_SPHERE_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( unknownInt, in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownInt2, in, version ); \
unknownFloats.resize(8); \
NifStream( unknownFloats, in, version ); \

#define BHK_MULTI_SPHERE_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( unknownInt, out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( unknownFloats, out, version ); \

#define BHK_MULTI_SPHERE_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "     Unknown Float 3:  " << unknownFloat3 << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
return out.str(); \

// 
// A shape constructed from a bunch of strips.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Refers to a bunch of NiTriStripsData blocks that make up this shape.
// - Unknown.
#define BHK_NI_TRI_STRIPS_SHAPE_MEMBERS \
uint unknownInt; \
vector<float > unknownFloats1; \
vector<uint > unknownInts1; \
vector<float > unknownFloats2; \
uint unknownInt2; \
LinkGroup strips; \
vector<uint > unknownInts3; \

#define BHK_NI_TRI_STRIPS_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_NI_TRI_STRIPS_SHAPE_PARENTS AbhkShape

#define BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT

#define BHK_NI_TRI_STRIPS_SHAPE_READ \
uint numUnknownInts3; \
AbhkShape::Read( in, version ); \
NifStream( unknownInt, in, version ); \
unknownFloats1.resize(2); \
NifStream( unknownFloats1, in, version ); \
unknownInts1.resize(5); \
NifStream( unknownInts1, in, version ); \
unknownFloats2.resize(3); \
NifStream( unknownFloats2, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( strips, in, version ); \
NifStream( numUnknownInts3, in, version ); \
unknownInts3.resize(numUnknownInts3); \
NifStream( unknownInts3, in, version ); \

#define BHK_NI_TRI_STRIPS_SHAPE_WRITE \
uint numUnknownInts3; \
AbhkShape::Write( out, version ); \
numUnknownInts3 = uint(unknownInts3.size()); \
NifStream( unknownInt, out, version ); \
NifStream( unknownFloats1, out, version ); \
NifStream( unknownInts1, out, version ); \
NifStream( unknownFloats2, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( strips, out, version ); \
NifStream( numUnknownInts3, out, version ); \
NifStream( unknownInts3, out, version ); \

#define BHK_NI_TRI_STRIPS_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "      Unknown Ints 1:  -- data not shown --" << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
out << "              Strips:  " << strips << endl; \
out << "  Num Unknown Ints 3:  -- calculated --" << endl; \
out << "      Unknown Ints 3:  -- data not shown --" << endl; \
return out.str(); \

// 
// A shape constructed from strips data.
//
// - Unknown.
// - Unknown.
// - A link to the shape's NiTriStripsData.
#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_MEMBERS \
vector<vector<uint > > unknownInts; \
vector<float > unknownFloats; \
Link data; \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENTS AbhkShape

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_CONSTRUCT

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_READ \
ushort numUnknownInts; \
AbhkShape::Read( in, version ); \
NifStream( numUnknownInts, in, version ); \
unknownInts.resize(numUnknownInts); \
NifStream( unknownInts, in, version ); \
unknownFloats.resize(13); \
NifStream( unknownFloats, in, version ); \
NifStream( data, in, version ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_WRITE \
ushort numUnknownInts; \
AbhkShape::Write( out, version ); \
numUnknownInts = ushort(unknownInts.size()); \
NifStream( numUnknownInts, out, version ); \
NifStream( unknownInts, out, version ); \
NifStream( unknownFloats, out, version ); \
NifStream( data, out, version ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "    Num Unknown Ints:  -- calculated --" << endl; \
out << "        Unknown Ints:  -- data not shown --" << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// A prismatic constraint.
//
// - Unknown.
// - Unknown.
#define BHK_PRISMATIC_CONSTRAINT_MEMBERS \
vector<vector<float > > unknownFloats; \
vector<float > unknownFloats2; \

#define BHK_PRISMATIC_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_PRISMATIC_CONSTRAINT_PARENTS AbhkConstraint

#define BHK_PRISMATIC_CONSTRAINT_CONSTRUCT

#define BHK_PRISMATIC_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
unknownFloats.resize(8); \
NifStream( unknownFloats, in, version ); \
unknownFloats2.resize(3); \
NifStream( unknownFloats2, in, version ); \

#define BHK_PRISMATIC_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( unknownFloats, out, version ); \
NifStream( unknownFloats2, out, version ); \

#define BHK_PRISMATIC_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkConstraint::asString(); \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
return out.str(); \

// 
// Ragdoll constraint.
//
#define BHK_RAGDOLL_CONSTRAINT_MEMBERS \

#define BHK_RAGDOLL_CONSTRAINT_GETATTR \
attr_ref attr = AbhkRagdollConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_RAGDOLL_CONSTRAINT_PARENTS AbhkRagdollConstraint

#define BHK_RAGDOLL_CONSTRAINT_CONSTRUCT

#define BHK_RAGDOLL_CONSTRAINT_READ \
AbhkRagdollConstraint::Read( in, version ); \

#define BHK_RAGDOLL_CONSTRAINT_WRITE \
AbhkRagdollConstraint::Write( out, version ); \

#define BHK_RAGDOLL_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkRagdollConstraint::asString(); \
return out.str(); \

// 
// Unknown.
//
#define BHK_RIGID_BODY_MEMBERS \

#define BHK_RIGID_BODY_GETATTR \
attr_ref attr = AbhkRigidBody::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_RIGID_BODY_PARENTS AbhkRigidBody

#define BHK_RIGID_BODY_CONSTRUCT

#define BHK_RIGID_BODY_READ \
AbhkRigidBody::Read( in, version ); \

#define BHK_RIGID_BODY_WRITE \
AbhkRigidBody::Write( out, version ); \

#define BHK_RIGID_BODY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkRigidBody::asString(); \
return out.str(); \

// 
// Unknown.
//
#define BHK_RIGID_BODY_T_MEMBERS \

#define BHK_RIGID_BODY_T_GETATTR \
attr_ref attr = AbhkRigidBody::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_RIGID_BODY_T_PARENTS AbhkRigidBody

#define BHK_RIGID_BODY_T_CONSTRUCT

#define BHK_RIGID_BODY_T_READ \
AbhkRigidBody::Read( in, version ); \

#define BHK_RIGID_BODY_T_WRITE \
AbhkRigidBody::Write( out, version ); \

#define BHK_RIGID_BODY_T_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkRigidBody::asString(); \
return out.str(); \

// 
// Unknown shape.
//
// - Link to a shape.
// - Unknown.
// - Unknown.
// - Unknown. (1,0,0,0,0) x 3.
// - Unknown.
#define BHK_SIMPLE_SHAPE_PHANTOM_MEMBERS \
Link shape; \
uint unknownInt1; \
vector<float > unkownFloats; \
vector<vector<float > > unknownFloats2; \
float unknownFloat; \

#define BHK_SIMPLE_SHAPE_PHANTOM_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Shape" ) \
  return attr_ref(shape); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknownFloat); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_SIMPLE_SHAPE_PHANTOM_PARENTS AbhkShape

#define BHK_SIMPLE_SHAPE_PHANTOM_CONSTRUCT

#define BHK_SIMPLE_SHAPE_PHANTOM_READ \
AbhkShape::Read( in, version ); \
NifStream( shape, in, version ); \
NifStream( unknownInt1, in, version ); \
unkownFloats.resize(7); \
NifStream( unkownFloats, in, version ); \
unknownFloats2.resize(3); \
NifStream( unknownFloats2, in, version ); \
NifStream( unknownFloat, in, version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_WRITE \
AbhkShape::Write( out, version ); \
NifStream( shape, out, version ); \
NifStream( unknownInt1, out, version ); \
NifStream( unkownFloats, out, version ); \
NifStream( unknownFloats2, out, version ); \
NifStream( unknownFloat, out, version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "               Shape:  " << shape << endl; \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "       Unkown Floats:  -- data not shown --" << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
out << "       Unknown Float:  " << unknownFloat << endl; \
return out.str(); \

// 
// Unknown.
//
#define BHK_S_P_COLLISION_OBJECT_MEMBERS \

#define BHK_S_P_COLLISION_OBJECT_GETATTR \
attr_ref attr = ACollisionObject::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_S_P_COLLISION_OBJECT_PARENTS ACollisionObject

#define BHK_S_P_COLLISION_OBJECT_CONSTRUCT

#define BHK_S_P_COLLISION_OBJECT_READ \
ACollisionObject::Read( in, version ); \

#define BHK_S_P_COLLISION_OBJECT_WRITE \
ACollisionObject::Write( out, version ); \

#define BHK_S_P_COLLISION_OBJECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ACollisionObject::asString(); \
return out.str(); \

// 
// A sphere.
//
// - Unknown.
// - This denotes the radius of the sphere.
#define BHK_SPHERE_SHAPE_MEMBERS \
uint unknownInt; \
float radius; \

#define BHK_SPHERE_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
if ( attr_name == "Radius" ) \
  return attr_ref(radius); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_SPHERE_SHAPE_PARENTS AbhkShape

#define BHK_SPHERE_SHAPE_CONSTRUCT

#define BHK_SPHERE_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( unknownInt, in, version ); \
NifStream( radius, in, version ); \

#define BHK_SPHERE_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( unknownInt, out, version ); \
NifStream( radius, out, version ); \

#define BHK_SPHERE_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "              Radius:  " << radius << endl; \
return out.str(); \

// 
// A spring constraint.
//
// - Unknown.
// - Unknown.
#define BHK_STIFF_SPRING_CONSTRAINT_MEMBERS \
vector<vector<float > > unknownFloats; \
float unknownFloat; \

#define BHK_STIFF_SPRING_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknownFloat); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_STIFF_SPRING_CONSTRAINT_PARENTS AbhkConstraint

#define BHK_STIFF_SPRING_CONSTRAINT_CONSTRUCT

#define BHK_STIFF_SPRING_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
unknownFloats.resize(2); \
NifStream( unknownFloats, in, version ); \
NifStream( unknownFloat, in, version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( unknownFloats, out, version ); \
NifStream( unknownFloat, out, version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkConstraint::asString(); \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "       Unknown Float:  " << unknownFloat << endl; \
return out.str(); \

// 
// A transformed shape?
//
#define BHK_TRANSFORM_SHAPE_MEMBERS \

#define BHK_TRANSFORM_SHAPE_GETATTR \
attr_ref attr = AbhkTransformShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_TRANSFORM_SHAPE_PARENTS AbhkTransformShape

#define BHK_TRANSFORM_SHAPE_CONSTRUCT

#define BHK_TRANSFORM_SHAPE_READ \
AbhkTransformShape::Read( in, version ); \

#define BHK_TRANSFORM_SHAPE_WRITE \
AbhkTransformShape::Write( out, version ); \

#define BHK_TRANSFORM_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkTransformShape::asString(); \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown.
#define B_S_BOUND_MEMBERS \
string name; \
vector<float > unknownFloats; \

#define B_S_BOUND_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define B_S_BOUND_PARENTS AData

#define B_S_BOUND_CONSTRUCT

#define B_S_BOUND_READ \
AData::Read( in, version ); \
NifStream( name, in, version ); \
unknownFloats.resize(6); \
NifStream( unknownFloats, in, version ); \

#define B_S_BOUND_WRITE \
AData::Write( out, version ); \
NifStream( name, out, version ); \
NifStream( unknownFloats, out, version ); \

#define B_S_BOUND_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown. Marks furniture sitting positions?
//
// - Contains the string 'FRN'?
// - Unknown. Probably has something to do with the furniture positions?
#define B_S_FURNITURE_MARKER_MEMBERS \
string name; \
vector<FurniturePosition > positions; \

#define B_S_FURNITURE_MARKER_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define B_S_FURNITURE_MARKER_PARENTS AData

#define B_S_FURNITURE_MARKER_CONSTRUCT

#define B_S_FURNITURE_MARKER_READ \
uint numPositions; \
AData::Read( in, version ); \
if ( version <= 0x14000005 ) { \
  NifStream( name, in, version ); \
}; \
NifStream( numPositions, in, version ); \
positions.resize(numPositions); \
NifStream( positions, in, version ); \

#define B_S_FURNITURE_MARKER_WRITE \
uint numPositions; \
AData::Write( out, version ); \
numPositions = uint(positions.size()); \
if ( version <= 0x14000005 ) { \
  NifStream( name, out, version ); \
}; \
NifStream( numPositions, out, version ); \
NifStream( positions, out, version ); \

#define B_S_FURNITURE_MARKER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "       Num Positions:  -- calculated --" << endl; \
out << "           Positions:  -- data not shown --" << endl; \
return out.str(); \

// 
// An extended keyframe controller.
//
// - A link to more keyframe data.
#define B_S_KEYFRAME_CONTROLLER_MEMBERS \
Link data2; \

#define B_S_KEYFRAME_CONTROLLER_GETATTR \
attr_ref attr = AKeyframeController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data 2" ) \
  return attr_ref(data2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define B_S_KEYFRAME_CONTROLLER_PARENTS AKeyframeController

#define B_S_KEYFRAME_CONTROLLER_CONSTRUCT

#define B_S_KEYFRAME_CONTROLLER_READ \
AKeyframeController::Read( in, version ); \
NifStream( data2, in, version ); \

#define B_S_KEYFRAME_CONTROLLER_WRITE \
AKeyframeController::Write( out, version ); \
NifStream( data2, out, version ); \

#define B_S_KEYFRAME_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyframeController::asString(); \
out << "              Data 2:  " << data2 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
#define B_S_PARENT_VELOCITY_MODIFIER_MEMBERS \
float unknownFloat; \

#define B_S_PARENT_VELOCITY_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknownFloat); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define B_S_PARENT_VELOCITY_MODIFIER_PARENTS APSysModifier

#define B_S_PARENT_VELOCITY_MODIFIER_CONSTRUCT

#define B_S_PARENT_VELOCITY_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( unknownFloat, in, version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( unknownFloat, out, version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "       Unknown Float:  " << unknownFloat << endl; \
return out.str(); \

// 
// Unknown.
//
#define B_S_P_SYS_ARRAY_EMITTER_MEMBERS \

#define B_S_P_SYS_ARRAY_EMITTER_GETATTR \
attr_ref attr = APSysVolumeEmitter::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define B_S_P_SYS_ARRAY_EMITTER_PARENTS APSysVolumeEmitter

#define B_S_P_SYS_ARRAY_EMITTER_CONSTRUCT

#define B_S_P_SYS_ARRAY_EMITTER_READ \
APSysVolumeEmitter::Read( in, version ); \

#define B_S_P_SYS_ARRAY_EMITTER_WRITE \
APSysVolumeEmitter::Write( out, version ); \

#define B_S_P_SYS_ARRAY_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysVolumeEmitter::asString(); \
return out.str(); \

// 
// Unknown.
//
// - The string 'BSX'?
// - The flags.
#define B_S_X_FLAGS_MEMBERS \
string name; \
uint flags; \

#define B_S_X_FLAGS_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define B_S_X_FLAGS_PARENTS AData

#define B_S_X_FLAGS_CONSTRUCT name(BSX)

#define B_S_X_FLAGS_READ \
AData::Read( in, version ); \
NifStream( name, in, version ); \
NifStream( flags, in, version ); \

#define B_S_X_FLAGS_WRITE \
AData::Write( out, version ); \
NifStream( name, out, version ); \
NifStream( flags, out, version ); \

#define B_S_X_FLAGS_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "               Flags:  " << flags << endl; \
return out.str(); \

// 
// Unknown.
//
#define FX_BUTTON_MEMBERS \

#define FX_BUTTON_GETATTR \
attr_ref attr = AFx::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define FX_BUTTON_PARENTS AFx

#define FX_BUTTON_CONSTRUCT

#define FX_BUTTON_READ \
AFx::Read( in, version ); \

#define FX_BUTTON_WRITE \
AFx::Write( out, version ); \

#define FX_BUTTON_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AFx::asString(); \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown links; options of the radio button?
#define FX_RADIO_BUTTON_MEMBERS \
uint unknownInt1; \
uint unknownInt2; \
uint unknownInt3; \
LinkGroup unknownLinks; \

#define FX_RADIO_BUTTON_GETATTR \
attr_ref attr = AFx::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
if ( attr_name == "Unknown Int  2" ) \
  return attr_ref(unknownInt2); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknownInt3); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define FX_RADIO_BUTTON_PARENTS AFx

#define FX_RADIO_BUTTON_CONSTRUCT

#define FX_RADIO_BUTTON_READ \
AFx::Read( in, version ); \
NifStream( unknownInt1, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( unknownInt3, in, version ); \
NifStream( unknownLinks, in, version ); \

#define FX_RADIO_BUTTON_WRITE \
AFx::Write( out, version ); \
NifStream( unknownInt1, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( unknownInt3, out, version ); \
NifStream( unknownLinks, out, version ); \

#define FX_RADIO_BUTTON_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AFx::asString(); \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "      Unknown Int  2:  " << unknownInt2 << endl; \
out << "       Unknown Int 3:  " << unknownInt3 << endl; \
out << "       Unknown Links:  " << unknownLinks << endl; \
return out.str(); \

// 
// Unknown.
//
#define FX_WIDGET_MEMBERS \

#define FX_WIDGET_GETATTR \
attr_ref attr = AFx::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define FX_WIDGET_PARENTS AFx

#define FX_WIDGET_CONSTRUCT

#define FX_WIDGET_READ \
AFx::Read( in, version ); \

#define FX_WIDGET_WRITE \
AFx::Write( out, version ); \

#define FX_WIDGET_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AFx::asString(); \
return out.str(); \

// 
// NiTriStripsData for havok data?
//
// - The physics triangles?
// - The vertices?
#define HK_PACKED_NI_TRI_STRIPS_DATA_MEMBERS \
vector<hkTriangle > triangles; \
vector<Vector3 > vertices; \

#define HK_PACKED_NI_TRI_STRIPS_DATA_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_PARENTS AbhkShape

#define HK_PACKED_NI_TRI_STRIPS_DATA_CONSTRUCT

#define HK_PACKED_NI_TRI_STRIPS_DATA_READ \
uint numTriangles; \
uint numVertices; \
AbhkShape::Read( in, version ); \
NifStream( numTriangles, in, version ); \
triangles.resize(numTriangles); \
NifStream( triangles, in, version ); \
NifStream( numVertices, in, version ); \
vertices.resize(numVertices); \
NifStream( vertices, in, version ); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_WRITE \
uint numTriangles; \
uint numVertices; \
AbhkShape::Write( out, version ); \
numTriangles = uint(triangles.size()); \
numVertices = uint(vertices.size()); \
NifStream( numTriangles, out, version ); \
NifStream( triangles, out, version ); \
NifStream( numVertices, out, version ); \
NifStream( vertices, out, version ); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "       Num Triangles:  -- calculated --" << endl; \
out << "           Triangles:  -- data not shown --" << endl; \
out << "        Num Vertices:  -- calculated --" << endl; \
out << "            Vertices:  -- data not shown --" << endl; \
return out.str(); \

// 
// Time controller for transparency.
//
// - Alpha controller data index.
#define NI_ALPHA_CONTROLLER_MEMBERS \
Link data; \

#define NI_ALPHA_CONTROLLER_GETATTR \
attr_ref attr = ASingleInterpolatorController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_ALPHA_CONTROLLER_PARENTS ASingleInterpolatorController

#define NI_ALPHA_CONTROLLER_CONSTRUCT

#define NI_ALPHA_CONTROLLER_READ \
ASingleInterpolatorController::Read( in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( data, in, version ); \
}; \

#define NI_ALPHA_CONTROLLER_WRITE \
ASingleInterpolatorController::Write( out, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( data, out, version ); \
}; \

#define NI_ALPHA_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ASingleInterpolatorController::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Transparency. Flags 0x00ED.
//
// - Bit 0 : alpha blending enable
// Bits 1-4 : source blend mode
// Bits 5-8 : destination blend mode
// Bit 9 : alpha test enable
// Bit 10-12 : alpha test mode
// Bit 13 : Unknown ( 1 if test enabled ? )
// 
// blend modes (glBlendFunc):
// 0000 GL_ONE
// 0001 GL_ZERO
// 0010 GL_SRC_COLOR
// 0011 GL_ONE_MINUS_SRC_COLOR
// 0100 GL_DST_COLOR
// 0101 GL_ONE_MINUS_DST_COLOR
// 0110 GL_SRC_ALPHA
// 0111 GL_ONE_MINUS_SRC_ALPHA
// 1000 GL_DST_ALPHA
// 1001 GL_ONE_MINUS_DST_ALPHA
// 1010 GL_SRC_ALPHA_SATURATE
// 
// test modes (glAlphaFunc):
// 000 GL_ALWAYS
// 001 GL_LESS
// 010 GL_EQUAL
// 011 GL_LEQUAL
// 100 GL_GREATER
// 101 GL_NOTEQUAL
// 110 GL_GEQUAL
// 111 GL_NEVER
// - Threshold for alpha testing (see: glAlphaFunc)
#define NI_ALPHA_PROPERTY_MEMBERS \
Flags flags; \
byte threshold; \

#define NI_ALPHA_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Threshold" ) \
  return attr_ref(threshold); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_ALPHA_PROPERTY_PARENTS AProperty

#define NI_ALPHA_PROPERTY_CONSTRUCT flags(237)

#define NI_ALPHA_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \
NifStream( threshold, in, version ); \

#define NI_ALPHA_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \
NifStream( threshold, out, version ); \

#define NI_ALPHA_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "           Threshold:  " << threshold << endl; \
return out.str(); \

// 
// Ambient light source.
//
#define NI_AMBIENT_LIGHT_MEMBERS \

#define NI_AMBIENT_LIGHT_GETATTR \
attr_ref attr = ALight::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_AMBIENT_LIGHT_PARENTS ALight

#define NI_AMBIENT_LIGHT_CONSTRUCT

#define NI_AMBIENT_LIGHT_READ \
ALight::Read( in, version ); \

#define NI_AMBIENT_LIGHT_WRITE \
ALight::Write( out, version ); \

#define NI_AMBIENT_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ALight::asString(); \
return out.str(); \

// 
// Unknown.
//
#define NI_AUTO_NORMAL_PARTICLES_MEMBERS \

#define NI_AUTO_NORMAL_PARTICLES_GETATTR \
attr_ref attr = AParticleNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_AUTO_NORMAL_PARTICLES_PARENTS AParticleNode

#define NI_AUTO_NORMAL_PARTICLES_CONSTRUCT

#define NI_AUTO_NORMAL_PARTICLES_READ \
AParticleNode::Read( in, version ); \

#define NI_AUTO_NORMAL_PARTICLES_WRITE \
AParticleNode::Write( out, version ); \

#define NI_AUTO_NORMAL_PARTICLES_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleNode::asString(); \
return out.str(); \

// 
// Particle system data block (emits particles along vertex normals?).
//
#define NI_AUTO_NORMAL_PARTICLES_DATA_MEMBERS \

#define NI_AUTO_NORMAL_PARTICLES_DATA_GETATTR \
attr_ref attr = AParticlesData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_PARENTS AParticlesData

#define NI_AUTO_NORMAL_PARTICLES_DATA_CONSTRUCT

#define NI_AUTO_NORMAL_PARTICLES_DATA_READ \
AParticlesData::Read( in, version ); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_WRITE \
AParticlesData::Write( out, version ); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticlesData::asString(); \
return out.str(); \

// 
// These nodes will always be rotated to face the camera creating a billboard effect for any attached objects.
//
// - 0: ALWAYS_FACE_CAMERA
// 1: ROTATE_ABOUT_UP
// 2: RIGID_FACE_CAMERA
// 3: ALWAYS_FACE_CENTER
// 4: RIGID_FACE_CENTER
#define NI_BILLBOARD_NODE_MEMBERS \
ushort billboardMode; \

#define NI_BILLBOARD_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Billboard Mode" ) \
  return attr_ref(billboardMode); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BILLBOARD_NODE_PARENTS AParentNode

#define NI_BILLBOARD_NODE_CONSTRUCT

#define NI_BILLBOARD_NODE_READ \
AParentNode::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( billboardMode, in, version ); \
}; \

#define NI_BILLBOARD_NODE_WRITE \
AParentNode::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( billboardMode, out, version ); \
}; \

#define NI_BILLBOARD_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
out << "      Billboard Mode:  " << billboardMode << endl; \
return out.str(); \

// 
// Binary extra data block. Used to store normals and binormals in Oblivion.
//
// - The binary data.
#define NI_BINARY_EXTRA_DATA_MEMBERS \
ByteArray binaryData; \

#define NI_BINARY_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BINARY_EXTRA_DATA_PARENTS AExtraData

#define NI_BINARY_EXTRA_DATA_CONSTRUCT

#define NI_BINARY_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( binaryData, in, version ); \

#define NI_BINARY_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( binaryData, out, version ); \

#define NI_BINARY_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "         Binary Data:  " << binaryData << endl; \
return out.str(); \

// 
// An interpolator for a bool.
//
// - The interpolated bool?
#define NI_BLEND_BOOL_INTERPOLATOR_MEMBERS \
byte bool; \

#define NI_BLEND_BOOL_INTERPOLATOR_GETATTR \
attr_ref attr = ABlendInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Bool" ) \
  return attr_ref(bool); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BLEND_BOOL_INTERPOLATOR_PARENTS ABlendInterpolator

#define NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT

#define NI_BLEND_BOOL_INTERPOLATOR_READ \
ABlendInterpolator::Read( in, version ); \
NifStream( bool, in, version ); \

#define NI_BLEND_BOOL_INTERPOLATOR_WRITE \
ABlendInterpolator::Write( out, version ); \
NifStream( bool, out, version ); \

#define NI_BLEND_BOOL_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABlendInterpolator::asString(); \
out << "                Bool:  " << bool << endl; \
return out.str(); \

// 
// An interpolator for a float.
//
// - The interpolated float?
#define NI_BLEND_FLOAT_INTERPOLATOR_MEMBERS \
float float; \

#define NI_BLEND_FLOAT_INTERPOLATOR_GETATTR \
attr_ref attr = ABlendInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Float" ) \
  return attr_ref(float); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BLEND_FLOAT_INTERPOLATOR_PARENTS ABlendInterpolator

#define NI_BLEND_FLOAT_INTERPOLATOR_CONSTRUCT

#define NI_BLEND_FLOAT_INTERPOLATOR_READ \
ABlendInterpolator::Read( in, version ); \
NifStream( float, in, version ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_WRITE \
ABlendInterpolator::Write( out, version ); \
NifStream( float, out, version ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABlendInterpolator::asString(); \
out << "               Float:  " << float << endl; \
return out.str(); \

// 
// Interpolates a point?
//
// - The interpolated point?
#define NI_BLEND_POINT3_INTERPOLATOR_MEMBERS \
Vector3 point; \

#define NI_BLEND_POINT3_INTERPOLATOR_GETATTR \
attr_ref attr = ABlendInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Point" ) \
  return attr_ref(point); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BLEND_POINT3_INTERPOLATOR_PARENTS ABlendInterpolator

#define NI_BLEND_POINT3_INTERPOLATOR_CONSTRUCT

#define NI_BLEND_POINT3_INTERPOLATOR_READ \
ABlendInterpolator::Read( in, version ); \
NifStream( point, in, version ); \

#define NI_BLEND_POINT3_INTERPOLATOR_WRITE \
ABlendInterpolator::Write( out, version ); \
NifStream( point, out, version ); \

#define NI_BLEND_POINT3_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABlendInterpolator::asString(); \
out << "               Point:  " << point << endl; \
return out.str(); \

// 
// Unknown.
//
#define NI_BLEND_TRANSFORM_INTERPOLATOR_MEMBERS \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_GETATTR \
attr_ref attr = ABlendInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_PARENTS ABlendInterpolator

#define NI_BLEND_TRANSFORM_INTERPOLATOR_CONSTRUCT

#define NI_BLEND_TRANSFORM_INTERPOLATOR_READ \
ABlendInterpolator::Read( in, version ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_WRITE \
ABlendInterpolator::Write( out, version ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABlendInterpolator::asString(); \
return out.str(); \

// 
// A LOD controller for bones?
//
// - List of shape groups.
// - Group of NiTriShape indices.
#define NI_BONE_L_O_D_CONTROLLER_MEMBERS \
vector<SkinShapeGroup > shapeGroups1; \
LinkGroup shapeGroups2; \

#define NI_BONE_L_O_D_CONTROLLER_GETATTR \
attr_ref attr = ABoneLODController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BONE_L_O_D_CONTROLLER_PARENTS ABoneLODController

#define NI_BONE_L_O_D_CONTROLLER_CONSTRUCT

#define NI_BONE_L_O_D_CONTROLLER_READ \
uint numShapeGroups; \
ABoneLODController::Read( in, version ); \
NifStream( numShapeGroups, in, version ); \
shapeGroups1.resize(numShapeGroups); \
NifStream( shapeGroups1, in, version ); \
NifStream( shapeGroups2, in, version ); \

#define NI_BONE_L_O_D_CONTROLLER_WRITE \
uint numShapeGroups; \
ABoneLODController::Write( out, version ); \
numShapeGroups = uint(shapeGroups1.size()); \
NifStream( numShapeGroups, out, version ); \
NifStream( shapeGroups1, out, version ); \
NifStream( shapeGroups2, out, version ); \

#define NI_BONE_L_O_D_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABoneLODController::asString(); \
out << "    Num Shape Groups:  -- calculated --" << endl; \
out << "      Shape Groups 1:  -- data not shown --" << endl; \
out << "      Shape Groups 2:  " << shapeGroups2 << endl; \
return out.str(); \

// 
// Timed boolean data.
//
// - The boolean keys.
#define NI_BOOL_DATA_MEMBERS \
VectorKeyArray<byte > data; \

#define NI_BOOL_DATA_GETATTR \
attr_ref attr = AKeyedData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BOOL_DATA_PARENTS AKeyedData

#define NI_BOOL_DATA_CONSTRUCT

#define NI_BOOL_DATA_READ \
AKeyedData::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_BOOL_DATA_WRITE \
AKeyedData::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_BOOL_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyedData::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Boolean extra data.
//
// - The boolean extra data value.
#define NI_BOOLEAN_EXTRA_DATA_MEMBERS \
byte booleanData; \

#define NI_BOOLEAN_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Boolean Data" ) \
  return attr_ref(booleanData); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BOOLEAN_EXTRA_DATA_PARENTS AExtraData

#define NI_BOOLEAN_EXTRA_DATA_CONSTRUCT

#define NI_BOOLEAN_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( booleanData, in, version ); \

#define NI_BOOLEAN_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( booleanData, out, version ); \

#define NI_BOOLEAN_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "        Boolean Data:  " << booleanData << endl; \
return out.str(); \

// 
// Unknown.
//
// - Value when posed?  At time 0?
// - Refers to a NiBoolData block.
#define NI_BOOL_INTERPOLATOR_MEMBERS \
bool boolValue; \
Link data; \

#define NI_BOOL_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Bool Value" ) \
  return attr_ref(boolValue); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BOOL_INTERPOLATOR_PARENTS AInterpolator

#define NI_BOOL_INTERPOLATOR_CONSTRUCT

#define NI_BOOL_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( boolValue, in, version ); \
NifStream( data, in, version ); \

#define NI_BOOL_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( boolValue, out, version ); \
NifStream( data, out, version ); \

#define NI_BOOL_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "          Bool Value:  " << boolValue << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Unknown.
//
// - The interpolated bool?
// - The bool data.
#define NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS \
byte bool; \
Link data; \

#define NI_BOOL_TIMELINE_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Bool" ) \
  return attr_ref(bool); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_PARENTS AInterpolator

#define NI_BOOL_TIMELINE_INTERPOLATOR_CONSTRUCT

#define NI_BOOL_TIMELINE_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( bool, in, version ); \
NifStream( data, in, version ); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( bool, out, version ); \
NifStream( data, out, version ); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "                Bool:  " << bool << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Node for animated objects without armature.
//
#define NI_B_S_ANIMATION_NODE_MEMBERS \

#define NI_B_S_ANIMATION_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_S_ANIMATION_NODE_PARENTS AParentNode

#define NI_B_S_ANIMATION_NODE_CONSTRUCT

#define NI_B_S_ANIMATION_NODE_READ \
AParentNode::Read( in, version ); \

#define NI_B_S_ANIMATION_NODE_WRITE \
AParentNode::Write( out, version ); \

#define NI_B_S_ANIMATION_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
return out.str(); \

// 
// A simple LOD controller for bones.
//
#define NI_B_S_BONE_L_O_D_CONTROLLER_MEMBERS \

#define NI_B_S_BONE_L_O_D_CONTROLLER_GETATTR \
attr_ref attr = ABoneLODController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_PARENTS ABoneLODController

#define NI_B_S_BONE_L_O_D_CONTROLLER_CONSTRUCT

#define NI_B_S_BONE_L_O_D_CONTROLLER_READ \
ABoneLODController::Read( in, version ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_WRITE \
ABoneLODController::Write( out, version ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABoneLODController::asString(); \
return out.str(); \

// 
// A particle system controller, used by BS in conjunction with NiBSParticleNode.
//
#define NI_B_S_P_ARRAY_CONTROLLER_MEMBERS \

#define NI_B_S_P_ARRAY_CONTROLLER_GETATTR \
attr_ref attr = AParticleSystemController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_S_P_ARRAY_CONTROLLER_PARENTS AParticleSystemController

#define NI_B_S_P_ARRAY_CONTROLLER_CONSTRUCT

#define NI_B_S_P_ARRAY_CONTROLLER_READ \
AParticleSystemController::Read( in, version ); \

#define NI_B_S_P_ARRAY_CONTROLLER_WRITE \
AParticleSystemController::Write( out, version ); \

#define NI_B_S_P_ARRAY_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleSystemController::asString(); \
return out.str(); \

// 
// Unknown.
//
#define NI_B_S_PARTICLE_NODE_MEMBERS \

#define NI_B_S_PARTICLE_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_S_PARTICLE_NODE_PARENTS AParentNode

#define NI_B_S_PARTICLE_NODE_CONSTRUCT

#define NI_B_S_PARTICLE_NODE_READ \
AParentNode::Read( in, version ); \

#define NI_B_S_PARTICLE_NODE_WRITE \
AParentNode::Write( out, version ); \

#define NI_B_S_PARTICLE_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
#define NI_B_SPLINE_BASIS_DATA_MEMBERS \
uint unknownInt; \

#define NI_B_SPLINE_BASIS_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_BASIS_DATA_PARENTS AData

#define NI_B_SPLINE_BASIS_DATA_CONSTRUCT

#define NI_B_SPLINE_BASIS_DATA_READ \
AData::Read( in, version ); \
NifStream( unknownInt, in, version ); \

#define NI_B_SPLINE_BASIS_DATA_WRITE \
AData::Write( out, version ); \
NifStream( unknownInt, out, version ); \

#define NI_B_SPLINE_BASIS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_MEMBERS \
vector<float > unknownFloats; \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_GETATTR \
attr_ref attr = ABSplineCompInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_PARENTS ABSplineCompInterpolator

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_CONSTRUCT

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_READ \
ABSplineCompInterpolator::Read( in, version ); \
unknownFloats.resize(6); \
NifStream( unknownFloats, in, version ); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_WRITE \
ABSplineCompInterpolator::Write( out, version ); \
NifStream( unknownFloats, out, version ); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABSplineCompInterpolator::asString(); \
out << "      Unknown Floats:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
// - Refers to NiBSplineData.
// - Unknown.
// - Unknown.
#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_MEMBERS \
Link data; \
Link unknownLink; \
vector<float > unknownFloats; \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_GETATTR \
attr_ref attr = ABSplineCompInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknownLink); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENTS ABSplineCompInterpolator

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_CONSTRUCT

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_READ \
ABSplineCompInterpolator::Read( in, version ); \
NifStream( data, in, version ); \
NifStream( unknownLink, in, version ); \
unknownFloats.resize(6); \
NifStream( unknownFloats, in, version ); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_WRITE \
ABSplineCompInterpolator::Write( out, version ); \
NifStream( data, out, version ); \
NifStream( unknownLink, out, version ); \
NifStream( unknownFloats, out, version ); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABSplineCompInterpolator::asString(); \
out << "                Data:  " << data << endl; \
out << "        Unknown Link:  " << unknownLink << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
// - Refers to NiBSplineData.
// - Refers to NiBSPlineBasisData.
// - Unknown.
#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS \
Link data; \
Link basisData; \
vector<float > unknown4; \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_GETATTR \
attr_ref attr = ABSplineCompInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Basis Data" ) \
  return attr_ref(basisData); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENTS ABSplineCompInterpolator

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_CONSTRUCT

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_READ \
ABSplineCompInterpolator::Read( in, version ); \
NifStream( data, in, version ); \
NifStream( basisData, in, version ); \
unknown4.resize(17); \
NifStream( unknown4, in, version ); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_WRITE \
ABSplineCompInterpolator::Write( out, version ); \
NifStream( data, out, version ); \
NifStream( basisData, out, version ); \
NifStream( unknown4, out, version ); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABSplineCompInterpolator::asString(); \
out << "                Data:  " << data << endl; \
out << "          Basis Data:  " << basisData << endl; \
out << "            Unknown4:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown. Zero?
// - Unknown data. Could be shorts or bytes or...
#define NI_B_SPLINE_DATA_MEMBERS \
uint unknownInt; \
vector<vector<byte > > unknownData; \

#define NI_B_SPLINE_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_DATA_PARENTS AData

#define NI_B_SPLINE_DATA_CONSTRUCT

#define NI_B_SPLINE_DATA_READ \
uint count; \
AData::Read( in, version ); \
NifStream( unknownInt, in, version ); \
NifStream( count, in, version ); \
unknownData.resize(count); \
NifStream( unknownData, in, version ); \

#define NI_B_SPLINE_DATA_WRITE \
uint count; \
AData::Write( out, version ); \
count = uint(unknownData.size()); \
NifStream( unknownInt, out, version ); \
NifStream( count, out, version ); \
NifStream( unknownData, out, version ); \

#define NI_B_SPLINE_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "               Count:  -- calculated --" << endl; \
out << "        Unknown Data:  -- data not shown --" << endl; \
return out.str(); \

// 
// Camera object.
//
// - Unknown.
// - Frustrum left.
// - Frustrum right.
// - Frustrum top.
// - Frustrum bottom.
// - Frustrum near.
// - Frustrum far.
// - Determines whether perspective is used.  Orthographic means no perspective.
// - Viewport left.
// - Viewport right.
// - Viewport top.
// - Viewport bottom.
// - Level of detail adjust.
// - Unknown.
// - Unknown.  Changing value crashes viewer.
// - Unknown.  Changing value crashes viewer.
#define NI_CAMERA_MEMBERS \
ushort unknownShort; \
float frustumLeft; \
float frustumRight; \
float frustumTop; \
float frustumBottom; \
float frustumNear; \
float frustumFar; \
bool useOrthographicProjection; \
float viewportLeft; \
float viewportRight; \
float viewportTop; \
float viewportBottom; \
float lodAdjust; \
Link unknownLink_; \
uint unknownInt; \
uint unknownInt2; \

#define NI_CAMERA_GETATTR \
attr_ref attr = ANode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Frustum Left" ) \
  return attr_ref(frustumLeft); \
if ( attr_name == "Frustum Right" ) \
  return attr_ref(frustumRight); \
if ( attr_name == "Frustum Top" ) \
  return attr_ref(frustumTop); \
if ( attr_name == "Frustum Bottom" ) \
  return attr_ref(frustumBottom); \
if ( attr_name == "Frustum Near" ) \
  return attr_ref(frustumNear); \
if ( attr_name == "Frustum Far" ) \
  return attr_ref(frustumFar); \
if ( attr_name == "Use Orthographic Projection" ) \
  return attr_ref(useOrthographicProjection); \
if ( attr_name == "Viewport Left" ) \
  return attr_ref(viewportLeft); \
if ( attr_name == "Viewport Right" ) \
  return attr_ref(viewportRight); \
if ( attr_name == "Viewport Top" ) \
  return attr_ref(viewportTop); \
if ( attr_name == "Viewport Bottom" ) \
  return attr_ref(viewportBottom); \
if ( attr_name == "LOD Adjust" ) \
  return attr_ref(lodAdjust); \
if ( attr_name == "Unknown Link?" ) \
  return attr_ref(unknownLink_); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_CAMERA_PARENTS ANode

#define NI_CAMERA_CONSTRUCT

#define NI_CAMERA_READ \
ANode::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknownShort, in, version ); \
}; \
NifStream( frustumLeft, in, version ); \
NifStream( frustumRight, in, version ); \
NifStream( frustumTop, in, version ); \
NifStream( frustumBottom, in, version ); \
NifStream( frustumNear, in, version ); \
NifStream( frustumFar, in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( useOrthographicProjection, in, version ); \
}; \
NifStream( viewportLeft, in, version ); \
NifStream( viewportRight, in, version ); \
NifStream( viewportTop, in, version ); \
NifStream( viewportBottom, in, version ); \
NifStream( lodAdjust, in, version ); \
NifStream( unknownLink_, in, version ); \
NifStream( unknownInt, in, version ); \
if ( version >= 0x04020100 ) { \
  NifStream( unknownInt2, in, version ); \
}; \

#define NI_CAMERA_WRITE \
ANode::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknownShort, out, version ); \
}; \
NifStream( frustumLeft, out, version ); \
NifStream( frustumRight, out, version ); \
NifStream( frustumTop, out, version ); \
NifStream( frustumBottom, out, version ); \
NifStream( frustumNear, out, version ); \
NifStream( frustumFar, out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( useOrthographicProjection, out, version ); \
}; \
NifStream( viewportLeft, out, version ); \
NifStream( viewportRight, out, version ); \
NifStream( viewportTop, out, version ); \
NifStream( viewportBottom, out, version ); \
NifStream( lodAdjust, out, version ); \
NifStream( unknownLink_, out, version ); \
NifStream( unknownInt, out, version ); \
if ( version >= 0x04020100 ) { \
  NifStream( unknownInt2, out, version ); \
}; \

#define NI_CAMERA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ANode::asString(); \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "        Frustum Left:  " << frustumLeft << endl; \
out << "       Frustum Right:  " << frustumRight << endl; \
out << "         Frustum Top:  " << frustumTop << endl; \
out << "      Frustum Bottom:  " << frustumBottom << endl; \
out << "        Frustum Near:  " << frustumNear << endl; \
out << "         Frustum Far:  " << frustumFar << endl; \
out << "Use Orthographic Projection:  " << useOrthographicProjection << endl; \
out << "       Viewport Left:  " << viewportLeft << endl; \
out << "      Viewport Right:  " << viewportRight << endl; \
out << "        Viewport Top:  " << viewportTop << endl; \
out << "     Viewport Bottom:  " << viewportBottom << endl; \
out << "          LOD Adjust:  " << lodAdjust << endl; \
out << "       Unknown Link?:  " << unknownLink_ << endl; \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
return out.str(); \

// 
// Collision box.
//
// - Index of the node referring to this collision data block.
// - Unknown.
// - Unknown.
// - Type of collision data.
// - Unknown.
// - Unknown (can be negative, so not necessarily a radius).
// - Unknown.
// - Unknown.
#define NI_COLLISION_DATA_MEMBERS \
uint targetNode; \
uint unknown2; \
byte unknown3; \
uint collisionType; \
uint unknown5; \
Vector3 unknown7; \
vector<float > unknown6; \
vector<float > unknown8; \

#define NI_COLLISION_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Target Node" ) \
  return attr_ref(targetNode); \
if ( attr_name == "Unknown2" ) \
  return attr_ref(unknown2); \
if ( attr_name == "Unknown3" ) \
  return attr_ref(unknown3); \
if ( attr_name == "Collision Type" ) \
  return attr_ref(collisionType); \
if ( attr_name == "Unknown5" ) \
  return attr_ref(unknown5); \
if ( attr_name == "Unknown7" ) \
  return attr_ref(unknown7); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_COLLISION_DATA_PARENTS AData

#define NI_COLLISION_DATA_CONSTRUCT

#define NI_COLLISION_DATA_READ \
AData::Read( in, version ); \
NifStream( targetNode, in, version ); \
NifStream( unknown2, in, version ); \
NifStream( unknown3, in, version ); \
NifStream( collisionType, in, version ); \
if ( collisionType == 0 ) { \
  NifStream( unknown5, in, version ); \
  NifStream( unknown7, in, version ); \
}; \
if ( collisionType == 2 ) { \
  unknown6.resize(8); \
  NifStream( unknown6, in, version ); \
}; \
if ( collisionType == 1 ) { \
  unknown8.resize(15); \
  NifStream( unknown8, in, version ); \
}; \

#define NI_COLLISION_DATA_WRITE \
AData::Write( out, version ); \
NifStream( targetNode, out, version ); \
NifStream( unknown2, out, version ); \
NifStream( unknown3, out, version ); \
NifStream( collisionType, out, version ); \
if ( collisionType == 0 ) { \
  NifStream( unknown5, out, version ); \
  NifStream( unknown7, out, version ); \
}; \
if ( collisionType == 2 ) { \
  NifStream( unknown6, out, version ); \
}; \
if ( collisionType == 1 ) { \
  NifStream( unknown8, out, version ); \
}; \

#define NI_COLLISION_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Target Node:  " << targetNode << endl; \
out << "            Unknown2:  " << unknown2 << endl; \
out << "            Unknown3:  " << unknown3 << endl; \
out << "      Collision Type:  " << collisionType << endl; \
out << "            Unknown5:  " << unknown5 << endl; \
out << "            Unknown7:  " << unknown7 << endl; \
out << "            Unknown6:  -- data not shown --" << endl; \
out << "            Unknown8:  -- data not shown --" << endl; \
return out.str(); \

// 
// Color data for material color controller.
//
// - The color keys.
#define NI_COLOR_DATA_MEMBERS \
VectorKeyArray<Color4 > data; \

#define NI_COLOR_DATA_GETATTR \
attr_ref attr = AKeyedData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_COLOR_DATA_PARENTS AKeyedData

#define NI_COLOR_DATA_CONSTRUCT

#define NI_COLOR_DATA_READ \
AKeyedData::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_COLOR_DATA_WRITE \
AKeyedData::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_COLOR_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyedData::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Unknown.
//
// - RGBA Color?
#define NI_COLOR_EXTRA_DATA_MEMBERS \
Color4 data; \

#define NI_COLOR_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_COLOR_EXTRA_DATA_PARENTS AExtraData

#define NI_COLOR_EXTRA_DATA_CONSTRUCT

#define NI_COLOR_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_COLOR_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_COLOR_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Unknown. Root of all controllers?
//
// - Unknown.
// - Refers to a list of NiControllerSequence blocks.
// - Refers to a NiDefaultAVObjectPalette.
#define NI_CONTROLLER_MANAGER_MEMBERS \
bool unknownByte; \
LinkGroup controllerSequences; \
Link objectPalette; \

#define NI_CONTROLLER_MANAGER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
if ( attr_name == "Object Palette" ) \
  return attr_ref(objectPalette); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_CONTROLLER_MANAGER_PARENTS AController

#define NI_CONTROLLER_MANAGER_CONSTRUCT

#define NI_CONTROLLER_MANAGER_READ \
AController::Read( in, version ); \
NifStream( unknownByte, in, version ); \
NifStream( controllerSequences, in, version ); \
NifStream( objectPalette, in, version ); \

#define NI_CONTROLLER_MANAGER_WRITE \
AController::Write( out, version ); \
NifStream( unknownByte, out, version ); \
NifStream( controllerSequences, out, version ); \
NifStream( objectPalette, out, version ); \

#define NI_CONTROLLER_MANAGER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "Controller Sequences:  " << controllerSequences << endl; \
out << "      Object Palette:  " << objectPalette << endl; \
return out.str(); \

// 
// Root node in .kf files (version 10.0.1.0 and up).
//
// - Name of this block. This is also the name of the action associated with this file. For instance, if the original NIF file is called "demon.nif" and this animation file contains an attack sequence, then the file would be called "demon_attack1.kf" and this field would contain the string "attack1".
// - Refers to a NiTextKeyExtraData block.
// - Unknown.
// - Refers to controlled blocks.
// - Unknown. 1.0?
// - Link to NiTextKeyExtraData. Replaces the other Text Keys field in versions 10.1.0.106 and up.
// - Unknown.
// - Unknown.
// - Unknown.
// - The controller sequence start time?
// - The controller sequence stop time?
// - Unknown.
// - Unknown.
// - Unknown. Could be a link.
// - Unknown.
// - Refers to NiStringPalette.
#define NI_CONTROLLER_SEQUENCE_MEMBERS \
string name; \
ControllerLink textKeys; \
uint unknownInt1; \
vector<ControllerLink > controlledBlocks; \
float unknownFloat1; \
Link textKeys2; \
uint unknownInt0; \
float unknownFloat3; \
float unknownFloat4; \
float startTime; \
float stopTime; \
float unknownFloat2; \
byte unknownByte; \
uint unknownInt3; \
string unknownString; \
Link stringPalette; \

#define NI_CONTROLLER_SEQUENCE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Text Keys 2" ) \
  return attr_ref(textKeys2); \
if ( attr_name == "Unknown Int 0" ) \
  return attr_ref(unknownInt0); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknownFloat3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknownFloat4); \
if ( attr_name == "Start Time" ) \
  return attr_ref(startTime); \
if ( attr_name == "Stop Time" ) \
  return attr_ref(stopTime); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknownInt3); \
if ( attr_name == "Unknown String" ) \
  return attr_ref(unknownString); \
if ( attr_name == "String Palette" ) \
  return attr_ref(stringPalette); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_CONTROLLER_SEQUENCE_PARENTS AData

#define NI_CONTROLLER_SEQUENCE_CONSTRUCT

#define NI_CONTROLLER_SEQUENCE_READ \
uint numControlledBlocks; \
AData::Read( in, version ); \
NifStream( name, in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( textKeys, in, version ); \
}; \
NifStream( numControlledBlocks, in, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownInt1, in, version ); \
}; \
controlledBlocks.resize(numControlledBlocks); \
NifStream( controlledBlocks, in, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownFloat1, in, version ); \
  NifStream( textKeys2, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknownInt0, in, version ); \
}; \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownFloat3, in, version ); \
  NifStream( unknownFloat4, in, version ); \
  NifStream( startTime, in, version ); \
  NifStream( stopTime, in, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x0A020000 ) ) { \
  NifStream( unknownFloat2, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknownByte, in, version ); \
}; \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownInt3, in, version ); \
  NifStream( unknownString, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( stringPalette, in, version ); \
}; \

#define NI_CONTROLLER_SEQUENCE_WRITE \
uint numControlledBlocks; \
AData::Write( out, version ); \
numControlledBlocks = uint(controlledBlocks.size()); \
NifStream( name, out, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( textKeys, out, version ); \
}; \
NifStream( numControlledBlocks, out, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownInt1, out, version ); \
}; \
NifStream( controlledBlocks, out, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownFloat1, out, version ); \
  NifStream( textKeys2, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknownInt0, out, version ); \
}; \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownFloat3, out, version ); \
  NifStream( unknownFloat4, out, version ); \
  NifStream( startTime, out, version ); \
  NifStream( stopTime, out, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x0A020000 ) ) { \
  NifStream( unknownFloat2, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknownByte, out, version ); \
}; \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownInt3, out, version ); \
  NifStream( unknownString, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( stringPalette, out, version ); \
}; \

#define NI_CONTROLLER_SEQUENCE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "           Text Keys:  " << textKeys << endl; \
out << "Num Controlled Blocks:  -- calculated --" << endl; \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "   Controlled Blocks:  -- data not shown --" << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "         Text Keys 2:  " << textKeys2 << endl; \
out << "       Unknown Int 0:  " << unknownInt0 << endl; \
out << "     Unknown Float 3:  " << unknownFloat3 << endl; \
out << "     Unknown Float 4:  " << unknownFloat4 << endl; \
out << "          Start Time:  " << startTime << endl; \
out << "           Stop Time:  " << stopTime << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "       Unknown Int 3:  " << unknownInt3 << endl; \
out << "      Unknown String:  " << unknownString << endl; \
out << "      String Palette:  " << stringPalette << endl; \
return out.str(); \

// 
// Unknown. Refers to a list of objects. Used by NiControllerManager.
//
// - Unknown.
// - The objects.
#define NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS \
uint unknownInt; \
vector<AVObject > objects; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_PARENTS AData

#define NI_DEFAULT_A_V_OBJECT_PALETTE_CONSTRUCT

#define NI_DEFAULT_A_V_OBJECT_PALETTE_READ \
uint numObjects; \
AData::Read( in, version ); \
NifStream( unknownInt, in, version ); \
NifStream( numObjects, in, version ); \
objects.resize(numObjects); \
NifStream( objects, in, version ); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_WRITE \
uint numObjects; \
AData::Write( out, version ); \
numObjects = uint(objects.size()); \
NifStream( unknownInt, out, version ); \
NifStream( numObjects, out, version ); \
NifStream( objects, out, version ); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "         Num Objects:  -- calculated --" << endl; \
out << "             Objects:  -- data not shown --" << endl; \
return out.str(); \

// 
// Directional light source.
//
#define NI_DIRECTIONAL_LIGHT_MEMBERS \

#define NI_DIRECTIONAL_LIGHT_GETATTR \
attr_ref attr = ALight::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_DIRECTIONAL_LIGHT_PARENTS ALight

#define NI_DIRECTIONAL_LIGHT_CONSTRUCT

#define NI_DIRECTIONAL_LIGHT_READ \
ALight::Read( in, version ); \

#define NI_DIRECTIONAL_LIGHT_WRITE \
ALight::Write( out, version ); \

#define NI_DIRECTIONAL_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ALight::asString(); \
return out.str(); \

// 
// Unknown.
//
// - 1's Bit: Enable dithering
#define NI_DITHER_PROPERTY_MEMBERS \
Flags flags; \

#define NI_DITHER_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_DITHER_PROPERTY_PARENTS AProperty

#define NI_DITHER_PROPERTY_CONSTRUCT

#define NI_DITHER_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \

#define NI_DITHER_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \

#define NI_DITHER_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
return out.str(); \

// 
// Texture flipping controller.
//
// - Target texture slot (0=base, 4=glow).
// - 0?
// - Time between two flips.
// delta = (start_time - stop_time) / sources.num_indices
// - The texture source indices.
#define NI_FLIP_CONTROLLER_MEMBERS \
uint textureSlot; \
uint unknownInt2; \
float delta; \
LinkGroup sources; \

#define NI_FLIP_CONTROLLER_GETATTR \
attr_ref attr = ASingleInterpolatorController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Texture Slot" ) \
  return attr_ref(textureSlot); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
if ( attr_name == "Delta" ) \
  return attr_ref(delta); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLIP_CONTROLLER_PARENTS ASingleInterpolatorController

#define NI_FLIP_CONTROLLER_CONSTRUCT

#define NI_FLIP_CONTROLLER_READ \
ASingleInterpolatorController::Read( in, version ); \
NifStream( textureSlot, in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( unknownInt2, in, version ); \
  NifStream( delta, in, version ); \
}; \
NifStream( sources, in, version ); \

#define NI_FLIP_CONTROLLER_WRITE \
ASingleInterpolatorController::Write( out, version ); \
NifStream( textureSlot, out, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( unknownInt2, out, version ); \
  NifStream( delta, out, version ); \
}; \
NifStream( sources, out, version ); \

#define NI_FLIP_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ASingleInterpolatorController::asString(); \
out << "        Texture Slot:  " << textureSlot << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
out << "               Delta:  " << delta << endl; \
out << "             Sources:  " << sources << endl; \
return out.str(); \

// 
// Possibly the 1D position along a 3D path.
//
// - The keys.
#define NI_FLOAT_DATA_MEMBERS \
VectorKeyArray<float > data; \

#define NI_FLOAT_DATA_GETATTR \
attr_ref attr = AKeyedData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLOAT_DATA_PARENTS AKeyedData

#define NI_FLOAT_DATA_CONSTRUCT

#define NI_FLOAT_DATA_READ \
AKeyedData::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_FLOAT_DATA_WRITE \
AKeyedData::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_FLOAT_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyedData::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Float extra data.
//
// - The float data.
#define NI_FLOAT_EXTRA_DATA_MEMBERS \
float floatData; \

#define NI_FLOAT_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Float Data" ) \
  return attr_ref(floatData); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLOAT_EXTRA_DATA_PARENTS AExtraData

#define NI_FLOAT_EXTRA_DATA_CONSTRUCT

#define NI_FLOAT_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( floatData, in, version ); \

#define NI_FLOAT_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( floatData, out, version ); \

#define NI_FLOAT_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "          Float Data:  " << floatData << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown. Refers to some NiFloatExtraData name?
#define NI_FLOAT_EXTRA_DATA_CONTROLLER_MEMBERS \
Link unknownLink; \
string unknownString; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknownLink); \
if ( attr_name == "Unknown String" ) \
  return attr_ref(unknownString); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_PARENTS AController

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_CONSTRUCT

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_READ \
AController::Read( in, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( unknownLink, in, version ); \
  NifStream( unknownString, in, version ); \
}; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( unknownLink, out, version ); \
  NifStream( unknownString, out, version ); \
}; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "        Unknown Link:  " << unknownLink << endl; \
out << "      Unknown String:  " << unknownString << endl; \
return out.str(); \

// 
// Unknown.
//
// - Value when posed?  At time 0?
// - Float data?
#define NI_FLOAT_INTERPOLATOR_MEMBERS \
float floatValue; \
Link data; \

#define NI_FLOAT_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Float Value" ) \
  return attr_ref(floatValue); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLOAT_INTERPOLATOR_PARENTS AInterpolator

#define NI_FLOAT_INTERPOLATOR_CONSTRUCT

#define NI_FLOAT_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( floatValue, in, version ); \
NifStream( data, in, version ); \

#define NI_FLOAT_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( floatValue, out, version ); \
NifStream( data, out, version ); \

#define NI_FLOAT_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "         Float Value:  " << floatValue << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Unknown.
//
// - Float data.
#define NI_FLOATS_EXTRA_DATA_MEMBERS \
vector<float > data; \

#define NI_FLOATS_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLOATS_EXTRA_DATA_PARENTS AExtraData

#define NI_FLOATS_EXTRA_DATA_CONSTRUCT

#define NI_FLOATS_EXTRA_DATA_READ \
uint numFloats; \
AExtraData::Read( in, version ); \
NifStream( numFloats, in, version ); \
data.resize(numFloats); \
NifStream( data, in, version ); \

#define NI_FLOATS_EXTRA_DATA_WRITE \
uint numFloats; \
AExtraData::Write( out, version ); \
numFloats = uint(data.size()); \
NifStream( numFloats, out, version ); \
NifStream( data, out, version ); \

#define NI_FLOATS_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "          Num Floats:  -- calculated --" << endl; \
out << "                Data:  -- data not shown --" << endl; \
return out.str(); \

// 
// Describes... fog?
//
// - 1's bit: Enables Fog
// 2's bit: Sets Fog Function to FOG_RANGE_SQ
// 4's bit: Sets Fog Function to FOG_VERTEX_ALPHA
// 
// If 2's and 4's bit are not set, but fog is enabled, Fog function is FOG_Z_LINEAR.
// - The thickness of the fog?  Default is 1.0
// - The color of the fog.
#define NI_FOG_PROPERTY_MEMBERS \
Flags flags; \
float fogDepth; \
Color3 fogColor; \

#define NI_FOG_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Fog Depth" ) \
  return attr_ref(fogDepth); \
if ( attr_name == "Fog Color" ) \
  return attr_ref(fogColor); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FOG_PROPERTY_PARENTS AProperty

#define NI_FOG_PROPERTY_CONSTRUCT

#define NI_FOG_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \
NifStream( fogDepth, in, version ); \
NifStream( fogColor, in, version ); \

#define NI_FOG_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \
NifStream( fogDepth, out, version ); \
NifStream( fogColor, out, version ); \

#define NI_FOG_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "           Fog Depth:  " << fogDepth << endl; \
out << "           Fog Color:  " << fogColor << endl; \
return out.str(); \

// 
// Time controller for geometry morphing.
//
// - Unknown.
// - Unknown.
// - Geometry morphing data index.
// - Unknown byte (always zero?).
// - List of interpolators.
// - Unknown.
#define NI_GEOM_MORPHER_CONTROLLER_MEMBERS \
ushort unknown; \
byte unknown2; \
Link data; \
byte unknownByte; \
LinkGroup interpolators; \
vector<uint > unknownInts; \

#define NI_GEOM_MORPHER_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown" ) \
  return attr_ref(unknown); \
if ( attr_name == "Unknown 2" ) \
  return attr_ref(unknown2); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_GEOM_MORPHER_CONTROLLER_PARENTS AController

#define NI_GEOM_MORPHER_CONTROLLER_CONSTRUCT

#define NI_GEOM_MORPHER_CONTROLLER_READ \
uint numUnknownInts; \
AController::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown2, in, version ); \
}; \
NifStream( data, in, version ); \
NifStream( unknownByte, in, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( interpolators, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( numUnknownInts, in, version ); \
  unknownInts.resize(numUnknownInts); \
  NifStream( unknownInts, in, version ); \
}; \

#define NI_GEOM_MORPHER_CONTROLLER_WRITE \
uint numUnknownInts; \
AController::Write( out, version ); \
numUnknownInts = uint(unknownInts.size()); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown2, out, version ); \
}; \
NifStream( data, out, version ); \
NifStream( unknownByte, out, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( interpolators, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( numUnknownInts, out, version ); \
  NifStream( unknownInts, out, version ); \
}; \

#define NI_GEOM_MORPHER_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "             Unknown:  " << unknown << endl; \
out << "           Unknown 2:  " << unknown2 << endl; \
out << "                Data:  " << data << endl; \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "       Interpolators:  " << interpolators << endl; \
out << "    Num Unknown Ints:  -- calculated --" << endl; \
out << "        Unknown Ints:  -- data not shown --" << endl; \
return out.str(); \

// 
// A particle modifier; applies a gravitational field on the particles.
//
// - Unknown.
// - The strength/force of this gravity.
// - The force field's type. 
// 0: Wind (fixed direction)
// 1: Point (fixed origin)
// - The position of the mass point relative to the particle system.
// - The direction of the applied acceleration.
#define NI_GRAVITY_MEMBERS \
float unknownFloat1; \
float force; \
uint type; \
Vector3 position; \
Vector3 direction; \

#define NI_GRAVITY_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Force" ) \
  return attr_ref(force); \
if ( attr_name == "Type" ) \
  return attr_ref(type); \
if ( attr_name == "Position" ) \
  return attr_ref(position); \
if ( attr_name == "Direction" ) \
  return attr_ref(direction); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_GRAVITY_PARENTS AParticleModifier

#define NI_GRAVITY_CONSTRUCT

#define NI_GRAVITY_READ \
AParticleModifier::Read( in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( force, in, version ); \
NifStream( type, in, version ); \
NifStream( position, in, version ); \
NifStream( direction, in, version ); \

#define NI_GRAVITY_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( force, out, version ); \
NifStream( type, out, version ); \
NifStream( position, out, version ); \
NifStream( direction, out, version ); \

#define NI_GRAVITY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "               Force:  " << force << endl; \
out << "                Type:  " << type << endl; \
out << "            Position:  " << position << endl; \
out << "           Direction:  " << direction << endl; \
return out.str(); \

// 
// Extra integer data.
//
// - The value of the extra data.
#define NI_INTEGER_EXTRA_DATA_MEMBERS \
uint integerData; \

#define NI_INTEGER_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Integer Data" ) \
  return attr_ref(integerData); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_INTEGER_EXTRA_DATA_PARENTS AExtraData

#define NI_INTEGER_EXTRA_DATA_CONSTRUCT

#define NI_INTEGER_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( integerData, in, version ); \

#define NI_INTEGER_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( integerData, out, version ); \

#define NI_INTEGER_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "        Integer Data:  " << integerData << endl; \
return out.str(); \

// 
// Integers data.
//
// - Integers.
#define NI_INTEGERS_EXTRA_DATA_MEMBERS \
vector<uint > data; \

#define NI_INTEGERS_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_INTEGERS_EXTRA_DATA_PARENTS AExtraData

#define NI_INTEGERS_EXTRA_DATA_CONSTRUCT

#define NI_INTEGERS_EXTRA_DATA_READ \
uint numIntegers; \
AExtraData::Read( in, version ); \
NifStream( numIntegers, in, version ); \
data.resize(numIntegers); \
NifStream( data, in, version ); \

#define NI_INTEGERS_EXTRA_DATA_WRITE \
uint numIntegers; \
AExtraData::Write( out, version ); \
numIntegers = uint(data.size()); \
NifStream( numIntegers, out, version ); \
NifStream( data, out, version ); \

#define NI_INTEGERS_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "        Num Integers:  -- calculated --" << endl; \
out << "                Data:  -- data not shown --" << endl; \
return out.str(); \

// 
// Keyframe controller block.
//
#define NI_KEYFRAME_CONTROLLER_MEMBERS \

#define NI_KEYFRAME_CONTROLLER_GETATTR \
attr_ref attr = AKeyframeController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_KEYFRAME_CONTROLLER_PARENTS AKeyframeController

#define NI_KEYFRAME_CONTROLLER_CONSTRUCT

#define NI_KEYFRAME_CONTROLLER_READ \
AKeyframeController::Read( in, version ); \

#define NI_KEYFRAME_CONTROLLER_WRITE \
AKeyframeController::Write( out, version ); \

#define NI_KEYFRAME_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyframeController::asString(); \
return out.str(); \

// 
// Keyframe data for mesh transform.
//
#define NI_KEYFRAME_DATA_MEMBERS \

#define NI_KEYFRAME_DATA_GETATTR \
attr_ref attr = AKeyframeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_KEYFRAME_DATA_PARENTS AKeyframeData

#define NI_KEYFRAME_DATA_CONSTRUCT

#define NI_KEYFRAME_DATA_READ \
AKeyframeData::Read( in, version ); \

#define NI_KEYFRAME_DATA_WRITE \
AKeyframeData::Write( out, version ); \

#define NI_KEYFRAME_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyframeData::asString(); \
return out.str(); \

// 
// Light color animation controller.
//     
//     
//     
//     
//     Unknown.
//
// - Unknown.
// - Link to NiPosData
// - Link to NiPoint3Interpolator.
#define NI_LIGHT_COLOR_CONTROLLER_MEMBERS \
ushort unknownShort; \
Link data; \
Link interpolator; \

#define NI_LIGHT_COLOR_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Interpolator" ) \
  return attr_ref(interpolator); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_LIGHT_COLOR_CONTROLLER_PARENTS AController

#define NI_LIGHT_COLOR_CONTROLLER_CONSTRUCT

#define NI_LIGHT_COLOR_CONTROLLER_READ \
AController::Read( in, version ); \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) { \
  NifStream( unknownShort, in, version ); \
}; \
if ( version <= 0x0A010000 ) { \
  NifStream( data, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( interpolator, in, version ); \
  NifStream( unknownShort, in, version ); \
}; \

#define NI_LIGHT_COLOR_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) { \
  NifStream( unknownShort, out, version ); \
}; \
if ( version <= 0x0A010000 ) { \
  NifStream( data, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( interpolator, out, version ); \
  NifStream( unknownShort, out, version ); \
}; \

#define NI_LIGHT_COLOR_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "                Data:  " << data << endl; \
out << "        Interpolator:  " << interpolator << endl; \
return out.str(); \

// 
// Unknown controller.
//
// - Unknown link. Interpolator?
#define NI_LIGHT_DIMMER_CONTROLLER_MEMBERS \
Link unknownLink; \

#define NI_LIGHT_DIMMER_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknownLink); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_LIGHT_DIMMER_CONTROLLER_PARENTS AController

#define NI_LIGHT_DIMMER_CONTROLLER_CONSTRUCT

#define NI_LIGHT_DIMMER_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( unknownLink, in, version ); \

#define NI_LIGHT_DIMMER_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( unknownLink, out, version ); \

#define NI_LIGHT_DIMMER_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "        Unknown Link:  " << unknownLink << endl; \
return out.str(); \

// 
// Level of detail selector. Links to different levels of detail of the same model, used to switch a geometry at a specified distance.
//
// - The ranges of distance where each level of detail applies.
#define NI_L_O_D_NODE_MEMBERS \
LODInfo lodInfo; \

#define NI_L_O_D_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_L_O_D_NODE_PARENTS AParentNode

#define NI_L_O_D_NODE_CONSTRUCT

#define NI_L_O_D_NODE_READ \
AParentNode::Read( in, version ); \
NifStream( lodInfo, in, version ); \

#define NI_L_O_D_NODE_WRITE \
AParentNode::Write( out, version ); \
NifStream( lodInfo, out, version ); \

#define NI_L_O_D_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
out << "            LOD Info:  " << lodInfo << endl; \
return out.str(); \

// 
// Unknown. Start time is 3.4e+38 and stop time is -3.4e+38.
//
// - Unknown.
// - Link to the node to look at?
#define NI_LOOK_AT_CONTROLLER_MEMBERS \
ushort unknown1; \
Link lookAtNode; \

#define NI_LOOK_AT_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown1" ) \
  return attr_ref(unknown1); \
if ( attr_name == "Look At Node" ) \
  return attr_ref(lookAtNode); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_LOOK_AT_CONTROLLER_PARENTS AController

#define NI_LOOK_AT_CONTROLLER_CONSTRUCT

#define NI_LOOK_AT_CONTROLLER_READ \
AController::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown1, in, version ); \
}; \
NifStream( lookAtNode, in, version ); \

#define NI_LOOK_AT_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown1, out, version ); \
}; \
NifStream( lookAtNode, out, version ); \

#define NI_LOOK_AT_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "            Unknown1:  " << unknown1 << endl; \
out << "        Look At Node:  " << lookAtNode << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Refers to a Node to focus on.
// - Unknown.
// - Translate.
// - Rotation.
// - Scale.
// - Refers to NiPoint3Interpolator.
// - Refers to a NiFloatInterpolator.
// - Refers to a NiFloatInterpolator.
#define NI_LOOK_AT_INTERPOLATOR_MEMBERS \
ushort unknownShort; \
Link lookAt; \
float unknownFloat; \
Vector3 translation; \
Quaternion rotation; \
float scale; \
Link unknownLink1; \
Link unknownLink2; \
Link unknownLink3; \

#define NI_LOOK_AT_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Look At" ) \
  return attr_ref(lookAt); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknownFloat); \
if ( attr_name == "Translation" ) \
  return attr_ref(translation); \
if ( attr_name == "Rotation" ) \
  return attr_ref(rotation); \
if ( attr_name == "Scale" ) \
  return attr_ref(scale); \
if ( attr_name == "Unknown Link 1" ) \
  return attr_ref(unknownLink1); \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknownLink2); \
if ( attr_name == "Unknown Link 3" ) \
  return attr_ref(unknownLink3); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_LOOK_AT_INTERPOLATOR_PARENTS AInterpolator

#define NI_LOOK_AT_INTERPOLATOR_CONSTRUCT

#define NI_LOOK_AT_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( unknownShort, in, version ); \
NifStream( lookAt, in, version ); \
NifStream( unknownFloat, in, version ); \
NifStream( translation, in, version ); \
NifStream( rotation, in, version ); \
NifStream( scale, in, version ); \
NifStream( unknownLink1, in, version ); \
NifStream( unknownLink2, in, version ); \
NifStream( unknownLink3, in, version ); \

#define NI_LOOK_AT_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( unknownShort, out, version ); \
NifStream( lookAt, out, version ); \
NifStream( unknownFloat, out, version ); \
NifStream( translation, out, version ); \
NifStream( rotation, out, version ); \
NifStream( scale, out, version ); \
NifStream( unknownLink1, out, version ); \
NifStream( unknownLink2, out, version ); \
NifStream( unknownLink3, out, version ); \

#define NI_LOOK_AT_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "             Look At:  " << lookAt << endl; \
out << "       Unknown Float:  " << unknownFloat << endl; \
out << "         Translation:  " << translation << endl; \
out << "            Rotation:  " << rotation << endl; \
out << "               Scale:  " << scale << endl; \
out << "      Unknown Link 1:  " << unknownLink1 << endl; \
out << "      Unknown Link 2:  " << unknownLink2 << endl; \
out << "      Unknown Link 3:  " << unknownLink3 << endl; \
return out.str(); \

// 
// Time controller for material color.
//
// - Unknown.
// - Material color controller data block index.
// - Unknown.
#define NI_MATERIAL_COLOR_CONTROLLER_MEMBERS \
ushort unknown; \
Link data; \
ushort unknownShort; \

#define NI_MATERIAL_COLOR_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown" ) \
  return attr_ref(unknown); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_MATERIAL_COLOR_CONTROLLER_PARENTS AController

#define NI_MATERIAL_COLOR_CONTROLLER_CONSTRUCT

#define NI_MATERIAL_COLOR_CONTROLLER_READ \
AController::Read( in, version ); \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) { \
  NifStream( unknown, in, version ); \
}; \
NifStream( data, in, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( unknownShort, in, version ); \
}; \

#define NI_MATERIAL_COLOR_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) { \
  NifStream( unknown, out, version ); \
}; \
NifStream( data, out, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( unknownShort, out, version ); \
}; \

#define NI_MATERIAL_COLOR_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "             Unknown:  " << unknown << endl; \
out << "                Data:  " << data << endl; \
out << "       Unknown Short:  " << unknownShort << endl; \
return out.str(); \

// 
// Describes the material shading properties.
//
// - Property flags.
// - How much the material reflects ambient light.
// - How much the material reflects diffuse light.
// - How much light the material reflects in a specular manner.
// - How much light the material emits.
// - The material's glossiness.
// - The material transparency (1=non-transparant). Refer to a NiAlphaProperty block in this material's parent NiTriShape block, when alpha is not 1.
#define NI_MATERIAL_PROPERTY_MEMBERS \
Flags flags; \
Color3 ambientColor; \
Color3 diffuseColor; \
Color3 specularColor; \
Color3 emissiveColor; \
float glossiness; \
float alpha; \

#define NI_MATERIAL_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Ambient Color" ) \
  return attr_ref(ambientColor); \
if ( attr_name == "Diffuse Color" ) \
  return attr_ref(diffuseColor); \
if ( attr_name == "Specular Color" ) \
  return attr_ref(specularColor); \
if ( attr_name == "Emissive Color" ) \
  return attr_ref(emissiveColor); \
if ( attr_name == "Glossiness" ) \
  return attr_ref(glossiness); \
if ( attr_name == "Alpha" ) \
  return attr_ref(alpha); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_MATERIAL_PROPERTY_PARENTS AProperty

#define NI_MATERIAL_PROPERTY_CONSTRUCT

#define NI_MATERIAL_PROPERTY_READ \
AProperty::Read( in, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, in, version ); \
}; \
NifStream( ambientColor, in, version ); \
NifStream( diffuseColor, in, version ); \
NifStream( specularColor, in, version ); \
NifStream( emissiveColor, in, version ); \
NifStream( glossiness, in, version ); \
NifStream( alpha, in, version ); \

#define NI_MATERIAL_PROPERTY_WRITE \
AProperty::Write( out, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, out, version ); \
}; \
NifStream( ambientColor, out, version ); \
NifStream( diffuseColor, out, version ); \
NifStream( specularColor, out, version ); \
NifStream( emissiveColor, out, version ); \
NifStream( glossiness, out, version ); \
NifStream( alpha, out, version ); \

#define NI_MATERIAL_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "       Ambient Color:  " << ambientColor << endl; \
out << "       Diffuse Color:  " << diffuseColor << endl; \
out << "      Specular Color:  " << specularColor << endl; \
out << "      Emissive Color:  " << emissiveColor << endl; \
out << "          Glossiness:  " << glossiness << endl; \
out << "               Alpha:  " << alpha << endl; \
return out.str(); \

// 
// Particle system.
//
// - List of particle modifiers
#define NI_MESH_PARTICLE_SYSTEM_MEMBERS \
ModifierGroup modifiers; \

#define NI_MESH_PARTICLE_SYSTEM_GETATTR \
attr_ref attr = AParticleNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_MESH_PARTICLE_SYSTEM_PARENTS AParticleNode

#define NI_MESH_PARTICLE_SYSTEM_CONSTRUCT

#define NI_MESH_PARTICLE_SYSTEM_READ \
AParticleNode::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( modifiers, in, version ); \
}; \

#define NI_MESH_PARTICLE_SYSTEM_WRITE \
AParticleNode::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( modifiers, out, version ); \
}; \

#define NI_MESH_PARTICLE_SYSTEM_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleNode::asString(); \
out << "           Modifiers:  " << modifiers << endl; \
return out.str(); \

// 
// Particle meshes data.
//
// - Unknown.
// - Unknown. Repeatedly (1,0,0,0).
// - Unknown. Repeatedly (0,0,0,1,0,0,0,0,0,0).
// - Unknown. Zero.
// - Unknown. Usually 0.
// - Link to a particle modifier?
// - Unknown.
// - Unknown. Seems to refer to particle modifiers.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Links to a NiNode; but this NiNode doesn't seem to be a mesh?
#define NI_MESH_P_SYS_DATA_MEMBERS \
byte unknownByte11; \
vector<vector<float > > unknownFloats3; \
vector<vector<float > > unknownFloats4; \
vector<vector<float > > unknownFloats5; \
uint unknownInt1; \
Link modifier; \
byte unknownByte2; \
LinkGroup unknownLinkGroup; \
ushort unknownShort4; \
uint unknownInt2; \
byte unknownByte12; \
uint unknownInt3; \
uint unknownInt4; \
Link unknownLink2; \

#define NI_MESH_P_SYS_DATA_GETATTR \
attr_ref attr = APSysData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Byte 11" ) \
  return attr_ref(unknownByte11); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
if ( attr_name == "Modifier" ) \
  return attr_ref(modifier); \
if ( attr_name == "Unknown Byte 2" ) \
  return attr_ref(unknownByte2); \
if ( attr_name == "Unknown Short 4" ) \
  return attr_ref(unknownShort4); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
if ( attr_name == "Unknown Byte 12" ) \
  return attr_ref(unknownByte12); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknownInt3); \
if ( attr_name == "Unknown Int 4" ) \
  return attr_ref(unknownInt4); \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknownLink2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_MESH_P_SYS_DATA_PARENTS APSysData

#define NI_MESH_P_SYS_DATA_CONSTRUCT

#define NI_MESH_P_SYS_DATA_READ \
APSysData::Read( in, version ); \
if ( version >= 0x14000005 ) { \
  NifStream( unknownByte11, in, version ); \
}; \
if ( version <= 0x14000004 ) { \
  unknownFloats3.resize(numVertices); \
  NifStream( unknownFloats3, in, version ); \
  unknownFloats4.resize(numVertices); \
  NifStream( unknownFloats4, in, version ); \
}; \
if ( version >= 0x14000005 ) { \
  unknownFloats5.resize(numVertices); \
  NifStream( unknownFloats5, in, version ); \
}; \
NifStream( unknownInt1, in, version ); \
if ( version <= 0x14000004 ) { \
  NifStream( modifier, in, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) { \
  NifStream( unknownByte2, in, version ); \
  NifStream( unknownLinkGroup, in, version ); \
}; \
if ( version >= 0x14000005 ) { \
  NifStream( unknownShort4, in, version ); \
  NifStream( unknownInt2, in, version ); \
  NifStream( unknownByte12, in, version ); \
  NifStream( unknownInt3, in, version ); \
  NifStream( unknownInt4, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( unknownLink2, in, version ); \
}; \

#define NI_MESH_P_SYS_DATA_WRITE \
APSysData::Write( out, version ); \
if ( version >= 0x14000005 ) { \
  NifStream( unknownByte11, out, version ); \
}; \
if ( version <= 0x14000004 ) { \
  NifStream( unknownFloats3, out, version ); \
  NifStream( unknownFloats4, out, version ); \
}; \
if ( version >= 0x14000005 ) { \
  NifStream( unknownFloats5, out, version ); \
}; \
NifStream( unknownInt1, out, version ); \
if ( version <= 0x14000004 ) { \
  NifStream( modifier, out, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) { \
  NifStream( unknownByte2, out, version ); \
  NifStream( unknownLinkGroup, out, version ); \
}; \
if ( version >= 0x14000005 ) { \
  NifStream( unknownShort4, out, version ); \
  NifStream( unknownInt2, out, version ); \
  NifStream( unknownByte12, out, version ); \
  NifStream( unknownInt3, out, version ); \
  NifStream( unknownInt4, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( unknownLink2, out, version ); \
}; \

#define NI_MESH_P_SYS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysData::asString(); \
out << "     Unknown Byte 11:  " << unknownByte11 << endl; \
out << "    Unknown Floats 3:  -- data not shown --" << endl; \
out << "    Unknown Floats 4:  -- data not shown --" << endl; \
out << "    Unknown Floats 5:  -- data not shown --" << endl; \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "            Modifier:  " << modifier << endl; \
out << "      Unknown Byte 2:  " << unknownByte2 << endl; \
out << "  Unknown Link Group:  " << unknownLinkGroup << endl; \
out << "     Unknown Short 4:  " << unknownShort4 << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
out << "     Unknown Byte 12:  " << unknownByte12 << endl; \
out << "       Unknown Int 3:  " << unknownInt3 << endl; \
out << "       Unknown Int 4:  " << unknownInt4 << endl; \
out << "      Unknown Link 2:  " << unknownLink2 << endl; \
return out.str(); \

// 
// Geometry morphing data.
//
// - Number of vertices.
// - This byte is always 1 in all official files.
// - The geometry morphing blocks.
#define NI_MORPH_DATA_MEMBERS \
uint numVertices; \
byte unknownByte; \
vector<Morph > morphs; \

#define NI_MORPH_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Vertices" ) \
  return attr_ref(numVertices); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_MORPH_DATA_PARENTS AData

#define NI_MORPH_DATA_CONSTRUCT

#define NI_MORPH_DATA_READ \
uint numMorphs; \
AData::Read( in, version ); \
NifStream( numMorphs, in, version ); \
NifStream( numVertices, in, version ); \
NifStream( unknownByte, in, version ); \
morphs.resize(numMorphs); \
NifStream( morphs, in, version, numVertices ); \

#define NI_MORPH_DATA_WRITE \
uint numMorphs; \
AData::Write( out, version ); \
numMorphs = uint(morphs.size()); \
NifStream( numMorphs, out, version ); \
NifStream( numVertices, out, version ); \
NifStream( unknownByte, out, version ); \
NifStream( morphs, out, version, numVertices ); \

#define NI_MORPH_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "          Num Morphs:  -- calculated --" << endl; \
out << "        Num Vertices:  " << numVertices << endl; \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "              Morphs:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
// - List of NiNode targets.
#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_MEMBERS \
TargetGroup targets; \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENTS AController

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_CONSTRUCT

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( targets, in, version ); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( targets, out, version ); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "             Targets:  " << targets << endl; \
return out.str(); \

// 
// The standard node block.
//
#define NI_NODE_MEMBERS \

#define NI_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_NODE_PARENTS AParentNode

#define NI_NODE_CONSTRUCT

#define NI_NODE_READ \
AParentNode::Read( in, version ); \

#define NI_NODE_WRITE \
AParentNode::Write( out, version ); \

#define NI_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
return out.str(); \

// 
// A color palette.
//
// - Unknown, always = 0.
// - The number of palette entries?  Always = 256.
// - The color palette.
#define NI_PALETTE_MEMBERS \
byte unknownByte; \
uint numEntries_; \
vector<vector<byte > > palette; \

#define NI_PALETTE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
if ( attr_name == "Num Entries?" ) \
  return attr_ref(numEntries_); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PALETTE_PARENTS AData

#define NI_PALETTE_CONSTRUCT

#define NI_PALETTE_READ \
AData::Read( in, version ); \
NifStream( unknownByte, in, version ); \
NifStream( numEntries_, in, version ); \
palette.resize(256); \
NifStream( palette, in, version ); \

#define NI_PALETTE_WRITE \
AData::Write( out, version ); \
NifStream( unknownByte, out, version ); \
NifStream( numEntries_, out, version ); \
NifStream( palette, out, version ); \

#define NI_PALETTE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "        Num Entries?:  " << numEntries_ << endl; \
out << "             Palette:  -- data not shown --" << endl; \
return out.str(); \

// 
// A particle modifier.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_PARTICLE_BOMB_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \
uint unknownInt1; \
uint unknownInt2; \
float unknownFloat5; \
float unknownFloat6; \
float unknownFloat7; \
float unknownFloat8; \
float unknownFloat9; \
float unknownFloat10; \

#define NI_PARTICLE_BOMB_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknownFloat3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknownFloat4); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
if ( attr_name == "Unknown Float 5" ) \
  return attr_ref(unknownFloat5); \
if ( attr_name == "Unknown Float 6" ) \
  return attr_ref(unknownFloat6); \
if ( attr_name == "Unknown Float 7" ) \
  return attr_ref(unknownFloat7); \
if ( attr_name == "Unknown Float 8" ) \
  return attr_ref(unknownFloat8); \
if ( attr_name == "Unknown Float 9" ) \
  return attr_ref(unknownFloat9); \
if ( attr_name == "Unknown Float 10" ) \
  return attr_ref(unknownFloat10); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_BOMB_PARENTS AParticleModifier

#define NI_PARTICLE_BOMB_CONSTRUCT

#define NI_PARTICLE_BOMB_READ \
AParticleModifier::Read( in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \
NifStream( unknownInt1, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( unknownFloat5, in, version ); \
NifStream( unknownFloat6, in, version ); \
NifStream( unknownFloat7, in, version ); \
NifStream( unknownFloat8, in, version ); \
NifStream( unknownFloat9, in, version ); \
NifStream( unknownFloat10, in, version ); \

#define NI_PARTICLE_BOMB_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \
NifStream( unknownInt1, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( unknownFloat5, out, version ); \
NifStream( unknownFloat6, out, version ); \
NifStream( unknownFloat7, out, version ); \
NifStream( unknownFloat8, out, version ); \
NifStream( unknownFloat9, out, version ); \
NifStream( unknownFloat10, out, version ); \

#define NI_PARTICLE_BOMB_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "     Unknown Float 3:  " << unknownFloat3 << endl; \
out << "     Unknown Float 4:  " << unknownFloat4 << endl; \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
out << "     Unknown Float 5:  " << unknownFloat5 << endl; \
out << "     Unknown Float 6:  " << unknownFloat6 << endl; \
out << "     Unknown Float 7:  " << unknownFloat7 << endl; \
out << "     Unknown Float 8:  " << unknownFloat8 << endl; \
out << "     Unknown Float 9:  " << unknownFloat9 << endl; \
out << "    Unknown Float 10:  " << unknownFloat10 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Color data index.
#define NI_PARTICLE_COLOR_MODIFIER_MEMBERS \
Link colorData; \

#define NI_PARTICLE_COLOR_MODIFIER_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Color Data" ) \
  return attr_ref(colorData); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_COLOR_MODIFIER_PARENTS AParticleModifier

#define NI_PARTICLE_COLOR_MODIFIER_CONSTRUCT

#define NI_PARTICLE_COLOR_MODIFIER_READ \
AParticleModifier::Read( in, version ); \
NifStream( colorData, in, version ); \

#define NI_PARTICLE_COLOR_MODIFIER_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( colorData, out, version ); \

#define NI_PARTICLE_COLOR_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "          Color Data:  " << colorData << endl; \
return out.str(); \

// 
// This particle system modifier controls the particle size. If it is present the particles start with size 0.0 . Then they grow to their original size and stay there until they fade to zero size again at the end of their lifetime cycle.
//
// - The time from the beginning of the particle lifetime during which the particle grows.
// - The time from the end of the particle lifetime during which the particle fades.
#define NI_PARTICLE_GROW_FADE_MEMBERS \
float grow; \
float fade; \

#define NI_PARTICLE_GROW_FADE_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Grow" ) \
  return attr_ref(grow); \
if ( attr_name == "Fade" ) \
  return attr_ref(fade); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_GROW_FADE_PARENTS AParticleModifier

#define NI_PARTICLE_GROW_FADE_CONSTRUCT

#define NI_PARTICLE_GROW_FADE_READ \
AParticleModifier::Read( in, version ); \
NifStream( grow, in, version ); \
NifStream( fade, in, version ); \

#define NI_PARTICLE_GROW_FADE_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( grow, out, version ); \
NifStream( fade, out, version ); \

#define NI_PARTICLE_GROW_FADE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "                Grow:  " << grow << endl; \
out << "                Fade:  " << fade << endl; \
return out.str(); \

// 
// Mesh particle node?
//
#define NI_PARTICLE_MESHES_MEMBERS \

#define NI_PARTICLE_MESHES_GETATTR \
attr_ref attr = AParticleNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_MESHES_PARENTS AParticleNode

#define NI_PARTICLE_MESHES_CONSTRUCT

#define NI_PARTICLE_MESHES_READ \
AParticleNode::Read( in, version ); \

#define NI_PARTICLE_MESHES_WRITE \
AParticleNode::Write( out, version ); \

#define NI_PARTICLE_MESHES_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleNode::asString(); \
return out.str(); \

// 
// Particle meshes data.
//
// - Refers to the mesh that makes up a particle?
#define NI_PARTICLE_MESHES_DATA_MEMBERS \
Link unknownLink2; \

#define NI_PARTICLE_MESHES_DATA_GETATTR \
attr_ref attr = ARotatingParticlesData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknownLink2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_MESHES_DATA_PARENTS ARotatingParticlesData

#define NI_PARTICLE_MESHES_DATA_CONSTRUCT

#define NI_PARTICLE_MESHES_DATA_READ \
ARotatingParticlesData::Read( in, version ); \
NifStream( unknownLink2, in, version ); \

#define NI_PARTICLE_MESHES_DATA_WRITE \
ARotatingParticlesData::Write( out, version ); \
NifStream( unknownLink2, out, version ); \

#define NI_PARTICLE_MESHES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ARotatingParticlesData::asString(); \
out << "      Unknown Link 2:  " << unknownLink2 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Links to nodes of particle meshes?
#define NI_PARTICLE_MESH_MODIFIER_MEMBERS \
LinkGroup particleMeshes; \

#define NI_PARTICLE_MESH_MODIFIER_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_MESH_MODIFIER_PARENTS AParticleModifier

#define NI_PARTICLE_MESH_MODIFIER_CONSTRUCT

#define NI_PARTICLE_MESH_MODIFIER_READ \
AParticleModifier::Read( in, version ); \
NifStream( particleMeshes, in, version ); \

#define NI_PARTICLE_MESH_MODIFIER_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( particleMeshes, out, version ); \

#define NI_PARTICLE_MESH_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "     Particle Meshes:  " << particleMeshes << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_PARTICLE_ROTATION_MEMBERS \
byte unknownByte; \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \

#define NI_PARTICLE_ROTATION_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknownFloat3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknownFloat4); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_ROTATION_PARENTS AParticleModifier

#define NI_PARTICLE_ROTATION_CONSTRUCT

#define NI_PARTICLE_ROTATION_READ \
AParticleModifier::Read( in, version ); \
NifStream( unknownByte, in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \

#define NI_PARTICLE_ROTATION_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( unknownByte, out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \

#define NI_PARTICLE_ROTATION_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "     Unknown Float 3:  " << unknownFloat3 << endl; \
out << "     Unknown Float 4:  " << unknownFloat4 << endl; \
return out.str(); \

// 
// Particle system node.
//
#define NI_PARTICLES_MEMBERS \

#define NI_PARTICLES_GETATTR \
attr_ref attr = AParticleNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLES_PARENTS AParticleNode

#define NI_PARTICLES_CONSTRUCT

#define NI_PARTICLES_READ \
AParticleNode::Read( in, version ); \

#define NI_PARTICLES_WRITE \
AParticleNode::Write( out, version ); \

#define NI_PARTICLES_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleNode::asString(); \
return out.str(); \

// 
// Particle system data.
//
#define NI_PARTICLES_DATA_MEMBERS \

#define NI_PARTICLES_DATA_GETATTR \
attr_ref attr = ARotatingParticlesData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLES_DATA_PARENTS ARotatingParticlesData

#define NI_PARTICLES_DATA_CONSTRUCT

#define NI_PARTICLES_DATA_READ \
ARotatingParticlesData::Read( in, version ); \

#define NI_PARTICLES_DATA_WRITE \
ARotatingParticlesData::Write( out, version ); \

#define NI_PARTICLES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ARotatingParticlesData::asString(); \
return out.str(); \

// 
// A particle system.
//
// - List of particle modifiers.
#define NI_PARTICLE_SYSTEM_MEMBERS \
ModifierGroup modifiers; \

#define NI_PARTICLE_SYSTEM_GETATTR \
attr_ref attr = AParticleNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_SYSTEM_PARENTS AParticleNode

#define NI_PARTICLE_SYSTEM_CONSTRUCT

#define NI_PARTICLE_SYSTEM_READ \
AParticleNode::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( modifiers, in, version ); \
}; \

#define NI_PARTICLE_SYSTEM_WRITE \
AParticleNode::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( modifiers, out, version ); \
}; \

#define NI_PARTICLE_SYSTEM_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleNode::asString(); \
out << "           Modifiers:  " << modifiers << endl; \
return out.str(); \

// 
// A particle system controller
//
#define NI_PARTICLE_SYSTEM_CONTROLLER_MEMBERS \

#define NI_PARTICLE_SYSTEM_CONTROLLER_GETATTR \
attr_ref attr = AParticleSystemController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_PARENTS AParticleSystemController

#define NI_PARTICLE_SYSTEM_CONTROLLER_CONSTRUCT

#define NI_PARTICLE_SYSTEM_CONTROLLER_READ \
AParticleSystemController::Read( in, version ); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_WRITE \
AParticleSystemController::Write( out, version ); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleSystemController::asString(); \
return out.str(); \

// 
// Time controller for a path.
//
// - Unknown.
// - Unknown, always 1?
// - Unknown, always 0?
// - Unknown, always 0?
// - Unknown, always 0?
// - Path controller data index (position data). ?
// - Path controller data index (float data). ?
#define NI_PATH_CONTROLLER_MEMBERS \
ushort unknownShort2; \
uint unknownInt1; \
uint unknownInt2; \
uint unknownInt3; \
ushort unknownShort; \
Link posData; \
Link floatData; \

#define NI_PATH_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknownShort2); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknownInt2); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknownInt3); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Pos Data" ) \
  return attr_ref(posData); \
if ( attr_name == "Float Data" ) \
  return attr_ref(floatData); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PATH_CONTROLLER_PARENTS AController

#define NI_PATH_CONTROLLER_CONSTRUCT

#define NI_PATH_CONTROLLER_READ \
AController::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknownShort2, in, version ); \
}; \
NifStream( unknownInt1, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( unknownInt3, in, version ); \
NifStream( unknownShort, in, version ); \
NifStream( posData, in, version ); \
NifStream( floatData, in, version ); \

#define NI_PATH_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknownShort2, out, version ); \
}; \
NifStream( unknownInt1, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( unknownInt3, out, version ); \
NifStream( unknownShort, out, version ); \
NifStream( posData, out, version ); \
NifStream( floatData, out, version ); \

#define NI_PATH_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "     Unknown Short 2:  " << unknownShort2 << endl; \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "       Unknown Int 2:  " << unknownInt2 << endl; \
out << "       Unknown Int 3:  " << unknownInt3 << endl; \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "            Pos Data:  " << posData << endl; \
out << "          Float Data:  " << floatData << endl; \
return out.str(); \

// 
// Unknown interpolator.
//
// - Unknown.
// - Unknown.
// - Unknown. Zero.
// - Links to NiPosData.
// - Links to NiFloatData.
#define NI_PATH_INTERPOLATOR_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
ushort unknownShort2; \
Link posData; \
Link floatData; \

#define NI_PATH_INTERPOLATOR_GETATTR \
attr_ref attr = ABlendInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknownShort2); \
if ( attr_name == "Pos Data" ) \
  return attr_ref(posData); \
if ( attr_name == "Float Data" ) \
  return attr_ref(floatData); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PATH_INTERPOLATOR_PARENTS ABlendInterpolator

#define NI_PATH_INTERPOLATOR_CONSTRUCT

#define NI_PATH_INTERPOLATOR_READ \
ABlendInterpolator::Read( in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownShort2, in, version ); \
NifStream( posData, in, version ); \
NifStream( floatData, in, version ); \

#define NI_PATH_INTERPOLATOR_WRITE \
ABlendInterpolator::Write( out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownShort2, out, version ); \
NifStream( posData, out, version ); \
NifStream( floatData, out, version ); \

#define NI_PATH_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABlendInterpolator::asString(); \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "     Unknown Short 2:  " << unknownShort2 << endl; \
out << "            Pos Data:  " << posData << endl; \
out << "          Float Data:  " << floatData << endl; \
return out.str(); \

// 
// A texture.
//
// - 0 = PX_FMT_RGB8
// 1 = PX_FMT_RGBA8
// 2 = PX_FMT_PAL8
// 4 = ???
// 5 = ??? (version 20.0.0.4)
// 6 = ??? (version 20.0.0.4)
// - 0x000000ff (for 24bpp and 32bpp) or 0x00000000 (for 8bpp)
// - 0x0000ff00 (for 24bpp and 32bpp) or 0x00000000 (for 8bpp)
// - 0x00ff0000 (for 24bpp and 32bpp) or 0x00000000 (for 8bpp)
// - 0xff000000 (for 32bpp) or 0x00000000 (for 24bpp and 8bpp)
// - Bits per pixel, 0 (?), 8, 24 or 32.
// - [96,8,130,0,0,65,0,0] if 24 bits per pixel
// [129,8,130,32,0,65,12,0] if 32 bits per pixel
// [34,0,0,0,0,0,0,0] if 8 bits per pixel
// [4,0,0,0,0,0,0,0] if 0 (?) bits per pixel
// - Seems to always be zero.
// - Unknown.
// - Link to NiPalette, for 8-bit textures.
// - Bytes per pixel (Bits Per Pixel / 8).
// - Mipmap descriptions (width, height, offset).
// - Raw pixel data holding the mipmaps.  Mipmap zero is the full-size texture and they get smaller by half as the number increases.
#define NI_PIXEL_DATA_MEMBERS \
uint pixelFormat; \
uint redMask; \
uint greenMask; \
uint blueMask; \
uint alphaMask; \
uint bitsPerPixel; \
vector<byte > unknown8Bytes; \
uint unknownInt; \
vector<byte > unknown54Bytes; \
Link palette; \
uint bytesPerPixel; \
vector<MipMap > mipmaps; \
ByteArray pixelData; \

#define NI_PIXEL_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Pixel Format" ) \
  return attr_ref(pixelFormat); \
if ( attr_name == "Red Mask" ) \
  return attr_ref(redMask); \
if ( attr_name == "Green Mask" ) \
  return attr_ref(greenMask); \
if ( attr_name == "Blue Mask" ) \
  return attr_ref(blueMask); \
if ( attr_name == "Alpha Mask" ) \
  return attr_ref(alphaMask); \
if ( attr_name == "Bits Per Pixel" ) \
  return attr_ref(bitsPerPixel); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknownInt); \
if ( attr_name == "Palette" ) \
  return attr_ref(palette); \
if ( attr_name == "Bytes Per Pixel" ) \
  return attr_ref(bytesPerPixel); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PIXEL_DATA_PARENTS AData

#define NI_PIXEL_DATA_CONSTRUCT

#define NI_PIXEL_DATA_READ \
uint numMipmaps; \
AData::Read( in, version ); \
NifStream( pixelFormat, in, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( redMask, in, version ); \
  NifStream( greenMask, in, version ); \
  NifStream( blueMask, in, version ); \
  NifStream( alphaMask, in, version ); \
  NifStream( bitsPerPixel, in, version ); \
  unknown8Bytes.resize(8); \
  NifStream( unknown8Bytes, in, version ); \
}; \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A020000 ) ) { \
  NifStream( unknownInt, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
  unknown54Bytes.resize(54); \
  NifStream( unknown54Bytes, in, version ); \
}; \
NifStream( palette, in, version ); \
NifStream( numMipmaps, in, version ); \
NifStream( bytesPerPixel, in, version ); \
mipmaps.resize(numMipmaps); \
NifStream( mipmaps, in, version ); \
NifStream( pixelData, in, version ); \

#define NI_PIXEL_DATA_WRITE \
uint numMipmaps; \
AData::Write( out, version ); \
numMipmaps = uint(mipmaps.size()); \
NifStream( pixelFormat, out, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( redMask, out, version ); \
  NifStream( greenMask, out, version ); \
  NifStream( blueMask, out, version ); \
  NifStream( alphaMask, out, version ); \
  NifStream( bitsPerPixel, out, version ); \
  NifStream( unknown8Bytes, out, version ); \
}; \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A020000 ) ) { \
  NifStream( unknownInt, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknown54Bytes, out, version ); \
}; \
NifStream( palette, out, version ); \
NifStream( numMipmaps, out, version ); \
NifStream( bytesPerPixel, out, version ); \
NifStream( mipmaps, out, version ); \
NifStream( pixelData, out, version ); \

#define NI_PIXEL_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "        Pixel Format:  " << pixelFormat << endl; \
out << "            Red Mask:  " << redMask << endl; \
out << "          Green Mask:  " << greenMask << endl; \
out << "           Blue Mask:  " << blueMask << endl; \
out << "          Alpha Mask:  " << alphaMask << endl; \
out << "      Bits Per Pixel:  " << bitsPerPixel << endl; \
out << "     Unknown 8 Bytes:  -- data not shown --" << endl; \
out << "         Unknown Int:  " << unknownInt << endl; \
out << "    Unknown 54 Bytes:  -- data not shown --" << endl; \
out << "             Palette:  " << palette << endl; \
out << "         Num Mipmaps:  -- calculated --" << endl; \
out << "     Bytes Per Pixel:  " << bytesPerPixel << endl; \
out << "             Mipmaps:  -- data not shown --" << endl; \
out << "          Pixel Data:  " << pixelData << endl; \
return out.str(); \

// 
// Unknown.
//
// - Usually 0?
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_PLANAR_COLLIDER_MEMBERS \
ushort unknownShort; \
float unknownFloat1; \
float unknownFloat2; \
ushort unknownShort2; \
float unknownFloat3; \
float unknownFloat4; \
float unknownFloat5; \
float unknownFloat6; \
float unknownFloat7; \
float unknownFloat8; \
float unknownFloat9; \
float unknownFloat10; \
float unknownFloat11; \
float unknownFloat12; \
float unknownFloat13; \
float unknownFloat14; \
float unknownFloat15; \
float unknownFloat16; \

#define NI_PLANAR_COLLIDER_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknownShort2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknownFloat3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknownFloat4); \
if ( attr_name == "Unknown Float 5" ) \
  return attr_ref(unknownFloat5); \
if ( attr_name == "Unknown Float 6" ) \
  return attr_ref(unknownFloat6); \
if ( attr_name == "Unknown Float 7" ) \
  return attr_ref(unknownFloat7); \
if ( attr_name == "Unknown Float 8" ) \
  return attr_ref(unknownFloat8); \
if ( attr_name == "Unknown Float 9" ) \
  return attr_ref(unknownFloat9); \
if ( attr_name == "Unknown Float 10" ) \
  return attr_ref(unknownFloat10); \
if ( attr_name == "Unknown Float 11" ) \
  return attr_ref(unknownFloat11); \
if ( attr_name == "Unknown Float 12" ) \
  return attr_ref(unknownFloat12); \
if ( attr_name == "Unknown Float 13" ) \
  return attr_ref(unknownFloat13); \
if ( attr_name == "Unknown Float 14" ) \
  return attr_ref(unknownFloat14); \
if ( attr_name == "Unknown Float 15" ) \
  return attr_ref(unknownFloat15); \
if ( attr_name == "Unknown Float 16" ) \
  return attr_ref(unknownFloat16); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PLANAR_COLLIDER_PARENTS AParticleModifier

#define NI_PLANAR_COLLIDER_CONSTRUCT

#define NI_PLANAR_COLLIDER_READ \
AParticleModifier::Read( in, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( unknownShort, in, version ); \
}; \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
if ( ( version >= 0x04020200 ) && ( version <= 0x04020200 ) ) { \
  NifStream( unknownShort2, in, version ); \
}; \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \
NifStream( unknownFloat5, in, version ); \
NifStream( unknownFloat6, in, version ); \
NifStream( unknownFloat7, in, version ); \
NifStream( unknownFloat8, in, version ); \
NifStream( unknownFloat9, in, version ); \
NifStream( unknownFloat10, in, version ); \
NifStream( unknownFloat11, in, version ); \
NifStream( unknownFloat12, in, version ); \
NifStream( unknownFloat13, in, version ); \
NifStream( unknownFloat14, in, version ); \
NifStream( unknownFloat15, in, version ); \
NifStream( unknownFloat16, in, version ); \

#define NI_PLANAR_COLLIDER_WRITE \
AParticleModifier::Write( out, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( unknownShort, out, version ); \
}; \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
if ( ( version >= 0x04020200 ) && ( version <= 0x04020200 ) ) { \
  NifStream( unknownShort2, out, version ); \
}; \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \
NifStream( unknownFloat5, out, version ); \
NifStream( unknownFloat6, out, version ); \
NifStream( unknownFloat7, out, version ); \
NifStream( unknownFloat8, out, version ); \
NifStream( unknownFloat9, out, version ); \
NifStream( unknownFloat10, out, version ); \
NifStream( unknownFloat11, out, version ); \
NifStream( unknownFloat12, out, version ); \
NifStream( unknownFloat13, out, version ); \
NifStream( unknownFloat14, out, version ); \
NifStream( unknownFloat15, out, version ); \
NifStream( unknownFloat16, out, version ); \

#define NI_PLANAR_COLLIDER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "     Unknown Short 2:  " << unknownShort2 << endl; \
out << "     Unknown Float 3:  " << unknownFloat3 << endl; \
out << "     Unknown Float 4:  " << unknownFloat4 << endl; \
out << "     Unknown Float 5:  " << unknownFloat5 << endl; \
out << "     Unknown Float 6:  " << unknownFloat6 << endl; \
out << "     Unknown Float 7:  " << unknownFloat7 << endl; \
out << "     Unknown Float 8:  " << unknownFloat8 << endl; \
out << "     Unknown Float 9:  " << unknownFloat9 << endl; \
out << "    Unknown Float 10:  " << unknownFloat10 << endl; \
out << "    Unknown Float 11:  " << unknownFloat11 << endl; \
out << "    Unknown Float 12:  " << unknownFloat12 << endl; \
out << "    Unknown Float 13:  " << unknownFloat13 << endl; \
out << "    Unknown Float 14:  " << unknownFloat14 << endl; \
out << "    Unknown Float 15:  " << unknownFloat15 << endl; \
out << "    Unknown Float 16:  " << unknownFloat16 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Value when posed?  Value at time 0?
// - Reference to NiPosData.
#define NI_POINT3_INTERPOLATOR_MEMBERS \
Vector3 point3Value; \
Link data; \

#define NI_POINT3_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Point 3 Value" ) \
  return attr_ref(point3Value); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_POINT3_INTERPOLATOR_PARENTS AInterpolator

#define NI_POINT3_INTERPOLATOR_CONSTRUCT

#define NI_POINT3_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( point3Value, in, version ); \
NifStream( data, in, version ); \

#define NI_POINT3_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( point3Value, out, version ); \
NifStream( data, out, version ); \

#define NI_POINT3_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "       Point 3 Value:  " << point3Value << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// A point light.
//
#define NI_POINT_LIGHT_MEMBERS \

#define NI_POINT_LIGHT_GETATTR \
attr_ref attr = APointLight::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_POINT_LIGHT_PARENTS APointLight

#define NI_POINT_LIGHT_CONSTRUCT

#define NI_POINT_LIGHT_READ \
APointLight::Read( in, version ); \

#define NI_POINT_LIGHT_WRITE \
APointLight::Write( out, version ); \

#define NI_POINT_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APointLight::asString(); \
return out.str(); \

// 
// Position data.
//
// - The position keys.
#define NI_POS_DATA_MEMBERS \
VectorKeyArray<Vector3 > data; \

#define NI_POS_DATA_GETATTR \
attr_ref attr = AKeyedData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_POS_DATA_PARENTS AKeyedData

#define NI_POS_DATA_CONSTRUCT

#define NI_POS_DATA_READ \
AKeyedData::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_POS_DATA_WRITE \
AKeyedData::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_POS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyedData::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Unknown particle modifier.
//
// - Unknown.
// - Link to NiPSysSpawnModifier block?
#define NI_P_SYS_AGE_DEATH_MODIFIER_MEMBERS \
bool spawnOnDeath; \
Link spawnModifier; \

#define NI_P_SYS_AGE_DEATH_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Spawn on Death" ) \
  return attr_ref(spawnOnDeath); \
if ( attr_name == "Spawn Modifier" ) \
  return attr_ref(spawnModifier); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT

#define NI_P_SYS_AGE_DEATH_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( spawnOnDeath, in, version ); \
NifStream( spawnModifier, in, version ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( spawnOnDeath, out, version ); \
NifStream( spawnModifier, out, version ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "      Spawn on Death:  " << spawnOnDeath << endl; \
out << "      Spawn Modifier:  " << spawnModifier << endl; \
return out.str(); \

// 
// Unknown.
//
// - Link to a node.
// - Not sure, could be floats as well. Zero.
// - Unknown.
// - Unknown.
#define NI_P_SYS_BOMB_MODIFIER_MEMBERS \
CrossRef unknownLink; \
vector<uint > unknownInts1; \
vector<float > unknownFloats; \
vector<uint > unknownInts2; \

#define NI_P_SYS_BOMB_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknownLink); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_BOMB_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_BOMB_MODIFIER_CONSTRUCT

#define NI_P_SYS_BOMB_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( unknownLink, in, version ); \
unknownInts1.resize(2); \
NifStream( unknownInts1, in, version ); \
unknownFloats.resize(3); \
NifStream( unknownFloats, in, version ); \
unknownInts2.resize(2); \
NifStream( unknownInts2, in, version ); \

#define NI_P_SYS_BOMB_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( unknownLink, out, version ); \
NifStream( unknownInts1, out, version ); \
NifStream( unknownFloats, out, version ); \
NifStream( unknownInts2, out, version ); \

#define NI_P_SYS_BOMB_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "        Unknown Link:  " << unknownLink << endl; \
out << "      Unknown Ints 1:  -- data not shown --" << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "      Unknown Ints 2:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown particle system modifier.
//
// - Unknown.
#define NI_P_SYS_BOUND_UPDATE_MODIFIER_MEMBERS \
ushort updateSkip; \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Update Skip" ) \
  return attr_ref(updateSkip); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_CONSTRUCT

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( updateSkip, in, version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( updateSkip, out, version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "         Update Skip:  " << updateSkip << endl; \
return out.str(); \

// 
// Unknown particle modifier.
//
// - Width of the boxes to emit?
// - Height of the boxes to emit?
// - Depth of the boxes to emit?
#define NI_P_SYS_BOX_EMITTER_MEMBERS \
float width; \
float height; \
float depth; \

#define NI_P_SYS_BOX_EMITTER_GETATTR \
attr_ref attr = APSysVolumeEmitter::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Width" ) \
  return attr_ref(width); \
if ( attr_name == "Height" ) \
  return attr_ref(height); \
if ( attr_name == "Depth" ) \
  return attr_ref(depth); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_BOX_EMITTER_PARENTS APSysVolumeEmitter

#define NI_P_SYS_BOX_EMITTER_CONSTRUCT

#define NI_P_SYS_BOX_EMITTER_READ \
APSysVolumeEmitter::Read( in, version ); \
NifStream( width, in, version ); \
NifStream( height, in, version ); \
NifStream( depth, in, version ); \

#define NI_P_SYS_BOX_EMITTER_WRITE \
APSysVolumeEmitter::Write( out, version ); \
NifStream( width, out, version ); \
NifStream( height, out, version ); \
NifStream( depth, out, version ); \

#define NI_P_SYS_BOX_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysVolumeEmitter::asString(); \
out << "               Width:  " << width << endl; \
out << "              Height:  " << height << endl; \
out << "               Depth:  " << depth << endl; \
return out.str(); \

// 
// Unknown.
//
// - Link to NiPSysPlanarCollider.
#define NI_P_SYS_COLLIDER_MANAGER_MEMBERS \
Link collider; \

#define NI_P_SYS_COLLIDER_MANAGER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Collider" ) \
  return attr_ref(collider); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_COLLIDER_MANAGER_PARENTS APSysModifier

#define NI_P_SYS_COLLIDER_MANAGER_CONSTRUCT

#define NI_P_SYS_COLLIDER_MANAGER_READ \
APSysModifier::Read( in, version ); \
NifStream( collider, in, version ); \

#define NI_P_SYS_COLLIDER_MANAGER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( collider, out, version ); \

#define NI_P_SYS_COLLIDER_MANAGER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "            Collider:  " << collider << endl; \
return out.str(); \

// 
// Unknown particle modifier.
//
// - Refers to NiColorData block.
#define NI_P_SYS_COLOR_MODIFIER_MEMBERS \
Link data; \

#define NI_P_SYS_COLOR_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_COLOR_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_COLOR_MODIFIER_CONSTRUCT

#define NI_P_SYS_COLOR_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_P_SYS_COLOR_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_P_SYS_COLOR_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Unknown.
//
// - Radius of cylinders to emit?
// - Height of cylinders to emit?
#define NI_P_SYS_CYLINDER_EMITTER_MEMBERS \
float radius; \
float height; \

#define NI_P_SYS_CYLINDER_EMITTER_GETATTR \
attr_ref attr = APSysVolumeEmitter::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Radius" ) \
  return attr_ref(radius); \
if ( attr_name == "Height" ) \
  return attr_ref(height); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_CYLINDER_EMITTER_PARENTS APSysVolumeEmitter

#define NI_P_SYS_CYLINDER_EMITTER_CONSTRUCT

#define NI_P_SYS_CYLINDER_EMITTER_READ \
APSysVolumeEmitter::Read( in, version ); \
NifStream( radius, in, version ); \
NifStream( height, in, version ); \

#define NI_P_SYS_CYLINDER_EMITTER_WRITE \
APSysVolumeEmitter::Write( out, version ); \
NifStream( radius, out, version ); \
NifStream( height, out, version ); \

#define NI_P_SYS_CYLINDER_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysVolumeEmitter::asString(); \
out << "              Radius:  " << radius << endl; \
out << "              Height:  " << height << endl; \
return out.str(); \

// 
// Particle system data.
//
// - Unknown.
// - Unknown.
// - Unknown
// - Unknown (this is a very wild guess!).
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_P_SYS_DATA_MEMBERS \
vector<vector<float > > unknownFloats4; \
bool unknownBool1; \
vector<vector<byte > > unknownBytes; \
vector<vector<byte > > unknownBytesAlt; \
byte unknownByte3; \
bool unknownBool2; \
vector<vector<byte > > unknownBytes2; \
uint unknownInt1; \

#define NI_P_SYS_DATA_GETATTR \
attr_ref attr = APSysData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Bool 1" ) \
  return attr_ref(unknownBool1); \
if ( attr_name == "Unknown Byte 3" ) \
  return attr_ref(unknownByte3); \
if ( attr_name == "Unknown Bool 2" ) \
  return attr_ref(unknownBool2); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_DATA_PARENTS APSysData

#define NI_P_SYS_DATA_CONSTRUCT

#define NI_P_SYS_DATA_READ \
APSysData::Read( in, version ); \
if ( version <= 0x0A020000 ) { \
  unknownFloats4.resize(numVertices); \
  NifStream( unknownFloats4, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknownBool1, in, version ); \
  if ( unknownBool1 != 0 ) { \
    unknownBytes.resize(numVertices); \
    NifStream( unknownBytes, in, version ); \
  }; \
  if ( unknownBool1 == 0 ) { \
    unknownBytesAlt.resize(numVertices); \
    NifStream( unknownBytesAlt, in, version ); \
  }; \
  NifStream( unknownByte3, in, version ); \
  NifStream( unknownBool2, in, version ); \
  if ( unknownBool2 != 0 ) { \
    unknownBytes2.resize(numVertices); \
    NifStream( unknownBytes2, in, version ); \
  }; \
}; \
NifStream( unknownInt1, in, version ); \

#define NI_P_SYS_DATA_WRITE \
APSysData::Write( out, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( unknownFloats4, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknownBool1, out, version ); \
  if ( unknownBool1 != 0 ) { \
    NifStream( unknownBytes, out, version ); \
  }; \
  if ( unknownBool1 == 0 ) { \
    NifStream( unknownBytesAlt, out, version ); \
  }; \
  NifStream( unknownByte3, out, version ); \
  NifStream( unknownBool2, out, version ); \
  if ( unknownBool2 != 0 ) { \
    NifStream( unknownBytes2, out, version ); \
  }; \
}; \
NifStream( unknownInt1, out, version ); \

#define NI_P_SYS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysData::asString(); \
out << "    Unknown Floats 4:  -- data not shown --" << endl; \
out << "      Unknown Bool 1:  " << unknownBool1 << endl; \
out << "       Unknown Bytes:  -- data not shown --" << endl; \
out << "   Unknown Bytes Alt:  -- data not shown --" << endl; \
out << "      Unknown Byte 3:  " << unknownByte3 << endl; \
out << "      Unknown Bool 2:  " << unknownBool2 << endl; \
out << "     Unknown Bytes 2:  -- data not shown --" << endl; \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Parent reference.
// - Unknown floats.
#define NI_P_SYS_DRAG_MODIFIER_MEMBERS \
uint parent; \
vector<float > unknownFloats; \

#define NI_P_SYS_DRAG_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Parent" ) \
  return attr_ref(parent); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_DRAG_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_DRAG_MODIFIER_CONSTRUCT

#define NI_P_SYS_DRAG_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( parent, in, version ); \
unknownFloats.resize(6); \
NifStream( unknownFloats, in, version ); \

#define NI_P_SYS_DRAG_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( parent, out, version ); \
NifStream( unknownFloats, out, version ); \

#define NI_P_SYS_DRAG_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "              Parent:  " << parent << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
return out.str(); \

// 
// Particle system emitter controller.
//
// - Particle system controller data.
#define NI_P_SYS_EMITTER_CTLR_MEMBERS \
Link data; \

#define NI_P_SYS_EMITTER_CTLR_GETATTR \
attr_ref attr = APSysCtlr::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_EMITTER_CTLR_PARENTS APSysCtlr

#define NI_P_SYS_EMITTER_CTLR_CONSTRUCT

#define NI_P_SYS_EMITTER_CTLR_READ \
APSysCtlr::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_P_SYS_EMITTER_CTLR_WRITE \
APSysCtlr::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_P_SYS_EMITTER_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysCtlr::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Particle system emitter controller data.
//
// - Unknown.
// - Unknown.
#define NI_P_SYS_EMITTER_CTLR_DATA_MEMBERS \
VectorKeyArray<float > floatKeys_; \
KeyArray<byte > visibilityKeys_; \

#define NI_P_SYS_EMITTER_CTLR_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_EMITTER_CTLR_DATA_PARENTS AData

#define NI_P_SYS_EMITTER_CTLR_DATA_CONSTRUCT

#define NI_P_SYS_EMITTER_CTLR_DATA_READ \
AData::Read( in, version ); \
NifStream( floatKeys_, in, version ); \
NifStream( visibilityKeys_, in, version ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_WRITE \
AData::Write( out, version ); \
NifStream( floatKeys_, out, version ); \
NifStream( visibilityKeys_, out, version ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Float Keys?:  " << floatKeys_ << endl; \
out << "    Visibility Keys?:  " << visibilityKeys_ << endl; \
return out.str(); \

// 
// Unknown.
//
#define NI_P_SYS_EMITTER_DECLINATION_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_GETATTR \
attr_ref attr = APSysCtlr::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_PARENTS APSysCtlr

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_CONSTRUCT

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_READ \
APSysCtlr::Read( in, version ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_WRITE \
APSysCtlr::Write( out, version ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysCtlr::asString(); \
return out.str(); \

// 
// Unknown.
//
#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_GETATTR \
attr_ref attr = APSysCtlr::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_PARENTS APSysCtlr

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_CONSTRUCT

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_READ \
APSysCtlr::Read( in, version ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_WRITE \
APSysCtlr::Write( out, version ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysCtlr::asString(); \
return out.str(); \

// 
// Unknown.
//
#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_GETATTR \
attr_ref attr = APSysCtlr::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_PARENTS APSysCtlr

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_CONSTRUCT

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_READ \
APSysCtlr::Read( in, version ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_WRITE \
APSysCtlr::Write( out, version ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysCtlr::asString(); \
return out.str(); \

// 
// Unknown.
//
#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_GETATTR \
attr_ref attr = APSysCtlr::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_PARENTS APSysCtlr

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_CONSTRUCT

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_READ \
APSysCtlr::Read( in, version ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_WRITE \
APSysCtlr::Write( out, version ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysCtlr::asString(); \
return out.str(); \

// 
// Unknown.
//
#define NI_P_SYS_EMITTER_SPEED_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_SPEED_CTLR_GETATTR \
attr_ref attr = APSysCtlr::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_PARENTS APSysCtlr

#define NI_P_SYS_EMITTER_SPEED_CTLR_CONSTRUCT

#define NI_P_SYS_EMITTER_SPEED_CTLR_READ \
APSysCtlr::Read( in, version ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_WRITE \
APSysCtlr::Write( out, version ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysCtlr::asString(); \
return out.str(); \

// 
// Unknown particle system modifier.
//
// - Refers to a NiNode.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.  Can only get it to say FORCE_PLANAR or Unknown so far.  Usual value is 1.0.
#define NI_P_SYS_GRAVITY_MODIFIER_MEMBERS \
CrossRef gravityObject; \
Vector3 gravityAxis; \
float decay; \
float strength; \
float turbulence; \
float turbulenceScale; \
float forceType; \

#define NI_P_SYS_GRAVITY_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Gravity Object" ) \
  return attr_ref(gravityObject); \
if ( attr_name == "Gravity Axis" ) \
  return attr_ref(gravityAxis); \
if ( attr_name == "Decay" ) \
  return attr_ref(decay); \
if ( attr_name == "Strength" ) \
  return attr_ref(strength); \
if ( attr_name == "Turbulence" ) \
  return attr_ref(turbulence); \
if ( attr_name == "Turbulence Scale" ) \
  return attr_ref(turbulenceScale); \
if ( attr_name == "Force Type" ) \
  return attr_ref(forceType); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_GRAVITY_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_GRAVITY_MODIFIER_CONSTRUCT

#define NI_P_SYS_GRAVITY_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( gravityObject, in, version ); \
NifStream( gravityAxis, in, version ); \
NifStream( decay, in, version ); \
NifStream( strength, in, version ); \
NifStream( turbulence, in, version ); \
NifStream( turbulenceScale, in, version ); \
NifStream( forceType, in, version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( gravityObject, out, version ); \
NifStream( gravityAxis, out, version ); \
NifStream( decay, out, version ); \
NifStream( strength, out, version ); \
NifStream( turbulence, out, version ); \
NifStream( turbulenceScale, out, version ); \
NifStream( forceType, out, version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "      Gravity Object:  " << gravityObject << endl; \
out << "        Gravity Axis:  " << gravityAxis << endl; \
out << "               Decay:  " << decay << endl; \
out << "            Strength:  " << strength << endl; \
out << "          Turbulence:  " << turbulence << endl; \
out << "    Turbulence Scale:  " << turbulenceScale << endl; \
out << "          Force Type:  " << forceType << endl; \
return out.str(); \

// 
// Unknown.
//
#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_MEMBERS \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_GETATTR \
attr_ref attr = APSysCtlr::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_PARENTS APSysCtlr

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_CONSTRUCT

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_READ \
APSysCtlr::Read( in, version ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_WRITE \
APSysCtlr::Write( out, version ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysCtlr::asString(); \
return out.str(); \

// 
// Unknown particle system modifier.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_P_SYS_GROW_FADE_MODIFIER_MEMBERS \
float growTime; \
ushort growGeneration; \
float fadeTime; \
ushort fadeGeneration; \

#define NI_P_SYS_GROW_FADE_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Grow Time" ) \
  return attr_ref(growTime); \
if ( attr_name == "Grow Generation" ) \
  return attr_ref(growGeneration); \
if ( attr_name == "Fade Time" ) \
  return attr_ref(fadeTime); \
if ( attr_name == "Fade Generation" ) \
  return attr_ref(fadeGeneration); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_GROW_FADE_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_GROW_FADE_MODIFIER_CONSTRUCT

#define NI_P_SYS_GROW_FADE_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( growTime, in, version ); \
NifStream( growGeneration, in, version ); \
NifStream( fadeTime, in, version ); \
NifStream( fadeGeneration, in, version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( growTime, out, version ); \
NifStream( growGeneration, out, version ); \
NifStream( fadeTime, out, version ); \
NifStream( fadeGeneration, out, version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "           Grow Time:  " << growTime << endl; \
out << "     Grow Generation:  " << growGeneration << endl; \
out << "           Fade Time:  " << fadeTime << endl; \
out << "     Fade Generation:  " << fadeGeneration << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_P_SYS_MESH_EMITTER_MEMBERS \
LinkGroup unknownLinkGroup; \
vector<uint > unknownInts1; \
float unknownFloat; \
vector<uint > unknownInts2; \

#define NI_P_SYS_MESH_EMITTER_GETATTR \
attr_ref attr = APSysEmitter::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknownFloat); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_MESH_EMITTER_PARENTS APSysEmitter

#define NI_P_SYS_MESH_EMITTER_CONSTRUCT

#define NI_P_SYS_MESH_EMITTER_READ \
APSysEmitter::Read( in, version ); \
NifStream( unknownLinkGroup, in, version ); \
unknownInts1.resize(2); \
NifStream( unknownInts1, in, version ); \
NifStream( unknownFloat, in, version ); \
unknownInts2.resize(2); \
NifStream( unknownInts2, in, version ); \

#define NI_P_SYS_MESH_EMITTER_WRITE \
APSysEmitter::Write( out, version ); \
NifStream( unknownLinkGroup, out, version ); \
NifStream( unknownInts1, out, version ); \
NifStream( unknownFloat, out, version ); \
NifStream( unknownInts2, out, version ); \

#define NI_P_SYS_MESH_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysEmitter::asString(); \
out << "  Unknown Link Group:  " << unknownLinkGroup << endl; \
out << "      Unknown Ints 1:  -- data not shown --" << endl; \
out << "       Unknown Float:  " << unknownFloat << endl; \
out << "      Unknown Ints 2:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
// - Not sure here... Group of target NiNodes?
#define NI_P_SYS_MESH_UPDATE_MODIFIER_MEMBERS \
LinkGroup meshes; \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_MESH_UPDATE_MODIFIER_CONSTRUCT

#define NI_P_SYS_MESH_UPDATE_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( meshes, in, version ); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( meshes, out, version ); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "              Meshes:  " << meshes << endl; \
return out.str(); \

// 
// Unknown.
//
#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_MEMBERS \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_GETATTR \
attr_ref attr = APSysCtlr::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_PARENTS APSysCtlr

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_CONSTRUCT

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_READ \
APSysCtlr::Read( in, version ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_WRITE \
APSysCtlr::Write( out, version ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysCtlr::asString(); \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Link to NiPSysSpawnModifier block?
// - Link to parent.
// - Unknown link?  Usually -1
// - Link to a NiNode?
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_P_SYS_PLANAR_COLLIDER_MEMBERS \
float bounce; \
bool spawnOnCollide; \
bool dieOnCollide; \
Link spawnModifier; \
uint parent; \
Link unknownLink_; \
Link colliderObject; \
float width; \
float height; \
Vector3 xAxis; \
Vector3 yAxis; \

#define NI_P_SYS_PLANAR_COLLIDER_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Bounce" ) \
  return attr_ref(bounce); \
if ( attr_name == "Spawn on Collide" ) \
  return attr_ref(spawnOnCollide); \
if ( attr_name == "Die on Collide" ) \
  return attr_ref(dieOnCollide); \
if ( attr_name == "Spawn Modifier" ) \
  return attr_ref(spawnModifier); \
if ( attr_name == "Parent" ) \
  return attr_ref(parent); \
if ( attr_name == "Unknown Link?" ) \
  return attr_ref(unknownLink_); \
if ( attr_name == "Collider Object" ) \
  return attr_ref(colliderObject); \
if ( attr_name == "Width" ) \
  return attr_ref(width); \
if ( attr_name == "Height" ) \
  return attr_ref(height); \
if ( attr_name == "X Axis" ) \
  return attr_ref(xAxis); \
if ( attr_name == "Y Axis" ) \
  return attr_ref(yAxis); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_PLANAR_COLLIDER_PARENTS AData

#define NI_P_SYS_PLANAR_COLLIDER_CONSTRUCT

#define NI_P_SYS_PLANAR_COLLIDER_READ \
AData::Read( in, version ); \
NifStream( bounce, in, version ); \
NifStream( spawnOnCollide, in, version ); \
NifStream( dieOnCollide, in, version ); \
NifStream( spawnModifier, in, version ); \
NifStream( parent, in, version ); \
NifStream( unknownLink_, in, version ); \
NifStream( colliderObject, in, version ); \
NifStream( width, in, version ); \
NifStream( height, in, version ); \
NifStream( xAxis, in, version ); \
NifStream( yAxis, in, version ); \

#define NI_P_SYS_PLANAR_COLLIDER_WRITE \
AData::Write( out, version ); \
NifStream( bounce, out, version ); \
NifStream( spawnOnCollide, out, version ); \
NifStream( dieOnCollide, out, version ); \
NifStream( spawnModifier, out, version ); \
NifStream( parent, out, version ); \
NifStream( unknownLink_, out, version ); \
NifStream( colliderObject, out, version ); \
NifStream( width, out, version ); \
NifStream( height, out, version ); \
NifStream( xAxis, out, version ); \
NifStream( yAxis, out, version ); \

#define NI_P_SYS_PLANAR_COLLIDER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "              Bounce:  " << bounce << endl; \
out << "    Spawn on Collide:  " << spawnOnCollide << endl; \
out << "      Die on Collide:  " << dieOnCollide << endl; \
out << "      Spawn Modifier:  " << spawnModifier << endl; \
out << "              Parent:  " << parent << endl; \
out << "       Unknown Link?:  " << unknownLink_ << endl; \
out << "     Collider Object:  " << colliderObject << endl; \
out << "               Width:  " << width << endl; \
out << "              Height:  " << height << endl; \
out << "              X Axis:  " << xAxis << endl; \
out << "              Y Axis:  " << yAxis << endl; \
return out.str(); \

// 
// Unknown particle system modifier.
//
#define NI_P_SYS_POSITION_MODIFIER_MEMBERS \

#define NI_P_SYS_POSITION_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_POSITION_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_POSITION_MODIFIER_CONSTRUCT

#define NI_P_SYS_POSITION_MODIFIER_READ \
APSysModifier::Read( in, version ); \

#define NI_P_SYS_POSITION_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \

#define NI_P_SYS_POSITION_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
return out.str(); \

// 
// Unknown.
//
#define NI_P_SYS_RESET_ON_LOOP_CTLR_MEMBERS \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_PARENTS AController

#define NI_P_SYS_RESET_ON_LOOP_CTLR_CONSTRUCT

#define NI_P_SYS_RESET_ON_LOOP_CTLR_READ \
AController::Read( in, version ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_WRITE \
AController::Write( out, version ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
return out.str(); \

// 
// Unknown particle system modifier.
//
// - Unknown.
// - Unknown
// - Unknown.
// - Unknown.
// - Unknown
// - Unknown.
// - Unknown.
#define NI_P_SYS_ROTATION_MODIFIER_MEMBERS \
float initialRotationSpeed; \
float initialRotationSpeedVariation; \
float initialRotationAngle; \
float initialRotationAngleVariation; \
bool randomRotSpeedSign; \
bool randomInitialAxis; \
Vector3 initialAxis; \

#define NI_P_SYS_ROTATION_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Initial Rotation Speed" ) \
  return attr_ref(initialRotationSpeed); \
if ( attr_name == "Initial Rotation Speed Variation" ) \
  return attr_ref(initialRotationSpeedVariation); \
if ( attr_name == "Initial Rotation Angle" ) \
  return attr_ref(initialRotationAngle); \
if ( attr_name == "Initial Rotation Angle Variation" ) \
  return attr_ref(initialRotationAngleVariation); \
if ( attr_name == "Random Rot Speed Sign" ) \
  return attr_ref(randomRotSpeedSign); \
if ( attr_name == "Random Initial Axis" ) \
  return attr_ref(randomInitialAxis); \
if ( attr_name == "Initial Axis" ) \
  return attr_ref(initialAxis); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_ROTATION_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_ROTATION_MODIFIER_CONSTRUCT

#define NI_P_SYS_ROTATION_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( initialRotationSpeed, in, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( initialRotationSpeedVariation, in, version ); \
  NifStream( initialRotationAngle, in, version ); \
  NifStream( initialRotationAngleVariation, in, version ); \
  NifStream( randomRotSpeedSign, in, version ); \
}; \
NifStream( randomInitialAxis, in, version ); \
NifStream( initialAxis, in, version ); \

#define NI_P_SYS_ROTATION_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( initialRotationSpeed, out, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( initialRotationSpeedVariation, out, version ); \
  NifStream( initialRotationAngle, out, version ); \
  NifStream( initialRotationAngleVariation, out, version ); \
  NifStream( randomRotSpeedSign, out, version ); \
}; \
NifStream( randomInitialAxis, out, version ); \
NifStream( initialAxis, out, version ); \

#define NI_P_SYS_ROTATION_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "Initial Rotation Speed:  " << initialRotationSpeed << endl; \
out << "Initial Rotation Speed Variation:  " << initialRotationSpeedVariation << endl; \
out << "Initial Rotation Angle:  " << initialRotationAngle << endl; \
out << "Initial Rotation Angle Variation:  " << initialRotationAngleVariation << endl; \
out << "Random Rot Speed Sign:  " << randomRotSpeedSign << endl; \
out << " Random Initial Axis:  " << randomInitialAxis << endl; \
out << "        Initial Axis:  " << initialAxis << endl; \
return out.str(); \

// 
// Unknown particle modifier.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_P_SYS_SPAWN_MODIFIER_MEMBERS \
ushort numSpawnGenerations; \
float percentageSpawned; \
ushort minNumToSpawn; \
ushort maxNumToSpawn; \
float spawnSpeedChaos; \
float spawnDirChaos; \
float lifeSpan; \
float lifeSpanVariation; \

#define NI_P_SYS_SPAWN_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Spawn Generations" ) \
  return attr_ref(numSpawnGenerations); \
if ( attr_name == "Percentage Spawned" ) \
  return attr_ref(percentageSpawned); \
if ( attr_name == "Min Num to Spawn" ) \
  return attr_ref(minNumToSpawn); \
if ( attr_name == "Max Num to Spawn" ) \
  return attr_ref(maxNumToSpawn); \
if ( attr_name == "Spawn Speed Chaos" ) \
  return attr_ref(spawnSpeedChaos); \
if ( attr_name == "Spawn Dir Chaos" ) \
  return attr_ref(spawnDirChaos); \
if ( attr_name == "Life Span" ) \
  return attr_ref(lifeSpan); \
if ( attr_name == "Life Span Variation" ) \
  return attr_ref(lifeSpanVariation); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_SPAWN_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_SPAWN_MODIFIER_CONSTRUCT

#define NI_P_SYS_SPAWN_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( numSpawnGenerations, in, version ); \
NifStream( percentageSpawned, in, version ); \
NifStream( minNumToSpawn, in, version ); \
NifStream( maxNumToSpawn, in, version ); \
NifStream( spawnSpeedChaos, in, version ); \
NifStream( spawnDirChaos, in, version ); \
NifStream( lifeSpan, in, version ); \
NifStream( lifeSpanVariation, in, version ); \

#define NI_P_SYS_SPAWN_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( numSpawnGenerations, out, version ); \
NifStream( percentageSpawned, out, version ); \
NifStream( minNumToSpawn, out, version ); \
NifStream( maxNumToSpawn, out, version ); \
NifStream( spawnSpeedChaos, out, version ); \
NifStream( spawnDirChaos, out, version ); \
NifStream( lifeSpan, out, version ); \
NifStream( lifeSpanVariation, out, version ); \

#define NI_P_SYS_SPAWN_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "Num Spawn Generations:  " << numSpawnGenerations << endl; \
out << "  Percentage Spawned:  " << percentageSpawned << endl; \
out << "    Min Num to Spawn:  " << minNumToSpawn << endl; \
out << "    Max Num to Spawn:  " << maxNumToSpawn << endl; \
out << "   Spawn Speed Chaos:  " << spawnSpeedChaos << endl; \
out << "     Spawn Dir Chaos:  " << spawnDirChaos << endl; \
out << "           Life Span:  " << lifeSpan << endl; \
out << " Life Span Variation:  " << lifeSpanVariation << endl; \
return out.str(); \

// 
// Unknown.
//
// - Radius of spheres to emit?
#define NI_P_SYS_SPHERE_EMITTER_MEMBERS \
float radius; \

#define NI_P_SYS_SPHERE_EMITTER_GETATTR \
attr_ref attr = APSysVolumeEmitter::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Radius" ) \
  return attr_ref(radius); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_SPHERE_EMITTER_PARENTS APSysVolumeEmitter

#define NI_P_SYS_SPHERE_EMITTER_CONSTRUCT

#define NI_P_SYS_SPHERE_EMITTER_READ \
APSysVolumeEmitter::Read( in, version ); \
NifStream( radius, in, version ); \

#define NI_P_SYS_SPHERE_EMITTER_WRITE \
APSysVolumeEmitter::Write( out, version ); \
NifStream( radius, out, version ); \

#define NI_P_SYS_SPHERE_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysVolumeEmitter::asString(); \
out << "              Radius:  " << radius << endl; \
return out.str(); \

// 
// Particle system controller, used for ???.
//
#define NI_P_SYS_UPDATE_CTLR_MEMBERS \

#define NI_P_SYS_UPDATE_CTLR_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_UPDATE_CTLR_PARENTS AController

#define NI_P_SYS_UPDATE_CTLR_CONSTRUCT

#define NI_P_SYS_UPDATE_CTLR_READ \
AController::Read( in, version ); \

#define NI_P_SYS_UPDATE_CTLR_WRITE \
AController::Write( out, version ); \

#define NI_P_SYS_UPDATE_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
return out.str(); \

// 
// Describes levels of detail.
//
// - ?
// - The ranges of distance that each level of detail applies in.
#define NI_RANGE_L_O_D_DATA_MEMBERS \
Vector3 lodCenter; \
vector<LODRange > lodLevels; \

#define NI_RANGE_L_O_D_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "LOD Center" ) \
  return attr_ref(lodCenter); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_RANGE_L_O_D_DATA_PARENTS AData

#define NI_RANGE_L_O_D_DATA_CONSTRUCT

#define NI_RANGE_L_O_D_DATA_READ \
uint numLodLevels; \
AData::Read( in, version ); \
NifStream( lodCenter, in, version ); \
NifStream( numLodLevels, in, version ); \
lodLevels.resize(numLodLevels); \
NifStream( lodLevels, in, version ); \

#define NI_RANGE_L_O_D_DATA_WRITE \
uint numLodLevels; \
AData::Write( out, version ); \
numLodLevels = uint(lodLevels.size()); \
NifStream( lodCenter, out, version ); \
NifStream( numLodLevels, out, version ); \
NifStream( lodLevels, out, version ); \

#define NI_RANGE_L_O_D_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "          LOD Center:  " << lodCenter << endl; \
out << "      Num LOD Levels:  -- calculated --" << endl; \
out << "          LOD Levels:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
#define NI_ROTATING_PARTICLES_MEMBERS \

#define NI_ROTATING_PARTICLES_GETATTR \
attr_ref attr = AParticleNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_ROTATING_PARTICLES_PARENTS AParticleNode

#define NI_ROTATING_PARTICLES_CONSTRUCT

#define NI_ROTATING_PARTICLES_READ \
AParticleNode::Read( in, version ); \

#define NI_ROTATING_PARTICLES_WRITE \
AParticleNode::Write( out, version ); \

#define NI_ROTATING_PARTICLES_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleNode::asString(); \
return out.str(); \

// 
// Rotating particles data block.
//
#define NI_ROTATING_PARTICLES_DATA_MEMBERS \

#define NI_ROTATING_PARTICLES_DATA_GETATTR \
attr_ref attr = ARotatingParticlesData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_ROTATING_PARTICLES_DATA_PARENTS ARotatingParticlesData

#define NI_ROTATING_PARTICLES_DATA_CONSTRUCT

#define NI_ROTATING_PARTICLES_DATA_READ \
ARotatingParticlesData::Read( in, version ); \

#define NI_ROTATING_PARTICLES_DATA_WRITE \
ARotatingParticlesData::Write( out, version ); \

#define NI_ROTATING_PARTICLES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ARotatingParticlesData::asString(); \
return out.str(); \

// 
// Unknown.
//
// - Unknown floats.
// - Unknown.
#define NI_SCREEN_L_O_D_DATA_MEMBERS \
vector<float > unknownFloats; \
vector<float > unknownFloats2; \

#define NI_SCREEN_L_O_D_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SCREEN_L_O_D_DATA_PARENTS AData

#define NI_SCREEN_L_O_D_DATA_CONSTRUCT

#define NI_SCREEN_L_O_D_DATA_READ \
uint unknownCount; \
AData::Read( in, version ); \
unknownFloats.resize(8); \
NifStream( unknownFloats, in, version ); \
NifStream( unknownCount, in, version ); \
unknownFloats2.resize(unknownCount); \
NifStream( unknownFloats2, in, version ); \

#define NI_SCREEN_L_O_D_DATA_WRITE \
uint unknownCount; \
AData::Write( out, version ); \
unknownCount = uint(unknownFloats2.size()); \
NifStream( unknownFloats, out, version ); \
NifStream( unknownCount, out, version ); \
NifStream( unknownFloats2, out, version ); \

#define NI_SCREEN_L_O_D_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "       Unknown Count:  -- calculated --" << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
return out.str(); \

// 
// Keyframe animation root node, in .kf files.
//
#define NI_SEQUENCE_STREAM_HELPER_MEMBERS \

#define NI_SEQUENCE_STREAM_HELPER_GETATTR \
attr_ref attr = AControllable::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SEQUENCE_STREAM_HELPER_PARENTS AControllable

#define NI_SEQUENCE_STREAM_HELPER_CONSTRUCT

#define NI_SEQUENCE_STREAM_HELPER_READ \
AControllable::Read( in, version ); \

#define NI_SEQUENCE_STREAM_HELPER_WRITE \
AControllable::Write( out, version ); \

#define NI_SEQUENCE_STREAM_HELPER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AControllable::asString(); \
return out.str(); \

// 
// Determines whether flat shading or smooth shading is used on a shape.
//
// - 1's Bit:  Enable smooth phong shading on this shape.
// 
// If 1's bit is not set, hard-edged flat shading will be used on this shape.
#define NI_SHADE_PROPERTY_MEMBERS \
Flags flags; \

#define NI_SHADE_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SHADE_PROPERTY_PARENTS AProperty

#define NI_SHADE_PROPERTY_CONSTRUCT

#define NI_SHADE_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \

#define NI_SHADE_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \

#define NI_SHADE_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
return out.str(); \

// 
// Skinning data.
//
// - The overall rotation offset of the skin from this bone in the bind position.
// (This is a guess, it has always been the identity matrix so far)
// - The overall translation offset of the skin from this bone in the bind position. (This is a guess, it has always been (0.0, 0.0, 0.0) so far)
// - The scale offset of the skin from this bone in the bind position. (This is an assumption - it has always been 1.0 so far)
// - This optionally links a NiSkinPartition for hardware-acceleration information.
// - Unknown. Could be a bool conditioning the following block.
// - Contains offset data for each node that this skin is influenced by.
#define NI_SKIN_DATA_MEMBERS \
Matrix33 rotation; \
Vector3 translation; \
float scale; \
Link skinPartition; \
byte unknownByte; \
vector<SkinData > boneList; \

#define NI_SKIN_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Rotation" ) \
  return attr_ref(rotation); \
if ( attr_name == "Translation" ) \
  return attr_ref(translation); \
if ( attr_name == "Scale" ) \
  return attr_ref(scale); \
if ( attr_name == "Skin Partition" ) \
  return attr_ref(skinPartition); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SKIN_DATA_PARENTS AData

#define NI_SKIN_DATA_CONSTRUCT

#define NI_SKIN_DATA_READ \
uint numBones; \
AData::Read( in, version ); \
NifStream( rotation, in, version ); \
NifStream( translation, in, version ); \
NifStream( scale, in, version ); \
NifStream( numBones, in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( skinPartition, in, version ); \
}; \
if ( version >= 0x04020100 ) { \
  NifStream( unknownByte, in, version ); \
}; \
boneList.resize(numBones); \
NifStream( boneList, in, version ); \

#define NI_SKIN_DATA_WRITE \
uint numBones; \
AData::Write( out, version ); \
numBones = uint(boneList.size()); \
NifStream( rotation, out, version ); \
NifStream( translation, out, version ); \
NifStream( scale, out, version ); \
NifStream( numBones, out, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( skinPartition, out, version ); \
}; \
if ( version >= 0x04020100 ) { \
  NifStream( unknownByte, out, version ); \
}; \
NifStream( boneList, out, version ); \

#define NI_SKIN_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "            Rotation:  " << rotation << endl; \
out << "         Translation:  " << translation << endl; \
out << "               Scale:  " << scale << endl; \
out << "           Num Bones:  -- calculated --" << endl; \
out << "      Skin Partition:  " << skinPartition << endl; \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "           Bone List:  -- data not shown --" << endl; \
return out.str(); \

// 
// Skinning instance.
//
// - Skinning data reference.
// - Refers to a NiSkinPartition block, which partitions the mesh such that every vertex is only influenced by a limited number of bones.
// - List of all armature bones.
#define NI_SKIN_INSTANCE_MEMBERS \
Link data; \
Link skinPartition; \
Bones bones; \

#define NI_SKIN_INSTANCE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Skin Partition" ) \
  return attr_ref(skinPartition); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SKIN_INSTANCE_PARENTS AData

#define NI_SKIN_INSTANCE_CONSTRUCT

#define NI_SKIN_INSTANCE_READ \
CrossRef skeletonRoot; \
AData::Read( in, version ); \
NifStream( data, in, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( skinPartition, in, version ); \
}; \
NifStream( bones, in, version ); \

#define NI_SKIN_INSTANCE_WRITE \
CrossRef skeletonRoot; \
AData::Write( out, version ); \
skeletonRoot = SkeletonRoot(); \
NifStream( data, out, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( skinPartition, out, version ); \
}; \
NifStream( bones, out, version ); \

#define NI_SKIN_INSTANCE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Data:  " << data << endl; \
out << "      Skin Partition:  " << skinPartition << endl; \
out << "       Skeleton Root:  -- calculated --" << endl; \
out << "               Bones:  " << bones << endl; \
return out.str(); \

// 
// Skinning data, optimized for hardware skinning. The mesh is partitioned in submeshes such that each vertex of a submesh is influenced only by a limited and fixed number of bones.
//
// - Skin partition blocks.
#define NI_SKIN_PARTITION_MEMBERS \
vector<SkinPartition > skinPartitionBlocks; \

#define NI_SKIN_PARTITION_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SKIN_PARTITION_PARENTS AData

#define NI_SKIN_PARTITION_CONSTRUCT

#define NI_SKIN_PARTITION_READ \
uint numSkinPartitionBlocks; \
AData::Read( in, version ); \
NifStream( numSkinPartitionBlocks, in, version ); \
skinPartitionBlocks.resize(numSkinPartitionBlocks); \
NifStream( skinPartitionBlocks, in, version ); \

#define NI_SKIN_PARTITION_WRITE \
uint numSkinPartitionBlocks; \
AData::Write( out, version ); \
numSkinPartitionBlocks = uint(skinPartitionBlocks.size()); \
NifStream( numSkinPartitionBlocks, out, version ); \
NifStream( skinPartitionBlocks, out, version ); \

#define NI_SKIN_PARTITION_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "Num Skin Partition Blocks:  -- calculated --" << endl; \
out << "Skin Partition Blocks:  -- data not shown --" << endl; \
return out.str(); \

// 
// Describes texture source and properties.
//
// - The source of the texture; an external file or an internal NiPixelData block.
// - 0=palettised, 1=16-bit, 2=32-bit, 3=compressed, 4=bumpmap, 5=default, 6=?
// - 0=no, 1=yes, 2=default
// - 0=ignore texture alpha channel and use material alpha setting (?)
// 1=binary (?)
// 2=smooth (?)
// 3=multiply texture alpha channel with the material alpha setting, or, if there is no texture alpha channel, use material alpha setting as alpha channel; this is the default setting in official Morrowind files
// 
// Note: the NiTriShape linked to this block must have a NiAlphaProperty in its list of properties to enable material and/or texture transparency.
// - Unknown, usually 1.
// - Unknown.
#define NI_SOURCE_TEXTURE_MEMBERS \
TexSource textureSource; \
PixelLayout pixelLayout; \
MipMapFormat useMipmaps; \
AlphaFormat alphaFormat; \
byte unknownByte; \
byte unknownByte2; \

#define NI_SOURCE_TEXTURE_GETATTR \
attr_ref attr = AControllable::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Texture Source" ) \
  return attr_ref(textureSource); \
if ( attr_name == "Pixel Layout" ) \
  return attr_ref(pixelLayout); \
if ( attr_name == "Use Mipmaps" ) \
  return attr_ref(useMipmaps); \
if ( attr_name == "Alpha Format" ) \
  return attr_ref(alphaFormat); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknownByte); \
if ( attr_name == "Unknown Byte 2" ) \
  return attr_ref(unknownByte2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SOURCE_TEXTURE_PARENTS AControllable

#define NI_SOURCE_TEXTURE_CONSTRUCT

#define NI_SOURCE_TEXTURE_READ \
AControllable::Read( in, version ); \
NifStream( textureSource, in, version ); \
NifStream( pixelLayout, in, version ); \
NifStream( useMipmaps, in, version ); \
NifStream( alphaFormat, in, version ); \
NifStream( unknownByte, in, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownByte2, in, version ); \
}; \

#define NI_SOURCE_TEXTURE_WRITE \
AControllable::Write( out, version ); \
NifStream( textureSource, out, version ); \
NifStream( pixelLayout, out, version ); \
NifStream( useMipmaps, out, version ); \
NifStream( alphaFormat, out, version ); \
NifStream( unknownByte, out, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknownByte2, out, version ); \
}; \

#define NI_SOURCE_TEXTURE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AControllable::asString(); \
out << "      Texture Source:  " << textureSource << endl; \
out << "        Pixel Layout:  " << pixelLayout << endl; \
out << "         Use Mipmaps:  " << useMipmaps << endl; \
out << "        Alpha Format:  " << alphaFormat << endl; \
out << "        Unknown Byte:  " << unknownByte << endl; \
out << "      Unknown Byte 2:  " << unknownByte2 << endl; \
return out.str(); \

// 
// Gives specularity to a shape. Flags 0x0001.
//
// - 1's Bit = Enable specular lighting on this shape.
#define NI_SPECULAR_PROPERTY_MEMBERS \
Flags flags; \

#define NI_SPECULAR_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SPECULAR_PROPERTY_PARENTS AProperty

#define NI_SPECULAR_PROPERTY_CONSTRUCT

#define NI_SPECULAR_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \

#define NI_SPECULAR_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \

#define NI_SPECULAR_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_SPHERICAL_COLLIDER_MEMBERS \
float unknownFloat1; \
ushort unknownShort; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \
float unknownFloat5; \

#define NI_SPHERICAL_COLLIDER_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknownFloat1); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknownFloat2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknownFloat3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknownFloat4); \
if ( attr_name == "Unknown Float 5" ) \
  return attr_ref(unknownFloat5); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SPHERICAL_COLLIDER_PARENTS AParticleModifier

#define NI_SPHERICAL_COLLIDER_CONSTRUCT

#define NI_SPHERICAL_COLLIDER_READ \
AParticleModifier::Read( in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownShort, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \
NifStream( unknownFloat5, in, version ); \

#define NI_SPHERICAL_COLLIDER_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownShort, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \
NifStream( unknownFloat5, out, version ); \

#define NI_SPHERICAL_COLLIDER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "     Unknown Float 1:  " << unknownFloat1 << endl; \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "     Unknown Float 2:  " << unknownFloat2 << endl; \
out << "     Unknown Float 3:  " << unknownFloat3 << endl; \
out << "     Unknown Float 4:  " << unknownFloat4 << endl; \
out << "     Unknown Float 5:  " << unknownFloat5 << endl; \
return out.str(); \

// 
// A spot.
//
// - The opening angle of the spot.
// - Describes the distribution of light. (see: glLight)
#define NI_SPOT_LIGHT_MEMBERS \
float cutoffAngle; \
float exponent; \

#define NI_SPOT_LIGHT_GETATTR \
attr_ref attr = APointLight::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Cutoff Angle" ) \
  return attr_ref(cutoffAngle); \
if ( attr_name == "Exponent" ) \
  return attr_ref(exponent); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SPOT_LIGHT_PARENTS APointLight

#define NI_SPOT_LIGHT_CONSTRUCT

#define NI_SPOT_LIGHT_READ \
APointLight::Read( in, version ); \
NifStream( cutoffAngle, in, version ); \
NifStream( exponent, in, version ); \

#define NI_SPOT_LIGHT_WRITE \
APointLight::Write( out, version ); \
NifStream( cutoffAngle, out, version ); \
NifStream( exponent, out, version ); \

#define NI_SPOT_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APointLight::asString(); \
out << "        Cutoff Angle:  " << cutoffAngle << endl; \
out << "            Exponent:  " << exponent << endl; \
return out.str(); \

// 
// Allows control of stencil testing.
//
// - Property flags.
// - Enables or disables the stencil test.
// - 0: TEST_NEVER
// 1: TEST_LESS
// 2: TEST_EQUAL
// 3: TEST_LESSEQUAL
// 4: TEST_GREATER
// 5: TEST_NOTEQUAL
// 6: TEST_GREATEREQUAL
// 7: TEST_ALWAYS
// - Unknown.  Default is 0.
// - This is a signed value and the default is -1.
// - 0: ACTION_KEEP
// 1: ACTION_ZERO
// 2: ACTION_REPLACE
// 3: ACTION_INCREMENT
// 4: ACTION_DECREMENT
// 5: ACTION_INVERT
// - 0: ACTION_KEEP
// 1: ACTION_ZERO
// 2: ACTION_REPLACE
// 3: ACTION_INCREMENT
// 4: ACTION_DECREMENT
// 5: ACTION_INVERT
// - 0: ACTION_KEEP
// 1: ACTION_ZERO
// 2: ACTION_REPLACE
// 3: ACTION_INCREMENT
// 4: ACTION_DECREMENT
// 5: ACTION_INVERT
// - 0: DRAW_CCW_OR_BOTH (? use application defaults ?)
// 1: DRAW_CCW (cull front facing faces)
// 2: DRAW_CW (Backface culling)
// 3: DRAW_BOTH (Double sided faces)
#define NI_STENCIL_PROPERTY_MEMBERS \
Flags flags; \
bool stencilEnabled; \
uint stencilFunction; \
uint stencilRef; \
uint stencilMask; \
uint failAction; \
uint zFailAction; \
uint passAction; \
uint drawMode; \

#define NI_STENCIL_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Stencil Enabled" ) \
  return attr_ref(stencilEnabled); \
if ( attr_name == "Stencil Function" ) \
  return attr_ref(stencilFunction); \
if ( attr_name == "Stencil Ref" ) \
  return attr_ref(stencilRef); \
if ( attr_name == "Stencil Mask" ) \
  return attr_ref(stencilMask); \
if ( attr_name == "Fail Action" ) \
  return attr_ref(failAction); \
if ( attr_name == "Z Fail Action" ) \
  return attr_ref(zFailAction); \
if ( attr_name == "Pass Action" ) \
  return attr_ref(passAction); \
if ( attr_name == "Draw Mode" ) \
  return attr_ref(drawMode); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_STENCIL_PROPERTY_PARENTS AProperty

#define NI_STENCIL_PROPERTY_CONSTRUCT

#define NI_STENCIL_PROPERTY_READ \
AProperty::Read( in, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, in, version ); \
}; \
NifStream( stencilEnabled, in, version ); \
NifStream( stencilFunction, in, version ); \
NifStream( stencilRef, in, version ); \
NifStream( stencilMask, in, version ); \
NifStream( failAction, in, version ); \
NifStream( zFailAction, in, version ); \
NifStream( passAction, in, version ); \
NifStream( drawMode, in, version ); \

#define NI_STENCIL_PROPERTY_WRITE \
AProperty::Write( out, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, out, version ); \
}; \
NifStream( stencilEnabled, out, version ); \
NifStream( stencilFunction, out, version ); \
NifStream( stencilRef, out, version ); \
NifStream( stencilMask, out, version ); \
NifStream( failAction, out, version ); \
NifStream( zFailAction, out, version ); \
NifStream( passAction, out, version ); \
NifStream( drawMode, out, version ); \

#define NI_STENCIL_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "     Stencil Enabled:  " << stencilEnabled << endl; \
out << "    Stencil Function:  " << stencilFunction << endl; \
out << "         Stencil Ref:  " << stencilRef << endl; \
out << "        Stencil Mask:  " << stencilMask << endl; \
out << "         Fail Action:  " << failAction << endl; \
out << "       Z Fail Action:  " << zFailAction << endl; \
out << "         Pass Action:  " << passAction << endl; \
out << "           Draw Mode:  " << drawMode << endl; \
return out.str(); \

// 
// Apparently commands for an optimizer instructing it to keep things it would normally discard.
// Also refers to NiNode blocks (through their name) in animation .kf files.
//
// - The string.
#define NI_STRING_EXTRA_DATA_MEMBERS \
string stringData; \

#define NI_STRING_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "String Data" ) \
  return attr_ref(stringData); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_STRING_EXTRA_DATA_PARENTS AExtraData

#define NI_STRING_EXTRA_DATA_CONSTRUCT

#define NI_STRING_EXTRA_DATA_READ \
uint bytesRemaining; \
AExtraData::Read( in, version ); \
NifStream( stringData, in, version ); \

#define NI_STRING_EXTRA_DATA_WRITE \
uint bytesRemaining; \
AExtraData::Write( out, version ); \
bytesRemaining = BytesRemaining(); \
NifStream( stringData, out, version ); \

#define NI_STRING_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "     Bytes Remaining:  -- calculated --" << endl; \
out << "         String Data:  " << stringData << endl; \
return out.str(); \

// 
// List of 0x00-seperated strings, which are names of controlled blocks and controller types. Used in .kf files in conjunction with NiControllerSequence.
//
// - A bunch of 0x00 seperated strings.
#define NI_STRING_PALETTE_MEMBERS \
StringPalette palette; \

#define NI_STRING_PALETTE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_STRING_PALETTE_PARENTS AData

#define NI_STRING_PALETTE_CONSTRUCT

#define NI_STRING_PALETTE_READ \
AData::Read( in, version ); \
NifStream( palette, in, version ); \

#define NI_STRING_PALETTE_WRITE \
AData::Write( out, version ); \
NifStream( palette, out, version ); \

#define NI_STRING_PALETTE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "             Palette:  " << palette << endl; \
return out.str(); \

// 
// List of strings; for example, a list of all bone names.
//
// - The strings.
#define NI_STRINGS_EXTRA_DATA_MEMBERS \
vector<string > data; \

#define NI_STRINGS_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_STRINGS_EXTRA_DATA_PARENTS AExtraData

#define NI_STRINGS_EXTRA_DATA_CONSTRUCT

#define NI_STRINGS_EXTRA_DATA_READ \
uint numStrings; \
AExtraData::Read( in, version ); \
NifStream( numStrings, in, version ); \
data.resize(numStrings); \
NifStream( data, in, version ); \

#define NI_STRINGS_EXTRA_DATA_WRITE \
uint numStrings; \
AExtraData::Write( out, version ); \
numStrings = uint(data.size()); \
NifStream( numStrings, out, version ); \
NifStream( data, out, version ); \

#define NI_STRINGS_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "         Num Strings:  -- calculated --" << endl; \
out << "                Data:  -- data not shown --" << endl; \
return out.str(); \

// 
// Extra data, used to name different animation sequences.
//
// - Unknown.  Always equals zero in all official files.
// - List of textual notes and at which time they take effect. Used for designating the start and stop of animations and the triggering of sounds.
#define NI_TEXT_KEY_EXTRA_DATA_MEMBERS \
uint unknownInt1; \
KeyArray<string > textKeys; \

#define NI_TEXT_KEY_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknownInt1); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TEXT_KEY_EXTRA_DATA_PARENTS AExtraData

#define NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT

#define NI_TEXT_KEY_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( unknownInt1, in, version ); \
}; \
NifStream( textKeys, in, version ); \

#define NI_TEXT_KEY_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( unknownInt1, out, version ); \
}; \
NifStream( textKeys, out, version ); \

#define NI_TEXT_KEY_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "       Unknown Int 1:  " << unknownInt1 << endl; \
out << "           Text Keys:  " << textKeys << endl; \
return out.str(); \

// 
// Enables environment mapping. Should be in both the children list and effects list of the NiTriShape block. For Morrowind: the bump map can be used to bump the environment map (note that the bump map is ignored if no NiTextureEffect block is present).
//
// - Model projection matrix.  Always identity?
// - Model projection transform.  Always (0,0,0)?
// - 0: FILTER_NEAREST
// 1: FILTER_BILERP
// 2: FILTER_TRILERP (Usual value)
// 3: FILTER_NEAREST_MIPNEAREST
// 4: FILTER_NEAREST_MIPLERP
// 5: FILTER_BILERP_MIPNAREST
// - 0: CLAMP_S_CLAMP (Common value)
// 1: CLAMP_S_WRAP
// 2: WRAP_S_CLAMP_T
// 3: WRAP_S_WRAP_T (Common value)
// - 0: PROJECTED_LIGHT
// 1: PROJECTED_SHADOW
// 2: ENVIRONMENT_MAP (Usual value)
// 3: FOG_MAP
// - 0: WORLD_PARALLEL
// 1: WORLD_PERSPECTIVE
// 2: SPHERE_MAP (Usual value)
// 3: SPECULAR_CUBE_MAP
// 4: DIFFUSE_CUBE_MAP
// - Source texture index.
// - 0: Disabled (Usual value)
// 1: Enabled
// - Unknown: (1,0,0)?
// - Unknown. 0?
// - 0?
// - 0xFFB5?
// - Unknown: 0.
#define NI_TEXTURE_EFFECT_MEMBERS \
Matrix33 modelProjectionMatrix; \
Vector3 modelProjectionTransform; \
uint textureFiltering; \
uint textureClamping; \
uint textureType; \
uint coordinateGenerationType; \
Link sourceTexture; \
byte clippingPlane; \
Vector3 unknownVector; \
float unknownFloat; \
ushort ps2L; \
ushort ps2K; \
ushort unknownShort; \

#define NI_TEXTURE_EFFECT_GETATTR \
attr_ref attr = ADynamicEffect::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Model Projection Matrix" ) \
  return attr_ref(modelProjectionMatrix); \
if ( attr_name == "Model Projection Transform" ) \
  return attr_ref(modelProjectionTransform); \
if ( attr_name == "Texture Filtering" ) \
  return attr_ref(textureFiltering); \
if ( attr_name == "Texture Clamping" ) \
  return attr_ref(textureClamping); \
if ( attr_name == "Texture Type" ) \
  return attr_ref(textureType); \
if ( attr_name == "Coordinate Generation Type" ) \
  return attr_ref(coordinateGenerationType); \
if ( attr_name == "Source Texture" ) \
  return attr_ref(sourceTexture); \
if ( attr_name == "Clipping Plane" ) \
  return attr_ref(clippingPlane); \
if ( attr_name == "Unknown Vector" ) \
  return attr_ref(unknownVector); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknownFloat); \
if ( attr_name == "PS2 L" ) \
  return attr_ref(ps2L); \
if ( attr_name == "PS2 K" ) \
  return attr_ref(ps2K); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TEXTURE_EFFECT_PARENTS ADynamicEffect

#define NI_TEXTURE_EFFECT_CONSTRUCT

#define NI_TEXTURE_EFFECT_READ \
ADynamicEffect::Read( in, version ); \
NifStream( modelProjectionMatrix, in, version ); \
NifStream( modelProjectionTransform, in, version ); \
NifStream( textureFiltering, in, version ); \
NifStream( textureClamping, in, version ); \
NifStream( textureType, in, version ); \
NifStream( coordinateGenerationType, in, version ); \
NifStream( sourceTexture, in, version ); \
NifStream( clippingPlane, in, version ); \
NifStream( unknownVector, in, version ); \
NifStream( unknownFloat, in, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( ps2L, in, version ); \
  NifStream( ps2K, in, version ); \
}; \
if ( version <= 0x0401000C ) { \
  NifStream( unknownShort, in, version ); \
}; \

#define NI_TEXTURE_EFFECT_WRITE \
ADynamicEffect::Write( out, version ); \
NifStream( modelProjectionMatrix, out, version ); \
NifStream( modelProjectionTransform, out, version ); \
NifStream( textureFiltering, out, version ); \
NifStream( textureClamping, out, version ); \
NifStream( textureType, out, version ); \
NifStream( coordinateGenerationType, out, version ); \
NifStream( sourceTexture, out, version ); \
NifStream( clippingPlane, out, version ); \
NifStream( unknownVector, out, version ); \
NifStream( unknownFloat, out, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( ps2L, out, version ); \
  NifStream( ps2K, out, version ); \
}; \
if ( version <= 0x0401000C ) { \
  NifStream( unknownShort, out, version ); \
}; \

#define NI_TEXTURE_EFFECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ADynamicEffect::asString(); \
out << "Model Projection Matrix:  " << modelProjectionMatrix << endl; \
out << "Model Projection Transform:  " << modelProjectionTransform << endl; \
out << "   Texture Filtering:  " << textureFiltering << endl; \
out << "    Texture Clamping:  " << textureClamping << endl; \
out << "        Texture Type:  " << textureType << endl; \
out << "Coordinate Generation Type:  " << coordinateGenerationType << endl; \
out << "      Source Texture:  " << sourceTexture << endl; \
out << "      Clipping Plane:  " << clippingPlane << endl; \
out << "      Unknown Vector:  " << unknownVector << endl; \
out << "       Unknown Float:  " << unknownFloat << endl; \
out << "               PS2 L:  " << ps2L << endl; \
out << "               PS2 K:  " << ps2K << endl; \
out << "       Unknown Short:  " << unknownShort << endl; \
return out.str(); \

// 
// Texture transformation controller.
//
// - Unknown.
// - The target texture slot.
// 0: base map
// 1: dark map
// ...
// - 0: translate u
// 1: translate v
// 2: rotate ?
// 3: tiling u
// 4: tiling v
// - Link to NiFloatData.
#define NI_TEXTURE_TRANSFORM_CONTROLLER_MEMBERS \
byte unknown2; \
uint textureSlot; \
uint operation; \
Link data; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_GETATTR \
attr_ref attr = ASingleInterpolatorController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown2" ) \
  return attr_ref(unknown2); \
if ( attr_name == "Texture Slot" ) \
  return attr_ref(textureSlot); \
if ( attr_name == "Operation" ) \
  return attr_ref(operation); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_PARENTS ASingleInterpolatorController

#define NI_TEXTURE_TRANSFORM_CONTROLLER_CONSTRUCT

#define NI_TEXTURE_TRANSFORM_CONTROLLER_READ \
ASingleInterpolatorController::Read( in, version ); \
NifStream( unknown2, in, version ); \
NifStream( textureSlot, in, version ); \
NifStream( operation, in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( data, in, version ); \
}; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_WRITE \
ASingleInterpolatorController::Write( out, version ); \
NifStream( unknown2, out, version ); \
NifStream( textureSlot, out, version ); \
NifStream( operation, out, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( data, out, version ); \
}; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ASingleInterpolatorController::asString(); \
out << "            Unknown2:  " << unknown2 << endl; \
out << "        Texture Slot:  " << textureSlot << endl; \
out << "           Operation:  " << operation << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Describes an object's textures.
//
// - Property flags.
// - 0=replace, 1=decal, 2=modulate, 3=hilight, 4=hilight2
// - Number of textures. Always 7 in versions < 20.0.0.4. Can also be 8 in >= 20.0.0.4.
// - The base texture.
// - The dark texture.
// - The detail texture.
// - The gloss texture.
// - The glowing texture.
// - The bump map texture.
// - The decal texture.
// - Another decal texture.  2 seems to be the limit.
// - Shader textures.
#define NI_TEXTURING_PROPERTY_MEMBERS \
Flags flags; \
ApplyMode applyMode; \
uint textureCount; \
Texture baseTexture; \
Texture darkTexture; \
Texture detailTexture; \
Texture glossTexture; \
Texture glowTexture; \
BumpMap bumpMapTexture; \
Texture decal0Texture; \
Texture decalTexture1; \
ExtraTextureGroup shaderTextures; \

#define NI_TEXTURING_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Apply Mode" ) \
  return attr_ref(applyMode); \
if ( attr_name == "Texture Count" ) \
  return attr_ref(textureCount); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TEXTURING_PROPERTY_PARENTS AProperty

#define NI_TEXTURING_PROPERTY_CONSTRUCT applyMode(2), textureCount(7)

#define NI_TEXTURING_PROPERTY_READ \
AProperty::Read( in, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, in, version ); \
}; \
NifStream( applyMode, in, version ); \
NifStream( textureCount, in, version ); \
NifStream( baseTexture, in, version ); \
NifStream( darkTexture, in, version ); \
NifStream( detailTexture, in, version ); \
NifStream( glossTexture, in, version ); \
NifStream( glowTexture, in, version ); \
NifStream( bumpMapTexture, in, version ); \
NifStream( decal0Texture, in, version ); \
if ( version >= 0x14000004 ) { \
  if ( textureCount == 8 ) { \
    NifStream( decalTexture1, in, version ); \
  }; \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( shaderTextures, in, version ); \
}; \

#define NI_TEXTURING_PROPERTY_WRITE \
AProperty::Write( out, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, out, version ); \
}; \
NifStream( applyMode, out, version ); \
NifStream( textureCount, out, version ); \
NifStream( baseTexture, out, version ); \
NifStream( darkTexture, out, version ); \
NifStream( detailTexture, out, version ); \
NifStream( glossTexture, out, version ); \
NifStream( glowTexture, out, version ); \
NifStream( bumpMapTexture, out, version ); \
NifStream( decal0Texture, out, version ); \
if ( version >= 0x14000004 ) { \
  if ( textureCount == 8 ) { \
    NifStream( decalTexture1, out, version ); \
  }; \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( shaderTextures, out, version ); \
}; \

#define NI_TEXTURING_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "          Apply Mode:  " << applyMode << endl; \
out << "       Texture Count:  " << textureCount << endl; \
out << "        Base Texture:  " << baseTexture << endl; \
out << "        Dark Texture:  " << darkTexture << endl; \
out << "      Detail Texture:  " << detailTexture << endl; \
out << "       Gloss Texture:  " << glossTexture << endl; \
out << "        Glow Texture:  " << glowTexture << endl; \
out << "    Bump Map Texture:  " << bumpMapTexture << endl; \
out << "     Decal 0 Texture:  " << decal0Texture << endl; \
out << "     Decal Texture 1:  " << decalTexture1 << endl; \
out << "     Shader Textures:  " << shaderTextures << endl; \
return out.str(); \

// 
// NiTransformController replaces the NiKeyframeController.
//
#define NI_TRANSFORM_CONTROLLER_MEMBERS \

#define NI_TRANSFORM_CONTROLLER_GETATTR \
attr_ref attr = ASingleInterpolatorController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRANSFORM_CONTROLLER_PARENTS ASingleInterpolatorController

#define NI_TRANSFORM_CONTROLLER_CONSTRUCT

#define NI_TRANSFORM_CONTROLLER_READ \
ASingleInterpolatorController::Read( in, version ); \

#define NI_TRANSFORM_CONTROLLER_WRITE \
ASingleInterpolatorController::Write( out, version ); \

#define NI_TRANSFORM_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ASingleInterpolatorController::asString(); \
return out.str(); \

// 
// Mesh animation keyframe data.
//
#define NI_TRANSFORM_DATA_MEMBERS \

#define NI_TRANSFORM_DATA_GETATTR \
attr_ref attr = AKeyframeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRANSFORM_DATA_PARENTS AKeyframeData

#define NI_TRANSFORM_DATA_CONSTRUCT

#define NI_TRANSFORM_DATA_READ \
AKeyframeData::Read( in, version ); \

#define NI_TRANSFORM_DATA_WRITE \
AKeyframeData::Write( out, version ); \

#define NI_TRANSFORM_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyframeData::asString(); \
return out.str(); \

// 
// Unknown.
//
// - Translate.
// - Rotation.
// - Scale.
// - Unknown.
// - Refers to NiTransformData.
#define NI_TRANSFORM_INTERPOLATOR_MEMBERS \
Vector3 translation; \
Quaternion rotation; \
float scale; \
vector<byte > unknownBytes; \
Link data; \

#define NI_TRANSFORM_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Translation" ) \
  return attr_ref(translation); \
if ( attr_name == "Rotation" ) \
  return attr_ref(rotation); \
if ( attr_name == "Scale" ) \
  return attr_ref(scale); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRANSFORM_INTERPOLATOR_PARENTS AInterpolator

#define NI_TRANSFORM_INTERPOLATOR_CONSTRUCT

#define NI_TRANSFORM_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( translation, in, version ); \
NifStream( rotation, in, version ); \
NifStream( scale, in, version ); \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  unknownBytes.resize(3); \
  NifStream( unknownBytes, in, version ); \
}; \
NifStream( data, in, version ); \

#define NI_TRANSFORM_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( translation, out, version ); \
NifStream( rotation, out, version ); \
NifStream( scale, out, version ); \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknownBytes, out, version ); \
}; \
NifStream( data, out, version ); \

#define NI_TRANSFORM_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "         Translation:  " << translation << endl; \
out << "            Rotation:  " << rotation << endl; \
out << "               Scale:  " << scale << endl; \
out << "       Unknown Bytes:  -- data not shown --" << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// A shape node that refers to singular triangle data.
//
#define NI_TRI_SHAPE_MEMBERS \

#define NI_TRI_SHAPE_GETATTR \
attr_ref attr = AShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRI_SHAPE_PARENTS AShape

#define NI_TRI_SHAPE_CONSTRUCT

#define NI_TRI_SHAPE_READ \
AShape::Read( in, version ); \

#define NI_TRI_SHAPE_WRITE \
AShape::Write( out, version ); \

#define NI_TRI_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShape::asString(); \
return out.str(); \

// 
// Holds mesh data using a list of singular triangles.
//     
//     
//     
//     
//     
//     
//     Triangle face data.
//
// - Num Triangles times 3.
// - Do we have triangle data?
// - Triangle data.
// - The matching vertex groups.
#define NI_TRI_SHAPE_DATA_MEMBERS \
uint numTrianglePoints; \
bool hasTriangles; \
vector<Triangle > triangles; \
vector<MatchGroup > matchGroups; \

#define NI_TRI_SHAPE_DATA_GETATTR \
attr_ref attr = AShapeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Triangle Points" ) \
  return attr_ref(numTrianglePoints); \
if ( attr_name == "Has Triangles" ) \
  return attr_ref(hasTriangles); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRI_SHAPE_DATA_PARENTS AShapeData

#define NI_TRI_SHAPE_DATA_CONSTRUCT

#define NI_TRI_SHAPE_DATA_READ \
ushort numTriangles; \
ushort numMatchGroups; \
AShapeData::Read( in, version ); \
NifStream( numTriangles, in, version ); \
NifStream( numTrianglePoints, in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( hasTriangles, in, version ); \
}; \
if ( version <= 0x0A000102 ) { \
  triangles.resize(numTriangles); \
  NifStream( triangles, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( hasTriangles != 0 ) { \
    triangles.resize(numTriangles); \
    NifStream( triangles, in, version ); \
  }; \
}; \
NifStream( numMatchGroups, in, version ); \
matchGroups.resize(numMatchGroups); \
NifStream( matchGroups, in, version ); \

#define NI_TRI_SHAPE_DATA_WRITE \
ushort numTriangles; \
ushort numMatchGroups; \
AShapeData::Write( out, version ); \
numTriangles = ushort(triangles.size()); \
numMatchGroups = ushort(matchGroups.size()); \
NifStream( numTriangles, out, version ); \
NifStream( numTrianglePoints, out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( hasTriangles, out, version ); \
}; \
if ( version <= 0x0A000102 ) { \
  NifStream( triangles, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( hasTriangles != 0 ) { \
    NifStream( triangles, out, version ); \
  }; \
}; \
NifStream( numMatchGroups, out, version ); \
NifStream( matchGroups, out, version ); \

#define NI_TRI_SHAPE_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShapeData::asString(); \
out << "       Num Triangles:  -- calculated --" << endl; \
out << " Num Triangle Points:  " << numTrianglePoints << endl; \
out << "       Has Triangles:  " << hasTriangles << endl; \
out << "           Triangles:  -- data not shown --" << endl; \
out << "    Num Match Groups:  -- calculated --" << endl; \
out << "        Match Groups:  -- data not shown --" << endl; \
return out.str(); \

// 
// A shape node that refers to data organized into strips of triangles
//
#define NI_TRI_STRIPS_MEMBERS \

#define NI_TRI_STRIPS_GETATTR \
attr_ref attr = AShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRI_STRIPS_PARENTS AShape

#define NI_TRI_STRIPS_CONSTRUCT

#define NI_TRI_STRIPS_READ \
AShape::Read( in, version ); \

#define NI_TRI_STRIPS_WRITE \
AShape::Write( out, version ); \

#define NI_TRI_STRIPS_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShape::asString(); \
return out.str(); \

// 
// Holds mesh data using strips of triangles.
//     
//     
//     
//     
//     
//     
//     
//     The points in the Triangle strips. Size is the sum of all entries in Strip Lengths.
//
// - Number of triangles.
// - Do we have strip point data?
// - The points in the Triangle strips.  Size is the sum of all entries in Strip Lengths.
#define NI_TRI_STRIPS_DATA_MEMBERS \
ushort numTriangles; \
bool hasPoints; \
vector<vector<ushort > > points; \

#define NI_TRI_STRIPS_DATA_GETATTR \
attr_ref attr = AShapeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Triangles" ) \
  return attr_ref(numTriangles); \
if ( attr_name == "Has Points" ) \
  return attr_ref(hasPoints); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRI_STRIPS_DATA_PARENTS AShapeData

#define NI_TRI_STRIPS_DATA_CONSTRUCT

#define NI_TRI_STRIPS_DATA_READ \
ushort numStrips; \
vector<ushort > stripLengths; \
AShapeData::Read( in, version ); \
NifStream( numTriangles, in, version ); \
NifStream( numStrips, in, version ); \
stripLengths.resize(numStrips); \
NifStream( stripLengths, in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( hasPoints, in, version ); \
}; \
if ( version <= 0x0A000102 ) { \
  points.resize(numStrips); \
  NifStream( points, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( hasPoints != 0 ) { \
    points.resize(numStrips); \
    NifStream( points, in, version ); \
  }; \
}; \

#define NI_TRI_STRIPS_DATA_WRITE \
ushort numStrips; \
vector<ushort > stripLengths; \
AShapeData::Write( out, version ); \
numStrips = ushort(stripLengths.size()); \
stripLengths.resize(numStrips); for (uint i = 0; i < points.size(); i++) stripLengths[i] = ushort(points[i].size()); \
NifStream( numTriangles, out, version ); \
NifStream( numStrips, out, version ); \
NifStream( stripLengths, out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( hasPoints, out, version ); \
}; \
if ( version <= 0x0A000102 ) { \
  NifStream( points, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( hasPoints != 0 ) { \
    NifStream( points, out, version ); \
  }; \
}; \

#define NI_TRI_STRIPS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShapeData::asString(); \
out << "       Num Triangles:  " << numTriangles << endl; \
out << "          Num Strips:  -- calculated --" << endl; \
out << "       Strip Lengths:  -- calculated --" << endl; \
out << "          Has Points:  " << hasPoints << endl; \
out << "              Points:  -- data not shown --" << endl; \
return out.str(); \

// 
// Time controller for texture coordinates.
//
// - Always 0?
// - Texture coordinate controller data index.
#define NI_U_V_CONTROLLER_MEMBERS \
ushort unknownShort; \
Link data; \

#define NI_U_V_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknownShort); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_U_V_CONTROLLER_PARENTS AController

#define NI_U_V_CONTROLLER_CONSTRUCT

#define NI_U_V_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( unknownShort, in, version ); \
NifStream( data, in, version ); \

#define NI_U_V_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( unknownShort, out, version ); \
NifStream( data, out, version ); \

#define NI_U_V_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "       Unknown Short:  " << unknownShort << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Texture coordinate data.
//
// - Four UV data groups.  Perhaps the first two control x and y.
// The existence of the second two is a guess - there are always two zero values following the first two in all official files.
#define NI_U_V_DATA_MEMBERS \
vector<VectorKeyArray<float > > uvGroups; \

#define NI_U_V_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_U_V_DATA_PARENTS AData

#define NI_U_V_DATA_CONSTRUCT

#define NI_U_V_DATA_READ \
AData::Read( in, version ); \
uvGroups.resize(4); \
NifStream( uvGroups, in, version ); \

#define NI_U_V_DATA_WRITE \
AData::Write( out, version ); \
NifStream( uvGroups, out, version ); \

#define NI_U_V_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "           UV Groups:  -- data not shown --" << endl; \
return out.str(); \

// 
// Extra vector data.
//
// - The vector data.
// - Not sure whether this comes before or after the vector data.
#define NI_VECTOR_EXTRA_DATA_MEMBERS \
Vector3 vectorData; \
float unknownFloat; \

#define NI_VECTOR_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Vector Data" ) \
  return attr_ref(vectorData); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknownFloat); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_VECTOR_EXTRA_DATA_PARENTS AExtraData

#define NI_VECTOR_EXTRA_DATA_CONSTRUCT

#define NI_VECTOR_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( vectorData, in, version ); \
NifStream( unknownFloat, in, version ); \

#define NI_VECTOR_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( vectorData, out, version ); \
NifStream( unknownFloat, out, version ); \

#define NI_VECTOR_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "         Vector Data:  " << vectorData << endl; \
out << "       Unknown Float:  " << unknownFloat << endl; \
return out.str(); \

// 
// Property of vertex colors. This block is referred to by the root block of the NIF file whenever some NiTriShapeData block has vertex colors with non-default settings; if not present, vertex colors have vertex_mode=2 and lighting_mode=1.
//
// - Property flags.
// - 0: SOURCE_IGNORE
// 1: SOURCE_EMISSIVE
// 2: SOURCE_AMB_DIFF (Ambient/Diffuse)
// - 0: LIGHTING_E (Emissive)
// 1: LIGHTING_E_A_D (Emissive, ambient, diffuse)
#define NI_VERTEX_COLOR_PROPERTY_MEMBERS \
Flags flags; \
VertMode vertexMode; \
LightMode lightingMode; \

#define NI_VERTEX_COLOR_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Vertex Mode" ) \
  return attr_ref(vertexMode); \
if ( attr_name == "Lighting Mode" ) \
  return attr_ref(lightingMode); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_VERTEX_COLOR_PROPERTY_PARENTS AProperty

#define NI_VERTEX_COLOR_PROPERTY_CONSTRUCT

#define NI_VERTEX_COLOR_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \
NifStream( vertexMode, in, version ); \
NifStream( lightingMode, in, version ); \

#define NI_VERTEX_COLOR_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \
NifStream( vertexMode, out, version ); \
NifStream( lightingMode, out, version ); \

#define NI_VERTEX_COLOR_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "         Vertex Mode:  " << vertexMode << endl; \
out << "       Lighting Mode:  " << lightingMode << endl; \
return out.str(); \

// 
// Not used in skinning.
// Unsure of use - perhaps for morphing animation or gravity.
//
// - Number of bytes in this data block.
// - The vertex weights.
#define NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS \
uint numBytes; \
vector<float > weight; \

#define NI_VERT_WEIGHTS_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Bytes" ) \
  return attr_ref(numBytes); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_PARENTS AExtraData

#define NI_VERT_WEIGHTS_EXTRA_DATA_CONSTRUCT

#define NI_VERT_WEIGHTS_EXTRA_DATA_READ \
ushort numVertices; \
AExtraData::Read( in, version ); \
NifStream( numBytes, in, version ); \
NifStream( numVertices, in, version ); \
weight.resize(numVertices); \
NifStream( weight, in, version ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_WRITE \
ushort numVertices; \
AExtraData::Write( out, version ); \
numVertices = ushort(weight.size()); \
NifStream( numBytes, out, version ); \
NifStream( numVertices, out, version ); \
NifStream( weight, out, version ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "           Num Bytes:  " << numBytes << endl; \
out << "        Num Vertices:  -- calculated --" << endl; \
out << "              Weight:  -- data not shown --" << endl; \
return out.str(); \

// 
// Time controller for visibility.
//
// - Visibility controller data block index.
#define NI_VIS_CONTROLLER_MEMBERS \
Link data; \

#define NI_VIS_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_VIS_CONTROLLER_PARENTS AController

#define NI_VIS_CONTROLLER_CONSTRUCT

#define NI_VIS_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_VIS_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_VIS_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Visibility data for a controller.
//
// - The visibility keys.
#define NI_VIS_DATA_MEMBERS \
KeyArray<byte > data; \

#define NI_VIS_DATA_GETATTR \
attr_ref attr = AKeyedData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_VIS_DATA_PARENTS AKeyedData

#define NI_VIS_DATA_CONSTRUCT

#define NI_VIS_DATA_READ \
AKeyedData::Read( in, version ); \
NifStream( data, in, version ); \

#define NI_VIS_DATA_WRITE \
AKeyedData::Write( out, version ); \
NifStream( data, out, version ); \

#define NI_VIS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyedData::asString(); \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Unknown.
//
// - Property flags.
// 0 - Wireframe Mode Disabled
// 1 - Wireframe Mode Enabled
#define NI_WIREFRAME_PROPERTY_MEMBERS \
Flags flags; \

#define NI_WIREFRAME_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_WIREFRAME_PROPERTY_PARENTS AProperty

#define NI_WIREFRAME_PROPERTY_CONSTRUCT

#define NI_WIREFRAME_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \

#define NI_WIREFRAME_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \

#define NI_WIREFRAME_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
return out.str(); \

// 
// This Property controlls the Z buffer (OpenGL: depth buffer).
//
// - Bit 0 enables the z test
// Bit 1 controlls wether the z buffer is read only (0) or read/write (1)
// - Z-Test function (see: GlDepthFunc)
// 0: TEST_ALWAYS
// 1: TEST_LESS
// 2: TEST_EQUAL
// 3: TEST_LESSEQUAL
// 4: TEST_GREATER
// 5: TEST_NOTEQUAL
// 6: TEST_GREATEREQUAL
// 7: TEST_NEVER
#define NI_Z_BUFFER_PROPERTY_MEMBERS \
Flags flags; \
uint function; \

#define NI_Z_BUFFER_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Function" ) \
  return attr_ref(function); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_Z_BUFFER_PROPERTY_PARENTS AProperty

#define NI_Z_BUFFER_PROPERTY_CONSTRUCT flags(3), function(3)

#define NI_Z_BUFFER_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \
if ( version >= 0x0401000C ) { \
  NifStream( function, in, version ); \
}; \

#define NI_Z_BUFFER_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \
if ( version >= 0x0401000C ) { \
  NifStream( function, out, version ); \
}; \

#define NI_Z_BUFFER_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "            Function:  " << function << endl; \
return out.str(); \

// 
// Morrowind-specific node for collision mesh.
//
#define ROOT_COLLISION_NODE_MEMBERS \

#define ROOT_COLLISION_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define ROOT_COLLISION_NODE_PARENTS AParentNode

#define ROOT_COLLISION_NODE_CONSTRUCT

#define ROOT_COLLISION_NODE_READ \
AParentNode::Read( in, version ); \

#define ROOT_COLLISION_NODE_WRITE \
AParentNode::Write( out, version ); \

#define ROOT_COLLISION_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
return out.str(); \


#endif
