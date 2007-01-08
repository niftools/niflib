/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIF_BASIC_TYPES_H_
#define _NIF_BASIC_TYPES_H_

#include <string>
#include "gen/enums.h"
namespace Niflib {
using namespace std;

struct HeaderString {
	string header;
};

struct ShortString {
	string str;
};

struct LineString {
	string line;
};

//--Non-mathematical Basic Types--//
#ifndef byte
typedef unsigned char	byte;
#endif

//TODO:  This is temporary to make it compile.  Should eventually be adjusted to display 1's and 0's insted of as an int.
typedef unsigned short Flags;
}
#endif
