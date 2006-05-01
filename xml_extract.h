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
  vector<uint > bones;
  Bones() {};
};

void NifStream( Bones & val, istream & in, uint version ) {
  uint num_bones;
  NifStream( num_bones, in, version );
  val.bones.resize(num_bones);
  NifStream( val.bones, in, version );
};

void NifStream( Bones const & val, ostream & out, uint version ) {
  uint num_bones;
  num_bones = uint(val.bones.size());
  NifStream( num_bones, out, version );
  NifStream( val.bones, out, version );
};

ostream & operator<<( ostream & out, Bones const & val );

// 
// An array of bytes.
//
struct ByteArray {
  // Unknown.
  uint unknown_int;
  // The bytes which make up the array
  vector<byte > data;
  ByteArray() {};
};

void NifStream( ByteArray & val, istream & in, uint version ) {
  uint size;
  NifStream( size, in, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.unknown_int, in, version );
  };
  val.data.resize(size);
  NifStream( val.data, in, version );
};

void NifStream( ByteArray const & val, ostream & out, uint version ) {
  uint size;
  size = uint(val.data.size());
  NifStream( size, out, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.unknown_int, out, version );
  };
  NifStream( val.data, out, version );
};

ostream & operator<<( ostream & out, ByteArray const & val );

// 
// An integer value that may or may not be used.
//
struct CondInt {
  // Non-Zero if the following Integer appears.  Otherwise, the integer does not appear.
  bool is_used;
  // An unknown integer.
  uint unknown_int;
  CondInt() {};
};

void NifStream( CondInt & val, istream & in, uint version ) {
  NifStream( val.is_used, in, version );
  if ( val.is_used != 0 ) {
    NifStream( val.unknown_int, in, version );
  };
};

void NifStream( CondInt const & val, ostream & out, uint version ) {
  NifStream( val.is_used, out, version );
  if ( val.is_used != 0 ) {
    NifStream( val.unknown_int, out, version );
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
  uint num_keys;
  NifStream( num_keys, in, version );
  val.keys.resize(num_keys);
  NifStream( val.keys, in, version );
};

template <class T >
void NifStream( KeyArray<T> const & val, ostream & out, uint version ) {
  uint num_keys;
  num_keys = uint(val.keys.size());
  NifStream( num_keys, out, version );
  NifStream( val.keys, out, version );
};

template <class T >
ostream & operator<<( ostream & out, KeyArray<T> const & val );

// 
// List of block indices.
//
struct LinkGroup {
  // The list of block indices.
  vector<uint > indices;
  LinkGroup() {};
};

void NifStream( LinkGroup & val, istream & in, uint version ) {
  uint num_indices;
  NifStream( num_indices, in, version );
  val.indices.resize(num_indices);
  NifStream( val.indices, in, version );
};

void NifStream( LinkGroup const & val, ostream & out, uint version ) {
  uint num_indices;
  num_indices = uint(val.indices.size());
  NifStream( num_indices, out, version );
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
  vector<ushort > vertex_indices;
  MatchGroup() {};
};

void NifStream( MatchGroup & val, istream & in, uint version ) {
  ushort num_vertices;
  NifStream( num_vertices, in, version );
  val.vertex_indices.resize(num_vertices);
  NifStream( val.vertex_indices, in, version );
};

void NifStream( MatchGroup const & val, ostream & out, uint version ) {
  ushort num_vertices;
  num_vertices = ushort(val.vertex_indices.size());
  NifStream( num_vertices, out, version );
  NifStream( val.vertex_indices, out, version );
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
  bool has_modifiers;
  // The list of particle modifiers.
  LinkGroup modifiers;
  ModifierGroup() {};
};

void NifStream( ModifierGroup & val, istream & in, uint version ) {
  NifStream( val.has_modifiers, in, version );
  NifStream( val.modifiers, in, version );
};

void NifStream( ModifierGroup const & val, ostream & out, uint version ) {
  NifStream( val.has_modifiers, out, version );
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
  uint num_keys;
  NifStream( num_keys, in, version );
  val.keys.resize(num_keys);
  NifStream( val.keys, in, version );
};

template <class T >
void NifStream( ns_keyarray<T> const & val, ostream & out, uint version ) {
  uint num_keys;
  num_keys = uint(val.keys.size());
  NifStream( num_keys, out, version );
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
  vector<vector<uint > > link_pairs;
  SkinShapeGroup() {};
};

void NifStream( SkinShapeGroup & val, istream & in, uint version ) {
  uint num_link_pairs;
  NifStream( num_link_pairs, in, version );
  val.link_pairs.resize(num_link_pairs);
  for (uint i = 0; i < num_link_pairs; i++) {
    val.link_pairs[i].resize(2);
  };
  NifStream( val.link_pairs, in, version );
};

void NifStream( SkinShapeGroup const & val, ostream & out, uint version ) {
  uint num_link_pairs;
  num_link_pairs = uint(val.link_pairs.size());
  NifStream( num_link_pairs, out, version );
  NifStream( val.link_pairs, out, version );
};

ostream & operator<<( ostream & out, SkinShapeGroup const & val );

// 
// Used in NiDefaultAVObjectPalette.
//
struct AVObject {
  // Object name.
  string name;
  // Object reference.
  uint object;
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
  uint interpolator;
  // Unknown link. Usually -1.
  uint unknown_link_1;
  // Unknown.
  uint unknown_link_2;
  // Unknown.
  ushort unknown_short_0;
  // Idle animations tend to have low values for this, and blocks that have high values tend to correspond with the important parts of the animation. WARNING: BREAKS CIV4 NIF FILES! Only observed in Oblivion NIF files so far.
  byte priority_;
  // Refers to the NiStringPalette which contains the name of the controlled block.
  uint string_palette;
  // The name of the animated node.
  string node_name;
  // Offset in the string palette where the name of the controlled node (NiNode, NiTriShape, ...) starts.
  ushort node_name_offset;
  // Unknown, always 0.
  ushort unknown_short_1;
  // Name of the property (NiMaterialProperty, ...), if this controller controls a property.
  string property_type;
  // Offset in the string palette where the property (NiMaterialProperty, ...) starts, if this controller controls a property. Otherwise, -1.
  ushort property_type_offset;
  // Unknown, usually 0, but sometimes also 0xFFFF.
  ushort unknown_short_2;
  // Probably the block type name of the controller in the NIF file that is child of the controlled block.
  string controller_type;
  // Apparently the offset in the string palette of some type of controller related to Interpolator (for example, a 'NiTransformInterpolator' will have here a 'NiTransformController', etc.). Sometimes the type of controller that links to the interpolator. Probably it refers to the controller in the NIF file that is child of the controlled block, via its type name.
  ushort controller_type_offset;
  // Unknown, always 0.
  ushort unknown_short_3;
  // Some variable string (such as 'SELF_ILLUM', '0-0-TT_TRANSLATE_U', 'tongue_out', etc.).
  string variable_1;
  // Offset in the string palette where some variable string starts (such as 'SELF_ILLUM', '0-0-TT_TRANSLATE_U', 'tongue_out', etc.). Usually, -1.
  ushort variable_offset_1;
  // Unknown, usually 0, but sometimes 0xFFFF.
  ushort unknown_short_4;
  // Another variable string, apparently used for particle system controllers.
  string variable_2;
  // Offset in the string palette where some variable string starts (so far only 'EmitterActive' and 'BirthRate' have been observed in official files, used for particle system controllers). Usually, -1.
  ushort variable_offset_2;
  // Unknown, usually 0, but sometimes 0xFFFF.
  ushort unknown_short_5;
  ControllerLink() {};
};

void NifStream( ControllerLink & val, istream & in, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.name, in, version );
  };
  NifStream( val.interpolator, in, version );
  if ( version >= 0x0A01006A ) {
    NifStream( val.unknown_link_1, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknown_link_2, in, version );
    NifStream( val.unknown_short_0, in, version );
  };
  if ( version >= 0x0A01006A ) {
    NifStream( val.priority_, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.string_palette, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.node_name, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.node_name_offset, in, version );
    NifStream( val.unknown_short_1, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.property_type, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.property_type_offset, in, version );
    NifStream( val.unknown_short_2, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.controller_type, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.controller_type_offset, in, version );
    NifStream( val.unknown_short_3, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.variable_1, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.variable_offset_1, in, version );
    NifStream( val.unknown_short_4, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.variable_2, in, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.variable_offset_2, in, version );
    NifStream( val.unknown_short_5, in, version );
  };
};

void NifStream( ControllerLink const & val, ostream & out, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.name, out, version );
  };
  NifStream( val.interpolator, out, version );
  if ( version >= 0x0A01006A ) {
    NifStream( val.unknown_link_1, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknown_link_2, out, version );
    NifStream( val.unknown_short_0, out, version );
  };
  if ( version >= 0x0A01006A ) {
    NifStream( val.priority_, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.string_palette, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.node_name, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.node_name_offset, out, version );
    NifStream( val.unknown_short_1, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.property_type, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.property_type_offset, out, version );
    NifStream( val.unknown_short_2, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.controller_type, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.controller_type_offset, out, version );
    NifStream( val.unknown_short_3, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.variable_1, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.variable_offset_1, out, version );
    NifStream( val.unknown_short_4, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.variable_2, out, version );
  };
  if ( version >= 0x0A020000 ) {
    NifStream( val.variable_offset_2, out, version );
    NifStream( val.unknown_short_5, out, version );
  };
};

ostream & operator<<( ostream & out, ControllerLink const & val );

// 
// The NIF file header.
//
struct Header {
  // 'NetImmerse File Format x.x.x.x' (versions <= 10.0.1.2) or 'Gamebryo File Format x.x.x.x' (versions >= 10.1.0.0), with x.x.x.x the version written out. Ends with a newline character (0x0A).
  HeaderString header_string;
  // The NIF version, in hexadecimal notation: 0x04000002, 0x0401000C, 0x04020002, 0x04020100, 0x04020200, 0x0A000100, 0x0A010000, 0x0A020000, 0x14000004, ...
  uint version;
  // Determines the endian-ness of the data.
  // 
  // 1 = little endian (default)
  // 0 = big endian
  byte endian_type;
  // An extra version number, for companies that decide to modify the file format.
  uint user_version;
  // Unknown.
  uint unknown_int_1;
  // Unknown.
  uint unknown_int_3;
  // Could be the name of the creator of the NIF file?
  ShortString creator_;
  // Unknown. Can be something like 'TriStrip Process Script'.
  ShortString export_type_;
  // Unknown. Possibly the selected option of the export script. Can be something like 'Default Export Script'.
  ShortString export_script_;
  // List of all block types used in this NIF file.
  vector<string > block_types;
  // Maps file blocks on their corresponding type: first file block is of type block_types[block_type_index[0]], the second of block_types[block_type_index[1]], etc.
  vector<ushort > block_type_index;
  // Unknown.
  uint unknown_int_2;
  Header() : version(0x04000002), endian_type(1) {};
};

void NifStream( Header & val, istream & in, uint version ) {
  uint num_blocks;
  ushort num_block_types;
  NifStream( val.header_string, in, version );
  NifStream( val.version, in, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.endian_type, in, version );
  };
  if ( version >= 0x0A010000 ) {
    NifStream( val.user_version, in, version );
  };
  NifStream( num_blocks, in, version );
  if ( ( version >= 0x0A000102 ) && ( version <= 0x0A000102 ) ) {
    NifStream( val.unknown_int_1, in, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.user_version != 0 ) {
      NifStream( val.unknown_int_3, in, version );
    };
  };
  if ( version >= 0x0A000102 ) {
    if ( val.user_version != 0 ) {
      NifStream( val.creator_, in, version );
      NifStream( val.export_type_, in, version );
      NifStream( val.export_script_, in, version );
    };
  };
  if ( version >= 0x0A000100 ) {
    NifStream( num_block_types, in, version );
    val.block_types.resize(num_block_types);
    NifStream( val.block_types, in, version );
    val.block_type_index.resize(num_blocks);
    NifStream( val.block_type_index, in, version );
    NifStream( val.unknown_int_2, in, version );
  };
};

void NifStream( Header const & val, ostream & out, uint version ) {
  uint num_blocks;
  ushort num_block_types;
  num_blocks = uint(val.block_type_index.size());
  num_block_types = ushort(val.block_types.size());
  NifStream( val.header_string, out, version );
  NifStream( val.version, out, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.endian_type, out, version );
  };
  if ( version >= 0x0A010000 ) {
    NifStream( val.user_version, out, version );
  };
  NifStream( num_blocks, out, version );
  if ( ( version >= 0x0A000102 ) && ( version <= 0x0A000102 ) ) {
    NifStream( val.unknown_int_1, out, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.user_version != 0 ) {
      NifStream( val.unknown_int_3, out, version );
    };
  };
  if ( version >= 0x0A000102 ) {
    if ( val.user_version != 0 ) {
      NifStream( val.creator_, out, version );
      NifStream( val.export_type_, out, version );
      NifStream( val.export_script_, out, version );
    };
  };
  if ( version >= 0x0A000100 ) {
    NifStream( num_block_types, out, version );
    NifStream( val.block_types, out, version );
    NifStream( val.block_type_index, out, version );
    NifStream( val.unknown_int_2, out, version );
  };
};

ostream & operator<<( ostream & out, Header const & val );

// 
// Describes a shader.
//
struct Shader {
  // Do we have a shader?
  bool has_shader;
  // The shader name.
  string shader_name;
  // Unknown link, usually -1.
  uint unknown_link;
  Shader() {};
};

void NifStream( Shader & val, istream & in, uint version ) {
  NifStream( val.has_shader, in, version );
  if ( val.has_shader != 0 ) {
    NifStream( val.shader_name, in, version );
    NifStream( val.unknown_link, in, version );
  };
};

void NifStream( Shader const & val, ostream & out, uint version ) {
  NifStream( val.has_shader, out, version );
  if ( val.has_shader != 0 ) {
    NifStream( val.shader_name, out, version );
    NifStream( val.unknown_link, out, version );
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
  vector<uint > indices;
  TargetGroup() {};
};

void NifStream( TargetGroup & val, istream & in, uint version ) {
  ushort num_indices;
  NifStream( num_indices, in, version );
  val.indices.resize(num_indices);
  NifStream( val.indices, in, version );
};

void NifStream( TargetGroup const & val, ostream & out, uint version ) {
  ushort num_indices;
  num_indices = ushort(val.indices.size());
  NifStream( num_indices, out, version );
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
  uint num_keys;
  // The key type (1, 2, or 3).
  uint key_type;
  // Linearly interpolated keys.
  vector<ns_keylin<T > > keys;
  ns_keyvecarray() {};
};

template <class T >
void NifStream( ns_keyvecarray<T> & val, istream & in, uint version ) {
  NifStream( val.num_keys, in, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, in, version );
  };
  if ( val.key_type == 1 ) {
    val.keys.resize(val.num_keys);
    NifStream( val.keys, in, version );
  };
  if ( val.key_type == 2 ) {
    val.keys.resize(val.num_keys);
    NifStream( val.keys, in, version );
  };
  if ( val.key_type == 3 ) {
    val.keys.resize(val.num_keys);
    NifStream( val.keys, in, version );
  };
  if ( val.key_type == 5 ) {
    val.keys.resize(val.num_keys);
    NifStream( val.keys, in, version );
  };
};

template <class T >
void NifStream( ns_keyvecarray<T> const & val, ostream & out, uint version ) {
  NifStream( val.num_keys, out, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, out, version );
  };
  if ( val.key_type == 1 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.key_type == 2 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.key_type == 3 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.key_type == 5 ) {
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
  vector<ns_keyvecarray<float > > sub_keys;
  ns_keyrotsub() {};
};

void NifStream( ns_keyrotsub & val, istream & in, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.time, in, version );
  };
  val.sub_keys.resize(3);
  NifStream( val.sub_keys, in, version );
};

void NifStream( ns_keyrotsub const & val, ostream & out, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.time, out, version );
  };
  NifStream( val.sub_keys, out, version );
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
  uint num_keys;
  // The key type (1, 2, 3, or 4).
  uint key_type;
  // Linear keys.
  vector<ns_keylin<T > > keys;
  // Special rotation keys (3 float arrays, one for each axis).
  vector<ns_keyrotsub > keys_sub;
  ns_keyrotarray() {};
};

template <class T >
void NifStream( ns_keyrotarray<T> & val, istream & in, uint version ) {
  NifStream( val.num_keys, in, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, in, version );
  };
  if ( val.key_type == 1 ) {
    val.keys.resize(val.num_keys);
    NifStream( val.keys, in, version );
  };
  if ( val.key_type == 2 ) {
    val.keys.resize(val.num_keys);
    NifStream( val.keys, in, version );
  };
  if ( val.key_type == 3 ) {
    val.keys.resize(val.num_keys);
    NifStream( val.keys, in, version );
  };
  if ( val.key_type == 4 ) {
    val.keys_sub.resize(val.num_keys);
    NifStream( val.keys_sub, in, version );
  };
};

template <class T >
void NifStream( ns_keyrotarray<T> const & val, ostream & out, uint version ) {
  NifStream( val.num_keys, out, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, out, version );
  };
  if ( val.key_type == 1 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.key_type == 2 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.key_type == 3 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.key_type == 4 ) {
    NifStream( val.keys_sub, out, version );
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
  uint key_type;
  // Linearly interpolated keys.
  vector<ns_keylin<T > > keys;
  ns_keyvecarraytyp() {};
};

template <class T >
void NifStream( ns_keyvecarraytyp<T> & val, istream & in, uint version ) {
  uint num_keys;
  NifStream( num_keys, in, version );
  NifStream( val.key_type, in, version );
  if ( val.key_type == 1 ) {
    val.keys.resize(num_keys);
    NifStream( val.keys, in, version );
  };
  if ( val.key_type == 2 ) {
    val.keys.resize(num_keys);
    NifStream( val.keys, in, version );
  };
  if ( val.key_type == 3 ) {
    val.keys.resize(num_keys);
    NifStream( val.keys, in, version );
  };
};

template <class T >
void NifStream( ns_keyvecarraytyp<T> const & val, ostream & out, uint version ) {
  uint num_keys;
  num_keys = uint(val.keys.size());
  NifStream( num_keys, out, version );
  NifStream( val.key_type, out, version );
  if ( val.key_type == 1 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.key_type == 2 ) {
    NifStream( val.keys, out, version );
  };
  if ( val.key_type == 3 ) {
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
  bool is_used;
  // The bump map texture description.
  TexDesc texture;
  // ?
  float bump_map_luma_scale;
  // ?
  float bump_map_luma_offset;
  // ?
  Matrix22 matrix;
  BumpMap() {};
};

void NifStream( BumpMap & val, istream & in, uint version ) {
  NifStream( val.is_used, in, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture, in, version );
    NifStream( val.bump_map_luma_scale, in, version );
    NifStream( val.bump_map_luma_offset, in, version );
    NifStream( val.matrix, in, version );
  };
};

void NifStream( BumpMap const & val, ostream & out, uint version ) {
  NifStream( val.is_used, out, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture, out, version );
    NifStream( val.bump_map_luma_scale, out, version );
    NifStream( val.bump_map_luma_offset, out, version );
    NifStream( val.matrix, out, version );
  };
};

ostream & operator<<( ostream & out, BumpMap const & val );

// 
// A texture that is not a bumpmap.
//
struct Texture {
  // Determines whether this texture contains any information. If Non-Zero the following data is present, otherwise it is not.
  bool is_used;
  // The texture description.
  TexDesc texture_data;
  Texture() {};
};

void NifStream( Texture & val, istream & in, uint version ) {
  NifStream( val.is_used, in, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture_data, in, version );
  };
};

void NifStream( Texture const & val, ostream & out, uint version ) {
  NifStream( val.is_used, out, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture_data, out, version );
  };
};

ostream & operator<<( ostream & out, Texture const & val );

// 
// An extended version of texture.
//
struct Texture2 {
  // Is it used?
  bool is_used;
  // The texture data.
  TexDesc texture_data;
  // Unknown.
  uint unknown_int;
  Texture2() {};
};

void NifStream( Texture2 & val, istream & in, uint version ) {
  NifStream( val.is_used, in, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture_data, in, version );
    NifStream( val.unknown_int, in, version );
  };
};

void NifStream( Texture2 const & val, ostream & out, uint version ) {
  NifStream( val.is_used, out, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture_data, out, version );
    NifStream( val.unknown_int, out, version );
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
  uint num_textures;
  NifStream( num_textures, in, version );
  val.textures.resize(num_textures);
  NifStream( val.textures, in, version );
};

void NifStream( ExtraTextureGroup const & val, ostream & out, uint version ) {
  uint num_textures;
  num_textures = uint(val.textures.size());
  NifStream( num_textures, out, version );
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
  ushort num_strips;
  // List of bones.
  vector<ushort > bones;
  // Do we have a vertex map?
  bool has_vertex_map;
  // Maps the weight/influence lists in this submesh to the vertices in the shape being skinned.
  vector<ushort > vertex_map;
  // Do we have vertex weights?
  bool has_vertex_weights;
  // The vertex weights.
  vector<vector<float > > vertex_weights;
  // Do we have strip data?
  bool has_strips;
  // The strips.
  vector<vector<ushort > > strips;
  // The triangles.
  vector<Triangle > triangles;
  // Do we have bone indices?
  bool has_bone_indices;
  // Bone indices, they index into 'Bones'.
  vector<vector<byte > > bone_indices;
  SkinPartition() {};
};

void NifStream( SkinPartition & val, istream & in, uint version ) {
  ushort num_vertices;
  ushort num_triangles;
  ushort num_bones;
  ushort num_weights_per_vertex;
  vector<ushort > strip_lengths;
  NifStream( num_vertices, in, version );
  NifStream( num_triangles, in, version );
  NifStream( num_bones, in, version );
  NifStream( val.num_strips, in, version );
  NifStream( num_weights_per_vertex, in, version );
  val.bones.resize(num_bones);
  NifStream( val.bones, in, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.has_vertex_map, in, version );
  };
  if ( version <= 0x0A000102 ) {
    val.vertex_map.resize(num_vertices);
    NifStream( val.vertex_map, in, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.has_vertex_map != 0 ) {
      val.vertex_map.resize(num_vertices);
      NifStream( val.vertex_map, in, version );
    };
    NifStream( val.has_vertex_weights, in, version );
  };
  if ( version <= 0x0A000102 ) {
    val.vertex_weights.resize(num_vertices);
    for (uint i = 0; i < num_vertices; i++) {
      val.vertex_weights[i].resize(num_weights_per_vertex);
    };
    NifStream( val.vertex_weights, in, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.has_vertex_weights != 0 ) {
      val.vertex_weights.resize(num_vertices);
      for (uint i = 0; i < num_vertices; i++) {
        val.vertex_weights[i].resize(num_weights_per_vertex);
      };
      NifStream( val.vertex_weights, in, version );
    };
  };
  strip_lengths.resize(val.num_strips);
  NifStream( strip_lengths, in, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.has_strips, in, version );
  };
  if ( version <= 0x0A000102 ) {
    val.strips.resize(val.num_strips);
    for (uint i = 0; i < val.num_strips; i++) {
      val.strips[i].resize(strip_lengths[i]);
    };
    NifStream( val.strips, in, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.has_strips != 0 ) {
      val.strips.resize(val.num_strips);
      for (uint i = 0; i < val.num_strips; i++) {
        val.strips[i].resize(strip_lengths[i]);
      };
      NifStream( val.strips, in, version );
    };
  };
  if ( val.num_strips == 0 ) {
    val.triangles.resize(num_triangles);
    NifStream( val.triangles, in, version );
  };
  NifStream( val.has_bone_indices, in, version );
  if ( val.has_bone_indices != 0 ) {
    val.bone_indices.resize(num_vertices);
    for (uint i = 0; i < num_vertices; i++) {
      val.bone_indices[i].resize(num_weights_per_vertex);
    };
    NifStream( val.bone_indices, in, version );
  };
};

void NifStream( SkinPartition const & val, ostream & out, uint version ) {
  ushort num_vertices;
  ushort num_triangles;
  ushort num_bones;
  ushort num_weights_per_vertex;
  vector<ushort > strip_lengths;
  num_vertices = ushort(val.vertex_map.size());
  num_triangles = ushort(val.triangles.size());
  num_bones = ushort(val.bones.size());
  num_weights_per_vertex = ushort(val.vertex_weights.size());
  strip_lengths.resize(val.strips.size()); for (uint i = 0; i < val.strips.size(); i++) strip_lengths[i] = ushort(val.strips[i].size());
  NifStream( num_vertices, out, version );
  NifStream( num_triangles, out, version );
  NifStream( num_bones, out, version );
  NifStream( val.num_strips, out, version );
  NifStream( num_weights_per_vertex, out, version );
  NifStream( val.bones, out, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.has_vertex_map, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.vertex_map, out, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.has_vertex_map != 0 ) {
      NifStream( val.vertex_map, out, version );
    };
    NifStream( val.has_vertex_weights, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.vertex_weights, out, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.has_vertex_weights != 0 ) {
      NifStream( val.vertex_weights, out, version );
    };
  };
  NifStream( strip_lengths, out, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.has_strips, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.strips, out, version );
  };
  if ( version >= 0x0A010000 ) {
    if ( val.has_strips != 0 ) {
      NifStream( val.strips, out, version );
    };
  };
  if ( val.num_strips == 0 ) {
    NifStream( val.triangles, out, version );
  };
  NifStream( val.has_bone_indices, out, version );
  if ( val.has_bone_indices != 0 ) {
    NifStream( val.bone_indices, out, version );
  };
};

ostream & operator<<( ostream & out, SkinPartition const & val );

// 
// Unknown.
//
struct unk292bytes {
  // Unknown.
  vector<vector<byte > > unknown_292_bytes;
  unk292bytes() {};
};

void NifStream( unk292bytes & val, istream & in, uint version ) {
  val.unknown_292_bytes.resize(73);
  for (uint i = 0; i < 73; i++) {
    val.unknown_292_bytes[i].resize(4);
  };
  NifStream( val.unknown_292_bytes, in, version );
};

void NifStream( unk292bytes const & val, ostream & out, uint version ) {
  NifStream( val.unknown_292_bytes, out, version );
};

ostream & operator<<( ostream & out, unk292bytes const & val );

// 
// Describes a furniture position?
//
struct FurniturePosition {
  // Unknown. Position?
  Vector3 unknown_vector;
  // Unknown.
  ushort unknown_short;
  // This might refer to a furnituremarkerxx.nif file.
  byte position_ref_1_;
  // This might also refer to a furnituremarkerxx.nif file.
  byte position_ref_2_;
  FurniturePosition() {};
};

void NifStream( FurniturePosition & val, istream & in, uint version ) {
  NifStream( val.unknown_vector, in, version );
  NifStream( val.unknown_short, in, version );
  NifStream( val.position_ref_1_, in, version );
  NifStream( val.position_ref_2_, in, version );
};

void NifStream( FurniturePosition const & val, ostream & out, uint version ) {
  NifStream( val.unknown_vector, out, version );
  NifStream( val.unknown_short, out, version );
  NifStream( val.position_ref_1_, out, version );
  NifStream( val.position_ref_2_, out, version );
};

ostream & operator<<( ostream & out, FurniturePosition const & val );

// 
// A triangle with extra data used for physics.
//
struct hkTriangle {
  // The triangle.
  Triangle triangle;
  // Another short, doesn't look like a vertex index.
  ushort unknown_short;
  // This appears to be a normalized vector, so probably it is a normal or a tangent vector or something like that.
  Vector3 normal;
  hkTriangle() {};
};

void NifStream( hkTriangle & val, istream & in, uint version ) {
  NifStream( val.triangle, in, version );
  NifStream( val.unknown_short, in, version );
  NifStream( val.normal, in, version );
};

void NifStream( hkTriangle const & val, ostream & out, uint version ) {
  NifStream( val.triangle, out, version );
  NifStream( val.unknown_short, out, version );
  NifStream( val.normal, out, version );
};

ostream & operator<<( ostream & out, hkTriangle const & val );

// 
// Info about level of detail ranges.
//
struct LODInfo {
  // Type of LOD info (0=regular, 1=info is in a NiRangeLODData block).
  uint lod_type;
  // ?
  Vector3 lod_center;
  // The ranges of distance that each level of detail applies in.
  vector<LODRange > lod_levels;
  // Zero?
  ushort unknown_short;
  // Refers to NiRangeLODData block.
  uint range_data;
  LODInfo() {};
};

void NifStream( LODInfo & val, istream & in, uint version ) {
  uint num_lod_levels;
  NifStream( val.lod_type, in, version );
  if ( val.lod_type == 0 ) {
    NifStream( val.lod_center, in, version );
    NifStream( num_lod_levels, in, version );
    val.lod_levels.resize(num_lod_levels);
    NifStream( val.lod_levels, in, version );
  };
  if ( val.lod_type == 1 ) {
    NifStream( val.unknown_short, in, version );
    NifStream( val.range_data, in, version );
  };
};

void NifStream( LODInfo const & val, ostream & out, uint version ) {
  uint num_lod_levels;
  num_lod_levels = uint(val.lod_levels.size());
  NifStream( val.lod_type, out, version );
  if ( val.lod_type == 0 ) {
    NifStream( val.lod_center, out, version );
    NifStream( num_lod_levels, out, version );
    NifStream( val.lod_levels, out, version );
  };
  if ( val.lod_type == 1 ) {
    NifStream( val.unknown_short, out, version );
    NifStream( val.range_data, out, version );
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
  Vector3 unknown_vector;
  // The particle's age.
  float lifetime;
  // Maximum age of the particle.
  float lifespan;
  // Timestamp of the last update.
  float timestamp;
  // Unknown short (=0)
  ushort unknown_short;
  // Particle/vertex index matches array index
  ushort vertex_id;
  Particle() {};
};

void NifStream( Particle & val, istream & in, uint version ) {
  NifStream( val.velocity, in, version );
  NifStream( val.unknown_vector, in, version );
  NifStream( val.lifetime, in, version );
  NifStream( val.lifespan, in, version );
  NifStream( val.timestamp, in, version );
  NifStream( val.unknown_short, in, version );
  NifStream( val.vertex_id, in, version );
};

void NifStream( Particle const & val, ostream & out, uint version ) {
  NifStream( val.velocity, out, version );
  NifStream( val.unknown_vector, out, version );
  NifStream( val.lifetime, out, version );
  NifStream( val.lifespan, out, version );
  NifStream( val.timestamp, out, version );
  NifStream( val.unknown_short, out, version );
  NifStream( val.vertex_id, out, version );
};

ostream & operator<<( ostream & out, Particle const & val );

// 
// Data for several particles.
//
struct ParticleGroup {
  // Number of valid entries in the following array.
  // (number of active particles at the time the system was saved)
  ushort num_valid;
  // Individual particle modifiers?
  vector<Particle > particles;
  ParticleGroup() {};
};

void NifStream( ParticleGroup & val, istream & in, uint version ) {
  ushort num_particles;
  NifStream( num_particles, in, version );
  NifStream( val.num_valid, in, version );
  val.particles.resize(num_particles);
  NifStream( val.particles, in, version );
};

void NifStream( ParticleGroup const & val, ostream & out, uint version ) {
  ushort num_particles;
  num_particles = ushort(val.particles.size());
  NifStream( num_particles, out, version );
  NifStream( val.num_valid, out, version );
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
  vector<float > unknown_4_floats;
  // The vertex weights.
  vector<SkinWeight > vertex_weights;
  SkinData() {};
};

void NifStream( SkinData & val, istream & in, uint version ) {
  ushort num_vertices;
  NifStream( val.rotation, in, version );
  NifStream( val.translation, in, version );
  NifStream( val.scale, in, version );
  val.unknown_4_floats.resize(4);
  NifStream( val.unknown_4_floats, in, version );
  NifStream( num_vertices, in, version );
  val.vertex_weights.resize(num_vertices);
  NifStream( val.vertex_weights, in, version );
};

void NifStream( SkinData const & val, ostream & out, uint version ) {
  ushort num_vertices;
  num_vertices = ushort(val.vertex_weights.size());
  NifStream( val.rotation, out, version );
  NifStream( val.translation, out, version );
  NifStream( val.scale, out, version );
  NifStream( val.unknown_4_floats, out, version );
  NifStream( num_vertices, out, version );
  NifStream( val.vertex_weights, out, version );
};

ostream & operator<<( ostream & out, SkinData const & val );

// 
// An array of keys. This one always has a Key Type.
//
template <class T >
struct TypedVectorKeyArray {
  // The key type.
  uint key_type;
  // The keys.
  vector<Key<T > > keys;
  TypedVectorKeyArray() {};
};

template <class T >
void NifStream( TypedVectorKeyArray<T> & val, istream & in, uint version ) {
  uint num_keys;
  NifStream( num_keys, in, version );
  NifStream( val.key_type, in, version );
  val.keys.resize(num_keys);
  NifStream( val.keys, in, version, val.key_type );
};

template <class T >
void NifStream( TypedVectorKeyArray<T> const & val, ostream & out, uint version ) {
  uint num_keys;
  num_keys = uint(val.keys.size());
  NifStream( num_keys, out, version );
  NifStream( val.key_type, out, version );
  NifStream( val.keys, out, version, val.key_type );
};

template <class T >
ostream & operator<<( ostream & out, TypedVectorKeyArray<T> const & val );

// 
// Geometry morphing data component.
//
struct Morph {
  // Name of the frame.
  string frame_name;
  // The morphing keyframes.
  TypedVectorKeyArray<float > frames;
  // Unknown.
  uint unknown_int;
  // Morph vectors.
  vector<Vector3 > vectors;
  Morph() {};
};

void NifStream( Morph & val, istream & in, uint version, uint attr_arg ) {
  if ( version >= 0x0A01006A ) {
    NifStream( val.frame_name, in, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.frames, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknown_int, in, version );
  };
  val.vectors.resize(attr_arg);
  NifStream( val.vectors, in, version );
};

void NifStream( Morph const & val, ostream & out, uint version, uint attr_arg ) {
  if ( version >= 0x0A01006A ) {
    NifStream( val.frame_name, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.frames, out, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknown_int, out, version );
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
  uint num_keys;
  // The key type.
  uint key_type;
  // The keys.
  vector<Key<T > > keys;
  VectorKeyArray() {};
};

template <class T >
void NifStream( VectorKeyArray<T> & val, istream & in, uint version ) {
  NifStream( val.num_keys, in, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, in, version );
  };
  val.keys.resize(val.num_keys);
  NifStream( val.keys, in, version, val.key_type );
};

template <class T >
void NifStream( VectorKeyArray<T> const & val, ostream & out, uint version ) {
  NifStream( val.num_keys, out, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, out, version );
  };
  NifStream( val.keys, out, version, val.key_type );
};

template <class T >
ostream & operator<<( ostream & out, VectorKeyArray<T> const & val );

// 
// Rotation key array.
//
template <class T >
struct RotationKeyArray {
  // Number of keys.
  uint num_keys;
  // Key type (1, 2, 3, or 4).
  uint key_type;
  // The rotation keys.
  vector<Key<T > > keys;
  RotationKeyArray() {};
};

template <class T >
void NifStream( RotationKeyArray<T> & val, istream & in, uint version ) {
  NifStream( val.num_keys, in, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, in, version );
  };
  val.keys.resize(val.num_keys);
  NifStream( val.keys, in, version, val.key_type );
};

template <class T >
void NifStream( RotationKeyArray<T> const & val, ostream & out, uint version ) {
  NifStream( val.num_keys, out, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, out, version );
  };
  NifStream( val.keys, out, version, val.key_type );
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
uint extra_data; \
LinkGroup extra_data_list; \
uint controller; \

#define A_CONTROLLABLE_GETATTR \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Extra Data" ) \
  return attr_ref(extra_data); \
if ( attr_name == "Controller" ) \
  return attr_ref(controller); \
return attr_ref(); \

#define A_CONTROLLABLE_PARENTS ABlock

#define A_CONTROLLABLE_CONSTRUCT

#define A_CONTROLLABLE_READ \
NifStream( name, in, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( extra_data, in, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( extra_data_list, in, version ); \
}; \
NifStream( controller, in, version ); \

#define A_CONTROLLABLE_WRITE \
NifStream( name, out, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( extra_data, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( extra_data_list, out, version ); \
}; \
NifStream( controller, out, version ); \

#define A_CONTROLLABLE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << "                Name:  " << name << endl; \
out << "          Extra Data:  " << extra_data << endl; \
out << "     Extra Data List:  " << extra_data_list << endl; \
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
uint next_controller; \
Flags flags; \
float frequency; \
float phase; \
float start_time; \
float stop_time; \
uint target; \

#define A_CONTROLLER_GETATTR \
if ( attr_name == "Next Controller" ) \
  return attr_ref(next_controller); \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Frequency" ) \
  return attr_ref(frequency); \
if ( attr_name == "Phase" ) \
  return attr_ref(phase); \
if ( attr_name == "Start Time" ) \
  return attr_ref(start_time); \
if ( attr_name == "Stop Time" ) \
  return attr_ref(stop_time); \
if ( attr_name == "Target" ) \
  return attr_ref(target); \
return attr_ref(); \

#define A_CONTROLLER_PARENTS ABlock

#define A_CONTROLLER_CONSTRUCT

#define A_CONTROLLER_READ \
NifStream( next_controller, in, version ); \
NifStream( flags, in, version ); \
NifStream( frequency, in, version ); \
NifStream( phase, in, version ); \
NifStream( start_time, in, version ); \
NifStream( stop_time, in, version ); \
NifStream( target, in, version ); \

#define A_CONTROLLER_WRITE \
NifStream( next_controller, out, version ); \
NifStream( flags, out, version ); \
NifStream( frequency, out, version ); \
NifStream( phase, out, version ); \
NifStream( start_time, out, version ); \
NifStream( stop_time, out, version ); \
NifStream( target, out, version ); \

#define A_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << "     Next Controller:  " << next_controller << endl; \
out << "               Flags:  " << flags << endl; \
out << "           Frequency:  " << frequency << endl; \
out << "               Phase:  " << phase << endl; \
out << "          Start Time:  " << start_time << endl; \
out << "           Stop Time:  " << stop_time << endl; \
out << "              Target:  " << target << endl; \
return out.str(); \

// 
// Level of detail controller for bones?
//
// - Unknown.
// - Unknown.
// - A list of node groups (each group a sequence of bones?).
#define A_BONE_L_O_D_CONTROLLER_MEMBERS \
uint unknown_int_1; \
uint unknown_int_2; \
vector<LinkGroup > node_groups; \

#define A_BONE_L_O_D_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
return attr_ref(); \

#define A_BONE_L_O_D_CONTROLLER_PARENTS AController

#define A_BONE_L_O_D_CONTROLLER_CONSTRUCT

#define A_BONE_L_O_D_CONTROLLER_READ \
uint num_node_groups; \
AController::Read( in, version ); \
NifStream( unknown_int_1, in, version ); \
NifStream( num_node_groups, in, version ); \
NifStream( unknown_int_2, in, version ); \
node_groups.resize(num_node_groups); \
NifStream( node_groups, in, version ); \

#define A_BONE_L_O_D_CONTROLLER_WRITE \
uint num_node_groups; \
AController::Write( out, version ); \
num_node_groups = uint(node_groups.size()); \
NifStream( unknown_int_1, out, version ); \
NifStream( num_node_groups, out, version ); \
NifStream( unknown_int_2, out, version ); \
NifStream( node_groups, out, version ); \

#define A_BONE_L_O_D_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "     Num Node Groups:  -- calculated --" << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
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
vector<uint > bodies; \
uint unknown_int; \

#define ABHK_CONSTRAINT_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
return attr_ref(); \

#define ABHK_CONSTRAINT_PARENTS AData

#define ABHK_CONSTRAINT_CONSTRUCT

#define ABHK_CONSTRAINT_READ \
uint num_bodies; \
AData::Read( in, version ); \
NifStream( num_bodies, in, version ); \
bodies.resize(num_bodies); \
NifStream( bodies, in, version ); \
NifStream( unknown_int, in, version ); \

#define ABHK_CONSTRAINT_WRITE \
uint num_bodies; \
AData::Write( out, version ); \
num_bodies = uint(bodies.size()); \
NifStream( num_bodies, out, version ); \
NifStream( bodies, out, version ); \
NifStream( unknown_int, out, version ); \

#define ABHK_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "          Num Bodies:  -- calculated --" << endl; \
out << "              Bodies:  -- data not shown --" << endl; \
out << "         Unknown Int:  " << unknown_int << endl; \
return out.str(); \

// 
// Ragdoll constraint.
//
// - Unknown floats.
// - Unknown.
// - Unknown.
#define ABHK_RAGDOLL_CONSTRAINT_MEMBERS \
vector<vector<float > > unknown_floats; \
float unknown_float_1; \
float unknown_float_2; \

#define ABHK_RAGDOLL_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
return attr_ref(); \

#define ABHK_RAGDOLL_CONSTRAINT_PARENTS AbhkConstraint

#define ABHK_RAGDOLL_CONSTRAINT_CONSTRUCT

#define ABHK_RAGDOLL_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
unknown_floats.resize(7); \
NifStream( unknown_floats, in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_float_2, in, version ); \

#define ABHK_RAGDOLL_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( unknown_floats, out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_float_2, out, version ); \

#define ABHK_RAGDOLL_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkConstraint::asString(); \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
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
uint shape; \
uint flags; \
vector<float > unknown_floats_1; \
vector<ushort > unknown_shorts_1; \
uint flags_2; \
vector<ushort > unknown_shorts_2; \
Vector3 translation; \
float unknown_float_00; \
QuaternionXYZW rotation; \
vector<float > unknown_floats_2; \
vector<float > transform_; \
Vector3 center; \
float unknown_float_01; \
float mass; \
float unknown_float_0; \
float unknown_float_1; \
float friction; \
float elasticity; \
float unknown_float_2; \
float unknown_float_3; \
float unknown_float_4; \
vector<byte > unknown_bytes_5; \
uint unknown_int_6; \
uint unknown_int_7; \
uint unknown_int_8; \
LinkGroup constraints; \

#define ABHK_RIGID_BODY_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Shape" ) \
  return attr_ref(shape); \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Flags 2" ) \
  return attr_ref(flags_2); \
if ( attr_name == "Translation" ) \
  return attr_ref(translation); \
if ( attr_name == "Unknown Float 00" ) \
  return attr_ref(unknown_float_00); \
if ( attr_name == "Center" ) \
  return attr_ref(center); \
if ( attr_name == "Unknown Float 01" ) \
  return attr_ref(unknown_float_01); \
if ( attr_name == "Mass" ) \
  return attr_ref(mass); \
if ( attr_name == "Unknown Float 0" ) \
  return attr_ref(unknown_float_0); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Friction" ) \
  return attr_ref(friction); \
if ( attr_name == "Elasticity" ) \
  return attr_ref(elasticity); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknown_float_3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknown_float_4); \
if ( attr_name == "Unknown Int 6" ) \
  return attr_ref(unknown_int_6); \
if ( attr_name == "Unknown Int 7" ) \
  return attr_ref(unknown_int_7); \
if ( attr_name == "Unknown Int 8" ) \
  return attr_ref(unknown_int_8); \
return attr_ref(); \

#define ABHK_RIGID_BODY_PARENTS AData

#define ABHK_RIGID_BODY_CONSTRUCT

#define ABHK_RIGID_BODY_READ \
AData::Read( in, version ); \
NifStream( shape, in, version ); \
NifStream( flags, in, version ); \
unknown_floats_1.resize(5); \
NifStream( unknown_floats_1, in, version ); \
unknown_shorts_1.resize(4); \
NifStream( unknown_shorts_1, in, version ); \
NifStream( flags_2, in, version ); \
unknown_shorts_2.resize(6); \
NifStream( unknown_shorts_2, in, version ); \
NifStream( translation, in, version ); \
NifStream( unknown_float_00, in, version ); \
NifStream( rotation, in, version ); \
unknown_floats_2.resize(8); \
NifStream( unknown_floats_2, in, version ); \
transform_.resize(12); \
NifStream( transform_, in, version ); \
NifStream( center, in, version ); \
NifStream( unknown_float_01, in, version ); \
NifStream( mass, in, version ); \
NifStream( unknown_float_0, in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( friction, in, version ); \
NifStream( elasticity, in, version ); \
NifStream( unknown_float_2, in, version ); \
NifStream( unknown_float_3, in, version ); \
NifStream( unknown_float_4, in, version ); \
unknown_bytes_5.resize(4); \
NifStream( unknown_bytes_5, in, version ); \
NifStream( unknown_int_6, in, version ); \
NifStream( unknown_int_7, in, version ); \
NifStream( unknown_int_8, in, version ); \
NifStream( constraints, in, version ); \
NifStream( unknown_int_6, in, version ); \

#define ABHK_RIGID_BODY_WRITE \
AData::Write( out, version ); \
NifStream( shape, out, version ); \
NifStream( flags, out, version ); \
NifStream( unknown_floats_1, out, version ); \
NifStream( unknown_shorts_1, out, version ); \
NifStream( flags_2, out, version ); \
NifStream( unknown_shorts_2, out, version ); \
NifStream( translation, out, version ); \
NifStream( unknown_float_00, out, version ); \
NifStream( rotation, out, version ); \
NifStream( unknown_floats_2, out, version ); \
NifStream( transform_, out, version ); \
NifStream( center, out, version ); \
NifStream( unknown_float_01, out, version ); \
NifStream( mass, out, version ); \
NifStream( unknown_float_0, out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( friction, out, version ); \
NifStream( elasticity, out, version ); \
NifStream( unknown_float_2, out, version ); \
NifStream( unknown_float_3, out, version ); \
NifStream( unknown_float_4, out, version ); \
NifStream( unknown_bytes_5, out, version ); \
NifStream( unknown_int_6, out, version ); \
NifStream( unknown_int_7, out, version ); \
NifStream( unknown_int_8, out, version ); \
NifStream( constraints, out, version ); \
NifStream( unknown_int_6, out, version ); \

#define ABHK_RIGID_BODY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "               Shape:  " << shape << endl; \
out << "               Flags:  " << flags << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "    Unknown Shorts 1:  -- data not shown --" << endl; \
out << "             Flags 2:  " << flags_2 << endl; \
out << "    Unknown Shorts 2:  -- data not shown --" << endl; \
out << "         Translation:  " << translation << endl; \
out << "    Unknown Float 00:  " << unknown_float_00 << endl; \
out << "            Rotation:  " << rotation << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
out << "          Transform?:  -- data not shown --" << endl; \
out << "              Center:  " << center << endl; \
out << "    Unknown Float 01:  " << unknown_float_01 << endl; \
out << "                Mass:  " << mass << endl; \
out << "     Unknown Float 0:  " << unknown_float_0 << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "            Friction:  " << friction << endl; \
out << "          Elasticity:  " << elasticity << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "     Unknown Float 3:  " << unknown_float_3 << endl; \
out << "     Unknown Float 4:  " << unknown_float_4 << endl; \
out << "     Unknown Bytes 5:  -- data not shown --" << endl; \
out << "       Unknown Int 6:  " << unknown_int_6 << endl; \
out << "       Unknown Int 7:  " << unknown_int_7 << endl; \
out << "       Unknown Int 8:  " << unknown_int_8 << endl; \
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
uint sub_shape; \
uint unknown_int; \
float unknown_float_1; \
float unknown_float_2; \
float unknown_float_3; \
Matrix44 transform; \

#define ABHK_TRANSFORM_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Sub Shape" ) \
  return attr_ref(sub_shape); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknown_float_3); \
if ( attr_name == "Transform" ) \
  return attr_ref(transform); \
return attr_ref(); \

#define ABHK_TRANSFORM_SHAPE_PARENTS AbhkShape

#define ABHK_TRANSFORM_SHAPE_CONSTRUCT

#define ABHK_TRANSFORM_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( sub_shape, in, version ); \
NifStream( unknown_int, in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_float_2, in, version ); \
NifStream( unknown_float_3, in, version ); \
NifStream( transform, in, version ); \

#define ABHK_TRANSFORM_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( sub_shape, out, version ); \
NifStream( unknown_int, out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_float_2, out, version ); \
NifStream( unknown_float_3, out, version ); \
NifStream( transform, out, version ); \

#define ABHK_TRANSFORM_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "           Sub Shape:  " << sub_shape << endl; \
out << "         Unknown Int:  " << unknown_int << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "     Unknown Float 3:  " << unknown_float_3 << endl; \
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
ushort unknown_short; \
uint body; \

#define A_COLLISION_OBJECT_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Parent" ) \
  return attr_ref(parent); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Body" ) \
  return attr_ref(body); \
return attr_ref(); \

#define A_COLLISION_OBJECT_PARENTS AData

#define A_COLLISION_OBJECT_CONSTRUCT

#define A_COLLISION_OBJECT_READ \
AData::Read( in, version ); \
NifStream( parent, in, version ); \
NifStream( unknown_short, in, version ); \
NifStream( body, in, version ); \

#define A_COLLISION_OBJECT_WRITE \
AData::Write( out, version ); \
NifStream( parent, out, version ); \
NifStream( unknown_short, out, version ); \
NifStream( body, out, version ); \

#define A_COLLISION_OBJECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "              Parent:  " << parent << endl; \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "                Body:  " << body << endl; \
return out.str(); \

// 
// A generic extra data block.
//
// - Name of this block.
// - Block number of the next extra data block.
#define A_EXTRA_DATA_MEMBERS \
string name; \
uint next_extra_data; \

#define A_EXTRA_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Next Extra Data" ) \
  return attr_ref(next_extra_data); \
return attr_ref(); \

#define A_EXTRA_DATA_PARENTS AData

#define A_EXTRA_DATA_CONSTRUCT

#define A_EXTRA_DATA_READ \
AData::Read( in, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( name, in, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( next_extra_data, in, version ); \
}; \

#define A_EXTRA_DATA_WRITE \
AData::Write( out, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( name, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( next_extra_data, out, version ); \
}; \

#define A_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "     Next Extra Data:  " << next_extra_data << endl; \
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
ushort unknown_short; \
uint unknown_int; \

#define A_BLEND_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
return attr_ref(); \

#define A_BLEND_INTERPOLATOR_PARENTS AInterpolator

#define A_BLEND_INTERPOLATOR_CONSTRUCT

#define A_BLEND_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( unknown_short, in, version ); \
NifStream( unknown_int, in, version ); \

#define A_BLEND_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( unknown_short, out, version ); \
NifStream( unknown_int, out, version ); \

#define A_BLEND_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "         Unknown Int:  " << unknown_int << endl; \
return out.str(); \

// 
// A B-spline (component?) interpolator.
//
// - Animation start time.
// - Animation stop time.
#define A_B_SPLINE_COMP_INTERPOLATOR_MEMBERS \
float start_time; \
float stop_time; \

#define A_B_SPLINE_COMP_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Start Time" ) \
  return attr_ref(start_time); \
if ( attr_name == "Stop Time" ) \
  return attr_ref(stop_time); \
return attr_ref(); \

#define A_B_SPLINE_COMP_INTERPOLATOR_PARENTS AInterpolator

#define A_B_SPLINE_COMP_INTERPOLATOR_CONSTRUCT

#define A_B_SPLINE_COMP_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( start_time, in, version ); \
NifStream( stop_time, in, version ); \

#define A_B_SPLINE_COMP_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( start_time, out, version ); \
NifStream( stop_time, out, version ); \

#define A_B_SPLINE_COMP_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "          Start Time:  " << start_time << endl; \
out << "           Stop Time:  " << stop_time << endl; \
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
uint data; \

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
BoundingBox bounding_box; \
uint collision_data; \

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
  return attr_ref(bounding_box); \
if ( attr_name == "Collision Data" ) \
  return attr_ref(collision_data); \
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
  NifStream( bounding_box, in, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( collision_data, in, version ); \
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
  NifStream( bounding_box, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( collision_data, out, version ); \
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
out << "        Bounding Box:  " << bounding_box << endl; \
out << "      Collision Data:  " << collision_data << endl; \
return out.str(); \

// 
// A dynamic effect such as a light or environment map.
//
// - This is probably the list of affected nodes. For some reason i do not know the max exporter seems to write pointers instead of links. But it doesn't matter because at least in version 4.0.0.2 the list is automagically updated by the engine during the load stage.
// - Turns effect on and off?  Switches list to list of unaffected nodes?
// - The list of affected nodes?
#define A_DYNAMIC_EFFECT_MEMBERS \
CondInt affected_node_list_; \
bool switch_state; \
LinkGroup affected_nodes; \

#define A_DYNAMIC_EFFECT_GETATTR \
attr_ref attr = ANode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Switch State" ) \
  return attr_ref(switch_state); \
return attr_ref(); \

#define A_DYNAMIC_EFFECT_PARENTS ANode

#define A_DYNAMIC_EFFECT_CONSTRUCT

#define A_DYNAMIC_EFFECT_READ \
ANode::Read( in, version ); \
if ( version <= 0x04000002 ) { \
  NifStream( affected_node_list_, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( switch_state, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  NifStream( affected_nodes, in, version ); \
}; \

#define A_DYNAMIC_EFFECT_WRITE \
ANode::Write( out, version ); \
if ( version <= 0x04000002 ) { \
  NifStream( affected_node_list_, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( switch_state, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  NifStream( affected_nodes, out, version ); \
}; \

#define A_DYNAMIC_EFFECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ANode::asString(); \
out << " Affected Node List?:  " << affected_node_list_ << endl; \
out << "        Switch State:  " << switch_state << endl; \
out << "      Affected Nodes:  " << affected_nodes << endl; \
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
Color3 ambient_color; \
Color3 diffuse_color; \
Color3 specular_color; \

#define A_LIGHT_GETATTR \
attr_ref attr = ADynamicEffect::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Dimmer" ) \
  return attr_ref(dimmer); \
if ( attr_name == "Ambient Color" ) \
  return attr_ref(ambient_color); \
if ( attr_name == "Diffuse Color" ) \
  return attr_ref(diffuse_color); \
if ( attr_name == "Specular Color" ) \
  return attr_ref(specular_color); \
return attr_ref(); \

#define A_LIGHT_PARENTS ADynamicEffect

#define A_LIGHT_CONSTRUCT

#define A_LIGHT_READ \
ADynamicEffect::Read( in, version ); \
NifStream( dimmer, in, version ); \
NifStream( ambient_color, in, version ); \
NifStream( diffuse_color, in, version ); \
NifStream( specular_color, in, version ); \

#define A_LIGHT_WRITE \
ADynamicEffect::Write( out, version ); \
NifStream( dimmer, out, version ); \
NifStream( ambient_color, out, version ); \
NifStream( diffuse_color, out, version ); \
NifStream( specular_color, out, version ); \

#define A_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ADynamicEffect::asString(); \
out << "              Dimmer:  " << dimmer << endl; \
out << "       Ambient Color:  " << ambient_color << endl; \
out << "       Diffuse Color:  " << diffuse_color << endl; \
out << "      Specular Color:  " << specular_color << endl; \
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
uint next_modifier; \
uint previous_modifier; \

#define A_PARTICLE_MODIFIER_GETATTR \
if ( attr_name == "Next Modifier" ) \
  return attr_ref(next_modifier); \
if ( attr_name == "Previous Modifier" ) \
  return attr_ref(previous_modifier); \
return attr_ref(); \

#define A_PARTICLE_MODIFIER_PARENTS ABlock

#define A_PARTICLE_MODIFIER_CONSTRUCT

#define A_PARTICLE_MODIFIER_READ \
NifStream( next_modifier, in, version ); \
NifStream( previous_modifier, in, version ); \

#define A_PARTICLE_MODIFIER_WRITE \
NifStream( next_modifier, out, version ); \
NifStream( previous_modifier, out, version ); \

#define A_PARTICLE_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << "       Next Modifier:  " << next_modifier << endl; \
out << "   Previous Modifier:  " << previous_modifier << endl; \
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
float speed_random; \
float vertical_direction; \
float vertical_angle; \
float horizontal_direction; \
float horizontal_angle; \
float unknown_float_5; \
float unknown_float_6; \
float unknown_float_7; \
float unknown_float_8; \
float unknown_float_9; \
float unknown_float_10; \
float unknown_float_11; \
float size; \
float emit_start_time; \
float emit_stop_time; \
byte unknown_byte; \
float emit_rate; \
float lifetime; \
float lifetime_random; \
ushort emit_flags; \
Vector3 start_random; \
uint emitter; \
ushort unknown_short_2_; \
float unknown_float_13_; \
uint unknown_int_1_; \
uint unknown_int_2_; \
ushort unknown_short_3_; \
ParticleGroup particles; \
uint unknown_link; \
uint particle_extra; \
uint unknown_link_2; \
byte trailer; \

#define A_PARTICLE_SYSTEM_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Speed" ) \
  return attr_ref(speed); \
if ( attr_name == "Speed Random" ) \
  return attr_ref(speed_random); \
if ( attr_name == "Vertical Direction" ) \
  return attr_ref(vertical_direction); \
if ( attr_name == "Vertical Angle" ) \
  return attr_ref(vertical_angle); \
if ( attr_name == "Horizontal Direction" ) \
  return attr_ref(horizontal_direction); \
if ( attr_name == "Horizontal Angle" ) \
  return attr_ref(horizontal_angle); \
if ( attr_name == "Unknown Float 5" ) \
  return attr_ref(unknown_float_5); \
if ( attr_name == "Unknown Float 6" ) \
  return attr_ref(unknown_float_6); \
if ( attr_name == "Unknown Float 7" ) \
  return attr_ref(unknown_float_7); \
if ( attr_name == "Unknown Float 8" ) \
  return attr_ref(unknown_float_8); \
if ( attr_name == "Unknown Float 9" ) \
  return attr_ref(unknown_float_9); \
if ( attr_name == "Unknown Float 10" ) \
  return attr_ref(unknown_float_10); \
if ( attr_name == "Unknown Float 11" ) \
  return attr_ref(unknown_float_11); \
if ( attr_name == "Size" ) \
  return attr_ref(size); \
if ( attr_name == "Emit Start Time" ) \
  return attr_ref(emit_start_time); \
if ( attr_name == "Emit Stop Time" ) \
  return attr_ref(emit_stop_time); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
if ( attr_name == "Emit Rate" ) \
  return attr_ref(emit_rate); \
if ( attr_name == "Lifetime" ) \
  return attr_ref(lifetime); \
if ( attr_name == "Lifetime Random" ) \
  return attr_ref(lifetime_random); \
if ( attr_name == "Emit Flags" ) \
  return attr_ref(emit_flags); \
if ( attr_name == "Start Random" ) \
  return attr_ref(start_random); \
if ( attr_name == "Emitter" ) \
  return attr_ref(emitter); \
if ( attr_name == "Unknown Short 2?" ) \
  return attr_ref(unknown_short_2_); \
if ( attr_name == "Unknown Float 13?" ) \
  return attr_ref(unknown_float_13_); \
if ( attr_name == "Unknown Int 1?" ) \
  return attr_ref(unknown_int_1_); \
if ( attr_name == "Unknown Int 2?" ) \
  return attr_ref(unknown_int_2_); \
if ( attr_name == "Unknown Short 3?" ) \
  return attr_ref(unknown_short_3_); \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknown_link); \
if ( attr_name == "Particle Extra" ) \
  return attr_ref(particle_extra); \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknown_link_2); \
if ( attr_name == "Trailer" ) \
  return attr_ref(trailer); \
return attr_ref(); \

#define A_PARTICLE_SYSTEM_CONTROLLER_PARENTS AController

#define A_PARTICLE_SYSTEM_CONTROLLER_CONSTRUCT

#define A_PARTICLE_SYSTEM_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( speed, in, version ); \
NifStream( speed_random, in, version ); \
NifStream( vertical_direction, in, version ); \
NifStream( vertical_angle, in, version ); \
NifStream( horizontal_direction, in, version ); \
NifStream( horizontal_angle, in, version ); \
NifStream( unknown_float_5, in, version ); \
NifStream( unknown_float_6, in, version ); \
NifStream( unknown_float_7, in, version ); \
NifStream( unknown_float_8, in, version ); \
NifStream( unknown_float_9, in, version ); \
NifStream( unknown_float_10, in, version ); \
NifStream( unknown_float_11, in, version ); \
NifStream( size, in, version ); \
NifStream( emit_start_time, in, version ); \
NifStream( emit_stop_time, in, version ); \
NifStream( unknown_byte, in, version ); \
NifStream( emit_rate, in, version ); \
NifStream( lifetime, in, version ); \
NifStream( lifetime_random, in, version ); \
NifStream( emit_flags, in, version ); \
NifStream( start_random, in, version ); \
NifStream( emitter, in, version ); \
NifStream( unknown_short_2_, in, version ); \
NifStream( unknown_float_13_, in, version ); \
NifStream( unknown_int_1_, in, version ); \
NifStream( unknown_int_2_, in, version ); \
NifStream( unknown_short_3_, in, version ); \
NifStream( particles, in, version ); \
NifStream( unknown_link, in, version ); \
NifStream( particle_extra, in, version ); \
NifStream( unknown_link_2, in, version ); \
NifStream( trailer, in, version ); \

#define A_PARTICLE_SYSTEM_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( speed, out, version ); \
NifStream( speed_random, out, version ); \
NifStream( vertical_direction, out, version ); \
NifStream( vertical_angle, out, version ); \
NifStream( horizontal_direction, out, version ); \
NifStream( horizontal_angle, out, version ); \
NifStream( unknown_float_5, out, version ); \
NifStream( unknown_float_6, out, version ); \
NifStream( unknown_float_7, out, version ); \
NifStream( unknown_float_8, out, version ); \
NifStream( unknown_float_9, out, version ); \
NifStream( unknown_float_10, out, version ); \
NifStream( unknown_float_11, out, version ); \
NifStream( size, out, version ); \
NifStream( emit_start_time, out, version ); \
NifStream( emit_stop_time, out, version ); \
NifStream( unknown_byte, out, version ); \
NifStream( emit_rate, out, version ); \
NifStream( lifetime, out, version ); \
NifStream( lifetime_random, out, version ); \
NifStream( emit_flags, out, version ); \
NifStream( start_random, out, version ); \
NifStream( emitter, out, version ); \
NifStream( unknown_short_2_, out, version ); \
NifStream( unknown_float_13_, out, version ); \
NifStream( unknown_int_1_, out, version ); \
NifStream( unknown_int_2_, out, version ); \
NifStream( unknown_short_3_, out, version ); \
NifStream( particles, out, version ); \
NifStream( unknown_link, out, version ); \
NifStream( particle_extra, out, version ); \
NifStream( unknown_link_2, out, version ); \
NifStream( trailer, out, version ); \

#define A_PARTICLE_SYSTEM_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "               Speed:  " << speed << endl; \
out << "        Speed Random:  " << speed_random << endl; \
out << "  Vertical Direction:  " << vertical_direction << endl; \
out << "      Vertical Angle:  " << vertical_angle << endl; \
out << "Horizontal Direction:  " << horizontal_direction << endl; \
out << "    Horizontal Angle:  " << horizontal_angle << endl; \
out << "     Unknown Float 5:  " << unknown_float_5 << endl; \
out << "     Unknown Float 6:  " << unknown_float_6 << endl; \
out << "     Unknown Float 7:  " << unknown_float_7 << endl; \
out << "     Unknown Float 8:  " << unknown_float_8 << endl; \
out << "     Unknown Float 9:  " << unknown_float_9 << endl; \
out << "    Unknown Float 10:  " << unknown_float_10 << endl; \
out << "    Unknown Float 11:  " << unknown_float_11 << endl; \
out << "                Size:  " << size << endl; \
out << "     Emit Start Time:  " << emit_start_time << endl; \
out << "      Emit Stop Time:  " << emit_stop_time << endl; \
out << "        Unknown Byte:  " << unknown_byte << endl; \
out << "           Emit Rate:  " << emit_rate << endl; \
out << "            Lifetime:  " << lifetime << endl; \
out << "     Lifetime Random:  " << lifetime_random << endl; \
out << "          Emit Flags:  " << emit_flags << endl; \
out << "        Start Random:  " << start_random << endl; \
out << "             Emitter:  " << emitter << endl; \
out << "    Unknown Short 2?:  " << unknown_short_2_ << endl; \
out << "   Unknown Float 13?:  " << unknown_float_13_ << endl; \
out << "      Unknown Int 1?:  " << unknown_int_1_ << endl; \
out << "      Unknown Int 2?:  " << unknown_int_2_ << endl; \
out << "    Unknown Short 3?:  " << unknown_short_3_ << endl; \
out << "           Particles:  " << particles << endl; \
out << "        Unknown Link:  " << unknown_link << endl; \
out << "      Particle Extra:  " << particle_extra << endl; \
out << "      Unknown Link 2:  " << unknown_link_2 << endl; \
out << "             Trailer:  " << trailer << endl; \
return out.str(); \

// 
// A type of light.
//
// - Constant Attenuation
// - Linear Attenuation
// - Quadratic Attenuation (see glLight)
#define A_POINT_LIGHT_MEMBERS \
float constant_attenuation; \
float linear_attenuation; \
float quadratic_attenuation; \

#define A_POINT_LIGHT_GETATTR \
attr_ref attr = ALight::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Constant Attenuation" ) \
  return attr_ref(constant_attenuation); \
if ( attr_name == "Linear Attenuation" ) \
  return attr_ref(linear_attenuation); \
if ( attr_name == "Quadratic Attenuation" ) \
  return attr_ref(quadratic_attenuation); \
return attr_ref(); \

#define A_POINT_LIGHT_PARENTS ALight

#define A_POINT_LIGHT_CONSTRUCT

#define A_POINT_LIGHT_READ \
ALight::Read( in, version ); \
NifStream( constant_attenuation, in, version ); \
NifStream( linear_attenuation, in, version ); \
NifStream( quadratic_attenuation, in, version ); \

#define A_POINT_LIGHT_WRITE \
ALight::Write( out, version ); \
NifStream( constant_attenuation, out, version ); \
NifStream( linear_attenuation, out, version ); \
NifStream( quadratic_attenuation, out, version ); \

#define A_POINT_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ALight::asString(); \
out << "Constant Attenuation:  " << constant_attenuation << endl; \
out << "  Linear Attenuation:  " << linear_attenuation << endl; \
out << "Quadratic Attenuation:  " << quadratic_attenuation << endl; \
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
float speed_variation; \
float declination; \
float declination_variation; \
float planar_angle; \
float planar_angle_variation; \
Color4 initial_color; \
float initial_radius; \
float radius_variation; \
float life_span; \
float life_span_variation; \

#define A_P_SYS_EMITTER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Speed" ) \
  return attr_ref(speed); \
if ( attr_name == "Speed Variation" ) \
  return attr_ref(speed_variation); \
if ( attr_name == "Declination" ) \
  return attr_ref(declination); \
if ( attr_name == "Declination Variation" ) \
  return attr_ref(declination_variation); \
if ( attr_name == "Planar Angle" ) \
  return attr_ref(planar_angle); \
if ( attr_name == "Planar Angle Variation" ) \
  return attr_ref(planar_angle_variation); \
if ( attr_name == "Initial Color" ) \
  return attr_ref(initial_color); \
if ( attr_name == "Initial Radius" ) \
  return attr_ref(initial_radius); \
if ( attr_name == "Radius Variation" ) \
  return attr_ref(radius_variation); \
if ( attr_name == "Life Span" ) \
  return attr_ref(life_span); \
if ( attr_name == "Life Span Variation" ) \
  return attr_ref(life_span_variation); \
return attr_ref(); \

#define A_P_SYS_EMITTER_PARENTS APSysModifier

#define A_P_SYS_EMITTER_CONSTRUCT

#define A_P_SYS_EMITTER_READ \
APSysModifier::Read( in, version ); \
NifStream( speed, in, version ); \
NifStream( speed_variation, in, version ); \
NifStream( declination, in, version ); \
NifStream( declination_variation, in, version ); \
NifStream( planar_angle, in, version ); \
NifStream( planar_angle_variation, in, version ); \
NifStream( initial_color, in, version ); \
NifStream( initial_radius, in, version ); \
NifStream( radius_variation, in, version ); \
NifStream( life_span, in, version ); \
NifStream( life_span_variation, in, version ); \

#define A_P_SYS_EMITTER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( speed, out, version ); \
NifStream( speed_variation, out, version ); \
NifStream( declination, out, version ); \
NifStream( declination_variation, out, version ); \
NifStream( planar_angle, out, version ); \
NifStream( planar_angle_variation, out, version ); \
NifStream( initial_color, out, version ); \
NifStream( initial_radius, out, version ); \
NifStream( radius_variation, out, version ); \
NifStream( life_span, out, version ); \
NifStream( life_span_variation, out, version ); \

#define A_P_SYS_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "               Speed:  " << speed << endl; \
out << "     Speed Variation:  " << speed_variation << endl; \
out << "         Declination:  " << declination << endl; \
out << "Declination Variation:  " << declination_variation << endl; \
out << "        Planar Angle:  " << planar_angle << endl; \
out << "Planar Angle Variation:  " << planar_angle_variation << endl; \
out << "       Initial Color:  " << initial_color << endl; \
out << "      Initial Radius:  " << initial_radius << endl; \
out << "    Radius Variation:  " << radius_variation << endl; \
out << "           Life Span:  " << life_span << endl; \
out << " Life Span Variation:  " << life_span_variation << endl; \
return out.str(); \

// 
// An emitter that emits meshes?
//
// - Node parent of this modifier?
#define A_P_SYS_VOLUME_EMITTER_MEMBERS \
uint emitter_object; \

#define A_P_SYS_VOLUME_EMITTER_GETATTR \
attr_ref attr = APSysEmitter::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Emitter Object" ) \
  return attr_ref(emitter_object); \
return attr_ref(); \

#define A_P_SYS_VOLUME_EMITTER_PARENTS APSysEmitter

#define A_P_SYS_VOLUME_EMITTER_CONSTRUCT

#define A_P_SYS_VOLUME_EMITTER_READ \
APSysEmitter::Read( in, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( emitter_object, in, version ); \
}; \

#define A_P_SYS_VOLUME_EMITTER_WRITE \
APSysEmitter::Write( out, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( emitter_object, out, version ); \
}; \

#define A_P_SYS_VOLUME_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysEmitter::asString(); \
out << "      Emitter Object:  " << emitter_object << endl; \
return out.str(); \

// 
// Describes a mesh, built from triangles.
//
// - Data index (NiTriShapeData/NiTriStripData).
// - Skin instance index.
// - Shader.
#define A_SHAPE_MEMBERS \
uint data; \
uint skin_instance; \
Shader shader; \

#define A_SHAPE_GETATTR \
attr_ref attr = ANode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Skin Instance" ) \
  return attr_ref(skin_instance); \
return attr_ref(); \

#define A_SHAPE_PARENTS ANode

#define A_SHAPE_CONSTRUCT

#define A_SHAPE_READ \
ANode::Read( in, version ); \
NifStream( data, in, version ); \
NifStream( skin_instance, in, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( shader, in, version ); \
}; \

#define A_SHAPE_WRITE \
ANode::Write( out, version ); \
NifStream( data, out, version ); \
NifStream( skin_instance, out, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( shader, out, version ); \
}; \

#define A_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ANode::asString(); \
out << "                Data:  " << data << endl; \
out << "       Skin Instance:  " << skin_instance << endl; \
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
ushort unknown_short_1; \
bool has_vertices; \
vector<Vector3 > vertices; \
byte num_uv_sets_2; \
byte unknown_byte; \
bool has_normals; \
vector<Vector3 > normals; \
vector<vector<Vector3 > > unknown_vectors_1; \
vector<vector<Vector3 > > unknown_vectors_2; \
bool has_vertex_colors; \
vector<Color4 > vertex_colors; \
bool has_uv; \
vector<vector<TexCoord > > uv_sets; \
vector<vector<TexCoord > > uv_sets_2; \
ushort unknown_short_2; \
uint unknown_link; \

#define A_SHAPE_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Unknown Short 1" ) \
  return attr_ref(unknown_short_1); \
if ( attr_name == "Has Vertices" ) \
  return attr_ref(has_vertices); \
if ( attr_name == "Num UV Sets 2" ) \
  return attr_ref(num_uv_sets_2); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
if ( attr_name == "Has Normals" ) \
  return attr_ref(has_normals); \
if ( attr_name == "Has Vertex Colors" ) \
  return attr_ref(has_vertex_colors); \
if ( attr_name == "Has UV" ) \
  return attr_ref(has_uv); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknown_short_2); \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknown_link); \
return attr_ref(); \

#define A_SHAPE_DATA_PARENTS AData

#define A_SHAPE_DATA_CONSTRUCT

#define A_SHAPE_DATA_READ \
ushort num_vertices; \
Vector3 center; \
float radius; \
ushort num_uv_sets; \
AData::Read( in, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( name, in, version ); \
}; \
NifStream( num_vertices, in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown_short_1, in, version ); \
}; \
NifStream( has_vertices, in, version ); \
if ( has_vertices != 0 ) { \
  vertices.resize(num_vertices); \
  NifStream( vertices, in, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( num_uv_sets_2, in, version ); \
  NifStream( unknown_byte, in, version ); \
}; \
NifStream( has_normals, in, version ); \
if ( has_normals != 0 ) { \
  normals.resize(num_vertices); \
  NifStream( normals, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( unknown_byte & 16 ) { \
    unknown_vectors_1.resize(has_normals); \
    NifStream( unknown_vectors_1, in, version ); \
    unknown_vectors_2.resize(has_normals); \
    NifStream( unknown_vectors_2, in, version ); \
  }; \
}; \
NifStream( has_vertex_colors, in, version ); \
if ( has_vertex_colors != 0 ) { \
  vertex_colors.resize(num_vertices); \
  NifStream( vertex_colors, in, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( num_uv_sets, in, version ); \
}; \
if ( version <= 0x04000002 ) { \
  NifStream( has_uv, in, version ); \
}; \
if ( version <= 0x04020200 ) { \
  uv_sets.resize(num_uv_sets); \
  NifStream( uv_sets, in, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  uv_sets_2.resize(num_uv_sets_2 & 63); \
  NifStream( uv_sets_2, in, version ); \
  NifStream( unknown_short_2, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknown_link, in, version ); \
}; \

#define A_SHAPE_DATA_WRITE \
ushort num_vertices; \
Vector3 center; \
float radius; \
ushort num_uv_sets; \
AData::Write( out, version ); \
num_vertices = ushort(vertices.size()); \
center = Center(); \
radius = Radius(); \
num_uv_sets = ushort(uv_sets.size()); \
if ( version >= 0x0A020000 ) { \
  NifStream( name, out, version ); \
}; \
NifStream( num_vertices, out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown_short_1, out, version ); \
}; \
NifStream( has_vertices, out, version ); \
if ( has_vertices != 0 ) { \
  NifStream( vertices, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( num_uv_sets_2, out, version ); \
  NifStream( unknown_byte, out, version ); \
}; \
NifStream( has_normals, out, version ); \
if ( has_normals != 0 ) { \
  NifStream( normals, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( unknown_byte & 16 ) { \
    NifStream( unknown_vectors_1, out, version ); \
    NifStream( unknown_vectors_2, out, version ); \
  }; \
}; \
NifStream( has_vertex_colors, out, version ); \
if ( has_vertex_colors != 0 ) { \
  NifStream( vertex_colors, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( num_uv_sets, out, version ); \
}; \
if ( version <= 0x04000002 ) { \
  NifStream( has_uv, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
  NifStream( uv_sets, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( uv_sets_2, out, version ); \
  NifStream( unknown_short_2, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknown_link, out, version ); \
}; \

#define A_SHAPE_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "        Num Vertices:  -- calculated --" << endl; \
out << "     Unknown Short 1:  " << unknown_short_1 << endl; \
out << "        Has Vertices:  " << has_vertices << endl; \
out << "            Vertices:  -- data not shown --" << endl; \
out << "       Num UV Sets 2:  " << num_uv_sets_2 << endl; \
out << "        Unknown Byte:  " << unknown_byte << endl; \
out << "         Has Normals:  " << has_normals << endl; \
out << "             Normals:  -- data not shown --" << endl; \
out << "   Unknown Vectors 1:  -- data not shown --" << endl; \
out << "   Unknown Vectors 2:  -- data not shown --" << endl; \
out << "              Center:  -- calculated --" << endl; \
out << "              Radius:  -- calculated --" << endl; \
out << "   Has Vertex Colors:  " << has_vertex_colors << endl; \
out << "       Vertex Colors:  -- data not shown --" << endl; \
out << "         Num UV Sets:  -- calculated --" << endl; \
out << "              Has UV:  " << has_uv << endl; \
out << "             UV Sets:  -- data not shown --" << endl; \
out << "           UV Sets 2:  -- data not shown --" << endl; \
out << "     Unknown Short 2:  " << unknown_short_2 << endl; \
out << "        Unknown Link:  " << unknown_link << endl; \
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
ushort num_particles; \
float size; \
ushort num_active; \
ushort unknown_short; \
bool has_sizes; \
vector<float > sizes; \

#define A_PARTICLES_DATA_GETATTR \
attr_ref attr = AShapeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Particles" ) \
  return attr_ref(num_particles); \
if ( attr_name == "Size" ) \
  return attr_ref(size); \
if ( attr_name == "Num Active" ) \
  return attr_ref(num_active); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Has Sizes" ) \
  return attr_ref(has_sizes); \
return attr_ref(); \

#define A_PARTICLES_DATA_PARENTS AShapeData

#define A_PARTICLES_DATA_CONSTRUCT

#define A_PARTICLES_DATA_READ \
AShapeData::Read( in, version ); \
if ( version <= 0x04000002 ) { \
  NifStream( num_particles, in, version ); \
}; \
if ( version <= 0x0A000100 ) { \
  NifStream( size, in, version ); \
}; \
if ( version <= 0x04000002 ) { \
  NifStream( num_active, in, version ); \
}; \
if ( ( version >= 0x0401000C ) && ( version <= 0x0A000100 ) ) { \
  NifStream( unknown_short, in, version ); \
}; \
NifStream( has_sizes, in, version ); \
if ( has_sizes != 0 ) { \
  sizes.resize(num_vertices); \
  NifStream( sizes, in, version ); \
}; \

#define A_PARTICLES_DATA_WRITE \
AShapeData::Write( out, version ); \
if ( version <= 0x04000002 ) { \
  NifStream( num_particles, out, version ); \
}; \
if ( version <= 0x0A000100 ) { \
  NifStream( size, out, version ); \
}; \
if ( version <= 0x04000002 ) { \
  NifStream( num_active, out, version ); \
}; \
if ( ( version >= 0x0401000C ) && ( version <= 0x0A000100 ) ) { \
  NifStream( unknown_short, out, version ); \
}; \
NifStream( has_sizes, out, version ); \
if ( has_sizes != 0 ) { \
  NifStream( sizes, out, version ); \
}; \

#define A_PARTICLES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShapeData::asString(); \
out << "       Num Particles:  " << num_particles << endl; \
out << "                Size:  " << size << endl; \
out << "          Num Active:  " << num_active << endl; \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "           Has Sizes:  " << has_sizes << endl; \
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
bool has_unknown_floats_1; \
vector<float > unknown_floats_1; \
ushort unknown_short_3; \
bool has_unknown_floats_2; \
vector<float > unknown_floats_2; \
byte unknown_byte_1; \

#define A_P_SYS_DATA_GETATTR \
attr_ref attr = AShapeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Has Unknown Floats 1" ) \
  return attr_ref(has_unknown_floats_1); \
if ( attr_name == "Unknown Short 3" ) \
  return attr_ref(unknown_short_3); \
if ( attr_name == "Has Unknown Floats 2" ) \
  return attr_ref(has_unknown_floats_2); \
if ( attr_name == "Unknown Byte 1" ) \
  return attr_ref(unknown_byte_1); \
return attr_ref(); \

#define A_P_SYS_DATA_PARENTS AShapeData

#define A_P_SYS_DATA_CONSTRUCT

#define A_P_SYS_DATA_READ \
AShapeData::Read( in, version ); \
NifStream( has_unknown_floats_1, in, version ); \
if ( has_unknown_floats_1 != 0 ) { \
  unknown_floats_1.resize(num_vertices); \
  NifStream( unknown_floats_1, in, version ); \
}; \
NifStream( unknown_short_3, in, version ); \
NifStream( has_unknown_floats_2, in, version ); \
if ( has_unknown_floats_2 != 0 ) { \
  unknown_floats_2.resize(num_vertices); \
  NifStream( unknown_floats_2, in, version ); \
}; \
NifStream( unknown_byte_1, in, version ); \

#define A_P_SYS_DATA_WRITE \
AShapeData::Write( out, version ); \
NifStream( has_unknown_floats_1, out, version ); \
if ( has_unknown_floats_1 != 0 ) { \
  NifStream( unknown_floats_1, out, version ); \
}; \
NifStream( unknown_short_3, out, version ); \
NifStream( has_unknown_floats_2, out, version ); \
if ( has_unknown_floats_2 != 0 ) { \
  NifStream( unknown_floats_2, out, version ); \
}; \
NifStream( unknown_byte_1, out, version ); \

#define A_P_SYS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShapeData::asString(); \
out << "Has Unknown Floats 1:  " << has_unknown_floats_1 << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "     Unknown Short 3:  " << unknown_short_3 << endl; \
out << "Has Unknown Floats 2:  " << has_unknown_floats_2 << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
out << "      Unknown Byte 1:  " << unknown_byte_1 << endl; \
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
ushort num_active; \
bool has_unknown_floats; \
vector<float > unknown_floats; \
bool has_rotations; \
vector<Quaternion > rotations; \

#define A_ROTATING_PARTICLES_DATA_GETATTR \
attr_ref attr = AParticlesData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Active" ) \
  return attr_ref(num_active); \
if ( attr_name == "Has Unknown Floats" ) \
  return attr_ref(has_unknown_floats); \
if ( attr_name == "Has Rotations" ) \
  return attr_ref(has_rotations); \
return attr_ref(); \

#define A_ROTATING_PARTICLES_DATA_PARENTS AParticlesData

#define A_ROTATING_PARTICLES_DATA_CONSTRUCT

#define A_ROTATING_PARTICLES_DATA_READ \
AParticlesData::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( num_active, in, version ); \
  NifStream( has_unknown_floats, in, version ); \
  if ( has_unknown_floats != 0 ) { \
    unknown_floats.resize(num_vertices); \
    NifStream( unknown_floats, in, version ); \
  }; \
}; \
NifStream( has_rotations, in, version ); \
if ( has_rotations != 0 ) { \
  rotations.resize(num_vertices); \
  NifStream( rotations, in, version ); \
}; \

#define A_ROTATING_PARTICLES_DATA_WRITE \
AParticlesData::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( num_active, out, version ); \
  NifStream( has_unknown_floats, out, version ); \
  if ( has_unknown_floats != 0 ) { \
    NifStream( unknown_floats, out, version ); \
  }; \
}; \
NifStream( has_rotations, out, version ); \
if ( has_rotations != 0 ) { \
  NifStream( rotations, out, version ); \
}; \

#define A_ROTATING_PARTICLES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticlesData::asString(); \
out << "          Num Active:  " << num_active << endl; \
out << "  Has Unknown Floats:  " << has_unknown_floats << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "       Has Rotations:  " << has_rotations << endl; \
out << "           Rotations:  -- data not shown --" << endl; \
return out.str(); \

// 
// A controller referring to an interpolator.
//
// - Link to interpolator.
#define A_SINGLE_INTERPOLATOR_CONTROLLER_MEMBERS \
uint interpolator; \

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
string unknown_string; \

#define A_P_SYS_CTLR_GETATTR \
attr_ref attr = ASingleInterpolatorController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown String" ) \
  return attr_ref(unknown_string); \
return attr_ref(); \

#define A_P_SYS_CTLR_PARENTS ASingleInterpolatorController

#define A_P_SYS_CTLR_CONSTRUCT

#define A_P_SYS_CTLR_READ \
ASingleInterpolatorController::Read( in, version ); \
NifStream( unknown_string, in, version ); \

#define A_P_SYS_CTLR_WRITE \
ASingleInterpolatorController::Write( out, version ); \
NifStream( unknown_string, out, version ); \

#define A_P_SYS_CTLR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ASingleInterpolatorController::asString(); \
out << "      Unknown String:  " << unknown_string << endl; \
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
float unknown_float_1; \
float unknown_float_2; \

#define BHK_BLEND_COLLISION_OBJECT_GETATTR \
attr_ref attr = ACollisionObject::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_BLEND_COLLISION_OBJECT_PARENTS ACollisionObject

#define BHK_BLEND_COLLISION_OBJECT_CONSTRUCT

#define BHK_BLEND_COLLISION_OBJECT_READ \
ACollisionObject::Read( in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_float_2, in, version ); \

#define BHK_BLEND_COLLISION_OBJECT_WRITE \
ACollisionObject::Write( out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_float_2, out, version ); \

#define BHK_BLEND_COLLISION_OBJECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ACollisionObject::asString(); \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
return out.str(); \

// 
// Unknown. Is apparently only used in skeleton.nif files.
//
// - Seems to be always zero.
#define BHK_BLEND_CONTROLLER_MEMBERS \
uint unknown_int; \

#define BHK_BLEND_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_BLEND_CONTROLLER_PARENTS AController

#define BHK_BLEND_CONTROLLER_CONSTRUCT

#define BHK_BLEND_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( unknown_int, in, version ); \

#define BHK_BLEND_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( unknown_int, out, version ); \

#define BHK_BLEND_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
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
uint unknown_int; \
float unknown_float_1; \
ushort unknown_short_1; \
ushort unknown_short_2; \
ushort unknown_short_3; \
ushort unknown_short_4; \
Vector3 unknown_vector; \
float unknown_float_2; \

#define BHK_BOX_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Short 1" ) \
  return attr_ref(unknown_short_1); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknown_short_2); \
if ( attr_name == "Unknown Short 3" ) \
  return attr_ref(unknown_short_3); \
if ( attr_name == "Unknown Short 4" ) \
  return attr_ref(unknown_short_4); \
if ( attr_name == "Unknown Vector" ) \
  return attr_ref(unknown_vector); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_BOX_SHAPE_PARENTS AbhkShape

#define BHK_BOX_SHAPE_CONSTRUCT

#define BHK_BOX_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( unknown_int, in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_short_1, in, version ); \
NifStream( unknown_short_2, in, version ); \
NifStream( unknown_short_3, in, version ); \
NifStream( unknown_short_4, in, version ); \
NifStream( unknown_vector, in, version ); \
NifStream( unknown_float_2, in, version ); \

#define BHK_BOX_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( unknown_int, out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_short_1, out, version ); \
NifStream( unknown_short_2, out, version ); \
NifStream( unknown_short_3, out, version ); \
NifStream( unknown_short_4, out, version ); \
NifStream( unknown_vector, out, version ); \
NifStream( unknown_float_2, out, version ); \

#define BHK_BOX_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Short 1:  " << unknown_short_1 << endl; \
out << "     Unknown Short 2:  " << unknown_short_2 << endl; \
out << "     Unknown Short 3:  " << unknown_short_3 << endl; \
out << "     Unknown Short 4:  " << unknown_short_4 << endl; \
out << "      Unknown Vector:  " << unknown_vector << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
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
uint unknown_int_1; \
float radius; \
ushort unknown_short_1; \
ushort unknown_short_2; \
ushort unknown_short_3; \
ushort unknown_short_4; \
Vector3 unknown_vector_1; \
float radius_1; \
Vector3 unknown_vector_2; \
float radius_2; \

#define BHK_CAPSULE_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
if ( attr_name == "Radius" ) \
  return attr_ref(radius); \
if ( attr_name == "Unknown Short 1" ) \
  return attr_ref(unknown_short_1); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknown_short_2); \
if ( attr_name == "Unknown Short 3" ) \
  return attr_ref(unknown_short_3); \
if ( attr_name == "Unknown Short 4" ) \
  return attr_ref(unknown_short_4); \
if ( attr_name == "Unknown Vector 1" ) \
  return attr_ref(unknown_vector_1); \
if ( attr_name == "Radius 1" ) \
  return attr_ref(radius_1); \
if ( attr_name == "Unknown Vector 2" ) \
  return attr_ref(unknown_vector_2); \
if ( attr_name == "Radius 2" ) \
  return attr_ref(radius_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_CAPSULE_SHAPE_PARENTS AbhkShape

#define BHK_CAPSULE_SHAPE_CONSTRUCT

#define BHK_CAPSULE_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( unknown_int_1, in, version ); \
NifStream( radius, in, version ); \
NifStream( unknown_short_1, in, version ); \
NifStream( unknown_short_2, in, version ); \
NifStream( unknown_short_3, in, version ); \
NifStream( unknown_short_4, in, version ); \
NifStream( unknown_vector_1, in, version ); \
NifStream( radius_1, in, version ); \
NifStream( unknown_vector_2, in, version ); \
NifStream( radius_2, in, version ); \

#define BHK_CAPSULE_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( unknown_int_1, out, version ); \
NifStream( radius, out, version ); \
NifStream( unknown_short_1, out, version ); \
NifStream( unknown_short_2, out, version ); \
NifStream( unknown_short_3, out, version ); \
NifStream( unknown_short_4, out, version ); \
NifStream( unknown_vector_1, out, version ); \
NifStream( radius_1, out, version ); \
NifStream( unknown_vector_2, out, version ); \
NifStream( radius_2, out, version ); \

#define BHK_CAPSULE_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "              Radius:  " << radius << endl; \
out << "     Unknown Short 1:  " << unknown_short_1 << endl; \
out << "     Unknown Short 2:  " << unknown_short_2 << endl; \
out << "     Unknown Short 3:  " << unknown_short_3 << endl; \
out << "     Unknown Short 4:  " << unknown_short_4 << endl; \
out << "    Unknown Vector 1:  " << unknown_vector_1 << endl; \
out << "            Radius 1:  " << radius_1 << endl; \
out << "    Unknown Vector 2:  " << unknown_vector_2 << endl; \
out << "            Radius 2:  " << radius_2 << endl; \
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
uint unknown_int; \
vector<float > unknown_floats_1; \
vector<Float4 > unknown_vectors_1; \
vector<Float4 > unknown_vectors_2; \

#define BHK_CONVEX_VERTICES_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_CONVEX_VERTICES_SHAPE_PARENTS AbhkShape

#define BHK_CONVEX_VERTICES_SHAPE_CONSTRUCT

#define BHK_CONVEX_VERTICES_SHAPE_READ \
uint num_1; \
uint num_2; \
AbhkShape::Read( in, version ); \
NifStream( unknown_int, in, version ); \
unknown_floats_1.resize(7); \
NifStream( unknown_floats_1, in, version ); \
NifStream( num_1, in, version ); \
unknown_vectors_1.resize(num_1); \
NifStream( unknown_vectors_1, in, version ); \
NifStream( num_2, in, version ); \
unknown_vectors_2.resize(num_2); \
NifStream( unknown_vectors_2, in, version ); \

#define BHK_CONVEX_VERTICES_SHAPE_WRITE \
uint num_1; \
uint num_2; \
AbhkShape::Write( out, version ); \
num_1 = uint(unknown_vectors_1.size()); \
num_2 = uint(unknown_vectors_2.size()); \
NifStream( unknown_int, out, version ); \
NifStream( unknown_floats_1, out, version ); \
NifStream( num_1, out, version ); \
NifStream( unknown_vectors_1, out, version ); \
NifStream( num_2, out, version ); \
NifStream( unknown_vectors_2, out, version ); \

#define BHK_CONVEX_VERTICES_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
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
vector<vector<float > > unknown_floats; \

#define BHK_HINGE_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_HINGE_CONSTRAINT_PARENTS AbhkConstraint

#define BHK_HINGE_CONSTRAINT_CONSTRUCT

#define BHK_HINGE_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
unknown_floats.resize(5); \
NifStream( unknown_floats, in, version ); \

#define BHK_HINGE_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( unknown_floats, out, version ); \

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
uint unknown_int; \

#define BHK_LIMITED_HINGE_CONSTRAINT_GETATTR \
attr_ref attr = AbhkRagdollConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_LIMITED_HINGE_CONSTRAINT_PARENTS AbhkRagdollConstraint

#define BHK_LIMITED_HINGE_CONSTRAINT_CONSTRUCT

#define BHK_LIMITED_HINGE_CONSTRAINT_READ \
AbhkRagdollConstraint::Read( in, version ); \
NifStream( unknown_int, in, version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_WRITE \
AbhkRagdollConstraint::Write( out, version ); \
NifStream( unknown_int, out, version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkRagdollConstraint::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
return out.str(); \

// 
// A list of shapes.
//
// - List of shapes.
// - Unknown.
// - Unknown.
// - Unknown.
#define BHK_LIST_SHAPE_MEMBERS \
LinkGroup sub_shapes; \
uint unknown_int; \
vector<float > unknown_floats; \
vector<uint > unknown_ints; \

#define BHK_LIST_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_LIST_SHAPE_PARENTS AbhkShape

#define BHK_LIST_SHAPE_CONSTRUCT

#define BHK_LIST_SHAPE_READ \
uint num_unknown_ints; \
AbhkShape::Read( in, version ); \
NifStream( sub_shapes, in, version ); \
NifStream( unknown_int, in, version ); \
unknown_floats.resize(6); \
NifStream( unknown_floats, in, version ); \
NifStream( num_unknown_ints, in, version ); \
unknown_ints.resize(num_unknown_ints); \
NifStream( unknown_ints, in, version ); \

#define BHK_LIST_SHAPE_WRITE \
uint num_unknown_ints; \
AbhkShape::Write( out, version ); \
num_unknown_ints = uint(unknown_ints.size()); \
NifStream( sub_shapes, out, version ); \
NifStream( unknown_int, out, version ); \
NifStream( unknown_floats, out, version ); \
NifStream( num_unknown_ints, out, version ); \
NifStream( unknown_ints, out, version ); \

#define BHK_LIST_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "          Sub Shapes:  " << sub_shapes << endl; \
out << "         Unknown Int:  " << unknown_int << endl; \
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
uint unknown_int_2; \
uint unknown_link_1; \
uint unknown_link_2; \
uint unknown_int_3; \
vector<float > unknown_floats_1; \
vector<vector<float > > unknown_floats; \
float unknown_float_1; \
float unknown_float_2; \

#define BHK_MALLEABLE_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Type" ) \
  return attr_ref(type); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
if ( attr_name == "Unknown Link 1" ) \
  return attr_ref(unknown_link_1); \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknown_link_2); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknown_int_3); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_MALLEABLE_CONSTRAINT_PARENTS AbhkConstraint

#define BHK_MALLEABLE_CONSTRAINT_CONSTRUCT

#define BHK_MALLEABLE_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
NifStream( type, in, version ); \
NifStream( unknown_int_2, in, version ); \
NifStream( unknown_link_1, in, version ); \
NifStream( unknown_link_2, in, version ); \
NifStream( unknown_int_3, in, version ); \
unknown_floats_1.resize(3); \
NifStream( unknown_floats_1, in, version ); \
unknown_floats.resize(7); \
NifStream( unknown_floats, in, version ); \
NifStream( unknown_float_1, in, version ); \
if ( type == 2 ) { \
  NifStream( unknown_float_2, in, version ); \
}; \

#define BHK_MALLEABLE_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( type, out, version ); \
NifStream( unknown_int_2, out, version ); \
NifStream( unknown_link_1, out, version ); \
NifStream( unknown_link_2, out, version ); \
NifStream( unknown_int_3, out, version ); \
NifStream( unknown_floats_1, out, version ); \
NifStream( unknown_floats, out, version ); \
NifStream( unknown_float_1, out, version ); \
if ( type == 2 ) { \
  NifStream( unknown_float_2, out, version ); \
}; \

#define BHK_MALLEABLE_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkConstraint::asString(); \
out << "                Type:  " << type << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
out << "      Unknown Link 1:  " << unknown_link_1 << endl; \
out << "      Unknown Link 2:  " << unknown_link_2 << endl; \
out << "       Unknown Int 3:  " << unknown_int_3 << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
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
uint shape; \
uint unknown_int; \
vector<byte > unknown_bytes_1; \
float unknown_float; \
vector<byte > unknown_bytes_2; \
vector<float > unknown_floats; \

#define BHK_MOPP_BV_TREE_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Shape" ) \
  return attr_ref(shape); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknown_float); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_MOPP_BV_TREE_SHAPE_PARENTS AbhkShape

#define BHK_MOPP_BV_TREE_SHAPE_CONSTRUCT

#define BHK_MOPP_BV_TREE_SHAPE_READ \
uint num_unknown_bytes_2; \
AbhkShape::Read( in, version ); \
NifStream( shape, in, version ); \
NifStream( unknown_int, in, version ); \
unknown_bytes_1.resize(8); \
NifStream( unknown_bytes_1, in, version ); \
NifStream( unknown_float, in, version ); \
NifStream( num_unknown_bytes_2, in, version ); \
unknown_bytes_2.resize(num_unknown_bytes_2); \
NifStream( unknown_bytes_2, in, version ); \
unknown_floats.resize(4); \
NifStream( unknown_floats, in, version ); \

#define BHK_MOPP_BV_TREE_SHAPE_WRITE \
uint num_unknown_bytes_2; \
AbhkShape::Write( out, version ); \
num_unknown_bytes_2 = uint(unknown_bytes_2.size()); \
NifStream( shape, out, version ); \
NifStream( unknown_int, out, version ); \
NifStream( unknown_bytes_1, out, version ); \
NifStream( unknown_float, out, version ); \
NifStream( num_unknown_bytes_2, out, version ); \
NifStream( unknown_bytes_2, out, version ); \
NifStream( unknown_floats, out, version ); \

#define BHK_MOPP_BV_TREE_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "               Shape:  " << shape << endl; \
out << "         Unknown Int:  " << unknown_int << endl; \
out << "     Unknown Bytes 1:  -- data not shown --" << endl; \
out << "       Unknown Float:  " << unknown_float << endl; \
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
uint unknown_int; \
float unknown_float_1; \
float unknown_float_2; \
float unknown_float_3; \
uint unknown_int_2; \
vector<float > unknown_floats; \

#define BHK_MULTI_SPHERE_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknown_float_3); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_MULTI_SPHERE_SHAPE_PARENTS AbhkShape

#define BHK_MULTI_SPHERE_SHAPE_CONSTRUCT

#define BHK_MULTI_SPHERE_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( unknown_int, in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_float_2, in, version ); \
NifStream( unknown_float_3, in, version ); \
NifStream( unknown_int_2, in, version ); \
unknown_floats.resize(8); \
NifStream( unknown_floats, in, version ); \

#define BHK_MULTI_SPHERE_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( unknown_int, out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_float_2, out, version ); \
NifStream( unknown_float_3, out, version ); \
NifStream( unknown_int_2, out, version ); \
NifStream( unknown_floats, out, version ); \

#define BHK_MULTI_SPHERE_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "     Unknown Float 3:  " << unknown_float_3 << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
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
uint unknown_int; \
vector<float > unknown_floats_1; \
vector<uint > unknown_ints_1; \
vector<float > unknown_floats_2; \
uint unknown_int_2; \
LinkGroup strips; \
vector<uint > unknown_ints_3; \

#define BHK_NI_TRI_STRIPS_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_NI_TRI_STRIPS_SHAPE_PARENTS AbhkShape

#define BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT

#define BHK_NI_TRI_STRIPS_SHAPE_READ \
uint num_unknown_ints_3; \
AbhkShape::Read( in, version ); \
NifStream( unknown_int, in, version ); \
unknown_floats_1.resize(2); \
NifStream( unknown_floats_1, in, version ); \
unknown_ints_1.resize(5); \
NifStream( unknown_ints_1, in, version ); \
unknown_floats_2.resize(3); \
NifStream( unknown_floats_2, in, version ); \
NifStream( unknown_int_2, in, version ); \
NifStream( strips, in, version ); \
NifStream( num_unknown_ints_3, in, version ); \
unknown_ints_3.resize(num_unknown_ints_3); \
NifStream( unknown_ints_3, in, version ); \

#define BHK_NI_TRI_STRIPS_SHAPE_WRITE \
uint num_unknown_ints_3; \
AbhkShape::Write( out, version ); \
num_unknown_ints_3 = uint(unknown_ints_3.size()); \
NifStream( unknown_int, out, version ); \
NifStream( unknown_floats_1, out, version ); \
NifStream( unknown_ints_1, out, version ); \
NifStream( unknown_floats_2, out, version ); \
NifStream( unknown_int_2, out, version ); \
NifStream( strips, out, version ); \
NifStream( num_unknown_ints_3, out, version ); \
NifStream( unknown_ints_3, out, version ); \

#define BHK_NI_TRI_STRIPS_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
out << "    Unknown Floats 1:  -- data not shown --" << endl; \
out << "      Unknown Ints 1:  -- data not shown --" << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
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
vector<vector<uint > > unknown_ints; \
vector<float > unknown_floats; \
uint data; \

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
ushort num_unknown_ints; \
AbhkShape::Read( in, version ); \
NifStream( num_unknown_ints, in, version ); \
unknown_ints.resize(num_unknown_ints); \
NifStream( unknown_ints, in, version ); \
unknown_floats.resize(13); \
NifStream( unknown_floats, in, version ); \
NifStream( data, in, version ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_WRITE \
ushort num_unknown_ints; \
AbhkShape::Write( out, version ); \
num_unknown_ints = ushort(unknown_ints.size()); \
NifStream( num_unknown_ints, out, version ); \
NifStream( unknown_ints, out, version ); \
NifStream( unknown_floats, out, version ); \
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
vector<vector<float > > unknown_floats; \
vector<float > unknown_floats_2; \

#define BHK_PRISMATIC_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_PRISMATIC_CONSTRAINT_PARENTS AbhkConstraint

#define BHK_PRISMATIC_CONSTRAINT_CONSTRUCT

#define BHK_PRISMATIC_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
unknown_floats.resize(8); \
NifStream( unknown_floats, in, version ); \
unknown_floats_2.resize(3); \
NifStream( unknown_floats_2, in, version ); \

#define BHK_PRISMATIC_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( unknown_floats, out, version ); \
NifStream( unknown_floats_2, out, version ); \

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
uint shape; \
uint unknown_int_1; \
vector<float > unkown_floats; \
vector<vector<float > > unknown_floats_2; \
float unknown_float; \

#define BHK_SIMPLE_SHAPE_PHANTOM_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Shape" ) \
  return attr_ref(shape); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknown_float); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_SIMPLE_SHAPE_PHANTOM_PARENTS AbhkShape

#define BHK_SIMPLE_SHAPE_PHANTOM_CONSTRUCT

#define BHK_SIMPLE_SHAPE_PHANTOM_READ \
AbhkShape::Read( in, version ); \
NifStream( shape, in, version ); \
NifStream( unknown_int_1, in, version ); \
unkown_floats.resize(7); \
NifStream( unkown_floats, in, version ); \
unknown_floats_2.resize(3); \
NifStream( unknown_floats_2, in, version ); \
NifStream( unknown_float, in, version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_WRITE \
AbhkShape::Write( out, version ); \
NifStream( shape, out, version ); \
NifStream( unknown_int_1, out, version ); \
NifStream( unkown_floats, out, version ); \
NifStream( unknown_floats_2, out, version ); \
NifStream( unknown_float, out, version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "               Shape:  " << shape << endl; \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "       Unkown Floats:  -- data not shown --" << endl; \
out << "    Unknown Floats 2:  -- data not shown --" << endl; \
out << "       Unknown Float:  " << unknown_float << endl; \
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
uint unknown_int; \
float radius; \

#define BHK_SPHERE_SHAPE_GETATTR \
attr_ref attr = AbhkShape::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
if ( attr_name == "Radius" ) \
  return attr_ref(radius); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_SPHERE_SHAPE_PARENTS AbhkShape

#define BHK_SPHERE_SHAPE_CONSTRUCT

#define BHK_SPHERE_SHAPE_READ \
AbhkShape::Read( in, version ); \
NifStream( unknown_int, in, version ); \
NifStream( radius, in, version ); \

#define BHK_SPHERE_SHAPE_WRITE \
AbhkShape::Write( out, version ); \
NifStream( unknown_int, out, version ); \
NifStream( radius, out, version ); \

#define BHK_SPHERE_SHAPE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkShape::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
out << "              Radius:  " << radius << endl; \
return out.str(); \

// 
// A spring constraint.
//
// - Unknown.
// - Unknown.
#define BHK_STIFF_SPRING_CONSTRAINT_MEMBERS \
vector<vector<float > > unknown_floats; \
float unknown_float; \

#define BHK_STIFF_SPRING_CONSTRAINT_GETATTR \
attr_ref attr = AbhkConstraint::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknown_float); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define BHK_STIFF_SPRING_CONSTRAINT_PARENTS AbhkConstraint

#define BHK_STIFF_SPRING_CONSTRAINT_CONSTRUCT

#define BHK_STIFF_SPRING_CONSTRAINT_READ \
AbhkConstraint::Read( in, version ); \
unknown_floats.resize(2); \
NifStream( unknown_floats, in, version ); \
NifStream( unknown_float, in, version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, version ); \
NifStream( unknown_floats, out, version ); \
NifStream( unknown_float, out, version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AbhkConstraint::asString(); \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "       Unknown Float:  " << unknown_float << endl; \
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
vector<float > unknown_floats; \

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
unknown_floats.resize(6); \
NifStream( unknown_floats, in, version ); \

#define B_S_BOUND_WRITE \
AData::Write( out, version ); \
NifStream( name, out, version ); \
NifStream( unknown_floats, out, version ); \

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
uint num_positions; \
AData::Read( in, version ); \
if ( version <= 0x14000005 ) { \
  NifStream( name, in, version ); \
}; \
NifStream( num_positions, in, version ); \
positions.resize(num_positions); \
NifStream( positions, in, version ); \

#define B_S_FURNITURE_MARKER_WRITE \
uint num_positions; \
AData::Write( out, version ); \
num_positions = uint(positions.size()); \
if ( version <= 0x14000005 ) { \
  NifStream( name, out, version ); \
}; \
NifStream( num_positions, out, version ); \
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
uint data_2; \

#define B_S_KEYFRAME_CONTROLLER_GETATTR \
attr_ref attr = AKeyframeController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data 2" ) \
  return attr_ref(data_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define B_S_KEYFRAME_CONTROLLER_PARENTS AKeyframeController

#define B_S_KEYFRAME_CONTROLLER_CONSTRUCT

#define B_S_KEYFRAME_CONTROLLER_READ \
AKeyframeController::Read( in, version ); \
NifStream( data_2, in, version ); \

#define B_S_KEYFRAME_CONTROLLER_WRITE \
AKeyframeController::Write( out, version ); \
NifStream( data_2, out, version ); \

#define B_S_KEYFRAME_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AKeyframeController::asString(); \
out << "              Data 2:  " << data_2 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
#define B_S_PARENT_VELOCITY_MODIFIER_MEMBERS \
float unknown_float; \

#define B_S_PARENT_VELOCITY_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknown_float); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define B_S_PARENT_VELOCITY_MODIFIER_PARENTS APSysModifier

#define B_S_PARENT_VELOCITY_MODIFIER_CONSTRUCT

#define B_S_PARENT_VELOCITY_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( unknown_float, in, version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( unknown_float, out, version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "       Unknown Float:  " << unknown_float << endl; \
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
uint unknown_int_1; \
uint unknown_int__2; \
uint unknown_int_3; \
LinkGroup unknown_links; \

#define FX_RADIO_BUTTON_GETATTR \
attr_ref attr = AFx::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
if ( attr_name == "Unknown Int  2" ) \
  return attr_ref(unknown_int__2); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknown_int_3); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define FX_RADIO_BUTTON_PARENTS AFx

#define FX_RADIO_BUTTON_CONSTRUCT

#define FX_RADIO_BUTTON_READ \
AFx::Read( in, version ); \
NifStream( unknown_int_1, in, version ); \
NifStream( unknown_int__2, in, version ); \
NifStream( unknown_int_3, in, version ); \
NifStream( unknown_links, in, version ); \

#define FX_RADIO_BUTTON_WRITE \
AFx::Write( out, version ); \
NifStream( unknown_int_1, out, version ); \
NifStream( unknown_int__2, out, version ); \
NifStream( unknown_int_3, out, version ); \
NifStream( unknown_links, out, version ); \

#define FX_RADIO_BUTTON_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AFx::asString(); \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "      Unknown Int  2:  " << unknown_int__2 << endl; \
out << "       Unknown Int 3:  " << unknown_int_3 << endl; \
out << "       Unknown Links:  " << unknown_links << endl; \
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
uint num_triangles; \
uint num_vertices; \
AbhkShape::Read( in, version ); \
NifStream( num_triangles, in, version ); \
triangles.resize(num_triangles); \
NifStream( triangles, in, version ); \
NifStream( num_vertices, in, version ); \
vertices.resize(num_vertices); \
NifStream( vertices, in, version ); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_WRITE \
uint num_triangles; \
uint num_vertices; \
AbhkShape::Write( out, version ); \
num_triangles = uint(triangles.size()); \
num_vertices = uint(vertices.size()); \
NifStream( num_triangles, out, version ); \
NifStream( triangles, out, version ); \
NifStream( num_vertices, out, version ); \
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
uint data; \

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
ushort billboard_mode; \

#define NI_BILLBOARD_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Billboard Mode" ) \
  return attr_ref(billboard_mode); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BILLBOARD_NODE_PARENTS AParentNode

#define NI_BILLBOARD_NODE_CONSTRUCT

#define NI_BILLBOARD_NODE_READ \
AParentNode::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( billboard_mode, in, version ); \
}; \

#define NI_BILLBOARD_NODE_WRITE \
AParentNode::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( billboard_mode, out, version ); \
}; \

#define NI_BILLBOARD_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
out << "      Billboard Mode:  " << billboard_mode << endl; \
return out.str(); \

// 
// Binary extra data block. Used to store normals and binormals in Oblivion.
//
// - The binary data.
#define NI_BINARY_EXTRA_DATA_MEMBERS \
ByteArray binary_data; \

#define NI_BINARY_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BINARY_EXTRA_DATA_PARENTS AExtraData

#define NI_BINARY_EXTRA_DATA_CONSTRUCT

#define NI_BINARY_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( binary_data, in, version ); \

#define NI_BINARY_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( binary_data, out, version ); \

#define NI_BINARY_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "         Binary Data:  " << binary_data << endl; \
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
vector<SkinShapeGroup > shape_groups_1; \
LinkGroup shape_groups_2; \

#define NI_BONE_L_O_D_CONTROLLER_GETATTR \
attr_ref attr = ABoneLODController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BONE_L_O_D_CONTROLLER_PARENTS ABoneLODController

#define NI_BONE_L_O_D_CONTROLLER_CONSTRUCT

#define NI_BONE_L_O_D_CONTROLLER_READ \
uint num_shape_groups; \
ABoneLODController::Read( in, version ); \
NifStream( num_shape_groups, in, version ); \
shape_groups_1.resize(num_shape_groups); \
NifStream( shape_groups_1, in, version ); \
NifStream( shape_groups_2, in, version ); \

#define NI_BONE_L_O_D_CONTROLLER_WRITE \
uint num_shape_groups; \
ABoneLODController::Write( out, version ); \
num_shape_groups = uint(shape_groups_1.size()); \
NifStream( num_shape_groups, out, version ); \
NifStream( shape_groups_1, out, version ); \
NifStream( shape_groups_2, out, version ); \

#define NI_BONE_L_O_D_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABoneLODController::asString(); \
out << "    Num Shape Groups:  -- calculated --" << endl; \
out << "      Shape Groups 1:  -- data not shown --" << endl; \
out << "      Shape Groups 2:  " << shape_groups_2 << endl; \
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
byte boolean_data; \

#define NI_BOOLEAN_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Boolean Data" ) \
  return attr_ref(boolean_data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BOOLEAN_EXTRA_DATA_PARENTS AExtraData

#define NI_BOOLEAN_EXTRA_DATA_CONSTRUCT

#define NI_BOOLEAN_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( boolean_data, in, version ); \

#define NI_BOOLEAN_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( boolean_data, out, version ); \

#define NI_BOOLEAN_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "        Boolean Data:  " << boolean_data << endl; \
return out.str(); \

// 
// Unknown.
//
// - Value when posed?  At time 0?
// - Refers to a NiBoolData block.
#define NI_BOOL_INTERPOLATOR_MEMBERS \
bool bool_value; \
uint data; \

#define NI_BOOL_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Bool Value" ) \
  return attr_ref(bool_value); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_BOOL_INTERPOLATOR_PARENTS AInterpolator

#define NI_BOOL_INTERPOLATOR_CONSTRUCT

#define NI_BOOL_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( bool_value, in, version ); \
NifStream( data, in, version ); \

#define NI_BOOL_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( bool_value, out, version ); \
NifStream( data, out, version ); \

#define NI_BOOL_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "          Bool Value:  " << bool_value << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Unknown.
//
// - The interpolated bool?
// - The bool data.
#define NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS \
byte bool; \
uint data; \

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
uint unknown_int; \

#define NI_B_SPLINE_BASIS_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_BASIS_DATA_PARENTS AData

#define NI_B_SPLINE_BASIS_DATA_CONSTRUCT

#define NI_B_SPLINE_BASIS_DATA_READ \
AData::Read( in, version ); \
NifStream( unknown_int, in, version ); \

#define NI_B_SPLINE_BASIS_DATA_WRITE \
AData::Write( out, version ); \
NifStream( unknown_int, out, version ); \

#define NI_B_SPLINE_BASIS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_MEMBERS \
vector<float > unknown_floats; \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_GETATTR \
attr_ref attr = ABSplineCompInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_PARENTS ABSplineCompInterpolator

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_CONSTRUCT

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_READ \
ABSplineCompInterpolator::Read( in, version ); \
unknown_floats.resize(6); \
NifStream( unknown_floats, in, version ); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_WRITE \
ABSplineCompInterpolator::Write( out, version ); \
NifStream( unknown_floats, out, version ); \

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
uint data; \
uint unknown_link; \
vector<float > unknown_floats; \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_GETATTR \
attr_ref attr = ABSplineCompInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknown_link); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENTS ABSplineCompInterpolator

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_CONSTRUCT

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_READ \
ABSplineCompInterpolator::Read( in, version ); \
NifStream( data, in, version ); \
NifStream( unknown_link, in, version ); \
unknown_floats.resize(6); \
NifStream( unknown_floats, in, version ); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_WRITE \
ABSplineCompInterpolator::Write( out, version ); \
NifStream( data, out, version ); \
NifStream( unknown_link, out, version ); \
NifStream( unknown_floats, out, version ); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABSplineCompInterpolator::asString(); \
out << "                Data:  " << data << endl; \
out << "        Unknown Link:  " << unknown_link << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
// - Refers to NiBSplineData.
// - Refers to NiBSPlineBasisData.
// - Unknown.
#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS \
uint data; \
uint basis_data; \
vector<float > unknown4; \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_GETATTR \
attr_ref attr = ABSplineCompInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Basis Data" ) \
  return attr_ref(basis_data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENTS ABSplineCompInterpolator

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_CONSTRUCT

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_READ \
ABSplineCompInterpolator::Read( in, version ); \
NifStream( data, in, version ); \
NifStream( basis_data, in, version ); \
unknown4.resize(17); \
NifStream( unknown4, in, version ); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_WRITE \
ABSplineCompInterpolator::Write( out, version ); \
NifStream( data, out, version ); \
NifStream( basis_data, out, version ); \
NifStream( unknown4, out, version ); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABSplineCompInterpolator::asString(); \
out << "                Data:  " << data << endl; \
out << "          Basis Data:  " << basis_data << endl; \
out << "            Unknown4:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown. Zero?
// - Unknown data. Could be shorts or bytes or...
#define NI_B_SPLINE_DATA_MEMBERS \
uint unknown_int; \
vector<vector<byte > > unknown_data; \

#define NI_B_SPLINE_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_B_SPLINE_DATA_PARENTS AData

#define NI_B_SPLINE_DATA_CONSTRUCT

#define NI_B_SPLINE_DATA_READ \
uint count; \
AData::Read( in, version ); \
NifStream( unknown_int, in, version ); \
NifStream( count, in, version ); \
unknown_data.resize(count); \
NifStream( unknown_data, in, version ); \

#define NI_B_SPLINE_DATA_WRITE \
uint count; \
AData::Write( out, version ); \
count = uint(unknown_data.size()); \
NifStream( unknown_int, out, version ); \
NifStream( count, out, version ); \
NifStream( unknown_data, out, version ); \

#define NI_B_SPLINE_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
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
ushort unknown_short; \
float frustum_left; \
float frustum_right; \
float frustum_top; \
float frustum_bottom; \
float frustum_near; \
float frustum_far; \
bool use_orthographic_projection; \
float viewport_left; \
float viewport_right; \
float viewport_top; \
float viewport_bottom; \
float lod_adjust; \
uint unknown_link_; \
uint unknown_int; \
uint unknown_int_2; \

#define NI_CAMERA_GETATTR \
attr_ref attr = ANode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Frustum Left" ) \
  return attr_ref(frustum_left); \
if ( attr_name == "Frustum Right" ) \
  return attr_ref(frustum_right); \
if ( attr_name == "Frustum Top" ) \
  return attr_ref(frustum_top); \
if ( attr_name == "Frustum Bottom" ) \
  return attr_ref(frustum_bottom); \
if ( attr_name == "Frustum Near" ) \
  return attr_ref(frustum_near); \
if ( attr_name == "Frustum Far" ) \
  return attr_ref(frustum_far); \
if ( attr_name == "Use Orthographic Projection" ) \
  return attr_ref(use_orthographic_projection); \
if ( attr_name == "Viewport Left" ) \
  return attr_ref(viewport_left); \
if ( attr_name == "Viewport Right" ) \
  return attr_ref(viewport_right); \
if ( attr_name == "Viewport Top" ) \
  return attr_ref(viewport_top); \
if ( attr_name == "Viewport Bottom" ) \
  return attr_ref(viewport_bottom); \
if ( attr_name == "LOD Adjust" ) \
  return attr_ref(lod_adjust); \
if ( attr_name == "Unknown Link?" ) \
  return attr_ref(unknown_link_); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_CAMERA_PARENTS ANode

#define NI_CAMERA_CONSTRUCT

#define NI_CAMERA_READ \
ANode::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown_short, in, version ); \
}; \
NifStream( frustum_left, in, version ); \
NifStream( frustum_right, in, version ); \
NifStream( frustum_top, in, version ); \
NifStream( frustum_bottom, in, version ); \
NifStream( frustum_near, in, version ); \
NifStream( frustum_far, in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( use_orthographic_projection, in, version ); \
}; \
NifStream( viewport_left, in, version ); \
NifStream( viewport_right, in, version ); \
NifStream( viewport_top, in, version ); \
NifStream( viewport_bottom, in, version ); \
NifStream( lod_adjust, in, version ); \
NifStream( unknown_link_, in, version ); \
NifStream( unknown_int, in, version ); \
if ( version >= 0x04020100 ) { \
  NifStream( unknown_int_2, in, version ); \
}; \

#define NI_CAMERA_WRITE \
ANode::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown_short, out, version ); \
}; \
NifStream( frustum_left, out, version ); \
NifStream( frustum_right, out, version ); \
NifStream( frustum_top, out, version ); \
NifStream( frustum_bottom, out, version ); \
NifStream( frustum_near, out, version ); \
NifStream( frustum_far, out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( use_orthographic_projection, out, version ); \
}; \
NifStream( viewport_left, out, version ); \
NifStream( viewport_right, out, version ); \
NifStream( viewport_top, out, version ); \
NifStream( viewport_bottom, out, version ); \
NifStream( lod_adjust, out, version ); \
NifStream( unknown_link_, out, version ); \
NifStream( unknown_int, out, version ); \
if ( version >= 0x04020100 ) { \
  NifStream( unknown_int_2, out, version ); \
}; \

#define NI_CAMERA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ANode::asString(); \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "        Frustum Left:  " << frustum_left << endl; \
out << "       Frustum Right:  " << frustum_right << endl; \
out << "         Frustum Top:  " << frustum_top << endl; \
out << "      Frustum Bottom:  " << frustum_bottom << endl; \
out << "        Frustum Near:  " << frustum_near << endl; \
out << "         Frustum Far:  " << frustum_far << endl; \
out << "Use Orthographic Projection:  " << use_orthographic_projection << endl; \
out << "       Viewport Left:  " << viewport_left << endl; \
out << "      Viewport Right:  " << viewport_right << endl; \
out << "        Viewport Top:  " << viewport_top << endl; \
out << "     Viewport Bottom:  " << viewport_bottom << endl; \
out << "          LOD Adjust:  " << lod_adjust << endl; \
out << "       Unknown Link?:  " << unknown_link_ << endl; \
out << "         Unknown Int:  " << unknown_int << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
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
uint target_node; \
uint unknown2; \
byte unknown3; \
uint collision_type; \
uint unknown5; \
Vector3 unknown7; \
vector<float > unknown6; \
vector<float > unknown8; \

#define NI_COLLISION_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Target Node" ) \
  return attr_ref(target_node); \
if ( attr_name == "Unknown2" ) \
  return attr_ref(unknown2); \
if ( attr_name == "Unknown3" ) \
  return attr_ref(unknown3); \
if ( attr_name == "Collision Type" ) \
  return attr_ref(collision_type); \
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
NifStream( target_node, in, version ); \
NifStream( unknown2, in, version ); \
NifStream( unknown3, in, version ); \
NifStream( collision_type, in, version ); \
if ( collision_type == 0 ) { \
  NifStream( unknown5, in, version ); \
  NifStream( unknown7, in, version ); \
}; \
if ( collision_type == 2 ) { \
  unknown6.resize(8); \
  NifStream( unknown6, in, version ); \
}; \
if ( collision_type == 1 ) { \
  unknown8.resize(15); \
  NifStream( unknown8, in, version ); \
}; \

#define NI_COLLISION_DATA_WRITE \
AData::Write( out, version ); \
NifStream( target_node, out, version ); \
NifStream( unknown2, out, version ); \
NifStream( unknown3, out, version ); \
NifStream( collision_type, out, version ); \
if ( collision_type == 0 ) { \
  NifStream( unknown5, out, version ); \
  NifStream( unknown7, out, version ); \
}; \
if ( collision_type == 2 ) { \
  NifStream( unknown6, out, version ); \
}; \
if ( collision_type == 1 ) { \
  NifStream( unknown8, out, version ); \
}; \

#define NI_COLLISION_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Target Node:  " << target_node << endl; \
out << "            Unknown2:  " << unknown2 << endl; \
out << "            Unknown3:  " << unknown3 << endl; \
out << "      Collision Type:  " << collision_type << endl; \
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
bool unknown_byte; \
LinkGroup controller_sequences; \
uint object_palette; \

#define NI_CONTROLLER_MANAGER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
if ( attr_name == "Object Palette" ) \
  return attr_ref(object_palette); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_CONTROLLER_MANAGER_PARENTS AController

#define NI_CONTROLLER_MANAGER_CONSTRUCT

#define NI_CONTROLLER_MANAGER_READ \
AController::Read( in, version ); \
NifStream( unknown_byte, in, version ); \
NifStream( controller_sequences, in, version ); \
NifStream( object_palette, in, version ); \

#define NI_CONTROLLER_MANAGER_WRITE \
AController::Write( out, version ); \
NifStream( unknown_byte, out, version ); \
NifStream( controller_sequences, out, version ); \
NifStream( object_palette, out, version ); \

#define NI_CONTROLLER_MANAGER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "        Unknown Byte:  " << unknown_byte << endl; \
out << "Controller Sequences:  " << controller_sequences << endl; \
out << "      Object Palette:  " << object_palette << endl; \
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
ControllerLink text_keys; \
uint unknown_int_1; \
vector<ControllerLink > controlled_blocks; \
float unknown_float_1; \
uint text_keys_2; \
uint unknown_int_0; \
float unknown_float_3; \
float unknown_float_4; \
float start_time; \
float stop_time; \
float unknown_float_2; \
byte unknown_byte; \
uint unknown_int_3; \
string unknown_string; \
uint string_palette; \

#define NI_CONTROLLER_SEQUENCE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Name" ) \
  return attr_ref(name); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Text Keys 2" ) \
  return attr_ref(text_keys_2); \
if ( attr_name == "Unknown Int 0" ) \
  return attr_ref(unknown_int_0); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknown_float_3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknown_float_4); \
if ( attr_name == "Start Time" ) \
  return attr_ref(start_time); \
if ( attr_name == "Stop Time" ) \
  return attr_ref(stop_time); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknown_int_3); \
if ( attr_name == "Unknown String" ) \
  return attr_ref(unknown_string); \
if ( attr_name == "String Palette" ) \
  return attr_ref(string_palette); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_CONTROLLER_SEQUENCE_PARENTS AData

#define NI_CONTROLLER_SEQUENCE_CONSTRUCT

#define NI_CONTROLLER_SEQUENCE_READ \
uint num_controlled_blocks; \
AData::Read( in, version ); \
NifStream( name, in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( text_keys, in, version ); \
}; \
NifStream( num_controlled_blocks, in, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_int_1, in, version ); \
}; \
controlled_blocks.resize(num_controlled_blocks); \
NifStream( controlled_blocks, in, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_float_1, in, version ); \
  NifStream( text_keys_2, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown_int_0, in, version ); \
}; \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_float_3, in, version ); \
  NifStream( unknown_float_4, in, version ); \
  NifStream( start_time, in, version ); \
  NifStream( stop_time, in, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x0A020000 ) ) { \
  NifStream( unknown_float_2, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown_byte, in, version ); \
}; \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_int_3, in, version ); \
  NifStream( unknown_string, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( string_palette, in, version ); \
}; \

#define NI_CONTROLLER_SEQUENCE_WRITE \
uint num_controlled_blocks; \
AData::Write( out, version ); \
num_controlled_blocks = uint(controlled_blocks.size()); \
NifStream( name, out, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( text_keys, out, version ); \
}; \
NifStream( num_controlled_blocks, out, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_int_1, out, version ); \
}; \
NifStream( controlled_blocks, out, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_float_1, out, version ); \
  NifStream( text_keys_2, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown_int_0, out, version ); \
}; \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_float_3, out, version ); \
  NifStream( unknown_float_4, out, version ); \
  NifStream( start_time, out, version ); \
  NifStream( stop_time, out, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x0A020000 ) ) { \
  NifStream( unknown_float_2, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown_byte, out, version ); \
}; \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_int_3, out, version ); \
  NifStream( unknown_string, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( string_palette, out, version ); \
}; \

#define NI_CONTROLLER_SEQUENCE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Name:  " << name << endl; \
out << "           Text Keys:  " << text_keys << endl; \
out << "Num Controlled Blocks:  -- calculated --" << endl; \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "   Controlled Blocks:  -- data not shown --" << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "         Text Keys 2:  " << text_keys_2 << endl; \
out << "       Unknown Int 0:  " << unknown_int_0 << endl; \
out << "     Unknown Float 3:  " << unknown_float_3 << endl; \
out << "     Unknown Float 4:  " << unknown_float_4 << endl; \
out << "          Start Time:  " << start_time << endl; \
out << "           Stop Time:  " << stop_time << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "        Unknown Byte:  " << unknown_byte << endl; \
out << "       Unknown Int 3:  " << unknown_int_3 << endl; \
out << "      Unknown String:  " << unknown_string << endl; \
out << "      String Palette:  " << string_palette << endl; \
return out.str(); \

// 
// Unknown. Refers to a list of objects. Used by NiControllerManager.
//
// - Unknown.
// - The objects.
#define NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS \
uint unknown_int; \
vector<AVObject > objects; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_PARENTS AData

#define NI_DEFAULT_A_V_OBJECT_PALETTE_CONSTRUCT

#define NI_DEFAULT_A_V_OBJECT_PALETTE_READ \
uint num_objects; \
AData::Read( in, version ); \
NifStream( unknown_int, in, version ); \
NifStream( num_objects, in, version ); \
objects.resize(num_objects); \
NifStream( objects, in, version ); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_WRITE \
uint num_objects; \
AData::Write( out, version ); \
num_objects = uint(objects.size()); \
NifStream( unknown_int, out, version ); \
NifStream( num_objects, out, version ); \
NifStream( objects, out, version ); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Unknown Int:  " << unknown_int << endl; \
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
uint texture_slot; \
uint unknown_int_2; \
float delta; \
LinkGroup sources; \

#define NI_FLIP_CONTROLLER_GETATTR \
attr_ref attr = ASingleInterpolatorController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Texture Slot" ) \
  return attr_ref(texture_slot); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
if ( attr_name == "Delta" ) \
  return attr_ref(delta); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLIP_CONTROLLER_PARENTS ASingleInterpolatorController

#define NI_FLIP_CONTROLLER_CONSTRUCT

#define NI_FLIP_CONTROLLER_READ \
ASingleInterpolatorController::Read( in, version ); \
NifStream( texture_slot, in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( unknown_int_2, in, version ); \
  NifStream( delta, in, version ); \
}; \
NifStream( sources, in, version ); \

#define NI_FLIP_CONTROLLER_WRITE \
ASingleInterpolatorController::Write( out, version ); \
NifStream( texture_slot, out, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( unknown_int_2, out, version ); \
  NifStream( delta, out, version ); \
}; \
NifStream( sources, out, version ); \

#define NI_FLIP_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ASingleInterpolatorController::asString(); \
out << "        Texture Slot:  " << texture_slot << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
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
float float_data; \

#define NI_FLOAT_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Float Data" ) \
  return attr_ref(float_data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLOAT_EXTRA_DATA_PARENTS AExtraData

#define NI_FLOAT_EXTRA_DATA_CONSTRUCT

#define NI_FLOAT_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( float_data, in, version ); \

#define NI_FLOAT_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( float_data, out, version ); \

#define NI_FLOAT_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "          Float Data:  " << float_data << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown. Refers to some NiFloatExtraData name?
#define NI_FLOAT_EXTRA_DATA_CONTROLLER_MEMBERS \
uint unknown_link; \
string unknown_string; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknown_link); \
if ( attr_name == "Unknown String" ) \
  return attr_ref(unknown_string); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_PARENTS AController

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_CONSTRUCT

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_READ \
AController::Read( in, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( unknown_link, in, version ); \
  NifStream( unknown_string, in, version ); \
}; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( unknown_link, out, version ); \
  NifStream( unknown_string, out, version ); \
}; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "        Unknown Link:  " << unknown_link << endl; \
out << "      Unknown String:  " << unknown_string << endl; \
return out.str(); \

// 
// Unknown.
//
// - Value when posed?  At time 0?
// - Float data?
#define NI_FLOAT_INTERPOLATOR_MEMBERS \
float float_value; \
uint data; \

#define NI_FLOAT_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Float Value" ) \
  return attr_ref(float_value); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FLOAT_INTERPOLATOR_PARENTS AInterpolator

#define NI_FLOAT_INTERPOLATOR_CONSTRUCT

#define NI_FLOAT_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( float_value, in, version ); \
NifStream( data, in, version ); \

#define NI_FLOAT_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( float_value, out, version ); \
NifStream( data, out, version ); \

#define NI_FLOAT_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "         Float Value:  " << float_value << endl; \
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
uint num_floats; \
AExtraData::Read( in, version ); \
NifStream( num_floats, in, version ); \
data.resize(num_floats); \
NifStream( data, in, version ); \

#define NI_FLOATS_EXTRA_DATA_WRITE \
uint num_floats; \
AExtraData::Write( out, version ); \
num_floats = uint(data.size()); \
NifStream( num_floats, out, version ); \
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
float fog_depth; \
Color3 fog_color; \

#define NI_FOG_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Fog Depth" ) \
  return attr_ref(fog_depth); \
if ( attr_name == "Fog Color" ) \
  return attr_ref(fog_color); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_FOG_PROPERTY_PARENTS AProperty

#define NI_FOG_PROPERTY_CONSTRUCT

#define NI_FOG_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \
NifStream( fog_depth, in, version ); \
NifStream( fog_color, in, version ); \

#define NI_FOG_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \
NifStream( fog_depth, out, version ); \
NifStream( fog_color, out, version ); \

#define NI_FOG_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "           Fog Depth:  " << fog_depth << endl; \
out << "           Fog Color:  " << fog_color << endl; \
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
byte unknown_2; \
uint data; \
byte unknown_byte; \
LinkGroup interpolators; \
vector<uint > unknown_ints; \

#define NI_GEOM_MORPHER_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown" ) \
  return attr_ref(unknown); \
if ( attr_name == "Unknown 2" ) \
  return attr_ref(unknown_2); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_GEOM_MORPHER_CONTROLLER_PARENTS AController

#define NI_GEOM_MORPHER_CONTROLLER_CONSTRUCT

#define NI_GEOM_MORPHER_CONTROLLER_READ \
uint num_unknown_ints; \
AController::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown_2, in, version ); \
}; \
NifStream( data, in, version ); \
NifStream( unknown_byte, in, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( interpolators, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( num_unknown_ints, in, version ); \
  unknown_ints.resize(num_unknown_ints); \
  NifStream( unknown_ints, in, version ); \
}; \

#define NI_GEOM_MORPHER_CONTROLLER_WRITE \
uint num_unknown_ints; \
AController::Write( out, version ); \
num_unknown_ints = uint(unknown_ints.size()); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown_2, out, version ); \
}; \
NifStream( data, out, version ); \
NifStream( unknown_byte, out, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( interpolators, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( num_unknown_ints, out, version ); \
  NifStream( unknown_ints, out, version ); \
}; \

#define NI_GEOM_MORPHER_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "             Unknown:  " << unknown << endl; \
out << "           Unknown 2:  " << unknown_2 << endl; \
out << "                Data:  " << data << endl; \
out << "        Unknown Byte:  " << unknown_byte << endl; \
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
float unknown_float_1; \
float force; \
uint type; \
Vector3 position; \
Vector3 direction; \

#define NI_GRAVITY_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
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
NifStream( unknown_float_1, in, version ); \
NifStream( force, in, version ); \
NifStream( type, in, version ); \
NifStream( position, in, version ); \
NifStream( direction, in, version ); \

#define NI_GRAVITY_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( force, out, version ); \
NifStream( type, out, version ); \
NifStream( position, out, version ); \
NifStream( direction, out, version ); \

#define NI_GRAVITY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
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
uint integer_data; \

#define NI_INTEGER_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Integer Data" ) \
  return attr_ref(integer_data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_INTEGER_EXTRA_DATA_PARENTS AExtraData

#define NI_INTEGER_EXTRA_DATA_CONSTRUCT

#define NI_INTEGER_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( integer_data, in, version ); \

#define NI_INTEGER_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( integer_data, out, version ); \

#define NI_INTEGER_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "        Integer Data:  " << integer_data << endl; \
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
uint num_integers; \
AExtraData::Read( in, version ); \
NifStream( num_integers, in, version ); \
data.resize(num_integers); \
NifStream( data, in, version ); \

#define NI_INTEGERS_EXTRA_DATA_WRITE \
uint num_integers; \
AExtraData::Write( out, version ); \
num_integers = uint(data.size()); \
NifStream( num_integers, out, version ); \
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
ushort unknown_short; \
uint data; \
uint interpolator; \

#define NI_LIGHT_COLOR_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
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
  NifStream( unknown_short, in, version ); \
}; \
if ( version <= 0x0A010000 ) { \
  NifStream( data, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( interpolator, in, version ); \
  NifStream( unknown_short, in, version ); \
}; \

#define NI_LIGHT_COLOR_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) { \
  NifStream( unknown_short, out, version ); \
}; \
if ( version <= 0x0A010000 ) { \
  NifStream( data, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( interpolator, out, version ); \
  NifStream( unknown_short, out, version ); \
}; \

#define NI_LIGHT_COLOR_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "                Data:  " << data << endl; \
out << "        Interpolator:  " << interpolator << endl; \
return out.str(); \

// 
// Unknown controller.
//
// - Unknown link. Interpolator?
#define NI_LIGHT_DIMMER_CONTROLLER_MEMBERS \
uint unknown_link; \

#define NI_LIGHT_DIMMER_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknown_link); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_LIGHT_DIMMER_CONTROLLER_PARENTS AController

#define NI_LIGHT_DIMMER_CONTROLLER_CONSTRUCT

#define NI_LIGHT_DIMMER_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( unknown_link, in, version ); \

#define NI_LIGHT_DIMMER_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( unknown_link, out, version ); \

#define NI_LIGHT_DIMMER_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "        Unknown Link:  " << unknown_link << endl; \
return out.str(); \

// 
// Level of detail selector. Links to different levels of detail of the same model, used to switch a geometry at a specified distance.
//
// - The ranges of distance where each level of detail applies.
#define NI_L_O_D_NODE_MEMBERS \
LODInfo lod_info; \

#define NI_L_O_D_NODE_GETATTR \
attr_ref attr = AParentNode::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_L_O_D_NODE_PARENTS AParentNode

#define NI_L_O_D_NODE_CONSTRUCT

#define NI_L_O_D_NODE_READ \
AParentNode::Read( in, version ); \
NifStream( lod_info, in, version ); \

#define NI_L_O_D_NODE_WRITE \
AParentNode::Write( out, version ); \
NifStream( lod_info, out, version ); \

#define NI_L_O_D_NODE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParentNode::asString(); \
out << "            LOD Info:  " << lod_info << endl; \
return out.str(); \

// 
// Unknown. Start time is 3.4e+38 and stop time is -3.4e+38.
//
// - Unknown.
// - Link to the node to look at?
#define NI_LOOK_AT_CONTROLLER_MEMBERS \
ushort unknown1; \
uint look_at_node; \

#define NI_LOOK_AT_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown1" ) \
  return attr_ref(unknown1); \
if ( attr_name == "Look At Node" ) \
  return attr_ref(look_at_node); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_LOOK_AT_CONTROLLER_PARENTS AController

#define NI_LOOK_AT_CONTROLLER_CONSTRUCT

#define NI_LOOK_AT_CONTROLLER_READ \
AController::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown1, in, version ); \
}; \
NifStream( look_at_node, in, version ); \

#define NI_LOOK_AT_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown1, out, version ); \
}; \
NifStream( look_at_node, out, version ); \

#define NI_LOOK_AT_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "            Unknown1:  " << unknown1 << endl; \
out << "        Look At Node:  " << look_at_node << endl; \
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
ushort unknown_short; \
uint look_at; \
float unknown_float; \
Vector3 translation; \
Quaternion rotation; \
float scale; \
uint unknown_link_1; \
uint unknown_link_2; \
uint unknown_link_3; \

#define NI_LOOK_AT_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Look At" ) \
  return attr_ref(look_at); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknown_float); \
if ( attr_name == "Translation" ) \
  return attr_ref(translation); \
if ( attr_name == "Rotation" ) \
  return attr_ref(rotation); \
if ( attr_name == "Scale" ) \
  return attr_ref(scale); \
if ( attr_name == "Unknown Link 1" ) \
  return attr_ref(unknown_link_1); \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknown_link_2); \
if ( attr_name == "Unknown Link 3" ) \
  return attr_ref(unknown_link_3); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_LOOK_AT_INTERPOLATOR_PARENTS AInterpolator

#define NI_LOOK_AT_INTERPOLATOR_CONSTRUCT

#define NI_LOOK_AT_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( unknown_short, in, version ); \
NifStream( look_at, in, version ); \
NifStream( unknown_float, in, version ); \
NifStream( translation, in, version ); \
NifStream( rotation, in, version ); \
NifStream( scale, in, version ); \
NifStream( unknown_link_1, in, version ); \
NifStream( unknown_link_2, in, version ); \
NifStream( unknown_link_3, in, version ); \

#define NI_LOOK_AT_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( unknown_short, out, version ); \
NifStream( look_at, out, version ); \
NifStream( unknown_float, out, version ); \
NifStream( translation, out, version ); \
NifStream( rotation, out, version ); \
NifStream( scale, out, version ); \
NifStream( unknown_link_1, out, version ); \
NifStream( unknown_link_2, out, version ); \
NifStream( unknown_link_3, out, version ); \

#define NI_LOOK_AT_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "             Look At:  " << look_at << endl; \
out << "       Unknown Float:  " << unknown_float << endl; \
out << "         Translation:  " << translation << endl; \
out << "            Rotation:  " << rotation << endl; \
out << "               Scale:  " << scale << endl; \
out << "      Unknown Link 1:  " << unknown_link_1 << endl; \
out << "      Unknown Link 2:  " << unknown_link_2 << endl; \
out << "      Unknown Link 3:  " << unknown_link_3 << endl; \
return out.str(); \

// 
// Time controller for material color.
//
// - Unknown.
// - Material color controller data block index.
// - Unknown.
#define NI_MATERIAL_COLOR_CONTROLLER_MEMBERS \
ushort unknown; \
uint data; \
ushort unknown_short; \

#define NI_MATERIAL_COLOR_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown" ) \
  return attr_ref(unknown); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
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
  NifStream( unknown_short, in, version ); \
}; \

#define NI_MATERIAL_COLOR_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) { \
  NifStream( unknown, out, version ); \
}; \
NifStream( data, out, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( unknown_short, out, version ); \
}; \

#define NI_MATERIAL_COLOR_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "             Unknown:  " << unknown << endl; \
out << "                Data:  " << data << endl; \
out << "       Unknown Short:  " << unknown_short << endl; \
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
Color3 ambient_color; \
Color3 diffuse_color; \
Color3 specular_color; \
Color3 emissive_color; \
float glossiness; \
float alpha; \

#define NI_MATERIAL_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Ambient Color" ) \
  return attr_ref(ambient_color); \
if ( attr_name == "Diffuse Color" ) \
  return attr_ref(diffuse_color); \
if ( attr_name == "Specular Color" ) \
  return attr_ref(specular_color); \
if ( attr_name == "Emissive Color" ) \
  return attr_ref(emissive_color); \
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
NifStream( ambient_color, in, version ); \
NifStream( diffuse_color, in, version ); \
NifStream( specular_color, in, version ); \
NifStream( emissive_color, in, version ); \
NifStream( glossiness, in, version ); \
NifStream( alpha, in, version ); \

#define NI_MATERIAL_PROPERTY_WRITE \
AProperty::Write( out, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, out, version ); \
}; \
NifStream( ambient_color, out, version ); \
NifStream( diffuse_color, out, version ); \
NifStream( specular_color, out, version ); \
NifStream( emissive_color, out, version ); \
NifStream( glossiness, out, version ); \
NifStream( alpha, out, version ); \

#define NI_MATERIAL_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "       Ambient Color:  " << ambient_color << endl; \
out << "       Diffuse Color:  " << diffuse_color << endl; \
out << "      Specular Color:  " << specular_color << endl; \
out << "      Emissive Color:  " << emissive_color << endl; \
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
byte unknown_byte_11; \
vector<vector<float > > unknown_floats_3; \
vector<vector<float > > unknown_floats_4; \
vector<vector<float > > unknown_floats_5; \
uint unknown_int_1; \
uint modifier; \
byte unknown_byte_2; \
LinkGroup unknown_link_group; \
ushort unknown_short_4; \
uint unknown_int_2; \
byte unknown_byte_12; \
uint unknown_int_3; \
uint unknown_int_4; \
uint unknown_link_2; \

#define NI_MESH_P_SYS_DATA_GETATTR \
attr_ref attr = APSysData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Byte 11" ) \
  return attr_ref(unknown_byte_11); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
if ( attr_name == "Modifier" ) \
  return attr_ref(modifier); \
if ( attr_name == "Unknown Byte 2" ) \
  return attr_ref(unknown_byte_2); \
if ( attr_name == "Unknown Short 4" ) \
  return attr_ref(unknown_short_4); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
if ( attr_name == "Unknown Byte 12" ) \
  return attr_ref(unknown_byte_12); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknown_int_3); \
if ( attr_name == "Unknown Int 4" ) \
  return attr_ref(unknown_int_4); \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknown_link_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_MESH_P_SYS_DATA_PARENTS APSysData

#define NI_MESH_P_SYS_DATA_CONSTRUCT

#define NI_MESH_P_SYS_DATA_READ \
APSysData::Read( in, version ); \
if ( version >= 0x14000005 ) { \
  NifStream( unknown_byte_11, in, version ); \
}; \
if ( version <= 0x14000004 ) { \
  unknown_floats_3.resize(num_vertices); \
  NifStream( unknown_floats_3, in, version ); \
  unknown_floats_4.resize(num_vertices); \
  NifStream( unknown_floats_4, in, version ); \
}; \
if ( version >= 0x14000005 ) { \
  unknown_floats_5.resize(num_vertices); \
  NifStream( unknown_floats_5, in, version ); \
}; \
NifStream( unknown_int_1, in, version ); \
if ( version <= 0x14000004 ) { \
  NifStream( modifier, in, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) { \
  NifStream( unknown_byte_2, in, version ); \
  NifStream( unknown_link_group, in, version ); \
}; \
if ( version >= 0x14000005 ) { \
  NifStream( unknown_short_4, in, version ); \
  NifStream( unknown_int_2, in, version ); \
  NifStream( unknown_byte_12, in, version ); \
  NifStream( unknown_int_3, in, version ); \
  NifStream( unknown_int_4, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( unknown_link_2, in, version ); \
}; \

#define NI_MESH_P_SYS_DATA_WRITE \
APSysData::Write( out, version ); \
if ( version >= 0x14000005 ) { \
  NifStream( unknown_byte_11, out, version ); \
}; \
if ( version <= 0x14000004 ) { \
  NifStream( unknown_floats_3, out, version ); \
  NifStream( unknown_floats_4, out, version ); \
}; \
if ( version >= 0x14000005 ) { \
  NifStream( unknown_floats_5, out, version ); \
}; \
NifStream( unknown_int_1, out, version ); \
if ( version <= 0x14000004 ) { \
  NifStream( modifier, out, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) { \
  NifStream( unknown_byte_2, out, version ); \
  NifStream( unknown_link_group, out, version ); \
}; \
if ( version >= 0x14000005 ) { \
  NifStream( unknown_short_4, out, version ); \
  NifStream( unknown_int_2, out, version ); \
  NifStream( unknown_byte_12, out, version ); \
  NifStream( unknown_int_3, out, version ); \
  NifStream( unknown_int_4, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
  NifStream( unknown_link_2, out, version ); \
}; \

#define NI_MESH_P_SYS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysData::asString(); \
out << "     Unknown Byte 11:  " << unknown_byte_11 << endl; \
out << "    Unknown Floats 3:  -- data not shown --" << endl; \
out << "    Unknown Floats 4:  -- data not shown --" << endl; \
out << "    Unknown Floats 5:  -- data not shown --" << endl; \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "            Modifier:  " << modifier << endl; \
out << "      Unknown Byte 2:  " << unknown_byte_2 << endl; \
out << "  Unknown Link Group:  " << unknown_link_group << endl; \
out << "     Unknown Short 4:  " << unknown_short_4 << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
out << "     Unknown Byte 12:  " << unknown_byte_12 << endl; \
out << "       Unknown Int 3:  " << unknown_int_3 << endl; \
out << "       Unknown Int 4:  " << unknown_int_4 << endl; \
out << "      Unknown Link 2:  " << unknown_link_2 << endl; \
return out.str(); \

// 
// Geometry morphing data.
//
// - Number of vertices.
// - This byte is always 1 in all official files.
// - The geometry morphing blocks.
#define NI_MORPH_DATA_MEMBERS \
uint num_vertices; \
byte unknown_byte; \
vector<Morph > morphs; \

#define NI_MORPH_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Vertices" ) \
  return attr_ref(num_vertices); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_MORPH_DATA_PARENTS AData

#define NI_MORPH_DATA_CONSTRUCT

#define NI_MORPH_DATA_READ \
uint num_morphs; \
AData::Read( in, version ); \
NifStream( num_morphs, in, version ); \
NifStream( num_vertices, in, version ); \
NifStream( unknown_byte, in, version ); \
morphs.resize(num_morphs); \
NifStream( morphs, in, version, num_vertices ); \

#define NI_MORPH_DATA_WRITE \
uint num_morphs; \
AData::Write( out, version ); \
num_morphs = uint(morphs.size()); \
NifStream( num_morphs, out, version ); \
NifStream( num_vertices, out, version ); \
NifStream( unknown_byte, out, version ); \
NifStream( morphs, out, version, num_vertices ); \

#define NI_MORPH_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "          Num Morphs:  -- calculated --" << endl; \
out << "        Num Vertices:  " << num_vertices << endl; \
out << "        Unknown Byte:  " << unknown_byte << endl; \
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
byte unknown_byte; \
uint num_entries_; \
vector<vector<byte > > palette; \

#define NI_PALETTE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
if ( attr_name == "Num Entries?" ) \
  return attr_ref(num_entries_); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PALETTE_PARENTS AData

#define NI_PALETTE_CONSTRUCT

#define NI_PALETTE_READ \
AData::Read( in, version ); \
NifStream( unknown_byte, in, version ); \
NifStream( num_entries_, in, version ); \
palette.resize(256); \
NifStream( palette, in, version ); \

#define NI_PALETTE_WRITE \
AData::Write( out, version ); \
NifStream( unknown_byte, out, version ); \
NifStream( num_entries_, out, version ); \
NifStream( palette, out, version ); \

#define NI_PALETTE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "        Unknown Byte:  " << unknown_byte << endl; \
out << "        Num Entries?:  " << num_entries_ << endl; \
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
float unknown_float_1; \
float unknown_float_2; \
float unknown_float_3; \
float unknown_float_4; \
uint unknown_int_1; \
uint unknown_int_2; \
float unknown_float_5; \
float unknown_float_6; \
float unknown_float_7; \
float unknown_float_8; \
float unknown_float_9; \
float unknown_float_10; \

#define NI_PARTICLE_BOMB_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknown_float_3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknown_float_4); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
if ( attr_name == "Unknown Float 5" ) \
  return attr_ref(unknown_float_5); \
if ( attr_name == "Unknown Float 6" ) \
  return attr_ref(unknown_float_6); \
if ( attr_name == "Unknown Float 7" ) \
  return attr_ref(unknown_float_7); \
if ( attr_name == "Unknown Float 8" ) \
  return attr_ref(unknown_float_8); \
if ( attr_name == "Unknown Float 9" ) \
  return attr_ref(unknown_float_9); \
if ( attr_name == "Unknown Float 10" ) \
  return attr_ref(unknown_float_10); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_BOMB_PARENTS AParticleModifier

#define NI_PARTICLE_BOMB_CONSTRUCT

#define NI_PARTICLE_BOMB_READ \
AParticleModifier::Read( in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_float_2, in, version ); \
NifStream( unknown_float_3, in, version ); \
NifStream( unknown_float_4, in, version ); \
NifStream( unknown_int_1, in, version ); \
NifStream( unknown_int_2, in, version ); \
NifStream( unknown_float_5, in, version ); \
NifStream( unknown_float_6, in, version ); \
NifStream( unknown_float_7, in, version ); \
NifStream( unknown_float_8, in, version ); \
NifStream( unknown_float_9, in, version ); \
NifStream( unknown_float_10, in, version ); \

#define NI_PARTICLE_BOMB_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_float_2, out, version ); \
NifStream( unknown_float_3, out, version ); \
NifStream( unknown_float_4, out, version ); \
NifStream( unknown_int_1, out, version ); \
NifStream( unknown_int_2, out, version ); \
NifStream( unknown_float_5, out, version ); \
NifStream( unknown_float_6, out, version ); \
NifStream( unknown_float_7, out, version ); \
NifStream( unknown_float_8, out, version ); \
NifStream( unknown_float_9, out, version ); \
NifStream( unknown_float_10, out, version ); \

#define NI_PARTICLE_BOMB_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "     Unknown Float 3:  " << unknown_float_3 << endl; \
out << "     Unknown Float 4:  " << unknown_float_4 << endl; \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
out << "     Unknown Float 5:  " << unknown_float_5 << endl; \
out << "     Unknown Float 6:  " << unknown_float_6 << endl; \
out << "     Unknown Float 7:  " << unknown_float_7 << endl; \
out << "     Unknown Float 8:  " << unknown_float_8 << endl; \
out << "     Unknown Float 9:  " << unknown_float_9 << endl; \
out << "    Unknown Float 10:  " << unknown_float_10 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Color data index.
#define NI_PARTICLE_COLOR_MODIFIER_MEMBERS \
uint color_data; \

#define NI_PARTICLE_COLOR_MODIFIER_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Color Data" ) \
  return attr_ref(color_data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_COLOR_MODIFIER_PARENTS AParticleModifier

#define NI_PARTICLE_COLOR_MODIFIER_CONSTRUCT

#define NI_PARTICLE_COLOR_MODIFIER_READ \
AParticleModifier::Read( in, version ); \
NifStream( color_data, in, version ); \

#define NI_PARTICLE_COLOR_MODIFIER_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( color_data, out, version ); \

#define NI_PARTICLE_COLOR_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "          Color Data:  " << color_data << endl; \
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
uint unknown_link_2; \

#define NI_PARTICLE_MESHES_DATA_GETATTR \
attr_ref attr = ARotatingParticlesData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Link 2" ) \
  return attr_ref(unknown_link_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_MESHES_DATA_PARENTS ARotatingParticlesData

#define NI_PARTICLE_MESHES_DATA_CONSTRUCT

#define NI_PARTICLE_MESHES_DATA_READ \
ARotatingParticlesData::Read( in, version ); \
NifStream( unknown_link_2, in, version ); \

#define NI_PARTICLE_MESHES_DATA_WRITE \
ARotatingParticlesData::Write( out, version ); \
NifStream( unknown_link_2, out, version ); \

#define NI_PARTICLE_MESHES_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ARotatingParticlesData::asString(); \
out << "      Unknown Link 2:  " << unknown_link_2 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Links to nodes of particle meshes?
#define NI_PARTICLE_MESH_MODIFIER_MEMBERS \
LinkGroup particle_meshes; \

#define NI_PARTICLE_MESH_MODIFIER_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_MESH_MODIFIER_PARENTS AParticleModifier

#define NI_PARTICLE_MESH_MODIFIER_CONSTRUCT

#define NI_PARTICLE_MESH_MODIFIER_READ \
AParticleModifier::Read( in, version ); \
NifStream( particle_meshes, in, version ); \

#define NI_PARTICLE_MESH_MODIFIER_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( particle_meshes, out, version ); \

#define NI_PARTICLE_MESH_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "     Particle Meshes:  " << particle_meshes << endl; \
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
byte unknown_byte; \
float unknown_float_1; \
float unknown_float_2; \
float unknown_float_3; \
float unknown_float_4; \

#define NI_PARTICLE_ROTATION_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknown_float_3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknown_float_4); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PARTICLE_ROTATION_PARENTS AParticleModifier

#define NI_PARTICLE_ROTATION_CONSTRUCT

#define NI_PARTICLE_ROTATION_READ \
AParticleModifier::Read( in, version ); \
NifStream( unknown_byte, in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_float_2, in, version ); \
NifStream( unknown_float_3, in, version ); \
NifStream( unknown_float_4, in, version ); \

#define NI_PARTICLE_ROTATION_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( unknown_byte, out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_float_2, out, version ); \
NifStream( unknown_float_3, out, version ); \
NifStream( unknown_float_4, out, version ); \

#define NI_PARTICLE_ROTATION_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "        Unknown Byte:  " << unknown_byte << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "     Unknown Float 3:  " << unknown_float_3 << endl; \
out << "     Unknown Float 4:  " << unknown_float_4 << endl; \
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
ushort unknown_short_2; \
uint unknown_int_1; \
uint unknown_int_2; \
uint unknown_int_3; \
ushort unknown_short; \
uint pos_data; \
uint float_data; \

#define NI_PATH_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknown_short_2); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
if ( attr_name == "Unknown Int 2" ) \
  return attr_ref(unknown_int_2); \
if ( attr_name == "Unknown Int 3" ) \
  return attr_ref(unknown_int_3); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Pos Data" ) \
  return attr_ref(pos_data); \
if ( attr_name == "Float Data" ) \
  return attr_ref(float_data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PATH_CONTROLLER_PARENTS AController

#define NI_PATH_CONTROLLER_CONSTRUCT

#define NI_PATH_CONTROLLER_READ \
AController::Read( in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown_short_2, in, version ); \
}; \
NifStream( unknown_int_1, in, version ); \
NifStream( unknown_int_2, in, version ); \
NifStream( unknown_int_3, in, version ); \
NifStream( unknown_short, in, version ); \
NifStream( pos_data, in, version ); \
NifStream( float_data, in, version ); \

#define NI_PATH_CONTROLLER_WRITE \
AController::Write( out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( unknown_short_2, out, version ); \
}; \
NifStream( unknown_int_1, out, version ); \
NifStream( unknown_int_2, out, version ); \
NifStream( unknown_int_3, out, version ); \
NifStream( unknown_short, out, version ); \
NifStream( pos_data, out, version ); \
NifStream( float_data, out, version ); \

#define NI_PATH_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "     Unknown Short 2:  " << unknown_short_2 << endl; \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "       Unknown Int 2:  " << unknown_int_2 << endl; \
out << "       Unknown Int 3:  " << unknown_int_3 << endl; \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "            Pos Data:  " << pos_data << endl; \
out << "          Float Data:  " << float_data << endl; \
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
float unknown_float_1; \
float unknown_float_2; \
ushort unknown_short_2; \
uint pos_data; \
uint float_data; \

#define NI_PATH_INTERPOLATOR_GETATTR \
attr_ref attr = ABlendInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknown_short_2); \
if ( attr_name == "Pos Data" ) \
  return attr_ref(pos_data); \
if ( attr_name == "Float Data" ) \
  return attr_ref(float_data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PATH_INTERPOLATOR_PARENTS ABlendInterpolator

#define NI_PATH_INTERPOLATOR_CONSTRUCT

#define NI_PATH_INTERPOLATOR_READ \
ABlendInterpolator::Read( in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_float_2, in, version ); \
NifStream( unknown_short_2, in, version ); \
NifStream( pos_data, in, version ); \
NifStream( float_data, in, version ); \

#define NI_PATH_INTERPOLATOR_WRITE \
ABlendInterpolator::Write( out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_float_2, out, version ); \
NifStream( unknown_short_2, out, version ); \
NifStream( pos_data, out, version ); \
NifStream( float_data, out, version ); \

#define NI_PATH_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ABlendInterpolator::asString(); \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "     Unknown Short 2:  " << unknown_short_2 << endl; \
out << "            Pos Data:  " << pos_data << endl; \
out << "          Float Data:  " << float_data << endl; \
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
uint pixel_format; \
uint red_mask; \
uint green_mask; \
uint blue_mask; \
uint alpha_mask; \
uint bits_per_pixel; \
vector<byte > unknown_8_bytes; \
uint unknown_int; \
vector<byte > unknown_54_bytes; \
uint palette; \
uint bytes_per_pixel; \
vector<MipMap > mipmaps; \
ByteArray pixel_data; \

#define NI_PIXEL_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Pixel Format" ) \
  return attr_ref(pixel_format); \
if ( attr_name == "Red Mask" ) \
  return attr_ref(red_mask); \
if ( attr_name == "Green Mask" ) \
  return attr_ref(green_mask); \
if ( attr_name == "Blue Mask" ) \
  return attr_ref(blue_mask); \
if ( attr_name == "Alpha Mask" ) \
  return attr_ref(alpha_mask); \
if ( attr_name == "Bits Per Pixel" ) \
  return attr_ref(bits_per_pixel); \
if ( attr_name == "Unknown Int" ) \
  return attr_ref(unknown_int); \
if ( attr_name == "Palette" ) \
  return attr_ref(palette); \
if ( attr_name == "Bytes Per Pixel" ) \
  return attr_ref(bytes_per_pixel); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PIXEL_DATA_PARENTS AData

#define NI_PIXEL_DATA_CONSTRUCT

#define NI_PIXEL_DATA_READ \
uint num_mipmaps; \
AData::Read( in, version ); \
NifStream( pixel_format, in, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( red_mask, in, version ); \
  NifStream( green_mask, in, version ); \
  NifStream( blue_mask, in, version ); \
  NifStream( alpha_mask, in, version ); \
  NifStream( bits_per_pixel, in, version ); \
  unknown_8_bytes.resize(8); \
  NifStream( unknown_8_bytes, in, version ); \
}; \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A020000 ) ) { \
  NifStream( unknown_int, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
  unknown_54_bytes.resize(54); \
  NifStream( unknown_54_bytes, in, version ); \
}; \
NifStream( palette, in, version ); \
NifStream( num_mipmaps, in, version ); \
NifStream( bytes_per_pixel, in, version ); \
mipmaps.resize(num_mipmaps); \
NifStream( mipmaps, in, version ); \
NifStream( pixel_data, in, version ); \

#define NI_PIXEL_DATA_WRITE \
uint num_mipmaps; \
AData::Write( out, version ); \
num_mipmaps = uint(mipmaps.size()); \
NifStream( pixel_format, out, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( red_mask, out, version ); \
  NifStream( green_mask, out, version ); \
  NifStream( blue_mask, out, version ); \
  NifStream( alpha_mask, out, version ); \
  NifStream( bits_per_pixel, out, version ); \
  NifStream( unknown_8_bytes, out, version ); \
}; \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A020000 ) ) { \
  NifStream( unknown_int, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknown_54_bytes, out, version ); \
}; \
NifStream( palette, out, version ); \
NifStream( num_mipmaps, out, version ); \
NifStream( bytes_per_pixel, out, version ); \
NifStream( mipmaps, out, version ); \
NifStream( pixel_data, out, version ); \

#define NI_PIXEL_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "        Pixel Format:  " << pixel_format << endl; \
out << "            Red Mask:  " << red_mask << endl; \
out << "          Green Mask:  " << green_mask << endl; \
out << "           Blue Mask:  " << blue_mask << endl; \
out << "          Alpha Mask:  " << alpha_mask << endl; \
out << "      Bits Per Pixel:  " << bits_per_pixel << endl; \
out << "     Unknown 8 Bytes:  -- data not shown --" << endl; \
out << "         Unknown Int:  " << unknown_int << endl; \
out << "    Unknown 54 Bytes:  -- data not shown --" << endl; \
out << "             Palette:  " << palette << endl; \
out << "         Num Mipmaps:  -- calculated --" << endl; \
out << "     Bytes Per Pixel:  " << bytes_per_pixel << endl; \
out << "             Mipmaps:  -- data not shown --" << endl; \
out << "          Pixel Data:  " << pixel_data << endl; \
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
ushort unknown_short; \
float unknown_float_1; \
float unknown_float_2; \
ushort unknown_short_2; \
float unknown_float_3; \
float unknown_float_4; \
float unknown_float_5; \
float unknown_float_6; \
float unknown_float_7; \
float unknown_float_8; \
float unknown_float_9; \
float unknown_float_10; \
float unknown_float_11; \
float unknown_float_12; \
float unknown_float_13; \
float unknown_float_14; \
float unknown_float_15; \
float unknown_float_16; \

#define NI_PLANAR_COLLIDER_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Short 2" ) \
  return attr_ref(unknown_short_2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknown_float_3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknown_float_4); \
if ( attr_name == "Unknown Float 5" ) \
  return attr_ref(unknown_float_5); \
if ( attr_name == "Unknown Float 6" ) \
  return attr_ref(unknown_float_6); \
if ( attr_name == "Unknown Float 7" ) \
  return attr_ref(unknown_float_7); \
if ( attr_name == "Unknown Float 8" ) \
  return attr_ref(unknown_float_8); \
if ( attr_name == "Unknown Float 9" ) \
  return attr_ref(unknown_float_9); \
if ( attr_name == "Unknown Float 10" ) \
  return attr_ref(unknown_float_10); \
if ( attr_name == "Unknown Float 11" ) \
  return attr_ref(unknown_float_11); \
if ( attr_name == "Unknown Float 12" ) \
  return attr_ref(unknown_float_12); \
if ( attr_name == "Unknown Float 13" ) \
  return attr_ref(unknown_float_13); \
if ( attr_name == "Unknown Float 14" ) \
  return attr_ref(unknown_float_14); \
if ( attr_name == "Unknown Float 15" ) \
  return attr_ref(unknown_float_15); \
if ( attr_name == "Unknown Float 16" ) \
  return attr_ref(unknown_float_16); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_PLANAR_COLLIDER_PARENTS AParticleModifier

#define NI_PLANAR_COLLIDER_CONSTRUCT

#define NI_PLANAR_COLLIDER_READ \
AParticleModifier::Read( in, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( unknown_short, in, version ); \
}; \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_float_2, in, version ); \
if ( ( version >= 0x04020200 ) && ( version <= 0x04020200 ) ) { \
  NifStream( unknown_short_2, in, version ); \
}; \
NifStream( unknown_float_3, in, version ); \
NifStream( unknown_float_4, in, version ); \
NifStream( unknown_float_5, in, version ); \
NifStream( unknown_float_6, in, version ); \
NifStream( unknown_float_7, in, version ); \
NifStream( unknown_float_8, in, version ); \
NifStream( unknown_float_9, in, version ); \
NifStream( unknown_float_10, in, version ); \
NifStream( unknown_float_11, in, version ); \
NifStream( unknown_float_12, in, version ); \
NifStream( unknown_float_13, in, version ); \
NifStream( unknown_float_14, in, version ); \
NifStream( unknown_float_15, in, version ); \
NifStream( unknown_float_16, in, version ); \

#define NI_PLANAR_COLLIDER_WRITE \
AParticleModifier::Write( out, version ); \
if ( version >= 0x0A000100 ) { \
  NifStream( unknown_short, out, version ); \
}; \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_float_2, out, version ); \
if ( ( version >= 0x04020200 ) && ( version <= 0x04020200 ) ) { \
  NifStream( unknown_short_2, out, version ); \
}; \
NifStream( unknown_float_3, out, version ); \
NifStream( unknown_float_4, out, version ); \
NifStream( unknown_float_5, out, version ); \
NifStream( unknown_float_6, out, version ); \
NifStream( unknown_float_7, out, version ); \
NifStream( unknown_float_8, out, version ); \
NifStream( unknown_float_9, out, version ); \
NifStream( unknown_float_10, out, version ); \
NifStream( unknown_float_11, out, version ); \
NifStream( unknown_float_12, out, version ); \
NifStream( unknown_float_13, out, version ); \
NifStream( unknown_float_14, out, version ); \
NifStream( unknown_float_15, out, version ); \
NifStream( unknown_float_16, out, version ); \

#define NI_PLANAR_COLLIDER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "     Unknown Short 2:  " << unknown_short_2 << endl; \
out << "     Unknown Float 3:  " << unknown_float_3 << endl; \
out << "     Unknown Float 4:  " << unknown_float_4 << endl; \
out << "     Unknown Float 5:  " << unknown_float_5 << endl; \
out << "     Unknown Float 6:  " << unknown_float_6 << endl; \
out << "     Unknown Float 7:  " << unknown_float_7 << endl; \
out << "     Unknown Float 8:  " << unknown_float_8 << endl; \
out << "     Unknown Float 9:  " << unknown_float_9 << endl; \
out << "    Unknown Float 10:  " << unknown_float_10 << endl; \
out << "    Unknown Float 11:  " << unknown_float_11 << endl; \
out << "    Unknown Float 12:  " << unknown_float_12 << endl; \
out << "    Unknown Float 13:  " << unknown_float_13 << endl; \
out << "    Unknown Float 14:  " << unknown_float_14 << endl; \
out << "    Unknown Float 15:  " << unknown_float_15 << endl; \
out << "    Unknown Float 16:  " << unknown_float_16 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Value when posed?  Value at time 0?
// - Reference to NiPosData.
#define NI_POINT3_INTERPOLATOR_MEMBERS \
Vector3 point_3_value; \
uint data; \

#define NI_POINT3_INTERPOLATOR_GETATTR \
attr_ref attr = AInterpolator::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Point 3 Value" ) \
  return attr_ref(point_3_value); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_POINT3_INTERPOLATOR_PARENTS AInterpolator

#define NI_POINT3_INTERPOLATOR_CONSTRUCT

#define NI_POINT3_INTERPOLATOR_READ \
AInterpolator::Read( in, version ); \
NifStream( point_3_value, in, version ); \
NifStream( data, in, version ); \

#define NI_POINT3_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( point_3_value, out, version ); \
NifStream( data, out, version ); \

#define NI_POINT3_INTERPOLATOR_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AInterpolator::asString(); \
out << "       Point 3 Value:  " << point_3_value << endl; \
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
bool spawn_on_death; \
uint spawn_modifier; \

#define NI_P_SYS_AGE_DEATH_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Spawn on Death" ) \
  return attr_ref(spawn_on_death); \
if ( attr_name == "Spawn Modifier" ) \
  return attr_ref(spawn_modifier); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT

#define NI_P_SYS_AGE_DEATH_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( spawn_on_death, in, version ); \
NifStream( spawn_modifier, in, version ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( spawn_on_death, out, version ); \
NifStream( spawn_modifier, out, version ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "      Spawn on Death:  " << spawn_on_death << endl; \
out << "      Spawn Modifier:  " << spawn_modifier << endl; \
return out.str(); \

// 
// Unknown.
//
// - Link to a node.
// - Not sure, could be floats as well. Zero.
// - Unknown.
// - Unknown.
#define NI_P_SYS_BOMB_MODIFIER_MEMBERS \
uint unknown_link; \
vector<uint > unknown_ints_1; \
vector<float > unknown_floats; \
vector<uint > unknown_ints_2; \

#define NI_P_SYS_BOMB_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Link" ) \
  return attr_ref(unknown_link); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_BOMB_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_BOMB_MODIFIER_CONSTRUCT

#define NI_P_SYS_BOMB_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( unknown_link, in, version ); \
unknown_ints_1.resize(2); \
NifStream( unknown_ints_1, in, version ); \
unknown_floats.resize(3); \
NifStream( unknown_floats, in, version ); \
unknown_ints_2.resize(2); \
NifStream( unknown_ints_2, in, version ); \

#define NI_P_SYS_BOMB_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( unknown_link, out, version ); \
NifStream( unknown_ints_1, out, version ); \
NifStream( unknown_floats, out, version ); \
NifStream( unknown_ints_2, out, version ); \

#define NI_P_SYS_BOMB_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "        Unknown Link:  " << unknown_link << endl; \
out << "      Unknown Ints 1:  -- data not shown --" << endl; \
out << "      Unknown Floats:  -- data not shown --" << endl; \
out << "      Unknown Ints 2:  -- data not shown --" << endl; \
return out.str(); \

// 
// Unknown particle system modifier.
//
// - Unknown.
#define NI_P_SYS_BOUND_UPDATE_MODIFIER_MEMBERS \
ushort update_skip; \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Update Skip" ) \
  return attr_ref(update_skip); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_CONSTRUCT

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( update_skip, in, version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( update_skip, out, version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "         Update Skip:  " << update_skip << endl; \
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
uint collider; \

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
uint data; \

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
vector<vector<float > > unknown_floats_4; \
bool unknown_bool_1; \
vector<vector<byte > > unknown_bytes; \
vector<vector<byte > > unknown_bytes_alt; \
byte unknown_byte_3; \
bool unknown_bool_2; \
vector<vector<byte > > unknown_bytes_2; \
uint unknown_int_1; \

#define NI_P_SYS_DATA_GETATTR \
attr_ref attr = APSysData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Bool 1" ) \
  return attr_ref(unknown_bool_1); \
if ( attr_name == "Unknown Byte 3" ) \
  return attr_ref(unknown_byte_3); \
if ( attr_name == "Unknown Bool 2" ) \
  return attr_ref(unknown_bool_2); \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_DATA_PARENTS APSysData

#define NI_P_SYS_DATA_CONSTRUCT

#define NI_P_SYS_DATA_READ \
APSysData::Read( in, version ); \
if ( version <= 0x0A020000 ) { \
  unknown_floats_4.resize(num_vertices); \
  NifStream( unknown_floats_4, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknown_bool_1, in, version ); \
  if ( unknown_bool_1 != 0 ) { \
    unknown_bytes.resize(num_vertices); \
    NifStream( unknown_bytes, in, version ); \
  }; \
  if ( unknown_bool_1 == 0 ) { \
    unknown_bytes_alt.resize(num_vertices); \
    NifStream( unknown_bytes_alt, in, version ); \
  }; \
  NifStream( unknown_byte_3, in, version ); \
  NifStream( unknown_bool_2, in, version ); \
  if ( unknown_bool_2 != 0 ) { \
    unknown_bytes_2.resize(num_vertices); \
    NifStream( unknown_bytes_2, in, version ); \
  }; \
}; \
NifStream( unknown_int_1, in, version ); \

#define NI_P_SYS_DATA_WRITE \
APSysData::Write( out, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( unknown_floats_4, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
  NifStream( unknown_bool_1, out, version ); \
  if ( unknown_bool_1 != 0 ) { \
    NifStream( unknown_bytes, out, version ); \
  }; \
  if ( unknown_bool_1 == 0 ) { \
    NifStream( unknown_bytes_alt, out, version ); \
  }; \
  NifStream( unknown_byte_3, out, version ); \
  NifStream( unknown_bool_2, out, version ); \
  if ( unknown_bool_2 != 0 ) { \
    NifStream( unknown_bytes_2, out, version ); \
  }; \
}; \
NifStream( unknown_int_1, out, version ); \

#define NI_P_SYS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysData::asString(); \
out << "    Unknown Floats 4:  -- data not shown --" << endl; \
out << "      Unknown Bool 1:  " << unknown_bool_1 << endl; \
out << "       Unknown Bytes:  -- data not shown --" << endl; \
out << "   Unknown Bytes Alt:  -- data not shown --" << endl; \
out << "      Unknown Byte 3:  " << unknown_byte_3 << endl; \
out << "      Unknown Bool 2:  " << unknown_bool_2 << endl; \
out << "     Unknown Bytes 2:  -- data not shown --" << endl; \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
return out.str(); \

// 
// Unknown.
//
// - Parent reference.
// - Unknown floats.
#define NI_P_SYS_DRAG_MODIFIER_MEMBERS \
uint parent; \
vector<float > unknown_floats; \

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
unknown_floats.resize(6); \
NifStream( unknown_floats, in, version ); \

#define NI_P_SYS_DRAG_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( parent, out, version ); \
NifStream( unknown_floats, out, version ); \

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
uint data; \

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
VectorKeyArray<float > float_keys_; \
KeyArray<byte > visibility_keys_; \

#define NI_P_SYS_EMITTER_CTLR_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_EMITTER_CTLR_DATA_PARENTS AData

#define NI_P_SYS_EMITTER_CTLR_DATA_CONSTRUCT

#define NI_P_SYS_EMITTER_CTLR_DATA_READ \
AData::Read( in, version ); \
NifStream( float_keys_, in, version ); \
NifStream( visibility_keys_, in, version ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_WRITE \
AData::Write( out, version ); \
NifStream( float_keys_, out, version ); \
NifStream( visibility_keys_, out, version ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "         Float Keys?:  " << float_keys_ << endl; \
out << "    Visibility Keys?:  " << visibility_keys_ << endl; \
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
uint gravity_object; \
Vector3 gravity_axis; \
float decay; \
float strength; \
float turbulence; \
float turbulence_scale; \
float force_type; \

#define NI_P_SYS_GRAVITY_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Gravity Object" ) \
  return attr_ref(gravity_object); \
if ( attr_name == "Gravity Axis" ) \
  return attr_ref(gravity_axis); \
if ( attr_name == "Decay" ) \
  return attr_ref(decay); \
if ( attr_name == "Strength" ) \
  return attr_ref(strength); \
if ( attr_name == "Turbulence" ) \
  return attr_ref(turbulence); \
if ( attr_name == "Turbulence Scale" ) \
  return attr_ref(turbulence_scale); \
if ( attr_name == "Force Type" ) \
  return attr_ref(force_type); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_GRAVITY_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_GRAVITY_MODIFIER_CONSTRUCT

#define NI_P_SYS_GRAVITY_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( gravity_object, in, version ); \
NifStream( gravity_axis, in, version ); \
NifStream( decay, in, version ); \
NifStream( strength, in, version ); \
NifStream( turbulence, in, version ); \
NifStream( turbulence_scale, in, version ); \
NifStream( force_type, in, version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( gravity_object, out, version ); \
NifStream( gravity_axis, out, version ); \
NifStream( decay, out, version ); \
NifStream( strength, out, version ); \
NifStream( turbulence, out, version ); \
NifStream( turbulence_scale, out, version ); \
NifStream( force_type, out, version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "      Gravity Object:  " << gravity_object << endl; \
out << "        Gravity Axis:  " << gravity_axis << endl; \
out << "               Decay:  " << decay << endl; \
out << "            Strength:  " << strength << endl; \
out << "          Turbulence:  " << turbulence << endl; \
out << "    Turbulence Scale:  " << turbulence_scale << endl; \
out << "          Force Type:  " << force_type << endl; \
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
float grow_time; \
ushort grow_generation; \
float fade_time; \
ushort fade_generation; \

#define NI_P_SYS_GROW_FADE_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Grow Time" ) \
  return attr_ref(grow_time); \
if ( attr_name == "Grow Generation" ) \
  return attr_ref(grow_generation); \
if ( attr_name == "Fade Time" ) \
  return attr_ref(fade_time); \
if ( attr_name == "Fade Generation" ) \
  return attr_ref(fade_generation); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_GROW_FADE_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_GROW_FADE_MODIFIER_CONSTRUCT

#define NI_P_SYS_GROW_FADE_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( grow_time, in, version ); \
NifStream( grow_generation, in, version ); \
NifStream( fade_time, in, version ); \
NifStream( fade_generation, in, version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( grow_time, out, version ); \
NifStream( grow_generation, out, version ); \
NifStream( fade_time, out, version ); \
NifStream( fade_generation, out, version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "           Grow Time:  " << grow_time << endl; \
out << "     Grow Generation:  " << grow_generation << endl; \
out << "           Fade Time:  " << fade_time << endl; \
out << "     Fade Generation:  " << fade_generation << endl; \
return out.str(); \

// 
// Unknown.
//
// - Unknown.
// - Unknown.
// - Unknown.
// - Unknown.
#define NI_P_SYS_MESH_EMITTER_MEMBERS \
LinkGroup unknown_link_group; \
vector<uint > unknown_ints_1; \
float unknown_float; \
vector<uint > unknown_ints_2; \

#define NI_P_SYS_MESH_EMITTER_GETATTR \
attr_ref attr = APSysEmitter::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknown_float); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_MESH_EMITTER_PARENTS APSysEmitter

#define NI_P_SYS_MESH_EMITTER_CONSTRUCT

#define NI_P_SYS_MESH_EMITTER_READ \
APSysEmitter::Read( in, version ); \
NifStream( unknown_link_group, in, version ); \
unknown_ints_1.resize(2); \
NifStream( unknown_ints_1, in, version ); \
NifStream( unknown_float, in, version ); \
unknown_ints_2.resize(2); \
NifStream( unknown_ints_2, in, version ); \

#define NI_P_SYS_MESH_EMITTER_WRITE \
APSysEmitter::Write( out, version ); \
NifStream( unknown_link_group, out, version ); \
NifStream( unknown_ints_1, out, version ); \
NifStream( unknown_float, out, version ); \
NifStream( unknown_ints_2, out, version ); \

#define NI_P_SYS_MESH_EMITTER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysEmitter::asString(); \
out << "  Unknown Link Group:  " << unknown_link_group << endl; \
out << "      Unknown Ints 1:  -- data not shown --" << endl; \
out << "       Unknown Float:  " << unknown_float << endl; \
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
bool spawn_on_collide; \
bool die_on_collide; \
uint spawn_modifier; \
uint parent; \
uint unknown_link_; \
uint collider_object; \
float width; \
float height; \
Vector3 x_axis; \
Vector3 y_axis; \

#define NI_P_SYS_PLANAR_COLLIDER_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Bounce" ) \
  return attr_ref(bounce); \
if ( attr_name == "Spawn on Collide" ) \
  return attr_ref(spawn_on_collide); \
if ( attr_name == "Die on Collide" ) \
  return attr_ref(die_on_collide); \
if ( attr_name == "Spawn Modifier" ) \
  return attr_ref(spawn_modifier); \
if ( attr_name == "Parent" ) \
  return attr_ref(parent); \
if ( attr_name == "Unknown Link?" ) \
  return attr_ref(unknown_link_); \
if ( attr_name == "Collider Object" ) \
  return attr_ref(collider_object); \
if ( attr_name == "Width" ) \
  return attr_ref(width); \
if ( attr_name == "Height" ) \
  return attr_ref(height); \
if ( attr_name == "X Axis" ) \
  return attr_ref(x_axis); \
if ( attr_name == "Y Axis" ) \
  return attr_ref(y_axis); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_PLANAR_COLLIDER_PARENTS AData

#define NI_P_SYS_PLANAR_COLLIDER_CONSTRUCT

#define NI_P_SYS_PLANAR_COLLIDER_READ \
AData::Read( in, version ); \
NifStream( bounce, in, version ); \
NifStream( spawn_on_collide, in, version ); \
NifStream( die_on_collide, in, version ); \
NifStream( spawn_modifier, in, version ); \
NifStream( parent, in, version ); \
NifStream( unknown_link_, in, version ); \
NifStream( collider_object, in, version ); \
NifStream( width, in, version ); \
NifStream( height, in, version ); \
NifStream( x_axis, in, version ); \
NifStream( y_axis, in, version ); \

#define NI_P_SYS_PLANAR_COLLIDER_WRITE \
AData::Write( out, version ); \
NifStream( bounce, out, version ); \
NifStream( spawn_on_collide, out, version ); \
NifStream( die_on_collide, out, version ); \
NifStream( spawn_modifier, out, version ); \
NifStream( parent, out, version ); \
NifStream( unknown_link_, out, version ); \
NifStream( collider_object, out, version ); \
NifStream( width, out, version ); \
NifStream( height, out, version ); \
NifStream( x_axis, out, version ); \
NifStream( y_axis, out, version ); \

#define NI_P_SYS_PLANAR_COLLIDER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "              Bounce:  " << bounce << endl; \
out << "    Spawn on Collide:  " << spawn_on_collide << endl; \
out << "      Die on Collide:  " << die_on_collide << endl; \
out << "      Spawn Modifier:  " << spawn_modifier << endl; \
out << "              Parent:  " << parent << endl; \
out << "       Unknown Link?:  " << unknown_link_ << endl; \
out << "     Collider Object:  " << collider_object << endl; \
out << "               Width:  " << width << endl; \
out << "              Height:  " << height << endl; \
out << "              X Axis:  " << x_axis << endl; \
out << "              Y Axis:  " << y_axis << endl; \
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
float initial_rotation_speed; \
float initial_rotation_speed_variation; \
float initial_rotation_angle; \
float initial_rotation_angle_variation; \
bool random_rot_speed_sign; \
bool random_initial_axis; \
Vector3 initial_axis; \

#define NI_P_SYS_ROTATION_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Initial Rotation Speed" ) \
  return attr_ref(initial_rotation_speed); \
if ( attr_name == "Initial Rotation Speed Variation" ) \
  return attr_ref(initial_rotation_speed_variation); \
if ( attr_name == "Initial Rotation Angle" ) \
  return attr_ref(initial_rotation_angle); \
if ( attr_name == "Initial Rotation Angle Variation" ) \
  return attr_ref(initial_rotation_angle_variation); \
if ( attr_name == "Random Rot Speed Sign" ) \
  return attr_ref(random_rot_speed_sign); \
if ( attr_name == "Random Initial Axis" ) \
  return attr_ref(random_initial_axis); \
if ( attr_name == "Initial Axis" ) \
  return attr_ref(initial_axis); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_ROTATION_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_ROTATION_MODIFIER_CONSTRUCT

#define NI_P_SYS_ROTATION_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( initial_rotation_speed, in, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( initial_rotation_speed_variation, in, version ); \
  NifStream( initial_rotation_angle, in, version ); \
  NifStream( initial_rotation_angle_variation, in, version ); \
  NifStream( random_rot_speed_sign, in, version ); \
}; \
NifStream( random_initial_axis, in, version ); \
NifStream( initial_axis, in, version ); \

#define NI_P_SYS_ROTATION_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( initial_rotation_speed, out, version ); \
if ( version >= 0x14000004 ) { \
  NifStream( initial_rotation_speed_variation, out, version ); \
  NifStream( initial_rotation_angle, out, version ); \
  NifStream( initial_rotation_angle_variation, out, version ); \
  NifStream( random_rot_speed_sign, out, version ); \
}; \
NifStream( random_initial_axis, out, version ); \
NifStream( initial_axis, out, version ); \

#define NI_P_SYS_ROTATION_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "Initial Rotation Speed:  " << initial_rotation_speed << endl; \
out << "Initial Rotation Speed Variation:  " << initial_rotation_speed_variation << endl; \
out << "Initial Rotation Angle:  " << initial_rotation_angle << endl; \
out << "Initial Rotation Angle Variation:  " << initial_rotation_angle_variation << endl; \
out << "Random Rot Speed Sign:  " << random_rot_speed_sign << endl; \
out << " Random Initial Axis:  " << random_initial_axis << endl; \
out << "        Initial Axis:  " << initial_axis << endl; \
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
ushort num_spawn_generations; \
float percentage_spawned; \
ushort min_num_to_spawn; \
ushort max_num_to_spawn; \
float spawn_speed_chaos; \
float spawn_dir_chaos; \
float life_span; \
float life_span_variation; \

#define NI_P_SYS_SPAWN_MODIFIER_GETATTR \
attr_ref attr = APSysModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Spawn Generations" ) \
  return attr_ref(num_spawn_generations); \
if ( attr_name == "Percentage Spawned" ) \
  return attr_ref(percentage_spawned); \
if ( attr_name == "Min Num to Spawn" ) \
  return attr_ref(min_num_to_spawn); \
if ( attr_name == "Max Num to Spawn" ) \
  return attr_ref(max_num_to_spawn); \
if ( attr_name == "Spawn Speed Chaos" ) \
  return attr_ref(spawn_speed_chaos); \
if ( attr_name == "Spawn Dir Chaos" ) \
  return attr_ref(spawn_dir_chaos); \
if ( attr_name == "Life Span" ) \
  return attr_ref(life_span); \
if ( attr_name == "Life Span Variation" ) \
  return attr_ref(life_span_variation); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_P_SYS_SPAWN_MODIFIER_PARENTS APSysModifier

#define NI_P_SYS_SPAWN_MODIFIER_CONSTRUCT

#define NI_P_SYS_SPAWN_MODIFIER_READ \
APSysModifier::Read( in, version ); \
NifStream( num_spawn_generations, in, version ); \
NifStream( percentage_spawned, in, version ); \
NifStream( min_num_to_spawn, in, version ); \
NifStream( max_num_to_spawn, in, version ); \
NifStream( spawn_speed_chaos, in, version ); \
NifStream( spawn_dir_chaos, in, version ); \
NifStream( life_span, in, version ); \
NifStream( life_span_variation, in, version ); \

#define NI_P_SYS_SPAWN_MODIFIER_WRITE \
APSysModifier::Write( out, version ); \
NifStream( num_spawn_generations, out, version ); \
NifStream( percentage_spawned, out, version ); \
NifStream( min_num_to_spawn, out, version ); \
NifStream( max_num_to_spawn, out, version ); \
NifStream( spawn_speed_chaos, out, version ); \
NifStream( spawn_dir_chaos, out, version ); \
NifStream( life_span, out, version ); \
NifStream( life_span_variation, out, version ); \

#define NI_P_SYS_SPAWN_MODIFIER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APSysModifier::asString(); \
out << "Num Spawn Generations:  " << num_spawn_generations << endl; \
out << "  Percentage Spawned:  " << percentage_spawned << endl; \
out << "    Min Num to Spawn:  " << min_num_to_spawn << endl; \
out << "    Max Num to Spawn:  " << max_num_to_spawn << endl; \
out << "   Spawn Speed Chaos:  " << spawn_speed_chaos << endl; \
out << "     Spawn Dir Chaos:  " << spawn_dir_chaos << endl; \
out << "           Life Span:  " << life_span << endl; \
out << " Life Span Variation:  " << life_span_variation << endl; \
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
Vector3 lod_center; \
vector<LODRange > lod_levels; \

#define NI_RANGE_L_O_D_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "LOD Center" ) \
  return attr_ref(lod_center); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_RANGE_L_O_D_DATA_PARENTS AData

#define NI_RANGE_L_O_D_DATA_CONSTRUCT

#define NI_RANGE_L_O_D_DATA_READ \
uint num_lod_levels; \
AData::Read( in, version ); \
NifStream( lod_center, in, version ); \
NifStream( num_lod_levels, in, version ); \
lod_levels.resize(num_lod_levels); \
NifStream( lod_levels, in, version ); \

#define NI_RANGE_L_O_D_DATA_WRITE \
uint num_lod_levels; \
AData::Write( out, version ); \
num_lod_levels = uint(lod_levels.size()); \
NifStream( lod_center, out, version ); \
NifStream( num_lod_levels, out, version ); \
NifStream( lod_levels, out, version ); \

#define NI_RANGE_L_O_D_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "          LOD Center:  " << lod_center << endl; \
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
vector<float > unknown_floats; \
vector<float > unknown_floats_2; \

#define NI_SCREEN_L_O_D_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SCREEN_L_O_D_DATA_PARENTS AData

#define NI_SCREEN_L_O_D_DATA_CONSTRUCT

#define NI_SCREEN_L_O_D_DATA_READ \
uint unknown_count; \
AData::Read( in, version ); \
unknown_floats.resize(8); \
NifStream( unknown_floats, in, version ); \
NifStream( unknown_count, in, version ); \
unknown_floats_2.resize(unknown_count); \
NifStream( unknown_floats_2, in, version ); \

#define NI_SCREEN_L_O_D_DATA_WRITE \
uint unknown_count; \
AData::Write( out, version ); \
unknown_count = uint(unknown_floats_2.size()); \
NifStream( unknown_floats, out, version ); \
NifStream( unknown_count, out, version ); \
NifStream( unknown_floats_2, out, version ); \

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
uint skin_partition; \
byte unknown_byte; \
vector<SkinData > bone_list; \

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
  return attr_ref(skin_partition); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SKIN_DATA_PARENTS AData

#define NI_SKIN_DATA_CONSTRUCT

#define NI_SKIN_DATA_READ \
uint num_bones; \
AData::Read( in, version ); \
NifStream( rotation, in, version ); \
NifStream( translation, in, version ); \
NifStream( scale, in, version ); \
NifStream( num_bones, in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( skin_partition, in, version ); \
}; \
if ( version >= 0x04020100 ) { \
  NifStream( unknown_byte, in, version ); \
}; \
bone_list.resize(num_bones); \
NifStream( bone_list, in, version ); \

#define NI_SKIN_DATA_WRITE \
uint num_bones; \
AData::Write( out, version ); \
num_bones = uint(bone_list.size()); \
NifStream( rotation, out, version ); \
NifStream( translation, out, version ); \
NifStream( scale, out, version ); \
NifStream( num_bones, out, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( skin_partition, out, version ); \
}; \
if ( version >= 0x04020100 ) { \
  NifStream( unknown_byte, out, version ); \
}; \
NifStream( bone_list, out, version ); \

#define NI_SKIN_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "            Rotation:  " << rotation << endl; \
out << "         Translation:  " << translation << endl; \
out << "               Scale:  " << scale << endl; \
out << "           Num Bones:  -- calculated --" << endl; \
out << "      Skin Partition:  " << skin_partition << endl; \
out << "        Unknown Byte:  " << unknown_byte << endl; \
out << "           Bone List:  -- data not shown --" << endl; \
return out.str(); \

// 
// Skinning instance.
//
// - Skinning data reference.
// - Refers to a NiSkinPartition block, which partitions the mesh such that every vertex is only influenced by a limited number of bones.
// - List of all armature bones.
#define NI_SKIN_INSTANCE_MEMBERS \
uint data; \
uint skin_partition; \
Bones bones; \

#define NI_SKIN_INSTANCE_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
if ( attr_name == "Skin Partition" ) \
  return attr_ref(skin_partition); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SKIN_INSTANCE_PARENTS AData

#define NI_SKIN_INSTANCE_CONSTRUCT

#define NI_SKIN_INSTANCE_READ \
uint skeleton_root; \
AData::Read( in, version ); \
NifStream( data, in, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( skin_partition, in, version ); \
}; \
NifStream( bones, in, version ); \

#define NI_SKIN_INSTANCE_WRITE \
uint skeleton_root; \
AData::Write( out, version ); \
skeleton_root = SkeletonRoot(); \
NifStream( data, out, version ); \
if ( version >= 0x0A020000 ) { \
  NifStream( skin_partition, out, version ); \
}; \
NifStream( bones, out, version ); \

#define NI_SKIN_INSTANCE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AData::asString(); \
out << "                Data:  " << data << endl; \
out << "      Skin Partition:  " << skin_partition << endl; \
out << "       Skeleton Root:  -- calculated --" << endl; \
out << "               Bones:  " << bones << endl; \
return out.str(); \

// 
// Skinning data, optimized for hardware skinning. The mesh is partitioned in submeshes such that each vertex of a submesh is influenced only by a limited and fixed number of bones.
//
// - Skin partition blocks.
#define NI_SKIN_PARTITION_MEMBERS \
vector<SkinPartition > skin_partition_blocks; \

#define NI_SKIN_PARTITION_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SKIN_PARTITION_PARENTS AData

#define NI_SKIN_PARTITION_CONSTRUCT

#define NI_SKIN_PARTITION_READ \
uint num_skin_partition_blocks; \
AData::Read( in, version ); \
NifStream( num_skin_partition_blocks, in, version ); \
skin_partition_blocks.resize(num_skin_partition_blocks); \
NifStream( skin_partition_blocks, in, version ); \

#define NI_SKIN_PARTITION_WRITE \
uint num_skin_partition_blocks; \
AData::Write( out, version ); \
num_skin_partition_blocks = uint(skin_partition_blocks.size()); \
NifStream( num_skin_partition_blocks, out, version ); \
NifStream( skin_partition_blocks, out, version ); \

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
TexSource texture_source; \
PixelLayout pixel_layout; \
MipMapFormat use_mipmaps; \
AlphaFormat alpha_format; \
byte unknown_byte; \
byte unknown_byte_2; \

#define NI_SOURCE_TEXTURE_GETATTR \
attr_ref attr = AControllable::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Texture Source" ) \
  return attr_ref(texture_source); \
if ( attr_name == "Pixel Layout" ) \
  return attr_ref(pixel_layout); \
if ( attr_name == "Use Mipmaps" ) \
  return attr_ref(use_mipmaps); \
if ( attr_name == "Alpha Format" ) \
  return attr_ref(alpha_format); \
if ( attr_name == "Unknown Byte" ) \
  return attr_ref(unknown_byte); \
if ( attr_name == "Unknown Byte 2" ) \
  return attr_ref(unknown_byte_2); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SOURCE_TEXTURE_PARENTS AControllable

#define NI_SOURCE_TEXTURE_CONSTRUCT

#define NI_SOURCE_TEXTURE_READ \
AControllable::Read( in, version ); \
NifStream( texture_source, in, version ); \
NifStream( pixel_layout, in, version ); \
NifStream( use_mipmaps, in, version ); \
NifStream( alpha_format, in, version ); \
NifStream( unknown_byte, in, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_byte_2, in, version ); \
}; \

#define NI_SOURCE_TEXTURE_WRITE \
AControllable::Write( out, version ); \
NifStream( texture_source, out, version ); \
NifStream( pixel_layout, out, version ); \
NifStream( use_mipmaps, out, version ); \
NifStream( alpha_format, out, version ); \
NifStream( unknown_byte, out, version ); \
if ( version >= 0x0A01006A ) { \
  NifStream( unknown_byte_2, out, version ); \
}; \

#define NI_SOURCE_TEXTURE_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AControllable::asString(); \
out << "      Texture Source:  " << texture_source << endl; \
out << "        Pixel Layout:  " << pixel_layout << endl; \
out << "         Use Mipmaps:  " << use_mipmaps << endl; \
out << "        Alpha Format:  " << alpha_format << endl; \
out << "        Unknown Byte:  " << unknown_byte << endl; \
out << "      Unknown Byte 2:  " << unknown_byte_2 << endl; \
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
float unknown_float_1; \
ushort unknown_short; \
float unknown_float_2; \
float unknown_float_3; \
float unknown_float_4; \
float unknown_float_5; \

#define NI_SPHERICAL_COLLIDER_GETATTR \
attr_ref attr = AParticleModifier::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Float 1" ) \
  return attr_ref(unknown_float_1); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Unknown Float 2" ) \
  return attr_ref(unknown_float_2); \
if ( attr_name == "Unknown Float 3" ) \
  return attr_ref(unknown_float_3); \
if ( attr_name == "Unknown Float 4" ) \
  return attr_ref(unknown_float_4); \
if ( attr_name == "Unknown Float 5" ) \
  return attr_ref(unknown_float_5); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SPHERICAL_COLLIDER_PARENTS AParticleModifier

#define NI_SPHERICAL_COLLIDER_CONSTRUCT

#define NI_SPHERICAL_COLLIDER_READ \
AParticleModifier::Read( in, version ); \
NifStream( unknown_float_1, in, version ); \
NifStream( unknown_short, in, version ); \
NifStream( unknown_float_2, in, version ); \
NifStream( unknown_float_3, in, version ); \
NifStream( unknown_float_4, in, version ); \
NifStream( unknown_float_5, in, version ); \

#define NI_SPHERICAL_COLLIDER_WRITE \
AParticleModifier::Write( out, version ); \
NifStream( unknown_float_1, out, version ); \
NifStream( unknown_short, out, version ); \
NifStream( unknown_float_2, out, version ); \
NifStream( unknown_float_3, out, version ); \
NifStream( unknown_float_4, out, version ); \
NifStream( unknown_float_5, out, version ); \

#define NI_SPHERICAL_COLLIDER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AParticleModifier::asString(); \
out << "     Unknown Float 1:  " << unknown_float_1 << endl; \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "     Unknown Float 2:  " << unknown_float_2 << endl; \
out << "     Unknown Float 3:  " << unknown_float_3 << endl; \
out << "     Unknown Float 4:  " << unknown_float_4 << endl; \
out << "     Unknown Float 5:  " << unknown_float_5 << endl; \
return out.str(); \

// 
// A spot.
//
// - The opening angle of the spot.
// - Describes the distribution of light. (see: glLight)
#define NI_SPOT_LIGHT_MEMBERS \
float cutoff_angle; \
float exponent; \

#define NI_SPOT_LIGHT_GETATTR \
attr_ref attr = APointLight::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Cutoff Angle" ) \
  return attr_ref(cutoff_angle); \
if ( attr_name == "Exponent" ) \
  return attr_ref(exponent); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_SPOT_LIGHT_PARENTS APointLight

#define NI_SPOT_LIGHT_CONSTRUCT

#define NI_SPOT_LIGHT_READ \
APointLight::Read( in, version ); \
NifStream( cutoff_angle, in, version ); \
NifStream( exponent, in, version ); \

#define NI_SPOT_LIGHT_WRITE \
APointLight::Write( out, version ); \
NifStream( cutoff_angle, out, version ); \
NifStream( exponent, out, version ); \

#define NI_SPOT_LIGHT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << APointLight::asString(); \
out << "        Cutoff Angle:  " << cutoff_angle << endl; \
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
bool stencil_enabled; \
uint stencil_function; \
uint stencil_ref; \
uint stencil_mask; \
uint fail_action; \
uint z_fail_action; \
uint pass_action; \
uint draw_mode; \

#define NI_STENCIL_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Stencil Enabled" ) \
  return attr_ref(stencil_enabled); \
if ( attr_name == "Stencil Function" ) \
  return attr_ref(stencil_function); \
if ( attr_name == "Stencil Ref" ) \
  return attr_ref(stencil_ref); \
if ( attr_name == "Stencil Mask" ) \
  return attr_ref(stencil_mask); \
if ( attr_name == "Fail Action" ) \
  return attr_ref(fail_action); \
if ( attr_name == "Z Fail Action" ) \
  return attr_ref(z_fail_action); \
if ( attr_name == "Pass Action" ) \
  return attr_ref(pass_action); \
if ( attr_name == "Draw Mode" ) \
  return attr_ref(draw_mode); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_STENCIL_PROPERTY_PARENTS AProperty

#define NI_STENCIL_PROPERTY_CONSTRUCT

#define NI_STENCIL_PROPERTY_READ \
AProperty::Read( in, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, in, version ); \
}; \
NifStream( stencil_enabled, in, version ); \
NifStream( stencil_function, in, version ); \
NifStream( stencil_ref, in, version ); \
NifStream( stencil_mask, in, version ); \
NifStream( fail_action, in, version ); \
NifStream( z_fail_action, in, version ); \
NifStream( pass_action, in, version ); \
NifStream( draw_mode, in, version ); \

#define NI_STENCIL_PROPERTY_WRITE \
AProperty::Write( out, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, out, version ); \
}; \
NifStream( stencil_enabled, out, version ); \
NifStream( stencil_function, out, version ); \
NifStream( stencil_ref, out, version ); \
NifStream( stencil_mask, out, version ); \
NifStream( fail_action, out, version ); \
NifStream( z_fail_action, out, version ); \
NifStream( pass_action, out, version ); \
NifStream( draw_mode, out, version ); \

#define NI_STENCIL_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "     Stencil Enabled:  " << stencil_enabled << endl; \
out << "    Stencil Function:  " << stencil_function << endl; \
out << "         Stencil Ref:  " << stencil_ref << endl; \
out << "        Stencil Mask:  " << stencil_mask << endl; \
out << "         Fail Action:  " << fail_action << endl; \
out << "       Z Fail Action:  " << z_fail_action << endl; \
out << "         Pass Action:  " << pass_action << endl; \
out << "           Draw Mode:  " << draw_mode << endl; \
return out.str(); \

// 
// Apparently commands for an optimizer instructing it to keep things it would normally discard.
// Also refers to NiNode blocks (through their name) in animation .kf files.
//
// - The string.
#define NI_STRING_EXTRA_DATA_MEMBERS \
string string_data; \

#define NI_STRING_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "String Data" ) \
  return attr_ref(string_data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_STRING_EXTRA_DATA_PARENTS AExtraData

#define NI_STRING_EXTRA_DATA_CONSTRUCT

#define NI_STRING_EXTRA_DATA_READ \
uint bytes_remaining; \
AExtraData::Read( in, version ); \
NifStream( string_data, in, version ); \

#define NI_STRING_EXTRA_DATA_WRITE \
uint bytes_remaining; \
AExtraData::Write( out, version ); \
bytes_remaining = BytesRemaining(); \
NifStream( string_data, out, version ); \

#define NI_STRING_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "     Bytes Remaining:  -- calculated --" << endl; \
out << "         String Data:  " << string_data << endl; \
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
uint num_strings; \
AExtraData::Read( in, version ); \
NifStream( num_strings, in, version ); \
data.resize(num_strings); \
NifStream( data, in, version ); \

#define NI_STRINGS_EXTRA_DATA_WRITE \
uint num_strings; \
AExtraData::Write( out, version ); \
num_strings = uint(data.size()); \
NifStream( num_strings, out, version ); \
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
uint unknown_int_1; \
KeyArray<string > text_keys; \

#define NI_TEXT_KEY_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Int 1" ) \
  return attr_ref(unknown_int_1); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TEXT_KEY_EXTRA_DATA_PARENTS AExtraData

#define NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT

#define NI_TEXT_KEY_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( unknown_int_1, in, version ); \
}; \
NifStream( text_keys, in, version ); \

#define NI_TEXT_KEY_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
if ( version <= 0x04020200 ) { \
  NifStream( unknown_int_1, out, version ); \
}; \
NifStream( text_keys, out, version ); \

#define NI_TEXT_KEY_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "       Unknown Int 1:  " << unknown_int_1 << endl; \
out << "           Text Keys:  " << text_keys << endl; \
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
Matrix33 model_projection_matrix; \
Vector3 model_projection_transform; \
uint texture_filtering; \
uint texture_clamping; \
uint texture_type; \
uint coordinate_generation_type; \
uint source_texture; \
byte clipping_plane; \
Vector3 unknown_vector; \
float unknown_float; \
ushort ps2_l; \
ushort ps2_k; \
ushort unknown_short; \

#define NI_TEXTURE_EFFECT_GETATTR \
attr_ref attr = ADynamicEffect::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Model Projection Matrix" ) \
  return attr_ref(model_projection_matrix); \
if ( attr_name == "Model Projection Transform" ) \
  return attr_ref(model_projection_transform); \
if ( attr_name == "Texture Filtering" ) \
  return attr_ref(texture_filtering); \
if ( attr_name == "Texture Clamping" ) \
  return attr_ref(texture_clamping); \
if ( attr_name == "Texture Type" ) \
  return attr_ref(texture_type); \
if ( attr_name == "Coordinate Generation Type" ) \
  return attr_ref(coordinate_generation_type); \
if ( attr_name == "Source Texture" ) \
  return attr_ref(source_texture); \
if ( attr_name == "Clipping Plane" ) \
  return attr_ref(clipping_plane); \
if ( attr_name == "Unknown Vector" ) \
  return attr_ref(unknown_vector); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknown_float); \
if ( attr_name == "PS2 L" ) \
  return attr_ref(ps2_l); \
if ( attr_name == "PS2 K" ) \
  return attr_ref(ps2_k); \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TEXTURE_EFFECT_PARENTS ADynamicEffect

#define NI_TEXTURE_EFFECT_CONSTRUCT

#define NI_TEXTURE_EFFECT_READ \
ADynamicEffect::Read( in, version ); \
NifStream( model_projection_matrix, in, version ); \
NifStream( model_projection_transform, in, version ); \
NifStream( texture_filtering, in, version ); \
NifStream( texture_clamping, in, version ); \
NifStream( texture_type, in, version ); \
NifStream( coordinate_generation_type, in, version ); \
NifStream( source_texture, in, version ); \
NifStream( clipping_plane, in, version ); \
NifStream( unknown_vector, in, version ); \
NifStream( unknown_float, in, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( ps2_l, in, version ); \
  NifStream( ps2_k, in, version ); \
}; \
if ( version <= 0x0401000C ) { \
  NifStream( unknown_short, in, version ); \
}; \

#define NI_TEXTURE_EFFECT_WRITE \
ADynamicEffect::Write( out, version ); \
NifStream( model_projection_matrix, out, version ); \
NifStream( model_projection_transform, out, version ); \
NifStream( texture_filtering, out, version ); \
NifStream( texture_clamping, out, version ); \
NifStream( texture_type, out, version ); \
NifStream( coordinate_generation_type, out, version ); \
NifStream( source_texture, out, version ); \
NifStream( clipping_plane, out, version ); \
NifStream( unknown_vector, out, version ); \
NifStream( unknown_float, out, version ); \
if ( version <= 0x0A020000 ) { \
  NifStream( ps2_l, out, version ); \
  NifStream( ps2_k, out, version ); \
}; \
if ( version <= 0x0401000C ) { \
  NifStream( unknown_short, out, version ); \
}; \

#define NI_TEXTURE_EFFECT_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << ADynamicEffect::asString(); \
out << "Model Projection Matrix:  " << model_projection_matrix << endl; \
out << "Model Projection Transform:  " << model_projection_transform << endl; \
out << "   Texture Filtering:  " << texture_filtering << endl; \
out << "    Texture Clamping:  " << texture_clamping << endl; \
out << "        Texture Type:  " << texture_type << endl; \
out << "Coordinate Generation Type:  " << coordinate_generation_type << endl; \
out << "      Source Texture:  " << source_texture << endl; \
out << "      Clipping Plane:  " << clipping_plane << endl; \
out << "      Unknown Vector:  " << unknown_vector << endl; \
out << "       Unknown Float:  " << unknown_float << endl; \
out << "               PS2 L:  " << ps2_l << endl; \
out << "               PS2 K:  " << ps2_k << endl; \
out << "       Unknown Short:  " << unknown_short << endl; \
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
uint texture_slot; \
uint operation; \
uint data; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_GETATTR \
attr_ref attr = ASingleInterpolatorController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown2" ) \
  return attr_ref(unknown2); \
if ( attr_name == "Texture Slot" ) \
  return attr_ref(texture_slot); \
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
NifStream( texture_slot, in, version ); \
NifStream( operation, in, version ); \
if ( version <= 0x0A010000 ) { \
  NifStream( data, in, version ); \
}; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_WRITE \
ASingleInterpolatorController::Write( out, version ); \
NifStream( unknown2, out, version ); \
NifStream( texture_slot, out, version ); \
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
out << "        Texture Slot:  " << texture_slot << endl; \
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
ApplyMode apply_mode; \
uint texture_count; \
Texture base_texture; \
Texture dark_texture; \
Texture detail_texture; \
Texture gloss_texture; \
Texture glow_texture; \
BumpMap bump_map_texture; \
Texture decal_0_texture; \
Texture decal_texture_1; \
ExtraTextureGroup shader_textures; \

#define NI_TEXTURING_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Apply Mode" ) \
  return attr_ref(apply_mode); \
if ( attr_name == "Texture Count" ) \
  return attr_ref(texture_count); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TEXTURING_PROPERTY_PARENTS AProperty

#define NI_TEXTURING_PROPERTY_CONSTRUCT apply_mode(2), texture_count(7)

#define NI_TEXTURING_PROPERTY_READ \
AProperty::Read( in, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, in, version ); \
}; \
NifStream( apply_mode, in, version ); \
NifStream( texture_count, in, version ); \
NifStream( base_texture, in, version ); \
NifStream( dark_texture, in, version ); \
NifStream( detail_texture, in, version ); \
NifStream( gloss_texture, in, version ); \
NifStream( glow_texture, in, version ); \
NifStream( bump_map_texture, in, version ); \
NifStream( decal_0_texture, in, version ); \
if ( version >= 0x14000004 ) { \
  if ( texture_count == 8 ) { \
    NifStream( decal_texture_1, in, version ); \
  }; \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( shader_textures, in, version ); \
}; \

#define NI_TEXTURING_PROPERTY_WRITE \
AProperty::Write( out, version ); \
if ( version <= 0x0A000102 ) { \
  NifStream( flags, out, version ); \
}; \
NifStream( apply_mode, out, version ); \
NifStream( texture_count, out, version ); \
NifStream( base_texture, out, version ); \
NifStream( dark_texture, out, version ); \
NifStream( detail_texture, out, version ); \
NifStream( gloss_texture, out, version ); \
NifStream( glow_texture, out, version ); \
NifStream( bump_map_texture, out, version ); \
NifStream( decal_0_texture, out, version ); \
if ( version >= 0x14000004 ) { \
  if ( texture_count == 8 ) { \
    NifStream( decal_texture_1, out, version ); \
  }; \
}; \
if ( version >= 0x0A000100 ) { \
  NifStream( shader_textures, out, version ); \
}; \

#define NI_TEXTURING_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "          Apply Mode:  " << apply_mode << endl; \
out << "       Texture Count:  " << texture_count << endl; \
out << "        Base Texture:  " << base_texture << endl; \
out << "        Dark Texture:  " << dark_texture << endl; \
out << "      Detail Texture:  " << detail_texture << endl; \
out << "       Gloss Texture:  " << gloss_texture << endl; \
out << "        Glow Texture:  " << glow_texture << endl; \
out << "    Bump Map Texture:  " << bump_map_texture << endl; \
out << "     Decal 0 Texture:  " << decal_0_texture << endl; \
out << "     Decal Texture 1:  " << decal_texture_1 << endl; \
out << "     Shader Textures:  " << shader_textures << endl; \
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
vector<byte > unknown_bytes; \
uint data; \

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
  unknown_bytes.resize(3); \
  NifStream( unknown_bytes, in, version ); \
}; \
NifStream( data, in, version ); \

#define NI_TRANSFORM_INTERPOLATOR_WRITE \
AInterpolator::Write( out, version ); \
NifStream( translation, out, version ); \
NifStream( rotation, out, version ); \
NifStream( scale, out, version ); \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
  NifStream( unknown_bytes, out, version ); \
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
uint num_triangle_points; \
bool has_triangles; \
vector<Triangle > triangles; \
vector<MatchGroup > match_groups; \

#define NI_TRI_SHAPE_DATA_GETATTR \
attr_ref attr = AShapeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Triangle Points" ) \
  return attr_ref(num_triangle_points); \
if ( attr_name == "Has Triangles" ) \
  return attr_ref(has_triangles); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRI_SHAPE_DATA_PARENTS AShapeData

#define NI_TRI_SHAPE_DATA_CONSTRUCT

#define NI_TRI_SHAPE_DATA_READ \
ushort num_triangles; \
ushort num_match_groups; \
AShapeData::Read( in, version ); \
NifStream( num_triangles, in, version ); \
NifStream( num_triangle_points, in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( has_triangles, in, version ); \
}; \
if ( version <= 0x0A000102 ) { \
  triangles.resize(num_triangles); \
  NifStream( triangles, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( has_triangles != 0 ) { \
    triangles.resize(num_triangles); \
    NifStream( triangles, in, version ); \
  }; \
}; \
NifStream( num_match_groups, in, version ); \
match_groups.resize(num_match_groups); \
NifStream( match_groups, in, version ); \

#define NI_TRI_SHAPE_DATA_WRITE \
ushort num_triangles; \
ushort num_match_groups; \
AShapeData::Write( out, version ); \
num_triangles = ushort(triangles.size()); \
num_match_groups = ushort(match_groups.size()); \
NifStream( num_triangles, out, version ); \
NifStream( num_triangle_points, out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( has_triangles, out, version ); \
}; \
if ( version <= 0x0A000102 ) { \
  NifStream( triangles, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( has_triangles != 0 ) { \
    NifStream( triangles, out, version ); \
  }; \
}; \
NifStream( num_match_groups, out, version ); \
NifStream( match_groups, out, version ); \

#define NI_TRI_SHAPE_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShapeData::asString(); \
out << "       Num Triangles:  -- calculated --" << endl; \
out << " Num Triangle Points:  " << num_triangle_points << endl; \
out << "       Has Triangles:  " << has_triangles << endl; \
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
ushort num_triangles; \
bool has_points; \
vector<vector<ushort > > points; \

#define NI_TRI_STRIPS_DATA_GETATTR \
attr_ref attr = AShapeData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Triangles" ) \
  return attr_ref(num_triangles); \
if ( attr_name == "Has Points" ) \
  return attr_ref(has_points); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_TRI_STRIPS_DATA_PARENTS AShapeData

#define NI_TRI_STRIPS_DATA_CONSTRUCT

#define NI_TRI_STRIPS_DATA_READ \
ushort num_strips; \
vector<ushort > strip_lengths; \
AShapeData::Read( in, version ); \
NifStream( num_triangles, in, version ); \
NifStream( num_strips, in, version ); \
strip_lengths.resize(num_strips); \
NifStream( strip_lengths, in, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( has_points, in, version ); \
}; \
if ( version <= 0x0A000102 ) { \
  points.resize(num_strips); \
  NifStream( points, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( has_points != 0 ) { \
    points.resize(num_strips); \
    NifStream( points, in, version ); \
  }; \
}; \

#define NI_TRI_STRIPS_DATA_WRITE \
ushort num_strips; \
vector<ushort > strip_lengths; \
AShapeData::Write( out, version ); \
num_strips = ushort(strip_lengths.size()); \
strip_lengths.resize(num_strips); for (uint i = 0; i < points.size(); i++) strip_lengths[i] = ushort(points[i].size()); \
NifStream( num_triangles, out, version ); \
NifStream( num_strips, out, version ); \
NifStream( strip_lengths, out, version ); \
if ( version >= 0x0A010000 ) { \
  NifStream( has_points, out, version ); \
}; \
if ( version <= 0x0A000102 ) { \
  NifStream( points, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
  if ( has_points != 0 ) { \
    NifStream( points, out, version ); \
  }; \
}; \

#define NI_TRI_STRIPS_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AShapeData::asString(); \
out << "       Num Triangles:  " << num_triangles << endl; \
out << "          Num Strips:  -- calculated --" << endl; \
out << "       Strip Lengths:  -- calculated --" << endl; \
out << "          Has Points:  " << has_points << endl; \
out << "              Points:  -- data not shown --" << endl; \
return out.str(); \

// 
// Time controller for texture coordinates.
//
// - Always 0?
// - Texture coordinate controller data index.
#define NI_U_V_CONTROLLER_MEMBERS \
ushort unknown_short; \
uint data; \

#define NI_U_V_CONTROLLER_GETATTR \
attr_ref attr = AController::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Unknown Short" ) \
  return attr_ref(unknown_short); \
if ( attr_name == "Data" ) \
  return attr_ref(data); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_U_V_CONTROLLER_PARENTS AController

#define NI_U_V_CONTROLLER_CONSTRUCT

#define NI_U_V_CONTROLLER_READ \
AController::Read( in, version ); \
NifStream( unknown_short, in, version ); \
NifStream( data, in, version ); \

#define NI_U_V_CONTROLLER_WRITE \
AController::Write( out, version ); \
NifStream( unknown_short, out, version ); \
NifStream( data, out, version ); \

#define NI_U_V_CONTROLLER_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AController::asString(); \
out << "       Unknown Short:  " << unknown_short << endl; \
out << "                Data:  " << data << endl; \
return out.str(); \

// 
// Texture coordinate data.
//
// - Four UV data groups.  Perhaps the first two control x and y.
// The existence of the second two is a guess - there are always two zero values following the first two in all official files.
#define NI_U_V_DATA_MEMBERS \
vector<VectorKeyArray<float > > uv_groups; \

#define NI_U_V_DATA_GETATTR \
attr_ref attr = AData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_U_V_DATA_PARENTS AData

#define NI_U_V_DATA_CONSTRUCT

#define NI_U_V_DATA_READ \
AData::Read( in, version ); \
uv_groups.resize(4); \
NifStream( uv_groups, in, version ); \

#define NI_U_V_DATA_WRITE \
AData::Write( out, version ); \
NifStream( uv_groups, out, version ); \

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
Vector3 vector_data; \
float unknown_float; \

#define NI_VECTOR_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Vector Data" ) \
  return attr_ref(vector_data); \
if ( attr_name == "Unknown Float" ) \
  return attr_ref(unknown_float); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_VECTOR_EXTRA_DATA_PARENTS AExtraData

#define NI_VECTOR_EXTRA_DATA_CONSTRUCT

#define NI_VECTOR_EXTRA_DATA_READ \
AExtraData::Read( in, version ); \
NifStream( vector_data, in, version ); \
NifStream( unknown_float, in, version ); \

#define NI_VECTOR_EXTRA_DATA_WRITE \
AExtraData::Write( out, version ); \
NifStream( vector_data, out, version ); \
NifStream( unknown_float, out, version ); \

#define NI_VECTOR_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "         Vector Data:  " << vector_data << endl; \
out << "       Unknown Float:  " << unknown_float << endl; \
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
VertMode vertex_mode; \
LightMode lighting_mode; \

#define NI_VERTEX_COLOR_PROPERTY_GETATTR \
attr_ref attr = AProperty::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Flags" ) \
  return attr_ref(flags); \
if ( attr_name == "Vertex Mode" ) \
  return attr_ref(vertex_mode); \
if ( attr_name == "Lighting Mode" ) \
  return attr_ref(lighting_mode); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_VERTEX_COLOR_PROPERTY_PARENTS AProperty

#define NI_VERTEX_COLOR_PROPERTY_CONSTRUCT

#define NI_VERTEX_COLOR_PROPERTY_READ \
AProperty::Read( in, version ); \
NifStream( flags, in, version ); \
NifStream( vertex_mode, in, version ); \
NifStream( lighting_mode, in, version ); \

#define NI_VERTEX_COLOR_PROPERTY_WRITE \
AProperty::Write( out, version ); \
NifStream( flags, out, version ); \
NifStream( vertex_mode, out, version ); \
NifStream( lighting_mode, out, version ); \

#define NI_VERTEX_COLOR_PROPERTY_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AProperty::asString(); \
out << "               Flags:  " << flags << endl; \
out << "         Vertex Mode:  " << vertex_mode << endl; \
out << "       Lighting Mode:  " << lighting_mode << endl; \
return out.str(); \

// 
// Not used in skinning.
// Unsure of use - perhaps for morphing animation or gravity.
//
// - Number of bytes in this data block.
// - The vertex weights.
#define NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS \
uint num_bytes; \
vector<float > weight; \

#define NI_VERT_WEIGHTS_EXTRA_DATA_GETATTR \
attr_ref attr = AExtraData::GetAttr( attr_name ); \
if ( attr.is_null() == false ) return attr; \
if ( attr_name == "Num Bytes" ) \
  return attr_ref(num_bytes); \
throw runtime_error("The attribute you requested does not exist in this block, or can't be accessed."); \
return attr_ref(); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_PARENTS AExtraData

#define NI_VERT_WEIGHTS_EXTRA_DATA_CONSTRUCT

#define NI_VERT_WEIGHTS_EXTRA_DATA_READ \
ushort num_vertices; \
AExtraData::Read( in, version ); \
NifStream( num_bytes, in, version ); \
NifStream( num_vertices, in, version ); \
weight.resize(num_vertices); \
NifStream( weight, in, version ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_WRITE \
ushort num_vertices; \
AExtraData::Write( out, version ); \
num_vertices = ushort(weight.size()); \
NifStream( num_bytes, out, version ); \
NifStream( num_vertices, out, version ); \
NifStream( weight, out, version ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_STRING \
stringstream out; \
out.setf(ios::fixed, ios::floatfield); \
out << setprecision(1); \
out << AExtraData::asString(); \
out << "           Num Bytes:  " << num_bytes << endl; \
out << "        Num Vertices:  -- calculated --" << endl; \
out << "              Weight:  -- data not shown --" << endl; \
return out.str(); \

// 
// Time controller for visibility.
//
// - Visibility controller data block index.
#define NI_VIS_CONTROLLER_MEMBERS \
uint data; \

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
