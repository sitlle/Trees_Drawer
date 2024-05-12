#include<SFML/Graphics.hpp>
#include"VERTEX.h"
#pragma once

class Drawer {
public:
    Drawer() = default;
    ~Drawer() = default;

    static void Draw() noexcept;
    static void Print_DD_TREE() noexcept;
    static void Print_AVL_TREE() noexcept;
    static void Print_SPLAY_TREE() noexcept;
    static void Print_RB_TREE() noexcept;

    template<typename vertex_type>
    static void PrintInOrder(VERTEX<vertex_type>* vertex) noexcept;

    template<typename vertex_type>
    static void DrawVertex(VERTEX<vertex_type>* vertex) noexcept;

    static void DrawLine(const std::pair<float, float>& first,
                        const std::pair<float, float>& second,
                        const float& RADIUS, sf::Color COLOR = sf::Color::Red) noexcept;
};