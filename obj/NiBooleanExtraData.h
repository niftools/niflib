/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBOOLEANEXTRADATA_H_
#define _NIBOOLEANEXTRADATA_H_

#include "xml_extract.h"
#include NI_BOOLEAN_EXTRA_DATA_INCLUDE

/*
 * NiBooleanExtraData
 */

class NiBooleanExtraData;
typedef Ref<NiBooleanExtraData> NiBooleanExtraDataRef;

class NiBooleanExtraData : public NI_BOOLEAN_EXTRA_DATA_PARENT {
public:
  NiBooleanExtraData();
  ~NiBooleanExtraData();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_BOOLEAN_EXTRA_DATA_MEMBERS
};

#endif
