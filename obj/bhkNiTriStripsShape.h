/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKNITRISTRIPSSHAPE_H_
#define _BHKNITRISTRIPSSHAPE_H_

#include "bhkSphereRepShape.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiTriStripsData;

#include "../gen/obj_defines.h"

class bhkNiTriStripsShape;
typedef Ref<bhkNiTriStripsShape> bhkNiTriStripsShapeRef;

/*!
 * bhkNiTriStripsShape - A shape constructed from a bunch of strips.
 */

class NIFLIB_API bhkNiTriStripsShape : public BHK_NI_TRI_STRIPS_SHAPE_PARENT {
public:
	bhkNiTriStripsShape();
	~bhkNiTriStripsShape();
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

	/*!
	 * Scale. Usually (1.0, 1.0, 1.0).
	 */
	Vector3 GetScale() const;
	void SetScale( const Vector3 & n );

	void	SetNumStripsData(int i);
	void	SetStripsData(int i, Ref<NiTriStripsData> &);

protected:
	BHK_NI_TRI_STRIPS_SHAPE_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
