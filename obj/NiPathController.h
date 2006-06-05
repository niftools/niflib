/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPATHCONTROLLER_H_
#define _NIPATHCONTROLLER_H_

#include "NiTimeController.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiPosData;
class NiFloatData;

#include "../gen/obj_defines.h"

class NiPathController;
typedef Ref<NiPathController> NiPathControllerRef;

/*!
 * NiPathController - Time controller for a path.
 */

class NiPathController : public NI_PATH_CONTROLLER_PARENT {
public:
	NiPathController();
	~NiPathController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_PATH_CONTROLLER_MEMBERS
};

#endif
