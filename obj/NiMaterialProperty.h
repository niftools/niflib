/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMATERIALPROPERTY_H_
#define _NIMATERIALPROPERTY_H_

#include "NiProperty.h"

#include "../gen/obj_defines.h"

class NiMaterialProperty;
typedef Ref<NiMaterialProperty> NiMaterialPropertyRef;

/*!
 * NiMaterialProperty - Describes the material shading properties.
 */

class NIFLIB_API NiMaterialProperty : public NI_MATERIAL_PROPERTY_PARENT {
public:
	NiMaterialProperty();
	~NiMaterialProperty();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	ushort GetFlags() const;
	void SetFlags( ushort n );

	float GetTransparency() const;
	void SetTransparency( float n );

	float GetGlossiness() const;
	void SetGlossiness( float n );

	Color3 GetAmbientColor() const;
	void SetAmbientColor( const Color3 & n );

	Color3 GetDiffuseColor() const;
	void SetDiffuseColor( const Color3 & n );

	Color3 GetEmissiveColor() const;
	void SetEmissiveColor( const Color3 & n );

	Color3 GetSpecularColor() const;
	void SetSpecularColor( const Color3 & n );
	

protected:
	NI_MATERIAL_PROPERTY_MEMBERS
};

#endif
