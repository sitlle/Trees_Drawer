#pragma once
#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include"Node_RB.h"

class RB {
public:
    Node_RB* root;
    RB() = default;
    ~RB() = default;

    void Add(int64_t val) {
        if (Find(val)) {
            return;
        }
        auto* node = new Node_RB;
        node->prev = nullptr;
        node->val = val;
        node->left = nullptr;
        node->right = nullptr;
        node->param.COLOR = sf::Color::Red;

        Node_RB* vertex = root;
        Node_RB* extra_vertex = nullptr;

        while (vertex != nullptr) {
            extra_vertex = vertex;
            if (node->val < vertex->val) {
                vertex = vertex->left;
            } else {
                vertex = vertex->right;
            }
        }

        node->prev = extra_vertex;
        if (extra_vertex == nullptr) {
            root = node;
        } else if (node->val < extra_vertex->val) {
            extra_vertex->left = node;
        } else {
            extra_vertex->right = node;
        }

        if (node->prev == nullptr) {
            node->param.COLOR = sf::Color::Black;
            return;
        }

        if (node->prev->prev == nullptr) {
            return;
        }

        Add(node);
    }

    bool Find(int64_t val) {
        return Find(root, val);
    }

    void Remove(int64_t val) {
        if (!Find(val)) {
            return;
        }
        Remove(root, val);
    }

    static Node_RB* get_min(Node_RB* vertex) {
        while (vertex->left != nullptr) {
            vertex = vertex->left;
        }
        return vertex;
    }

private:

    bool Find(Node_RB* vertex, int64_t val) {
        if (vertex == nullptr) {
            return false;
        }
        if (vertex->val == val) {
            return true;
        }
        if (vertex->val < val) {
            return Find(vertex->right, val);
        }
        return Find(vertex->left, val);
    }

    void Add(Node_RB* vertex){
        Node_RB* extra_vertex;
        while (vertex->prev != nullptr && vertex->prev->prev != nullptr &&
        vertex->prev->param.COLOR == sf::Color::Red) {
            if (vertex->prev == vertex->prev->prev->right) {
                extra_vertex = vertex->prev->prev->left;
                if (extra_vertex != nullptr && extra_vertex->param.COLOR == sf::Color::Red) {
                    extra_vertex->param.COLOR = sf::Color::Black;
                    vertex->prev->param.COLOR = sf::Color::Black;
                    vertex->prev->prev->param.COLOR = sf::Color::Red;
                    vertex = vertex->prev->prev;
                } else {
                    if (vertex == vertex->prev->left) {
                        vertex = vertex->prev;
                        rightRotate(vertex);
                    }
                    vertex->prev->param.COLOR = sf::Color::Black;
                    vertex->prev->prev->param.COLOR = sf::Color::Red;
                    leftRotate(vertex->prev->prev);
                }
            } else {
                extra_vertex = vertex->prev->prev->right;
                if (extra_vertex != nullptr && extra_vertex->param.COLOR == sf::Color::Red) {
                    extra_vertex->param.COLOR = sf::Color::Black;
                    vertex->prev->param.COLOR = sf::Color::Black;
                    vertex->prev->prev->param.COLOR = sf::Color::Red;
                    vertex = vertex->prev->prev;
                } else {
                    if (vertex == vertex->prev->right) {
                        vertex = vertex->prev;
                        leftRotate(vertex);
                    }
                    vertex->prev->param.COLOR = sf::Color::Black;
                    vertex->prev->prev->param.COLOR = sf::Color::Red;
                    rightRotate(vertex->prev->prev);
                }
            }
            if (vertex == root) {
                break;
            }
        }
        if (root != nullptr) {
            root->param.COLOR = sf::Color::Black;
        }
    }

    void leftRotate(Node_RB* vertex) {
        Node_RB* extra_vertex = vertex->right;
        if (extra_vertex != nullptr) {
            vertex->right = extra_vertex->left;
        }
        if (extra_vertex != nullptr && extra_vertex->left != nullptr) {
            extra_vertex->left->prev = vertex;
        }
        if (extra_vertex != nullptr) {
            extra_vertex->prev = vertex->prev;
        }
        if (vertex->prev == nullptr) {
            root = extra_vertex;
        } else if (vertex == vertex->prev->left) {
            vertex->prev->left = extra_vertex;
        } else {
            vertex->prev->right = extra_vertex;
        }
        if (extra_vertex != nullptr) {
            extra_vertex->left = vertex;
        }
        vertex->prev = extra_vertex;
    }

    void rightRotate(Node_RB* vertex) {
        auto extra_vertex = vertex->left;
        if (extra_vertex != nullptr) {
            vertex->left = extra_vertex->right;
        }
        if (extra_vertex != nullptr && extra_vertex->right != nullptr) {
            extra_vertex->right->prev = vertex;
        }
        if (extra_vertex != nullptr) {
            extra_vertex->prev = vertex->prev;
        }
        if (vertex->prev == nullptr) {
            this->root = extra_vertex;
        } else if (vertex == vertex->prev->right) {
            vertex->prev->right = extra_vertex;
        } else {
            vertex->prev->left = extra_vertex;
        }
        if (extra_vertex != nullptr) {
            extra_vertex->right = vertex;
        }
        vertex->prev = extra_vertex;
    }

    void Remove(Node_RB* vertex) {
        Node_RB* extra_vertex;
        while (vertex != nullptr && vertex != root &&
        vertex->param.COLOR != sf::Color::Red) {
            if (vertex == vertex->prev->left) {
                if (vertex->prev != nullptr) {
                    extra_vertex = vertex->prev->right;
                } else {
                    extra_vertex = nullptr;
                }
                if (extra_vertex != nullptr) {
                    if (vertex != nullptr && extra_vertex->param.COLOR == sf::Color::Red) {
                        extra_vertex->param.COLOR = sf::Color::Black;
                        vertex->prev->param.COLOR = sf::Color::Red;
                        leftRotate(vertex->prev);
                        extra_vertex = vertex->prev->right;
                    }
                    if (vertex != nullptr && extra_vertex != nullptr && extra_vertex->left != nullptr &&
                        extra_vertex->left->param.COLOR == sf::Color::Black &&
                        extra_vertex->right->param.COLOR == sf::Color::Black) {
                        extra_vertex->param.COLOR = sf::Color::Red;
                        vertex = vertex->prev;
                    } else {
                        if (extra_vertex != nullptr && extra_vertex->right != nullptr &&
                            extra_vertex->right->param.COLOR == sf::Color::Black) {
                            if (extra_vertex->left != nullptr) {
                                extra_vertex->left->param.COLOR = sf::Color::Black;
                            }
                            extra_vertex->param.COLOR = sf::Color::Red;
                            rightRotate(extra_vertex);
                            extra_vertex = vertex->prev->right;
                        }
                        if (vertex != nullptr && extra_vertex != nullptr) {
                            extra_vertex->param.COLOR = vertex->prev->param.COLOR;
                        }
                        if (vertex != nullptr && vertex->prev != nullptr) {
                            vertex->prev->param.COLOR = sf::Color::Black;
                        }
                        if (extra_vertex != nullptr && extra_vertex->right != nullptr) {
                            extra_vertex->right->param.COLOR = sf::Color::Black;
                        }
                        if (vertex != nullptr) {
                            leftRotate(vertex->prev);
                        }
                        vertex = root;
                    }
                }
            } else {
                if (vertex->prev != nullptr) {
                    extra_vertex = vertex->prev->left;
                } else {
                    extra_vertex = nullptr;
                }
                if (extra_vertex != nullptr) {
                    if (extra_vertex->param.COLOR == sf::Color::Red) {
                        extra_vertex->param.COLOR = sf::Color::Black;
                        if (vertex->prev != nullptr) {
                            vertex->prev->param.COLOR = sf::Color::Red;
                        }
                        if (vertex != nullptr) {
                            rightRotate(vertex->prev);
                        }
                        if (vertex != nullptr) {
                            extra_vertex = vertex->prev->left;
                        }
                    }
                    if (vertex != nullptr && extra_vertex != nullptr && extra_vertex->right != nullptr &&
                        extra_vertex->right->param.COLOR == sf::Color::Black &&
                        extra_vertex->right->param.COLOR == sf::Color::Black) {
                        extra_vertex->param.COLOR = sf::Color::Red;
                        vertex = vertex->prev;
                    } else {
                        if (vertex != nullptr && extra_vertex != nullptr && extra_vertex->left != nullptr &&
                            extra_vertex->left->param.COLOR == sf::Color::Black) {
                            if (extra_vertex->right != nullptr) {
                                extra_vertex->right->param.COLOR = sf::Color::Black;
                            }
                            extra_vertex->param.COLOR = sf::Color::Red;
                            leftRotate(extra_vertex);
                            extra_vertex = vertex->prev->left;
                        }
                        if (extra_vertex != nullptr) {
                            extra_vertex->param.COLOR = vertex->prev->param.COLOR;
                        }
                        if (vertex != nullptr && vertex->prev != nullptr) {
                            vertex->prev->param.COLOR = sf::Color::Black;
                        }
                        if (extra_vertex != nullptr && extra_vertex->left != nullptr) {
                            extra_vertex->left->param.COLOR = sf::Color::Black;
                        }
                        if (vertex != nullptr) {
                            rightRotate(vertex->prev);
                        }
                        vertex = root;
                    }
                }
            }
        }
        if (vertex != nullptr) {
            vertex->param.COLOR = sf::Color::Black;
        }
    }


    void TR(Node_RB* first, Node_RB* second){
        if (first->prev == nullptr) {
            root = second;
        } else if (first == first->prev->left){
            first->prev->left = second;
        } else {
            first->prev->right = second;
        }
        if (second != nullptr) {
            second->prev = first->prev;
        }
    }

    void Remove(Node_RB* vertex, int64_t val) {
        Node_RB* first = nullptr;
        Node_RB* second = nullptr;
        Node_RB* third = nullptr;
        while (vertex != nullptr){
            if (vertex->val == val) {
                first = vertex;
            }
            if (vertex->val <= val) {
                vertex = vertex->right;
            } else {
                vertex = vertex->left;
            }
        }

        if (first == nullptr) {
            return;
        }

        third = first;
        sf::Color third_original_color = third->param.COLOR;
        if (first->left == nullptr) {
            second = first->right;
            TR(first, first->right);
        } else if (first->right == nullptr) {
            second = first->left;
            TR(first, first->left);
        } else {
            third = get_min(first->right);
            third_original_color = third->param.COLOR;
            second = third->right;
            if (third->prev == first) {
                if (second != nullptr) {
                    second->prev = third;
                }
            } else {
                TR(third, third->right);
                third->right = first->right;
                third->right->prev = third;
            }

            TR(first, third);
            third->left = first->left;
            third->left->prev = third;
            third->param.COLOR = first->param.COLOR;
        }
        delete first;
        if (third_original_color == sf::Color::Black){
            Remove(second);
        }
    }
};
