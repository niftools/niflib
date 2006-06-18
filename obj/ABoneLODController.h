/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABONELODCONTROLLER_H_
#define _ABONELODCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../gen/NodeGroup.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class ABoneLODController;
typedef Ref<ABoneLODController> ABoneLODControllerRef;

/*!
 * ABoneLODController - Level of detail controller for bones?
 */

class NIFLIB_API ABoneLODController : public A_BONE_L_O_D_CONTROLLER_PARENT {
public:
	ABoneLODController();
	~ABoneLODController();
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

	//TODO:  This is not a priority but needs to be implemented eventually
protected:
	A_BONE_L_O_D_CONTROLLER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
