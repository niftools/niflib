/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITIMECONTROLLER_H_
#define _NITIMECONTROLLER_H_

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {
class NiObject;

//#include "../gen/obj_defines.h"

class NiTimeController;
class NiObjectNET;
typedef Ref<NiTimeController> NiTimeControllerRef;

/*!
 * NiTimeController - A generic time controller block.
 */

class NiTimeController : public NI_TIME_CONTROLLER_PARENT {
public:
	NIFLIB_API NiTimeController();
	NIFLIB_API ~NiTimeController();
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

	/*! 
	 * Returns a reference to the next controller in a linked list.
	 * This function should only be called by NiObjectNET.
	 * \return A reference to the next controller in the linked list.
	 */
	NIFLIB_HIDDEN NiTimeControllerRef GetNextController() const;

	/*! 
	 * Sets the next controller in a linked list.
	 * This function should only be called by NiObjectNET.
	 * \param obj A reference to the object to set as the one after this in the chain.
	 */
	NIFLIB_HIDDEN void SetNextController( const NiTimeControllerRef & obj );

	/*! 
	 * This function should only be called by NiObjectNET.  It sets the target of
	 * this controller when it is attatched to the NiObjectNET class. */
	NIFLIB_HIDDEN void SetTarget( NiObjectNET * new_target );

	/*! 
	 * This function returns the current target NiObjectNET, if any, that this controller
	 * is acting on.
	 * \return A reference to the current target of this controller.
	 */
	NIFLIB_API Ref<NiObjectNET> GetTarget();

	NIFLIB_API unsigned short GetFlags() const;
	NIFLIB_API void SetFlags( unsigned short n );

	NIFLIB_API float GetFrequency() const;
	NIFLIB_API void SetFrequency( float n );

	NIFLIB_API float GetPhase() const;
	NIFLIB_API void SetPhase( float n );

	NIFLIB_API float GetStartTime() const;
	NIFLIB_API void SetStartTime( float n );

	NIFLIB_API float GetStopTime() const;
	NIFLIB_API void SetStopTime( float n );
protected:
	NI_TIME_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
