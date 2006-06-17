/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKBLENDCONTROLLER_H_
#define _BHKBLENDCONTROLLER_H_

#include "NiTimeController.h"

#include "../gen/obj_defines.h"

class bhkBlendController;
typedef Ref<bhkBlendController> bhkBlendControllerRef;

/*!
 * bhkBlendController - Unknown. Is apparently only used in skeleton.nif
 * files.
 */

class NIFLIB_API bhkBlendController : public BHK_BLEND_CONTROLLER_PARENT {
public:
	bhkBlendController();
	~bhkBlendController();
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
	BHK_BLEND_CONTROLLER_MEMBERS
};

#endif
