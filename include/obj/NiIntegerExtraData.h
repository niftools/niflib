/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIINTEGEREXTRADATA_H_
#define _NIINTEGEREXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiIntegerExtraData;
typedef Ref<NiIntegerExtraData> NiIntegerExtraDataRef;

/*!
 * NiIntegerExtraData - Extra integer data.
 */

class NIFLIB_API NiIntegerExtraData : public NI_INTEGER_EXTRA_DATA_PARENT {
public:
	NiIntegerExtraData();
	~NiIntegerExtraData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	uint GetData() const;
	void SetData( uint n );

protected:
	NI_INTEGER_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
