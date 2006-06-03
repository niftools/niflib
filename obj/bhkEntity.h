/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKENTITY_H_
#define _BHKENTITY_H_

#include "bhkWorldObject.h"
#include "Ref.h"
#include "obj/bhkShape.h"

#include "gen/obj_defines.h"

/*
 * bhkEntity
 */

class bhkEntity;
typedef Ref<bhkEntity> bhkEntityRef;

class bhkEntity : public BHK_ENTITY_PARENT {
public:
  bhkEntity();
  ~bhkEntity();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  BHK_ENTITY_MEMBERS
};

#endif
