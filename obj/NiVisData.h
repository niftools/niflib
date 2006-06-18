/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIVISDATA_H_
#define _NIVISDATA_H_

#include "AKeyedData.h"
namespace NifLib {


#include "../gen/obj_defines.h"

class NiVisData;
typedef Ref<NiVisData> NiVisDataRef;

/*!
 * NiVisData - Visibility data for a controller.
 */

class NIFLIB_API NiVisData : public NI_VIS_DATA_PARENT {
public:
	NiVisData();
	~NiVisData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_VIS_DATA_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
