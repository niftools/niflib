/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIALPHAPROPERTY_H_
#define _NIALPHAPROPERTY_H_

#include "xml_extract.h"
#include NI_ALPHA_PROPERTY_INCLUDE

/*
 * NiAlphaProperty
 */

class NiAlphaProperty;
typedef Ref<NiAlphaProperty> NiAlphaPropertyRef;

class NiAlphaProperty : public NI_ALPHA_PROPERTY_PARENT {
public:
	NiAlphaProperty();
	~NiAlphaProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_ALPHA_PROPERTY_MEMBERS
};
#endif
