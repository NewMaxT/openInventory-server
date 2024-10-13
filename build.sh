echo "Building project in /build"
mkdir build/
cd build/
cmake ..
cmake --build . --config Release
