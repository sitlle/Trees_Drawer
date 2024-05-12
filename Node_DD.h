#pragma once
#include"Random.h"

struct Node_DD {
    Node_Options param;
    int64_t val;
    int64_t priority;
    Node_DD* left;
    Node_DD* right;

    Node_DD() {
        val = 0;
        priority = 0;
        left = nullptr;
        right = nullptr;
    }

    ~Node_DD() = default;

    Node_DD(Node_DD const& other) {
        param = other.param;
        val = other.val;
        priority = other.priority;
        left = other.left;
        right = other.right;
    }

    explicit Node_DD(int64_t _val = 0, int32_t _height = -1) : val(_val),
            priority(get_random()),
            left(nullptr), right(nullptr) {}
};
