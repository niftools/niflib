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

//#include "../gen/obj_defines.h"

class bhkEntity;
typedef Ref<bhkEntity> bhkEntityRef;

/*!
 * bhkEntity - A havok node, describes physical properties.
 */

class bhkEntity : public BHK_ENTITY_PARENT {
public:
	NIFLIB_API bhkEntity();
	NIFLIB_API ~bhkEntity();
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
	 * Retrieves the shape object that this body is using.
	 * \param[in] value The shape object being used by this body.
	 */
	NIFLIB_API Ref<bhkShape > GetShape() const;

	/*!
	 * Sets the shape object that this body will use.
	 * \param[in] value The new shape object for this body to use.
	 */
	NIFLIB_API void SetShape( bhkShape * value );

	/*!
	 * Gets the current Oblivion layer, which seems to determine the mesh color displayed by the Oblivion Construction Set.
	 * \return The current Oblivion Layer.
	 */
	NIFLIB_API OblivionLayer GetLayer() const;

	/*!
	 * Sets the Oblivion layer, which seems to determine the mesh color displayed by the Oblivion Construction Set.
	 * \param[in] value The new Oblivoin layer to use.
	 */
	NIFLIB_API void SetLayer( OblivionLayer value );

protected:
	BHK_ENTITY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
