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

//#include "../gen/obj_defines.h"

class NiBoolTimelineInterpolator;
typedef Ref<NiBoolTimelineInterpolator> NiBoolTimelineInterpolatorRef;

/*!
 * NiBoolTimelineInterpolator - Unknown.
 */

class NiBoolTimelineInterpolator : public NI_BOOL_TIMELINE_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiBoolTimelineInterpolator();
	NIFLIB_API ~NiBoolTimelineInterpolator();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * The interpolated bool?
	 */
	NIFLIB_API byte GetBoolValue() const;
	NIFLIB_API void SetBoolValue( byte value );

	/*!
	 * The bool data.
	 */
	NIFLIB_API Ref<NiBoolData > GetData() const;
	NIFLIB_API void SetData( Ref<NiBoolData > value );

protected:
	NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
