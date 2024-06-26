#include"Main_Window.h"
#include"Drawer.h"
using namespace std;

RenderWindow MAIN_WINDOW::Main_Window_(VideoMode(WINDOW_W_, WINDOW_H_), "meow");
Vector2i MAIN_WINDOW::mouse_pos_;

// options
PRINT_TREE_OPTIONS MAIN_WINDOW::PRINT_DD_OPTIONS_;
PRINT_TREE_OPTIONS MAIN_WINDOW::PRINT_AVL_OPTIONS_;
PRINT_TREE_OPTIONS MAIN_WINDOW::PRINT_SPLAY_OPTIONS_;
PRINT_TREE_OPTIONS MAIN_WINDOW::PRINT_RB_OPTIONS_;

TREE_OPTIONS MAIN_WINDOW::DD_OPTIONS_;
TREE_OPTIONS MAIN_WINDOW::AVL_OPTIONS_;
TREE_OPTIONS MAIN_WINDOW::SPLAY_OPTIONS_;
TREE_OPTIONS MAIN_WINDOW::RB_OPTIONS_;
// tree
DD MAIN_WINDOW::DD_TREE_;
AVL MAIN_WINDOW::AVL_TREE_;
SPLAY MAIN_WINDOW::SPLAY_TREE_;
RB MAIN_WINDOW::RB_TREE_;

// draw
VERTEX<Node_DD>* MAIN_WINDOW::DD_DRAW_TREE_;
VERTEX<Node_AVL>* MAIN_WINDOW::AVL_DRAW_TREE_;
VERTEX<Node_SPLAY>* MAIN_WINDOW::SPLAY_DRAW_TREE_;
VERTEX<Node_RB>* MAIN_WINDOW::RB_DRAW_TREE_;

MAIN_WINDOW::which_window_ MAIN_WINDOW::type_ = MAIN_WINDOW::which_window_::DD_TREE;
sf::Font MAIN_WINDOW::User_Font_;
sf::Text MAIN_WINDOW::User_Text_;

MAIN_WINDOW::MAIN_WINDOW() :
        click_(click_type_::EMPTY) {
    User_Font_.loadFromFile("/home/yeawer/tree/Hack-Bold.ttf");
    User_Text_.setFont(User_Font_);
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
            } else if (Keyboard::isKeyPressed(Keyboard::I)) {
                Control::KeyBoard_Control::CLICK_I();
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
            if (mouse_pos_.y > 100) {
                if (type_ == which_window_::DD_TREE) {
                    LEFT_CLICK<Node_DD>(DD_DRAW_TREE_);
                } else if (type_ == which_window_::AVL_TREE) {
                    LEFT_CLICK<Node_AVL>(AVL_DRAW_TREE_);
                } else if (type_ == which_window_::SPLAY_TREE) {
                    LEFT_CLICK<Node_SPLAY>(SPLAY_DRAW_TREE_);
                } else if (type_ == which_window_::RB_TREE) {
                    LEFT_CLICK<Node_RB>(RB_DRAW_TREE_);
                }
            } else {
                const float size = WINDOW_W_ + 100;
                const float box_size = size / 4;
                if (float(mouse_pos_.x) >= 150.f && float(mouse_pos_.x) <= 270.f) {
                    type_ = which_window_::DD_TREE;
                } else if (float(mouse_pos_.x) >= box_size && float(mouse_pos_.x) <= box_size + 240.f) {
                    type_ = which_window_::AVL_TREE;
                } else if (float(mouse_pos_.x) >= 2 * box_size && float(mouse_pos_.x) <= 2 * box_size + 300.f) {
                    type_ = which_window_::SPLAY_TREE;
                } else if (float(mouse_pos_.x) >= 3 * box_size && float(mouse_pos_.x) <= 3 * box_size + 420.f) {
                    type_ = which_window_::RB_TREE;
                }
            }
            click_ = click_type_::EMPTY;
        } else if (click_ == click_type_::RIGHT) {
            if (type_ == which_window_::DD_TREE) {
                RIGHT_CLICK<Node_DD>(DD_DRAW_TREE_);
            } else if (type_ == which_window_::AVL_TREE) {
                RIGHT_CLICK<Node_AVL>(AVL_DRAW_TREE_);
            } else if (type_ == which_window_::SPLAY_TREE) {
                RIGHT_CLICK<Node_SPLAY>(SPLAY_DRAW_TREE_);
            } else if (type_ == which_window_::RB_TREE) {
                RIGHT_CLICK<Node_RB>(RB_DRAW_TREE_);
            }
            click_ = click_type_::EMPTY;
        }
        Drawer::Draw();
    }
}

void MAIN_WINDOW::DrawTreeNames() noexcept {
    const float size = WINDOW_W_ + 100;
    sf::RectangleShape Big_Box(sf::Vector2f(0, 0));
    Big_Box.setSize(sf::Vector2f(size, 100));
    Big_Box.setFillColor(sf::Color::Black);
    Main_Window_.draw(Big_Box);
    std::vector<std::string> names(4);
    std::string DD_NAME = "Pivo";
    std::string AVL_NAME = "AVL tree";
    std::string SPLAY_NAME = "Splay tree";
    std::string RB_NAME = "Red-black tree";
    names[0] = DD_NAME;
    names[1] = AVL_NAME;
    names[2] = SPLAY_NAME;
    names[3] = RB_NAME;
    std::vector<float> pos_x(4);
    pos_x[0] += 150;
    std::vector<sf::Color> colors(4, sf::Color::White);
    if (type_ == which_window_::DD_TREE) {
        colors[0] = sf::Color::Red;
    } else if (type_ == which_window_::AVL_TREE) {
        colors[1] = sf::Color::Red;
    } else if (type_ == which_window_::SPLAY_TREE) {
        colors[2] = sf::Color::Red;
    } else if (type_ == which_window_::RB_TREE) {
        colors[3] = sf::Color::Red;
    }
    const float box_size = size / 4;
    for (int i = 0; i < 4; ++i) {
        DrawTextInBox(Main_Window_, {box_size * float(i) + pos_x[i], 0},
                      {box_size, 100}, names[i],
                      User_Text_, 0, 50, colors[i]);
    }
}

template<typename vertex_type>
void MAIN_WINDOW::LEFT_CLICK(VERTEX<vertex_type>* TREE) noexcept {
    VERTEX<vertex_type>* res = WHICH_VERTEX::Which_Vertex<vertex_type>(TREE);
    if (res != nullptr) {
        if (res->COLOR == Color::Blue) {
            res->COLOR = res->real_vertex->param.COLOR;
        } else {
            res->COLOR = Color::Blue;
        }
    }
}

template<typename vertex_type>
void MAIN_WINDOW::RIGHT_CLICK(VERTEX<vertex_type> *TREE) noexcept {
    VERTEX<vertex_type>* res = WHICH_VERTEX::Which_Vertex<vertex_type>(TREE);
    if (res != nullptr) {
        Info_Vertex_Window e(res);
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
        FIRST = (vertex->coords.first + MAIN_WINDOW::PRINT_AVL_OPTIONS_.cnt_x + vertex->radius) /
                MAIN_WINDOW::PRINT_AVL_OPTIONS_.zoom;
        SECOND = (vertex->coords.second + MAIN_WINDOW::PRINT_AVL_OPTIONS_.cnt_y + vertex->radius) /
                 MAIN_WINDOW::PRINT_AVL_OPTIONS_.zoom;
        zoom = MAIN_WINDOW::PRINT_AVL_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        FIRST = (vertex->coords.first + MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.cnt_x + vertex->radius) /
                MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.zoom;
        SECOND = (vertex->coords.second + MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.cnt_y + vertex->radius) /
                 MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.zoom;
        zoom = MAIN_WINDOW::PRINT_SPLAY_OPTIONS_.zoom;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::RB_TREE) {
        FIRST = (vertex->coords.first + MAIN_WINDOW::PRINT_RB_OPTIONS_.cnt_x + vertex->radius) /
                MAIN_WINDOW::PRINT_RB_OPTIONS_.zoom;
        SECOND = (vertex->coords.second + MAIN_WINDOW::PRINT_RB_OPTIONS_.cnt_y + vertex->radius) /
                 MAIN_WINDOW::PRINT_RB_OPTIONS_.zoom;
        zoom = MAIN_WINDOW::PRINT_RB_OPTIONS_.zoom;
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