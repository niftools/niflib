/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NILIGHT_H_
#define _NILIGHT_H_

#include "NiDynamicEffect.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiLight;
typedef Ref<NiLight> NiLightRef;

/*!
 * NiLight - Light source.
 */

class NiLight : public NI_LIGHT_PARENT {
public:
	NIFLIB_API NiLight();
	NIFLIB_API ~NiLight();
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
	 * Gets the current dimmer value for this light.  Used to turn the light intensity up or down.
	 * \return The current dimmer value.
	 */
	NIFLIB_API float GetDimmer() const;

	/*!
	 * Sets the dimmer value for this light.  Used to turn the light intensity up or down.
	 * \param[in] value The new dimmer value.
	 */
	NIFLIB_API void SetDimmer( float value );

	/*!
	 * Gets the current ambient color of this light.
	 * \return The current ambient color.
	 */
	NIFLIB_API Color3 GetAmbientColor() const;

	/*!
	 * Sets the ambient color of this light.
	 * \param[in] value The new ambient color.
	 */
	NIFLIB_API void SetAmbientColor( Color3 value );

	/*!
	 * Gets the current diffuse color of this light.
	 * \return The current diffuse color.
	 */
	NIFLIB_API Color3 GetDiffuseColor() const;

	/*!
	 * Sets the diffuse color of this light.
	 * \param[in] value The new diffuse color.
	 */
	NIFLIB_API void SetDiffuseColor( Color3 value );

	/*!
	 * Gets the current specular color of this light.
	 * \return The current specular color.
	 */
	NIFLIB_API Color3 GetSpecularColor() const;

	/*!
	 * Sets the specular color of this light.
	 * \param[in] value The new specular color.
	 */
	NIFLIB_API void SetSpecularColor( Color3 value );

protected:
	NI_LIGHT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
