#pragma once

struct PRINT_TREE_OPTIONS {
    float cnt_x;
    float cnt_y;
    float zoom;
    PRINT_TREE_OPTIONS() : cnt_x(0.f), cnt_y(0.f), zoom(1.f) {}
    ~PRINT_TREE_OPTIONS() = default;
};