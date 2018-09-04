//
// Created by Mike Terentyev on 09/05/18.
//

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include <gtest/gtest.h>

#include "huffman_encryptor.h"
#include "huffman_decryptor.h"
#include "preCounter.h"
#include "encoded_symbol.h"

using namespace std;

TEST(correctness, code) {
    encoded_symbol code;
    size_t sz = 100;

    for (size_t i = 0; i < sz; i++) code.push_back_bit(1);


    EXPECT_EQ(sz, code.get_bit_size());
    EXPECT_EQ(string(sz, '1'), code.to_string());
}

string GO(string text) {
    Frequency frequency(text);
    Encryptor encoder(frequency);
    Decryptor decoder(frequency);
    string res;
    for (char c : decoder.decode_vector(encoder.encode_string(text))) res += c;
    return res;
}
TEST(correctness, huffman_empty) {
    string text = "";
    EXPECT_EQ(text, GO(text));
}
TEST(correctness, huffman_one_symbol) {
    string text = "k";
    EXPECT_EQ(text, GO(text));
}
TEST(correctness, huffman_two_symbol) {
    string text = "ke";
    EXPECT_EQ(text, GO(text));
}
TEST(correctness, huffman_tree_symbol) {
    string text = "kek";
    EXPECT_EQ(text, GO(text));
}
TEST(correctness, huffman_four_symbol) {
    string text = "keke";
    EXPECT_EQ(text, GO(text));
}

TEST(correctness, simple) {
    string text = "C allows you to shoot yourself in the foot.\nC++ allows you to re-use the bullet.\n";
    EXPECT_EQ(text, GO(text));
}

TEST(correctness, huffman_codes_constructor) {
    string text = "sxssxsxsxsxsx";
    Frequency frequency(text);
    Encryptor encoder(frequency);
    Decryptor decoder(encoder.get_codes());
    string res;
    for (char c : decoder.decode_vector(encoder.encode_string(text))) res += c;
    EXPECT_EQ(text, res);
}