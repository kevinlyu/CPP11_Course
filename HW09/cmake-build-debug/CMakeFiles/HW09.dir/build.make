# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.6

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2016.2.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2016.2.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Homework\C++\HW09

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Homework\C++\HW09\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW09.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW09.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW09.dir/flags.make

CMakeFiles/HW09.dir/main.cpp.obj: CMakeFiles/HW09.dir/flags.make
CMakeFiles/HW09.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Homework\C++\HW09\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW09.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HW09.dir\main.cpp.obj -c D:\Homework\C++\HW09\main.cpp

CMakeFiles/HW09.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW09.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Homework\C++\HW09\main.cpp > CMakeFiles\HW09.dir\main.cpp.i

CMakeFiles/HW09.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW09.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Homework\C++\HW09\main.cpp -o CMakeFiles\HW09.dir\main.cpp.s

CMakeFiles/HW09.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/HW09.dir/main.cpp.obj.requires

CMakeFiles/HW09.dir/main.cpp.obj.provides: CMakeFiles/HW09.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\HW09.dir\build.make CMakeFiles/HW09.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/HW09.dir/main.cpp.obj.provides

CMakeFiles/HW09.dir/main.cpp.obj.provides.build: CMakeFiles/HW09.dir/main.cpp.obj


CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj: CMakeFiles/HW09.dir/flags.make
CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj: ../TRADE_DATE.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Homework\C++\HW09\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\HW09.dir\TRADE_DATE.cpp.obj -c D:\Homework\C++\HW09\TRADE_DATE.cpp

CMakeFiles/HW09.dir/TRADE_DATE.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW09.dir/TRADE_DATE.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Homework\C++\HW09\TRADE_DATE.cpp > CMakeFiles\HW09.dir\TRADE_DATE.cpp.i

CMakeFiles/HW09.dir/TRADE_DATE.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW09.dir/TRADE_DATE.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Homework\C++\HW09\TRADE_DATE.cpp -o CMakeFiles\HW09.dir\TRADE_DATE.cpp.s

CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj.requires:

.PHONY : CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj.requires

CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj.provides: CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj.requires
	$(MAKE) -f CMakeFiles\HW09.dir\build.make CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj.provides.build
.PHONY : CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj.provides

CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj.provides.build: CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj


# Object files for target HW09
HW09_OBJECTS = \
"CMakeFiles/HW09.dir/main.cpp.obj" \
"CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj"

# External object files for target HW09
HW09_EXTERNAL_OBJECTS =

HW09.exe: CMakeFiles/HW09.dir/main.cpp.obj
HW09.exe: CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj
HW09.exe: CMakeFiles/HW09.dir/build.make
HW09.exe: CMakeFiles/HW09.dir/linklibs.rsp
HW09.exe: CMakeFiles/HW09.dir/objects1.rsp
HW09.exe: CMakeFiles/HW09.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Homework\C++\HW09\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable HW09.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\HW09.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW09.dir/build: HW09.exe

.PHONY : CMakeFiles/HW09.dir/build

CMakeFiles/HW09.dir/requires: CMakeFiles/HW09.dir/main.cpp.obj.requires
CMakeFiles/HW09.dir/requires: CMakeFiles/HW09.dir/TRADE_DATE.cpp.obj.requires

.PHONY : CMakeFiles/HW09.dir/requires

CMakeFiles/HW09.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HW09.dir\cmake_clean.cmake
.PHONY : CMakeFiles/HW09.dir/clean

CMakeFiles/HW09.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Homework\C++\HW09 D:\Homework\C++\HW09 D:\Homework\C++\HW09\cmake-build-debug D:\Homework\C++\HW09\cmake-build-debug D:\Homework\C++\HW09\cmake-build-debug\CMakeFiles\HW09.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW09.dir/depend

