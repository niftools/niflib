/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILOOKATINTERPOLATOR_H_
#define _NILOOKATINTERPOLATOR_H_

#include "NiInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiNode;
class NiPoint3Interpolator;
class NiFloatInterpolator;

//#include "../gen/obj_defines.h"

class NiLookAtInterpolator;
typedef Ref<NiLookAtInterpolator> NiLookAtInterpolatorRef;

/*!
 * NiLookAtInterpolator - Unknown.
 */

class NiLookAtInterpolator : public NI_LOOK_AT_INTERPOLATOR_PARENT {
public:
	NIFLIB_API NiLookAtInterpolator();
	NIFLIB_API ~NiLookAtInterpolator();
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
	 * Refers to a Node to focus on.
	 */
	NIFLIB_API Ref<NiNode > GetLookAt() const;
	NIFLIB_API void SetLookAt( Ref<NiNode > value );

	/*!
	 * Translate.
	 */
	NIFLIB_API Vector3 GetTranslation() const;
	NIFLIB_API void SetTranslation( Vector3 value );

	/*!
	 * Rotation.
	 */
	NIFLIB_API Quaternion GetRotation() const;
	NIFLIB_API void SetRotation( Quaternion value );

	/*!
	 * Scale.
	 */
	NIFLIB_API float GetScale() const;
	NIFLIB_API void SetScale( float value );

protected:
	NI_LOOK_AT_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
