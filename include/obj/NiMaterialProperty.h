/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Can be used to get the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \return The flag data.
	 */
	NIFLIB_API unsigned short GetFlags() const;

	/*!
	 * Can be used to set the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \param[in] n The new flag data.  Will overwrite any existing flag data.
	 */
	NIFLIB_API void SetFlags( unsigned short n );

	/*!
	 * Gets the current transparency of this material.
	 * \return The current transparency.
	 */
	NIFLIB_API float GetTransparency() const;

	/*!
	 * Sets the current transparency of this material.
	 * \param[in] n The new transparency.
	 */
	NIFLIB_API void SetTransparency( float n );

	/*!
	 * Gets the current ambient color of this material.  This determines how the material reacts to the ambient color of any lights shining on it.  Should ususally be (1,1,1).
	 * \return The current ambient color.
	 */
	NIFLIB_API Color3 GetAmbientColor() const;

	/*!
	 * Sets the ambient color of this material.  This determines how the material reacts to the ambient color of any lights shining on it.  Should ususally be (1,1,1).
	 * \param[in] n The new ambient color.
	 */
	NIFLIB_API void SetAmbientColor( const Color3 & n );

	/*!
	 * Gets the diffuse color of this material.  This is the main color of the material.  Should be (1,1,1) if a texture is present.
	 * \return The current diffuse color.
	 */
	NIFLIB_API Color3 GetDiffuseColor() const;

	/*!
	 * Sets the diffuse color of this material.  This is the main color of the material.  Should be (1,1,1) if a texture is present.
	 * \param[in] n The new diffuse color.
	 */
	NIFLIB_API void SetDiffuseColor( const Color3 & n );

	/*!
	 * Gets the current emissive color of this material.  This is an extra color component use for objects that glow.  It makes affected objects look brighter than they would normally if set to something other than black.
	 * \return The current emissive color.
	 */
	NIFLIB_API Color3 GetEmissiveColor() const;

	/*!
	 * Sets the emissive color of this material.  This is an extra color component use for objects that glow.  It makes affected objects look brighter than they would normally if set to something other than black.
	 * \param[in] n The new emissive color.
	 */
	NIFLIB_API void SetEmissiveColor( const Color3 & n );

	/*!
	 * Gets the current specular color of this material.  This is the color of bright highlights that appear if specular lighting is enabled.  The exact look of the hilights depends on the glossiness setting of the material.
	 * \return The current specular color.
	 */
	NIFLIB_API Color3 GetSpecularColor() const;

	/*!
	 * Sets the specular color of this material.  This is the color of bright highlights that appear if specular lighting is enabled.  The exact look of the hilights depends on the glossiness setting of the material.
	 * \param[in] n The new specular color.
	 */
	NIFLIB_API void SetSpecularColor( const Color3 & n );

	/*!
	 * Gets the current glossiness of this material.  This determines how it reflects specular light.  Also known as shininess.
	 * \return The current glossiness.
	 */
	NIFLIB_API float GetGlossiness() const;

	/*!
	 * Sets the glossiness of this material.  This determines how it reflects specular light.  Also known as shininess.
	 * \param[in] n The new glossiness.
	 */
	NIFLIB_API void SetGlossiness( float n );

protected:
	NI_MATERIAL_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
