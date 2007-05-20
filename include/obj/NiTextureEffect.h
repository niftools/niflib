/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NITEXTUREEFFECT_H_
#define _NITEXTUREEFFECT_H_

#include "NiDynamicEffect.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiSourceTexture;

//#include "../gen/obj_defines.h"

class NiTextureEffect;
typedef Ref<NiTextureEffect> NiTextureEffectRef;

/*!
 * NiTextureEffect - Enables environment mapping. Should be in both the
 * children list and effects list of the NiTriShape object. For Morrowind:
 * the bump map can be used to bump the environment map (note that the
 * bump map is ignored if no NiTextureEffect object is present).
 */

class NiTextureEffect : public NI_TEXTURE_EFFECT_PARENT {
public:
	NIFLIB_API NiTextureEffect();
	NIFLIB_API ~NiTextureEffect();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*!
	 * Retrives the model projection matrix of this effect.  This always seems to be set to the identity.
	 * \return The model projection matrix.
	 */
	NIFLIB_API Matrix33 GetModelProjectionMatrix() const;

	/*!
	 * Sets the model projection matrix of this effect.  This always seems to be set to the identity.
	 * \param[in] value The new model projection matrix.
	 */
	NIFLIB_API void SetModelProjectionMatrix( Matrix33 value );

	/*!
	 * Retrieves the model projection transform of this effect.  This always seems to be set to (0,0,0).
	 * \return The model projection transform.
	 */
	NIFLIB_API Vector3 GetModelProjectionTransform() const;

	/*!
	 * Sets the model projection transform of this effect.  This always seems to be set to (0,0,0).
	 * \param[in] value The new model projection transform.
	 */
	NIFLIB_API void SetModelProjectionTransform( Vector3 value );

	/*!
	 * Retrieves the texture filtering mode used by this effect.
	 * \return The texture filtering mode.
	 */
	NIFLIB_API TexFilterMode GetTextureFiltering() const;

	/*!
	 * Sets the texture filtering mode used by this effect.
	 * \param[in] value The new texture filtering mode.
	 */
	NIFLIB_API void SetTextureFiltering( TexFilterMode value );

	/*!
	 * Retrieves the texture clamping mode used by this effect.
	 * \return The texture clamping mode.
	 */
	NIFLIB_API TexClampMode GetTextureClamping() const;

	/*!
	 * Sets the texture clamping mode used by this effect.
	 * \param[in] value The new texture clamping mode.
	 */
	NIFLIB_API void SetTextureClamping( TexClampMode value );

	/*!
	 * Retrieves the texture type used by this effect.  Valid values are:
	 * 0: PROJECTED_LIGHT
	 * 1: PROJECTED_SHADOW
	 * 2: ENVIRONMENT_MAP (Usual value)
	 * 3: FOG_MAP
	 * \return The texture type.
	 */
	NIFLIB_API unsigned int GetTextureType() const;

	/*!
	 * Sets the texture type used by this effect.  Valid values are:
	 * 0: PROJECTED_LIGHT
	 * 1: PROJECTED_SHADOW
	 * 2: ENVIRONMENT_MAP (Usual value)
	 * 3: FOG_MAP
	 * \param[in] value The new texture type.
	 */
	NIFLIB_API void SetTextureType( unsigned int value );

	/*!
	 * Retrieves the texture coordinate generation mode.  Valid values are:
	 * 0: WORLD_PARALLEL
	 * 1: WORLD_PERSPECTIVE
	 * 2: SPHERE_MAP (Usual value)
	 * 3: SPECULAR_CUBE_MAP
	 * 4: DIFFUSE_CUBE_MAP
	 * \return The texture coordinate generation mode.
	 */
	NIFLIB_API unsigned int GetCoordinateGenerationType() const;

	/*!
	 * Sets the texture coordinate generation mode.  Valid values are:
	 * 0: WORLD_PARALLEL
	 * 1: WORLD_PERSPECTIVE
	 * 2: SPHERE_MAP (Usual value)
	 * 3: SPECULAR_CUBE_MAP
	 * 4: DIFFUSE_CUBE_MAP
	 * \return The new texture coordinate generation mode.
	 */
	NIFLIB_API void SetCoordinateGenerationType( unsigned int value );

	/*!
	 * Retrieves the source texture index.
	 * \return The source texture index.
	 */
	NIFLIB_API Ref<NiSourceTexture > GetSourceTexture() const;

	/*!
	 * Sets the source texture index.
	 * \param[in] value The new source texture index.
	 */
	NIFLIB_API void SetSourceTexture( Ref<NiSourceTexture > value );

	/*!
	 * Retrieves the clipping plane behavior.  Valid values are:
	 * 0: Disabled (Usual value)
	 * 1: Enabled
	 * \return The clipping plane behavior.
	 */
	NIFLIB_API byte GetClippingPlane() const;

	/*!
	 * Sets the clipping plane behavior.  Valid values are:
	 * 0: Disabled (Usual value)
	 * 1: Enabled
	 * \param[in] value The new clipping plane behavior.
	 */
	NIFLIB_API void SetClippingPlane( byte value );

	/*!
	 * Retrieves a Playstation 2 - specific value.  Can just be left at the default of 0.
	 * \return The PS2 L value.
	 */
	NIFLIB_API unsigned short GetPs2L() const;

	/*!
	 * Sets a Playstation 2 - specific value.  Can just be left at the default of 0.
	 * \param[in] The new PS2 L value.
	 */
	NIFLIB_API void SetPs2L( unsigned short value );

	/*!
	 * Retrieves a Playstation 2 - specific value.  Can just be left at the default of 0xFFB5.
	 * \return The PS2 K value.
	 */
	NIFLIB_API unsigned short GetPs2K() const;

	/*!
	 * Sets a Playstation 2 - specific value.  Can just be left at the default of 0xFFB5.
	 * \param[in] The new PS2 K value.
	 */
	NIFLIB_API void SetPs2K( unsigned short value );

	//--END CUSTOM CODE--//

protected:
	NI_TEXTURE_EFFECT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
