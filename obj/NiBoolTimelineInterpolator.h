/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBOOLTIMELINEINTERPOLATOR_H_
#define _NIBOOLTIMELINEINTERPOLATOR_H_

#include "NiInterpolator.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiBoolData;

#include "gen/obj_defines.h"

/*
 * NiBoolTimelineInterpolator
 */

class NiBoolTimelineInterpolator;
typedef Ref<NiBoolTimelineInterpolator> NiBoolTimelineInterpolatorRef;

class NiBoolTimelineInterpolator : public NI_BOOL_TIMELINE_INTERPOLATOR_PARENT {
public:
	NiBoolTimelineInterpolator();
	~NiBoolTimelineInterpolator();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS
};

#endif
