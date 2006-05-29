/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITEXTUREEFFECT_H_
#define _NITEXTUREEFFECT_H_

#include "xml_extract.h"
#include NI_TEXTURE_EFFECT_INCLUDE

/*
 * NiTextureEffect
 */

class NiTextureEffect;
typedef Ref<NiTextureEffect> NiTextureEffectRef;

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
  virtual const Type & GetType() const;
protected:
  NI_TEXTURE_EFFECT_MEMBERS
};

#endif
