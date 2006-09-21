/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIFLOATEXTRADATACONTROLLER_H_
#define _NIFLOATEXTRADATACONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiObject;

#include "../gen/obj_defines.h"

class NiFloatExtraDataController;
typedef Ref<NiFloatExtraDataController> NiFloatExtraDataControllerRef;

/*!
 * NiFloatExtraDataController - Unknown.
 */

class NIFLIB_API NiFloatExtraDataController : public NI_FLOAT_EXTRA_DATA_CONTROLLER_PARENT {
public:
	NiFloatExtraDataController();
	~NiFloatExtraDataController();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	//TODO:  The function of all data is currently unknown.
protected:
	NI_FLOAT_EXTRA_DATA_CONTROLLER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
