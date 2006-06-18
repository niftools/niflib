/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPATHINTERPOLATOR_H_
#define _NIPATHINTERPOLATOR_H_

#include "NiBlendInterpolator.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiPosData;
class NiFloatData;

#include "../gen/obj_defines.h"

class NiPathInterpolator;
typedef Ref<NiPathInterpolator> NiPathInterpolatorRef;

/*!
 * NiPathInterpolator - Unknown interpolator.
 */

class NIFLIB_API NiPathInterpolator : public NI_PATH_INTERPOLATOR_PARENT {
public:
	NiPathInterpolator();
	~NiPathInterpolator();
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
	NI_PATH_INTERPOLATOR_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
