/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKMOPPBVTREESHAPE_H_
#define _BHKMOPPBVTREESHAPE_H_

#include "bhkShape.h"

// Forward define of referenced blocks
#include "../Ref.h"
class bhkShape;

#include "../gen/obj_defines.h"

class bhkMoppBvTreeShape;
typedef Ref<bhkMoppBvTreeShape> bhkMoppBvTreeShapeRef;

/*!
 * bhkMoppBvTreeShape - Memory optimized partial polytope bounding volume
 * tree shape (not an entity).
 */

class DLLEXPORT bhkMoppBvTreeShape : public BHK_MOPP_BV_TREE_SHAPE_PARENT {
public:
	bhkMoppBvTreeShape();
	~bhkMoppBvTreeShape();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_MOPP_BV_TREE_SHAPE_MEMBERS
};

#endif
