/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICOLORDATA_H_
#define _NICOLORDATA_H_

#include "AKeyedData.h"
// Include structures
#include "../gen/KeyGroup.h"

#include "../gen/obj_defines.h"

class NiColorData;
typedef Ref<NiColorData> NiColorDataRef;

/*!
 * NiColorData - Color data for material color controller.
 */

class DLLEXPORT NiColorData : public NI_COLOR_DATA_PARENT {
public:
	NiColorData();
	~NiColorData();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_COLOR_DATA_MEMBERS
};

#endif
