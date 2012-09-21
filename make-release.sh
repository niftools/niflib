VERSION=`cat VERSION`
rm ../niflib-${VERSION}-src.zip
doxygen
find . -type f -not -wholename "*.git*" -and -not -name ".project" | xargs zip ../niflib-${VERSION}-src.zip
