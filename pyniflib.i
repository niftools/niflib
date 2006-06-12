// Swig module description file for a C dynamic library source file
// Generate with: swig -c++ -python -o py_wrap.cpp pyniflib.i

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
%include "stl.i"
%include "std_map.i"
%include "exception.i"
%include "std_list.i"
%include "typemaps.i"

// enable string assignment in structure member functions
%typemap(in) std::string* ($*1_ltype tempstr) {
	char * temps; int templ;
 	if (PyString_AsStringAndSize($input, &temps, &templ)) return NULL;
 	tempstr = $*1_ltype(temps, templ);
 	$1 = &tempstr;
}
%typemap(out) std::string* "$result = PyString_FromStringAndSize($1->data(), $1->length());";

// we need a version of SWIG that has SWIG_CATCH_STDEXCEPT support
#if SWIG_VERSION >= 0x010322
%exception {
	try {
		$action
	}
	SWIG_CATCH_STDEXCEPT // catch std::exception
	catch (...) {
		SWIG_exception(SWIG_UnknownError, "Unknown exception");
	}
}
#endif

// we need to define this because the wrapper gets confused about NIFLIB_API'd functions otherwise
#define NIFLIB_API

%{
	#include "niflib.h"
%}

// we need the definition of the template classes before we define the template Python names below
template <class T> 
struct Key {
	float time;
	T data, forward_tangent, backward_tangent;
	float tension, bias, continuity;
};

%ignore Key;
%template(vector_byte) std::vector<byte>;
%template(vector_ushort) std::vector<ushort>;
%template(vector_SkinShape) std::vector<SkinShape>;
%template(vector_string) std::vector<std::string>;
%template(vector_Triangle) std::vector<Triangle>;
%template(vector_Vector3) std::vector<Vector3>;
%template(vector_float) std::vector<float>;
%template(vector_SkinWeight) std::vector<SkinWeight>;
%template(vector_NodeGroup) std::vector<NodeGroup>;
%template(vector_Color4) std::vector<Color4>;
%template(vector_Float4) std::vector<Float4>;
%template(vector_uint) std::vector<uint>;
%template(vector_FurniturePosition) std::vector<FurniturePosition>;
%template(vector_hkTriangle) std::vector<hkTriangle>;
%template(vector_SkinShapeGroup) std::vector<SkinShapeGroup>;
%template(vector_ControllerLink) std::vector<ControllerLink>;
%template(vector_AVObject) std::vector<AVObject>;
%template(vector_Morph) std::vector<Morph>;
%template(vector_LODRange) std::vector<LODRange>;
%template(vector_Quaternion) std::vector<Quaternion>;
%template(vector_Particle) std::vector<Particle>;
%template(vector_MipMap) std::vector<MipMap>;
%template(vector_SkinData) std::vector<SkinData>;
%template(vector_SkinPartition) std::vector<SkinPartition>;
%template(vector_ShaderTexDesc) std::vector<ShaderTexDesc>;
%template(vector_MatchGroup) std::vector<MatchGroup>;
%template(pair_int_float) std::pair<int, float>;
%template(map_int_float) std::map<int, float>;

%include "niflib.h"
