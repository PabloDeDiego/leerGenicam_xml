cmake_minimum_required(VERSION 3.10)
project(ReadXML)

message(STATUS "que mierda viene: ${CMAKE_BINARY_DIR}")
# Añadir Conan
include(${CMAKE_BINARY_DIR}/lib_dependences/conan_toolchain.cmake)

# Habilitar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Buscar tinyxml2
find_package(tinyxml2 REQUIRED)

add_executable(ReadXML src/main.cpp)

if(TinyXML2_FOUND)
  include_directories(${TinyXML2_INCLUDE_DIRS})
endif()

# Enlazar bibliotecas de Conan
target_link_libraries(ReadXML tinyxml2::tinyxml2)