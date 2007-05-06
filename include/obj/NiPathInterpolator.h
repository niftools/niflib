/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIPATHINTERPOLATOR_H_
#define _NIPATHINTERPOLATOR_H_

#include "NiBlendInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPosData;
class NiFloatData;

//#include "../gen/obj_defines.h"

class NiPathInterpolator;
typedef Ref<NiPathInterpolator> NiPathInterpolatorRef;

/*!
 * NiPathInterpolator - Unknown interpolator.
 */

class NiPathInterpolator : public NI_PATH_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiPathInterpolator();
	NIFLIB_API ~NiPathInterpolator();
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
	 * Gets the NiPosData object that this interpolator links to, if any.
	 * \return The NiPosData object that this interpolator links to, or NULL if one is not linked.
	 */
	NIFLIB_API Ref<NiPosData> GetPosData() const;

	/*!
	 * Sets the NiPosData object that this interpolator links to, if any.
	 * \return The NiPosData object that this interpolator should now link to, or NULL to clear the current one.
	 */
	NIFLIB_API void SetPosData( NiPosData * value );

	/*!
	 * Gets the NiFloatData object that this interpolator links to, if any.
	 * \return The NiFloatData object that this interpolator links to, or NULL if one is not linked.
	 */
	NIFLIB_API Ref<NiFloatData > GetFloatData() const;

	/*!
	 * Sets the NiFloatData object that this interpolator links to, if any.
	 * \return The NiFloatData object that this interpolator should now link to, or NULL to clear the current one.
	 */
	NIFLIB_API void SetFloatData( NiFloatData * value );

protected:
	NI_PATH_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
