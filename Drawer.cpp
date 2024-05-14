#include "Drawer.h"
#include "Main_Window.h"

void Drawer::Draw() noexcept {
    MAIN_WINDOW::Main_Window_.clear(sf::Color::White);
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) { // draw DD
        Print_DD_TREE();
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) { // draw AVL
        Print_AVL_TREE();
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) { // draw SPLAY
        Print_SPLAY_TREE();
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::RB_TREE) { // draw RB
        Print_RB_TREE();
    }
    MAIN_WINDOW::DrawTreeNames();
    MAIN_WINDOW::Main_Window_.display();
}

template<typename vertex_type> void Drawer::DrawVertex(VERTEX<vertex_type>* vertex) noexcept {
    CircleShape Output_Circle;
    float addX = 0;
    float addY = 0;
    float zoom = 1.f;
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        addX = MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_x;
        addY = MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_y;
        zoom = MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        addX = MAIN_WINDOW::PRINT_AVL_OPTIONS_.cnt_x;
        addY = MAIN_WINDOW::PRINT_AVL_OPTIONS_.cnt_y;
        zoom = MAIN_WINDOW::PRINT_AVL_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        addX = MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.cnt_x;
        addY = MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.cnt_y;
        zoom = MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::RB_TREE) {
        addX = MAIN_WINDOW::PRINT_RB_OPTIONS_.cnt_x;
        addY = MAIN_WINDOW::PRINT_RB_OPTIONS_.cnt_y;
        zoom = MAIN_WINDOW::PRINT_RB_OPTIONS_.zoom;
    }
    Output_Circle.setPosition(Vector2f({vertex->coords.first / zoom + addX / zoom,
                                        vertex->coords.second / zoom + addY / zoom}));
    Output_Circle.setRadius(vertex->radius / zoom);
    Output_Circle.setFillColor(vertex->COLOR);
    MAIN_WINDOW::Main_Window_.draw(Output_Circle);
    // Draw Text
    float text_size = vertex->radius / 1.5;
    float pos_x = 0;
    float pos_y = 0;
    std::string value = std::to_string(vertex->val);
    if (value.size() >= 6) {
        MAIN_WINDOW::User_Text_.setString("...");
    } else {
        MAIN_WINDOW::User_Text_.setString(std::to_string(vertex->val));
    }
    if (value.size() == 1) {
        pos_x += 4.5;
    } else if (value.size() == 2) {
        pos_x -= 1.5;
    } else if (value.size() == 3) {
        pos_x -= 6.5;
    } else if (value.size() == 4) {
        pos_x -= 0.8;
        pos_y += 7;
        text_size = vertex->radius / 2;
    } else if (value.size() == 5) {
        pos_x += 1;
        pos_y += 12;
        text_size = vertex->radius / 2.5;
    } else {
        pos_x -= 3;
    }
    MAIN_WINDOW::User_Text_.setPosition(Vector2f((vertex->coords.first + addX + text_size + pos_x) / zoom,
                                                 (vertex->coords.second + addY + text_size + pos_y) / zoom ));
    MAIN_WINDOW::User_Text_.setFillColor(Color::White);
    MAIN_WINDOW::User_Text_.setCharacterSize(static_cast<unsigned int>(text_size / zoom));
    MAIN_WINDOW::Main_Window_.draw(MAIN_WINDOW::User_Text_);
}

void Drawer::DrawLine(const std::pair<float, float> &first, const std::pair<float, float> &second,
                           const float& RADIUS, sf::Color COLOR) noexcept {
    float addX = 0;
    float addY = 0;
    float zoom = 1.f;
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        addX = MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_x;
        addY = MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_y;
        zoom = MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        addX = MAIN_WINDOW::PRINT_AVL_OPTIONS_.cnt_x;
        addY = MAIN_WINDOW::PRINT_AVL_OPTIONS_.cnt_y;
        zoom = MAIN_WINDOW::PRINT_AVL_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        addX = MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.cnt_x;
        addY = MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.cnt_y;
        zoom = MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::RB_TREE) {
        addX = MAIN_WINDOW::PRINT_RB_OPTIONS_.cnt_x;
        addY = MAIN_WINDOW::PRINT_RB_OPTIONS_.cnt_y;
        zoom = MAIN_WINDOW::PRINT_RB_OPTIONS_.zoom;
    }
    sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f((first.first + addX + RADIUS) / zoom,
                                    (first.second + addY + RADIUS) / zoom), sf::Color::Black),
            sf::Vertex(sf::Vector2f((second.first + addX + RADIUS) / zoom,
                                    (second.second + addY + RADIUS) / zoom), sf::Color::Black)
    };
    MAIN_WINDOW::Main_Window_.draw(line, 2, sf::Lines);
}

template<typename vertex_type>
void Drawer::PrintInOrder(VERTEX<vertex_type> *vertex) noexcept {
    if (vertex == nullptr) {
        return;
    }
    if (vertex->left != nullptr) {
        DrawLine(vertex->coords, vertex->left->coords, vertex->radius);
    }
    if (vertex->right != nullptr) {
        DrawLine(vertex->coords, vertex->right->coords, vertex->radius);
    }
    PrintInOrder<vertex_type>(vertex->left);
    DrawVertex(vertex);
    PrintInOrder<vertex_type>(vertex->right);
}

void Drawer::Print_DD_TREE() noexcept {
    PrintInOrder<Node_DD>(MAIN_WINDOW::DD_DRAW_TREE_);
}

void Drawer::Print_AVL_TREE() noexcept {
    PrintInOrder<Node_AVL>(MAIN_WINDOW::AVL_DRAW_TREE_);
}

void Drawer::Print_SPLAY_TREE() noexcept {
    PrintInOrder<Node_SPLAY>(MAIN_WINDOW::SPLAY_DRAW_TREE_);
}

void Drawer::Print_RB_TREE() noexcept {
    PrintInOrder<Node_RB>(MAIN_WINDOW::RB_DRAW_TREE_);
}

