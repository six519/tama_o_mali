cmake_minimum_required(VERSION 3.10)
include(FindPackageHandleStandardArgs)

project(Tama_o_Mali)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

find_package(OpenCV REQUIRED)
find_package(SDL2_mixer 2.0 REQUIRED)

file(GLOB SOURCES "src/*.cpp")

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ${SDL2_MIXER_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

link_libraries(
    ${OpenCV_LIBS}
    ${SDL2_MIXER_LIBRARIES}
)

add_executable(tama_o_mali ${SOURCES})