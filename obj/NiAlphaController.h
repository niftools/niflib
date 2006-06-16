/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIALPHACONTROLLER_H_
#define _NIALPHACONTROLLER_H_

#include "NiSingleInterpolatorController.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiFloatData;

#include "../gen/obj_defines.h"

class NiAlphaController;
typedef Ref<NiAlphaController> NiAlphaControllerRef;

/*!
 * NiAlphaController - Time controller for transparency.
 */

class NIFLIB_API NiAlphaController : public NI_ALPHA_CONTROLLER_PARENT {
public:
	NiAlphaController();
	~NiAlphaController();
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
	NI_ALPHA_CONTROLLER_MEMBERS
};

#endif
