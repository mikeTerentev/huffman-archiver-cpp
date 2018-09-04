//
// Created by Mike Terentyev on 09/05/18.
//

#include "encoded_symbol.h"

void encoded_symbol::push_back_bit(bool bit) {
    bit_size++;
    if (data.size() * MAX_BLOCK_LEN < bit_size) {
        data.push_back(0);
    }
    if (bit) {
        data.back() ^= (1 << pos_in_box(bit_size - 1));
    }
}

size_t encoded_symbol::pos_in_box(size_t index) const {
    return (MAX_BLOCK_LEN - (index % MAX_BLOCK_LEN) - 1);
}

void encoded_symbol::pop_bit() {
    bit_size--;
    if ((data.size() - 1) * MAX_BLOCK_LEN >= bit_size) {
        data.pop_back();
    } else {
        data.back() &= UINT8_MAX ^ (1 << pos_in_box(bit_size));
    }
}

bool encoded_symbol::get_bit(size_t ind) const {
    return static_cast<bool>(data[ind / MAX_BLOCK_LEN] & (1 << pos_in_box(ind)));
}

size_t encoded_symbol::get_bit_size() const {
    return bit_size;
}

std::string encoded_symbol::to_string() {
    std::string res;
    for (size_t i = 0; i < bit_size; i++) {
        res += '0' + get_bit(i);
    }
    return res;
}

std::vector<uint8_t> encoded_symbol::get_data() const {
    return data;
}
