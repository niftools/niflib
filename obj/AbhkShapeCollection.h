/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABHKSHAPECOLLECTION_H_
#define _ABHKSHAPECOLLECTION_H_

#include "xml_extract.h"
#include ABHK_SHAPE_COLLECTION_INCLUDE

/*
 * AbhkShapeCollection
 */

class AbhkShapeCollection;
typedef Ref<AbhkShapeCollection> AbhkShapeCollectionRef;

class AbhkShapeCollection : public ABHK_SHAPE_COLLECTION_PARENT {
public:
	AbhkShapeCollection();
	~AbhkShapeCollection();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version );
private:
	ABHK_SHAPE_COLLECTION_MEMBERS
};
#endif
