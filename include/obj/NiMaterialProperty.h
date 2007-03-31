/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMATERIALPROPERTY_H_
#define _NIMATERIALPROPERTY_H_

#include "NiProperty.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiMaterialProperty;
typedef Ref<NiMaterialProperty> NiMaterialPropertyRef;

/*!
 * NiMaterialProperty - Describes the material shading properties.
 */

class NiMaterialProperty : public NI_MATERIAL_PROPERTY_PARENT {
public:
	NIFLIB_API NiMaterialProperty();
	NIFLIB_API ~NiMaterialProperty();
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

	NIFLIB_API unsigned short GetFlags() const;
	NIFLIB_API void SetFlags( unsigned short n );

	NIFLIB_API float GetTransparency() const;
	NIFLIB_API void SetTransparency( float n );

	NIFLIB_API float GetGlossiness() const;
	NIFLIB_API void SetGlossiness( float n );

	NIFLIB_API Color3 GetAmbientColor() const;
	NIFLIB_API void SetAmbientColor( const Color3 & n );

	NIFLIB_API Color3 GetDiffuseColor() const;
	NIFLIB_API void SetDiffuseColor( const Color3 & n );

	NIFLIB_API Color3 GetEmissiveColor() const;
	NIFLIB_API void SetEmissiveColor( const Color3 & n );

	NIFLIB_API Color3 GetSpecularColor() const;
	NIFLIB_API void SetSpecularColor( const Color3 & n );
	

protected:
	NI_MATERIAL_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
