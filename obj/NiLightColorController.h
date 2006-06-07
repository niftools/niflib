/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILIGHTCOLORCONTROLLER_H_
#define _NILIGHTCOLORCONTROLLER_H_

#include "NiTimeController.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiPosData;
class NiPoint3Interpolator;

#include "../gen/obj_defines.h"

class NiLightColorController;
typedef Ref<NiLightColorController> NiLightColorControllerRef;

/*!
 * NiLightColorController - Light color animation controller.
 */

class DLLEXPORT NiLightColorController : public NI_LIGHT_COLOR_CONTROLLER_PARENT {
public:
	NiLightColorController();
	~NiLightColorController();
	//Run-Time Type Information
	static const Type TYPE;
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;
protected:
	NI_LIGHT_COLOR_CONTROLLER_MEMBERS
};

#endif
