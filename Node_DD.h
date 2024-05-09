#pragma once
#include"Random.h"

struct Node_DD {
    Node_Options param;
    int64_t val;
    int64_t priority;
    Node_DD* left;
    Node_DD* right;
    int32_t height = 0;
    explicit Node_DD(int64_t _val = 0, int32_t _height = -1) : val(_val),
            height(_height + 1), priority(get_random()),
            left(nullptr), right(nullptr) {}
    ~Node_DD() = default;
};
