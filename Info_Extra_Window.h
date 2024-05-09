#include<bits/stdc++.h>
#include"Boxed.h"
#include"KeyBoard.h"
#include"VERTEX.h"
#include"Node_DD.h"
#include"Node_AVL.h"
//splay node
#include"Node_Options.h"
#pragma once

class Info_Extra_Window {
public:
    Info_Extra_Window() = default;
    ~Info_Extra_Window() = default;
    template<typename vertex_type>
    explicit Info_Extra_Window(VERTEX<vertex_type>* Input_Vertex);
    void Events();
    void Draw();
    void Process();
private:
    Font User_Font;
    Text User_Text;
    struct WINDOW {
        Color COLOR = Color::White;
        Vector2f position = {0, 0};
        Vector2f size = {0, 0};
        WINDOW() = default;
        ~WINDOW() = default;
    };
    static constexpr int32_t WINDOW_W_ = 1500;
    static const int32_t WINDOW_H_ = 599;
    RenderWindow Main_Window_;
    Event Main_Event_{};
    std::vector<WINDOW> Boxes_;
    std::vector<std::string> Info_;
    int cnt = 0;
};

template<typename vertex_type>
Info_Extra_Window::Info_Extra_Window(VERTEX<vertex_type> *Input_Vertex) :
        Main_Window_(VideoMode(WINDOW_W_, WINDOW_H_), "meow") {
    Boxes_.resize(6);
    Info_.resize(6);
    for (int i = 0; i < 6; ++i) {
        Boxes_[i].COLOR = Color::White;
        Boxes_[i].size = Vector2f(static_cast<float>(WINDOW_W_) + 100, 100);
        Boxes_[i].position = Vector2f(0.f, float(i) * 100.f);
    }
    Info_[0] = "value: " + std::to_string(Input_Vertex->val);
    Info_[1] = "height: " + std::to_string(Input_Vertex->real_vertex->param.height);
    Info_[2] = "posX: " + bigint::bigint_to_string(Input_Vertex->real_vertex->param.posX);
    Info_[3] = "shift: " + bigint::bigint_to_string(Input_Vertex->real_vertex->param.sdv);
    Info_[4] = "left posX: " + bigint::bigint_to_string(Input_Vertex->real_vertex->param.L);
    Info_[5] = "right posX: " + bigint::bigint_to_string(Input_Vertex->real_vertex->param.R);
    Main_Window_.setPosition(Vector2i(500, 500));
    User_Font.loadFromFile("/home/yeawer/tree/Hack-Bold.ttf");
    User_Text.setFont(User_Font);
}
