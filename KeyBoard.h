#pragma once
using namespace sf;

static std::string Input_Letters() {
    if (Keyboard::isKeyPressed(Keyboard::Num1)) {
        return "1";
    } else if (Keyboard::isKeyPressed(Keyboard::Num2)) {
        return "2";
    } else if (Keyboard::isKeyPressed(Keyboard::Num3)) {
        return "3";
    } else if (Keyboard::isKeyPressed(Keyboard::Num4)) {
        return "4";
    } else if (Keyboard::isKeyPressed(Keyboard::Num5)) {
        return "5";
    } else if (Keyboard::isKeyPressed(Keyboard::Num6)) {
        return "6";
    } else if (Keyboard::isKeyPressed(Keyboard::Num7)) {
        return "7";
    } else if (Keyboard::isKeyPressed(Keyboard::Num8)) {
        return "8";
    } else if (Keyboard::isKeyPressed(Keyboard::Num9)) {
        return "9";
    } else if (Keyboard::isKeyPressed(Keyboard::Num0)) {
        return "0";
    } else if (Keyboard::isKeyPressed(Keyboard::Hyphen) ||
               Keyboard::isKeyPressed(Keyboard::Subtract)) {
        return "-";
    }
    else if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
        return "$";
    }
    return "";
}