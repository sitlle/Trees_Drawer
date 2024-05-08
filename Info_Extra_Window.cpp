#include "Info_Extra_Window.h"

void Info_Extra_Window::Events() {
    while (Main_Window_.pollEvent(Main_Event_)) {
        if (Main_Event_.type == Event::Closed ||
            Main_Event_.type == Event::KeyPressed &&
            (Keyboard::isKeyPressed(Keyboard::Escape) ||
             Keyboard::isKeyPressed(Keyboard::Enter))) { // close
            Main_Window_.close();
        }
    }
}

void Info_Extra_Window::Draw() {
    Main_Window_.clear();
    for (int i = 0; i < 6; ++i) {
        DrawBox(Main_Window_, Boxes_[i].position, Boxes_[i].size, Boxes_[i].COLOR);
        DrawTextInBox(Main_Window_, Boxes_[i].position, Boxes_[i].size, Info_[i],
                     User_Text, 0, 60);
    }
    Main_Window_.display();
}

void Info_Extra_Window::Process() {
    while (Main_Window_.isOpen()) {
        Events();
        Draw();
        cnt++;
        cnt %= 10;
    }
}