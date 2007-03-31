/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTERCTLR_H_
#define _NIPSYSEMITTERCTLR_H_

#include "APSysCtlr.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
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
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * This controller's data
	 */
	NIFLIB_API Ref<NiPSysEmitterCtlrData > GetData() const;
	NIFLIB_API void SetData( Ref<NiPSysEmitterCtlrData > value );

	/*!
	 * Links to a bool interpolator. Controls emitter's visibility status?
	 */
	NIFLIB_API Ref<NiInterpolator > GetVisibilityInterpolator() const;
	NIFLIB_API void SetVisibilityInterpolator( Ref<NiInterpolator > value );

protected:
	NI_P_SYS_EMITTER_CTLR_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
