/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMATERIALPROPERTY_H_
#define _NIMATERIALPROPERTY_H_

#include "xml_extract.h"
#include NI_MATERIAL_PROPERTY_INCLUDE

/*
 * NiMaterialProperty
 */

class NiMaterialProperty;
typedef Ref<NiMaterialProperty> NiMaterialPropertyRef;

class NiMaterialProperty : public NI_MATERIAL_PROPERTY_PARENT {
public:
	NiMaterialProperty();
	~NiMaterialProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	NI_MATERIAL_PROPERTY_MEMBERS
};
#endif
