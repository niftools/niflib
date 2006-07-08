/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICONTROLLERSEQUENCE_H_
#define _NICONTROLLERSEQUENCE_H_

#include "NiObject.h"
// Include structures
#include "../gen/ControllerLink.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiTextKeyExtraData;
class NiControllerManager;
class NiStringPalette;
class NiTimeController;
class NiSingleInterpolatorController;

#include "../gen/obj_defines.h"

class NiControllerSequence;
typedef Ref<NiControllerSequence> NiControllerSequenceRef;

/*!
 * NiControllerSequence - Root node in .kf files (version 10.0.1.0 and
 * up).
 */

class NIFLIB_API NiControllerSequence : public NI_CONTROLLER_SEQUENCE_PARENT {
public:
	NiControllerSequence();
	~NiControllerSequence();
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

	enum CycleType {
		CYCLE_LOOP = 0,
		CYCLE_REVERSE = 1,
		CYCLE_CLAMP = 2
	};

	/*! Sets the name and block reference to the NiTextKeyExtraData block which will be used by this controller sequence to specify the keyframe labels or "notes."
	 * \param new_name The name of the NiTextKeyExtraData block to use.
	 * \param txt_key A reference to the NiTextKeyExtraData object to use.
	 * \sa NiTextKeyExtraData
	 */
	void SetTextKey( const Ref<NiTextKeyExtraData> & txt_key );

	/*! Attatches a controler to this KF file for a KF file of version 10.2.0.0 or below.  Versions above this use interpolators.
	 * \param obj A reference to the new NiTimeController to attach.
	 * \sa NiControllerSequence::ClearChildren, NiControllersequence::AddInterpolator
	 */
	void AddController( const Ref<NiTimeController> & obj );

	/*! Attatches an interpolator to this KF file for a KF file of version greater than 10.2.0.0.  Versions below this use controllers.
	 * \param obj A reference to the new controller which has an interpolator to attach.
	 * \param priority Used only in Oblivion to set the priority of one controller over another when the two are merged.
	 * \sa NiControllerSequence::ClearChildren, NiControllerSequence::AddController
	 */
	void AddInterpolator( const Ref<NiSingleInterpolatorController> & obj, byte priority = 0 );

	/*! Removes all controllers and interpolators from this Kf file root object.
	 * \sa NiControllerSequence::AddController, NiControllersequence::AddInterpolator
	 */
	void ClearControllerData();

	/*! Retrieves the data for the controllers or interpolators which are attached to this controller sequence.
	 * \return A vector containing the data for all controllers.
	 * \sa NiControllerSequence::AddController, NiControllersequence::AddInterpolator, ClearKfChildren
	 */
	vector<ControllerLink> GetControllerData() const;

	Ref<NiTextKeyExtraData> GetTextKeyExtraData() const;

	/*!
	 * The animation frequency.
	 */
	float GetFrequency() const;
	void SetFrequency( float value );

	/*!
	 * The controller sequence start time
	 */
	float GetStartTime() const;
	void SetStartTime( float value );

	/*!
	 * The controller sequence stop time
	 */
	float GetStopTime() const;
	void SetStopTime( float value );

	CycleType GetCycleType() const;
	void SetCycleType( CycleType n );

protected:
	NiControllerManager * NiControllerSequence::Parent() const;
	NI_CONTROLLER_SEQUENCE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
