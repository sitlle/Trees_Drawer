#pragma once
#include"BigInteger.h"

struct Node_Options {
    int32_t height;
    int32_t size;
    bigint posX;
    bigint sdv;
    bigint L;
    bigint R;
    sf::Color COLOR;
    Node_Options() : height(0), posX(to_bigint("0")), sdv(to_bigint("0")), L(to_bigint("0")), R(to_bigint("0")),
                     COLOR(sf::Color::Red), size(0) {}
    ~Node_Options() = default;
};