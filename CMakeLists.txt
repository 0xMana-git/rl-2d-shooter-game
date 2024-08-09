cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Global properties
# set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Project name
project(shooter2d)

add_subdirectory(modules)


include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/modules/min-2d-engine/include")
# Library


#add_executable(engine2d ${LIB_SOURCE_FILES})
file(GLOB_RECURSE SOURCES src/objects/*.cpp src/*.cpp)
add_executable(shooter2d ${SOURCES})
target_link_libraries(shooter2d engine2d)