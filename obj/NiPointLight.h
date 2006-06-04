/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPOINTLIGHT_H_
#define _NIPOINTLIGHT_H_

#include "NiLight.h"

#include "gen/obj_defines.h"

class NiPointLight;
typedef Ref<NiPointLight> NiPointLightRef;

/*!
 * NiPointLight - A point light.
 */

class NiPointLight : public NI_POINT_LIGHT_PARENT {
public:
	NiPointLight();
	~NiPointLight();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_POINT_LIGHT_MEMBERS
};

#endif
