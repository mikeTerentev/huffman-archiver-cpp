//
// Created by Mike Terentyev on 09/05/18.
//

#ifndef HUFFMAN_BUFFERED_READER_H
#define HUFFMAN_BUFFERED_READER_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <climits>

#include "consts.h"
#include "impl_consts.h"

class Input_stream {
public:
    Input_stream() = delete;
    explicit Input_stream(std::string file);
    ~Input_stream();
    bool isEof();
    uint8_t read_ui8();
    uint16_t read_ui16();
    uint32_t read_ui32();
    std::vector<uint8_t> read_vector(size_t sz);
    void reset();
private:
    std::ifstream stream;
    size_t pos = 0;
    size_t last_read_amount = 0;
    char buffer[BUFFER_SIZE];
private:
    void read_buff();

    void try_read_buffer();
};

#endif //HUFFMAN_BUFFERED_READER_H
