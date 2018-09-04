//
// Created by Mike Terentyev on 09/05/18.
//

#ifndef HUFFMAN_LIB_FREQUENCY_H
#define HUFFMAN_LIB_FREQUENCY_H

#include <vector>
#include <string>
#include <array>
#include "../../../src/input_stream.h"

struct Frequency {
    Frequency() = default;

    explicit Frequency(std::string line);

    void add_symbol(uint8_t c);

    std::vector<unsigned long long> const &get_data() const;

    static Frequency calc_frequency(Input_stream &reader);

private:
    std::vector<unsigned long long> data = std::vector<unsigned long long>(256);

};

#endif //HUFFMAN_LIB_FREQUENCY_H
