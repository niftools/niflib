/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISTRINGPALETTE_H_
#define _NISTRINGPALETTE_H_

#include "NiObject.h"

// Include structures
#include "../gen/StringPalette.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiStringPalette;
typedef Ref<NiStringPalette> NiStringPaletteRef;

/*!
 * NiStringPalette - List of 0x00-seperated strings, which are names of
 * controlled blocks and controller types. Used in .kf files in
 * conjunction with NiControllerSequence.
 */

class NiStringPalette : public NI_STRING_PALETTE_PARENT {
public:
	NIFLIB_API NiStringPalette();
	NIFLIB_API ~NiStringPalette();
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

	NIFLIB_API string GetPaletteString() const;
	NIFLIB_API void SetPaletteString( const string & n );
	NIFLIB_API string GetSubStr( short offset ) const;
	NIFLIB_API unsigned int AddSubStr( const string & n );

protected:
	NI_STRING_PALETTE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
