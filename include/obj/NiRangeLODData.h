/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIRANGELODDATA_H_
#define _NIRANGELODDATA_H_

#include "NiLODData.h"

// Include structures
#include "../gen/LODRange.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiRangeLODData;
typedef Ref<NiRangeLODData> NiRangeLODDataRef;

/*!
 * NiRangeLODData - Describes levels of detail based on distance of
 * object from camera.
 */

class NiRangeLODData : public NI_RANGE_L_O_D_DATA_PARENT {
public:
	NIFLIB_API NiRangeLODData();
	NIFLIB_API ~NiRangeLODData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Get the point to calculate distance from for switching?
	 * \return The point to calculate distance from for switching?
	 */
	NIFLIB_API Vector3 GetLODCenter() const;

	/*!
	 * Set the point to calculate distance from for switching?
	 * \param[in] value The new point to calculate distance from for switching?
	 */
	NIFLIB_API void SetLODCenter( const Vector3 & value );

	/*!
	 * Get the ranges of distance that each level of detail applies in.
	 * \return The ranges of distance that each level of detail applies in.
	 */
	NIFLIB_API vector<LODRange > GetLODLevels() const;

	/*!
	 * Set the ranges of distance that each level of detail applies in.
	 * \param[in] value The new ranges of distance that each level of detail applies in.
	 */
	NIFLIB_API void SetLODLevels( const vector<LODRange> & value );

protected:
	NI_RANGE_L_O_D_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
