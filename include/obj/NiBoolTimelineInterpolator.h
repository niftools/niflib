/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBOOLTIMELINEINTERPOLATOR_H_
#define _NIBOOLTIMELINEINTERPOLATOR_H_

#include "NiInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiBoolData;

#include "../gen/obj_defines.h"

class NiBoolTimelineInterpolator;
typedef Ref<NiBoolTimelineInterpolator> NiBoolTimelineInterpolatorRef;

/*!
 * NiBoolTimelineInterpolator - Unknown.
 */

class NIFLIB_API NiBoolTimelineInterpolator : public NI_BOOL_TIMELINE_INTERPOLATOR_PARENT {
public:
	NiBoolTimelineInterpolator();
	~NiBoolTimelineInterpolator();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * The interpolated bool?
	 */
	byte GetBoolValue() const;
	void SetBoolValue( byte value );

	/*!
	 * The bool data.
	 */
	Ref<NiBoolData > GetData() const;
	void SetData( Ref<NiBoolData > value );

protected:
	NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
