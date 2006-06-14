/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _OBJ_DEFINES_H_
#define _OBJ_DEFINES_H_

#define MAXARRAYDUMP 20

#define NI_OBJECT_MEMBERS \

#define NI_OBJECT_INCLUDE ".h" \

#define NI_OBJECT_PARENT \

#define NI_OBJECT_CONSTRUCT \

#define NI_OBJECT_READ \

#define NI_OBJECT_WRITE \

#define NI_OBJECT_STRING \
stringstream out; \
return out.str(); \

#define NI_OBJECT_FIXLINKS \

#define NI_OBJECT_GETREFS \
list<Ref<NiObject> > refs; \
return refs; \

#define A_KEYED_DATA_MEMBERS \

#define A_KEYED_DATA_INCLUDE "NiObject.h" \

#define A_KEYED_DATA_PARENT NiObject \

#define A_KEYED_DATA_CONSTRUCT \

#define A_KEYED_DATA_READ \
NiObject::Read( in, link_stack, version, user_version ); \

#define A_KEYED_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \

#define A_KEYED_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
return out.str(); \

#define A_KEYED_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define A_KEYED_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define A_PARTICLE_MODIFIER_MEMBERS \
Ref<AParticleModifier > nextModifier; \
NiParticleSystemController * controller; \

#define A_PARTICLE_MODIFIER_INCLUDE "NiObject.h" \

#define A_PARTICLE_MODIFIER_PARENT NiObject \

#define A_PARTICLE_MODIFIER_CONSTRUCT \
 : nextModifier(NULL), controller(NULL) \

#define A_PARTICLE_MODIFIER_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define A_PARTICLE_MODIFIER_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
if ( nextModifier != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(nextModifier)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( controller != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(controller)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define A_PARTICLE_MODIFIER_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Next Modifier:  " << nextModifier << endl; \
out << "Controller:  " << controller << endl; \
return out.str(); \

#define A_PARTICLE_MODIFIER_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	nextModifier = DynamicCast<AParticleModifier>(objects[link_stack.front()]); \
	if ( nextModifier == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	nextModifier = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	controller = DynamicCast<NiParticleSystemController>(objects[link_stack.front()]); \
	if ( controller == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	controller = NULL; \
link_stack.pop_front(); \

#define A_PARTICLE_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( nextModifier != NULL ) \
	refs.push_back(StaticCast<NiObject>(nextModifier)); \
return refs; \

#define BHK_REF_OBJECT_MEMBERS \

#define BHK_REF_OBJECT_INCLUDE "NiObject.h" \

#define BHK_REF_OBJECT_PARENT NiObject \

#define BHK_REF_OBJECT_CONSTRUCT \

#define BHK_REF_OBJECT_READ \
NiObject::Read( in, link_stack, version, user_version ); \

#define BHK_REF_OBJECT_WRITE \
NiObject::Write( out, link_map, version, user_version ); \

#define BHK_REF_OBJECT_STRING \
stringstream out; \
out << NiObject::asString(); \
return out.str(); \

#define BHK_REF_OBJECT_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_REF_OBJECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define BHK_SERIALIZABLE_MEMBERS \

#define BHK_SERIALIZABLE_INCLUDE "bhkRefObject.h" \

#define BHK_SERIALIZABLE_PARENT bhkRefObject \

#define BHK_SERIALIZABLE_CONSTRUCT \

#define BHK_SERIALIZABLE_READ \
bhkRefObject::Read( in, link_stack, version, user_version ); \

#define BHK_SERIALIZABLE_WRITE \
bhkRefObject::Write( out, link_map, version, user_version ); \

#define BHK_SERIALIZABLE_STRING \
stringstream out; \
out << bhkRefObject::asString(); \
return out.str(); \

#define BHK_SERIALIZABLE_FIXLINKS \
bhkRefObject::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_SERIALIZABLE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkRefObject::GetRefs(); \
return refs; \

#define ABHK_CONSTRAINT_MEMBERS \
uint numBodies; \
vector<bhkShape * > bodies; \
uint priority; \

#define ABHK_CONSTRAINT_INCLUDE "bhkSerializable.h" \

#define ABHK_CONSTRAINT_PARENT bhkSerializable \

#define ABHK_CONSTRAINT_CONSTRUCT \
 : numBodies((uint)0), priority((uint)1) \

#define ABHK_CONSTRAINT_READ \
uint block_num; \
bhkSerializable::Read( in, link_stack, version, user_version ); \
NifStream( numBodies, in, version ); \
bodies.resize(numBodies); \
for (uint i0 = 0; i0 < bodies.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( priority, in, version ); \

#define ABHK_CONSTRAINT_WRITE \
bhkSerializable::Write( out, link_map, version, user_version ); \
NifStream( numBodies, out, version ); \
for (uint i0 = 0; i0 < bodies.size(); i0++) { \
	if ( bodies[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(bodies[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
NifStream( priority, out, version ); \

#define ABHK_CONSTRAINT_STRING \
stringstream out; \
out << bhkSerializable::asString(); \
out << "Num Bodies:  " << numBodies << endl; \
for (uint i0 = 0; i0 < bodies.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Bodies[" << i0 << "]:  " << bodies[i0] << endl; \
}; \
out << "Priority:  " << priority << endl; \
return out.str(); \

#define ABHK_CONSTRAINT_FIXLINKS \
bhkSerializable::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < bodies.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		bodies[i0] = DynamicCast<bhkShape>(objects[link_stack.front()]); \
		if ( bodies[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		bodies[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define ABHK_CONSTRAINT_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkSerializable::GetRefs(); \
for (uint i0 = 0; i0 < bodies.size(); i0++) { \
}; \
return refs; \

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
AbhkConstraint::Read( in, link_stack, version, user_version ); \
NifStream( pivotA, in, version ); \
NifStream( planeA, in, version ); \
NifStream( twistA, in, version ); \
NifStream( pivotB, in, version ); \
NifStream( planeB, in, version ); \
NifStream( twistB, in, version ); \
NifStream( coneMinAngle, in, version ); \
NifStream( planeMinAngle, in, version ); \
NifStream( planeMaxAngle, in, version ); \
NifStream( twistMinAngle, in, version ); \
NifStream( twistMaxAngle, in, version ); \
NifStream( maxFriction, in, version ); \

#define ABHK_RAGDOLL_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, link_map, version, user_version ); \
NifStream( pivotA, out, version ); \
NifStream( planeA, out, version ); \
NifStream( twistA, out, version ); \
NifStream( pivotB, out, version ); \
NifStream( planeB, out, version ); \
NifStream( twistB, out, version ); \
NifStream( coneMinAngle, out, version ); \
NifStream( planeMinAngle, out, version ); \
NifStream( planeMaxAngle, out, version ); \
NifStream( twistMinAngle, out, version ); \
NifStream( twistMaxAngle, out, version ); \
NifStream( maxFriction, out, version ); \

#define ABHK_RAGDOLL_CONSTRAINT_STRING \
stringstream out; \
out << AbhkConstraint::asString(); \
out << "Pivot A:  " << pivotA << endl; \
out << "Plane A:  " << planeA << endl; \
out << "Twist A:  " << twistA << endl; \
out << "Pivot B:  " << pivotB << endl; \
out << "Plane B:  " << planeB << endl; \
out << "Twist B:  " << twistB << endl; \
out << "Cone Min Angle:  " << coneMinAngle << endl; \
out << "Plane Min Angle:  " << planeMinAngle << endl; \
out << "Plane Max Angle:  " << planeMaxAngle << endl; \
out << "Twist Min Angle:  " << twistMinAngle << endl; \
out << "Twist Max Angle:  " << twistMaxAngle << endl; \
out << "Max Friction:  " << maxFriction << endl; \
return out.str(); \

#define ABHK_RAGDOLL_CONSTRAINT_FIXLINKS \
AbhkConstraint::FixLinks( objects, link_stack, version, user_version ); \

#define ABHK_RAGDOLL_CONSTRAINT_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkConstraint::GetRefs(); \
return refs; \

#define BHK_SHAPE_MEMBERS \

#define BHK_SHAPE_INCLUDE "bhkSerializable.h" \

#define BHK_SHAPE_PARENT bhkSerializable \

#define BHK_SHAPE_CONSTRUCT \

#define BHK_SHAPE_READ \
bhkSerializable::Read( in, link_stack, version, user_version ); \

#define BHK_SHAPE_WRITE \
bhkSerializable::Write( out, link_map, version, user_version ); \

#define BHK_SHAPE_STRING \
stringstream out; \
out << bhkSerializable::asString(); \
return out.str(); \

#define BHK_SHAPE_FIXLINKS \
bhkSerializable::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkSerializable::GetRefs(); \
return refs; \

#define ABHK_SHAPE_COLLECTION_MEMBERS \

#define ABHK_SHAPE_COLLECTION_INCLUDE "bhkShape.h" \

#define ABHK_SHAPE_COLLECTION_PARENT bhkShape \

#define ABHK_SHAPE_COLLECTION_CONSTRUCT \

#define ABHK_SHAPE_COLLECTION_READ \
bhkShape::Read( in, link_stack, version, user_version ); \

#define ABHK_SHAPE_COLLECTION_WRITE \
bhkShape::Write( out, link_map, version, user_version ); \

#define ABHK_SHAPE_COLLECTION_STRING \
stringstream out; \
out << bhkShape::asString(); \
return out.str(); \

#define ABHK_SHAPE_COLLECTION_FIXLINKS \
bhkShape::FixLinks( objects, link_stack, version, user_version ); \

#define ABHK_SHAPE_COLLECTION_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkShape::GetRefs(); \
return refs; \

#define BHK_SPHERE_REP_SHAPE_MEMBERS \
uint material; \

#define BHK_SPHERE_REP_SHAPE_INCLUDE "bhkShape.h" \

#define BHK_SPHERE_REP_SHAPE_PARENT bhkShape \

#define BHK_SPHERE_REP_SHAPE_CONSTRUCT \
 : material((uint)0) \

#define BHK_SPHERE_REP_SHAPE_READ \
bhkShape::Read( in, link_stack, version, user_version ); \
NifStream( material, in, version ); \

#define BHK_SPHERE_REP_SHAPE_WRITE \
bhkShape::Write( out, link_map, version, user_version ); \
NifStream( material, out, version ); \

#define BHK_SPHERE_REP_SHAPE_STRING \
stringstream out; \
out << bhkShape::asString(); \
out << "Material:  " << material << endl; \
return out.str(); \

#define BHK_SPHERE_REP_SHAPE_FIXLINKS \
bhkShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_SPHERE_REP_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkShape::GetRefs(); \
return refs; \

#define BHK_CONVEX_SHAPE_MEMBERS \

#define BHK_CONVEX_SHAPE_INCLUDE "bhkSphereRepShape.h" \

#define BHK_CONVEX_SHAPE_PARENT bhkSphereRepShape \

#define BHK_CONVEX_SHAPE_CONSTRUCT \

#define BHK_CONVEX_SHAPE_READ \
bhkSphereRepShape::Read( in, link_stack, version, user_version ); \

#define BHK_CONVEX_SHAPE_WRITE \
bhkSphereRepShape::Write( out, link_map, version, user_version ); \

#define BHK_CONVEX_SHAPE_STRING \
stringstream out; \
out << bhkSphereRepShape::asString(); \
return out.str(); \

#define BHK_CONVEX_SHAPE_FIXLINKS \
bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_CONVEX_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkSphereRepShape::GetRefs(); \
return refs; \

#define BHK_WORLD_OBJECT_MEMBERS \

#define BHK_WORLD_OBJECT_INCLUDE "bhkShape.h" \

#define BHK_WORLD_OBJECT_PARENT bhkShape \

#define BHK_WORLD_OBJECT_CONSTRUCT \

#define BHK_WORLD_OBJECT_READ \
bhkShape::Read( in, link_stack, version, user_version ); \

#define BHK_WORLD_OBJECT_WRITE \
bhkShape::Write( out, link_map, version, user_version ); \

#define BHK_WORLD_OBJECT_STRING \
stringstream out; \
out << bhkShape::asString(); \
return out.str(); \

#define BHK_WORLD_OBJECT_FIXLINKS \
bhkShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_WORLD_OBJECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkShape::GetRefs(); \
return refs; \

#define BHK_ENTITY_MEMBERS \
Ref<bhkShape > shape; \
uint layer; \

#define BHK_ENTITY_INCLUDE "bhkWorldObject.h" \

#define BHK_ENTITY_PARENT bhkWorldObject \

#define BHK_ENTITY_CONSTRUCT \
 : shape(NULL), layer((uint)0) \

#define BHK_ENTITY_READ \
uint block_num; \
bhkWorldObject::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( layer, in, version ); \

#define BHK_ENTITY_WRITE \
bhkWorldObject::Write( out, link_map, version, user_version ); \
if ( shape != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(shape)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( layer, out, version ); \

#define BHK_ENTITY_STRING \
stringstream out; \
out << bhkWorldObject::asString(); \
out << "Shape:  " << shape << endl; \
out << "Layer:  " << layer << endl; \
return out.str(); \

#define BHK_ENTITY_FIXLINKS \
bhkWorldObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	shape = DynamicCast<bhkShape>(objects[link_stack.front()]); \
	if ( shape == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	shape = NULL; \
link_stack.pop_front(); \

#define BHK_ENTITY_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkWorldObject::GetRefs(); \
if ( shape != NULL ) \
	refs.push_back(StaticCast<NiObject>(shape)); \
return refs; \

#define NI_COLLISION_OBJECT_MEMBERS \
NiAVObject * parent; \
ushort unknownShort; \
Ref<NiObject > body; \

#define NI_COLLISION_OBJECT_INCLUDE "NiObject.h" \

#define NI_COLLISION_OBJECT_PARENT NiObject \

#define NI_COLLISION_OBJECT_CONSTRUCT \
 : parent(NULL), unknownShort((ushort)0), body(NULL) \

#define NI_COLLISION_OBJECT_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( unknownShort, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_COLLISION_OBJECT_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
if ( parent != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(parent)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( unknownShort, out, version ); \
if ( body != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(body)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_COLLISION_OBJECT_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Parent:  " << parent << endl; \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Body:  " << body << endl; \
return out.str(); \

#define NI_COLLISION_OBJECT_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	parent = DynamicCast<NiAVObject>(objects[link_stack.front()]); \
	if ( parent == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	parent = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	body = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( body == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	body = NULL; \
link_stack.pop_front(); \

#define NI_COLLISION_OBJECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( body != NULL ) \
	refs.push_back(StaticCast<NiObject>(body)); \
return refs; \

#define NI_EXTRA_DATA_MEMBERS \
string name; \
Ref<NiExtraData > nextExtraData; \

#define NI_EXTRA_DATA_INCLUDE "NiObject.h" \

#define NI_EXTRA_DATA_PARENT NiObject \

#define NI_EXTRA_DATA_CONSTRUCT \
 : nextExtraData(NULL) \

#define NI_EXTRA_DATA_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A000100 ) { \
	NifStream( name, in, version ); \
}; \
if ( version <= 0x04020200 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_EXTRA_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A000100 ) { \
	NifStream( name, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
	if ( nextExtraData != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(nextExtraData)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_EXTRA_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Name:  " << name << endl; \
out << "Next Extra Data:  " << nextExtraData << endl; \
return out.str(); \

#define NI_EXTRA_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x04020200 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		nextExtraData = DynamicCast<NiExtraData>(objects[link_stack.front()]); \
		if ( nextExtraData == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		nextExtraData = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( nextExtraData != NULL ) \
	refs.push_back(StaticCast<NiObject>(nextExtraData)); \
return refs; \

#define NI_INTERPOLATOR_MEMBERS \

#define NI_INTERPOLATOR_INCLUDE "NiObject.h" \

#define NI_INTERPOLATOR_PARENT NiObject \

#define NI_INTERPOLATOR_CONSTRUCT \

#define NI_INTERPOLATOR_READ \
NiObject::Read( in, link_stack, version, user_version ); \

#define NI_INTERPOLATOR_WRITE \
NiObject::Write( out, link_map, version, user_version ); \

#define NI_INTERPOLATOR_STRING \
stringstream out; \
out << NiObject::asString(); \
return out.str(); \

#define NI_INTERPOLATOR_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_BLEND_INTERPOLATOR_MEMBERS \
ushort unknownShort; \
uint unknownInt; \

#define NI_BLEND_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_BLEND_INTERPOLATOR_PARENT NiInterpolator \

#define NI_BLEND_INTERPOLATOR_CONSTRUCT \
 : unknownShort((ushort)0), unknownInt((uint)0) \

#define NI_BLEND_INTERPOLATOR_READ \
NiInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( unknownShort, in, version ); \
NifStream( unknownInt, in, version ); \

#define NI_BLEND_INTERPOLATOR_WRITE \
NiInterpolator::Write( out, link_map, version, user_version ); \
NifStream( unknownShort, out, version ); \
NifStream( unknownInt, out, version ); \

#define NI_BLEND_INTERPOLATOR_STRING \
stringstream out; \
out << NiInterpolator::asString(); \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Unknown Int:  " << unknownInt << endl; \
return out.str(); \

#define NI_BLEND_INTERPOLATOR_FIXLINKS \
NiInterpolator::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiInterpolator::GetRefs(); \
return refs; \

#define NI_B_SPLINE_INTERPOLATOR_MEMBERS \
float startTime; \
float stopTime; \

#define NI_B_SPLINE_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_B_SPLINE_INTERPOLATOR_PARENT NiInterpolator \

#define NI_B_SPLINE_INTERPOLATOR_CONSTRUCT \
 : startTime(0.0f), stopTime(0.0f) \

#define NI_B_SPLINE_INTERPOLATOR_READ \
NiInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( startTime, in, version ); \
NifStream( stopTime, in, version ); \

#define NI_B_SPLINE_INTERPOLATOR_WRITE \
NiInterpolator::Write( out, link_map, version, user_version ); \
NifStream( startTime, out, version ); \
NifStream( stopTime, out, version ); \

#define NI_B_SPLINE_INTERPOLATOR_STRING \
stringstream out; \
out << NiInterpolator::asString(); \
out << "Start Time:  " << startTime << endl; \
out << "Stop Time:  " << stopTime << endl; \
return out.str(); \

#define NI_B_SPLINE_INTERPOLATOR_FIXLINKS \
NiInterpolator::FixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiInterpolator::GetRefs(); \
return refs; \

#define NI_OBJECT_N_E_T_MEMBERS \
string name; \
Ref<NiExtraData > extraData; \
uint numExtraDataList; \
vector<Ref<NiExtraData > > extraDataList; \
Ref<NiTimeController > controller; \

#define NI_OBJECT_N_E_T_INCLUDE "NiObject.h" \

#define NI_OBJECT_N_E_T_PARENT NiObject \

#define NI_OBJECT_N_E_T_CONSTRUCT \
 : extraData(NULL), numExtraDataList((uint)0), controller(NULL) \

#define NI_OBJECT_N_E_T_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( name, in, version ); \
if ( version <= 0x04020200 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
if ( version >= 0x0A000100 ) { \
	NifStream( numExtraDataList, in, version ); \
	extraDataList.resize(numExtraDataList); \
	for (uint i1 = 0; i1 < extraDataList.size(); i1++) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_OBJECT_N_E_T_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( name, out, version ); \
if ( version <= 0x04020200 ) { \
	if ( extraData != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(extraData)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( version >= 0x0A000100 ) { \
	NifStream( numExtraDataList, out, version ); \
	for (uint i1 = 0; i1 < extraDataList.size(); i1++) { \
		if ( extraDataList[i1] != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(extraDataList[i1])], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \
if ( controller != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(controller)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_OBJECT_N_E_T_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Name:  " << name << endl; \
out << "Extra Data:  " << extraData << endl; \
out << "Num Extra Data List:  " << numExtraDataList << endl; \
for (uint i0 = 0; i0 < extraDataList.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Extra Data List[" << i0 << "]:  " << extraDataList[i0] << endl; \
}; \
out << "Controller:  " << controller << endl; \
return out.str(); \

#define NI_OBJECT_N_E_T_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x04020200 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		extraData = DynamicCast<NiExtraData>(objects[link_stack.front()]); \
		if ( extraData == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		extraData = NULL; \
	link_stack.pop_front(); \
}; \
if ( version >= 0x0A000100 ) { \
	for (uint i1 = 0; i1 < extraDataList.size(); i1++) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			extraDataList[i1] = DynamicCast<NiExtraData>(objects[link_stack.front()]); \
			if ( extraDataList[i1] == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			extraDataList[i1] = NULL; \
		link_stack.pop_front(); \
	}; \
}; \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	controller = DynamicCast<NiTimeController>(objects[link_stack.front()]); \
	if ( controller == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	controller = NULL; \
link_stack.pop_front(); \

#define NI_OBJECT_N_E_T_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( extraData != NULL ) \
	refs.push_back(StaticCast<NiObject>(extraData)); \
for (uint i0 = 0; i0 < extraDataList.size(); i0++) { \
	if ( extraDataList[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(extraDataList[i0])); \
}; \
if ( controller != NULL ) \
	refs.push_back(StaticCast<NiObject>(controller)); \
return refs; \

#define NI_A_V_OBJECT_MEMBERS \
ushort flags; \
Vector3 translation; \
Matrix33 rotation; \
float scale; \
Vector3 velocity; \
uint numProperties; \
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
uint block_num; \
NiObjectNET::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \
NifStream( translation, in, version ); \
NifStream( rotation, in, version ); \
NifStream( scale, in, version ); \
if ( version <= 0x04020200 ) { \
	NifStream( velocity, in, version ); \
}; \
NifStream( numProperties, in, version ); \
properties.resize(numProperties); \
for (uint i0 = 0; i0 < properties.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
if ( version <= 0x04020200 ) { \
	NifStream( hasBoundingBox, in, version ); \
	if ( (hasBoundingBox != 0) ) { \
		NifStream( boundingBox.unknownInt, in, version ); \
		NifStream( boundingBox.translation, in, version ); \
		NifStream( boundingBox.rotation, in, version ); \
		NifStream( boundingBox.radius, in, version ); \
	}; \
}; \
if ( ( version >= 0x0A000100 ) && ( version <= 0x0A020000 ) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
if ( version >= 0x14000004 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_A_V_OBJECT_WRITE \
NiObjectNET::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \
NifStream( translation, out, version ); \
NifStream( rotation, out, version ); \
NifStream( scale, out, version ); \
if ( version <= 0x04020200 ) { \
	NifStream( velocity, out, version ); \
}; \
NifStream( numProperties, out, version ); \
for (uint i0 = 0; i0 < properties.size(); i0++) { \
	if ( properties[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(properties[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
	NifStream( hasBoundingBox, out, version ); \
	if ( (hasBoundingBox != 0) ) { \
		NifStream( boundingBox.unknownInt, out, version ); \
		NifStream( boundingBox.translation, out, version ); \
		NifStream( boundingBox.rotation, out, version ); \
		NifStream( boundingBox.radius, out, version ); \
	}; \
}; \
if ( ( version >= 0x0A000100 ) && ( version <= 0x0A020000 ) ) { \
	if ( collisionData != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(collisionData)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
	if ( collisionObject != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(collisionObject)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_A_V_OBJECT_STRING \
stringstream out; \
out << NiObjectNET::asString(); \
out << "Flags:  " << flags << endl; \
out << "Translation:  " << translation << endl; \
out << "Rotation:  " << rotation << endl; \
out << "Scale:  " << scale << endl; \
out << "Velocity:  " << velocity << endl; \
out << "Num Properties:  " << numProperties << endl; \
for (uint i0 = 0; i0 < properties.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Properties[" << i0 << "]:  " << properties[i0] << endl; \
}; \
out << "Has Bounding Box:  " << hasBoundingBox << endl; \
if ( (hasBoundingBox != 0) ) { \
	out << "  Unknown Int:  " << boundingBox.unknownInt << endl; \
	out << "  Translation:  " << boundingBox.translation << endl; \
	out << "  Rotation:  " << boundingBox.rotation << endl; \
	out << "  Radius:  " << boundingBox.radius << endl; \
}; \
out << "Collision Data:  " << collisionData << endl; \
out << "Collision Object:  " << collisionObject << endl; \
return out.str(); \

#define NI_A_V_OBJECT_FIXLINKS \
NiObjectNET::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < properties.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		properties[i0] = DynamicCast<NiProperty>(objects[link_stack.front()]); \
		if ( properties[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		properties[i0] = NULL; \
	link_stack.pop_front(); \
}; \
if ( ( version >= 0x0A000100 ) && ( version <= 0x0A020000 ) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		collisionData = DynamicCast<NiCollisionData>(objects[link_stack.front()]); \
		if ( collisionData == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		collisionData = NULL; \
	link_stack.pop_front(); \
}; \
if ( version >= 0x14000004 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		collisionObject = DynamicCast<NiCollisionObject>(objects[link_stack.front()]); \
		if ( collisionObject == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		collisionObject = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_A_V_OBJECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObjectNET::GetRefs(); \
for (uint i0 = 0; i0 < properties.size(); i0++) { \
	if ( properties[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(properties[i0])); \
}; \
if ( collisionData != NULL ) \
	refs.push_back(StaticCast<NiObject>(collisionData)); \
if ( collisionObject != NULL ) \
	refs.push_back(StaticCast<NiObject>(collisionObject)); \
return refs; \

#define NI_DYNAMIC_EFFECT_MEMBERS \
bool hasAffectedNodeList_; \
uint affectedNodeList_; \
bool switchState; \
uint numAffectedNodes; \
vector<Ref<NiAVObject > > affectedNodes; \

#define NI_DYNAMIC_EFFECT_INCLUDE "NiAVObject.h" \

#define NI_DYNAMIC_EFFECT_PARENT NiAVObject \

#define NI_DYNAMIC_EFFECT_CONSTRUCT \
 : hasAffectedNodeList_(false), affectedNodeList_((uint)0), switchState(false), numAffectedNodes((uint)0) \

#define NI_DYNAMIC_EFFECT_READ \
uint block_num; \
NiAVObject::Read( in, link_stack, version, user_version ); \
if ( version <= 0x04000002 ) { \
	NifStream( hasAffectedNodeList_, in, version ); \
	if ( (hasAffectedNodeList_ != 0) ) { \
		NifStream( affectedNodeList_, in, version ); \
	}; \
}; \
if ( version >= 0x0A020000 ) { \
	NifStream( switchState, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
	NifStream( numAffectedNodes, in, version ); \
	affectedNodes.resize(numAffectedNodes); \
	for (uint i1 = 0; i1 < affectedNodes.size(); i1++) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \

#define NI_DYNAMIC_EFFECT_WRITE \
NiAVObject::Write( out, link_map, version, user_version ); \
if ( version <= 0x04000002 ) { \
	NifStream( hasAffectedNodeList_, out, version ); \
	if ( (hasAffectedNodeList_ != 0) ) { \
		NifStream( affectedNodeList_, out, version ); \
	}; \
}; \
if ( version >= 0x0A020000 ) { \
	NifStream( switchState, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
	NifStream( numAffectedNodes, out, version ); \
	for (uint i1 = 0; i1 < affectedNodes.size(); i1++) { \
		if ( affectedNodes[i1] != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(affectedNodes[i1])], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \

#define NI_DYNAMIC_EFFECT_STRING \
stringstream out; \
out << NiAVObject::asString(); \
out << "Has Affected Node List?:  " << hasAffectedNodeList_ << endl; \
if ( (hasAffectedNodeList_ != 0) ) { \
	out << "  Affected Node List?:  " << affectedNodeList_ << endl; \
}; \
out << "Switch State:  " << switchState << endl; \
out << "Num Affected Nodes:  " << numAffectedNodes << endl; \
for (uint i0 = 0; i0 < affectedNodes.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Affected Nodes[" << i0 << "]:  " << affectedNodes[i0] << endl; \
}; \
return out.str(); \

#define NI_DYNAMIC_EFFECT_FIXLINKS \
NiAVObject::FixLinks( objects, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	for (uint i1 = 0; i1 < affectedNodes.size(); i1++) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			affectedNodes[i1] = DynamicCast<NiAVObject>(objects[link_stack.front()]); \
			if ( affectedNodes[i1] == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			affectedNodes[i1] = NULL; \
		link_stack.pop_front(); \
	}; \
}; \

#define NI_DYNAMIC_EFFECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiAVObject::GetRefs(); \
for (uint i0 = 0; i0 < affectedNodes.size(); i0++) { \
	if ( affectedNodes[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(affectedNodes[i0])); \
}; \
return refs; \

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
NiDynamicEffect::Read( in, link_stack, version, user_version ); \
NifStream( dimmer, in, version ); \
NifStream( ambientColor, in, version ); \
NifStream( diffuseColor, in, version ); \
NifStream( specularColor, in, version ); \

#define NI_LIGHT_WRITE \
NiDynamicEffect::Write( out, link_map, version, user_version ); \
NifStream( dimmer, out, version ); \
NifStream( ambientColor, out, version ); \
NifStream( diffuseColor, out, version ); \
NifStream( specularColor, out, version ); \

#define NI_LIGHT_STRING \
stringstream out; \
out << NiDynamicEffect::asString(); \
out << "Dimmer:  " << dimmer << endl; \
out << "Ambient Color:  " << ambientColor << endl; \
out << "Diffuse Color:  " << diffuseColor << endl; \
out << "Specular Color:  " << specularColor << endl; \
return out.str(); \

#define NI_LIGHT_FIXLINKS \
NiDynamicEffect::FixLinks( objects, link_stack, version, user_version ); \

#define NI_LIGHT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiDynamicEffect::GetRefs(); \
return refs; \

#define NI_PROPERTY_MEMBERS \

#define NI_PROPERTY_INCLUDE "NiObjectNET.h" \

#define NI_PROPERTY_PARENT NiObjectNET \

#define NI_PROPERTY_CONSTRUCT \

#define NI_PROPERTY_READ \
NiObjectNET::Read( in, link_stack, version, user_version ); \

#define NI_PROPERTY_WRITE \
NiObjectNET::Write( out, link_map, version, user_version ); \

#define NI_PROPERTY_STRING \
stringstream out; \
out << NiObjectNET::asString(); \
return out.str(); \

#define NI_PROPERTY_FIXLINKS \
NiObjectNET::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObjectNET::GetRefs(); \
return refs; \

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
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( name, in, version ); \
NifStream( order, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( active, in, version ); \

#define NI_P_SYS_MODIFIER_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( name, out, version ); \
NifStream( order, out, version ); \
if ( target != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(target)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( active, out, version ); \

#define NI_P_SYS_MODIFIER_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Name:  " << name << endl; \
out << "Order:  " << order << endl; \
out << "Target:  " << target << endl; \
out << "Active:  " << active << endl; \
return out.str(); \

#define NI_P_SYS_MODIFIER_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	target = DynamicCast<NiParticleSystem>(objects[link_stack.front()]); \
	if ( target == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	target = NULL; \
link_stack.pop_front(); \

#define NI_P_SYS_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

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
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( speed, in, version ); \
NifStream( speedVariation, in, version ); \
NifStream( declination, in, version ); \
NifStream( declinationVariation, in, version ); \
NifStream( planarAngle, in, version ); \
NifStream( planarAngleVariation, in, version ); \
NifStream( initialColor, in, version ); \
NifStream( initialRadius, in, version ); \
NifStream( radiusVariation, in, version ); \
NifStream( lifeSpan, in, version ); \
NifStream( lifeSpanVariation, in, version ); \

#define NI_P_SYS_EMITTER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
NifStream( speed, out, version ); \
NifStream( speedVariation, out, version ); \
NifStream( declination, out, version ); \
NifStream( declinationVariation, out, version ); \
NifStream( planarAngle, out, version ); \
NifStream( planarAngleVariation, out, version ); \
NifStream( initialColor, out, version ); \
NifStream( initialRadius, out, version ); \
NifStream( radiusVariation, out, version ); \
NifStream( lifeSpan, out, version ); \
NifStream( lifeSpanVariation, out, version ); \

#define NI_P_SYS_EMITTER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Speed:  " << speed << endl; \
out << "Speed Variation:  " << speedVariation << endl; \
out << "Declination:  " << declination << endl; \
out << "Declination Variation:  " << declinationVariation << endl; \
out << "Planar Angle:  " << planarAngle << endl; \
out << "Planar Angle Variation:  " << planarAngleVariation << endl; \
out << "Initial Color:  " << initialColor << endl; \
out << "Initial Radius:  " << initialRadius << endl; \
out << "Radius Variation:  " << radiusVariation << endl; \
out << "Life Span:  " << lifeSpan << endl; \
out << "Life Span Variation:  " << lifeSpanVariation << endl; \
return out.str(); \

#define NI_P_SYS_EMITTER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define NI_P_SYS_VOLUME_EMITTER_MEMBERS \
NiNode * emitterObject; \

#define NI_P_SYS_VOLUME_EMITTER_INCLUDE "NiPSysEmitter.h" \

#define NI_P_SYS_VOLUME_EMITTER_PARENT NiPSysEmitter \

#define NI_P_SYS_VOLUME_EMITTER_CONSTRUCT \
 : emitterObject(NULL) \

#define NI_P_SYS_VOLUME_EMITTER_READ \
uint block_num; \
NiPSysEmitter::Read( in, link_stack, version, user_version ); \
if ( version >= 0x14000004 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_P_SYS_VOLUME_EMITTER_WRITE \
NiPSysEmitter::Write( out, link_map, version, user_version ); \
if ( version >= 0x14000004 ) { \
	if ( emitterObject != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(emitterObject)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_P_SYS_VOLUME_EMITTER_STRING \
stringstream out; \
out << NiPSysEmitter::asString(); \
out << "Emitter Object:  " << emitterObject << endl; \
return out.str(); \

#define NI_P_SYS_VOLUME_EMITTER_FIXLINKS \
NiPSysEmitter::FixLinks( objects, link_stack, version, user_version ); \
if ( version >= 0x14000004 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		emitterObject = DynamicCast<NiNode>(objects[link_stack.front()]); \
		if ( emitterObject == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		emitterObject = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_P_SYS_VOLUME_EMITTER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysEmitter::GetRefs(); \
return refs; \

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
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( flags, in, version ); \
NifStream( frequency, in, version ); \
NifStream( phase, in, version ); \
NifStream( startTime, in, version ); \
NifStream( stopTime, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_TIME_CONTROLLER_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
if ( nextController != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(nextController)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( flags, out, version ); \
NifStream( frequency, out, version ); \
NifStream( phase, out, version ); \
NifStream( startTime, out, version ); \
NifStream( stopTime, out, version ); \
if ( target != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(target)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_TIME_CONTROLLER_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Next Controller:  " << nextController << endl; \
out << "Flags:  " << flags << endl; \
out << "Frequency:  " << frequency << endl; \
out << "Phase:  " << phase << endl; \
out << "Start Time:  " << startTime << endl; \
out << "Stop Time:  " << stopTime << endl; \
out << "Target:  " << target << endl; \
return out.str(); \

#define NI_TIME_CONTROLLER_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	nextController = DynamicCast<NiTimeController>(objects[link_stack.front()]); \
	if ( nextController == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	nextController = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	target = DynamicCast<NiObjectNET>(objects[link_stack.front()]); \
	if ( target == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	target = NULL; \
link_stack.pop_front(); \

#define NI_TIME_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( nextController != NULL ) \
	refs.push_back(StaticCast<NiObject>(nextController)); \
return refs; \

#define A_BONE_L_O_D_CONTROLLER_MEMBERS \
uint unknownInt1; \
uint numNodeGroups; \
uint unknownInt2; \
vector<NodeGroup > nodeGroups; \

#define A_BONE_L_O_D_CONTROLLER_INCLUDE "NiTimeController.h" \

#define A_BONE_L_O_D_CONTROLLER_PARENT NiTimeController \

#define A_BONE_L_O_D_CONTROLLER_CONSTRUCT \
 : unknownInt1((uint)0), numNodeGroups((uint)0), unknownInt2((uint)0) \

#define A_BONE_L_O_D_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
NifStream( unknownInt1, in, version ); \
NifStream( numNodeGroups, in, version ); \
NifStream( unknownInt2, in, version ); \
nodeGroups.resize(numNodeGroups); \
for (uint i0 = 0; i0 < nodeGroups.size(); i0++) { \
	NifStream( nodeGroups[i0].numNodes, in, version ); \
	nodeGroups[i0].nodes.resize(nodeGroups[i0].numNodes); \
	for (uint i1 = 0; i1 < nodeGroups[i0].nodes.size(); i1++) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \

#define A_BONE_L_O_D_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
NifStream( unknownInt1, out, version ); \
NifStream( numNodeGroups, out, version ); \
NifStream( unknownInt2, out, version ); \
for (uint i0 = 0; i0 < nodeGroups.size(); i0++) { \
	NifStream( nodeGroups[i0].numNodes, out, version ); \
	for (uint i1 = 0; i1 < nodeGroups[i0].nodes.size(); i1++) { \
		if ( nodeGroups[i0].nodes[i1] != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(nodeGroups[i0].nodes[i1])], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \

#define A_BONE_L_O_D_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown Int 1:  " << unknownInt1 << endl; \
out << "Num Node Groups:  " << numNodeGroups << endl; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
for (uint i0 = 0; i0 < nodeGroups.size(); i0++) { \
	out << "  Num Nodes:  " << nodeGroups[i0].numNodes << endl; \
	for (uint i1 = 0; i1 < nodeGroups[i0].nodes.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Nodes[" << i1 << "]:  " << nodeGroups[i0].nodes[i1] << endl; \
	}; \
}; \
return out.str(); \

#define A_BONE_L_O_D_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < nodeGroups.size(); i0++) { \
	for (uint i1 = 0; i1 < nodeGroups[i0].nodes.size(); i1++) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			nodeGroups[i0].nodes[i1] = DynamicCast<NiNode>(objects[link_stack.front()]); \
			if ( nodeGroups[i0].nodes[i1] == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			nodeGroups[i0].nodes[i1] = NULL; \
		link_stack.pop_front(); \
	}; \
}; \

#define A_BONE_L_O_D_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
for (uint i0 = 0; i0 < nodeGroups.size(); i0++) { \
	for (uint i1 = 0; i1 < nodeGroups[i0].nodes.size(); i1++) { \
		if ( nodeGroups[i0].nodes[i1] != NULL ) \
			refs.push_back(StaticCast<NiObject>(nodeGroups[i0].nodes[i1])); \
	}; \
}; \
return refs; \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_MEMBERS \
Ref<NiInterpolator > interpolator; \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_PARENT NiTimeController \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_CONSTRUCT \
 : interpolator(NULL) \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A020000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A020000 ) { \
	if ( interpolator != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(interpolator)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Interpolator:  " << interpolator << endl; \
return out.str(); \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if ( version >= 0x0A020000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		interpolator = DynamicCast<NiInterpolator>(objects[link_stack.front()]); \
		if ( interpolator == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		interpolator = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( interpolator != NULL ) \
	refs.push_back(StaticCast<NiObject>(interpolator)); \
return refs; \

#define A_P_SYS_CTLR_MEMBERS \
string modifierName; \

#define A_P_SYS_CTLR_INCLUDE "NiSingleInterpolatorController.h" \

#define A_P_SYS_CTLR_PARENT NiSingleInterpolatorController \

#define A_P_SYS_CTLR_CONSTRUCT \

#define A_P_SYS_CTLR_READ \
NiSingleInterpolatorController::Read( in, link_stack, version, user_version ); \
NifStream( modifierName, in, version ); \

#define A_P_SYS_CTLR_WRITE \
NiSingleInterpolatorController::Write( out, link_map, version, user_version ); \
NifStream( modifierName, out, version ); \

#define A_P_SYS_CTLR_STRING \
stringstream out; \
out << NiSingleInterpolatorController::asString(); \
out << "Modifier Name:  " << modifierName << endl; \
return out.str(); \

#define A_P_SYS_CTLR_FIXLINKS \
NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version ); \

#define A_P_SYS_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiSingleInterpolatorController::GetRefs(); \
return refs; \

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
uint block_num; \
NiAVObject::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
if ( version >= 0x0A000100 ) { \
	NifStream( hasShader, in, version ); \
	if ( (hasShader != 0) ) { \
		NifStream( shaderName, in, version ); \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \

#define NI_TRI_BASED_GEOM_WRITE \
NiAVObject::Write( out, link_map, version, user_version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( skinInstance != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(skinInstance)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( version >= 0x0A000100 ) { \
	NifStream( hasShader, out, version ); \
	if ( (hasShader != 0) ) { \
		NifStream( shaderName, out, version ); \
		if ( unknownLink != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \

#define NI_TRI_BASED_GEOM_STRING \
stringstream out; \
out << NiAVObject::asString(); \
out << "Data:  " << data << endl; \
out << "Skin Instance:  " << skinInstance << endl; \
out << "Has Shader:  " << hasShader << endl; \
if ( (hasShader != 0) ) { \
	out << "  Shader Name:  " << shaderName << endl; \
	out << "  Unknown Link:  " << unknownLink << endl; \
}; \
return out.str(); \

#define NI_TRI_BASED_GEOM_FIXLINKS \
NiAVObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiTriBasedGeomData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	skinInstance = DynamicCast<NiSkinInstance>(objects[link_stack.front()]); \
	if ( skinInstance == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	skinInstance = NULL; \
link_stack.pop_front(); \
if ( version >= 0x0A000100 ) { \
	if ( (hasShader != 0) ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]); \
			if ( unknownLink == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			unknownLink = NULL; \
		link_stack.pop_front(); \
	}; \
}; \

#define NI_TRI_BASED_GEOM_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiAVObject::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
if ( skinInstance != NULL ) \
	refs.push_back(StaticCast<NiObject>(skinInstance)); \
if ( unknownLink != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink)); \
return refs; \

#define NI_TRI_BASED_GEOM_DATA_MEMBERS \
string name; \
ushort numVertices; \
ushort unknownShort1; \
bool hasVertices; \
vector<Vector3 > vertices; \
byte numUvSets2; \
byte unknownByte; \
bool hasNormals; \
vector<Vector3 > normals; \
vector<Vector3 > unknownVectors1; \
vector<Vector3 > unknownVectors2; \
Vector3 center; \
float radius; \
bool hasVertexColors; \
vector<Color4 > vertexColors; \
ushort numUvSets; \
bool hasUv; \
vector<vector<TexCoord > > uvSets; \
ushort unknownShort2; \
Ref<NiObject > unknownLink; \

#define NI_TRI_BASED_GEOM_DATA_INCLUDE "NiObject.h" \

#define NI_TRI_BASED_GEOM_DATA_PARENT NiObject \

#define NI_TRI_BASED_GEOM_DATA_CONSTRUCT \
 : numVertices((ushort)0), unknownShort1((ushort)0), hasVertices(false), numUvSets2((byte)0), unknownByte((byte)0), hasNormals(false), radius(0.0f), hasVertexColors(false), numUvSets((ushort)0), hasUv(false), unknownShort2((ushort)0), unknownLink(NULL) \

#define NI_TRI_BASED_GEOM_DATA_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A020000 ) { \
	NifStream( name, in, version ); \
}; \
NifStream( numVertices, in, version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknownShort1, in, version ); \
}; \
NifStream( hasVertices, in, version ); \
if ( (hasVertices != 0) ) { \
	vertices.resize(numVertices); \
	for (uint i1 = 0; i1 < vertices.size(); i1++) { \
		NifStream( vertices[i1], in, version ); \
	}; \
}; \
if ( version >= 0x0A000100 ) { \
	NifStream( numUvSets2, in, version ); \
	NifStream( unknownByte, in, version ); \
}; \
NifStream( hasNormals, in, version ); \
if ( (hasNormals != 0) ) { \
	normals.resize(numVertices); \
	for (uint i1 = 0; i1 < normals.size(); i1++) { \
		NifStream( normals[i1], in, version ); \
	}; \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) { \
		unknownVectors1.resize(numVertices); \
		for (uint i2 = 0; i2 < unknownVectors1.size(); i2++) { \
			NifStream( unknownVectors1[i2], in, version ); \
		}; \
		unknownVectors2.resize(numVertices); \
		for (uint i2 = 0; i2 < unknownVectors2.size(); i2++) { \
			NifStream( unknownVectors2[i2], in, version ); \
		}; \
	}; \
}; \
NifStream( center, in, version ); \
NifStream( radius, in, version ); \
NifStream( hasVertexColors, in, version ); \
if ( (hasVertexColors != 0) ) { \
	vertexColors.resize(numVertices); \
	for (uint i1 = 0; i1 < vertexColors.size(); i1++) { \
		NifStream( vertexColors[i1], in, version ); \
	}; \
}; \
if ( version <= 0x04020200 ) { \
	NifStream( numUvSets, in, version ); \
}; \
if ( version <= 0x04000002 ) { \
	NifStream( hasUv, in, version ); \
}; \
if ( version <= 0x04020200 ) { \
	uvSets.resize(numUvSets); \
	for (uint i1 = 0; i1 < uvSets.size(); i1++) { \
		uvSets[i1].resize(numVertices); \
		for (uint i2 = 0; i2 < uvSets[i1].size(); i2++) { \
			NifStream( uvSets[i1][i2], in, version ); \
		}; \
	}; \
}; \
if ( version >= 0x0A000100 ) { \
	uvSets.resize((numUvSets2 & 63)); \
	for (uint i1 = 0; i1 < uvSets.size(); i1++) { \
		uvSets[i1].resize(numVertices); \
		for (uint i2 = 0; i2 < uvSets[i1].size(); i2++) { \
			NifStream( uvSets[i1][i2], in, version ); \
		}; \
	}; \
	NifStream( unknownShort2, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_TRI_BASED_GEOM_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A020000 ) { \
	NifStream( name, out, version ); \
}; \
NifStream( numVertices, out, version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknownShort1, out, version ); \
}; \
NifStream( hasVertices, out, version ); \
if ( (hasVertices != 0) ) { \
	for (uint i1 = 0; i1 < vertices.size(); i1++) { \
		NifStream( vertices[i1], out, version ); \
	}; \
}; \
if ( version >= 0x0A000100 ) { \
	NifStream( numUvSets2, out, version ); \
	NifStream( unknownByte, out, version ); \
}; \
NifStream( hasNormals, out, version ); \
if ( (hasNormals != 0) ) { \
	for (uint i1 = 0; i1 < normals.size(); i1++) { \
		NifStream( normals[i1], out, version ); \
	}; \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) { \
		for (uint i2 = 0; i2 < unknownVectors1.size(); i2++) { \
			NifStream( unknownVectors1[i2], out, version ); \
		}; \
		for (uint i2 = 0; i2 < unknownVectors2.size(); i2++) { \
			NifStream( unknownVectors2[i2], out, version ); \
		}; \
	}; \
}; \
NifStream( center, out, version ); \
NifStream( radius, out, version ); \
NifStream( hasVertexColors, out, version ); \
if ( (hasVertexColors != 0) ) { \
	for (uint i1 = 0; i1 < vertexColors.size(); i1++) { \
		NifStream( vertexColors[i1], out, version ); \
	}; \
}; \
if ( version <= 0x04020200 ) { \
	NifStream( numUvSets, out, version ); \
}; \
if ( version <= 0x04000002 ) { \
	NifStream( hasUv, out, version ); \
}; \
if ( version <= 0x04020200 ) { \
	for (uint i1 = 0; i1 < uvSets.size(); i1++) { \
		for (uint i2 = 0; i2 < uvSets[i1].size(); i2++) { \
			NifStream( uvSets[i1][i2], out, version ); \
		}; \
	}; \
}; \
if ( version >= 0x0A000100 ) { \
	for (uint i1 = 0; i1 < uvSets.size(); i1++) { \
		for (uint i2 = 0; i2 < uvSets[i1].size(); i2++) { \
			NifStream( uvSets[i1][i2], out, version ); \
		}; \
	}; \
	NifStream( unknownShort2, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
	if ( unknownLink != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_TRI_BASED_GEOM_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Name:  " << name << endl; \
out << "Num Vertices:  " << numVertices << endl; \
out << "Unknown Short 1:  " << unknownShort1 << endl; \
out << "Has Vertices:  " << hasVertices << endl; \
if ( (hasVertices != 0) ) { \
	for (uint i1 = 0; i1 < vertices.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Vertices[" << i1 << "]:  " << vertices[i1] << endl; \
	}; \
}; \
out << "Num UV Sets 2:  " << numUvSets2 << endl; \
out << "Unknown Byte:  " << unknownByte << endl; \
out << "Has Normals:  " << hasNormals << endl; \
if ( (hasNormals != 0) ) { \
	for (uint i1 = 0; i1 < normals.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Normals[" << i1 << "]:  " << normals[i1] << endl; \
	}; \
}; \
if ( (((hasNormals != 0)) && ((unknownByte & 16))) ) { \
	for (uint i1 = 0; i1 < unknownVectors1.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Vectors 1[" << i1 << "]:  " << unknownVectors1[i1] << endl; \
	}; \
	for (uint i1 = 0; i1 < unknownVectors2.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Vectors 2[" << i1 << "]:  " << unknownVectors2[i1] << endl; \
	}; \
}; \
out << "Center:  " << center << endl; \
out << "Radius:  " << radius << endl; \
out << "Has Vertex Colors:  " << hasVertexColors << endl; \
if ( (hasVertexColors != 0) ) { \
	for (uint i1 = 0; i1 < vertexColors.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Vertex Colors[" << i1 << "]:  " << vertexColors[i1] << endl; \
	}; \
}; \
out << "Num UV Sets:  " << numUvSets << endl; \
out << "Has UV:  " << hasUv << endl; \
for (uint i0 = 0; i0 < uvSets.size(); i0++) { \
	for (uint i1 = 0; i1 < uvSets[i0].size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    UV Sets[" << i0 << "][" << i1 << "]:  " << uvSets[i0][i1] << endl; \
	}; \
}; \
out << "Unknown Short 2:  " << unknownShort2 << endl; \
out << "Unknown Link:  " << unknownLink << endl; \
return out.str(); \

#define NI_TRI_BASED_GEOM_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if ( version >= 0x14000004 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]); \
		if ( unknownLink == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		unknownLink = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_TRI_BASED_GEOM_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( unknownLink != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink)); \
return refs; \

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
NiTriBasedGeomData::Read( in, link_stack, version, user_version ); \
NifStream( hasUnknownFloats1, in, version ); \
if ( (hasUnknownFloats1 != 0) ) { \
	unknownFloats1.resize(numVertices); \
	for (uint i1 = 0; i1 < unknownFloats1.size(); i1++) { \
		NifStream( unknownFloats1[i1], in, version ); \
	}; \
}; \
NifStream( unknownShort3, in, version ); \
NifStream( hasUnknownFloats2, in, version ); \
if ( (hasUnknownFloats2 != 0) ) { \
	unknownFloats2.resize(numVertices); \
	for (uint i1 = 0; i1 < unknownFloats2.size(); i1++) { \
		NifStream( unknownFloats2[i1], in, version ); \
	}; \
}; \
NifStream( unknownByte1, in, version ); \

#define A_P_SYS_DATA_WRITE \
NiTriBasedGeomData::Write( out, link_map, version, user_version ); \
NifStream( hasUnknownFloats1, out, version ); \
if ( (hasUnknownFloats1 != 0) ) { \
	for (uint i1 = 0; i1 < unknownFloats1.size(); i1++) { \
		NifStream( unknownFloats1[i1], out, version ); \
	}; \
}; \
NifStream( unknownShort3, out, version ); \
NifStream( hasUnknownFloats2, out, version ); \
if ( (hasUnknownFloats2 != 0) ) { \
	for (uint i1 = 0; i1 < unknownFloats2.size(); i1++) { \
		NifStream( unknownFloats2[i1], out, version ); \
	}; \
}; \
NifStream( unknownByte1, out, version ); \

#define A_P_SYS_DATA_STRING \
stringstream out; \
out << NiTriBasedGeomData::asString(); \
out << "Has Unknown Floats 1:  " << hasUnknownFloats1 << endl; \
if ( (hasUnknownFloats1 != 0) ) { \
	for (uint i1 = 0; i1 < unknownFloats1.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats 1[" << i1 << "]:  " << unknownFloats1[i1] << endl; \
	}; \
}; \
out << "Unknown Short 3:  " << unknownShort3 << endl; \
out << "Has Unknown Floats 2:  " << hasUnknownFloats2 << endl; \
if ( (hasUnknownFloats2 != 0) ) { \
	for (uint i1 = 0; i1 < unknownFloats2.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats 2[" << i1 << "]:  " << unknownFloats2[i1] << endl; \
	}; \
}; \
out << "Unknown Byte 1:  " << unknownByte1 << endl; \
return out.str(); \

#define A_P_SYS_DATA_FIXLINKS \
NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version ); \

#define A_P_SYS_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTriBasedGeomData::GetRefs(); \
return refs; \

#define BHK_BLEND_COLLISION_OBJECT_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \

#define BHK_BLEND_COLLISION_OBJECT_INCLUDE "NiCollisionObject.h" \

#define BHK_BLEND_COLLISION_OBJECT_PARENT NiCollisionObject \

#define BHK_BLEND_COLLISION_OBJECT_CONSTRUCT \
 : unknownFloat1(0.0f), unknownFloat2(0.0f) \

#define BHK_BLEND_COLLISION_OBJECT_READ \
NiCollisionObject::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \

#define BHK_BLEND_COLLISION_OBJECT_WRITE \
NiCollisionObject::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \

#define BHK_BLEND_COLLISION_OBJECT_STRING \
stringstream out; \
out << NiCollisionObject::asString(); \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
return out.str(); \

#define BHK_BLEND_COLLISION_OBJECT_FIXLINKS \
NiCollisionObject::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_BLEND_COLLISION_OBJECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiCollisionObject::GetRefs(); \
return refs; \

#define BHK_BLEND_CONTROLLER_MEMBERS \
uint unknownInt; \

#define BHK_BLEND_CONTROLLER_INCLUDE "NiTimeController.h" \

#define BHK_BLEND_CONTROLLER_PARENT NiTimeController \

#define BHK_BLEND_CONTROLLER_CONSTRUCT \
 : unknownInt((uint)0) \

#define BHK_BLEND_CONTROLLER_READ \
NiTimeController::Read( in, link_stack, version, user_version ); \
NifStream( unknownInt, in, version ); \

#define BHK_BLEND_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
NifStream( unknownInt, out, version ); \

#define BHK_BLEND_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown Int:  " << unknownInt << endl; \
return out.str(); \

#define BHK_BLEND_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_BLEND_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
return refs; \

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
bhkConvexShape::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownShort1, in, version ); \
NifStream( unknownShort2, in, version ); \
NifStream( unknownShort3, in, version ); \
NifStream( unknownShort4, in, version ); \
NifStream( dimensions, in, version ); \
NifStream( unknownFloat2, in, version ); \

#define BHK_BOX_SHAPE_WRITE \
bhkConvexShape::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownShort1, out, version ); \
NifStream( unknownShort2, out, version ); \
NifStream( unknownShort3, out, version ); \
NifStream( unknownShort4, out, version ); \
NifStream( dimensions, out, version ); \
NifStream( unknownFloat2, out, version ); \

#define BHK_BOX_SHAPE_STRING \
stringstream out; \
out << bhkConvexShape::asString(); \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Short 1:  " << unknownShort1 << endl; \
out << "Unknown Short 2:  " << unknownShort2 << endl; \
out << "Unknown Short 3:  " << unknownShort3 << endl; \
out << "Unknown Short 4:  " << unknownShort4 << endl; \
out << "Dimensions:  " << dimensions << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
return out.str(); \

#define BHK_BOX_SHAPE_FIXLINKS \
bhkConvexShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_BOX_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkConvexShape::GetRefs(); \
return refs; \

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
bhkConvexShape::Read( in, link_stack, version, user_version ); \
NifStream( radius, in, version ); \
NifStream( unknownShort1, in, version ); \
NifStream( unknownShort2, in, version ); \
NifStream( unknownShort3, in, version ); \
NifStream( unknownShort4, in, version ); \
NifStream( firstPoint, in, version ); \
NifStream( radius1, in, version ); \
NifStream( secondPoint, in, version ); \
NifStream( radius2, in, version ); \

#define BHK_CAPSULE_SHAPE_WRITE \
bhkConvexShape::Write( out, link_map, version, user_version ); \
NifStream( radius, out, version ); \
NifStream( unknownShort1, out, version ); \
NifStream( unknownShort2, out, version ); \
NifStream( unknownShort3, out, version ); \
NifStream( unknownShort4, out, version ); \
NifStream( firstPoint, out, version ); \
NifStream( radius1, out, version ); \
NifStream( secondPoint, out, version ); \
NifStream( radius2, out, version ); \

#define BHK_CAPSULE_SHAPE_STRING \
stringstream out; \
out << bhkConvexShape::asString(); \
out << "Radius:  " << radius << endl; \
out << "Unknown Short 1:  " << unknownShort1 << endl; \
out << "Unknown Short 2:  " << unknownShort2 << endl; \
out << "Unknown Short 3:  " << unknownShort3 << endl; \
out << "Unknown Short 4:  " << unknownShort4 << endl; \
out << "First Point:  " << firstPoint << endl; \
out << "Radius 1:  " << radius1 << endl; \
out << "Second Point:  " << secondPoint << endl; \
out << "Radius 2:  " << radius2 << endl; \
return out.str(); \

#define BHK_CAPSULE_SHAPE_FIXLINKS \
bhkConvexShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_CAPSULE_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkConvexShape::GetRefs(); \
return refs; \

#define BHK_COLLISION_OBJECT_MEMBERS \

#define BHK_COLLISION_OBJECT_INCLUDE "NiCollisionObject.h" \

#define BHK_COLLISION_OBJECT_PARENT NiCollisionObject \

#define BHK_COLLISION_OBJECT_CONSTRUCT \

#define BHK_COLLISION_OBJECT_READ \
NiCollisionObject::Read( in, link_stack, version, user_version ); \

#define BHK_COLLISION_OBJECT_WRITE \
NiCollisionObject::Write( out, link_map, version, user_version ); \

#define BHK_COLLISION_OBJECT_STRING \
stringstream out; \
out << NiCollisionObject::asString(); \
return out.str(); \

#define BHK_COLLISION_OBJECT_FIXLINKS \
NiCollisionObject::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_COLLISION_OBJECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiCollisionObject::GetRefs(); \
return refs; \

#define BHK_CONVEX_VERTICES_SHAPE_MEMBERS \
float unknownFloats1[7]; \
uint num1; \
vector<Float4 > unknownVectors1; \
uint num2; \
vector<Float4 > unknownVectors2; \

#define BHK_CONVEX_VERTICES_SHAPE_INCLUDE "bhkSphereRepShape.h" \

#define BHK_CONVEX_VERTICES_SHAPE_PARENT bhkSphereRepShape \

#define BHK_CONVEX_VERTICES_SHAPE_CONSTRUCT \
 : num1((uint)0), num2((uint)0) \

#define BHK_CONVEX_VERTICES_SHAPE_READ \
bhkSphereRepShape::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 7; i0++) { \
	NifStream( unknownFloats1[i0], in, version ); \
}; \
NifStream( num1, in, version ); \
unknownVectors1.resize(num1); \
for (uint i0 = 0; i0 < unknownVectors1.size(); i0++) { \
	NifStream( unknownVectors1[i0], in, version ); \
}; \
NifStream( num2, in, version ); \
unknownVectors2.resize(num2); \
for (uint i0 = 0; i0 < unknownVectors2.size(); i0++) { \
	NifStream( unknownVectors2[i0], in, version ); \
}; \

#define BHK_CONVEX_VERTICES_SHAPE_WRITE \
bhkSphereRepShape::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 7; i0++) { \
	NifStream( unknownFloats1[i0], out, version ); \
}; \
NifStream( num1, out, version ); \
for (uint i0 = 0; i0 < unknownVectors1.size(); i0++) { \
	NifStream( unknownVectors1[i0], out, version ); \
}; \
NifStream( num2, out, version ); \
for (uint i0 = 0; i0 < unknownVectors2.size(); i0++) { \
	NifStream( unknownVectors2[i0], out, version ); \
}; \

#define BHK_CONVEX_VERTICES_SHAPE_STRING \
stringstream out; \
out << bhkSphereRepShape::asString(); \
for (uint i0 = 0; i0 < 7; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats 1[" << i0 << "]:  " << unknownFloats1[i0] << endl; \
}; \
out << "Num 1:  " << num1 << endl; \
for (uint i0 = 0; i0 < unknownVectors1.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Vectors 1[" << i0 << "]:  " << unknownVectors1[i0] << endl; \
}; \
out << "Num 2:  " << num2 << endl; \
for (uint i0 = 0; i0 < unknownVectors2.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Vectors 2[" << i0 << "]:  " << unknownVectors2[i0] << endl; \
}; \
return out.str(); \

#define BHK_CONVEX_VERTICES_SHAPE_FIXLINKS \
bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_CONVEX_VERTICES_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkSphereRepShape::GetRefs(); \
return refs; \

#define BHK_HINGE_CONSTRAINT_MEMBERS \
float unknownFloats[5][4]; \

#define BHK_HINGE_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_HINGE_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_HINGE_CONSTRAINT_CONSTRUCT \

#define BHK_HINGE_CONSTRAINT_READ \
AbhkConstraint::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 5; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		NifStream( unknownFloats[i0][i1], in, version ); \
	}; \
}; \

#define BHK_HINGE_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 5; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		NifStream( unknownFloats[i0][i1], out, version ); \
	}; \
}; \

#define BHK_HINGE_CONSTRAINT_STRING \
stringstream out; \
out << AbhkConstraint::asString(); \
for (uint i0 = 0; i0 < 5; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats[" << i0 << "][" << i1 << "]:  " << unknownFloats[i0][i1] << endl; \
	}; \
}; \
return out.str(); \

#define BHK_HINGE_CONSTRAINT_FIXLINKS \
AbhkConstraint::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_HINGE_CONSTRAINT_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkConstraint::GetRefs(); \
return refs; \

#define BHK_LIMITED_HINGE_CONSTRAINT_MEMBERS \
LimitedHingeDescriptor limitedHinge; \

#define BHK_LIMITED_HINGE_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_LIMITED_HINGE_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_LIMITED_HINGE_CONSTRAINT_CONSTRUCT \

#define BHK_LIMITED_HINGE_CONSTRAINT_READ \
AbhkConstraint::Read( in, link_stack, version, user_version ); \
NifStream( limitedHinge.pivotA, in, version ); \
NifStream( limitedHinge.axleA_, in, version ); \
NifStream( limitedHinge.perp2axleina1, in, version ); \
NifStream( limitedHinge.perp2axleina2, in, version ); \
NifStream( limitedHinge.pivotB, in, version ); \
NifStream( limitedHinge.axleB, in, version ); \
NifStream( limitedHinge.unknownVector, in, version ); \
NifStream( limitedHinge.minAngle, in, version ); \
NifStream( limitedHinge.maxAngle, in, version ); \
NifStream( limitedHinge.maxFriction, in, version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, link_map, version, user_version ); \
NifStream( limitedHinge.pivotA, out, version ); \
NifStream( limitedHinge.axleA_, out, version ); \
NifStream( limitedHinge.perp2axleina1, out, version ); \
NifStream( limitedHinge.perp2axleina2, out, version ); \
NifStream( limitedHinge.pivotB, out, version ); \
NifStream( limitedHinge.axleB, out, version ); \
NifStream( limitedHinge.unknownVector, out, version ); \
NifStream( limitedHinge.minAngle, out, version ); \
NifStream( limitedHinge.maxAngle, out, version ); \
NifStream( limitedHinge.maxFriction, out, version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_STRING \
stringstream out; \
out << AbhkConstraint::asString(); \
out << "Pivot A:  " << limitedHinge.pivotA << endl; \
out << "Axle A ?:  " << limitedHinge.axleA_ << endl; \
out << "Perp2AxleInA1:  " << limitedHinge.perp2axleina1 << endl; \
out << "Perp2AxleInA2:  " << limitedHinge.perp2axleina2 << endl; \
out << "Pivot B:  " << limitedHinge.pivotB << endl; \
out << "Axle B:  " << limitedHinge.axleB << endl; \
out << "Unknown Vector:  " << limitedHinge.unknownVector << endl; \
out << "Min Angle:  " << limitedHinge.minAngle << endl; \
out << "Max Angle:  " << limitedHinge.maxAngle << endl; \
out << "Max Friction:  " << limitedHinge.maxFriction << endl; \
return out.str(); \

#define BHK_LIMITED_HINGE_CONSTRAINT_FIXLINKS \
AbhkConstraint::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_LIMITED_HINGE_CONSTRAINT_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkConstraint::GetRefs(); \
return refs; \

#define BHK_LIST_SHAPE_MEMBERS \
uint numSubShapes; \
vector<Ref<bhkShape > > subShapes; \
uint material; \
float unknownFloats[6]; \
uint numUnknownInts; \
vector<uint > unknownInts; \

#define BHK_LIST_SHAPE_INCLUDE "AbhkShapeCollection.h" \

#define BHK_LIST_SHAPE_PARENT AbhkShapeCollection \

#define BHK_LIST_SHAPE_CONSTRUCT \
 : numSubShapes((uint)0), material((uint)0), numUnknownInts((uint)0) \

#define BHK_LIST_SHAPE_READ \
uint block_num; \
AbhkShapeCollection::Read( in, link_stack, version, user_version ); \
NifStream( numSubShapes, in, version ); \
subShapes.resize(numSubShapes); \
for (uint i0 = 0; i0 < subShapes.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( material, in, version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownFloats[i0], in, version ); \
}; \
NifStream( numUnknownInts, in, version ); \
unknownInts.resize(numUnknownInts); \
for (uint i0 = 0; i0 < unknownInts.size(); i0++) { \
	NifStream( unknownInts[i0], in, version ); \
}; \

#define BHK_LIST_SHAPE_WRITE \
AbhkShapeCollection::Write( out, link_map, version, user_version ); \
NifStream( numSubShapes, out, version ); \
for (uint i0 = 0; i0 < subShapes.size(); i0++) { \
	if ( subShapes[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(subShapes[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
NifStream( material, out, version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownFloats[i0], out, version ); \
}; \
NifStream( numUnknownInts, out, version ); \
for (uint i0 = 0; i0 < unknownInts.size(); i0++) { \
	NifStream( unknownInts[i0], out, version ); \
}; \

#define BHK_LIST_SHAPE_STRING \
stringstream out; \
out << AbhkShapeCollection::asString(); \
out << "Num Sub Shapes:  " << numSubShapes << endl; \
for (uint i0 = 0; i0 < subShapes.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Sub Shapes[" << i0 << "]:  " << subShapes[i0] << endl; \
}; \
out << "Material:  " << material << endl; \
for (uint i0 = 0; i0 < 6; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats[" << i0 << "]:  " << unknownFloats[i0] << endl; \
}; \
out << "Num Unknown Ints:  " << numUnknownInts << endl; \
for (uint i0 = 0; i0 < unknownInts.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Ints[" << i0 << "]:  " << unknownInts[i0] << endl; \
}; \
return out.str(); \

#define BHK_LIST_SHAPE_FIXLINKS \
AbhkShapeCollection::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < subShapes.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		subShapes[i0] = DynamicCast<bhkShape>(objects[link_stack.front()]); \
		if ( subShapes[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		subShapes[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define BHK_LIST_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkShapeCollection::GetRefs(); \
for (uint i0 = 0; i0 < subShapes.size(); i0++) { \
	if ( subShapes[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(subShapes[i0])); \
}; \
return refs; \

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
uint block_num; \
AbhkConstraint::Read( in, link_stack, version, user_version ); \
NifStream( type, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( unknownInt3, in, version ); \
if ( (type == 7) ) { \
	NifStream( ragdoll.pivotA, in, version ); \
	NifStream( ragdoll.planeA, in, version ); \
	NifStream( ragdoll.twistA, in, version ); \
	NifStream( ragdoll.pivotB, in, version ); \
	NifStream( ragdoll.planeB, in, version ); \
	NifStream( ragdoll.twistB, in, version ); \
	NifStream( ragdoll.coneMinAngle, in, version ); \
	NifStream( ragdoll.planeMinAngle, in, version ); \
	NifStream( ragdoll.planeMaxAngle, in, version ); \
	NifStream( ragdoll.twistMinAngle, in, version ); \
	NifStream( ragdoll.twistMaxAngle, in, version ); \
	NifStream( ragdoll.maxFriction, in, version ); \
}; \
if ( (type == 2) ) { \
	NifStream( limitedHinge.pivotA, in, version ); \
	NifStream( limitedHinge.axleA_, in, version ); \
	NifStream( limitedHinge.perp2axleina1, in, version ); \
	NifStream( limitedHinge.perp2axleina2, in, version ); \
	NifStream( limitedHinge.pivotB, in, version ); \
	NifStream( limitedHinge.axleB, in, version ); \
	NifStream( limitedHinge.unknownVector, in, version ); \
	NifStream( limitedHinge.minAngle, in, version ); \
	NifStream( limitedHinge.maxAngle, in, version ); \
	NifStream( limitedHinge.maxFriction, in, version ); \
}; \
NifStream( tau, in, version ); \
NifStream( damping, in, version ); \

#define BHK_MALLEABLE_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, link_map, version, user_version ); \
NifStream( type, out, version ); \
NifStream( unknownInt2, out, version ); \
if ( unknownLink1 != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink1)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( unknownLink2 != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( unknownInt3, out, version ); \
if ( (type == 7) ) { \
	NifStream( ragdoll.pivotA, out, version ); \
	NifStream( ragdoll.planeA, out, version ); \
	NifStream( ragdoll.twistA, out, version ); \
	NifStream( ragdoll.pivotB, out, version ); \
	NifStream( ragdoll.planeB, out, version ); \
	NifStream( ragdoll.twistB, out, version ); \
	NifStream( ragdoll.coneMinAngle, out, version ); \
	NifStream( ragdoll.planeMinAngle, out, version ); \
	NifStream( ragdoll.planeMaxAngle, out, version ); \
	NifStream( ragdoll.twistMinAngle, out, version ); \
	NifStream( ragdoll.twistMaxAngle, out, version ); \
	NifStream( ragdoll.maxFriction, out, version ); \
}; \
if ( (type == 2) ) { \
	NifStream( limitedHinge.pivotA, out, version ); \
	NifStream( limitedHinge.axleA_, out, version ); \
	NifStream( limitedHinge.perp2axleina1, out, version ); \
	NifStream( limitedHinge.perp2axleina2, out, version ); \
	NifStream( limitedHinge.pivotB, out, version ); \
	NifStream( limitedHinge.axleB, out, version ); \
	NifStream( limitedHinge.unknownVector, out, version ); \
	NifStream( limitedHinge.minAngle, out, version ); \
	NifStream( limitedHinge.maxAngle, out, version ); \
	NifStream( limitedHinge.maxFriction, out, version ); \
}; \
NifStream( tau, out, version ); \
NifStream( damping, out, version ); \

#define BHK_MALLEABLE_CONSTRAINT_STRING \
stringstream out; \
out << AbhkConstraint::asString(); \
out << "Type:  " << type << endl; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
out << "Unknown Link 1:  " << unknownLink1 << endl; \
out << "Unknown Link 2:  " << unknownLink2 << endl; \
out << "Unknown Int 3:  " << unknownInt3 << endl; \
if ( (type == 7) ) { \
	out << "  Pivot A:  " << ragdoll.pivotA << endl; \
	out << "  Plane A:  " << ragdoll.planeA << endl; \
	out << "  Twist A:  " << ragdoll.twistA << endl; \
	out << "  Pivot B:  " << ragdoll.pivotB << endl; \
	out << "  Plane B:  " << ragdoll.planeB << endl; \
	out << "  Twist B:  " << ragdoll.twistB << endl; \
	out << "  Cone Min Angle:  " << ragdoll.coneMinAngle << endl; \
	out << "  Plane Min Angle:  " << ragdoll.planeMinAngle << endl; \
	out << "  Plane Max Angle:  " << ragdoll.planeMaxAngle << endl; \
	out << "  Twist Min Angle:  " << ragdoll.twistMinAngle << endl; \
	out << "  Twist Max Angle:  " << ragdoll.twistMaxAngle << endl; \
	out << "  Max Friction:  " << ragdoll.maxFriction << endl; \
}; \
if ( (type == 2) ) { \
	out << "  Pivot A:  " << limitedHinge.pivotA << endl; \
	out << "  Axle A ?:  " << limitedHinge.axleA_ << endl; \
	out << "  Perp2AxleInA1:  " << limitedHinge.perp2axleina1 << endl; \
	out << "  Perp2AxleInA2:  " << limitedHinge.perp2axleina2 << endl; \
	out << "  Pivot B:  " << limitedHinge.pivotB << endl; \
	out << "  Axle B:  " << limitedHinge.axleB << endl; \
	out << "  Unknown Vector:  " << limitedHinge.unknownVector << endl; \
	out << "  Min Angle:  " << limitedHinge.minAngle << endl; \
	out << "  Max Angle:  " << limitedHinge.maxAngle << endl; \
	out << "  Max Friction:  " << limitedHinge.maxFriction << endl; \
}; \
out << "Tau:  " << tau << endl; \
out << "Damping:  " << damping << endl; \
return out.str(); \

#define BHK_MALLEABLE_CONSTRAINT_FIXLINKS \
AbhkConstraint::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink1 = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( unknownLink1 == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink1 = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink2 = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( unknownLink2 == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink2 = NULL; \
link_stack.pop_front(); \

#define BHK_MALLEABLE_CONSTRAINT_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkConstraint::GetRefs(); \
if ( unknownLink1 != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink1)); \
if ( unknownLink2 != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink2)); \
return refs; \

#define BHK_MOPP_BV_TREE_SHAPE_MEMBERS \
Ref<bhkShape > shape; \
uint material; \
byte unknownBytes1[8]; \
float unknownFloat; \
uint numUnknownBytes2; \
vector<byte > unknownBytes2; \
Vector3 unknownVector; \
float unknownFloat2; \

#define BHK_MOPP_BV_TREE_SHAPE_INCLUDE "bhkShape.h" \

#define BHK_MOPP_BV_TREE_SHAPE_PARENT bhkShape \

#define BHK_MOPP_BV_TREE_SHAPE_CONSTRUCT \
 : shape(NULL), material((uint)0), unknownFloat(0.0f), numUnknownBytes2((uint)0), unknownFloat2(0.0f) \

#define BHK_MOPP_BV_TREE_SHAPE_READ \
uint block_num; \
bhkShape::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( material, in, version ); \
for (uint i0 = 0; i0 < 8; i0++) { \
	NifStream( unknownBytes1[i0], in, version ); \
}; \
NifStream( unknownFloat, in, version ); \
NifStream( numUnknownBytes2, in, version ); \
unknownBytes2.resize(numUnknownBytes2); \
for (uint i0 = 0; i0 < unknownBytes2.size(); i0++) { \
	NifStream( unknownBytes2[i0], in, version ); \
}; \
NifStream( unknownVector, in, version ); \
NifStream( unknownFloat2, in, version ); \

#define BHK_MOPP_BV_TREE_SHAPE_WRITE \
bhkShape::Write( out, link_map, version, user_version ); \
if ( shape != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(shape)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( material, out, version ); \
for (uint i0 = 0; i0 < 8; i0++) { \
	NifStream( unknownBytes1[i0], out, version ); \
}; \
NifStream( unknownFloat, out, version ); \
NifStream( numUnknownBytes2, out, version ); \
for (uint i0 = 0; i0 < unknownBytes2.size(); i0++) { \
	NifStream( unknownBytes2[i0], out, version ); \
}; \
NifStream( unknownVector, out, version ); \
NifStream( unknownFloat2, out, version ); \

#define BHK_MOPP_BV_TREE_SHAPE_STRING \
stringstream out; \
out << bhkShape::asString(); \
out << "Shape:  " << shape << endl; \
out << "Material:  " << material << endl; \
for (uint i0 = 0; i0 < 8; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Bytes 1[" << i0 << "]:  " << unknownBytes1[i0] << endl; \
}; \
out << "Unknown Float:  " << unknownFloat << endl; \
out << "Num Unknown Bytes 2:  " << numUnknownBytes2 << endl; \
for (uint i0 = 0; i0 < unknownBytes2.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Bytes 2[" << i0 << "]:  " << unknownBytes2[i0] << endl; \
}; \
out << "Unknown Vector:  " << unknownVector << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
return out.str(); \

#define BHK_MOPP_BV_TREE_SHAPE_FIXLINKS \
bhkShape::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	shape = DynamicCast<bhkShape>(objects[link_stack.front()]); \
	if ( shape == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	shape = NULL; \
link_stack.pop_front(); \

#define BHK_MOPP_BV_TREE_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkShape::GetRefs(); \
if ( shape != NULL ) \
	refs.push_back(StaticCast<NiObject>(shape)); \
return refs; \

#define BHK_MULTI_SPHERE_SHAPE_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
uint unknownInt2; \
float unknownFloats[8]; \

#define BHK_MULTI_SPHERE_SHAPE_INCLUDE "bhkSphereRepShape.h" \

#define BHK_MULTI_SPHERE_SHAPE_PARENT bhkSphereRepShape \

#define BHK_MULTI_SPHERE_SHAPE_CONSTRUCT \
 : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownInt2((uint)0) \

#define BHK_MULTI_SPHERE_SHAPE_READ \
bhkSphereRepShape::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownInt2, in, version ); \
for (uint i0 = 0; i0 < 8; i0++) { \
	NifStream( unknownFloats[i0], in, version ); \
}; \

#define BHK_MULTI_SPHERE_SHAPE_WRITE \
bhkSphereRepShape::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownInt2, out, version ); \
for (uint i0 = 0; i0 < 8; i0++) { \
	NifStream( unknownFloats[i0], out, version ); \
}; \

#define BHK_MULTI_SPHERE_SHAPE_STRING \
stringstream out; \
out << bhkSphereRepShape::asString(); \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
out << "Unknown Float 3:  " << unknownFloat3 << endl; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
for (uint i0 = 0; i0 < 8; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats[" << i0 << "]:  " << unknownFloats[i0] << endl; \
}; \
return out.str(); \

#define BHK_MULTI_SPHERE_SHAPE_FIXLINKS \
bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_MULTI_SPHERE_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkSphereRepShape::GetRefs(); \
return refs; \

#define BHK_NI_TRI_STRIPS_SHAPE_MEMBERS \
float unknownFloats1[2]; \
uint unknownInts1[5]; \
float unknownFloats2[3]; \
uint unknownInt2; \
uint numStripsData; \
vector<Ref<NiTriStripsData > > stripsData; \
uint numUnknownInts3; \
vector<uint > unknownInts3; \

#define BHK_NI_TRI_STRIPS_SHAPE_INCLUDE "bhkSphereRepShape.h" \

#define BHK_NI_TRI_STRIPS_SHAPE_PARENT bhkSphereRepShape \

#define BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT \
 : unknownInt2((uint)0), numStripsData((uint)0), numUnknownInts3((uint)0) \

#define BHK_NI_TRI_STRIPS_SHAPE_READ \
uint block_num; \
bhkSphereRepShape::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 2; i0++) { \
	NifStream( unknownFloats1[i0], in, version ); \
}; \
for (uint i0 = 0; i0 < 5; i0++) { \
	NifStream( unknownInts1[i0], in, version ); \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	NifStream( unknownFloats2[i0], in, version ); \
}; \
NifStream( unknownInt2, in, version ); \
NifStream( numStripsData, in, version ); \
stripsData.resize(numStripsData); \
for (uint i0 = 0; i0 < stripsData.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( numUnknownInts3, in, version ); \
unknownInts3.resize(numUnknownInts3); \
for (uint i0 = 0; i0 < unknownInts3.size(); i0++) { \
	NifStream( unknownInts3[i0], in, version ); \
}; \

#define BHK_NI_TRI_STRIPS_SHAPE_WRITE \
bhkSphereRepShape::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 2; i0++) { \
	NifStream( unknownFloats1[i0], out, version ); \
}; \
for (uint i0 = 0; i0 < 5; i0++) { \
	NifStream( unknownInts1[i0], out, version ); \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	NifStream( unknownFloats2[i0], out, version ); \
}; \
NifStream( unknownInt2, out, version ); \
NifStream( numStripsData, out, version ); \
for (uint i0 = 0; i0 < stripsData.size(); i0++) { \
	if ( stripsData[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(stripsData[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
NifStream( numUnknownInts3, out, version ); \
for (uint i0 = 0; i0 < unknownInts3.size(); i0++) { \
	NifStream( unknownInts3[i0], out, version ); \
}; \

#define BHK_NI_TRI_STRIPS_SHAPE_STRING \
stringstream out; \
out << bhkSphereRepShape::asString(); \
for (uint i0 = 0; i0 < 2; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats 1[" << i0 << "]:  " << unknownFloats1[i0] << endl; \
}; \
for (uint i0 = 0; i0 < 5; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Ints 1[" << i0 << "]:  " << unknownInts1[i0] << endl; \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats 2[" << i0 << "]:  " << unknownFloats2[i0] << endl; \
}; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
out << "Num Strips Data:  " << numStripsData << endl; \
for (uint i0 = 0; i0 < stripsData.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Strips Data[" << i0 << "]:  " << stripsData[i0] << endl; \
}; \
out << "Num Unknown Ints 3:  " << numUnknownInts3 << endl; \
for (uint i0 = 0; i0 < unknownInts3.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Ints 3[" << i0 << "]:  " << unknownInts3[i0] << endl; \
}; \
return out.str(); \

#define BHK_NI_TRI_STRIPS_SHAPE_FIXLINKS \
bhkSphereRepShape::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < stripsData.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		stripsData[i0] = DynamicCast<NiTriStripsData>(objects[link_stack.front()]); \
		if ( stripsData[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		stripsData[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define BHK_NI_TRI_STRIPS_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkSphereRepShape::GetRefs(); \
for (uint i0 = 0; i0 < stripsData.size(); i0++) { \
	if ( stripsData[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(stripsData[i0])); \
}; \
return refs; \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_MEMBERS \
ushort numSubparts; \
vector< array<uint,3> > subparts; \
float unknownFloats[9]; \
float scale; \
float unknownFloats2[3]; \
Ref<hkPackedNiTriStripsData > data; \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_INCLUDE "AbhkShapeCollection.h" \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT AbhkShapeCollection \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_CONSTRUCT \
 : numSubparts((ushort)0), scale(1.0f), data(NULL) \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_READ \
uint block_num; \
AbhkShapeCollection::Read( in, link_stack, version, user_version ); \
NifStream( numSubparts, in, version ); \
subparts.resize(numSubparts); \
for (uint i0 = 0; i0 < subparts.size(); i0++) { \
	for (uint i1 = 0; i1 < 3; i1++) { \
		NifStream( subparts[i0][i1], in, version ); \
	}; \
}; \
for (uint i0 = 0; i0 < 9; i0++) { \
	NifStream( unknownFloats[i0], in, version ); \
}; \
NifStream( scale, in, version ); \
for (uint i0 = 0; i0 < 3; i0++) { \
	NifStream( unknownFloats2[i0], in, version ); \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_WRITE \
AbhkShapeCollection::Write( out, link_map, version, user_version ); \
NifStream( numSubparts, out, version ); \
for (uint i0 = 0; i0 < subparts.size(); i0++) { \
	for (uint i1 = 0; i1 < 3; i1++) { \
		NifStream( subparts[i0][i1], out, version ); \
	}; \
}; \
for (uint i0 = 0; i0 < 9; i0++) { \
	NifStream( unknownFloats[i0], out, version ); \
}; \
NifStream( scale, out, version ); \
for (uint i0 = 0; i0 < 3; i0++) { \
	NifStream( unknownFloats2[i0], out, version ); \
}; \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_STRING \
stringstream out; \
out << AbhkShapeCollection::asString(); \
out << "Num Subparts:  " << numSubparts << endl; \
for (uint i0 = 0; i0 < subparts.size(); i0++) { \
	for (uint i1 = 0; i1 < 3; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Subparts[" << i0 << "][" << i1 << "]:  " << subparts[i0][i1] << endl; \
	}; \
}; \
for (uint i0 = 0; i0 < 9; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats[" << i0 << "]:  " << unknownFloats[i0] << endl; \
}; \
out << "Scale:  " << scale << endl; \
for (uint i0 = 0; i0 < 3; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats 2[" << i0 << "]:  " << unknownFloats2[i0] << endl; \
}; \
out << "Data:  " << data << endl; \
return out.str(); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_FIXLINKS \
AbhkShapeCollection::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<hkPackedNiTriStripsData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkShapeCollection::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define BHK_PRISMATIC_CONSTRAINT_MEMBERS \
Float4 unknownVectors[8]; \
float unknownFloats2[3]; \

#define BHK_PRISMATIC_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_PRISMATIC_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_PRISMATIC_CONSTRAINT_CONSTRUCT \

#define BHK_PRISMATIC_CONSTRAINT_READ \
AbhkConstraint::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 8; i0++) { \
	NifStream( unknownVectors[i0], in, version ); \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	NifStream( unknownFloats2[i0], in, version ); \
}; \

#define BHK_PRISMATIC_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 8; i0++) { \
	NifStream( unknownVectors[i0], out, version ); \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	NifStream( unknownFloats2[i0], out, version ); \
}; \

#define BHK_PRISMATIC_CONSTRAINT_STRING \
stringstream out; \
out << AbhkConstraint::asString(); \
for (uint i0 = 0; i0 < 8; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Vectors[" << i0 << "]:  " << unknownVectors[i0] << endl; \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats 2[" << i0 << "]:  " << unknownFloats2[i0] << endl; \
}; \
return out.str(); \

#define BHK_PRISMATIC_CONSTRAINT_FIXLINKS \
AbhkConstraint::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_PRISMATIC_CONSTRAINT_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkConstraint::GetRefs(); \
return refs; \

#define BHK_RAGDOLL_CONSTRAINT_MEMBERS \

#define BHK_RAGDOLL_CONSTRAINT_INCLUDE "AbhkRagdollConstraint.h" \

#define BHK_RAGDOLL_CONSTRAINT_PARENT AbhkRagdollConstraint \

#define BHK_RAGDOLL_CONSTRAINT_CONSTRUCT \

#define BHK_RAGDOLL_CONSTRAINT_READ \
AbhkRagdollConstraint::Read( in, link_stack, version, user_version ); \

#define BHK_RAGDOLL_CONSTRAINT_WRITE \
AbhkRagdollConstraint::Write( out, link_map, version, user_version ); \

#define BHK_RAGDOLL_CONSTRAINT_STRING \
stringstream out; \
out << AbhkRagdollConstraint::asString(); \
return out.str(); \

#define BHK_RAGDOLL_CONSTRAINT_FIXLINKS \
AbhkRagdollConstraint::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_RAGDOLL_CONSTRAINT_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkRagdollConstraint::GetRefs(); \
return refs; \

#define BHK_RIGID_BODY_MEMBERS \
float unknownFloats1[5]; \
ushort unknownShorts1[4]; \
uint layerCopy_; \
ushort unknownShorts2[6]; \
Vector3 translation; \
float unknownFloat00; \
QuaternionXYZW rotation; \
Vector3 linearVelocity; \
float unknownFloat01; \
Vector3 angularVelocity; \
float unknownFloat02; \
float transform_[12]; \
Vector3 center; \
float unknownFloat03; \
float mass; \
float linearDamping; \
float angularDamping; \
float friction; \
float restitution; \
float maxLinearVelocity; \
float maxAngularVelocity; \
float penDepth; \
byte motionSystem_; \
byte unknownByte1; \
byte unknownByte2; \
byte qualityType; \
uint unknownInt6; \
uint unknownInt7; \
uint unknownInt8; \
uint numConstraints; \
vector<Ref<AbhkConstraint > > constraints; \

#define BHK_RIGID_BODY_INCLUDE "bhkEntity.h" \

#define BHK_RIGID_BODY_PARENT bhkEntity \

#define BHK_RIGID_BODY_CONSTRUCT \
 : layerCopy_((uint)0), unknownFloat00(0.0f), unknownFloat01(0.0f), unknownFloat02(0.0f), unknownFloat03(0.0f), mass(0.0f), linearDamping(0.0f), angularDamping(0.0f), friction(0.0f), restitution(0.0f), maxLinearVelocity(0.0f), maxAngularVelocity(31.415926535f), penDepth(0.0f), motionSystem_((byte)0), unknownByte1((byte)0), unknownByte2((byte)0), qualityType((byte)0), unknownInt6((uint)0), unknownInt7((uint)0), unknownInt8((uint)0), numConstraints((uint)0) \

#define BHK_RIGID_BODY_READ \
uint block_num; \
bhkEntity::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 5; i0++) { \
	NifStream( unknownFloats1[i0], in, version ); \
}; \
for (uint i0 = 0; i0 < 4; i0++) { \
	NifStream( unknownShorts1[i0], in, version ); \
}; \
NifStream( layerCopy_, in, version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownShorts2[i0], in, version ); \
}; \
NifStream( translation, in, version ); \
NifStream( unknownFloat00, in, version ); \
NifStream( rotation.x, in, version ); \
NifStream( rotation.y, in, version ); \
NifStream( rotation.z, in, version ); \
NifStream( rotation.w, in, version ); \
NifStream( linearVelocity, in, version ); \
NifStream( unknownFloat01, in, version ); \
NifStream( angularVelocity, in, version ); \
NifStream( unknownFloat02, in, version ); \
for (uint i0 = 0; i0 < 12; i0++) { \
	NifStream( transform_[i0], in, version ); \
}; \
NifStream( center, in, version ); \
NifStream( unknownFloat03, in, version ); \
NifStream( mass, in, version ); \
NifStream( linearDamping, in, version ); \
NifStream( angularDamping, in, version ); \
NifStream( friction, in, version ); \
NifStream( restitution, in, version ); \
NifStream( maxLinearVelocity, in, version ); \
NifStream( maxAngularVelocity, in, version ); \
NifStream( penDepth, in, version ); \
NifStream( motionSystem_, in, version ); \
NifStream( unknownByte1, in, version ); \
NifStream( unknownByte2, in, version ); \
NifStream( qualityType, in, version ); \
NifStream( unknownInt6, in, version ); \
NifStream( unknownInt7, in, version ); \
NifStream( unknownInt8, in, version ); \
NifStream( numConstraints, in, version ); \
constraints.resize(numConstraints); \
for (uint i0 = 0; i0 < constraints.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( unknownInt6, in, version ); \

#define BHK_RIGID_BODY_WRITE \
bhkEntity::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 5; i0++) { \
	NifStream( unknownFloats1[i0], out, version ); \
}; \
for (uint i0 = 0; i0 < 4; i0++) { \
	NifStream( unknownShorts1[i0], out, version ); \
}; \
NifStream( layerCopy_, out, version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownShorts2[i0], out, version ); \
}; \
NifStream( translation, out, version ); \
NifStream( unknownFloat00, out, version ); \
NifStream( rotation.x, out, version ); \
NifStream( rotation.y, out, version ); \
NifStream( rotation.z, out, version ); \
NifStream( rotation.w, out, version ); \
NifStream( linearVelocity, out, version ); \
NifStream( unknownFloat01, out, version ); \
NifStream( angularVelocity, out, version ); \
NifStream( unknownFloat02, out, version ); \
for (uint i0 = 0; i0 < 12; i0++) { \
	NifStream( transform_[i0], out, version ); \
}; \
NifStream( center, out, version ); \
NifStream( unknownFloat03, out, version ); \
NifStream( mass, out, version ); \
NifStream( linearDamping, out, version ); \
NifStream( angularDamping, out, version ); \
NifStream( friction, out, version ); \
NifStream( restitution, out, version ); \
NifStream( maxLinearVelocity, out, version ); \
NifStream( maxAngularVelocity, out, version ); \
NifStream( penDepth, out, version ); \
NifStream( motionSystem_, out, version ); \
NifStream( unknownByte1, out, version ); \
NifStream( unknownByte2, out, version ); \
NifStream( qualityType, out, version ); \
NifStream( unknownInt6, out, version ); \
NifStream( unknownInt7, out, version ); \
NifStream( unknownInt8, out, version ); \
NifStream( numConstraints, out, version ); \
for (uint i0 = 0; i0 < constraints.size(); i0++) { \
	if ( constraints[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(constraints[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
NifStream( unknownInt6, out, version ); \

#define BHK_RIGID_BODY_STRING \
stringstream out; \
out << bhkEntity::asString(); \
for (uint i0 = 0; i0 < 5; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats 1[" << i0 << "]:  " << unknownFloats1[i0] << endl; \
}; \
for (uint i0 = 0; i0 < 4; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Shorts 1[" << i0 << "]:  " << unknownShorts1[i0] << endl; \
}; \
out << "Layer Copy?:  " << layerCopy_ << endl; \
for (uint i0 = 0; i0 < 6; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Shorts 2[" << i0 << "]:  " << unknownShorts2[i0] << endl; \
}; \
out << "Translation:  " << translation << endl; \
out << "Unknown Float 00:  " << unknownFloat00 << endl; \
out << "x:  " << rotation.x << endl; \
out << "y:  " << rotation.y << endl; \
out << "z:  " << rotation.z << endl; \
out << "w:  " << rotation.w << endl; \
out << "Linear Velocity:  " << linearVelocity << endl; \
out << "Unknown Float 01:  " << unknownFloat01 << endl; \
out << "Angular Velocity:  " << angularVelocity << endl; \
out << "Unknown Float 02:  " << unknownFloat02 << endl; \
for (uint i0 = 0; i0 < 12; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Transform?[" << i0 << "]:  " << transform_[i0] << endl; \
}; \
out << "Center:  " << center << endl; \
out << "Unknown Float 03:  " << unknownFloat03 << endl; \
out << "Mass:  " << mass << endl; \
out << "Linear Damping:  " << linearDamping << endl; \
out << "Angular Damping:  " << angularDamping << endl; \
out << "Friction:  " << friction << endl; \
out << "Restitution:  " << restitution << endl; \
out << "Max Linear Velocity:  " << maxLinearVelocity << endl; \
out << "Max Angular Velocity:  " << maxAngularVelocity << endl; \
out << "Pen Depth:  " << penDepth << endl; \
out << "Motion System?:  " << motionSystem_ << endl; \
out << "Unknown Byte 1:  " << unknownByte1 << endl; \
out << "Unknown Byte 2:  " << unknownByte2 << endl; \
out << "Quality Type:  " << qualityType << endl; \
out << "Unknown Int 6:  " << unknownInt6 << endl; \
out << "Unknown Int 7:  " << unknownInt7 << endl; \
out << "Unknown Int 8:  " << unknownInt8 << endl; \
out << "Num Constraints:  " << numConstraints << endl; \
for (uint i0 = 0; i0 < constraints.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Constraints[" << i0 << "]:  " << constraints[i0] << endl; \
}; \
return out.str(); \

#define BHK_RIGID_BODY_FIXLINKS \
bhkEntity::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < constraints.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		constraints[i0] = DynamicCast<AbhkConstraint>(objects[link_stack.front()]); \
		if ( constraints[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		constraints[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define BHK_RIGID_BODY_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkEntity::GetRefs(); \
for (uint i0 = 0; i0 < constraints.size(); i0++) { \
	if ( constraints[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(constraints[i0])); \
}; \
return refs; \

#define BHK_RIGID_BODY_T_MEMBERS \

#define BHK_RIGID_BODY_T_INCLUDE "bhkRigidBody.h" \

#define BHK_RIGID_BODY_T_PARENT bhkRigidBody \

#define BHK_RIGID_BODY_T_CONSTRUCT \

#define BHK_RIGID_BODY_T_READ \
bhkRigidBody::Read( in, link_stack, version, user_version ); \

#define BHK_RIGID_BODY_T_WRITE \
bhkRigidBody::Write( out, link_map, version, user_version ); \

#define BHK_RIGID_BODY_T_STRING \
stringstream out; \
out << bhkRigidBody::asString(); \
return out.str(); \

#define BHK_RIGID_BODY_T_FIXLINKS \
bhkRigidBody::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_RIGID_BODY_T_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkRigidBody::GetRefs(); \
return refs; \

#define BHK_SIMPLE_SHAPE_PHANTOM_MEMBERS \
float unkownFloats[7]; \
float unknownFloats2[3][5]; \
float unknownFloat; \

#define BHK_SIMPLE_SHAPE_PHANTOM_INCLUDE "bhkEntity.h" \

#define BHK_SIMPLE_SHAPE_PHANTOM_PARENT bhkEntity \

#define BHK_SIMPLE_SHAPE_PHANTOM_CONSTRUCT \
 : unknownFloat(0.0f) \

#define BHK_SIMPLE_SHAPE_PHANTOM_READ \
bhkEntity::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 7; i0++) { \
	NifStream( unkownFloats[i0], in, version ); \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	for (uint i1 = 0; i1 < 5; i1++) { \
		NifStream( unknownFloats2[i0][i1], in, version ); \
	}; \
}; \
NifStream( unknownFloat, in, version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_WRITE \
bhkEntity::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 7; i0++) { \
	NifStream( unkownFloats[i0], out, version ); \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	for (uint i1 = 0; i1 < 5; i1++) { \
		NifStream( unknownFloats2[i0][i1], out, version ); \
	}; \
}; \
NifStream( unknownFloat, out, version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_STRING \
stringstream out; \
out << bhkEntity::asString(); \
for (uint i0 = 0; i0 < 7; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unkown Floats[" << i0 << "]:  " << unkownFloats[i0] << endl; \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	for (uint i1 = 0; i1 < 5; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats 2[" << i0 << "][" << i1 << "]:  " << unknownFloats2[i0][i1] << endl; \
	}; \
}; \
out << "Unknown Float:  " << unknownFloat << endl; \
return out.str(); \

#define BHK_SIMPLE_SHAPE_PHANTOM_FIXLINKS \
bhkEntity::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_SIMPLE_SHAPE_PHANTOM_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkEntity::GetRefs(); \
return refs; \

#define BHK_S_P_COLLISION_OBJECT_MEMBERS \

#define BHK_S_P_COLLISION_OBJECT_INCLUDE "NiCollisionObject.h" \

#define BHK_S_P_COLLISION_OBJECT_PARENT NiCollisionObject \

#define BHK_S_P_COLLISION_OBJECT_CONSTRUCT \

#define BHK_S_P_COLLISION_OBJECT_READ \
NiCollisionObject::Read( in, link_stack, version, user_version ); \

#define BHK_S_P_COLLISION_OBJECT_WRITE \
NiCollisionObject::Write( out, link_map, version, user_version ); \

#define BHK_S_P_COLLISION_OBJECT_STRING \
stringstream out; \
out << NiCollisionObject::asString(); \
return out.str(); \

#define BHK_S_P_COLLISION_OBJECT_FIXLINKS \
NiCollisionObject::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_S_P_COLLISION_OBJECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiCollisionObject::GetRefs(); \
return refs; \

#define BHK_SPHERE_SHAPE_MEMBERS \
float radius; \

#define BHK_SPHERE_SHAPE_INCLUDE "bhkConvexShape.h" \

#define BHK_SPHERE_SHAPE_PARENT bhkConvexShape \

#define BHK_SPHERE_SHAPE_CONSTRUCT \
 : radius(0.0f) \

#define BHK_SPHERE_SHAPE_READ \
bhkConvexShape::Read( in, link_stack, version, user_version ); \
NifStream( radius, in, version ); \

#define BHK_SPHERE_SHAPE_WRITE \
bhkConvexShape::Write( out, link_map, version, user_version ); \
NifStream( radius, out, version ); \

#define BHK_SPHERE_SHAPE_STRING \
stringstream out; \
out << bhkConvexShape::asString(); \
out << "Radius:  " << radius << endl; \
return out.str(); \

#define BHK_SPHERE_SHAPE_FIXLINKS \
bhkConvexShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_SPHERE_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkConvexShape::GetRefs(); \
return refs; \

#define BHK_STIFF_SPRING_CONSTRAINT_MEMBERS \
float unknownFloats[2][4]; \
float unknownFloat; \

#define BHK_STIFF_SPRING_CONSTRAINT_INCLUDE "AbhkConstraint.h" \

#define BHK_STIFF_SPRING_CONSTRAINT_PARENT AbhkConstraint \

#define BHK_STIFF_SPRING_CONSTRAINT_CONSTRUCT \
 : unknownFloat(0.0f) \

#define BHK_STIFF_SPRING_CONSTRAINT_READ \
AbhkConstraint::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 2; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		NifStream( unknownFloats[i0][i1], in, version ); \
	}; \
}; \
NifStream( unknownFloat, in, version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_WRITE \
AbhkConstraint::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 2; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		NifStream( unknownFloats[i0][i1], out, version ); \
	}; \
}; \
NifStream( unknownFloat, out, version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_STRING \
stringstream out; \
out << AbhkConstraint::asString(); \
for (uint i0 = 0; i0 < 2; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats[" << i0 << "][" << i1 << "]:  " << unknownFloats[i0][i1] << endl; \
	}; \
}; \
out << "Unknown Float:  " << unknownFloat << endl; \
return out.str(); \

#define BHK_STIFF_SPRING_CONSTRAINT_FIXLINKS \
AbhkConstraint::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_STIFF_SPRING_CONSTRAINT_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkConstraint::GetRefs(); \
return refs; \

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
bhkEntity::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( transform, in, version ); \

#define BHK_TRANSFORM_SHAPE_WRITE \
bhkEntity::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( transform, out, version ); \

#define BHK_TRANSFORM_SHAPE_STRING \
stringstream out; \
out << bhkEntity::asString(); \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
out << "Unknown Float 3:  " << unknownFloat3 << endl; \
out << "Transform:  " << transform << endl; \
return out.str(); \

#define BHK_TRANSFORM_SHAPE_FIXLINKS \
bhkEntity::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_TRANSFORM_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkEntity::GetRefs(); \
return refs; \

#define BHK_CONVEX_TRANSFORM_SHAPE_MEMBERS \

#define BHK_CONVEX_TRANSFORM_SHAPE_INCLUDE "bhkTransformShape.h" \

#define BHK_CONVEX_TRANSFORM_SHAPE_PARENT bhkTransformShape \

#define BHK_CONVEX_TRANSFORM_SHAPE_CONSTRUCT \

#define BHK_CONVEX_TRANSFORM_SHAPE_READ \
bhkTransformShape::Read( in, link_stack, version, user_version ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_WRITE \
bhkTransformShape::Write( out, link_map, version, user_version ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_STRING \
stringstream out; \
out << bhkTransformShape::asString(); \
return out.str(); \

#define BHK_CONVEX_TRANSFORM_SHAPE_FIXLINKS \
bhkTransformShape::FixLinks( objects, link_stack, version, user_version ); \

#define BHK_CONVEX_TRANSFORM_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = bhkTransformShape::GetRefs(); \
return refs; \

#define B_S_BOUND_MEMBERS \
float unknownFloats[6]; \

#define B_S_BOUND_INCLUDE "NiExtraData.h" \

#define B_S_BOUND_PARENT NiExtraData \

#define B_S_BOUND_CONSTRUCT \

#define B_S_BOUND_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownFloats[i0], in, version ); \
}; \

#define B_S_BOUND_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownFloats[i0], out, version ); \
}; \

#define B_S_BOUND_STRING \
stringstream out; \
out << NiExtraData::asString(); \
for (uint i0 = 0; i0 < 6; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats[" << i0 << "]:  " << unknownFloats[i0] << endl; \
}; \
return out.str(); \

#define B_S_BOUND_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define B_S_BOUND_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define B_S_FURNITURE_MARKER_MEMBERS \
uint numPositions; \
vector<FurniturePosition > positions; \

#define B_S_FURNITURE_MARKER_INCLUDE "NiExtraData.h" \

#define B_S_FURNITURE_MARKER_PARENT NiExtraData \

#define B_S_FURNITURE_MARKER_CONSTRUCT \
 : numPositions((uint)0) \

#define B_S_FURNITURE_MARKER_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( numPositions, in, version ); \
positions.resize(numPositions); \
for (uint i0 = 0; i0 < positions.size(); i0++) { \
	NifStream( positions[i0].offset, in, version ); \
	NifStream( positions[i0].orientation, in, version ); \
	NifStream( positions[i0].positionRef1, in, version ); \
	NifStream( positions[i0].positionRef2, in, version ); \
}; \

#define B_S_FURNITURE_MARKER_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( numPositions, out, version ); \
for (uint i0 = 0; i0 < positions.size(); i0++) { \
	NifStream( positions[i0].offset, out, version ); \
	NifStream( positions[i0].orientation, out, version ); \
	NifStream( positions[i0].positionRef1, out, version ); \
	NifStream( positions[i0].positionRef2, out, version ); \
}; \

#define B_S_FURNITURE_MARKER_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Num Positions:  " << numPositions << endl; \
for (uint i0 = 0; i0 < positions.size(); i0++) { \
	out << "  Offset:  " << positions[i0].offset << endl; \
	out << "  Orientation:  " << positions[i0].orientation << endl; \
	out << "  Position Ref 1:  " << positions[i0].positionRef1 << endl; \
	out << "  Position Ref 2:  " << positions[i0].positionRef2 << endl; \
}; \
return out.str(); \

#define B_S_FURNITURE_MARKER_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define B_S_FURNITURE_MARKER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define B_S_PARENT_VELOCITY_MODIFIER_MEMBERS \
float unknownFloat; \

#define B_S_PARENT_VELOCITY_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define B_S_PARENT_VELOCITY_MODIFIER_PARENT NiPSysModifier \

#define B_S_PARENT_VELOCITY_MODIFIER_CONSTRUCT \
 : unknownFloat(0.0f) \

#define B_S_PARENT_VELOCITY_MODIFIER_READ \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat, in, version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat, out, version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Unknown Float:  " << unknownFloat << endl; \
return out.str(); \

#define B_S_PARENT_VELOCITY_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \

#define B_S_PARENT_VELOCITY_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define B_S_P_SYS_ARRAY_EMITTER_MEMBERS \

#define B_S_P_SYS_ARRAY_EMITTER_INCLUDE "NiPSysVolumeEmitter.h" \

#define B_S_P_SYS_ARRAY_EMITTER_PARENT NiPSysVolumeEmitter \

#define B_S_P_SYS_ARRAY_EMITTER_CONSTRUCT \

#define B_S_P_SYS_ARRAY_EMITTER_READ \
NiPSysVolumeEmitter::Read( in, link_stack, version, user_version ); \

#define B_S_P_SYS_ARRAY_EMITTER_WRITE \
NiPSysVolumeEmitter::Write( out, link_map, version, user_version ); \

#define B_S_P_SYS_ARRAY_EMITTER_STRING \
stringstream out; \
out << NiPSysVolumeEmitter::asString(); \
return out.str(); \

#define B_S_P_SYS_ARRAY_EMITTER_FIXLINKS \
NiPSysVolumeEmitter::FixLinks( objects, link_stack, version, user_version ); \

#define B_S_P_SYS_ARRAY_EMITTER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysVolumeEmitter::GetRefs(); \
return refs; \

#define B_S_X_FLAGS_MEMBERS \
uint flags; \

#define B_S_X_FLAGS_INCLUDE "NiExtraData.h" \

#define B_S_X_FLAGS_PARENT NiExtraData \

#define B_S_X_FLAGS_CONSTRUCT \
 : flags((uint)0) \

#define B_S_X_FLAGS_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \

#define B_S_X_FLAGS_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \

#define B_S_X_FLAGS_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Flags:  " << flags << endl; \
return out.str(); \

#define B_S_X_FLAGS_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define B_S_X_FLAGS_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define HK_PACKED_NI_TRI_STRIPS_DATA_MEMBERS \
uint numTriangles; \
vector<hkTriangle > triangles; \
uint numVertices; \
vector<Vector3 > vertices; \

#define HK_PACKED_NI_TRI_STRIPS_DATA_INCLUDE "AbhkShapeCollection.h" \

#define HK_PACKED_NI_TRI_STRIPS_DATA_PARENT AbhkShapeCollection \

#define HK_PACKED_NI_TRI_STRIPS_DATA_CONSTRUCT \
 : numTriangles((uint)0), numVertices((uint)0) \

#define HK_PACKED_NI_TRI_STRIPS_DATA_READ \
AbhkShapeCollection::Read( in, link_stack, version, user_version ); \
NifStream( numTriangles, in, version ); \
triangles.resize(numTriangles); \
for (uint i0 = 0; i0 < triangles.size(); i0++) { \
	NifStream( triangles[i0].triangle, in, version ); \
	NifStream( triangles[i0].unknownShort, in, version ); \
	NifStream( triangles[i0].normal, in, version ); \
}; \
NifStream( numVertices, in, version ); \
vertices.resize(numVertices); \
for (uint i0 = 0; i0 < vertices.size(); i0++) { \
	NifStream( vertices[i0], in, version ); \
}; \

#define HK_PACKED_NI_TRI_STRIPS_DATA_WRITE \
AbhkShapeCollection::Write( out, link_map, version, user_version ); \
NifStream( numTriangles, out, version ); \
for (uint i0 = 0; i0 < triangles.size(); i0++) { \
	NifStream( triangles[i0].triangle, out, version ); \
	NifStream( triangles[i0].unknownShort, out, version ); \
	NifStream( triangles[i0].normal, out, version ); \
}; \
NifStream( numVertices, out, version ); \
for (uint i0 = 0; i0 < vertices.size(); i0++) { \
	NifStream( vertices[i0], out, version ); \
}; \

#define HK_PACKED_NI_TRI_STRIPS_DATA_STRING \
stringstream out; \
out << AbhkShapeCollection::asString(); \
out << "Num Triangles:  " << numTriangles << endl; \
for (uint i0 = 0; i0 < triangles.size(); i0++) { \
	out << "  Triangle:  " << triangles[i0].triangle << endl; \
	out << "  Unknown Short:  " << triangles[i0].unknownShort << endl; \
	out << "  Normal:  " << triangles[i0].normal << endl; \
}; \
out << "Num Vertices:  " << numVertices << endl; \
for (uint i0 = 0; i0 < vertices.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Vertices[" << i0 << "]:  " << vertices[i0] << endl; \
}; \
return out.str(); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_FIXLINKS \
AbhkShapeCollection::FixLinks( objects, link_stack, version, user_version ); \

#define HK_PACKED_NI_TRI_STRIPS_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = AbhkShapeCollection::GetRefs(); \
return refs; \

#define NI_ALPHA_CONTROLLER_MEMBERS \
Ref<NiFloatData > data; \

#define NI_ALPHA_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_ALPHA_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_ALPHA_CONTROLLER_CONSTRUCT \
 : data(NULL) \

#define NI_ALPHA_CONTROLLER_READ \
uint block_num; \
NiSingleInterpolatorController::Read( in, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_ALPHA_CONTROLLER_WRITE \
NiSingleInterpolatorController::Write( out, link_map, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if ( data != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_ALPHA_CONTROLLER_STRING \
stringstream out; \
out << NiSingleInterpolatorController::asString(); \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_ALPHA_CONTROLLER_FIXLINKS \
NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		data = DynamicCast<NiFloatData>(objects[link_stack.front()]); \
		if ( data == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		data = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_ALPHA_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiSingleInterpolatorController::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_ALPHA_PROPERTY_MEMBERS \
ushort flags; \
byte threshold; \

#define NI_ALPHA_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_ALPHA_PROPERTY_PARENT NiProperty \

#define NI_ALPHA_PROPERTY_CONSTRUCT \
 : flags((ushort)237), threshold((byte)0) \

#define NI_ALPHA_PROPERTY_READ \
NiProperty::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \
NifStream( threshold, in, version ); \

#define NI_ALPHA_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \
NifStream( threshold, out, version ); \

#define NI_ALPHA_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
out << "Threshold:  " << threshold << endl; \
return out.str(); \

#define NI_ALPHA_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_ALPHA_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define NI_AMBIENT_LIGHT_MEMBERS \

#define NI_AMBIENT_LIGHT_INCLUDE "NiLight.h" \

#define NI_AMBIENT_LIGHT_PARENT NiLight \

#define NI_AMBIENT_LIGHT_CONSTRUCT \

#define NI_AMBIENT_LIGHT_READ \
NiLight::Read( in, link_stack, version, user_version ); \

#define NI_AMBIENT_LIGHT_WRITE \
NiLight::Write( out, link_map, version, user_version ); \

#define NI_AMBIENT_LIGHT_STRING \
stringstream out; \
out << NiLight::asString(); \
return out.str(); \

#define NI_AMBIENT_LIGHT_FIXLINKS \
NiLight::FixLinks( objects, link_stack, version, user_version ); \

#define NI_AMBIENT_LIGHT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiLight::GetRefs(); \
return refs; \

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
NiTriBasedGeomData::Read( in, link_stack, version, user_version ); \
if ( version <= 0x04000002 ) { \
	NifStream( numParticles, in, version ); \
}; \
if ( version <= 0x0A000100 ) { \
	NifStream( size, in, version ); \
}; \
if ( version <= 0x04000002 ) { \
	NifStream( numActive, in, version ); \
}; \
if ( ( version >= 0x0401000C ) && ( version <= 0x0A000100 ) ) { \
	NifStream( unknownShort, in, version ); \
}; \
NifStream( hasSizes, in, version ); \
if ( (hasSizes != 0) ) { \
	sizes.resize(numVertices); \
	for (uint i1 = 0; i1 < sizes.size(); i1++) { \
		NifStream( sizes[i1], in, version ); \
	}; \
}; \

#define NI_AUTO_NORMAL_PARTICLES_DATA_WRITE \
NiTriBasedGeomData::Write( out, link_map, version, user_version ); \
if ( version <= 0x04000002 ) { \
	NifStream( numParticles, out, version ); \
}; \
if ( version <= 0x0A000100 ) { \
	NifStream( size, out, version ); \
}; \
if ( version <= 0x04000002 ) { \
	NifStream( numActive, out, version ); \
}; \
if ( ( version >= 0x0401000C ) && ( version <= 0x0A000100 ) ) { \
	NifStream( unknownShort, out, version ); \
}; \
NifStream( hasSizes, out, version ); \
if ( (hasSizes != 0) ) { \
	for (uint i1 = 0; i1 < sizes.size(); i1++) { \
		NifStream( sizes[i1], out, version ); \
	}; \
}; \

#define NI_AUTO_NORMAL_PARTICLES_DATA_STRING \
stringstream out; \
out << NiTriBasedGeomData::asString(); \
out << "Num Particles:  " << numParticles << endl; \
out << "Size:  " << size << endl; \
out << "Num Active:  " << numActive << endl; \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Has Sizes:  " << hasSizes << endl; \
if ( (hasSizes != 0) ) { \
	for (uint i1 = 0; i1 < sizes.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Sizes[" << i1 << "]:  " << sizes[i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_FIXLINKS \
NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTriBasedGeomData::GetRefs(); \
return refs; \

#define NI_BINARY_EXTRA_DATA_MEMBERS \
ByteArray binaryData; \

#define NI_BINARY_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_BINARY_EXTRA_DATA_PARENT NiExtraData \

#define NI_BINARY_EXTRA_DATA_CONSTRUCT \

#define NI_BINARY_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( binaryData.dataSize, in, version ); \
if ( ( version >= 0x14000004 ) && ( version <= 0x14000004 ) ) { \
	NifStream( binaryData.unknownInt, in, version ); \
}; \
binaryData.data.resize(binaryData.dataSize); \
for (uint i0 = 0; i0 < binaryData.data.size(); i0++) { \
	NifStream( binaryData.data[i0], in, version ); \
}; \

#define NI_BINARY_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( binaryData.dataSize, out, version ); \
if ( ( version >= 0x14000004 ) && ( version <= 0x14000004 ) ) { \
	NifStream( binaryData.unknownInt, out, version ); \
}; \
for (uint i0 = 0; i0 < binaryData.data.size(); i0++) { \
	NifStream( binaryData.data[i0], out, version ); \
}; \

#define NI_BINARY_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Data Size:  " << binaryData.dataSize << endl; \
out << "Unknown Int:  " << binaryData.unknownInt << endl; \
for (uint i0 = 0; i0 < binaryData.data.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Data[" << i0 << "]:  " << binaryData.data[i0] << endl; \
}; \
return out.str(); \

#define NI_BINARY_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BINARY_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_BLEND_BOOL_INTERPOLATOR_MEMBERS \
byte boolValue; \

#define NI_BLEND_BOOL_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_BLEND_BOOL_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT \
 : boolValue((byte)0) \

#define NI_BLEND_BOOL_INTERPOLATOR_READ \
NiBlendInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( boolValue, in, version ); \

#define NI_BLEND_BOOL_INTERPOLATOR_WRITE \
NiBlendInterpolator::Write( out, link_map, version, user_version ); \
NifStream( boolValue, out, version ); \

#define NI_BLEND_BOOL_INTERPOLATOR_STRING \
stringstream out; \
out << NiBlendInterpolator::asString(); \
out << "Bool Value:  " << boolValue << endl; \
return out.str(); \

#define NI_BLEND_BOOL_INTERPOLATOR_FIXLINKS \
NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_BOOL_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiBlendInterpolator::GetRefs(); \
return refs; \

#define NI_BLEND_FLOAT_INTERPOLATOR_MEMBERS \
float floatValue; \

#define NI_BLEND_FLOAT_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_BLEND_FLOAT_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_BLEND_FLOAT_INTERPOLATOR_CONSTRUCT \
 : floatValue(0.0f) \

#define NI_BLEND_FLOAT_INTERPOLATOR_READ \
NiBlendInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( floatValue, in, version ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_WRITE \
NiBlendInterpolator::Write( out, link_map, version, user_version ); \
NifStream( floatValue, out, version ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_STRING \
stringstream out; \
out << NiBlendInterpolator::asString(); \
out << "Float Value:  " << floatValue << endl; \
return out.str(); \

#define NI_BLEND_FLOAT_INTERPOLATOR_FIXLINKS \
NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_FLOAT_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiBlendInterpolator::GetRefs(); \
return refs; \

#define NI_BLEND_POINT3_INTERPOLATOR_MEMBERS \
Vector3 pointValue; \

#define NI_BLEND_POINT3_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_BLEND_POINT3_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_BLEND_POINT3_INTERPOLATOR_CONSTRUCT \

#define NI_BLEND_POINT3_INTERPOLATOR_READ \
NiBlendInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( pointValue, in, version ); \

#define NI_BLEND_POINT3_INTERPOLATOR_WRITE \
NiBlendInterpolator::Write( out, link_map, version, user_version ); \
NifStream( pointValue, out, version ); \

#define NI_BLEND_POINT3_INTERPOLATOR_STRING \
stringstream out; \
out << NiBlendInterpolator::asString(); \
out << "Point Value:  " << pointValue << endl; \
return out.str(); \

#define NI_BLEND_POINT3_INTERPOLATOR_FIXLINKS \
NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_POINT3_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiBlendInterpolator::GetRefs(); \
return refs; \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_MEMBERS \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_INCLUDE "NiBlendInterpolator.h" \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_PARENT NiBlendInterpolator \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_CONSTRUCT \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_READ \
NiBlendInterpolator::Read( in, link_stack, version, user_version ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_WRITE \
NiBlendInterpolator::Write( out, link_map, version, user_version ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_STRING \
stringstream out; \
out << NiBlendInterpolator::asString(); \
return out.str(); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_FIXLINKS \
NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiBlendInterpolator::GetRefs(); \
return refs; \

#define NI_BONE_L_O_D_CONTROLLER_MEMBERS \
uint numShapeGroups; \
vector<SkinShapeGroup > shapeGroups1; \
uint numShapeGroups2; \
vector<Ref<NiTriShape > > shapeGroups2; \

#define NI_BONE_L_O_D_CONTROLLER_INCLUDE "ABoneLODController.h" \

#define NI_BONE_L_O_D_CONTROLLER_PARENT ABoneLODController \

#define NI_BONE_L_O_D_CONTROLLER_CONSTRUCT \
 : numShapeGroups((uint)0), numShapeGroups2((uint)0) \

#define NI_BONE_L_O_D_CONTROLLER_READ \
uint block_num; \
ABoneLODController::Read( in, link_stack, version, user_version ); \
NifStream( numShapeGroups, in, version ); \
shapeGroups1.resize(numShapeGroups); \
for (uint i0 = 0; i0 < shapeGroups1.size(); i0++) { \
	NifStream( shapeGroups1[i0].numLinkPairs, in, version ); \
	shapeGroups1[i0].linkPairs.resize(shapeGroups1[i0].numLinkPairs); \
	for (uint i1 = 0; i1 < shapeGroups1[i0].linkPairs.size(); i1++) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \
NifStream( numShapeGroups2, in, version ); \
shapeGroups2.resize(numShapeGroups2); \
for (uint i0 = 0; i0 < shapeGroups2.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_BONE_L_O_D_CONTROLLER_WRITE \
ABoneLODController::Write( out, link_map, version, user_version ); \
NifStream( numShapeGroups, out, version ); \
for (uint i0 = 0; i0 < shapeGroups1.size(); i0++) { \
	NifStream( shapeGroups1[i0].numLinkPairs, out, version ); \
	for (uint i1 = 0; i1 < shapeGroups1[i0].linkPairs.size(); i1++) { \
		if ( shapeGroups1[i0].linkPairs[i1].shape != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(shapeGroups1[i0].linkPairs[i1].shape)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
		if ( shapeGroups1[i0].linkPairs[i1].skinInstance != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(shapeGroups1[i0].linkPairs[i1].skinInstance)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \
NifStream( numShapeGroups2, out, version ); \
for (uint i0 = 0; i0 < shapeGroups2.size(); i0++) { \
	if ( shapeGroups2[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(shapeGroups2[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_BONE_L_O_D_CONTROLLER_STRING \
stringstream out; \
out << ABoneLODController::asString(); \
out << "Num Shape Groups:  " << numShapeGroups << endl; \
for (uint i0 = 0; i0 < shapeGroups1.size(); i0++) { \
	out << "  Num Link Pairs:  " << shapeGroups1[i0].numLinkPairs << endl; \
	for (uint i1 = 0; i1 < shapeGroups1[i0].linkPairs.size(); i1++) { \
		out << "    Shape:  " << shapeGroups1[i0].linkPairs[i1].shape << endl; \
		out << "    Skin Instance:  " << shapeGroups1[i0].linkPairs[i1].skinInstance << endl; \
	}; \
}; \
out << "Num Shape Groups 2:  " << numShapeGroups2 << endl; \
for (uint i0 = 0; i0 < shapeGroups2.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Shape Groups 2[" << i0 << "]:  " << shapeGroups2[i0] << endl; \
}; \
return out.str(); \

#define NI_BONE_L_O_D_CONTROLLER_FIXLINKS \
ABoneLODController::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < shapeGroups1.size(); i0++) { \
	for (uint i1 = 0; i1 < shapeGroups1[i0].linkPairs.size(); i1++) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			shapeGroups1[i0].linkPairs[i1].shape = DynamicCast<NiTriShape>(objects[link_stack.front()]); \
			if ( shapeGroups1[i0].linkPairs[i1].shape == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			shapeGroups1[i0].linkPairs[i1].shape = NULL; \
		link_stack.pop_front(); \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			shapeGroups1[i0].linkPairs[i1].skinInstance = DynamicCast<NiSkinInstance>(objects[link_stack.front()]); \
			if ( shapeGroups1[i0].linkPairs[i1].skinInstance == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			shapeGroups1[i0].linkPairs[i1].skinInstance = NULL; \
		link_stack.pop_front(); \
	}; \
}; \
for (uint i0 = 0; i0 < shapeGroups2.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		shapeGroups2[i0] = DynamicCast<NiTriShape>(objects[link_stack.front()]); \
		if ( shapeGroups2[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		shapeGroups2[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_BONE_L_O_D_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = ABoneLODController::GetRefs(); \
for (uint i0 = 0; i0 < shapeGroups1.size(); i0++) { \
	for (uint i1 = 0; i1 < shapeGroups1[i0].linkPairs.size(); i1++) { \
		if ( shapeGroups1[i0].linkPairs[i1].shape != NULL ) \
			refs.push_back(StaticCast<NiObject>(shapeGroups1[i0].linkPairs[i1].shape)); \
		if ( shapeGroups1[i0].linkPairs[i1].skinInstance != NULL ) \
			refs.push_back(StaticCast<NiObject>(shapeGroups1[i0].linkPairs[i1].skinInstance)); \
	}; \
}; \
for (uint i0 = 0; i0 < shapeGroups2.size(); i0++) { \
	if ( shapeGroups2[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(shapeGroups2[i0])); \
}; \
return refs; \

#define NI_BOOL_DATA_MEMBERS \
KeyGroup<byte > data; \

#define NI_BOOL_DATA_INCLUDE "AKeyedData.h" \

#define NI_BOOL_DATA_PARENT AKeyedData \

#define NI_BOOL_DATA_CONSTRUCT \

#define NI_BOOL_DATA_READ \
AKeyedData::Read( in, link_stack, version, user_version ); \
NifStream( data.numKeys, in, version ); \
if ( (data.numKeys != 0) ) { \
	NifStream( data.interpolation, in, version ); \
}; \
data.keys.resize(data.numKeys); \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	NifStream( data.keys[i0], in, version, data.interpolation ); \
}; \

#define NI_BOOL_DATA_WRITE \
AKeyedData::Write( out, link_map, version, user_version ); \
NifStream( data.numKeys, out, version ); \
if ( (data.numKeys != 0) ) { \
	NifStream( data.interpolation, out, version ); \
}; \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	NifStream( data.keys[i0], out, version, data.interpolation ); \
}; \

#define NI_BOOL_DATA_STRING \
stringstream out; \
out << AKeyedData::asString(); \
out << "Num Keys:  " << data.numKeys << endl; \
if ( (data.numKeys != 0) ) { \
	out << "  Interpolation:  " << data.interpolation << endl; \
}; \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Keys[" << i0 << "]:  " << data.keys[i0] << endl; \
}; \
return out.str(); \

#define NI_BOOL_DATA_FIXLINKS \
AKeyedData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BOOL_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = AKeyedData::GetRefs(); \
return refs; \

#define NI_BOOLEAN_EXTRA_DATA_MEMBERS \
byte booleanData; \

#define NI_BOOLEAN_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_BOOLEAN_EXTRA_DATA_PARENT NiExtraData \

#define NI_BOOLEAN_EXTRA_DATA_CONSTRUCT \
 : booleanData((byte)0) \

#define NI_BOOLEAN_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( booleanData, in, version ); \

#define NI_BOOLEAN_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( booleanData, out, version ); \

#define NI_BOOLEAN_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Boolean Data:  " << booleanData << endl; \
return out.str(); \

#define NI_BOOLEAN_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BOOLEAN_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_BOOL_INTERPOLATOR_MEMBERS \
bool boolValue; \
Ref<NiBoolData > data; \

#define NI_BOOL_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_BOOL_INTERPOLATOR_PARENT NiInterpolator \

#define NI_BOOL_INTERPOLATOR_CONSTRUCT \
 : boolValue(false), data(NULL) \

#define NI_BOOL_INTERPOLATOR_READ \
uint block_num; \
NiInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( boolValue, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_BOOL_INTERPOLATOR_WRITE \
NiInterpolator::Write( out, link_map, version, user_version ); \
NifStream( boolValue, out, version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_BOOL_INTERPOLATOR_STRING \
stringstream out; \
out << NiInterpolator::asString(); \
out << "Bool Value:  " << boolValue << endl; \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_BOOL_INTERPOLATOR_FIXLINKS \
NiInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiBoolData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define NI_BOOL_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiInterpolator::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS \
byte boolValue; \
Ref<NiBoolData > data; \

#define NI_BOOL_TIMELINE_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_BOOL_TIMELINE_INTERPOLATOR_PARENT NiInterpolator \

#define NI_BOOL_TIMELINE_INTERPOLATOR_CONSTRUCT \
 : boolValue((byte)0), data(NULL) \

#define NI_BOOL_TIMELINE_INTERPOLATOR_READ \
uint block_num; \
NiInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( boolValue, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_WRITE \
NiInterpolator::Write( out, link_map, version, user_version ); \
NifStream( boolValue, out, version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_STRING \
stringstream out; \
out << NiInterpolator::asString(); \
out << "Bool Value:  " << boolValue << endl; \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_FIXLINKS \
NiInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiBoolData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define NI_BOOL_TIMELINE_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiInterpolator::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_B_S_BONE_L_O_D_CONTROLLER_MEMBERS \

#define NI_B_S_BONE_L_O_D_CONTROLLER_INCLUDE "ABoneLODController.h" \

#define NI_B_S_BONE_L_O_D_CONTROLLER_PARENT ABoneLODController \

#define NI_B_S_BONE_L_O_D_CONTROLLER_CONSTRUCT \

#define NI_B_S_BONE_L_O_D_CONTROLLER_READ \
ABoneLODController::Read( in, link_stack, version, user_version ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_WRITE \
ABoneLODController::Write( out, link_map, version, user_version ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_STRING \
stringstream out; \
out << ABoneLODController::asString(); \
return out.str(); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_FIXLINKS \
ABoneLODController::FixLinks( objects, link_stack, version, user_version ); \

#define NI_B_S_BONE_L_O_D_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = ABoneLODController::GetRefs(); \
return refs; \

#define NI_B_SPLINE_BASIS_DATA_MEMBERS \
uint unknownInt; \

#define NI_B_SPLINE_BASIS_DATA_INCLUDE "NiObject.h" \

#define NI_B_SPLINE_BASIS_DATA_PARENT NiObject \

#define NI_B_SPLINE_BASIS_DATA_CONSTRUCT \
 : unknownInt((uint)0) \

#define NI_B_SPLINE_BASIS_DATA_READ \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( unknownInt, in, version ); \

#define NI_B_SPLINE_BASIS_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( unknownInt, out, version ); \

#define NI_B_SPLINE_BASIS_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Unknown Int:  " << unknownInt << endl; \
return out.str(); \

#define NI_B_SPLINE_BASIS_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_BASIS_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_MEMBERS \
float unknownFloats[6]; \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_INCLUDE "NiBSplineInterpolator.h" \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_PARENT NiBSplineInterpolator \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_CONSTRUCT \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_READ \
NiBSplineInterpolator::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownFloats[i0], in, version ); \
}; \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_WRITE \
NiBSplineInterpolator::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownFloats[i0], out, version ); \
}; \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_STRING \
stringstream out; \
out << NiBSplineInterpolator::asString(); \
for (uint i0 = 0; i0 < 6; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats[" << i0 << "]:  " << unknownFloats[i0] << endl; \
}; \
return out.str(); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_FIXLINKS \
NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiBSplineInterpolator::GetRefs(); \
return refs; \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_MEMBERS \
Ref<NiBSplineData > data; \
Ref<NiObject > unknownLink; \
float unknownFloats[6]; \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_INCLUDE "NiBSplineInterpolator.h" \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT NiBSplineInterpolator \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_CONSTRUCT \
 : data(NULL), unknownLink(NULL) \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_READ \
uint block_num; \
NiBSplineInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownFloats[i0], in, version ); \
}; \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_WRITE \
NiBSplineInterpolator::Write( out, link_map, version, user_version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( unknownLink != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
for (uint i0 = 0; i0 < 6; i0++) { \
	NifStream( unknownFloats[i0], out, version ); \
}; \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_STRING \
stringstream out; \
out << NiBSplineInterpolator::asString(); \
out << "Data:  " << data << endl; \
out << "Unknown Link:  " << unknownLink << endl; \
for (uint i0 = 0; i0 < 6; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats[" << i0 << "]:  " << unknownFloats[i0] << endl; \
}; \
return out.str(); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_FIXLINKS \
NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiBSplineData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( unknownLink == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink = NULL; \
link_stack.pop_front(); \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiBSplineInterpolator::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
if ( unknownLink != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink)); \
return refs; \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS \
Ref<NiBSplineData > data; \
Ref<NiBSplineBasisData > basisData; \
float unknown4[17]; \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_INCLUDE "NiBSplineInterpolator.h" \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT NiBSplineInterpolator \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_CONSTRUCT \
 : data(NULL), basisData(NULL) \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_READ \
uint block_num; \
NiBSplineInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
for (uint i0 = 0; i0 < 17; i0++) { \
	NifStream( unknown4[i0], in, version ); \
}; \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_WRITE \
NiBSplineInterpolator::Write( out, link_map, version, user_version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( basisData != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(basisData)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
for (uint i0 = 0; i0 < 17; i0++) { \
	NifStream( unknown4[i0], out, version ); \
}; \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_STRING \
stringstream out; \
out << NiBSplineInterpolator::asString(); \
out << "Data:  " << data << endl; \
out << "Basis Data:  " << basisData << endl; \
for (uint i0 = 0; i0 < 17; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown4[" << i0 << "]:  " << unknown4[i0] << endl; \
}; \
return out.str(); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_FIXLINKS \
NiBSplineInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiBSplineData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	basisData = DynamicCast<NiBSplineBasisData>(objects[link_stack.front()]); \
	if ( basisData == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	basisData = NULL; \
link_stack.pop_front(); \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiBSplineInterpolator::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
if ( basisData != NULL ) \
	refs.push_back(StaticCast<NiObject>(basisData)); \
return refs; \

#define NI_B_SPLINE_DATA_MEMBERS \
uint unknownInt; \
uint count; \
vector< array<byte,2> > unknownData; \

#define NI_B_SPLINE_DATA_INCLUDE "NiObject.h" \

#define NI_B_SPLINE_DATA_PARENT NiObject \

#define NI_B_SPLINE_DATA_CONSTRUCT \
 : unknownInt((uint)0), count((uint)0) \

#define NI_B_SPLINE_DATA_READ \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( unknownInt, in, version ); \
NifStream( count, in, version ); \
unknownData.resize(count); \
for (uint i0 = 0; i0 < unknownData.size(); i0++) { \
	for (uint i1 = 0; i1 < 2; i1++) { \
		NifStream( unknownData[i0][i1], in, version ); \
	}; \
}; \

#define NI_B_SPLINE_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( unknownInt, out, version ); \
NifStream( count, out, version ); \
for (uint i0 = 0; i0 < unknownData.size(); i0++) { \
	for (uint i1 = 0; i1 < 2; i1++) { \
		NifStream( unknownData[i0][i1], out, version ); \
	}; \
}; \

#define NI_B_SPLINE_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Unknown Int:  " << unknownInt << endl; \
out << "Count:  " << count << endl; \
for (uint i0 = 0; i0 < unknownData.size(); i0++) { \
	for (uint i1 = 0; i1 < 2; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Data[" << i0 << "][" << i1 << "]:  " << unknownData[i0][i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_B_SPLINE_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_B_SPLINE_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

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
uint block_num; \
NiAVObject::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknownShort, in, version ); \
}; \
NifStream( frustumLeft, in, version ); \
NifStream( frustumRight, in, version ); \
NifStream( frustumTop, in, version ); \
NifStream( frustumBottom, in, version ); \
NifStream( frustumNear, in, version ); \
NifStream( frustumFar, in, version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( useOrthographicProjection, in, version ); \
}; \
NifStream( viewportLeft, in, version ); \
NifStream( viewportRight, in, version ); \
NifStream( viewportTop, in, version ); \
NifStream( viewportBottom, in, version ); \
NifStream( lodAdjust, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( unknownInt, in, version ); \
if ( version >= 0x04020100 ) { \
	NifStream( unknownInt2, in, version ); \
}; \

#define NI_CAMERA_WRITE \
NiAVObject::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknownShort, out, version ); \
}; \
NifStream( frustumLeft, out, version ); \
NifStream( frustumRight, out, version ); \
NifStream( frustumTop, out, version ); \
NifStream( frustumBottom, out, version ); \
NifStream( frustumNear, out, version ); \
NifStream( frustumFar, out, version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( useOrthographicProjection, out, version ); \
}; \
NifStream( viewportLeft, out, version ); \
NifStream( viewportRight, out, version ); \
NifStream( viewportTop, out, version ); \
NifStream( viewportBottom, out, version ); \
NifStream( lodAdjust, out, version ); \
if ( unknownLink_ != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink_)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( unknownInt, out, version ); \
if ( version >= 0x04020100 ) { \
	NifStream( unknownInt2, out, version ); \
}; \

#define NI_CAMERA_STRING \
stringstream out; \
out << NiAVObject::asString(); \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Frustum Left:  " << frustumLeft << endl; \
out << "Frustum Right:  " << frustumRight << endl; \
out << "Frustum Top:  " << frustumTop << endl; \
out << "Frustum Bottom:  " << frustumBottom << endl; \
out << "Frustum Near:  " << frustumNear << endl; \
out << "Frustum Far:  " << frustumFar << endl; \
out << "Use Orthographic Projection:  " << useOrthographicProjection << endl; \
out << "Viewport Left:  " << viewportLeft << endl; \
out << "Viewport Right:  " << viewportRight << endl; \
out << "Viewport Top:  " << viewportTop << endl; \
out << "Viewport Bottom:  " << viewportBottom << endl; \
out << "LOD Adjust:  " << lodAdjust << endl; \
out << "Unknown Link?:  " << unknownLink_ << endl; \
out << "Unknown Int:  " << unknownInt << endl; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
return out.str(); \

#define NI_CAMERA_FIXLINKS \
NiAVObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink_ = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( unknownLink_ == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink_ = NULL; \
link_stack.pop_front(); \

#define NI_CAMERA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiAVObject::GetRefs(); \
if ( unknownLink_ != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink_)); \
return refs; \

#define NI_COLLISION_DATA_MEMBERS \
NiNode * targetNode; \
uint unknown2; \
byte unknown3; \
uint collisionType; \
uint unknown5; \
Vector3 unknown7; \
float unknown6[8]; \
float unknown8[15]; \

#define NI_COLLISION_DATA_INCLUDE "NiObject.h" \

#define NI_COLLISION_DATA_PARENT NiObject \

#define NI_COLLISION_DATA_CONSTRUCT \
 : targetNode(NULL), unknown2((uint)0), unknown3((byte)0), collisionType((uint)0), unknown5((uint)0) \

#define NI_COLLISION_DATA_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( unknown2, in, version ); \
NifStream( unknown3, in, version ); \
NifStream( collisionType, in, version ); \
if ( (collisionType == 0) ) { \
	NifStream( unknown5, in, version ); \
	NifStream( unknown7, in, version ); \
}; \
if ( (collisionType == 2) ) { \
	for (uint i1 = 0; i1 < 8; i1++) { \
		NifStream( unknown6[i1], in, version ); \
	}; \
}; \
if ( (collisionType == 1) ) { \
	for (uint i1 = 0; i1 < 15; i1++) { \
		NifStream( unknown8[i1], in, version ); \
	}; \
}; \

#define NI_COLLISION_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
if ( targetNode != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(targetNode)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( unknown2, out, version ); \
NifStream( unknown3, out, version ); \
NifStream( collisionType, out, version ); \
if ( (collisionType == 0) ) { \
	NifStream( unknown5, out, version ); \
	NifStream( unknown7, out, version ); \
}; \
if ( (collisionType == 2) ) { \
	for (uint i1 = 0; i1 < 8; i1++) { \
		NifStream( unknown6[i1], out, version ); \
	}; \
}; \
if ( (collisionType == 1) ) { \
	for (uint i1 = 0; i1 < 15; i1++) { \
		NifStream( unknown8[i1], out, version ); \
	}; \
}; \

#define NI_COLLISION_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Target Node:  " << targetNode << endl; \
out << "Unknown2:  " << unknown2 << endl; \
out << "Unknown3:  " << unknown3 << endl; \
out << "Collision Type:  " << collisionType << endl; \
if ( (collisionType == 0) ) { \
	out << "  Unknown5:  " << unknown5 << endl; \
	out << "  Unknown7:  " << unknown7 << endl; \
}; \
if ( (collisionType == 2) ) { \
	for (uint i1 = 0; i1 < 8; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown6[" << i1 << "]:  " << unknown6[i1] << endl; \
	}; \
}; \
if ( (collisionType == 1) ) { \
	for (uint i1 = 0; i1 < 15; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown8[" << i1 << "]:  " << unknown8[i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_COLLISION_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	targetNode = DynamicCast<NiNode>(objects[link_stack.front()]); \
	if ( targetNode == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	targetNode = NULL; \
link_stack.pop_front(); \

#define NI_COLLISION_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_COLOR_DATA_MEMBERS \
KeyGroup<Color4 > data; \

#define NI_COLOR_DATA_INCLUDE "AKeyedData.h" \

#define NI_COLOR_DATA_PARENT AKeyedData \

#define NI_COLOR_DATA_CONSTRUCT \

#define NI_COLOR_DATA_READ \
AKeyedData::Read( in, link_stack, version, user_version ); \
NifStream( data.numKeys, in, version ); \
if ( (data.numKeys != 0) ) { \
	NifStream( data.interpolation, in, version ); \
}; \
data.keys.resize(data.numKeys); \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	NifStream( data.keys[i0], in, version, data.interpolation ); \
}; \

#define NI_COLOR_DATA_WRITE \
AKeyedData::Write( out, link_map, version, user_version ); \
NifStream( data.numKeys, out, version ); \
if ( (data.numKeys != 0) ) { \
	NifStream( data.interpolation, out, version ); \
}; \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	NifStream( data.keys[i0], out, version, data.interpolation ); \
}; \

#define NI_COLOR_DATA_STRING \
stringstream out; \
out << AKeyedData::asString(); \
out << "Num Keys:  " << data.numKeys << endl; \
if ( (data.numKeys != 0) ) { \
	out << "  Interpolation:  " << data.interpolation << endl; \
}; \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Keys[" << i0 << "]:  " << data.keys[i0] << endl; \
}; \
return out.str(); \

#define NI_COLOR_DATA_FIXLINKS \
AKeyedData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_COLOR_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = AKeyedData::GetRefs(); \
return refs; \

#define NI_COLOR_EXTRA_DATA_MEMBERS \
Color4 data; \

#define NI_COLOR_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_COLOR_EXTRA_DATA_PARENT NiExtraData \

#define NI_COLOR_EXTRA_DATA_CONSTRUCT \

#define NI_COLOR_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( data, in, version ); \

#define NI_COLOR_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( data, out, version ); \

#define NI_COLOR_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_COLOR_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_COLOR_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_CONTROLLER_MANAGER_MEMBERS \
bool cumulative; \
uint numControllerSequences; \
vector<Ref<NiControllerSequence > > controllerSequences; \
Ref<NiDefaultAVObjectPalette > objectPalette; \

#define NI_CONTROLLER_MANAGER_INCLUDE "NiTimeController.h" \

#define NI_CONTROLLER_MANAGER_PARENT NiTimeController \

#define NI_CONTROLLER_MANAGER_CONSTRUCT \
 : cumulative(false), numControllerSequences((uint)0), objectPalette(NULL) \

#define NI_CONTROLLER_MANAGER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
NifStream( cumulative, in, version ); \
NifStream( numControllerSequences, in, version ); \
controllerSequences.resize(numControllerSequences); \
for (uint i0 = 0; i0 < controllerSequences.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_CONTROLLER_MANAGER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
NifStream( cumulative, out, version ); \
NifStream( numControllerSequences, out, version ); \
for (uint i0 = 0; i0 < controllerSequences.size(); i0++) { \
	if ( controllerSequences[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(controllerSequences[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( objectPalette != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(objectPalette)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_CONTROLLER_MANAGER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Cumulative:  " << cumulative << endl; \
out << "Num Controller Sequences:  " << numControllerSequences << endl; \
for (uint i0 = 0; i0 < controllerSequences.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Controller Sequences[" << i0 << "]:  " << controllerSequences[i0] << endl; \
}; \
out << "Object Palette:  " << objectPalette << endl; \
return out.str(); \

#define NI_CONTROLLER_MANAGER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < controllerSequences.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		controllerSequences[i0] = DynamicCast<NiControllerSequence>(objects[link_stack.front()]); \
		if ( controllerSequences[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		controllerSequences[i0] = NULL; \
	link_stack.pop_front(); \
}; \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	objectPalette = DynamicCast<NiDefaultAVObjectPalette>(objects[link_stack.front()]); \
	if ( objectPalette == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	objectPalette = NULL; \
link_stack.pop_front(); \

#define NI_CONTROLLER_MANAGER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
for (uint i0 = 0; i0 < controllerSequences.size(); i0++) { \
	if ( controllerSequences[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(controllerSequences[i0])); \
}; \
if ( objectPalette != NULL ) \
	refs.push_back(StaticCast<NiObject>(objectPalette)); \
return refs; \

#define NI_CONTROLLER_SEQUENCE_MEMBERS \
string name; \
ControllerLink textKeys; \
uint numControlledBlocks; \
uint unknownInt1; \
vector<ControllerLink > controlledBlocks; \
float weight; \
Ref<NiTextKeyExtraData > textKeys2; \
uint cycleType; \
uint unknownInt0; \
float frequency; \
float startTime; \
float stopTime; \
float unknownFloat2; \
byte unknownByte; \
NiControllerManager * manager; \
string unknownString; \
Ref<NiStringPalette > stringPalette; \

#define NI_CONTROLLER_SEQUENCE_INCLUDE "NiObject.h" \

#define NI_CONTROLLER_SEQUENCE_PARENT NiObject \

#define NI_CONTROLLER_SEQUENCE_CONSTRUCT \
 : numControlledBlocks((uint)0), unknownInt1((uint)0), weight(1.0f), textKeys2(NULL), cycleType((uint)0), unknownInt0((uint)0), frequency(0.0f), startTime(0.0f), stopTime(0.0f), unknownFloat2(0.0f), unknownByte((byte)0), manager(NULL), stringPalette(NULL) \

#define NI_CONTROLLER_SEQUENCE_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( name, in, version ); \
if ( version <= 0x0A010000 ) { \
	if ( version <= 0x0A010000 ) { \
		NifStream( textKeys.name, in, version ); \
	}; \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	if ( version >= 0x0A01006A ) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
		NifStream( textKeys.unknownShort0, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( user_version == 11 ) ) { \
		NifStream( textKeys.priority_, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.nodeName, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.nodeNameOffset, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.propertyType, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.propertyTypeOffset, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.controllerType, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.controllerTypeOffset, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.variable1, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.variableOffset1, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.variable2, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.variableOffset2, in, version ); \
	}; \
}; \
NifStream( numControlledBlocks, in, version ); \
if ( version >= 0x0A01006A ) { \
	NifStream( unknownInt1, in, version ); \
}; \
controlledBlocks.resize(numControlledBlocks); \
for (uint i0 = 0; i0 < controlledBlocks.size(); i0++) { \
	if ( version <= 0x0A010000 ) { \
		NifStream( controlledBlocks[i0].name, in, version ); \
	}; \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	if ( version >= 0x0A01006A ) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
		NifStream( controlledBlocks[i0].unknownShort0, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( user_version == 11 ) ) { \
		NifStream( controlledBlocks[i0].priority_, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].nodeName, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].nodeNameOffset, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].propertyType, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].propertyTypeOffset, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].controllerType, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].controllerTypeOffset, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].variable1, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].variableOffset1, in, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].variable2, in, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].variableOffset2, in, version ); \
	}; \
}; \
if ( version >= 0x0A01006A ) { \
	NifStream( weight, in, version ); \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( cycleType, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
	NifStream( unknownInt0, in, version ); \
}; \
if ( version >= 0x0A01006A ) { \
	NifStream( frequency, in, version ); \
	NifStream( startTime, in, version ); \
	NifStream( stopTime, in, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x0A020000 ) ) { \
	NifStream( unknownFloat2, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
	NifStream( unknownByte, in, version ); \
}; \
if ( version >= 0x0A01006A ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( unknownString, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_CONTROLLER_SEQUENCE_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( name, out, version ); \
if ( version <= 0x0A010000 ) { \
	if ( version <= 0x0A010000 ) { \
		NifStream( textKeys.name, out, version ); \
	}; \
	if ( textKeys.interpolator != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(textKeys.interpolator)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	if ( version >= 0x0A01006A ) { \
		if ( textKeys.unknownLink1 != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(textKeys.unknownLink1)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		if ( textKeys.unknownLink2 != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(textKeys.unknownLink2)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
		NifStream( textKeys.unknownShort0, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( user_version == 11 ) ) { \
		NifStream( textKeys.priority_, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		if ( textKeys.stringPalette != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(textKeys.stringPalette)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.nodeName, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.nodeNameOffset, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.propertyType, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.propertyTypeOffset, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.controllerType, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.controllerTypeOffset, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.variable1, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.variableOffset1, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( textKeys.variable2, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( textKeys.variableOffset2, out, version ); \
	}; \
}; \
NifStream( numControlledBlocks, out, version ); \
if ( version >= 0x0A01006A ) { \
	NifStream( unknownInt1, out, version ); \
}; \
for (uint i0 = 0; i0 < controlledBlocks.size(); i0++) { \
	if ( version <= 0x0A010000 ) { \
		NifStream( controlledBlocks[i0].name, out, version ); \
	}; \
	if ( controlledBlocks[i0].interpolator != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i0].interpolator)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	if ( version >= 0x0A01006A ) { \
		if ( controlledBlocks[i0].unknownLink1 != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i0].unknownLink1)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		if ( controlledBlocks[i0].unknownLink2 != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i0].unknownLink2)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
		NifStream( controlledBlocks[i0].unknownShort0, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( user_version == 11 ) ) { \
		NifStream( controlledBlocks[i0].priority_, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		if ( controlledBlocks[i0].stringPalette != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(controlledBlocks[i0].stringPalette)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].nodeName, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].nodeNameOffset, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].propertyType, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].propertyTypeOffset, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].controllerType, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].controllerTypeOffset, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].variable1, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].variableOffset1, out, version ); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( controlledBlocks[i0].variable2, out, version ); \
	}; \
	if ( version >= 0x0A020000 ) { \
		NifStream( controlledBlocks[i0].variableOffset2, out, version ); \
	}; \
}; \
if ( version >= 0x0A01006A ) { \
	NifStream( weight, out, version ); \
	if ( textKeys2 != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(textKeys2)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( cycleType, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
	NifStream( unknownInt0, out, version ); \
}; \
if ( version >= 0x0A01006A ) { \
	NifStream( frequency, out, version ); \
	NifStream( startTime, out, version ); \
	NifStream( stopTime, out, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x0A020000 ) ) { \
	NifStream( unknownFloat2, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
	NifStream( unknownByte, out, version ); \
}; \
if ( version >= 0x0A01006A ) { \
	if ( manager != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(manager)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( unknownString, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
	if ( stringPalette != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(stringPalette)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_CONTROLLER_SEQUENCE_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Name:  " << name << endl; \
out << "Name:  " << textKeys.name << endl; \
out << "Interpolator:  " << textKeys.interpolator << endl; \
out << "Unknown Link 1:  " << textKeys.unknownLink1 << endl; \
out << "Unknown Link 2:  " << textKeys.unknownLink2 << endl; \
out << "Unknown Short 0:  " << textKeys.unknownShort0 << endl; \
out << "Priority?:  " << textKeys.priority_ << endl; \
out << "String Palette:  " << textKeys.stringPalette << endl; \
out << "Node Name:  " << textKeys.nodeName << endl; \
out << "Node Name Offset:  " << textKeys.nodeNameOffset << endl; \
out << "Property Type:  " << textKeys.propertyType << endl; \
out << "Property Type Offset:  " << textKeys.propertyTypeOffset << endl; \
out << "Controller Type:  " << textKeys.controllerType << endl; \
out << "Controller Type Offset:  " << textKeys.controllerTypeOffset << endl; \
out << "Variable 1:  " << textKeys.variable1 << endl; \
out << "Variable Offset 1:  " << textKeys.variableOffset1 << endl; \
out << "Variable 2:  " << textKeys.variable2 << endl; \
out << "Variable Offset 2:  " << textKeys.variableOffset2 << endl; \
out << "Num Controlled Blocks:  " << numControlledBlocks << endl; \
out << "Unknown Int 1:  " << unknownInt1 << endl; \
for (uint i0 = 0; i0 < controlledBlocks.size(); i0++) { \
	out << "  Name:  " << controlledBlocks[i0].name << endl; \
	out << "  Interpolator:  " << controlledBlocks[i0].interpolator << endl; \
	out << "  Unknown Link 1:  " << controlledBlocks[i0].unknownLink1 << endl; \
	out << "  Unknown Link 2:  " << controlledBlocks[i0].unknownLink2 << endl; \
	out << "  Unknown Short 0:  " << controlledBlocks[i0].unknownShort0 << endl; \
	out << "  Priority?:  " << controlledBlocks[i0].priority_ << endl; \
	out << "  String Palette:  " << controlledBlocks[i0].stringPalette << endl; \
	out << "  Node Name:  " << controlledBlocks[i0].nodeName << endl; \
	out << "  Node Name Offset:  " << controlledBlocks[i0].nodeNameOffset << endl; \
	out << "  Property Type:  " << controlledBlocks[i0].propertyType << endl; \
	out << "  Property Type Offset:  " << controlledBlocks[i0].propertyTypeOffset << endl; \
	out << "  Controller Type:  " << controlledBlocks[i0].controllerType << endl; \
	out << "  Controller Type Offset:  " << controlledBlocks[i0].controllerTypeOffset << endl; \
	out << "  Variable 1:  " << controlledBlocks[i0].variable1 << endl; \
	out << "  Variable Offset 1:  " << controlledBlocks[i0].variableOffset1 << endl; \
	out << "  Variable 2:  " << controlledBlocks[i0].variable2 << endl; \
	out << "  Variable Offset 2:  " << controlledBlocks[i0].variableOffset2 << endl; \
}; \
out << "Weight:  " << weight << endl; \
out << "Text Keys 2:  " << textKeys2 << endl; \
out << "Cycle Type:  " << cycleType << endl; \
out << "Unknown Int 0:  " << unknownInt0 << endl; \
out << "Frequency:  " << frequency << endl; \
out << "Start Time:  " << startTime << endl; \
out << "Stop Time:  " << stopTime << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
out << "Unknown Byte:  " << unknownByte << endl; \
out << "Manager:  " << manager << endl; \
out << "Unknown String:  " << unknownString << endl; \
out << "String Palette:  " << stringPalette << endl; \
return out.str(); \

#define NI_CONTROLLER_SEQUENCE_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		textKeys.interpolator = DynamicCast<NiInterpolator>(objects[link_stack.front()]); \
		if ( textKeys.interpolator == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		textKeys.interpolator = NULL; \
	link_stack.pop_front(); \
	if ( version >= 0x0A01006A ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			textKeys.unknownLink1 = DynamicCast<NiObject>(objects[link_stack.front()]); \
			if ( textKeys.unknownLink1 == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			textKeys.unknownLink1 = NULL; \
		link_stack.pop_front(); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			textKeys.unknownLink2 = DynamicCast<NiObject>(objects[link_stack.front()]); \
			if ( textKeys.unknownLink2 == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			textKeys.unknownLink2 = NULL; \
		link_stack.pop_front(); \
	}; \
	if ( version >= 0x0A020000 ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			textKeys.stringPalette = DynamicCast<NiStringPalette>(objects[link_stack.front()]); \
			if ( textKeys.stringPalette == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			textKeys.stringPalette = NULL; \
		link_stack.pop_front(); \
	}; \
}; \
for (uint i0 = 0; i0 < controlledBlocks.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		controlledBlocks[i0].interpolator = DynamicCast<NiInterpolator>(objects[link_stack.front()]); \
		if ( controlledBlocks[i0].interpolator == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		controlledBlocks[i0].interpolator = NULL; \
	link_stack.pop_front(); \
	if ( version >= 0x0A01006A ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			controlledBlocks[i0].unknownLink1 = DynamicCast<NiObject>(objects[link_stack.front()]); \
			if ( controlledBlocks[i0].unknownLink1 == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			controlledBlocks[i0].unknownLink1 = NULL; \
		link_stack.pop_front(); \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			controlledBlocks[i0].unknownLink2 = DynamicCast<NiObject>(objects[link_stack.front()]); \
			if ( controlledBlocks[i0].unknownLink2 == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			controlledBlocks[i0].unknownLink2 = NULL; \
		link_stack.pop_front(); \
	}; \
	if ( version >= 0x0A020000 ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			controlledBlocks[i0].stringPalette = DynamicCast<NiStringPalette>(objects[link_stack.front()]); \
			if ( controlledBlocks[i0].stringPalette == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			controlledBlocks[i0].stringPalette = NULL; \
		link_stack.pop_front(); \
	}; \
}; \
if ( version >= 0x0A01006A ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		textKeys2 = DynamicCast<NiTextKeyExtraData>(objects[link_stack.front()]); \
		if ( textKeys2 == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		textKeys2 = NULL; \
	link_stack.pop_front(); \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		manager = DynamicCast<NiControllerManager>(objects[link_stack.front()]); \
		if ( manager == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		manager = NULL; \
	link_stack.pop_front(); \
}; \
if ( version >= 0x0A020000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		stringPalette = DynamicCast<NiStringPalette>(objects[link_stack.front()]); \
		if ( stringPalette == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		stringPalette = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_CONTROLLER_SEQUENCE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( textKeys.interpolator != NULL ) \
	refs.push_back(StaticCast<NiObject>(textKeys.interpolator)); \
if ( textKeys.unknownLink1 != NULL ) \
	refs.push_back(StaticCast<NiObject>(textKeys.unknownLink1)); \
if ( textKeys.unknownLink2 != NULL ) \
	refs.push_back(StaticCast<NiObject>(textKeys.unknownLink2)); \
if ( textKeys.stringPalette != NULL ) \
	refs.push_back(StaticCast<NiObject>(textKeys.stringPalette)); \
for (uint i0 = 0; i0 < controlledBlocks.size(); i0++) { \
	if ( controlledBlocks[i0].interpolator != NULL ) \
		refs.push_back(StaticCast<NiObject>(controlledBlocks[i0].interpolator)); \
	if ( controlledBlocks[i0].unknownLink1 != NULL ) \
		refs.push_back(StaticCast<NiObject>(controlledBlocks[i0].unknownLink1)); \
	if ( controlledBlocks[i0].unknownLink2 != NULL ) \
		refs.push_back(StaticCast<NiObject>(controlledBlocks[i0].unknownLink2)); \
	if ( controlledBlocks[i0].stringPalette != NULL ) \
		refs.push_back(StaticCast<NiObject>(controlledBlocks[i0].stringPalette)); \
}; \
if ( textKeys2 != NULL ) \
	refs.push_back(StaticCast<NiObject>(textKeys2)); \
if ( stringPalette != NULL ) \
	refs.push_back(StaticCast<NiObject>(stringPalette)); \
return refs; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS \
uint unknownInt; \
uint numObjs; \
vector<AVObject > objs; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_INCLUDE "NiObject.h" \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT NiObject \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_CONSTRUCT \
 : unknownInt((uint)0), numObjs((uint)0) \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( unknownInt, in, version ); \
NifStream( numObjs, in, version ); \
objs.resize(numObjs); \
for (uint i0 = 0; i0 < objs.size(); i0++) { \
	NifStream( objs[i0].name, in, version ); \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( unknownInt, out, version ); \
NifStream( numObjs, out, version ); \
for (uint i0 = 0; i0 < objs.size(); i0++) { \
	NifStream( objs[i0].name, out, version ); \
	if ( objs[i0].object != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(objs[i0].object)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Unknown Int:  " << unknownInt << endl; \
out << "Num Objs:  " << numObjs << endl; \
for (uint i0 = 0; i0 < objs.size(); i0++) { \
	out << "  Name:  " << objs[i0].name << endl; \
	out << "  Object:  " << objs[i0].object << endl; \
}; \
return out.str(); \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < objs.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		objs[i0].object = DynamicCast<NiAVObject>(objects[link_stack.front()]); \
		if ( objs[i0].object == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		objs[i0].object = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
for (uint i0 = 0; i0 < objs.size(); i0++) { \
}; \
return refs; \

#define NI_DIRECTIONAL_LIGHT_MEMBERS \

#define NI_DIRECTIONAL_LIGHT_INCLUDE "NiLight.h" \

#define NI_DIRECTIONAL_LIGHT_PARENT NiLight \

#define NI_DIRECTIONAL_LIGHT_CONSTRUCT \

#define NI_DIRECTIONAL_LIGHT_READ \
NiLight::Read( in, link_stack, version, user_version ); \

#define NI_DIRECTIONAL_LIGHT_WRITE \
NiLight::Write( out, link_map, version, user_version ); \

#define NI_DIRECTIONAL_LIGHT_STRING \
stringstream out; \
out << NiLight::asString(); \
return out.str(); \

#define NI_DIRECTIONAL_LIGHT_FIXLINKS \
NiLight::FixLinks( objects, link_stack, version, user_version ); \

#define NI_DIRECTIONAL_LIGHT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiLight::GetRefs(); \
return refs; \

#define NI_DITHER_PROPERTY_MEMBERS \
ushort flags; \

#define NI_DITHER_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_DITHER_PROPERTY_PARENT NiProperty \

#define NI_DITHER_PROPERTY_CONSTRUCT \
 : flags((ushort)0) \

#define NI_DITHER_PROPERTY_READ \
NiProperty::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \

#define NI_DITHER_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \

#define NI_DITHER_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
return out.str(); \

#define NI_DITHER_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_DITHER_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define NI_FLIP_CONTROLLER_MEMBERS \
uint textureSlot; \
uint unknownInt2; \
float delta; \
uint numSources; \
vector<Ref<NiSourceTexture > > sources; \

#define NI_FLIP_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_FLIP_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_FLIP_CONTROLLER_CONSTRUCT \
 : textureSlot((uint)0), unknownInt2((uint)0), delta(0.0f), numSources((uint)0) \

#define NI_FLIP_CONTROLLER_READ \
uint block_num; \
NiSingleInterpolatorController::Read( in, link_stack, version, user_version ); \
NifStream( textureSlot, in, version ); \
if ( version <= 0x0A010000 ) { \
	NifStream( unknownInt2, in, version ); \
	NifStream( delta, in, version ); \
}; \
NifStream( numSources, in, version ); \
sources.resize(numSources); \
for (uint i0 = 0; i0 < sources.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_FLIP_CONTROLLER_WRITE \
NiSingleInterpolatorController::Write( out, link_map, version, user_version ); \
NifStream( textureSlot, out, version ); \
if ( version <= 0x0A010000 ) { \
	NifStream( unknownInt2, out, version ); \
	NifStream( delta, out, version ); \
}; \
NifStream( numSources, out, version ); \
for (uint i0 = 0; i0 < sources.size(); i0++) { \
	if ( sources[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(sources[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_FLIP_CONTROLLER_STRING \
stringstream out; \
out << NiSingleInterpolatorController::asString(); \
out << "Texture Slot:  " << textureSlot << endl; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
out << "Delta:  " << delta << endl; \
out << "Num Sources:  " << numSources << endl; \
for (uint i0 = 0; i0 < sources.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Sources[" << i0 << "]:  " << sources[i0] << endl; \
}; \
return out.str(); \

#define NI_FLIP_CONTROLLER_FIXLINKS \
NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < sources.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		sources[i0] = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
		if ( sources[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		sources[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_FLIP_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiSingleInterpolatorController::GetRefs(); \
for (uint i0 = 0; i0 < sources.size(); i0++) { \
	if ( sources[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(sources[i0])); \
}; \
return refs; \

#define NI_FLOAT_DATA_MEMBERS \
KeyGroup<float > data; \

#define NI_FLOAT_DATA_INCLUDE "AKeyedData.h" \

#define NI_FLOAT_DATA_PARENT AKeyedData \

#define NI_FLOAT_DATA_CONSTRUCT \

#define NI_FLOAT_DATA_READ \
AKeyedData::Read( in, link_stack, version, user_version ); \
NifStream( data.numKeys, in, version ); \
if ( (data.numKeys != 0) ) { \
	NifStream( data.interpolation, in, version ); \
}; \
data.keys.resize(data.numKeys); \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	NifStream( data.keys[i0], in, version, data.interpolation ); \
}; \

#define NI_FLOAT_DATA_WRITE \
AKeyedData::Write( out, link_map, version, user_version ); \
NifStream( data.numKeys, out, version ); \
if ( (data.numKeys != 0) ) { \
	NifStream( data.interpolation, out, version ); \
}; \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	NifStream( data.keys[i0], out, version, data.interpolation ); \
}; \

#define NI_FLOAT_DATA_STRING \
stringstream out; \
out << AKeyedData::asString(); \
out << "Num Keys:  " << data.numKeys << endl; \
if ( (data.numKeys != 0) ) { \
	out << "  Interpolation:  " << data.interpolation << endl; \
}; \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Keys[" << i0 << "]:  " << data.keys[i0] << endl; \
}; \
return out.str(); \

#define NI_FLOAT_DATA_FIXLINKS \
AKeyedData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_FLOAT_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = AKeyedData::GetRefs(); \
return refs; \

#define NI_FLOAT_EXTRA_DATA_MEMBERS \
float floatData; \

#define NI_FLOAT_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_FLOAT_EXTRA_DATA_PARENT NiExtraData \

#define NI_FLOAT_EXTRA_DATA_CONSTRUCT \
 : floatData(0.0f) \

#define NI_FLOAT_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( floatData, in, version ); \

#define NI_FLOAT_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( floatData, out, version ); \

#define NI_FLOAT_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Float Data:  " << floatData << endl; \
return out.str(); \

#define NI_FLOAT_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_FLOAT_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_MEMBERS \
Ref<NiObject > unknownLink; \
string unknownString; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_PARENT NiTimeController \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_CONSTRUCT \
 : unknownLink(NULL) \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
if ( version >= 0x14000004 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( unknownString, in, version ); \
}; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
if ( version >= 0x14000004 ) { \
	if ( unknownLink != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( unknownString, out, version ); \
}; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown Link:  " << unknownLink << endl; \
out << "Unknown String:  " << unknownString << endl; \
return out.str(); \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if ( version >= 0x14000004 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]); \
		if ( unknownLink == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		unknownLink = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( unknownLink != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink)); \
return refs; \

#define NI_FLOAT_INTERPOLATOR_MEMBERS \
float floatValue; \
Ref<NiFloatData > data; \

#define NI_FLOAT_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_FLOAT_INTERPOLATOR_PARENT NiInterpolator \

#define NI_FLOAT_INTERPOLATOR_CONSTRUCT \
 : floatValue(0.0f), data(NULL) \

#define NI_FLOAT_INTERPOLATOR_READ \
uint block_num; \
NiInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( floatValue, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_FLOAT_INTERPOLATOR_WRITE \
NiInterpolator::Write( out, link_map, version, user_version ); \
NifStream( floatValue, out, version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_FLOAT_INTERPOLATOR_STRING \
stringstream out; \
out << NiInterpolator::asString(); \
out << "Float Value:  " << floatValue << endl; \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_FLOAT_INTERPOLATOR_FIXLINKS \
NiInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiFloatData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define NI_FLOAT_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiInterpolator::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_FLOATS_EXTRA_DATA_MEMBERS \
uint numFloats; \
vector<float > data; \

#define NI_FLOATS_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_FLOATS_EXTRA_DATA_PARENT NiExtraData \

#define NI_FLOATS_EXTRA_DATA_CONSTRUCT \
 : numFloats((uint)0) \

#define NI_FLOATS_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( numFloats, in, version ); \
data.resize(numFloats); \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	NifStream( data[i0], in, version ); \
}; \

#define NI_FLOATS_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( numFloats, out, version ); \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	NifStream( data[i0], out, version ); \
}; \

#define NI_FLOATS_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Num Floats:  " << numFloats << endl; \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Data[" << i0 << "]:  " << data[i0] << endl; \
}; \
return out.str(); \

#define NI_FLOATS_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_FLOATS_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_FOG_PROPERTY_MEMBERS \
ushort flags; \
float fogDepth; \
Color3 fogColor; \

#define NI_FOG_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_FOG_PROPERTY_PARENT NiProperty \

#define NI_FOG_PROPERTY_CONSTRUCT \
 : flags((ushort)0), fogDepth(0.0f) \

#define NI_FOG_PROPERTY_READ \
NiProperty::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \
NifStream( fogDepth, in, version ); \
NifStream( fogColor, in, version ); \

#define NI_FOG_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \
NifStream( fogDepth, out, version ); \
NifStream( fogColor, out, version ); \

#define NI_FOG_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
out << "Fog Depth:  " << fogDepth << endl; \
out << "Fog Color:  " << fogColor << endl; \
return out.str(); \

#define NI_FOG_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_FOG_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define NI_GEOM_MORPHER_CONTROLLER_MEMBERS \
ushort unknown; \
byte unknown2; \
Ref<NiMorphData > data; \
byte unknownByte; \
uint numInterpolators; \
vector<Ref<NiInterpolator > > interpolators; \
uint numUnknownInts; \
vector<uint > unknownInts; \

#define NI_GEOM_MORPHER_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_GEOM_MORPHER_CONTROLLER_PARENT NiTimeController \

#define NI_GEOM_MORPHER_CONTROLLER_CONSTRUCT \
 : unknown((ushort)0), unknown2((byte)0), data(NULL), unknownByte((byte)0), numInterpolators((uint)0), numUnknownInts((uint)0) \

#define NI_GEOM_MORPHER_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknown, in, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
	NifStream( unknown2, in, version ); \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( unknownByte, in, version ); \
if ( version >= 0x0A01006A ) { \
	NifStream( numInterpolators, in, version ); \
	interpolators.resize(numInterpolators); \
	for (uint i1 = 0; i1 < interpolators.size(); i1++) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \
if ( version >= 0x0A020000 ) { \
	NifStream( numUnknownInts, in, version ); \
	unknownInts.resize(numUnknownInts); \
	for (uint i1 = 0; i1 < unknownInts.size(); i1++) { \
		NifStream( unknownInts[i1], in, version ); \
	}; \
}; \

#define NI_GEOM_MORPHER_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknown, out, version ); \
}; \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
	NifStream( unknown2, out, version ); \
}; \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( unknownByte, out, version ); \
if ( version >= 0x0A01006A ) { \
	NifStream( numInterpolators, out, version ); \
	for (uint i1 = 0; i1 < interpolators.size(); i1++) { \
		if ( interpolators[i1] != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(interpolators[i1])], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \
if ( version >= 0x0A020000 ) { \
	NifStream( numUnknownInts, out, version ); \
	for (uint i1 = 0; i1 < unknownInts.size(); i1++) { \
		NifStream( unknownInts[i1], out, version ); \
	}; \
}; \

#define NI_GEOM_MORPHER_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown:  " << unknown << endl; \
out << "Unknown 2:  " << unknown2 << endl; \
out << "Data:  " << data << endl; \
out << "Unknown Byte:  " << unknownByte << endl; \
out << "Num Interpolators:  " << numInterpolators << endl; \
for (uint i0 = 0; i0 < interpolators.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Interpolators[" << i0 << "]:  " << interpolators[i0] << endl; \
}; \
out << "Num Unknown Ints:  " << numUnknownInts << endl; \
for (uint i0 = 0; i0 < unknownInts.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Ints[" << i0 << "]:  " << unknownInts[i0] << endl; \
}; \
return out.str(); \

#define NI_GEOM_MORPHER_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiMorphData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \
if ( version >= 0x0A01006A ) { \
	for (uint i1 = 0; i1 < interpolators.size(); i1++) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			interpolators[i1] = DynamicCast<NiInterpolator>(objects[link_stack.front()]); \
			if ( interpolators[i1] == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			interpolators[i1] = NULL; \
		link_stack.pop_front(); \
	}; \
}; \

#define NI_GEOM_MORPHER_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
for (uint i0 = 0; i0 < interpolators.size(); i0++) { \
	if ( interpolators[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(interpolators[i0])); \
}; \
return refs; \

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
AParticleModifier::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( force, in, version ); \
NifStream( type, in, version ); \
NifStream( position, in, version ); \
NifStream( direction, in, version ); \

#define NI_GRAVITY_WRITE \
AParticleModifier::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( force, out, version ); \
NifStream( type, out, version ); \
NifStream( position, out, version ); \
NifStream( direction, out, version ); \

#define NI_GRAVITY_STRING \
stringstream out; \
out << AParticleModifier::asString(); \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Force:  " << force << endl; \
out << "Type:  " << type << endl; \
out << "Position:  " << position << endl; \
out << "Direction:  " << direction << endl; \
return out.str(); \

#define NI_GRAVITY_FIXLINKS \
AParticleModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_GRAVITY_GETREFS \
list<Ref<NiObject> > refs; \
refs = AParticleModifier::GetRefs(); \
return refs; \

#define NI_INTEGER_EXTRA_DATA_MEMBERS \
uint integerData; \

#define NI_INTEGER_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_INTEGER_EXTRA_DATA_PARENT NiExtraData \

#define NI_INTEGER_EXTRA_DATA_CONSTRUCT \
 : integerData((uint)0) \

#define NI_INTEGER_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( integerData, in, version ); \

#define NI_INTEGER_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( integerData, out, version ); \

#define NI_INTEGER_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Integer Data:  " << integerData << endl; \
return out.str(); \

#define NI_INTEGER_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_INTEGER_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_INTEGERS_EXTRA_DATA_MEMBERS \
uint numIntegers; \
vector<uint > data; \

#define NI_INTEGERS_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_INTEGERS_EXTRA_DATA_PARENT NiExtraData \

#define NI_INTEGERS_EXTRA_DATA_CONSTRUCT \
 : numIntegers((uint)0) \

#define NI_INTEGERS_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( numIntegers, in, version ); \
data.resize(numIntegers); \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	NifStream( data[i0], in, version ); \
}; \

#define NI_INTEGERS_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( numIntegers, out, version ); \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	NifStream( data[i0], out, version ); \
}; \

#define NI_INTEGERS_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Num Integers:  " << numIntegers << endl; \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Data[" << i0 << "]:  " << data[i0] << endl; \
}; \
return out.str(); \

#define NI_INTEGERS_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_INTEGERS_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_KEYFRAME_CONTROLLER_MEMBERS \
Ref<NiKeyframeData > data; \

#define NI_KEYFRAME_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_KEYFRAME_CONTROLLER_PARENT NiTimeController \

#define NI_KEYFRAME_CONTROLLER_CONSTRUCT \
 : data(NULL) \

#define NI_KEYFRAME_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_KEYFRAME_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_KEYFRAME_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_KEYFRAME_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiKeyframeData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define NI_KEYFRAME_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define B_S_KEYFRAME_CONTROLLER_MEMBERS \
Ref<NiKeyframeData > data2; \

#define B_S_KEYFRAME_CONTROLLER_INCLUDE "NiKeyframeController.h" \

#define B_S_KEYFRAME_CONTROLLER_PARENT NiKeyframeController \

#define B_S_KEYFRAME_CONTROLLER_CONSTRUCT \
 : data2(NULL) \

#define B_S_KEYFRAME_CONTROLLER_READ \
uint block_num; \
NiKeyframeController::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define B_S_KEYFRAME_CONTROLLER_WRITE \
NiKeyframeController::Write( out, link_map, version, user_version ); \
if ( data2 != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data2)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define B_S_KEYFRAME_CONTROLLER_STRING \
stringstream out; \
out << NiKeyframeController::asString(); \
out << "Data 2:  " << data2 << endl; \
return out.str(); \

#define B_S_KEYFRAME_CONTROLLER_FIXLINKS \
NiKeyframeController::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data2 = DynamicCast<NiKeyframeData>(objects[link_stack.front()]); \
	if ( data2 == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data2 = NULL; \
link_stack.pop_front(); \

#define B_S_KEYFRAME_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiKeyframeController::GetRefs(); \
if ( data2 != NULL ) \
	refs.push_back(StaticCast<NiObject>(data2)); \
return refs; \

#define NI_KEYFRAME_DATA_MEMBERS \
uint numRotationKeys; \
KeyType rotationType; \
vector<Key<Quaternion > > quaternionKeys; \
float unknownFloat; \
KeyGroup<float > xyzRotations[3]; \
KeyGroup<Vector3 > translations; \
KeyGroup<float > scales; \

#define NI_KEYFRAME_DATA_INCLUDE "AKeyedData.h" \

#define NI_KEYFRAME_DATA_PARENT AKeyedData \

#define NI_KEYFRAME_DATA_CONSTRUCT \
 : numRotationKeys((uint)0), rotationType((KeyType)0), unknownFloat(0.0f) \

#define NI_KEYFRAME_DATA_READ \
AKeyedData::Read( in, link_stack, version, user_version ); \
NifStream( numRotationKeys, in, version ); \
if ( (numRotationKeys != 0) ) { \
	NifStream( rotationType, in, version ); \
}; \
if ( (rotationType != 4) ) { \
	quaternionKeys.resize(numRotationKeys); \
	for (uint i1 = 0; i1 < quaternionKeys.size(); i1++) { \
		NifStream( quaternionKeys[i1], in, version, rotationType ); \
	}; \
}; \
if ( version <= 0x0A010000 ) { \
	if ( (rotationType == 4) ) { \
		NifStream( unknownFloat, in, version ); \
	}; \
}; \
if ( (rotationType == 4) ) { \
	for (uint i1 = 0; i1 < 3; i1++) { \
		NifStream( xyzRotations[i1].numKeys, in, version ); \
		if ( (xyzRotations[i1].numKeys != 0) ) { \
			NifStream( xyzRotations[i1].interpolation, in, version ); \
		}; \
		xyzRotations[i1].keys.resize(xyzRotations[i1].numKeys); \
		for (uint i2 = 0; i2 < xyzRotations[i1].keys.size(); i2++) { \
			NifStream( xyzRotations[i1].keys[i2], in, version, xyzRotations[i1].interpolation ); \
		}; \
	}; \
}; \
NifStream( translations.numKeys, in, version ); \
if ( (translations.numKeys != 0) ) { \
	NifStream( translations.interpolation, in, version ); \
}; \
translations.keys.resize(translations.numKeys); \
for (uint i0 = 0; i0 < translations.keys.size(); i0++) { \
	NifStream( translations.keys[i0], in, version, translations.interpolation ); \
}; \
NifStream( scales.numKeys, in, version ); \
if ( (scales.numKeys != 0) ) { \
	NifStream( scales.interpolation, in, version ); \
}; \
scales.keys.resize(scales.numKeys); \
for (uint i0 = 0; i0 < scales.keys.size(); i0++) { \
	NifStream( scales.keys[i0], in, version, scales.interpolation ); \
}; \

#define NI_KEYFRAME_DATA_WRITE \
AKeyedData::Write( out, link_map, version, user_version ); \
NifStream( numRotationKeys, out, version ); \
if ( (numRotationKeys != 0) ) { \
	NifStream( rotationType, out, version ); \
}; \
if ( (rotationType != 4) ) { \
	for (uint i1 = 0; i1 < quaternionKeys.size(); i1++) { \
		NifStream( quaternionKeys[i1], out, version, rotationType ); \
	}; \
}; \
if ( version <= 0x0A010000 ) { \
	if ( (rotationType == 4) ) { \
		NifStream( unknownFloat, out, version ); \
	}; \
}; \
if ( (rotationType == 4) ) { \
	for (uint i1 = 0; i1 < 3; i1++) { \
		NifStream( xyzRotations[i1].numKeys, out, version ); \
		if ( (xyzRotations[i1].numKeys != 0) ) { \
			NifStream( xyzRotations[i1].interpolation, out, version ); \
		}; \
		for (uint i2 = 0; i2 < xyzRotations[i1].keys.size(); i2++) { \
			NifStream( xyzRotations[i1].keys[i2], out, version, xyzRotations[i1].interpolation ); \
		}; \
	}; \
}; \
NifStream( translations.numKeys, out, version ); \
if ( (translations.numKeys != 0) ) { \
	NifStream( translations.interpolation, out, version ); \
}; \
for (uint i0 = 0; i0 < translations.keys.size(); i0++) { \
	NifStream( translations.keys[i0], out, version, translations.interpolation ); \
}; \
NifStream( scales.numKeys, out, version ); \
if ( (scales.numKeys != 0) ) { \
	NifStream( scales.interpolation, out, version ); \
}; \
for (uint i0 = 0; i0 < scales.keys.size(); i0++) { \
	NifStream( scales.keys[i0], out, version, scales.interpolation ); \
}; \

#define NI_KEYFRAME_DATA_STRING \
stringstream out; \
out << AKeyedData::asString(); \
out << "Num Rotation Keys:  " << numRotationKeys << endl; \
if ( (numRotationKeys != 0) ) { \
	out << "  Rotation Type:  " << rotationType << endl; \
}; \
if ( (rotationType != 4) ) { \
	for (uint i1 = 0; i1 < quaternionKeys.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Quaternion Keys[" << i1 << "]:  " << quaternionKeys[i1] << endl; \
	}; \
}; \
if ( (rotationType == 4) ) { \
	out << "  Unknown Float:  " << unknownFloat << endl; \
	for (uint i1 = 0; i1 < 3; i1++) { \
		out << "    Num Keys:  " << xyzRotations[i1].numKeys << endl; \
		if ( (xyzRotations[i1].numKeys != 0) ) { \
			out << "      Interpolation:  " << xyzRotations[i1].interpolation << endl; \
		}; \
		for (uint i2 = 0; i2 < xyzRotations[i1].keys.size(); i2++) { \
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) { \
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
				break; \
			}; \
			out << "      Keys[" << i2 << "]:  " << xyzRotations[i1].keys[i2] << endl; \
		}; \
	}; \
}; \
out << "Num Keys:  " << translations.numKeys << endl; \
if ( (translations.numKeys != 0) ) { \
	out << "  Interpolation:  " << translations.interpolation << endl; \
}; \
for (uint i0 = 0; i0 < translations.keys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Keys[" << i0 << "]:  " << translations.keys[i0] << endl; \
}; \
out << "Num Keys:  " << scales.numKeys << endl; \
if ( (scales.numKeys != 0) ) { \
	out << "  Interpolation:  " << scales.interpolation << endl; \
}; \
for (uint i0 = 0; i0 < scales.keys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Keys[" << i0 << "]:  " << scales.keys[i0] << endl; \
}; \
return out.str(); \

#define NI_KEYFRAME_DATA_FIXLINKS \
AKeyedData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_KEYFRAME_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = AKeyedData::GetRefs(); \
return refs; \

#define NI_LIGHT_COLOR_CONTROLLER_MEMBERS \
ushort unknownShort; \
Ref<NiPosData > data; \
Ref<NiPoint3Interpolator > interpolator; \

#define NI_LIGHT_COLOR_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_LIGHT_COLOR_CONTROLLER_PARENT NiTimeController \

#define NI_LIGHT_COLOR_CONTROLLER_CONSTRUCT \
 : unknownShort((ushort)0), data(NULL), interpolator(NULL) \

#define NI_LIGHT_COLOR_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) { \
	NifStream( unknownShort, in, version ); \
}; \
if ( version <= 0x0A010000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
if ( version >= 0x0A020000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( unknownShort, in, version ); \
}; \

#define NI_LIGHT_COLOR_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A010000 ) ) { \
	NifStream( unknownShort, out, version ); \
}; \
if ( version <= 0x0A010000 ) { \
	if ( data != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
	if ( interpolator != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(interpolator)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( unknownShort, out, version ); \
}; \

#define NI_LIGHT_COLOR_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Data:  " << data << endl; \
out << "Interpolator:  " << interpolator << endl; \
return out.str(); \

#define NI_LIGHT_COLOR_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		data = DynamicCast<NiPosData>(objects[link_stack.front()]); \
		if ( data == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		data = NULL; \
	link_stack.pop_front(); \
}; \
if ( version >= 0x0A020000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		interpolator = DynamicCast<NiPoint3Interpolator>(objects[link_stack.front()]); \
		if ( interpolator == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		interpolator = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_LIGHT_COLOR_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
if ( interpolator != NULL ) \
	refs.push_back(StaticCast<NiObject>(interpolator)); \
return refs; \

#define NI_LIGHT_DIMMER_CONTROLLER_MEMBERS \
Ref<NiInterpolator > unknownLink; \

#define NI_LIGHT_DIMMER_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_LIGHT_DIMMER_CONTROLLER_PARENT NiTimeController \

#define NI_LIGHT_DIMMER_CONTROLLER_CONSTRUCT \
 : unknownLink(NULL) \

#define NI_LIGHT_DIMMER_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_LIGHT_DIMMER_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
if ( unknownLink != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_LIGHT_DIMMER_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown Link:  " << unknownLink << endl; \
return out.str(); \

#define NI_LIGHT_DIMMER_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink = DynamicCast<NiInterpolator>(objects[link_stack.front()]); \
	if ( unknownLink == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink = NULL; \
link_stack.pop_front(); \

#define NI_LIGHT_DIMMER_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( unknownLink != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink)); \
return refs; \

#define NI_LOOK_AT_CONTROLLER_MEMBERS \
ushort unknown1; \
Ref<NiNode > lookAtNode; \

#define NI_LOOK_AT_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_LOOK_AT_CONTROLLER_PARENT NiTimeController \

#define NI_LOOK_AT_CONTROLLER_CONSTRUCT \
 : unknown1((ushort)0), lookAtNode(NULL) \

#define NI_LOOK_AT_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknown1, in, version ); \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_LOOK_AT_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknown1, out, version ); \
}; \
if ( lookAtNode != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(lookAtNode)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_LOOK_AT_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown1:  " << unknown1 << endl; \
out << "Look At Node:  " << lookAtNode << endl; \
return out.str(); \

#define NI_LOOK_AT_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	lookAtNode = DynamicCast<NiNode>(objects[link_stack.front()]); \
	if ( lookAtNode == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	lookAtNode = NULL; \
link_stack.pop_front(); \

#define NI_LOOK_AT_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( lookAtNode != NULL ) \
	refs.push_back(StaticCast<NiObject>(lookAtNode)); \
return refs; \

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
uint block_num; \
NiInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( unknownShort, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( unknownFloat, in, version ); \
NifStream( translation, in, version ); \
NifStream( rotation, in, version ); \
NifStream( scale, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_LOOK_AT_INTERPOLATOR_WRITE \
NiInterpolator::Write( out, link_map, version, user_version ); \
NifStream( unknownShort, out, version ); \
if ( lookAt != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(lookAt)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( unknownFloat, out, version ); \
NifStream( translation, out, version ); \
NifStream( rotation, out, version ); \
NifStream( scale, out, version ); \
if ( unknownLink1 != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink1)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( unknownLink2 != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( unknownLink3 != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink3)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_LOOK_AT_INTERPOLATOR_STRING \
stringstream out; \
out << NiInterpolator::asString(); \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Look At:  " << lookAt << endl; \
out << "Unknown Float:  " << unknownFloat << endl; \
out << "Translation:  " << translation << endl; \
out << "Rotation:  " << rotation << endl; \
out << "Scale:  " << scale << endl; \
out << "Unknown Link 1:  " << unknownLink1 << endl; \
out << "Unknown Link 2:  " << unknownLink2 << endl; \
out << "Unknown Link 3:  " << unknownLink3 << endl; \
return out.str(); \

#define NI_LOOK_AT_INTERPOLATOR_FIXLINKS \
NiInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	lookAt = DynamicCast<NiNode>(objects[link_stack.front()]); \
	if ( lookAt == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	lookAt = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink1 = DynamicCast<NiPoint3Interpolator>(objects[link_stack.front()]); \
	if ( unknownLink1 == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink1 = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink2 = DynamicCast<NiFloatInterpolator>(objects[link_stack.front()]); \
	if ( unknownLink2 == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink2 = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink3 = DynamicCast<NiFloatInterpolator>(objects[link_stack.front()]); \
	if ( unknownLink3 == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink3 = NULL; \
link_stack.pop_front(); \

#define NI_LOOK_AT_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiInterpolator::GetRefs(); \
if ( lookAt != NULL ) \
	refs.push_back(StaticCast<NiObject>(lookAt)); \
if ( unknownLink1 != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink1)); \
if ( unknownLink2 != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink2)); \
if ( unknownLink3 != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink3)); \
return refs; \

#define NI_MATERIAL_COLOR_CONTROLLER_MEMBERS \
ushort unknown; \
Ref<NiPosData > data; \

#define NI_MATERIAL_COLOR_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_MATERIAL_COLOR_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_MATERIAL_COLOR_CONTROLLER_CONSTRUCT \
 : unknown((ushort)0), data(NULL) \

#define NI_MATERIAL_COLOR_CONTROLLER_READ \
uint block_num; \
NiSingleInterpolatorController::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknown, in, version ); \
}; \
if ( version <= 0x0A010000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_MATERIAL_COLOR_CONTROLLER_WRITE \
NiSingleInterpolatorController::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknown, out, version ); \
}; \
if ( version <= 0x0A010000 ) { \
	if ( data != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_MATERIAL_COLOR_CONTROLLER_STRING \
stringstream out; \
out << NiSingleInterpolatorController::asString(); \
out << "Unknown:  " << unknown << endl; \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_MATERIAL_COLOR_CONTROLLER_FIXLINKS \
NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		data = DynamicCast<NiPosData>(objects[link_stack.front()]); \
		if ( data == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		data = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_MATERIAL_COLOR_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiSingleInterpolatorController::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

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
NiProperty::Read( in, link_stack, version, user_version ); \
if ( version <= 0x0A000102 ) { \
	NifStream( flags, in, version ); \
}; \
NifStream( ambientColor, in, version ); \
NifStream( diffuseColor, in, version ); \
NifStream( specularColor, in, version ); \
NifStream( emissiveColor, in, version ); \
NifStream( glossiness, in, version ); \
NifStream( alpha, in, version ); \

#define NI_MATERIAL_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
if ( version <= 0x0A000102 ) { \
	NifStream( flags, out, version ); \
}; \
NifStream( ambientColor, out, version ); \
NifStream( diffuseColor, out, version ); \
NifStream( specularColor, out, version ); \
NifStream( emissiveColor, out, version ); \
NifStream( glossiness, out, version ); \
NifStream( alpha, out, version ); \

#define NI_MATERIAL_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
out << "Ambient Color:  " << ambientColor << endl; \
out << "Diffuse Color:  " << diffuseColor << endl; \
out << "Specular Color:  " << specularColor << endl; \
out << "Emissive Color:  " << emissiveColor << endl; \
out << "Glossiness:  " << glossiness << endl; \
out << "Alpha:  " << alpha << endl; \
return out.str(); \

#define NI_MATERIAL_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_MATERIAL_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define NI_MESH_P_SYS_DATA_MEMBERS \
byte unknownByte11; \
vector< array<float,4> > unknownFloats3; \
vector< array<float,10> > unknownFloats4; \
vector< array<float,12> > unknownFloats5; \
uint unknownInt1; \
Ref<NiPSysModifier > modifier; \
byte unknownByte2; \
uint numUnknownLinks; \
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
uint block_num; \
APSysData::Read( in, link_stack, version, user_version ); \
if ( version >= 0x14000005 ) { \
	NifStream( unknownByte11, in, version ); \
}; \
if ( version <= 0x14000004 ) { \
	unknownFloats3.resize(numVertices); \
	for (uint i1 = 0; i1 < unknownFloats3.size(); i1++) { \
		for (uint i2 = 0; i2 < 4; i2++) { \
			NifStream( unknownFloats3[i1][i2], in, version ); \
		}; \
	}; \
	unknownFloats4.resize(numVertices); \
	for (uint i1 = 0; i1 < unknownFloats4.size(); i1++) { \
		for (uint i2 = 0; i2 < 10; i2++) { \
			NifStream( unknownFloats4[i1][i2], in, version ); \
		}; \
	}; \
}; \
if ( version >= 0x14000005 ) { \
	unknownFloats5.resize(numVertices); \
	for (uint i1 = 0; i1 < unknownFloats5.size(); i1++) { \
		for (uint i2 = 0; i2 < 12; i2++) { \
			NifStream( unknownFloats5[i1][i2], in, version ); \
		}; \
	}; \
}; \
NifStream( unknownInt1, in, version ); \
if ( version <= 0x14000004 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) { \
	NifStream( unknownByte2, in, version ); \
	NifStream( numUnknownLinks, in, version ); \
	unknownLinks.resize(numUnknownLinks); \
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \
if ( version >= 0x14000005 ) { \
	NifStream( unknownShort4, in, version ); \
	NifStream( unknownInt2, in, version ); \
	NifStream( unknownByte12, in, version ); \
	NifStream( unknownInt3, in, version ); \
	NifStream( unknownInt4, in, version ); \
}; \
if ( version >= 0x0A020000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_MESH_P_SYS_DATA_WRITE \
APSysData::Write( out, link_map, version, user_version ); \
if ( version >= 0x14000005 ) { \
	NifStream( unknownByte11, out, version ); \
}; \
if ( version <= 0x14000004 ) { \
	for (uint i1 = 0; i1 < unknownFloats3.size(); i1++) { \
		for (uint i2 = 0; i2 < 4; i2++) { \
			NifStream( unknownFloats3[i1][i2], out, version ); \
		}; \
	}; \
	for (uint i1 = 0; i1 < unknownFloats4.size(); i1++) { \
		for (uint i2 = 0; i2 < 10; i2++) { \
			NifStream( unknownFloats4[i1][i2], out, version ); \
		}; \
	}; \
}; \
if ( version >= 0x14000005 ) { \
	for (uint i1 = 0; i1 < unknownFloats5.size(); i1++) { \
		for (uint i2 = 0; i2 < 12; i2++) { \
			NifStream( unknownFloats5[i1][i2], out, version ); \
		}; \
	}; \
}; \
NifStream( unknownInt1, out, version ); \
if ( version <= 0x14000004 ) { \
	if ( modifier != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(modifier)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) { \
	NifStream( unknownByte2, out, version ); \
	NifStream( numUnknownLinks, out, version ); \
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) { \
		if ( unknownLinks[i1] != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(unknownLinks[i1])], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \
if ( version >= 0x14000005 ) { \
	NifStream( unknownShort4, out, version ); \
	NifStream( unknownInt2, out, version ); \
	NifStream( unknownByte12, out, version ); \
	NifStream( unknownInt3, out, version ); \
	NifStream( unknownInt4, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
	if ( unknownLink2 != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_MESH_P_SYS_DATA_STRING \
stringstream out; \
out << APSysData::asString(); \
out << "Unknown Byte 11:  " << unknownByte11 << endl; \
for (uint i0 = 0; i0 < unknownFloats3.size(); i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats 3[" << i0 << "][" << i1 << "]:  " << unknownFloats3[i0][i1] << endl; \
	}; \
}; \
for (uint i0 = 0; i0 < unknownFloats4.size(); i0++) { \
	for (uint i1 = 0; i1 < 10; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats 4[" << i0 << "][" << i1 << "]:  " << unknownFloats4[i0][i1] << endl; \
	}; \
}; \
for (uint i0 = 0; i0 < unknownFloats5.size(); i0++) { \
	for (uint i1 = 0; i1 < 12; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats 5[" << i0 << "][" << i1 << "]:  " << unknownFloats5[i0][i1] << endl; \
	}; \
}; \
out << "Unknown Int 1:  " << unknownInt1 << endl; \
out << "Modifier:  " << modifier << endl; \
out << "Unknown Byte 2:  " << unknownByte2 << endl; \
out << "Num Unknown Links:  " << numUnknownLinks << endl; \
for (uint i0 = 0; i0 < unknownLinks.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Links[" << i0 << "]:  " << unknownLinks[i0] << endl; \
}; \
out << "Unknown Short 4:  " << unknownShort4 << endl; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
out << "Unknown Byte 12:  " << unknownByte12 << endl; \
out << "Unknown Int 3:  " << unknownInt3 << endl; \
out << "Unknown Int 4:  " << unknownInt4 << endl; \
out << "Unknown Link 2:  " << unknownLink2 << endl; \
return out.str(); \

#define NI_MESH_P_SYS_DATA_FIXLINKS \
APSysData::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x14000004 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		modifier = DynamicCast<NiPSysModifier>(objects[link_stack.front()]); \
		if ( modifier == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		modifier = NULL; \
	link_stack.pop_front(); \
}; \
if ( ( version >= 0x0A020000 ) && ( version <= 0x14000004 ) ) { \
	for (uint i1 = 0; i1 < unknownLinks.size(); i1++) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			unknownLinks[i1] = DynamicCast<NiPSysModifier>(objects[link_stack.front()]); \
			if ( unknownLinks[i1] == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			unknownLinks[i1] = NULL; \
		link_stack.pop_front(); \
	}; \
}; \
if ( version >= 0x0A020000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		unknownLink2 = DynamicCast<NiNode>(objects[link_stack.front()]); \
		if ( unknownLink2 == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		unknownLink2 = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_MESH_P_SYS_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysData::GetRefs(); \
if ( modifier != NULL ) \
	refs.push_back(StaticCast<NiObject>(modifier)); \
for (uint i0 = 0; i0 < unknownLinks.size(); i0++) { \
	if ( unknownLinks[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(unknownLinks[i0])); \
}; \
if ( unknownLink2 != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink2)); \
return refs; \

#define NI_MORPH_DATA_MEMBERS \
uint numMorphs; \
uint numVertices; \
byte unknownByte; \
vector<Morph > morphs; \

#define NI_MORPH_DATA_INCLUDE "NiObject.h" \

#define NI_MORPH_DATA_PARENT NiObject \

#define NI_MORPH_DATA_CONSTRUCT \
 : numMorphs((uint)0), numVertices((uint)0), unknownByte((byte)0) \

#define NI_MORPH_DATA_READ \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( numMorphs, in, version ); \
NifStream( numVertices, in, version ); \
NifStream( unknownByte, in, version ); \
morphs.resize(numMorphs); \
for (uint i0 = 0; i0 < morphs.size(); i0++) { \
	if ( version >= 0x0A01006A ) { \
		NifStream( morphs[i0].frameName, in, version ); \
	}; \
	if ( version <= 0x0A000102 ) { \
		NifStream( morphs[i0].numMorphKeys, in, version ); \
		NifStream( morphs[i0].morphInterpolation, in, version ); \
		morphs[i0].morphKeys.resize(morphs[i0].numMorphKeys); \
		for (uint i2 = 0; i2 < morphs[i0].morphKeys.size(); i2++) { \
			NifStream( morphs[i0].morphKeys[i2], in, version, morphs[i0].morphInterpolation ); \
		}; \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( morphs[i0].unknownInt, in, version ); \
	}; \
	morphs[i0].vectors.resize(numVertices); \
	for (uint i1 = 0; i1 < morphs[i0].vectors.size(); i1++) { \
		NifStream( morphs[i0].vectors[i1], in, version ); \
	}; \
}; \

#define NI_MORPH_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( numMorphs, out, version ); \
NifStream( numVertices, out, version ); \
NifStream( unknownByte, out, version ); \
for (uint i0 = 0; i0 < morphs.size(); i0++) { \
	if ( version >= 0x0A01006A ) { \
		NifStream( morphs[i0].frameName, out, version ); \
	}; \
	if ( version <= 0x0A000102 ) { \
		NifStream( morphs[i0].numMorphKeys, out, version ); \
		NifStream( morphs[i0].morphInterpolation, out, version ); \
		for (uint i2 = 0; i2 < morphs[i0].morphKeys.size(); i2++) { \
			NifStream( morphs[i0].morphKeys[i2], out, version, morphs[i0].morphInterpolation ); \
		}; \
	}; \
	if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
		NifStream( morphs[i0].unknownInt, out, version ); \
	}; \
	for (uint i1 = 0; i1 < morphs[i0].vectors.size(); i1++) { \
		NifStream( morphs[i0].vectors[i1], out, version ); \
	}; \
}; \

#define NI_MORPH_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Num Morphs:  " << numMorphs << endl; \
out << "Num Vertices:  " << numVertices << endl; \
out << "Unknown Byte:  " << unknownByte << endl; \
for (uint i0 = 0; i0 < morphs.size(); i0++) { \
	out << "  Frame Name:  " << morphs[i0].frameName << endl; \
	out << "  Num Morph Keys:  " << morphs[i0].numMorphKeys << endl; \
	out << "  Morph Interpolation:  " << morphs[i0].morphInterpolation << endl; \
	for (uint i1 = 0; i1 < morphs[i0].morphKeys.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Morph Keys[" << i1 << "]:  " << morphs[i0].morphKeys[i1] << endl; \
	}; \
	out << "  Unknown Int:  " << morphs[i0].unknownInt << endl; \
	for (uint i1 = 0; i1 < morphs[i0].vectors.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Vectors[" << i1 << "]:  " << morphs[i0].vectors[i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_MORPH_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_MORPH_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_MEMBERS \
ushort numExtraTargets; \
vector<NiNode * > extraTargets; \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENT NiTimeController \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_CONSTRUCT \
 : numExtraTargets((ushort)0) \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
NifStream( numExtraTargets, in, version ); \
extraTargets.resize(numExtraTargets); \
for (uint i0 = 0; i0 < extraTargets.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
NifStream( numExtraTargets, out, version ); \
for (uint i0 = 0; i0 < extraTargets.size(); i0++) { \
	if ( extraTargets[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(extraTargets[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Num Extra Targets:  " << numExtraTargets << endl; \
for (uint i0 = 0; i0 < extraTargets.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Extra Targets[" << i0 << "]:  " << extraTargets[i0] << endl; \
}; \
return out.str(); \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < extraTargets.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		extraTargets[i0] = DynamicCast<NiNode>(objects[link_stack.front()]); \
		if ( extraTargets[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		extraTargets[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
for (uint i0 = 0; i0 < extraTargets.size(); i0++) { \
}; \
return refs; \

#define NI_NODE_MEMBERS \
uint numChildren; \
vector<Ref<NiAVObject > > children; \
uint numEffects; \
vector<Ref<NiDynamicEffect > > effects; \

#define NI_NODE_INCLUDE "NiAVObject.h" \

#define NI_NODE_PARENT NiAVObject \

#define NI_NODE_CONSTRUCT \
 : numChildren((uint)0), numEffects((uint)0) \

#define NI_NODE_READ \
uint block_num; \
NiAVObject::Read( in, link_stack, version, user_version ); \
NifStream( numChildren, in, version ); \
children.resize(numChildren); \
for (uint i0 = 0; i0 < children.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( numEffects, in, version ); \
effects.resize(numEffects); \
for (uint i0 = 0; i0 < effects.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_NODE_WRITE \
NiAVObject::Write( out, link_map, version, user_version ); \
NifStream( numChildren, out, version ); \
for (uint i0 = 0; i0 < children.size(); i0++) { \
	if ( children[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(children[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
NifStream( numEffects, out, version ); \
for (uint i0 = 0; i0 < effects.size(); i0++) { \
	if ( effects[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(effects[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_NODE_STRING \
stringstream out; \
out << NiAVObject::asString(); \
out << "Num Children:  " << numChildren << endl; \
for (uint i0 = 0; i0 < children.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Children[" << i0 << "]:  " << children[i0] << endl; \
}; \
out << "Num Effects:  " << numEffects << endl; \
for (uint i0 = 0; i0 < effects.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Effects[" << i0 << "]:  " << effects[i0] << endl; \
}; \
return out.str(); \

#define NI_NODE_FIXLINKS \
NiAVObject::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < children.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		children[i0] = DynamicCast<NiAVObject>(objects[link_stack.front()]); \
		if ( children[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		children[i0] = NULL; \
	link_stack.pop_front(); \
}; \
for (uint i0 = 0; i0 < effects.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		effects[i0] = DynamicCast<NiDynamicEffect>(objects[link_stack.front()]); \
		if ( effects[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		effects[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_NODE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiAVObject::GetRefs(); \
for (uint i0 = 0; i0 < children.size(); i0++) { \
	if ( children[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(children[i0])); \
}; \
for (uint i0 = 0; i0 < effects.size(); i0++) { \
	if ( effects[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(effects[i0])); \
}; \
return refs; \

#define AVOID_NODE_MEMBERS \

#define AVOID_NODE_INCLUDE "NiNode.h" \

#define AVOID_NODE_PARENT NiNode \

#define AVOID_NODE_CONSTRUCT \

#define AVOID_NODE_READ \
NiNode::Read( in, link_stack, version, user_version ); \

#define AVOID_NODE_WRITE \
NiNode::Write( out, link_map, version, user_version ); \

#define AVOID_NODE_STRING \
stringstream out; \
out << NiNode::asString(); \
return out.str(); \

#define AVOID_NODE_FIXLINKS \
NiNode::FixLinks( objects, link_stack, version, user_version ); \

#define AVOID_NODE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiNode::GetRefs(); \
return refs; \

#define FX_WIDGET_MEMBERS \
byte unknown1; \
byte unknown292Bytes[292]; \

#define FX_WIDGET_INCLUDE "NiNode.h" \

#define FX_WIDGET_PARENT NiNode \

#define FX_WIDGET_CONSTRUCT \
 : unknown1((byte)0) \

#define FX_WIDGET_READ \
NiNode::Read( in, link_stack, version, user_version ); \
NifStream( unknown1, in, version ); \
for (uint i0 = 0; i0 < 292; i0++) { \
	NifStream( unknown292Bytes[i0], in, version ); \
}; \

#define FX_WIDGET_WRITE \
NiNode::Write( out, link_map, version, user_version ); \
NifStream( unknown1, out, version ); \
for (uint i0 = 0; i0 < 292; i0++) { \
	NifStream( unknown292Bytes[i0], out, version ); \
}; \

#define FX_WIDGET_STRING \
stringstream out; \
out << NiNode::asString(); \
out << "Unknown1:  " << unknown1 << endl; \
for (uint i0 = 0; i0 < 292; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown 292 Bytes[" << i0 << "]:  " << unknown292Bytes[i0] << endl; \
}; \
return out.str(); \

#define FX_WIDGET_FIXLINKS \
NiNode::FixLinks( objects, link_stack, version, user_version ); \

#define FX_WIDGET_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiNode::GetRefs(); \
return refs; \

#define FX_BUTTON_MEMBERS \

#define FX_BUTTON_INCLUDE "FxWidget.h" \

#define FX_BUTTON_PARENT FxWidget \

#define FX_BUTTON_CONSTRUCT \

#define FX_BUTTON_READ \
FxWidget::Read( in, link_stack, version, user_version ); \

#define FX_BUTTON_WRITE \
FxWidget::Write( out, link_map, version, user_version ); \

#define FX_BUTTON_STRING \
stringstream out; \
out << FxWidget::asString(); \
return out.str(); \

#define FX_BUTTON_FIXLINKS \
FxWidget::FixLinks( objects, link_stack, version, user_version ); \

#define FX_BUTTON_GETREFS \
list<Ref<NiObject> > refs; \
refs = FxWidget::GetRefs(); \
return refs; \

#define FX_RADIO_BUTTON_MEMBERS \
uint unknownInt1; \
uint unknownInt2; \
uint unknownInt3; \
uint numUnknownLinks; \
vector<Ref<NiObject > > unknownLinks; \

#define FX_RADIO_BUTTON_INCLUDE "FxWidget.h" \

#define FX_RADIO_BUTTON_PARENT FxWidget \

#define FX_RADIO_BUTTON_CONSTRUCT \
 : unknownInt1((uint)0), unknownInt2((uint)0), unknownInt3((uint)0), numUnknownLinks((uint)0) \

#define FX_RADIO_BUTTON_READ \
uint block_num; \
FxWidget::Read( in, link_stack, version, user_version ); \
NifStream( unknownInt1, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( unknownInt3, in, version ); \
NifStream( numUnknownLinks, in, version ); \
unknownLinks.resize(numUnknownLinks); \
for (uint i0 = 0; i0 < unknownLinks.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define FX_RADIO_BUTTON_WRITE \
FxWidget::Write( out, link_map, version, user_version ); \
NifStream( unknownInt1, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( unknownInt3, out, version ); \
NifStream( numUnknownLinks, out, version ); \
for (uint i0 = 0; i0 < unknownLinks.size(); i0++) { \
	if ( unknownLinks[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(unknownLinks[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define FX_RADIO_BUTTON_STRING \
stringstream out; \
out << FxWidget::asString(); \
out << "Unknown Int 1:  " << unknownInt1 << endl; \
out << "Unknown Int  2:  " << unknownInt2 << endl; \
out << "Unknown Int 3:  " << unknownInt3 << endl; \
out << "Num Unknown Links:  " << numUnknownLinks << endl; \
for (uint i0 = 0; i0 < unknownLinks.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Links[" << i0 << "]:  " << unknownLinks[i0] << endl; \
}; \
return out.str(); \

#define FX_RADIO_BUTTON_FIXLINKS \
FxWidget::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < unknownLinks.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		unknownLinks[i0] = DynamicCast<NiObject>(objects[link_stack.front()]); \
		if ( unknownLinks[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		unknownLinks[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define FX_RADIO_BUTTON_GETREFS \
list<Ref<NiObject> > refs; \
refs = FxWidget::GetRefs(); \
for (uint i0 = 0; i0 < unknownLinks.size(); i0++) { \
	if ( unknownLinks[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(unknownLinks[i0])); \
}; \
return refs; \

#define NI_BILLBOARD_NODE_MEMBERS \
ushort billboardMode; \

#define NI_BILLBOARD_NODE_INCLUDE "NiNode.h" \

#define NI_BILLBOARD_NODE_PARENT NiNode \

#define NI_BILLBOARD_NODE_CONSTRUCT \
 : billboardMode((ushort)0) \

#define NI_BILLBOARD_NODE_READ \
NiNode::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( billboardMode, in, version ); \
}; \

#define NI_BILLBOARD_NODE_WRITE \
NiNode::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( billboardMode, out, version ); \
}; \

#define NI_BILLBOARD_NODE_STRING \
stringstream out; \
out << NiNode::asString(); \
out << "Billboard Mode:  " << billboardMode << endl; \
return out.str(); \

#define NI_BILLBOARD_NODE_FIXLINKS \
NiNode::FixLinks( objects, link_stack, version, user_version ); \

#define NI_BILLBOARD_NODE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiNode::GetRefs(); \
return refs; \

#define NI_B_S_ANIMATION_NODE_MEMBERS \

#define NI_B_S_ANIMATION_NODE_INCLUDE "NiNode.h" \

#define NI_B_S_ANIMATION_NODE_PARENT NiNode \

#define NI_B_S_ANIMATION_NODE_CONSTRUCT \

#define NI_B_S_ANIMATION_NODE_READ \
NiNode::Read( in, link_stack, version, user_version ); \

#define NI_B_S_ANIMATION_NODE_WRITE \
NiNode::Write( out, link_map, version, user_version ); \

#define NI_B_S_ANIMATION_NODE_STRING \
stringstream out; \
out << NiNode::asString(); \
return out.str(); \

#define NI_B_S_ANIMATION_NODE_FIXLINKS \
NiNode::FixLinks( objects, link_stack, version, user_version ); \

#define NI_B_S_ANIMATION_NODE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiNode::GetRefs(); \
return refs; \

#define NI_B_S_PARTICLE_NODE_MEMBERS \

#define NI_B_S_PARTICLE_NODE_INCLUDE "NiNode.h" \

#define NI_B_S_PARTICLE_NODE_PARENT NiNode \

#define NI_B_S_PARTICLE_NODE_CONSTRUCT \

#define NI_B_S_PARTICLE_NODE_READ \
NiNode::Read( in, link_stack, version, user_version ); \

#define NI_B_S_PARTICLE_NODE_WRITE \
NiNode::Write( out, link_map, version, user_version ); \

#define NI_B_S_PARTICLE_NODE_STRING \
stringstream out; \
out << NiNode::asString(); \
return out.str(); \

#define NI_B_S_PARTICLE_NODE_FIXLINKS \
NiNode::FixLinks( objects, link_stack, version, user_version ); \

#define NI_B_S_PARTICLE_NODE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiNode::GetRefs(); \
return refs; \

#define NI_L_O_D_NODE_MEMBERS \
uint lodType; \
Vector3 lodCenter; \
uint numLodLevels; \
vector<LODRange > lodLevels; \
ushort unknownShort; \
Ref<NiRangeLODData > rangeData; \

#define NI_L_O_D_NODE_INCLUDE "NiNode.h" \

#define NI_L_O_D_NODE_PARENT NiNode \

#define NI_L_O_D_NODE_CONSTRUCT \
 : lodType((uint)0), numLodLevels((uint)0), unknownShort((ushort)0), rangeData(NULL) \

#define NI_L_O_D_NODE_READ \
uint block_num; \
NiNode::Read( in, link_stack, version, user_version ); \
NifStream( lodType, in, version ); \
if ( (lodType == 0) ) { \
	NifStream( lodCenter, in, version ); \
	NifStream( numLodLevels, in, version ); \
	lodLevels.resize(numLodLevels); \
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) { \
		NifStream( lodLevels[i1].near, in, version ); \
		NifStream( lodLevels[i1].far, in, version ); \
	}; \
}; \
if ( (lodType == 1) ) { \
	NifStream( unknownShort, in, version ); \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_L_O_D_NODE_WRITE \
NiNode::Write( out, link_map, version, user_version ); \
NifStream( lodType, out, version ); \
if ( (lodType == 0) ) { \
	NifStream( lodCenter, out, version ); \
	NifStream( numLodLevels, out, version ); \
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) { \
		NifStream( lodLevels[i1].near, out, version ); \
		NifStream( lodLevels[i1].far, out, version ); \
	}; \
}; \
if ( (lodType == 1) ) { \
	NifStream( unknownShort, out, version ); \
	if ( rangeData != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(rangeData)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_L_O_D_NODE_STRING \
stringstream out; \
out << NiNode::asString(); \
out << "LOD Type:  " << lodType << endl; \
if ( (lodType == 0) ) { \
	out << "  LOD Center:  " << lodCenter << endl; \
	out << "  Num LOD Levels:  " << numLodLevels << endl; \
	for (uint i1 = 0; i1 < lodLevels.size(); i1++) { \
		out << "    Near:  " << lodLevels[i1].near << endl; \
		out << "    Far:  " << lodLevels[i1].far << endl; \
	}; \
}; \
if ( (lodType == 1) ) { \
	out << "  Unknown Short:  " << unknownShort << endl; \
	out << "  Range Data:  " << rangeData << endl; \
}; \
return out.str(); \

#define NI_L_O_D_NODE_FIXLINKS \
NiNode::FixLinks( objects, link_stack, version, user_version ); \
if ( (lodType == 1) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		rangeData = DynamicCast<NiRangeLODData>(objects[link_stack.front()]); \
		if ( rangeData == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		rangeData = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_L_O_D_NODE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiNode::GetRefs(); \
if ( rangeData != NULL ) \
	refs.push_back(StaticCast<NiObject>(rangeData)); \
return refs; \

#define NI_PALETTE_MEMBERS \
byte unknownByte; \
uint numEntries_; \
byte palette[256][4]; \

#define NI_PALETTE_INCLUDE "NiObject.h" \

#define NI_PALETTE_PARENT NiObject \

#define NI_PALETTE_CONSTRUCT \
 : unknownByte((byte)0), numEntries_((uint)0) \

#define NI_PALETTE_READ \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( unknownByte, in, version ); \
NifStream( numEntries_, in, version ); \
for (uint i0 = 0; i0 < 256; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		NifStream( palette[i0][i1], in, version ); \
	}; \
}; \

#define NI_PALETTE_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( unknownByte, out, version ); \
NifStream( numEntries_, out, version ); \
for (uint i0 = 0; i0 < 256; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		NifStream( palette[i0][i1], out, version ); \
	}; \
}; \

#define NI_PALETTE_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Unknown Byte:  " << unknownByte << endl; \
out << "Num Entries?:  " << numEntries_ << endl; \
for (uint i0 = 0; i0 < 256; i0++) { \
	for (uint i1 = 0; i1 < 4; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Palette[" << i0 << "][" << i1 << "]:  " << palette[i0][i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_PALETTE_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PALETTE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

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
AParticleModifier::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \
NifStream( unknownInt1, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( unknownFloat5, in, version ); \
NifStream( unknownFloat6, in, version ); \
NifStream( unknownFloat7, in, version ); \
NifStream( unknownFloat8, in, version ); \
NifStream( unknownFloat9, in, version ); \
NifStream( unknownFloat10, in, version ); \

#define NI_PARTICLE_BOMB_WRITE \
AParticleModifier::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \
NifStream( unknownInt1, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( unknownFloat5, out, version ); \
NifStream( unknownFloat6, out, version ); \
NifStream( unknownFloat7, out, version ); \
NifStream( unknownFloat8, out, version ); \
NifStream( unknownFloat9, out, version ); \
NifStream( unknownFloat10, out, version ); \

#define NI_PARTICLE_BOMB_STRING \
stringstream out; \
out << AParticleModifier::asString(); \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
out << "Unknown Float 3:  " << unknownFloat3 << endl; \
out << "Unknown Float 4:  " << unknownFloat4 << endl; \
out << "Unknown Int 1:  " << unknownInt1 << endl; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
out << "Unknown Float 5:  " << unknownFloat5 << endl; \
out << "Unknown Float 6:  " << unknownFloat6 << endl; \
out << "Unknown Float 7:  " << unknownFloat7 << endl; \
out << "Unknown Float 8:  " << unknownFloat8 << endl; \
out << "Unknown Float 9:  " << unknownFloat9 << endl; \
out << "Unknown Float 10:  " << unknownFloat10 << endl; \
return out.str(); \

#define NI_PARTICLE_BOMB_FIXLINKS \
AParticleModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_BOMB_GETREFS \
list<Ref<NiObject> > refs; \
refs = AParticleModifier::GetRefs(); \
return refs; \

#define NI_PARTICLE_COLOR_MODIFIER_MEMBERS \
Ref<NiColorData > colorData; \

#define NI_PARTICLE_COLOR_MODIFIER_INCLUDE "AParticleModifier.h" \

#define NI_PARTICLE_COLOR_MODIFIER_PARENT AParticleModifier \

#define NI_PARTICLE_COLOR_MODIFIER_CONSTRUCT \
 : colorData(NULL) \

#define NI_PARTICLE_COLOR_MODIFIER_READ \
uint block_num; \
AParticleModifier::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_PARTICLE_COLOR_MODIFIER_WRITE \
AParticleModifier::Write( out, link_map, version, user_version ); \
if ( colorData != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(colorData)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_PARTICLE_COLOR_MODIFIER_STRING \
stringstream out; \
out << AParticleModifier::asString(); \
out << "Color Data:  " << colorData << endl; \
return out.str(); \

#define NI_PARTICLE_COLOR_MODIFIER_FIXLINKS \
AParticleModifier::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	colorData = DynamicCast<NiColorData>(objects[link_stack.front()]); \
	if ( colorData == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	colorData = NULL; \
link_stack.pop_front(); \

#define NI_PARTICLE_COLOR_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = AParticleModifier::GetRefs(); \
if ( colorData != NULL ) \
	refs.push_back(StaticCast<NiObject>(colorData)); \
return refs; \

#define NI_PARTICLE_GROW_FADE_MEMBERS \
float grow; \
float fade; \

#define NI_PARTICLE_GROW_FADE_INCLUDE "AParticleModifier.h" \

#define NI_PARTICLE_GROW_FADE_PARENT AParticleModifier \

#define NI_PARTICLE_GROW_FADE_CONSTRUCT \
 : grow(0.0f), fade(0.0f) \

#define NI_PARTICLE_GROW_FADE_READ \
AParticleModifier::Read( in, link_stack, version, user_version ); \
NifStream( grow, in, version ); \
NifStream( fade, in, version ); \

#define NI_PARTICLE_GROW_FADE_WRITE \
AParticleModifier::Write( out, link_map, version, user_version ); \
NifStream( grow, out, version ); \
NifStream( fade, out, version ); \

#define NI_PARTICLE_GROW_FADE_STRING \
stringstream out; \
out << AParticleModifier::asString(); \
out << "Grow:  " << grow << endl; \
out << "Fade:  " << fade << endl; \
return out.str(); \

#define NI_PARTICLE_GROW_FADE_FIXLINKS \
AParticleModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_GROW_FADE_GETREFS \
list<Ref<NiObject> > refs; \
refs = AParticleModifier::GetRefs(); \
return refs; \

#define NI_PARTICLE_MESH_MODIFIER_MEMBERS \
uint numParticleMeshes; \
Ref<NiAVObject > particleMeshes; \

#define NI_PARTICLE_MESH_MODIFIER_INCLUDE "AParticleModifier.h" \

#define NI_PARTICLE_MESH_MODIFIER_PARENT AParticleModifier \

#define NI_PARTICLE_MESH_MODIFIER_CONSTRUCT \
 : numParticleMeshes((uint)0), particleMeshes(NULL) \

#define NI_PARTICLE_MESH_MODIFIER_READ \
uint block_num; \
AParticleModifier::Read( in, link_stack, version, user_version ); \
NifStream( numParticleMeshes, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_PARTICLE_MESH_MODIFIER_WRITE \
AParticleModifier::Write( out, link_map, version, user_version ); \
NifStream( numParticleMeshes, out, version ); \
if ( particleMeshes != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(particleMeshes)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_PARTICLE_MESH_MODIFIER_STRING \
stringstream out; \
out << AParticleModifier::asString(); \
out << "Num Particle Meshes:  " << numParticleMeshes << endl; \
out << "Particle Meshes:  " << particleMeshes << endl; \
return out.str(); \

#define NI_PARTICLE_MESH_MODIFIER_FIXLINKS \
AParticleModifier::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	particleMeshes = DynamicCast<NiAVObject>(objects[link_stack.front()]); \
	if ( particleMeshes == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	particleMeshes = NULL; \
link_stack.pop_front(); \

#define NI_PARTICLE_MESH_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = AParticleModifier::GetRefs(); \
if ( particleMeshes != NULL ) \
	refs.push_back(StaticCast<NiObject>(particleMeshes)); \
return refs; \

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
AParticleModifier::Read( in, link_stack, version, user_version ); \
NifStream( unknownByte, in, version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \

#define NI_PARTICLE_ROTATION_WRITE \
AParticleModifier::Write( out, link_map, version, user_version ); \
NifStream( unknownByte, out, version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \

#define NI_PARTICLE_ROTATION_STRING \
stringstream out; \
out << AParticleModifier::asString(); \
out << "Unknown Byte:  " << unknownByte << endl; \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
out << "Unknown Float 3:  " << unknownFloat3 << endl; \
out << "Unknown Float 4:  " << unknownFloat4 << endl; \
return out.str(); \

#define NI_PARTICLE_ROTATION_FIXLINKS \
AParticleModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_ROTATION_GETREFS \
list<Ref<NiObject> > refs; \
refs = AParticleModifier::GetRefs(); \
return refs; \

#define NI_PARTICLES_MEMBERS \

#define NI_PARTICLES_INCLUDE "NiTriBasedGeom.h" \

#define NI_PARTICLES_PARENT NiTriBasedGeom \

#define NI_PARTICLES_CONSTRUCT \

#define NI_PARTICLES_READ \
NiTriBasedGeom::Read( in, link_stack, version, user_version ); \

#define NI_PARTICLES_WRITE \
NiTriBasedGeom::Write( out, link_map, version, user_version ); \

#define NI_PARTICLES_STRING \
stringstream out; \
out << NiTriBasedGeom::asString(); \
return out.str(); \

#define NI_PARTICLES_FIXLINKS \
NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLES_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTriBasedGeom::GetRefs(); \
return refs; \

#define NI_AUTO_NORMAL_PARTICLES_MEMBERS \

#define NI_AUTO_NORMAL_PARTICLES_INCLUDE "NiParticles.h" \

#define NI_AUTO_NORMAL_PARTICLES_PARENT NiParticles \

#define NI_AUTO_NORMAL_PARTICLES_CONSTRUCT \

#define NI_AUTO_NORMAL_PARTICLES_READ \
NiParticles::Read( in, link_stack, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_WRITE \
NiParticles::Write( out, link_map, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_STRING \
stringstream out; \
out << NiParticles::asString(); \
return out.str(); \

#define NI_AUTO_NORMAL_PARTICLES_FIXLINKS \
NiParticles::FixLinks( objects, link_stack, version, user_version ); \

#define NI_AUTO_NORMAL_PARTICLES_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiParticles::GetRefs(); \
return refs; \

#define NI_PARTICLE_MESHES_MEMBERS \

#define NI_PARTICLE_MESHES_INCLUDE "NiParticles.h" \

#define NI_PARTICLE_MESHES_PARENT NiParticles \

#define NI_PARTICLE_MESHES_CONSTRUCT \

#define NI_PARTICLE_MESHES_READ \
NiParticles::Read( in, link_stack, version, user_version ); \

#define NI_PARTICLE_MESHES_WRITE \
NiParticles::Write( out, link_map, version, user_version ); \

#define NI_PARTICLE_MESHES_STRING \
stringstream out; \
out << NiParticles::asString(); \
return out.str(); \

#define NI_PARTICLE_MESHES_FIXLINKS \
NiParticles::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLE_MESHES_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiParticles::GetRefs(); \
return refs; \

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
NiAutoNormalParticlesData::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( numActive, in, version ); \
	NifStream( hasUnknownFloats, in, version ); \
	if ( (hasUnknownFloats != 0) ) { \
		unknownFloats.resize(numVertices); \
		for (uint i2 = 0; i2 < unknownFloats.size(); i2++) { \
			NifStream( unknownFloats[i2], in, version ); \
		}; \
	}; \
}; \
NifStream( hasRotations, in, version ); \
if ( (hasRotations != 0) ) { \
	rotations.resize(numVertices); \
	for (uint i1 = 0; i1 < rotations.size(); i1++) { \
		NifStream( rotations[i1], in, version ); \
	}; \
}; \

#define NI_PARTICLES_DATA_WRITE \
NiAutoNormalParticlesData::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( numActive, out, version ); \
	NifStream( hasUnknownFloats, out, version ); \
	if ( (hasUnknownFloats != 0) ) { \
		for (uint i2 = 0; i2 < unknownFloats.size(); i2++) { \
			NifStream( unknownFloats[i2], out, version ); \
		}; \
	}; \
}; \
NifStream( hasRotations, out, version ); \
if ( (hasRotations != 0) ) { \
	for (uint i1 = 0; i1 < rotations.size(); i1++) { \
		NifStream( rotations[i1], out, version ); \
	}; \
}; \

#define NI_PARTICLES_DATA_STRING \
stringstream out; \
out << NiAutoNormalParticlesData::asString(); \
out << "Num Active:  " << numActive << endl; \
out << "Has Unknown Floats:  " << hasUnknownFloats << endl; \
if ( (hasUnknownFloats != 0) ) { \
	for (uint i1 = 0; i1 < unknownFloats.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats[" << i1 << "]:  " << unknownFloats[i1] << endl; \
	}; \
}; \
out << "Has Rotations:  " << hasRotations << endl; \
if ( (hasRotations != 0) ) { \
	for (uint i1 = 0; i1 < rotations.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Rotations[" << i1 << "]:  " << rotations[i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_PARTICLES_DATA_FIXLINKS \
NiAutoNormalParticlesData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PARTICLES_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiAutoNormalParticlesData::GetRefs(); \
return refs; \

#define NI_PARTICLE_MESHES_DATA_MEMBERS \
Ref<NiAVObject > unknownLink2; \

#define NI_PARTICLE_MESHES_DATA_INCLUDE "NiParticlesData.h" \

#define NI_PARTICLE_MESHES_DATA_PARENT NiParticlesData \

#define NI_PARTICLE_MESHES_DATA_CONSTRUCT \
 : unknownLink2(NULL) \

#define NI_PARTICLE_MESHES_DATA_READ \
uint block_num; \
NiParticlesData::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_PARTICLE_MESHES_DATA_WRITE \
NiParticlesData::Write( out, link_map, version, user_version ); \
if ( unknownLink2 != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_PARTICLE_MESHES_DATA_STRING \
stringstream out; \
out << NiParticlesData::asString(); \
out << "Unknown Link 2:  " << unknownLink2 << endl; \
return out.str(); \

#define NI_PARTICLE_MESHES_DATA_FIXLINKS \
NiParticlesData::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink2 = DynamicCast<NiAVObject>(objects[link_stack.front()]); \
	if ( unknownLink2 == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink2 = NULL; \
link_stack.pop_front(); \

#define NI_PARTICLE_MESHES_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiParticlesData::GetRefs(); \
if ( unknownLink2 != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink2)); \
return refs; \

#define NI_PARTICLE_SYSTEM_MEMBERS \
bool unknownBool; \
uint numModifiers; \
vector<Ref<NiPSysModifier > > modifiers; \

#define NI_PARTICLE_SYSTEM_INCLUDE "NiParticles.h" \

#define NI_PARTICLE_SYSTEM_PARENT NiParticles \

#define NI_PARTICLE_SYSTEM_CONSTRUCT \
 : unknownBool(false), numModifiers((uint)0) \

#define NI_PARTICLE_SYSTEM_READ \
uint block_num; \
NiParticles::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknownBool, in, version ); \
	NifStream( numModifiers, in, version ); \
	modifiers.resize(numModifiers); \
	for (uint i1 = 0; i1 < modifiers.size(); i1++) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \

#define NI_PARTICLE_SYSTEM_WRITE \
NiParticles::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknownBool, out, version ); \
	NifStream( numModifiers, out, version ); \
	for (uint i1 = 0; i1 < modifiers.size(); i1++) { \
		if ( modifiers[i1] != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(modifiers[i1])], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \

#define NI_PARTICLE_SYSTEM_STRING \
stringstream out; \
out << NiParticles::asString(); \
out << "Unknown Bool:  " << unknownBool << endl; \
out << "Num Modifiers:  " << numModifiers << endl; \
for (uint i0 = 0; i0 < modifiers.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Modifiers[" << i0 << "]:  " << modifiers[i0] << endl; \
}; \
return out.str(); \

#define NI_PARTICLE_SYSTEM_FIXLINKS \
NiParticles::FixLinks( objects, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	for (uint i1 = 0; i1 < modifiers.size(); i1++) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			modifiers[i1] = DynamicCast<NiPSysModifier>(objects[link_stack.front()]); \
			if ( modifiers[i1] == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			modifiers[i1] = NULL; \
		link_stack.pop_front(); \
	}; \
}; \

#define NI_PARTICLE_SYSTEM_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiParticles::GetRefs(); \
for (uint i0 = 0; i0 < modifiers.size(); i0++) { \
	if ( modifiers[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(modifiers[i0])); \
}; \
return refs; \

#define NI_MESH_PARTICLE_SYSTEM_MEMBERS \

#define NI_MESH_PARTICLE_SYSTEM_INCLUDE "NiParticleSystem.h" \

#define NI_MESH_PARTICLE_SYSTEM_PARENT NiParticleSystem \

#define NI_MESH_PARTICLE_SYSTEM_CONSTRUCT \

#define NI_MESH_PARTICLE_SYSTEM_READ \
NiParticleSystem::Read( in, link_stack, version, user_version ); \

#define NI_MESH_PARTICLE_SYSTEM_WRITE \
NiParticleSystem::Write( out, link_map, version, user_version ); \

#define NI_MESH_PARTICLE_SYSTEM_STRING \
stringstream out; \
out << NiParticleSystem::asString(); \
return out.str(); \

#define NI_MESH_PARTICLE_SYSTEM_FIXLINKS \
NiParticleSystem::FixLinks( objects, link_stack, version, user_version ); \

#define NI_MESH_PARTICLE_SYSTEM_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiParticleSystem::GetRefs(); \
return refs; \

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
ushort numParticles; \
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
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
NifStream( speed, in, version ); \
NifStream( speedRandom, in, version ); \
NifStream( verticalDirection, in, version ); \
NifStream( verticalAngle, in, version ); \
NifStream( horizontalDirection, in, version ); \
NifStream( horizontalAngle, in, version ); \
NifStream( unknownFloat5, in, version ); \
NifStream( unknownFloat6, in, version ); \
NifStream( unknownFloat7, in, version ); \
NifStream( unknownFloat8, in, version ); \
NifStream( unknownFloat9, in, version ); \
NifStream( unknownFloat10, in, version ); \
NifStream( unknownFloat11, in, version ); \
NifStream( size, in, version ); \
NifStream( emitStartTime, in, version ); \
NifStream( emitStopTime, in, version ); \
NifStream( unknownByte, in, version ); \
NifStream( emitRate, in, version ); \
NifStream( lifetime, in, version ); \
NifStream( lifetimeRandom, in, version ); \
NifStream( emitFlags, in, version ); \
NifStream( startRandom, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( unknownShort2_, in, version ); \
NifStream( unknownFloat13_, in, version ); \
NifStream( unknownInt1_, in, version ); \
NifStream( unknownInt2_, in, version ); \
NifStream( unknownShort3_, in, version ); \
NifStream( numParticles, in, version ); \
NifStream( numValid, in, version ); \
particles.resize(numParticles); \
for (uint i0 = 0; i0 < particles.size(); i0++) { \
	NifStream( particles[i0].velocity, in, version ); \
	NifStream( particles[i0].unknownVector, in, version ); \
	NifStream( particles[i0].lifetime, in, version ); \
	NifStream( particles[i0].lifespan, in, version ); \
	NifStream( particles[i0].timestamp, in, version ); \
	NifStream( particles[i0].unknownShort, in, version ); \
	NifStream( particles[i0].vertexId, in, version ); \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( trailer, in, version ); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
NifStream( speed, out, version ); \
NifStream( speedRandom, out, version ); \
NifStream( verticalDirection, out, version ); \
NifStream( verticalAngle, out, version ); \
NifStream( horizontalDirection, out, version ); \
NifStream( horizontalAngle, out, version ); \
NifStream( unknownFloat5, out, version ); \
NifStream( unknownFloat6, out, version ); \
NifStream( unknownFloat7, out, version ); \
NifStream( unknownFloat8, out, version ); \
NifStream( unknownFloat9, out, version ); \
NifStream( unknownFloat10, out, version ); \
NifStream( unknownFloat11, out, version ); \
NifStream( size, out, version ); \
NifStream( emitStartTime, out, version ); \
NifStream( emitStopTime, out, version ); \
NifStream( unknownByte, out, version ); \
NifStream( emitRate, out, version ); \
NifStream( lifetime, out, version ); \
NifStream( lifetimeRandom, out, version ); \
NifStream( emitFlags, out, version ); \
NifStream( startRandom, out, version ); \
if ( emitter != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(emitter)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( unknownShort2_, out, version ); \
NifStream( unknownFloat13_, out, version ); \
NifStream( unknownInt1_, out, version ); \
NifStream( unknownInt2_, out, version ); \
NifStream( unknownShort3_, out, version ); \
NifStream( numParticles, out, version ); \
NifStream( numValid, out, version ); \
for (uint i0 = 0; i0 < particles.size(); i0++) { \
	NifStream( particles[i0].velocity, out, version ); \
	NifStream( particles[i0].unknownVector, out, version ); \
	NifStream( particles[i0].lifetime, out, version ); \
	NifStream( particles[i0].lifespan, out, version ); \
	NifStream( particles[i0].timestamp, out, version ); \
	NifStream( particles[i0].unknownShort, out, version ); \
	NifStream( particles[i0].vertexId, out, version ); \
}; \
if ( unknownLink != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( particleExtra != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(particleExtra)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( unknownLink2 != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink2)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( trailer, out, version ); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Speed:  " << speed << endl; \
out << "Speed Random:  " << speedRandom << endl; \
out << "Vertical Direction:  " << verticalDirection << endl; \
out << "Vertical Angle:  " << verticalAngle << endl; \
out << "Horizontal Direction:  " << horizontalDirection << endl; \
out << "Horizontal Angle:  " << horizontalAngle << endl; \
out << "Unknown Float 5:  " << unknownFloat5 << endl; \
out << "Unknown Float 6:  " << unknownFloat6 << endl; \
out << "Unknown Float 7:  " << unknownFloat7 << endl; \
out << "Unknown Float 8:  " << unknownFloat8 << endl; \
out << "Unknown Float 9:  " << unknownFloat9 << endl; \
out << "Unknown Float 10:  " << unknownFloat10 << endl; \
out << "Unknown Float 11:  " << unknownFloat11 << endl; \
out << "Size:  " << size << endl; \
out << "Emit Start Time:  " << emitStartTime << endl; \
out << "Emit Stop Time:  " << emitStopTime << endl; \
out << "Unknown Byte:  " << unknownByte << endl; \
out << "Emit Rate:  " << emitRate << endl; \
out << "Lifetime:  " << lifetime << endl; \
out << "Lifetime Random:  " << lifetimeRandom << endl; \
out << "Emit Flags:  " << emitFlags << endl; \
out << "Start Random:  " << startRandom << endl; \
out << "Emitter:  " << emitter << endl; \
out << "Unknown Short 2?:  " << unknownShort2_ << endl; \
out << "Unknown Float 13?:  " << unknownFloat13_ << endl; \
out << "Unknown Int 1?:  " << unknownInt1_ << endl; \
out << "Unknown Int 2?:  " << unknownInt2_ << endl; \
out << "Unknown Short 3?:  " << unknownShort3_ << endl; \
out << "Num Particles:  " << numParticles << endl; \
out << "Num Valid:  " << numValid << endl; \
for (uint i0 = 0; i0 < particles.size(); i0++) { \
	out << "  Velocity:  " << particles[i0].velocity << endl; \
	out << "  Unknown Vector:  " << particles[i0].unknownVector << endl; \
	out << "  Lifetime:  " << particles[i0].lifetime << endl; \
	out << "  Lifespan:  " << particles[i0].lifespan << endl; \
	out << "  Timestamp:  " << particles[i0].timestamp << endl; \
	out << "  Unknown Short:  " << particles[i0].unknownShort << endl; \
	out << "  Vertex ID:  " << particles[i0].vertexId << endl; \
}; \
out << "Unknown Link:  " << unknownLink << endl; \
out << "Particle Extra:  " << particleExtra << endl; \
out << "Unknown Link 2:  " << unknownLink2 << endl; \
out << "Trailer:  " << trailer << endl; \
return out.str(); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	emitter = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( emitter == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	emitter = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( unknownLink == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	particleExtra = DynamicCast<AParticleModifier>(objects[link_stack.front()]); \
	if ( particleExtra == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	particleExtra = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink2 = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( unknownLink2 == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink2 = NULL; \
link_stack.pop_front(); \

#define NI_PARTICLE_SYSTEM_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( emitter != NULL ) \
	refs.push_back(StaticCast<NiObject>(emitter)); \
if ( unknownLink != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink)); \
if ( particleExtra != NULL ) \
	refs.push_back(StaticCast<NiObject>(particleExtra)); \
if ( unknownLink2 != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink2)); \
return refs; \

#define NI_B_S_P_ARRAY_CONTROLLER_MEMBERS \

#define NI_B_S_P_ARRAY_CONTROLLER_INCLUDE "NiParticleSystemController.h" \

#define NI_B_S_P_ARRAY_CONTROLLER_PARENT NiParticleSystemController \

#define NI_B_S_P_ARRAY_CONTROLLER_CONSTRUCT \

#define NI_B_S_P_ARRAY_CONTROLLER_READ \
NiParticleSystemController::Read( in, link_stack, version, user_version ); \

#define NI_B_S_P_ARRAY_CONTROLLER_WRITE \
NiParticleSystemController::Write( out, link_map, version, user_version ); \

#define NI_B_S_P_ARRAY_CONTROLLER_STRING \
stringstream out; \
out << NiParticleSystemController::asString(); \
return out.str(); \

#define NI_B_S_P_ARRAY_CONTROLLER_FIXLINKS \
NiParticleSystemController::FixLinks( objects, link_stack, version, user_version ); \

#define NI_B_S_P_ARRAY_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiParticleSystemController::GetRefs(); \
return refs; \

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
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknownShort2, in, version ); \
}; \
NifStream( unknownInt1, in, version ); \
NifStream( unknownInt2, in, version ); \
NifStream( unknownInt3, in, version ); \
NifStream( unknownShort, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_PATH_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( unknownShort2, out, version ); \
}; \
NifStream( unknownInt1, out, version ); \
NifStream( unknownInt2, out, version ); \
NifStream( unknownInt3, out, version ); \
NifStream( unknownShort, out, version ); \
if ( posData != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(posData)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( floatData != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(floatData)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_PATH_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown Short 2:  " << unknownShort2 << endl; \
out << "Unknown Int 1:  " << unknownInt1 << endl; \
out << "Unknown Int 2:  " << unknownInt2 << endl; \
out << "Unknown Int 3:  " << unknownInt3 << endl; \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Pos Data:  " << posData << endl; \
out << "Float Data:  " << floatData << endl; \
return out.str(); \

#define NI_PATH_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	posData = DynamicCast<NiPosData>(objects[link_stack.front()]); \
	if ( posData == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	posData = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	floatData = DynamicCast<NiFloatData>(objects[link_stack.front()]); \
	if ( floatData == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	floatData = NULL; \
link_stack.pop_front(); \

#define NI_PATH_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( posData != NULL ) \
	refs.push_back(StaticCast<NiObject>(posData)); \
if ( floatData != NULL ) \
	refs.push_back(StaticCast<NiObject>(floatData)); \
return refs; \

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
uint block_num; \
NiBlendInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownShort2, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_PATH_INTERPOLATOR_WRITE \
NiBlendInterpolator::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownShort2, out, version ); \
if ( posData != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(posData)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( floatData != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(floatData)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_PATH_INTERPOLATOR_STRING \
stringstream out; \
out << NiBlendInterpolator::asString(); \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
out << "Unknown Short 2:  " << unknownShort2 << endl; \
out << "Pos Data:  " << posData << endl; \
out << "Float Data:  " << floatData << endl; \
return out.str(); \

#define NI_PATH_INTERPOLATOR_FIXLINKS \
NiBlendInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	posData = DynamicCast<NiPosData>(objects[link_stack.front()]); \
	if ( posData == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	posData = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	floatData = DynamicCast<NiFloatData>(objects[link_stack.front()]); \
	if ( floatData == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	floatData = NULL; \
link_stack.pop_front(); \

#define NI_PATH_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiBlendInterpolator::GetRefs(); \
if ( posData != NULL ) \
	refs.push_back(StaticCast<NiObject>(posData)); \
if ( floatData != NULL ) \
	refs.push_back(StaticCast<NiObject>(floatData)); \
return refs; \

#define NI_PIXEL_DATA_MEMBERS \
PixelFormat pixelFormat; \
uint redMask; \
uint greenMask; \
uint blueMask; \
uint alphaMask; \
uint bitsPerPixel; \
byte unknown8Bytes[8]; \
uint unknownInt; \
byte unknown54Bytes[54]; \
Ref<NiPalette > palette; \
uint numMipmaps; \
uint bytesPerPixel; \
vector<MipMap > mipmaps; \
ByteArray pixelData; \

#define NI_PIXEL_DATA_INCLUDE "NiObject.h" \

#define NI_PIXEL_DATA_PARENT NiObject \

#define NI_PIXEL_DATA_CONSTRUCT \
 : pixelFormat((PixelFormat)0), redMask((uint)0), greenMask((uint)0), blueMask((uint)0), alphaMask((uint)0), bitsPerPixel((uint)0), unknownInt((uint)0), palette(NULL), numMipmaps((uint)0), bytesPerPixel((uint)0) \

#define NI_PIXEL_DATA_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( pixelFormat, in, version ); \
if ( version <= 0x0A020000 ) { \
	NifStream( redMask, in, version ); \
	NifStream( greenMask, in, version ); \
	NifStream( blueMask, in, version ); \
	NifStream( alphaMask, in, version ); \
	NifStream( bitsPerPixel, in, version ); \
	for (uint i1 = 0; i1 < 8; i1++) { \
		NifStream( unknown8Bytes[i1], in, version ); \
	}; \
}; \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A020000 ) ) { \
	NifStream( unknownInt, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
	for (uint i1 = 0; i1 < 54; i1++) { \
		NifStream( unknown54Bytes[i1], in, version ); \
	}; \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( numMipmaps, in, version ); \
NifStream( bytesPerPixel, in, version ); \
mipmaps.resize(numMipmaps); \
for (uint i0 = 0; i0 < mipmaps.size(); i0++) { \
	NifStream( mipmaps[i0].width, in, version ); \
	NifStream( mipmaps[i0].height, in, version ); \
	NifStream( mipmaps[i0].offset, in, version ); \
}; \
NifStream( pixelData.dataSize, in, version ); \
if ( ( version >= 0x14000004 ) && ( version <= 0x14000004 ) ) { \
	NifStream( pixelData.unknownInt, in, version ); \
}; \
pixelData.data.resize(pixelData.dataSize); \
for (uint i0 = 0; i0 < pixelData.data.size(); i0++) { \
	NifStream( pixelData.data[i0], in, version ); \
}; \

#define NI_PIXEL_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( pixelFormat, out, version ); \
if ( version <= 0x0A020000 ) { \
	NifStream( redMask, out, version ); \
	NifStream( greenMask, out, version ); \
	NifStream( blueMask, out, version ); \
	NifStream( alphaMask, out, version ); \
	NifStream( bitsPerPixel, out, version ); \
	for (uint i1 = 0; i1 < 8; i1++) { \
		NifStream( unknown8Bytes[i1], out, version ); \
	}; \
}; \
if ( ( version >= 0x0A010000 ) && ( version <= 0x0A020000 ) ) { \
	NifStream( unknownInt, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
	for (uint i1 = 0; i1 < 54; i1++) { \
		NifStream( unknown54Bytes[i1], out, version ); \
	}; \
}; \
if ( palette != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(palette)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( numMipmaps, out, version ); \
NifStream( bytesPerPixel, out, version ); \
for (uint i0 = 0; i0 < mipmaps.size(); i0++) { \
	NifStream( mipmaps[i0].width, out, version ); \
	NifStream( mipmaps[i0].height, out, version ); \
	NifStream( mipmaps[i0].offset, out, version ); \
}; \
NifStream( pixelData.dataSize, out, version ); \
if ( ( version >= 0x14000004 ) && ( version <= 0x14000004 ) ) { \
	NifStream( pixelData.unknownInt, out, version ); \
}; \
for (uint i0 = 0; i0 < pixelData.data.size(); i0++) { \
	NifStream( pixelData.data[i0], out, version ); \
}; \

#define NI_PIXEL_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Pixel Format:  " << pixelFormat << endl; \
out << "Red Mask:  " << redMask << endl; \
out << "Green Mask:  " << greenMask << endl; \
out << "Blue Mask:  " << blueMask << endl; \
out << "Alpha Mask:  " << alphaMask << endl; \
out << "Bits Per Pixel:  " << bitsPerPixel << endl; \
for (uint i0 = 0; i0 < 8; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown 8 Bytes[" << i0 << "]:  " << unknown8Bytes[i0] << endl; \
}; \
out << "Unknown Int:  " << unknownInt << endl; \
for (uint i0 = 0; i0 < 54; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown 54 Bytes[" << i0 << "]:  " << unknown54Bytes[i0] << endl; \
}; \
out << "Palette:  " << palette << endl; \
out << "Num Mipmaps:  " << numMipmaps << endl; \
out << "Bytes Per Pixel:  " << bytesPerPixel << endl; \
for (uint i0 = 0; i0 < mipmaps.size(); i0++) { \
	out << "  Width:  " << mipmaps[i0].width << endl; \
	out << "  Height:  " << mipmaps[i0].height << endl; \
	out << "  Offset:  " << mipmaps[i0].offset << endl; \
}; \
out << "Data Size:  " << pixelData.dataSize << endl; \
out << "Unknown Int:  " << pixelData.unknownInt << endl; \
for (uint i0 = 0; i0 < pixelData.data.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Data[" << i0 << "]:  " << pixelData.data[i0] << endl; \
}; \
return out.str(); \

#define NI_PIXEL_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	palette = DynamicCast<NiPalette>(objects[link_stack.front()]); \
	if ( palette == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	palette = NULL; \
link_stack.pop_front(); \

#define NI_PIXEL_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( palette != NULL ) \
	refs.push_back(StaticCast<NiObject>(palette)); \
return refs; \

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
AParticleModifier::Read( in, link_stack, version, user_version ); \
if ( version >= 0x0A000100 ) { \
	NifStream( unknownShort, in, version ); \
}; \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownFloat2, in, version ); \
if ( ( version >= 0x04020200 ) && ( version <= 0x04020200 ) ) { \
	NifStream( unknownShort2, in, version ); \
}; \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \
NifStream( unknownFloat5, in, version ); \
NifStream( unknownFloat6, in, version ); \
NifStream( unknownFloat7, in, version ); \
NifStream( unknownFloat8, in, version ); \
NifStream( unknownFloat9, in, version ); \
NifStream( unknownFloat10, in, version ); \
NifStream( unknownFloat11, in, version ); \
NifStream( unknownFloat12, in, version ); \
NifStream( unknownFloat13, in, version ); \
NifStream( unknownFloat14, in, version ); \
NifStream( unknownFloat15, in, version ); \
NifStream( unknownFloat16, in, version ); \

#define NI_PLANAR_COLLIDER_WRITE \
AParticleModifier::Write( out, link_map, version, user_version ); \
if ( version >= 0x0A000100 ) { \
	NifStream( unknownShort, out, version ); \
}; \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownFloat2, out, version ); \
if ( ( version >= 0x04020200 ) && ( version <= 0x04020200 ) ) { \
	NifStream( unknownShort2, out, version ); \
}; \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \
NifStream( unknownFloat5, out, version ); \
NifStream( unknownFloat6, out, version ); \
NifStream( unknownFloat7, out, version ); \
NifStream( unknownFloat8, out, version ); \
NifStream( unknownFloat9, out, version ); \
NifStream( unknownFloat10, out, version ); \
NifStream( unknownFloat11, out, version ); \
NifStream( unknownFloat12, out, version ); \
NifStream( unknownFloat13, out, version ); \
NifStream( unknownFloat14, out, version ); \
NifStream( unknownFloat15, out, version ); \
NifStream( unknownFloat16, out, version ); \

#define NI_PLANAR_COLLIDER_STRING \
stringstream out; \
out << AParticleModifier::asString(); \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
out << "Unknown Short 2:  " << unknownShort2 << endl; \
out << "Unknown Float 3:  " << unknownFloat3 << endl; \
out << "Unknown Float 4:  " << unknownFloat4 << endl; \
out << "Unknown Float 5:  " << unknownFloat5 << endl; \
out << "Unknown Float 6:  " << unknownFloat6 << endl; \
out << "Unknown Float 7:  " << unknownFloat7 << endl; \
out << "Unknown Float 8:  " << unknownFloat8 << endl; \
out << "Unknown Float 9:  " << unknownFloat9 << endl; \
out << "Unknown Float 10:  " << unknownFloat10 << endl; \
out << "Unknown Float 11:  " << unknownFloat11 << endl; \
out << "Unknown Float 12:  " << unknownFloat12 << endl; \
out << "Unknown Float 13:  " << unknownFloat13 << endl; \
out << "Unknown Float 14:  " << unknownFloat14 << endl; \
out << "Unknown Float 15:  " << unknownFloat15 << endl; \
out << "Unknown Float 16:  " << unknownFloat16 << endl; \
return out.str(); \

#define NI_PLANAR_COLLIDER_FIXLINKS \
AParticleModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_PLANAR_COLLIDER_GETREFS \
list<Ref<NiObject> > refs; \
refs = AParticleModifier::GetRefs(); \
return refs; \

#define NI_POINT3_INTERPOLATOR_MEMBERS \
Vector3 point3Value; \
Ref<NiPosData > data; \

#define NI_POINT3_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_POINT3_INTERPOLATOR_PARENT NiInterpolator \

#define NI_POINT3_INTERPOLATOR_CONSTRUCT \
 : data(NULL) \

#define NI_POINT3_INTERPOLATOR_READ \
uint block_num; \
NiInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( point3Value, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_POINT3_INTERPOLATOR_WRITE \
NiInterpolator::Write( out, link_map, version, user_version ); \
NifStream( point3Value, out, version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_POINT3_INTERPOLATOR_STRING \
stringstream out; \
out << NiInterpolator::asString(); \
out << "Point 3 Value:  " << point3Value << endl; \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_POINT3_INTERPOLATOR_FIXLINKS \
NiInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiPosData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define NI_POINT3_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiInterpolator::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_POINT_LIGHT_MEMBERS \
float constantAttenuation; \
float linearAttenuation; \
float quadraticAttenuation; \

#define NI_POINT_LIGHT_INCLUDE "NiLight.h" \

#define NI_POINT_LIGHT_PARENT NiLight \

#define NI_POINT_LIGHT_CONSTRUCT \
 : constantAttenuation(0.0f), linearAttenuation(0.0f), quadraticAttenuation(0.0f) \

#define NI_POINT_LIGHT_READ \
NiLight::Read( in, link_stack, version, user_version ); \
NifStream( constantAttenuation, in, version ); \
NifStream( linearAttenuation, in, version ); \
NifStream( quadraticAttenuation, in, version ); \

#define NI_POINT_LIGHT_WRITE \
NiLight::Write( out, link_map, version, user_version ); \
NifStream( constantAttenuation, out, version ); \
NifStream( linearAttenuation, out, version ); \
NifStream( quadraticAttenuation, out, version ); \

#define NI_POINT_LIGHT_STRING \
stringstream out; \
out << NiLight::asString(); \
out << "Constant Attenuation:  " << constantAttenuation << endl; \
out << "Linear Attenuation:  " << linearAttenuation << endl; \
out << "Quadratic Attenuation:  " << quadraticAttenuation << endl; \
return out.str(); \

#define NI_POINT_LIGHT_FIXLINKS \
NiLight::FixLinks( objects, link_stack, version, user_version ); \

#define NI_POINT_LIGHT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiLight::GetRefs(); \
return refs; \

#define NI_POS_DATA_MEMBERS \
KeyGroup<Vector3 > data; \

#define NI_POS_DATA_INCLUDE "AKeyedData.h" \

#define NI_POS_DATA_PARENT AKeyedData \

#define NI_POS_DATA_CONSTRUCT \

#define NI_POS_DATA_READ \
AKeyedData::Read( in, link_stack, version, user_version ); \
NifStream( data.numKeys, in, version ); \
if ( (data.numKeys != 0) ) { \
	NifStream( data.interpolation, in, version ); \
}; \
data.keys.resize(data.numKeys); \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	NifStream( data.keys[i0], in, version, data.interpolation ); \
}; \

#define NI_POS_DATA_WRITE \
AKeyedData::Write( out, link_map, version, user_version ); \
NifStream( data.numKeys, out, version ); \
if ( (data.numKeys != 0) ) { \
	NifStream( data.interpolation, out, version ); \
}; \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	NifStream( data.keys[i0], out, version, data.interpolation ); \
}; \

#define NI_POS_DATA_STRING \
stringstream out; \
out << AKeyedData::asString(); \
out << "Num Keys:  " << data.numKeys << endl; \
if ( (data.numKeys != 0) ) { \
	out << "  Interpolation:  " << data.interpolation << endl; \
}; \
for (uint i0 = 0; i0 < data.keys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Keys[" << i0 << "]:  " << data.keys[i0] << endl; \
}; \
return out.str(); \

#define NI_POS_DATA_FIXLINKS \
AKeyedData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_POS_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = AKeyedData::GetRefs(); \
return refs; \

#define NI_P_SYS_AGE_DEATH_MODIFIER_MEMBERS \
bool spawnOnDeath; \
Ref<NiPSysSpawnModifier > spawnModifier; \

#define NI_P_SYS_AGE_DEATH_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_AGE_DEATH_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT \
 : spawnOnDeath(false), spawnModifier(NULL) \

#define NI_P_SYS_AGE_DEATH_MODIFIER_READ \
uint block_num; \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( spawnOnDeath, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
NifStream( spawnOnDeath, out, version ); \
if ( spawnModifier != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(spawnModifier)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Spawn on Death:  " << spawnOnDeath << endl; \
out << "Spawn Modifier:  " << spawnModifier << endl; \
return out.str(); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	spawnModifier = DynamicCast<NiPSysSpawnModifier>(objects[link_stack.front()]); \
	if ( spawnModifier == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	spawnModifier = NULL; \
link_stack.pop_front(); \

#define NI_P_SYS_AGE_DEATH_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
if ( spawnModifier != NULL ) \
	refs.push_back(StaticCast<NiObject>(spawnModifier)); \
return refs; \

#define NI_P_SYS_BOMB_MODIFIER_MEMBERS \
NiNode * unknownLink; \
uint unknownInts1[2]; \
float unknownFloats[3]; \
uint unknownInts2[2]; \

#define NI_P_SYS_BOMB_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_BOMB_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_BOMB_MODIFIER_CONSTRUCT \
 : unknownLink(NULL) \

#define NI_P_SYS_BOMB_MODIFIER_READ \
uint block_num; \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
for (uint i0 = 0; i0 < 2; i0++) { \
	NifStream( unknownInts1[i0], in, version ); \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	NifStream( unknownFloats[i0], in, version ); \
}; \
for (uint i0 = 0; i0 < 2; i0++) { \
	NifStream( unknownInts2[i0], in, version ); \
}; \

#define NI_P_SYS_BOMB_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
if ( unknownLink != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
for (uint i0 = 0; i0 < 2; i0++) { \
	NifStream( unknownInts1[i0], out, version ); \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	NifStream( unknownFloats[i0], out, version ); \
}; \
for (uint i0 = 0; i0 < 2; i0++) { \
	NifStream( unknownInts2[i0], out, version ); \
}; \

#define NI_P_SYS_BOMB_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Unknown Link:  " << unknownLink << endl; \
for (uint i0 = 0; i0 < 2; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Ints 1[" << i0 << "]:  " << unknownInts1[i0] << endl; \
}; \
for (uint i0 = 0; i0 < 3; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats[" << i0 << "]:  " << unknownFloats[i0] << endl; \
}; \
for (uint i0 = 0; i0 < 2; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Ints 2[" << i0 << "]:  " << unknownInts2[i0] << endl; \
}; \
return out.str(); \

#define NI_P_SYS_BOMB_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink = DynamicCast<NiNode>(objects[link_stack.front()]); \
	if ( unknownLink == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink = NULL; \
link_stack.pop_front(); \

#define NI_P_SYS_BOMB_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_MEMBERS \
ushort updateSkip; \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_CONSTRUCT \
 : updateSkip((ushort)0) \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_READ \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( updateSkip, in, version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
NifStream( updateSkip, out, version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Update Skip:  " << updateSkip << endl; \
return out.str(); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define NI_P_SYS_BOX_EMITTER_MEMBERS \
float width; \
float height; \
float depth; \

#define NI_P_SYS_BOX_EMITTER_INCLUDE "NiPSysVolumeEmitter.h" \

#define NI_P_SYS_BOX_EMITTER_PARENT NiPSysVolumeEmitter \

#define NI_P_SYS_BOX_EMITTER_CONSTRUCT \
 : width(0.0f), height(0.0f), depth(0.0f) \

#define NI_P_SYS_BOX_EMITTER_READ \
NiPSysVolumeEmitter::Read( in, link_stack, version, user_version ); \
NifStream( width, in, version ); \
NifStream( height, in, version ); \
NifStream( depth, in, version ); \

#define NI_P_SYS_BOX_EMITTER_WRITE \
NiPSysVolumeEmitter::Write( out, link_map, version, user_version ); \
NifStream( width, out, version ); \
NifStream( height, out, version ); \
NifStream( depth, out, version ); \

#define NI_P_SYS_BOX_EMITTER_STRING \
stringstream out; \
out << NiPSysVolumeEmitter::asString(); \
out << "Width:  " << width << endl; \
out << "Height:  " << height << endl; \
out << "Depth:  " << depth << endl; \
return out.str(); \

#define NI_P_SYS_BOX_EMITTER_FIXLINKS \
NiPSysVolumeEmitter::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_BOX_EMITTER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysVolumeEmitter::GetRefs(); \
return refs; \

#define NI_P_SYS_COLLIDER_MANAGER_MEMBERS \
Ref<NiPSysPlanarCollider > collider; \

#define NI_P_SYS_COLLIDER_MANAGER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_COLLIDER_MANAGER_PARENT NiPSysModifier \

#define NI_P_SYS_COLLIDER_MANAGER_CONSTRUCT \
 : collider(NULL) \

#define NI_P_SYS_COLLIDER_MANAGER_READ \
uint block_num; \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_P_SYS_COLLIDER_MANAGER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
if ( collider != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(collider)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_P_SYS_COLLIDER_MANAGER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Collider:  " << collider << endl; \
return out.str(); \

#define NI_P_SYS_COLLIDER_MANAGER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	collider = DynamicCast<NiPSysPlanarCollider>(objects[link_stack.front()]); \
	if ( collider == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	collider = NULL; \
link_stack.pop_front(); \

#define NI_P_SYS_COLLIDER_MANAGER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
if ( collider != NULL ) \
	refs.push_back(StaticCast<NiObject>(collider)); \
return refs; \

#define NI_P_SYS_COLOR_MODIFIER_MEMBERS \
Ref<NiColorData > data; \

#define NI_P_SYS_COLOR_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_COLOR_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_COLOR_MODIFIER_CONSTRUCT \
 : data(NULL) \

#define NI_P_SYS_COLOR_MODIFIER_READ \
uint block_num; \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_P_SYS_COLOR_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_P_SYS_COLOR_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_P_SYS_COLOR_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiColorData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define NI_P_SYS_COLOR_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_P_SYS_CYLINDER_EMITTER_MEMBERS \
float radius; \
float height; \

#define NI_P_SYS_CYLINDER_EMITTER_INCLUDE "NiPSysVolumeEmitter.h" \

#define NI_P_SYS_CYLINDER_EMITTER_PARENT NiPSysVolumeEmitter \

#define NI_P_SYS_CYLINDER_EMITTER_CONSTRUCT \
 : radius(0.0f), height(0.0f) \

#define NI_P_SYS_CYLINDER_EMITTER_READ \
NiPSysVolumeEmitter::Read( in, link_stack, version, user_version ); \
NifStream( radius, in, version ); \
NifStream( height, in, version ); \

#define NI_P_SYS_CYLINDER_EMITTER_WRITE \
NiPSysVolumeEmitter::Write( out, link_map, version, user_version ); \
NifStream( radius, out, version ); \
NifStream( height, out, version ); \

#define NI_P_SYS_CYLINDER_EMITTER_STRING \
stringstream out; \
out << NiPSysVolumeEmitter::asString(); \
out << "Radius:  " << radius << endl; \
out << "Height:  " << height << endl; \
return out.str(); \

#define NI_P_SYS_CYLINDER_EMITTER_FIXLINKS \
NiPSysVolumeEmitter::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_CYLINDER_EMITTER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysVolumeEmitter::GetRefs(); \
return refs; \

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
APSysData::Read( in, link_stack, version, user_version ); \
if ( version <= 0x0A020000 ) { \
	unknownFloats4.resize(numVertices); \
	for (uint i1 = 0; i1 < unknownFloats4.size(); i1++) { \
		for (uint i2 = 0; i2 < 10; i2++) { \
			NifStream( unknownFloats4[i1][i2], in, version ); \
		}; \
	}; \
}; \
if ( version >= 0x14000004 ) { \
	NifStream( unknownBool1, in, version ); \
	if ( (unknownBool1 != 0) ) { \
		unknownBytes.resize(numVertices); \
		for (uint i2 = 0; i2 < unknownBytes.size(); i2++) { \
			for (uint i3 = 0; i3 < 32; i3++) { \
				NifStream( unknownBytes[i2][i3], in, version ); \
			}; \
		}; \
	}; \
	if ( (unknownBool1 == 0) ) { \
		unknownBytesAlt.resize(numVertices); \
		for (uint i2 = 0; i2 < unknownBytesAlt.size(); i2++) { \
			for (uint i3 = 0; i3 < 28; i3++) { \
				NifStream( unknownBytesAlt[i2][i3], in, version ); \
			}; \
		}; \
	}; \
	NifStream( unknownByte3, in, version ); \
	NifStream( unknownBool2, in, version ); \
	if ( (unknownBool2 != 0) ) { \
		unknownBytes2.resize(numVertices); \
		for (uint i2 = 0; i2 < unknownBytes2.size(); i2++) { \
			for (uint i3 = 0; i3 < 4; i3++) { \
				NifStream( unknownBytes2[i2][i3], in, version ); \
			}; \
		}; \
	}; \
}; \
NifStream( unknownInt1, in, version ); \

#define NI_P_SYS_DATA_WRITE \
APSysData::Write( out, link_map, version, user_version ); \
if ( version <= 0x0A020000 ) { \
	for (uint i1 = 0; i1 < unknownFloats4.size(); i1++) { \
		for (uint i2 = 0; i2 < 10; i2++) { \
			NifStream( unknownFloats4[i1][i2], out, version ); \
		}; \
	}; \
}; \
if ( version >= 0x14000004 ) { \
	NifStream( unknownBool1, out, version ); \
	if ( (unknownBool1 != 0) ) { \
		for (uint i2 = 0; i2 < unknownBytes.size(); i2++) { \
			for (uint i3 = 0; i3 < 32; i3++) { \
				NifStream( unknownBytes[i2][i3], out, version ); \
			}; \
		}; \
	}; \
	if ( (unknownBool1 == 0) ) { \
		for (uint i2 = 0; i2 < unknownBytesAlt.size(); i2++) { \
			for (uint i3 = 0; i3 < 28; i3++) { \
				NifStream( unknownBytesAlt[i2][i3], out, version ); \
			}; \
		}; \
	}; \
	NifStream( unknownByte3, out, version ); \
	NifStream( unknownBool2, out, version ); \
	if ( (unknownBool2 != 0) ) { \
		for (uint i2 = 0; i2 < unknownBytes2.size(); i2++) { \
			for (uint i3 = 0; i3 < 4; i3++) { \
				NifStream( unknownBytes2[i2][i3], out, version ); \
			}; \
		}; \
	}; \
}; \
NifStream( unknownInt1, out, version ); \

#define NI_P_SYS_DATA_STRING \
stringstream out; \
out << APSysData::asString(); \
for (uint i0 = 0; i0 < unknownFloats4.size(); i0++) { \
	for (uint i1 = 0; i1 < 10; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown Floats 4[" << i0 << "][" << i1 << "]:  " << unknownFloats4[i0][i1] << endl; \
	}; \
}; \
out << "Unknown Bool 1:  " << unknownBool1 << endl; \
if ( (unknownBool1 != 0) ) { \
	for (uint i1 = 0; i1 < unknownBytes.size(); i1++) { \
		for (uint i2 = 0; i2 < 32; i2++) { \
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) { \
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
				break; \
			}; \
			out << "      Unknown Bytes[" << i1 << "][" << i2 << "]:  " << unknownBytes[i1][i2] << endl; \
		}; \
	}; \
}; \
if ( (unknownBool1 == 0) ) { \
	for (uint i1 = 0; i1 < unknownBytesAlt.size(); i1++) { \
		for (uint i2 = 0; i2 < 28; i2++) { \
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) { \
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
				break; \
			}; \
			out << "      Unknown Bytes Alt[" << i1 << "][" << i2 << "]:  " << unknownBytesAlt[i1][i2] << endl; \
		}; \
	}; \
}; \
out << "Unknown Byte 3:  " << unknownByte3 << endl; \
out << "Unknown Bool 2:  " << unknownBool2 << endl; \
if ( (unknownBool2 != 0) ) { \
	for (uint i1 = 0; i1 < unknownBytes2.size(); i1++) { \
		for (uint i2 = 0; i2 < 4; i2++) { \
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) { \
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
				break; \
			}; \
			out << "      Unknown Bytes 2[" << i1 << "][" << i2 << "]:  " << unknownBytes2[i1][i2] << endl; \
		}; \
	}; \
}; \
out << "Unknown Int 1:  " << unknownInt1 << endl; \
return out.str(); \

#define NI_P_SYS_DATA_FIXLINKS \
APSysData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysData::GetRefs(); \
return refs; \

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
uint block_num; \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( dragAxis, in, version ); \
NifStream( percentage, in, version ); \
NifStream( range, in, version ); \
NifStream( rangeFalloff, in, version ); \

#define NI_P_SYS_DRAG_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
if ( parent != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(parent)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( dragAxis, out, version ); \
NifStream( percentage, out, version ); \
NifStream( range, out, version ); \
NifStream( rangeFalloff, out, version ); \

#define NI_P_SYS_DRAG_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Parent:  " << parent << endl; \
out << "Drag Axis:  " << dragAxis << endl; \
out << "Percentage:  " << percentage << endl; \
out << "Range:  " << range << endl; \
out << "Range Falloff:  " << rangeFalloff << endl; \
return out.str(); \

#define NI_P_SYS_DRAG_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	parent = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( parent == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	parent = NULL; \
link_stack.pop_front(); \

#define NI_P_SYS_DRAG_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define NI_P_SYS_EMITTER_CTLR_MEMBERS \
Ref<NiPSysEmitterCtlrData > data; \
Ref<NiInterpolator > visibilityInterpolator; \

#define NI_P_SYS_EMITTER_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_CTLR_CONSTRUCT \
 : data(NULL), visibilityInterpolator(NULL) \

#define NI_P_SYS_EMITTER_CTLR_READ \
uint block_num; \
APSysCtlr::Read( in, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
if ( version >= 0x0A020000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_P_SYS_EMITTER_CTLR_WRITE \
APSysCtlr::Write( out, link_map, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if ( data != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( version >= 0x0A020000 ) { \
	if ( visibilityInterpolator != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(visibilityInterpolator)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_P_SYS_EMITTER_CTLR_STRING \
stringstream out; \
out << APSysCtlr::asString(); \
out << "Data:  " << data << endl; \
out << "Visibility Interpolator:  " << visibilityInterpolator << endl; \
return out.str(); \

#define NI_P_SYS_EMITTER_CTLR_FIXLINKS \
APSysCtlr::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		data = DynamicCast<NiPSysEmitterCtlrData>(objects[link_stack.front()]); \
		if ( data == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		data = NULL; \
	link_stack.pop_front(); \
}; \
if ( version >= 0x0A020000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		visibilityInterpolator = DynamicCast<NiInterpolator>(objects[link_stack.front()]); \
		if ( visibilityInterpolator == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		visibilityInterpolator = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_P_SYS_EMITTER_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysCtlr::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
if ( visibilityInterpolator != NULL ) \
	refs.push_back(StaticCast<NiObject>(visibilityInterpolator)); \
return refs; \

#define NI_P_SYS_EMITTER_CTLR_DATA_MEMBERS \
KeyGroup<float > floatKeys_; \
uint numVisibilityKeys_; \
vector<Key<byte > > visibilityKeys_; \

#define NI_P_SYS_EMITTER_CTLR_DATA_INCLUDE "NiObject.h" \

#define NI_P_SYS_EMITTER_CTLR_DATA_PARENT NiObject \

#define NI_P_SYS_EMITTER_CTLR_DATA_CONSTRUCT \
 : numVisibilityKeys_((uint)0) \

#define NI_P_SYS_EMITTER_CTLR_DATA_READ \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( floatKeys_.numKeys, in, version ); \
if ( (floatKeys_.numKeys != 0) ) { \
	NifStream( floatKeys_.interpolation, in, version ); \
}; \
floatKeys_.keys.resize(floatKeys_.numKeys); \
for (uint i0 = 0; i0 < floatKeys_.keys.size(); i0++) { \
	NifStream( floatKeys_.keys[i0], in, version, floatKeys_.interpolation ); \
}; \
NifStream( numVisibilityKeys_, in, version ); \
visibilityKeys_.resize(numVisibilityKeys_); \
for (uint i0 = 0; i0 < visibilityKeys_.size(); i0++) { \
	NifStream( visibilityKeys_[i0], in, version, 1 ); \
}; \

#define NI_P_SYS_EMITTER_CTLR_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( floatKeys_.numKeys, out, version ); \
if ( (floatKeys_.numKeys != 0) ) { \
	NifStream( floatKeys_.interpolation, out, version ); \
}; \
for (uint i0 = 0; i0 < floatKeys_.keys.size(); i0++) { \
	NifStream( floatKeys_.keys[i0], out, version, floatKeys_.interpolation ); \
}; \
NifStream( numVisibilityKeys_, out, version ); \
for (uint i0 = 0; i0 < visibilityKeys_.size(); i0++) { \
	NifStream( visibilityKeys_[i0], out, version, 1 ); \
}; \

#define NI_P_SYS_EMITTER_CTLR_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Num Keys:  " << floatKeys_.numKeys << endl; \
if ( (floatKeys_.numKeys != 0) ) { \
	out << "  Interpolation:  " << floatKeys_.interpolation << endl; \
}; \
for (uint i0 = 0; i0 < floatKeys_.keys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Keys[" << i0 << "]:  " << floatKeys_.keys[i0] << endl; \
}; \
out << "Num Visibility Keys?:  " << numVisibilityKeys_ << endl; \
for (uint i0 = 0; i0 < visibilityKeys_.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Visibility Keys?[" << i0 << "]:  " << visibilityKeys_[i0] << endl; \
}; \
return out.str(); \

#define NI_P_SYS_EMITTER_CTLR_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_CTLR_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_READ \
APSysCtlr::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_WRITE \
APSysCtlr::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_STRING \
stringstream out; \
out << APSysCtlr::asString(); \
return out.str(); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_FIXLINKS \
APSysCtlr::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysCtlr::GetRefs(); \
return refs; \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_READ \
APSysCtlr::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_WRITE \
APSysCtlr::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_STRING \
stringstream out; \
out << APSysCtlr::asString(); \
return out.str(); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_FIXLINKS \
APSysCtlr::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysCtlr::GetRefs(); \
return refs; \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_READ \
APSysCtlr::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_WRITE \
APSysCtlr::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_STRING \
stringstream out; \
out << APSysCtlr::asString(); \
return out.str(); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_FIXLINKS \
APSysCtlr::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysCtlr::GetRefs(); \
return refs; \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_READ \
APSysCtlr::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_WRITE \
APSysCtlr::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_STRING \
stringstream out; \
out << APSysCtlr::asString(); \
return out.str(); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_FIXLINKS \
APSysCtlr::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysCtlr::GetRefs(); \
return refs; \

#define NI_P_SYS_EMITTER_SPEED_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_SPEED_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_EMITTER_SPEED_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_EMITTER_SPEED_CTLR_CONSTRUCT \

#define NI_P_SYS_EMITTER_SPEED_CTLR_READ \
APSysCtlr::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_WRITE \
APSysCtlr::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_STRING \
stringstream out; \
out << APSysCtlr::asString(); \
return out.str(); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_FIXLINKS \
APSysCtlr::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_EMITTER_SPEED_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysCtlr::GetRefs(); \
return refs; \

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
uint block_num; \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( gravityAxis, in, version ); \
NifStream( decay, in, version ); \
NifStream( strength, in, version ); \
NifStream( forceType, in, version ); \
NifStream( turbulence, in, version ); \
NifStream( turbulenceScale, in, version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
if ( gravityObject != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(gravityObject)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( gravityAxis, out, version ); \
NifStream( decay, out, version ); \
NifStream( strength, out, version ); \
NifStream( forceType, out, version ); \
NifStream( turbulence, out, version ); \
NifStream( turbulenceScale, out, version ); \

#define NI_P_SYS_GRAVITY_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Gravity Object:  " << gravityObject << endl; \
out << "Gravity Axis:  " << gravityAxis << endl; \
out << "Decay:  " << decay << endl; \
out << "Strength:  " << strength << endl; \
out << "Force Type:  " << forceType << endl; \
out << "Turbulence:  " << turbulence << endl; \
out << "Turbulence Scale:  " << turbulenceScale << endl; \
return out.str(); \

#define NI_P_SYS_GRAVITY_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	gravityObject = DynamicCast<NiNode>(objects[link_stack.front()]); \
	if ( gravityObject == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	gravityObject = NULL; \
link_stack.pop_front(); \

#define NI_P_SYS_GRAVITY_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_MEMBERS \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_CONSTRUCT \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_READ \
APSysCtlr::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_WRITE \
APSysCtlr::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_STRING \
stringstream out; \
out << APSysCtlr::asString(); \
return out.str(); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_FIXLINKS \
APSysCtlr::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysCtlr::GetRefs(); \
return refs; \

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
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( growTime, in, version ); \
NifStream( growGeneration, in, version ); \
NifStream( fadeTime, in, version ); \
NifStream( fadeGeneration, in, version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
NifStream( growTime, out, version ); \
NifStream( growGeneration, out, version ); \
NifStream( fadeTime, out, version ); \
NifStream( fadeGeneration, out, version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Grow Time:  " << growTime << endl; \
out << "Grow Generation:  " << growGeneration << endl; \
out << "Fade Time:  " << fadeTime << endl; \
out << "Fade Generation:  " << fadeGeneration << endl; \
return out.str(); \

#define NI_P_SYS_GROW_FADE_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_GROW_FADE_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define NI_P_SYS_MESH_EMITTER_MEMBERS \
uint numEmitterMeshes; \
vector<Ref<NiTriBasedGeom > > emitterMeshes; \
uint initialVelocityType; \
uint emissionType; \
Vector3 emissionAxis; \

#define NI_P_SYS_MESH_EMITTER_INCLUDE "NiPSysEmitter.h" \

#define NI_P_SYS_MESH_EMITTER_PARENT NiPSysEmitter \

#define NI_P_SYS_MESH_EMITTER_CONSTRUCT \
 : numEmitterMeshes((uint)0), initialVelocityType((uint)0), emissionType((uint)0) \

#define NI_P_SYS_MESH_EMITTER_READ \
uint block_num; \
NiPSysEmitter::Read( in, link_stack, version, user_version ); \
NifStream( numEmitterMeshes, in, version ); \
emitterMeshes.resize(numEmitterMeshes); \
for (uint i0 = 0; i0 < emitterMeshes.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( initialVelocityType, in, version ); \
NifStream( emissionType, in, version ); \
NifStream( emissionAxis, in, version ); \

#define NI_P_SYS_MESH_EMITTER_WRITE \
NiPSysEmitter::Write( out, link_map, version, user_version ); \
NifStream( numEmitterMeshes, out, version ); \
for (uint i0 = 0; i0 < emitterMeshes.size(); i0++) { \
	if ( emitterMeshes[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(emitterMeshes[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
NifStream( initialVelocityType, out, version ); \
NifStream( emissionType, out, version ); \
NifStream( emissionAxis, out, version ); \

#define NI_P_SYS_MESH_EMITTER_STRING \
stringstream out; \
out << NiPSysEmitter::asString(); \
out << "Num Emitter Meshes:  " << numEmitterMeshes << endl; \
for (uint i0 = 0; i0 < emitterMeshes.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Emitter Meshes[" << i0 << "]:  " << emitterMeshes[i0] << endl; \
}; \
out << "Initial Velocity Type:  " << initialVelocityType << endl; \
out << "Emission Type:  " << emissionType << endl; \
out << "Emission Axis:  " << emissionAxis << endl; \
return out.str(); \

#define NI_P_SYS_MESH_EMITTER_FIXLINKS \
NiPSysEmitter::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < emitterMeshes.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		emitterMeshes[i0] = DynamicCast<NiTriBasedGeom>(objects[link_stack.front()]); \
		if ( emitterMeshes[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		emitterMeshes[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_P_SYS_MESH_EMITTER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysEmitter::GetRefs(); \
for (uint i0 = 0; i0 < emitterMeshes.size(); i0++) { \
	if ( emitterMeshes[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(emitterMeshes[i0])); \
}; \
return refs; \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_MEMBERS \
uint numMeshes; \
vector<Ref<NiNode > > meshes; \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_CONSTRUCT \
 : numMeshes((uint)0) \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_READ \
uint block_num; \
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( numMeshes, in, version ); \
meshes.resize(numMeshes); \
for (uint i0 = 0; i0 < meshes.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
NifStream( numMeshes, out, version ); \
for (uint i0 = 0; i0 < meshes.size(); i0++) { \
	if ( meshes[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(meshes[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Num Meshes:  " << numMeshes << endl; \
for (uint i0 = 0; i0 < meshes.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Meshes[" << i0 << "]:  " << meshes[i0] << endl; \
}; \
return out.str(); \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < meshes.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		meshes[i0] = DynamicCast<NiNode>(objects[link_stack.front()]); \
		if ( meshes[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		meshes[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
for (uint i0 = 0; i0 < meshes.size(); i0++) { \
	if ( meshes[i0] != NULL ) \
		refs.push_back(StaticCast<NiObject>(meshes[i0])); \
}; \
return refs; \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_MEMBERS \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_INCLUDE "APSysCtlr.h" \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_PARENT APSysCtlr \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_CONSTRUCT \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_READ \
APSysCtlr::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_WRITE \
APSysCtlr::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_STRING \
stringstream out; \
out << APSysCtlr::asString(); \
return out.str(); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_FIXLINKS \
APSysCtlr::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = APSysCtlr::GetRefs(); \
return refs; \

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
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( bounce, in, version ); \
NifStream( spawnOnCollide, in, version ); \
NifStream( dieOnCollide, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( width, in, version ); \
NifStream( height, in, version ); \
NifStream( xAxis, in, version ); \
NifStream( yAxis, in, version ); \

#define NI_P_SYS_PLANAR_COLLIDER_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( bounce, out, version ); \
NifStream( spawnOnCollide, out, version ); \
NifStream( dieOnCollide, out, version ); \
if ( spawnModifier != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(spawnModifier)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( parent != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(parent)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( unknownLink_ != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(unknownLink_)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( colliderObject != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(colliderObject)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( width, out, version ); \
NifStream( height, out, version ); \
NifStream( xAxis, out, version ); \
NifStream( yAxis, out, version ); \

#define NI_P_SYS_PLANAR_COLLIDER_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Bounce:  " << bounce << endl; \
out << "Spawn on Collide:  " << spawnOnCollide << endl; \
out << "Die on Collide:  " << dieOnCollide << endl; \
out << "Spawn Modifier:  " << spawnModifier << endl; \
out << "Parent:  " << parent << endl; \
out << "Unknown Link?:  " << unknownLink_ << endl; \
out << "Collider Object:  " << colliderObject << endl; \
out << "Width:  " << width << endl; \
out << "Height:  " << height << endl; \
out << "X Axis:  " << xAxis << endl; \
out << "Y Axis:  " << yAxis << endl; \
return out.str(); \

#define NI_P_SYS_PLANAR_COLLIDER_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	spawnModifier = DynamicCast<NiPSysSpawnModifier>(objects[link_stack.front()]); \
	if ( spawnModifier == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	spawnModifier = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	parent = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( parent == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	parent = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	unknownLink_ = DynamicCast<NiObject>(objects[link_stack.front()]); \
	if ( unknownLink_ == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	unknownLink_ = NULL; \
link_stack.pop_front(); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	colliderObject = DynamicCast<NiNode>(objects[link_stack.front()]); \
	if ( colliderObject == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	colliderObject = NULL; \
link_stack.pop_front(); \

#define NI_P_SYS_PLANAR_COLLIDER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( spawnModifier != NULL ) \
	refs.push_back(StaticCast<NiObject>(spawnModifier)); \
if ( unknownLink_ != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink_)); \
if ( colliderObject != NULL ) \
	refs.push_back(StaticCast<NiObject>(colliderObject)); \
return refs; \

#define NI_P_SYS_POSITION_MODIFIER_MEMBERS \

#define NI_P_SYS_POSITION_MODIFIER_INCLUDE "NiPSysModifier.h" \

#define NI_P_SYS_POSITION_MODIFIER_PARENT NiPSysModifier \

#define NI_P_SYS_POSITION_MODIFIER_CONSTRUCT \

#define NI_P_SYS_POSITION_MODIFIER_READ \
NiPSysModifier::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_POSITION_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_POSITION_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
return out.str(); \

#define NI_P_SYS_POSITION_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_POSITION_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_MEMBERS \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_INCLUDE "NiTimeController.h" \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT NiTimeController \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_CONSTRUCT \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_READ \
NiTimeController::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_STRING \
stringstream out; \
out << NiTimeController::asString(); \
return out.str(); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
return refs; \

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
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( initialRotationSpeed, in, version ); \
if ( version >= 0x14000004 ) { \
	NifStream( initialRotationSpeedVariation, in, version ); \
	NifStream( initialRotationAngle, in, version ); \
	NifStream( initialRotationAngleVariation, in, version ); \
	NifStream( randomRotSpeedSign, in, version ); \
}; \
NifStream( randomInitialAxis, in, version ); \
NifStream( initialAxis, in, version ); \

#define NI_P_SYS_ROTATION_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
NifStream( initialRotationSpeed, out, version ); \
if ( version >= 0x14000004 ) { \
	NifStream( initialRotationSpeedVariation, out, version ); \
	NifStream( initialRotationAngle, out, version ); \
	NifStream( initialRotationAngleVariation, out, version ); \
	NifStream( randomRotSpeedSign, out, version ); \
}; \
NifStream( randomInitialAxis, out, version ); \
NifStream( initialAxis, out, version ); \

#define NI_P_SYS_ROTATION_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Initial Rotation Speed:  " << initialRotationSpeed << endl; \
out << "Initial Rotation Speed Variation:  " << initialRotationSpeedVariation << endl; \
out << "Initial Rotation Angle:  " << initialRotationAngle << endl; \
out << "Initial Rotation Angle Variation:  " << initialRotationAngleVariation << endl; \
out << "Random Rot Speed Sign:  " << randomRotSpeedSign << endl; \
out << "Random Initial Axis:  " << randomInitialAxis << endl; \
out << "Initial Axis:  " << initialAxis << endl; \
return out.str(); \

#define NI_P_SYS_ROTATION_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_ROTATION_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

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
NiPSysModifier::Read( in, link_stack, version, user_version ); \
NifStream( numSpawnGenerations, in, version ); \
NifStream( percentageSpawned, in, version ); \
NifStream( minNumToSpawn, in, version ); \
NifStream( maxNumToSpawn, in, version ); \
NifStream( spawnSpeedChaos, in, version ); \
NifStream( spawnDirChaos, in, version ); \
NifStream( lifeSpan, in, version ); \
NifStream( lifeSpanVariation, in, version ); \

#define NI_P_SYS_SPAWN_MODIFIER_WRITE \
NiPSysModifier::Write( out, link_map, version, user_version ); \
NifStream( numSpawnGenerations, out, version ); \
NifStream( percentageSpawned, out, version ); \
NifStream( minNumToSpawn, out, version ); \
NifStream( maxNumToSpawn, out, version ); \
NifStream( spawnSpeedChaos, out, version ); \
NifStream( spawnDirChaos, out, version ); \
NifStream( lifeSpan, out, version ); \
NifStream( lifeSpanVariation, out, version ); \

#define NI_P_SYS_SPAWN_MODIFIER_STRING \
stringstream out; \
out << NiPSysModifier::asString(); \
out << "Num Spawn Generations:  " << numSpawnGenerations << endl; \
out << "Percentage Spawned:  " << percentageSpawned << endl; \
out << "Min Num to Spawn:  " << minNumToSpawn << endl; \
out << "Max Num to Spawn:  " << maxNumToSpawn << endl; \
out << "Spawn Speed Chaos:  " << spawnSpeedChaos << endl; \
out << "Spawn Dir Chaos:  " << spawnDirChaos << endl; \
out << "Life Span:  " << lifeSpan << endl; \
out << "Life Span Variation:  " << lifeSpanVariation << endl; \
return out.str(); \

#define NI_P_SYS_SPAWN_MODIFIER_FIXLINKS \
NiPSysModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_SPAWN_MODIFIER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysModifier::GetRefs(); \
return refs; \

#define NI_P_SYS_SPHERE_EMITTER_MEMBERS \
float radius; \

#define NI_P_SYS_SPHERE_EMITTER_INCLUDE "NiPSysVolumeEmitter.h" \

#define NI_P_SYS_SPHERE_EMITTER_PARENT NiPSysVolumeEmitter \

#define NI_P_SYS_SPHERE_EMITTER_CONSTRUCT \
 : radius(0.0f) \

#define NI_P_SYS_SPHERE_EMITTER_READ \
NiPSysVolumeEmitter::Read( in, link_stack, version, user_version ); \
NifStream( radius, in, version ); \

#define NI_P_SYS_SPHERE_EMITTER_WRITE \
NiPSysVolumeEmitter::Write( out, link_map, version, user_version ); \
NifStream( radius, out, version ); \

#define NI_P_SYS_SPHERE_EMITTER_STRING \
stringstream out; \
out << NiPSysVolumeEmitter::asString(); \
out << "Radius:  " << radius << endl; \
return out.str(); \

#define NI_P_SYS_SPHERE_EMITTER_FIXLINKS \
NiPSysVolumeEmitter::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_SPHERE_EMITTER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPSysVolumeEmitter::GetRefs(); \
return refs; \

#define NI_P_SYS_UPDATE_CTLR_MEMBERS \

#define NI_P_SYS_UPDATE_CTLR_INCLUDE "NiTimeController.h" \

#define NI_P_SYS_UPDATE_CTLR_PARENT NiTimeController \

#define NI_P_SYS_UPDATE_CTLR_CONSTRUCT \

#define NI_P_SYS_UPDATE_CTLR_READ \
NiTimeController::Read( in, link_stack, version, user_version ); \

#define NI_P_SYS_UPDATE_CTLR_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \

#define NI_P_SYS_UPDATE_CTLR_STRING \
stringstream out; \
out << NiTimeController::asString(); \
return out.str(); \

#define NI_P_SYS_UPDATE_CTLR_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \

#define NI_P_SYS_UPDATE_CTLR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
return refs; \

#define NI_RANGE_L_O_D_DATA_MEMBERS \
Vector3 lodCenter; \
uint numLodLevels; \
vector<LODRange > lodLevels; \

#define NI_RANGE_L_O_D_DATA_INCLUDE "NiObject.h" \

#define NI_RANGE_L_O_D_DATA_PARENT NiObject \

#define NI_RANGE_L_O_D_DATA_CONSTRUCT \
 : numLodLevels((uint)0) \

#define NI_RANGE_L_O_D_DATA_READ \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( lodCenter, in, version ); \
NifStream( numLodLevels, in, version ); \
lodLevels.resize(numLodLevels); \
for (uint i0 = 0; i0 < lodLevels.size(); i0++) { \
	NifStream( lodLevels[i0].near, in, version ); \
	NifStream( lodLevels[i0].far, in, version ); \
}; \

#define NI_RANGE_L_O_D_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( lodCenter, out, version ); \
NifStream( numLodLevels, out, version ); \
for (uint i0 = 0; i0 < lodLevels.size(); i0++) { \
	NifStream( lodLevels[i0].near, out, version ); \
	NifStream( lodLevels[i0].far, out, version ); \
}; \

#define NI_RANGE_L_O_D_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "LOD Center:  " << lodCenter << endl; \
out << "Num LOD Levels:  " << numLodLevels << endl; \
for (uint i0 = 0; i0 < lodLevels.size(); i0++) { \
	out << "  Near:  " << lodLevels[i0].near << endl; \
	out << "  Far:  " << lodLevels[i0].far << endl; \
}; \
return out.str(); \

#define NI_RANGE_L_O_D_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_RANGE_L_O_D_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_ROTATING_PARTICLES_MEMBERS \

#define NI_ROTATING_PARTICLES_INCLUDE "NiParticles.h" \

#define NI_ROTATING_PARTICLES_PARENT NiParticles \

#define NI_ROTATING_PARTICLES_CONSTRUCT \

#define NI_ROTATING_PARTICLES_READ \
NiParticles::Read( in, link_stack, version, user_version ); \

#define NI_ROTATING_PARTICLES_WRITE \
NiParticles::Write( out, link_map, version, user_version ); \

#define NI_ROTATING_PARTICLES_STRING \
stringstream out; \
out << NiParticles::asString(); \
return out.str(); \

#define NI_ROTATING_PARTICLES_FIXLINKS \
NiParticles::FixLinks( objects, link_stack, version, user_version ); \

#define NI_ROTATING_PARTICLES_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiParticles::GetRefs(); \
return refs; \

#define NI_ROTATING_PARTICLES_DATA_MEMBERS \

#define NI_ROTATING_PARTICLES_DATA_INCLUDE "NiParticlesData.h" \

#define NI_ROTATING_PARTICLES_DATA_PARENT NiParticlesData \

#define NI_ROTATING_PARTICLES_DATA_CONSTRUCT \

#define NI_ROTATING_PARTICLES_DATA_READ \
NiParticlesData::Read( in, link_stack, version, user_version ); \

#define NI_ROTATING_PARTICLES_DATA_WRITE \
NiParticlesData::Write( out, link_map, version, user_version ); \

#define NI_ROTATING_PARTICLES_DATA_STRING \
stringstream out; \
out << NiParticlesData::asString(); \
return out.str(); \

#define NI_ROTATING_PARTICLES_DATA_FIXLINKS \
NiParticlesData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_ROTATING_PARTICLES_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiParticlesData::GetRefs(); \
return refs; \

#define NI_SCREEN_L_O_D_DATA_MEMBERS \
float unknownFloats[8]; \
uint unknownCount; \
vector<float > unknownFloats2; \

#define NI_SCREEN_L_O_D_DATA_INCLUDE "NiObject.h" \

#define NI_SCREEN_L_O_D_DATA_PARENT NiObject \

#define NI_SCREEN_L_O_D_DATA_CONSTRUCT \
 : unknownCount((uint)0) \

#define NI_SCREEN_L_O_D_DATA_READ \
NiObject::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 8; i0++) { \
	NifStream( unknownFloats[i0], in, version ); \
}; \
NifStream( unknownCount, in, version ); \
unknownFloats2.resize(unknownCount); \
for (uint i0 = 0; i0 < unknownFloats2.size(); i0++) { \
	NifStream( unknownFloats2[i0], in, version ); \
}; \

#define NI_SCREEN_L_O_D_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 8; i0++) { \
	NifStream( unknownFloats[i0], out, version ); \
}; \
NifStream( unknownCount, out, version ); \
for (uint i0 = 0; i0 < unknownFloats2.size(); i0++) { \
	NifStream( unknownFloats2[i0], out, version ); \
}; \

#define NI_SCREEN_L_O_D_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
for (uint i0 = 0; i0 < 8; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats[" << i0 << "]:  " << unknownFloats[i0] << endl; \
}; \
out << "Unknown Count:  " << unknownCount << endl; \
for (uint i0 = 0; i0 < unknownFloats2.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Floats 2[" << i0 << "]:  " << unknownFloats2[i0] << endl; \
}; \
return out.str(); \

#define NI_SCREEN_L_O_D_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_SCREEN_L_O_D_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_SEQUENCE_STREAM_HELPER_MEMBERS \

#define NI_SEQUENCE_STREAM_HELPER_INCLUDE "NiObjectNET.h" \

#define NI_SEQUENCE_STREAM_HELPER_PARENT NiObjectNET \

#define NI_SEQUENCE_STREAM_HELPER_CONSTRUCT \

#define NI_SEQUENCE_STREAM_HELPER_READ \
NiObjectNET::Read( in, link_stack, version, user_version ); \

#define NI_SEQUENCE_STREAM_HELPER_WRITE \
NiObjectNET::Write( out, link_map, version, user_version ); \

#define NI_SEQUENCE_STREAM_HELPER_STRING \
stringstream out; \
out << NiObjectNET::asString(); \
return out.str(); \

#define NI_SEQUENCE_STREAM_HELPER_FIXLINKS \
NiObjectNET::FixLinks( objects, link_stack, version, user_version ); \

#define NI_SEQUENCE_STREAM_HELPER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObjectNET::GetRefs(); \
return refs; \

#define NI_SHADE_PROPERTY_MEMBERS \
ushort flags; \

#define NI_SHADE_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_SHADE_PROPERTY_PARENT NiProperty \

#define NI_SHADE_PROPERTY_CONSTRUCT \
 : flags((ushort)0) \

#define NI_SHADE_PROPERTY_READ \
NiProperty::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \

#define NI_SHADE_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \

#define NI_SHADE_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
return out.str(); \

#define NI_SHADE_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_SHADE_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define NI_SKIN_DATA_MEMBERS \
Matrix33 rotation; \
Vector3 translation; \
float scale; \
uint numBones; \
Ref<NiSkinPartition > skinPartition; \
byte unknownByte; \
vector<SkinData > boneList; \

#define NI_SKIN_DATA_INCLUDE "NiObject.h" \

#define NI_SKIN_DATA_PARENT NiObject \

#define NI_SKIN_DATA_CONSTRUCT \
 : scale(0.0f), numBones((uint)0), skinPartition(NULL), unknownByte((byte)0) \

#define NI_SKIN_DATA_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( rotation, in, version ); \
NifStream( translation, in, version ); \
NifStream( scale, in, version ); \
NifStream( numBones, in, version ); \
if ( version <= 0x0A010000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
if ( version >= 0x04020100 ) { \
	NifStream( unknownByte, in, version ); \
}; \
boneList.resize(numBones); \
for (uint i0 = 0; i0 < boneList.size(); i0++) { \
	NifStream( boneList[i0].rotation, in, version ); \
	NifStream( boneList[i0].translation, in, version ); \
	NifStream( boneList[i0].scale, in, version ); \
	for (uint i1 = 0; i1 < 4; i1++) { \
		NifStream( boneList[i0].unknown4Floats[i1], in, version ); \
	}; \
	NifStream( boneList[i0].numVertices, in, version ); \
	boneList[i0].vertexWeights.resize(boneList[i0].numVertices); \
	for (uint i1 = 0; i1 < boneList[i0].vertexWeights.size(); i1++) { \
		NifStream( boneList[i0].vertexWeights[i1].index, in, version ); \
		NifStream( boneList[i0].vertexWeights[i1].weight, in, version ); \
	}; \
}; \

#define NI_SKIN_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( rotation, out, version ); \
NifStream( translation, out, version ); \
NifStream( scale, out, version ); \
NifStream( numBones, out, version ); \
if ( version <= 0x0A010000 ) { \
	if ( skinPartition != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(skinPartition)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( version >= 0x04020100 ) { \
	NifStream( unknownByte, out, version ); \
}; \
for (uint i0 = 0; i0 < boneList.size(); i0++) { \
	NifStream( boneList[i0].rotation, out, version ); \
	NifStream( boneList[i0].translation, out, version ); \
	NifStream( boneList[i0].scale, out, version ); \
	for (uint i1 = 0; i1 < 4; i1++) { \
		NifStream( boneList[i0].unknown4Floats[i1], out, version ); \
	}; \
	NifStream( boneList[i0].numVertices, out, version ); \
	for (uint i1 = 0; i1 < boneList[i0].vertexWeights.size(); i1++) { \
		NifStream( boneList[i0].vertexWeights[i1].index, out, version ); \
		NifStream( boneList[i0].vertexWeights[i1].weight, out, version ); \
	}; \
}; \

#define NI_SKIN_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Rotation:  " << rotation << endl; \
out << "Translation:  " << translation << endl; \
out << "Scale:  " << scale << endl; \
out << "Num Bones:  " << numBones << endl; \
out << "Skin Partition:  " << skinPartition << endl; \
out << "Unknown Byte:  " << unknownByte << endl; \
for (uint i0 = 0; i0 < boneList.size(); i0++) { \
	out << "  Rotation:  " << boneList[i0].rotation << endl; \
	out << "  Translation:  " << boneList[i0].translation << endl; \
	out << "  Scale:  " << boneList[i0].scale << endl; \
	for (uint i1 = 0; i1 < 4; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Unknown 4 Floats[" << i1 << "]:  " << boneList[i0].unknown4Floats[i1] << endl; \
	}; \
	out << "  Num Vertices:  " << boneList[i0].numVertices << endl; \
	for (uint i1 = 0; i1 < boneList[i0].vertexWeights.size(); i1++) { \
		out << "    Index:  " << boneList[i0].vertexWeights[i1].index << endl; \
		out << "    Weight:  " << boneList[i0].vertexWeights[i1].weight << endl; \
	}; \
}; \
return out.str(); \

#define NI_SKIN_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		skinPartition = DynamicCast<NiSkinPartition>(objects[link_stack.front()]); \
		if ( skinPartition == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		skinPartition = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_SKIN_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( skinPartition != NULL ) \
	refs.push_back(StaticCast<NiObject>(skinPartition)); \
return refs; \

#define NI_SKIN_INSTANCE_MEMBERS \
Ref<NiSkinData > data; \
Ref<NiSkinPartition > skinPartition; \
NiNode * skeletonRoot; \
uint numBones; \
vector<NiNode * > bones; \

#define NI_SKIN_INSTANCE_INCLUDE "NiObject.h" \

#define NI_SKIN_INSTANCE_PARENT NiObject \

#define NI_SKIN_INSTANCE_CONSTRUCT \
 : data(NULL), skinPartition(NULL), skeletonRoot(NULL), numBones((uint)0) \

#define NI_SKIN_INSTANCE_READ \
uint block_num; \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
if ( version >= 0x0A020000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( numBones, in, version ); \
bones.resize(numBones); \
for (uint i0 = 0; i0 < bones.size(); i0++) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_SKIN_INSTANCE_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
if ( version >= 0x0A020000 ) { \
	if ( skinPartition != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(skinPartition)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
if ( skeletonRoot != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(skeletonRoot)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( numBones, out, version ); \
for (uint i0 = 0; i0 < bones.size(); i0++) { \
	if ( bones[i0] != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(bones[i0])], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_SKIN_INSTANCE_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Data:  " << data << endl; \
out << "Skin Partition:  " << skinPartition << endl; \
out << "Skeleton Root:  " << skeletonRoot << endl; \
out << "Num Bones:  " << numBones << endl; \
for (uint i0 = 0; i0 < bones.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Bones[" << i0 << "]:  " << bones[i0] << endl; \
}; \
return out.str(); \

#define NI_SKIN_INSTANCE_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiSkinData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \
if ( version >= 0x0A020000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		skinPartition = DynamicCast<NiSkinPartition>(objects[link_stack.front()]); \
		if ( skinPartition == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		skinPartition = NULL; \
	link_stack.pop_front(); \
}; \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	skeletonRoot = DynamicCast<NiNode>(objects[link_stack.front()]); \
	if ( skeletonRoot == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	skeletonRoot = NULL; \
link_stack.pop_front(); \
for (uint i0 = 0; i0 < bones.size(); i0++) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		bones[i0] = DynamicCast<NiNode>(objects[link_stack.front()]); \
		if ( bones[i0] == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		bones[i0] = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_SKIN_INSTANCE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
if ( skinPartition != NULL ) \
	refs.push_back(StaticCast<NiObject>(skinPartition)); \
for (uint i0 = 0; i0 < bones.size(); i0++) { \
}; \
return refs; \

#define NI_SKIN_PARTITION_MEMBERS \
uint numSkinPartitionBlocks; \
vector<SkinPartition > skinPartitionBlocks; \

#define NI_SKIN_PARTITION_INCLUDE "NiObject.h" \

#define NI_SKIN_PARTITION_PARENT NiObject \

#define NI_SKIN_PARTITION_CONSTRUCT \
 : numSkinPartitionBlocks((uint)0) \

#define NI_SKIN_PARTITION_READ \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( numSkinPartitionBlocks, in, version ); \
skinPartitionBlocks.resize(numSkinPartitionBlocks); \
for (uint i0 = 0; i0 < skinPartitionBlocks.size(); i0++) { \
	NifStream( skinPartitionBlocks[i0].numVertices, in, version ); \
	NifStream( skinPartitionBlocks[i0].numTriangles, in, version ); \
	NifStream( skinPartitionBlocks[i0].numBones, in, version ); \
	NifStream( skinPartitionBlocks[i0].numStrips, in, version ); \
	NifStream( skinPartitionBlocks[i0].numWeightsPerVertex, in, version ); \
	skinPartitionBlocks[i0].bones.resize(skinPartitionBlocks[i0].numBones); \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].bones.size(); i1++) { \
		NifStream( skinPartitionBlocks[i0].bones[i1], in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( skinPartitionBlocks[i0].hasVertexMap, in, version ); \
	}; \
	if ( version <= 0x0A000102 ) { \
		skinPartitionBlocks[i0].vertexMap.resize(skinPartitionBlocks[i0].numVertices); \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].vertexMap.size(); i2++) { \
			NifStream( skinPartitionBlocks[i0].vertexMap[i2], in, version ); \
		}; \
	}; \
	if ( version >= 0x0A010000 ) { \
		if ( (skinPartitionBlocks[i0].hasVertexMap != 0) ) { \
			skinPartitionBlocks[i0].vertexMap.resize(skinPartitionBlocks[i0].numVertices); \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].vertexMap.size(); i3++) { \
				NifStream( skinPartitionBlocks[i0].vertexMap[i3], in, version ); \
			}; \
		}; \
		NifStream( skinPartitionBlocks[i0].hasVertexWeights, in, version ); \
	}; \
	if ( version <= 0x0A000102 ) { \
		skinPartitionBlocks[i0].vertexWeights.resize(skinPartitionBlocks[i0].numVertices); \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].vertexWeights.size(); i2++) { \
			skinPartitionBlocks[i0].vertexWeights[i2].resize(skinPartitionBlocks[i0].numWeightsPerVertex); \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].vertexWeights[i2].size(); i3++) { \
				NifStream( skinPartitionBlocks[i0].vertexWeights[i2][i3], in, version ); \
			}; \
		}; \
	}; \
	if ( version >= 0x0A010000 ) { \
		if ( (skinPartitionBlocks[i0].hasVertexWeights != 0) ) { \
			skinPartitionBlocks[i0].vertexWeights.resize(skinPartitionBlocks[i0].numVertices); \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].vertexWeights.size(); i3++) { \
				skinPartitionBlocks[i0].vertexWeights[i3].resize(skinPartitionBlocks[i0].numWeightsPerVertex); \
				for (uint i4 = 0; i4 < skinPartitionBlocks[i0].vertexWeights[i3].size(); i4++) { \
					NifStream( skinPartitionBlocks[i0].vertexWeights[i3][i4], in, version ); \
				}; \
			}; \
		}; \
	}; \
	skinPartitionBlocks[i0].stripLengths.resize(skinPartitionBlocks[i0].numStrips); \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].stripLengths.size(); i1++) { \
		NifStream( skinPartitionBlocks[i0].stripLengths[i1], in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( skinPartitionBlocks[i0].hasStrips, in, version ); \
	}; \
	if ( version <= 0x0A000102 ) { \
		skinPartitionBlocks[i0].strips.resize(skinPartitionBlocks[i0].numStrips); \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].strips.size(); i2++) { \
			skinPartitionBlocks[i0].strips[i2].resize(skinPartitionBlocks[i0].stripLengths[i2]); \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].stripLengths[i2]; i3++) { \
				NifStream( skinPartitionBlocks[i0].strips[i2][i3], in, version ); \
			}; \
		}; \
	}; \
	if ( version >= 0x0A010000 ) { \
		if ( (skinPartitionBlocks[i0].hasStrips != 0) ) { \
			skinPartitionBlocks[i0].strips.resize(skinPartitionBlocks[i0].numStrips); \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].strips.size(); i3++) { \
				skinPartitionBlocks[i0].strips[i3].resize(skinPartitionBlocks[i0].stripLengths[i3]); \
				for (uint i4 = 0; i4 < skinPartitionBlocks[i0].stripLengths[i3]; i4++) { \
					NifStream( skinPartitionBlocks[i0].strips[i3][i4], in, version ); \
				}; \
			}; \
		}; \
	}; \
	if ( (skinPartitionBlocks[i0].numStrips == 0) ) { \
		skinPartitionBlocks[i0].triangles.resize(skinPartitionBlocks[i0].numTriangles); \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].triangles.size(); i2++) { \
			NifStream( skinPartitionBlocks[i0].triangles[i2], in, version ); \
		}; \
	}; \
	NifStream( skinPartitionBlocks[i0].hasBoneIndices, in, version ); \
	if ( (skinPartitionBlocks[i0].hasBoneIndices != 0) ) { \
		skinPartitionBlocks[i0].boneIndices.resize(skinPartitionBlocks[i0].numVertices); \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].boneIndices.size(); i2++) { \
			skinPartitionBlocks[i0].boneIndices[i2].resize(skinPartitionBlocks[i0].numWeightsPerVertex); \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].boneIndices[i2].size(); i3++) { \
				NifStream( skinPartitionBlocks[i0].boneIndices[i2][i3], in, version ); \
			}; \
		}; \
	}; \
}; \

#define NI_SKIN_PARTITION_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( numSkinPartitionBlocks, out, version ); \
for (uint i0 = 0; i0 < skinPartitionBlocks.size(); i0++) { \
	NifStream( skinPartitionBlocks[i0].numVertices, out, version ); \
	NifStream( skinPartitionBlocks[i0].numTriangles, out, version ); \
	NifStream( skinPartitionBlocks[i0].numBones, out, version ); \
	NifStream( skinPartitionBlocks[i0].numStrips, out, version ); \
	NifStream( skinPartitionBlocks[i0].numWeightsPerVertex, out, version ); \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].bones.size(); i1++) { \
		NifStream( skinPartitionBlocks[i0].bones[i1], out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( skinPartitionBlocks[i0].hasVertexMap, out, version ); \
	}; \
	if ( version <= 0x0A000102 ) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].vertexMap.size(); i2++) { \
			NifStream( skinPartitionBlocks[i0].vertexMap[i2], out, version ); \
		}; \
	}; \
	if ( version >= 0x0A010000 ) { \
		if ( (skinPartitionBlocks[i0].hasVertexMap != 0) ) { \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].vertexMap.size(); i3++) { \
				NifStream( skinPartitionBlocks[i0].vertexMap[i3], out, version ); \
			}; \
		}; \
		NifStream( skinPartitionBlocks[i0].hasVertexWeights, out, version ); \
	}; \
	if ( version <= 0x0A000102 ) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].vertexWeights.size(); i2++) { \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].vertexWeights[i2].size(); i3++) { \
				NifStream( skinPartitionBlocks[i0].vertexWeights[i2][i3], out, version ); \
			}; \
		}; \
	}; \
	if ( version >= 0x0A010000 ) { \
		if ( (skinPartitionBlocks[i0].hasVertexWeights != 0) ) { \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].vertexWeights.size(); i3++) { \
				for (uint i4 = 0; i4 < skinPartitionBlocks[i0].vertexWeights[i3].size(); i4++) { \
					NifStream( skinPartitionBlocks[i0].vertexWeights[i3][i4], out, version ); \
				}; \
			}; \
		}; \
	}; \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].stripLengths.size(); i1++) { \
		NifStream( skinPartitionBlocks[i0].stripLengths[i1], out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( skinPartitionBlocks[i0].hasStrips, out, version ); \
	}; \
	if ( version <= 0x0A000102 ) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].strips.size(); i2++) { \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].stripLengths[i2]; i3++) { \
				NifStream( skinPartitionBlocks[i0].strips[i2][i3], out, version ); \
			}; \
		}; \
	}; \
	if ( version >= 0x0A010000 ) { \
		if ( (skinPartitionBlocks[i0].hasStrips != 0) ) { \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].strips.size(); i3++) { \
				for (uint i4 = 0; i4 < skinPartitionBlocks[i0].stripLengths[i3]; i4++) { \
					NifStream( skinPartitionBlocks[i0].strips[i3][i4], out, version ); \
				}; \
			}; \
		}; \
	}; \
	if ( (skinPartitionBlocks[i0].numStrips == 0) ) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].triangles.size(); i2++) { \
			NifStream( skinPartitionBlocks[i0].triangles[i2], out, version ); \
		}; \
	}; \
	NifStream( skinPartitionBlocks[i0].hasBoneIndices, out, version ); \
	if ( (skinPartitionBlocks[i0].hasBoneIndices != 0) ) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].boneIndices.size(); i2++) { \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].boneIndices[i2].size(); i3++) { \
				NifStream( skinPartitionBlocks[i0].boneIndices[i2][i3], out, version ); \
			}; \
		}; \
	}; \
}; \

#define NI_SKIN_PARTITION_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Num Skin Partition Blocks:  " << numSkinPartitionBlocks << endl; \
for (uint i0 = 0; i0 < skinPartitionBlocks.size(); i0++) { \
	out << "  Num Vertices:  " << skinPartitionBlocks[i0].numVertices << endl; \
	out << "  Num Triangles:  " << skinPartitionBlocks[i0].numTriangles << endl; \
	out << "  Num Bones:  " << skinPartitionBlocks[i0].numBones << endl; \
	out << "  Num Strips:  " << skinPartitionBlocks[i0].numStrips << endl; \
	out << "  Num Weights Per Vertex:  " << skinPartitionBlocks[i0].numWeightsPerVertex << endl; \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].bones.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Bones[" << i1 << "]:  " << skinPartitionBlocks[i0].bones[i1] << endl; \
	}; \
	out << "  Has Vertex Map:  " << skinPartitionBlocks[i0].hasVertexMap << endl; \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].vertexMap.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Vertex Map[" << i1 << "]:  " << skinPartitionBlocks[i0].vertexMap[i1] << endl; \
	}; \
	out << "  Has Vertex Weights:  " << skinPartitionBlocks[i0].hasVertexWeights << endl; \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].vertexWeights.size(); i1++) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].vertexWeights[i1].size(); i2++) { \
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) { \
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
				break; \
			}; \
			out << "      Vertex Weights[" << i1 << "][" << i2 << "]:  " << skinPartitionBlocks[i0].vertexWeights[i1][i2] << endl; \
		}; \
	}; \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].stripLengths.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Strip Lengths[" << i1 << "]:  " << skinPartitionBlocks[i0].stripLengths[i1] << endl; \
	}; \
	out << "  Has Strips:  " << skinPartitionBlocks[i0].hasStrips << endl; \
	for (uint i1 = 0; i1 < skinPartitionBlocks[i0].strips.size(); i1++) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].stripLengths[i1]; i2++) { \
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) { \
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
				break; \
			}; \
			out << "      Strips[" << i1 << "][" << i2 << "]:  " << skinPartitionBlocks[i0].strips[i1][i2] << endl; \
		}; \
	}; \
	if ( (skinPartitionBlocks[i0].numStrips == 0) ) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].triangles.size(); i2++) { \
			if ( !verbose && ( i2 > MAXARRAYDUMP ) ) { \
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
				break; \
			}; \
			out << "      Triangles[" << i2 << "]:  " << skinPartitionBlocks[i0].triangles[i2] << endl; \
		}; \
	}; \
	out << "  Has Bone Indices:  " << skinPartitionBlocks[i0].hasBoneIndices << endl; \
	if ( (skinPartitionBlocks[i0].hasBoneIndices != 0) ) { \
		for (uint i2 = 0; i2 < skinPartitionBlocks[i0].boneIndices.size(); i2++) { \
			for (uint i3 = 0; i3 < skinPartitionBlocks[i0].boneIndices[i2].size(); i3++) { \
				if ( !verbose && ( i3 > MAXARRAYDUMP ) ) { \
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
					break; \
				}; \
				out << "        Bone Indices[" << i2 << "][" << i3 << "]:  " << skinPartitionBlocks[i0].boneIndices[i2][i3] << endl; \
			}; \
		}; \
	}; \
}; \
return out.str(); \

#define NI_SKIN_PARTITION_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_SKIN_PARTITION_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

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
uint block_num; \
NiObjectNET::Read( in, link_stack, version, user_version ); \
NifStream( useExternal, in, version ); \
if ( (useExternal == 1) ) { \
	NifStream( fileName, in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (useExternal == 1) ) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
	}; \
}; \
if ( version <= 0x0A000100 ) { \
	if ( (useExternal == 0) ) { \
		NifStream( unknownByte, in, version ); \
	}; \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (useExternal == 0) ) { \
		NifStream( originalFileName_, in, version ); \
	}; \
}; \
if ( (useExternal == 0) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \
NifStream( pixelLayout, in, version ); \
NifStream( useMipmaps, in, version ); \
NifStream( alphaFormat, in, version ); \
NifStream( unknownByte, in, version ); \
if ( version >= 0x0A01006A ) { \
	NifStream( unknownByte2, in, version ); \
}; \

#define NI_SOURCE_TEXTURE_WRITE \
NiObjectNET::Write( out, link_map, version, user_version ); \
NifStream( useExternal, out, version ); \
if ( (useExternal == 1) ) { \
	NifStream( fileName, out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (useExternal == 1) ) { \
		if ( unknownLink != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(unknownLink)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
	}; \
}; \
if ( version <= 0x0A000100 ) { \
	if ( (useExternal == 0) ) { \
		NifStream( unknownByte, out, version ); \
	}; \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (useExternal == 0) ) { \
		NifStream( originalFileName_, out, version ); \
	}; \
}; \
if ( (useExternal == 0) ) { \
	if ( pixelData != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(pixelData)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \
NifStream( pixelLayout, out, version ); \
NifStream( useMipmaps, out, version ); \
NifStream( alphaFormat, out, version ); \
NifStream( unknownByte, out, version ); \
if ( version >= 0x0A01006A ) { \
	NifStream( unknownByte2, out, version ); \
}; \

#define NI_SOURCE_TEXTURE_STRING \
stringstream out; \
out << NiObjectNET::asString(); \
out << "Use External:  " << useExternal << endl; \
if ( (useExternal == 1) ) { \
	out << "  File Name:  " << fileName << endl; \
	out << "  Unknown Link:  " << unknownLink << endl; \
}; \
if ( (useExternal == 0) ) { \
	out << "  Unknown Byte:  " << unknownByte << endl; \
	out << "  Original File Name?:  " << originalFileName_ << endl; \
	out << "  Pixel Data:  " << pixelData << endl; \
}; \
out << "Pixel Layout:  " << pixelLayout << endl; \
out << "Use Mipmaps:  " << useMipmaps << endl; \
out << "Alpha Format:  " << alphaFormat << endl; \
out << "Unknown Byte 2:  " << unknownByte2 << endl; \
return out.str(); \

#define NI_SOURCE_TEXTURE_FIXLINKS \
NiObjectNET::FixLinks( objects, link_stack, version, user_version ); \
if ( version >= 0x0A010000 ) { \
	if ( (useExternal == 1) ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			unknownLink = DynamicCast<NiObject>(objects[link_stack.front()]); \
			if ( unknownLink == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			unknownLink = NULL; \
		link_stack.pop_front(); \
	}; \
}; \
if ( (useExternal == 0) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		pixelData = DynamicCast<NiPixelData>(objects[link_stack.front()]); \
		if ( pixelData == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		pixelData = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_SOURCE_TEXTURE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObjectNET::GetRefs(); \
if ( unknownLink != NULL ) \
	refs.push_back(StaticCast<NiObject>(unknownLink)); \
if ( pixelData != NULL ) \
	refs.push_back(StaticCast<NiObject>(pixelData)); \
return refs; \

#define NI_SPECULAR_PROPERTY_MEMBERS \
ushort flags; \

#define NI_SPECULAR_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_SPECULAR_PROPERTY_PARENT NiProperty \

#define NI_SPECULAR_PROPERTY_CONSTRUCT \
 : flags((ushort)0) \

#define NI_SPECULAR_PROPERTY_READ \
NiProperty::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \

#define NI_SPECULAR_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \

#define NI_SPECULAR_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
return out.str(); \

#define NI_SPECULAR_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_SPECULAR_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

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
AParticleModifier::Read( in, link_stack, version, user_version ); \
NifStream( unknownFloat1, in, version ); \
NifStream( unknownShort, in, version ); \
NifStream( unknownFloat2, in, version ); \
NifStream( unknownFloat3, in, version ); \
NifStream( unknownFloat4, in, version ); \
NifStream( unknownFloat5, in, version ); \

#define NI_SPHERICAL_COLLIDER_WRITE \
AParticleModifier::Write( out, link_map, version, user_version ); \
NifStream( unknownFloat1, out, version ); \
NifStream( unknownShort, out, version ); \
NifStream( unknownFloat2, out, version ); \
NifStream( unknownFloat3, out, version ); \
NifStream( unknownFloat4, out, version ); \
NifStream( unknownFloat5, out, version ); \

#define NI_SPHERICAL_COLLIDER_STRING \
stringstream out; \
out << AParticleModifier::asString(); \
out << "Unknown Float 1:  " << unknownFloat1 << endl; \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Unknown Float 2:  " << unknownFloat2 << endl; \
out << "Unknown Float 3:  " << unknownFloat3 << endl; \
out << "Unknown Float 4:  " << unknownFloat4 << endl; \
out << "Unknown Float 5:  " << unknownFloat5 << endl; \
return out.str(); \

#define NI_SPHERICAL_COLLIDER_FIXLINKS \
AParticleModifier::FixLinks( objects, link_stack, version, user_version ); \

#define NI_SPHERICAL_COLLIDER_GETREFS \
list<Ref<NiObject> > refs; \
refs = AParticleModifier::GetRefs(); \
return refs; \

#define NI_SPOT_LIGHT_MEMBERS \
float cutoffAngle; \
float exponent; \

#define NI_SPOT_LIGHT_INCLUDE "NiPointLight.h" \

#define NI_SPOT_LIGHT_PARENT NiPointLight \

#define NI_SPOT_LIGHT_CONSTRUCT \
 : cutoffAngle(0.0f), exponent(0.0f) \

#define NI_SPOT_LIGHT_READ \
NiPointLight::Read( in, link_stack, version, user_version ); \
NifStream( cutoffAngle, in, version ); \
NifStream( exponent, in, version ); \

#define NI_SPOT_LIGHT_WRITE \
NiPointLight::Write( out, link_map, version, user_version ); \
NifStream( cutoffAngle, out, version ); \
NifStream( exponent, out, version ); \

#define NI_SPOT_LIGHT_STRING \
stringstream out; \
out << NiPointLight::asString(); \
out << "Cutoff Angle:  " << cutoffAngle << endl; \
out << "Exponent:  " << exponent << endl; \
return out.str(); \

#define NI_SPOT_LIGHT_FIXLINKS \
NiPointLight::FixLinks( objects, link_stack, version, user_version ); \

#define NI_SPOT_LIGHT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiPointLight::GetRefs(); \
return refs; \

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
NiProperty::Read( in, link_stack, version, user_version ); \
if ( version <= 0x0A000102 ) { \
	NifStream( flags, in, version ); \
}; \
NifStream( stencilEnabled, in, version ); \
NifStream( stencilFunction, in, version ); \
NifStream( stencilRef, in, version ); \
NifStream( stencilMask, in, version ); \
NifStream( failAction, in, version ); \
NifStream( zFailAction, in, version ); \
NifStream( passAction, in, version ); \
NifStream( drawMode, in, version ); \

#define NI_STENCIL_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
if ( version <= 0x0A000102 ) { \
	NifStream( flags, out, version ); \
}; \
NifStream( stencilEnabled, out, version ); \
NifStream( stencilFunction, out, version ); \
NifStream( stencilRef, out, version ); \
NifStream( stencilMask, out, version ); \
NifStream( failAction, out, version ); \
NifStream( zFailAction, out, version ); \
NifStream( passAction, out, version ); \
NifStream( drawMode, out, version ); \

#define NI_STENCIL_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
out << "Stencil Enabled:  " << stencilEnabled << endl; \
out << "Stencil Function:  " << stencilFunction << endl; \
out << "Stencil Ref:  " << stencilRef << endl; \
out << "Stencil Mask:  " << stencilMask << endl; \
out << "Fail Action:  " << failAction << endl; \
out << "Z Fail Action:  " << zFailAction << endl; \
out << "Pass Action:  " << passAction << endl; \
out << "Draw Mode:  " << drawMode << endl; \
return out.str(); \

#define NI_STENCIL_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_STENCIL_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define NI_STRING_EXTRA_DATA_MEMBERS \
uint bytesRemaining; \
string stringData; \

#define NI_STRING_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_STRING_EXTRA_DATA_PARENT NiExtraData \

#define NI_STRING_EXTRA_DATA_CONSTRUCT \
 : bytesRemaining((uint)0) \

#define NI_STRING_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
if ( version <= 0x04020200 ) { \
	NifStream( bytesRemaining, in, version ); \
}; \
NifStream( stringData, in, version ); \

#define NI_STRING_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
if ( version <= 0x04020200 ) { \
	NifStream( bytesRemaining, out, version ); \
}; \
NifStream( stringData, out, version ); \

#define NI_STRING_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Bytes Remaining:  " << bytesRemaining << endl; \
out << "String Data:  " << stringData << endl; \
return out.str(); \

#define NI_STRING_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_STRING_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_STRING_PALETTE_MEMBERS \
StringPalette palette; \

#define NI_STRING_PALETTE_INCLUDE "NiObject.h" \

#define NI_STRING_PALETTE_PARENT NiObject \

#define NI_STRING_PALETTE_CONSTRUCT \

#define NI_STRING_PALETTE_READ \
NiObject::Read( in, link_stack, version, user_version ); \
NifStream( palette.palette, in, version ); \
NifStream( palette.length, in, version ); \

#define NI_STRING_PALETTE_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
NifStream( palette.palette, out, version ); \
NifStream( palette.length, out, version ); \

#define NI_STRING_PALETTE_STRING \
stringstream out; \
out << NiObject::asString(); \
out << "Palette:  " << palette.palette << endl; \
out << "Length:  " << palette.length << endl; \
return out.str(); \

#define NI_STRING_PALETTE_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_STRING_PALETTE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_STRINGS_EXTRA_DATA_MEMBERS \
uint numStrings; \
vector<string > data; \

#define NI_STRINGS_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_STRINGS_EXTRA_DATA_PARENT NiExtraData \

#define NI_STRINGS_EXTRA_DATA_CONSTRUCT \
 : numStrings((uint)0) \

#define NI_STRINGS_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( numStrings, in, version ); \
data.resize(numStrings); \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	NifStream( data[i0], in, version ); \
}; \

#define NI_STRINGS_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( numStrings, out, version ); \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	NifStream( data[i0], out, version ); \
}; \

#define NI_STRINGS_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Num Strings:  " << numStrings << endl; \
for (uint i0 = 0; i0 < data.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Data[" << i0 << "]:  " << data[i0] << endl; \
}; \
return out.str(); \

#define NI_STRINGS_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_STRINGS_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_TEXT_KEY_EXTRA_DATA_MEMBERS \
uint unknownInt1; \
uint numTextKeys; \
vector<Key<string > > textKeys; \

#define NI_TEXT_KEY_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_TEXT_KEY_EXTRA_DATA_PARENT NiExtraData \

#define NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT \
 : unknownInt1((uint)0), numTextKeys((uint)0) \

#define NI_TEXT_KEY_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
if ( version <= 0x04020200 ) { \
	NifStream( unknownInt1, in, version ); \
}; \
NifStream( numTextKeys, in, version ); \
textKeys.resize(numTextKeys); \
for (uint i0 = 0; i0 < textKeys.size(); i0++) { \
	NifStream( textKeys[i0], in, version, 1 ); \
}; \

#define NI_TEXT_KEY_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
if ( version <= 0x04020200 ) { \
	NifStream( unknownInt1, out, version ); \
}; \
NifStream( numTextKeys, out, version ); \
for (uint i0 = 0; i0 < textKeys.size(); i0++) { \
	NifStream( textKeys[i0], out, version, 1 ); \
}; \

#define NI_TEXT_KEY_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Unknown Int 1:  " << unknownInt1 << endl; \
out << "Num Text Keys:  " << numTextKeys << endl; \
for (uint i0 = 0; i0 < textKeys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Text Keys[" << i0 << "]:  " << textKeys[i0] << endl; \
}; \
return out.str(); \

#define NI_TEXT_KEY_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_TEXT_KEY_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

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
uint block_num; \
NiDynamicEffect::Read( in, link_stack, version, user_version ); \
NifStream( modelProjectionMatrix, in, version ); \
NifStream( modelProjectionTransform, in, version ); \
NifStream( textureFiltering, in, version ); \
NifStream( textureClamping, in, version ); \
NifStream( textureType, in, version ); \
NifStream( coordinateGenerationType, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \
NifStream( clippingPlane, in, version ); \
NifStream( unknownVector, in, version ); \
NifStream( unknownFloat, in, version ); \
if ( version <= 0x0A020000 ) { \
	NifStream( ps2L, in, version ); \
	NifStream( ps2K, in, version ); \
}; \
if ( version <= 0x0401000C ) { \
	NifStream( unknownShort, in, version ); \
}; \

#define NI_TEXTURE_EFFECT_WRITE \
NiDynamicEffect::Write( out, link_map, version, user_version ); \
NifStream( modelProjectionMatrix, out, version ); \
NifStream( modelProjectionTransform, out, version ); \
NifStream( textureFiltering, out, version ); \
NifStream( textureClamping, out, version ); \
NifStream( textureType, out, version ); \
NifStream( coordinateGenerationType, out, version ); \
if ( sourceTexture != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(sourceTexture)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \
NifStream( clippingPlane, out, version ); \
NifStream( unknownVector, out, version ); \
NifStream( unknownFloat, out, version ); \
if ( version <= 0x0A020000 ) { \
	NifStream( ps2L, out, version ); \
	NifStream( ps2K, out, version ); \
}; \
if ( version <= 0x0401000C ) { \
	NifStream( unknownShort, out, version ); \
}; \

#define NI_TEXTURE_EFFECT_STRING \
stringstream out; \
out << NiDynamicEffect::asString(); \
out << "Model Projection Matrix:  " << modelProjectionMatrix << endl; \
out << "Model Projection Transform:  " << modelProjectionTransform << endl; \
out << "Texture Filtering:  " << textureFiltering << endl; \
out << "Texture Clamping:  " << textureClamping << endl; \
out << "Texture Type:  " << textureType << endl; \
out << "Coordinate Generation Type:  " << coordinateGenerationType << endl; \
out << "Source Texture:  " << sourceTexture << endl; \
out << "Clipping Plane:  " << clippingPlane << endl; \
out << "Unknown Vector:  " << unknownVector << endl; \
out << "Unknown Float:  " << unknownFloat << endl; \
out << "PS2 L:  " << ps2L << endl; \
out << "PS2 K:  " << ps2K << endl; \
out << "Unknown Short:  " << unknownShort << endl; \
return out.str(); \

#define NI_TEXTURE_EFFECT_FIXLINKS \
NiDynamicEffect::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	sourceTexture = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
	if ( sourceTexture == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	sourceTexture = NULL; \
link_stack.pop_front(); \

#define NI_TEXTURE_EFFECT_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiDynamicEffect::GetRefs(); \
if ( sourceTexture != NULL ) \
	refs.push_back(StaticCast<NiObject>(sourceTexture)); \
return refs; \

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
uint block_num; \
NiSingleInterpolatorController::Read( in, link_stack, version, user_version ); \
NifStream( unknown2, in, version ); \
NifStream( textureSlot, in, version ); \
NifStream( operation, in, version ); \
if ( version <= 0x0A010000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_WRITE \
NiSingleInterpolatorController::Write( out, link_map, version, user_version ); \
NifStream( unknown2, out, version ); \
NifStream( textureSlot, out, version ); \
NifStream( operation, out, version ); \
if ( version <= 0x0A010000 ) { \
	if ( data != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_STRING \
stringstream out; \
out << NiSingleInterpolatorController::asString(); \
out << "Unknown2:  " << unknown2 << endl; \
out << "Texture Slot:  " << textureSlot << endl; \
out << "Operation:  " << operation << endl; \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_FIXLINKS \
NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		data = DynamicCast<NiFloatData>(objects[link_stack.front()]); \
		if ( data == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		data = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiSingleInterpolatorController::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

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
uint numShaderTextures; \
vector<ShaderTexDesc > shaderTextures; \

#define NI_TEXTURING_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_TEXTURING_PROPERTY_PARENT NiProperty \

#define NI_TEXTURING_PROPERTY_CONSTRUCT \
 : flags((ushort)0), applyMode((ApplyMode)2), textureCount((uint)7), hasBaseTexture(false), hasDarkTexture(false), hasDetailTexture(false), hasGlossTexture(false), hasGlowTexture(false), hasBumpMapTexture(false), bumpMapLumaScale(0.0f), bumpMapLumaOffset(0.0f), hasDecal0Texture(false), hasDecal1Texture(false), numShaderTextures((uint)0) \

#define NI_TEXTURING_PROPERTY_READ \
uint block_num; \
NiProperty::Read( in, link_stack, version, user_version ); \
if ( version <= 0x0A000102 ) { \
	NifStream( flags, in, version ); \
}; \
NifStream( applyMode, in, version ); \
NifStream( textureCount, in, version ); \
NifStream( hasBaseTexture, in, version ); \
if ( (hasBaseTexture != 0) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( baseTexture.clampMode, in, version ); \
	NifStream( baseTexture.filterMode, in, version ); \
	NifStream( baseTexture.textureSet, in, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( baseTexture.ps2L, in, version ); \
		NifStream( baseTexture.ps2K, in, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( baseTexture.unknown1, in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( baseTexture.hasTextureTransform, in, version ); \
		if ( (baseTexture.hasTextureTransform != 0) ) { \
			NifStream( baseTexture.translation, in, version ); \
			NifStream( baseTexture.tiling, in, version ); \
			NifStream( baseTexture.wRotation, in, version ); \
			NifStream( baseTexture.transformType_, in, version ); \
			NifStream( baseTexture.centerOffset, in, version ); \
		}; \
	}; \
}; \
NifStream( hasDarkTexture, in, version ); \
if ( (hasDarkTexture != 0) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( darkTexture.clampMode, in, version ); \
	NifStream( darkTexture.filterMode, in, version ); \
	NifStream( darkTexture.textureSet, in, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( darkTexture.ps2L, in, version ); \
		NifStream( darkTexture.ps2K, in, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( darkTexture.unknown1, in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( darkTexture.hasTextureTransform, in, version ); \
		if ( (darkTexture.hasTextureTransform != 0) ) { \
			NifStream( darkTexture.translation, in, version ); \
			NifStream( darkTexture.tiling, in, version ); \
			NifStream( darkTexture.wRotation, in, version ); \
			NifStream( darkTexture.transformType_, in, version ); \
			NifStream( darkTexture.centerOffset, in, version ); \
		}; \
	}; \
}; \
NifStream( hasDetailTexture, in, version ); \
if ( (hasDetailTexture != 0) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( detailTexture.clampMode, in, version ); \
	NifStream( detailTexture.filterMode, in, version ); \
	NifStream( detailTexture.textureSet, in, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( detailTexture.ps2L, in, version ); \
		NifStream( detailTexture.ps2K, in, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( detailTexture.unknown1, in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( detailTexture.hasTextureTransform, in, version ); \
		if ( (detailTexture.hasTextureTransform != 0) ) { \
			NifStream( detailTexture.translation, in, version ); \
			NifStream( detailTexture.tiling, in, version ); \
			NifStream( detailTexture.wRotation, in, version ); \
			NifStream( detailTexture.transformType_, in, version ); \
			NifStream( detailTexture.centerOffset, in, version ); \
		}; \
	}; \
}; \
NifStream( hasGlossTexture, in, version ); \
if ( (hasGlossTexture != 0) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( glossTexture.clampMode, in, version ); \
	NifStream( glossTexture.filterMode, in, version ); \
	NifStream( glossTexture.textureSet, in, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( glossTexture.ps2L, in, version ); \
		NifStream( glossTexture.ps2K, in, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( glossTexture.unknown1, in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( glossTexture.hasTextureTransform, in, version ); \
		if ( (glossTexture.hasTextureTransform != 0) ) { \
			NifStream( glossTexture.translation, in, version ); \
			NifStream( glossTexture.tiling, in, version ); \
			NifStream( glossTexture.wRotation, in, version ); \
			NifStream( glossTexture.transformType_, in, version ); \
			NifStream( glossTexture.centerOffset, in, version ); \
		}; \
	}; \
}; \
NifStream( hasGlowTexture, in, version ); \
if ( (hasGlowTexture != 0) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( glowTexture.clampMode, in, version ); \
	NifStream( glowTexture.filterMode, in, version ); \
	NifStream( glowTexture.textureSet, in, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( glowTexture.ps2L, in, version ); \
		NifStream( glowTexture.ps2K, in, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( glowTexture.unknown1, in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( glowTexture.hasTextureTransform, in, version ); \
		if ( (glowTexture.hasTextureTransform != 0) ) { \
			NifStream( glowTexture.translation, in, version ); \
			NifStream( glowTexture.tiling, in, version ); \
			NifStream( glowTexture.wRotation, in, version ); \
			NifStream( glowTexture.transformType_, in, version ); \
			NifStream( glowTexture.centerOffset, in, version ); \
		}; \
	}; \
}; \
NifStream( hasBumpMapTexture, in, version ); \
if ( (hasBumpMapTexture != 0) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( bumpMapTexture.clampMode, in, version ); \
	NifStream( bumpMapTexture.filterMode, in, version ); \
	NifStream( bumpMapTexture.textureSet, in, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( bumpMapTexture.ps2L, in, version ); \
		NifStream( bumpMapTexture.ps2K, in, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( bumpMapTexture.unknown1, in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( bumpMapTexture.hasTextureTransform, in, version ); \
		if ( (bumpMapTexture.hasTextureTransform != 0) ) { \
			NifStream( bumpMapTexture.translation, in, version ); \
			NifStream( bumpMapTexture.tiling, in, version ); \
			NifStream( bumpMapTexture.wRotation, in, version ); \
			NifStream( bumpMapTexture.transformType_, in, version ); \
			NifStream( bumpMapTexture.centerOffset, in, version ); \
		}; \
	}; \
	NifStream( bumpMapLumaScale, in, version ); \
	NifStream( bumpMapLumaOffset, in, version ); \
	NifStream( bumpMapMatrix, in, version ); \
}; \
NifStream( hasDecal0Texture, in, version ); \
if ( (hasDecal0Texture != 0) ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
	NifStream( decal0Texture.clampMode, in, version ); \
	NifStream( decal0Texture.filterMode, in, version ); \
	NifStream( decal0Texture.textureSet, in, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( decal0Texture.ps2L, in, version ); \
		NifStream( decal0Texture.ps2K, in, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( decal0Texture.unknown1, in, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( decal0Texture.hasTextureTransform, in, version ); \
		if ( (decal0Texture.hasTextureTransform != 0) ) { \
			NifStream( decal0Texture.translation, in, version ); \
			NifStream( decal0Texture.tiling, in, version ); \
			NifStream( decal0Texture.wRotation, in, version ); \
			NifStream( decal0Texture.transformType_, in, version ); \
			NifStream( decal0Texture.centerOffset, in, version ); \
		}; \
	}; \
}; \
if ( (textureCount == 8) ) { \
	NifStream( hasDecal1Texture, in, version ); \
}; \
if ( version >= 0x14000004 ) { \
	if ( (((textureCount == 8)) && ((hasDecal1Texture != 0))) ) { \
		NifStream( block_num, in, version ); \
		link_stack.push_back( block_num ); \
		NifStream( decal1Texture.clampMode, in, version ); \
		NifStream( decal1Texture.filterMode, in, version ); \
		NifStream( decal1Texture.textureSet, in, version ); \
		if ( version <= 0x0A020000 ) { \
			NifStream( decal1Texture.ps2L, in, version ); \
			NifStream( decal1Texture.ps2K, in, version ); \
		}; \
		if ( version <= 0x0401000C ) { \
			NifStream( decal1Texture.unknown1, in, version ); \
		}; \
		if ( version >= 0x0A010000 ) { \
			NifStream( decal1Texture.hasTextureTransform, in, version ); \
			if ( (decal1Texture.hasTextureTransform != 0) ) { \
				NifStream( decal1Texture.translation, in, version ); \
				NifStream( decal1Texture.tiling, in, version ); \
				NifStream( decal1Texture.wRotation, in, version ); \
				NifStream( decal1Texture.transformType_, in, version ); \
				NifStream( decal1Texture.centerOffset, in, version ); \
			}; \
		}; \
	}; \
}; \
if ( version >= 0x0A000100 ) { \
	NifStream( numShaderTextures, in, version ); \
	shaderTextures.resize(numShaderTextures); \
	for (uint i1 = 0; i1 < shaderTextures.size(); i1++) { \
		NifStream( shaderTextures[i1].isUsed, in, version ); \
		if ( (shaderTextures[i1].isUsed != 0) ) { \
			NifStream( block_num, in, version ); \
			link_stack.push_back( block_num ); \
			NifStream( shaderTextures[i1].textureData.clampMode, in, version ); \
			NifStream( shaderTextures[i1].textureData.filterMode, in, version ); \
			NifStream( shaderTextures[i1].textureData.textureSet, in, version ); \
			if ( version <= 0x0A020000 ) { \
				NifStream( shaderTextures[i1].textureData.ps2L, in, version ); \
				NifStream( shaderTextures[i1].textureData.ps2K, in, version ); \
			}; \
			if ( version <= 0x0401000C ) { \
				NifStream( shaderTextures[i1].textureData.unknown1, in, version ); \
			}; \
			if ( version >= 0x0A010000 ) { \
				NifStream( shaderTextures[i1].textureData.hasTextureTransform, in, version ); \
				if ( (shaderTextures[i1].textureData.hasTextureTransform != 0) ) { \
					NifStream( shaderTextures[i1].textureData.translation, in, version ); \
					NifStream( shaderTextures[i1].textureData.tiling, in, version ); \
					NifStream( shaderTextures[i1].textureData.wRotation, in, version ); \
					NifStream( shaderTextures[i1].textureData.transformType_, in, version ); \
					NifStream( shaderTextures[i1].textureData.centerOffset, in, version ); \
				}; \
			}; \
			NifStream( shaderTextures[i1].unknownInt, in, version ); \
		}; \
	}; \
}; \

#define NI_TEXTURING_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
if ( version <= 0x0A000102 ) { \
	NifStream( flags, out, version ); \
}; \
NifStream( applyMode, out, version ); \
NifStream( textureCount, out, version ); \
NifStream( hasBaseTexture, out, version ); \
if ( (hasBaseTexture != 0) ) { \
	if ( baseTexture.source != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(baseTexture.source)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( baseTexture.clampMode, out, version ); \
	NifStream( baseTexture.filterMode, out, version ); \
	NifStream( baseTexture.textureSet, out, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( baseTexture.ps2L, out, version ); \
		NifStream( baseTexture.ps2K, out, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( baseTexture.unknown1, out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( baseTexture.hasTextureTransform, out, version ); \
		if ( (baseTexture.hasTextureTransform != 0) ) { \
			NifStream( baseTexture.translation, out, version ); \
			NifStream( baseTexture.tiling, out, version ); \
			NifStream( baseTexture.wRotation, out, version ); \
			NifStream( baseTexture.transformType_, out, version ); \
			NifStream( baseTexture.centerOffset, out, version ); \
		}; \
	}; \
}; \
NifStream( hasDarkTexture, out, version ); \
if ( (hasDarkTexture != 0) ) { \
	if ( darkTexture.source != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(darkTexture.source)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( darkTexture.clampMode, out, version ); \
	NifStream( darkTexture.filterMode, out, version ); \
	NifStream( darkTexture.textureSet, out, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( darkTexture.ps2L, out, version ); \
		NifStream( darkTexture.ps2K, out, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( darkTexture.unknown1, out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( darkTexture.hasTextureTransform, out, version ); \
		if ( (darkTexture.hasTextureTransform != 0) ) { \
			NifStream( darkTexture.translation, out, version ); \
			NifStream( darkTexture.tiling, out, version ); \
			NifStream( darkTexture.wRotation, out, version ); \
			NifStream( darkTexture.transformType_, out, version ); \
			NifStream( darkTexture.centerOffset, out, version ); \
		}; \
	}; \
}; \
NifStream( hasDetailTexture, out, version ); \
if ( (hasDetailTexture != 0) ) { \
	if ( detailTexture.source != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(detailTexture.source)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( detailTexture.clampMode, out, version ); \
	NifStream( detailTexture.filterMode, out, version ); \
	NifStream( detailTexture.textureSet, out, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( detailTexture.ps2L, out, version ); \
		NifStream( detailTexture.ps2K, out, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( detailTexture.unknown1, out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( detailTexture.hasTextureTransform, out, version ); \
		if ( (detailTexture.hasTextureTransform != 0) ) { \
			NifStream( detailTexture.translation, out, version ); \
			NifStream( detailTexture.tiling, out, version ); \
			NifStream( detailTexture.wRotation, out, version ); \
			NifStream( detailTexture.transformType_, out, version ); \
			NifStream( detailTexture.centerOffset, out, version ); \
		}; \
	}; \
}; \
NifStream( hasGlossTexture, out, version ); \
if ( (hasGlossTexture != 0) ) { \
	if ( glossTexture.source != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(glossTexture.source)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( glossTexture.clampMode, out, version ); \
	NifStream( glossTexture.filterMode, out, version ); \
	NifStream( glossTexture.textureSet, out, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( glossTexture.ps2L, out, version ); \
		NifStream( glossTexture.ps2K, out, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( glossTexture.unknown1, out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( glossTexture.hasTextureTransform, out, version ); \
		if ( (glossTexture.hasTextureTransform != 0) ) { \
			NifStream( glossTexture.translation, out, version ); \
			NifStream( glossTexture.tiling, out, version ); \
			NifStream( glossTexture.wRotation, out, version ); \
			NifStream( glossTexture.transformType_, out, version ); \
			NifStream( glossTexture.centerOffset, out, version ); \
		}; \
	}; \
}; \
NifStream( hasGlowTexture, out, version ); \
if ( (hasGlowTexture != 0) ) { \
	if ( glowTexture.source != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(glowTexture.source)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( glowTexture.clampMode, out, version ); \
	NifStream( glowTexture.filterMode, out, version ); \
	NifStream( glowTexture.textureSet, out, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( glowTexture.ps2L, out, version ); \
		NifStream( glowTexture.ps2K, out, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( glowTexture.unknown1, out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( glowTexture.hasTextureTransform, out, version ); \
		if ( (glowTexture.hasTextureTransform != 0) ) { \
			NifStream( glowTexture.translation, out, version ); \
			NifStream( glowTexture.tiling, out, version ); \
			NifStream( glowTexture.wRotation, out, version ); \
			NifStream( glowTexture.transformType_, out, version ); \
			NifStream( glowTexture.centerOffset, out, version ); \
		}; \
	}; \
}; \
NifStream( hasBumpMapTexture, out, version ); \
if ( (hasBumpMapTexture != 0) ) { \
	if ( bumpMapTexture.source != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(bumpMapTexture.source)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( bumpMapTexture.clampMode, out, version ); \
	NifStream( bumpMapTexture.filterMode, out, version ); \
	NifStream( bumpMapTexture.textureSet, out, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( bumpMapTexture.ps2L, out, version ); \
		NifStream( bumpMapTexture.ps2K, out, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( bumpMapTexture.unknown1, out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( bumpMapTexture.hasTextureTransform, out, version ); \
		if ( (bumpMapTexture.hasTextureTransform != 0) ) { \
			NifStream( bumpMapTexture.translation, out, version ); \
			NifStream( bumpMapTexture.tiling, out, version ); \
			NifStream( bumpMapTexture.wRotation, out, version ); \
			NifStream( bumpMapTexture.transformType_, out, version ); \
			NifStream( bumpMapTexture.centerOffset, out, version ); \
		}; \
	}; \
	NifStream( bumpMapLumaScale, out, version ); \
	NifStream( bumpMapLumaOffset, out, version ); \
	NifStream( bumpMapMatrix, out, version ); \
}; \
NifStream( hasDecal0Texture, out, version ); \
if ( (hasDecal0Texture != 0) ) { \
	if ( decal0Texture.source != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(decal0Texture.source)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
	NifStream( decal0Texture.clampMode, out, version ); \
	NifStream( decal0Texture.filterMode, out, version ); \
	NifStream( decal0Texture.textureSet, out, version ); \
	if ( version <= 0x0A020000 ) { \
		NifStream( decal0Texture.ps2L, out, version ); \
		NifStream( decal0Texture.ps2K, out, version ); \
	}; \
	if ( version <= 0x0401000C ) { \
		NifStream( decal0Texture.unknown1, out, version ); \
	}; \
	if ( version >= 0x0A010000 ) { \
		NifStream( decal0Texture.hasTextureTransform, out, version ); \
		if ( (decal0Texture.hasTextureTransform != 0) ) { \
			NifStream( decal0Texture.translation, out, version ); \
			NifStream( decal0Texture.tiling, out, version ); \
			NifStream( decal0Texture.wRotation, out, version ); \
			NifStream( decal0Texture.transformType_, out, version ); \
			NifStream( decal0Texture.centerOffset, out, version ); \
		}; \
	}; \
}; \
if ( (textureCount == 8) ) { \
	NifStream( hasDecal1Texture, out, version ); \
}; \
if ( version >= 0x14000004 ) { \
	if ( (((textureCount == 8)) && ((hasDecal1Texture != 0))) ) { \
		if ( decal1Texture.source != NULL ) \
			NifStream( link_map[StaticCast<NiObject>(decal1Texture.source)], out, version ); \
		else \
			NifStream( 0xffffffff, out, version ); \
		NifStream( decal1Texture.clampMode, out, version ); \
		NifStream( decal1Texture.filterMode, out, version ); \
		NifStream( decal1Texture.textureSet, out, version ); \
		if ( version <= 0x0A020000 ) { \
			NifStream( decal1Texture.ps2L, out, version ); \
			NifStream( decal1Texture.ps2K, out, version ); \
		}; \
		if ( version <= 0x0401000C ) { \
			NifStream( decal1Texture.unknown1, out, version ); \
		}; \
		if ( version >= 0x0A010000 ) { \
			NifStream( decal1Texture.hasTextureTransform, out, version ); \
			if ( (decal1Texture.hasTextureTransform != 0) ) { \
				NifStream( decal1Texture.translation, out, version ); \
				NifStream( decal1Texture.tiling, out, version ); \
				NifStream( decal1Texture.wRotation, out, version ); \
				NifStream( decal1Texture.transformType_, out, version ); \
				NifStream( decal1Texture.centerOffset, out, version ); \
			}; \
		}; \
	}; \
}; \
if ( version >= 0x0A000100 ) { \
	NifStream( numShaderTextures, out, version ); \
	for (uint i1 = 0; i1 < shaderTextures.size(); i1++) { \
		NifStream( shaderTextures[i1].isUsed, out, version ); \
		if ( (shaderTextures[i1].isUsed != 0) ) { \
			if ( shaderTextures[i1].textureData.source != NULL ) \
				NifStream( link_map[StaticCast<NiObject>(shaderTextures[i1].textureData.source)], out, version ); \
			else \
				NifStream( 0xffffffff, out, version ); \
			NifStream( shaderTextures[i1].textureData.clampMode, out, version ); \
			NifStream( shaderTextures[i1].textureData.filterMode, out, version ); \
			NifStream( shaderTextures[i1].textureData.textureSet, out, version ); \
			if ( version <= 0x0A020000 ) { \
				NifStream( shaderTextures[i1].textureData.ps2L, out, version ); \
				NifStream( shaderTextures[i1].textureData.ps2K, out, version ); \
			}; \
			if ( version <= 0x0401000C ) { \
				NifStream( shaderTextures[i1].textureData.unknown1, out, version ); \
			}; \
			if ( version >= 0x0A010000 ) { \
				NifStream( shaderTextures[i1].textureData.hasTextureTransform, out, version ); \
				if ( (shaderTextures[i1].textureData.hasTextureTransform != 0) ) { \
					NifStream( shaderTextures[i1].textureData.translation, out, version ); \
					NifStream( shaderTextures[i1].textureData.tiling, out, version ); \
					NifStream( shaderTextures[i1].textureData.wRotation, out, version ); \
					NifStream( shaderTextures[i1].textureData.transformType_, out, version ); \
					NifStream( shaderTextures[i1].textureData.centerOffset, out, version ); \
				}; \
			}; \
			NifStream( shaderTextures[i1].unknownInt, out, version ); \
		}; \
	}; \
}; \

#define NI_TEXTURING_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
out << "Apply Mode:  " << applyMode << endl; \
out << "Texture Count:  " << textureCount << endl; \
out << "Has Base Texture:  " << hasBaseTexture << endl; \
if ( (hasBaseTexture != 0) ) { \
	out << "  Source:  " << baseTexture.source << endl; \
	out << "  Clamp Mode:  " << baseTexture.clampMode << endl; \
	out << "  Filter Mode:  " << baseTexture.filterMode << endl; \
	out << "  Texture Set:  " << baseTexture.textureSet << endl; \
	out << "  PS2 L:  " << baseTexture.ps2L << endl; \
	out << "  PS2 K:  " << baseTexture.ps2K << endl; \
	out << "  Unknown1:  " << baseTexture.unknown1 << endl; \
	out << "  Has Texture Transform:  " << baseTexture.hasTextureTransform << endl; \
	if ( (baseTexture.hasTextureTransform != 0) ) { \
		out << "    Translation:  " << baseTexture.translation << endl; \
		out << "    Tiling:  " << baseTexture.tiling << endl; \
		out << "    W Rotation:  " << baseTexture.wRotation << endl; \
		out << "    Transform Type?:  " << baseTexture.transformType_ << endl; \
		out << "    Center Offset:  " << baseTexture.centerOffset << endl; \
	}; \
}; \
out << "Has Dark Texture:  " << hasDarkTexture << endl; \
if ( (hasDarkTexture != 0) ) { \
	out << "  Source:  " << darkTexture.source << endl; \
	out << "  Clamp Mode:  " << darkTexture.clampMode << endl; \
	out << "  Filter Mode:  " << darkTexture.filterMode << endl; \
	out << "  Texture Set:  " << darkTexture.textureSet << endl; \
	out << "  PS2 L:  " << darkTexture.ps2L << endl; \
	out << "  PS2 K:  " << darkTexture.ps2K << endl; \
	out << "  Unknown1:  " << darkTexture.unknown1 << endl; \
	out << "  Has Texture Transform:  " << darkTexture.hasTextureTransform << endl; \
	if ( (darkTexture.hasTextureTransform != 0) ) { \
		out << "    Translation:  " << darkTexture.translation << endl; \
		out << "    Tiling:  " << darkTexture.tiling << endl; \
		out << "    W Rotation:  " << darkTexture.wRotation << endl; \
		out << "    Transform Type?:  " << darkTexture.transformType_ << endl; \
		out << "    Center Offset:  " << darkTexture.centerOffset << endl; \
	}; \
}; \
out << "Has Detail Texture:  " << hasDetailTexture << endl; \
if ( (hasDetailTexture != 0) ) { \
	out << "  Source:  " << detailTexture.source << endl; \
	out << "  Clamp Mode:  " << detailTexture.clampMode << endl; \
	out << "  Filter Mode:  " << detailTexture.filterMode << endl; \
	out << "  Texture Set:  " << detailTexture.textureSet << endl; \
	out << "  PS2 L:  " << detailTexture.ps2L << endl; \
	out << "  PS2 K:  " << detailTexture.ps2K << endl; \
	out << "  Unknown1:  " << detailTexture.unknown1 << endl; \
	out << "  Has Texture Transform:  " << detailTexture.hasTextureTransform << endl; \
	if ( (detailTexture.hasTextureTransform != 0) ) { \
		out << "    Translation:  " << detailTexture.translation << endl; \
		out << "    Tiling:  " << detailTexture.tiling << endl; \
		out << "    W Rotation:  " << detailTexture.wRotation << endl; \
		out << "    Transform Type?:  " << detailTexture.transformType_ << endl; \
		out << "    Center Offset:  " << detailTexture.centerOffset << endl; \
	}; \
}; \
out << "Has Gloss Texture:  " << hasGlossTexture << endl; \
if ( (hasGlossTexture != 0) ) { \
	out << "  Source:  " << glossTexture.source << endl; \
	out << "  Clamp Mode:  " << glossTexture.clampMode << endl; \
	out << "  Filter Mode:  " << glossTexture.filterMode << endl; \
	out << "  Texture Set:  " << glossTexture.textureSet << endl; \
	out << "  PS2 L:  " << glossTexture.ps2L << endl; \
	out << "  PS2 K:  " << glossTexture.ps2K << endl; \
	out << "  Unknown1:  " << glossTexture.unknown1 << endl; \
	out << "  Has Texture Transform:  " << glossTexture.hasTextureTransform << endl; \
	if ( (glossTexture.hasTextureTransform != 0) ) { \
		out << "    Translation:  " << glossTexture.translation << endl; \
		out << "    Tiling:  " << glossTexture.tiling << endl; \
		out << "    W Rotation:  " << glossTexture.wRotation << endl; \
		out << "    Transform Type?:  " << glossTexture.transformType_ << endl; \
		out << "    Center Offset:  " << glossTexture.centerOffset << endl; \
	}; \
}; \
out << "Has Glow Texture:  " << hasGlowTexture << endl; \
if ( (hasGlowTexture != 0) ) { \
	out << "  Source:  " << glowTexture.source << endl; \
	out << "  Clamp Mode:  " << glowTexture.clampMode << endl; \
	out << "  Filter Mode:  " << glowTexture.filterMode << endl; \
	out << "  Texture Set:  " << glowTexture.textureSet << endl; \
	out << "  PS2 L:  " << glowTexture.ps2L << endl; \
	out << "  PS2 K:  " << glowTexture.ps2K << endl; \
	out << "  Unknown1:  " << glowTexture.unknown1 << endl; \
	out << "  Has Texture Transform:  " << glowTexture.hasTextureTransform << endl; \
	if ( (glowTexture.hasTextureTransform != 0) ) { \
		out << "    Translation:  " << glowTexture.translation << endl; \
		out << "    Tiling:  " << glowTexture.tiling << endl; \
		out << "    W Rotation:  " << glowTexture.wRotation << endl; \
		out << "    Transform Type?:  " << glowTexture.transformType_ << endl; \
		out << "    Center Offset:  " << glowTexture.centerOffset << endl; \
	}; \
}; \
out << "Has Bump Map Texture:  " << hasBumpMapTexture << endl; \
if ( (hasBumpMapTexture != 0) ) { \
	out << "  Source:  " << bumpMapTexture.source << endl; \
	out << "  Clamp Mode:  " << bumpMapTexture.clampMode << endl; \
	out << "  Filter Mode:  " << bumpMapTexture.filterMode << endl; \
	out << "  Texture Set:  " << bumpMapTexture.textureSet << endl; \
	out << "  PS2 L:  " << bumpMapTexture.ps2L << endl; \
	out << "  PS2 K:  " << bumpMapTexture.ps2K << endl; \
	out << "  Unknown1:  " << bumpMapTexture.unknown1 << endl; \
	out << "  Has Texture Transform:  " << bumpMapTexture.hasTextureTransform << endl; \
	if ( (bumpMapTexture.hasTextureTransform != 0) ) { \
		out << "    Translation:  " << bumpMapTexture.translation << endl; \
		out << "    Tiling:  " << bumpMapTexture.tiling << endl; \
		out << "    W Rotation:  " << bumpMapTexture.wRotation << endl; \
		out << "    Transform Type?:  " << bumpMapTexture.transformType_ << endl; \
		out << "    Center Offset:  " << bumpMapTexture.centerOffset << endl; \
	}; \
	out << "  Bump Map Luma Scale:  " << bumpMapLumaScale << endl; \
	out << "  Bump Map Luma Offset:  " << bumpMapLumaOffset << endl; \
	out << "  Bump Map Matrix:  " << bumpMapMatrix << endl; \
}; \
out << "Has Decal 0 Texture:  " << hasDecal0Texture << endl; \
if ( (hasDecal0Texture != 0) ) { \
	out << "  Source:  " << decal0Texture.source << endl; \
	out << "  Clamp Mode:  " << decal0Texture.clampMode << endl; \
	out << "  Filter Mode:  " << decal0Texture.filterMode << endl; \
	out << "  Texture Set:  " << decal0Texture.textureSet << endl; \
	out << "  PS2 L:  " << decal0Texture.ps2L << endl; \
	out << "  PS2 K:  " << decal0Texture.ps2K << endl; \
	out << "  Unknown1:  " << decal0Texture.unknown1 << endl; \
	out << "  Has Texture Transform:  " << decal0Texture.hasTextureTransform << endl; \
	if ( (decal0Texture.hasTextureTransform != 0) ) { \
		out << "    Translation:  " << decal0Texture.translation << endl; \
		out << "    Tiling:  " << decal0Texture.tiling << endl; \
		out << "    W Rotation:  " << decal0Texture.wRotation << endl; \
		out << "    Transform Type?:  " << decal0Texture.transformType_ << endl; \
		out << "    Center Offset:  " << decal0Texture.centerOffset << endl; \
	}; \
}; \
if ( (textureCount == 8) ) { \
	out << "  Has Decal 1 Texture:  " << hasDecal1Texture << endl; \
}; \
if ( (((textureCount == 8)) && ((hasDecal1Texture != 0))) ) { \
	out << "  Source:  " << decal1Texture.source << endl; \
	out << "  Clamp Mode:  " << decal1Texture.clampMode << endl; \
	out << "  Filter Mode:  " << decal1Texture.filterMode << endl; \
	out << "  Texture Set:  " << decal1Texture.textureSet << endl; \
	out << "  PS2 L:  " << decal1Texture.ps2L << endl; \
	out << "  PS2 K:  " << decal1Texture.ps2K << endl; \
	out << "  Unknown1:  " << decal1Texture.unknown1 << endl; \
	out << "  Has Texture Transform:  " << decal1Texture.hasTextureTransform << endl; \
	if ( (decal1Texture.hasTextureTransform != 0) ) { \
		out << "    Translation:  " << decal1Texture.translation << endl; \
		out << "    Tiling:  " << decal1Texture.tiling << endl; \
		out << "    W Rotation:  " << decal1Texture.wRotation << endl; \
		out << "    Transform Type?:  " << decal1Texture.transformType_ << endl; \
		out << "    Center Offset:  " << decal1Texture.centerOffset << endl; \
	}; \
}; \
out << "Num Shader Textures:  " << numShaderTextures << endl; \
for (uint i0 = 0; i0 < shaderTextures.size(); i0++) { \
	out << "  Is Used:  " << shaderTextures[i0].isUsed << endl; \
	if ( (shaderTextures[i0].isUsed != 0) ) { \
		out << "    Source:  " << shaderTextures[i0].textureData.source << endl; \
		out << "    Clamp Mode:  " << shaderTextures[i0].textureData.clampMode << endl; \
		out << "    Filter Mode:  " << shaderTextures[i0].textureData.filterMode << endl; \
		out << "    Texture Set:  " << shaderTextures[i0].textureData.textureSet << endl; \
		out << "    PS2 L:  " << shaderTextures[i0].textureData.ps2L << endl; \
		out << "    PS2 K:  " << shaderTextures[i0].textureData.ps2K << endl; \
		out << "    Unknown1:  " << shaderTextures[i0].textureData.unknown1 << endl; \
		out << "    Has Texture Transform:  " << shaderTextures[i0].textureData.hasTextureTransform << endl; \
		if ( (shaderTextures[i0].textureData.hasTextureTransform != 0) ) { \
			out << "      Translation:  " << shaderTextures[i0].textureData.translation << endl; \
			out << "      Tiling:  " << shaderTextures[i0].textureData.tiling << endl; \
			out << "      W Rotation:  " << shaderTextures[i0].textureData.wRotation << endl; \
			out << "      Transform Type?:  " << shaderTextures[i0].textureData.transformType_ << endl; \
			out << "      Center Offset:  " << shaderTextures[i0].textureData.centerOffset << endl; \
		}; \
		out << "    Unknown Int:  " << shaderTextures[i0].unknownInt << endl; \
	}; \
}; \
return out.str(); \

#define NI_TEXTURING_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \
if ( (hasBaseTexture != 0) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		baseTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
		if ( baseTexture.source == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		baseTexture.source = NULL; \
	link_stack.pop_front(); \
}; \
if ( (hasDarkTexture != 0) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		darkTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
		if ( darkTexture.source == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		darkTexture.source = NULL; \
	link_stack.pop_front(); \
}; \
if ( (hasDetailTexture != 0) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		detailTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
		if ( detailTexture.source == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		detailTexture.source = NULL; \
	link_stack.pop_front(); \
}; \
if ( (hasGlossTexture != 0) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		glossTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
		if ( glossTexture.source == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		glossTexture.source = NULL; \
	link_stack.pop_front(); \
}; \
if ( (hasGlowTexture != 0) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		glowTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
		if ( glowTexture.source == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		glowTexture.source = NULL; \
	link_stack.pop_front(); \
}; \
if ( (hasBumpMapTexture != 0) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		bumpMapTexture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
		if ( bumpMapTexture.source == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		bumpMapTexture.source = NULL; \
	link_stack.pop_front(); \
}; \
if ( (hasDecal0Texture != 0) ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		decal0Texture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
		if ( decal0Texture.source == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		decal0Texture.source = NULL; \
	link_stack.pop_front(); \
}; \
if ( version >= 0x14000004 ) { \
	if ( (((textureCount == 8)) && ((hasDecal1Texture != 0))) ) { \
		if (link_stack.empty()) \
			throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
		if (link_stack.front() != 0xffffffff) { \
			decal1Texture.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
			if ( decal1Texture.source == NULL ) \
				throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
		} else \
			decal1Texture.source = NULL; \
		link_stack.pop_front(); \
	}; \
}; \
if ( version >= 0x0A000100 ) { \
	for (uint i1 = 0; i1 < shaderTextures.size(); i1++) { \
		if ( (shaderTextures[i1].isUsed != 0) ) { \
			if (link_stack.empty()) \
				throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
			if (link_stack.front() != 0xffffffff) { \
				shaderTextures[i1].textureData.source = DynamicCast<NiSourceTexture>(objects[link_stack.front()]); \
				if ( shaderTextures[i1].textureData.source == NULL ) \
					throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
			} else \
				shaderTextures[i1].textureData.source = NULL; \
			link_stack.pop_front(); \
		}; \
	}; \
}; \

#define NI_TEXTURING_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
if ( baseTexture.source != NULL ) \
	refs.push_back(StaticCast<NiObject>(baseTexture.source)); \
if ( darkTexture.source != NULL ) \
	refs.push_back(StaticCast<NiObject>(darkTexture.source)); \
if ( detailTexture.source != NULL ) \
	refs.push_back(StaticCast<NiObject>(detailTexture.source)); \
if ( glossTexture.source != NULL ) \
	refs.push_back(StaticCast<NiObject>(glossTexture.source)); \
if ( glowTexture.source != NULL ) \
	refs.push_back(StaticCast<NiObject>(glowTexture.source)); \
if ( bumpMapTexture.source != NULL ) \
	refs.push_back(StaticCast<NiObject>(bumpMapTexture.source)); \
if ( decal0Texture.source != NULL ) \
	refs.push_back(StaticCast<NiObject>(decal0Texture.source)); \
if ( decal1Texture.source != NULL ) \
	refs.push_back(StaticCast<NiObject>(decal1Texture.source)); \
for (uint i0 = 0; i0 < shaderTextures.size(); i0++) { \
	if ( shaderTextures[i0].textureData.source != NULL ) \
		refs.push_back(StaticCast<NiObject>(shaderTextures[i0].textureData.source)); \
}; \
return refs; \

#define NI_TRANSFORM_CONTROLLER_MEMBERS \

#define NI_TRANSFORM_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_TRANSFORM_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_TRANSFORM_CONTROLLER_CONSTRUCT \

#define NI_TRANSFORM_CONTROLLER_READ \
NiSingleInterpolatorController::Read( in, link_stack, version, user_version ); \

#define NI_TRANSFORM_CONTROLLER_WRITE \
NiSingleInterpolatorController::Write( out, link_map, version, user_version ); \

#define NI_TRANSFORM_CONTROLLER_STRING \
stringstream out; \
out << NiSingleInterpolatorController::asString(); \
return out.str(); \

#define NI_TRANSFORM_CONTROLLER_FIXLINKS \
NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version ); \

#define NI_TRANSFORM_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiSingleInterpolatorController::GetRefs(); \
return refs; \

#define NI_TRANSFORM_DATA_MEMBERS \

#define NI_TRANSFORM_DATA_INCLUDE "NiKeyframeData.h" \

#define NI_TRANSFORM_DATA_PARENT NiKeyframeData \

#define NI_TRANSFORM_DATA_CONSTRUCT \

#define NI_TRANSFORM_DATA_READ \
NiKeyframeData::Read( in, link_stack, version, user_version ); \

#define NI_TRANSFORM_DATA_WRITE \
NiKeyframeData::Write( out, link_map, version, user_version ); \

#define NI_TRANSFORM_DATA_STRING \
stringstream out; \
out << NiKeyframeData::asString(); \
return out.str(); \

#define NI_TRANSFORM_DATA_FIXLINKS \
NiKeyframeData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_TRANSFORM_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiKeyframeData::GetRefs(); \
return refs; \

#define NI_TRANSFORM_INTERPOLATOR_MEMBERS \
Vector3 translation; \
Quaternion rotation; \
float scale; \
byte unknownBytes[3]; \
Ref<NiTransformData > data; \

#define NI_TRANSFORM_INTERPOLATOR_INCLUDE "NiInterpolator.h" \

#define NI_TRANSFORM_INTERPOLATOR_PARENT NiInterpolator \

#define NI_TRANSFORM_INTERPOLATOR_CONSTRUCT \
 : scale(0.0f), data(NULL) \

#define NI_TRANSFORM_INTERPOLATOR_READ \
uint block_num; \
NiInterpolator::Read( in, link_stack, version, user_version ); \
NifStream( translation, in, version ); \
NifStream( rotation, in, version ); \
NifStream( scale, in, version ); \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
	for (uint i1 = 0; i1 < 3; i1++) { \
		NifStream( unknownBytes[i1], in, version ); \
	}; \
}; \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_TRANSFORM_INTERPOLATOR_WRITE \
NiInterpolator::Write( out, link_map, version, user_version ); \
NifStream( translation, out, version ); \
NifStream( rotation, out, version ); \
NifStream( scale, out, version ); \
if ( ( version >= 0x0A01006A ) && ( version <= 0x0A01006A ) ) { \
	for (uint i1 = 0; i1 < 3; i1++) { \
		NifStream( unknownBytes[i1], out, version ); \
	}; \
}; \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_TRANSFORM_INTERPOLATOR_STRING \
stringstream out; \
out << NiInterpolator::asString(); \
out << "Translation:  " << translation << endl; \
out << "Rotation:  " << rotation << endl; \
out << "Scale:  " << scale << endl; \
for (uint i0 = 0; i0 < 3; i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Unknown Bytes[" << i0 << "]:  " << unknownBytes[i0] << endl; \
}; \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_TRANSFORM_INTERPOLATOR_FIXLINKS \
NiInterpolator::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiTransformData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define NI_TRANSFORM_INTERPOLATOR_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiInterpolator::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_TRI_SHAPE_MEMBERS \

#define NI_TRI_SHAPE_INCLUDE "NiTriBasedGeom.h" \

#define NI_TRI_SHAPE_PARENT NiTriBasedGeom \

#define NI_TRI_SHAPE_CONSTRUCT \

#define NI_TRI_SHAPE_READ \
NiTriBasedGeom::Read( in, link_stack, version, user_version ); \

#define NI_TRI_SHAPE_WRITE \
NiTriBasedGeom::Write( out, link_map, version, user_version ); \

#define NI_TRI_SHAPE_STRING \
stringstream out; \
out << NiTriBasedGeom::asString(); \
return out.str(); \

#define NI_TRI_SHAPE_FIXLINKS \
NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_SHAPE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTriBasedGeom::GetRefs(); \
return refs; \

#define NI_TRI_SHAPE_DATA_MEMBERS \
ushort numTriangles; \
uint numTrianglePoints; \
bool hasTriangles; \
vector<Triangle > triangles; \
ushort numMatchGroups; \
vector<MatchGroup > matchGroups; \

#define NI_TRI_SHAPE_DATA_INCLUDE "NiTriBasedGeomData.h" \

#define NI_TRI_SHAPE_DATA_PARENT NiTriBasedGeomData \

#define NI_TRI_SHAPE_DATA_CONSTRUCT \
 : numTriangles((ushort)0), numTrianglePoints((uint)0), hasTriangles(false), numMatchGroups((ushort)0) \

#define NI_TRI_SHAPE_DATA_READ \
NiTriBasedGeomData::Read( in, link_stack, version, user_version ); \
NifStream( numTriangles, in, version ); \
NifStream( numTrianglePoints, in, version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( hasTriangles, in, version ); \
}; \
if ( version <= 0x0A000102 ) { \
	triangles.resize(numTriangles); \
	for (uint i1 = 0; i1 < triangles.size(); i1++) { \
		NifStream( triangles[i1], in, version ); \
	}; \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (hasTriangles != 0) ) { \
		triangles.resize(numTriangles); \
		for (uint i2 = 0; i2 < triangles.size(); i2++) { \
			NifStream( triangles[i2], in, version ); \
		}; \
	}; \
}; \
NifStream( numMatchGroups, in, version ); \
matchGroups.resize(numMatchGroups); \
for (uint i0 = 0; i0 < matchGroups.size(); i0++) { \
	NifStream( matchGroups[i0].numVertices, in, version ); \
	matchGroups[i0].vertexIndices.resize(matchGroups[i0].numVertices); \
	for (uint i1 = 0; i1 < matchGroups[i0].vertexIndices.size(); i1++) { \
		NifStream( matchGroups[i0].vertexIndices[i1], in, version ); \
	}; \
}; \

#define NI_TRI_SHAPE_DATA_WRITE \
NiTriBasedGeomData::Write( out, link_map, version, user_version ); \
NifStream( numTriangles, out, version ); \
NifStream( numTrianglePoints, out, version ); \
if ( version >= 0x0A010000 ) { \
	NifStream( hasTriangles, out, version ); \
}; \
if ( version <= 0x0A000102 ) { \
	for (uint i1 = 0; i1 < triangles.size(); i1++) { \
		NifStream( triangles[i1], out, version ); \
	}; \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (hasTriangles != 0) ) { \
		for (uint i2 = 0; i2 < triangles.size(); i2++) { \
			NifStream( triangles[i2], out, version ); \
		}; \
	}; \
}; \
NifStream( numMatchGroups, out, version ); \
for (uint i0 = 0; i0 < matchGroups.size(); i0++) { \
	NifStream( matchGroups[i0].numVertices, out, version ); \
	for (uint i1 = 0; i1 < matchGroups[i0].vertexIndices.size(); i1++) { \
		NifStream( matchGroups[i0].vertexIndices[i1], out, version ); \
	}; \
}; \

#define NI_TRI_SHAPE_DATA_STRING \
stringstream out; \
out << NiTriBasedGeomData::asString(); \
out << "Num Triangles:  " << numTriangles << endl; \
out << "Num Triangle Points:  " << numTrianglePoints << endl; \
out << "Has Triangles:  " << hasTriangles << endl; \
for (uint i0 = 0; i0 < triangles.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Triangles[" << i0 << "]:  " << triangles[i0] << endl; \
}; \
out << "Num Match Groups:  " << numMatchGroups << endl; \
for (uint i0 = 0; i0 < matchGroups.size(); i0++) { \
	out << "  Num Vertices:  " << matchGroups[i0].numVertices << endl; \
	for (uint i1 = 0; i1 < matchGroups[i0].vertexIndices.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Vertex Indices[" << i1 << "]:  " << matchGroups[i0].vertexIndices[i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_TRI_SHAPE_DATA_FIXLINKS \
NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_SHAPE_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTriBasedGeomData::GetRefs(); \
return refs; \

#define NI_TRI_STRIPS_MEMBERS \

#define NI_TRI_STRIPS_INCLUDE "NiTriBasedGeom.h" \

#define NI_TRI_STRIPS_PARENT NiTriBasedGeom \

#define NI_TRI_STRIPS_CONSTRUCT \

#define NI_TRI_STRIPS_READ \
NiTriBasedGeom::Read( in, link_stack, version, user_version ); \

#define NI_TRI_STRIPS_WRITE \
NiTriBasedGeom::Write( out, link_map, version, user_version ); \

#define NI_TRI_STRIPS_STRING \
stringstream out; \
out << NiTriBasedGeom::asString(); \
return out.str(); \

#define NI_TRI_STRIPS_FIXLINKS \
NiTriBasedGeom::FixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_STRIPS_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTriBasedGeom::GetRefs(); \
return refs; \

#define NI_TRI_STRIPS_DATA_MEMBERS \
ushort numTriangles; \
ushort numStrips; \
vector<ushort > stripLengths; \
bool hasPoints; \
vector<vector<ushort > > points; \

#define NI_TRI_STRIPS_DATA_INCLUDE "NiTriBasedGeomData.h" \

#define NI_TRI_STRIPS_DATA_PARENT NiTriBasedGeomData \

#define NI_TRI_STRIPS_DATA_CONSTRUCT \
 : numTriangles((ushort)0), numStrips((ushort)0), hasPoints(false) \

#define NI_TRI_STRIPS_DATA_READ \
NiTriBasedGeomData::Read( in, link_stack, version, user_version ); \
NifStream( numTriangles, in, version ); \
NifStream( numStrips, in, version ); \
stripLengths.resize(numStrips); \
for (uint i0 = 0; i0 < stripLengths.size(); i0++) { \
	NifStream( stripLengths[i0], in, version ); \
}; \
if ( version >= 0x0A010000 ) { \
	NifStream( hasPoints, in, version ); \
}; \
if ( version <= 0x0A000102 ) { \
	points.resize(numStrips); \
	for (uint i1 = 0; i1 < points.size(); i1++) { \
		points[i1].resize(stripLengths[i1]); \
		for (uint i2 = 0; i2 < stripLengths[i1]; i2++) { \
			NifStream( points[i1][i2], in, version ); \
		}; \
	}; \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (hasPoints != 0) ) { \
		points.resize(numStrips); \
		for (uint i2 = 0; i2 < points.size(); i2++) { \
			points[i2].resize(stripLengths[i2]); \
			for (uint i3 = 0; i3 < stripLengths[i2]; i3++) { \
				NifStream( points[i2][i3], in, version ); \
			}; \
		}; \
	}; \
}; \

#define NI_TRI_STRIPS_DATA_WRITE \
NiTriBasedGeomData::Write( out, link_map, version, user_version ); \
NifStream( numTriangles, out, version ); \
NifStream( numStrips, out, version ); \
for (uint i0 = 0; i0 < stripLengths.size(); i0++) { \
	NifStream( stripLengths[i0], out, version ); \
}; \
if ( version >= 0x0A010000 ) { \
	NifStream( hasPoints, out, version ); \
}; \
if ( version <= 0x0A000102 ) { \
	for (uint i1 = 0; i1 < points.size(); i1++) { \
		for (uint i2 = 0; i2 < stripLengths[i1]; i2++) { \
			NifStream( points[i1][i2], out, version ); \
		}; \
	}; \
}; \
if ( version >= 0x0A010000 ) { \
	if ( (hasPoints != 0) ) { \
		for (uint i2 = 0; i2 < points.size(); i2++) { \
			for (uint i3 = 0; i3 < stripLengths[i2]; i3++) { \
				NifStream( points[i2][i3], out, version ); \
			}; \
		}; \
	}; \
}; \

#define NI_TRI_STRIPS_DATA_STRING \
stringstream out; \
out << NiTriBasedGeomData::asString(); \
out << "Num Triangles:  " << numTriangles << endl; \
out << "Num Strips:  " << numStrips << endl; \
for (uint i0 = 0; i0 < stripLengths.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Strip Lengths[" << i0 << "]:  " << stripLengths[i0] << endl; \
}; \
out << "Has Points:  " << hasPoints << endl; \
for (uint i0 = 0; i0 < points.size(); i0++) { \
	for (uint i1 = 0; i1 < stripLengths[i0]; i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Points[" << i0 << "][" << i1 << "]:  " << points[i0][i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_TRI_STRIPS_DATA_FIXLINKS \
NiTriBasedGeomData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_TRI_STRIPS_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTriBasedGeomData::GetRefs(); \
return refs; \

#define NI_U_V_CONTROLLER_MEMBERS \
ushort unknownShort; \
Ref<NiUVData > data; \

#define NI_U_V_CONTROLLER_INCLUDE "NiTimeController.h" \

#define NI_U_V_CONTROLLER_PARENT NiTimeController \

#define NI_U_V_CONTROLLER_CONSTRUCT \
 : unknownShort((ushort)0), data(NULL) \

#define NI_U_V_CONTROLLER_READ \
uint block_num; \
NiTimeController::Read( in, link_stack, version, user_version ); \
NifStream( unknownShort, in, version ); \
NifStream( block_num, in, version ); \
link_stack.push_back( block_num ); \

#define NI_U_V_CONTROLLER_WRITE \
NiTimeController::Write( out, link_map, version, user_version ); \
NifStream( unknownShort, out, version ); \
if ( data != NULL ) \
	NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
else \
	NifStream( 0xffffffff, out, version ); \

#define NI_U_V_CONTROLLER_STRING \
stringstream out; \
out << NiTimeController::asString(); \
out << "Unknown Short:  " << unknownShort << endl; \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_U_V_CONTROLLER_FIXLINKS \
NiTimeController::FixLinks( objects, link_stack, version, user_version ); \
if (link_stack.empty()) \
	throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
if (link_stack.front() != 0xffffffff) { \
	data = DynamicCast<NiUVData>(objects[link_stack.front()]); \
	if ( data == NULL ) \
		throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
} else \
	data = NULL; \
link_stack.pop_front(); \

#define NI_U_V_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiTimeController::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_U_V_DATA_MEMBERS \
KeyGroup<float > uvGroups[4]; \

#define NI_U_V_DATA_INCLUDE "NiObject.h" \

#define NI_U_V_DATA_PARENT NiObject \

#define NI_U_V_DATA_CONSTRUCT \

#define NI_U_V_DATA_READ \
NiObject::Read( in, link_stack, version, user_version ); \
for (uint i0 = 0; i0 < 4; i0++) { \
	NifStream( uvGroups[i0].numKeys, in, version ); \
	if ( (uvGroups[i0].numKeys != 0) ) { \
		NifStream( uvGroups[i0].interpolation, in, version ); \
	}; \
	uvGroups[i0].keys.resize(uvGroups[i0].numKeys); \
	for (uint i1 = 0; i1 < uvGroups[i0].keys.size(); i1++) { \
		NifStream( uvGroups[i0].keys[i1], in, version, uvGroups[i0].interpolation ); \
	}; \
}; \

#define NI_U_V_DATA_WRITE \
NiObject::Write( out, link_map, version, user_version ); \
for (uint i0 = 0; i0 < 4; i0++) { \
	NifStream( uvGroups[i0].numKeys, out, version ); \
	if ( (uvGroups[i0].numKeys != 0) ) { \
		NifStream( uvGroups[i0].interpolation, out, version ); \
	}; \
	for (uint i1 = 0; i1 < uvGroups[i0].keys.size(); i1++) { \
		NifStream( uvGroups[i0].keys[i1], out, version, uvGroups[i0].interpolation ); \
	}; \
}; \

#define NI_U_V_DATA_STRING \
stringstream out; \
out << NiObject::asString(); \
for (uint i0 = 0; i0 < 4; i0++) { \
	out << "  Num Keys:  " << uvGroups[i0].numKeys << endl; \
	if ( (uvGroups[i0].numKeys != 0) ) { \
		out << "    Interpolation:  " << uvGroups[i0].interpolation << endl; \
	}; \
	for (uint i1 = 0; i1 < uvGroups[i0].keys.size(); i1++) { \
		if ( !verbose && ( i1 > MAXARRAYDUMP ) ) { \
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
			break; \
		}; \
		out << "    Keys[" << i1 << "]:  " << uvGroups[i0].keys[i1] << endl; \
	}; \
}; \
return out.str(); \

#define NI_U_V_DATA_FIXLINKS \
NiObject::FixLinks( objects, link_stack, version, user_version ); \

#define NI_U_V_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiObject::GetRefs(); \
return refs; \

#define NI_VECTOR_EXTRA_DATA_MEMBERS \
Vector3 vectorData; \
float unknownFloat; \

#define NI_VECTOR_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_VECTOR_EXTRA_DATA_PARENT NiExtraData \

#define NI_VECTOR_EXTRA_DATA_CONSTRUCT \
 : unknownFloat(0.0f) \

#define NI_VECTOR_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( vectorData, in, version ); \
NifStream( unknownFloat, in, version ); \

#define NI_VECTOR_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( vectorData, out, version ); \
NifStream( unknownFloat, out, version ); \

#define NI_VECTOR_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Vector Data:  " << vectorData << endl; \
out << "Unknown Float:  " << unknownFloat << endl; \
return out.str(); \

#define NI_VECTOR_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_VECTOR_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_VERTEX_COLOR_PROPERTY_MEMBERS \
ushort flags; \
VertMode vertexMode; \
LightMode lightingMode; \

#define NI_VERTEX_COLOR_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_VERTEX_COLOR_PROPERTY_PARENT NiProperty \

#define NI_VERTEX_COLOR_PROPERTY_CONSTRUCT \
 : flags((ushort)0), vertexMode((VertMode)0), lightingMode((LightMode)0) \

#define NI_VERTEX_COLOR_PROPERTY_READ \
NiProperty::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \
NifStream( vertexMode, in, version ); \
NifStream( lightingMode, in, version ); \

#define NI_VERTEX_COLOR_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \
NifStream( vertexMode, out, version ); \
NifStream( lightingMode, out, version ); \

#define NI_VERTEX_COLOR_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
out << "Vertex Mode:  " << vertexMode << endl; \
out << "Lighting Mode:  " << lightingMode << endl; \
return out.str(); \

#define NI_VERTEX_COLOR_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_VERTEX_COLOR_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS \
uint numBytes; \
ushort numVertices; \
vector<float > weight; \

#define NI_VERT_WEIGHTS_EXTRA_DATA_INCLUDE "NiExtraData.h" \

#define NI_VERT_WEIGHTS_EXTRA_DATA_PARENT NiExtraData \

#define NI_VERT_WEIGHTS_EXTRA_DATA_CONSTRUCT \
 : numBytes((uint)0), numVertices((ushort)0) \

#define NI_VERT_WEIGHTS_EXTRA_DATA_READ \
NiExtraData::Read( in, link_stack, version, user_version ); \
NifStream( numBytes, in, version ); \
NifStream( numVertices, in, version ); \
weight.resize(numVertices); \
for (uint i0 = 0; i0 < weight.size(); i0++) { \
	NifStream( weight[i0], in, version ); \
}; \

#define NI_VERT_WEIGHTS_EXTRA_DATA_WRITE \
NiExtraData::Write( out, link_map, version, user_version ); \
NifStream( numBytes, out, version ); \
NifStream( numVertices, out, version ); \
for (uint i0 = 0; i0 < weight.size(); i0++) { \
	NifStream( weight[i0], out, version ); \
}; \

#define NI_VERT_WEIGHTS_EXTRA_DATA_STRING \
stringstream out; \
out << NiExtraData::asString(); \
out << "Num Bytes:  " << numBytes << endl; \
out << "Num Vertices:  " << numVertices << endl; \
for (uint i0 = 0; i0 < weight.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Weight[" << i0 << "]:  " << weight[i0] << endl; \
}; \
return out.str(); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_FIXLINKS \
NiExtraData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_VERT_WEIGHTS_EXTRA_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiExtraData::GetRefs(); \
return refs; \

#define NI_VIS_CONTROLLER_MEMBERS \
Ref<NiVisData > data; \

#define NI_VIS_CONTROLLER_INCLUDE "NiSingleInterpolatorController.h" \

#define NI_VIS_CONTROLLER_PARENT NiSingleInterpolatorController \

#define NI_VIS_CONTROLLER_CONSTRUCT \
 : data(NULL) \

#define NI_VIS_CONTROLLER_READ \
uint block_num; \
NiSingleInterpolatorController::Read( in, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	NifStream( block_num, in, version ); \
	link_stack.push_back( block_num ); \
}; \

#define NI_VIS_CONTROLLER_WRITE \
NiSingleInterpolatorController::Write( out, link_map, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if ( data != NULL ) \
		NifStream( link_map[StaticCast<NiObject>(data)], out, version ); \
	else \
		NifStream( 0xffffffff, out, version ); \
}; \

#define NI_VIS_CONTROLLER_STRING \
stringstream out; \
out << NiSingleInterpolatorController::asString(); \
out << "Data:  " << data << endl; \
return out.str(); \

#define NI_VIS_CONTROLLER_FIXLINKS \
NiSingleInterpolatorController::FixLinks( objects, link_stack, version, user_version ); \
if ( version <= 0x0A010000 ) { \
	if (link_stack.empty()) \
		throw runtime_error("Trying to pop a link from empty stack. This is probably a bug."); \
	if (link_stack.front() != 0xffffffff) { \
		data = DynamicCast<NiVisData>(objects[link_stack.front()]); \
		if ( data == NULL ) \
			throw runtime_error("Link could not be cast to required type during file read. This NIF file may be invalid or improperly understood."); \
	} else \
		data = NULL; \
	link_stack.pop_front(); \
}; \

#define NI_VIS_CONTROLLER_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiSingleInterpolatorController::GetRefs(); \
if ( data != NULL ) \
	refs.push_back(StaticCast<NiObject>(data)); \
return refs; \

#define NI_VIS_DATA_MEMBERS \
uint numVisKeys; \
vector<Key<byte > > visKeys; \

#define NI_VIS_DATA_INCLUDE "AKeyedData.h" \

#define NI_VIS_DATA_PARENT AKeyedData \

#define NI_VIS_DATA_CONSTRUCT \
 : numVisKeys((uint)0) \

#define NI_VIS_DATA_READ \
AKeyedData::Read( in, link_stack, version, user_version ); \
NifStream( numVisKeys, in, version ); \
visKeys.resize(numVisKeys); \
for (uint i0 = 0; i0 < visKeys.size(); i0++) { \
	NifStream( visKeys[i0], in, version, 1 ); \
}; \

#define NI_VIS_DATA_WRITE \
AKeyedData::Write( out, link_map, version, user_version ); \
NifStream( numVisKeys, out, version ); \
for (uint i0 = 0; i0 < visKeys.size(); i0++) { \
	NifStream( visKeys[i0], out, version, 1 ); \
}; \

#define NI_VIS_DATA_STRING \
stringstream out; \
out << AKeyedData::asString(); \
out << "Num Vis Keys:  " << numVisKeys << endl; \
for (uint i0 = 0; i0 < visKeys.size(); i0++) { \
	if ( !verbose && ( i0 > MAXARRAYDUMP ) ) { \
		out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl; \
		break; \
	}; \
	out << "  Vis Keys[" << i0 << "]:  " << visKeys[i0] << endl; \
}; \
return out.str(); \

#define NI_VIS_DATA_FIXLINKS \
AKeyedData::FixLinks( objects, link_stack, version, user_version ); \

#define NI_VIS_DATA_GETREFS \
list<Ref<NiObject> > refs; \
refs = AKeyedData::GetRefs(); \
return refs; \

#define NI_WIREFRAME_PROPERTY_MEMBERS \
ushort flags; \

#define NI_WIREFRAME_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_WIREFRAME_PROPERTY_PARENT NiProperty \

#define NI_WIREFRAME_PROPERTY_CONSTRUCT \
 : flags((ushort)0) \

#define NI_WIREFRAME_PROPERTY_READ \
NiProperty::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \

#define NI_WIREFRAME_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \

#define NI_WIREFRAME_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
return out.str(); \

#define NI_WIREFRAME_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_WIREFRAME_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define NI_Z_BUFFER_PROPERTY_MEMBERS \
ushort flags; \
uint function; \

#define NI_Z_BUFFER_PROPERTY_INCLUDE "NiProperty.h" \

#define NI_Z_BUFFER_PROPERTY_PARENT NiProperty \

#define NI_Z_BUFFER_PROPERTY_CONSTRUCT \
 : flags((ushort)3), function((uint)3) \

#define NI_Z_BUFFER_PROPERTY_READ \
NiProperty::Read( in, link_stack, version, user_version ); \
NifStream( flags, in, version ); \
if ( version >= 0x0401000C ) { \
	NifStream( function, in, version ); \
}; \

#define NI_Z_BUFFER_PROPERTY_WRITE \
NiProperty::Write( out, link_map, version, user_version ); \
NifStream( flags, out, version ); \
if ( version >= 0x0401000C ) { \
	NifStream( function, out, version ); \
}; \

#define NI_Z_BUFFER_PROPERTY_STRING \
stringstream out; \
out << NiProperty::asString(); \
out << "Flags:  " << flags << endl; \
out << "Function:  " << function << endl; \
return out.str(); \

#define NI_Z_BUFFER_PROPERTY_FIXLINKS \
NiProperty::FixLinks( objects, link_stack, version, user_version ); \

#define NI_Z_BUFFER_PROPERTY_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiProperty::GetRefs(); \
return refs; \

#define ROOT_COLLISION_NODE_MEMBERS \

#define ROOT_COLLISION_NODE_INCLUDE "NiNode.h" \

#define ROOT_COLLISION_NODE_PARENT NiNode \

#define ROOT_COLLISION_NODE_CONSTRUCT \

#define ROOT_COLLISION_NODE_READ \
NiNode::Read( in, link_stack, version, user_version ); \

#define ROOT_COLLISION_NODE_WRITE \
NiNode::Write( out, link_map, version, user_version ); \

#define ROOT_COLLISION_NODE_STRING \
stringstream out; \
out << NiNode::asString(); \
return out.str(); \

#define ROOT_COLLISION_NODE_FIXLINKS \
NiNode::FixLinks( objects, link_stack, version, user_version ); \

#define ROOT_COLLISION_NODE_GETREFS \
list<Ref<NiObject> > refs; \
refs = NiNode::GetRefs(); \
return refs; \

#endif
