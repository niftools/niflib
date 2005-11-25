rem Windows Niflib Python wrapper compilation script (using the Visual C++ Toolkit & SWIG 1.3.27)
"\Program Files\swigwin-1.3.27\swig.exe" -c++ -python -o py_wrap.cpp pyniflib.i
cl /LD /EHsc /I"\Program Files\Python24\include" /I. /Fe"_niflib.dll" niflib.cpp docsys_extract.cpp NIF_Blocks.cpp NIF_IO.cpp nif_math.cpp py_wrap.cpp "\Program Files\Python24\libs\python24.lib"
