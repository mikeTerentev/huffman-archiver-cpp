//
// Created by Mike Terentyev on 09/05/18.
//

#ifndef HUFFMAN_LIB_HUFFMAN_CODE_H
#define HUFFMAN_LIB_HUFFMAN_CODE_H

#include <vector>
#include <string>

#include "consts.h"

struct encoded_symbol {
    encoded_symbol() : data(0), bit_size(0) {}
    encoded_symbol(size_t sz, const std::vector<uint8_t> &d) : bit_size(sz), data(d) {};
    void push_back_bit(bool bit);
    void pop_bit();
    bool get_bit(size_t ind) const;
    size_t get_bit_size() const;
    std::string to_string();
    std::vector<uint8_t> get_data()const;
private:
    std::vector<uint8_t> data;
    size_t bit_size;
private:
    size_t pos_in_box(size_t index) const;
};

#endif //HUFFMAN_LIB_HUFFMAN_CODE_H
