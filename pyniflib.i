// Swig module description file for a C dynamic library source file
// Generate with: swig -c++ -python -o py_wrap.cpp pyniflib.i

%module niflib
%include "stl.i"
%include "std_map.i"
%include "exception.i"

%exception {
    try {
      $action
    }
    SWIG_CATCH_STDEXCEPT // catch std::exception 
    catch (...) {
     SWIG_exception(SWIG_UnknownError, "Unknown exception");
    }
}

%{
  #include "NIFlib/niflib.h"
%}

namespace std {
	%template(vector_float) vector<float>;
	%template(vector_blk_ref) vector<blk_ref>;
	%template(vector_Vector3D) vector<Vector3D>;
	%template(vector_Color) vector<Color>;
	%template(vector_UVCoord) vector<UVCoord>;
	%template(vector_Triangle) vector<Triangle>;
	%template(vector_SkinWeight) vector<SkinWeight>;
	%template(pair_int_float) pair<int, float>;
	%template(map_int_float) map<int, float>;
};

%include "../NIFlib/niflib.h"


