#include<SFML/Graphics.hpp>
#include"FrontEnd.h"

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    MAIN_WINDOW Pr{};
    Pr.Process();
}