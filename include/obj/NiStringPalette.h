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
 * controlled objects and controller types. Used in .kf files in
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

	/*!
	 * Retrieves the entire palette string.  This is a buffer of characters that will contain the all the strings stored in this palette.  It is usually better to get individual strings with the NiStringPalette::GetSubStr function.
	 * \return The entire palette string.
	 */
	NIFLIB_API string GetPaletteString() const;

	/*!
	 * Sets the contents of the entire palette string.  This is a buffer of characters that will contain the all the strings stored in this palette.  It is usually better to add individual strings with the NiStringPalette::AddSubStr function.
	 * \param[in] n The new palette string.  This will overwrite all existing strings stored in the palette.
	 */
	NIFLIB_API void SetPaletteString( const string & n );

	/*!
	 * Retrieves a particular sub string from the palette by offset into the string palette.
	 * \param[in] offset The offset into the string palette where the desired sub string starts.  I.e. the number of characters that preceed it in the string palette.
	 * \return The sub string starting at the specified offset in the string palette.
	 */
	NIFLIB_API string GetSubStr( short offset ) const;

	/*!
	 * Adds a new sub string to the end of the string palete and returns the offset position where it was added.
	 * \param[in] n The new sub string to add.
	 * \return The offset into the string palette where the new sub string was added.  I.e. the number of characters that preceed it in the string palette.
	 */
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
