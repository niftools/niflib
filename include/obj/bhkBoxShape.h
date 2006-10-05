/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKBOXSHAPE_H_
#define _BHKBOXSHAPE_H_

#include "bhkConvexShape.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class bhkBoxShape;
typedef Ref<bhkBoxShape> bhkBoxShapeRef;

/*!
 * bhkBoxShape - A box.
 */

class NIFLIB_API bhkBoxShape : public BHK_BOX_SHAPE_PARENT {
public:
	bhkBoxShape();
	~bhkBoxShape();
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
	 * Looks like this could be the box size.
	 */
	Vector3 GetDimensions() const;
	void SetDimensions( const Vector3& value );

protected:
	BHK_BOX_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
