cmake_minimum_required(VERSION 3.13)
project(lattice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${lattice_SOURCE_DIR}/cmake")

# Look up SDL2 and add the include directory to our include path
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
)

add_executable(lattice main.cpp)
target_link_libraries(
        lattice
        ${SDL2_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
)


