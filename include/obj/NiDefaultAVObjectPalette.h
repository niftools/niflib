/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NIDEFAULTAVOBJECTPALETTE_H_
#define _NIDEFAULTAVOBJECTPALETTE_H_

#include "NiObject.h"

// Include structures
#include "../gen/AVObject.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiDefaultAVObjectPalette;
typedef Ref<NiDefaultAVObjectPalette> NiDefaultAVObjectPaletteRef;

/*!
 * NiDefaultAVObjectPalette - Unknown. Refers to a list of objects. Used
 * by NiControllerManager.
 */

class NiDefaultAVObjectPalette : public NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT {
public:
	NIFLIB_API NiDefaultAVObjectPalette();
	NIFLIB_API ~NiDefaultAVObjectPalette();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Gets the AV Objects stored in this palette.
	 * \return The AV Objects stored in this palette.
	 */
	NIFLIB_API vector<Ref<NiAVObject> > GetObjs() const;

	/*!
	 * Sets the AV Objects stored in this palette.
	 * \return The new AV Objects to be stored in this palette.
	 */
	NIFLIB_API void SetObjs( const vector<Ref<NiAVObject> >& value );

protected:
	NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
