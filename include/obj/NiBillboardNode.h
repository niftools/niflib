/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

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
	NIFLIB_API static const Type TYPE;
	NIFLIB_API static NiObject * Create();
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retreives the current bilboard mode of this bilboard node.  This determines how it will cause the node to face the camera.
	 * \return The current bilboard mode.
	 */
	NIFLIB_API BillboardMode GetBillboardMode() const;

	/*!
	 * Sets the bilboard mode of this bilboard node.  This determines how it will cause the node to face the camera.
	 * \param[in] value The new bilboard mode.
	 */
	NIFLIB_API void SetBillboardMode( BillboardMode value );

protected:
	NI_BILLBOARD_NODE_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
