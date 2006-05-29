/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSXFLAGS_H_
#define _BSXFLAGS_H_

#include "xml_extract.h"
#include B_S_X_FLAGS_INCLUDE

/*
 * BSXFlags
 */

class BSXFlags;
typedef Ref<BSXFlags> BSXFlagsRef;

class BSXFlags : public B_S_X_FLAGS_PARENT {
public:
  BSXFlags();
  ~BSXFlags();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  B_S_X_FLAGS_MEMBERS
};

#endif
