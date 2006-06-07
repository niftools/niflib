/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBLENDPOINT3INTERPOLATOR_H_
#define _NIBLENDPOINT3INTERPOLATOR_H_

#include "NiBlendInterpolator.h"

#include "../gen/obj_defines.h"

class NiBlendPoint3Interpolator;
typedef Ref<NiBlendPoint3Interpolator> NiBlendPoint3InterpolatorRef;

/*!
 * NiBlendPoint3Interpolator - Interpolates a point?
 */

class NIFLIB_API NiBlendPoint3Interpolator : public NI_BLEND_POINT3_INTERPOLATOR_PARENT {
public:
	NiBlendPoint3Interpolator();
	~NiBlendPoint3Interpolator();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_BLEND_POINT3_INTERPOLATOR_MEMBERS
};

#endif
