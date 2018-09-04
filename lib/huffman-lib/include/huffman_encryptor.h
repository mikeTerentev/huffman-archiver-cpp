//
// Created by Mike Terentyev on 09/05/18.
//

#ifndef HUFFMAN_LIB_ENCODER_H
#define HUFFMAN_LIB_ENCODER_H

#include <vector>
#include <string>

#include "HuffmanAlgorithm.h"
#include "preCounter.h"
#include "tree.h"
#include "encoded_symbol.h"
#include "../../../src/output_stream.h"

class Encryptor : public HuffmanAlgorithm {
public:
    Encryptor() = delete;

    explicit Encryptor(Frequency const &frequency);

    std::vector<encoded_symbol> encode_string(std::string const &data);

    encoded_symbol const &encode_symbol(uint8_t c);

    void encode(Input_stream &reader, Output_stream &writer);

    void write_header(Output_stream &writer);
};

#endif //HUFFMAN_LIB_ENCODER_H
