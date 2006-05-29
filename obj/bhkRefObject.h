/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKREFOBJECT_H_
#define _BHKREFOBJECT_H_

#include "xml_extract.h"
#include BHK_REF_OBJECT_INCLUDE

/*
 * bhkRefObject
 */

class bhkRefObject;
typedef Ref<bhkRefObject> bhkRefObjectRef;

class bhkRefObject : public BHK_REF_OBJECT_PARENT {
public:
  bhkRefObject();
  ~bhkRefObject();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  BHK_REF_OBJECT_MEMBERS
};

#endif
