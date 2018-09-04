//
// Created by Mike Terentyev on 09/05/18.
//

#include "huffman_encryptor.h"

Encryptor::Encryptor(Frequency const &frequency) : HuffmanAlgorithm(frequency) {};

void Encryptor::encode(Input_stream &reader, Output_stream &writer) {
    auto const &codes = get_codes();

    for (size_t i = 0; i < 256; i++) {
        auto const &code = codes[i];
        writer.write_ui8(static_cast<uint8_t>(i)); //char
        writer.write_ui16(static_cast<uint16_t>(code.get_bit_size())); //bit_size
        writer.write_ui16(static_cast<uint16_t>(code.get_data().size())); //data blocks
        writer.write_vector_ui8(code.get_data());
    }

    while (!reader.isEof()) {
        writer.write_encoded_symbol(encode_symbol(reader.read_ui8()));
    }
    writer.complete_buffer();
}

encoded_symbol const &Encryptor::encode_symbol(uint8_t c) {
    return huffman_codes[c];
}

std::vector<encoded_symbol> Encryptor::encode_string(std::string const &data) {
    std::vector<encoded_symbol> res;
    for (char symbol : data) {
        res.push_back(huffman_codes[symbol]);
    }
    return res;
}


