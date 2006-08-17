/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _OBJ_DEFINES_H_
#define _OBJ_DEFINES_H_

#define MAXARRAYDUMP 20

#define STANDARD_INTERNAL_METHODS \
private:\
  void InternalRead( istream& in, list<uint> & link_stack, unsigned int version, unsigned int user_version );\
  void InternalWrite( ostream& out, map<NiObjectRef,uint> link_map, unsigned int version, unsigned int user_version ) const;\
  string InternalAsString( bool verbose ) const;\
  void InternalFixLinks( const vector<NiObjectRef> & objects, list<uint> & link_stack, unsigned int version, unsigned int user_version );\
  list<NiObjectRef> InternalGetRefs() const;
#define NI_OBJECT_MEMBERS \

#define NI_OBJECT_INCLUDE ".h" \

#define NI_OBJECT_PARENT \

#define NI_OBJECT_CONSTRUCT \

#define NI_OBJECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_OBJECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_OBJECT_STRING \
return InternalAsString( verbose ); \

#define NI_OBJECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_OBJECT_GETREFS \
return InternalGetRefs(); \

#define A_KEYED_DATA_MEMBERS \

#define A_KEYED_DATA_INCLUDE "NiObject.h" \

#define A_KEYED_DATA_PARENT NiObject \

#define A_KEYED_DATA_CONSTRUCT \

#define A_KEYED_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define A_KEYED_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define A_KEYED_DATA_STRING \
return InternalAsString( verbose ); \

#define A_KEYED_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define A_KEYED_DATA_GETREFS \
return InternalGetRefs(); \

#define A_PARTICLE_MODIFIER_MEMBERS \
Ref<AParticleModifier > nextModifier; \
NiParticleSystemController * controller; \

#define A_PARTICLE_MODIFIER_INCLUDE "NiObject.h" \

#define A_PARTICLE_MODIFIER_PARENT NiObject \

#define A_PARTICLE_MODIFIER_CONSTRUCT \
 : nextModifier(NULL), controller(NULL) \

#define A_PARTICLE_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define A_PARTICLE_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define A_PARTICLE_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define A_PARTICLE_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define A_PARTICLE_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define BHK_REF_OBJECT_MEMBERS \

#define BHK_REF_OBJECT_INCLUDE "NiObject.h" \

#define BHK_REF_OBJECT_PARENT NiObject \

#define BHK_REF_OBJECT_CONSTRUCT \

#define BHK_REF_OBJECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_REF_OBJECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_REF_OBJECT_STRING \
return InternalAsString( verbose ); \

#define BHK_REF_OBJECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_REF_OBJECT_GETREFS \
return InternalGetRefs(); \

#define BHK_SERIALIZABLE_MEMBERS \

#define BHK_SERIALIZABLE_INCLUDE "bhkRefObject.h" \

#define BHK_SERIALIZABLE_PARENT bhkRefObject \

#define BHK_SERIALIZABLE_CONSTRUCT \

#define BHK_SERIALIZABLE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_SERIALIZABLE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_SERIALIZABLE_STRING \
return InternalAsString( verbose ); \

#define BHK_SERIALIZABLE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_SERIALIZABLE_GETREFS \
return InternalGetRefs(); \

#define ABHK_CONSTRAINT_MEMBERS \
mutable uint numBodies; \
vector<bhkShape * > bodies; \
uint priority; \

#define ABHK_CONSTRAINT_INCLUDE "bhkSerializable.h" \

#define ABHK_CONSTRAINT_PARENT bhkSerializable \

#define ABHK_CONSTRAINT_CONSTRUCT \
 : numBodies((uint)0), priority((uint)1) \

#define ABHK_CONSTRAINT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define ABHK_CONSTRAINT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define ABHK_CONSTRAINT_STRING \
return InternalAsString( verbose ); \

#define ABHK_CONSTRAINT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define ABHK_CONSTRAINT_GETREFS \
return InternalGetRefs(); \

#define ABHK_RAGDOLL_CONSTRAINT_MEMBERS \
Float4 pivotA; \
Float4 planeA; \
Float4 twistA; \
Float4 pivotB; \
Float4 planeB; \
Float4 twistB; \
float coneMinAngle; \
float planeMinAngle; \
float planeMaxAngle; \
float twistMinAngle; \
float twistMaxAngle; \
float maxFriction; \

#define ABHK_RAGDOLL_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define ABHK_RAGDOLL_CONSTRAINT_PARENT AbhkConstraint \

#define ABHK_RAGDOLL_CONSTRAINT_CONSTRUCT \
 : coneMinAngle(0.0f), planeMinAngle(0.0f), planeMaxAngle(0.0f), twistMinAngle(0.0f), twistMaxAngle(0.0f), maxFriction(0.0f) \

#define ABHK_RAGDOLL_CONSTRAINT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define ABHK_RAGDOLL_CONSTRAINT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define ABHK_RAGDOLL_CONSTRAINT_STRING \
return InternalAsString( verbose ); \

#define ABHK_RAGDOLL_CONSTRAINT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define ABHK_RAGDOLL_CONSTRAINT_GETREFS \
return InternalGetRefs(); \

#define BHK_SHAPE_MEMBERS \

#define BHK_SHAPE_INCLUDE "bhkSerializable.h" \

#define BHK_SHAPE_PARENT bhkSerializable \

#define BHK_SHAPE_CONSTRUCT \

#define BHK_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_SHAPE_GETREFS \
return InternalGetRefs(); \

#define ABHK_SHAPE_COLLECTION_MEMBERS \

#define ABHK_SHAPE_COLLECTION_INCLUDE "bhkShape.h" \

#define ABHK_SHAPE_COLLECTION_PARENT bhkShape \

#define ABHK_SHAPE_COLLECTION_CONSTRUCT \

#define ABHK_SHAPE_COLLECTION_READ \
InternalRead( in, link_stack, version, user_version ); \

#define ABHK_SHAPE_COLLECTION_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define ABHK_SHAPE_COLLECTION_STRING \
return InternalAsString( verbose ); \

#define ABHK_SHAPE_COLLECTION_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define ABHK_SHAPE_COLLECTION_GETREFS \
return InternalGetRefs(); \

#define BHK_SPHERE_REP_SHAPE_MEMBERS \
uint material; \

#define BHK_SPHERE_REP_SHAPE_INCLUDE "bhkShape.h" \

#define BHK_SPHERE_REP_SHAPE_PARENT bhkShape \

#define BHK_SPHERE_REP_SHAPE_CONSTRUCT \
 : material((uint)0) \

#define BHK_SPHERE_REP_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_SPHERE_REP_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_SPHERE_REP_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_SPHERE_REP_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_SPHERE_REP_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_CONVEX_SHAPE_MEMBERS \

#define BHK_CONVEX_SHAPE_INCLUDE "bhkSphereRepShape.h" \

#define BHK_CONVEX_SHAPE_PARENT bhkSphereRepShape \

#define BHK_CONVEX_SHAPE_CONSTRUCT \

#define BHK_CONVEX_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_CONVEX_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_CONVEX_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_CONVEX_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_CONVEX_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_WORLD_OBJECT_MEMBERS \

#define BHK_WORLD_OBJECT_INCLUDE "bhkShape.h" \

#define BHK_WORLD_OBJECT_PARENT bhkShape \

#define BHK_WORLD_OBJECT_CONSTRUCT \

#define BHK_WORLD_OBJECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_WORLD_OBJECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_WORLD_OBJECT_STRING \
return InternalAsString( verbose ); \

#define BHK_WORLD_OBJECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_WORLD_OBJECT_GETREFS \
return InternalGetRefs(); \

#define BHK_ENTITY_MEMBERS \
Ref<bhkShape > shape; \
uint layer; \

#define BHK_ENTITY_INCLUDE "bhkWorldObject.h" \

#define BHK_ENTITY_PARENT bhkWorldObject \

#define BHK_ENTITY_CONSTRUCT \
 : shape(NULL), layer((uint)0) \

#define BHK_ENTITY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_ENTITY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_ENTITY_STRING \
return InternalAsString( verbose ); \

#define BHK_ENTITY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_ENTITY_GETREFS \
return InternalGetRefs(); \

#define NI_COLLISION_OBJECT_MEMBERS \
NiAVObject * parent; \
ushort unknownShort; \
Ref<NiObject > body; \

#define NI_COLLISION_OBJECT_INCLUDE "NiObject.h" \

#define NI_COLLISION_OBJECT_PARENT NiObject \

#define NI_COLLISION_OBJECT_CONSTRUCT \
 : parent(NULL), unknownShort((ushort)0), body(NULL) \

#define NI_COLLISION_OBJECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_COLLISION_OBJECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_COLLISION_OBJECT_STRING \
return InternalAsString( verbose ); \

#define NI_COLLISION_OBJECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_COLLISION_OBJECT_GETREFS \
return InternalGetRefs(); \

#define NI_EXTRA_DATA_MEMBERS \
string name; \
Ref<NiExtraData > nextExtraData; \

#define NI_EXTRA_DATA_INCLUDE "NiObject.h" \

#define NI_EXTRA_DATA_PARENT NiObject \

#define NI_EXTRA_DATA_CONSTRUCT \
 : nextExtraData(NULL) \

#define NI_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_INTERPOLATOR_MEMBERS \

#define NI_INTERPOLATOR_INCLUDE "NiObject.h" \

#define NI_INTERPOLATOR_PARENT NiObject \

#define NI_INTERPOLATOR_CONSTRUCT \

#define NI_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_BLEND_INTERPOLATOR_MEMBERS \
ushort unknownShort; \
uint unknownInt; \

#define NI_BLEND_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_BLEND_INTERPOLATOR_PARENT NiInterpolator \

#define NI_BLEND_INTERPOLATOR_CONSTRUCT \
 : unknownShort((ushort)0), unknownInt((uint)0) \

#define NI_BLEND_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BLEND_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BLEND_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_BLEND_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_B_SPLINE_INTERPOLATOR_MEMBERS \
float startTime; \
float stopTime; \
Ref<NiBSplineData > splineData; \
Ref<NiBSplineBasisData > basisData; \

#define NI_B_SPLINE_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_B_SPLINE_INTERPOLATOR_PARENT NiInterpolator \

#define NI_B_SPLINE_INTERPOLATOR_CONSTRUCT \
 : startTime(0.0f), stopTime(0.0f), splineData(NULL), basisData(NULL) \

#define NI_B_SPLINE_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_SPLINE_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_SPLINE_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_B_SPLINE_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_OBJECT_N_E_T_MEMBERS \
string name; \
Ref<NiExtraData > extraData; \
mutable uint numExtraDataList; \
vector<Ref<NiExtraData > > extraDataList; \
Ref<NiTimeController > controller; \

#define NI_OBJECT_N_E_T_INCLUDE "NiObject.h" \

#define NI_OBJECT_N_E_T_PARENT NiObject \

#define NI_OBJECT_N_E_T_CONSTRUCT \
 : extraData(NULL), numExtraDataList((uint)0), controller(NULL) \

#define NI_OBJECT_N_E_T_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_OBJECT_N_E_T_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_OBJECT_N_E_T_STRING \
return InternalAsString( verbose ); \

#define NI_OBJECT_N_E_T_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_OBJECT_N_E_T_GETREFS \
return InternalGetRefs(); \

#define NI_A_V_OBJECT_MEMBERS \
ushort flags; \
Vector3 translation; \
Matrix33 rotation; \
float scale; \
Vector3 velocity; \
mutable uint numProperties; \
vector<Ref<NiProperty > > properties; \
bool hasBoundingBox; \
BoundingBox boundingBox; \
Ref<NiCollisionData > collisionData; \
Ref<NiCollisionObject > collisionObject; \

#define NI_A_V_OBJECT_INCLUDE "NiObjectNET.h" \

#define NI_A_V_OBJECT_PARENT NiObjectNET \

#define NI_A_V_OBJECT_CONSTRUCT \
 : flags((ushort)0), scale(1.0f), numProperties((uint)0), hasBoundingBox(false), collisionData(NULL), collisionObject(NULL) \

#define NI_A_V_OBJECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_A_V_OBJECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_A_V_OBJECT_STRING \
return InternalAsString( verbose ); \

#define NI_A_V_OBJECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_A_V_OBJECT_GETREFS \
return InternalGetRefs(); \

#define NI_DYNAMIC_EFFECT_MEMBERS \
bool hasAffectedNodeList_; \
uint affectedNodeList_; \
bool switchState; \
mutable uint numAffectedNodes; \
vector<Ref<NiAVObject > > affectedNodes; \

#define NI_DYNAMIC_EFFECT_INCLUDE "NiAVObject.h" \

#define NI_DYNAMIC_EFFECT_PARENT NiAVObject \

#define NI_DYNAMIC_EFFECT_CONSTRUCT \
 : hasAffectedNodeList_(false), affectedNodeList_((uint)0), switchState(false), numAffectedNodes((uint)0) \

#define NI_DYNAMIC_EFFECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_DYNAMIC_EFFECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_DYNAMIC_EFFECT_STRING \
return InternalAsString( verbose ); \

#define NI_DYNAMIC_EFFECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_DYNAMIC_EFFECT_GETREFS \
return InternalGetRefs(); \

#define NI_LIGHT_MEMBERS \
float dimmer; \
Color3 ambientColor; \
Color3 diffuseColor; \
Color3 specularColor; \

#define NI_LIGHT_INCLUDE "NiDynamicEffect.h" \

#define NI_LIGHT_PARENT NiDynamicEffect \

#define NI_LIGHT_CONSTRUCT \
 : dimmer(0.0f) \

#define NI_LIGHT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_LIGHT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_LIGHT_STRING \
return InternalAsString( verbose ); \

#define NI_LIGHT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_LIGHT_GETREFS \
return InternalGetRefs(); \

#define NI_PROPERTY_MEMBERS \

#define NI_PROPERTY_INCLUDE "NiObjectNET.h" \

#define NI_PROPERTY_PARENT NiObjectNET \

#define NI_PROPERTY_CONSTRUCT \

#define NI_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_MODIFIER_MEMBERS \
string name; \
uint order; \
NiParticleSystem * target; \
bool active; \

#define NI_P_SYS_MODIFIER_INCLUDE "NiObject.h" \

#define NI_P_SYS_MODIFIER_PARENT NiObject \

#define NI_P_SYS_MODIFIER_CONSTRUCT \
 : order((uint)0), target(NULL), active(false) \

#define NI_P_SYS_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_EMITTER_MEMBERS \
float speed; \
float speedVariation; \
float declination; \
float declinationVariation; \
float planarAngle; \
float planarAngleVariation; \
Color4 initialColor; \
float initialRadius; \
float radiusVariation; \
float lifeSpan; \
float lifeSpanVariation; \

#define NI_P_SYS_EMITTER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_EMITTER_PARENT NiPSysModifier \

#define NI_P_SYS_EMITTER_CONSTRUCT \
 : speed(0.0f), speedVariation(0.0f), declination(0.0f), declinationVariation(0.0f), planarAngle(0.0f), planarAngleVariation(0.0f), initialRadius(0.0f), radiusVariation(0.0f), lifeSpan(0.0f), lifeSpanVariation(0.0f) \

#define NI_P_SYS_EMITTER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_EMITTER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_VOLUME_EMITTER_MEMBERS \
NiNode * emitterObject; \

#define NI_P_SYS_VOLUME_EMITTER_INCLUDE "NiPSysEmitter.h" \

#define NI_P_SYS_VOLUME_EMITTER_PARENT NiPSysEmitter \

#define NI_P_SYS_VOLUME_EMITTER_CONSTRUCT \
 : emitterObject(NULL) \

#define NI_P_SYS_VOLUME_EMITTER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_VOLUME_EMITTER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_VOLUME_EMITTER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_VOLUME_EMITTER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_VOLUME_EMITTER_GETREFS \
return InternalGetRefs(); \

#define NI_TIME_CONTROLLER_MEMBERS \
Ref<NiTimeController > nextController; \
ushort flags; \
float frequency; \
float phase; \
float startTime; \
float stopTime; \
NiObjectNET * target; \

#define NI_TIME_CONTROLLER_INCLUDE "NiObject.h" \

#define NI_TIME_CONTROLLER_PARENT NiObject \

#define NI_TIME_CONTROLLER_CONSTRUCT \
 : nextController(NULL), flags((ushort)0), frequency(0.0f), phase(0.0f), startTime(0.0f), stopTime(0.0f), target(NULL) \

#define NI_TIME_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TIME_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TIME_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_TIME_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TIME_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define A_BONE_L_O_D_CONTROLLER_MEMBERS \
uint unknownInt1; \
mutable uint numNodeGroups; \
uint unknownInt2; \
vector<NodeGroup > nodeGroups; \

#define A_BONE_L_O_D_CONTROLLER_INCLUDE "NiTimeController.h" \

#define A_BONE_L_O_D_CONTROLLER_PARENT NiTimeController \

#define A_BONE_L_O_D_CONTROLLER_CONSTRUCT \
 : unknownInt1((uint)0), numNodeGroups((uint)0), unknownInt2((uint)0) \

#define A_BONE_L_O_D_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define A_BONE_L_O_D_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define A_BONE_L_O_D_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define A_BONE_L_O_D_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define A_BONE_L_O_D_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_MEMBERS \
Ref<NiInterpolator > interpolator; \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_PARENT NiTimeController \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_CONSTRUCT \
 : interpolator(NULL) \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define A_P_SYS_CTLR_MEMBERS \
string modifierName; \

#define A_P_SYS_CTLR_INCLUDE "NiSingleInterpolatorController.h" \

#define A_P_SYS_CTLR_PARENT NiSingleInterpolatorController \

#define A_P_SYS_CTLR_CONSTRUCT \

#define A_P_SYS_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define A_P_SYS_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define A_P_SYS_CTLR_STRING \
return InternalAsString( verbose ); \

#define A_P_SYS_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define A_P_SYS_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_TRI_BASED_GEOM_MEMBERS \
Ref<NiTriBasedGeomData > data; \
Ref<NiSkinInstance > skinInstance; \
bool hasShader; \
string shaderName; \
Ref<NiObject > unknownLink; \

#define NI_TRI_BASED_GEOM_INCLUDE "NiAVObject.h" \

#define NI_TRI_BASED_GEOM_PARENT NiAVObject \

#define NI_TRI_BASED_GEOM_CONSTRUCT \
 : data(NULL), skinInstance(NULL), hasShader(false), unknownLink(NULL) \

#define NI_TRI_BASED_GEOM_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRI_BASED_GEOM_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRI_BASED_GEOM_STRING \
return InternalAsString( verbose ); \

#define NI_TRI_BASED_GEOM_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_BASED_GEOM_GETREFS \
return InternalGetRefs(); \

#define NI_TRI_BASED_GEOM_DATA_MEMBERS \
string name; \
mutable ushort numVertices; \
ushort unknownShort1; \
bool hasVertices; \
vector<Vector3 > vertices; \
mutable byte numUvSets2; \
byte unknownByte; \
bool hasNormals; \
vector<Vector3 > normals; \
vector<Vector3 > unknownVectors1; \
vector<Vector3 > unknownVectors2; \
Vector3 center; \
float radius; \
bool hasVertexColors; \
vector<Color4 > vertexColors; \
mutable ushort numUvSets; \
bool hasUv; \
vector<vector<TexCoord > > uvSets; \
ushort unknownShort2; \
Ref<NiObject > unknownLink; \

#define NI_TRI_BASED_GEOM_DATA_INCLUDE "NiObject.h" \

#define NI_TRI_BASED_GEOM_DATA_PARENT NiObject \

#define NI_TRI_BASED_GEOM_DATA_CONSTRUCT \
 : numVertices((ushort)0), unknownShort1((ushort)0), hasVertices(false), numUvSets2((byte)0), unknownByte((byte)0), hasNormals(false), radius(0.0f), hasVertexColors(false), numUvSets((ushort)0), hasUv(false), unknownShort2((ushort)0), unknownLink(NULL) \

#define NI_TRI_BASED_GEOM_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRI_BASED_GEOM_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRI_BASED_GEOM_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_TRI_BASED_GEOM_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_BASED_GEOM_DATA_GETREFS \
return InternalGetRefs(); \

#define A_P_SYS_DATA_MEMBERS \
bool hasUnknownFloats1; \
vector<float > unknownFloats1; \
ushort unknownShort3; \
bool hasUnknownFloats2; \
vector<float > unknownFloats2; \
byte unknownByte1; \

#define A_P_SYS_DATA_INCLUDE "NiTriBasedGeomData.h" \

#define A_P_SYS_DATA_PARENT NiTriBasedGeomData \

#define A_P_SYS_DATA_CONSTRUCT \
 : hasUnknownFloats1(false), unknownShort3((ushort)0), hasUnknownFloats2(false), unknownByte1((byte)0) \

#define A_P_SYS_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define A_P_SYS_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define A_P_SYS_DATA_STRING \
return InternalAsString( verbose ); \

#define A_P_SYS_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define A_P_SYS_DATA_GETREFS \
return InternalGetRefs(); \

#define BHK_BLEND_COLLISION_OBJECT_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \

#define BHK_BLEND_COLLISION_OBJECT_INCLUDE "NiCollisionObject.h" \

#define BHK_BLEND_COLLISION_OBJECT_PARENT NiCollisionObject \

#define BHK_BLEND_COLLISION_OBJECT_CONSTRUCT \
 : unknownFloat1(0.0f), unknownFloat2(0.0f) \

#define BHK_BLEND_COLLISION_OBJECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_BLEND_COLLISION_OBJECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_BLEND_COLLISION_OBJECT_STRING \
return InternalAsString( verbose ); \

#define BHK_BLEND_COLLISION_OBJECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_BLEND_COLLISION_OBJECT_GETREFS \
return InternalGetRefs(); \

#define BHK_BLEND_CONTROLLER_MEMBERS \
uint unknownInt; \

#define BHK_BLEND_CONTROLLER_INCLUDE "NiTimeController.h" \

#define BHK_BLEND_CONTROLLER_PARENT NiTimeController \

#define BHK_BLEND_CONTROLLER_CONSTRUCT \
 : unknownInt((uint)0) \

#define BHK_BLEND_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_BLEND_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_BLEND_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define BHK_BLEND_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_BLEND_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define BHK_BOX_SHAPE_MEMBERS \
float unknownFloat1; \
ushort unknownShort1; \
ushort unknownShort2; \
ushort unknownShort3; \
ushort unknownShort4; \
Vector3 dimensions; \
float unknownFloat2; \

#define BHK_BOX_SHAPE_INCLUDE "bhkConvexShape.h" \

#define BHK_BOX_SHAPE_PARENT bhkConvexShape \

#define BHK_BOX_SHAPE_CONSTRUCT \
 : unknownFloat1(0.0f), unknownShort1((ushort)0), unknownShort2((ushort)0), unknownShort3((ushort)0), unknownShort4((ushort)0), unknownFloat2(0.0f) \

#define BHK_BOX_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_BOX_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_BOX_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_BOX_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_BOX_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_CAPSULE_SHAPE_MEMBERS \
float radius; \
ushort unknownShort1; \
ushort unknownShort2; \
ushort unknownShort3; \
ushort unknownShort4; \
Vector3 firstPoint; \
float radius1; \
Vector3 secondPoint; \
float radius2; \

#define BHK_CAPSULE_SHAPE_INCLUDE "bhkConvexShape.h" \

#define BHK_CAPSULE_SHAPE_PARENT bhkConvexShape \

#define BHK_CAPSULE_SHAPE_CONSTRUCT \
 : radius(0.0f), unknownShort1((ushort)0), unknownShort2((ushort)0), unknownShort3((ushort)0), unknownShort4((ushort)0), radius1(0.0f), radius2(0.0f) \

#define BHK_CAPSULE_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_CAPSULE_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_CAPSULE_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_CAPSULE_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_CAPSULE_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_COLLISION_OBJECT_MEMBERS \

#define BHK_COLLISION_OBJECT_INCLUDE "NiCollisionObject.h" \

#define BHK_COLLISION_OBJECT_PARENT NiCollisionObject \

#define BHK_COLLISION_OBJECT_CONSTRUCT \

#define BHK_COLLISION_OBJECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_COLLISION_OBJECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_COLLISION_OBJECT_STRING \
return InternalAsString( verbose ); \

#define BHK_COLLISION_OBJECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_COLLISION_OBJECT_GETREFS \
return InternalGetRefs(); \

#define BHK_CONVEX_VERTICES_SHAPE_MEMBERS \
array<float,7> unknownFloats1; \
mutable uint num1; \
vector<Float4 > unknownVectors1; \
mutable uint num2; \
vector<Float4 > unknownVectors2; \

#define BHK_CONVEX_VERTICES_SHAPE_INCLUDE "bhkSphereRepShape.h" \

#define BHK_CONVEX_VERTICES_SHAPE_PARENT bhkSphereRepShape \

#define BHK_CONVEX_VERTICES_SHAPE_CONSTRUCT \
 : num1((uint)0), num2((uint)0) \

#define BHK_CONVEX_VERTICES_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_CONVEX_VERTICES_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_CONVEX_VERTICES_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_CONVEX_VERTICES_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_CONVEX_VERTICES_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_HINGE_CONSTRAINT_MEMBERS \
array<array<float,5>,4> unknownFloats; \

#define BHK_HINGE_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_HINGE_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_HINGE_CONSTRAINT_CONSTRUCT \

#define BHK_HINGE_CONSTRAINT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_HINGE_CONSTRAINT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_HINGE_CONSTRAINT_STRING \
return InternalAsString( verbose ); \

#define BHK_HINGE_CONSTRAINT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_HINGE_CONSTRAINT_GETREFS \
return InternalGetRefs(); \

#define BHK_LIMITED_HINGE_CONSTRAINT_MEMBERS \
LimitedHingeDescriptor limitedHinge; \

#define BHK_LIMITED_HINGE_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_LIMITED_HINGE_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_LIMITED_HINGE_CONSTRAINT_CONSTRUCT \

#define BHK_LIMITED_HINGE_CONSTRAINT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_STRING \
return InternalAsString( verbose ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_GETREFS \
return InternalGetRefs(); \

#define BHK_LIST_SHAPE_MEMBERS \
mutable uint numSubShapes; \
vector<Ref<bhkShape > > subShapes; \
uint material; \
array<float,6> unknownFloats; \
mutable uint numUnknownInts; \
vector<uint > unknownInts; \

#define BHK_LIST_SHAPE_INCLUDE "AbhkShapeCollection.h" \

#define BHK_LIST_SHAPE_PARENT AbhkShapeCollection \

#define BHK_LIST_SHAPE_CONSTRUCT \
 : numSubShapes((uint)0), material((uint)0), numUnknownInts((uint)0) \

#define BHK_LIST_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_LIST_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_LIST_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_LIST_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_LIST_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_MALLEABLE_CONSTRAINT_MEMBERS \
uint type; \
uint unknownInt2; \
Ref<NiObject > unknownLink1; \
Ref<NiObject > unknownLink2; \
uint unknownInt3; \
RagDollDescriptor ragdoll; \
LimitedHingeDescriptor limitedHinge; \
float tau; \
float damping; \

#define BHK_MALLEABLE_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_MALLEABLE_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_MALLEABLE_CONSTRAINT_CONSTRUCT \
 : type((uint)0), unknownInt2((uint)0), unknownLink1(NULL), unknownLink2(NULL), unknownInt3((uint)0), tau(0.0f), damping(0.0f) \

#define BHK_MALLEABLE_CONSTRAINT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_MALLEABLE_CONSTRAINT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_MALLEABLE_CONSTRAINT_STRING \
return InternalAsString( verbose ); \

#define BHK_MALLEABLE_CONSTRAINT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_MALLEABLE_CONSTRAINT_GETREFS \
return InternalGetRefs(); \

#define BHK_MOPP_BV_TREE_SHAPE_MEMBERS \
Ref<bhkShape > shape; \
uint material; \
array<byte,8> unknownBytes1; \
float unknownFloat; \
mutable uint numUnknownBytes2; \
vector<byte > unknownBytes2; \
Vector3 unknownVector; \
float unknownFloat2; \

#define BHK_MOPP_BV_TREE_SHAPE_INCLUDE "bhkShape.h" \

#define BHK_MOPP_BV_TREE_SHAPE_PARENT bhkShape \

#define BHK_MOPP_BV_TREE_SHAPE_CONSTRUCT \
 : shape(NULL), material((uint)0), unknownFloat(0.0f), numUnknownBytes2((uint)0), unknownFloat2(0.0f) \

#define BHK_MOPP_BV_TREE_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_MOPP_BV_TREE_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_MOPP_BV_TREE_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_MOPP_BV_TREE_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_MOPP_BV_TREE_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_MULTI_SPHERE_SHAPE_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
uint unknownInt2; \
array<float,8> unknownFloats; \

#define BHK_MULTI_SPHERE_SHAPE_INCLUDE "bhkSphereRepShape.h" \

#define BHK_MULTI_SPHERE_SHAPE_PARENT bhkSphereRepShape \

#define BHK_MULTI_SPHERE_SHAPE_CONSTRUCT \
 : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownInt2((uint)0) \

#define BHK_MULTI_SPHERE_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_MULTI_SPHERE_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_MULTI_SPHERE_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_MULTI_SPHERE_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_MULTI_SPHERE_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_NI_TRI_STRIPS_SHAPE_MEMBERS \
float unknownFloat1; \
uint unknownInt1; \
array<uint,4> unknownInts1; \
uint unknownInt2; \
Vector3 scale; \
uint unknownInt3; \
mutable uint numStripsData; \
vector<Ref<NiTriStripsData > > stripsData; \
mutable uint numUnknownInts2; \
vector<uint > unknownInts2; \

#define BHK_NI_TRI_STRIPS_SHAPE_INCLUDE "bhkSphereRepShape.h" \

#define BHK_NI_TRI_STRIPS_SHAPE_PARENT bhkSphereRepShape \

#define BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT \
 : unknownFloat1(0.1f), unknownInt1((uint)0x004ABE60), unknownInt2((uint)1), scale(1.0f, 1.0f, 1.0f), unknownInt3((uint)0), numStripsData((uint)0), numUnknownInts2((uint)0) \

#define BHK_NI_TRI_STRIPS_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_NI_TRI_STRIPS_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_NI_TRI_STRIPS_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_NI_TRI_STRIPS_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_NI_TRI_STRIPS_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_MEMBERS \
mutable ushort numSubparts; \
vector< array<uint,3> > subparts; \
array<float,9> unknownFloats; \
float scale; \
array<float,3> unknownFloats2; \
Ref<hkPackedNiTriStripsData > data; \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_INCLUDE "AbhkShapeCollection.h" \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT AbhkShapeCollection \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_CONSTRUCT \
 : numSubparts((ushort)0), scale(1.0f), data(NULL) \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_PRISMATIC_CONSTRAINT_MEMBERS \
array<Float4,8> unknownVectors; \
array<float,3> unknownFloats2; \

#define BHK_PRISMATIC_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_PRISMATIC_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_PRISMATIC_CONSTRAINT_CONSTRUCT \

#define BHK_PRISMATIC_CONSTRAINT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_PRISMATIC_CONSTRAINT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_PRISMATIC_CONSTRAINT_STRING \
return InternalAsString( verbose ); \

#define BHK_PRISMATIC_CONSTRAINT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_PRISMATIC_CONSTRAINT_GETREFS \
return InternalGetRefs(); \

#define BHK_RAGDOLL_CONSTRAINT_MEMBERS \

#define BHK_RAGDOLL_CONSTRAINT_INCLUDE "AbhkRagdollConstraint.h" \

#define BHK_RAGDOLL_CONSTRAINT_PARENT AbhkRagdollConstraint \

#define BHK_RAGDOLL_CONSTRAINT_CONSTRUCT \

#define BHK_RAGDOLL_CONSTRAINT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_RAGDOLL_CONSTRAINT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_RAGDOLL_CONSTRAINT_STRING \
return InternalAsString( verbose ); \

#define BHK_RAGDOLL_CONSTRAINT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_RAGDOLL_CONSTRAINT_GETREFS \
return InternalGetRefs(); \

#define BHK_RIGID_BODY_MEMBERS \
array<float,5> unknownFloats1; \
array<ushort,4> unknownShorts1; \
uint layerCopy; \
array<ushort,6> unknownShorts2; \
Vector3 translation; \
float unknownFloat00; \
QuaternionXYZW rotation; \
Vector3 linearVelocity; \
float unknownFloat01; \
Vector3 angularVelocity; \
float unknownFloat02; \
array<float,12> transform; \
Vector3 center; \
float unknownFloat03; \
float mass; \
float linearDamping; \
float angularDamping; \
float friction; \
float restitution; \
float maxLinearVelocity; \
float maxAngularVelocity; \
float penetrationDepth; \
byte motionSystem; \
byte unknownByte1; \
byte unknownByte2; \
byte qualityType; \
uint unknownInt6; \
uint unknownInt7; \
uint unknownInt8; \
mutable uint numConstraints; \
vector<Ref<AbhkConstraint > > constraints; \

#define BHK_RIGID_BODY_INCLUDE "bhkEntity.h" \

#define BHK_RIGID_BODY_PARENT bhkEntity \

#define BHK_RIGID_BODY_CONSTRUCT \
 : layerCopy((uint)0), unknownFloat00(0.0f), unknownFloat01(0.0f), unknownFloat02(0.0f), unknownFloat03(0.0f), mass(0.0f), linearDamping(0.0f), angularDamping(0.0f), friction(0.0f), restitution(0.0f), maxLinearVelocity(0.0f), maxAngularVelocity(31.415926535f), penetrationDepth(0.0f), motionSystem((byte)0), unknownByte1((byte)0), unknownByte2((byte)0), qualityType((byte)0), unknownInt6((uint)0), unknownInt7((uint)0), unknownInt8((uint)0), numConstraints((uint)0) \

#define BHK_RIGID_BODY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_RIGID_BODY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_RIGID_BODY_STRING \
return InternalAsString( verbose ); \

#define BHK_RIGID_BODY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_RIGID_BODY_GETREFS \
return InternalGetRefs(); \

#define BHK_RIGID_BODY_T_MEMBERS \

#define BHK_RIGID_BODY_T_INCLUDE "bhkRigidBody.h" \

#define BHK_RIGID_BODY_T_PARENT bhkRigidBody \

#define BHK_RIGID_BODY_T_CONSTRUCT \

#define BHK_RIGID_BODY_T_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_RIGID_BODY_T_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_RIGID_BODY_T_STRING \
return InternalAsString( verbose ); \

#define BHK_RIGID_BODY_T_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_RIGID_BODY_T_GETREFS \
return InternalGetRefs(); \

#define BHK_SIMPLE_SHAPE_PHANTOM_MEMBERS \
array<float,7> unkownFloats; \
array<array<float,3>,5> unknownFloats2; \
float unknownFloat; \

#define BHK_SIMPLE_SHAPE_PHANTOM_INCLUDE "bhkEntity.h" \

#define BHK_SIMPLE_SHAPE_PHANTOM_PARENT bhkEntity \

#define BHK_SIMPLE_SHAPE_PHANTOM_CONSTRUCT \
 : unknownFloat(0.0f) \

#define BHK_SIMPLE_SHAPE_PHANTOM_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_STRING \
return InternalAsString( verbose ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_GETREFS \
return InternalGetRefs(); \

#define BHK_S_P_COLLISION_OBJECT_MEMBERS \

#define BHK_S_P_COLLISION_OBJECT_INCLUDE "NiCollisionObject.h" \

#define BHK_S_P_COLLISION_OBJECT_PARENT NiCollisionObject \

#define BHK_S_P_COLLISION_OBJECT_CONSTRUCT \

#define BHK_S_P_COLLISION_OBJECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_S_P_COLLISION_OBJECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_S_P_COLLISION_OBJECT_STRING \
return InternalAsString( verbose ); \

#define BHK_S_P_COLLISION_OBJECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_S_P_COLLISION_OBJECT_GETREFS \
return InternalGetRefs(); \

#define BHK_SPHERE_SHAPE_MEMBERS \
float radius; \

#define BHK_SPHERE_SHAPE_INCLUDE "bhkConvexShape.h" \

#define BHK_SPHERE_SHAPE_PARENT bhkConvexShape \

#define BHK_SPHERE_SHAPE_CONSTRUCT \
 : radius(0.0f) \

#define BHK_SPHERE_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_SPHERE_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_SPHERE_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_SPHERE_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_SPHERE_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_STIFF_SPRING_CONSTRAINT_MEMBERS \
array<array<float,2>,4> unknownFloats; \
float unknownFloat; \

#define BHK_STIFF_SPRING_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_STIFF_SPRING_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_STIFF_SPRING_CONSTRAINT_CONSTRUCT \
 : unknownFloat(0.0f) \

#define BHK_STIFF_SPRING_CONSTRAINT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_STRING \
return InternalAsString( verbose ); \

#define BHK_STIFF_SPRING_CONSTRAINT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_GETREFS \
return InternalGetRefs(); \

#define BHK_TRANSFORM_SHAPE_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
Matrix44 transform; \

#define BHK_TRANSFORM_SHAPE_INCLUDE "bhkEntity.h" \

#define BHK_TRANSFORM_SHAPE_PARENT bhkEntity \

#define BHK_TRANSFORM_SHAPE_CONSTRUCT \
 : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f) \

#define BHK_TRANSFORM_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_TRANSFORM_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_TRANSFORM_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_TRANSFORM_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_TRANSFORM_SHAPE_GETREFS \
return InternalGetRefs(); \

#define BHK_CONVEX_TRANSFORM_SHAPE_MEMBERS \

#define BHK_CONVEX_TRANSFORM_SHAPE_INCLUDE "bhkTransformShape.h" \

#define BHK_CONVEX_TRANSFORM_SHAPE_PARENT bhkTransformShape \

#define BHK_CONVEX_TRANSFORM_SHAPE_CONSTRUCT \

#define BHK_CONVEX_TRANSFORM_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_STRING \
return InternalAsString( verbose ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_GETREFS \
return InternalGetRefs(); \

#define B_S_BOUND_MEMBERS \
array<float,6> unknownFloats; \

#define B_S_BOUND_INCLUDE "NiExtraData.h" \

#define B_S_BOUND_PARENT NiExtraData \

#define B_S_BOUND_CONSTRUCT \

#define B_S_BOUND_READ \
InternalRead( in, link_stack, version, user_version ); \

#define B_S_BOUND_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define B_S_BOUND_STRING \
return InternalAsString( verbose ); \

#define B_S_BOUND_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define B_S_BOUND_GETREFS \
return InternalGetRefs(); \

#define B_S_FURNITURE_MARKER_MEMBERS \
mutable uint numPositions; \
vector<FurniturePosition > positions; \

#define B_S_FURNITURE_MARKER_INCLUDE "NiExtraData.h" \

#define B_S_FURNITURE_MARKER_PARENT NiExtraData \

#define B_S_FURNITURE_MARKER_CONSTRUCT \
 : numPositions((uint)0) \

#define B_S_FURNITURE_MARKER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define B_S_FURNITURE_MARKER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define B_S_FURNITURE_MARKER_STRING \
return InternalAsString( verbose ); \

#define B_S_FURNITURE_MARKER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define B_S_FURNITURE_MARKER_GETREFS \
return InternalGetRefs(); \

#define B_S_PARENT_VELOCITY_MODIFIER_MEMBERS \
float unknownFloat; \

#define B_S_PARENT_VELOCITY_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define B_S_PARENT_VELOCITY_MODIFIER_PARENT NiPSysModifier \

#define B_S_PARENT_VELOCITY_MODIFIER_CONSTRUCT \
 : unknownFloat(0.0f) \

#define B_S_PARENT_VELOCITY_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define B_S_PARENT_VELOCITY_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define B_S_P_SYS_ARRAY_EMITTER_MEMBERS \

#define B_S_P_SYS_ARRAY_EMITTER_INCLUDE "NiPSysVolumeEmitter.h" \

#define B_S_P_SYS_ARRAY_EMITTER_PARENT NiPSysVolumeEmitter \

#define B_S_P_SYS_ARRAY_EMITTER_CONSTRUCT \

#define B_S_P_SYS_ARRAY_EMITTER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define B_S_P_SYS_ARRAY_EMITTER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define B_S_P_SYS_ARRAY_EMITTER_STRING \
return InternalAsString( verbose ); \

#define B_S_P_SYS_ARRAY_EMITTER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define B_S_P_SYS_ARRAY_EMITTER_GETREFS \
return InternalGetRefs(); \

#define B_S_X_FLAGS_MEMBERS \
uint flags; \

#define B_S_X_FLAGS_INCLUDE "NiExtraData.h" \

#define B_S_X_FLAGS_PARENT NiExtraData \

#define B_S_X_FLAGS_CONSTRUCT \
 : flags((uint)0) \

#define B_S_X_FLAGS_READ \
InternalRead( in, link_stack, version, user_version ); \

#define B_S_X_FLAGS_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define B_S_X_FLAGS_STRING \
return InternalAsString( verbose ); \

#define B_S_X_FLAGS_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define B_S_X_FLAGS_GETREFS \
return InternalGetRefs(); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_MEMBERS \
mutable uint numTriangles; \
vector<hkTriangle > triangles; \
mutable uint numVertices; \
vector<Vector3 > vertices; \

#define HK_PACKED_NI_TRI_STRIPS_DATA_INCLUDE "AbhkShapeCollection.h" \

#define HK_PACKED_NI_TRI_STRIPS_DATA_PARENT AbhkShapeCollection \

#define HK_PACKED_NI_TRI_STRIPS_DATA_CONSTRUCT \
 : numTriangles((uint)0), numVertices((uint)0) \

#define HK_PACKED_NI_TRI_STRIPS_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_STRING \
return InternalAsString( verbose ); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_ALPHA_CONTROLLER_MEMBERS \
Ref<NiFloatData > data; \

#define NI_ALPHA_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_ALPHA_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_ALPHA_CONTROLLER_CONSTRUCT \
 : data(NULL) \

#define NI_ALPHA_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_ALPHA_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_ALPHA_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_ALPHA_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_ALPHA_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_ALPHA_PROPERTY_MEMBERS \
ushort flags; \
byte threshold; \

#define NI_ALPHA_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_ALPHA_PROPERTY_PARENT NiProperty \

#define NI_ALPHA_PROPERTY_CONSTRUCT \
 : flags((ushort)237), threshold((byte)0) \

#define NI_ALPHA_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_ALPHA_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_ALPHA_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_ALPHA_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_ALPHA_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_AMBIENT_LIGHT_MEMBERS \

#define NI_AMBIENT_LIGHT_INCLUDE "NiLight.h" \

#define NI_AMBIENT_LIGHT_PARENT NiLight \

#define NI_AMBIENT_LIGHT_CONSTRUCT \

#define NI_AMBIENT_LIGHT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_AMBIENT_LIGHT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_AMBIENT_LIGHT_STRING \
return InternalAsString( verbose ); \

#define NI_AMBIENT_LIGHT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_AMBIENT_LIGHT_GETREFS \
return InternalGetRefs(); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_MEMBERS \
ushort numParticles; \
float size; \
ushort numActive; \
ushort unknownShort; \
bool hasSizes; \
vector<float > sizes; \

#define NI_AUTO_NORMAL_PARTICLES_DATA_INCLUDE "NiTriBasedGeomData.h" \

#define NI_AUTO_NORMAL_PARTICLES_DATA_PARENT NiTriBasedGeomData \

#define NI_AUTO_NORMAL_PARTICLES_DATA_CONSTRUCT \
 : numParticles((ushort)0), size(0.0f), numActive((ushort)0), unknownShort((ushort)0), hasSizes(false) \

#define NI_AUTO_NORMAL_PARTICLES_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_BINARY_EXTRA_DATA_MEMBERS \
ByteArray binaryData; \

#define NI_BINARY_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_BINARY_EXTRA_DATA_PARENT NiExtraData \

#define NI_BINARY_EXTRA_DATA_CONSTRUCT \

#define NI_BINARY_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BINARY_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BINARY_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_BINARY_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BINARY_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_BLEND_BOOL_INTERPOLATOR_MEMBERS \
byte boolValue; \

#define NI_BLEND_BOOL_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_BLEND_BOOL_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT \
 : boolValue((byte)0) \

#define NI_BLEND_BOOL_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BLEND_BOOL_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BLEND_BOOL_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_BLEND_BOOL_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_BOOL_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_BLEND_FLOAT_INTERPOLATOR_MEMBERS \
float floatValue; \

#define NI_BLEND_FLOAT_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_BLEND_FLOAT_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_BLEND_FLOAT_INTERPOLATOR_CONSTRUCT \
 : floatValue(0.0f) \

#define NI_BLEND_FLOAT_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_BLEND_POINT3_INTERPOLATOR_MEMBERS \
Vector3 pointValue; \

#define NI_BLEND_POINT3_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_BLEND_POINT3_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_BLEND_POINT3_INTERPOLATOR_CONSTRUCT \

#define NI_BLEND_POINT3_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BLEND_POINT3_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BLEND_POINT3_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_BLEND_POINT3_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_POINT3_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_MEMBERS \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_CONSTRUCT \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_BONE_L_O_D_CONTROLLER_MEMBERS \
mutable uint numShapeGroups; \
vector<SkinShapeGroup > shapeGroups1; \
mutable uint numShapeGroups2; \
vector<Ref<NiTriShape > > shapeGroups2; \

#define NI_BONE_L_O_D_CONTROLLER_INCLUDE "ABoneLODController.h" \

#define NI_BONE_L_O_D_CONTROLLER_PARENT ABoneLODController \

#define NI_BONE_L_O_D_CONTROLLER_CONSTRUCT \
 : numShapeGroups((uint)0), numShapeGroups2((uint)0) \

#define NI_BONE_L_O_D_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BONE_L_O_D_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BONE_L_O_D_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_BONE_L_O_D_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BONE_L_O_D_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_BOOL_DATA_MEMBERS \
KeyGroup<byte > data; \

#define NI_BOOL_DATA_INCLUDE "AKeyedData.h" \

#define NI_BOOL_DATA_PARENT AKeyedData \

#define NI_BOOL_DATA_CONSTRUCT \

#define NI_BOOL_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BOOL_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BOOL_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_BOOL_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BOOL_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_BOOLEAN_EXTRA_DATA_MEMBERS \
byte booleanData; \

#define NI_BOOLEAN_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_BOOLEAN_EXTRA_DATA_PARENT NiExtraData \

#define NI_BOOLEAN_EXTRA_DATA_CONSTRUCT \
 : booleanData((byte)0) \

#define NI_BOOLEAN_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BOOLEAN_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BOOLEAN_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_BOOLEAN_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BOOLEAN_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_BOOL_INTERPOLATOR_MEMBERS \
bool boolValue; \
Ref<NiBoolData > data; \

#define NI_BOOL_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_BOOL_INTERPOLATOR_PARENT NiInterpolator \

#define NI_BOOL_INTERPOLATOR_CONSTRUCT \
 : boolValue(false), data(NULL) \

#define NI_BOOL_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BOOL_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BOOL_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_BOOL_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BOOL_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS \
byte boolValue; \
Ref<NiBoolData > data; \

#define NI_BOOL_TIMELINE_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_BOOL_TIMELINE_INTERPOLATOR_PARENT NiInterpolator \

#define NI_BOOL_TIMELINE_INTERPOLATOR_CONSTRUCT \
 : boolValue((byte)0), data(NULL) \

#define NI_BOOL_TIMELINE_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_MEMBERS \

#define NI_B_S_BONE_L_O_D_CONTROLLER_INCLUDE "ABoneLODController.h" \

#define NI_B_S_BONE_L_O_D_CONTROLLER_PARENT ABoneLODController \

#define NI_B_S_BONE_L_O_D_CONTROLLER_CONSTRUCT \

#define NI_B_S_BONE_L_O_D_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_B_SPLINE_BASIS_DATA_MEMBERS \
uint numControlPt; \

#define NI_B_SPLINE_BASIS_DATA_INCLUDE "NiObject.h" \

#define NI_B_SPLINE_BASIS_DATA_PARENT NiObject \

#define NI_B_SPLINE_BASIS_DATA_CONSTRUCT \
 : numControlPt((uint)0) \

#define NI_B_SPLINE_BASIS_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_SPLINE_BASIS_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_SPLINE_BASIS_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_B_SPLINE_BASIS_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_BASIS_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_MEMBERS \
array<float,4> unknownFloats; \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_INCLUDE "NiBSplineInterpolator.h" \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_PARENT NiBSplineInterpolator \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_CONSTRUCT \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_MEMBERS \
array<float,6> unknownFloats; \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_INCLUDE "NiBSplineInterpolator.h" \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT NiBSplineInterpolator \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_CONSTRUCT \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS \
Vector3 translation; \
Quaternion rotation; \
float scale; \
ushort translateOffset; \
ushort unkInt1; \
ushort rotateOffset; \
ushort unkInt2; \
ushort scaleOffset; \
ushort unkInt3; \
float translateBias; \
float translateMultiplier; \
float rotationBias; \
float rotationMultiplier; \
float scaleBias; \
float scaleMultiplier; \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_INCLUDE "NiBSplineInterpolator.h" \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT NiBSplineInterpolator \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_CONSTRUCT \
 : scale(0.0f), translateOffset((ushort)0), unkInt1((ushort)0), rotateOffset((ushort)0), unkInt2((ushort)0), scaleOffset((ushort)0), unkInt3((ushort)0), translateBias(0.0f), translateMultiplier(0.0f), rotationBias(0.0f), rotationMultiplier(0.0f), scaleBias(0.0f), scaleMultiplier(0.0f) \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_B_SPLINE_DATA_MEMBERS \
uint unknownInt; \
mutable uint count; \
vector<short > controlPoints; \

#define NI_B_SPLINE_DATA_INCLUDE "NiObject.h" \

#define NI_B_SPLINE_DATA_PARENT NiObject \

#define NI_B_SPLINE_DATA_CONSTRUCT \
 : unknownInt((uint)0), count((uint)0) \

#define NI_B_SPLINE_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_SPLINE_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_SPLINE_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_B_SPLINE_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_CAMERA_MEMBERS \
ushort unknownShort; \
float frustumLeft; \
float frustumRight; \
float frustumTop; \
float frustumBottom; \
float frustumNear; \
float frustumFar; \
bool useOrthographicProjection; \
float viewportLeft; \
float viewportRight; \
float viewportTop; \
float viewportBottom; \
float lodAdjust; \
Ref<NiObject > unknownLink_; \
uint unknownInt; \
uint unknownInt2; \

#define NI_CAMERA_INCLUDE "NiAVObject.h" \

#define NI_CAMERA_PARENT NiAVObject \

#define NI_CAMERA_CONSTRUCT \
 : unknownShort((ushort)0), frustumLeft(0.0f), frustumRight(0.0f), frustumTop(0.0f), frustumBottom(0.0f), frustumNear(0.0f), frustumFar(0.0f), useOrthographicProjection(false), viewportLeft(0.0f), viewportRight(0.0f), viewportTop(0.0f), viewportBottom(0.0f), lodAdjust(0.0f), unknownLink_(NULL), unknownInt((uint)0), unknownInt2((uint)0) \

#define NI_CAMERA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_CAMERA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_CAMERA_STRING \
return InternalAsString( verbose ); \

#define NI_CAMERA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_CAMERA_GETREFS \
return InternalGetRefs(); \

#define NI_COLLISION_DATA_MEMBERS \
NiNode * targetNode; \
uint unknown2; \
byte unknown3; \
uint collisionType; \
uint unknown5; \
Vector3 unknown7; \
array<float,8> unknown6; \
array<float,15> unknown8; \

#define NI_COLLISION_DATA_INCLUDE "NiObject.h" \

#define NI_COLLISION_DATA_PARENT NiObject \

#define NI_COLLISION_DATA_CONSTRUCT \
 : targetNode(NULL), unknown2((uint)0), unknown3((byte)0), collisionType((uint)0), unknown5((uint)0) \

#define NI_COLLISION_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_COLLISION_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_COLLISION_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_COLLISION_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_COLLISION_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_COLOR_DATA_MEMBERS \
KeyGroup<Color4 > data; \

#define NI_COLOR_DATA_INCLUDE "AKeyedData.h" \

#define NI_COLOR_DATA_PARENT AKeyedData \

#define NI_COLOR_DATA_CONSTRUCT \

#define NI_COLOR_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_COLOR_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_COLOR_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_COLOR_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_COLOR_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_COLOR_EXTRA_DATA_MEMBERS \
Color4 data; \

#define NI_COLOR_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_COLOR_EXTRA_DATA_PARENT NiExtraData \

#define NI_COLOR_EXTRA_DATA_CONSTRUCT \

#define NI_COLOR_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_COLOR_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_COLOR_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_COLOR_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_COLOR_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_CONTROLLER_MANAGER_MEMBERS \
bool cumulative; \
mutable uint numControllerSequences; \
vector<Ref<NiControllerSequence > > controllerSequences; \
Ref<NiDefaultAVObjectPalette > objectPalette; \

#define NI_CONTROLLER_MANAGER_INCLUDE "NiTimeController.h" \

#define NI_CONTROLLER_MANAGER_PARENT NiTimeController \

#define NI_CONTROLLER_MANAGER_CONSTRUCT \
 : cumulative(false), numControllerSequences((uint)0), objectPalette(NULL) \

#define NI_CONTROLLER_MANAGER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_CONTROLLER_MANAGER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_CONTROLLER_MANAGER_STRING \
return InternalAsString( verbose ); \

#define NI_CONTROLLER_MANAGER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_CONTROLLER_MANAGER_GETREFS \
return InternalGetRefs(); \

#define NI_CONTROLLER_SEQUENCE_MEMBERS \
string name; \
string textKeysName; \
Ref<NiTextKeyExtraData > textKeys; \
mutable uint numControlledBlocks; \
uint unknownInt1; \
vector<ControllerLink > controlledBlocks; \
float weight; \
uint cycleType; \
uint unknownInt0; \
float frequency; \
float startTime; \
float stopTime; \
float unknownFloat2; \
byte unknownByte; \
NiControllerManager * manager; \
string targetName; \
Ref<NiStringPalette > stringPalette; \

#define NI_CONTROLLER_SEQUENCE_INCLUDE "NiObject.h" \

#define NI_CONTROLLER_SEQUENCE_PARENT NiObject \

#define NI_CONTROLLER_SEQUENCE_CONSTRUCT \
 : textKeys(NULL), numControlledBlocks((uint)0), unknownInt1((uint)0), weight(1.0f), cycleType((uint)0), unknownInt0((uint)0), frequency(0.0f), startTime(0.0f), stopTime(0.0f), unknownFloat2(0.0f), unknownByte((byte)0), manager(NULL), stringPalette(NULL) \

#define NI_CONTROLLER_SEQUENCE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_CONTROLLER_SEQUENCE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_CONTROLLER_SEQUENCE_STRING \
return InternalAsString( verbose ); \

#define NI_CONTROLLER_SEQUENCE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_CONTROLLER_SEQUENCE_GETREFS \
return InternalGetRefs(); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS \
uint unknownInt; \
mutable uint numObjs; \
vector<AVObject > objs; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_INCLUDE "NiObject.h" \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT NiObject \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_CONSTRUCT \
 : unknownInt((uint)0), numObjs((uint)0) \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_STRING \
return InternalAsString( verbose ); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_GETREFS \
return InternalGetRefs(); \

#define NI_DIRECTIONAL_LIGHT_MEMBERS \

#define NI_DIRECTIONAL_LIGHT_INCLUDE "NiLight.h" \

#define NI_DIRECTIONAL_LIGHT_PARENT NiLight \

#define NI_DIRECTIONAL_LIGHT_CONSTRUCT \

#define NI_DIRECTIONAL_LIGHT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_DIRECTIONAL_LIGHT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_DIRECTIONAL_LIGHT_STRING \
return InternalAsString( verbose ); \

#define NI_DIRECTIONAL_LIGHT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_DIRECTIONAL_LIGHT_GETREFS \
return InternalGetRefs(); \

#define NI_DITHER_PROPERTY_MEMBERS \
ushort flags; \

#define NI_DITHER_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_DITHER_PROPERTY_PARENT NiProperty \

#define NI_DITHER_PROPERTY_CONSTRUCT \
 : flags((ushort)0) \

#define NI_DITHER_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_DITHER_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_DITHER_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_DITHER_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_DITHER_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_FLIP_CONTROLLER_MEMBERS \
uint textureSlot; \
uint unknownInt2; \
float delta; \
mutable uint numSources; \
vector<Ref<NiSourceTexture > > sources; \

#define NI_FLIP_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_FLIP_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_FLIP_CONTROLLER_CONSTRUCT \
 : textureSlot((uint)0), unknownInt2((uint)0), delta(0.0f), numSources((uint)0) \

#define NI_FLIP_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_FLIP_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_FLIP_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_FLIP_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_FLIP_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_FLOAT_DATA_MEMBERS \
KeyGroup<float > data; \

#define NI_FLOAT_DATA_INCLUDE "AKeyedData.h" \

#define NI_FLOAT_DATA_PARENT AKeyedData \

#define NI_FLOAT_DATA_CONSTRUCT \

#define NI_FLOAT_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_FLOAT_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_FLOAT_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_FLOAT_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_FLOAT_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_FLOAT_EXTRA_DATA_MEMBERS \
float floatData; \

#define NI_FLOAT_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_FLOAT_EXTRA_DATA_PARENT NiExtraData \

#define NI_FLOAT_EXTRA_DATA_CONSTRUCT \
 : floatData(0.0f) \

#define NI_FLOAT_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_FLOAT_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_FLOAT_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_FLOAT_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_FLOAT_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_MEMBERS \
Ref<NiObject > unknownLink; \
string unknownString; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_PARENT NiTimeController \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_CONSTRUCT \
 : unknownLink(NULL) \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_FLOAT_INTERPOLATOR_MEMBERS \
float floatValue; \
Ref<NiFloatData > data; \

#define NI_FLOAT_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_FLOAT_INTERPOLATOR_PARENT NiInterpolator \

#define NI_FLOAT_INTERPOLATOR_CONSTRUCT \
 : floatValue(0.0f), data(NULL) \

#define NI_FLOAT_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_FLOAT_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_FLOAT_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_FLOAT_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_FLOAT_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_FLOATS_EXTRA_DATA_MEMBERS \
mutable uint numFloats; \
vector<float > data; \

#define NI_FLOATS_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_FLOATS_EXTRA_DATA_PARENT NiExtraData \

#define NI_FLOATS_EXTRA_DATA_CONSTRUCT \
 : numFloats((uint)0) \

#define NI_FLOATS_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_FLOATS_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_FLOATS_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_FLOATS_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_FLOATS_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_FOG_PROPERTY_MEMBERS \
ushort flags; \
float fogDepth; \
Color3 fogColor; \

#define NI_FOG_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_FOG_PROPERTY_PARENT NiProperty \

#define NI_FOG_PROPERTY_CONSTRUCT \
 : flags((ushort)0), fogDepth(0.0f) \

#define NI_FOG_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_FOG_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_FOG_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_FOG_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_FOG_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_GEOM_MORPHER_CONTROLLER_MEMBERS \
ushort unknown; \
byte unknown2; \
Ref<NiMorphData > data; \
byte unknownByte; \
mutable uint numInterpolators; \
vector<Ref<NiInterpolator > > interpolators; \
mutable uint numUnknownInts; \
vector<uint > unknownInts; \

#define NI_GEOM_MORPHER_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_GEOM_MORPHER_CONTROLLER_PARENT NiTimeController \

#define NI_GEOM_MORPHER_CONTROLLER_CONSTRUCT \
 : unknown((ushort)0), unknown2((byte)0), data(NULL), unknownByte((byte)0), numInterpolators((uint)0), numUnknownInts((uint)0) \

#define NI_GEOM_MORPHER_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_GEOM_MORPHER_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_GEOM_MORPHER_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_GEOM_MORPHER_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_GEOM_MORPHER_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_GRAVITY_MEMBERS \
float unknownFloat1; \
float force; \
uint type; \
Vector3 position; \
Vector3 direction; \

#define NI_GRAVITY_INCLUDE "AParticleModifier.h" \

#define NI_GRAVITY_PARENT AParticleModifier \

#define NI_GRAVITY_CONSTRUCT \
 : unknownFloat1(0.0f), force(0.0f), type((uint)0) \

#define NI_GRAVITY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_GRAVITY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_GRAVITY_STRING \
return InternalAsString( verbose ); \

#define NI_GRAVITY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_GRAVITY_GETREFS \
return InternalGetRefs(); \

#define NI_INTEGER_EXTRA_DATA_MEMBERS \
uint integerData; \

#define NI_INTEGER_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_INTEGER_EXTRA_DATA_PARENT NiExtraData \

#define NI_INTEGER_EXTRA_DATA_CONSTRUCT \
 : integerData((uint)0) \

#define NI_INTEGER_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_INTEGER_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_INTEGER_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_INTEGER_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_INTEGER_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_INTEGERS_EXTRA_DATA_MEMBERS \
mutable uint numIntegers; \
vector<uint > data; \

#define NI_INTEGERS_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_INTEGERS_EXTRA_DATA_PARENT NiExtraData \

#define NI_INTEGERS_EXTRA_DATA_CONSTRUCT \
 : numIntegers((uint)0) \

#define NI_INTEGERS_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_INTEGERS_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_INTEGERS_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_INTEGERS_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_INTEGERS_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_KEYFRAME_CONTROLLER_MEMBERS \
Ref<NiKeyframeData > data; \

#define NI_KEYFRAME_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_KEYFRAME_CONTROLLER_PARENT NiTimeController \

#define NI_KEYFRAME_CONTROLLER_CONSTRUCT \
 : data(NULL) \

#define NI_KEYFRAME_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_KEYFRAME_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_KEYFRAME_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_KEYFRAME_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_KEYFRAME_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define B_S_KEYFRAME_CONTROLLER_MEMBERS \
Ref<NiKeyframeData > data2; \

#define B_S_KEYFRAME_CONTROLLER_INCLUDE "NiKeyframeController.h" \

#define B_S_KEYFRAME_CONTROLLER_PARENT NiKeyframeController \

#define B_S_KEYFRAME_CONTROLLER_CONSTRUCT \
 : data2(NULL) \

#define B_S_KEYFRAME_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define B_S_KEYFRAME_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define B_S_KEYFRAME_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define B_S_KEYFRAME_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define B_S_KEYFRAME_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_KEYFRAME_DATA_MEMBERS \
mutable uint numRotationKeys; \
KeyType rotationType; \
vector<Key<Quaternion > > quaternionKeys; \
float unknownFloat; \
array<KeyGroup<float >,3> xyzRotations; \
KeyGroup<Vector3 > translations; \
KeyGroup<float > scales; \

#define NI_KEYFRAME_DATA_INCLUDE "AKeyedData.h" \

#define NI_KEYFRAME_DATA_PARENT AKeyedData \

#define NI_KEYFRAME_DATA_CONSTRUCT \
 : numRotationKeys((uint)0), rotationType((KeyType)0), unknownFloat(0.0f) \

#define NI_KEYFRAME_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_KEYFRAME_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_KEYFRAME_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_KEYFRAME_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_KEYFRAME_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_LIGHT_COLOR_CONTROLLER_MEMBERS \
ushort unknownShort; \
Ref<NiPosData > data; \
Ref<NiPoint3Interpolator > interpolator; \

#define NI_LIGHT_COLOR_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_LIGHT_COLOR_CONTROLLER_PARENT NiTimeController \

#define NI_LIGHT_COLOR_CONTROLLER_CONSTRUCT \
 : unknownShort((ushort)0), data(NULL), interpolator(NULL) \

#define NI_LIGHT_COLOR_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_LIGHT_COLOR_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_LIGHT_COLOR_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_LIGHT_COLOR_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_LIGHT_COLOR_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_LIGHT_DIMMER_CONTROLLER_MEMBERS \
Ref<NiInterpolator > unknownLink; \

#define NI_LIGHT_DIMMER_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_LIGHT_DIMMER_CONTROLLER_PARENT NiTimeController \

#define NI_LIGHT_DIMMER_CONTROLLER_CONSTRUCT \
 : unknownLink(NULL) \

#define NI_LIGHT_DIMMER_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_LIGHT_DIMMER_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_LIGHT_DIMMER_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_LIGHT_DIMMER_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_LIGHT_DIMMER_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_LOOK_AT_CONTROLLER_MEMBERS \
ushort unknown1; \
Ref<NiNode > lookAtNode; \

#define NI_LOOK_AT_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_LOOK_AT_CONTROLLER_PARENT NiTimeController \

#define NI_LOOK_AT_CONTROLLER_CONSTRUCT \
 : unknown1((ushort)0), lookAtNode(NULL) \

#define NI_LOOK_AT_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_LOOK_AT_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_LOOK_AT_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_LOOK_AT_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_LOOK_AT_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_LOOK_AT_INTERPOLATOR_MEMBERS \
ushort unknownShort; \
Ref<NiNode > lookAt; \
float unknownFloat; \
Vector3 translation; \
Quaternion rotation; \
float scale; \
Ref<NiPoint3Interpolator > unknownLink1; \
Ref<NiFloatInterpolator > unknownLink2; \
Ref<NiFloatInterpolator > unknownLink3; \

#define NI_LOOK_AT_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_LOOK_AT_INTERPOLATOR_PARENT NiInterpolator \

#define NI_LOOK_AT_INTERPOLATOR_CONSTRUCT \
 : unknownShort((ushort)0), lookAt(NULL), unknownFloat(0.0f), scale(0.0f), unknownLink1(NULL), unknownLink2(NULL), unknownLink3(NULL) \

#define NI_LOOK_AT_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_LOOK_AT_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_LOOK_AT_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_LOOK_AT_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_LOOK_AT_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_MATERIAL_COLOR_CONTROLLER_MEMBERS \
ushort unknown; \
Ref<NiPosData > data; \

#define NI_MATERIAL_COLOR_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_MATERIAL_COLOR_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_MATERIAL_COLOR_CONTROLLER_CONSTRUCT \
 : unknown((ushort)0), data(NULL) \

#define NI_MATERIAL_COLOR_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_MATERIAL_COLOR_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_MATERIAL_COLOR_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_MATERIAL_COLOR_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_MATERIAL_COLOR_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_MATERIAL_PROPERTY_MEMBERS \
ushort flags; \
Color3 ambientColor; \
Color3 diffuseColor; \
Color3 specularColor; \
Color3 emissiveColor; \
float glossiness; \
float alpha; \

#define NI_MATERIAL_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_MATERIAL_PROPERTY_PARENT NiProperty \

#define NI_MATERIAL_PROPERTY_CONSTRUCT \
 : flags((ushort)0), glossiness(0.0f), alpha(0.0f) \

#define NI_MATERIAL_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_MATERIAL_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_MATERIAL_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_MATERIAL_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_MATERIAL_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_MESH_P_SYS_DATA_MEMBERS \
byte unknownByte11; \
vector< array<float,4> > unknownFloats3; \
vector< array<float,10> > unknownFloats4; \
vector< array<float,12> > unknownFloats5; \
uint unknownInt1; \
Ref<NiPSysModifier > modifier; \
byte unknownByte2; \
mutable uint numUnknownLinks; \
vector<Ref<NiPSysModifier > > unknownLinks; \
ushort unknownShort4; \
uint unknownInt2; \
byte unknownByte12; \
uint unknownInt3; \
uint unknownInt4; \
Ref<NiNode > unknownLink2; \

#define NI_MESH_P_SYS_DATA_INCLUDE "APSysData.h" \

#define NI_MESH_P_SYS_DATA_PARENT APSysData \

#define NI_MESH_P_SYS_DATA_CONSTRUCT \
 : unknownByte11((byte)0), unknownInt1((uint)0), modifier(NULL), unknownByte2((byte)0), numUnknownLinks((uint)0), unknownShort4((ushort)0), unknownInt2((uint)0), unknownByte12((byte)0), unknownInt3((uint)0), unknownInt4((uint)0), unknownLink2(NULL) \

#define NI_MESH_P_SYS_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_MESH_P_SYS_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_MESH_P_SYS_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_MESH_P_SYS_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_MESH_P_SYS_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_MORPH_DATA_MEMBERS \
mutable uint numMorphs; \
uint numVertices; \
byte unknownByte; \
vector<Morph > morphs; \

#define NI_MORPH_DATA_INCLUDE "NiObject.h" \

#define NI_MORPH_DATA_PARENT NiObject \

#define NI_MORPH_DATA_CONSTRUCT \
 : numMorphs((uint)0), numVertices((uint)0), unknownByte((byte)0) \

#define NI_MORPH_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_MORPH_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_MORPH_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_MORPH_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_MORPH_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_MEMBERS \
mutable ushort numExtraTargets; \
vector<NiNode * > extraTargets; \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENT NiTimeController \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_CONSTRUCT \
 : numExtraTargets((ushort)0) \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_NODE_MEMBERS \
mutable uint numChildren; \
vector<Ref<NiAVObject > > children; \
mutable uint numEffects; \
vector<Ref<NiDynamicEffect > > effects; \

#define NI_NODE_INCLUDE "NiAVObject.h" \

#define NI_NODE_PARENT NiAVObject \

#define NI_NODE_CONSTRUCT \
 : numChildren((uint)0), numEffects((uint)0) \

#define NI_NODE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_NODE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_NODE_STRING \
return InternalAsString( verbose ); \

#define NI_NODE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_NODE_GETREFS \
return InternalGetRefs(); \

#define AVOID_NODE_MEMBERS \

#define AVOID_NODE_INCLUDE "NiNode.h" \

#define AVOID_NODE_PARENT NiNode \

#define AVOID_NODE_CONSTRUCT \

#define AVOID_NODE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define AVOID_NODE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define AVOID_NODE_STRING \
return InternalAsString( verbose ); \

#define AVOID_NODE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define AVOID_NODE_GETREFS \
return InternalGetRefs(); \

#define FX_WIDGET_MEMBERS \
byte unknown1; \
array<byte,292> unknown292Bytes; \

#define FX_WIDGET_INCLUDE "NiNode.h" \

#define FX_WIDGET_PARENT NiNode \

#define FX_WIDGET_CONSTRUCT \
 : unknown1((byte)0) \

#define FX_WIDGET_READ \
InternalRead( in, link_stack, version, user_version ); \

#define FX_WIDGET_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define FX_WIDGET_STRING \
return InternalAsString( verbose ); \

#define FX_WIDGET_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define FX_WIDGET_GETREFS \
return InternalGetRefs(); \

#define FX_BUTTON_MEMBERS \

#define FX_BUTTON_INCLUDE "FxWidget.h" \

#define FX_BUTTON_PARENT FxWidget \

#define FX_BUTTON_CONSTRUCT \

#define FX_BUTTON_READ \
InternalRead( in, link_stack, version, user_version ); \

#define FX_BUTTON_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define FX_BUTTON_STRING \
return InternalAsString( verbose ); \

#define FX_BUTTON_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define FX_BUTTON_GETREFS \
return InternalGetRefs(); \

#define FX_RADIO_BUTTON_MEMBERS \
uint unknownInt1; \
uint unknownInt2; \
uint unknownInt3; \
mutable uint numUnknownLinks; \
vector<Ref<NiObject > > unknownLinks; \

#define FX_RADIO_BUTTON_INCLUDE "FxWidget.h" \

#define FX_RADIO_BUTTON_PARENT FxWidget \

#define FX_RADIO_BUTTON_CONSTRUCT \
 : unknownInt1((uint)0), unknownInt2((uint)0), unknownInt3((uint)0), numUnknownLinks((uint)0) \

#define FX_RADIO_BUTTON_READ \
InternalRead( in, link_stack, version, user_version ); \

#define FX_RADIO_BUTTON_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define FX_RADIO_BUTTON_STRING \
return InternalAsString( verbose ); \

#define FX_RADIO_BUTTON_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define FX_RADIO_BUTTON_GETREFS \
return InternalGetRefs(); \

#define NI_BILLBOARD_NODE_MEMBERS \
ushort billboardMode; \

#define NI_BILLBOARD_NODE_INCLUDE "NiNode.h" \

#define NI_BILLBOARD_NODE_PARENT NiNode \

#define NI_BILLBOARD_NODE_CONSTRUCT \
 : billboardMode((ushort)0) \

#define NI_BILLBOARD_NODE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_BILLBOARD_NODE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_BILLBOARD_NODE_STRING \
return InternalAsString( verbose ); \

#define NI_BILLBOARD_NODE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_BILLBOARD_NODE_GETREFS \
return InternalGetRefs(); \

#define NI_B_S_ANIMATION_NODE_MEMBERS \

#define NI_B_S_ANIMATION_NODE_INCLUDE "NiNode.h" \

#define NI_B_S_ANIMATION_NODE_PARENT NiNode \

#define NI_B_S_ANIMATION_NODE_CONSTRUCT \

#define NI_B_S_ANIMATION_NODE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_S_ANIMATION_NODE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_S_ANIMATION_NODE_STRING \
return InternalAsString( verbose ); \

#define NI_B_S_ANIMATION_NODE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_S_ANIMATION_NODE_GETREFS \
return InternalGetRefs(); \

#define NI_B_S_PARTICLE_NODE_MEMBERS \

#define NI_B_S_PARTICLE_NODE_INCLUDE "NiNode.h" \

#define NI_B_S_PARTICLE_NODE_PARENT NiNode \

#define NI_B_S_PARTICLE_NODE_CONSTRUCT \

#define NI_B_S_PARTICLE_NODE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_S_PARTICLE_NODE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_S_PARTICLE_NODE_STRING \
return InternalAsString( verbose ); \

#define NI_B_S_PARTICLE_NODE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_S_PARTICLE_NODE_GETREFS \
return InternalGetRefs(); \

#define NI_L_O_D_NODE_MEMBERS \
uint lodType; \
Vector3 lodCenter; \
mutable uint numLodLevels; \
vector<LODRange > lodLevels; \
ushort unknownShort; \
Ref<NiRangeLODData > rangeData; \

#define NI_L_O_D_NODE_INCLUDE "NiNode.h" \

#define NI_L_O_D_NODE_PARENT NiNode \

#define NI_L_O_D_NODE_CONSTRUCT \
 : lodType((uint)0), numLodLevels((uint)0), unknownShort((ushort)0), rangeData(NULL) \

#define NI_L_O_D_NODE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_L_O_D_NODE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_L_O_D_NODE_STRING \
return InternalAsString( verbose ); \

#define NI_L_O_D_NODE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_L_O_D_NODE_GETREFS \
return InternalGetRefs(); \

#define NI_PALETTE_MEMBERS \
byte unknownByte; \
uint numEntries_; \
array<array<byte,256>,4> palette; \

#define NI_PALETTE_INCLUDE "NiObject.h" \

#define NI_PALETTE_PARENT NiObject \

#define NI_PALETTE_CONSTRUCT \
 : unknownByte((byte)0), numEntries_((uint)0) \

#define NI_PALETTE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PALETTE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PALETTE_STRING \
return InternalAsString( verbose ); \

#define NI_PALETTE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PALETTE_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_BOMB_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \
uint unknownInt1; \
uint unknownInt2; \
float unknownFloat5; \
float unknownFloat6; \
float unknownFloat7; \
float unknownFloat8; \
float unknownFloat9; \
float unknownFloat10; \

#define NI_PARTICLE_BOMB_INCLUDE "AParticleModifier.h" \

#define NI_PARTICLE_BOMB_PARENT AParticleModifier \

#define NI_PARTICLE_BOMB_CONSTRUCT \
 : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownFloat4(0.0f), unknownInt1((uint)0), unknownInt2((uint)0), unknownFloat5(0.0f), unknownFloat6(0.0f), unknownFloat7(0.0f), unknownFloat8(0.0f), unknownFloat9(0.0f), unknownFloat10(0.0f) \

#define NI_PARTICLE_BOMB_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_BOMB_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_BOMB_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_BOMB_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_BOMB_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_COLOR_MODIFIER_MEMBERS \
Ref<NiColorData > colorData; \

#define NI_PARTICLE_COLOR_MODIFIER_INCLUDE "AParticleModifier.h" \

#define NI_PARTICLE_COLOR_MODIFIER_PARENT AParticleModifier \

#define NI_PARTICLE_COLOR_MODIFIER_CONSTRUCT \
 : colorData(NULL) \

#define NI_PARTICLE_COLOR_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_COLOR_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_COLOR_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_COLOR_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_COLOR_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_GROW_FADE_MEMBERS \
float grow; \
float fade; \

#define NI_PARTICLE_GROW_FADE_INCLUDE "AParticleModifier.h" \

#define NI_PARTICLE_GROW_FADE_PARENT AParticleModifier \

#define NI_PARTICLE_GROW_FADE_CONSTRUCT \
 : grow(0.0f), fade(0.0f) \

#define NI_PARTICLE_GROW_FADE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_GROW_FADE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_GROW_FADE_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_GROW_FADE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_GROW_FADE_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_MESH_MODIFIER_MEMBERS \
mutable uint numParticleMeshes; \
vector<Ref<NiAVObject > > particleMeshes; \

#define NI_PARTICLE_MESH_MODIFIER_INCLUDE "AParticleModifier.h" \

#define NI_PARTICLE_MESH_MODIFIER_PARENT AParticleModifier \

#define NI_PARTICLE_MESH_MODIFIER_CONSTRUCT \
 : numParticleMeshes((uint)0) \

#define NI_PARTICLE_MESH_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_MESH_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_MESH_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_MESH_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_MESH_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_ROTATION_MEMBERS \
byte unknownByte; \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \

#define NI_PARTICLE_ROTATION_INCLUDE "AParticleModifier.h" \

#define NI_PARTICLE_ROTATION_PARENT AParticleModifier \

#define NI_PARTICLE_ROTATION_CONSTRUCT \
 : unknownByte((byte)0), unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownFloat4(0.0f) \

#define NI_PARTICLE_ROTATION_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_ROTATION_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_ROTATION_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_ROTATION_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_ROTATION_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLES_MEMBERS \

#define NI_PARTICLES_INCLUDE "NiTriBasedGeom.h" \

#define NI_PARTICLES_PARENT NiTriBasedGeom \

#define NI_PARTICLES_CONSTRUCT \

#define NI_PARTICLES_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLES_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLES_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLES_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLES_GETREFS \
return InternalGetRefs(); \

#define NI_AUTO_NORMAL_PARTICLES_MEMBERS \

#define NI_AUTO_NORMAL_PARTICLES_INCLUDE "NiParticles.h" \

#define NI_AUTO_NORMAL_PARTICLES_PARENT NiParticles \

#define NI_AUTO_NORMAL_PARTICLES_CONSTRUCT \

#define NI_AUTO_NORMAL_PARTICLES_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_STRING \
return InternalAsString( verbose ); \

#define NI_AUTO_NORMAL_PARTICLES_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_MESHES_MEMBERS \

#define NI_PARTICLE_MESHES_INCLUDE "NiParticles.h" \

#define NI_PARTICLE_MESHES_PARENT NiParticles \

#define NI_PARTICLE_MESHES_CONSTRUCT \

#define NI_PARTICLE_MESHES_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_MESHES_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_MESHES_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_MESHES_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_MESHES_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLES_DATA_MEMBERS \
ushort numActive; \
bool hasUnknownFloats; \
vector<float > unknownFloats; \
bool hasRotations; \
vector<Quaternion > rotations; \

#define NI_PARTICLES_DATA_INCLUDE "NiAutoNormalParticlesData.h" \

#define NI_PARTICLES_DATA_PARENT NiAutoNormalParticlesData \

#define NI_PARTICLES_DATA_CONSTRUCT \
 : numActive((ushort)0), hasUnknownFloats(false), hasRotations(false) \

#define NI_PARTICLES_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLES_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLES_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLES_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLES_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_MESHES_DATA_MEMBERS \
Ref<NiAVObject > unknownLink2; \

#define NI_PARTICLE_MESHES_DATA_INCLUDE "NiParticlesData.h" \

#define NI_PARTICLE_MESHES_DATA_PARENT NiParticlesData \

#define NI_PARTICLE_MESHES_DATA_CONSTRUCT \
 : unknownLink2(NULL) \

#define NI_PARTICLE_MESHES_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_MESHES_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_MESHES_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_MESHES_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_MESHES_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_SYSTEM_MEMBERS \
bool unknownBool; \
mutable uint numModifiers; \
vector<Ref<NiPSysModifier > > modifiers; \

#define NI_PARTICLE_SYSTEM_INCLUDE "NiParticles.h" \

#define NI_PARTICLE_SYSTEM_PARENT NiParticles \

#define NI_PARTICLE_SYSTEM_CONSTRUCT \
 : unknownBool(false), numModifiers((uint)0) \

#define NI_PARTICLE_SYSTEM_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_SYSTEM_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_SYSTEM_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_SYSTEM_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_SYSTEM_GETREFS \
return InternalGetRefs(); \

#define NI_MESH_PARTICLE_SYSTEM_MEMBERS \

#define NI_MESH_PARTICLE_SYSTEM_INCLUDE "NiParticleSystem.h" \

#define NI_MESH_PARTICLE_SYSTEM_PARENT NiParticleSystem \

#define NI_MESH_PARTICLE_SYSTEM_CONSTRUCT \

#define NI_MESH_PARTICLE_SYSTEM_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_MESH_PARTICLE_SYSTEM_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_MESH_PARTICLE_SYSTEM_STRING \
return InternalAsString( verbose ); \

#define NI_MESH_PARTICLE_SYSTEM_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_MESH_PARTICLE_SYSTEM_GETREFS \
return InternalGetRefs(); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_MEMBERS \
float speed; \
float speedRandom; \
float verticalDirection; \
float verticalAngle; \
float horizontalDirection; \
float horizontalAngle; \
float unknownFloat5; \
float unknownFloat6; \
float unknownFloat7; \
float unknownFloat8; \
float unknownFloat9; \
float unknownFloat10; \
float unknownFloat11; \
float size; \
float emitStartTime; \
float emitStopTime; \
byte unknownByte; \
float emitRate; \
float lifetime; \
float lifetimeRandom; \
ushort emitFlags; \
Vector3 startRandom; \
Ref<NiObject > emitter; \
ushort unknownShort2_; \
float unknownFloat13_; \
uint unknownInt1_; \
uint unknownInt2_; \
ushort unknownShort3_; \
mutable ushort numParticles; \
ushort numValid; \
vector<Particle > particles; \
Ref<NiObject > unknownLink; \
Ref<AParticleModifier > particleExtra; \
Ref<NiObject > unknownLink2; \
byte trailer; \

#define NI_PARTICLE_SYSTEM_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_PARTICLE_SYSTEM_CONTROLLER_PARENT NiTimeController \

#define NI_PARTICLE_SYSTEM_CONTROLLER_CONSTRUCT \
 : speed(0.0f), speedRandom(0.0f), verticalDirection(0.0f), verticalAngle(0.0f), horizontalDirection(0.0f), horizontalAngle(0.0f), unknownFloat5(0.0f), unknownFloat6(0.0f), unknownFloat7(0.0f), unknownFloat8(0.0f), unknownFloat9(0.0f), unknownFloat10(0.0f), unknownFloat11(0.0f), size(0.0f), emitStartTime(0.0f), emitStopTime(0.0f), unknownByte((byte)0), emitRate(0.0f), lifetime(0.0f), lifetimeRandom(0.0f), emitFlags((ushort)0), emitter(NULL), unknownShort2_((ushort)0), unknownFloat13_(0.0f), unknownInt1_((uint)0), unknownInt2_((uint)0), unknownShort3_((ushort)0), numParticles((ushort)0), numValid((ushort)0), unknownLink(NULL), particleExtra(NULL), unknownLink2(NULL), trailer((byte)0) \

#define NI_PARTICLE_SYSTEM_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_B_S_P_ARRAY_CONTROLLER_MEMBERS \

#define NI_B_S_P_ARRAY_CONTROLLER_INCLUDE "NiParticleSystemController.h" \

#define NI_B_S_P_ARRAY_CONTROLLER_PARENT NiParticleSystemController \

#define NI_B_S_P_ARRAY_CONTROLLER_CONSTRUCT \

#define NI_B_S_P_ARRAY_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_B_S_P_ARRAY_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_B_S_P_ARRAY_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_B_S_P_ARRAY_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_B_S_P_ARRAY_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_PATH_CONTROLLER_MEMBERS \
ushort unknownShort2; \
uint unknownInt1; \
uint unknownInt2; \
uint unknownInt3; \
ushort unknownShort; \
Ref<NiPosData > posData; \
Ref<NiFloatData > floatData; \

#define NI_PATH_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_PATH_CONTROLLER_PARENT NiTimeController \

#define NI_PATH_CONTROLLER_CONSTRUCT \
 : unknownShort2((ushort)0), unknownInt1((uint)0), unknownInt2((uint)0), unknownInt3((uint)0), unknownShort((ushort)0), posData(NULL), floatData(NULL) \

#define NI_PATH_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PATH_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PATH_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_PATH_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PATH_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_PATH_INTERPOLATOR_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
ushort unknownShort2; \
Ref<NiPosData > posData; \
Ref<NiFloatData > floatData; \

#define NI_PATH_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_PATH_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_PATH_INTERPOLATOR_CONSTRUCT \
 : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownShort2((ushort)0), posData(NULL), floatData(NULL) \

#define NI_PATH_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PATH_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PATH_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_PATH_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PATH_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_PIXEL_DATA_MEMBERS \
PixelFormat pixelFormat; \
uint redMask; \
uint greenMask; \
uint blueMask; \
uint alphaMask; \
uint bitsPerPixel; \
array<byte,8> unknown8Bytes; \
uint unknownInt; \
array<byte,54> unknown54Bytes; \
Ref<NiPalette > palette; \
mutable uint numMipmaps; \
uint bytesPerPixel; \
vector<MipMap > mipmaps; \
ByteArray pixelData; \
uint unknownInt2; \

#define NI_PIXEL_DATA_INCLUDE "NiObject.h" \

#define NI_PIXEL_DATA_PARENT NiObject \

#define NI_PIXEL_DATA_CONSTRUCT \
 : pixelFormat((PixelFormat)0), redMask((uint)0), greenMask((uint)0), blueMask((uint)0), alphaMask((uint)0), bitsPerPixel((uint)0), unknownInt((uint)0), palette(NULL), numMipmaps((uint)0), bytesPerPixel((uint)0), unknownInt2((uint)0) \

#define NI_PIXEL_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PIXEL_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PIXEL_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_PIXEL_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PIXEL_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_PLANAR_COLLIDER_MEMBERS \
ushort unknownShort; \
float unknownFloat1; \
float unknownFloat2; \
ushort unknownShort2; \
float unknownFloat3; \
float unknownFloat4; \
float unknownFloat5; \
float unknownFloat6; \
float unknownFloat7; \
float unknownFloat8; \
float unknownFloat9; \
float unknownFloat10; \
float unknownFloat11; \
float unknownFloat12; \
float unknownFloat13; \
float unknownFloat14; \
float unknownFloat15; \
float unknownFloat16; \

#define NI_PLANAR_COLLIDER_INCLUDE "AParticleModifier.h" \

#define NI_PLANAR_COLLIDER_PARENT AParticleModifier \

#define NI_PLANAR_COLLIDER_CONSTRUCT \
 : unknownShort((ushort)0), unknownFloat1(0.0f), unknownFloat2(0.0f), unknownShort2((ushort)0), unknownFloat3(0.0f), unknownFloat4(0.0f), unknownFloat5(0.0f), unknownFloat6(0.0f), unknownFloat7(0.0f), unknownFloat8(0.0f), unknownFloat9(0.0f), unknownFloat10(0.0f), unknownFloat11(0.0f), unknownFloat12(0.0f), unknownFloat13(0.0f), unknownFloat14(0.0f), unknownFloat15(0.0f), unknownFloat16(0.0f) \

#define NI_PLANAR_COLLIDER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_PLANAR_COLLIDER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_PLANAR_COLLIDER_STRING \
return InternalAsString( verbose ); \

#define NI_PLANAR_COLLIDER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_PLANAR_COLLIDER_GETREFS \
return InternalGetRefs(); \

#define NI_POINT3_INTERPOLATOR_MEMBERS \
Vector3 point3Value; \
Ref<NiPosData > data; \

#define NI_POINT3_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_POINT3_INTERPOLATOR_PARENT NiInterpolator \

#define NI_POINT3_INTERPOLATOR_CONSTRUCT \
 : data(NULL) \

#define NI_POINT3_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_POINT3_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_POINT3_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_POINT3_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_POINT3_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_POINT_LIGHT_MEMBERS \
float constantAttenuation; \
float linearAttenuation; \
float quadraticAttenuation; \

#define NI_POINT_LIGHT_INCLUDE "NiLight.h" \

#define NI_POINT_LIGHT_PARENT NiLight \

#define NI_POINT_LIGHT_CONSTRUCT \
 : constantAttenuation(0.0f), linearAttenuation(0.0f), quadraticAttenuation(0.0f) \

#define NI_POINT_LIGHT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_POINT_LIGHT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_POINT_LIGHT_STRING \
return InternalAsString( verbose ); \

#define NI_POINT_LIGHT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_POINT_LIGHT_GETREFS \
return InternalGetRefs(); \

#define NI_POS_DATA_MEMBERS \
KeyGroup<Vector3 > data; \

#define NI_POS_DATA_INCLUDE "AKeyedData.h" \

#define NI_POS_DATA_PARENT AKeyedData \

#define NI_POS_DATA_CONSTRUCT \

#define NI_POS_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_POS_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_POS_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_POS_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_POS_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_MEMBERS \
bool spawnOnDeath; \
Ref<NiPSysSpawnModifier > spawnModifier; \

#define NI_P_SYS_AGE_DEATH_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_AGE_DEATH_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT \
 : spawnOnDeath(false), spawnModifier(NULL) \

#define NI_P_SYS_AGE_DEATH_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_BOMB_MODIFIER_MEMBERS \
NiNode * unknownLink; \
array<uint,2> unknownInts1; \
array<float,3> unknownFloats; \
array<uint,2> unknownInts2; \

#define NI_P_SYS_BOMB_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_BOMB_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_BOMB_MODIFIER_CONSTRUCT \
 : unknownLink(NULL) \

#define NI_P_SYS_BOMB_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_BOMB_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_BOMB_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_BOMB_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_BOMB_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_MEMBERS \
ushort updateSkip; \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_CONSTRUCT \
 : updateSkip((ushort)0) \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_BOX_EMITTER_MEMBERS \
float width; \
float height; \
float depth; \

#define NI_P_SYS_BOX_EMITTER_INCLUDE "NiPSysVolumeEmitter.h" \

#define NI_P_SYS_BOX_EMITTER_PARENT NiPSysVolumeEmitter \

#define NI_P_SYS_BOX_EMITTER_CONSTRUCT \
 : width(0.0f), height(0.0f), depth(0.0f) \

#define NI_P_SYS_BOX_EMITTER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_BOX_EMITTER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_BOX_EMITTER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_BOX_EMITTER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_BOX_EMITTER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_COLLIDER_MANAGER_MEMBERS \
Ref<NiPSysPlanarCollider > collider; \

#define NI_P_SYS_COLLIDER_MANAGER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_COLLIDER_MANAGER_PARENT NiPSysModifier \

#define NI_P_SYS_COLLIDER_MANAGER_CONSTRUCT \
 : collider(NULL) \

#define NI_P_SYS_COLLIDER_MANAGER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_COLLIDER_MANAGER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_COLLIDER_MANAGER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_COLLIDER_MANAGER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_COLLIDER_MANAGER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_COLOR_MODIFIER_MEMBERS \
Ref<NiColorData > data; \

#define NI_P_SYS_COLOR_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_COLOR_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_COLOR_MODIFIER_CONSTRUCT \
 : data(NULL) \

#define NI_P_SYS_COLOR_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_COLOR_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_COLOR_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_COLOR_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_COLOR_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_CYLINDER_EMITTER_MEMBERS \
float radius; \
float height; \

#define NI_P_SYS_CYLINDER_EMITTER_INCLUDE "NiPSysVolumeEmitter.h" \

#define NI_P_SYS_CYLINDER_EMITTER_PARENT NiPSysVolumeEmitter \

#define NI_P_SYS_CYLINDER_EMITTER_CONSTRUCT \
 : radius(0.0f), height(0.0f) \

#define NI_P_SYS_CYLINDER_EMITTER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_CYLINDER_EMITTER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_CYLINDER_EMITTER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_CYLINDER_EMITTER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_CYLINDER_EMITTER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_DATA_MEMBERS \
vector< array<float,10> > unknownFloats4; \
bool unknownBool1; \
vector< array<byte,32> > unknownBytes; \
vector< array<byte,28> > unknownBytesAlt; \
byte unknownByte3; \
bool unknownBool2; \
vector< array<byte,4> > unknownBytes2; \
uint unknownInt1; \

#define NI_P_SYS_DATA_INCLUDE "APSysData.h" \

#define NI_P_SYS_DATA_PARENT APSysData \

#define NI_P_SYS_DATA_CONSTRUCT \
 : unknownBool1(false), unknownByte3((byte)0), unknownBool2(false), unknownInt1((uint)0) \

#define NI_P_SYS_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_DRAG_MODIFIER_MEMBERS \
NiObject * parent; \
Vector3 dragAxis; \
float percentage; \
float range; \
float rangeFalloff; \

#define NI_P_SYS_DRAG_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_DRAG_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_DRAG_MODIFIER_CONSTRUCT \
 : parent(NULL), percentage(0.0f), range(0.0f), rangeFalloff(0.0f) \

#define NI_P_SYS_DRAG_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_DRAG_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_DRAG_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_DRAG_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_DRAG_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_EMITTER_CTLR_MEMBERS \
Ref<NiPSysEmitterCtlrData > data; \
Ref<NiInterpolator > visibilityInterpolator; \

#define NI_P_SYS_EMITTER_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_CTLR_CONSTRUCT \
 : data(NULL), visibilityInterpolator(NULL) \

#define NI_P_SYS_EMITTER_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_EMITTER_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_EMITTER_CTLR_DATA_MEMBERS \
KeyGroup<float > floatKeys_; \
mutable uint numVisibilityKeys_; \
vector<Key<byte > > visibilityKeys_; \

#define NI_P_SYS_EMITTER_CTLR_DATA_INCLUDE "NiObject.h" \

#define NI_P_SYS_EMITTER_CTLR_DATA_PARENT NiObject \

#define NI_P_SYS_EMITTER_CTLR_DATA_CONSTRUCT \
 : numVisibilityKeys_((uint)0) \

#define NI_P_SYS_EMITTER_CTLR_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_SPEED_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_SPEED_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_SPEED_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_SPEED_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_GRAVITY_MODIFIER_MEMBERS \
NiNode * gravityObject; \
Vector3 gravityAxis; \
float decay; \
float strength; \
uint forceType; \
float turbulence; \
float turbulenceScale; \

#define NI_P_SYS_GRAVITY_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_GRAVITY_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_GRAVITY_MODIFIER_CONSTRUCT \
 : gravityObject(NULL), decay(0.0f), strength(0.0f), forceType((uint)0), turbulence(0.0f), turbulenceScale(1.0f) \

#define NI_P_SYS_GRAVITY_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_GRAVITY_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_MEMBERS \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_CONSTRUCT \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_GROW_FADE_MODIFIER_MEMBERS \
float growTime; \
ushort growGeneration; \
float fadeTime; \
ushort fadeGeneration; \

#define NI_P_SYS_GROW_FADE_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_GROW_FADE_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_GROW_FADE_MODIFIER_CONSTRUCT \
 : growTime(0.0f), growGeneration((ushort)0), fadeTime(0.0f), fadeGeneration((ushort)0) \

#define NI_P_SYS_GROW_FADE_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_MESH_EMITTER_MEMBERS \
mutable uint numEmitterMeshes; \
vector<Ref<NiTriBasedGeom > > emitterMeshes; \
uint initialVelocityType; \
uint emissionType; \
Vector3 emissionAxis; \

#define NI_P_SYS_MESH_EMITTER_INCLUDE "NiPSysEmitter.h" \

#define NI_P_SYS_MESH_EMITTER_PARENT NiPSysEmitter \

#define NI_P_SYS_MESH_EMITTER_CONSTRUCT \
 : numEmitterMeshes((uint)0), initialVelocityType((uint)0), emissionType((uint)0) \

#define NI_P_SYS_MESH_EMITTER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_MESH_EMITTER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_MESH_EMITTER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_MESH_EMITTER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_MESH_EMITTER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_MEMBERS \
mutable uint numMeshes; \
vector<Ref<NiNode > > meshes; \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_CONSTRUCT \
 : numMeshes((uint)0) \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_MEMBERS \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_CONSTRUCT \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_PLANAR_COLLIDER_MEMBERS \
float bounce; \
bool spawnOnCollide; \
bool dieOnCollide; \
Ref<NiPSysSpawnModifier > spawnModifier; \
NiObject * parent; \
Ref<NiObject > unknownLink_; \
Ref<NiNode > colliderObject; \
float width; \
float height; \
Vector3 xAxis; \
Vector3 yAxis; \

#define NI_P_SYS_PLANAR_COLLIDER_INCLUDE "NiObject.h" \

#define NI_P_SYS_PLANAR_COLLIDER_PARENT NiObject \

#define NI_P_SYS_PLANAR_COLLIDER_CONSTRUCT \
 : bounce(0.0f), spawnOnCollide(false), dieOnCollide(false), spawnModifier(NULL), parent(NULL), unknownLink_(NULL), colliderObject(NULL), width(0.0f), height(0.0f) \

#define NI_P_SYS_PLANAR_COLLIDER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_PLANAR_COLLIDER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_PLANAR_COLLIDER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_PLANAR_COLLIDER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_PLANAR_COLLIDER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_POSITION_MODIFIER_MEMBERS \

#define NI_P_SYS_POSITION_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_POSITION_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_POSITION_MODIFIER_CONSTRUCT \

#define NI_P_SYS_POSITION_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_POSITION_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_POSITION_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_POSITION_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_POSITION_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_MEMBERS \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_INCLUDE "NiTimeController.h" \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT NiTimeController \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_CONSTRUCT \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_ROTATION_MODIFIER_MEMBERS \
float initialRotationSpeed; \
float initialRotationSpeedVariation; \
float initialRotationAngle; \
float initialRotationAngleVariation; \
bool randomRotSpeedSign; \
bool randomInitialAxis; \
Vector3 initialAxis; \

#define NI_P_SYS_ROTATION_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_ROTATION_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_ROTATION_MODIFIER_CONSTRUCT \
 : initialRotationSpeed(0.0f), initialRotationSpeedVariation(0.0f), initialRotationAngle(0.0f), initialRotationAngleVariation(0.0f), randomRotSpeedSign(false), randomInitialAxis(false) \

#define NI_P_SYS_ROTATION_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_ROTATION_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_ROTATION_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_ROTATION_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_ROTATION_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_SPAWN_MODIFIER_MEMBERS \
ushort numSpawnGenerations; \
float percentageSpawned; \
ushort minNumToSpawn; \
ushort maxNumToSpawn; \
float spawnSpeedChaos; \
float spawnDirChaos; \
float lifeSpan; \
float lifeSpanVariation; \

#define NI_P_SYS_SPAWN_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_SPAWN_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_SPAWN_MODIFIER_CONSTRUCT \
 : numSpawnGenerations((ushort)0), percentageSpawned(0.0f), minNumToSpawn((ushort)0), maxNumToSpawn((ushort)0), spawnSpeedChaos(0.0f), spawnDirChaos(0.0f), lifeSpan(0.0f), lifeSpanVariation(0.0f) \

#define NI_P_SYS_SPAWN_MODIFIER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_SPAWN_MODIFIER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_SPAWN_MODIFIER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_SPAWN_MODIFIER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_SPAWN_MODIFIER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_SPHERE_EMITTER_MEMBERS \
float radius; \

#define NI_P_SYS_SPHERE_EMITTER_INCLUDE "NiPSysVolumeEmitter.h" \

#define NI_P_SYS_SPHERE_EMITTER_PARENT NiPSysVolumeEmitter \

#define NI_P_SYS_SPHERE_EMITTER_CONSTRUCT \
 : radius(0.0f) \

#define NI_P_SYS_SPHERE_EMITTER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_SPHERE_EMITTER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_SPHERE_EMITTER_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_SPHERE_EMITTER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_SPHERE_EMITTER_GETREFS \
return InternalGetRefs(); \

#define NI_P_SYS_UPDATE_CTLR_MEMBERS \

#define NI_P_SYS_UPDATE_CTLR_INCLUDE "NiTimeController.h" \

#define NI_P_SYS_UPDATE_CTLR_PARENT NiTimeController \

#define NI_P_SYS_UPDATE_CTLR_CONSTRUCT \

#define NI_P_SYS_UPDATE_CTLR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_P_SYS_UPDATE_CTLR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_P_SYS_UPDATE_CTLR_STRING \
return InternalAsString( verbose ); \

#define NI_P_SYS_UPDATE_CTLR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_UPDATE_CTLR_GETREFS \
return InternalGetRefs(); \

#define NI_RANGE_L_O_D_DATA_MEMBERS \
Vector3 lodCenter; \
mutable uint numLodLevels; \
vector<LODRange > lodLevels; \

#define NI_RANGE_L_O_D_DATA_INCLUDE "NiObject.h" \

#define NI_RANGE_L_O_D_DATA_PARENT NiObject \

#define NI_RANGE_L_O_D_DATA_CONSTRUCT \
 : numLodLevels((uint)0) \

#define NI_RANGE_L_O_D_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_RANGE_L_O_D_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_RANGE_L_O_D_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_RANGE_L_O_D_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_RANGE_L_O_D_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_ROTATING_PARTICLES_MEMBERS \

#define NI_ROTATING_PARTICLES_INCLUDE "NiParticles.h" \

#define NI_ROTATING_PARTICLES_PARENT NiParticles \

#define NI_ROTATING_PARTICLES_CONSTRUCT \

#define NI_ROTATING_PARTICLES_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_ROTATING_PARTICLES_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_ROTATING_PARTICLES_STRING \
return InternalAsString( verbose ); \

#define NI_ROTATING_PARTICLES_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_ROTATING_PARTICLES_GETREFS \
return InternalGetRefs(); \

#define NI_ROTATING_PARTICLES_DATA_MEMBERS \

#define NI_ROTATING_PARTICLES_DATA_INCLUDE "NiParticlesData.h" \

#define NI_ROTATING_PARTICLES_DATA_PARENT NiParticlesData \

#define NI_ROTATING_PARTICLES_DATA_CONSTRUCT \

#define NI_ROTATING_PARTICLES_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_ROTATING_PARTICLES_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_ROTATING_PARTICLES_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_ROTATING_PARTICLES_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_ROTATING_PARTICLES_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_SCREEN_L_O_D_DATA_MEMBERS \
array<float,8> unknownFloats; \
mutable uint unknownCount; \
vector<float > unknownFloats2; \

#define NI_SCREEN_L_O_D_DATA_INCLUDE "NiObject.h" \

#define NI_SCREEN_L_O_D_DATA_PARENT NiObject \

#define NI_SCREEN_L_O_D_DATA_CONSTRUCT \
 : unknownCount((uint)0) \

#define NI_SCREEN_L_O_D_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SCREEN_L_O_D_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SCREEN_L_O_D_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_SCREEN_L_O_D_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SCREEN_L_O_D_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_SEQUENCE_STREAM_HELPER_MEMBERS \

#define NI_SEQUENCE_STREAM_HELPER_INCLUDE "NiObjectNET.h" \

#define NI_SEQUENCE_STREAM_HELPER_PARENT NiObjectNET \

#define NI_SEQUENCE_STREAM_HELPER_CONSTRUCT \

#define NI_SEQUENCE_STREAM_HELPER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SEQUENCE_STREAM_HELPER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SEQUENCE_STREAM_HELPER_STRING \
return InternalAsString( verbose ); \

#define NI_SEQUENCE_STREAM_HELPER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SEQUENCE_STREAM_HELPER_GETREFS \
return InternalGetRefs(); \

#define NI_SHADE_PROPERTY_MEMBERS \
ushort flags; \

#define NI_SHADE_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_SHADE_PROPERTY_PARENT NiProperty \

#define NI_SHADE_PROPERTY_CONSTRUCT \
 : flags((ushort)0) \

#define NI_SHADE_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SHADE_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SHADE_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_SHADE_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SHADE_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_SKIN_DATA_MEMBERS \
Matrix33 rotation; \
Vector3 translation; \
float scale; \
mutable uint numBones; \
Ref<NiSkinPartition > skinPartition; \
byte unknownByte; \
vector<SkinData > boneList; \

#define NI_SKIN_DATA_INCLUDE "NiObject.h" \

#define NI_SKIN_DATA_PARENT NiObject \

#define NI_SKIN_DATA_CONSTRUCT \
 : scale(0.0f), numBones((uint)0), skinPartition(NULL), unknownByte((byte)1) \

#define NI_SKIN_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SKIN_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SKIN_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_SKIN_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SKIN_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_SKIN_INSTANCE_MEMBERS \
Ref<NiSkinData > data; \
Ref<NiSkinPartition > skinPartition; \
NiNode * skeletonRoot; \
mutable uint numBones; \
vector<NiNode * > bones; \

#define NI_SKIN_INSTANCE_INCLUDE "NiObject.h" \

#define NI_SKIN_INSTANCE_PARENT NiObject \

#define NI_SKIN_INSTANCE_CONSTRUCT \
 : data(NULL), skinPartition(NULL), skeletonRoot(NULL), numBones((uint)0) \

#define NI_SKIN_INSTANCE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SKIN_INSTANCE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SKIN_INSTANCE_STRING \
return InternalAsString( verbose ); \

#define NI_SKIN_INSTANCE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SKIN_INSTANCE_GETREFS \
return InternalGetRefs(); \

#define NI_SKIN_PARTITION_MEMBERS \
mutable uint numSkinPartitionBlocks; \
vector<SkinPartition > skinPartitionBlocks; \

#define NI_SKIN_PARTITION_INCLUDE "NiObject.h" \

#define NI_SKIN_PARTITION_PARENT NiObject \

#define NI_SKIN_PARTITION_CONSTRUCT \
 : numSkinPartitionBlocks((uint)0) \

#define NI_SKIN_PARTITION_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SKIN_PARTITION_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SKIN_PARTITION_STRING \
return InternalAsString( verbose ); \

#define NI_SKIN_PARTITION_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SKIN_PARTITION_GETREFS \
return InternalGetRefs(); \

#define NI_SOURCE_TEXTURE_MEMBERS \
byte useExternal; \
string fileName; \
Ref<NiObject > unknownLink; \
byte unknownByte; \
string originalFileName_; \
Ref<NiPixelData > pixelData; \
PixelLayout pixelLayout; \
MipMapFormat useMipmaps; \
AlphaFormat alphaFormat; \
byte unknownByte2; \

#define NI_SOURCE_TEXTURE_INCLUDE "NiObjectNET.h" \

#define NI_SOURCE_TEXTURE_PARENT NiObjectNET \

#define NI_SOURCE_TEXTURE_CONSTRUCT \
 : useExternal((byte)1), unknownLink(NULL), unknownByte((byte)0), pixelData(NULL), pixelLayout((PixelLayout)5), useMipmaps((MipMapFormat)2), alphaFormat((AlphaFormat)3), unknownByte2((byte)1) \

#define NI_SOURCE_TEXTURE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SOURCE_TEXTURE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SOURCE_TEXTURE_STRING \
return InternalAsString( verbose ); \

#define NI_SOURCE_TEXTURE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SOURCE_TEXTURE_GETREFS \
return InternalGetRefs(); \

#define NI_SPECULAR_PROPERTY_MEMBERS \
ushort flags; \

#define NI_SPECULAR_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_SPECULAR_PROPERTY_PARENT NiProperty \

#define NI_SPECULAR_PROPERTY_CONSTRUCT \
 : flags((ushort)0) \

#define NI_SPECULAR_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SPECULAR_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SPECULAR_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_SPECULAR_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SPECULAR_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_SPHERICAL_COLLIDER_MEMBERS \
float unknownFloat1; \
ushort unknownShort; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \
float unknownFloat5; \

#define NI_SPHERICAL_COLLIDER_INCLUDE "AParticleModifier.h" \

#define NI_SPHERICAL_COLLIDER_PARENT AParticleModifier \

#define NI_SPHERICAL_COLLIDER_CONSTRUCT \
 : unknownFloat1(0.0f), unknownShort((ushort)0), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownFloat4(0.0f), unknownFloat5(0.0f) \

#define NI_SPHERICAL_COLLIDER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SPHERICAL_COLLIDER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SPHERICAL_COLLIDER_STRING \
return InternalAsString( verbose ); \

#define NI_SPHERICAL_COLLIDER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SPHERICAL_COLLIDER_GETREFS \
return InternalGetRefs(); \

#define NI_SPOT_LIGHT_MEMBERS \
float cutoffAngle; \
float exponent; \

#define NI_SPOT_LIGHT_INCLUDE "NiPointLight.h" \

#define NI_SPOT_LIGHT_PARENT NiPointLight \

#define NI_SPOT_LIGHT_CONSTRUCT \
 : cutoffAngle(0.0f), exponent(0.0f) \

#define NI_SPOT_LIGHT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_SPOT_LIGHT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_SPOT_LIGHT_STRING \
return InternalAsString( verbose ); \

#define NI_SPOT_LIGHT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_SPOT_LIGHT_GETREFS \
return InternalGetRefs(); \

#define NI_STENCIL_PROPERTY_MEMBERS \
ushort flags; \
bool stencilEnabled; \
uint stencilFunction; \
uint stencilRef; \
uint stencilMask; \
uint failAction; \
uint zFailAction; \
uint passAction; \
uint drawMode; \

#define NI_STENCIL_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_STENCIL_PROPERTY_PARENT NiProperty \

#define NI_STENCIL_PROPERTY_CONSTRUCT \
 : flags((ushort)0), stencilEnabled(false), stencilFunction((uint)0), stencilRef((uint)0), stencilMask((uint)4294967295), failAction((uint)0), zFailAction((uint)0), passAction((uint)0), drawMode((uint)0) \

#define NI_STENCIL_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_STENCIL_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_STENCIL_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_STENCIL_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_STENCIL_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_STRING_EXTRA_DATA_MEMBERS \
uint bytesRemaining; \
string stringData; \

#define NI_STRING_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_STRING_EXTRA_DATA_PARENT NiExtraData \

#define NI_STRING_EXTRA_DATA_CONSTRUCT \
 : bytesRemaining((uint)0) \

#define NI_STRING_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_STRING_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_STRING_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_STRING_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_STRING_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_STRING_PALETTE_MEMBERS \
StringPalette palette; \

#define NI_STRING_PALETTE_INCLUDE "NiObject.h" \

#define NI_STRING_PALETTE_PARENT NiObject \

#define NI_STRING_PALETTE_CONSTRUCT \

#define NI_STRING_PALETTE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_STRING_PALETTE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_STRING_PALETTE_STRING \
return InternalAsString( verbose ); \

#define NI_STRING_PALETTE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_STRING_PALETTE_GETREFS \
return InternalGetRefs(); \

#define NI_STRINGS_EXTRA_DATA_MEMBERS \
mutable uint numStrings; \
vector<string > data; \

#define NI_STRINGS_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_STRINGS_EXTRA_DATA_PARENT NiExtraData \

#define NI_STRINGS_EXTRA_DATA_CONSTRUCT \
 : numStrings((uint)0) \

#define NI_STRINGS_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_STRINGS_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_STRINGS_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_STRINGS_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_STRINGS_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_TEXT_KEY_EXTRA_DATA_MEMBERS \
uint unknownInt1; \
mutable uint numTextKeys; \
vector<Key<string > > textKeys; \

#define NI_TEXT_KEY_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_TEXT_KEY_EXTRA_DATA_PARENT NiExtraData \

#define NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT \
 : unknownInt1((uint)0), numTextKeys((uint)0) \

#define NI_TEXT_KEY_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TEXT_KEY_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TEXT_KEY_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_TEXT_KEY_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TEXT_KEY_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_TEXTURE_EFFECT_MEMBERS \
Matrix33 modelProjectionMatrix; \
Vector3 modelProjectionTransform; \
uint textureFiltering; \
uint textureClamping; \
uint textureType; \
uint coordinateGenerationType; \
Ref<NiSourceTexture > sourceTexture; \
byte clippingPlane; \
Vector3 unknownVector; \
float unknownFloat; \
ushort ps2L; \
ushort ps2K; \
ushort unknownShort; \

#define NI_TEXTURE_EFFECT_INCLUDE "NiDynamicEffect.h" \

#define NI_TEXTURE_EFFECT_PARENT NiDynamicEffect \

#define NI_TEXTURE_EFFECT_CONSTRUCT \
 : textureFiltering((uint)0), textureClamping((uint)0), textureType((uint)0), coordinateGenerationType((uint)0), sourceTexture(NULL), clippingPlane((byte)0), unknownFloat(0.0f), ps2L((ushort)0), ps2K((ushort)0), unknownShort((ushort)0) \

#define NI_TEXTURE_EFFECT_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TEXTURE_EFFECT_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TEXTURE_EFFECT_STRING \
return InternalAsString( verbose ); \

#define NI_TEXTURE_EFFECT_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TEXTURE_EFFECT_GETREFS \
return InternalGetRefs(); \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_MEMBERS \
byte unknown2; \
uint textureSlot; \
uint operation; \
Ref<NiFloatData > data; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_CONSTRUCT \
 : unknown2((byte)0), textureSlot((uint)0), operation((uint)0), data(NULL) \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_TEXTURING_PROPERTY_MEMBERS \
ushort flags; \
ApplyMode applyMode; \
uint textureCount; \
bool hasBaseTexture; \
TexDesc baseTexture; \
bool hasDarkTexture; \
TexDesc darkTexture; \
bool hasDetailTexture; \
TexDesc detailTexture; \
bool hasGlossTexture; \
TexDesc glossTexture; \
bool hasGlowTexture; \
TexDesc glowTexture; \
bool hasBumpMapTexture; \
TexDesc bumpMapTexture; \
float bumpMapLumaScale; \
float bumpMapLumaOffset; \
Matrix22 bumpMapMatrix; \
bool hasDecal0Texture; \
TexDesc decal0Texture; \
bool hasDecal1Texture; \
TexDesc decal1Texture; \
mutable uint numShaderTextures; \
vector<ShaderTexDesc > shaderTextures; \

#define NI_TEXTURING_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_TEXTURING_PROPERTY_PARENT NiProperty \

#define NI_TEXTURING_PROPERTY_CONSTRUCT \
 : flags((ushort)0), applyMode((ApplyMode)2), textureCount((uint)7), hasBaseTexture(false), hasDarkTexture(false), hasDetailTexture(false), hasGlossTexture(false), hasGlowTexture(false), hasBumpMapTexture(false), bumpMapLumaScale(0.0f), bumpMapLumaOffset(0.0f), hasDecal0Texture(false), hasDecal1Texture(false), numShaderTextures((uint)0) \

#define NI_TEXTURING_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TEXTURING_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TEXTURING_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_TEXTURING_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TEXTURING_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_TRANSFORM_CONTROLLER_MEMBERS \

#define NI_TRANSFORM_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_TRANSFORM_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_TRANSFORM_CONTROLLER_CONSTRUCT \

#define NI_TRANSFORM_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRANSFORM_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRANSFORM_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_TRANSFORM_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRANSFORM_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_TRANSFORM_DATA_MEMBERS \

#define NI_TRANSFORM_DATA_INCLUDE "NiKeyframeData.h" \

#define NI_TRANSFORM_DATA_PARENT NiKeyframeData \

#define NI_TRANSFORM_DATA_CONSTRUCT \

#define NI_TRANSFORM_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRANSFORM_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRANSFORM_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_TRANSFORM_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRANSFORM_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_TRANSFORM_INTERPOLATOR_MEMBERS \
Vector3 translation; \
Quaternion rotation; \
float scale; \
array<byte,3> unknownBytes; \
Ref<NiTransformData > data; \

#define NI_TRANSFORM_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_TRANSFORM_INTERPOLATOR_PARENT NiInterpolator \

#define NI_TRANSFORM_INTERPOLATOR_CONSTRUCT \
 : scale(0.0f), data(NULL) \

#define NI_TRANSFORM_INTERPOLATOR_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRANSFORM_INTERPOLATOR_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRANSFORM_INTERPOLATOR_STRING \
return InternalAsString( verbose ); \

#define NI_TRANSFORM_INTERPOLATOR_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRANSFORM_INTERPOLATOR_GETREFS \
return InternalGetRefs(); \

#define NI_TRI_SHAPE_MEMBERS \

#define NI_TRI_SHAPE_INCLUDE "NiTriBasedGeom.h" \

#define NI_TRI_SHAPE_PARENT NiTriBasedGeom \

#define NI_TRI_SHAPE_CONSTRUCT \

#define NI_TRI_SHAPE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRI_SHAPE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRI_SHAPE_STRING \
return InternalAsString( verbose ); \

#define NI_TRI_SHAPE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_SHAPE_GETREFS \
return InternalGetRefs(); \

#define NI_TRI_SHAPE_DATA_MEMBERS \
mutable ushort numTriangles; \
uint numTrianglePoints; \
bool hasTriangles; \
vector<Triangle > triangles; \
mutable ushort numMatchGroups; \
vector<MatchGroup > matchGroups; \

#define NI_TRI_SHAPE_DATA_INCLUDE "NiTriBasedGeomData.h" \

#define NI_TRI_SHAPE_DATA_PARENT NiTriBasedGeomData \

#define NI_TRI_SHAPE_DATA_CONSTRUCT \
 : numTriangles((ushort)0), numTrianglePoints((uint)0), hasTriangles(false), numMatchGroups((ushort)0) \

#define NI_TRI_SHAPE_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRI_SHAPE_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRI_SHAPE_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_TRI_SHAPE_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_SHAPE_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_TRI_STRIPS_MEMBERS \

#define NI_TRI_STRIPS_INCLUDE "NiTriBasedGeom.h" \

#define NI_TRI_STRIPS_PARENT NiTriBasedGeom \

#define NI_TRI_STRIPS_CONSTRUCT \

#define NI_TRI_STRIPS_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRI_STRIPS_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRI_STRIPS_STRING \
return InternalAsString( verbose ); \

#define NI_TRI_STRIPS_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_STRIPS_GETREFS \
return InternalGetRefs(); \

#define NI_TRI_STRIPS_DATA_MEMBERS \
ushort numTriangles; \
mutable ushort numStrips; \
mutable vector<ushort > stripLengths; \
bool hasPoints; \
vector<vector<ushort > > points; \

#define NI_TRI_STRIPS_DATA_INCLUDE "NiTriBasedGeomData.h" \

#define NI_TRI_STRIPS_DATA_PARENT NiTriBasedGeomData \

#define NI_TRI_STRIPS_DATA_CONSTRUCT \
 : numTriangles((ushort)0), numStrips((ushort)0), hasPoints(false) \

#define NI_TRI_STRIPS_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_TRI_STRIPS_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_TRI_STRIPS_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_TRI_STRIPS_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_STRIPS_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_U_V_CONTROLLER_MEMBERS \
ushort unknownShort; \
Ref<NiUVData > data; \

#define NI_U_V_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_U_V_CONTROLLER_PARENT NiTimeController \

#define NI_U_V_CONTROLLER_CONSTRUCT \
 : unknownShort((ushort)0), data(NULL) \

#define NI_U_V_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_U_V_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_U_V_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_U_V_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_U_V_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_U_V_DATA_MEMBERS \
array<KeyGroup<float >,4> uvGroups; \

#define NI_U_V_DATA_INCLUDE "NiObject.h" \

#define NI_U_V_DATA_PARENT NiObject \

#define NI_U_V_DATA_CONSTRUCT \

#define NI_U_V_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_U_V_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_U_V_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_U_V_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_U_V_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_VECTOR_EXTRA_DATA_MEMBERS \
Vector3 vectorData; \
float unknownFloat; \

#define NI_VECTOR_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_VECTOR_EXTRA_DATA_PARENT NiExtraData \

#define NI_VECTOR_EXTRA_DATA_CONSTRUCT \
 : unknownFloat(0.0f) \

#define NI_VECTOR_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_VECTOR_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_VECTOR_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_VECTOR_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_VECTOR_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_VERTEX_COLOR_PROPERTY_MEMBERS \
ushort flags; \
VertMode vertexMode; \
LightMode lightingMode; \

#define NI_VERTEX_COLOR_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_VERTEX_COLOR_PROPERTY_PARENT NiProperty \

#define NI_VERTEX_COLOR_PROPERTY_CONSTRUCT \
 : flags((ushort)0), vertexMode((VertMode)0), lightingMode((LightMode)0) \

#define NI_VERTEX_COLOR_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_VERTEX_COLOR_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_VERTEX_COLOR_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_VERTEX_COLOR_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_VERTEX_COLOR_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS \
uint numBytes; \
mutable ushort numVertices; \
vector<float > weight; \

#define NI_VERT_WEIGHTS_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_VERT_WEIGHTS_EXTRA_DATA_PARENT NiExtraData \

#define NI_VERT_WEIGHTS_EXTRA_DATA_CONSTRUCT \
 : numBytes((uint)0), numVertices((ushort)0) \

#define NI_VERT_WEIGHTS_EXTRA_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_VIS_CONTROLLER_MEMBERS \
Ref<NiVisData > data; \

#define NI_VIS_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_VIS_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_VIS_CONTROLLER_CONSTRUCT \
 : data(NULL) \

#define NI_VIS_CONTROLLER_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_VIS_CONTROLLER_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_VIS_CONTROLLER_STRING \
return InternalAsString( verbose ); \

#define NI_VIS_CONTROLLER_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_VIS_CONTROLLER_GETREFS \
return InternalGetRefs(); \

#define NI_VIS_DATA_MEMBERS \
mutable uint numVisKeys; \
vector<Key<byte > > visKeys; \

#define NI_VIS_DATA_INCLUDE "AKeyedData.h" \

#define NI_VIS_DATA_PARENT AKeyedData \

#define NI_VIS_DATA_CONSTRUCT \
 : numVisKeys((uint)0) \

#define NI_VIS_DATA_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_VIS_DATA_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_VIS_DATA_STRING \
return InternalAsString( verbose ); \

#define NI_VIS_DATA_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_VIS_DATA_GETREFS \
return InternalGetRefs(); \

#define NI_WIREFRAME_PROPERTY_MEMBERS \
ushort flags; \

#define NI_WIREFRAME_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_WIREFRAME_PROPERTY_PARENT NiProperty \

#define NI_WIREFRAME_PROPERTY_CONSTRUCT \
 : flags((ushort)0) \

#define NI_WIREFRAME_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_WIREFRAME_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_WIREFRAME_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_WIREFRAME_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_WIREFRAME_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define NI_Z_BUFFER_PROPERTY_MEMBERS \
ushort flags; \
uint function; \

#define NI_Z_BUFFER_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_Z_BUFFER_PROPERTY_PARENT NiProperty \

#define NI_Z_BUFFER_PROPERTY_CONSTRUCT \
 : flags((ushort)3), function((uint)3) \

#define NI_Z_BUFFER_PROPERTY_READ \
InternalRead( in, link_stack, version, user_version ); \

#define NI_Z_BUFFER_PROPERTY_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define NI_Z_BUFFER_PROPERTY_STRING \
return InternalAsString( verbose ); \

#define NI_Z_BUFFER_PROPERTY_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define NI_Z_BUFFER_PROPERTY_GETREFS \
return InternalGetRefs(); \

#define ROOT_COLLISION_NODE_MEMBERS \

#define ROOT_COLLISION_NODE_INCLUDE "NiNode.h" \

#define ROOT_COLLISION_NODE_PARENT NiNode \

#define ROOT_COLLISION_NODE_CONSTRUCT \

#define ROOT_COLLISION_NODE_READ \
InternalRead( in, link_stack, version, user_version ); \

#define ROOT_COLLISION_NODE_WRITE \
InternalWrite( out, link_map, version, user_version ); \

#define ROOT_COLLISION_NODE_STRING \
return InternalAsString( verbose ); \

#define ROOT_COLLISION_NODE_FIXLINKS \
InternalFixLinks( objects, link_stack, version, user_version ); \

#define ROOT_COLLISION_NODE_GETREFS \
return InternalGetRefs(); \

#endif
