/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _ABONELODCONTROLLER_H_
#define _ABONELODCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../gen/NodeGroup.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class ABoneLODController;
typedef Ref<ABoneLODController> ABoneLODControllerRef;

/*!
 * ABoneLODController - Level of detail controller for bones?
 */

class NIFLIB_API ABoneLODController : public A_BONE_L_O_D_CONTROLLER_PARENT {
public:
	ABoneLODController();
	~ABoneLODController();
	//Run-Time Type Information
	static const Type & TypeConst() { return TYPE; }
private:
	static const Type TYPE;
public:
	virtual void Read( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual void Write( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	virtual string asString( bool verbose = false ) const;
	virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	virtual list<NiObjectRef> GetRefs() const;
	virtual const Type & GetType() const;

	/*!
	 * Returns the number of node groups (each group a sequence of bones).
	 */
   int GetNodeGroupCount() const;

   /*!
    * Returns a specific node group (each group a sequence of bones).
    */
	vector<Ref<NiNode> > GetNodeGroup( int index ) const;

   /*!
    * Add a single node to the specified group. The Group list will expand if necessary.
    */
   void AddNodeToGroup( int index, Ref<NiNode> node );

   /*!
    * Remove a single node from the specified group. 
    */
   void RemoveNodeFromGroup( int index, Ref<NiNode> node );

   /*!
    * Assign an entire node group. 
    */
	void SetNodeGroup( int index, const vector<Ref<NiNode> >& group );


   /*!
   * Remove an entire node group. 
   */
   void RemoveNodeGroup( int index );

   /*!
   * Clear all node groups.
   */
   void ClearNodeGroups();

protected:
	A_BONE_L_O_D_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,uint> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
