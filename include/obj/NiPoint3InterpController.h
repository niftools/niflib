/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIPOINT3INTERPCONTROLLER_H_
#define _NIPOINT3INTERPCONTROLLER_H_

#include "NiSingleInterpController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPosData;
class NiPoint3InterpController;
typedef Ref<NiPoint3InterpController> NiPoint3InterpControllerRef;

/*!
 * NiPoint3InterpController - A controller that interpolates point 3
 * data?
 */

class NiPoint3InterpController : public NI_POINT3_INTERP_CONTROLLER_PARENT {
public:
	NIFLIB_API NiPoint3InterpController();
	NIFLIB_API ~NiPoint3InterpController();
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

	/*!
	 * Retrives the pos data used by this controller.
	 * \return The pos data.
	 */
	NIFLIB_API Ref<NiPosData> GetData() const;

	/*!
	 * Sets the pos data used by this controller.
	 * \param[in] value The new pos data.
	 */
	NIFLIB_API void SetData( NiPosData * value );

	//--END CUSTOM CODE--//

protected:
	NI_POINT3_INTERP_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
