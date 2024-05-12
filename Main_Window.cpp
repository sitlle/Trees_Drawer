#include"Main_Window.h"
#include"Drawer.h"
using namespace std;

RenderWindow MAIN_WINDOW::Main_Window_(VideoMode(WINDOW_W_, WINDOW_H_), "meow");
Vector2i MAIN_WINDOW::mouse_pos_;

// options
PRINT_TREE_OPTIONS MAIN_WINDOW::PRINT_DD_OPTIONS_;
PRINT_TREE_OPTIONS MAIN_WINDOW::PRINT_AVL_OPTIONS;
PRINT_TREE_OPTIONS MAIN_WINDOW::PRINT_SPLAY_OPTIONS;

TREE_OPTIONS MAIN_WINDOW::DD_OPTIONS_;
TREE_OPTIONS MAIN_WINDOW::AVL_OPTIONS_;
TREE_OPTIONS MAIN_WINDOW::SPLAY_OPTIONS;
// tree
DD MAIN_WINDOW::DD_TREE_;
AVL MAIN_WINDOW::AVL_TREE_;
SPLAY MAIN_WINDOW::SPLAY_TREE_;

// draw
VERTEX<Node_DD>* MAIN_WINDOW::DD_DRAW_TREE_;
VERTEX<Node_AVL>* MAIN_WINDOW::AVL_DRAW_TREE_;
VERTEX<Node_SPLAY>* MAIN_WINDOW::SPLAY_DRAW_TREE_;

float MAIN_WINDOW::zoom_ = 1.f;
MAIN_WINDOW::which_window_ MAIN_WINDOW::type_ = MAIN_WINDOW::which_window_::DD_TREE;
sf::Font MAIN_WINDOW::User_Font_;
sf::Text MAIN_WINDOW::User_Text_;

MAIN_WINDOW::MAIN_WINDOW() :
        click_(click_type_::EMPTY) {
    User_Font_.loadFromFile("/home/yeawer/tree/Hack-Bold.ttf");
    User_Text_.setFont(User_Font_);
}

template<typename vertex_type>
void MAIN_WINDOW::InOrder_Add_X
(VERTEX<vertex_type> *vertex, int32_t add) noexcept {
    if (vertex == nullptr) {
        return;
    }
    InOrder_Add_X<vertex_type>(vertex->left, add);
    vertex->coords.first += float(add);
    InOrder_Add_X<vertex_type>(vertex->right, add);
}

template<typename vertex_type> void MAIN_WINDOW::InOrder_Add_Y
(VERTEX<vertex_type>* vertex, int32_t add) noexcept {
    if (vertex == nullptr) {
        return;
    }
    InOrder_Add_Y<vertex_type>(vertex->left, add);
    vertex->coords.second += float(add);
    InOrder_Add_Y<vertex_type>(vertex->right, add);
}

void MAIN_WINDOW::Events() {
    while (Main_Window_.pollEvent(Main_Event_)) {
        if (Main_Event_.type == Event::Closed ||
            Main_Event_.type == Event::KeyPressed &&
            Keyboard::isKeyPressed(Keyboard::Escape)) {
            Main_Window_.close();
        } else if (Main_Event_.type == Event::MouseButtonPressed) { // click
            if (Mouse::isButtonPressed(Mouse::Left)) {
                click_ = click_type_::LEFT;
                mouse_pos_ = Mouse::getPosition(Main_Window_);
            } else if (Mouse::isButtonPressed(Mouse::Right)) {
                click_ = click_type_::RIGHT;
                mouse_pos_ = Mouse::getPosition(Main_Window_);
            }
        } else if (Main_Event_.type == Event::KeyPressed) {
            if (Keyboard::isKeyPressed(Keyboard::Num1)) { // add one num
                Control::Nums_Control::NUM1();
            } else if (Keyboard::isKeyPressed(sf::Keyboard::Num2)) { // add x nums
                Control::Nums_Control::NUM2();
            }  else if (Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                Control::Nums_Control::NUM3();
            } else if (Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                Control::Nums_Control::NUM4();
            } else if (Keyboard::isKeyPressed(Keyboard::W)) {
                Control::KeyBoard_Control::MOVE_UP();
            } else if (Keyboard::isKeyPressed(Keyboard::S)) {
                Control::KeyBoard_Control::MOVE_DOWN();
            } else if (Keyboard::isKeyPressed(Keyboard::A)) {
                Control::KeyBoard_Control::MOVE_LEFT();
            } else if (Keyboard::isKeyPressed(Keyboard::D)) {
                Control::KeyBoard_Control::MOVE_RIGHT();
            } else if (Keyboard::isKeyPressed(Keyboard::Left)) {
                Control::Arrow_Control::MOVE_LEFT();
            } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                Control::Arrow_Control::MOVE_RIGHT();
            } else if (Keyboard::isKeyPressed(Keyboard::Down)) {
                Control::Arrow_Control::MOVE_DOWN();
            } else if (Keyboard::isKeyPressed(Keyboard::Up)) {
                Control::Arrow_Control::MOVE_UP();
            } else if (Keyboard::isKeyPressed(Keyboard::Delete)) {
                Control::KeyBoard_Control::DELETE();
            }
        } else if (Main_Event_.type == sf::Event::MouseWheelMoved) {
            if (Main_Event_.mouseWheel.delta == -1) {
                Control::Mouse_Control::MOVE_DOWN();
            } else if (Main_Event_.mouseWheel.delta == 1) {
                Control::Mouse_Control::MOVE_UP();
            }
        }
    }
}

void MAIN_WINDOW::Process() {
    while (Main_Window_.isOpen()) {
        Events();
        if (click_ == click_type_::LEFT) {
            if (type_ == which_window_::DD_TREE) {
                LEFT_CLICK<Node_DD>(DD_DRAW_TREE_);
            } else if (type_ == which_window_::AVL_TREE) {
                LEFT_CLICK<Node_AVL>(AVL_DRAW_TREE_);
            } else if (type_ == which_window_::SPLAY_TREE) {
                LEFT_CLICK<Node_SPLAY>(SPLAY_DRAW_TREE_);
            }
            click_ = click_type_::EMPTY;
        } else if (click_ == click_type_::RIGHT) {
            if (type_ == which_window_::DD_TREE) {
                RIGHT_CLICK<Node_DD>(DD_DRAW_TREE_);
            } else if (type_ == which_window_::AVL_TREE) {
                RIGHT_CLICK<Node_AVL>(AVL_DRAW_TREE_);
            } else if (type_ == which_window_::SPLAY_TREE) {
                RIGHT_CLICK<Node_SPLAY>(SPLAY_DRAW_TREE_);
            }
            click_ = click_type_::EMPTY;
        }
        Drawer::Draw();
    }
}

template<typename vertex_type>
void MAIN_WINDOW::LEFT_CLICK(VERTEX<vertex_type>* TREE) noexcept {
    VERTEX<vertex_type>* res = WHICH_VERTEX::Which_Vertex<vertex_type>(TREE);
    if (res != nullptr) {
        if (res->COLOR == Color::Blue) {
            res->COLOR = Color::Red;
            res->real_vertex->param.COLOR = Color::Red;
        } else {
            res->COLOR = Color::Blue;
            res->real_vertex->param.COLOR = Color::Blue;
        }
    }
}

template<typename vertex_type>
void MAIN_WINDOW::RIGHT_CLICK(VERTEX<vertex_type> *TREE) noexcept {
    VERTEX<vertex_type>* res = WHICH_VERTEX::Which_Vertex<vertex_type>(TREE);
    if (res != nullptr) {
        Info_Extra_Window e(res);
        e.Process();
    }
}

// WHICH VERTEX

template<typename vertex_type>
VERTEX<vertex_type>* WHICH_VERTEX::FindVertex(VERTEX<vertex_type> *vertex) noexcept {
    float FIRST = 0;
    float SECOND = 0;
    float zoom = 1.f;
    if (vertex == nullptr) {
        return nullptr;
    }
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        FIRST = (vertex->coords.first + MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_x  + vertex->radius) /
                MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom;
        SECOND = (vertex->coords.second + MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_y + vertex->radius) /
                 MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom;
        zoom = MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        FIRST = (vertex->coords.first + MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_x + vertex->radius) /
                MAIN_WINDOW::PRINT_AVL_OPTIONS.zoom;
        SECOND = (vertex->coords.second + MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_y  + vertex->radius) /
                 MAIN_WINDOW::PRINT_AVL_OPTIONS.zoom;
        zoom = MAIN_WINDOW::PRINT_AVL_OPTIONS.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        FIRST = (vertex->coords.first + MAIN_WINDOW::PRINT_SPLAY_OPTIONS.cnt_x + vertex->radius) /
                MAIN_WINDOW::PRINT_SPLAY_OPTIONS.zoom;
        SECOND = (vertex->coords.second + MAIN_WINDOW::PRINT_SPLAY_OPTIONS.cnt_y  + vertex->radius) /
                 MAIN_WINDOW::PRINT_SPLAY_OPTIONS.zoom;
        zoom = MAIN_WINDOW::PRINT_SPLAY_OPTIONS.zoom;
    }
    float dist = std::sqrt((float(MAIN_WINDOW::mouse_pos_.x) - FIRST) *
                           (float(MAIN_WINDOW::mouse_pos_.x) - FIRST) +
                           (float(MAIN_WINDOW::mouse_pos_.y) - SECOND) *
                           (float(MAIN_WINDOW::mouse_pos_.y) - SECOND));
    if (dist <= vertex->radius / zoom) {
        return vertex;
    }
    VERTEX<vertex_type>* ans1 = nullptr;
    VERTEX<vertex_type>* ans2 = nullptr;
    if (vertex->left != nullptr) {
        ans1 = FindVertex(vertex->left);
    }
    if (vertex->right != nullptr) {
        ans2 = FindVertex(vertex->right);
    }
    if (ans1 == nullptr && ans2 == nullptr) {
        return nullptr;
    }
    if (ans1 != nullptr) {
        return ans1;
    }
    return ans2;
}