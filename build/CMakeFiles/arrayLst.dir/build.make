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
CMAKE_COMMAND = /mnt/e/WSL/sftware/cmake/bin/cmake

# The command to remove a file.
RM = /mnt/e/WSL/sftware/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/e/P/SRC/Eng/Lang/cpp/langAlg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build

# Include any dependencies generated for this target.
include CMakeFiles/arrayLst.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/arrayLst.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/arrayLst.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/arrayLst.dir/flags.make

CMakeFiles/arrayLst.dir/arrayLst.cpp.o: CMakeFiles/arrayLst.dir/flags.make
CMakeFiles/arrayLst.dir/arrayLst.cpp.o: /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/arrayLst.cpp
CMakeFiles/arrayLst.dir/arrayLst.cpp.o: CMakeFiles/arrayLst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/arrayLst.dir/arrayLst.cpp.o"
	/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/arrayLst.dir/arrayLst.cpp.o -MF CMakeFiles/arrayLst.dir/arrayLst.cpp.o.d -o CMakeFiles/arrayLst.dir/arrayLst.cpp.o -c /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/arrayLst.cpp

CMakeFiles/arrayLst.dir/arrayLst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrayLst.dir/arrayLst.cpp.i"
	/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/arrayLst.cpp > CMakeFiles/arrayLst.dir/arrayLst.cpp.i

CMakeFiles/arrayLst.dir/arrayLst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrayLst.dir/arrayLst.cpp.s"
	/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/arrayLst.cpp -o CMakeFiles/arrayLst.dir/arrayLst.cpp.s

# Object files for target arrayLst
arrayLst_OBJECTS = \
"CMakeFiles/arrayLst.dir/arrayLst.cpp.o"

# External object files for target arrayLst
arrayLst_EXTERNAL_OBJECTS =

arrayLst: CMakeFiles/arrayLst.dir/arrayLst.cpp.o
arrayLst: CMakeFiles/arrayLst.dir/build.make
arrayLst: CMakeFiles/arrayLst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arrayLst"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arrayLst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/arrayLst.dir/build: arrayLst
.PHONY : CMakeFiles/arrayLst.dir/build

CMakeFiles/arrayLst.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/arrayLst.dir/cmake_clean.cmake
.PHONY : CMakeFiles/arrayLst.dir/clean

CMakeFiles/arrayLst.dir/depend:
	cd /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/P/SRC/Eng/Lang/cpp/langAlg /mnt/e/P/SRC/Eng/Lang/cpp/langAlg /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build/CMakeFiles/arrayLst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/arrayLst.dir/depend

