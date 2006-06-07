/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NITEXTURETRANSFORMCONTROLLER_H_
#define _NITEXTURETRANSFORMCONTROLLER_H_

#include "NiSingleInterpolatorController.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiFloatData;

#include "../gen/obj_defines.h"

class NiTextureTransformController;
typedef Ref<NiTextureTransformController> NiTextureTransformControllerRef;

/*!
 * NiTextureTransformController - Texture transformation controller.
 */

class NIFLIB_API NiTextureTransformController : public NI_TEXTURE_TRANSFORM_CONTROLLER_PARENT {
public:
	NiTextureTransformController();
	~NiTextureTransformController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_TEXTURE_TRANSFORM_CONTROLLER_MEMBERS
};

#endif
