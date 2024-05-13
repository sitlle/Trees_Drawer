#pragma once
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include"Node_Options.h"

struct Node_RB {
    Node_Options param;
    int64_t val;
    Node_RB* prev = nullptr;
    Node_RB* left;
    Node_RB* right;

    Node_RB() = default;
    ~Node_RB() = default;


    Node_RB(Node_RB const& other) {
        param = other.param;
        val = other.val;
        left = other.left;
        right = other.right;
        prev = other.prev;
    }
};