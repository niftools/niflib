/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIPALETTE_H_
#define _NIPALETTE_H_

#include "NiObject.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiPalette;
typedef Ref<NiPalette> NiPaletteRef;

/*!
 * NiPalette - A color palette.
 */

class NIFLIB_API NiPalette : public NI_PALETTE_PARENT {
public:
	NiPalette();
	~NiPalette();
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

	/*! Retrieves the palette data from this palette block.
	 * \return A vector containing the the colors stored in the palette.
	 * \sa NiPalette::SetPalette
	 */
	vector<Color4> GetPalette() const;

	/*! Sets the palette data for this palette block.
	 * \param new_pal A vector containing the the new colors to be stored in the palette.
	 * \sa NiPalette::GetPalette
	 */
	void SetPalette( const vector<Color4> & new_pal );
protected:
	NI_PALETTE_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
