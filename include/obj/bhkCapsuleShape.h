/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKCAPSULESHAPE_H_
#define _BHKCAPSULESHAPE_H_

#include "bhkConvexShape.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class bhkCapsuleShape;
typedef Ref<bhkCapsuleShape> bhkCapsuleShapeRef;

/*!
 * bhkCapsuleShape - A capsule.
 */

class bhkCapsuleShape : public BHK_CAPSULE_SHAPE_PARENT {
public:
	NIFLIB_API bhkCapsuleShape();
	NIFLIB_API ~bhkCapsuleShape();
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
	 * Apparently the capsule's radius.
	 */
	NIFLIB_API float GetRadius() const;
	NIFLIB_API void SetRadius( float value );

	/*!
	 * First point on the capsule's axis.
	 */
	NIFLIB_API Vector3 GetFirstPoint() const;
	NIFLIB_API void SetFirstPoint( const Vector3 & value );

	/*!
	 * Matches first capsule radius.
	 */
	NIFLIB_API float GetRadius1() const;
	NIFLIB_API void SetRadius1( float value );

	/*!
	 * Second point on the capsule's axis.
	 */
	NIFLIB_API Vector3 GetSecondPoint() const;
	NIFLIB_API void SetSecondPoint( const Vector3 & value );

	/*!
	 * Matches second capsule radius.
	 */
	NIFLIB_API float GetRadius2() const;
	NIFLIB_API void SetRadius2( float value );

protected:
	BHK_CAPSULE_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
