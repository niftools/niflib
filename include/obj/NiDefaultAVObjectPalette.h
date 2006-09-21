/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIDEFAULTAVOBJECTPALETTE_H_
#define _NIDEFAULTAVOBJECTPALETTE_H_

#include "NiObject.h"

// Include structures
#include "../gen/AVObject.h"
namespace Niflib {


#include "../gen/obj_defines.h"

class NiDefaultAVObjectPalette;
typedef Ref<NiDefaultAVObjectPalette> NiDefaultAVObjectPaletteRef;

/*!
 * NiDefaultAVObjectPalette - Unknown. Refers to a list of objects. Used
 * by NiControllerManager.
 */

class NIFLIB_API NiDefaultAVObjectPalette : public NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT {
public:
	NiDefaultAVObjectPalette();
	~NiDefaultAVObjectPalette();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * The objects.
	 */
	vector<Ref<NiAVObject> > GetObjs() const;
	void SetObjs( const vector<Ref<NiAVObject> >& value );

protected:
	NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
