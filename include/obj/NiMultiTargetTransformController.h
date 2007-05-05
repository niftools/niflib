/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMULTITARGETTRANSFORMCONTROLLER_H_
#define _NIMULTITARGETTRANSFORMCONTROLLER_H_

#include "NiTimeController.h"

namespace Niflib {

// Forward define of referenced NIF objects
class NiNode;

//#include "../gen/obj_defines.h"

class NiMultiTargetTransformController;
typedef Ref<NiMultiTargetTransformController> NiMultiTargetTransformControllerRef;

/*!
 * NiMultiTargetTransformController - Unknown.
 */

class NiMultiTargetTransformController : public NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENT {
public:
	NIFLIB_API NiMultiTargetTransformController();
	NIFLIB_API ~NiMultiTargetTransformController();
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
	 * Retrives a list of the extra NiNode targets to be controlled.
	 * \return The NiNode targets to be controlled.
	 */
	NIFLIB_API vector<Ref<NiNode> > GetExtraTargets() const;

	/*!
	 * Sets the list of the extra NiNode targets to be controlled.
	 * \param[in] value The new NiNode targets to be controlled.
	 */
	NIFLIB_API void SetExtraTargets( const vector< Ref<NiNode> > & value );

protected:
	NI_MULTI_TARGET_TRANSFORM_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
