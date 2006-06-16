/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITRANSFORMCONTROLLER_H_
#define _NITRANSFORMCONTROLLER_H_

#include "NiSingleInterpolatorController.h"

#include "../gen/obj_defines.h"

class NiTransformController;
typedef Ref<NiTransformController> NiTransformControllerRef;

/*!
 * NiTransformController - NiTransformController replaces the
 * NiKeyframeController.
 */

class NIFLIB_API NiTransformController : public NI_TRANSFORM_CONTROLLER_PARENT {
public:
	NiTransformController();
	~NiTransformController();
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
	NI_TRANSFORM_CONTROLLER_MEMBERS
};

#endif
