/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISPOTLIGHT_H_
#define _NISPOTLIGHT_H_

#include "NiPointLight.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiSpotLight;
typedef Ref<NiSpotLight> NiSpotLightRef;

/*!
 * NiSpotLight - A spot.
 */

class NIFLIB_API NiSpotLight : public NI_SPOT_LIGHT_PARENT {
public:
	NiSpotLight();
	~NiSpotLight();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * The opening angle of the spot.
	 */
	float GetCutoffAngle() const;
	void SetCutoffAngle( float value );

	/*!
	 * Describes the distribution of light. (see: glLight)
	 */
	float GetExponent() const;
	void SetExponent( float value );

protected:
	NI_SPOT_LIGHT_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
