#pragma once
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include"Node_Options.h"

struct Node_RB {
    Node_Options param;
    int64_t val;
    Node_RB* prev;
    Node_RB* left;
    Node_RB* right;

    Node_RB() = default;
    ~Node_RB() = default;

};