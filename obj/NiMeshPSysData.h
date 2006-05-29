/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMESHPSYSDATA_H_
#define _NIMESHPSYSDATA_H_

#include "xml_extract.h"
#include NI_MESH_P_SYS_DATA_INCLUDE

/*
 * NiMeshPSysData
 */

class NiMeshPSysData;
typedef Ref<NiMeshPSysData> NiMeshPSysDataRef;

class NiMeshPSysData : public NI_MESH_P_SYS_DATA_PARENT {
public:
  NiMeshPSysData();
  ~NiMeshPSysData();
  //Run-Time Type Information
  static const Type TYPE;
  virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
  virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
  virtual string asString( bool verbose = false ) const;
  virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
  virtual const Type & GetType() const;
protected:
  NI_MESH_P_SYS_DATA_MEMBERS
};

#endif
