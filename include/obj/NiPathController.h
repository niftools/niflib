/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPATHCONTROLLER_H_
#define _NIPATHCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPosData;
class NiFloatData;

//#include "../gen/obj_defines.h"

class NiPathController;
typedef Ref<NiPathController> NiPathControllerRef;

/*!
 * NiPathController - Time controller for a path.
 */

class NiPathController : public NI_PATH_CONTROLLER_PARENT {
public:
	NIFLIB_API NiPathController();
	NIFLIB_API ~NiPathController();
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

	//TODO:  This class has a lot of unknown data

	/*!
	 * Retrives the float data used by this controller.
	 * \return The float data.
	 */
	NIFLIB_API Ref<NiFloatData> GetFloatData() const;

	/*!
	 * Sets the float data used by this controller.
	 * \param[in] n The new float data.
	 */
	NIFLIB_API void SetFloatData( NiFloatData * n );

	/*!
	 * Retrives the pos data used by this controller.
	 * \return The pos data.
	 */
	NIFLIB_API Ref<NiPosData> GetPosData() const;

	/*!
	 * Sets the pos data used by this controller.
	 * \param[in] n The new pos data.
	 */
	NIFLIB_API void SetPosData( NiPosData * n );

protected:
	NI_PATH_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
