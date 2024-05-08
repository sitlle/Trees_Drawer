#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#pragma once

class Second_Extra_Window {
public:
    Second_Extra_Window();
    ~Second_Extra_Window() = default;
    void Events();
    void Draw() noexcept;
    void FindErrors();
    std::string Process();

private:
    sf::Font User_Font;
    sf::Text User_Text;
    struct WINDOW {
        sf::Color COLOR = sf::Color::Green;
        sf::Vector2f position = {0, 0};
        sf::Vector2f size = {0, 0};
        WINDOW() = default;
        ~WINDOW() = default;
    };
    std::string Input_String_;
    static constexpr int32_t WINDOW_W_ = 1500;
    static constexpr int32_t WINDOW_H_ = 750;
    sf::RenderWindow Main_Window_;
    sf::Event Main_Event_{};
    WINDOW Main_Box_;
};

