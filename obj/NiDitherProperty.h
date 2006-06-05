/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIDITHERPROPERTY_H_
#define _NIDITHERPROPERTY_H_

#include "NiProperty.h"

#include "../gen/obj_defines.h"

class NiDitherProperty;
typedef Ref<NiDitherProperty> NiDitherPropertyRef;

/*!
 * NiDitherProperty - Unknown.
 */

class NiDitherProperty : public NI_DITHER_PROPERTY_PARENT {
public:
	NiDitherProperty();
	~NiDitherProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_DITHER_PROPERTY_MEMBERS
};

#endif
