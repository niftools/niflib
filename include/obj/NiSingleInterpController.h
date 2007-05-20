/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NISINGLEINTERPCONTROLLER_H_
#define _NISINGLEINTERPCONTROLLER_H_

#include "NiInterpController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiInterpolator;
class NiSingleInterpController;
typedef Ref<NiSingleInterpController> NiSingleInterpControllerRef;

/*!
 * NiSingleInterpController - A controller referring to a single
 * interpolator.
 */

class NiSingleInterpController : public NI_SINGLE_INTERP_CONTROLLER_PARENT {
public:
	NIFLIB_API NiSingleInterpController();
	NIFLIB_API ~NiSingleInterpController();
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
	 * Retrives the interpolator used by this controller.
	 * \return The interpolator.
	 */
	NIFLIB_API Ref<NiInterpolator> GetInterpolator() const;

	/*!
	 * Sets the interpolator used by this controller.
	 * \param[in] value The new interpolator.
	 */
	NIFLIB_API void SetInterpolator( NiInterpolator * value );

	//--END CUSTOM CODE--//

protected:
	NI_SINGLE_INTERP_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
