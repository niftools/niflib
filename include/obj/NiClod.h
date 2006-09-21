/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICLOD_H_
#define _NICLOD_H_

#include "NiTriBasedGeom.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiClod;
typedef Ref<NiClod> NiClodRef;

/*!
 * NiClod - A shape node that refers to singular triangle data.
 */

class NIFLIB_API NiClod : public NI_CLOD_PARENT {
public:
	NiClod();
	~NiClod();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_CLOD_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
