cmake_minimum_required(VERSION 3.0)
project(CALC)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/output)
include_directories(${PROJECT_SOURCE_DIR}/inc)
# 搜索 src 目录下的源文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
add_executable(app  ${SRC_LIST})