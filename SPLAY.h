#pragma once
#include<bits/stdc++.h>
#include"Node_SPLAY.h"
#include"Random.h"

class SPLAY {
public:
    Node_SPLAY* root;
    SPLAY() {
        root = nullptr;
    }

    ~SPLAY() {
        clear(root);
    }

    void Add_Rnd(int32_t x) {
        for (int i = 0; i < x; ++i) {
            int64_t num = get_random() % 100;
            Add(num);
        }
    }

    void Add(int64_t val) {
        if (Find(val)) {
            return;
        }
        auto* add_vertex = new Node_SPLAY(val);
        if (root == nullptr) {
            root = add_vertex;
            return;
        }
        Add(root, add_vertex);
    }

    void Remove(int64_t val) {
        if (!Find(val)) {
            return;
        }
        root = splay(root, val);
        auto root_copy = root;
        delete root;
        root = Merge(root_copy->left, root_copy->right);
    }

    bool Find(int64_t val) {
        return Find(root, val);
    }


private:

    bool Find(Node_SPLAY* vertex, int64_t val) {
        if (vertex == nullptr) {
            return false;
        }
        if (vertex->val == val) {
            return true;
        }
        return (Find(vertex->left, val) | Find(vertex->right, val));
    }

    void clear(Node_SPLAY* vertex) {
        if (vertex == nullptr) {
            return;
        }
        clear(vertex->left);
        clear(vertex->right);
        delete vertex;
    }

    Node_SPLAY* LeftRotate(Node_SPLAY* vertex) {
        Node_SPLAY* e = vertex->right;
        vertex->right = e->left;
        e->left = vertex;
        return e;
    }

    Node_SPLAY* RightRotate(Node_SPLAY* vertex) {
        Node_SPLAY* e = vertex->left;
        vertex->left = e->right;
        e->right = vertex;
        return e;
    }

    Node_SPLAY* splay(Node_SPLAY* vertex, int64_t val) {
        if (vertex == nullptr || vertex->val == val) {
            return vertex;
        }
        if (vertex->val > val) {
            if (vertex->left == nullptr) {
                return vertex;
            }
            if (vertex->left->val > val) { // zig-zig
                vertex->left->left = splay(vertex->left->left, val);
                vertex = RightRotate(vertex);
            } else if (vertex->left->val < val) { // zig-zag
                vertex->left->right = splay(vertex->left->right, val);
                if (vertex->left->right != nullptr) {
                    vertex->left = LeftRotate(vertex->left);
                }
            }
            // zag
            if (vertex->left == nullptr) {
                return vertex;
            }
            return RightRotate(vertex);
        } else {
            if (vertex->right == nullptr) {
                return vertex;
            }
            if (vertex->right->val > val) { // zig-zag
                vertex->right->left = splay(vertex->right->left, val);
                if (vertex->right->left != nullptr) {
                    vertex->right = RightRotate(vertex->right);
                }
            } else if (vertex->right->val < val) { // zag-zag
                vertex->right->right = splay(vertex->right->right, val);
                vertex = LeftRotate(vertex);
            }
            // zag
            if (vertex->right == nullptr) {
                return vertex;
            }
            return LeftRotate(vertex);
        }
    }

    void Add(Node_SPLAY* vertex, Node_SPLAY* add_vertex) {
        if (vertex->val > add_vertex->val) {
            if (vertex->left == nullptr) {
                vertex->left = add_vertex;
                root = splay(root, add_vertex->val);
            } else {
                Add(vertex->left, add_vertex);
            }
        } else {
            if (vertex->right == nullptr) {
                vertex->right = add_vertex;
                root = splay(root, add_vertex->val);
            } else {
                Add(vertex->right, add_vertex);
            }
        }
    }

    int64_t GetMax(Node_SPLAY* vertex) { // not empty tree
        if (vertex->right == nullptr) {
            return vertex->val;
        }
        return GetMax(vertex->right);
    }

    Node_SPLAY* Merge(Node_SPLAY* First_Tree, Node_SPLAY* Second_Tree) {
        // First tree < Second tree
        if (First_Tree == nullptr) {
            return Second_Tree;
        }
        int64_t first_max = GetMax(First_Tree);
        First_Tree = splay(First_Tree, first_max);
        First_Tree->right = Second_Tree;
        return First_Tree;
    }
};