/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _BHKPHANTOM_H_
#define _BHKPHANTOM_H_

#include "bhkWorldObject.h"
namespace Niflib {

class bhkPhantom;
typedef Ref<bhkPhantom> bhkPhantomRef;

/*!
 * bhkPhantom - Havok object that do not react with other objects when
 * they collide (causing deflection, etc.) but still trigger collision
 * notifications to the game.  Possible uses are traps, portals, AI
 * fields, etc.
 */

class bhkPhantom : public BHK_PHANTOM_PARENT {
public:
	NIFLIB_API bhkPhantom();
	NIFLIB_API ~bhkPhantom();
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
	BHK_PHANTOM_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
