//
// Created by Mike Terentyev on 09/05/18.
//

#include "HuffmanAlgorithm.h"

//d+e
HuffmanAlgorithm::HuffmanAlgorithm(Frequency const &frequency) {
    auto const &codes = frequency.get_data();
    for (size_t i = 0; i < 256; i++) {
        auto const &x = codes[i];
        building_queue.push(new Tree_element(i, x));
    }
    build_tree();
}

void HuffmanAlgorithm::build_tree() {
    if (building_queue.empty()) {
        return;
    }

    if (building_queue.size() == 1) {
        tree_root = new Tree_element(0, building_queue.top(), nullptr);
    } else {
        while (building_queue.size() > 1) {
            auto l = building_queue.top();
            building_queue.pop();
            auto r = building_queue.top();
            building_queue.pop();

            auto top = new Tree_element(l->counter + r->counter, l, r);
            building_queue.push(top);
        }
        tree_root = building_queue.top();
    }
    building_queue.pop();
    encoded_symbol code;
    go_dfs(tree_root, code);
}

HuffmanAlgorithm::~HuffmanAlgorithm() {
    dfs_del(tree_root);
}

void HuffmanAlgorithm::dfs_del(Tree_element *v) {
    if (v == nullptr) return;
    if (v->is_list()) {
        delete v;
        return;
    }
    dfs_del(v->l);
    dfs_del(v->r);
    delete v;
}


void HuffmanAlgorithm::go_dfs(Tree_element *const &v, encoded_symbol &code) {
    if (v == nullptr) return;

    if (v->is_list()) {
        huffman_codes[v->data] = code;
        return;
    }

    code.push_back_bit(0);
    go_dfs(v->l, code);
    code.pop_bit();
    code.push_back_bit(1);
    go_dfs(v->r, code);
    code.pop_bit();
}

std::vector<encoded_symbol> const &HuffmanAlgorithm::get_codes() {
    return huffman_codes;
}

HuffmanAlgorithm::HuffmanAlgorithm(std::vector<encoded_symbol> const &codes) {
    this->huffman_codes = codes;
    tree_root = new Tree_element(0, 0);
    for (size_t symbol = 0; symbol < 256; symbol++) {
        auto cur_node = tree_root;
        auto const &c = codes[symbol];

        for (size_t i = 0; i < c.get_bit_size(); i++) {
            bool bit = c.get_bit(i);
            if (bit) {
                if (cur_node->r == nullptr) {
                    cur_node->r = new Tree_element(0, 0);
                }
                cur_node = cur_node->r;
            } else {
                if (cur_node->l == nullptr) {
                    cur_node->l = new Tree_element(0, 0);
                }
                cur_node = cur_node->l;
            }
        }
        cur_node->data = symbol;
    }
}
