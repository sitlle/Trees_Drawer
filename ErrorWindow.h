#include<SFML/Graphics.hpp>
#pragma once

class ErrorWindow {
  public:
    ErrorWindow() = default;
    ~ErrorWindow() = default;
    explicit ErrorWindow(const std::string& error);
    void Process();
  private:
    sf::RenderWindow Error_Window_;
    sf::Event Error_Event_{};
    std::string message_;
    sf::Font Main_Font_;
    sf::Text Main_Text_;
};
