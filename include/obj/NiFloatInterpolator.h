/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFLOATINTERPOLATOR_H_
#define _NIFLOATINTERPOLATOR_H_

#include "NiInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiFloatData;

//#include "../gen/obj_defines.h"

class NiFloatInterpolator;
typedef Ref<NiFloatInterpolator> NiFloatInterpolatorRef;

/*!
 * NiFloatInterpolator - Unknown.
 */

class NIFLIB_API NiFloatInterpolator : public NI_FLOAT_INTERPOLATOR_PARENT {
public:
	NiFloatInterpolator();
	~NiFloatInterpolator();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Value when posed?  At time 0?
	 */
	float GetFloatValue() const;
	void SetFloatValue( float value );

	/*!
	 * Float data?
	 */
	Ref<NiFloatData > GetData() const;
	void SetData( Ref<NiFloatData > value );

protected:
	NI_FLOAT_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
