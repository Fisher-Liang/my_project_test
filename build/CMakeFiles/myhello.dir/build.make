# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fisher/lfs/my_project_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fisher/lfs/my_project_test/build

# Include any dependencies generated for this target.
include CMakeFiles/myhello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/myhello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myhello.dir/flags.make

CMakeFiles/myhello.dir/src/hello.cpp.o: CMakeFiles/myhello.dir/flags.make
CMakeFiles/myhello.dir/src/hello.cpp.o: ../src/hello.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fisher/lfs/my_project_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myhello.dir/src/hello.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/myhello.dir/src/hello.cpp.o -c /home/fisher/lfs/my_project_test/src/hello.cpp

CMakeFiles/myhello.dir/src/hello.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myhello.dir/src/hello.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fisher/lfs/my_project_test/src/hello.cpp > CMakeFiles/myhello.dir/src/hello.cpp.i

CMakeFiles/myhello.dir/src/hello.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myhello.dir/src/hello.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fisher/lfs/my_project_test/src/hello.cpp -o CMakeFiles/myhello.dir/src/hello.cpp.s

# Object files for target myhello
myhello_OBJECTS = \
"CMakeFiles/myhello.dir/src/hello.cpp.o"

# External object files for target myhello
myhello_EXTERNAL_OBJECTS =

myhello: CMakeFiles/myhello.dir/src/hello.cpp.o
myhello: CMakeFiles/myhello.dir/build.make
myhello: CMakeFiles/myhello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fisher/lfs/my_project_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myhello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myhello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myhello.dir/build: myhello

.PHONY : CMakeFiles/myhello.dir/build

CMakeFiles/myhello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myhello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myhello.dir/clean

CMakeFiles/myhello.dir/depend:
	cd /home/fisher/lfs/my_project_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fisher/lfs/my_project_test /home/fisher/lfs/my_project_test /home/fisher/lfs/my_project_test/build /home/fisher/lfs/my_project_test/build /home/fisher/lfs/my_project_test/build/CMakeFiles/myhello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myhello.dir/depend
