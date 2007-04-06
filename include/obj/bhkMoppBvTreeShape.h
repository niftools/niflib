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

class bhkMoppBvTreeShape : public BHK_MOPP_BV_TREE_SHAPE_PARENT {
public:
	NIFLIB_API bhkMoppBvTreeShape();
	NIFLIB_API ~bhkMoppBvTreeShape();
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

protected:
	BHK_MOPP_BV_TREE_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
