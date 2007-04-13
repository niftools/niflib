/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISCREENLODDATA_H_
#define _NISCREENLODDATA_H_

#include "NiLODData.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

class NiScreenLODData;
typedef Ref<NiScreenLODData> NiScreenLODDataRef;

/*!
 * NiScreenLODData - Describes levels of detail based on size of object
 * on screen?
 */

class NiScreenLODData : public NI_SCREEN_L_O_D_DATA_PARENT {
public:
	NIFLIB_API NiScreenLODData();
	NIFLIB_API ~NiScreenLODData();
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
	 * Get the center of the bounding sphere?
	 * \return The center of the bounding sphere?
	 */
	NIFLIB_API Vector3 GetBoundCenter() const;

	/*!
	 * Set the center of the bounding sphere?
	 * \param[in] bound_center The new center of the bounding sphere?
	 */
	NIFLIB_API void SetBoundCenter( const Vector3 & bound_center );

	/*!
	 * Get the radius of the bounding sphere?
	 * \return The radius of the bounding sphere?
	 */
	NIFLIB_API float GetBoundRadius() const;

	/*!
	 * Set the radius of the bounding sphere?
	 * \param[in] value The new radius of the bounding sphere?
	 */
	NIFLIB_API void SetBoundRadius( float value );

	/*!
	 * Get the center of the bounding sphere in world space?
	 * \return The center of the bounding sphere in world space?
	 */
	NIFLIB_API Vector3 GetWorldCenter() const;

	/*!
	 * Set the center of the bounding sphere in world space?
	 * \param[in] value The new center of the bounding sphere in world space?
	 */
	NIFLIB_API void SetWorldCenter( const Vector3 & value );

	/*!
	 * Get the radius of the bounding sphere in world space?
	 * \return The radius of the bounding sphere in world space?
	 */
	NIFLIB_API float GetWorldRadius() const;

	/*!
	 * Set the radius of the bounding sphere in world space?
	 * \param[in] value The new radius of the bounding sphere in world space?
	 */
	NIFLIB_API void SetWorldRadius( float value );

	/*!
	 * Get the LOD levels based on proportion of screen size?
	 * \return The LOD levels based on proportion of screen size?
	 */
	NIFLIB_API vector<float > GetProportionLevels() const;

	/*!
	 * Set the LOD levels based on proportion of screen size?
	 * \param[in] value The LOD levels based on proportion of screen size?
	 */
	NIFLIB_API void SetProportionLevels( const vector<float> & value );

protected:
	NI_SCREEN_L_O_D_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
