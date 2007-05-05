/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NiTexturingProperty_H_
#define _NiTexturingProperty_H_

#include "NiProperty.h"
// Include structures
#include "../gen/TexDesc.h"
#include "../gen/ShaderTexDesc.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiTexturingProperty;
typedef Ref<NiTexturingProperty> NiTexturingPropertyRef;

/*!
 * NiTexturingProperty - Describes an object's textures.
 */

class NiTexturingProperty : public NI_TEXTURING_PROPERTY_PARENT {
public:
	NIFLIB_API NiTexturingProperty();
	NIFLIB_API ~NiTexturingProperty();
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
	 * Retrieves the number of texture slots defined by this texturing propery.  Texture slots may or may not actually contain textures, but each slot has a different meaning so the way a texture is used is dependant upon which slot it is in.
	 * \return The number of texture slots defined by this texturing property.
	 * \sa NiTexturingProperty::SetTextureCount
	 */
	NIFLIB_API int GetTextureCount() const;

	/*!
	 * Sets the number of texture slots defined by this texturing propery.  Known valid values are 7 and 8.
	 * \param new_count The new size of the texture slot array.
	 * \sa NiTexturingProperty::GetTextureCount
	 */
	NIFLIB_API void SetTextureCount( int new_count );

	/*! 
	 * Retrieves the number of extra texture slots defined by this texturing propery.  These only exist in later Nif versions and their function is unknown.
	 * \return The number of extra texture slots defined by this texturing property.
	 * \sa NiTexturingProperty::SetExtraTextureCount
	 */
	NIFLIB_API int GetShaderTextureCount() const;

	/*! 
	 * Sets the number of extra texture slots defined by this texturing propery.  Often zero.
	 * \param new_count The new size of the extra texture slot array.
	 * \sa NiTexturingProperty::GetExtraTextureCount
	 */
	NIFLIB_API void SetShaderTextureCount( int new_count );

	/*! 
	 * Retrieves the current apply mode for this texturing propery.  This enum value affects the way the textures will be drawn.
	 * \return The current apply mode for this texturing property.
	 * \sa NiTexturingProperty::SetApplyMode
	 */
	NIFLIB_API ApplyMode GetApplyMode() const;

	/*! 
	 * Sets the current apply mode for this texturing propery.  This enum value affects the way the textures will be drawn.
	 * \param new_val The new apply mode for this texturing property.
	 * \sa NiTexturingProperty::GetApplyMode
	 */
	NIFLIB_API void SetApplyMode( ApplyMode new_val );

	/*! 
	 * Retrieves the texture desription structure that describes a texture by slot number.  The TexType enum is provided to make it easy to select the texture slot with the specific qualities that you want.
	 * \param n The slot number of the texture to get the texture description of.  This is a positive zero based index that must be less than the value returned by NiTexturingProperty::GetTextureCount.
	 * \sa NiTexturingProperty::SetTexture, TexType
	 */
	NIFLIB_API TexDesc GetTexture( int n ) const;

	/*! 
	 * Checks whether a particular texture type is being used
	 * \param n The slot number of the texture to check.  This is a positive zero based index that must be less than the value returned by NiTexturingProperty::GetTextureCount.
	 * \return true if the texture in this slot is used, false otherwise.
	 */
	NIFLIB_API bool HasTexture( int n ) const;

	/*! 
	 * Clears a specific texture slot.
	 * \param n The slot number of the texture to clear.  This is a positive zero based index that must be less than the value returned by NiTexturingProperty::GetTextureCount.
	 */
	NIFLIB_API void ClearTexture( int n );

	/*! 
	 * Sets a new description for the texture in the given slot number.  The TexType enum is provided to make it easy to select the texture slot with the specific qualities that you want.
	 * \param n The slot number of the texture to set the texture description of.  This is a positive zero based index that must be less than the value returned by NiTexturingProperty::GetTextureCount.
	 * \param new_val Thew new texture descriptoin for the texture at the given slot number.
	 * \sa NiTexturingProperty::GetTexture, TexType
	 */
	NIFLIB_API void SetTexture( int n, TexDesc & new_val );

	/*! 
	 * Retrieves the texture desription structure that describes an extra texture by slot number.  These only exist in the later Nif versions and their function is unknown.
	 * \param n The slot number of the extra texture to get the texture description of.  This is a positive zero based index that must be less than the value returned by NiTexturingProperty::GetExtraTextureCount.
	 * \sa NiTexturingProperty::SetExtraTexture
	 */
	NIFLIB_API TexDesc GetShaderTexture( int n ) const;

	/*! 
	 * Sets a new description for the texture in the given slot number.  These only exist in the later Nif versions and their function is unknown.
	 * \param n The slot number of the extra texture to set the texture description of.  This is a positive zero based index that must be less than the value returned by NiTexturingProperty::GetTextureCount.
	 * \param new_val Thew new texture descriptoin for the extra texture at the given slot number.
	 * \sa NiTexturingProperty::GetTexture, TexType
	 */
	NIFLIB_API void SetShaderTexture( int n, TexDesc & new_val );

	/*! 
	 * Retrieves the bump map luma offset.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return The bump map luma offset.
	 * \sa NiTexturingProperty::SetLumaOffset
	 */
	NIFLIB_API float GetLumaOffset() const;

	/*! 
	 * Sets the bump map luma offset.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map luma offset.
	 * \sa NiTexturingProperty::GetLumaOffset
	 */
	NIFLIB_API void SetLumaOffset( float new_val );

	/*! 
	 * Retrieves the bump map luma scale.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return The bump map luma scale.
	 * \sa NiTexturingProperty::SetLumaScale
	 */
	NIFLIB_API float GetLumaScale() const;

	/*! 
	 * Sets the bump map luma scale.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map luma scale.
	 * \sa NiTexturingProperty::GetLumaScale
	 */
	NIFLIB_API void SetLumaScale( float new_val );

	/*! 
	 * Retrieves the bump map matrix.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \return the bump map matrix.
	 * \sa NiTexturingProperty::SetBumpMapMatrix
	 */
	NIFLIB_API Matrix22 GetBumpMapMatrix() const;

	/*! 
	 * Sets the bump map matrix.  This is only relevant if a texture is defined in the BUMP_MAP texture slot.  The function of this is unknown.
	 * \param new_val The new bump map matrix.
	 * \sa NiTexturingProperty::GetBumpMapMatrix
	 */
	NIFLIB_API void SetBumpMapMatrix( Matrix22 & new_val );

protected:
	NI_TEXTURING_PROPERTY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
