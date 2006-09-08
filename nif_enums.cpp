/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#include <string>
#include <iostream>
#include <strstream>
#include "nif_enums.h"

#ifndef _countof
#  define _countof(x) (sizeof(x)/sizeof(x[0]))
#endif

namespace Niflib {

typedef struct EnumLookupType {
	uint value;
	const char *name;
	const char *desc;
} EnumLookupType;

static std::string EnumToString(uint value, EnumLookupType *table) {
	for (EnumLookupType *itr = table; itr->name != NULL; ++itr) {
		if (itr->value == value) return std::string(itr->name);
	}
	std::stringstream sstr;
	sstr << value;
	return sstr.str();
}

static uint StringToEnum(std::string value, EnumLookupType *table) {
	for (EnumLookupType *itr = table; itr->name != NULL; ++itr) {
		if (0 == value.compare(itr->name)) return itr->value;
	}
	uint retval = 0;
	std::stringstream sstr(value);
	sstr >> retval;
	return retval;
}

static std::string FlagsToString(uint value, EnumLookupType *table) {
	std::strstream sstr;
	for (EnumLookupType *itr = table; itr->name != NULL; ++itr) {
		if (itr->value && (itr->value & value) == itr->value) {
			if (sstr.rdbuf()->pcount() > 0) sstr << "|";
			sstr << itr->name;
			value ^= itr->value;
		}
	}
	if (value == 0 && sstr.rdbuf()->pcount() == 0) {
		return EnumToString(value, table);
	}
	if (value != 0) sstr << value;
	return string(sstr.str(), sstr.rdbuf()->pcount());
}

static uint StringToFlags(std::string value, EnumLookupType *table) {
	uint retval = 0;
	std::string::size_type start = 0;
	while(start < value.length()) {
		std::string::size_type end = value.find_first_of("|", start);
		std::string::size_type len = (end == string.npos) ? end : end-start;
		std::string subval = value.substr(start, len);
		retval |= StringToEnum(subval, table);
	}
	return retval;
}
/* Template wrappers around Nif IO routines */
template <typename T> inline T ReadValue(istream& in);
template <typename T> inline void WriteValue( T val, ostream& out);
template <> inline int    ReadValue<int>   (istream& in) { return ReadInt( in ); }
template <> inline uint   ReadValue<uint>  (istream& in) { return ReadUInt( in ); }
template <> inline ushort ReadValue<ushort>(istream& in) { return ReadUShort( in ); }
template <> inline short  ReadValue<short> (istream& in) { return ReadShort( in ); }
template <> inline byte   ReadValue<byte>  (istream& in) { return ReadByte( in ); }
template <> inline void WriteValue<int>   ( int val,    ostream& out) { WriteInt( val, out ); }
template <> inline void WriteValue<uint>  ( uint val,   ostream& out) { WriteUInt( val, out ); }
template <> inline void WriteValue<ushort>( ushort val, ostream& out) { WriteUShort( val, out ); }
template <> inline void WriteValue<short> ( short val,  ostream& out) { WriteShort( val, out ); }
template <> inline void WriteValue<byte>  ( byte val,   ostream& out) { WriteByte( val, out ); }

/*!
 * ForceType
 */
static EnumLookupType ForceTypeTable[] = {
	{0, "FORCE_PLANAR", "FORCE_PLANAR"},
	{1, "FORCE_SPHERICAL", "FORCE_SPHERICAL"},
	{2, "FORCE_UNKNOWN", "FORCE_UNKNOWN"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<ForceType>(ForceType value) {
	return EnumToString(uint(value), ForceTypeTable);
}

template <> ForceType StringToEnum<ForceType>(const std::string& value) {
	return ForceType(StringToEnum(value, ForceTypeTable));
}

void NifStream( ForceType & val, istream& in, uint version ) { val = ForceType(ReadValue<uint>( in )); }
void NifStream( ForceType const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, ForceType const & val ) { return out << EnumToString(val); }

/*!
 * PixelLayout
 */
static EnumLookupType PixelLayoutTable[] = {
	{0, "PIX_LAY_PALETTISED", "Texture is in 8-bit paletized format."},
	{1, "PIX_LAY_HIGH_COLOR_16", "Texture is in 16-bit high color format."},
	{2, "PIX_LAY_TRUE_COLOR_32", "Texture is in 32-bit true color format."},
	{3, "PIX_LAY_COMPRESSED", "Texture is compressed."},
	{4, "PIX_LAY_BUMPMAP", "Texture is a grayscale bump map."},
	{5, "PIX_LAY_DEFAULT", "Use default setting."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<PixelLayout>(PixelLayout value) {
	return EnumToString(uint(value), PixelLayoutTable);
}

template <> PixelLayout StringToEnum<PixelLayout>(const std::string& value) {
	return PixelLayout(StringToEnum(value, PixelLayoutTable));
}

void NifStream( PixelLayout & val, istream& in, uint version ) { val = PixelLayout(ReadValue<uint>( in )); }
void NifStream( PixelLayout const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, PixelLayout const & val ) { return out << EnumToString(val); }

/*!
 * LightMode
 */
static EnumLookupType LightModeTable[] = {
	{0, "LIGHT_MODE_EMISSIVE", "Emissive."},
	{1, "LIGHT_MODE_EMI_AMB_DIF", "Emissive + Ambient + Diffuse. (Default)"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<LightMode>(LightMode value) {
	return EnumToString(uint(value), LightModeTable);
}

template <> LightMode StringToEnum<LightMode>(const std::string& value) {
	return LightMode(StringToEnum(value, LightModeTable));
}

void NifStream( LightMode & val, istream& in, uint version ) { val = LightMode(ReadValue<uint>( in )); }
void NifStream( LightMode const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, LightMode const & val ) { return out << EnumToString(val); }

/*!
 * MipMapFormat
 */
static EnumLookupType MipMapFormatTable[] = {
	{0, "MIP_FMT_NO", "Texture does not use mip maps."},
	{1, "MIP_FMT_YES", "Texture uses mip maps."},
	{2, "MIP_FMT_DEFAULT", "Use default setting."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<MipMapFormat>(MipMapFormat value) {
	return EnumToString(uint(value), MipMapFormatTable);
}

template <> MipMapFormat StringToEnum<MipMapFormat>(const std::string& value) {
	return MipMapFormat(StringToEnum(value, MipMapFormatTable));
}

void NifStream( MipMapFormat & val, istream& in, uint version ) { val = MipMapFormat(ReadValue<uint>( in )); }
void NifStream( MipMapFormat const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, MipMapFormat const & val ) { return out << EnumToString(val); }

/*!
 * AlphaFormat
 */
static EnumLookupType AlphaFormatTable[] = {
	{0, "ALPHA_NONE", "No alpha blending; the texture is fully opaque."},
	{1, "ALPHA_BINARY", "Texture is either fully transparent or fully opaque.  There are no partially transparent areas."},
	{2, "ALPHA_SMOOTH", "Full range of alpha values can be used from fully transparent to fully opaque including all partially transparent values in between."},
	{3, "ALPHA_DEFAULT", "Use default setting."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<AlphaFormat>(AlphaFormat value) {
	return EnumToString(uint(value), AlphaFormatTable);
}

template <> AlphaFormat StringToEnum<AlphaFormat>(const std::string& value) {
	return AlphaFormat(StringToEnum(value, AlphaFormatTable));
}

void NifStream( AlphaFormat & val, istream& in, uint version ) { val = AlphaFormat(ReadValue<uint>( in )); }
void NifStream( AlphaFormat const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, AlphaFormat const & val ) { return out << EnumToString(val); }

/*!
 * TexFilterMode
 */
static EnumLookupType TexFilterModeTable[] = {
	{0, "FILTER_NEAREST", "Simply uses the nearest pixel.  Very grainy."},
	{1, "FILTER_BILERP", "Uses bilinear filtering."},
	{2, "FILTER_TRILERP", "Uses trilinear filtering."},
	{3, "FILTER_NEAREST_MIPNEAREST", "Uses the nearest pixel from the mipmap that is closest to the display size."},
	{4, "FILTER_NEAREST_MIPLERP", "Blends the two mipmaps closest to the display size linearly, and then uses the nearest pixel from the result."},
	{5, "FILTER_BILERP_MIPNEAREST", "Uses the closest mipmap to the display size and then uses bilinear filtering on the pixels."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<TexFilterMode>(TexFilterMode value) {
	return EnumToString(uint(value), TexFilterModeTable);
}

template <> TexFilterMode StringToEnum<TexFilterMode>(const std::string& value) {
	return TexFilterMode(StringToEnum(value, TexFilterModeTable));
}

void NifStream( TexFilterMode & val, istream& in, uint version ) { val = TexFilterMode(ReadValue<uint>( in )); }
void NifStream( TexFilterMode const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, TexFilterMode const & val ) { return out << EnumToString(val); }

/*!
 * MotionQuality
 */
static EnumLookupType MotionQualityTable[] = {
	{0, "MO_QUAL_MOVING", "Moving"},
	{1, "MO_QUAL_FIXED", "Fixed"},
	{2, "MO_QUAL_KEYFRAMED", "Keyframed"},
	{3, "MO_QUAL_MOVING2", "Moving(?)"},
	{4, "MO_QUAL_MOVING3", "Moving(?)"},
	{5, "MO_QUAL_CRITICAL", "Critical"},
	{6, "MO_QUAL_BULLET", "Bullet"},
	{7, "MO_QUAL_USER", "User"},
	{8, "MO_QUAL_NULL", "Null"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<MotionQuality>(MotionQuality value) {
	return EnumToString(uint(value), MotionQualityTable);
}

template <> MotionQuality StringToEnum<MotionQuality>(const std::string& value) {
	return MotionQuality(StringToEnum(value, MotionQualityTable));
}

void NifStream( MotionQuality & val, istream& in, uint version ) { val = MotionQuality(ReadValue<byte>( in )); }
void NifStream( MotionQuality const & val, ostream& out, uint version ) { WriteValue<byte>( val, out ); }
ostream & operator<<( ostream & out, MotionQuality const & val ) { return out << EnumToString(val); }

/*!
 * OblivionLayer
 */
static EnumLookupType OblivionLayerTable[] = {
	{0, "OL_UNIDENTIFIED", "Unidentified (white)"},
	{1, "OL_STATIC", "Static (red)"},
	{2, "OL_ANIM_STATIC", "AnimStatic (magenta)"},
	{3, "OL_TRANSPARENT", "Transparent (light pink)"},
	{4, "OL_CLUTTER", "Clutter (light blue)"},
	{5, "OL_WEAPON", "Weapon (orange)"},
	{6, "OL_PROJECTILE", "Projectile (light orange)"},
	{7, "OL_SPELL", "Spell (cyan)"},
	{8, "OL_BIPED", "Biped (green) Seems to apply to all creatures/NPCs"},
	{9, "OL_TREES", "Trees (light brown)"},
	{10, "OL_PROPS", "Props (magenta)"},
	{11, "OL_WATER", "Water (cyan)"},
	{12, "OL_TRIGGER", "Trigger (light grey)"},
	{13, "OL_TERRAIN", "Terrain (light yellow)"},
	{14, "OL_TRAP", "Trap (light grey)"},
	{15, "OL_NONCOLLIDABLE", "NonCollidable (white)"},
	{16, "OL_CLOUD_TRAP", "CloudTrap (greenish grey)"},
	{17, "OL_GROUND", "Ground (none)"},
	{18, "OL_PORTAL", "Portal (green)"},
	{19, "OL_STAIRS", "Stairs (white)"},
	{20, "OL_CHAR_CONTROLLER", "CharController (yellow)"},
	{21, "OL_AVOID_BOX", "AvoidBox (dark yellow)"},
	{22, "OL_UNKNOWN1", "? (white)"},
	{23, "OL_UNKNOWN2", "? (white)"},
	{24, "OL_CAMERA_PICK", "CameraPick (white)"},
	{25, "OL_ITEM_PICK", "ItemPick (white)"},
	{26, "OL_LINE_OF_SIGHT", "LineOfSight (white)"},
	{27, "OL_PATH_PICK", "PathPick (white)"},
	{28, "OL_CUSTOM_PICK_1", "CustomPick1 (white)"},
	{29, "OL_CUSTOM_PICK_2", "CustomPick2 (white)"},
	{30, "OL_SPELL_EXPLOSION", "SpellExplosion (white)"},
	{31, "OL_DROPPING_PICK", "DroppingPick (white)"},
	{32, "OL_OTHER", "Other (white)"},
	{33, "OL_HEAD", "Head"},
	{34, "OL_BODY", "Body"},
	{35, "OL_SPINE1", "Spine1"},
	{36, "OL_SPINE2", "Spine2"},
	{37, "OL_L_UPPER_ARM", "LUpperArm"},
	{38, "OL_L_FOREARM", "LForeArm"},
	{39, "OL_L_HAND", "LHand"},
	{40, "OL_L_THIGH", "LThigh"},
	{41, "OL_L_CALF", "LCalf"},
	{42, "OL_L_FOOT", "LFoot"},
	{43, "OL_R_UPPER_ARM", "RUpperArm"},
	{44, "OL_R_FOREARM", "RForeArm"},
	{45, "OL_R_HAND", "RHand"},
	{46, "OL_R_THIGH", "RThigh"},
	{47, "OL_R_CALF", "RCalf"},
	{48, "OL_R_FOOT", "RFoot"},
	{49, "OL_TAIL", "Tail"},
	{50, "OL_SIDE_WEAPON", "SideWeapon"},
	{51, "OL_SHEILD", "Shield"},
	{52, "OL_QUIVER", "Quiver"},
	{53, "OL_BACK_WEAPON", "BackWeapon"},
	{54, "OL_BACK_WEAPON2", "BackWeapon (?)"},
	{55, "OL_PONYTAIL", "PonyTail"},
	{56, "OL_WING", "Wing"},
	{57, "OL_NULL", "Null"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<OblivionLayer>(OblivionLayer value) {
	return EnumToString(uint(value), OblivionLayerTable);
}

template <> OblivionLayer StringToEnum<OblivionLayer>(const std::string& value) {
	return OblivionLayer(StringToEnum(value, OblivionLayerTable));
}

void NifStream( OblivionLayer & val, istream& in, uint version ) { val = OblivionLayer(ReadValue<uint>( in )); }
void NifStream( OblivionLayer const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, OblivionLayer const & val ) { return out << EnumToString(val); }

/*!
 * KeyType
 */
static EnumLookupType KeyTypeTable[] = {
	{1, "LINEAR_KEY", "Use linear interpolation."},
	{2, "QUADRATIC_KEY", "Use quadratic interpolation.  Forward and back tangents will be stored."},
	{3, "TBC_KEY", "Use Tension Bias Continuity interpolation.  Tension, bias, and continuity will be stored."},
	{4, "XYZ_ROTATION_KEY", "For use only with rotation data.  Separate X, Y, and Z keys will be stored instead of using quaternions."},
	{5, "UNKNOWN_KEY", "Unknown.  Step function?"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<KeyType>(KeyType value) {
	return EnumToString(uint(value), KeyTypeTable);
}

template <> KeyType StringToEnum<KeyType>(const std::string& value) {
	return KeyType(StringToEnum(value, KeyTypeTable));
}

void NifStream( KeyType & val, istream& in, uint version ) { val = KeyType(ReadValue<uint>( in )); }
void NifStream( KeyType const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, KeyType const & val ) { return out << EnumToString(val); }

/*!
 * VertMode
 */
static EnumLookupType VertModeTable[] = {
	{0, "VERT_MODE_SRC_IGNORE", "Source Ignore."},
	{1, "VERT_MODE_SRC_EMISSIVE", "Source Emissive."},
	{2, "VERT_MODE_SRC_AMB_DIF", "Source Ambient/Diffuse. (Default)"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<VertMode>(VertMode value) {
	return EnumToString(uint(value), VertModeTable);
}

template <> VertMode StringToEnum<VertMode>(const std::string& value) {
	return VertMode(StringToEnum(value, VertModeTable));
}

void NifStream( VertMode & val, istream& in, uint version ) { val = VertMode(ReadValue<uint>( in )); }
void NifStream( VertMode const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, VertMode const & val ) { return out << EnumToString(val); }

/*!
 * HavokMaterial
 */
static EnumLookupType HavokMaterialTable[] = {
	{0, "HAV_MAT_STONE", "Stone"},
	{1, "HAV_MAT_CLOTH", "Cloth"},
	{2, "HAV_MAT_DIRT", "Dirt"},
	{3, "HAV_MAT_GLASS", "Glass"},
	{4, "HAV_MAT_GRASS", "Grass"},
	{5, "HAV_MAT_METAL", "Metal"},
	{6, "HAV_MAT_ORGANIC", "Organic"},
	{7, "HAV_MAT_SKIN", "Skin"},
	{8, "HAV_MAT_WATER", "Water"},
	{9, "HAV_MAT_WOOD", "Wood"},
	{10, "HAV_MAT_HEAVY_STONE", "Heavy Stone"},
	{11, "HAV_MAT_HEAVY_METAL", "Heavy Metal"},
	{12, "HAV_MAT_HEAVY_WOOD", "Heavy Wood"},
	{13, "HAV_MAT_CHAIN", "Chain"},
	{14, "HAV_MAT_SNOW", "Snow"},
	{15, "HAV_MAT_STONE_STAIRS", "Stone Stairs"},
	{16, "HAV_MAT_CLOTH_STAIRS", "Cloth Stairs"},
	{17, "HAV_MAT_DIRT_STAIRS", "Dirt Stairs"},
	{18, "HAV_MAT_GLASS_STAIRS", "Glass Stairs"},
	{19, "HAV_MAT_GRASS_STAIRS", "Grass Stairs"},
	{20, "HAV_MAT_METAL_STAIRS", "Metal Stairs"},
	{21, "HAV_MAT_ORGANIC_STAIRS", "Organic Stairs"},
	{22, "HAV_MAT_SKIN_STAIRS", "Skin Stairs"},
	{23, "HAV_MAT_WATER_STAIRS", "Water Stairs"},
	{24, "HAV_MAT_WOOD_STAIRS", "Wood Stairs"},
	{25, "HAV_MAT_HEAVY_STONE_STAIRS", "Heavy Stone Stairs"},
	{26, "HAV_MAT_HEAVY_METAL_STAIRS", "Heavy Metal Stairs"},
	{27, "HAV_MAT_HEAVY_WOOD_STAIRS", "Heavy Wood Stairs"},
	{28, "HAV_MAT_CHAIN_STAIRS", "Chain Stairs"},
	{29, "HAV_MAT_SNOW_STAIRS", "Snow Stairs"},
	{30, "HAV_MAT_ELEVATOR", "Elevator"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<HavokMaterial>(HavokMaterial value) {
	return EnumToString(uint(value), HavokMaterialTable);
}

template <> HavokMaterial StringToEnum<HavokMaterial>(const std::string& value) {
	return HavokMaterial(StringToEnum(value, HavokMaterialTable));
}

void NifStream( HavokMaterial & val, istream& in, uint version ) { val = HavokMaterial(ReadValue<uint>( in )); }
void NifStream( HavokMaterial const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, HavokMaterial const & val ) { return out << EnumToString(val); }

/*!
 * PixelFormat
 */
static EnumLookupType PixelFormatTable[] = {
	{0, "PX_FMT_RGB8", "24-bit color: uses 8 bit to store each red, blue, and green component."},
	{1, "PX_FMT_RGBA8", "32-bit color with alpha: uses 8 bits to store each red, blue, green, and alpha component."},
	{2, "PX_FMT_PAL8", "8-bit palette index: uses 8 bits to store an index into the palette stored in a NiPallete object."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<PixelFormat>(PixelFormat value) {
	return EnumToString(uint(value), PixelFormatTable);
}

template <> PixelFormat StringToEnum<PixelFormat>(const std::string& value) {
	return PixelFormat(StringToEnum(value, PixelFormatTable));
}

void NifStream( PixelFormat & val, istream& in, uint version ) { val = PixelFormat(ReadValue<uint>( in )); }
void NifStream( PixelFormat const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, PixelFormat const & val ) { return out << EnumToString(val); }

/*!
 * CycleType
 */
static EnumLookupType CycleTypeTable[] = {
	{0, "CYCLE_LOOP", "Loop"},
	{1, "CYCLE_REVERSE", "Reverse"},
	{2, "CYCLE_CLAMP", "Clamp"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<CycleType>(CycleType value) {
	return EnumToString(uint(value), CycleTypeTable);
}

template <> CycleType StringToEnum<CycleType>(const std::string& value) {
	return CycleType(StringToEnum(value, CycleTypeTable));
}

void NifStream( CycleType & val, istream& in, uint version ) { val = CycleType(ReadValue<uint>( in )); }
void NifStream( CycleType const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, CycleType const & val ) { return out << EnumToString(val); }

/*!
 * ApplyMode
 */
static EnumLookupType ApplyModeTable[] = {
	{0, "APPLY_REPLACE", "Replaces existing color"},
	{1, "APPLY_DECAL", "For placing images on the object like stickers."},
	{2, "APPLY_MODULATE", "Modulates existing color. (Default)"},
	{3, "APPLY_HILIGHT", "PS2 Only.  Function Unknown."},
	{4, "APPLY_HILIGHT2", "PS2 Only.  Function Unknown."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<ApplyMode>(ApplyMode value) {
	return EnumToString(uint(value), ApplyModeTable);
}

template <> ApplyMode StringToEnum<ApplyMode>(const std::string& value) {
	return ApplyMode(StringToEnum(value, ApplyModeTable));
}

void NifStream( ApplyMode & val, istream& in, uint version ) { val = ApplyMode(ReadValue<uint>( in )); }
void NifStream( ApplyMode const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, ApplyMode const & val ) { return out << EnumToString(val); }

/*!
 * FieldType
 */
static EnumLookupType FieldTypeTable[] = {
	{0, "FIELD_WIND", "Wind (fixed direction)"},
	{1, "FIELD_POINT", "Point (fixed origin)"},
	{0, NULL, NULL},
};

template <> std::string EnumToString<FieldType>(FieldType value) {
	return EnumToString(uint(value), FieldTypeTable);
}

template <> FieldType StringToEnum<FieldType>(const std::string& value) {
	return FieldType(StringToEnum(value, FieldTypeTable));
}

void NifStream( FieldType & val, istream& in, uint version ) { val = FieldType(ReadValue<uint>( in )); }
void NifStream( FieldType const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, FieldType const & val ) { return out << EnumToString(val); }

/*!
 * BillboardMode
 */
static EnumLookupType BillboardModeTable[] = {
	{0, "ALWAYS_FACE_CAMERA", "The billboard will always face the camera."},
	{1, "ROTATE_ABOUT_UP", "The billboard will only rotate around the up axis."},
	{2, "RIGID_FACE_CAMERA", "Rigid Face Camera."},
	{3, "ALWAYS_FACE_CENTER", "Always Face Center."},
	{4, "RIGID_FACE_CENTER", "Rigid Face Center."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<BillboardMode>(BillboardMode value) {
	return EnumToString(uint(value), BillboardModeTable);
}

template <> BillboardMode StringToEnum<BillboardMode>(const std::string& value) {
	return BillboardMode(StringToEnum(value, BillboardModeTable));
}

void NifStream( BillboardMode & val, istream& in, uint version ) { val = BillboardMode(ReadValue<ushort>( in )); }
void NifStream( BillboardMode const & val, ostream& out, uint version ) { WriteValue<ushort>( val, out ); }
ostream & operator<<( ostream & out, BillboardMode const & val ) { return out << EnumToString(val); }

/*!
 * TexType
 */
static EnumLookupType TexTypeTable[] = {
	{0, "BASE_MAP", "The basic texture used by most meshes."},
	{1, "DARK_MAP", "Used to darken the model with false lighting."},
	{2, "DETAIL_MAP", "Combined with base map for added detail.  Usually tiled over the mesh many times for close-up view."},
	{3, "GLOSS_MAP", "Allows the specularity (glossyness) of an object to differ across its surface."},
	{4, "GLOW_MAP", "Creates a glowing effect.  Basically an incandescence map."},
	{5, "BUMP_MAP", "Used to make the object appear to have more detail than it really does."},
	{6, "DECAL_0_MAP", "For placing images on the object like stickers."},
	{7, "DECAL_1_MAP", "For placing images on the object like stickers."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<TexType>(TexType value) {
	return EnumToString(uint(value), TexTypeTable);
}

template <> TexType StringToEnum<TexType>(const std::string& value) {
	return TexType(StringToEnum(value, TexTypeTable));
}

void NifStream( TexType & val, istream& in, uint version ) { val = TexType(ReadValue<uint>( in )); }
void NifStream( TexType const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, TexType const & val ) { return out << EnumToString(val); }

/*!
 * TexClampMode
 */
static EnumLookupType TexClampModeTable[] = {
	{0, "CLAMP_S_CLAMP_T", "Clamp in both directions."},
	{1, "CLAMP_S_WRAP_T", "Clamp in the S(U) direction but wrap in the T(V) direction."},
	{2, "WRAP_S_CLAMP_T", "Wrap in the S(U) direction but clamp in the T(V) direction."},
	{3, "WRAP_S_WRAP_T", "Wrap in both directions."},
	{0, NULL, NULL},
};

template <> std::string EnumToString<TexClampMode>(TexClampMode value) {
	return EnumToString(uint(value), TexClampModeTable);
}

template <> TexClampMode StringToEnum<TexClampMode>(const std::string& value) {
	return TexClampMode(StringToEnum(value, TexClampModeTable));
}

void NifStream( TexClampMode & val, istream& in, uint version ) { val = TexClampMode(ReadValue<uint>( in )); }
void NifStream( TexClampMode const & val, ostream& out, uint version ) { WriteValue<uint>( val, out ); }
ostream & operator<<( ostream & out, TexClampMode const & val ) { return out << EnumToString(val); }

}
