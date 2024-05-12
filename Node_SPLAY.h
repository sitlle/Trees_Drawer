#include"Node_Options.h"
#pragma once

struct Node_SPLAY {
    // Node options
    Node_Options param;
    int64_t val{};
    Node_SPLAY* left{};
    Node_SPLAY* right{};
    int32_t height = 0;

    Node_SPLAY() = default;

    ~Node_SPLAY() = default;

    Node_SPLAY(Node_SPLAY const& other) {
        param = other.param;
        val = other.val;
        left = other.left;
        right = other.right;
        height = other.height;
    }

    explicit Node_SPLAY(int64_t _val = 0) : val(_val), height(0),
                                    left(nullptr), right(nullptr) {}
};