/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKNITRISTRIPSSHAPE_H_
#define _BHKNITRISTRIPSSHAPE_H_

#include "bhkSphereRepShape.h"

// Include structures
#include "../Ref.h"
#include "../gen/OblivionColFilter.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiTriStripsData;

//#include "../gen/obj_defines.h"

class bhkNiTriStripsShape;
typedef Ref<bhkNiTriStripsShape> bhkNiTriStripsShapeRef;

/*!
 * bhkNiTriStripsShape - A shape constructed from a bunch of strips.
 */

class bhkNiTriStripsShape : public BHK_NI_TRI_STRIPS_SHAPE_PARENT {
public:
	NIFLIB_API bhkNiTriStripsShape();
	NIFLIB_API ~bhkNiTriStripsShape();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Gets the scale. Usually (1.0, 1.0, 1.0).
	 * \return The scale.
	 */
	NIFLIB_API Vector3 GetScale() const;

	/*!
	 * Sets the scale. Usually (1.0, 1.0, 1.0).
	 * \param[in] n The new scale.
	 */
	NIFLIB_API void SetScale( const Vector3 & n );

	/*!
	 * Sets the number of NiTriStripsData objects referenced by this shape.
	 * \param[in] n The new number of NiTriStripsData objects.
	 */
	NIFLIB_API void	SetNumStripsData(int i);

	/*!
	 * Sets the NiTriStripsData object referenced by this shape at the specified index.
	 * \param[in] index The index at which the given NiTriStripsData object will be referenced.  Should be lower than the value set with bhkNiTriStripsShape::SetNumStripsData.
	 * \param[in] strips The new NiTriStripsData object to be referenced by this shape at the specified index.
	 */
	NIFLIB_API void	SetStripsData( int index, NiTriStripsData * strips );

protected:
	BHK_NI_TRI_STRIPS_SHAPE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
