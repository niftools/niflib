/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIOBJECTNET_H_
#define _NIOBJECTNET_H_

#include "xml_extract.h"
#include NI_OBJECT_N_E_T_INCLUDE

/*
 * NiObjectNET - An object that has a name.  Can have extra data and controllers attatched.
 */

class NiObjectNET;
typedef Ref<NiObjectNET> NiObjectNETRef;

class NiObjectNET : public NI_OBJECT_N_E_T_PARENT {
public:
	NiObjectNET();
	~NiObjectNET();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	
	string GetName();
	void SetName( string & new_name );
	//TODO: pointer to extra data type... find out what that is.  AExtraData right now.  Need functions to add/remove.
	//TODO: pointer to first NiTimeController type.  Need functions to add/remove.
private:
	NI_OBJECT_N_E_T_MEMBERS
};
#endif
