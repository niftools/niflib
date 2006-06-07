/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _TYPE_H_
#define _TYPE_H_

#include <string>

using namespace std;

/**
 * Run Time Type Inforamtion Class
 */
class DLLEXPORT Type {
public:
	Type (const string & type_name, const Type * par_type );
	~Type();

	string GetTypeName() const;

	bool IsSameType ( const Type & compare_to ) const;
	bool IsDerivedType ( const Type & compare_to ) const;
	bool operator<( const Type & compare_to ) const;
private:
	string name;
	const Type * base_type;
};

#endif
