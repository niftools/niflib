niflib.so: pyniflib_wrap.o niflib.o nif_io.o nif_math.o nif_blocks.o
	g++ -shared niflib.o nif_io.o nif_math.o nif_blocks.o pyniflib_wrap.o -o _niflib.so

niflib.py pyniflib_wrap.cxx: pyniflib.i
	swig -c++ -python pyniflib.i

pyniflib_wrap.o: pyniflib_wrap.cxx
	g++ -fPIC -I/usr/include/python2.3/ -c pyniflib_wrap.cxx

clean:
	rm -f *.so *.o niflib.py pyniflib_wrap.cxx

niflib.o: niflib.h niflib.cpp
	g++ -fPIC -c niflib.cpp -o niflib.o

nif_io.o: NIF_IO.h NIF_IO.cpp
	g++ -fPIC -c NIF_IO.cpp -o nif_io.o

nif_math.o: nif_math.h nif_math.cpp
	g++ -fPIC -c nif_math.cpp -o nif_math.o

nif_blocks.o: NIF_Blocks.h NIF_IO.h NIF_Blocks.cpp
	g++ -fPIC -c NIF_Blocks.cpp -o nif_blocks.o
