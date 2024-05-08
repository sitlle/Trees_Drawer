#pragma once

struct Node_Options {
    int32_t height;
    int32_t size;
    int64_t posX;
    int64_t sdv;
    std::pair<int64_t, int64_t> LR;
    sf::Color COLOR;
    Node_Options() : height(0), posX(0), sdv(0), LR({0, 0}),
                     COLOR(sf::Color::Red), size(0) {}
    ~Node_Options() = default;
};