/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKINPARTITION_H_
#define _NISKINPARTITION_H_

#include "NiObject.h"
#include "gen/SkinPartition.h"

#include "gen/obj_defines.h"

/*
 * NiSkinPartition
 */

class NiSkinPartition;
typedef Ref<NiSkinPartition> NiSkinPartitionRef;

class NiSkinPartition : public NI_SKIN_PARTITION_PARENT {
public:
  NiSkinPartition();
  ~NiSkinPartition();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_SKIN_PARTITION_MEMBERS
};

#endif
