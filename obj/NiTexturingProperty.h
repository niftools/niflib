/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITEXTURINGPROPERTY_H_
#define _NITEXTURINGPROPERTY_H_

#include "NiProperty.h"
// Include structures
#include "../gen/TexDesc.h"
#include "../gen/ShaderTexDesc.h"

#include "../gen/obj_defines.h"

class NiTexturingProperty;
typedef Ref<NiTexturingProperty> NiTexturingPropertyRef;

/*!
 * NiTexturingProperty - Describes an object's textures.
 */

class NiTexturingProperty : public NI_TEXTURING_PROPERTY_PARENT {
public:
	NiTexturingProperty();
	~NiTexturingProperty();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*! Retrieves the number of texture slots defined by this texturing propery.  Texture slots may or may not actually contain textures, but each slot has a different meaning so the way a texture is used is dependant upon which slot it is in.
	 * \return The number of texture slots defined by this texturing property.
	 * \sa ITexturingProperty::SetTextureCount
	 */
	int GetTextureCount() const;

	/*! Sets the number of texture slots defined by this texturing propery.  Known valid values are 7 and 8.
	 * \param n The new size of the texture slot array.
	 * \sa ITexturingProperty::GetTextureCount
	 */
	void SetTextureCount( int new_count );

	/*! Retrieves the number of extra texture slots defined by this texturing propery.  These only exist in later Nif versions and their function is unknown.
	 * \return The number of extra texture slots defined by this texturing property.
	 * \sa ITexturingProperty::SetExtraTextureCount
	 */
	int GetShaderTextureCount() const;

	/*! Sets the number of extra texture slots defined by this texturing propery.  Often zero.
	 * \param n The new size of the extra texture slot array.
	 * \sa ITexturingProperty::GetExtraTextureCount
	 */
	void SetShaderTextureCount( int new_count );

	/*! Retrieves the current apply mode for this texturing propery.  This enum value affects the way the textures will be drawn.
	 * \return The current apply mode for this texturing property.
	 * \sa ITexturingProperty::SetApplyMode
	 */
	ApplyMode GetApplyMode() const;

	/*! Sets the current apply mode for this texturing propery.  This enum value affects the way the textures will be drawn.
	 * \param new_val The new apply mode for this texturing property.
	 * \sa ITexturingProperty::GetApplyMode
	 */
	void SetApplyMode( ApplyMode new_val );

	/*! Retrieves the texture desription structure that describes a texture by slot number.  The TexType enum is provided to make it easy to select the texture slot with the specific qualities that you want.
	 * \param n The slot number of the texture to get the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \sa ITexturingProperty::SetTexture, TexType
	 */
	TexDesc GetTexture( int n ) const;

	/*! Sets a new description for the texture in the given slot number.  The TexType enum is provided to make it easy to select the texture slot with the specific qualities that you want.
	 * \param n The slot number of the texture to set the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \param new_val Thew new texture descriptoin for the texture at the given slot number.
	 * \sa ITexturingProperty::GetTexture, TexType
	 */
	void SetTexture( int n, TexDesc & new_val );

	/*! Retrieves the texture desription structure that describes an extra texture by slot number.  These only exist in the later Nif versions and their function is unknown.
	 * \param n The slot number of the extra texture to get the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetExtraTextureCount.
	 * \sa ITexturingProperty::SetExtraTexture
	 */
	TexDesc GetShaderTexture( int n ) const;

	/*! Sets a new description for the texture in the given slot number.  These only exist in the later Nif versions and their function is unknown.
	 * \param n The slot number of the extra texture to set the texture description of.  This is a positive zero based index that must be less than the value returned by ITexturingProperty::GetTextureCount.
	 * \param new_val Thew new texture descriptoin for the extra texture at the given slot number.
	 * \sa ITexturingProperty::GetTexture, TexType
	 */
	void SetShaderTexture( int n, TexDesc & new_val );

	/*! Retrieves the bump map luma offset.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return The bump map luma offset.
	 * \sa ITexturingProperty::SetLumaOffset
	 */
	float GetLumaOffset() const;

	/*! Sets the bump map luma offset.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map luma offset.
	 * \sa ITexturingProperty::GetLumaOffset
	 */
	void SetLumaOffset( float new_val );

	/*! Retrieves the bump map luma scale.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return The bump map luma scale.
	 * \sa ITexturingProperty::SetLumaScale
	 */
	float GetLumaScale() const;

	/*! Sets the bump map luma scale.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map luma scale.
	 * \sa ITexturingProperty::GetLumaScale
	 */
	void SetLumaScale( float new_val );

	/*! Retrieves the bump map matrix.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return the bump map matrix.
	 * \sa ITexturingProperty::SetBumpMapMatrix
	 */
	Matrix22 GetBumpMapMatrix() const;

	/*! Sets the bump map matrix.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map matrix.
	 * \sa ITexturingProperty::GetBumpMapMatrix
	 */
	void SetBumpMapMatrix( Matrix22 & new_val );

protected:
	NI_TEXTURING_PROPERTY_MEMBERS
};

#endif
