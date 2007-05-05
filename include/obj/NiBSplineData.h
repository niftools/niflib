/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINEDATA_H_
#define _NIBSPLINEDATA_H_

#include "NiObject.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiBSplineData;
typedef Ref<NiBSplineData> NiBSplineDataRef;

/*!
 * NiBSplineData - Unknown.
 */

class NiBSplineData : public NI_B_SPLINE_DATA_PARENT {
public:
	NIFLIB_API NiBSplineData();
	NIFLIB_API ~NiBSplineData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Get Signed shorts representing the spline data scaled by SHRT_MAX.
	 * \return The spline data.
	 */
	NIFLIB_API vector<short> GetControlPoints() const;

	/*!
	 * Get Range of signed shorts representing the data scaled by SHRT_MAX.
	 * \param[in] offset The start of the range.
	 * \param[in] count The number of control points to get.
	 * \return The control points that fall within the specified range.
	 */
	NIFLIB_API vector<short> GetControlPointRange(int offset, int count) const;

protected:
	NI_B_SPLINE_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
