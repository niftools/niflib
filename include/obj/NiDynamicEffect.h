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

class NIFLIB_API NiDynamicEffect : public NI_DYNAMIC_EFFECT_PARENT {
public:
	NiDynamicEffect();
	~NiDynamicEffect();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Turns effect on and off?  Switches list to list of unaffected nodes?
	 */
	bool GetSwitchState() const;
	void SetSwitchState( bool value );

	/*!
	 * The list of affected nodes?
	 */
	vector<Ref<NiAVObject > > GetAffectedNodes() const;
	void SetAffectedNodes( const vector<Ref<NiAVObject > >& value );

	/*!
	 * This is probably the list of affected nodes. For some reason i do not
	 * know the max exporter seems to write pointers instead of links. But it
	 * doesn't matter because at least in version 4.0.0.2 the list is
	 * automagically updated by the engine during the load stage.
	 */
	vector<unsigned int> GetAffectedNodeListPointers() const;
	void SetAffectedNodeListPointers( const vector<uint >& value );

protected:
	NI_DYNAMIC_EFFECT_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
