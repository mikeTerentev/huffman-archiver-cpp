//
// Created by Mike Terentyev on 09/05/18.
//

#ifndef HUFFMAN_LIB_HUFFMAN_H
#define HUFFMAN_LIB_HUFFMAN_H

#include <queue>
#include <array>
#include <climits>

#include "preCounter.h"
#include "encoded_symbol.h"
#include "tree.h"

class HuffmanAlgorithm {
public:
    HuffmanAlgorithm() = delete;

    ~HuffmanAlgorithm();

    explicit HuffmanAlgorithm(Frequency const &frequency);

    explicit HuffmanAlgorithm(std::vector<encoded_symbol> const &codes);

    std::vector<encoded_symbol> const &get_codes();

    Tree_element *tree_root;
private:
    struct comparator {
        bool operator()(Tree_element *const &l, Tree_element *const &r) {
            return l->counter > r->counter;
        }
    };

    std::priority_queue<Tree_element *, std::vector<Tree_element *>, comparator> building_queue;
protected:
    std::vector<encoded_symbol> huffman_codes = std::vector<encoded_symbol>(256);

    void build_tree();

    void go_dfs(Tree_element *const &root, encoded_symbol &code);

    void dfs_del(Tree_element *v);
};

#endif //HUFFMAN_LIB_HUFFMAN_H
