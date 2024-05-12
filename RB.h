#pragma once
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include"Node_RB.h"

class RB {
public:
    Node_RB* root;
    RB() = default;
    ~RB() = default;

    void Add(int64_t key) {
        Node_RB* node = new Node_RB;
        node->prev = nullptr;
        node->val = key;
        node->left = nullptr;
        node->right = nullptr;
        node->color = sf::Color::Red;

        Node_RB* y = nullptr;
        Node_RB* x = root;

        while (x != nullptr) {
            y = x;
            if (node->val < x->val) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        // y is parent of x
        node->prev = y;
        if (y == nullptr) {
            root = node;
        } else if (node->val < y->val) {
            y->left = node;
        } else {
            y->right = node;
        }

        // if new node is a root node, simply return
        if (node->prev == nullptr){
            node->color = sf::Color::Black;
            return;
        }

        // if the grandparent is null, simply return
        if (node->prev->prev == nullptr) {
            return;
        }

        // Fix the tree
        fixInsert(node);
    }

private:

    void fixInsert(Node_RB* k){
        Node_RB* u;
        while (k->prev->color == sf::Color::Red) {
            if (k->prev == k->prev->prev->right) {
                u = k->prev->prev->left; // uncle
                if (u->color == sf::Color::Red) {
                    // case 3.1
                    u->color = sf::Color::Black;
                    k->prev->color = sf::Color::Black;
                    k->prev->prev->color = sf::Color::Red;
                    k = k->prev->prev;
                } else {
                    if (k == k->prev->left) {
                        // case 3.2.2
                        k = k->prev;
                        rightRotate(k);
                    }
                    // case 3.2.1
                    k->prev->color = sf::Color::Black;
                    k->prev->prev->color = sf::Color::Red;
                    leftRotate(k->prev->prev);
                }
            } else {
                u = k->prev->prev->right; // uncle

                if (u->color == sf::Color::Red) {
                    // mirror case 3.1
                    u->color = sf::Color::Black;
                    k->prev->color = sf::Color::Black;
                    k->prev->prev->color = sf::Color::Red;
                    k = k->prev->prev;
                } else {
                    if (k == k->prev->right) {
                        // mirror case 3.2.2
                        k = k->prev;
                        leftRotate(k);
                    }
                    // mirror case 3.2.1
                    k->prev->color = sf::Color::Black;
                    k->prev->prev->color = sf::Color::Red;
                    rightRotate(k->prev->prev);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = sf::Color::Black;
    }

    void leftRotate(Node_RB* x) {
        Node_RB* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->prev = x;
        }
        y->prev = x->prev;
        if (x->prev == nullptr) {
            this->root = y;
        } else if (x == x->prev->left) {
            x->prev->left = y;
        } else {
            x->prev->right = y;
        }
        y->left = x;
        x->prev = y;
    }

    void rightRotate(Node_RB* x) {
        Node_RB* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->prev = x;
        }
        y->prev = x->prev;
        if (x->prev == nullptr) {
            this->root = y;
        } else if (x == x->prev->right) {
            x->prev->right = y;
        } else {
            x->prev->left = y;
        }
        y->right = x;
        x->prev = y;
    }
};
