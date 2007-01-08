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

class NIFLIB_API NiPoint3Interpolator : public NI_POINT3_INTERPOLATOR_PARENT {
public:
	NiPoint3Interpolator();
	~NiPoint3Interpolator();
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
	 * Value when posed?  Value at time 0?
	 */
	Vector3 GetPoint3Value() const;
	void SetPoint3Value( Vector3 value );

	/*!
	 * Reference to NiPosData.
	 */
	Ref<NiPosData > GetData() const;
	void SetData( Ref<NiPosData > value );

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
