## ejemplo XML
mkdir build
cd build

1 - Para WINDOWS
conan install .. -g CMakeDeps -g CMakeToolchain --build=missing --output-folder=lib_dependences
cmake .. -DCMAKE_POLICY_DEFAULT_CMP0091="NEW" -DCMAKE_BINARY_DIR=build -DCMAKE_BUILD_TYPE=Release -G "Visual Studio 17 2022"
cmake --build . --config Release

2 - Para Linux
conan install .. -g CMakeDeps -g CMakeToolchain --build=missing --output-folder=lib_dependences
cmake .. -DCMAKE_POLICY_DEFAULT_CMP0091="NEW" -DCMAKE_BINARY_DIR=build -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles"
cmake --build . --config Release