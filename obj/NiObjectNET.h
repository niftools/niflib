/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIOBJECTNET_H_
#define _NIOBJECTNET_H_

// Forward defines
class NiExtraData;
class NiTimeController;

#include "gen/obj_defines.h"
#include NI_OBJECT_N_E_T_INCLUDE

class NiObjectNET;
class NiExtraData;
class NiTimeController;

/*
 * NiObjectNET - An object that has a name.  Can have extra data and controllers attatched.
 */
typedef Ref<NiObjectNET> NiObjectNETRef;

class NiObjectNET : public NI_OBJECT_N_E_T_PARENT {
public:
	NiObjectNET();
	~NiObjectNET();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;

	string GetName();
	void SetName( string & new_name );
	/*!
	 * Formats a human readable string that includes the type of the object
	 * \return A string in the form:  address(type) {name}
	 */
	virtual string GetIDString();

	void AddExtraData( Ref<NiExtraData> & obj, uint version = VER_10_0_1_0 );
	void RemoveExtraData( Ref<NiExtraData> obj );
	void ShiftExtraData( uint version = VER_10_0_1_0 );
	void ClearExtraData();
	list< Ref<NiExtraData> > GetExtraData() const;

	void AddController( Ref<NiTimeController> & obj );
	void RemoveController( Ref<NiTimeController> obj );
	void ClearControllers();
	list< Ref<NiTimeController> > GetControllers() const;

	//TODO: pointer to first NiTimeController type.  Need functions to add/remove.
private:
	NI_OBJECT_N_E_T_MEMBERS
};
#endif
