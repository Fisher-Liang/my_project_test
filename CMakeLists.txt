# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.8)
# 定义项目名称和版本
project(myhello VERSION 1.1.0 LANGUAGES CXX)
set(CMAKE_lib_NAME Myhello)

set(SOURCE_FILES src/hello.cpp)
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_CROSSCOMPILING true)
set(TOOLCHAIN_DIR "/home/fisher/igs/DriveOS/toolchains/aarch64--glibc--stable-2020.08-1")
set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR}/aarch64-buildroot-linux-gnu/sysroot)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Specify the cross compiler.
set(CMAKE_C_COMPILER    ${TOOLCHAIN_DIR}/bin/aarch64-buildroot-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER  ${TOOLCHAIN_DIR}/bin/aarch64-buildroot-linux-gnu-g++)
message(STATUS "CMAKE_C_COMPILER: " ${CMAKE_C_COMPILER})
message(STATUS "CMAKE_CXX_COMPILER: " ${CMAKE_CXX_COMPILER})

# 设置编译器的编译标志
# set(CMAKE_BUILD_TYPE "Release")

# According to release or debug version, set compile options.
# if(${CMAKE_BUILD_TYPE} MATCHES "Release")
#     message(STATUS "Release Version")
#     set(BuildType "Release")
#     set(CMAKE_C_FLAGS "$ENV{CFLAGS} -DNODEBUG -O3 -Wall")
#     set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -DNODEBUG -O3 -Wall -std=c++11")
# else()
#     message(STATUS "Debug Version")
#     set(BuildType "Debug")
#     set(CMAKE_C_FLAGS "$ENV{CFLAGS} -O0 -g -Wall")
#     set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O0 -g -Wall -std=c++11")
#     add_definitions(-DREAD_DEBUG)
# endif()

set(CMAKE_C_FLAGS "$ENV{CFLAGS} -DNODEBUG -O3 -Wall")
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -DNODEBUG -O3 -Wall -std=c++11")

message(STATUS "CFLAGS: " ${CMAKE_C_FLAGS})
message(STATUS "CXXFLAGS: " ${CMAKE_CXX_FLAGS})

# # 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/releasefile/)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/libs/)

#========================================================================#
#===================          SO lib       ==============================#
#========================================================================#
add_library(${CMAKE_lib_NAME} SHARED
    src/hello.cpp
)

# target_link_libraries(${CMAKE_lib_NAME}
#     ${CMAKE_CURRENT_SOURCE_DIR}/libs/libMyhello.so
# )

target_include_directories(${CMAKE_lib_NAME} 
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
#========================================================================#
#===================          APP bin      ==============================#
#========================================================================#


add_definitions(-DAPP_PRINT_OUT)


add_executable(${PROJECT_NAME}
    src/a.cpp
)

target_link_libraries(${PROJECT_NAME} 
${CMAKE_CURRENT_SOURCE_DIR}/libs/libMyhello.so
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
message("CMAKE_CURRENT_SOURCE_DIR====",${CMAKE_CURRENT_SOURCE_DIR})
#========================================================================#



# shared static 二选一
# add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
# add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
# 规定.h开头的文件的路径
# include_directories(${PROJECT_SOURCE_DIR}/include)
# 规定.so或.a文件的路径
# link_directories(${PROJECT_SOURCE_DIR}/libs)

# target_link_libraries(
#   ${CMAKE_APP_NAME}
# #   libMyhello.a
# #   ${CMAKE_CURRENT_SOURCE_DIR}/libs/libMyhello.a
#   ${CMAKE_CURRENT_SOURCE_DIR}/libs/libMyhello.so
# )

# target_include_directories(test
#     PRIVATE
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
# )