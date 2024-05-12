#include<SFML/Graphics.hpp>
#include"Node_Options.h"
#pragma once

template<typename vertex_type> struct VERTEX {
    std::pair<float, float> coords;
    sf::Color COLOR = sf::Color::Red;
    float radius{};
    VERTEX* left{};
    VERTEX* right{};
    int val{};
    vertex_type* real_vertex;

    VERTEX() = default;

    explicit VERTEX<vertex_type>(vertex_type* input_vertex) {
        real_vertex = input_vertex;
        coords = {0, 0};
        radius = 0;
    }

    ~VERTEX() = default;

    VERTEX(VERTEX const& other) {
        coords = other.coords;
        COLOR = other.COLOR;
        radius = other.radius;
        left = other.left;
        right = other.right;
        val = other.val;
        real_vertex = other.real_vertex;
    }

private:
    void clear(VERTEX* vertex) {
        if (vertex == nullptr) {
            return;
        }
        clear(vertex->left);
        clear(vertex->right);
        delete vertex;
    }
};