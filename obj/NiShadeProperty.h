/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISHADEPROPERTY_H_
#define _NISHADEPROPERTY_H_

#include "xml_extract.h"
#include NI_SHADE_PROPERTY_INCLUDE

/*
 * NiShadeProperty
 */

class NiShadeProperty;
typedef Ref<NiShadeProperty> NiShadePropertyRef;

class NiShadeProperty : public NI_SHADE_PROPERTY_PARENT {
public:
	NiShadeProperty();
	~NiShadeProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_SHADE_PROPERTY_MEMBERS
};
#endif
