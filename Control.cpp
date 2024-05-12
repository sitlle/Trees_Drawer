#include"Main_Window.h"
#include "Control.h"
#include"Trees_Building.h"

// KEYBOARD

void Control::KeyBoard_Control::MOVE_UP() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_y += 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_y += 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        MAIN_WINDOW::PRINT_SPLAY_OPTIONS.cnt_y += 75;
    }
}

void Control::KeyBoard_Control::MOVE_DOWN() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_y -= 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_y -= 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        MAIN_WINDOW::PRINT_SPLAY_OPTIONS.cnt_y -= 75;
    }
}

void Control::KeyBoard_Control::MOVE_LEFT() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_x += 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_x += 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        MAIN_WINDOW::PRINT_SPLAY_OPTIONS.cnt_x += 75;
    }
}

void Control::KeyBoard_Control::MOVE_RIGHT() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.cnt_x -= 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.cnt_x -= 75;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        MAIN_WINDOW::PRINT_SPLAY_OPTIONS.cnt_x -= 75;
    }
}

void Control::KeyBoard_Control::DELETE() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        auto res = FIND_BLUE_VERTEX::Get_All_Blue(MAIN_WINDOW::DD_DRAW_TREE_);
        for (auto &NODE : res) {
            MAIN_WINDOW::DD_TREE_.Remove(NODE->val);
            MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                                                 MAIN_WINDOW::DD_OPTIONS_);
        }
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        auto res = FIND_BLUE_VERTEX::Get_All_Blue(MAIN_WINDOW::AVL_DRAW_TREE_);
        for (auto &NODE : res) {
            MAIN_WINDOW::AVL_TREE_.Remove(NODE->val);
            MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                                 MAIN_WINDOW::AVL_OPTIONS_);
        }
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        auto res = FIND_BLUE_VERTEX::Get_All_Blue(MAIN_WINDOW::SPLAY_DRAW_TREE_);
        for (auto &NODE : res) {
            MAIN_WINDOW::SPLAY_TREE_.Remove(NODE->val);
            MAIN_WINDOW::SPLAY_DRAW_TREE_ = Trees_Building::Build_Tree<Node_SPLAY, SPLAY>
                    (MAIN_WINDOW::SPLAY_TREE_, MAIN_WINDOW::SPLAY_OPTIONS);
        }
    }
}

void Control::KeyBoard_Control::CLICK_I() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        Info_Tree_Window extra_window;
        extra_window.Process<DD>(MAIN_WINDOW::DD_TREE_, 1);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        Info_Tree_Window extra_window;
        extra_window.Process<AVL>(MAIN_WINDOW::AVL_TREE_, 2);
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        Info_Tree_Window extra_window;
        extra_window.Process<SPLAY>(MAIN_WINDOW::SPLAY_TREE_, 3);
    }
}

// MOUSE

void Control::Mouse_Control::MOVE_UP() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom -= 0.03f;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.zoom -= 0.03f;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        MAIN_WINDOW::PRINT_SPLAY_OPTIONS.zoom -= 0.03f;
    }
}

void Control::Mouse_Control::MOVE_DOWN() noexcept {
    if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::DD_TREE) {
        MAIN_WINDOW::PRINT_DD_OPTIONS_.zoom += 0.03f;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::AVL_TREE) {
        MAIN_WINDOW::PRINT_AVL_OPTIONS.zoom += 0.03f;
    } else if (MAIN_WINDOW::type_ == MAIN_WINDOW::which_window_::SPLAY_TREE) {
        MAIN_WINDOW::PRINT_SPLAY_OPTIONS.zoom += 0.03f;
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
        MAIN_WINDOW::SPLAY_OPTIONS.TREE_W -= 0.03f;
        MAIN_WINDOW::SPLAY_OPTIONS.TREE_W = std::max(1.f, MAIN_WINDOW::SPLAY_OPTIONS.TREE_W);
        MAIN_WINDOW::SPLAY_DRAW_TREE_ = Trees_Building::Build_Tree<Node_SPLAY, SPLAY>
                (MAIN_WINDOW::SPLAY_TREE_, MAIN_WINDOW::SPLAY_OPTIONS);
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
        MAIN_WINDOW::SPLAY_OPTIONS.TREE_W += 0.03f;
        MAIN_WINDOW::SPLAY_DRAW_TREE_ = Trees_Building::Build_Tree<Node_SPLAY, SPLAY>
                (MAIN_WINDOW::SPLAY_TREE_, MAIN_WINDOW::SPLAY_OPTIONS);
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
        MAIN_WINDOW::SPLAY_OPTIONS.TREE_H += 0.03f;
        MAIN_WINDOW::SPLAY_OPTIONS.TREE_H = std::max(1.f, MAIN_WINDOW::SPLAY_OPTIONS.TREE_H);
        MAIN_WINDOW::SPLAY_DRAW_TREE_ = Trees_Building::Build_Tree<Node_SPLAY, SPLAY>
                (MAIN_WINDOW::SPLAY_TREE_, MAIN_WINDOW::SPLAY_OPTIONS);
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
        MAIN_WINDOW::SPLAY_OPTIONS.TREE_H -= 0.03f;
        MAIN_WINDOW::SPLAY_OPTIONS.TREE_H = std::max(1.f, MAIN_WINDOW::SPLAY_OPTIONS.TREE_H);
        MAIN_WINDOW::SPLAY_DRAW_TREE_ = Trees_Building::Build_Tree<Node_SPLAY, SPLAY>
                (MAIN_WINDOW::SPLAY_TREE_, MAIN_WINDOW::SPLAY_OPTIONS);
    }
}

// NUMS

void Control::Nums_Control::NUM1() noexcept {
    First_Extra_Window Extra_Window;
    std::string res = Extra_Window.Process();
    if (!res.empty()) {
        int64_t add_num = stoi(res);
        // add DD
        MAIN_WINDOW::DD_TREE_.Add(add_num);
        MAIN_WINDOW::AVL_TREE_.Add(add_num);
        MAIN_WINDOW::SPLAY_TREE_.Add(add_num);
        // re-build DD
        MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                             MAIN_WINDOW::DD_OPTIONS_);
        // add AVL
        MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                MAIN_WINDOW::AVL_OPTIONS_);
        // add SPLAY
        MAIN_WINDOW::SPLAY_DRAW_TREE_ = Trees_Building::Build_Tree<Node_SPLAY, SPLAY>
                (MAIN_WINDOW::SPLAY_TREE_, MAIN_WINDOW::SPLAY_OPTIONS);
    }
}

void Control::Nums_Control::NUM2() noexcept {
    First_Extra_Window Extra_Window;
    std::string res = Extra_Window.Process();
    if (!res.empty()) {
        int32_t counter = stoi(res);
        // add DD
        std::vector<int> rnd_nums;
        for (int i = 0; i < counter; ++i) {
            int add_num = get_random() % 100;
            MAIN_WINDOW::DD_TREE_.Add(add_num);
            MAIN_WINDOW::AVL_TREE_.Add(add_num);
            MAIN_WINDOW::SPLAY_TREE_.Add(add_num);
        }
        // re-build DD
        MAIN_WINDOW::DD_DRAW_TREE_ = Trees_Building::Build_Tree<Node_DD, DD>(MAIN_WINDOW::DD_TREE_,
                                                             MAIN_WINDOW::DD_OPTIONS_);
        // add AVL
        MAIN_WINDOW::AVL_DRAW_TREE_ = Trees_Building::Build_Tree<Node_AVL, AVL>(MAIN_WINDOW::AVL_TREE_,
                                                                MAIN_WINDOW::AVL_OPTIONS_);
        // add SPLAY
        MAIN_WINDOW::SPLAY_DRAW_TREE_ = Trees_Building::Build_Tree<Node_SPLAY, SPLAY>
                (MAIN_WINDOW::SPLAY_TREE_, MAIN_WINDOW::SPLAY_OPTIONS);
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
