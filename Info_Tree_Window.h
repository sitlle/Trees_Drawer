#pragma once
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include"VERTEX.h"
#include"Boxed.h"

class Info_Tree_Window {
public:
    Info_Tree_Window() : Main_Window_(sf::VideoMode(WINDOW_W_, WINDOW_H_), "extra meow") {}

    ~Info_Tree_Window() = default;

    void Events() noexcept;
    void Draw() noexcept;

    template<typename tree_type>
    void GetInfo(tree_type Tree, int type) noexcept;

    template<typename tree_type>
    void Process(tree_type tree, int type) noexcept;

private:
    sf::Font User_Font;
    sf::Text User_Text;
    struct WINDOW {
        sf::Color COLOR = sf::Color::White;
        sf::Vector2f position = {0, 0};
        sf::Vector2f size = {0, 0};
        WINDOW() = default;
        ~WINDOW() = default;
    };
    static constexpr int32_t WINDOW_W_ = 1500;
    static const int32_t WINDOW_H_ = 599;
    sf::RenderWindow Main_Window_;
    sf::Event Main_Event_{};
    std::vector<WINDOW> Boxes_;
    std::vector<std::string> Info_;
    int cnt = 0;
};

template<typename tree_type>
void Info_Tree_Window::GetInfo(tree_type Tree, int type) noexcept {
    if (Tree.root == nullptr) {
        Info_[0] = "type: ";
        if (type == 1) {
            Info_[0] += "Cartesian tree";
        } else if (type == 2) {
            Info_[0] += "AVL tree";
        } else if (type == 3) {
            Info_[0] += "Splay tree";
        }
        Info_[1] = "size: 0";
        Info_[2] = "height: 0";
        Info_[3] = "something: ";
        Info_[4] = "min value: ";
        Info_[5] = "max value: ";
        return;
    }
    // get size
    Info_[0] = "type: ";
    if (type == 1) {
        Info_[0] += "Cartesian tree";
    } else if (type == 2) {
        Info_[0] += "AVL tree";
    } else if (type == 3) {
        Info_[0] += "Splay tree";
    }
    Info_[1] = "height: ";
    Info_[1] += std::to_string(Tree.root->param.height);
    // size
    Info_[2] = "size: ";
    // smth
    Info_[3] = "something: ";
    // min value
    Info_[4] = "min value...: ";
    // max value
    Info_[5] = "max value: ";
}

template<typename tree_type>
void Info_Tree_Window::Process(tree_type Tree, int type) noexcept {
    Boxes_.resize(6);
    Info_.resize(6);
    for (int i = 0; i < 6; ++i) {
        Boxes_[i].COLOR = sf::Color::White;
        Boxes_[i].size = sf::Vector2f(static_cast<float>(WINDOW_W_) + 100, 100);
        Boxes_[i].position = sf::Vector2f(0.f, float(i) * 100.f);
    }
    GetInfo(Tree, type);
    Main_Window_.setPosition(sf::Vector2i(500, 500));
    User_Font.loadFromFile("/home/yeawer/tree/Hack-Bold.ttf");
    User_Text.setFont(User_Font);

    while (Main_Window_.isOpen()) {
        Events();
        Draw();
        cnt++;
        cnt %= 10;
    }
}
