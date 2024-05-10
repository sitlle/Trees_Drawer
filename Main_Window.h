#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include"AVL.h"
#include"DD.h"
#include"First_Extra_Window.h"
#include"Second_Extra_Window.h"
#include"Info_Extra_Window.h"
#include"VERTEX.h"
#include"Trees_Building.h"
#include"TREE_OPTIONS.h"
#include"Drawer.h"
#include"PRINT_TREE_OPTIONS.h"
#include"Control.h"
#pragma once

class WHICH_VERTEX;

class MAIN_WINDOW {
    friend class Control::WASD_Control;
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
    static float zoom_;
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
    // 0 - DD, 1 - AVL, 2 - Splay
    enum struct which_window_ {
        DD_TREE,
        AVL_TREE,
        SPLAY_TREE
    }; static which_window_ type_;
    // trees
    static AVL AVL_TREE_;
    static DD DD_TREE_;
    // DD options
    static PRINT_TREE_OPTIONS PRINT_DD_OPTIONS_;
    // AVL options
    static PRINT_TREE_OPTIONS PRINT_AVL_OPTIONS;
    // Splay counters
    static PRINT_TREE_OPTIONS PRINT_SPLAY_OPTIONS;
    // options
    static TREE_OPTIONS DD_OPTIONS_;
    static TREE_OPTIONS AVL_OPTIONS_;
    // Draw trees
    static VERTEX<Node_AVL>* AVL_DRAW_TREE_;
    static VERTEX<Node_DD>* DD_DRAW_TREE_;
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
                              std::vector<vertex_type>& blue_list) noexcept;

    template<typename vertex_type>
    static std::vector<vertex_type> Get_All_Blue(VERTEX<vertex_type>* TREE) noexcept;
};