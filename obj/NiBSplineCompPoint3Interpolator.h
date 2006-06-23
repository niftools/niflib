/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINECOMPPOINT3INTERPOLATOR_H_
#define _NIBSPLINECOMPPOINT3INTERPOLATOR_H_

#include "NiBSplineInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiBSplineData;
class NiObject;

#include "../gen/obj_defines.h"

class NiBSplineCompPoint3Interpolator;
typedef Ref<NiBSplineCompPoint3Interpolator> NiBSplineCompPoint3InterpolatorRef;

/*!
 * NiBSplineCompPoint3Interpolator - Unknown.
 */

class NIFLIB_API NiBSplineCompPoint3Interpolator : public NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT {
public:
	NiBSplineCompPoint3Interpolator();
	~NiBSplineCompPoint3Interpolator();
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
	 * Refers to NiBSplineData.
	 */
	Ref<NiBSplineData > GetData() const;
	void SetData( Ref<NiBSplineData > value );

protected:
	NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
