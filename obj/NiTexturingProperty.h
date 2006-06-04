/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITEXTURINGPROPERTY_H_
#define _NITEXTURINGPROPERTY_H_

#include "NiProperty.h"
// Include structures
#include "gen/TexDesc.h"
#include "gen/ShaderTexDesc.h"

#include "gen/obj_defines.h"

class NiTexturingProperty;
typedef Ref<NiTexturingProperty> NiTexturingPropertyRef;

/*!
 * NiTexturingProperty - Describes an object's textures.
 */

class NiTexturingProperty : public NI_TEXTURING_PROPERTY_PARENT {
public:
	NiTexturingProperty();
	~NiTexturingProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_TEXTURING_PROPERTY_MEMBERS
};

#endif
