# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\02_code\test1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\02_code\test1\build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/src/func.c.obj: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/func.c.obj: CMakeFiles/app.dir/includes_C.rsp
CMakeFiles/app.dir/src/func.c.obj: ../src/func.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\02_code\test1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app.dir/src/func.c.obj"
	C:\PROGRA~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\app.dir\src\func.c.obj   -c C:\02_code\test1\src\func.c

CMakeFiles/app.dir/src/func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/src/func.c.i"
	C:\PROGRA~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\02_code\test1\src\func.c > CMakeFiles\app.dir\src\func.c.i

CMakeFiles/app.dir/src/func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/src/func.c.s"
	C:\PROGRA~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\02_code\test1\src\func.c -o CMakeFiles\app.dir\src\func.c.s

CMakeFiles/app.dir/src/main.c.obj: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/main.c.obj: CMakeFiles/app.dir/includes_C.rsp
CMakeFiles/app.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\02_code\test1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/app.dir/src/main.c.obj"
	C:\PROGRA~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\app.dir\src\main.c.obj   -c C:\02_code\test1\src\main.c

CMakeFiles/app.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/app.dir/src/main.c.i"
	C:\PROGRA~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\02_code\test1\src\main.c > CMakeFiles\app.dir\src\main.c.i

CMakeFiles/app.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/app.dir/src/main.c.s"
	C:\PROGRA~2\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\02_code\test1\src\main.c -o CMakeFiles\app.dir\src\main.c.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/src/func.c.obj" \
"CMakeFiles/app.dir/src/main.c.obj"

# External object files for target app
app_EXTERNAL_OBJECTS =

app.exe: CMakeFiles/app.dir/src/func.c.obj
app.exe: CMakeFiles/app.dir/src/main.c.obj
app.exe: CMakeFiles/app.dir/build.make
app.exe: CMakeFiles/app.dir/linklibs.rsp
app.exe: CMakeFiles/app.dir/objects1.rsp
app.exe: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\02_code\test1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable app.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\app.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app.exe

.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\app.dir\cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\02_code\test1 C:\02_code\test1 C:\02_code\test1\build C:\02_code\test1\build C:\02_code\test1\build\CMakeFiles\app.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend

