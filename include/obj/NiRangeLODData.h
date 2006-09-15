/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIRANGELODDATA_H_
#define _NIRANGELODDATA_H_

#include "NiLODData.h"

// Include structures
#include "../gen/LODRange.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiRangeLODData;
typedef Ref<NiRangeLODData> NiRangeLODDataRef;

/*!
 * NiRangeLODData - Describes levels of detail based on distance of
 * object from camera.
 */

class NIFLIB_API NiRangeLODData : public NI_RANGE_L_O_D_DATA_PARENT {
public:
	NiRangeLODData();
	~NiRangeLODData();
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

	/*!
	 * ?
	 */
	Vector3 GetLodCenter() const;
	void SetLodCenter( const Vector3 & value );

	/*!
	 * The ranges of distance that each level of detail applies in.
	 */
	vector<LODRange > GetLodLevels() const;
	void SetLodLevels( const vector<LODRange >& value );

protected:
	NI_RANGE_L_O_D_DATA_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
