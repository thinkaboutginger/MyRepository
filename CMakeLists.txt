cmake_minimum_required(VERSION 3.0)
project(CALC)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)

include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_SOURCE_DIR}/misc/inc)
include_directories(${PROJECT_SOURCE_DIR}/hash/inc)
include_directories(${PROJECT_SOURCE_DIR}/two_pointers/inc)
aux_source_directory(${PROJECT_SOURCE_DIR} DIR_MAIN)

add_subdirectory(misc)
add_subdirectory(two_pointers)
add_subdirectory(hash)
add_executable(main ${DIR_MAIN})

target_link_libraries(main source_misc_lib)
target_link_libraries(main source_hash_lib)
target_link_libraries(main source_2pointers_lib)