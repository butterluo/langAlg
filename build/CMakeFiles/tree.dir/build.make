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
include CMakeFiles/tree.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tree.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree.dir/flags.make

CMakeFiles/tree.dir/tree.cpp.o: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/tree.cpp.o: /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/tree.cpp
CMakeFiles/tree.dir/tree.cpp.o: CMakeFiles/tree.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree.dir/tree.cpp.o"
	/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tree.dir/tree.cpp.o -MF CMakeFiles/tree.dir/tree.cpp.o.d -o CMakeFiles/tree.dir/tree.cpp.o -c /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/tree.cpp

CMakeFiles/tree.dir/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree.dir/tree.cpp.i"
	/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/tree.cpp > CMakeFiles/tree.dir/tree.cpp.i

CMakeFiles/tree.dir/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree.dir/tree.cpp.s"
	/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/bin/clang++ --target=aarch64-none-linux-android21 --gcc-toolchain=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64 --sysroot=/home/butter/CODES/Andr/ndk/android-ndk-r23c/toolchains/llvm/prebuilt/linux-x86_64/sysroot $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/tree.cpp -o CMakeFiles/tree.dir/tree.cpp.s

# Object files for target tree
tree_OBJECTS = \
"CMakeFiles/tree.dir/tree.cpp.o"

# External object files for target tree
tree_EXTERNAL_OBJECTS =

tree: CMakeFiles/tree.dir/tree.cpp.o
tree: CMakeFiles/tree.dir/build.make
tree: CMakeFiles/tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree.dir/build: tree
.PHONY : CMakeFiles/tree.dir/build

CMakeFiles/tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tree.dir/clean

CMakeFiles/tree.dir/depend:
	cd /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/P/SRC/Eng/Lang/cpp/langAlg /mnt/e/P/SRC/Eng/Lang/cpp/langAlg /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build /mnt/e/P/SRC/Eng/Lang/cpp/langAlg/build/CMakeFiles/tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tree.dir/depend
