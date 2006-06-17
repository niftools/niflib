/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBINARYEXTRADATA_H_
#define _NIBINARYEXTRADATA_H_

#include "NiExtraData.h"
// Include structures
#include "../gen/ByteArray.h"

#include "../gen/obj_defines.h"

class NiBinaryExtraData;
typedef Ref<NiBinaryExtraData> NiBinaryExtraDataRef;

/*!
 * NiBinaryExtraData - Binary extra data block. Used to store normals and
 * binormals in Oblivion.
 */

class NIFLIB_API NiBinaryExtraData : public NI_BINARY_EXTRA_DATA_PARENT {
public:
	NiBinaryExtraData();
	~NiBinaryExtraData();
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

	vector<byte> GetData() const;
	void SetData( const vector<byte> & n );

protected:
	NI_BINARY_EXTRA_DATA_MEMBERS
};

#endif
