/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIBSPLINEBASISDATA_H_
#define _NIBSPLINEBASISDATA_H_

#include "NiObject.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiBSplineBasisData;
typedef Ref<NiBSplineBasisData> NiBSplineBasisDataRef;

/*!
 * NiBSplineBasisData - Unknown.
 */

class NiBSplineBasisData : public NI_B_SPLINE_BASIS_DATA_PARENT {
public:
	NIFLIB_API NiBSplineBasisData();
	NIFLIB_API ~NiBSplineBasisData();
	//Run-Time Type Information
	NIFLIB_API static const Type TYPE;
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrives the current number of spline control points.  This is usually the number of frames for animation.
	 * \return The number of spline control points.
	 */
	NIFLIB_API unsigned int GetNumControlPt() const;

	/*!
	 * Sets the number of spline control points.  This is usually the number of frames for animation.
	 * \param[in] value The new number of spline control points.
	 */
	NIFLIB_API void SetNumControlPt( unsigned int value );

protected:
	NI_B_SPLINE_BASIS_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
