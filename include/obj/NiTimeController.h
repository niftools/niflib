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
 * NiTimeController - A generic time controller object.
 */

class NiTimeController : public NI_TIME_CONTROLLER_PARENT {
public:
	NIFLIB_API NiTimeController();
	NIFLIB_API ~NiTimeController();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
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

	/*!
	 * Can be used to get the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \return The flag data.
	 */
	NIFLIB_API unsigned short GetFlags() const;

	/*!
	 * Can be used to set the data stored in the flags field for this object.  It is usually better to call more specific flag-toggle functions if they are availiable.
	 * \param[in] n The new flag data.  Will overwrite any existing flag data.
	 */
	NIFLIB_API void SetFlags( unsigned short n );

	/*!
	 * Gets the frequency value of this controller.  This is used to map the time indices stored in the controller to seconds.  The value is multiplied by the application time to arrive at the controller time, so the default value of 1.0 means that the times in the controller are already in seconds.
	 * \return The frequency.
	 */
	NIFLIB_API float GetFrequency() const;

	/*!
	 * Sets the frequency value of this controller.  This is used to map the time indices stored in the controller to seconds.  The value is multiplied by the application time to arrive at the controller time, so the default value of 1.0 means that the times in the controller are already in seconds.  Calling this function with a new value will not cause any changes to the data stored in the controller.
	 * \param[in] n The new frequency.
	 */
	NIFLIB_API void SetFrequency( float n );

	/*!
	 * Gets the phase value of this controller.  This is used to map the time indices stored in the controller to seconds.  The value is is added to the result of the multiplication of application time by frequency to arrive at the controller time, so the default value of 0.0 means that there is no phase shift in the time indices.
	 * \return The phase.
	 */
	NIFLIB_API float GetPhase() const;

	/*!
	 * Sets the phase value of this controller.  This is used to map the time indices stored in the controller to seconds.  The value is is added to the result of the multiplication of application time by frequency to arrive at the controller time, so the default value of 0.0 means that there is no phase shift in the time indices.  Calling this function with a new value will not cause any changes to the data stored in the controller.
	 * \param[in] n The new phase.
	 */
	NIFLIB_API void SetPhase( float n );

	/*!
	 * Retrieves the time index where this controller begins to take affect.  If the animation type is set to wrap or cycle, the animation will not occur only between these time intervals but will be mapped to the right spot between them.  This value is in controller time, i.e. phase and frequency are applied to transform it to application time.
	 * \return The start time for the controller animation.
	 */
	NIFLIB_API float GetStartTime() const;

	/*!
	 * Sets the time index where this controller begins to take affect.  If the animation type is set to wrap or cycle, the animation will not occur only between these time intervals but will be mapped to the right spot between them.  This value is in controller time, i.e. phase and frequency are applied to transform it to application time.
	 * \param[in] n The new start time for the controller animation.
	 */
	NIFLIB_API void SetStartTime( float n );

	/*!
	 * Retrieves the time index where this controller stops taking affect.  If the animation type is set to wrap or cycle, the animation will not occur only between these time intervals but will be mapped to the right spot between them.  This value is in controller time, i.e. phase and frequency are applied to transform it to application time.
	 * \return The end time for the controller animation.
	 */
	NIFLIB_API float GetStopTime() const;

	/*!
	 * Sets the time index where this controller stops taking affect.  If the animation type is set to wrap or cycle, the animation will not occur only between these time intervals but will be mapped to the right spot between them.  This value is in controller time, i.e. phase and frequency are applied to transform it to application time.
	 * \param[in] n The new end time for the controller animation.
	 */
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
