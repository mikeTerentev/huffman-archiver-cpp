cmake_minimum_required(VERSION 3.5)
project(huffman_lib)

set(CMAKE_CXX_STANDARD 14)

add_library(huffman_lib preCounter.cpp
        include/preCounter.h huffman_decryptor.cpp include/huffman_decryptor.h HuffmanAlgorithm.cpp include/HuffmanAlgorithm.h encoded_symbol.cpp include/encoded_symbol.h include/tree.h huffman_encryptor.cpp include/huffman_encryptor.h include/consts.h)