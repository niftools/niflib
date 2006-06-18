/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISEQUENCESTREAMHELPER_H_
#define _NISEQUENCESTREAMHELPER_H_

#include "NiObjectNET.h"
namespace Niflib {

#include "../gen/obj_defines.h"

class NiSequenceStreamHelper;
typedef Ref<NiSequenceStreamHelper> NiSequenceStreamHelperRef;

/*!
 * NiSequenceStreamHelper - Keyframe animation root node, in .kf files.
 */

class NIFLIB_API NiSequenceStreamHelper : public NI_SEQUENCE_STREAM_HELPER_PARENT {
public:
	NiSequenceStreamHelper();
	~NiSequenceStreamHelper();
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
	NI_SEQUENCE_STREAM_HELPER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
