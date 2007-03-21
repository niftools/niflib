# quick test of the niflib library in python

import unittest
import os
from niflib import *

class TestNiNode(unittest.TestCase):
    def setUp(self):
        # (TODO: use python's temporary file creation method)

        # create nif file
        root = CreateNiNode()
        self.x = Matrix44(Vector3(2,3,4),Matrix33(0,0,1,0,1,0,-1,0,0),0.123)
        root.SetLocalTransform(self.x)
        self.nifinfo = NifInfo()
        self.nifinfo.version = 0x14000005
        self.nifinfo.creator = "amorilia"
        self.nifinfo.userVersion = 11
        WriteNifTree("test.nif", root.Ptr(), self.nifinfo)

        # read nif file
        self.nifinfo_in = NifInfo()
        root_obj = ReadNifFile("test.nif", self.nifinfo_in)
        root_in = DynamicCastToNiNode(root_obj.Ptr())

        self.x_in = root_in.GetLocalTransform()

        # delete nif file
        os.remove("test.nif")

    def test(self):
        self.failIf(self.nifinfo.version != self.nifinfo_in.version)
        self.failIf(self.nifinfo.userVersion != self.nifinfo_in.userVersion)
        self.failIf(self.nifinfo.creator != self.nifinfo_in.creator)
        for i in range(4):
            for j in range(4):
                self.assertAlmostEqual(self.x[i][j], self.x_in[i][j], 5)

if __name__ == '__main__':
    unittest.main()

