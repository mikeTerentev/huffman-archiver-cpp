//
// Created by Mike Terentyev on 09/05/18.
//

#include "preCounter.h"

Frequency Frequency::calc_frequency(Input_stream &reader) {
    Frequency frequency;
    while (!reader.isEof()) {
        frequency.add_symbol(reader.read_ui8());
    }
    reader.reset();
    return frequency;
}

void Frequency::add_symbol(uint8_t c) {
    data[c] += 1;
}

std::vector<unsigned long long> const &Frequency::get_data() const {
    return data;
}

Frequency::Frequency(std::string line) {
    for (uint8_t symbol : line) {
        data[symbol] += 1;
    }
}