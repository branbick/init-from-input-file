# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/branbick/git/init-from-input-file/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/branbick/git/init-from-input-file/test/build

# Include any dependencies generated for this target.
include CMakeFiles/tester_c.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tester_c.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tester_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tester_c.dir/flags.make

CMakeFiles/tester_c.dir/tester_c.c.o: CMakeFiles/tester_c.dir/flags.make
CMakeFiles/tester_c.dir/tester_c.c.o: ../tester_c.c
CMakeFiles/tester_c.dir/tester_c.c.o: CMakeFiles/tester_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/branbick/git/init-from-input-file/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tester_c.dir/tester_c.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tester_c.dir/tester_c.c.o -MF CMakeFiles/tester_c.dir/tester_c.c.o.d -o CMakeFiles/tester_c.dir/tester_c.c.o -c /home/branbick/git/init-from-input-file/test/tester_c.c

CMakeFiles/tester_c.dir/tester_c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tester_c.dir/tester_c.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/branbick/git/init-from-input-file/test/tester_c.c > CMakeFiles/tester_c.dir/tester_c.c.i

CMakeFiles/tester_c.dir/tester_c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tester_c.dir/tester_c.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/branbick/git/init-from-input-file/test/tester_c.c -o CMakeFiles/tester_c.dir/tester_c.c.s

CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o: CMakeFiles/tester_c.dir/flags.make
CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o: /home/branbick/git/init-from-input-file/src/init_from_input_file.c
CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o: CMakeFiles/tester_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/branbick/git/init-from-input-file/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o -MF CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o.d -o CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o -c /home/branbick/git/init-from-input-file/src/init_from_input_file.c

CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/branbick/git/init-from-input-file/src/init_from_input_file.c > CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.i

CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/branbick/git/init-from-input-file/src/init_from_input_file.c -o CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.s

CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o: CMakeFiles/tester_c.dir/flags.make
CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o: /home/branbick/git/init-from-input-file/src/init_tools.c
CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o: CMakeFiles/tester_c.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/branbick/git/init-from-input-file/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o -MF CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o.d -o CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o -c /home/branbick/git/init-from-input-file/src/init_tools.c

CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/branbick/git/init-from-input-file/src/init_tools.c > CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.i

CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/branbick/git/init-from-input-file/src/init_tools.c -o CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.s

# Object files for target tester_c
tester_c_OBJECTS = \
"CMakeFiles/tester_c.dir/tester_c.c.o" \
"CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o" \
"CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o"

# External object files for target tester_c
tester_c_EXTERNAL_OBJECTS =

tester_c: CMakeFiles/tester_c.dir/tester_c.c.o
tester_c: CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_from_input_file.c.o
tester_c: CMakeFiles/tester_c.dir/home/branbick/git/init-from-input-file/src/init_tools.c.o
tester_c: CMakeFiles/tester_c.dir/build.make
tester_c: CMakeFiles/tester_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/branbick/git/init-from-input-file/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable tester_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tester_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tester_c.dir/build: tester_c
.PHONY : CMakeFiles/tester_c.dir/build

CMakeFiles/tester_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tester_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tester_c.dir/clean

CMakeFiles/tester_c.dir/depend:
	cd /home/branbick/git/init-from-input-file/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/branbick/git/init-from-input-file/test /home/branbick/git/init-from-input-file/test /home/branbick/git/init-from-input-file/test/build /home/branbick/git/init-from-input-file/test/build /home/branbick/git/init-from-input-file/test/build/CMakeFiles/tester_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tester_c.dir/depend
