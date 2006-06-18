/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKMULTISPHERESHAPE_H_
#define _BHKMULTISPHERESHAPE_H_

#include "bhkSphereRepShape.h"
namespace NifLib {

#include "../gen/obj_defines.h"

class bhkMultiSphereShape;
typedef Ref<bhkMultiSphereShape> bhkMultiSphereShapeRef;

/*!
 * bhkMultiSphereShape - Unknown.
 */

class NIFLIB_API bhkMultiSphereShape : public BHK_MULTI_SPHERE_SHAPE_PARENT {
public:
	bhkMultiSphereShape();
	~bhkMultiSphereShape();
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

protected:
	BHK_MULTI_SPHERE_SHAPE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
