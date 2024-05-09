#pragma once
#include"BigInteger.h"

struct Node_Options {
    int32_t height;
    int32_t size;
    int64_t posX;
    int64_t sdv;
    int64_t L;
    int64_t R;
    sf::Color COLOR;
    Node_Options() : height(0), posX(0), sdv(0), L(0), R(0),
                     COLOR(sf::Color::Red), size(0) {}
    ~Node_Options() = default;
};
