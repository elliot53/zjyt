cmake_minimum_required(VERSION 3.10)
project(zjytools)
include(CMakePrintHelpers)
SET(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/share_library)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/archive_library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

include_directories(${PROJECT_SOURCE_DIR}/third_party/include)
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${PROJECT_SOURCE_DIR}/third_party/lib/jsoncpp)

add_library(zjyt STATIC ${SRC})