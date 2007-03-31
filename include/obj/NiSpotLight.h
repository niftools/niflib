/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISPOTLIGHT_H_
#define _NISPOTLIGHT_H_

#include "NiPointLight.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiSpotLight;
typedef Ref<NiSpotLight> NiSpotLightRef;

/*!
 * NiSpotLight - A spot.
 */

class NiSpotLight : public NI_SPOT_LIGHT_PARENT {
public:
	NIFLIB_API NiSpotLight();
	NIFLIB_API ~NiSpotLight();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * The opening angle of the spot.
	 */
	NIFLIB_API float GetCutoffAngle() const;
	NIFLIB_API void SetCutoffAngle( float value );

	/*!
	 * Describes the distribution of light. (see: glLight)
	 */
	NIFLIB_API float GetExponent() const;
	NIFLIB_API void SetExponent( float value );

protected:
	NI_SPOT_LIGHT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
