/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIOBJECTNET_H_
#define _NIOBJECTNET_H_

#include "NiObject.h"

namespace Niflib {

// Forward define of referenced NIF objects
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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
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

	/*! 
	 * Adds an extra data object to this one.  The way this data is stored changed after version 10.0.1.0, so the version
	 * can optionally be included to specify the old storage method.
	 * \param[in] obj The NiExtraData object to attach to this object.
	 * \param[in] version The way the extra data is arranged internally varies with the NIF version, so if a file is to be written, it is best to pass the intended version.  The default is 10.0.1.0, which specifies the newer behavior.
	 */
	NIFLIB_API void AddExtraData( NiExtraData * obj, unsigned version = VER_10_0_1_0 );

	/*! 
	 * Removes an extra data object to this one.
	 * \param[in] obj The NiExtraData object to remove from this object.
	 */
	NIFLIB_API void RemoveExtraData( NiExtraData * obj );

	/*! 
	 * Changes the internal storage method of the extra data in preparation for writing to a file.  This is only necessary if the
	 * extra data was added in one way and needs to be output in another.  This would happen if extra data was loaded from an old file and needed to be written to a file with a newer version.
	 * \param[in] version Specifies the NIF version that the internal data should be arranged for.
	 */
	NIFLIB_API void ShiftExtraData( unsigned int version = VER_10_0_1_0 );

	/*!
	 * Removes all extra data from this object.
	 */
	NIFLIB_API void ClearExtraData();

	/*!
	 * Returns a list of references to all the extra data referenced by this object.
	 * \return All the extra data objects referenced by this one.
	 */
	NIFLIB_API list< Ref<NiExtraData> > GetExtraData() const;

	/*!
	 * Used to determine whether this object is animated.  In other words, whether it has any controllers.
	 * \return True if the object has controllers, false otherwise.
	 */
	NIFLIB_API bool IsAnimated();

	/*!
	 * Adds a controller to this object.  Controllers allow various properties to be animated over time.
	 * \param[in] obj The controller to add.
	 */
	NIFLIB_API void AddController( NiTimeController * obj );

	/*!
	 * Removes a controller from this object.  Controllers allow various properties to be animated over time.
	 * \param[in] obj The controller to remove.
	 */
	NIFLIB_API void RemoveController( NiTimeController * obj );

	/*!
	 * Removes all controllers from this object.  This will remove any animation from it.
	 */
	NIFLIB_API void ClearControllers();

	/*!
	 * Gets a list of all controllers affecting this object.
	 * \return All the controllers affecting this object.
	 */
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
