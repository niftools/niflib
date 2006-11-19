/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIINTEGERSEXTRADATA_H_
#define _NIINTEGERSEXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiIntegersExtraData;
typedef Ref<NiIntegersExtraData> NiIntegersExtraDataRef;

/*!
 * NiIntegersExtraData - Integers data.
 */

class NIFLIB_API NiIntegersExtraData : public NI_INTEGERS_EXTRA_DATA_PARENT {
public:
	NiIntegersExtraData();
	~NiIntegersExtraData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Integers.
	 */
	vector<unsigned int> GetData() const;
	void SetData( const vector<uint >& value );

protected:
	NI_INTEGERS_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
