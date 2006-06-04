/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRIBASEDGEOM_H_
#define _NITRIBASEDGEOM_H_

#include "NiAVObject.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiTriBasedGeomData;
class NiSkinInstance;
class NiObject;

#include "gen/obj_defines.h"

class NiTriBasedGeom;
typedef Ref<NiTriBasedGeom> NiTriBasedGeomRef;

/*!
 * NiTriBasedGeom - Describes a mesh, built from triangles.
 */

class NiTriBasedGeom : public NI_TRI_BASED_GEOM_PARENT {
public:
	NiTriBasedGeom();
	~NiTriBasedGeom();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_TRI_BASED_GEOM_MEMBERS
};

#endif
