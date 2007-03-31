/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIGEOMMORPHERCONTROLLER_H_
#define _NIGEOMMORPHERCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiMorphData;
class NiInterpolator;

//#include "../gen/obj_defines.h"

class NiGeomMorpherController;
typedef Ref<NiGeomMorpherController> NiGeomMorpherControllerRef;

/*!
 * NiGeomMorpherController - Time controller for geometry morphing.
 */

class NiGeomMorpherController : public NI_GEOM_MORPHER_CONTROLLER_PARENT {
public:
	NIFLIB_API NiGeomMorpherController();
	NIFLIB_API ~NiGeomMorpherController();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//TODO: lots of unknown data in this object
	NIFLIB_API vector< Ref<NiInterpolator> > GetInterpolators() const;
	NIFLIB_API void SetInterpolators( const vector< Ref<NiInterpolator> > & n );

	NIFLIB_API Ref<NiMorphData> GetData() const;
	NIFLIB_API void SetData( const Ref<NiMorphData> & n );
protected:
	NI_GEOM_MORPHER_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
