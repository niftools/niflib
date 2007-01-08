/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPATHCONTROLLER_H_
#define _NIPATHCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiPosData;
class NiFloatData;

//#include "../gen/obj_defines.h"

class NiPathController;
typedef Ref<NiPathController> NiPathControllerRef;

/*!
 * NiPathController - Time controller for a path.
 */

class NIFLIB_API NiPathController : public NI_PATH_CONTROLLER_PARENT {
public:
	NiPathController();
	~NiPathController();
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

	//TODO:  This class has a lot of unknown data
	Ref<NiFloatData> GetFloatData() const;
	void SetFloatData( const Ref<NiFloatData> & n );

	Ref<NiPosData> GetPosData() const;
	void SetPosData( const Ref<NiPosData> & n );
protected:
	NI_PATH_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
