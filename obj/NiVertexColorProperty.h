/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIVERTEXCOLORPROPERTY_H_
#define _NIVERTEXCOLORPROPERTY_H_

#include "NiProperty.h"

#include "../gen/obj_defines.h"

class NiVertexColorProperty;
typedef Ref<NiVertexColorProperty> NiVertexColorPropertyRef;

/*!
 * NiVertexColorProperty - Property of vertex colors. This block is
 * referred to by the root block of the NIF file whenever some
 * NiTriShapeData block has vertex colors with non-default settings; if
 * not present, vertex colors have vertex_mode=2 and lighting_mode=1.
 */

class NiVertexColorProperty : public NI_VERTEX_COLOR_PROPERTY_PARENT {
public:
	NiVertexColorProperty();
	~NiVertexColorProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_VERTEX_COLOR_PROPERTY_MEMBERS
};

#endif
