#include "Second_Extra_Window.h"
#include<SFML/Graphics.hpp>
#include"Boxed.h"
#include"KeyBoard.h"
#include"ErrorWindow.h"

Second_Extra_Window::Second_Extra_Window() :
    Main_Window_(VideoMode(WINDOW_W_, WINDOW_H_), "extra_meow") {
    Main_Box_.size = {1250, 150};
    Main_Box_.position = {(static_cast<float>(WINDOW_W_) - Main_Box_.size.x) / 2.f,
                          (static_cast<float>(WINDOW_H_) - Main_Box_.size.y) / 2.f};
    Main_Window_.setPosition(Vector2i(500, 500));
    User_Font.loadFromFile("/home/yeawer/tree/Hack-Bold.ttf");
    User_Text.setFont(User_Font);
}

void Second_Extra_Window::Events() {
    while (Main_Window_.pollEvent(Main_Event_)) {
        if (Main_Event_.type == sf::Event::Closed ||
        Main_Event_.type == sf::Event::KeyPressed &&
        (Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
        Keyboard::isKeyPressed(sf::Keyboard::Enter))) { // close
            Main_Window_.close();
        } else if (Main_Event_.type == Event::KeyPressed) { // add letter
            std::string pl = Input_Letters();
            if (pl == "$") {
                if (!Input_String_.empty()) {
                    Input_String_.pop_back();
                }
            } else {
                Input_String_ += pl;
            }
        }
    }
}

void Second_Extra_Window::Draw() noexcept {
    Main_Window_.clear();
    DrawBox(Main_Window_, Main_Box_.position, Main_Box_.size, Main_Box_.COLOR);
    DrawTextInBox(Main_Window_, Main_Box_.position, Main_Box_.size, Input_String_,
                  User_Text);
    Main_Window_.display();
}

void Second_Extra_Window::FindErrors() {
    if (Input_String_.empty()) {
            return;
        }
        if (Input_String_[0] == '-' && Input_String_.size() == 1) {
            throw std::string{"not num"};
        }
        if (Input_String_.find('-') != std::string::npos) {
            throw std::string{"minus..."};
        }
        if (Input_String_[0] == '0' && Input_String_.size() > 1) {
            throw std::string{"0 isn't first"};
        }
        if (Input_String_.size() >= 5) {
            throw std::string{"big size"};
        }
        int64_t num = stoi(Input_String_);
        if (num > 2000) {
            throw std::string{"big size"};
        }
    }

std::string Second_Extra_Window::Process() {
    while (Main_Window_.isOpen()) {
        Events();
        Draw();
    }
    try {
        FindErrors();
    } catch (const std::string& error) {
        ErrorWindow Window(error);
        Window.Process();
        Input_String_.clear();
    }
    return Input_String_;
}
