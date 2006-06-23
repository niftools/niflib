/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILIGHTCOLORCONTROLLER_H_
#define _NILIGHTCOLORCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiPosData;
class NiPoint3Interpolator;

#include "../gen/obj_defines.h"

class NiLightColorController;
typedef Ref<NiLightColorController> NiLightColorControllerRef;

/*!
 * NiLightColorController - Light color animation controller.
 */

class NIFLIB_API NiLightColorController : public NI_LIGHT_COLOR_CONTROLLER_PARENT {
public:
	NiLightColorController();
	~NiLightColorController();
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

	/*!
	 * Link to NiPosData
	 */
	Ref<NiPosData > GetData() const;
	void SetData( Ref<NiPosData > value );

	/*!
	 * Link to NiPoint3Interpolator.
	 */
	Ref<NiPoint3Interpolator > GetInterpolator() const;
	void SetInterpolator( Ref<NiPoint3Interpolator > value );

protected:
	NI_LIGHT_COLOR_CONTROLLER_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
