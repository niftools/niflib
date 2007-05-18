/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _BHKPACKEDNITRISTRIPSSHAPE_H_
#define _BHKPACKEDNITRISTRIPSSHAPE_H_

#include "bhkShapeCollection.h"

// Include structures
#include "../Ref.h"
#include "../gen/OblivionSubShape.h"
namespace Niflib {

// Forward define of referenced NIF objects
class hkPackedNiTriStripsData;

//#include "../gen/obj_defines.h"

class bhkPackedNiTriStripsShape;
typedef Ref<bhkPackedNiTriStripsShape> bhkPackedNiTriStripsShapeRef;

/*!
 * bhkPackedNiTriStripsShape - A shape constructed from strips data.
 */

class bhkPackedNiTriStripsShape : public BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT {
public:
	NIFLIB_API bhkPackedNiTriStripsShape();
	NIFLIB_API ~bhkPackedNiTriStripsShape();
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
	BHK_PACKED_NI_TRI_STRIPS_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
