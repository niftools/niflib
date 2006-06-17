/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIGEOMMORPHERCONTROLLER_H_
#define _NIGEOMMORPHERCONTROLLER_H_

#include "NiTimeController.h"

// Forward define of referenced blocks
#include "../Ref.h"
class NiMorphData;
class NiInterpolator;

#include "../gen/obj_defines.h"

class NiGeomMorpherController;
typedef Ref<NiGeomMorpherController> NiGeomMorpherControllerRef;

/*!
 * NiGeomMorpherController - Time controller for geometry morphing.
 */

class NIFLIB_API NiGeomMorpherController : public NI_GEOM_MORPHER_CONTROLLER_PARENT {
public:
	NiGeomMorpherController();
	~NiGeomMorpherController();
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

	//TODO: lots of unknown data in this object
	vector< Ref<NiInterpolator> > GetInterpolators() const;
	void SetInterpolators( const vector< Ref<NiInterpolator> > & n );

	Ref<NiMorphData> GetData() const;
	void SetData( const Ref<NiMorphData> & n );
protected:
	NI_GEOM_MORPHER_CONTROLLER_MEMBERS
};

#endif
