/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISKINPARTITION_H_
#define _NISKINPARTITION_H_

#include "NiObject.h"

// Include structures
#include "../gen/SkinPartition.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiSkinPartition;
typedef Ref<NiSkinPartition> NiSkinPartitionRef;

/*!
 * NiSkinPartition - Skinning data, optimized for hardware skinning. The
 * mesh is partitioned in submeshes such that each vertex of a submesh is
 * influenced only by a limited and fixed number of bones.
 */

class NIFLIB_API NiSkinPartition : public NI_SKIN_PARTITION_PARENT {
public:
	NiSkinPartition();
	~NiSkinPartition();
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
	NI_SKIN_PARTITION_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
