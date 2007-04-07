/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIOBJECTNET_H_
#define _NIOBJECTNET_H_

#include "NiObject.h"

namespace Niflib {

// Forward define of referenced blocks
class NiExtraData;
class NiTimeController;

//#include "../gen/obj_defines.h"

class NiObjectNET;
class NiExtraData;
class NiTimeController;

/*
 * NiObjectNET - An object that has a name.  Can have extra data and controllers attatched.
 */
typedef Ref<NiObjectNET> NiObjectNETRef;

class NiObjectNET : public NI_OBJECT_N_E_T_PARENT {
public:
	NIFLIB_API NiObjectNET();
	NIFLIB_API ~NiObjectNET();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	NIFLIB_API string GetName();
	NIFLIB_API void SetName( const string & new_name );
	/*!
	 * Formats a human readable string that includes the type of the object
	 * \return A string in the form:  address(type) {name}
	 */
	NIFLIB_API virtual string GetIDString() const;

	NIFLIB_API void AddExtraData( NiExtraData * obj, unsigned version = VER_10_0_1_0 );
	NIFLIB_API void RemoveExtraData( NiExtraData * obj );
	NIFLIB_API void ShiftExtraData( unsigned int version = VER_10_0_1_0 );
	NIFLIB_API void ClearExtraData();
	NIFLIB_API list< Ref<NiExtraData> > GetExtraData() const;

	NIFLIB_API bool IsAnimated();
	NIFLIB_API void AddController( NiTimeController * obj );
	NIFLIB_API void RemoveController( NiTimeController * obj );
	NIFLIB_API void ClearControllers();
	NIFLIB_API list< Ref<NiTimeController> > GetControllers() const;

	//TODO: pointer to first NiTimeController type.  Need functions to add/remove.
private:
	NI_OBJECT_N_E_T_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
