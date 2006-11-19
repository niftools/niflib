/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBONELODCONTROLLER_H_
#define _NIBONELODCONTROLLER_H_

#include "ABoneLODController.h"

// Include structures
#include "../gen/SkinShapeGroup.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiTriShape;

//#include "../gen/obj_defines.h"

class NiBoneLODController;
typedef Ref<NiBoneLODController> NiBoneLODControllerRef;

/*!
 * NiBoneLODController - A LOD controller for bones?
 */

class NIFLIB_API NiBoneLODController : public NI_BONE_L_O_D_CONTROLLER_PARENT {
public:
	NiBoneLODController();
	~NiBoneLODController();
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

protected:
	NI_BONE_L_O_D_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
