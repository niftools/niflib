/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISCREENLODDATA_H_
#define _NISCREENLODDATA_H_

#include "NiLODData.h"
namespace Niflib {

#include "../gen/obj_defines.h"

class NiScreenLODData;
typedef Ref<NiScreenLODData> NiScreenLODDataRef;

/*!
 * NiScreenLODData - Describes levels of detail based on size of object
 * on screen?
 */

class NIFLIB_API NiScreenLODData : public NI_SCREEN_L_O_D_DATA_PARENT {
public:
	NiScreenLODData();
	~NiScreenLODData();
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
	 * Get the center of the bounding sphere?
	 */
	Vector3 GetBoundCenter() const;

	/*!
	 * Set the center of the bounding sphere?
	 */
	void SetBoundCenter( const Vector3 & bound_center );

	/*!
	 * Get the radius of the bounding sphere?
	 */
	float GetBoundRadius() const;

	/*!
	 * Set the radius of the bounding sphere?
	 */
	void SetBoundRadius( float value );

	/*!
	 * Get the center of the bounding sphere in world space?
	 */
	Vector3 GetWorldCenter() const;

	/*!
	 * Set the center of the bounding sphere in world space?
	 */
	void SetWorldCenter( const Vector3 & value );

	/*!
	 * Get the radius of the bounding sphere in world space?
	 */
	float GetWorldRadius() const;

	/*!
	 * Set the radius of the bounding sphere in world space?
	 */
	void SetWorldRadius( float value );

	/*!
	 * Get the LOD levels based on proportion of screen size?
	 */
	vector<float > GetProportionLevels() const;

	/*!
	 * Set the LOD levels based on proportion of screen size?
	 */
	void SetProportionLevels( const vector<float >& value );

protected:
	NI_SCREEN_L_O_D_DATA_MEMBERS
private:
	void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned,NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
