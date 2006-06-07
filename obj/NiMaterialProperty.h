/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMATERIALPROPERTY_H_
#define _NIMATERIALPROPERTY_H_

#include "NiProperty.h"

#include "../gen/obj_defines.h"

class NiMaterialProperty;
typedef Ref<NiMaterialProperty> NiMaterialPropertyRef;

/*!
 * NiMaterialProperty - Describes the material shading properties.
 */

class NIFLIB_API NiMaterialProperty : public NI_MATERIAL_PROPERTY_PARENT {
public:
	NiMaterialProperty();
	~NiMaterialProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_MATERIAL_PROPERTY_MEMBERS
};

#endif
