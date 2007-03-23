// Swig module description file for a C dynamic library source file
// Generate with: swig -c++ -python -o py_wrap.cpp niflib.i

/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above
     copyright notice, this list of conditions and the following
     disclaimer in the documentation and/or other materials provided
     with the distribution.

   * Neither the name of the NIF File Format Library and Tools
     project nor the names of its contributors may be used to endorse
     or promote products derived from this software without specific
     prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE. */

%module niflib

// a few common things are defined in a seperate file
// to avoid cluttering up the main interface file

%include "common.i"

// expose headers (templates first)

%include "../include/Key.h"
%include "../include/Ref.h"
%include "../include/niflib.h"
%include "../include/nif_versions.h"
%include "../include/nif_math.h"

// data structures

%include "../include/gen/ByteArray.h"
%include "../include/gen/Footer.h"
%include "../include/gen/LODRange.h"
%include "../include/gen/MatchGroup.h"
%include "../include/gen/MipMap.h"
%include "../include/gen/NodeGroup.h"
%include "../include/gen/QuaternionXYZW.h"
%include "../include/gen/SkinShape.h"
%include "../include/gen/SkinShapeGroup.h"
%include "../include/gen/SkinWeight.h"
%include "../include/gen/AVObject.h"
%include "../include/gen/ControllerLink.h"
%include "../include/gen/Header.h"
%include "../include/gen/StringPalette.h"
%include "../include/gen/TBC.h"
%include "../include/gen/KeyGroup.h"
%include "../include/gen/RotationKeyArray.h"
%include "../include/gen/TexDesc.h"
%include "../include/gen/ShaderTexDesc.h"
%include "../include/gen/TexSource.h"
%include "../include/gen/SkinPartition.h"
%include "../include/gen/BoundingBox.h"
%include "../include/gen/FurniturePosition.h"
%include "../include/gen/hkTriangle.h"
%include "../include/gen/Morph.h"
%include "../include/gen/Particle.h"
%include "../include/gen/SkinData.h"
%include "../include/gen/Sphere.h"
%include "../include/gen/RagDollDescriptor.h"
%include "../include/gen/LimitedHingeDescriptor.h"

// essential file blocks

%include "../include/obj/NiObject.h"
%include "../include/obj/NiObjectNET.h"
%include "../include/obj/NiAVObject.h"
%include "../include/obj/NiNode.h"
%include "../include/obj/NiControllerSequence.h"

// essential templates

%template(NiObjectRef) Niflib::Ref<Niflib::NiObject>;
%template(NiObjectNETRef) Niflib::Ref<Niflib::NiObjectNET>;
%template(NiAVObjectRef) Niflib::Ref<Niflib::NiAVObject>;
%template(NiNodeRef) Niflib::Ref<Niflib::NiNode>;
%template(vector_NiObjectRef) std::vector<Niflib::NiObjectRef>; // for ReadNifList
/*
%template(vector_byte) std::vector<Niflib::byte>;
%template(vector_ushort) std::vector<unsigned short>;
%template(vector_SkinShape) std::vector<Niflib::SkinShape>;
%template(vector_LineString) std::vector<Niflib::LineString>;
%template(vector_string) std::vector<std::string>;
%template(vector_Triangle) std::vector<Niflib::Triangle>;
%template(vector_Vector3) std::vector<Niflib::Vector3>;
%template(vector_SkinWeight) std::vector<Niflib::SkinWeight>;
%template(vector_uint) std::vector<unsigned int>;
%template(vector_NodeGroup) std::vector<Niflib::NodeGroup>;
%template(vector_Color4) std::vector<Niflib::Color4>;
%template(vector_float) std::vector<float>;
%template(vector_Float4) std::vector<Niflib::Float4>;
%template(vector_Sphere) std::vector<Niflib::Sphere>;
%template(vector_FurniturePosition) std::vector<Niflib::FurniturePosition>;
%template(vector_hkTriangle) std::vector<Niflib::hkTriangle>;
%template(vector_SkinShapeGroup) std::vector<Niflib::SkinShapeGroup>;
%template(vector_short) std::vector<short>;
%template(vector_ControllerLink) std::vector<Niflib::ControllerLink>;
%template(vector_AVObject) std::vector<Niflib::AVObject>;
%template(vector_Morph) std::vector<Niflib::Morph>;
%template(vector_LODRange) std::vector<Niflib::LODRange>;
%template(vector_Quaternion) std::vector<Niflib::Quaternion>;
%template(vector_Particle) std::vector<Niflib::Particle>;
%template(vector_MipMap) std::vector<Niflib::MipMap>;
%template(vector_SkinData) std::vector<Niflib::SkinData>;
%template(vector_SkinPartition) std::vector<Niflib::SkinPartition>;
%template(vector_ShaderTexDesc) std::vector<Niflib::ShaderTexDesc>;
%template(vector_MatchGroup) std::vector<Niflib::MatchGroup>;
%template(pair_int_float) std::pair<int, float>;
%template(map_int_float) std::map<int, float>;
*/

