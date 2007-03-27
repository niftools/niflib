/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NIAVOBJECT_H_
#define _NIAVOBJECT_H_

// Includes
#include "../gen/BoundingBox.h"
#include "NiObjectNET.h"
namespace Niflib {

//#include "../gen/obj_defines.h"

// Forward define of referenced blocks
class NiProperty;
class NiCollisionData;
class NiCollisionObject;
class NiNode;


/*
 * NiAVObject - An audio/video object?  Part of the scene graph and has a position in 3D.
 */

class NiAVObject;
typedef Ref<NiAVObject> NiAVObjectRef;

class NiAVObject : public NI_A_V_OBJECT_PARENT {
public:
	NIFLIB_API NiAVObject();
	NIFLIB_API ~NiAVObject();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:	
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const { return TYPE; };
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	//TODO:  What to do with newer files that have a link for a bounding box?  Wrap this in a function and translate?
	NIFLIB_API void ClearBoundingBox();
	NIFLIB_API BoundingBox GetBoundingBox() const;
	NIFLIB_API void SetBoundingBox( const BoundingBox & n );
	NIFLIB_API bool HasBoundingBox() const;
	
	/*! 
	 * This is a conveniance function that allows you to retrieve the full 4x4 matrix transform of a node.  It accesses the "Rotation," "Translation," and "Scale" attributes and builds a complete 4x4 transformation matrix from them.
	 * \return A 4x4 transformation matrix built from the node's transform attributes.
	 * \sa INode::GetWorldTransform
	 */
	NIFLIB_API Matrix44 GetLocalTransform() const;

	/*! 
	 * This is a conveniance function that allows you to set the rotation, scale, and translation of an AV object with a 4x4 matrix transform.
	 * \n A 4x4 transformation matrix to set the AVObject's transform attributes with.
	 * \sa INode::GetLocalTransform
	 */
	NIFLIB_API void SetLocalTransform( const Matrix44 & n );

	/*! 
	 * This function will return a transform matrix that represents the location of this node in world space.  In other words, it concatenates all parent transforms up to the root of the scene to give the ultimate combined transform from the origin for this node.
	 * \return The 4x4 world transform matrix of this node.
	 * \sa INode::GetLocalTransform
	 */
	NIFLIB_API Matrix44 GetWorldTransform() const;

	/*! Meant to be called by NiNode during the addition of new children.  Should not be called directly. */
	NIFLIB_HIDDEN void SetParent( NiNode * new_parent );

	NIFLIB_API Ref<NiNode> GetParent() const;

	NIFLIB_API void AddProperty( const Ref<NiProperty> & obj );
	NIFLIB_API void RemoveProperty( Ref<NiProperty> obj );
	NIFLIB_API void ClearProperties();
	vector< Ref<NiProperty> > GetProperties() const;
	Ref<NiProperty> GetPropertyByType( const Type & compare_to );

	NIFLIB_API unsigned short GetFlags() const;
	NIFLIB_API void SetFlags( unsigned short n );

	NIFLIB_API Matrix33 GetLocalRotation() const;
	NIFLIB_API void SetLocalRotation( const Matrix33 & n );

	NIFLIB_API Vector3 GetLocalTranslation() const;
	NIFLIB_API void SetLocalTranslation( const Vector3 & n );

	NIFLIB_API float GetLocalScale() const;
	NIFLIB_API void SetLocalScale( float n );

	NIFLIB_API Vector3 GetVelocity() const;
	NIFLIB_API void SetVelocity( const Vector3 & n );

	NIFLIB_API bool GetVisibility() const;
	NIFLIB_API void SetVisibility( bool n );

	/*!
	 * In Oblivion this links the havok objects.
	 */
	NIFLIB_API Ref<NiCollisionObject > GetCollisionObject() const;
	NIFLIB_API void SetCollisionObject( Ref<NiCollisionObject> value );

   /*!
   * Bounding box: refers to NiCollisionData
   */
   NIFLIB_API Ref<NiCollisionData > GetCollisionData() const;
   NIFLIB_API void SetCollisionData( Ref<NiCollisionData> value );

   NIFLIB_API bool GetHidden();
   NIFLIB_API void SetHidden(bool value);

   typedef enum CollisionType
   {
      CT_NONE, CT_TRIANGLES, CT_BOUNDINGBOX, CT_CONTINUE
   } CollisionType;

   NIFLIB_API CollisionType GetCollision();
   NIFLIB_API void SetCollsion(CollisionType value);


protected:
	NiNode * parent;
	NI_A_V_OBJECT_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
