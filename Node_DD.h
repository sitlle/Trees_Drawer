#include"Node_Options.h"
#include"Random.h"
#pragma once

struct Node_DD {
    int64_t val;
    int64_t priority;
    Node_Options param;
    Node_DD* left;
    Node_DD* right;
    explicit Node_DD(const int64_t& _val) : val(_val), priority(get_random()),
                                            left(nullptr), right(nullptr),
                                            param() {}
    ~Node_DD() = default;
};
