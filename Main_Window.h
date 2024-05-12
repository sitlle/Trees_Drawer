#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include"AVL.h"
#include"DD.h"
#include"SPLAY.h"
#include"First_Extra_Window.h"
#include"Second_Extra_Window.h"
#include"Info_Vertex_Window.h"
#include"VERTEX.h"
#include"Trees_Building.h"
#include"TREE_OPTIONS.h"
#include"Drawer.h"
#include"PRINT_TREE_OPTIONS.h"
#include"Control.h"
#include "Info_Tree_Window.h"
#include"RB.h"

#pragma once

class WHICH_VERTEX;

class MAIN_WINDOW {
    friend class Control::KeyBoard_Control;
    friend class Control::Mouse_Control;
    friend class Control::Arrow_Control;
    friend class Control::Nums_Control;
    friend class Drawer;
    friend class WHICH_VERTEX;
    friend class FIND_BLUE_VERTEX;

  public:
    MAIN_WINDOW();
    ~MAIN_WINDOW() = default;
    //Process
    void Process();
    //Process

    void Events();

    //Extra_Func

    template<typename vertex_type>
    void InOrder_Add_X(VERTEX<vertex_type>* vertex, int32_t add) noexcept;

    template<typename vertex_type>
    void InOrder_Add_Y(VERTEX<vertex_type>* vertex, int32_t add) noexcept;

    template<typename vertex_type>
    void LEFT_CLICK(VERTEX<vertex_type>* TREE) noexcept;

    template<typename vertex_type>
    void RIGHT_CLICK(VERTEX<vertex_type>* TREE) noexcept;
  private:
    static constexpr int32_t WINDOW_W_ = 2500;
    static constexpr int32_t WINDOW_H_ = 1500;
    // zoom_
    static RenderWindow Main_Window_;
    Event Main_Event_{};
    // Text, Font
    static Font User_Font_;
    static Text User_Text_;
    // click
    static Vector2i mouse_pos_;
    enum struct click_type_ {
        LEFT,
        RIGHT,
        EMPTY
    }; click_type_ click_;
    // Window
    enum struct which_window_ {
        DD_TREE,
        AVL_TREE,
        SPLAY_TREE,
        RB_TREE
    }; static which_window_ type_;
    // trees
    static AVL AVL_TREE_;
    static DD DD_TREE_;
    static SPLAY SPLAY_TREE_;
    static RB RB_TREE_;
    // print options
    static PRINT_TREE_OPTIONS PRINT_DD_OPTIONS_;
    static PRINT_TREE_OPTIONS PRINT_AVL_OPTIONS_;
    static PRINT_TREE_OPTIONS PRINT_SPLAY_OPTIONS_;
    static PRINT_TREE_OPTIONS PRINT_RB_OPTIONS_;
    // options
    static TREE_OPTIONS DD_OPTIONS_;
    static TREE_OPTIONS AVL_OPTIONS_;
    static TREE_OPTIONS SPLAY_OPTIONS_;
    static TREE_OPTIONS RB_OPTIONS_;
    // Draw trees
    static VERTEX<Node_AVL>* AVL_DRAW_TREE_;
    static VERTEX<Node_DD>* DD_DRAW_TREE_;
    static VERTEX<Node_SPLAY>* SPLAY_DRAW_TREE_;
    static VERTEX<Node_RB>* RB_DRAW_TREE_;
};

class WHICH_VERTEX {
public:
    WHICH_VERTEX() = default;
    ~WHICH_VERTEX() = default;

    template<typename vertex_type>
    static VERTEX<vertex_type>* FindVertex(VERTEX<vertex_type>* vertex) noexcept;

    template<typename vertex_type>
    static VERTEX<vertex_type>* Which_Vertex(VERTEX<vertex_type>* TREE) noexcept;
};

class FIND_BLUE_VERTEX {
public:
    FIND_BLUE_VERTEX() = default;
    ~FIND_BLUE_VERTEX() = default;

    template<typename vertex_type>
    static void Find_All_Blue(VERTEX<vertex_type>* TREE,
                              std::vector<vertex_type*> &blue_list) noexcept;

    template<typename vertex_type>
    static std::vector<vertex_type*> Get_All_Blue(VERTEX<vertex_type>* TREE) noexcept;
};

template<typename vertex_type>
VERTEX<vertex_type>* WHICH_VERTEX::Which_Vertex(VERTEX<vertex_type>* TREE) noexcept {
    VERTEX<vertex_type>* res = FindVertex(TREE); // res maybe nullptr
    if (res != nullptr) {
        std::cout << "------------------------------------------\n";
        std::cout << "value: " << std::to_string(res->real_vertex->val) << '\n';
        std::cout << "height: " << std::to_string(res->real_vertex->param.height) << '\n';
        std::cout << "posX: " << bigint::to_string(res->real_vertex->param.posX) << '\n';
        std::cout << "sdv: " << bigint::to_string(res->real_vertex->param.sdv) << '\n';
        std::cout << "left posX: " << bigint::to_string(res->real_vertex->param.L) << '\n';
        std::cout << "right posX: " << bigint::to_string(res->real_vertex->param.R) << '\n';
        std::cout << "------------------------------------------\n";
    }
    return res;
}

// FIND_BLUE_VERTEX

template<typename vertex_type>
void FIND_BLUE_VERTEX::Find_All_Blue(VERTEX<vertex_type>* TREE,
                                     std::vector<vertex_type*> &blue_list) noexcept {
    if (TREE == nullptr) {
        return;
    }
    if (TREE->COLOR == sf::Color::Blue) {
        blue_list.push_back(TREE->real_vertex);
    }
    Find_All_Blue(TREE->left, blue_list);
    Find_All_Blue(TREE->right, blue_list);
}

template<typename vertex_type>
std::vector<vertex_type*> FIND_BLUE_VERTEX::Get_All_Blue(VERTEX<vertex_type>* TREE) noexcept {
    std::vector<vertex_type*> blue_list;
    Find_All_Blue(TREE, blue_list);
    return blue_list;
}
