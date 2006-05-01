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
  out << "         Unknown Int:  " << val.unknown_int << endl;
  out << "                Data:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, CondInt const & val ) {
  out << "             Is Used:  " << val.is_used << endl;
  out << "         Unknown Int:  " << val.unknown_int << endl;
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
  out << "       Has Modifiers:  " << val.has_modifiers << endl;
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
  return out;
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
  return out;
};

ostream & operator<<( ostream & out, Shader const & val ) {
  out << "          Has Shader:  " << val.has_shader << endl;
  out << "         Shader Name:  " << val.shader_name << endl;
  out << "        Unknown Link:  " << val.unknown_link << endl;
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
  out << "            Num Keys:  " << val.num_keys << endl;
  out << "            Key Type:  " << val.key_type << endl;
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
  out << "            Num Keys:  " << val.num_keys << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
  out << "            Keys Sub:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, ns_keyvecarraytyp<T> const & val ) {
  out << "            Num Keys:  -- calculated --" << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, BumpMap const & val ) {
  out << "             Is Used:  " << val.is_used << endl;
  out << "             Texture:  " << val.texture << endl;
  out << " Bump Map Luma Scale:  " << val.bump_map_luma_scale << endl;
  out << "Bump Map Luma Offset:  " << val.bump_map_luma_offset << endl;
  out << "              Matrix:  " << val.matrix << endl;
  return out;
};

ostream & operator<<( ostream & out, Texture const & val ) {
  out << "             Is Used:  " << val.is_used << endl;
  out << "        Texture Data:  " << val.texture_data << endl;
  return out;
};

ostream & operator<<( ostream & out, Texture2 const & val ) {
  out << "             Is Used:  " << val.is_used << endl;
  out << "        Texture Data:  " << val.texture_data << endl;
  out << "         Unknown Int:  " << val.unknown_int << endl;
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
  return out;
};

ostream & operator<<( ostream & out, unk292bytes const & val ) {
  out << "   Unknown 292 Bytes:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, FurniturePosition const & val ) {
  out << "      Unknown Vector:  " << val.unknown_vector << endl;
  out << "       Unknown Short:  " << val.unknown_short << endl;
  out << "     Position Ref 1?:  " << val.position_ref_1_ << endl;
  out << "     Position Ref 2?:  " << val.position_ref_2_ << endl;
  return out;
};

ostream & operator<<( ostream & out, hkTriangle const & val ) {
  out << "            Triangle:  " << val.triangle << endl;
  out << "       Unknown Short:  " << val.unknown_short << endl;
  out << "              Normal:  " << val.normal << endl;
  return out;
};

ostream & operator<<( ostream & out, LODInfo const & val ) {
  out << "            LOD Type:  " << val.lod_type << endl;
  out << "          LOD Center:  " << val.lod_center << endl;
  out << "      Num LOD Levels:  -- calculated --" << endl;
  out << "          LOD Levels:  -- data not shown --" << endl;
  out << "       Unknown Short:  " << val.unknown_short << endl;
  out << "          Range Data:  " << val.range_data << endl;
  return out;
};

ostream & operator<<( ostream & out, Particle const & val ) {
  out << "            Velocity:  " << val.velocity << endl;
  out << "      Unknown Vector:  " << val.unknown_vector << endl;
  out << "            Lifetime:  " << val.lifetime << endl;
  out << "            Lifespan:  " << val.lifespan << endl;
  out << "           Timestamp:  " << val.timestamp << endl;
  out << "       Unknown Short:  " << val.unknown_short << endl;
  out << "           Vertex ID:  " << val.vertex_id << endl;
  return out;
};

ostream & operator<<( ostream & out, ParticleGroup const & val ) {
  out << "       Num Particles:  -- calculated --" << endl;
  out << "           Num Valid:  " << val.num_valid << endl;
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
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

ostream & operator<<( ostream & out, Morph const & val ) {
  out << "          Frame Name:  " << val.frame_name << endl;
  out << "              Frames:  " << val.frames << endl;
  out << "         Unknown Int:  " << val.unknown_int << endl;
  out << "             Vectors:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, VectorKeyArray<T> const & val ) {
  out << "            Num Keys:  " << val.num_keys << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

template <class T >
ostream & operator<<( ostream & out, RotationKeyArray<T> const & val ) {
  out << "            Num Keys:  " << val.num_keys << endl;
  out << "            Key Type:  " << val.key_type << endl;
  out << "                Keys:  -- data not shown --" << endl;
  return out;
};

