/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBOOLINTERPOLATOR_H_
#define _NIBOOLINTERPOLATOR_H_

#include "NiInterpolator.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiBoolData;

#include "../gen/obj_defines.h"

class NiBoolInterpolator;
typedef Ref<NiBoolInterpolator> NiBoolInterpolatorRef;

/*!
 * NiBoolInterpolator - Unknown.
 */

class NiBoolInterpolator : public NI_BOOL_INTERPOLATOR_PARENT {
public:
	NiBoolInterpolator();
	~NiBoolInterpolator();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_BOOL_INTERPOLATOR_MEMBERS
};

#endif
