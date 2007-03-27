/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBILLBOARDNODE_H_
#define _NIBILLBOARDNODE_H_

#include "NiNode.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiBillboardNode;
typedef Ref<NiBillboardNode> NiBillboardNodeRef;

/*!
 * NiBillboardNode - These nodes will always be rotated to face the
 * camera creating a billboard effect for any attached objects.
 */

class NiBillboardNode : public NI_BILLBOARD_NODE_PARENT {
public:
	NIFLIB_API NiBillboardNode();
	NIFLIB_API ~NiBillboardNode();
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
	 * 0: ALWAYS_FACE_CAMERA 1: ROTATE_ABOUT_UP 2: RIGID_FACE_CAMERA 3:
	 * ALWAYS_FACE_CENTER 4: RIGID_FACE_CENTER
	 */
	NIFLIB_API BillboardMode GetBillboardMode() const;
	NIFLIB_API void SetBillboardMode( BillboardMode value );

protected:
	NI_BILLBOARD_NODE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
