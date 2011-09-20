#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include <sstream> // stringstream

// evil hack to allow testing of private and protected data
#define private public
#define protected public 

#include "niflib.h"
#include "obj/NiNode.h"
#include "obj/NiSkinInstance.h"
#include "obj/NiTriStrips.h"
#include "obj/NiTriStripsData.h"

using namespace Niflib;
using namespace std;

BOOST_AUTO_TEST_SUITE(missing_link_stack_test_suite)

BOOST_AUTO_TEST_CASE(missing_link_stack_simple_test)
{
  stringstream ss;
  stringstream ss2;

  // create a simple nif tree with a skin partition
  NiNodeRef root = new NiNode;
  NiNodeRef bone = new NiNode;
  root->SetName("Root");
  bone->SetName("Bone");
  NiTriStripsRef shape = new NiTriStrips;
  NiTriStripsDataRef data = new NiTriStripsData;
  // set hierarchy
  shape->SetData(data);
  root->AddChild(DynamicCast<NiAVObject>(shape));
  root->AddChild(DynamicCast<NiAVObject>(bone));
  // bind skin to bone
  {
    vector<NiNodeRef> bones;
    bones.push_back(bone);
    shape->BindSkin(bones);
  }
  // write
  list<NiObject *> missing_link_stack;
  list<NiObjectRef> roots;
  roots.push_back(StaticCast<NiObject>(shape));
  BOOST_CHECK_NO_THROW(WriteNifTree(ss, roots, missing_link_stack, NifInfo(VER_20_0_0_5)));
  bool has_root = false;
  bool has_bone = false;
  // check that root and bone are missing
  for (list<NiObject *>::iterator it =  missing_link_stack.begin(); it != missing_link_stack.end(); it++) {
    if ((*it) != NULL) {
      if (!has_root && (*it) == root) {
        has_root = true;
      } else if (!has_bone && (*it) == bone) {
        has_bone = true;
      } else {
        BOOST_CHECK(false);
      }
    };
  }
  BOOST_CHECK_EQUAL(has_root, true);
  BOOST_CHECK_EQUAL(has_bone, true);
}

BOOST_AUTO_TEST_SUITE_END()
