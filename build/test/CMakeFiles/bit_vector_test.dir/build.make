# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/amallia/Development/bit_vector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/amallia/Development/bit_vector/build

# Include any dependencies generated for this target.
include test/CMakeFiles/bit_vector_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/bit_vector_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/bit_vector_test.dir/flags.make

test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o: test/CMakeFiles/bit_vector_test.dir/flags.make
test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o: ../test/bit_vector_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/amallia/Development/bit_vector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o"
	cd /Users/amallia/Development/bit_vector/build/test && /usr/local/opt/llvm/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o -c /Users/amallia/Development/bit_vector/test/bit_vector_test.cpp

test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.i"
	cd /Users/amallia/Development/bit_vector/build/test && /usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/amallia/Development/bit_vector/test/bit_vector_test.cpp > CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.i

test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.s"
	cd /Users/amallia/Development/bit_vector/build/test && /usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/amallia/Development/bit_vector/test/bit_vector_test.cpp -o CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.s

test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o.requires:

.PHONY : test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o.requires

test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o.provides: test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/bit_vector_test.dir/build.make test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o.provides.build
.PHONY : test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o.provides

test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o.provides.build: test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o


# Object files for target bit_vector_test
bit_vector_test_OBJECTS = \
"CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o"

# External object files for target bit_vector_test
bit_vector_test_EXTERNAL_OBJECTS =

test/bit_vector_test: test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o
test/bit_vector_test: test/CMakeFiles/bit_vector_test.dir/build.make
test/bit_vector_test: external/googletest/googlemock/gtest/libgtest.a
test/bit_vector_test: external/googletest/googlemock/libgmock.a
test/bit_vector_test: external/googletest/googlemock/gtest/libgtest.a
test/bit_vector_test: test/CMakeFiles/bit_vector_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/amallia/Development/bit_vector/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bit_vector_test"
	cd /Users/amallia/Development/bit_vector/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bit_vector_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/bit_vector_test.dir/build: test/bit_vector_test

.PHONY : test/CMakeFiles/bit_vector_test.dir/build

test/CMakeFiles/bit_vector_test.dir/requires: test/CMakeFiles/bit_vector_test.dir/bit_vector_test.cpp.o.requires

.PHONY : test/CMakeFiles/bit_vector_test.dir/requires

test/CMakeFiles/bit_vector_test.dir/clean:
	cd /Users/amallia/Development/bit_vector/build/test && $(CMAKE_COMMAND) -P CMakeFiles/bit_vector_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/bit_vector_test.dir/clean

test/CMakeFiles/bit_vector_test.dir/depend:
	cd /Users/amallia/Development/bit_vector/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/amallia/Development/bit_vector /Users/amallia/Development/bit_vector/test /Users/amallia/Development/bit_vector/build /Users/amallia/Development/bit_vector/build/test /Users/amallia/Development/bit_vector/build/test/CMakeFiles/bit_vector_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/bit_vector_test.dir/depend

