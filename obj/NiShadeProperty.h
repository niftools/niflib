/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISHADEPROPERTY_H_
#define _NISHADEPROPERTY_H_

#include "NiProperty.h"

#include "gen/obj_defines.h"

class NiShadeProperty;
typedef Ref<NiShadeProperty> NiShadePropertyRef;

/*!
 * NiShadeProperty - Determines whether flat shading or smooth shading is
 * used on a shape.
 */

class NiShadeProperty : public NI_SHADE_PROPERTY_PARENT {
public:
	NiShadeProperty();
	~NiShadeProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_SHADE_PROPERTY_MEMBERS
};

#endif
