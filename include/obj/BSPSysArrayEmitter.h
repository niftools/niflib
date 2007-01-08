/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BSPSYSARRAYEMITTER_H_
#define _BSPSYSARRAYEMITTER_H_

#include "NiPSysVolumeEmitter.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class BSPSysArrayEmitter;
typedef Ref<BSPSysArrayEmitter> BSPSysArrayEmitterRef;

/*!
 * BSPSysArrayEmitter - Unknown.
 */

class NIFLIB_API BSPSysArrayEmitter : public B_S_P_SYS_ARRAY_EMITTER_PARENT {
public:
	BSPSysArrayEmitter();
	~BSPSysArrayEmitter();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	B_S_P_SYS_ARRAY_EMITTER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
