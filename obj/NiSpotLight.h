/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISPOTLIGHT_H_
#define _NISPOTLIGHT_H_

#include "NiPointLight.h"

#include "gen/obj_defines.h"

class NiSpotLight;
typedef Ref<NiSpotLight> NiSpotLightRef;

/*!
 * NiSpotLight - A spot.
 */

class NiSpotLight : public NI_SPOT_LIGHT_PARENT {
public:
	NiSpotLight();
	~NiSpotLight();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_SPOT_LIGHT_MEMBERS
};

#endif
