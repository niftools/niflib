# quick test of the niflib library in python

from niflib import *

root = CreateNiNode()
x = Matrix44(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16)
root.SetLocalTransform(x)

nifinfo = NifInfo()
nifinfo.version = 0x14000005
nifinfo.creator = "amorilia"
WriteNifTree( "test.nif", root.Ptr(), nifinfo )

