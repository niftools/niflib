/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICONTROLLERMANAGER_H_
#define _NICONTROLLERMANAGER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiControllerSequence;
class NiDefaultAVObjectPalette;

//#include "../gen/obj_defines.h"

class NiControllerManager;
typedef Ref<NiControllerManager> NiControllerManagerRef;

/*!
 * NiControllerManager - Unknown. Root of all controllers?
 */

class NiControllerManager : public NI_CONTROLLER_MANAGER_PARENT {
public:
	NIFLIB_API NiControllerManager();
	NIFLIB_API ~NiControllerManager();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const { return TYPE; };
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Designates whether animation sequences are cumulative?
	 */
	NIFLIB_API bool GetCumulative() const;
	NIFLIB_API void SetCumulative( bool value );

	/*!
	 * Refers to a list of NiControllerSequence object.
	 */
	NIFLIB_API vector<Ref<NiControllerSequence > > GetControllerSequences() const;
	NIFLIB_API void SetControllerSequences( const vector<Ref<NiControllerSequence > >& value );
	NIFLIB_API void AddSequence( Ref<NiControllerSequence > & obj );
	NIFLIB_API void RemoveSequence( Ref<NiControllerSequence > obj );
	NIFLIB_API void ClearSequences();

	/*!
	 * Refers to a NiDefaultAVObjectPalette.
	 */
	NIFLIB_API Ref<NiDefaultAVObjectPalette > GetObjectPalette() const;
	NIFLIB_API void SetObjectPalette( Ref<NiDefaultAVObjectPalette > value );

protected:
	NI_CONTROLLER_MANAGER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
