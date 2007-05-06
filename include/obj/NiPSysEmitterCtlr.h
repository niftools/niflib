/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIPSYSEMITTERCTLR_H_
#define _NIPSYSEMITTERCTLR_H_

#include "APSysCtlr.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPSysEmitterCtlrData;
class NiInterpolator;

//#include "../gen/obj_defines.h"

class NiPSysEmitterCtlr;
typedef Ref<NiPSysEmitterCtlr> NiPSysEmitterCtlrRef;

/*!
 * NiPSysEmitterCtlr - Particle system emitter controller.
 */

class NiPSysEmitterCtlr : public NI_P_SYS_EMITTER_CTLR_PARENT {
public:
	NIFLIB_API NiPSysEmitterCtlr();
	NIFLIB_API ~NiPSysEmitterCtlr();
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
	 * Retrives the data object used by this controller.
	 * \return The data object.
	 */
	NIFLIB_API Ref<NiPSysEmitterCtlrData> GetData() const;

	/*!
	 * Sets the data object used by this controller.
	 * \param[in] value The new data object.
	 */
	NIFLIB_API void SetData( NiPSysEmitterCtlrData * value );

	/*!
	 * Retrives the visibility interpolator used by this controller.
	 * \return The visibility interpolator.
	 */
	NIFLIB_API Ref<NiInterpolator> GetVisibilityInterpolator() const;

	/*!
	 * Sets the visibility interpolator used by this controller.
	 * \param[in] value The new visibility interpolator.
	 */
	NIFLIB_API void SetVisibilityInterpolator( NiInterpolator * value );

protected:
	NI_P_SYS_EMITTER_CTLR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
