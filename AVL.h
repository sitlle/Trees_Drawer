#include<bits/stdc++.h>
#include"Random.h"
#include"Node_AVL.h"
#pragma once
class AVL {
public:
    Node_AVL* root;
    AVL() {
        root = nullptr;
    }

    ~AVL() = default;

    AVL(AVL const& other) {
        root = other.root;
    }

    void Add_Rnd(int32_t counter) {
        for (int32_t i = 0; i < counter; ++i) {
            int64_t num = get_random() % 100;
            Add(num);
        }
    }

    void Add(int64_t val) {
        if (Find(val)) {
            return;
        }
        if (root == nullptr) {
            root = new Node_AVL(val);
            return;
        }
        root = Global_Balanced(root, val);
    }

    void Remove(int64_t val) {
        if (!Find(val)) {
            return;
        }
        root = Remove(root, val);
    }

    bool Find(int64_t val) {
        return Find(root, val);
    }

    void Print() {
        Print(root);
    }

private:
    void clear(Node_AVL* vertex) {
        if (vertex == nullptr) {
            return;
        }
        clear(vertex->left);
        clear(vertex->right);
        delete vertex;
    }

    void Print(Node_AVL* vertex) {
        if (vertex == nullptr) {
            return;
        }
        Print(vertex->left);
        std::cout << vertex->val << ' ';
        Print(vertex->right);
    }

    bool Find(Node_AVL* vertex, int64_t val) {
        if (vertex == nullptr) {
            return false;
        }
        if (vertex->val == val) {
            return true;
        }
        if (val < vertex->val) {
            return Find(vertex->left, val);
        } else {
            return Find(vertex->right, val);
        }
    }

    Node_AVL* getMin(Node_AVL* vertex) {
        if (vertex == nullptr) {
            return nullptr;
        }
        if (vertex->left == nullptr) {
            return vertex;
        }
        return getMin(vertex->left);
    }

    Node_AVL* RemoveMin(Node_AVL* vertex) {
        if (vertex == nullptr) {
            return nullptr;
        }
        if (vertex->left == nullptr) {
            return vertex->right;
        }
        vertex->left = RemoveMin(vertex->left);
        return Local_Balanced(vertex);
    }

    Node_AVL* Remove(Node_AVL* vertex, int64_t val) {
        if (vertex == nullptr) {
            return nullptr;
        }
        if (vertex->val == val) {
            auto mn = getMin(vertex->right);
            if (mn == nullptr) {
                auto e = vertex->left;
                delete vertex;
                return Local_Balanced(e);
            }
            vertex->right = RemoveMin(vertex->right);
            mn->right = vertex->right;
            mn->left = vertex->left;
            return Local_Balanced(mn);
        } else if (vertex->val > val) {
            vertex->left = Remove(vertex->left, val);
        } else if (vertex->val < val) {
            vertex->right = Remove(vertex->right, val);
        }
        return Local_Balanced(vertex);
    }

    int32_t get_height(const Node_AVL* vertex) {
        if (vertex == nullptr) {
            return 0;
        }
        return vertex->height;
    }

    int32_t get_balance(const Node_AVL* vertex) {
        if (vertex == nullptr) {
            return 0;
        }
        return get_height(vertex->right) - get_height(vertex->left);
    }

    void Update(Node_AVL* vertex) {
        if (vertex == nullptr) {
            return;
        }
        vertex->height = std::max(get_height(vertex->left),
                                  get_height(vertex->right)) + 1;
        vertex->balance = get_balance(vertex);
    }

    Node_AVL* L_Rotate(Node_AVL* vertex) {
        Node_AVL* right_child = vertex->right;
        vertex->right = right_child->left;
        right_child->left = vertex;
        Update(vertex);
        Update(right_child);
        return right_child;
    }

    Node_AVL* R_Rotate(Node_AVL* vertex) {
        Node_AVL* left_child = vertex->left;
        vertex->left = left_child->right;
        left_child->right = vertex;
        Update(vertex);
        Update(left_child);
        return left_child;
    }

    Node_AVL* Local_Balanced(Node_AVL* vertex) {
        Update(vertex);
        if (get_balance(vertex) == 2) {
            if (get_balance(vertex->right) < 0) {
                vertex->right = R_Rotate(vertex->right);
            }
            return L_Rotate(vertex);
        }
        if (get_balance(vertex) == -2) {
            if (get_balance(vertex->left) > 0) {
                vertex->left = L_Rotate(vertex->left);
            }
            return R_Rotate(vertex);
        }
        return vertex;
    }

    Node_AVL* Global_Balanced(Node_AVL* vertex, int64_t& val) {
        if (val <= vertex->val) {
            if (vertex->left != nullptr) {
                vertex->left = Global_Balanced(vertex->left, val);
            } else {
                auto new_node = new Node_AVL(val, 0);
                vertex->left = new_node;
                Update(vertex);
                return vertex;
            }
        } else {
            if (vertex->right != nullptr) {
                vertex->right = Global_Balanced(vertex->right, val);
            } else {
                auto new_node = new Node_AVL(val, 0);
                vertex->right = new_node;
                Update(vertex);
                return vertex;
            }
        }
        return Local_Balanced(vertex);
    }
};