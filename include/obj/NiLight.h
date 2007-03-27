/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

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
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
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
	 * Dimmer.
	 */
	NIFLIB_API float GetDimmer() const;
	NIFLIB_API void SetDimmer( float value );

	/*!
	 * Ambient color.
	 */
	NIFLIB_API Color3 GetAmbientColor() const;
	NIFLIB_API void SetAmbientColor( Color3 value );

	/*!
	 * Diffuse color.
	 */
	NIFLIB_API Color3 GetDiffuseColor() const;
	NIFLIB_API void SetDiffuseColor( Color3 value );

	/*!
	 * Specular color.
	 */
	NIFLIB_API Color3 GetSpecularColor() const;
	NIFLIB_API void SetSpecularColor( Color3 value );

protected:
	NI_LIGHT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
