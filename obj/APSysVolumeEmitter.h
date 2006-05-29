/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _APSYSVOLUMEEMITTER_H_
#define _APSYSVOLUMEEMITTER_H_

#include "xml_extract.h"
#include A_P_SYS_VOLUME_EMITTER_INCLUDE

/*
 * APSysVolumeEmitter
 */

class APSysVolumeEmitter;
typedef Ref<APSysVolumeEmitter> APSysVolumeEmitterRef;

class APSysVolumeEmitter : public A_P_SYS_VOLUME_EMITTER_PARENT {
public:
	APSysVolumeEmitter();
	~APSysVolumeEmitter();
	//Run-Time Type Information
	static const Type TYPE;
	virtual const Type & GetType() const { return TYPE; };
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
private:
	A_P_SYS_VOLUME_EMITTER_MEMBERS
};
#endif
