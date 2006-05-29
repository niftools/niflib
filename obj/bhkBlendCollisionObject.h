/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKBLENDCOLLISIONOBJECT_H_
#define _BHKBLENDCOLLISIONOBJECT_H_

#include "xml_extract.h"
#include BHK_BLEND_COLLISION_OBJECT_INCLUDE

/*
 * bhkBlendCollisionObject
 */

class bhkBlendCollisionObject;
typedef Ref<bhkBlendCollisionObject> bhkBlendCollisionObjectRef;

class bhkBlendCollisionObject : public BHK_BLEND_COLLISION_OBJECT_PARENT {
public:
  bhkBlendCollisionObject();
  ~bhkBlendCollisionObject();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  BHK_BLEND_COLLISION_OBJECT_MEMBERS
};

#endif
