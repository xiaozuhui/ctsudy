# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "/Users/apple/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/apple/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/212.5080.54/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/double_linked_list.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/double_linked_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/double_linked_list.dir/flags.make

CMakeFiles/double_linked_list.dir/main.c.o: CMakeFiles/double_linked_list.dir/flags.make
CMakeFiles/double_linked_list.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/double_linked_list.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/double_linked_list.dir/main.c.o -c /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/main.c

CMakeFiles/double_linked_list.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/double_linked_list.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/main.c > CMakeFiles/double_linked_list.dir/main.c.i

CMakeFiles/double_linked_list.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/double_linked_list.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/main.c -o CMakeFiles/double_linked_list.dir/main.c.s

CMakeFiles/double_linked_list.dir/double_linked_list.c.o: CMakeFiles/double_linked_list.dir/flags.make
CMakeFiles/double_linked_list.dir/double_linked_list.c.o: ../double_linked_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/double_linked_list.dir/double_linked_list.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/double_linked_list.dir/double_linked_list.c.o -c /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/double_linked_list.c

CMakeFiles/double_linked_list.dir/double_linked_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/double_linked_list.dir/double_linked_list.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/double_linked_list.c > CMakeFiles/double_linked_list.dir/double_linked_list.c.i

CMakeFiles/double_linked_list.dir/double_linked_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/double_linked_list.dir/double_linked_list.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/double_linked_list.c -o CMakeFiles/double_linked_list.dir/double_linked_list.c.s

# Object files for target double_linked_list
double_linked_list_OBJECTS = \
"CMakeFiles/double_linked_list.dir/main.c.o" \
"CMakeFiles/double_linked_list.dir/double_linked_list.c.o"

# External object files for target double_linked_list
double_linked_list_EXTERNAL_OBJECTS =

double_linked_list: CMakeFiles/double_linked_list.dir/main.c.o
double_linked_list: CMakeFiles/double_linked_list.dir/double_linked_list.c.o
double_linked_list: CMakeFiles/double_linked_list.dir/build.make
double_linked_list: CMakeFiles/double_linked_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable double_linked_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/double_linked_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/double_linked_list.dir/build: double_linked_list
.PHONY : CMakeFiles/double_linked_list.dir/build

CMakeFiles/double_linked_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/double_linked_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/double_linked_list.dir/clean

CMakeFiles/double_linked_list.dir/depend:
	cd /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/cmake-build-debug /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/cmake-build-debug /Users/apple/codes/cstudy/data-structure/use_c/double_linked_list/cmake-build-debug/CMakeFiles/double_linked_list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/double_linked_list.dir/depend

