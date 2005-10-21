niflib.so: pyniflib_wrap.o niflib.o
	g++ -shared pyniflib_wrap.o niflib.o -o _niflib.so

niflib.py pyniflib_wrap.cxx: pyniflib.i
	swig -c++ -python pyniflib.i

pyniflib_wrap.o: pyniflib_wrap.cxx
	g++ -I/usr/include/python2.3/ -c pyniflib_wrap.cxx

clean:
	rm -f _niflib.so pyniflib_wrap.o niflib.o niflib.py pyniflib_wrap.cxx

niflib.o: niflib.h niflib.cpp
	g++ -c niflib.cpp
