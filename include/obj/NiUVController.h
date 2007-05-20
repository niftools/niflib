/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIUVCONTROLLER_H_
#define _NIUVCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiUVData;

//#include "../gen/obj_defines.h"

class NiUVController;
typedef Ref<NiUVController> NiUVControllerRef;

/*!
 * NiUVController - Time controller for texture coordinates.
 */

class NiUVController : public NI_U_V_CONTROLLER_PARENT {
public:
	NIFLIB_API NiUVController();
	NIFLIB_API ~NiUVController();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	//TODO:  This class has an unknown member

	/*!
	 * Retrives the UV data used by this controller.
	 * \return The UV data.
	 */
	NIFLIB_API Ref<NiUVData> GetData() const;

	/*!
	 * Sets the UV data used by this controller.
	 * \param[in] n The new UV data.
	 */
	NIFLIB_API void SetData( NiUVData * n );

	//--END CUSTOM CODE--//

protected:
	NI_U_V_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
