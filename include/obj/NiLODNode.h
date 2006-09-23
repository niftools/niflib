/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NILODNODE_H_
#define _NILODNODE_H_

#include "NiNode.h"

// Include structures
#include "../gen/LODRange.h"
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class NiLODData;

#include "../gen/obj_defines.h"

class NiLODNode;
typedef Ref<NiLODNode> NiLODNodeRef;

/*!
 * NiLODNode - Level of detail selector. Links to different levels of
 * detail of the same model, used to switch a geometry at a specified
 * distance.
 */

class NIFLIB_API NiLODNode : public NI_L_O_D_NODE_PARENT {
public:
	NiLODNode();
	~NiLODNode();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Get the point to calculate distance from for switching?
	 */
	Vector3 GetLODCenter() const;

	/*!
	 * Set the point to calculate distance from for switching?
	 */
	void SetLODCenter( const Vector3 & value );

	/*!
	 * Get the ranges of distance that each level of detail applies in.
	 */
	vector<LODRange > GetLODLevels() const;

	/*!
	 * Set the ranges of distance that each level of detail applies in.
	 */
	void SetLODLevels( const vector<LODRange >& value );

	/*!
	 * Get the data object that refers to LOD level information
	 */
	Ref<NiLODData > GetLODLevelData() const;
	
	/*!
	 * Set the data object that refers to LOD level information
	 */
	void SetLODLevelData( Ref<NiLODData > value );

protected:
	NI_L_O_D_NODE_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
