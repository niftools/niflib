/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIVERTWEIGHTSEXTRADATA_H_
#define _NIVERTWEIGHTSEXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiVertWeightsExtraData;
typedef Ref<NiVertWeightsExtraData> NiVertWeightsExtraDataRef;

/*!
 * NiVertWeightsExtraData - Not used in skinning. Unsure of use - perhaps
 * for morphing animation or gravity.
 */

class NIFLIB_API NiVertWeightsExtraData : public NI_VERT_WEIGHTS_EXTRA_DATA_PARENT {
public:
	NiVertWeightsExtraData();
	~NiVertWeightsExtraData();
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

	vector<float> GetData() const;
	void SetData( const vector<float> & n );

protected:
	NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
