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
CMAKE_SOURCE_DIR = /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/build

# Include any dependencies generated for this target.
include CMakeFiles/client1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client1.dir/flags.make

CMakeFiles/client1.dir/client1.cpp.o: CMakeFiles/client1.dir/flags.make
CMakeFiles/client1.dir/client1.cpp.o: ../client1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client1.dir/client1.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client1.dir/client1.cpp.o -c /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/client1.cpp

CMakeFiles/client1.dir/client1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client1.dir/client1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/client1.cpp > CMakeFiles/client1.dir/client1.cpp.i

CMakeFiles/client1.dir/client1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client1.dir/client1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/client1.cpp -o CMakeFiles/client1.dir/client1.cpp.s

# Object files for target client1
client1_OBJECTS = \
"CMakeFiles/client1.dir/client1.cpp.o"

# External object files for target client1
client1_EXTERNAL_OBJECTS =

../bin/client1: CMakeFiles/client1.dir/client1.cpp.o
../bin/client1: CMakeFiles/client1.dir/build.make
../bin/client1: CMakeFiles/client1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/client1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client1.dir/build: ../bin/client1

.PHONY : CMakeFiles/client1.dir/build

CMakeFiles/client1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client1.dir/clean

CMakeFiles/client1.dir/depend:
	cd /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/build /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/build /home/sun/ros_socket_adaptor/src/ros_socket_adaptor/src/client/build/CMakeFiles/client1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client1.dir/depend

