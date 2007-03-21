######
## Configure pyNiflib
######

# The path to the Niflib folder
niflib_path = "../niflib"

# Internal containers - those are not typedef'd
internal_containers = \
[
	"std::map<Niflib::Ref<Niflib::NiObject>,unsigned int,std::less<Niflib::Ref<Niflib::NiObject> >,std::allocator<std::pair<const Niflib::Ref<Niflib::NiObject>, unsigned int> > >",
	"std::list<unsigned int,std::allocator<unsigned int> >"
]