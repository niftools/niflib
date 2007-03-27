/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIDYNAMICEFFECT_H_
#define _NIDYNAMICEFFECT_H_

#include "NiAVObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
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
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Turns effect on and off?  Switches list to list of unaffected nodes?
	 */
	NIFLIB_API bool GetSwitchState() const;
	NIFLIB_API void SetSwitchState( bool value );

	/*!
	 * The list of affected nodes?
	 */
	NIFLIB_API vector<Ref<NiAVObject > > GetAffectedNodes() const;
	NIFLIB_API void SetAffectedNodes( const vector<Ref<NiAVObject > >& value );

	/*!
	 * This is probably the list of affected nodes. For some reason i do not
	 * know the max exporter seems to write pointers instead of links. But it
	 * doesn't matter because at least in version 4.0.0.2 the list is
	 * automagically updated by the engine during the load stage.
	 */
	NIFLIB_API vector<unsigned int> GetAffectedNodeListPointers() const;
	NIFLIB_API void SetAffectedNodeListPointers( const vector<unsigned int >& value );

protected:
	NI_DYNAMIC_EFFECT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
