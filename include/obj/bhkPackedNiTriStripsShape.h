/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKPACKEDNITRISTRIPSSHAPE_H_
#define _BHKPACKEDNITRISTRIPSSHAPE_H_

#include "AbhkShapeCollection.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class hkPackedNiTriStripsData;

#include "../gen/obj_defines.h"

class bhkPackedNiTriStripsShape;
typedef Ref<bhkPackedNiTriStripsShape> bhkPackedNiTriStripsShapeRef;

/*!
 * bhkPackedNiTriStripsShape - A shape constructed from strips data.
 */

class NIFLIB_API bhkPackedNiTriStripsShape : public BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT {
public:
	bhkPackedNiTriStripsShape();
	~bhkPackedNiTriStripsShape();
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

protected:
	BHK_PACKED_NI_TRI_STRIPS_SHAPE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
