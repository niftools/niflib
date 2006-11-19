/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRANSFORMINTERPOLATOR_H_
#define _NITRANSFORMINTERPOLATOR_H_

#include "NiInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiTransformData;

//#include "../gen/obj_defines.h"

class NiTransformInterpolator;
typedef Ref<NiTransformInterpolator> NiTransformInterpolatorRef;

/*!
 * NiTransformInterpolator - Unknown.
 */

class NIFLIB_API NiTransformInterpolator : public NI_TRANSFORM_INTERPOLATOR_PARENT {
public:
	NiTransformInterpolator();
	~NiTransformInterpolator();
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

	/*!
	 * Refers to NiTransformData.
	 */
	Ref<NiTransformData > GetData() const;
	void SetData( Ref<NiTransformData > value );

protected:
	NI_TRANSFORM_INTERPOLATOR_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
