/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBOOLTIMELINEINTERPOLATOR_H_
#define _NIBOOLTIMELINEINTERPOLATOR_H_

#include "NiInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
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
	 * Gets the boolean value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \return The boolean value stored in this object.
	 */
	NIFLIB_API bool GetBoolValue() const;

	/*!
	 * Sets the boolean value stored in this object.  Perhaps this is the current interpolated value, the value when posed, or at time index 0.
	 * \param[in] value The new boolean value to store in this object.
	 */
	NIFLIB_API void SetBoolValue( bool value );

	/*!
	 * Gets the NiBoolData object that this interpolator links to, if any.
	 * \return The NiBoolData object that this interpolator links to, or NULL if one is not linked.
	 */
	NIFLIB_API Ref<NiBoolData > GetData() const;

	/*!
	 * Sets the NiBoolData object that this interpolator links to, if any.
	 * \return The NiBoolData object that this interpolator should now link to, or NULL to clear the current one.
	 */
	NIFLIB_API void SetData( NiBoolData * value );

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
