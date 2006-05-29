/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILIGHTCOLORCONTROLLER_H_
#define _NILIGHTCOLORCONTROLLER_H_

#include "xml_extract.h"
#include NI_LIGHT_COLOR_CONTROLLER_INCLUDE

/*
 * NiLightColorController
 */

class NiLightColorController;
typedef Ref<NiLightColorController> NiLightColorControllerRef;

class NiLightColorController : public NI_LIGHT_COLOR_CONTROLLER_PARENT {
public:
  NiLightColorController();
  ~NiLightColorController();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_LIGHT_COLOR_CONTROLLER_MEMBERS
};

#endif
