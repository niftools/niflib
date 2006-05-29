/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSFURNITUREMARKER_H_
#define _BSFURNITUREMARKER_H_

#include "xml_extract.h"
#include B_S_FURNITURE_MARKER_INCLUDE

/*
 * BSFurnitureMarker
 */

class BSFurnitureMarker;
typedef Ref<BSFurnitureMarker> BSFurnitureMarkerRef;

class BSFurnitureMarker : public B_S_FURNITURE_MARKER_PARENT {
public:
  BSFurnitureMarker();
  ~BSFurnitureMarker();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  B_S_FURNITURE_MARKER_MEMBERS
};

#endif
