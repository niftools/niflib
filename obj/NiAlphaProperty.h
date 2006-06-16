/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIALPHAPROPERTY_H_
#define _NIALPHAPROPERTY_H_

#include "NiProperty.h"

#include "../gen/obj_defines.h"

class NiAlphaProperty;
typedef Ref<NiAlphaProperty> NiAlphaPropertyRef;

/*!
 * NiAlphaProperty - Transparency. Flags 0x00ED.
 */

class NIFLIB_API NiAlphaProperty : public NI_ALPHA_PROPERTY_PARENT {
public:
	NiAlphaProperty();
	~NiAlphaProperty();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	ushort GetFlags() const;
	void SetFlags( ushort n );

	byte GetAlphaTestThreshold() const;
	void SetAlphaTestThreshold( byte n );
protected:
	NI_ALPHA_PROPERTY_MEMBERS
};

#endif
