/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKENTITY_H_
#define _BHKENTITY_H_

#include "bhkWorldObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class bhkShape;

#include "../gen/obj_defines.h"

class bhkEntity;
typedef Ref<bhkEntity> bhkEntityRef;

/*!
 * bhkEntity - A havok node, describes physical properties.
 */

class NIFLIB_API bhkEntity : public BHK_ENTITY_PARENT {
public:
	bhkEntity();
	~bhkEntity();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

protected:
	BHK_ENTITY_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
