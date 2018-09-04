//
// Created by Mike Terentyev on 09/05/18.
//

#include "output_stream.h"

Output_stream::Output_stream(std::string const &file) : stream(file, std::ofstream::binary) {}

Output_stream::~Output_stream() {
    write_segment();
    stream.close();
}

void Output_stream::write_segment() {
    stream.write(buffer, cur_ptr);
    cur_ptr = 0;
}

void Output_stream::write_ui8(uint8_t chr) {
    if (cur_ptr == BUFFER_SIZE) write_segment();
    buffer[cur_ptr++] = chr;
}

void Output_stream::write_ui16(uint16_t src) {
    write_ui8(static_cast<uint8_t>(src >> 8));
    write_ui8(static_cast<uint8_t>(src & UINT8_MAX));
}

// for code.get_data
void Output_stream::write_vector_ui8(std::vector<uint8_t> const &vector) {
    for (auto item : vector) write_ui8(item);
}

void Output_stream::write_encoded_symbol(encoded_symbol const &code) {
    for (size_t i = 0, size = code.get_bit_size(); i < size; i++) push_back_bit(code.get_bit(i));
}

void Output_stream::push_back_bit(bool bit) {
    is_buf_full = false;
    block = (block << 1) + bit;
    block_size++;
    if (block_size == IN_MAX_BLOCK) {
        write_ui8(block); ///<------
        block_size = 0;
        block = 0;
        is_buf_full = true;
    }
}

void Output_stream::complete_buffer() {
    if (block_size != 0) {
        /**/last_byte_size = block_size;
        uint8_t fill_cnt = block_size;
        while (fill_cnt < IN_MAX_BLOCK) {
            push_back_bit(0);
            fill_cnt++;
        }
    } else {
        /**/last_byte_size = is_buf_full ? IN_MAX_BLOCK : 0;
    }
    write_ui8(last_byte_size);
}

void Output_stream::write_ui32_t(uint32_t x) {
    write_ui16(static_cast<uint16_t>(x >> 16));
    write_ui16(static_cast<uint16_t>(x & UINT16_MAX));
}
