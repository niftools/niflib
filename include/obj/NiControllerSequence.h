/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICONTROLLERSEQUENCE_H_
#define _NICONTROLLERSEQUENCE_H_

#include "NiObject.h"
// Include structures
#include "../gen/ControllerLink.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiTextKeyExtraData;
class NiControllerManager;
class NiStringPalette;
class NiTimeController;
class NiSingleInterpolatorController;

//#include "../gen/obj_defines.h"

class NiControllerSequence;
typedef Ref<NiControllerSequence> NiControllerSequenceRef;

/*!
 * NiControllerSequence - Root node in .kf files (version 10.0.1.0 and up).
 */

class NiControllerSequence : public NI_CONTROLLER_SEQUENCE_PARENT {
public:
	NIFLIB_API NiControllerSequence();
	NIFLIB_API ~NiControllerSequence();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Returns the name of this NiControllerSequence object. This is also the name of the action
	 * associated with this file. For instance, if the original NIF file is called
	 * "demon.nif" and this animation file contains an attack sequence, then
	 * the file would be called "demon_attack1.kf" and this field would
	 * contain the string "attack1".
	 * \return The name of this NiControllerSequence object.
	 */
	NIFLIB_API string GetName() const;

	/*!
	 * Sets the name of this NiControllerSequence object. This is also the name of the action
	 * associated with this file. For instance, if the original NIF file is called
	 * "demon.nif" and this animation file contains an attack sequence, then
	 * the file would be called "demon_attack1.kf" and this field would
	 * contain the string "attack1".
	 * \param[in] value The new name for this NiControllerSequence object.
	 */
	NIFLIB_API void SetName( const string & value );

	/*!
	 * Sets the name and reference to the NiTextKeyExtraData object which will be used by this controller sequence to specify the keyframe labels or "notes."
	 * \param[in] txt_key A reference to the NiTextKeyExtraData object to use.
	 * \sa NiTextKeyExtraData
	 */
	NIFLIB_API void SetTextKey( NiTextKeyExtraData * txt_key );

	/*! 
	 * Attatches a controler to this KF file for a KF file of version 10.2.0.0 or below.  Versions above this use interpolators.
	 * \param[in] obj A reference to the new NiTimeController to attach.
	 * \sa NiControllerSequence::ClearChildren, NiControllersequence::AddInterpolator
	 */
	NIFLIB_API void AddController( NiTimeController * obj );

	/*!
	 * Attatches an interpolator to this KF file for a KF file of version greater than 10.2.0.0.  Versions below this use controllers.
	 * \param[in] obj A reference to the new controller which has an interpolator to attach.
	 * \param[in] priority Used only in Oblivion to set the priority of one controller over another when the two are merged.
	 * \sa NiControllerSequence::ClearChildren, NiControllerSequence::AddController
	 */
	NIFLIB_API void AddInterpolator( NiSingleInterpolatorController * obj, byte priority = 0 );

	/*! 
	 * Removes all controllers and interpolators from this Kf file root object.
	 * \sa NiControllerSequence::AddController, NiControllersequence::AddInterpolator
	 */
	NIFLIB_API void ClearControllerData();

	/*!
	 * Retrieves the data for the controllers or interpolators which are attached to this controller sequence.
	 * \return A vector containing the data for all controllers.
	 * \sa NiControllerSequence::AddController, NiControllersequence::AddInterpolator, ClearKfChildren
	 */
	NIFLIB_API vector<ControllerLink> GetControllerData() const;

	/*!
	 * Retrieves the text keys, which are tags associated with keyframe times that mark the start and stop of each sequence, among other things such as the triggering of sound effects.
	 * \return The text key data.
	 */
	NIFLIB_API Ref<NiTextKeyExtraData> GetTextKeyExtraData() const;

	/*!
	 * Gets the animation frequency.
	 * \return The animation frequency.
	 */
	NIFLIB_API float GetFrequency() const;

	/*!
	 * Sets the animation frequency.
	 * \param[in] value The animation frequency.
	 */
	NIFLIB_API void SetFrequency( float value );

	/*!
	 * Gets the controller sequence start time.
	 * \return The controller sequence start time.
	 */
	NIFLIB_API float GetStartTime() const;

	/*!
	 * Sets the controller sequence start time.
	 * \param[in] value The controller sequence start time.
	 */
	NIFLIB_API void SetStartTime( float value );

	/*!
	 * Gets the controller sequence stop time.
	 * \return The conroller sequence stop time.
	 */
	NIFLIB_API float GetStopTime() const;

	/*!
	 * Sets the controller sequence stop time.
	 * \param[in] value The conroller sequence stop time.
	 */
	NIFLIB_API void SetStopTime( float value );

	/*!
	 * Gets the controller cyle behavior. Can be loop, reverse, or clamp.
	 * \return The animation cycle behavior.
	 */
	NIFLIB_API CycleType GetCycleType() const;

	/*!
	 * Sets the controller cyle behavior. Can be loop, reverse, or clamp.
	 * \param[in] n The new animation cycle behavior.
	 */
	NIFLIB_API void SetCycleType( CycleType n );

	/*! 
	 * Gets the  number of controllers.
	 * \return Number of total controllers in this sequence
	 * \sa GetControllerData
	 */
	NIFLIB_API int GetNumControllers() const;

	/*! 
	 * Gets controller priority.  Oblivion Specific.
	 * \return Priority of a specific controller.
	 * \param[in] controller The index of the controller to get the priority for.
	 * \sa GetControllerData, GetNumControllers, SetControllerPriority
	 */
	NIFLIB_API int GetControllerPriority( int controller ) const;

	/*! 
	 * Sets controller priority.  Oblivion Specific.
	 * \param[in] controller The index of the controller to set the priority for.
	 * \param[in] priority The amount of priority the controller should have.
	 * \sa GetControllerData, GetNumControllers, GetControllerPriority
	 */
	NIFLIB_API void SetControllerPriority( int controller, int priority );


	/*!
	 * Gets weight/priority of animation?
	 * \return The weight/priority of the animation?
	 */
	NIFLIB_API float GetWeight() const;

	/*!
	 * Sets weight/priority of animation?
	 * \param[in] value The weight/priority of the animation?
	 */
	NIFLIB_API void SetWeight( float value );

	/*!
	 * Gets the name of target node this controller acts on.
	 * \return The target node name.
	 */
	NIFLIB_API string GetTargetName() const;

	/*!
	 * Sets the name of target node this controller acts on.
	 * \param[in] value The target node name.
	 */
	NIFLIB_API void SetTargetName( const string & value );

protected:
   friend class NiControllerManager;
   NiControllerManager * GetParent() const;
   void SetParent( NiControllerManager * parent );

	NI_CONTROLLER_SEQUENCE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
