#include <cassert>

#include "../include/niflib.h"
#include "../include/obj/NiNode.h"

using namespace Niflib;
using namespace std;

void CreateSimpleNif() {
  NiNodeRef root(new NiNode);
  Matrix44 x(Vector3(2,3,4),Matrix33(0,0,1,0,1,0,-1,0,0),0.123);
  root->SetLocalTransform(x);
  NifInfo nifinfo(0x14000005);
  nifinfo.userVersion = 11;
  nifinfo.creator = "amorilia";
  WriteNifTree("test.nif", root, nifinfo);
};

void CheckSimpleNif() {
  NifInfo nifinfo;
  NiObjectRef root_obj = ReadNifTree("test.nif", &nifinfo);
  NiNodeRef root = DynamicCast<NiNode>(root_obj);
  assert(nifinfo.version == 0x14000005);
  assert(nifinfo.userVersion == 11);
  assert(nifinfo.creator == "amorilia");
  assert(root != NULL);
  Matrix44 x(Vector3(2,3,4),Matrix33(0,0,1,0,1,0,-1,0,0),0.123);
  Matrix44 y = root->GetLocalTransform();
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
      assert(abs(x[i][j]-y[i][j]) < 0.0001);
};

int main() {
  CreateSimpleNif();
  CheckSimpleNif();
  return 0;
}
