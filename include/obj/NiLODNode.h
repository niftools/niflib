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

//#include "../gen/obj_defines.h"

class NiLODNode;
typedef Ref<NiLODNode> NiLODNodeRef;

/*!
 * NiLODNode - Level of detail selector. Links to different levels of
 * detail of the same model, used to switch a geometry at a specified
 * distance.
 */

class NiLODNode : public NI_L_O_D_NODE_PARENT {
public:
	NIFLIB_API NiLODNode();
	NIFLIB_API ~NiLODNode();
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

	/*!
	 * Get the point to calculate distance from for switching?
	 */
	NIFLIB_API Vector3 GetLODCenter() const;

	/*!
	 * Set the point to calculate distance from for switching?
	 */
	NIFLIB_API void SetLODCenter( const Vector3 & value );

	/*!
	 * Get the ranges of distance that each level of detail applies in.
	 */
	NIFLIB_API vector<LODRange > GetLODLevels() const;

	/*!
	 * Set the ranges of distance that each level of detail applies in.
	 */
	NIFLIB_API void SetLODLevels( const vector<LODRange >& value );

	/*!
	 * Get the data object that refers to LOD level information
	 */
	NIFLIB_API Ref<NiLODData > GetLODLevelData() const;
	
	/*!
	 * Set the data object that refers to LOD level information
	 */
	NIFLIB_API void SetLODLevelData( Ref<NiLODData > value );

protected:
	NI_L_O_D_NODE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
