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

private:

    bool Find(Node_RB* vertex, int64_t val) {
        if (vertex == nullptr) {
            return false;
        }
        if (vertex->val == val) {
            return true;
        }
        return (Find(vertex->left, val) | Find(vertex->right, val));
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

    void Remove(Node_RB* x) {
        Node_RB* s;
        while (x != nullptr && x != root && x->param.COLOR == sf::Color::Black) {
            if (x == x->prev->left) {
                if (x->prev != nullptr) {
                    s = x->prev->right;
                } else {
                    s = nullptr;
                }
                if (s != nullptr) {
                    if (x != nullptr && s->param.COLOR == sf::Color::Red) {
                        // case 3.1
                        s->param.COLOR = sf::Color::Black;
                        x->prev->param.COLOR = sf::Color::Red;
                        leftRotate(x->prev);
                        s = x->prev->right;
                    }
                    if (x != nullptr && s != nullptr && s->left != nullptr &&
                    s->left->param.COLOR == sf::Color::Black &&
                        s->right->param.COLOR == sf::Color::Black) {
                        // case 3.2
                        s->param.COLOR = sf::Color::Red;
                        x = x->prev;
                    } else {
                        if (s != nullptr && s->right != nullptr &&
                        s->right->param.COLOR == sf::Color::Black) {
                            // case 3.3
                            if (s->left != nullptr) {
                                s->left->param.COLOR = sf::Color::Black;
                            }
                            s->param.COLOR = sf::Color::Red;
                            rightRotate(s);
                            s = x->prev->right;
                        }
                        // case 3.4
                        if (x != nullptr && s != nullptr) {
                            s->param.COLOR = x->prev->param.COLOR;
                        }
                        if (x != nullptr && x->prev != nullptr) {
                            x->prev->param.COLOR = sf::Color::Black;
                        }
                        if (s != nullptr && s->right != nullptr) {
                            s->right->param.COLOR = sf::Color::Black;
                        }
                        if (x != nullptr) {
                            leftRotate(x->prev);
                        }
                        x = root;
                    }
                }
            } else {
                if (x->prev != nullptr) {
                    s = x->prev->left;
                } else {
                    s = nullptr;
                }
                if (s != nullptr) {
                    if (s->param.COLOR == sf::Color::Red) {
                        // case 3.1
                        s->param.COLOR = sf::Color::Black;
                        if (x->prev != nullptr) {
                            x->prev->param.COLOR = sf::Color::Red;
                        }
                        if (x != nullptr) {
                            rightRotate(x->prev);
                        }
                        if (x != nullptr) {
                            s = x->prev->left;
                        }
                    }
                    if (x != nullptr && s != nullptr && s->right != nullptr &&
                    s->right->param.COLOR == sf::Color::Black &&
                        s->right->param.COLOR == sf::Color::Black) {
                        // case 3.2
                        s->param.COLOR = sf::Color::Red;
                        x = x->prev;
                    } else {
                        if (x != nullptr && s != nullptr && s->left != nullptr &&
                        s->left->param.COLOR == sf::Color::Black) {
                            // case 3.3
                            if (s->right != nullptr) {
                                s->right->param.COLOR = sf::Color::Black;
                            }
                            s->param.COLOR = sf::Color::Red;
                            leftRotate(s);
                            s = x->prev->left;
                        }
                        // case 3.4
                        if (s != nullptr) {
                            s->param.COLOR = x->prev->param.COLOR;
                        }
                        if (x != nullptr && x->prev != nullptr) {
                            x->prev->param.COLOR = sf::Color::Black;
                        }
                        if (s != nullptr && s->left != nullptr) {
                            s->left->param.COLOR = sf::Color::Black;
                        }
                        if (x != nullptr) {
                            rightRotate(x->prev);
                        }
                        x = root;
                    }
                }
            }
        }
        if (x != nullptr) {
            x->param.COLOR = sf::Color::Black;
        }
    }


    void rbTransplant(Node_RB* first, Node_RB* second){
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

    void Remove(Node_RB* vertex, int val) {
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
            rbTransplant(first, first->right);
        } else if (first->right == nullptr) {
            second = first->left;
            rbTransplant(first, first->left);
        } else {
            third = minimum(first->right);
            third_original_color = third->param.COLOR;
            second = third->right;
            if (third->prev == first) {
                if (second != nullptr) {
                    second->prev = third;
                }
            } else {
                rbTransplant(third, third->right);
                third->right = first->right;
                third->right->prev = third;
            }

            rbTransplant(first, third);
            third->left = first->left;
            third->left->prev = third;
            third->param.COLOR = first->param.COLOR;
        }
        delete first;
        if (third_original_color == sf::Color::Black){
            Remove(second);
        }
    }

    static Node_RB* minimum(Node_RB* vertex) {
        while (vertex->left != nullptr) {
            vertex = vertex->left;
        }
        return vertex;
    }

    static Node_RB* maximum(Node_RB* vertex) {
        while (vertex->right != nullptr) {
            vertex = vertex->right;
        }
        return vertex;
    }
};
