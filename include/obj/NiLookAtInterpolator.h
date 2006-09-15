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

#include "../gen/obj_defines.h"

class NiLookAtInterpolator;
typedef Ref<NiLookAtInterpolator> NiLookAtInterpolatorRef;

/*!
 * NiLookAtInterpolator - Unknown.
 */

class NIFLIB_API NiLookAtInterpolator : public NI_LOOK_AT_INTERPOLATOR_PARENT {
public:
	NiLookAtInterpolator();
	~NiLookAtInterpolator();
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
	 * Refers to a Node to focus on.
	 */
	Ref<NiNode > GetLookAt() const;
	void SetLookAt( Ref<NiNode > value );

	/*!
	 * Translate.
	 */
	Vector3 GetTranslation() const;
	void SetTranslation( Vector3 value );

	/*!
	 * Rotation.
	 */
	Quaternion GetRotation() const;
	void SetRotation( Quaternion value );

	/*!
	 * Scale.
	 */
	float GetScale() const;
	void SetScale( float value );

protected:
	NI_LOOK_AT_INTERPOLATOR_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
