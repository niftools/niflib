/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITEXTUREEFFECT_H_
#define _NITEXTUREEFFECT_H_

#include "NiDynamicEffect.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiSourceTexture;

#include "gen/obj_defines.h"

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
	NiTextureEffect();
	~NiTextureEffect();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_TEXTURE_EFFECT_MEMBERS
};

#endif
