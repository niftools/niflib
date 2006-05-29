/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include "bhkSerializable.h"

//Definition of TYPE constant
const Type bhkSerializable::TYPE("bhkSerializable", &BHK_SERIALIZABLE_PARENT::TYPE );

bhkSerializable::bhkSerializable() BHK_SERIALIZABLE_CONSTRUCT {}

bhkSerializable::~bhkSerializable() {}

void bhkSerializable::Read( istream& in, list<uint> & link_stack, unsigned int version ) {
  BHK_SERIALIZABLE_READ
}

void bhkSerializable::Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const {
  BHK_SERIALIZABLE_WRITE
}

string bhkSerializable::asString( bool verbose ) const {
  BHK_SERIALIZABLE_STRING
}

void bhkSerializable::FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version ) {
  BHK_SERIALIZABLE_FIXLINKS
}

const Type & bhkSerializable::GetType() const {
  return TYPE;
};

