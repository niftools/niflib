/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRANSFORMINTERPOLATOR_H_
#define _NITRANSFORMINTERPOLATOR_H_

#include "NiInterpolator.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiTransformData;

#include "../gen/obj_defines.h"

class NiTransformInterpolator;
typedef Ref<NiTransformInterpolator> NiTransformInterpolatorRef;

/*!
 * NiTransformInterpolator - Unknown.
 */

class NIFLIB_API NiTransformInterpolator : public NI_TRANSFORM_INTERPOLATOR_PARENT {
public:
	NiTransformInterpolator();
	~NiTransformInterpolator();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_TRANSFORM_INTERPOLATOR_MEMBERS
};

#endif
