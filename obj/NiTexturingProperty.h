/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITEXTURINGPROPERTY_H_
#define _NITEXTURINGPROPERTY_H_

#include "xml_extract.h"
#include NI_TEXTURING_PROPERTY_INCLUDE

/*
 * NiTexturingProperty
 */

class NiTexturingProperty;
typedef Ref<NiTexturingProperty> NiTexturingPropertyRef;

class NiTexturingProperty : public NI_TEXTURING_PROPERTY_PARENT {
public:
  NiTexturingProperty();
  ~NiTexturingProperty();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_TEXTURING_PROPERTY_MEMBERS
};

#endif
