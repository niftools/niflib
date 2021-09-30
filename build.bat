:: batch script for Windows build

@echo off

if not exist "build" (
	mkdir "build"
)

cmake -G "NMake Makefiles" -DCMAKE_BUILD_TYPE=Release -S "%cd%" -B "%cd%/build"

cd "build"

nmake
nmake package
nmake package_source

pause
exit /b 1