/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIBONELODCONTROLLER_H_
#define _NIBONELODCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../gen/SkinShapeGroup.h"
#include "../gen/NodeGroup.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiTriShape;

//#include "../gen/obj_defines.h"

class NiBoneLODController;
typedef Ref<NiBoneLODController> NiBoneLODControllerRef;

/*!
 * NiBoneLODController - A LOD controller for bones?
 */

class NiBoneLODController : public NI_BONE_L_O_D_CONTROLLER_PARENT {
public:
	NIFLIB_API NiBoneLODController();
	NIFLIB_API ~NiBoneLODController();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

protected:
	NI_BONE_L_O_D_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
