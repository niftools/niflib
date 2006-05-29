/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _FXRADIOBUTTON_H_
#define _FXRADIOBUTTON_H_

#include "xml_extract.h"
#include FX_RADIO_BUTTON_INCLUDE

/*
 * FxRadioButton
 */

class FxRadioButton;
typedef Ref<FxRadioButton> FxRadioButtonRef;

class FxRadioButton : public FX_RADIO_BUTTON_PARENT {
public:
  FxRadioButton();
  ~FxRadioButton();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  FX_RADIO_BUTTON_MEMBERS
};

#endif
