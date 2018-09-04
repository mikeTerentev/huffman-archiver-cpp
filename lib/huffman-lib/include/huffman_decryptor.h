//
// Created by Mike Terentyev on 09/05/18.
//

#ifndef HUFFMAN_LIB_DECODERR_H
#define HUFFMAN_LIB_DECODERR_H

#include <vector>
#include <array>
#include <cassert>
#include "encoded_symbol.h"
#include "tree.h"
#include "HuffmanAlgorithm.h"
#include "../../../src/input_stream.h"
#include "../../../src/output_stream.h"

class Decryptor : public HuffmanAlgorithm {
public:
    Decryptor() = delete;

    explicit Decryptor(Frequency const &frequency);

    explicit Decryptor(std::vector<encoded_symbol> const &codes);

    std::vector<uint8_t> decode_vector(std::vector <encoded_symbol> const &codes) ;

    void move_node_to_(bool bit);

    uint8_t get_symbol();

    Tree_element* get_cur_node();

    static Decryptor read_header(Input_stream &reader);

    static void decrypte(Input_stream &reader, Output_stream &writer);

private:
    Tree_element* cur_node;
};

#endif //HUFFMAN_LIB_DECODERR_H
