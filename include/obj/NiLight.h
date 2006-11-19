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

class NIFLIB_API NiLight : public NI_LIGHT_PARENT {
public:
	NiLight();
	~NiLight();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Dimmer.
	 */
	float GetDimmer() const;
	void SetDimmer( float value );

	/*!
	 * Ambient color.
	 */
	Color3 GetAmbientColor() const;
	void SetAmbientColor( Color3 value );

	/*!
	 * Diffuse color.
	 */
	Color3 GetDiffuseColor() const;
	void SetDiffuseColor( Color3 value );

	/*!
	 * Specular color.
	 */
	Color3 GetSpecularColor() const;
	void SetSpecularColor( Color3 value );

protected:
	NI_LIGHT_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
