/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIMATERIALCOLORCONTROLLER_H_
#define _NIMATERIALCOLORCONTROLLER_H_

#include "NiSingleInterpolatorController.h"

// Include structures
#include "../Ref.h"
namespace NifLib {

// Forward define of referenced blocks
class NiPosData;

#include "../gen/obj_defines.h"

class NiMaterialColorController;
typedef Ref<NiMaterialColorController> NiMaterialColorControllerRef;

/*!
 * NiMaterialColorController - Time controller for material color.
 */

class NIFLIB_API NiMaterialColorController : public NI_MATERIAL_COLOR_CONTROLLER_PARENT {
public:
	NiMaterialColorController();
	~NiMaterialColorController();
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
	NI_MATERIAL_COLOR_CONTROLLER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
