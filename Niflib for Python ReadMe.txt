Python SWIG wrapper for Niflib

To use:  Unzip the files to your Python folder (Probably C:\Python24).

Due to many API changes in Niflib 0.5, the module is called "new_niflib" to give
people using the older versions of Niflib for Python the ability to use both
versions at the same time.

A future release will return to using 'niflib.'

From within Python:

import new_niflib

or

from new_niflib import *

