#include "Info_Tree_Window.h"

void Info_Tree_Window::Draw() noexcept {
    Main_Window_.clear();
    for (int i = 0; i < 6; ++i) {
        DrawBox(Main_Window_, Boxes_[i].position, Boxes_[i].size, Boxes_[i].COLOR);
        DrawTextInBox(Main_Window_, Boxes_[i].position, Boxes_[i].size, Info_[i],
                      User_Text, 0, 60);
    }
    Main_Window_.display();}

void Info_Tree_Window::Events() noexcept {
    while (Main_Window_.pollEvent(Main_Event_)) {
        if (Main_Event_.type == sf::Event::Closed ||
            Main_Event_.type == sf::Event::KeyPressed &&
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))) { // close
            Main_Window_.close();
        }
    }
}