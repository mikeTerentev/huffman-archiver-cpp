//
// Created by Mike Terentyev on 09/05/18.
//

#include "input_stream.h"

//source: http://ru.cppreference.com/w/cpp/io/basic_ifstream
Input_stream::Input_stream(std::string file) : stream(file, std::ios::in | std::ifstream::binary) {
    if (stream.fail()) {
        stream.close();
        throw std::runtime_error("Can't read file " + file);
    }
}

Input_stream::~Input_stream() {
    stream.close();
}

void Input_stream::try_read_buffer() {
    if (pos == last_read_amount) read_buff();
}

bool Input_stream::isEof() {
    try_read_buffer();
    return last_read_amount == 0;
}

uint8_t Input_stream::read_ui8() {
    if (isEof()) throw std::runtime_error("Reading error : Expected symbol");

    try_read_buffer();
    return static_cast<uint8_t>(buffer[pos++]);
}

void Input_stream::read_buff() {
    stream.read(buffer, BUFFER_SIZE);
    last_read_amount = static_cast<size_t>(stream.gcount());// amount in last op 0 if EOF
    pos = 0;
}

uint16_t Input_stream::read_ui16() {
    uint16_t x = (read_ui8() << 8) + read_ui8();
    return x;
}

std::vector<uint8_t> Input_stream::read_vector(size_t sz) {
    std::vector<uint8_t> res;
    for (size_t i = 0; i < sz; i++) {
        res.push_back(read_ui8());
    }
    return res;
}

void Input_stream::reset() {
    pos = 0;
    last_read_amount = 0;
    stream.clear();
    stream.seekg(0, std::ios::beg); //set pos indication
}

uint32_t Input_stream::read_ui32() {
    uint32_t res = (read_ui16() << 16) | read_ui16();
    return res;
}

