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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\75414\Desktop\project\library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\75414\Desktop\project\library\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/library.dir/flags.make

CMakeFiles/library.dir/interface.c.obj: CMakeFiles/library.dir/flags.make
CMakeFiles/library.dir/interface.c.obj: CMakeFiles/library.dir/includes_C.rsp
CMakeFiles/library.dir/interface.c.obj: ../interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75414\Desktop\project\library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/library.dir/interface.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\library.dir\interface.c.obj   -c C:\Users\75414\Desktop\project\library\interface.c

CMakeFiles/library.dir/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/library.dir/interface.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75414\Desktop\project\library\interface.c > CMakeFiles\library.dir\interface.c.i

CMakeFiles/library.dir/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/library.dir/interface.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75414\Desktop\project\library\interface.c -o CMakeFiles\library.dir\interface.c.s

CMakeFiles/library.dir/library.c.obj: CMakeFiles/library.dir/flags.make
CMakeFiles/library.dir/library.c.obj: CMakeFiles/library.dir/includes_C.rsp
CMakeFiles/library.dir/library.c.obj: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75414\Desktop\project\library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/library.dir/library.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\library.dir\library.c.obj   -c C:\Users\75414\Desktop\project\library\library.c

CMakeFiles/library.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/library.dir/library.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75414\Desktop\project\library\library.c > CMakeFiles\library.dir\library.c.i

CMakeFiles/library.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/library.dir/library.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75414\Desktop\project\library\library.c -o CMakeFiles\library.dir\library.c.s

CMakeFiles/library.dir/user.c.obj: CMakeFiles/library.dir/flags.make
CMakeFiles/library.dir/user.c.obj: CMakeFiles/library.dir/includes_C.rsp
CMakeFiles/library.dir/user.c.obj: ../user.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75414\Desktop\project\library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/library.dir/user.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\library.dir\user.c.obj   -c C:\Users\75414\Desktop\project\library\user.c

CMakeFiles/library.dir/user.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/library.dir/user.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75414\Desktop\project\library\user.c > CMakeFiles\library.dir\user.c.i

CMakeFiles/library.dir/user.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/library.dir/user.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75414\Desktop\project\library\user.c -o CMakeFiles\library.dir\user.c.s

CMakeFiles/library.dir/main.c.obj: CMakeFiles/library.dir/flags.make
CMakeFiles/library.dir/main.c.obj: CMakeFiles/library.dir/includes_C.rsp
CMakeFiles/library.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\75414\Desktop\project\library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/library.dir/main.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\library.dir\main.c.obj   -c C:\Users\75414\Desktop\project\library\main.c

CMakeFiles/library.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/library.dir/main.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\75414\Desktop\project\library\main.c > CMakeFiles\library.dir\main.c.i

CMakeFiles/library.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/library.dir/main.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\75414\Desktop\project\library\main.c -o CMakeFiles\library.dir\main.c.s

# Object files for target library
library_OBJECTS = \
"CMakeFiles/library.dir/interface.c.obj" \
"CMakeFiles/library.dir/library.c.obj" \
"CMakeFiles/library.dir/user.c.obj" \
"CMakeFiles/library.dir/main.c.obj"

# External object files for target library
library_EXTERNAL_OBJECTS =

library.exe: CMakeFiles/library.dir/interface.c.obj
library.exe: CMakeFiles/library.dir/library.c.obj
library.exe: CMakeFiles/library.dir/user.c.obj
library.exe: CMakeFiles/library.dir/main.c.obj
library.exe: CMakeFiles/library.dir/build.make
library.exe: CMakeFiles/library.dir/linklibs.rsp
library.exe: CMakeFiles/library.dir/objects1.rsp
library.exe: CMakeFiles/library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\75414\Desktop\project\library\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable library.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\library.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/library.dir/build: library.exe

.PHONY : CMakeFiles/library.dir/build

CMakeFiles/library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\library.dir\cmake_clean.cmake
.PHONY : CMakeFiles/library.dir/clean

CMakeFiles/library.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\75414\Desktop\project\library C:\Users\75414\Desktop\project\library C:\Users\75414\Desktop\project\library\cmake-build-debug C:\Users\75414\Desktop\project\library\cmake-build-debug C:\Users\75414\Desktop\project\library\cmake-build-debug\CMakeFiles\library.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/library.dir/depend

