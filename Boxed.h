#include<SFML/Graphics.hpp>
using namespace sf;
#pragma once

static void DrawBox(sf::RenderWindow& Main_Window, sf::Vector2f& position,
             sf::Vector2f& size, sf::Color COLOR = sf::Color::White) {
    sf::Vertex line1[] = {
            Vertex(sf::Vector2f(position.x, position.y), COLOR),
            Vertex(sf::Vector2f(position.x + size.x, position.y),COLOR)
    };
    sf::Vertex line2[] = {
            Vertex(sf::Vector2f(position.x, position.y), COLOR),
            Vertex(sf::Vector2f(position.x, position.y + size.y), COLOR)
    };
    sf::Vertex line3[] = {
            Vertex(sf::Vector2f(position.x + size.x, position.y), COLOR),
            Vertex(sf::Vector2f(position.x + size.x, position.y + size.y), COLOR)
    };
    sf::Vertex line4[] = {
            Vertex(sf::Vector2f(position.x, position.y + size.y), COLOR),
            Vertex(sf::Vector2f(position.x + size.x, position.y + size.y), COLOR)
    };
    Main_Window.draw(line1, 2, sf::Lines);
    Main_Window.draw(line2, 2, sf::Lines);
    Main_Window.draw(line3, 2, sf::Lines);
    Main_Window.draw(line4, 2, sf::Lines);
}

static void DrawTextInBox(sf::RenderWindow& Main_Window, sf::Vector2f position,
                   sf::Vector2f size, std::string Output_String, sf::Text Output_Text, int start_pos = 0,
                   int Text_Size = 110, sf::Color COLOR = sf::Color::White) {
    Output_Text.setCharacterSize(Text_Size);
    Output_Text.setFillColor(COLOR);
    std::string res;
    for (int i = start_pos; i < Output_String.size(); ++i) {
        res += Output_String[i];
        Output_Text.setString(res);
        if (Output_Text.getLocalBounds().width > size.x - static_cast<float>(Text_Size) / 2) {
            break;
        }
    }
    const double x_position = position.x;
    const double y_position = position.y + (size.y - Output_Text.getLocalBounds().height) / 2;
    Output_Text.setPosition(sf::Vector2f(static_cast<float>(x_position),
                                         static_cast<float>(y_position)));
    Main_Window.draw(Output_Text);
}