//
// Created by Mike Terentyev on 09/05/18.
//

#include "huffman_decryptor.h"

Decryptor::Decryptor(Frequency const &frequency) : HuffmanAlgorithm(frequency), cur_node(tree_root) {
}

void Decryptor::move_node_to_(bool bit) {
    assert(cur_node != nullptr);
    if (cur_node->is_list()) cur_node = tree_root;
    cur_node = bit ? cur_node->r : cur_node->l;
}


uint8_t Decryptor::get_symbol() {
    if (cur_node->is_list()) {
        return cur_node->data;
    }
    throw std::runtime_error("Reading error : Expected to find char");
}

Decryptor::Decryptor(std::vector<encoded_symbol> const &codes) : HuffmanAlgorithm(codes), cur_node(tree_root) {

}

Tree_element *Decryptor::get_cur_node() {
    return cur_node;
}

Decryptor Decryptor::read_header(Input_stream &reader) {
    std::vector<encoded_symbol> codes(256);
    for (size_t i = 0; i < 256; i++) {
        uint8_t symbol = reader.read_ui8();
        uint16_t bit_size = reader.read_ui16();
        uint16_t blocks_amount = reader.read_ui16();
        std::vector<uint8_t> code = reader.read_vector(static_cast<size_t>(blocks_amount));
        codes[symbol] = encoded_symbol(static_cast<size_t>(bit_size), code);
    }
    return Decryptor(codes);
}

void Decryptor::decrypte(Input_stream &reader, Output_stream &writer) {
    Decryptor decoder = read_header(reader);

    uint8_t codes = reader.read_ui8();

    if (reader.isEof()) {
        throw std::runtime_error("Decode failed");
    }

    do {
        uint8_t next_codes = reader.read_ui8(), end_of_codes = MAX_BLOCK_LEN;

        if (reader.isEof()) end_of_codes = next_codes;

        for (auto i = 0; i < end_of_codes; i++) {
            auto bit = static_cast<bool>(codes & (1 << (MAX_BLOCK_LEN - i - 1)));
            decoder.move_node_to_(bit);
            if (decoder.get_cur_node() == nullptr)
                throw std::runtime_error("Decrypting error: expected to find char");
            if (decoder.cur_node->is_list())
                writer.write_ui8(decoder.get_symbol());
        }
        codes = next_codes;
    } while (!reader.isEof());
}

//only for tests
std::vector<uint8_t> Decryptor::decode_vector(std::vector<encoded_symbol> const &codes) {
    std::vector<uint8_t> res;
    cur_node = tree_root;
    for (const auto &code:codes) {
        for (size_t i = 0; i < code.get_bit_size(); i++) {
            bool bit = code.get_bit(i);
            move_node_to_(bit);
            if (cur_node->is_list()) {
                res.push_back(get_symbol());
            }
        }
    }
    return res;
}