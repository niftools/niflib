/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPIXELDATA_H_
#define _NIPIXELDATA_H_

#include "xml_extract.h"
#include NI_PIXEL_DATA_INCLUDE

/*
 * NiPixelData
 */

class NiPixelData;
typedef Ref<NiPixelData> NiPixelDataRef;

class NiPixelData : public NI_PIXEL_DATA_PARENT {
public:
  NiPixelData();
  ~NiPixelData();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_PIXEL_DATA_MEMBERS
};

#endif
