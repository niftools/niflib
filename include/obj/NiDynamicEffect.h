/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIDYNAMICEFFECT_H_
#define _NIDYNAMICEFFECT_H_

#include "NiAVObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiAVObject;

//#include "../gen/obj_defines.h"

class NiDynamicEffect;
typedef Ref<NiDynamicEffect> NiDynamicEffectRef;

/*!
 * NiDynamicEffect - A dynamic effect such as a light or environment map.
 */

class NiDynamicEffect : public NI_DYNAMIC_EFFECT_PARENT {
public:
	NIFLIB_API NiDynamicEffect();
	NIFLIB_API ~NiDynamicEffect();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Gets the current switch state for this effect.  Perhaps this turns effect on and off?
	 * \return The current switch state for this object.
	 */
	NIFLIB_API bool GetSwitchState() const;

	/*!
	 * Sets the current switch state for this effect.  Perhaps this turns effect on and off?
	 * \param[in] value The new switch state for this object.
	 */
	NIFLIB_API void SetSwitchState( bool value );

	/*!
	 * Retrieves what appears to be a list of the nodes that will be affected by this effect.
	 * \return A list of the nodes that will be affected by this effect.
	 */
	NIFLIB_API vector<Ref<NiAVObject > > GetAffectedNodes() const;

	/*!
	 * Sets what appears to be a list of the nodes that will be affected by this effect.
	 * \param[in] value A list of the new nodes that will be affected by this effect.
	 */
	NIFLIB_API void SetAffectedNodes( const vector<Ref<NiAVObject > >& value );

protected:
	NI_DYNAMIC_EFFECT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
