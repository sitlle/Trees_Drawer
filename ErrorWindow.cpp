#include "ErrorWindow.h"
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#pragma once

ErrorWindow::ErrorWindow(const std::string& error)
        : Error_Window_(sf::VideoMode(1400, 400), "Error") {
    Error_Window_.setPosition(sf::Vector2i(560, 550));
    message_ = error;
    Main_Font_.loadFromFile("/home/yeawer/tree/Hack-Bold.ttf");
    Main_Text_.setFont(Main_Font_);
    Main_Text_.setString(error);
    Main_Text_.setCharacterSize(140);
    float position_x = (static_cast<float>(Error_Window_.getSize().x) -
                        Main_Text_.getLocalBounds().width) / 2;
    float position_y = (static_cast<float>(Error_Window_.getSize().y) - Main_Text_.getLocalBounds().height) / 2;
    Main_Text_.setPosition(sf::Vector2f(position_x, position_y));
}

void ErrorWindow::Process() {
    int cnt = 0;
    while (Error_Window_.isOpen()) {
        while (Error_Window_.pollEvent(Error_Event_)) {
            if (Error_Event_.type == sf::Event::Closed ||
                Error_Event_.type == sf::Event::KeyPressed &&
                (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))) { // close
                Error_Window_.close();
            } else {
                cnt = 1;
            }
        }
        Error_Window_.clear();
        Error_Window_.draw(Main_Text_);
        Error_Window_.display();
    }
}
