#include<bits/stdc++.h>
#include"Node_DD.h"
#include"Random.h"
#pragma once
class DD {
public:
    Node_DD* root;

    explicit DD() {
        root = nullptr;
    }

    DD(DD const &other) {
        root = other.root;
    }

    ~DD() {
        clear(root);
    }

    bool Find(int64_t val) {
        return Find(root, val);
    }

    void Add(int64_t val) {
        if (Find(val)) {
            return;
        }
        auto* vertex = new Node_DD(val);
        auto[T_First, T_Second] = Split(root, vertex->val);
        T_First = Merge(T_First, vertex);
        root = Merge(T_First, T_Second);
    }

    void Add_Rnd(int32_t x) {
        for (int i = 0; i < x; ++i) {
            int rnd_num = static_cast<int>(get_random() % 100); // rand nums
            Add(rnd_num);
        }
    }

    void Remove(int64_t x) {
        if (Find(x)) {
            root = Remove(root, x);
        }
    }

    void Print() {
        Print(root);
    }

private:

    void clear(Node_DD* vertex) noexcept {
        if (vertex == nullptr) {
            return;
        }
        clear(vertex->left);
        clear(vertex->right);
        vertex = nullptr;
        delete vertex;
    }

    Node_DD* Remove(Node_DD* vertex, int64_t key) noexcept {
        if (vertex == nullptr) {
            return nullptr;
        }
        if (vertex->val == key) {
            return Merge(vertex->left, vertex->right);
        } else {
            if (key <= vertex->val) {
                vertex->left = Remove(vertex->left, key);
            } else {
                vertex->right = Remove(vertex->right, key);
            }
            return vertex;
        }
    }

    void Print(Node_DD* vertex) noexcept {
        if (vertex == nullptr) {
            return;
        }
        Print(vertex->left);
        std::cout << vertex->val << ' ';
        Print(vertex->right);
    }

    bool Find(Node_DD* vertex, int64_t key) noexcept {
        if (vertex == nullptr) {
            return false;
        }
        if (vertex->val == key) {
            return true;
        }
        if (key < vertex->val) {
            return Find(vertex->left, key);
        } else {
            return Find(vertex->right, key);
        }
    }

    Node_DD* Merge(Node_DD* T_First, Node_DD* T_Second) noexcept {
        if (T_First == nullptr) {
            return T_Second;
        }
        if (T_Second == nullptr) {
            return T_First;
        }
        if (T_First->priority > T_Second->priority) {
            T_First->right = Merge(T_First->right, T_Second);
            return T_First;
        } else {
            T_Second->left = Merge(T_First, T_Second->left);
            return T_Second;
        }
    }

    std::pair<Node_DD*, Node_DD*> Split(Node_DD* T, int64_t key) noexcept {
        if (T == nullptr) {
            return {nullptr, nullptr};
        }
        if (key <= T->val) {
            auto[T_First, T_Second] = Split(T->left, key);
            T->left = T_Second;
            return {T_First, T};
        } else {
            auto[T_First, T_Second] = Split(T->right, key);
            T->right = T_First;
            return {T, T_Second};
        }
    }
};