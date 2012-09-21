VERSION=`cat VERSION`
rm ../niflib-${VERSION}-src.zip
git submodule update --recursive
git clean -xfd
git submodule foreach --recursive git clean -xfd
doxygen
find . -type f -not -wholename "*.git*" -and -not -name ".project" | xargs zip ../niflib-${VERSION}-src.zip
