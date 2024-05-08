#include "First_Extra_Window.h"
#include "KeyBoard.h"
#include "Boxed.h"
#include "ErrorWindow.h"


First_Extra_Window::First_Extra_Window() : Main_Window_(VideoMode(WINDOW_W_, WINDOW_H_), "extra_meow") {
    Main_Box_.size = {1250, 150};
    Main_Box_.position = {(static_cast<float>(WINDOW_W_) - Main_Box_.size.x) / 2,
                          (static_cast<float>(WINDOW_H_) - Main_Box_.size.y) / 2};
    Main_Window_.setPosition(Vector2i(500, 500));
    User_Font.loadFromFile("/home/yeawer/tree/Hack-Bold.ttf");
    User_Text.setFont(User_Font);
}

void First_Extra_Window::Events() {
    while (Main_Window_.pollEvent(Main_Event_)) {
        if (Main_Event_.type == sf::Event::Closed ||
        Main_Event_.type == sf::Event::KeyPressed &&
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))) { // close
            Main_Window_.close();
        } else if (Main_Event_.type == sf::Event::KeyPressed) { // add letter
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

void First_Extra_Window::Draw() noexcept {
    Main_Window_.clear();
    DrawBox(Main_Window_, Main_Box_.position, Main_Box_.size, Main_Box_.COLOR);
    DrawTextInBox(Main_Window_, Main_Box_.position, Main_Box_.size, Input_String_,
                  User_Text);
    Main_Window_.display();
}

void First_Extra_Window::FindErrors() {
    if (Input_String_.empty()) {
        return;
    }
    if (Input_String_[0] == '-') {
        if (Input_String_.size() >= 10) {
            throw std::string{"big size"};
        }
    } else if (Input_String_.size() >= 10) {
        throw std::string{"big size"};
    }
    for (int i = 0; i < static_cast<int>(Input_String_.size()); ++i) {
        if (Input_String_[i] == '-' && i != 0) {
            throw std::string{"extra minus"};
        }
    }
    if (Input_String_[0] == '0' && Input_String_.size() > 1 ||
        Input_String_.size() >= 2 && Input_String_[0] == '-' && Input_String_[1] == '0') {
        throw std::string{"0 isn't first"};
    }
    if (Input_String_[0] == '-' && Input_String_.size() == 1) {
        throw std::string{"not num"};
    }
}

std::string First_Extra_Window::Process() {
    while (Main_Window_.isOpen()) {
        Events();
        Draw();
    }
    // check errors
    try {
        FindErrors();
    } catch (const std::string& error) {
        ErrorWindow Window(error);
        Window.Process();
        Input_String_.clear();
    }
    return Input_String_;
}