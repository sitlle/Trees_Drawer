#include"FrontEnd.h"
#include "Control.h"
#include"Trees_Building.h"

void Control::WASD_Control::MOVE_UP() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_y += 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_y += 75;
    }
}

void Control::WASD_Control::MOVE_DOWN() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_y -= 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_y -= 75;
    }
}

void Control::WASD_Control::MOVE_LEFT() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_x += 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_x += 75;
    }
}

void Control::WASD_Control::MOVE_RIGHT() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_x -= 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_x -= 75;
    }
}

void Control::Mouse_Control::MOVE_UP() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom -= 0.03f;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.zoom -= 0.03f;
    }
}

void Control::Mouse_Control::MOVE_DOWN() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom += 0.03f;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.zoom += 0.03f;
    }
}

void Control::Arrow_Control::MOVE_LEFT() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::DD_OPTIONS_.TREE_W -= 0.03f;
        MAIN_WINDOW::DD_OPTIONS_.TREE_W = std::max(1.f, MAIN_WINDOW::DD_OPTIONS_.TREE_W);
        MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                             MAIN_WINDOW::DD_OPTIONS_);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::AVL_OPTIONS_.TREE_W -= 0.03f;
        MAIN_WINDOW::AVL_OPTIONS_.TREE_W = std::max(1.f, MAIN_WINDOW::AVL_OPTIONS_.TREE_W);
        MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                MAIN_WINDOW::AVL_OPTIONS_);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {

    }
}

void Control::Arrow_Control::MOVE_RIGHT() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::DD_OPTIONS_.TREE_W += 0.03f;
        MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                             MAIN_WINDOW::DD_OPTIONS_);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::AVL_OPTIONS_.TREE_W += 0.03f;
        MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                MAIN_WINDOW::AVL_OPTIONS_);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {

    }
}

void Control::Arrow_Control::MOVE_DOWN() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::DD_OPTIONS_.TREE_H += 0.03f;
        MAIN_WINDOW::DD_OPTIONS_.TREE_H = std::max(1.f, MAIN_WINDOW::DD_OPTIONS_.TREE_H);
        MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                             MAIN_WINDOW::DD_OPTIONS_);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::AVL_OPTIONS_.TREE_H += 0.03f;
        MAIN_WINDOW::AVL_OPTIONS_.TREE_H = std::max(1.f, MAIN_WINDOW::AVL_OPTIONS_.TREE_H);
        MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                MAIN_WINDOW::AVL_OPTIONS_);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {

    }
}

void Control::Arrow_Control::MOVE_UP() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::DD_OPTIONS_.TREE_H -= 0.03f;
        MAIN_WINDOW::DD_OPTIONS_.TREE_H = std::max(1.f, MAIN_WINDOW::DD_OPTIONS_.TREE_H);
        MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                             MAIN_WINDOW::DD_OPTIONS_);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::AVL_OPTIONS_.TREE_H -= 0.03f;
        MAIN_WINDOW::AVL_OPTIONS_.TREE_H = std::max(1.f, MAIN_WINDOW::AVL_OPTIONS_.TREE_H);
        MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                MAIN_WINDOW::AVL_OPTIONS_);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {

    }
}

void Control::Nums_Control::NUM1() noexcept {
    First_Extra_Window Extra_Window;
    std::string res = Extra_Window.Process();
    if (!res.empty()) {
        int64_t add_num = stoi(res);
        /// more...
        // add DD
        MAIN_WINDOW::DD_TREE_.Add(add_num);
        MAIN_WINDOW::AVL_TREE_.Add(add_num);
        // re-build DD
        MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                             MAIN_WINDOW::DD_OPTIONS_);
        // add AVL
        MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                MAIN_WINDOW::AVL_OPTIONS_);
        // add Splay
    }
}

void Control::Nums_Control::NUM2() noexcept {
    First_Extra_Window Extra_Window;
    std::string res = Extra_Window.Process();
    if (!res.empty()) {
        int32_t add_num = stoi(res);
        /// more...
        // add DD
        MAIN_WINDOW::DD_TREE_.Add_Rnd(add_num);
        MAIN_WINDOW::AVL_TREE_.Add_X(add_num);
        // re-build DD
        MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                             MAIN_WINDOW::DD_OPTIONS_);
        // add AVL
        MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                MAIN_WINDOW::AVL_OPTIONS_);
        // add Splay

    }
}

void Control::Nums_Control::NUM3() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::type_ = MAIN_WINDOW::which_window_::DD_TREE;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        MAIN_WINDOW::type_ = MAIN_WINDOW::which_window_::AVL_TREE;
    }
}

void Control::Nums_Control::NUM4() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::type_ = MAIN_WINDOW::which_window_::AVL_TREE;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::type_ = MAIN_WINDOW::which_window_::SPLAY_TREE;
    }
}
