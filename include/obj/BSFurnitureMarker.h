/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

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
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	NIFLIB_API vector<FurniturePosition> GetFurniturePositions() const;
	NIFLIB_API void SetFurniturePositions( const vector<FurniturePosition> & n );

protected:
	B_S_FURNITURE_MARKER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
