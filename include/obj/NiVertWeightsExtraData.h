/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIVERTWEIGHTSEXTRADATA_H_
#define _NIVERTWEIGHTSEXTRADATA_H_

#include "NiExtraData.h"
namespace Niflib {


//#include "../gen/obj_defines.h"

class NiVertWeightsExtraData;
typedef Ref<NiVertWeightsExtraData> NiVertWeightsExtraDataRef;

/*!
 * NiVertWeightsExtraData - Not used in skinning. Unsure of use - perhaps
 * for morphing animation or gravity.
 */

class NiVertWeightsExtraData : public NI_VERT_WEIGHTS_EXTRA_DATA_PARENT {
public:
	NIFLIB_API NiVertWeightsExtraData();
	NIFLIB_API ~NiVertWeightsExtraData();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrieves the floating point values stored in this object.
	 * \return The floating point values stored in this object.
	 */
	NIFLIB_API vector<float> GetData() const;

	/*!
	 * Sets the floating point values stored in this object.
	 * \param[in] n The new floating point values to store in this object.
	 */
	NIFLIB_API void SetData( const vector<float> & n );

protected:
	NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
