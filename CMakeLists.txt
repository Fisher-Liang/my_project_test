# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_FLAGS "$ENV{CFLAGS} -DNODEBUG -O3 -Wall")
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -DNODEBUG -O3 -Wall -std=c++11")

# 定义项目名称和版本
project(Myhello VERSION 1.0.0 LANGUAGES CXX)

set(SOURCE_FILES src/hello.cpp)

# add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
# 规定.h开头的文件的路径
include_directories(${PROJECT_SOURCE_DIR}/include)
# 规定.so或.a文件的路径
link_directories(${PROJECT_SOURCE_DIR}/libs)
#=================================================================

set(CMAKE_APP_NAME test)


add_executable(
  ${CMAKE_APP_NAME}
  src/a.cpp
)

target_link_libraries(
  ${CMAKE_APP_NAME}
#   libMyhello.a
#   ${CMAKE_CURRENT_SOURCE_DIR}/libs/libMyhello.a
  ${CMAKE_CURRENT_SOURCE_DIR}/libs/libMyhello.so
)

# target_include_directories(test
#     PRIVATE
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
# )