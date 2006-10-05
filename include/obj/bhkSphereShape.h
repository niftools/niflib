/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKSPHERESHAPE_H_
#define _BHKSPHERESHAPE_H_

#include "bhkConvexShape.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class bhkSphereShape;
typedef Ref<bhkSphereShape> bhkSphereShapeRef;

/*!
 * bhkSphereShape - A sphere.
 */

class NIFLIB_API bhkSphereShape : public BHK_SPHERE_SHAPE_PARENT {
public:
	bhkSphereShape();
	~bhkSphereShape();
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
	 * This denotes the radius of the sphere.
	 */
	float GetRadius() const;
	void SetRadius( float value );

protected:
	BHK_SPHERE_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
