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

class NIFLIB_API NiTextureEffect : public NI_TEXTURE_EFFECT_PARENT {
public:
	NiTextureEffect();
	~NiTextureEffect();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Model projection matrix.  Always identity?
	 */
	Matrix33 GetModelProjectionMatrix() const;
	void SetModelProjectionMatrix( Matrix33 value );

	/*!
	 * Model projection transform.  Always (0,0,0)?
	 */
	Vector3 GetModelProjectionTransform() const;
	void SetModelProjectionTransform( Vector3 value );

	/*!
	 * 0: FILTER_NEAREST 1: FILTER_BILERP 2: FILTER_TRILERP (Usual value) 3:
	 * FILTER_NEAREST_MIPNEAREST 4: FILTER_NEAREST_MIPLERP 5:
	 * FILTER_BILERP_MIPNAREST
	 */
	TexFilterMode GetTextureFiltering() const;
	void SetTextureFiltering( TexFilterMode value );

	/*!
	 * 0: CLAMP_S_CLAMP (Common value) 1: CLAMP_S_WRAP 2: WRAP_S_CLAMP_T 3:
	 * WRAP_S_WRAP_T (Common value)
	 */
	TexClampMode GetTextureClamping() const;
	void SetTextureClamping( TexClampMode value );

	/*!
	 * 0: PROJECTED_LIGHT 1: PROJECTED_SHADOW 2: ENVIRONMENT_MAP (Usual
	 * value) 3: FOG_MAP
	 */
	uint GetTextureType() const;
	void SetTextureType( uint value );

	/*!
	 * 0: WORLD_PARALLEL 1: WORLD_PERSPECTIVE 2: SPHERE_MAP (Usual value) 3:
	 * SPECULAR_CUBE_MAP 4: DIFFUSE_CUBE_MAP
	 */
	uint GetCoordinateGenerationType() const;
	void SetCoordinateGenerationType( uint value );

	/*!
	 * Source texture index.
	 */
	Ref<NiSourceTexture > GetSourceTexture() const;
	void SetSourceTexture( Ref<NiSourceTexture > value );

	/*!
	 * 0: Disabled (Usual value) 1: Enabled
	 */
	byte GetClippingPlane() const;
	void SetClippingPlane( byte value );

	/*!
	 * 0?
	 */
	ushort GetPs2L() const;
	void SetPs2L( ushort value );

	/*!
	 * 0xFFB5?
	 */
	ushort GetPs2K() const;
	void SetPs2K( ushort value );

protected:
	NI_TEXTURE_EFFECT_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
