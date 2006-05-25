/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIOBJECTNET_H_
#define _NIOBJECTNET_H_

#include "NiObject.h"

/*
 * NiObjectNET - An object that has a name.  Can have extra data and controllers attatched.
 */

class NiObjectNET;

typedef Ref<NiObjectNET> NiObjectNETRef;

class NiObjectNET : public NiObject /*NI_OBJECT_N_E_T_PARENTS*/ {
public:
	NiObjectNET() /*NI_OBJECT_N_E_T_CONSTRUCT*/ {}
	~NiObjectNET() {}
	//Run-Time Type Information
	static const Type TYPE;
	string name;
	virtual void Read( istream& in, list<uint> link_stack, unsigned int version ) { /*NI_OBJECT_N_E_T_READ*/ }
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const { /*NI_OBJECT_N_E_T_WRITE*/ }
	virtual string asString( bool verbose = false ) const { /*NI_OBJECT_N_E_T_STRING*/ }
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> link_stack, unsigned int version ) { /*NI_OBJECT_N_E_T_FIXLINKS*/ }

private:
	/*NI_OBJECT_N_E_T_MEMBERS*/
	//TODO: pointer to extra data type... find out what that is.  AExtraData right now.  Need functions to add/remove.
	//TODO: pointer to first NiTimeController type.  Need functions to add/remove.
};

#endif