# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /C/msys64/mingw32/bin/cmake.exe

# The command to remove a file.
RM = /C/msys64/mingw32/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /C/Users/lpc0503/Desktop/vfs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /C/Users/lpc0503/Desktop/vfs/build

# Include any dependencies generated for this target.
include CMakeFiles/mylib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mylib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mylib.dir/flags.make

CMakeFiles/mylib.dir/src/icejj.cpp.obj: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/icejj.cpp.obj: ../src/icejj.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/lpc0503/Desktop/vfs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mylib.dir/src/icejj.cpp.obj"
	/C/msys64/mingw32/bin/i686-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/icejj.cpp.obj -c /C/Users/lpc0503/Desktop/vfs/src/icejj.cpp

CMakeFiles/mylib.dir/src/icejj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/icejj.cpp.i"
	/C/msys64/mingw32/bin/i686-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/lpc0503/Desktop/vfs/src/icejj.cpp > CMakeFiles/mylib.dir/src/icejj.cpp.i

CMakeFiles/mylib.dir/src/icejj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/icejj.cpp.s"
	/C/msys64/mingw32/bin/i686-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/lpc0503/Desktop/vfs/src/icejj.cpp -o CMakeFiles/mylib.dir/src/icejj.cpp.s

CMakeFiles/mylib.dir/src/fileSystem.cpp.obj: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/fileSystem.cpp.obj: ../src/fileSystem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/lpc0503/Desktop/vfs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mylib.dir/src/fileSystem.cpp.obj"
	/C/msys64/mingw32/bin/i686-w64-mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/fileSystem.cpp.obj -c /C/Users/lpc0503/Desktop/vfs/src/fileSystem.cpp

CMakeFiles/mylib.dir/src/fileSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/fileSystem.cpp.i"
	/C/msys64/mingw32/bin/i686-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/lpc0503/Desktop/vfs/src/fileSystem.cpp > CMakeFiles/mylib.dir/src/fileSystem.cpp.i

CMakeFiles/mylib.dir/src/fileSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/fileSystem.cpp.s"
	/C/msys64/mingw32/bin/i686-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/lpc0503/Desktop/vfs/src/fileSystem.cpp -o CMakeFiles/mylib.dir/src/fileSystem.cpp.s

# Object files for target mylib
mylib_OBJECTS = \
"CMakeFiles/mylib.dir/src/icejj.cpp.obj" \
"CMakeFiles/mylib.dir/src/fileSystem.cpp.obj"

# External object files for target mylib
mylib_EXTERNAL_OBJECTS =

libmylib.a: CMakeFiles/mylib.dir/src/icejj.cpp.obj
libmylib.a: CMakeFiles/mylib.dir/src/fileSystem.cpp.obj
libmylib.a: CMakeFiles/mylib.dir/build.make
libmylib.a: CMakeFiles/mylib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/C/Users/lpc0503/Desktop/vfs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libmylib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mylib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mylib.dir/build: libmylib.a

.PHONY : CMakeFiles/mylib.dir/build

CMakeFiles/mylib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mylib.dir/clean

CMakeFiles/mylib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /C/Users/lpc0503/Desktop/vfs /C/Users/lpc0503/Desktop/vfs /C/Users/lpc0503/Desktop/vfs/build /C/Users/lpc0503/Desktop/vfs/build /C/Users/lpc0503/Desktop/vfs/build/CMakeFiles/mylib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mylib.dir/depend

