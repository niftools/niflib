/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIKEYFRAMEDATA_H_
#define _NIKEYFRAMEDATA_H_

#include "AKeyedData.h"
// Include structures
#include "../gen/KeyGroup.h"
namespace Niflib {

#include "../gen/obj_defines.h"

class NiKeyframeData;
typedef Ref<NiKeyframeData> NiKeyframeDataRef;

/*!
 * NiKeyframeData - Keyframes for mesh animation.
 */

class NIFLIB_API NiKeyframeData : public NI_KEYFRAME_DATA_PARENT {
public:
	NiKeyframeData();
	~NiKeyframeData();
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

	//--Rotate--//

	/*! Retrieves the type of rotation interpolation being used.
		* \return The rotation key type specifing the type of interpolation being used.
		* \sa IKeyframeData::SetRotateType
		*/
	KeyType GetRotateType() const;

	/*! Sets the type of rotation interpolation being used.  Does not affect existing key data.
	 * \param t The new rotation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetRotateType
	 */
	void SetRotateType( KeyType t );

	/*! Retrieves the quaternion rotation key data.
	 * \return A vector containing Key<Quaternion> data which specify rotation over time.
	 * \sa IKeyframeData::SetQuatRotateKeys, Key
	 */
	vector< Key<Quaternion> > GetQuatRotateKeys() const;

	/*! Sets the quaternion rotation key data.
	 * \param keys A vector containing new Key<Quaternion> data which will replace any existing data.
	 * \sa IKeyframeData::GetQuatRotateKeys, Key
	 */
	void SetQuatRotateKeys( const vector< Key<Quaternion> > & keys );

	/*! Retrieves the type of x-rotation interpolation being used.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEY.
	 * \return The x-rotation key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetXRotateType
	 */
	KeyType GetXRotateType() const;

	/*! Sets the type of x-rotation interpolation being used.  Does not affect existing key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEY.
	 * \param t The new x-rotation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetXRotateType
	 */
	void SetXRotateType( KeyType t );

	/*! Retrieves the x-rotation key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEY.
	 * \return A vector containing Key<float> data which specify rotation over time in the x axis.
	 * \sa IKeyframeData::SetXRotateKeys, Key
	 */
	vector< Key<float> > GetXRotateKeys() const;

	/*! Sets the x-rotation key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEY.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa IKeyframeData::GetXRotateKeys, Key
	 */
	void SetXRotateKeys( const vector< Key<float> > & keys );

	/*! Retrieves the type of y-rotation interpolation being used.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEY.
	 * \return The y-rotation key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetYRotateType
	 */
	KeyType GetYRotateType() const;

	/*! Sets the type of y-rotation interpolation being used.  Does not affect existing key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEY.
	 * \param t The new y-rotation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetYRotateType
	 */
	void SetYRotateType( KeyType t );

	/*! Retrieves the y-rotation key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEY.
	 * \return A vector containing Key<float> data which specify rotation over time in the y axis.
	 * \sa IKeyframeData::SetXRotateKeys, Key
	 */
	vector< Key<float> > GetYRotateKeys() const;

	/*! Sets the y-rotation key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEY.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa IKeyframeData::GetXRotateKeys, Key
	 */
	void SetYRotateKeys( const vector< Key<float> > & keys );

	/*! Retrieves the type of z-rotation interpolation being used.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEZ.
	 * \return The z-rotation key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetZRotateType
	 */
	KeyType GetZRotateType() const;

	/*! Sets the type of z-rotation interpolation being used.  Does not affect existing key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEZ.
	 * \param t The new z-rotation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetZRotateType
	 */
	void SetZRotateType( KeyType t );

	/*! Retrieves the z-rotation key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEZ.
	 * \return A vector containing Key<float> data which specify rotation over time in the z axis.
	 * \sa IKeyframeData::SetXRotateKeys, Key
	 */
	vector< Key<float> > GetZRotateKeys() const;

	/*! Sets the z-rotation key data.  XYZ data is only used if rotation type is set to XYZ_ROTATION_KEZ.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa IKeyframeData::GetXRotateKeys, Key
	 */
	void SetZRotateKeys( const vector< Key<float> > & keys );

	//--Translate--//

	/*! Retrieves the type of translation interpolation being used.
	 * \return The translation key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetTranslateType
	 */
	KeyType GetTranslateType() const;

	/*! Sets the type of translation interpolation being used.  Does not affect existing key data.
	 * \param t The new translation key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetTranslateType
	 */
	void SetTranslateType( KeyType t );

	/*! Retrieves the translation key data.
	 * \return A vector containing Key<Vector3> data which specify translation over time.
	 * \sa IKeyframeData::SetTranslateKeys, Key
	 */
	vector< Key<Vector3> > GetTranslateKeys() const;

	/*! Sets the translation key data.
	 * \param keys A vector containing new Key<Vector3> data which will replace any existing data.
	 * \sa IKeyframeData::GetTranslateKeys, Key
	 */
	void SetTranslateKeys( vector< Key<Vector3> > const & keys );

	//--Scale--//

	/*! Retrieves the type of scale interpolation being used.
	 * \return The scale key type specifing the type of interpolation being used.
	 * \sa IKeyframeData::SetTranslateType
	 */
	KeyType GetScaleType() const;

	/*! Sets the type of scale interpolation being used.  Does not affect existing key data.
	 * \param t The new scale key type specifing the type of interpolation to be used.
	 * \sa IKeyframeData::GetScaleType
	 */
	void SetScaleType( KeyType t );

	/*! Retrieves the scale key data.
	 * \return A vector containing Key<float> data which specify scale over time.
	 * \sa IKeyframeData::SetScaleKeys, Key
	 */
	vector< Key<float> > GetScaleKeys() const;

	/*! Sets the scale key data.
	 * \param keys A vector containing new Key<float> data which will replace any existing data.
	 * \sa IKeyframeData::GetScaleKeys, Key
	 */
	void SetScaleKeys( vector< Key<float> > const & keys );

protected:
	void UpdateRotationKeyCount();
	NI_KEYFRAME_DATA_MEMBERS
	STANDARD_INTERNAL_METHODS
};

}
#endif
