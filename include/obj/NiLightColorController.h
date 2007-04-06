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

//#include "../gen/obj_defines.h"

class NiLightColorController;
typedef Ref<NiLightColorController> NiLightColorControllerRef;

/*!
 * NiLightColorController - Light color animation controller.
 */

class NiLightColorController : public NI_LIGHT_COLOR_CONTROLLER_PARENT {
public:
	NIFLIB_API NiLightColorController();
	NIFLIB_API ~NiLightColorController();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Link to NiPosData
	 */
	NIFLIB_API Ref<NiPosData > GetData() const;
	NIFLIB_API void SetData( Ref<NiPosData > value );

	/*!
	 * Link to NiPoint3Interpolator.
	 */
	NIFLIB_API Ref<NiPoint3Interpolator > GetInterpolator() const;
	NIFLIB_API void SetInterpolator( Ref<NiPoint3Interpolator > value );

protected:
	NI_LIGHT_COLOR_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
