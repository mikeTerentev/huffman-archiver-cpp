cmake_minimum_required(VERSION 3.5)
project(huffman_archiver)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fsanitize=address,undefined -D_GLIBCXX_DEBUG")
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} -g --coverage -D_GLIBCXX_DEBUG")
#set(CMAKE_CXX_FLAGS_RELEASE "-O2")

include_directories(${CMAKE_SOURCE_DIR}/lib/huffman-lib/include)
include_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(lib/huffman-lib)

add_executable(huffman src/main.cpp src/input_stream.cpp src/input_stream.h src/output_stream.cpp src/output_stream.h lib/huffman-lib/include/consts.h src/impl_consts.h)
target_link_libraries(huffman huffman_lib)

add_executable(huffman_lib_testing
        src/input_stream.cpp
        src/input_stream.h
        src/output_stream.cpp
        src/output_stream.h
        test/huffman_lib_testing.cpp
        lib/gtest/gtest-all.cc
        lib/gtest/gtest.h
        lib/gtest/gtest_main.cc)

target_link_libraries(huffman_lib_testing huffman_lib -lpthread)
