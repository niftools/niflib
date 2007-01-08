/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKMOPPBVTREESHAPE_H_
#define _BHKMOPPBVTREESHAPE_H_

#include "bhkShape.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class bhkShape;

//#include "../gen/obj_defines.h"

class bhkMoppBvTreeShape;
typedef Ref<bhkMoppBvTreeShape> bhkMoppBvTreeShapeRef;

/*!
 * bhkMoppBvTreeShape - Memory optimized partial polytope bounding volume
 * tree shape (not an entity).
 */

class NIFLIB_API bhkMoppBvTreeShape : public BHK_MOPP_BV_TREE_SHAPE_PARENT {
public:
	bhkMoppBvTreeShape();
	~bhkMoppBvTreeShape();
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
	BHK_MOPP_BV_TREE_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
