# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build

# Include any dependencies generated for this target.
include InputTests/CMakeFiles/InputTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include InputTests/CMakeFiles/InputTests.dir/compiler_depend.make

# Include the progress variables for this target.
include InputTests/CMakeFiles/InputTests.dir/progress.make

# Include the compile flags for this target's objects.
include InputTests/CMakeFiles/InputTests.dir/flags.make

InputTests/CMakeFiles/InputTests.dir/InputTests.cpp.o: InputTests/CMakeFiles/InputTests.dir/flags.make
InputTests/CMakeFiles/InputTests.dir/InputTests.cpp.o: /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/InputTests/InputTests.cpp
InputTests/CMakeFiles/InputTests.dir/InputTests.cpp.o: InputTests/CMakeFiles/InputTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object InputTests/CMakeFiles/InputTests.dir/InputTests.cpp.o"
	cd /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/InputTests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT InputTests/CMakeFiles/InputTests.dir/InputTests.cpp.o -MF CMakeFiles/InputTests.dir/InputTests.cpp.o.d -o CMakeFiles/InputTests.dir/InputTests.cpp.o -c /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/InputTests/InputTests.cpp

InputTests/CMakeFiles/InputTests.dir/InputTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/InputTests.dir/InputTests.cpp.i"
	cd /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/InputTests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/InputTests/InputTests.cpp > CMakeFiles/InputTests.dir/InputTests.cpp.i

InputTests/CMakeFiles/InputTests.dir/InputTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/InputTests.dir/InputTests.cpp.s"
	cd /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/InputTests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/InputTests/InputTests.cpp -o CMakeFiles/InputTests.dir/InputTests.cpp.s

# Object files for target InputTests
InputTests_OBJECTS = \
"CMakeFiles/InputTests.dir/InputTests.cpp.o"

# External object files for target InputTests
InputTests_EXTERNAL_OBJECTS =

InputTests/InputTests: InputTests/CMakeFiles/InputTests.dir/InputTests.cpp.o
InputTests/InputTests: InputTests/CMakeFiles/InputTests.dir/build.make
InputTests/InputTests: lib/libgtest_main.a
InputTests/InputTests: libUnitTesting.a
InputTests/InputTests: lib/libgtest.a
InputTests/InputTests: InputTests/CMakeFiles/InputTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable InputTests"
	cd /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/InputTests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/InputTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
InputTests/CMakeFiles/InputTests.dir/build: InputTests/InputTests
.PHONY : InputTests/CMakeFiles/InputTests.dir/build

InputTests/CMakeFiles/InputTests.dir/clean:
	cd /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/InputTests && $(CMAKE_COMMAND) -P CMakeFiles/InputTests.dir/cmake_clean.cmake
.PHONY : InputTests/CMakeFiles/InputTests.dir/clean

InputTests/CMakeFiles/InputTests.dir/depend:
	cd /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/InputTests /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/InputTests /Users/vitor/Documents/Estudos/42/Github/cub3d/unitTests/build/InputTests/CMakeFiles/InputTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : InputTests/CMakeFiles/InputTests.dir/depend
