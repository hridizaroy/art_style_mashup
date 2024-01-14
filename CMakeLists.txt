cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME mayaplugintest)
project(${PROJECT_NAME})

include($ENV{DEVKIT_LOCATION}/cmake/pluginEntry.cmake)

set(RESOURCES_FILES clay_texture.jpg)

set(MEL_FILES clay_texture.mel)

set(SOURCE_FILES
    clay_texture.cpp
    ${MEL_FILES}
    ${RESOURCE_FILES})

set(LIBRARIES
    OpenMaya Foundation
)

build_plugin()