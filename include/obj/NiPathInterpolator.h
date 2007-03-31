/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPATHINTERPOLATOR_H_
#define _NIPATHINTERPOLATOR_H_

#include "NiBlendInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
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
	 * Links to NiPosData.
	 */
	NIFLIB_API Ref<NiPosData > GetPosData() const;
	NIFLIB_API void SetPosData( Ref<NiPosData > value );

	/*!
	 * Links to NiFloatData.
	 */
	NIFLIB_API Ref<NiFloatData > GetFloatData() const;
	NIFLIB_API void SetFloatData( Ref<NiFloatData > value );

protected:
	NI_PATH_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
