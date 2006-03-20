// Swig module description file for a C dynamic library source file
// Generate with: swig -c++ -python -o py_wrap.cpp pyniflib.i

/* Copyright (c) 2005, NIF File Format Library and Tools
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

%template(vector_float) std::vector<float>;
%template(vector_short) std::vector<short>;
%template(vector_attr_ref) std::vector<attr_ref>;
%template(vector_blk_ref) std::vector<blk_ref>;
%template(list_blk_ref) std::list<blk_ref>;
%template(vector_Vector3) std::vector<Vector3>;
%template(vector_Color) std::vector<Color4>;
%template(vector_TexCoord) std::vector<TexCoord>;
%template(vector_Triangle) std::vector<Triangle>;
%template(vector_SkinWeight) std::vector<SkinWeight>;
%template(pair_int_float) std::pair<int, float>;
%template(map_int_float) std::map<int, float>;
%template(Key_Quaternion) Key<Quaternion>;
%template(vector_Key_Quaternion) std::vector< Key<Quaternion> >;
%template(Key_Vector3) Key<Vector3>;
%template(vector_Key_Vector3) std::vector< Key<Vector3> >;
%template(Key_float) Key<float>;
%template(vector_Key_float) std::vector< Key<float> >;
%template(Key_Color4) Key<Color4>;
%template(vector_Key_Color4) std::vector< Key<Color4> >;
%template(Key_string) Key<std::string>;
%template(vector_Key_string) std::vector< Key<std::string> >;

%ignore Float2::operator[](int n);
%ignore Float2::operator[](int n) const;
%ignore Float3::operator[](int n);
%ignore Float3::operator[](int n) const;
%ignore Float4::operator[](int n);
%ignore Float4::operator[](int n) const;
%ignore Matrix22::operator[](int n);
%ignore Matrix22::operator[](int n) const;
%ignore Matrix33::operator[](int n);
%ignore Matrix33::operator[](int n) const;
%ignore Matrix44::operator[](int n);
%ignore Matrix44::operator[](int n) const;
%ignore blk_ref::operator[](string const & index) const;

%ignore attr_ref::operator=(int n);
%ignore attr_ref::operator=(float n);
%ignore attr_ref::operator=(Float3 const & n);
%ignore attr_ref::operator=(string const & n);
%ignore attr_ref::operator=(const char * n);
%ignore attr_ref::operator=(Matrix33 const & n);
%ignore attr_ref::operator=(blk_ref const & n);
%ignore attr_ref::operator=(TexSource const & n);
%ignore attr_ref::operator=(BoundingBox const & n);
%ignore attr_ref::operator=(ConditionalInt const & n);
%ignore attr_ref::operator=(TexDesc const & n);

%ignore blk_ref::operator=(const blk_ref & rh );

%ignore attr_ref::operator int() const;
%ignore attr_ref::operator float() const;
%ignore attr_ref::operator Float3() const;
%ignore attr_ref::operator std::string() const;
%ignore attr_ref::operator Matrix33() const;
%ignore attr_ref::operator blk_ref() const;
%ignore attr_ref::operator TexSource() const;
%ignore attr_ref::operator BoundingBox() const;
%ignore attr_ref::operator ConditionalInt() const;
%ignore attr_ref::operator TexDesc() const;
%ignore attr_ref::operator std::list<blk_ref>() const;

%ignore operator<<(ostream & lh, const blk_ref & rh);

%rename QueryShapeData( blk_ref & block ) QueryShapeData_const;
%rename QueryTriShapeData( blk_ref const & block ) QueryTriShapeData_const;
%rename QuerySkinData( blk_ref const & block ) QuerySkinData_const;
%rename QueryNode( blk_ref const & block ) QueryNode_const;
%rename QueryKeyframeData( blk_ref const & block ) QueryKeyframeData_const;
%rename QueryTextKeyExtraData( blk_ref const & block ) QueryTextKeyExtraData_const;
%rename QueryMorphData( blk_ref const & block ) QueryMorphData_const;
%rename QueryTriStripsData( blk_ref const & block ) QueryTriStripsData_const;
%rename QueryColorData( blk_ref const & block ) QueryColorData_const;
%rename QueryFloatData( blk_ref const & block ) QueryFloatData_const;
%rename QueryPosData( blk_ref const & block ) QueryPosData_const;
%rename QueryBoolData( blk_ref const & block ) QueryBoolData_const;
%rename QueryPixelData( blk_ref const & block ) QueryPixelData_const;
%rename QueryPalette( blk_ref const & block ) QueryPalette_const;
%rename QueryControllerSequence( blk_ref const & block ) QueryControllerSequence_const;
%rename QueryTexturingProperty( blk_ref const & block ) QueryTexturingProperty_const;

%include "niflib.h"
