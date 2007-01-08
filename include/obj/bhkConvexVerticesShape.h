/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKCONVEXVERTICESSHAPE_H_
#define _BHKCONVEXVERTICESSHAPE_H_

#include "bhkSphereRepShape.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class bhkConvexVerticesShape;
typedef Ref<bhkConvexVerticesShape> bhkConvexVerticesShapeRef;

/*!
 * bhkConvexVerticesShape - A convex shape built from vertices?
 */

class NIFLIB_API bhkConvexVerticesShape : public BHK_CONVEX_VERTICES_SHAPE_PARENT {
public:
	bhkConvexVerticesShape();
	~bhkConvexVerticesShape();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	BHK_CONVEX_VERTICES_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
