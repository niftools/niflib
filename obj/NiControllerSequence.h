/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICONTROLLERSEQUENCE_H_
#define _NICONTROLLERSEQUENCE_H_

#include "NiObject.h"
// Include structures
#include "../gen/ControllerLink.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiTextKeyExtraData;
class NiControllerManager;
class NiStringPalette;
class NiTimeController;

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

	/*! Sets the name and block reference to the NiTextKeyExtraData block which will be used by this controller sequence to specify the keyframe labels or "notes."
	 * \param new_name The name of the NiTextKeyExtraData block to use.
	 * \param txt_key A reference to the NiTextKeyExtraData object to use.
	 * \sa NiTextKeyExtraData
	 */
	void SetTextKey( const string new_name, const Ref<NiTextKeyExtraData> & txt_key );

	/*! Attatches a controler to this KF file for a KF file of version 10.2.0.0 or below.  Versions above this use interpolators.
	 * \param target_name The name to re-link this controller with when it is merged with a Nif file.
	 * \param obj A reference to the new NiTimeController to attach.
	 * \sa NiControllerSequence::ClearChildren, NiControllersequence::AddInterpolator
	 */
	void AddController( const string target_name, const Ref<NiTimeController> & obj );

	/*! Attatches an interpolator to this KF file for a KF file of version greater than 10.2.0.0.  Versions below this use controllers.
	 * \param target_name The name to re-link this interpolator with when it is merged with a Nif file.
	 * \param obj A reference to the new NiInterpolator to attach.
	 * \param controller_type The original controller type that this interpolator was connected to.
	 * \sa NiControllerSequence::ClearChildren, NiControllerSequence::AddController
	 */
	void AddInterpolator( const string target_name, const Ref<NiInterpolator> & obj, string controller_type );

	/*! Removes all controllers and interpolators from this Kf file root object.
	 * \sa NiControllerSequence::AddController, NiControllersequence::AddInterpolator
	 */
	void ClearChildren();

private:
	string GetSubStr( const string & pal, short offset ) const;
protected:
	NiControllerManager * NiControllerSequence::Parent() const;
	NI_CONTROLLER_SEQUENCE_MEMBERS
};

#endif
