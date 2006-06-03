/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKININSTANCE_H_
#define _NISKININSTANCE_H_

#include "NiObject.h"
#include "Ref.h"
#include "obj/NiSkinData.h"
#include "obj/NiSkinPartition.h"
#include "gen/Bones.h"
class NiNode;

#include "gen/obj_defines.h"

/*
 * NiSkinInstance
 */

class NiSkinInstance;
typedef Ref<NiSkinInstance> NiSkinInstanceRef;

class NiSkinInstance : public NI_SKIN_INSTANCE_PARENT {
public:
  NiSkinInstance();
  ~NiSkinInstance();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NiNode * NiSkinInstance::SkeletonRoot() const;
  NI_SKIN_INSTANCE_MEMBERS
};

#endif
