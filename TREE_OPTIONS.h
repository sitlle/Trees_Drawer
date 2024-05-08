#pragma once

struct TREE_OPTIONS {
    float TREE_H;
    float TREE_W;
    TREE_OPTIONS() : TREE_H(2.f), TREE_W(1.5f) {}
    ~TREE_OPTIONS() = default;
};