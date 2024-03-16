cmake_minimum_required(VERSION 3.0)
project(CALC)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)

include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_SOURCE_DIR}/interview/inc)
aux_source_directory(${PROJECT_SOURCE_DIR} DIR_MAIN)

add_subdirectory(interview)
add_executable(main ${DIR_MAIN})

target_link_libraries(main source_lib)