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

class NIFLIB_API NiBSplineData : public NI_B_SPLINE_DATA_PARENT {
public:
	NiBSplineData();
	~NiBSplineData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

   /*!
   * Get Signed shorts representing the data scaled by SHRT_MAX.
   */
   vector<short > GetControlPoints() const;

   /*!
   * Get Range of signed shorts representing the data scaled by SHRT_MAX.
   */
   vector<short > GetControlPointRange(int offset, int count) const;

protected:
	NI_B_SPLINE_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
