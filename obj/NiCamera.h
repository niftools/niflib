/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NICAMERA_H_
#define _NICAMERA_H_

#include "NiAVObject.h"

// Forward define of referenced blocks
#include "Ref.h"
class NiObject;

#include "gen/obj_defines.h"

/*
 * NiCamera
 */

class NiCamera;
typedef Ref<NiCamera> NiCameraRef;

class NiCamera : public NI_CAMERA_PARENT {
public:
	NiCamera();
	~NiCamera();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version );
	virtual const Type & GetType() const;
protected:
	NI_CAMERA_MEMBERS
};

#endif
