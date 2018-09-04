//
// Created by Mike Terentyev on 09/05/18.
//

#ifndef HUFFMAN_LIB_TREE_H
#define HUFFMAN_LIB_TREE_H

#include <memory>

struct Tree_element {
    Tree_element *l;
    Tree_element *r;
    uint8_t data = 0;
    unsigned long long counter;
    ~Tree_element() = default;
    Tree_element(uint8_t c, unsigned long long freq) {
        this->data = c;
        this->counter = freq;
        l = r = nullptr;
    }

    bool is_list() {
        return l == nullptr && r == nullptr;
    }

    Tree_element(unsigned long long int freq, Tree_element *const &l, Tree_element *const &r) : counter(freq),
                                                                                                l(l),
                                                                                                r(r) {};
};

#endif //HUFFMAN_LIB_TREE_H
