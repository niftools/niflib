/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSXFLAGS_H_
#define _BSXFLAGS_H_

#include "NiExtraData.h"

#include "../gen/obj_defines.h"

class BSXFlags;
typedef Ref<BSXFlags> BSXFlagsRef;

/*!
 * BSXFlags - Unknown.
 */

class NIFLIB_API BSXFlags : public B_S_X_FLAGS_PARENT {
public:
	BSXFlags();
	~BSXFlags();
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

	uint GetFlags() const;
	void SetFlags( uint n );

protected:
	B_S_X_FLAGS_MEMBERS
};

#endif
