/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the opening angle of the spot light.
	 * \return The cutoff angle.
	 */
	NIFLIB_API float GetCutoffAngle() const;

	/*!
	 * Sets the opening angle of the spot light.
	 * \param[in] value The new cutoff angle.
	 */
	NIFLIB_API void SetCutoffAngle( float value );

	/*!
	 * Retrieves the exponent of this spot light.  This describes the distribution of light.  See glLight in OpenGL.
	 * \return The exponent value.
	 */
	NIFLIB_API float GetExponent() const;

	/*!
	 * Sets the exponent of this spot light.  This describes the distribution of light.  See glLight in OpenGL.
	 * \param[in] value The new exponent value.
	 */
	NIFLIB_API void SetExponent( float value );

protected:
	NI_SPOT_LIGHT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
