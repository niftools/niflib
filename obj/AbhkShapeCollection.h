/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABHKSHAPECOLLECTION_H_
#define _ABHKSHAPECOLLECTION_H_

#include "bhkShape.h"

#include "../gen/obj_defines.h"

class AbhkShapeCollection;
typedef Ref<AbhkShapeCollection> AbhkShapeCollectionRef;

/*!
 * AbhkShapeCollection - Havok data, not sure where to put in the
 * hierarchy.
 */

class AbhkShapeCollection : public ABHK_SHAPE_COLLECTION_PARENT {
public:
	AbhkShapeCollection();
	~AbhkShapeCollection();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	ABHK_SHAPE_COLLECTION_MEMBERS
};

#endif
