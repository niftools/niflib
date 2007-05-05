/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICONTROLLERMANAGER_H_
#define _NICONTROLLERMANAGER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 *  Used to determine whether or not the animation sequences are cumulative.
	 * \return True if animation sequences are cumulative, false otherwise.
	 */
	NIFLIB_API bool GetCumulative() const;

	/*!
	 *  Used to set whether or not the animation sequences are cumulative.
	 * \param[in] value True if animation sequences are to be cumulative, false otherwise.
	 */
	NIFLIB_API void SetCumulative( bool value );

	/*!
	 * Retrives the list of controller sequences that this controller manager references.
	 * \return The controller sequences.
	 */
	NIFLIB_API vector< Ref<NiControllerSequence> > GetControllerSequences() const;

	/*!
	 * Sets the list of controller sequences that this controller manager references.
	 * \param[in] value The new controller sequences.
	 */
	NIFLIB_API void SetControllerSequences( const vector< Ref<NiControllerSequence> > & value );


	/*!
	 * Adds a new controller sequence to this controller manager.
	 * \param[in] obj The new controller sequence to add.
	 */
	NIFLIB_API void AddSequence( NiControllerSequence * obj );

	/*!
	 * Removes a single controller sequence from this controller manager.
	 * \param[in] obj The controller sequence to remove.
	 */
	NIFLIB_API void RemoveSequence( NiControllerSequence * obj );

	/*!
	 * Removes all controller sequences from this controller manager.
	 */
	NIFLIB_API void ClearSequences();

	/*!
	 * Retrives the oject pallete object used by this controller manager.
	 * \return The object pallete.
	 */
	NIFLIB_API Ref<NiDefaultAVObjectPalette > GetObjectPalette() const;

	/*!
	 * Sets the object pallete object used by this controller manager.
	 * \param[in] value The new object pallete.
	 */
	NIFLIB_API void SetObjectPalette( NiDefaultAVObjectPalette * value );

protected:
	NI_CONTROLLER_MANAGER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
