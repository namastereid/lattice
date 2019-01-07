cmake_minimum_required(VERSION 3.13)
project(lattice)

set(CMAKE_CXX_STANDARD 17)

# Look up SDL2 and add the include directory to our include path
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(lattice main.cpp)
target_link_libraries(lattice ${SDL2_LIBRARIES})


