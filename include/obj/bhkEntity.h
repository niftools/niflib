/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _BHKENTITY_H_
#define _BHKENTITY_H_

#include "bhkWorldObject.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced blocks
class bhkShape;

//#include "../gen/obj_defines.h"

class bhkEntity;
typedef Ref<bhkEntity> bhkEntityRef;

/*!
 * bhkEntity - A havok node, describes physical properties.
 */

class bhkEntity : public BHK_ENTITY_PARENT {
public:
	NIFLIB_API bhkEntity();
	NIFLIB_API ~bhkEntity();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst() { return TYPE; }
private:
	NIFLIB_API static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * The body's shape.
	 */
	NIFLIB_API Ref<bhkShape > GetShape() const;
	NIFLIB_API void SetShape( Ref<bhkShape > value );

	/*!
	 * Sets mesh colour in CS.
    * 0: Unidentified (white)
	 * 1: Static (red)
    * 2: AnimStatic (magenta)
    * 3: Transparent (light pink)
    * 4: Clutter (light blue)
	 * 5: Weapon (orange)
    * 6: Projectile (light orange)
	 * 7: Spell (cyan)
    * 8: Biped (green) Seems to apply to all creatures/NPCs
    * 9: Trees (light brown)
    * 10: Props (magenta)
    * 11: Water (cyan)
    * 12: Trigger (light grey)
    * 13: Terrain (light yellow)
    * 14: Trap (light grey)
    * 15: NonCollidable (white)
	 * 16: CloudTrap (greenish grey)
    * 17: Ground (none)
	 * 18: Portal (green)
    * 19: Stairs (white)
    * 20: CharController (yellow)
    * 21: AvoidBox (dark yellow)
	 * 22: ? (white)
    * 23: ? (white)
    * 24: CameraPick (white)
    * 25: ItemPick (white)
    * 26: LineOfSight (white)
    * 27: PathPick (white)
    * 28: CustomPick1 (white)
    * 29: CustomPick2 (white)
    * 30: SpellExplosion (white)
    * 31: DroppingPick (white)
	 * 32: Other (white)
    * 33: Head
    * 34: Body
	 * 35: Spine1
    * 36: Spine2
    * 37: LUpperArm
	 * 38: LForeArm
    * 39: LHand
    * 40: LThigh
	 * 41: LCalf
    * 42: LFoot
    * 43: RUpperArm
	 * 44: RForeArm
    * 45: RHand
    * 46: RThigh
    * 47: RCalf
    * 48: RFoot
    * 49: Tail
    * 50: SideWeapon
    * 51: Shield
    * 52: Quiver
	 * 53: BackWeapon
    * 54: BackWeapon (?)
    * 55: PonyTail
	 * 56: Wing
    * 57+: Null
	 */
	NIFLIB_API OblivionLayer GetLayer() const;
	NIFLIB_API void SetLayer( OblivionLayer value );

protected:
	BHK_ENTITY_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, unsigned int version, unsigned int user_version ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, unsigned int version, unsigned int user_version );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
