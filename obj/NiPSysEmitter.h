/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPSYSEMITTER_H_
#define _NIPSYSEMITTER_H_

#include "NiPSysModifier.h"
namespace NifLib {


#include "../gen/obj_defines.h"

class NiPSysEmitter;
typedef Ref<NiPSysEmitter> NiPSysEmitterRef;

/*!
 * NiPSysEmitter - A particle emitter modifier?
 */

class NIFLIB_API NiPSysEmitter : public NI_P_SYS_EMITTER_PARENT {
public:
	NiPSysEmitter();
	~NiPSysEmitter();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	NI_P_SYS_EMITTER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
