/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPOINT3INTERPOLATOR_H_
#define _NIPOINT3INTERPOLATOR_H_

#include "NiInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiPosData;

//#include "../gen/obj_defines.h"

class NiPoint3Interpolator;
typedef Ref<NiPoint3Interpolator> NiPoint3InterpolatorRef;

/*!
 * NiPoint3Interpolator - Unknown.
 */

class NiPoint3Interpolator : public NI_POINT3_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiPoint3Interpolator();
	NIFLIB_API ~NiPoint3Interpolator();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Value when posed?  Value at time 0?
	 */
	NIFLIB_API Vector3 GetPoint3Value() const;
	NIFLIB_API void SetPoint3Value( Vector3 value );

	/*!
	 * Reference to NiPosData.
	 */
	NIFLIB_API Ref<NiPosData > GetData() const;
	NIFLIB_API void SetData( Ref<NiPosData > value );

protected:
	NI_POINT3_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
