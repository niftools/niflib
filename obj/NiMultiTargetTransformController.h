/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMULTITARGETTRANSFORMCONTROLLER_H_
#define _NIMULTITARGETTRANSFORMCONTROLLER_H_

#include "NiTimeController.h"
namespace Niflib {

// Forward define of referenced blocks
class NiNode;

#include "../gen/obj_defines.h"

class NiMultiTargetTransformController;
typedef Ref<NiMultiTargetTransformController> NiMultiTargetTransformControllerRef;

/*!
 * NiMultiTargetTransformController - Unknown.
 */

class NIFLIB_API NiMultiTargetTransformController : public NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENT {
public:
	NiMultiTargetTransformController();
	~NiMultiTargetTransformController();
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
	NI_MULTI_TARGET_TRANSFORM_CONTROLLER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
