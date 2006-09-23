/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTRINGSEXTRADATA_H_
#define _NISTRINGSEXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiStringsExtraData;
typedef Ref<NiStringsExtraData> NiStringsExtraDataRef;

/*!
 * NiStringsExtraData - List of strings; for example, a list of all bone
 * names.
 */

class NIFLIB_API NiStringsExtraData : public NI_STRINGS_EXTRA_DATA_PARENT {
public:
	NiStringsExtraData();
	~NiStringsExtraData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	vector<string> GetData() const;
	void SetData( const vector<string> & n );

protected:
	NI_STRINGS_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
