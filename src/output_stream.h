//
// Created by Mike Terentyev on 09/05/18.
//

#ifndef HUFFMAN_BUFFERED_WRITER_H
#define HUFFMAN_BUFFERED_WRITER_H

#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <climits>

#include "consts.h"
#include "impl_consts.h"
#include <encoded_symbol.h>

class Output_stream {
public:
    Output_stream() = delete;

    explicit Output_stream(std::string const &file);

    ~Output_stream();

    void write_ui8(uint8_t chr);

    void write_ui16(uint16_t src);

    void write_vector_ui8(std::vector<uint8_t> const &vector);

    void write_encoded_symbol(encoded_symbol const &code);

    void push_back_bit(bool bit);

    void complete_buffer();

private:
    uint8_t block_size = 0;
    uint8_t block = 0; //<----
    uint8_t last_byte_size = 0;
    bool is_buf_full = false;
    std::ofstream stream;
    size_t cur_ptr = 0;
    char buffer[BUFFER_SIZE];

    void write_segment();
    void write_ui32_t(uint32_t x);
};

#endif //HUFFMAN_BUFFERED_WRITER_H
