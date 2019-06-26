project(NOOPS2019)

#**************************************************************************************************
# General cMake settings
#**************************************************************************************************
cmake_minimum_required(VERSION 3.5)

if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
  cmake_policy(SET CMP0007 NEW)
endif(COMMAND cmake_policy)

if(NOT DEFINED CMAKE_SUPPRESS_DEVELOPER_WARNINGS)
  set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1 CACHE INTERNAL "No dev warnings")
endif()

#**************************************************************************************************
# Find Package ************************************************************************************
find_package(OpenCV REQUIRED)
find_package(X11 REQUIRED)

find_package(cxxopts CONFIG REQUIRED)

find_path(CPR_INCLUDE_DIRS cpr/cpr.h)
find_library(CPR_LIBRARIES cpr)
include_directories(${CPR_INCLUDE_DIRS})

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

find_package(OpenSSL REQUIRED)

find_package(ZLIB REQUIRED)

find_package(fmt CONFIG REQUIRED)

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

#**************************************************************************************************
# Include *****************************************************************************************
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${X11_INCLUDE_DIR})

include_directories(${_VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#**************************************************************************************************
# Set variable ************************************************************************************
SET(SOURCES

)

#**************************************************************************************************
# Set compiler ************************************************************************************
add_compile_options(-std=c++17 -Wall -fPIC) # for all targets in current directory

#**************************************************************************************************
# Linker ******************************************************************************************


#**************************************************************************************************
# Build Example
#**************************************************************************************************
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/hexbot)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/vexbot)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/golfbot)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/mazebot)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/polybot)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/pathbot)
