/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _OBJ_DEFINES_H_
#define _OBJ_DEFINES_H_

#define MAXARRAYDUMP 20

#ifndef SWIG
#define NI_OBJECT_MEMBERS \

#define A_KEYED_DATA_MEMBERS \

#define A_PARTICLE_MODIFIER_MEMBERS \
Ref<AParticleModifier > nextModifier; \
NiParticleSystemController * controller; \

#define BHK_REF_OBJECT_MEMBERS \

#define BHK_SERIALIZABLE_MEMBERS \

#define ABHK_CONSTRAINT_MEMBERS \
mutable unsigned int numBodies; \
vector<bhkShape * > bodies; \
unsigned int priority; \

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

#define BHK_SHAPE_MEMBERS \

#define ABHK_SHAPE_COLLECTION_MEMBERS \

#define BHK_SPHERE_REP_SHAPE_MEMBERS \
HavokMaterial material; \

#define BHK_CONVEX_SHAPE_MEMBERS \

#define BHK_WORLD_OBJECT_MEMBERS \

#define BHK_ENTITY_MEMBERS \
Ref<bhkShape > shape; \
OblivionLayer layer; \
byte colFilter; \
unsigned short unknownShort; \

#define NI_COLLISION_OBJECT_MEMBERS \
NiAVObject * parent; \
unsigned short unknownShort; \
Ref<NiObject > body; \

#define NI_EXTRA_DATA_MEMBERS \
string name; \
Ref<NiExtraData > nextExtraData; \

#define NI_INTERPOLATOR_MEMBERS \

#define NI_BLEND_INTERPOLATOR_MEMBERS \
unsigned short unknownShort; \
unsigned int unknownInt; \

#define NI_B_SPLINE_INTERPOLATOR_MEMBERS \
float startTime; \
float stopTime; \
Ref<NiBSplineData > splineData; \
Ref<NiBSplineBasisData > basisData; \

#define NI_OBJECT_N_E_T_MEMBERS \
string name; \
Ref<NiExtraData > extraData; \
mutable unsigned int numExtraDataList; \
vector<Ref<NiExtraData > > extraDataList; \
Ref<NiTimeController > controller; \

#define NI_A_V_OBJECT_MEMBERS \
unsigned short flags; \
Vector3 translation; \
Matrix33 rotation; \
float scale; \
Vector3 velocity; \
mutable unsigned int numProperties; \
vector<Ref<NiProperty > > properties; \
bool hasBoundingBox; \
BoundingBox boundingBox; \
Ref<NiCollisionData > collisionData; \
Ref<NiCollisionObject > collisionObject; \

#define NI_DYNAMIC_EFFECT_MEMBERS \
bool switchState; \
mutable unsigned int numAffectedNodes; \
vector<unsigned int > affectedNodeListPointers; \
vector<Ref<NiAVObject > > affectedNodes; \

#define NI_LIGHT_MEMBERS \
float dimmer; \
Color3 ambientColor; \
Color3 diffuseColor; \
Color3 specularColor; \

#define NI_PROPERTY_MEMBERS \

#define NI_P_SYS_MODIFIER_MEMBERS \
string name; \
unsigned int order; \
NiParticleSystem * target; \
bool active; \

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

#define NI_P_SYS_VOLUME_EMITTER_MEMBERS \
NiNode * emitterObject; \

#define NI_TIME_CONTROLLER_MEMBERS \
Ref<NiTimeController > nextController; \
unsigned short flags; \
float frequency; \
float phase; \
float startTime; \
float stopTime; \
NiObjectNET * target; \

#define A_BONE_L_O_D_CONTROLLER_MEMBERS \
unsigned int unknownInt1; \
mutable unsigned int numNodeGroups; \
unsigned int numNodeGroups2; \
vector<NodeGroup > nodeGroups; \

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_MEMBERS \
Ref<NiInterpolator > interpolator; \

#define A_P_SYS_CTLR_MEMBERS \
string modifierName; \

#define NI_GEOMETRY_MEMBERS \
Ref<NiGeometryData > data; \
Ref<NiSkinInstance > skinInstance; \
bool hasShader; \
string shaderName; \
Ref<NiObject > unknownLink; \

#define NI_TRI_BASED_GEOM_MEMBERS \

#define NI_GEOMETRY_DATA_MEMBERS \
string name; \
mutable unsigned short numVertices; \
unsigned short unknownShort1; \
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
mutable unsigned short numUvSets; \
bool hasUv; \
vector< vector<TexCoord > > uvSets; \
unsigned short unknownShort2; \
Ref<NiObject > unknownLink; \

#define NI_TRI_BASED_GEOM_DATA_MEMBERS \
unsigned short numTriangles; \

#define A_P_SYS_DATA_MEMBERS \
bool hasUnknownFloats1; \
vector<float > unknownFloats1; \
unsigned short unknownShort3; \
bool hasUnknownFloats2; \
vector<float > unknownFloats2; \
byte hasUnknownFloats3; \
vector< array<4,float > > unknownFloats3; \

#define BHK_BLEND_COLLISION_OBJECT_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \

#define BHK_BLEND_CONTROLLER_MEMBERS \
unsigned int unknownInt; \

#define BHK_BOX_SHAPE_MEMBERS \
float unknownFloat1; \
unsigned short unknownShort1; \
unsigned short unknownShort2; \
unsigned short unknownShort3; \
unsigned short unknownShort4; \
Vector3 dimensions; \
float min_Size; \

#define BHK_CAPSULE_SHAPE_MEMBERS \
float radius; \
unsigned short unknownShort1; \
unsigned short unknownShort2; \
unsigned short unknownShort3; \
unsigned short unknownShort4; \
Vector3 firstPoint; \
float radius1; \
Vector3 secondPoint; \
float radius2; \

#define BHK_COLLISION_OBJECT_MEMBERS \

#define BHK_CONVEX_VERTICES_SHAPE_MEMBERS \
array<7,float > unknownFloats1; \
mutable unsigned int numVertices; \
vector<Float4 > vertices; \
mutable unsigned int numNormals; \
vector<Float4 > normals; \

#define BHK_HINGE_CONSTRAINT_MEMBERS \
array< 5, array<4,float > > unknownFloats; \

#define BHK_LIMITED_HINGE_CONSTRAINT_MEMBERS \
LimitedHingeDescriptor limitedHinge; \

#define BHK_LIST_SHAPE_MEMBERS \
mutable unsigned int numSubShapes; \
vector<Ref<bhkShape > > subShapes; \
HavokMaterial material; \
array<6,float > unknownFloats; \
mutable unsigned int numUnknownInts; \
vector<unsigned int > unknownInts; \

#define BHK_MALLEABLE_CONSTRAINT_MEMBERS \
unsigned int type; \
unsigned int unknownInt2; \
Ref<NiObject > unknownLink1; \
Ref<NiObject > unknownLink2; \
unsigned int unknownInt3; \
RagDollDescriptor ragdoll; \
LimitedHingeDescriptor limitedHinge; \
float tau; \
float damping; \

#define BHK_MOPP_BV_TREE_SHAPE_MEMBERS \
Ref<bhkShape > shape; \
HavokMaterial material; \
array<8,byte > unknownBytes1; \
float unknownFloat; \
mutable unsigned int numUnknownBytes2; \
vector<byte > unknownBytes2; \
Vector3 unknownVector; \
float unknownFloat2; \

#define BHK_MULTI_SPHERE_SHAPE_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
mutable unsigned int numSpheres; \
vector<Sphere > spheres; \

#define BHK_NI_TRI_STRIPS_SHAPE_MEMBERS \
float unknownFloat1; \
unsigned int unknownInt1; \
array<4,unsigned int > unknownInts1; \
unsigned int unknownInt2; \
Vector3 scale; \
unsigned int unknownInt3; \
mutable unsigned int numStripsData; \
vector<Ref<NiTriStripsData > > stripsData; \
mutable unsigned int numDataLayers; \
vector<OblivionColFilter > dataLayers; \

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_MEMBERS \
mutable unsigned short numSubShapes; \
vector<OblivionSubShape > subShapes; \
array<9,float > unknownFloats; \
float scale; \
array<3,float > unknownFloats2; \
Ref<hkPackedNiTriStripsData > data; \

#define BHK_PRISMATIC_CONSTRAINT_MEMBERS \
array<8,Float4 > unknownVectors; \
array<3,float > unknownFloats2; \

#define BHK_RAGDOLL_CONSTRAINT_MEMBERS \

#define BHK_RIGID_BODY_MEMBERS \
array<5,float > unknown5Floats; \
array<4,unsigned short > unknown4Shorts; \
OblivionLayer layerCopy; \
byte colFilterCopy; \
array<7,unsigned short > unknown7Shorts; \
Vector3 translation; \
float unknownFloat00; \
QuaternionXYZW rotation; \
Vector3 linearVelocity; \
float unknownFloat01; \
Vector3 angularVelocity; \
float unknownFloat02; \
array<12,float > transform; \
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
MotionSystem motionSystem; \
byte unknownByte1; \
byte unknownByte2; \
MotionQuality qualityType; \
unsigned int unknownInt6; \
unsigned int unknownInt7; \
unsigned int unknownInt8; \
mutable unsigned int numConstraints; \
vector<Ref<AbhkConstraint > > constraints; \

#define BHK_RIGID_BODY_T_MEMBERS \

#define BHK_SIMPLE_SHAPE_PHANTOM_MEMBERS \
array<7,float > unkownFloats; \
array< 3, array<5,float > > unknownFloats2; \
float unknownFloat; \

#define BHK_S_P_COLLISION_OBJECT_MEMBERS \

#define BHK_SPHERE_SHAPE_MEMBERS \
float radius; \

#define BHK_STIFF_SPRING_CONSTRAINT_MEMBERS \
array< 2, array<4,float > > unknownFloats; \
float unknownFloat; \

#define BHK_TRANSFORM_SHAPE_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
Matrix44 transform; \

#define BHK_CONVEX_TRANSFORM_SHAPE_MEMBERS \

#define B_S_BOUND_MEMBERS \
Vector3 center; \
Vector3 dimensions; \

#define B_S_FURNITURE_MARKER_MEMBERS \
mutable unsigned int numPositions; \
vector<FurniturePosition > positions; \

#define B_S_PARENT_VELOCITY_MODIFIER_MEMBERS \
float unknownFloat; \

#define B_S_P_SYS_ARRAY_EMITTER_MEMBERS \

#define B_S_X_FLAGS_MEMBERS \
unsigned int flags; \

#define HK_PACKED_NI_TRI_STRIPS_DATA_MEMBERS \
mutable unsigned int numTriangles; \
vector<hkTriangle > triangles; \
mutable unsigned int numVertices; \
vector<Vector3 > vertices; \

#define NI_ALPHA_CONTROLLER_MEMBERS \
Ref<NiFloatData > data; \

#define NI_ALPHA_PROPERTY_MEMBERS \
unsigned short flags; \
byte threshold; \

#define NI_AMBIENT_LIGHT_MEMBERS \

#define NI_AUTO_NORMAL_PARTICLES_DATA_MEMBERS \
unsigned short numParticles; \
float size; \
unsigned short numActive; \
unsigned short unknownShort; \
bool hasSizes; \
vector<float > sizes; \

#define NI_BINARY_EXTRA_DATA_MEMBERS \
ByteArray binaryData; \

#define NI_BLEND_BOOL_INTERPOLATOR_MEMBERS \
byte boolValue; \

#define NI_BLEND_FLOAT_INTERPOLATOR_MEMBERS \
float floatValue; \

#define NI_BLEND_POINT3_INTERPOLATOR_MEMBERS \
Vector3 pointValue; \

#define NI_BLEND_TRANSFORM_INTERPOLATOR_MEMBERS \

#define NI_BONE_L_O_D_CONTROLLER_MEMBERS \
mutable unsigned int numShapeGroups; \
vector<SkinShapeGroup > shapeGroups1; \
mutable unsigned int numShapeGroups2; \
vector<Ref<NiTriShape > > shapeGroups2; \

#define NI_BOOL_DATA_MEMBERS \
KeyGroup<byte > data; \

#define NI_BOOLEAN_EXTRA_DATA_MEMBERS \
byte booleanData; \

#define NI_BOOL_INTERPOLATOR_MEMBERS \
bool boolValue; \
Ref<NiBoolData > data; \

#define NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS \
byte boolValue; \
Ref<NiBoolData > data; \

#define NI_B_S_BONE_L_O_D_CONTROLLER_MEMBERS \

#define NI_B_SPLINE_BASIS_DATA_MEMBERS \
unsigned int numControlPt; \

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_MEMBERS \
array<4,float > unknownFloats; \

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_MEMBERS \
array<6,float > unknownFloats; \

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS \
Vector3 translation; \
Quaternion rotation; \
float scale; \
unsigned int translateOffset; \
unsigned int rotateOffset; \
unsigned int scaleOffset; \
float translateBias; \
float translateMultiplier; \
float rotationBias; \
float rotationMultiplier; \
float scaleBias; \
float scaleMultiplier; \

#define NI_B_SPLINE_DATA_MEMBERS \
unsigned int unknownInt; \
mutable unsigned int count; \
vector<short > controlPoints; \

#define NI_CAMERA_MEMBERS \
unsigned short unknownShort; \
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
unsigned int unknownInt; \
unsigned int unknownInt2; \

#define NI_COLLISION_DATA_MEMBERS \
NiNode * targetNode; \
unsigned int unknownInt1; \
unsigned int unknownInt2; \
byte unknownByte; \
unsigned int collisionType; \
Vector3 unknownVector; \
array<8,float > unknownFloat1; \
array<15,float > unknownFloat2; \

#define NI_COLOR_DATA_MEMBERS \
KeyGroup<Color4 > data; \

#define NI_COLOR_EXTRA_DATA_MEMBERS \
Color4 data; \

#define NI_CONTROLLER_MANAGER_MEMBERS \
bool cumulative; \
mutable unsigned int numControllerSequences; \
vector<Ref<NiControllerSequence > > controllerSequences; \
Ref<NiDefaultAVObjectPalette > objectPalette; \

#define NI_CONTROLLER_SEQUENCE_MEMBERS \
string name; \
string textKeysName; \
Ref<NiTextKeyExtraData > textKeys; \
mutable unsigned int numControlledBlocks; \
unsigned int unknownInt1; \
vector<ControllerLink > controlledBlocks; \
float weight; \
CycleType cycleType; \
unsigned int unknownInt0; \
float frequency; \
float startTime; \
float stopTime; \
float unknownFloat2; \
byte unknownByte; \
NiControllerManager * manager; \
string targetName; \
Ref<NiStringPalette > stringPalette; \

#define NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS \
unsigned int unknownInt; \
mutable unsigned int numObjs; \
vector<AVObject > objs; \

#define NI_DIRECTIONAL_LIGHT_MEMBERS \

#define NI_DITHER_PROPERTY_MEMBERS \
unsigned short flags; \

#define NI_FLIP_CONTROLLER_MEMBERS \
unsigned int textureSlot; \
unsigned int unknownInt2; \
float delta; \
mutable unsigned int numSources; \
vector<Ref<NiSourceTexture > > sources; \

#define NI_FLOAT_DATA_MEMBERS \
KeyGroup<float > data; \

#define NI_FLOAT_EXTRA_DATA_MEMBERS \
float floatData; \

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_MEMBERS \
Ref<NiObject > unknownLink; \
string unknownString; \

#define NI_FLOAT_INTERPOLATOR_MEMBERS \
float floatValue; \
Ref<NiFloatData > data; \

#define NI_FLOATS_EXTRA_DATA_MEMBERS \
mutable unsigned int numFloats; \
vector<float > data; \

#define NI_FOG_PROPERTY_MEMBERS \
unsigned short flags; \
float fogDepth; \
Color3 fogColor; \

#define NI_GEOM_MORPHER_CONTROLLER_MEMBERS \
unsigned short unknown; \
byte unknown2; \
Ref<NiMorphData > data; \
byte unknownByte; \
mutable unsigned int numInterpolators; \
vector<Ref<NiInterpolator > > interpolators; \
mutable unsigned int numUnknownInts; \
vector<unsigned int > unknownInts; \

#define NI_GRAVITY_MEMBERS \
float unknownFloat1; \
float force; \
FieldType type; \
Vector3 position; \
Vector3 direction; \

#define NI_INTEGER_EXTRA_DATA_MEMBERS \
unsigned int integerData; \

#define NI_INTEGERS_EXTRA_DATA_MEMBERS \
mutable unsigned int numIntegers; \
vector<unsigned int > data; \

#define NI_KEYFRAME_CONTROLLER_MEMBERS \
Ref<NiKeyframeData > data; \

#define B_S_KEYFRAME_CONTROLLER_MEMBERS \
Ref<NiKeyframeData > data2; \

#define NI_KEYFRAME_DATA_MEMBERS \
mutable unsigned int numRotationKeys; \
KeyType rotationType; \
vector<Key<Quaternion > > quaternionKeys; \
float unknownFloat; \
array<3,KeyGroup<float > > xyzRotations; \
KeyGroup<Vector3 > translations; \
KeyGroup<float > scales; \

#define NI_LIGHT_COLOR_CONTROLLER_MEMBERS \
unsigned short unknownShort; \
Ref<NiPosData > data; \
Ref<NiPoint3Interpolator > interpolator; \

#define NI_LIGHT_DIMMER_CONTROLLER_MEMBERS \
Ref<NiInterpolator > unknownLink; \

#define NI_LOOK_AT_CONTROLLER_MEMBERS \
unsigned short unknown1; \
Ref<NiNode > lookAtNode; \

#define NI_LOOK_AT_INTERPOLATOR_MEMBERS \
unsigned short unknownShort; \
Ref<NiNode > lookAt; \
float unknownFloat; \
Vector3 translation; \
Quaternion rotation; \
float scale; \
Ref<NiPoint3Interpolator > unknownLink1; \
Ref<NiFloatInterpolator > unknownLink2; \
Ref<NiFloatInterpolator > unknownLink3; \

#define NI_MATERIAL_COLOR_CONTROLLER_MEMBERS \
unsigned short targetColor; \
Ref<NiPosData > data; \

#define NI_MATERIAL_PROPERTY_MEMBERS \
unsigned short flags; \
Color3 ambientColor; \
Color3 diffuseColor; \
Color3 specularColor; \
Color3 emissiveColor; \
float glossiness; \
float alpha; \

#define NI_MESH_P_SYS_DATA_MEMBERS \
byte unknownByte11; \
vector< array<10,float > > unknownFloats4; \
vector< array<12,float > > unknownFloats5; \
unsigned int unknownInt1; \
Ref<NiObject > modifier; \
byte unknownByte2; \
mutable unsigned int numUnknownLinks; \
vector<Ref<NiObject > > unknownLinks; \
unsigned short unknownShort4; \
unsigned int unknownInt2; \
byte unknownByte12; \
unsigned int unknownInt3; \
unsigned int unknownInt4; \
Ref<NiNode > unknownLink2; \

#define NI_MORPH_DATA_MEMBERS \
mutable unsigned int numMorphs; \
unsigned int numVertices; \
byte unknownByte; \
vector<Morph > morphs; \

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_MEMBERS \
mutable unsigned short numExtraTargets; \
vector<NiNode * > extraTargets; \

#define NI_NODE_MEMBERS \
mutable unsigned int numChildren; \
vector<Ref<NiAVObject > > children; \
mutable unsigned int numEffects; \
vector<Ref<NiDynamicEffect > > effects; \

#define AVOID_NODE_MEMBERS \

#define FX_WIDGET_MEMBERS \
byte unknown1; \
array<292,byte > unknown292Bytes; \

#define FX_BUTTON_MEMBERS \

#define FX_RADIO_BUTTON_MEMBERS \
unsigned int unknownInt1; \
unsigned int unknownInt2; \
unsigned int unknownInt3; \
mutable unsigned int numButtons; \
vector<FxRadioButton * > buttons; \

#define NI_BILLBOARD_NODE_MEMBERS \
BillboardMode billboardMode; \

#define NI_B_S_ANIMATION_NODE_MEMBERS \

#define NI_B_S_PARTICLE_NODE_MEMBERS \

#define NI_L_O_D_NODE_MEMBERS \
array<4,byte > unknown4Bytes; \
Vector3 lodCenter; \
mutable unsigned int numLodLevels; \
vector<LODRange > lodLevels; \
unsigned short unknownShort; \
Ref<NiLODData > lodLevelData; \

#define NI_PALETTE_MEMBERS \
byte unknownByte; \
unsigned int numEntries_; \
array< 256, array<4,byte > > palette; \

#define NI_PARTICLE_BOMB_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \
unsigned int unknownInt1; \
unsigned int unknownInt2; \
float unknownFloat5; \
float unknownFloat6; \
float unknownFloat7; \
float unknownFloat8; \
float unknownFloat9; \
float unknownFloat10; \

#define NI_PARTICLE_COLOR_MODIFIER_MEMBERS \
Ref<NiColorData > colorData; \

#define NI_PARTICLE_GROW_FADE_MEMBERS \
float grow; \
float fade; \

#define NI_PARTICLE_MESH_MODIFIER_MEMBERS \
mutable unsigned int numParticleMeshes; \
vector<Ref<NiAVObject > > particleMeshes; \

#define NI_PARTICLE_ROTATION_MEMBERS \
byte unknownByte; \
float unknownFloat1; \
float unknownFloat2; \
float unknownFloat3; \
float unknownFloat4; \

#define NI_PARTICLES_MEMBERS \

#define NI_AUTO_NORMAL_PARTICLES_MEMBERS \

#define NI_PARTICLE_MESHES_MEMBERS \

#define NI_PARTICLES_DATA_MEMBERS \
unsigned short numActive; \
bool hasUnknownFloats; \
vector<float > unknownFloats; \
bool hasRotations; \
vector<Quaternion > rotations; \

#define NI_PARTICLE_MESHES_DATA_MEMBERS \
Ref<NiAVObject > unknownLink2; \

#define NI_PARTICLE_SYSTEM_MEMBERS \
bool unknownBool; \
mutable unsigned int numModifiers; \
vector<Ref<NiPSysModifier > > modifiers; \

#define NI_MESH_PARTICLE_SYSTEM_MEMBERS \

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
unsigned short emitFlags; \
Vector3 startRandom; \
NiObject * emitter; \
unsigned short unknownShort2_; \
float unknownFloat13_; \
unsigned int unknownInt1_; \
unsigned int unknownInt2_; \
unsigned short unknownShort3_; \
mutable unsigned short numParticles; \
unsigned short numValid; \
vector<Particle > particles; \
Ref<NiObject > unknownLink; \
Ref<AParticleModifier > particleExtra; \
Ref<NiObject > unknownLink2; \
byte trailer; \

#define NI_B_S_P_ARRAY_CONTROLLER_MEMBERS \

#define NI_PATH_CONTROLLER_MEMBERS \
unsigned short unknownShort2; \
unsigned int unknownInt1; \
unsigned int unknownInt2; \
unsigned int unknownInt3; \
unsigned short unknownShort; \
Ref<NiPosData > posData; \
Ref<NiFloatData > floatData; \

#define NI_PATH_INTERPOLATOR_MEMBERS \
float unknownFloat1; \
float unknownFloat2; \
unsigned short unknownShort2; \
Ref<NiPosData > posData; \
Ref<NiFloatData > floatData; \

#define NI_PIXEL_DATA_MEMBERS \
PixelFormat pixelFormat; \
unsigned int redMask; \
unsigned int greenMask; \
unsigned int blueMask; \
unsigned int alphaMask; \
unsigned int bitsPerPixel; \
array<8,byte > unknown8Bytes; \
unsigned int unknownInt; \
array<54,byte > unknown54Bytes; \
Ref<NiPalette > palette; \
mutable unsigned int numMipmaps; \
unsigned int bytesPerPixel; \
vector<MipMap > mipmaps; \
ByteArray pixelData; \
unsigned int unknownInt2; \

#define NI_PLANAR_COLLIDER_MEMBERS \
unsigned short unknownShort; \
float unknownFloat1; \
float unknownFloat2; \
unsigned short unknownShort2; \
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

#define NI_POINT3_INTERPOLATOR_MEMBERS \
Vector3 point3Value; \
Ref<NiPosData > data; \

#define NI_POINT_LIGHT_MEMBERS \
float constantAttenuation; \
float linearAttenuation; \
float quadraticAttenuation; \

#define NI_POS_DATA_MEMBERS \
KeyGroup<Vector3 > data; \

#define NI_P_SYS_AGE_DEATH_MODIFIER_MEMBERS \
bool spawnOnDeath; \
Ref<NiPSysSpawnModifier > spawnModifier; \

#define NI_P_SYS_BOMB_MODIFIER_MEMBERS \
NiNode * unknownLink; \
array<2,unsigned int > unknownInts1; \
array<3,float > unknownFloats; \
array<2,unsigned int > unknownInts2; \

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_MEMBERS \
unsigned short updateSkip; \

#define NI_P_SYS_BOX_EMITTER_MEMBERS \
float width; \
float height; \
float depth; \

#define NI_P_SYS_COLLIDER_MANAGER_MEMBERS \
Ref<NiPSysPlanarCollider > collider; \

#define NI_P_SYS_COLOR_MODIFIER_MEMBERS \
Ref<NiColorData > data; \

#define NI_P_SYS_CYLINDER_EMITTER_MEMBERS \
float radius; \
float height; \

#define NI_P_SYS_DATA_MEMBERS \
vector< array<10,float > > unknownFloats4; \
bool unknownBool1; \
vector< array<32,byte > > unknownBytes; \
vector< array<28,byte > > unknownBytesAlt; \
byte unknownByte3; \
bool unknownBool2; \
vector< array<4,byte > > unknownBytes2; \
unsigned int unknownInt1; \

#define NI_P_SYS_DRAG_MODIFIER_MEMBERS \
NiObject * parent; \
Vector3 dragAxis; \
float percentage; \
float range; \
float rangeFalloff; \

#define NI_P_SYS_EMITTER_CTLR_MEMBERS \
Ref<NiPSysEmitterCtlrData > data; \
Ref<NiInterpolator > visibilityInterpolator; \

#define NI_P_SYS_EMITTER_CTLR_DATA_MEMBERS \
KeyGroup<float > floatKeys_; \
mutable unsigned int numVisibilityKeys_; \
vector<Key<byte > > visibilityKeys_; \

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_MEMBERS \

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_MEMBERS \
Ref<NiFloatData > unknownLink; \

#define NI_P_SYS_EMITTER_SPEED_CTLR_MEMBERS \
Ref<NiFloatData > unknownLink; \

#define NI_P_SYS_GRAVITY_MODIFIER_MEMBERS \
NiNode * gravityObject; \
Vector3 gravityAxis; \
float decay; \
float strength; \
ForceType forceType; \
float turbulence; \
float turbulenceScale; \

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_MEMBERS \
Ref<NiFloatData > unknownLink; \

#define NI_P_SYS_GROW_FADE_MODIFIER_MEMBERS \
float growTime; \
unsigned short growGeneration; \
float fadeTime; \
unsigned short fadeGeneration; \

#define NI_P_SYS_MESH_EMITTER_MEMBERS \
mutable unsigned int numEmitterMeshes; \
vector<Ref<NiTriBasedGeom > > emitterMeshes; \
unsigned int initialVelocityType; \
unsigned int emissionType; \
Vector3 emissionAxis; \

#define NI_P_SYS_MESH_UPDATE_MODIFIER_MEMBERS \
mutable unsigned int numMeshes; \
vector<Ref<NiNode > > meshes; \

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_MEMBERS \
unsigned int unknownInt; \

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

#define NI_P_SYS_POSITION_MODIFIER_MEMBERS \

#define NI_P_SYS_RESET_ON_LOOP_CTLR_MEMBERS \

#define NI_P_SYS_ROTATION_MODIFIER_MEMBERS \
float initialRotationSpeed; \
float initialRotationSpeedVariation; \
float initialRotationAngle; \
float initialRotationAngleVariation; \
bool randomRotSpeedSign; \
bool randomInitialAxis; \
Vector3 initialAxis; \

#define NI_P_SYS_SPAWN_MODIFIER_MEMBERS \
unsigned short numSpawnGenerations; \
float percentageSpawned; \
unsigned short minNumToSpawn; \
unsigned short maxNumToSpawn; \
float spawnSpeedChaos; \
float spawnDirChaos; \
float lifeSpan; \
float lifeSpanVariation; \

#define NI_P_SYS_SPHERE_EMITTER_MEMBERS \
float radius; \

#define NI_P_SYS_UPDATE_CTLR_MEMBERS \

#define NI_L_O_D_DATA_MEMBERS \

#define NI_RANGE_L_O_D_DATA_MEMBERS \
Vector3 lodCenter; \
mutable unsigned int numLodLevels; \
vector<LODRange > lodLevels; \

#define NI_SCREEN_L_O_D_DATA_MEMBERS \
Vector3 boundCenter; \
float boundRadius; \
Vector3 worldCenter; \
float worldRadius; \
mutable unsigned int proportionCount; \
vector<float > proportionLevels; \

#define NI_ROTATING_PARTICLES_MEMBERS \

#define NI_ROTATING_PARTICLES_DATA_MEMBERS \

#define NI_SEQUENCE_STREAM_HELPER_MEMBERS \

#define NI_SHADE_PROPERTY_MEMBERS \
unsigned short flags; \

#define NI_SKIN_DATA_MEMBERS \
Matrix33 rotation; \
Vector3 translation; \
float scale; \
mutable unsigned int numBones; \
Ref<NiSkinPartition > skinPartition; \
byte unknownByte; \
vector<SkinData > boneList; \

#define NI_SKIN_INSTANCE_MEMBERS \
Ref<NiSkinData > data; \
Ref<NiSkinPartition > skinPartition; \
NiNode * skeletonRoot; \
mutable unsigned int numBones; \
vector<NiNode * > bones; \

#define NI_CLOD_SKIN_INSTANCE_MEMBERS \

#define NI_SKIN_PARTITION_MEMBERS \
mutable unsigned int numSkinPartitionBlocks; \
vector<SkinPartition > skinPartitionBlocks; \

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

#define NI_SPECULAR_PROPERTY_MEMBERS \
unsigned short flags; \

#define NI_SPHERICAL_COLLIDER_MEMBERS \
float unknownFloat1; \
unsigned short unknownShort1; \
float unknownFloat2; \
unsigned short unknownShort2; \
float unknownFloat3; \
float unknownFloat4; \
float unknownFloat5; \

#define NI_SPOT_LIGHT_MEMBERS \
float cutoffAngle; \
float exponent; \

#define NI_STENCIL_PROPERTY_MEMBERS \
unsigned short flags; \
byte stencilEnabled; \
CompareMode stencilFunction; \
unsigned int stencilRef; \
unsigned int stencilMask; \
StencilAction failAction; \
StencilAction zFailAction; \
StencilAction passAction; \
FaceDrawMode drawMode; \

#define NI_STRING_EXTRA_DATA_MEMBERS \
unsigned int bytesRemaining; \
string stringData; \

#define NI_STRING_PALETTE_MEMBERS \
StringPalette palette; \

#define NI_STRINGS_EXTRA_DATA_MEMBERS \
mutable unsigned int numStrings; \
vector<string > data; \

#define NI_TEXT_KEY_EXTRA_DATA_MEMBERS \
unsigned int unknownInt1; \
mutable unsigned int numTextKeys; \
vector<Key<string > > textKeys; \

#define NI_TEXTURE_EFFECT_MEMBERS \
Matrix33 modelProjectionMatrix; \
Vector3 modelProjectionTransform; \
TexFilterMode textureFiltering; \
TexClampMode textureClamping; \
unsigned int textureType; \
unsigned int coordinateGenerationType; \
Ref<NiSourceTexture > sourceTexture; \
byte clippingPlane; \
Vector3 unknownVector; \
float unknownFloat; \
unsigned short ps2L; \
unsigned short ps2K; \
unsigned short unknownShort; \

#define NI_TEXTURE_TRANSFORM_CONTROLLER_MEMBERS \
byte unknown2; \
TexType textureSlot; \
unsigned int operation; \
Ref<NiFloatData > data; \

#define NI_TEXTURE_MODE_PROPERTY_MEMBERS \
array<3,short > unknown3Shorts; \

#define NI_IMAGE_MEMBERS \
byte external_; \
string file; \
array<4,short > unknown4Shorts; \

#define NI_TEXTURE_PROPERTY_MEMBERS \
unsigned short flags; \
Ref<NiImage > image; \

#define NI_TEXTURING_PROPERTY_MEMBERS \
unsigned short flags; \
ApplyMode applyMode; \
unsigned int textureCount; \
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
bool hasDecal2Texture; \
TexDesc decal2Texture; \
bool hasDecal3Texture; \
TexDesc decal3Texture; \
mutable unsigned int numShaderTextures; \
vector<ShaderTexDesc > shaderTextures; \

#define NI_TRANSFORM_CONTROLLER_MEMBERS \

#define NI_TRANSFORM_DATA_MEMBERS \

#define NI_TRANSFORM_INTERPOLATOR_MEMBERS \
Vector3 translation; \
Quaternion rotation; \
float scale; \
array<3,byte > unknownBytes; \
Ref<NiTransformData > data; \

#define NI_TRI_SHAPE_MEMBERS \

#define NI_TRI_SHAPE_DATA_MEMBERS \
unsigned int numTrianglePoints; \
bool hasTriangles; \
vector<Triangle > triangles; \
mutable unsigned short numMatchGroups; \
vector<MatchGroup > matchGroups; \

#define NI_TRI_STRIPS_MEMBERS \

#define NI_TRI_STRIPS_DATA_MEMBERS \
mutable unsigned short numStrips; \
mutable vector<unsigned short > stripLengths; \
bool hasPoints; \
vector< vector<unsigned short > > points; \

#define NI_CLOD_MEMBERS \

#define NI_CLOD_DATA_MEMBERS \
unsigned short unknownShorts; \
mutable unsigned short unknownCount1; \
mutable unsigned short unknownCount2; \
mutable unsigned short unknownCount3; \
float unknownFloat; \
unsigned short unknownShort; \
vector< array<6,unsigned short > > unknownClodShorts1; \
vector<unsigned short > unknownClodShorts2; \
vector< array<6,unsigned short > > unknownClodShorts3; \

#define NI_U_V_CONTROLLER_MEMBERS \
unsigned short unknownShort; \
Ref<NiUVData > data; \

#define NI_U_V_DATA_MEMBERS \
array<4,KeyGroup<float > > uvGroups; \

#define NI_VECTOR_EXTRA_DATA_MEMBERS \
Vector3 vectorData; \
float unknownFloat; \

#define NI_VERTEX_COLOR_PROPERTY_MEMBERS \
unsigned short flags; \
VertMode vertexMode; \
LightMode lightingMode; \

#define NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS \
unsigned int numBytes; \
mutable unsigned short numVertices; \
vector<float > weight; \

#define NI_VIS_CONTROLLER_MEMBERS \
Ref<NiVisData > data; \

#define NI_VIS_DATA_MEMBERS \
mutable unsigned int numVisKeys; \
vector<Key<byte > > visKeys; \

#define NI_WIREFRAME_PROPERTY_MEMBERS \
unsigned short flags; \

#define NI_Z_BUFFER_PROPERTY_MEMBERS \
unsigned short flags; \
CompareMode function; \

#define ROOT_COLLISION_NODE_MEMBERS \

#else
#define NI_OBJECT_MEMBERS
#define A_KEYED_DATA_MEMBERS
#define A_PARTICLE_MODIFIER_MEMBERS
#define BHK_REF_OBJECT_MEMBERS
#define BHK_SERIALIZABLE_MEMBERS
#define ABHK_CONSTRAINT_MEMBERS
#define ABHK_RAGDOLL_CONSTRAINT_MEMBERS
#define BHK_SHAPE_MEMBERS
#define ABHK_SHAPE_COLLECTION_MEMBERS
#define BHK_SPHERE_REP_SHAPE_MEMBERS
#define BHK_CONVEX_SHAPE_MEMBERS
#define BHK_WORLD_OBJECT_MEMBERS
#define BHK_ENTITY_MEMBERS
#define NI_COLLISION_OBJECT_MEMBERS
#define NI_EXTRA_DATA_MEMBERS
#define NI_INTERPOLATOR_MEMBERS
#define NI_BLEND_INTERPOLATOR_MEMBERS
#define NI_B_SPLINE_INTERPOLATOR_MEMBERS
#define NI_OBJECT_N_E_T_MEMBERS
#define NI_A_V_OBJECT_MEMBERS
#define NI_DYNAMIC_EFFECT_MEMBERS
#define NI_LIGHT_MEMBERS
#define NI_PROPERTY_MEMBERS
#define NI_P_SYS_MODIFIER_MEMBERS
#define NI_P_SYS_EMITTER_MEMBERS
#define NI_P_SYS_VOLUME_EMITTER_MEMBERS
#define NI_TIME_CONTROLLER_MEMBERS
#define A_BONE_L_O_D_CONTROLLER_MEMBERS
#define NI_SINGLE_INTERPOLATOR_CONTROLLER_MEMBERS
#define A_P_SYS_CTLR_MEMBERS
#define NI_GEOMETRY_MEMBERS
#define NI_TRI_BASED_GEOM_MEMBERS
#define NI_GEOMETRY_DATA_MEMBERS
#define NI_TRI_BASED_GEOM_DATA_MEMBERS
#define A_P_SYS_DATA_MEMBERS
#define BHK_BLEND_COLLISION_OBJECT_MEMBERS
#define BHK_BLEND_CONTROLLER_MEMBERS
#define BHK_BOX_SHAPE_MEMBERS
#define BHK_CAPSULE_SHAPE_MEMBERS
#define BHK_COLLISION_OBJECT_MEMBERS
#define BHK_CONVEX_VERTICES_SHAPE_MEMBERS
#define BHK_HINGE_CONSTRAINT_MEMBERS
#define BHK_LIMITED_HINGE_CONSTRAINT_MEMBERS
#define BHK_LIST_SHAPE_MEMBERS
#define BHK_MALLEABLE_CONSTRAINT_MEMBERS
#define BHK_MOPP_BV_TREE_SHAPE_MEMBERS
#define BHK_MULTI_SPHERE_SHAPE_MEMBERS
#define BHK_NI_TRI_STRIPS_SHAPE_MEMBERS
#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_MEMBERS
#define BHK_PRISMATIC_CONSTRAINT_MEMBERS
#define BHK_RAGDOLL_CONSTRAINT_MEMBERS
#define BHK_RIGID_BODY_MEMBERS
#define BHK_RIGID_BODY_T_MEMBERS
#define BHK_SIMPLE_SHAPE_PHANTOM_MEMBERS
#define BHK_S_P_COLLISION_OBJECT_MEMBERS
#define BHK_SPHERE_SHAPE_MEMBERS
#define BHK_STIFF_SPRING_CONSTRAINT_MEMBERS
#define BHK_TRANSFORM_SHAPE_MEMBERS
#define BHK_CONVEX_TRANSFORM_SHAPE_MEMBERS
#define B_S_BOUND_MEMBERS
#define B_S_FURNITURE_MARKER_MEMBERS
#define B_S_PARENT_VELOCITY_MODIFIER_MEMBERS
#define B_S_P_SYS_ARRAY_EMITTER_MEMBERS
#define B_S_X_FLAGS_MEMBERS
#define HK_PACKED_NI_TRI_STRIPS_DATA_MEMBERS
#define NI_ALPHA_CONTROLLER_MEMBERS
#define NI_ALPHA_PROPERTY_MEMBERS
#define NI_AMBIENT_LIGHT_MEMBERS
#define NI_AUTO_NORMAL_PARTICLES_DATA_MEMBERS
#define NI_BINARY_EXTRA_DATA_MEMBERS
#define NI_BLEND_BOOL_INTERPOLATOR_MEMBERS
#define NI_BLEND_FLOAT_INTERPOLATOR_MEMBERS
#define NI_BLEND_POINT3_INTERPOLATOR_MEMBERS
#define NI_BLEND_TRANSFORM_INTERPOLATOR_MEMBERS
#define NI_BONE_L_O_D_CONTROLLER_MEMBERS
#define NI_BOOL_DATA_MEMBERS
#define NI_BOOLEAN_EXTRA_DATA_MEMBERS
#define NI_BOOL_INTERPOLATOR_MEMBERS
#define NI_BOOL_TIMELINE_INTERPOLATOR_MEMBERS
#define NI_B_S_BONE_L_O_D_CONTROLLER_MEMBERS
#define NI_B_SPLINE_BASIS_DATA_MEMBERS
#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_MEMBERS
#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_MEMBERS
#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_MEMBERS
#define NI_B_SPLINE_DATA_MEMBERS
#define NI_CAMERA_MEMBERS
#define NI_COLLISION_DATA_MEMBERS
#define NI_COLOR_DATA_MEMBERS
#define NI_COLOR_EXTRA_DATA_MEMBERS
#define NI_CONTROLLER_MANAGER_MEMBERS
#define NI_CONTROLLER_SEQUENCE_MEMBERS
#define NI_DEFAULT_A_V_OBJECT_PALETTE_MEMBERS
#define NI_DIRECTIONAL_LIGHT_MEMBERS
#define NI_DITHER_PROPERTY_MEMBERS
#define NI_FLIP_CONTROLLER_MEMBERS
#define NI_FLOAT_DATA_MEMBERS
#define NI_FLOAT_EXTRA_DATA_MEMBERS
#define NI_FLOAT_EXTRA_DATA_CONTROLLER_MEMBERS
#define NI_FLOAT_INTERPOLATOR_MEMBERS
#define NI_FLOATS_EXTRA_DATA_MEMBERS
#define NI_FOG_PROPERTY_MEMBERS
#define NI_GEOM_MORPHER_CONTROLLER_MEMBERS
#define NI_GRAVITY_MEMBERS
#define NI_INTEGER_EXTRA_DATA_MEMBERS
#define NI_INTEGERS_EXTRA_DATA_MEMBERS
#define NI_KEYFRAME_CONTROLLER_MEMBERS
#define B_S_KEYFRAME_CONTROLLER_MEMBERS
#define NI_KEYFRAME_DATA_MEMBERS
#define NI_LIGHT_COLOR_CONTROLLER_MEMBERS
#define NI_LIGHT_DIMMER_CONTROLLER_MEMBERS
#define NI_LOOK_AT_CONTROLLER_MEMBERS
#define NI_LOOK_AT_INTERPOLATOR_MEMBERS
#define NI_MATERIAL_COLOR_CONTROLLER_MEMBERS
#define NI_MATERIAL_PROPERTY_MEMBERS
#define NI_MESH_P_SYS_DATA_MEMBERS
#define NI_MORPH_DATA_MEMBERS
#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_MEMBERS
#define NI_NODE_MEMBERS
#define AVOID_NODE_MEMBERS
#define FX_WIDGET_MEMBERS
#define FX_BUTTON_MEMBERS
#define FX_RADIO_BUTTON_MEMBERS
#define NI_BILLBOARD_NODE_MEMBERS
#define NI_B_S_ANIMATION_NODE_MEMBERS
#define NI_B_S_PARTICLE_NODE_MEMBERS
#define NI_L_O_D_NODE_MEMBERS
#define NI_PALETTE_MEMBERS
#define NI_PARTICLE_BOMB_MEMBERS
#define NI_PARTICLE_COLOR_MODIFIER_MEMBERS
#define NI_PARTICLE_GROW_FADE_MEMBERS
#define NI_PARTICLE_MESH_MODIFIER_MEMBERS
#define NI_PARTICLE_ROTATION_MEMBERS
#define NI_PARTICLES_MEMBERS
#define NI_AUTO_NORMAL_PARTICLES_MEMBERS
#define NI_PARTICLE_MESHES_MEMBERS
#define NI_PARTICLES_DATA_MEMBERS
#define NI_PARTICLE_MESHES_DATA_MEMBERS
#define NI_PARTICLE_SYSTEM_MEMBERS
#define NI_MESH_PARTICLE_SYSTEM_MEMBERS
#define NI_PARTICLE_SYSTEM_CONTROLLER_MEMBERS
#define NI_B_S_P_ARRAY_CONTROLLER_MEMBERS
#define NI_PATH_CONTROLLER_MEMBERS
#define NI_PATH_INTERPOLATOR_MEMBERS
#define NI_PIXEL_DATA_MEMBERS
#define NI_PLANAR_COLLIDER_MEMBERS
#define NI_POINT3_INTERPOLATOR_MEMBERS
#define NI_POINT_LIGHT_MEMBERS
#define NI_POS_DATA_MEMBERS
#define NI_P_SYS_AGE_DEATH_MODIFIER_MEMBERS
#define NI_P_SYS_BOMB_MODIFIER_MEMBERS
#define NI_P_SYS_BOUND_UPDATE_MODIFIER_MEMBERS
#define NI_P_SYS_BOX_EMITTER_MEMBERS
#define NI_P_SYS_COLLIDER_MANAGER_MEMBERS
#define NI_P_SYS_COLOR_MODIFIER_MEMBERS
#define NI_P_SYS_CYLINDER_EMITTER_MEMBERS
#define NI_P_SYS_DATA_MEMBERS
#define NI_P_SYS_DRAG_MODIFIER_MEMBERS
#define NI_P_SYS_EMITTER_CTLR_MEMBERS
#define NI_P_SYS_EMITTER_CTLR_DATA_MEMBERS
#define NI_P_SYS_EMITTER_DECLINATION_CTLR_MEMBERS
#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_MEMBERS
#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_MEMBERS
#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_MEMBERS
#define NI_P_SYS_EMITTER_SPEED_CTLR_MEMBERS
#define NI_P_SYS_GRAVITY_MODIFIER_MEMBERS
#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_MEMBERS
#define NI_P_SYS_GROW_FADE_MODIFIER_MEMBERS
#define NI_P_SYS_MESH_EMITTER_MEMBERS
#define NI_P_SYS_MESH_UPDATE_MODIFIER_MEMBERS
#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_MEMBERS
#define NI_P_SYS_PLANAR_COLLIDER_MEMBERS
#define NI_P_SYS_POSITION_MODIFIER_MEMBERS
#define NI_P_SYS_RESET_ON_LOOP_CTLR_MEMBERS
#define NI_P_SYS_ROTATION_MODIFIER_MEMBERS
#define NI_P_SYS_SPAWN_MODIFIER_MEMBERS
#define NI_P_SYS_SPHERE_EMITTER_MEMBERS
#define NI_P_SYS_UPDATE_CTLR_MEMBERS
#define NI_L_O_D_DATA_MEMBERS
#define NI_RANGE_L_O_D_DATA_MEMBERS
#define NI_SCREEN_L_O_D_DATA_MEMBERS
#define NI_ROTATING_PARTICLES_MEMBERS
#define NI_ROTATING_PARTICLES_DATA_MEMBERS
#define NI_SEQUENCE_STREAM_HELPER_MEMBERS
#define NI_SHADE_PROPERTY_MEMBERS
#define NI_SKIN_DATA_MEMBERS
#define NI_SKIN_INSTANCE_MEMBERS
#define NI_CLOD_SKIN_INSTANCE_MEMBERS
#define NI_SKIN_PARTITION_MEMBERS
#define NI_SOURCE_TEXTURE_MEMBERS
#define NI_SPECULAR_PROPERTY_MEMBERS
#define NI_SPHERICAL_COLLIDER_MEMBERS
#define NI_SPOT_LIGHT_MEMBERS
#define NI_STENCIL_PROPERTY_MEMBERS
#define NI_STRING_EXTRA_DATA_MEMBERS
#define NI_STRING_PALETTE_MEMBERS
#define NI_STRINGS_EXTRA_DATA_MEMBERS
#define NI_TEXT_KEY_EXTRA_DATA_MEMBERS
#define NI_TEXTURE_EFFECT_MEMBERS
#define NI_TEXTURE_TRANSFORM_CONTROLLER_MEMBERS
#define NI_TEXTURE_MODE_PROPERTY_MEMBERS
#define NI_IMAGE_MEMBERS
#define NI_TEXTURE_PROPERTY_MEMBERS
#define NI_TEXTURING_PROPERTY_MEMBERS
#define NI_TRANSFORM_CONTROLLER_MEMBERS
#define NI_TRANSFORM_DATA_MEMBERS
#define NI_TRANSFORM_INTERPOLATOR_MEMBERS
#define NI_TRI_SHAPE_MEMBERS
#define NI_TRI_SHAPE_DATA_MEMBERS
#define NI_TRI_STRIPS_MEMBERS
#define NI_TRI_STRIPS_DATA_MEMBERS
#define NI_CLOD_MEMBERS
#define NI_CLOD_DATA_MEMBERS
#define NI_U_V_CONTROLLER_MEMBERS
#define NI_U_V_DATA_MEMBERS
#define NI_VECTOR_EXTRA_DATA_MEMBERS
#define NI_VERTEX_COLOR_PROPERTY_MEMBERS
#define NI_VERT_WEIGHTS_EXTRA_DATA_MEMBERS
#define NI_VIS_CONTROLLER_MEMBERS
#define NI_VIS_DATA_MEMBERS
#define NI_WIREFRAME_PROPERTY_MEMBERS
#define NI_Z_BUFFER_PROPERTY_MEMBERS
#define ROOT_COLLISION_NODE_MEMBERS
#endif

#define NI_OBJECT_PARENT

#define NI_OBJECT_CONSTRUCT 
#define A_KEYED_DATA_PARENT NiObject

#define A_KEYED_DATA_CONSTRUCT 
#define A_PARTICLE_MODIFIER_PARENT NiObject

#define A_PARTICLE_MODIFIER_CONSTRUCT  : nextModifier(NULL), controller(NULL)

#define BHK_REF_OBJECT_PARENT NiObject

#define BHK_REF_OBJECT_CONSTRUCT 
#define BHK_SERIALIZABLE_PARENT bhkRefObject

#define BHK_SERIALIZABLE_CONSTRUCT 
#define ABHK_CONSTRAINT_PARENT bhkSerializable

#define ABHK_CONSTRAINT_CONSTRUCT  : numBodies((unsigned int)0), priority((unsigned int)1)

#define ABHK_RAGDOLL_CONSTRAINT_PARENT AbhkConstraint

#define ABHK_RAGDOLL_CONSTRAINT_CONSTRUCT  : coneMinAngle(0.0f), planeMinAngle(0.0f), planeMaxAngle(0.0f), twistMinAngle(0.0f), twistMaxAngle(0.0f), maxFriction(0.0f)

#define BHK_SHAPE_PARENT bhkSerializable

#define BHK_SHAPE_CONSTRUCT 
#define ABHK_SHAPE_COLLECTION_PARENT bhkShape

#define ABHK_SHAPE_COLLECTION_CONSTRUCT 
#define BHK_SPHERE_REP_SHAPE_PARENT bhkShape

#define BHK_SPHERE_REP_SHAPE_CONSTRUCT 
#define BHK_CONVEX_SHAPE_PARENT bhkSphereRepShape

#define BHK_CONVEX_SHAPE_CONSTRUCT 
#define BHK_WORLD_OBJECT_PARENT bhkShape

#define BHK_WORLD_OBJECT_CONSTRUCT 
#define BHK_ENTITY_PARENT bhkWorldObject

#define BHK_ENTITY_CONSTRUCT  : shape(NULL), layer((OblivionLayer)1), colFilter((byte)0), unknownShort((unsigned short)0)

#define NI_COLLISION_OBJECT_PARENT NiObject

#define NI_COLLISION_OBJECT_CONSTRUCT  : parent(NULL), unknownShort((unsigned short)1), body(NULL)

#define NI_EXTRA_DATA_PARENT NiObject

#define NI_EXTRA_DATA_CONSTRUCT  : nextExtraData(NULL)

#define NI_INTERPOLATOR_PARENT NiObject

#define NI_INTERPOLATOR_CONSTRUCT 
#define NI_BLEND_INTERPOLATOR_PARENT NiInterpolator

#define NI_BLEND_INTERPOLATOR_CONSTRUCT  : unknownShort((unsigned short)0), unknownInt((unsigned int)0)

#define NI_B_SPLINE_INTERPOLATOR_PARENT NiInterpolator

#define NI_B_SPLINE_INTERPOLATOR_CONSTRUCT  : startTime(0.0f), stopTime(0.0f), splineData(NULL), basisData(NULL)

#define NI_OBJECT_N_E_T_PARENT NiObject

#define NI_OBJECT_N_E_T_CONSTRUCT  : extraData(NULL), numExtraDataList((unsigned int)0), controller(NULL)

#define NI_A_V_OBJECT_PARENT NiObjectNET

#define NI_A_V_OBJECT_CONSTRUCT  : flags((unsigned short)0), scale(1.0f), numProperties((unsigned int)0), hasBoundingBox(false), collisionData(NULL), collisionObject(NULL)

#define NI_DYNAMIC_EFFECT_PARENT NiAVObject

#define NI_DYNAMIC_EFFECT_CONSTRUCT  : switchState(false), numAffectedNodes((unsigned int)0)

#define NI_LIGHT_PARENT NiDynamicEffect

#define NI_LIGHT_CONSTRUCT  : dimmer(0.0f)

#define NI_PROPERTY_PARENT NiObjectNET

#define NI_PROPERTY_CONSTRUCT 
#define NI_P_SYS_MODIFIER_PARENT NiObject

#define NI_P_SYS_MODIFIER_CONSTRUCT  : order((unsigned int)0), target(NULL), active(false)

#define NI_P_SYS_EMITTER_PARENT NiPSysModifier

#define NI_P_SYS_EMITTER_CONSTRUCT  : speed(0.0f), speedVariation(0.0f), declination(0.0f), declinationVariation(0.0f), planarAngle(0.0f), planarAngleVariation(0.0f), initialRadius(0.0f), radiusVariation(0.0f), lifeSpan(0.0f), lifeSpanVariation(0.0f)

#define NI_P_SYS_VOLUME_EMITTER_PARENT NiPSysEmitter

#define NI_P_SYS_VOLUME_EMITTER_CONSTRUCT  : emitterObject(NULL)

#define NI_TIME_CONTROLLER_PARENT NiObject

#define NI_TIME_CONTROLLER_CONSTRUCT  : nextController(NULL), flags((unsigned short)0), frequency(0.0f), phase(0.0f), startTime(0.0f), stopTime(0.0f), target(NULL)

#define A_BONE_L_O_D_CONTROLLER_PARENT NiTimeController

#define A_BONE_L_O_D_CONTROLLER_CONSTRUCT  : unknownInt1((unsigned int)0), numNodeGroups((unsigned int)0), numNodeGroups2((unsigned int)0)

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_PARENT NiTimeController

#define NI_SINGLE_INTERPOLATOR_CONTROLLER_CONSTRUCT  : interpolator(NULL)

#define A_P_SYS_CTLR_PARENT NiSingleInterpolatorController

#define A_P_SYS_CTLR_CONSTRUCT 
#define NI_GEOMETRY_PARENT NiAVObject

#define NI_GEOMETRY_CONSTRUCT  : data(NULL), skinInstance(NULL), hasShader(false), unknownLink(NULL)

#define NI_TRI_BASED_GEOM_PARENT NiGeometry

#define NI_TRI_BASED_GEOM_CONSTRUCT 
#define NI_GEOMETRY_DATA_PARENT NiObject

#define NI_GEOMETRY_DATA_CONSTRUCT  : numVertices((unsigned short)0), unknownShort1((unsigned short)0), hasVertices(false), numUvSets2((byte)0), unknownByte((byte)0), hasNormals(false), radius(0.0f), hasVertexColors(false), numUvSets((unsigned short)0), hasUv(false), unknownShort2((unsigned short)0), unknownLink(NULL)

#define NI_TRI_BASED_GEOM_DATA_PARENT NiGeometryData

#define NI_TRI_BASED_GEOM_DATA_CONSTRUCT  : numTriangles((unsigned short)0)

#define A_P_SYS_DATA_PARENT NiGeometryData

#define A_P_SYS_DATA_CONSTRUCT  : hasUnknownFloats1(false), unknownShort3((unsigned short)0), hasUnknownFloats2(false), hasUnknownFloats3((byte)0)

#define BHK_BLEND_COLLISION_OBJECT_PARENT NiCollisionObject

#define BHK_BLEND_COLLISION_OBJECT_CONSTRUCT  : unknownFloat1(0.0f), unknownFloat2(0.0f)

#define BHK_BLEND_CONTROLLER_PARENT NiTimeController

#define BHK_BLEND_CONTROLLER_CONSTRUCT  : unknownInt((unsigned int)0)

#define BHK_BOX_SHAPE_PARENT bhkConvexShape

#define BHK_BOX_SHAPE_CONSTRUCT  : unknownFloat1(0.0f), unknownShort1((unsigned short)0), unknownShort2((unsigned short)0), unknownShort3((unsigned short)0), unknownShort4((unsigned short)0), min_Size(0.0f)

#define BHK_CAPSULE_SHAPE_PARENT bhkConvexShape

#define BHK_CAPSULE_SHAPE_CONSTRUCT  : radius(0.0f), unknownShort1((unsigned short)0), unknownShort2((unsigned short)0), unknownShort3((unsigned short)0), unknownShort4((unsigned short)0), radius1(0.0f), radius2(0.0f)

#define BHK_COLLISION_OBJECT_PARENT NiCollisionObject

#define BHK_COLLISION_OBJECT_CONSTRUCT 
#define BHK_CONVEX_VERTICES_SHAPE_PARENT bhkSphereRepShape

#define BHK_CONVEX_VERTICES_SHAPE_CONSTRUCT  : numVertices((unsigned int)0), numNormals((unsigned int)0)

#define BHK_HINGE_CONSTRAINT_PARENT AbhkConstraint

#define BHK_HINGE_CONSTRAINT_CONSTRUCT 
#define BHK_LIMITED_HINGE_CONSTRAINT_PARENT AbhkConstraint

#define BHK_LIMITED_HINGE_CONSTRAINT_CONSTRUCT 
#define BHK_LIST_SHAPE_PARENT AbhkShapeCollection

#define BHK_LIST_SHAPE_CONSTRUCT  : numSubShapes((unsigned int)0), numUnknownInts((unsigned int)0)

#define BHK_MALLEABLE_CONSTRAINT_PARENT AbhkConstraint

#define BHK_MALLEABLE_CONSTRAINT_CONSTRUCT  : type((unsigned int)0), unknownInt2((unsigned int)0), unknownLink1(NULL), unknownLink2(NULL), unknownInt3((unsigned int)0), tau(0.0f), damping(0.0f)

#define BHK_MOPP_BV_TREE_SHAPE_PARENT bhkShape

#define BHK_MOPP_BV_TREE_SHAPE_CONSTRUCT  : shape(NULL), unknownFloat(0.0f), numUnknownBytes2((unsigned int)0), unknownFloat2(0.0f)

#define BHK_MULTI_SPHERE_SHAPE_PARENT bhkSphereRepShape

#define BHK_MULTI_SPHERE_SHAPE_CONSTRUCT  : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), numSpheres((unsigned int)0)

#define BHK_NI_TRI_STRIPS_SHAPE_PARENT bhkSphereRepShape

#define BHK_NI_TRI_STRIPS_SHAPE_CONSTRUCT  : unknownFloat1(0.1f), unknownInt1((unsigned int)0x004ABE60), unknownInt2((unsigned int)1), scale(1.0f, 1.0f, 1.0f), unknownInt3((unsigned int)0), numStripsData((unsigned int)0), numDataLayers((unsigned int)0)

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_PARENT AbhkShapeCollection

#define BHK_PACKED_NI_TRI_STRIPS_SHAPE_CONSTRUCT  : numSubShapes((unsigned short)0), scale(1.0f), data(NULL)

#define BHK_PRISMATIC_CONSTRAINT_PARENT AbhkConstraint

#define BHK_PRISMATIC_CONSTRAINT_CONSTRUCT 
#define BHK_RAGDOLL_CONSTRAINT_PARENT AbhkRagdollConstraint

#define BHK_RAGDOLL_CONSTRAINT_CONSTRUCT 
#define BHK_RIGID_BODY_PARENT bhkEntity

#define BHK_RIGID_BODY_CONSTRUCT  : layerCopy((OblivionLayer)1), colFilterCopy((byte)0), unknownFloat00(0.0f), unknownFloat01(0.0f), unknownFloat02(0.0f), unknownFloat03(0.0f), mass(0.0f), linearDamping(0.1f), angularDamping(0.1f), friction(0.3f), restitution(0.3f), maxLinearVelocity(250.0f), maxAngularVelocity(31.415926535f), penetrationDepth(0.15f), motionSystem((MotionSystem)7), unknownByte1((byte)1), unknownByte2((byte)1), qualityType((MotionQuality)1), unknownInt6((unsigned int)0), unknownInt7((unsigned int)0), unknownInt8((unsigned int)0), numConstraints((unsigned int)0)

#define BHK_RIGID_BODY_T_PARENT bhkRigidBody

#define BHK_RIGID_BODY_T_CONSTRUCT 
#define BHK_SIMPLE_SHAPE_PHANTOM_PARENT bhkEntity

#define BHK_SIMPLE_SHAPE_PHANTOM_CONSTRUCT  : unknownFloat(0.0f)

#define BHK_S_P_COLLISION_OBJECT_PARENT NiCollisionObject

#define BHK_S_P_COLLISION_OBJECT_CONSTRUCT 
#define BHK_SPHERE_SHAPE_PARENT bhkConvexShape

#define BHK_SPHERE_SHAPE_CONSTRUCT  : radius(0.0f)

#define BHK_STIFF_SPRING_CONSTRAINT_PARENT AbhkConstraint

#define BHK_STIFF_SPRING_CONSTRAINT_CONSTRUCT  : unknownFloat(0.0f)

#define BHK_TRANSFORM_SHAPE_PARENT bhkEntity

#define BHK_TRANSFORM_SHAPE_CONSTRUCT  : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f)

#define BHK_CONVEX_TRANSFORM_SHAPE_PARENT bhkTransformShape

#define BHK_CONVEX_TRANSFORM_SHAPE_CONSTRUCT 
#define B_S_BOUND_PARENT NiExtraData

#define B_S_BOUND_CONSTRUCT 
#define B_S_FURNITURE_MARKER_PARENT NiExtraData

#define B_S_FURNITURE_MARKER_CONSTRUCT  : numPositions((unsigned int)0)

#define B_S_PARENT_VELOCITY_MODIFIER_PARENT NiPSysModifier

#define B_S_PARENT_VELOCITY_MODIFIER_CONSTRUCT  : unknownFloat(0.0f)

#define B_S_P_SYS_ARRAY_EMITTER_PARENT NiPSysVolumeEmitter

#define B_S_P_SYS_ARRAY_EMITTER_CONSTRUCT 
#define B_S_X_FLAGS_PARENT NiExtraData

#define B_S_X_FLAGS_CONSTRUCT  : flags((unsigned int)0)

#define HK_PACKED_NI_TRI_STRIPS_DATA_PARENT AbhkShapeCollection

#define HK_PACKED_NI_TRI_STRIPS_DATA_CONSTRUCT  : numTriangles((unsigned int)0), numVertices((unsigned int)0)

#define NI_ALPHA_CONTROLLER_PARENT NiSingleInterpolatorController

#define NI_ALPHA_CONTROLLER_CONSTRUCT  : data(NULL)

#define NI_ALPHA_PROPERTY_PARENT NiProperty

#define NI_ALPHA_PROPERTY_CONSTRUCT  : flags((unsigned short)237), threshold((byte)0)

#define NI_AMBIENT_LIGHT_PARENT NiLight

#define NI_AMBIENT_LIGHT_CONSTRUCT 
#define NI_AUTO_NORMAL_PARTICLES_DATA_PARENT NiGeometryData

#define NI_AUTO_NORMAL_PARTICLES_DATA_CONSTRUCT  : numParticles((unsigned short)0), size(0.0f), numActive((unsigned short)0), unknownShort((unsigned short)0), hasSizes(false)

#define NI_BINARY_EXTRA_DATA_PARENT NiExtraData

#define NI_BINARY_EXTRA_DATA_CONSTRUCT 
#define NI_BLEND_BOOL_INTERPOLATOR_PARENT NiBlendInterpolator

#define NI_BLEND_BOOL_INTERPOLATOR_CONSTRUCT  : boolValue((byte)0)

#define NI_BLEND_FLOAT_INTERPOLATOR_PARENT NiBlendInterpolator

#define NI_BLEND_FLOAT_INTERPOLATOR_CONSTRUCT  : floatValue(0.0f)

#define NI_BLEND_POINT3_INTERPOLATOR_PARENT NiBlendInterpolator

#define NI_BLEND_POINT3_INTERPOLATOR_CONSTRUCT 
#define NI_BLEND_TRANSFORM_INTERPOLATOR_PARENT NiBlendInterpolator

#define NI_BLEND_TRANSFORM_INTERPOLATOR_CONSTRUCT 
#define NI_BONE_L_O_D_CONTROLLER_PARENT ABoneLODController

#define NI_BONE_L_O_D_CONTROLLER_CONSTRUCT  : numShapeGroups((unsigned int)0), numShapeGroups2((unsigned int)0)

#define NI_BOOL_DATA_PARENT AKeyedData

#define NI_BOOL_DATA_CONSTRUCT 
#define NI_BOOLEAN_EXTRA_DATA_PARENT NiExtraData

#define NI_BOOLEAN_EXTRA_DATA_CONSTRUCT  : booleanData((byte)0)

#define NI_BOOL_INTERPOLATOR_PARENT NiInterpolator

#define NI_BOOL_INTERPOLATOR_CONSTRUCT  : boolValue(false), data(NULL)

#define NI_BOOL_TIMELINE_INTERPOLATOR_PARENT NiInterpolator

#define NI_BOOL_TIMELINE_INTERPOLATOR_CONSTRUCT  : boolValue((byte)0), data(NULL)

#define NI_B_S_BONE_L_O_D_CONTROLLER_PARENT ABoneLODController

#define NI_B_S_BONE_L_O_D_CONTROLLER_CONSTRUCT 
#define NI_B_SPLINE_BASIS_DATA_PARENT NiObject

#define NI_B_SPLINE_BASIS_DATA_CONSTRUCT  : numControlPt((unsigned int)0)

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_PARENT NiBSplineInterpolator

#define NI_B_SPLINE_COMP_FLOAT_INTERPOLATOR_CONSTRUCT 
#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_PARENT NiBSplineInterpolator

#define NI_B_SPLINE_COMP_POINT3_INTERPOLATOR_CONSTRUCT 
#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_PARENT NiBSplineInterpolator

#define NI_B_SPLINE_COMP_TRANSFORM_INTERPOLATOR_CONSTRUCT  : scale(0.0f), translateOffset((unsigned int)0), rotateOffset((unsigned int)0), scaleOffset((unsigned int)0), translateBias(0.0f), translateMultiplier(0.0f), rotationBias(0.0f), rotationMultiplier(0.0f), scaleBias(0.0f), scaleMultiplier(0.0f)

#define NI_B_SPLINE_DATA_PARENT NiObject

#define NI_B_SPLINE_DATA_CONSTRUCT  : unknownInt((unsigned int)0), count((unsigned int)0)

#define NI_CAMERA_PARENT NiAVObject

#define NI_CAMERA_CONSTRUCT  : unknownShort((unsigned short)0), frustumLeft(0.0f), frustumRight(0.0f), frustumTop(0.0f), frustumBottom(0.0f), frustumNear(0.0f), frustumFar(0.0f), useOrthographicProjection(false), viewportLeft(0.0f), viewportRight(0.0f), viewportTop(0.0f), viewportBottom(0.0f), lodAdjust(0.0f), unknownLink_(NULL), unknownInt((unsigned int)0), unknownInt2((unsigned int)0)

#define NI_COLLISION_DATA_PARENT NiObject

#define NI_COLLISION_DATA_CONSTRUCT  : targetNode(NULL), unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownByte((byte)0), collisionType((unsigned int)0)

#define NI_COLOR_DATA_PARENT AKeyedData

#define NI_COLOR_DATA_CONSTRUCT 
#define NI_COLOR_EXTRA_DATA_PARENT NiExtraData

#define NI_COLOR_EXTRA_DATA_CONSTRUCT 
#define NI_CONTROLLER_MANAGER_PARENT NiTimeController

#define NI_CONTROLLER_MANAGER_CONSTRUCT  : cumulative(false), numControllerSequences((unsigned int)0), objectPalette(NULL)

#define NI_CONTROLLER_SEQUENCE_PARENT NiObject

#define NI_CONTROLLER_SEQUENCE_CONSTRUCT  : textKeys(NULL), numControlledBlocks((unsigned int)0), unknownInt1((unsigned int)0), weight(1.0f), unknownInt0((unsigned int)0), frequency(0.0f), startTime(0.0f), stopTime(0.0f), unknownFloat2(0.0f), unknownByte((byte)0), manager(NULL), stringPalette(NULL)

#define NI_DEFAULT_A_V_OBJECT_PALETTE_PARENT NiObject

#define NI_DEFAULT_A_V_OBJECT_PALETTE_CONSTRUCT  : unknownInt((unsigned int)0), numObjs((unsigned int)0)

#define NI_DIRECTIONAL_LIGHT_PARENT NiLight

#define NI_DIRECTIONAL_LIGHT_CONSTRUCT 
#define NI_DITHER_PROPERTY_PARENT NiProperty

#define NI_DITHER_PROPERTY_CONSTRUCT  : flags((unsigned short)0)

#define NI_FLIP_CONTROLLER_PARENT NiSingleInterpolatorController

#define NI_FLIP_CONTROLLER_CONSTRUCT  : textureSlot((unsigned int)0), unknownInt2((unsigned int)0), delta(0.0f), numSources((unsigned int)0)

#define NI_FLOAT_DATA_PARENT AKeyedData

#define NI_FLOAT_DATA_CONSTRUCT 
#define NI_FLOAT_EXTRA_DATA_PARENT NiExtraData

#define NI_FLOAT_EXTRA_DATA_CONSTRUCT  : floatData(0.0f)

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_PARENT NiTimeController

#define NI_FLOAT_EXTRA_DATA_CONTROLLER_CONSTRUCT  : unknownLink(NULL)

#define NI_FLOAT_INTERPOLATOR_PARENT NiInterpolator

#define NI_FLOAT_INTERPOLATOR_CONSTRUCT  : floatValue(0.0f), data(NULL)

#define NI_FLOATS_EXTRA_DATA_PARENT NiExtraData

#define NI_FLOATS_EXTRA_DATA_CONSTRUCT  : numFloats((unsigned int)0)

#define NI_FOG_PROPERTY_PARENT NiProperty

#define NI_FOG_PROPERTY_CONSTRUCT  : flags((unsigned short)0), fogDepth(0.0f)

#define NI_GEOM_MORPHER_CONTROLLER_PARENT NiTimeController

#define NI_GEOM_MORPHER_CONTROLLER_CONSTRUCT  : unknown((unsigned short)0), unknown2((byte)0), data(NULL), unknownByte((byte)0), numInterpolators((unsigned int)0), numUnknownInts((unsigned int)0)

#define NI_GRAVITY_PARENT AParticleModifier

#define NI_GRAVITY_CONSTRUCT  : unknownFloat1(0.0f), force(0.0f)

#define NI_INTEGER_EXTRA_DATA_PARENT NiExtraData

#define NI_INTEGER_EXTRA_DATA_CONSTRUCT  : integerData((unsigned int)0)

#define NI_INTEGERS_EXTRA_DATA_PARENT NiExtraData

#define NI_INTEGERS_EXTRA_DATA_CONSTRUCT  : numIntegers((unsigned int)0)

#define NI_KEYFRAME_CONTROLLER_PARENT NiTimeController

#define NI_KEYFRAME_CONTROLLER_CONSTRUCT  : data(NULL)

#define B_S_KEYFRAME_CONTROLLER_PARENT NiKeyframeController

#define B_S_KEYFRAME_CONTROLLER_CONSTRUCT  : data2(NULL)

#define NI_KEYFRAME_DATA_PARENT AKeyedData

#define NI_KEYFRAME_DATA_CONSTRUCT  : numRotationKeys((unsigned int)0), rotationType((KeyType)0), unknownFloat(0.0f)

#define NI_LIGHT_COLOR_CONTROLLER_PARENT NiTimeController

#define NI_LIGHT_COLOR_CONTROLLER_CONSTRUCT  : unknownShort((unsigned short)0), data(NULL), interpolator(NULL)

#define NI_LIGHT_DIMMER_CONTROLLER_PARENT NiTimeController

#define NI_LIGHT_DIMMER_CONTROLLER_CONSTRUCT  : unknownLink(NULL)

#define NI_LOOK_AT_CONTROLLER_PARENT NiTimeController

#define NI_LOOK_AT_CONTROLLER_CONSTRUCT  : unknown1((unsigned short)0), lookAtNode(NULL)

#define NI_LOOK_AT_INTERPOLATOR_PARENT NiInterpolator

#define NI_LOOK_AT_INTERPOLATOR_CONSTRUCT  : unknownShort((unsigned short)0), lookAt(NULL), unknownFloat(0.0f), scale(0.0f), unknownLink1(NULL), unknownLink2(NULL), unknownLink3(NULL)

#define NI_MATERIAL_COLOR_CONTROLLER_PARENT NiSingleInterpolatorController

#define NI_MATERIAL_COLOR_CONTROLLER_CONSTRUCT  : targetColor((unsigned short)0), data(NULL)

#define NI_MATERIAL_PROPERTY_PARENT NiProperty

#define NI_MATERIAL_PROPERTY_CONSTRUCT  : flags((unsigned short)0), glossiness(0.0f), alpha(0.0f)

#define NI_MESH_P_SYS_DATA_PARENT APSysData

#define NI_MESH_P_SYS_DATA_CONSTRUCT  : unknownByte11((byte)0), unknownInt1((unsigned int)0), modifier(NULL), unknownByte2((byte)0), numUnknownLinks((unsigned int)0), unknownShort4((unsigned short)0), unknownInt2((unsigned int)0), unknownByte12((byte)0), unknownInt3((unsigned int)0), unknownInt4((unsigned int)0), unknownLink2(NULL)

#define NI_MORPH_DATA_PARENT NiObject

#define NI_MORPH_DATA_CONSTRUCT  : numMorphs((unsigned int)0), numVertices((unsigned int)0), unknownByte((byte)0)

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_PARENT NiTimeController

#define NI_MULTI_TARGET_TRANSFORM_CONTROLLER_CONSTRUCT  : numExtraTargets((unsigned short)0)

#define NI_NODE_PARENT NiAVObject

#define NI_NODE_CONSTRUCT  : numChildren((unsigned int)0), numEffects((unsigned int)0)

#define AVOID_NODE_PARENT NiNode

#define AVOID_NODE_CONSTRUCT 
#define FX_WIDGET_PARENT NiNode

#define FX_WIDGET_CONSTRUCT  : unknown1((byte)0)

#define FX_BUTTON_PARENT FxWidget

#define FX_BUTTON_CONSTRUCT 
#define FX_RADIO_BUTTON_PARENT FxWidget

#define FX_RADIO_BUTTON_CONSTRUCT  : unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownInt3((unsigned int)0), numButtons((unsigned int)0)

#define NI_BILLBOARD_NODE_PARENT NiNode

#define NI_BILLBOARD_NODE_CONSTRUCT 
#define NI_B_S_ANIMATION_NODE_PARENT NiNode

#define NI_B_S_ANIMATION_NODE_CONSTRUCT 
#define NI_B_S_PARTICLE_NODE_PARENT NiNode

#define NI_B_S_PARTICLE_NODE_CONSTRUCT 
#define NI_L_O_D_NODE_PARENT NiNode

#define NI_L_O_D_NODE_CONSTRUCT  : numLodLevels((unsigned int)0), unknownShort((unsigned short)0), lodLevelData(NULL)

#define NI_PALETTE_PARENT NiObject

#define NI_PALETTE_CONSTRUCT  : unknownByte((byte)0), numEntries_((unsigned int)0)

#define NI_PARTICLE_BOMB_PARENT AParticleModifier

#define NI_PARTICLE_BOMB_CONSTRUCT  : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownFloat4(0.0f), unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownFloat5(0.0f), unknownFloat6(0.0f), unknownFloat7(0.0f), unknownFloat8(0.0f), unknownFloat9(0.0f), unknownFloat10(0.0f)

#define NI_PARTICLE_COLOR_MODIFIER_PARENT AParticleModifier

#define NI_PARTICLE_COLOR_MODIFIER_CONSTRUCT  : colorData(NULL)

#define NI_PARTICLE_GROW_FADE_PARENT AParticleModifier

#define NI_PARTICLE_GROW_FADE_CONSTRUCT  : grow(0.0f), fade(0.0f)

#define NI_PARTICLE_MESH_MODIFIER_PARENT AParticleModifier

#define NI_PARTICLE_MESH_MODIFIER_CONSTRUCT  : numParticleMeshes((unsigned int)0)

#define NI_PARTICLE_ROTATION_PARENT AParticleModifier

#define NI_PARTICLE_ROTATION_CONSTRUCT  : unknownByte((byte)0), unknownFloat1(0.0f), unknownFloat2(0.0f), unknownFloat3(0.0f), unknownFloat4(0.0f)

#define NI_PARTICLES_PARENT NiGeometry

#define NI_PARTICLES_CONSTRUCT 
#define NI_AUTO_NORMAL_PARTICLES_PARENT NiParticles

#define NI_AUTO_NORMAL_PARTICLES_CONSTRUCT 
#define NI_PARTICLE_MESHES_PARENT NiParticles

#define NI_PARTICLE_MESHES_CONSTRUCT 
#define NI_PARTICLES_DATA_PARENT NiAutoNormalParticlesData

#define NI_PARTICLES_DATA_CONSTRUCT  : numActive((unsigned short)0), hasUnknownFloats(false), hasRotations(false)

#define NI_PARTICLE_MESHES_DATA_PARENT NiParticlesData

#define NI_PARTICLE_MESHES_DATA_CONSTRUCT  : unknownLink2(NULL)

#define NI_PARTICLE_SYSTEM_PARENT NiParticles

#define NI_PARTICLE_SYSTEM_CONSTRUCT  : unknownBool(false), numModifiers((unsigned int)0)

#define NI_MESH_PARTICLE_SYSTEM_PARENT NiParticleSystem

#define NI_MESH_PARTICLE_SYSTEM_CONSTRUCT 
#define NI_PARTICLE_SYSTEM_CONTROLLER_PARENT NiTimeController

#define NI_PARTICLE_SYSTEM_CONTROLLER_CONSTRUCT  : speed(0.0f), speedRandom(0.0f), verticalDirection(0.0f), verticalAngle(0.0f), horizontalDirection(0.0f), horizontalAngle(0.0f), unknownFloat5(0.0f), unknownFloat6(0.0f), unknownFloat7(0.0f), unknownFloat8(0.0f), unknownFloat9(0.0f), unknownFloat10(0.0f), unknownFloat11(0.0f), size(0.0f), emitStartTime(0.0f), emitStopTime(0.0f), unknownByte((byte)0), emitRate(0.0f), lifetime(0.0f), lifetimeRandom(0.0f), emitFlags((unsigned short)0), emitter(NULL), unknownShort2_((unsigned short)0), unknownFloat13_(0.0f), unknownInt1_((unsigned int)0), unknownInt2_((unsigned int)0), unknownShort3_((unsigned short)0), numParticles((unsigned short)0), numValid((unsigned short)0), unknownLink(NULL), particleExtra(NULL), unknownLink2(NULL), trailer((byte)0)

#define NI_B_S_P_ARRAY_CONTROLLER_PARENT NiParticleSystemController

#define NI_B_S_P_ARRAY_CONTROLLER_CONSTRUCT 
#define NI_PATH_CONTROLLER_PARENT NiTimeController

#define NI_PATH_CONTROLLER_CONSTRUCT  : unknownShort2((unsigned short)0), unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), unknownInt3((unsigned int)0), unknownShort((unsigned short)0), posData(NULL), floatData(NULL)

#define NI_PATH_INTERPOLATOR_PARENT NiBlendInterpolator

#define NI_PATH_INTERPOLATOR_CONSTRUCT  : unknownFloat1(0.0f), unknownFloat2(0.0f), unknownShort2((unsigned short)0), posData(NULL), floatData(NULL)

#define NI_PIXEL_DATA_PARENT NiObject

#define NI_PIXEL_DATA_CONSTRUCT  : redMask((unsigned int)0), greenMask((unsigned int)0), blueMask((unsigned int)0), alphaMask((unsigned int)0), bitsPerPixel((unsigned int)0), unknownInt((unsigned int)0), palette(NULL), numMipmaps((unsigned int)0), bytesPerPixel((unsigned int)0), unknownInt2((unsigned int)0)

#define NI_PLANAR_COLLIDER_PARENT AParticleModifier

#define NI_PLANAR_COLLIDER_CONSTRUCT  : unknownShort((unsigned short)0), unknownFloat1(0.0f), unknownFloat2(0.0f), unknownShort2((unsigned short)0), unknownFloat3(0.0f), unknownFloat4(0.0f), unknownFloat5(0.0f), unknownFloat6(0.0f), unknownFloat7(0.0f), unknownFloat8(0.0f), unknownFloat9(0.0f), unknownFloat10(0.0f), unknownFloat11(0.0f), unknownFloat12(0.0f), unknownFloat13(0.0f), unknownFloat14(0.0f), unknownFloat15(0.0f), unknownFloat16(0.0f)

#define NI_POINT3_INTERPOLATOR_PARENT NiInterpolator

#define NI_POINT3_INTERPOLATOR_CONSTRUCT  : data(NULL)

#define NI_POINT_LIGHT_PARENT NiLight

#define NI_POINT_LIGHT_CONSTRUCT  : constantAttenuation(0.0f), linearAttenuation(0.0f), quadraticAttenuation(0.0f)

#define NI_POS_DATA_PARENT AKeyedData

#define NI_POS_DATA_CONSTRUCT 
#define NI_P_SYS_AGE_DEATH_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_AGE_DEATH_MODIFIER_CONSTRUCT  : spawnOnDeath(false), spawnModifier(NULL)

#define NI_P_SYS_BOMB_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_BOMB_MODIFIER_CONSTRUCT  : unknownLink(NULL)

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_BOUND_UPDATE_MODIFIER_CONSTRUCT  : updateSkip((unsigned short)0)

#define NI_P_SYS_BOX_EMITTER_PARENT NiPSysVolumeEmitter

#define NI_P_SYS_BOX_EMITTER_CONSTRUCT  : width(0.0f), height(0.0f), depth(0.0f)

#define NI_P_SYS_COLLIDER_MANAGER_PARENT NiPSysModifier

#define NI_P_SYS_COLLIDER_MANAGER_CONSTRUCT  : collider(NULL)

#define NI_P_SYS_COLOR_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_COLOR_MODIFIER_CONSTRUCT  : data(NULL)

#define NI_P_SYS_CYLINDER_EMITTER_PARENT NiPSysVolumeEmitter

#define NI_P_SYS_CYLINDER_EMITTER_CONSTRUCT  : radius(0.0f), height(0.0f)

#define NI_P_SYS_DATA_PARENT APSysData

#define NI_P_SYS_DATA_CONSTRUCT  : unknownBool1(false), unknownByte3((byte)0), unknownBool2(false), unknownInt1((unsigned int)0)

#define NI_P_SYS_DRAG_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_DRAG_MODIFIER_CONSTRUCT  : parent(NULL), percentage(0.0f), range(0.0f), rangeFalloff(0.0f)

#define NI_P_SYS_EMITTER_CTLR_PARENT APSysCtlr

#define NI_P_SYS_EMITTER_CTLR_CONSTRUCT  : data(NULL), visibilityInterpolator(NULL)

#define NI_P_SYS_EMITTER_CTLR_DATA_PARENT NiObject

#define NI_P_SYS_EMITTER_CTLR_DATA_CONSTRUCT  : numVisibilityKeys_((unsigned int)0)

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_PARENT APSysCtlr

#define NI_P_SYS_EMITTER_DECLINATION_CTLR_CONSTRUCT 
#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_PARENT APSysCtlr

#define NI_P_SYS_EMITTER_DECLINATION_VAR_CTLR_CONSTRUCT 
#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_PARENT APSysCtlr

#define NI_P_SYS_EMITTER_INITIAL_RADIUS_CTLR_CONSTRUCT 
#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_PARENT APSysCtlr

#define NI_P_SYS_EMITTER_LIFE_SPAN_CTLR_CONSTRUCT  : unknownLink(NULL)

#define NI_P_SYS_EMITTER_SPEED_CTLR_PARENT APSysCtlr

#define NI_P_SYS_EMITTER_SPEED_CTLR_CONSTRUCT  : unknownLink(NULL)

#define NI_P_SYS_GRAVITY_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_GRAVITY_MODIFIER_CONSTRUCT  : gravityObject(NULL), decay(0.0f), strength(0.0f), turbulence(0.0f), turbulenceScale(1.0f)

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_PARENT APSysCtlr

#define NI_P_SYS_GRAVITY_STRENGTH_CTLR_CONSTRUCT  : unknownLink(NULL)

#define NI_P_SYS_GROW_FADE_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_GROW_FADE_MODIFIER_CONSTRUCT  : growTime(0.0f), growGeneration((unsigned short)0), fadeTime(0.0f), fadeGeneration((unsigned short)0)

#define NI_P_SYS_MESH_EMITTER_PARENT NiPSysEmitter

#define NI_P_SYS_MESH_EMITTER_CONSTRUCT  : numEmitterMeshes((unsigned int)0), initialVelocityType((unsigned int)0), emissionType((unsigned int)0)

#define NI_P_SYS_MESH_UPDATE_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_MESH_UPDATE_MODIFIER_CONSTRUCT  : numMeshes((unsigned int)0)

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_PARENT APSysCtlr

#define NI_P_SYS_MODIFIER_ACTIVE_CTLR_CONSTRUCT  : unknownInt((unsigned int)0)

#define NI_P_SYS_PLANAR_COLLIDER_PARENT NiObject

#define NI_P_SYS_PLANAR_COLLIDER_CONSTRUCT  : bounce(0.0f), spawnOnCollide(false), dieOnCollide(false), spawnModifier(NULL), parent(NULL), unknownLink_(NULL), colliderObject(NULL), width(0.0f), height(0.0f)

#define NI_P_SYS_POSITION_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_POSITION_MODIFIER_CONSTRUCT 
#define NI_P_SYS_RESET_ON_LOOP_CTLR_PARENT NiTimeController

#define NI_P_SYS_RESET_ON_LOOP_CTLR_CONSTRUCT 
#define NI_P_SYS_ROTATION_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_ROTATION_MODIFIER_CONSTRUCT  : initialRotationSpeed(0.0f), initialRotationSpeedVariation(0.0f), initialRotationAngle(0.0f), initialRotationAngleVariation(0.0f), randomRotSpeedSign(false), randomInitialAxis(false)

#define NI_P_SYS_SPAWN_MODIFIER_PARENT NiPSysModifier

#define NI_P_SYS_SPAWN_MODIFIER_CONSTRUCT  : numSpawnGenerations((unsigned short)0), percentageSpawned(0.0f), minNumToSpawn((unsigned short)0), maxNumToSpawn((unsigned short)0), spawnSpeedChaos(0.0f), spawnDirChaos(0.0f), lifeSpan(0.0f), lifeSpanVariation(0.0f)

#define NI_P_SYS_SPHERE_EMITTER_PARENT NiPSysVolumeEmitter

#define NI_P_SYS_SPHERE_EMITTER_CONSTRUCT  : radius(0.0f)

#define NI_P_SYS_UPDATE_CTLR_PARENT NiTimeController

#define NI_P_SYS_UPDATE_CTLR_CONSTRUCT 
#define NI_L_O_D_DATA_PARENT NiObject

#define NI_L_O_D_DATA_CONSTRUCT 
#define NI_RANGE_L_O_D_DATA_PARENT NiLODData

#define NI_RANGE_L_O_D_DATA_CONSTRUCT  : numLodLevels((unsigned int)0)

#define NI_SCREEN_L_O_D_DATA_PARENT NiLODData

#define NI_SCREEN_L_O_D_DATA_CONSTRUCT  : boundRadius(0.0f), worldRadius(0.0f), proportionCount((unsigned int)0)

#define NI_ROTATING_PARTICLES_PARENT NiParticles

#define NI_ROTATING_PARTICLES_CONSTRUCT 
#define NI_ROTATING_PARTICLES_DATA_PARENT NiParticlesData

#define NI_ROTATING_PARTICLES_DATA_CONSTRUCT 
#define NI_SEQUENCE_STREAM_HELPER_PARENT NiObjectNET

#define NI_SEQUENCE_STREAM_HELPER_CONSTRUCT 
#define NI_SHADE_PROPERTY_PARENT NiProperty

#define NI_SHADE_PROPERTY_CONSTRUCT  : flags((unsigned short)0)

#define NI_SKIN_DATA_PARENT NiObject

#define NI_SKIN_DATA_CONSTRUCT  : scale(0.0f), numBones((unsigned int)0), skinPartition(NULL), unknownByte((byte)1)

#define NI_SKIN_INSTANCE_PARENT NiObject

#define NI_SKIN_INSTANCE_CONSTRUCT  : data(NULL), skinPartition(NULL), skeletonRoot(NULL), numBones((unsigned int)0)

#define NI_CLOD_SKIN_INSTANCE_PARENT NiSkinInstance

#define NI_CLOD_SKIN_INSTANCE_CONSTRUCT 
#define NI_SKIN_PARTITION_PARENT NiObject

#define NI_SKIN_PARTITION_CONSTRUCT  : numSkinPartitionBlocks((unsigned int)0)

#define NI_SOURCE_TEXTURE_PARENT NiObjectNET

#define NI_SOURCE_TEXTURE_CONSTRUCT  : useExternal((byte)1), unknownLink(NULL), unknownByte((byte)0), pixelData(NULL), pixelLayout((PixelLayout)5), useMipmaps((MipMapFormat)2), alphaFormat((AlphaFormat)3), unknownByte2((byte)1)

#define NI_SPECULAR_PROPERTY_PARENT NiProperty

#define NI_SPECULAR_PROPERTY_CONSTRUCT  : flags((unsigned short)0)

#define NI_SPHERICAL_COLLIDER_PARENT AParticleModifier

#define NI_SPHERICAL_COLLIDER_CONSTRUCT  : unknownFloat1(0.0f), unknownShort1((unsigned short)0), unknownFloat2(0.0f), unknownShort2((unsigned short)0), unknownFloat3(0.0f), unknownFloat4(0.0f), unknownFloat5(0.0f)

#define NI_SPOT_LIGHT_PARENT NiPointLight

#define NI_SPOT_LIGHT_CONSTRUCT  : cutoffAngle(0.0f), exponent(0.0f)

#define NI_STENCIL_PROPERTY_PARENT NiProperty

#define NI_STENCIL_PROPERTY_CONSTRUCT  : flags((unsigned short)0), stencilEnabled((byte)0), stencilRef((unsigned int)0), stencilMask((unsigned int)4294967295)

#define NI_STRING_EXTRA_DATA_PARENT NiExtraData

#define NI_STRING_EXTRA_DATA_CONSTRUCT  : bytesRemaining((unsigned int)0)

#define NI_STRING_PALETTE_PARENT NiObject

#define NI_STRING_PALETTE_CONSTRUCT 
#define NI_STRINGS_EXTRA_DATA_PARENT NiExtraData

#define NI_STRINGS_EXTRA_DATA_CONSTRUCT  : numStrings((unsigned int)0)

#define NI_TEXT_KEY_EXTRA_DATA_PARENT NiExtraData

#define NI_TEXT_KEY_EXTRA_DATA_CONSTRUCT  : unknownInt1((unsigned int)0), numTextKeys((unsigned int)0)

#define NI_TEXTURE_EFFECT_PARENT NiDynamicEffect

#define NI_TEXTURE_EFFECT_CONSTRUCT  : textureType((unsigned int)0), coordinateGenerationType((unsigned int)0), sourceTexture(NULL), clippingPlane((byte)0), unknownFloat(0.0f), ps2L((unsigned short)0), ps2K((unsigned short)0), unknownShort((unsigned short)0)

#define NI_TEXTURE_TRANSFORM_CONTROLLER_PARENT NiSingleInterpolatorController

#define NI_TEXTURE_TRANSFORM_CONTROLLER_CONSTRUCT  : unknown2((byte)0), operation((unsigned int)0), data(NULL)

#define NI_TEXTURE_MODE_PROPERTY_PARENT NiProperty

#define NI_TEXTURE_MODE_PROPERTY_CONSTRUCT 
#define NI_IMAGE_PARENT NiObject

#define NI_IMAGE_CONSTRUCT  : external_((byte)0)

#define NI_TEXTURE_PROPERTY_PARENT NiProperty

#define NI_TEXTURE_PROPERTY_CONSTRUCT  : flags((unsigned short)0), image(NULL)

#define NI_TEXTURING_PROPERTY_PARENT NiProperty

#define NI_TEXTURING_PROPERTY_CONSTRUCT  : flags((unsigned short)0), applyMode((ApplyMode)2), textureCount((unsigned int)7), hasBaseTexture(false), hasDarkTexture(false), hasDetailTexture(false), hasGlossTexture(false), hasGlowTexture(false), hasBumpMapTexture(false), bumpMapLumaScale(0.0f), bumpMapLumaOffset(0.0f), hasDecal0Texture(false), hasDecal1Texture(false), hasDecal2Texture(false), hasDecal3Texture(false), numShaderTextures((unsigned int)0)

#define NI_TRANSFORM_CONTROLLER_PARENT NiSingleInterpolatorController

#define NI_TRANSFORM_CONTROLLER_CONSTRUCT 
#define NI_TRANSFORM_DATA_PARENT NiKeyframeData

#define NI_TRANSFORM_DATA_CONSTRUCT 
#define NI_TRANSFORM_INTERPOLATOR_PARENT NiInterpolator

#define NI_TRANSFORM_INTERPOLATOR_CONSTRUCT  : scale(0.0f), data(NULL)

#define NI_TRI_SHAPE_PARENT NiTriBasedGeom

#define NI_TRI_SHAPE_CONSTRUCT 
#define NI_TRI_SHAPE_DATA_PARENT NiTriBasedGeomData

#define NI_TRI_SHAPE_DATA_CONSTRUCT  : numTrianglePoints((unsigned int)0), hasTriangles(false), numMatchGroups((unsigned short)0)

#define NI_TRI_STRIPS_PARENT NiTriBasedGeom

#define NI_TRI_STRIPS_CONSTRUCT 
#define NI_TRI_STRIPS_DATA_PARENT NiTriBasedGeomData

#define NI_TRI_STRIPS_DATA_CONSTRUCT  : numStrips((unsigned short)0), hasPoints(false)

#define NI_CLOD_PARENT NiTriBasedGeom

#define NI_CLOD_CONSTRUCT 
#define NI_CLOD_DATA_PARENT NiTriBasedGeomData

#define NI_CLOD_DATA_CONSTRUCT  : unknownShorts((unsigned short)0), unknownCount1((unsigned short)0), unknownCount2((unsigned short)0), unknownCount3((unsigned short)0), unknownFloat(0.0f), unknownShort((unsigned short)0)

#define NI_U_V_CONTROLLER_PARENT NiTimeController

#define NI_U_V_CONTROLLER_CONSTRUCT  : unknownShort((unsigned short)0), data(NULL)

#define NI_U_V_DATA_PARENT NiObject

#define NI_U_V_DATA_CONSTRUCT 
#define NI_VECTOR_EXTRA_DATA_PARENT NiExtraData

#define NI_VECTOR_EXTRA_DATA_CONSTRUCT  : unknownFloat(0.0f)

#define NI_VERTEX_COLOR_PROPERTY_PARENT NiProperty

#define NI_VERTEX_COLOR_PROPERTY_CONSTRUCT  : flags((unsigned short)0)

#define NI_VERT_WEIGHTS_EXTRA_DATA_PARENT NiExtraData

#define NI_VERT_WEIGHTS_EXTRA_DATA_CONSTRUCT  : numBytes((unsigned int)0), numVertices((unsigned short)0)

#define NI_VIS_CONTROLLER_PARENT NiSingleInterpolatorController

#define NI_VIS_CONTROLLER_CONSTRUCT  : data(NULL)

#define NI_VIS_DATA_PARENT AKeyedData

#define NI_VIS_DATA_CONSTRUCT  : numVisKeys((unsigned int)0)

#define NI_WIREFRAME_PROPERTY_PARENT NiProperty

#define NI_WIREFRAME_PROPERTY_CONSTRUCT  : flags((unsigned short)0)

#define NI_Z_BUFFER_PROPERTY_PARENT NiProperty

#define NI_Z_BUFFER_PROPERTY_CONSTRUCT  : flags((unsigned short)3), function((CompareMode)3)

#define ROOT_COLLISION_NODE_PARENT NiNode

#define ROOT_COLLISION_NODE_CONSTRUCT 
#endif
