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

void NifStream( Bones & val, istream & in, uint version ) {
  uint num_bones;
  NifStream( num_bones, in, version );
  val.bones.resize(num_bones);
  NifStream( val.bones, in, version );
};

void NifStream( Bones const & val, ostream & out, uint version ) {
  uint num_bones;
  num_bones = val.bones.size();
  NifStream( num_bones, out, version );
  NifStream( val.bones, out, version );
};

ostream & operator<<( ostream & out, Bones const & val ) {
  out << "           Num Bones:  -- calculated --" << endl;
  out << "               Bones:  -- data not shown --" << endl;
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
  size = val.data.size();
  NifStream( size, out, version );
  if ( version >= 0x14000004 ) {
    NifStream( val.unknown_int, out, version );
  };
  NifStream( val.data, out, version );
};

ostream & operator<<( ostream & out, ByteArray const & val ) {
  out << "                Size:  -- calculated --" << endl;
  out << "         Unknown Int:  " << val.unknown_int << endl;
  out << "                Data:  -- data not shown --" << endl;
};

void NifStream( condint & val, istream & in, uint version ) {
  NifStream( val.is_used, in, version );
  if ( val.is_used != 0 ) {
    NifStream( val.unknown_int, in, version );
  };
};

void NifStream( condint const & val, ostream & out, uint version ) {
  NifStream( val.is_used, out, version );
  if ( val.is_used != 0 ) {
    NifStream( val.unknown_int, out, version );
  };
};

ostream & operator<<( ostream & out, condint const & val ) {
  out << "             Is Used:  " << val.is_used << endl;
  out << "         Unknown Int:  " << val.unknown_int << endl;
};

template <class T >
void NifStream( keyarray<T> & val, istream & in, uint version ) {
  uint num_keys;
  NifStream( num_keys, in, version );
  val.keys.resize(num_keys);
  NifStream( val.keys, in, version );
};

template <class T >
void NifStream( keyarray<T> const & val, ostream & out, uint version ) {
  uint num_keys;
  num_keys = val.keys.size();
  NifStream( num_keys, out, version );
  NifStream( val.keys, out, version );
};

template <class T >
ostream & operator<<( ostream & out, keyarray<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "                Keys:  -- data not shown --" << endl;
};

void NifStream( linkgroup & val, istream & in, uint version ) {
  uint num_indices;
  NifStream( num_indices, in, version );
  val.indices.resize(num_indices);
  NifStream( val.indices, in, version );
};

void NifStream( linkgroup const & val, ostream & out, uint version ) {
  uint num_indices;
  num_indices = val.indices.size();
  NifStream( num_indices, out, version );
  NifStream( val.indices, out, version );
};

ostream & operator<<( ostream & out, linkgroup const & val ) {
  out << "         Num Indices:  -- calculated --" << endl;
  out << "             Indices:  -- data not shown --" << endl;
};

void NifStream( Footer & val, istream & in, uint version ) {
  NifStream( val.roots, in, version );
};

void NifStream( Footer const & val, ostream & out, uint version ) {
  NifStream( val.roots, out, version );
};

ostream & operator<<( ostream & out, Footer const & val ) {
  out << "               Roots:  " << val.roots << endl;
};

void NifStream( matchgroup & val, istream & in, uint version ) {
  ushort num_vertices;
  NifStream( num_vertices, in, version );
  val.vertex_indices.resize(num_vertices);
  NifStream( val.vertex_indices, in, version );
};

void NifStream( matchgroup const & val, ostream & out, uint version ) {
  ushort num_vertices;
  num_vertices = val.vertex_indices.size();
  NifStream( num_vertices, out, version );
  NifStream( val.vertex_indices, out, version );
};

ostream & operator<<( ostream & out, matchgroup const & val ) {
  out << "        Num Vertices:  -- calculated --" << endl;
  out << "      Vertex Indices:  -- data not shown --" << endl;
};

void NifStream( mipmap & val, istream & in, uint version ) {
  NifStream( val.width, in, version );
  NifStream( val.height, in, version );
  NifStream( val.offset, in, version );
};

void NifStream( mipmap const & val, ostream & out, uint version ) {
  NifStream( val.width, out, version );
  NifStream( val.height, out, version );
  NifStream( val.offset, out, version );
};

ostream & operator<<( ostream & out, mipmap const & val ) {
  out << "               Width:  " << val.width << endl;
  out << "              Height:  " << val.height << endl;
  out << "              Offset:  " << val.offset << endl;
};

void NifStream( modifiergroup & val, istream & in, uint version ) {
  NifStream( val.has_modifiers, in, version );
  NifStream( val.modifiers, in, version );
};

void NifStream( modifiergroup const & val, ostream & out, uint version ) {
  NifStream( val.has_modifiers, out, version );
  NifStream( val.modifiers, out, version );
};

ostream & operator<<( ostream & out, modifiergroup const & val ) {
  out << "       Has Modifiers:  " << val.has_modifiers << endl;
  out << "           Modifiers:  " << val.modifiers << endl;
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
ostream & operator<<( ostream & out, ns_keylin<T> const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "               Value:  " << val.value << endl;
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
  num_keys = val.keys.size();
  NifStream( num_keys, out, version );
  NifStream( val.keys, out, version );
};

template <class T >
ostream & operator<<( ostream & out, ns_keyarray<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "                Keys:  -- data not shown --" << endl;
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
ostream & operator<<( ostream & out, ns_keytan<T> const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "               Value:  " << val.value << endl;
  out << "             Forward:  " << val.forward << endl;
  out << "            Backward:  " << val.backward << endl;
};

void NifStream( quaternionxyzw & val, istream & in, uint version ) {
  NifStream( val.x, in, version );
  NifStream( val.y, in, version );
  NifStream( val.z, in, version );
  NifStream( val.w, in, version );
};

void NifStream( quaternionxyzw const & val, ostream & out, uint version ) {
  NifStream( val.x, out, version );
  NifStream( val.y, out, version );
  NifStream( val.z, out, version );
  NifStream( val.w, out, version );
};

ostream & operator<<( ostream & out, quaternionxyzw const & val ) {
  out << "                   x:  " << val.x << endl;
  out << "                   y:  " << val.y << endl;
  out << "                   z:  " << val.z << endl;
  out << "                   w:  " << val.w << endl;
};

void NifStream( shortstring & val, istream & in, uint version ) {
  byte length;
  NifStream( length, in, version );
  val.value.resize(length);
  NifStream( val.value, in, version );
};

void NifStream( shortstring const & val, ostream & out, uint version ) {
  byte length;
  length = val.value.size();
  NifStream( length, out, version );
  NifStream( val.value, out, version );
};

ostream & operator<<( ostream & out, shortstring const & val ) {
  out << "              Length:  -- calculated --" << endl;
  out << "               Value:  -- data not shown --" << endl;
};

void NifStream( skinshapegroup & val, istream & in, uint version ) {
  uint num_link_pairs;
  NifStream( num_link_pairs, in, version );
  val.link_pairs.resize(num_link_pairs);
  NifStream( val.link_pairs, in, version );
};

void NifStream( skinshapegroup const & val, ostream & out, uint version ) {
  uint num_link_pairs;
  num_link_pairs = val.link_pairs.size();
  NifStream( num_link_pairs, out, version );
  NifStream( val.link_pairs, out, version );
};

ostream & operator<<( ostream & out, skinshapegroup const & val ) {
  out << "      Num Link Pairs:  -- calculated --" << endl;
  out << "          Link Pairs:  -- data not shown --" << endl;
};

void NifStream( skinweight & val, istream & in, uint version ) {
  NifStream( val.index, in, version );
  NifStream( val.weight, in, version );
};

void NifStream( skinweight const & val, ostream & out, uint version ) {
  NifStream( val.index, out, version );
  NifStream( val.weight, out, version );
};

ostream & operator<<( ostream & out, skinweight const & val ) {
  out << "               Index:  " << val.index << endl;
  out << "              Weight:  " << val.weight << endl;
};

void NifStream( AVObject & val, istream & in, uint version ) {
  NifStream( val.name, in, version );
  NifStream( val.object, in, version );
};

void NifStream( AVObject const & val, ostream & out, uint version ) {
  NifStream( val.name, out, version );
  NifStream( val.object, out, version );
};

ostream & operator<<( ostream & out, AVObject const & val ) {
  out << "                Name:  " << val.name << endl;
  out << "              Object:  " << val.object << endl;
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

ostream & operator<<( ostream & out, ControllerLink const & val ) {
  out << "                Name:  " << val.name << endl;
  out << "        Interpolator:  " << val.interpolator << endl;
  out << "      Unknown Link 1:  " << val.unknown_link_1 << endl;
  out << "      Unknown Link 2:  " << val.unknown_link_2 << endl;
  out << "     Unknown Short 0:  " << val.unknown_short_0 << endl;
  out << "           Priority?:  " << val.priority_ << endl;
  out << "      String Palette:  " << val.string_palette << endl;
  out << "           Node Name:  " << val.node_name << endl;
  out << "    Node Name Offset:  " << val.node_name_offset << endl;
  out << "     Unknown Short 1:  " << val.unknown_short_1 << endl;
  out << "       Property Type:  " << val.property_type << endl;
  out << "Property Type Offset:  " << val.property_type_offset << endl;
  out << "     Unknown Short 2:  " << val.unknown_short_2 << endl;
  out << "     Controller Type:  " << val.controller_type << endl;
  out << "Controller Type Offset:  " << val.controller_type_offset << endl;
  out << "     Unknown Short 3:  " << val.unknown_short_3 << endl;
  out << "          Variable 1:  " << val.variable_1 << endl;
  out << "   Variable Offset 1:  " << val.variable_offset_1 << endl;
  out << "     Unknown Short 4:  " << val.unknown_short_4 << endl;
  out << "          Variable 2:  " << val.variable_2 << endl;
  out << "   Variable Offset 2:  " << val.variable_offset_2 << endl;
  out << "     Unknown Short 5:  " << val.unknown_short_5 << endl;
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
  num_blocks = val.block_type_index.size();
  num_block_types = val.block_types.size();
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

ostream & operator<<( ostream & out, Header const & val ) {
  out << "       Header String:  " << val.header_string << endl;
  out << "             Version:  " << val.version << endl;
  out << "         Endian Type:  " << val.endian_type << endl;
  out << "        User Version:  " << val.user_version << endl;
  out << "          Num Blocks:  -- calculated --" << endl;
  out << "       Unknown Int 1:  " << val.unknown_int_1 << endl;
  out << "       Unknown Int 3:  " << val.unknown_int_3 << endl;
  out << "            Creator?:  " << val.creator_ << endl;
  out << "        Export Type?:  " << val.export_type_ << endl;
  out << "      Export Script?:  " << val.export_script_ << endl;
  out << "     Num Block Types:  -- calculated --" << endl;
  out << "         Block Types:  -- data not shown --" << endl;
  out << "    Block Type Index:  -- data not shown --" << endl;
  out << "       Unknown Int 2:  " << val.unknown_int_2 << endl;
};

void NifStream( shader & val, istream & in, uint version ) {
  NifStream( val.has_shader, in, version );
  if ( val.has_shader != 0 ) {
    NifStream( val.shader_name, in, version );
    NifStream( val.unknown_link, in, version );
  };
};

void NifStream( shader const & val, ostream & out, uint version ) {
  NifStream( val.has_shader, out, version );
  if ( val.has_shader != 0 ) {
    NifStream( val.shader_name, out, version );
    NifStream( val.unknown_link, out, version );
  };
};

ostream & operator<<( ostream & out, shader const & val ) {
  out << "          Has Shader:  " << val.has_shader << endl;
  out << "         Shader Name:  " << val.shader_name << endl;
  out << "        Unknown Link:  " << val.unknown_link << endl;
};

void NifStream( stringpalette & val, istream & in, uint version ) {
  NifStream( val.palette, in, version );
  NifStream( val.length, in, version );
};

void NifStream( stringpalette const & val, ostream & out, uint version ) {
  NifStream( val.palette, out, version );
  NifStream( val.length, out, version );
};

ostream & operator<<( ostream & out, stringpalette const & val ) {
  out << "             Palette:  " << val.palette << endl;
  out << "              Length:  " << val.length << endl;
};

void NifStream( targetgroup & val, istream & in, uint version ) {
  ushort num_indices;
  NifStream( num_indices, in, version );
  val.indices.resize(num_indices);
  NifStream( val.indices, in, version );
};

void NifStream( targetgroup const & val, ostream & out, uint version ) {
  ushort num_indices;
  num_indices = val.indices.size();
  NifStream( num_indices, out, version );
  NifStream( val.indices, out, version );
};

ostream & operator<<( ostream & out, targetgroup const & val ) {
  out << "         Num Indices:  -- calculated --" << endl;
  out << "             Indices:  -- data not shown --" << endl;
};

void NifStream( tbc & val, istream & in, uint version ) {
  NifStream( val.t, in, version );
  NifStream( val.b, in, version );
  NifStream( val.c, in, version );
};

void NifStream( tbc const & val, ostream & out, uint version ) {
  NifStream( val.t, out, version );
  NifStream( val.b, out, version );
  NifStream( val.c, out, version );
};

ostream & operator<<( ostream & out, tbc const & val ) {
  out << "                   t:  " << val.t << endl;
  out << "                   b:  " << val.b << endl;
  out << "                   c:  " << val.c << endl;
};

template <class T >
void NifStream( keyvec<T> & val, istream & in, uint version ) {
  NifStream( val.time, in, version );
  NifStream( val.value, in, version );
  if ( (arg) == 2 ) {
    NifStream( val.forward, in, version );
    NifStream( val.backward, in, version );
  };
  if ( (arg) == 3 ) {
    NifStream( val.tbc, in, version );
  };
};

template <class T >
void NifStream( keyvec<T> const & val, ostream & out, uint version ) {
  NifStream( val.time, out, version );
  NifStream( val.value, out, version );
  if ( (arg) == 2 ) {
    NifStream( val.forward, out, version );
    NifStream( val.backward, out, version );
  };
  if ( (arg) == 3 ) {
    NifStream( val.tbc, out, version );
  };
};

template <class T >
ostream & operator<<( ostream & out, keyvec<T> const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "               Value:  " << val.value << endl;
  out << "             Forward:  " << val.forward << endl;
  out << "            Backward:  " << val.backward << endl;
  out << "                 TBC:  " << val.tbc << endl;
};

template <class T >
void NifStream( keyvecarray<T> & val, istream & in, uint version ) {
  NifStream( val.num_keys, in, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, in, version );
  };
  val.keys.resize(val.num_keys);
  NifStream( val.keys, in, version );
};

template <class T >
void NifStream( keyvecarray<T> const & val, ostream & out, uint version ) {
  NifStream( val.num_keys, out, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, out, version );
  };
  NifStream( val.keys, out, version );
};

template <class T >
ostream & operator<<( ostream & out, keyvecarray<T> const & val ) {
  out << "            Num Keys:  " << val.num_keys << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
};

template <class T >
void NifStream( keyrot<T> & val, istream & in, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.time, in, version );
  };
  if ( (arg) != 4 ) {
    NifStream( val.value, in, version );
  };
  if ( (arg) == 3 ) {
    NifStream( val.tbc, in, version );
  };
  if ( (arg) == 4 ) {
    val.sub_keys.resize(3);
    NifStream( val.sub_keys, in, version );
  };
};

template <class T >
void NifStream( keyrot<T> const & val, ostream & out, uint version ) {
  if ( version <= 0x0A010000 ) {
    NifStream( val.time, out, version );
  };
  if ( (arg) != 4 ) {
    NifStream( val.value, out, version );
  };
  if ( (arg) == 3 ) {
    NifStream( val.tbc, out, version );
  };
  if ( (arg) == 4 ) {
    NifStream( val.sub_keys, out, version );
  };
};

template <class T >
ostream & operator<<( ostream & out, keyrot<T> const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "               Value:  " << val.value << endl;
  out << "                 TBC:  " << val.tbc << endl;
  out << "            Sub Keys:  -- data not shown --" << endl;
};

template <class T >
void NifStream( keyrotarray<T> & val, istream & in, uint version ) {
  NifStream( val.num_keys, in, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, in, version );
  };
  val.keys.resize(val.num_keys);
  NifStream( val.keys, in, version );
};

template <class T >
void NifStream( keyrotarray<T> const & val, ostream & out, uint version ) {
  NifStream( val.num_keys, out, version );
  if ( val.num_keys != 0 ) {
    NifStream( val.key_type, out, version );
  };
  NifStream( val.keys, out, version );
};

template <class T >
ostream & operator<<( ostream & out, keyrotarray<T> const & val ) {
  out << "            Num Keys:  " << val.num_keys << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
};

template <class T >
void NifStream( keyvecarraytyp<T> & val, istream & in, uint version ) {
  uint num_keys;
  NifStream( num_keys, in, version );
  NifStream( val.key_type, in, version );
  val.keys.resize(num_keys);
  NifStream( val.keys, in, version );
};

template <class T >
void NifStream( keyvecarraytyp<T> const & val, ostream & out, uint version ) {
  uint num_keys;
  num_keys = val.keys.size();
  NifStream( num_keys, out, version );
  NifStream( val.key_type, out, version );
  NifStream( val.keys, out, version );
};

template <class T >
ostream & operator<<( ostream & out, keyvecarraytyp<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
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
ostream & operator<<( ostream & out, ns_keytbc<T> const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "               Value:  " << val.value << endl;
  out << "                 TBC:  " << val.tbc << endl;
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
};

template <class T >
ostream & operator<<( ostream & out, ns_keyvecarray<T> const & val ) {
  out << "            Num Keys:  " << val.num_keys << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
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

ostream & operator<<( ostream & out, ns_keyrotsub const & val ) {
  out << "                Time:  " << val.time << endl;
  out << "            Sub Keys:  -- data not shown --" << endl;
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
  if ( val.key_type == 4 ) {
    NifStream( val.keys_sub, out, version );
  };
};

template <class T >
ostream & operator<<( ostream & out, ns_keyrotarray<T> const & val ) {
  out << "            Num Keys:  " << val.num_keys << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
  out << "            Keys Sub:  -- data not shown --" << endl;
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
};

template <class T >
void NifStream( ns_keyvecarraytyp<T> const & val, ostream & out, uint version ) {
  uint num_keys;
  num_keys = val.keys.size();
  NifStream( num_keys, out, version );
  NifStream( val.key_type, out, version );
  if ( val.key_type == 1 ) {
    NifStream( val.keys, out, version );
  };
};

template <class T >
ostream & operator<<( ostream & out, ns_keyvecarraytyp<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
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

ostream & operator<<( ostream & out, BumpMap const & val ) {
  out << "             Is Used:  " << val.is_used << endl;
  out << "             Texture:  " << val.texture << endl;
  out << " Bump Map Luma Scale:  " << val.bump_map_luma_scale << endl;
  out << "Bump Map Luma Offset:  " << val.bump_map_luma_offset << endl;
  out << "              Matrix:  " << val.matrix << endl;
};

void NifStream( texture & val, istream & in, uint version ) {
  NifStream( val.is_used, in, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture_data, in, version );
  };
};

void NifStream( texture const & val, ostream & out, uint version ) {
  NifStream( val.is_used, out, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture_data, out, version );
  };
};

ostream & operator<<( ostream & out, texture const & val ) {
  out << "             Is Used:  " << val.is_used << endl;
  out << "        Texture Data:  " << val.texture_data << endl;
};

void NifStream( texture2 & val, istream & in, uint version ) {
  NifStream( val.is_used, in, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture_data, in, version );
    NifStream( val.unknown_int, in, version );
  };
};

void NifStream( texture2 const & val, ostream & out, uint version ) {
  NifStream( val.is_used, out, version );
  if ( val.is_used != 0 ) {
    NifStream( val.texture_data, out, version );
    NifStream( val.unknown_int, out, version );
  };
};

ostream & operator<<( ostream & out, texture2 const & val ) {
  out << "             Is Used:  " << val.is_used << endl;
  out << "        Texture Data:  " << val.texture_data << endl;
  out << "         Unknown Int:  " << val.unknown_int << endl;
};

void NifStream( ExtraTextureGroup & val, istream & in, uint version ) {
  uint num_textures;
  NifStream( num_textures, in, version );
  val.textures.resize(num_textures);
  NifStream( val.textures, in, version );
};

void NifStream( ExtraTextureGroup const & val, ostream & out, uint version ) {
  uint num_textures;
  num_textures = val.textures.size();
  NifStream( num_textures, out, version );
  NifStream( val.textures, out, version );
};

ostream & operator<<( ostream & out, ExtraTextureGroup const & val ) {
  out << "        Num Textures:  -- calculated --" << endl;
  out << "            Textures:  -- data not shown --" << endl;
};

void NifStream( skinpartitionblock & val, istream & in, uint version ) {
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
    NifStream( val.has_vertex_weights, in, version );
  };
  if ( version <= 0x0A000102 ) {
    val.vertex_weights.resize(num_vertices);
    NifStream( val.vertex_weights, in, version );
  };
  strip_lengths.resize(val.num_strips);
  NifStream( strip_lengths, in, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.has_strips, in, version );
  };
  if ( version <= 0x0A000102 ) {
    val.strips.resize(val.num_strips);
    NifStream( val.strips, in, version );
  };
  if ( val.num_strips == 0 ) {
    val.triangles.resize(num_triangles);
    NifStream( val.triangles, in, version );
  };
  NifStream( val.has_bone_indices, in, version );
  if ( val.has_bone_indices != 0 ) {
    val.bone_indices.resize(num_vertices);
    NifStream( val.bone_indices, in, version );
  };
};

void NifStream( skinpartitionblock const & val, ostream & out, uint version ) {
  ushort num_vertices;
  ushort num_triangles;
  ushort num_bones;
  ushort num_weights_per_vertex;
  vector<ushort > strip_lengths;
  num_vertices = val.vertex_map.size();
  num_triangles = val.triangles.size();
  num_bones = val.bones.size();
  num_weights_per_vertex = val.vertex_weights.size();
  strip_lengths = val.strips.size();
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
    NifStream( val.has_vertex_weights, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.vertex_weights, out, version );
  };
  NifStream( strip_lengths, out, version );
  if ( version >= 0x0A010000 ) {
    NifStream( val.has_strips, out, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.strips, out, version );
  };
  if ( val.num_strips == 0 ) {
    NifStream( val.triangles, out, version );
  };
  NifStream( val.has_bone_indices, out, version );
  if ( val.has_bone_indices != 0 ) {
    NifStream( val.bone_indices, out, version );
  };
};

ostream & operator<<( ostream & out, skinpartitionblock const & val ) {
  out << "        Num Vertices:  -- calculated --" << endl;
  out << "       Num Triangles:  -- calculated --" << endl;
  out << "           Num Bones:  -- calculated --" << endl;
  out << "          Num Strips:  " << val.num_strips << endl;
  out << "Num Weights Per Vertex:  -- calculated --" << endl;
  out << "               Bones:  -- data not shown --" << endl;
  out << "      Has Vertex Map:  " << val.has_vertex_map << endl;
  out << "          Vertex Map:  -- data not shown --" << endl;
  out << "  Has Vertex Weights:  " << val.has_vertex_weights << endl;
  out << "      Vertex Weights:  -- data not shown --" << endl;
  out << "       Strip Lengths:  -- calculated --" << endl;
  out << "          Has Strips:  " << val.has_strips << endl;
  out << "              Strips:  -- data not shown --" << endl;
  out << "           Triangles:  -- data not shown --" << endl;
  out << "    Has Bone Indices:  " << val.has_bone_indices << endl;
  out << "        Bone Indices:  -- data not shown --" << endl;
};

void NifStream( unk292bytes & val, istream & in, uint version ) {
  val.unknown_292_bytes.resize(73);
  NifStream( val.unknown_292_bytes, in, version );
};

void NifStream( unk292bytes const & val, ostream & out, uint version ) {
  NifStream( val.unknown_292_bytes, out, version );
};

ostream & operator<<( ostream & out, unk292bytes const & val ) {
  out << "   Unknown 292 Bytes:  -- data not shown --" << endl;
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

ostream & operator<<( ostream & out, FurniturePosition const & val ) {
  out << "      Unknown Vector:  " << val.unknown_vector << endl;
  out << "       Unknown Short:  " << val.unknown_short << endl;
  out << "     Position Ref 1?:  " << val.position_ref_1_ << endl;
  out << "     Position Ref 2?:  " << val.position_ref_2_ << endl;
};

void NifStream( hktriangle & val, istream & in, uint version ) {
  NifStream( val.triangle, in, version );
  NifStream( val.unknown_short, in, version );
  NifStream( val.normal, in, version );
};

void NifStream( hktriangle const & val, ostream & out, uint version ) {
  NifStream( val.triangle, out, version );
  NifStream( val.unknown_short, out, version );
  NifStream( val.normal, out, version );
};

ostream & operator<<( ostream & out, hktriangle const & val ) {
  out << "            Triangle:  " << val.triangle << endl;
  out << "       Unknown Short:  " << val.unknown_short << endl;
  out << "              Normal:  " << val.normal << endl;
};

void NifStream( lodinfo & val, istream & in, uint version ) {
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

void NifStream( lodinfo const & val, ostream & out, uint version ) {
  uint num_lod_levels;
  num_lod_levels = val.lod_levels.size();
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

ostream & operator<<( ostream & out, lodinfo const & val ) {
  out << "            LOD Type:  " << val.lod_type << endl;
  out << "          LOD Center:  " << val.lod_center << endl;
  out << "      Num LOD Levels:  -- calculated --" << endl;
  out << "          LOD Levels:  -- data not shown --" << endl;
  out << "       Unknown Short:  " << val.unknown_short << endl;
  out << "          Range Data:  " << val.range_data << endl;
};

void NifStream( morphblock & val, istream & in, uint version ) {
  if ( version >= 0x0A01006A ) {
    NifStream( val.frame_name, in, version );
  };
  if ( version <= 0x0A000102 ) {
    NifStream( val.frames, in, version );
  };
  if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) {
    NifStream( val.unknown_int, in, version );
  };
  val.vectors.resize((arg));
  NifStream( val.vectors, in, version );
};

void NifStream( morphblock const & val, ostream & out, uint version ) {
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

ostream & operator<<( ostream & out, morphblock const & val ) {
  out << "          Frame Name:  " << val.frame_name << endl;
  out << "              Frames:  " << val.frames << endl;
  out << "         Unknown Int:  " << val.unknown_int << endl;
  out << "             Vectors:  -- data not shown --" << endl;
};

void NifStream( particle & val, istream & in, uint version ) {
  NifStream( val.velocity, in, version );
  NifStream( val.unknown_vector, in, version );
  NifStream( val.lifetime, in, version );
  NifStream( val.lifespan, in, version );
  NifStream( val.timestamp, in, version );
  NifStream( val.unknown_short, in, version );
  NifStream( val.vertex_id, in, version );
};

void NifStream( particle const & val, ostream & out, uint version ) {
  NifStream( val.velocity, out, version );
  NifStream( val.unknown_vector, out, version );
  NifStream( val.lifetime, out, version );
  NifStream( val.lifespan, out, version );
  NifStream( val.timestamp, out, version );
  NifStream( val.unknown_short, out, version );
  NifStream( val.vertex_id, out, version );
};

ostream & operator<<( ostream & out, particle const & val ) {
  out << "            Velocity:  " << val.velocity << endl;
  out << "      Unknown Vector:  " << val.unknown_vector << endl;
  out << "            Lifetime:  " << val.lifetime << endl;
  out << "            Lifespan:  " << val.lifespan << endl;
  out << "           Timestamp:  " << val.timestamp << endl;
  out << "       Unknown Short:  " << val.unknown_short << endl;
  out << "           Vertex ID:  " << val.vertex_id << endl;
};

void NifStream( particlegroup & val, istream & in, uint version ) {
  ushort num_particles;
  NifStream( num_particles, in, version );
  NifStream( val.num_valid, in, version );
  val.particles.resize(num_particles);
  NifStream( val.particles, in, version );
};

void NifStream( particlegroup const & val, ostream & out, uint version ) {
  ushort num_particles;
  num_particles = val.particles.size();
  NifStream( num_particles, out, version );
  NifStream( val.num_valid, out, version );
  NifStream( val.particles, out, version );
};

ostream & operator<<( ostream & out, particlegroup const & val ) {
  out << "       Num Particles:  -- calculated --" << endl;
  out << "           Num Valid:  " << val.num_valid << endl;
  out << "           Particles:  -- data not shown --" << endl;
};

void NifStream( skinblock & val, istream & in, uint version ) {
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

void NifStream( skinblock const & val, ostream & out, uint version ) {
  ushort num_vertices;
  num_vertices = val.vertex_weights.size();
  NifStream( val.rotation, out, version );
  NifStream( val.translation, out, version );
  NifStream( val.scale, out, version );
  NifStream( val.unknown_4_floats, out, version );
  NifStream( num_vertices, out, version );
  NifStream( val.vertex_weights, out, version );
};

ostream & operator<<( ostream & out, skinblock const & val ) {
  out << "            Rotation:  " << val.rotation << endl;
  out << "         Translation:  " << val.translation << endl;
  out << "               Scale:  " << val.scale << endl;
  out << "    Unknown 4 Floats:  -- data not shown --" << endl;
  out << "        Num Vertices:  -- calculated --" << endl;
  out << "      Vertex Weights:  -- data not shown --" << endl;
};

