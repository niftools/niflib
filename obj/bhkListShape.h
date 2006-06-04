/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKLISTSHAPE_H_
#define _BHKLISTSHAPE_H_

#include "AbhkShapeCollection.h"

// Forward define of referenced blocks
#include "Ref.h"
class bhkShape;

#include "gen/obj_defines.h"

class bhkListShape;
typedef Ref<bhkListShape> bhkListShapeRef;

/*!
 * bhkListShape - A list of shapes.
 */

class bhkListShape : public BHK_LIST_SHAPE_PARENT {
public:
	bhkListShape();
	~bhkListShape();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	BHK_LIST_SHAPE_MEMBERS
};

#endif
