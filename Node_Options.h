#pragma once
#include"BigInteger.h"

struct Node_Options {
    int32_t height;
    int32_t size;
    bigint posX;
    bigint sdv;
    bigint L;
    bigint R;
    sf::Color COLOR = sf::Color::Black;

    ~Node_Options() = default;

    Node_Options(const Node_Options& other) {
        height = other.height;
        size = other.size;
        posX = other.posX;
        sdv = other.sdv;
        L = other.L;
        R = other.R;
    }

    Node_Options() : height(0), posX(bigint("0")), sdv(bigint("0")), L(bigint("0")), R(bigint("0")),
                     size(0) {}
};