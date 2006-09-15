/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITIMECONTROLLER_H_
#define _NITIMECONTROLLER_H_

#include "NiObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {
class NiObject;

#include "../gen/obj_defines.h"

class NiTimeController;
class NiObjectNET;
typedef Ref<NiTimeController> NiTimeControllerRef;

/*!
 * NiTimeController - A generic time controller block.
 */

class NIFLIB_API NiTimeController : public NI_TIME_CONTROLLER_PARENT {
public:
	NiTimeController();
	~NiTimeController();
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

	/*! 
	 * Returns a reference to the next controller in a linked list.
	 * This function should only be called by NiObjectNET.
	 * \return A reference to the next controller in the linked list.
	 */
	NiTimeControllerRef GetNextController() const;

	/*! 
	 * Sets the next controller in a linked list.
	 * This function should only be called by NiObjectNET.
	 * \param obj A reference to the object to set as the one after this in the chain.
	 */
	void SetNextController( const NiTimeControllerRef & obj );

	/*! 
	 * This function should only be called by NiObjectNET.  It sets the target of
	 * this controller when it is attatched to the NiObjectNET class. */
	void SetTarget( NiObjectNET * new_target );

	/*! 
	 * This function returns the current target NiObjectNET, if any, that this controller
	 * is acting on.
	 * \return A reference to the current target of this controller.
	 */
	Ref<NiObjectNET> GetTarget();

	ushort GetFlags() const;
	void SetFlags( ushort n );

	float GetFrequency() const;
	void SetFrequency( float n );

	float GetPhase() const;
	void SetPhase( float n );

	float GetStartTime() const;
	void SetStartTime( float n );

	float GetStopTime() const;
	void SetStopTime( float n );
protected:
	NI_TIME_CONTROLLER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
