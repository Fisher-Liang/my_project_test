# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fisher/lfs/my_project_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fisher/lfs/my_project_test

# Include any dependencies generated for this target.
include CMakeFiles/test_func_dlt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_func_dlt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_func_dlt.dir/flags.make

CMakeFiles/test_func_dlt.dir/src/Test.cpp.o: CMakeFiles/test_func_dlt.dir/flags.make
CMakeFiles/test_func_dlt.dir/src/Test.cpp.o: src/Test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fisher/lfs/my_project_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_func_dlt.dir/src/Test.cpp.o"
	/home/fisher/igs/DriveOS/toolchains/aarch64--glibc--stable-2020.08-1/bin/aarch64-buildroot-linux-gnu-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_func_dlt.dir/src/Test.cpp.o -c /home/fisher/lfs/my_project_test/src/Test.cpp

CMakeFiles/test_func_dlt.dir/src/Test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_func_dlt.dir/src/Test.cpp.i"
	/home/fisher/igs/DriveOS/toolchains/aarch64--glibc--stable-2020.08-1/bin/aarch64-buildroot-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fisher/lfs/my_project_test/src/Test.cpp > CMakeFiles/test_func_dlt.dir/src/Test.cpp.i

CMakeFiles/test_func_dlt.dir/src/Test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_func_dlt.dir/src/Test.cpp.s"
	/home/fisher/igs/DriveOS/toolchains/aarch64--glibc--stable-2020.08-1/bin/aarch64-buildroot-linux-gnu-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fisher/lfs/my_project_test/src/Test.cpp -o CMakeFiles/test_func_dlt.dir/src/Test.cpp.s

# Object files for target test_func_dlt
test_func_dlt_OBJECTS = \
"CMakeFiles/test_func_dlt.dir/src/Test.cpp.o"

# External object files for target test_func_dlt
test_func_dlt_EXTERNAL_OBJECTS =

libs/libtest_func_dlt.so: CMakeFiles/test_func_dlt.dir/src/Test.cpp.o
libs/libtest_func_dlt.so: CMakeFiles/test_func_dlt.dir/build.make
libs/libtest_func_dlt.so: CMakeFiles/test_func_dlt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fisher/lfs/my_project_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libs/libtest_func_dlt.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_func_dlt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_func_dlt.dir/build: libs/libtest_func_dlt.so

.PHONY : CMakeFiles/test_func_dlt.dir/build

CMakeFiles/test_func_dlt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_func_dlt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_func_dlt.dir/clean

CMakeFiles/test_func_dlt.dir/depend:
	cd /home/fisher/lfs/my_project_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fisher/lfs/my_project_test /home/fisher/lfs/my_project_test /home/fisher/lfs/my_project_test /home/fisher/lfs/my_project_test /home/fisher/lfs/my_project_test/CMakeFiles/test_func_dlt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_func_dlt.dir/depend

