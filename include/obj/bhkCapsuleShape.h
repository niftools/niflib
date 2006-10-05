/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKCAPSULESHAPE_H_
#define _BHKCAPSULESHAPE_H_

#include "bhkConvexShape.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class bhkCapsuleShape;
typedef Ref<bhkCapsuleShape> bhkCapsuleShapeRef;

/*!
 * bhkCapsuleShape - A capsule.
 */

class NIFLIB_API bhkCapsuleShape : public BHK_CAPSULE_SHAPE_PARENT {
public:
	bhkCapsuleShape();
	~bhkCapsuleShape();
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
	 * Apparently the capsule's radius.
	 */
	float GetRadius() const;
	void SetRadius( float value );

	/*!
	 * First point on the capsule's axis.
	 */
	Vector3 GetFirstPoint() const;
	void SetFirstPoint( const Vector3 & value );

	/*!
	 * Matches first capsule radius.
	 */
	float GetRadius1() const;
	void SetRadius1( float value );

	/*!
	 * Second point on the capsule's axis.
	 */
	Vector3 GetSecondPoint() const;
	void SetSecondPoint( const Vector3 & value );

	/*!
	 * Matches second capsule radius.
	 */
	float GetRadius2() const;
	void SetRadius2( float value );

protected:
	BHK_CAPSULE_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
