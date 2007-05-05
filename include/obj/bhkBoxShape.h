/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKBOXSHAPE_H_
#define _BHKBOXSHAPE_H_

#include "bhkConvexShape.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class bhkBoxShape;
typedef Ref<bhkBoxShape> bhkBoxShapeRef;

/*!
 * bhkBoxShape - A box.
 */

class bhkBoxShape : public BHK_BOX_SHAPE_PARENT {
public:
	NIFLIB_API bhkBoxShape();
	NIFLIB_API ~bhkBoxShape();
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
	 * Gets the dimentions of the box.
	 * \return The dimentions of the bounding box.
	 */
	NIFLIB_API Vector3 GetDimensions() const;

	/*!
	 * Sets the dimentions of the box.
	 * \param The new dimentions for the bounding box.
	 */
	NIFLIB_API void SetDimensions( const Vector3 & value );

protected:
	BHK_BOX_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
