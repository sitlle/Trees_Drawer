#include"Node_Options.h"
#pragma once

struct Node_AVL {
    // Node options
    Node_Options param;
    int64_t val;
    Node_AVL* left;
    Node_AVL* right;
    int32_t height = 0;
    int64_t balance;
    explicit Node_AVL(int64_t _val = 0, int32_t _height = -1) : val(_val),
                                                            height(_height + 1),
                                                            left(nullptr), right(nullptr),
                                                            balance(0) {}
};