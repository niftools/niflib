/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITEXTUREEFFECT_H_
#define _NITEXTUREEFFECT_H_

#include "NiDynamicEffect.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiSourceTexture;

//#include "../gen/obj_defines.h"

class NiTextureEffect;
typedef Ref<NiTextureEffect> NiTextureEffectRef;

/*!
 * NiTextureEffect - Enables environment mapping. Should be in both the
 * children list and effects list of the NiTriShape block. For Morrowind:
 * the bump map can be used to bump the environment map (note that the
 * bump map is ignored if no NiTextureEffect block is present).
 */

class NiTextureEffect : public NI_TEXTURE_EFFECT_PARENT {
public:
	NIFLIB_API NiTextureEffect();
	NIFLIB_API ~NiTextureEffect();
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

	/*!
	 * Model projection matrix.  Always identity?
	 */
	NIFLIB_API Matrix33 GetModelProjectionMatrix() const;
	NIFLIB_API void SetModelProjectionMatrix( Matrix33 value );

	/*!
	 * Model projection transform.  Always (0,0,0)?
	 */
	NIFLIB_API Vector3 GetModelProjectionTransform() const;
	NIFLIB_API void SetModelProjectionTransform( Vector3 value );

	/*!
	 * 0: FILTER_NEAREST 1: FILTER_BILERP 2: FILTER_TRILERP (Usual value) 3:
	 * FILTER_NEAREST_MIPNEAREST 4: FILTER_NEAREST_MIPLERP 5:
	 * FILTER_BILERP_MIPNAREST
	 */
	NIFLIB_API TexFilterMode GetTextureFiltering() const;
	NIFLIB_API void SetTextureFiltering( TexFilterMode value );

	/*!
	 * 0: CLAMP_S_CLAMP (Common value) 1: CLAMP_S_WRAP 2: WRAP_S_CLAMP_T 3:
	 * WRAP_S_WRAP_T (Common value)
	 */
	NIFLIB_API TexClampMode GetTextureClamping() const;
	NIFLIB_API void SetTextureClamping( TexClampMode value );

	/*!
	 * 0: PROJECTED_LIGHT 1: PROJECTED_SHADOW 2: ENVIRONMENT_MAP (Usual
	 * value) 3: FOG_MAP
	 */
	NIFLIB_API unsigned int GetTextureType() const;
	NIFLIB_API void SetTextureType( unsigned int value );

	/*!
	 * 0: WORLD_PARALLEL 1: WORLD_PERSPECTIVE 2: SPHERE_MAP (Usual value) 3:
	 * SPECULAR_CUBE_MAP 4: DIFFUSE_CUBE_MAP
	 */
	NIFLIB_API unsigned int GetCoordinateGenerationType() const;
	NIFLIB_API void SetCoordinateGenerationType( unsigned int value );

	/*!
	 * Source texture index.
	 */
	NIFLIB_API Ref<NiSourceTexture > GetSourceTexture() const;
	NIFLIB_API void SetSourceTexture( Ref<NiSourceTexture > value );

	/*!
	 * 0: Disabled (Usual value) 1: Enabled
	 */
	NIFLIB_API byte GetClippingPlane() const;
	NIFLIB_API void SetClippingPlane( byte value );

	/*!
	 * 0?
	 */
	NIFLIB_API unsigned short GetPs2L() const;
	NIFLIB_API void SetPs2L( unsigned short value );

	/*!
	 * 0xFFB5?
	 */
	NIFLIB_API unsigned short GetPs2K() const;
	NIFLIB_API void SetPs2K( unsigned short value );

protected:
	NI_TEXTURE_EFFECT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
