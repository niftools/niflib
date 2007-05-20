/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _NICOLORDATA_H_
#define _NICOLORDATA_H_

#include "NiObject.h"
// Include structures
#include "../gen/KeyGroup.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiColorData;
typedef Ref<NiColorData> NiColorDataRef;

/*!
 * NiColorData - Color data for material color controller.
 */

class NiColorData : public NI_COLOR_DATA_PARENT {
public:
	NIFLIB_API NiColorData();
	NIFLIB_API ~NiColorData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//--BEGIN MISC CUSTOM CODE--//

	/*! Retrieves the type of color interpolation being used.
	 * \return The color key type specifing the type of interpolation being used.
	 * \sa NiColorData::SetKeyType
	 */
	NIFLIB_API KeyType GetKeyType() const;

	/*! Sets the type of color interpolation being used.  Does not affect existing key data.
	 * \param t The new color key type specifing the type of interpolation to be used.
	 * \sa NiColorData::GetKeyType
	 */
	NIFLIB_API void SetKeyType( KeyType t );

	/*! Retrieves the color key data.
	 * \return A vector containing Key<Color4> data which specify color over time.
	 * \sa NiColorData::SetKeys, Key
	 */
	NIFLIB_API vector< Key<Color4> > GetKeys() const;

	/*! Sets the color key data.
	 * \param keys A vector containing new Key<Color4> data which will replace any existing data.
	 * \sa NiColorData::GetKeys, Key
	 */
	NIFLIB_API void SetKeys( vector< Key<Color4> > const & keys );

	//--END CUSTOM CODE--//

protected:
	NI_COLOR_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
