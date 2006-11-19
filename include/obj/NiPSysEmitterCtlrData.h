/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTERCTLRDATA_H_
#define _NIPSYSEMITTERCTLRDATA_H_

#include "NiObject.h"

// Include structures
#include "../gen/KeyGroup.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiPSysEmitterCtlrData;
typedef Ref<NiPSysEmitterCtlrData> NiPSysEmitterCtlrDataRef;

/*!
 * NiPSysEmitterCtlrData - Particle system emitter controller data.
 */

class NIFLIB_API NiPSysEmitterCtlrData : public NI_P_SYS_EMITTER_CTLR_DATA_PARENT {
public:
	NiPSysEmitterCtlrData();
	~NiPSysEmitterCtlrData();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Unknown.
	 */
	KeyGroup<float > GetFloatKeys_() const;
	void SetFloatKeys_( KeyGroup<float > value );

	/*!
	 * Unknown.
	 */
	vector<Key<byte > > GetVisibilityKeys_() const;
	void SetVisibilityKeys_( const vector<Key<byte > >& value );

protected:
	NI_P_SYS_EMITTER_CTLR_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
