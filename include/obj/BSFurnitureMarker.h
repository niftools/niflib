/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#ifndef _BSFURNITUREMARKER_H_
#define _BSFURNITUREMARKER_H_

#include "NiExtraData.h"

// Include structures
#include "../gen/FurniturePosition.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class BSFurnitureMarker;
typedef Ref<BSFurnitureMarker> BSFurnitureMarkerRef;

/*!
 * BSFurnitureMarker - Unknown. Marks furniture sitting positions?
 */

class BSFurnitureMarker : public B_S_FURNITURE_MARKER_PARENT {
public:
	NIFLIB_API BSFurnitureMarker();
	NIFLIB_API ~BSFurnitureMarker();
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

	/*!
	 * Retrieves the furniture marker positions.  These are markers that show where the character will end up if he/she sits or lies on this object.
	 * \return The furniture marker positions.
	 */
	NIFLIB_API vector<FurniturePosition> GetFurniturePositions() const;

	/*!
	 * Sets the furniture marker positions.  These are markers that show where the character will end up if he/she sits or lies on this object.
	 * \return The new furniture marker positions.
	 */
	NIFLIB_API void SetFurniturePositions( const vector<FurniturePosition> & n );

	//--END CUSTOM CODE--//

protected:
	B_S_FURNITURE_MARKER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
