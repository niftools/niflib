/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIAMBIENTLIGHT_H_
#define _NIAMBIENTLIGHT_H_

#include "NiLight.h"

#include "../gen/obj_defines.h"

class NiAmbientLight;
typedef Ref<NiAmbientLight> NiAmbientLightRef;

/*!
 * NiAmbientLight - Ambient light source.
 */

class NIFLIB_API NiAmbientLight : public NI_AMBIENT_LIGHT_PARENT {
public:
	NiAmbientLight();
	~NiAmbientLight();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_AMBIENT_LIGHT_MEMBERS
};

#endif
