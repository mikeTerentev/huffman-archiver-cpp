# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /nix/store/vv5flnbx7dvp6k83h047jpyi5n8298rn-cmake-3.8.2/bin/cmake

# The command to remove a file.
RM = /nix/store/vv5flnbx7dvp6k83h047jpyi5n8298rn-cmake-3.8.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivan/d/cpp-year2017/terentiev-mihail/haffman_archiver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/d/cpp-year2017/terentiev-mihail/haffman_archiver

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/nix/store/vv5flnbx7dvp6k83h047jpyi5n8298rn-cmake-3.8.2/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/nix/store/vv5flnbx7dvp6k83h047jpyi5n8298rn-cmake-3.8.2/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ivan/d/cpp-year2017/terentiev-mihail/haffman_archiver/CMakeFiles /home/ivan/d/cpp-year2017/terentiev-mihail/haffman_archiver/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ivan/d/cpp-year2017/terentiev-mihail/haffman_archiver/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named huffman_lib_testing

# Build rule for target.
huffman_lib_testing: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 huffman_lib_testing
.PHONY : huffman_lib_testing

# fast build rule for target.
huffman_lib_testing/fast:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/build
.PHONY : huffman_lib_testing/fast

#=============================================================================
# Target rules for targets named huffman

# Build rule for target.
huffman: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 huffman
.PHONY : huffman

# fast build rule for target.
huffman/fast:
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/build
.PHONY : huffman/fast

#=============================================================================
# Target rules for targets named huffman_lib

# Build rule for target.
huffman_lib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 huffman_lib
.PHONY : huffman_lib

# fast build rule for target.
huffman_lib/fast:
	$(MAKE) -f lib/huffman-lib/CMakeFiles/huffman_lib.dir/build.make lib/huffman-lib/CMakeFiles/huffman_lib.dir/build
.PHONY : huffman_lib/fast

lib/gtest/gtest-all.o: lib/gtest/gtest-all.cc.o

.PHONY : lib/gtest/gtest-all.o

# target to build an object file
lib/gtest/gtest-all.cc.o:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/lib/gtest/gtest-all.cc.o
.PHONY : lib/gtest/gtest-all.cc.o

lib/gtest/gtest-all.i: lib/gtest/gtest-all.cc.i

.PHONY : lib/gtest/gtest-all.i

# target to preprocess a source file
lib/gtest/gtest-all.cc.i:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/lib/gtest/gtest-all.cc.i
.PHONY : lib/gtest/gtest-all.cc.i

lib/gtest/gtest-all.s: lib/gtest/gtest-all.cc.s

.PHONY : lib/gtest/gtest-all.s

# target to generate assembly for a file
lib/gtest/gtest-all.cc.s:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/lib/gtest/gtest-all.cc.s
.PHONY : lib/gtest/gtest-all.cc.s

lib/gtest/gtest_main.o: lib/gtest/gtest_main.cc.o

.PHONY : lib/gtest/gtest_main.o

# target to build an object file
lib/gtest/gtest_main.cc.o:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/lib/gtest/gtest_main.cc.o
.PHONY : lib/gtest/gtest_main.cc.o

lib/gtest/gtest_main.i: lib/gtest/gtest_main.cc.i

.PHONY : lib/gtest/gtest_main.i

# target to preprocess a source file
lib/gtest/gtest_main.cc.i:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/lib/gtest/gtest_main.cc.i
.PHONY : lib/gtest/gtest_main.cc.i

lib/gtest/gtest_main.s: lib/gtest/gtest_main.cc.s

.PHONY : lib/gtest/gtest_main.s

# target to generate assembly for a file
lib/gtest/gtest_main.cc.s:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/lib/gtest/gtest_main.cc.s
.PHONY : lib/gtest/gtest_main.cc.s

src/input_stream.o: src/input_stream.cpp.o

.PHONY : src/input_stream.o

# target to build an object file
src/input_stream.cpp.o:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/src/input_stream.cpp.o
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/input_stream.cpp.o
.PHONY : src/input_stream.cpp.o

src/input_stream.i: src/input_stream.cpp.i

.PHONY : src/input_stream.i

# target to preprocess a source file
src/input_stream.cpp.i:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/src/input_stream.cpp.i
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/input_stream.cpp.i
.PHONY : src/input_stream.cpp.i

src/input_stream.s: src/input_stream.cpp.s

.PHONY : src/input_stream.s

# target to generate assembly for a file
src/input_stream.cpp.s:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/src/input_stream.cpp.s
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/input_stream.cpp.s
.PHONY : src/input_stream.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/output_stream.o: src/output_stream.cpp.o

.PHONY : src/output_stream.o

# target to build an object file
src/output_stream.cpp.o:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/src/output_stream.cpp.o
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/output_stream.cpp.o
.PHONY : src/output_stream.cpp.o

src/output_stream.i: src/output_stream.cpp.i

.PHONY : src/output_stream.i

# target to preprocess a source file
src/output_stream.cpp.i:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/src/output_stream.cpp.i
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/output_stream.cpp.i
.PHONY : src/output_stream.cpp.i

src/output_stream.s: src/output_stream.cpp.s

.PHONY : src/output_stream.s

# target to generate assembly for a file
src/output_stream.cpp.s:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/src/output_stream.cpp.s
	$(MAKE) -f CMakeFiles/huffman.dir/build.make CMakeFiles/huffman.dir/src/output_stream.cpp.s
.PHONY : src/output_stream.cpp.s

test/huffman_lib_testing.o: test/huffman_lib_testing.cpp.o

.PHONY : test/huffman_lib_testing.o

# target to build an object file
test/huffman_lib_testing.cpp.o:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/test/huffman_lib_testing.cpp.o
.PHONY : test/huffman_lib_testing.cpp.o

test/huffman_lib_testing.i: test/huffman_lib_testing.cpp.i

.PHONY : test/huffman_lib_testing.i

# target to preprocess a source file
test/huffman_lib_testing.cpp.i:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/test/huffman_lib_testing.cpp.i
.PHONY : test/huffman_lib_testing.cpp.i

test/huffman_lib_testing.s: test/huffman_lib_testing.cpp.s

.PHONY : test/huffman_lib_testing.s

# target to generate assembly for a file
test/huffman_lib_testing.cpp.s:
	$(MAKE) -f CMakeFiles/huffman_lib_testing.dir/build.make CMakeFiles/huffman_lib_testing.dir/test/huffman_lib_testing.cpp.s
.PHONY : test/huffman_lib_testing.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... huffman_lib_testing"
	@echo "... huffman"
	@echo "... huffman_lib"
	@echo "... lib/gtest/gtest-all.o"
	@echo "... lib/gtest/gtest-all.i"
	@echo "... lib/gtest/gtest-all.s"
	@echo "... lib/gtest/gtest_main.o"
	@echo "... lib/gtest/gtest_main.i"
	@echo "... lib/gtest/gtest_main.s"
	@echo "... src/input_stream.o"
	@echo "... src/input_stream.i"
	@echo "... src/input_stream.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/output_stream.o"
	@echo "... src/output_stream.i"
	@echo "... src/output_stream.s"
	@echo "... test/huffman_lib_testing.o"
	@echo "... test/huffman_lib_testing.i"
	@echo "... test/huffman_lib_testing.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

