/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPOINT3INTERPOLATOR_H_
#define _NIPOINT3INTERPOLATOR_H_

#include "NiInterpolator.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiPosData;

#include "gen/obj_defines.h"

/*
 * NiPoint3Interpolator
 */

class NiPoint3Interpolator;
typedef Ref<NiPoint3Interpolator> NiPoint3InterpolatorRef;

class NiPoint3Interpolator : public NI_POINT3_INTERPOLATOR_PARENT {
public:
	NiPoint3Interpolator();
	~NiPoint3Interpolator();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_POINT3_INTERPOLATOR_MEMBERS
};

#endif
