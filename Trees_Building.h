#include"DD.h"
#include"Node_DD.h"
#include"VERTEX.h"
#include"TREE_OPTIONS.h"
#pragma once

class Trees_Building {
public:
    Trees_Building() = default;
    ~Trees_Building() = default;

    template<typename vertex_type, typename tree_type>
    static VERTEX<vertex_type>* Build_Tree(tree_type& TREE, TREE_OPTIONS& TREE_OPT) noexcept;
private:
    template<typename vertex_type>
    static int32_t ReCalcHeight(vertex_type* vertex) noexcept;

    template<typename vertex_type>
    static int32_t ReCalcSize(vertex_type* vertex) noexcept;

    template<typename vertex_type>
    static void ReCalcPosX(vertex_type* vertex, int64_t x) noexcept;

    template<typename vertex_type>
    static void ReBuildTree(vertex_type* vertex) noexcept;

    template<typename vertex_type>
    static void ReCalcRadius(VERTEX<vertex_type>* node, float& RAD) noexcept;

    template<typename vertex_type>
    static VERTEX<vertex_type>* Tree_Building_InOrder(vertex_type *vertex, VERTEX<vertex_type> *node,
                                               std::pair<float, float> last_coords, int64_t x,
                                               TREE_OPTIONS& TREE_OPT) noexcept;

    template<typename vertex_type>
    static void Update_LR(vertex_type* vertex, int SDV = 0) noexcept;

    template<typename vertex_type>
    static void Compression(vertex_type* vertex, int64_t H,
                     int64_t path_sum = 0, int LorR = -1) noexcept;

    template<typename vertex_type>
    static void LazyUpdates(vertex_type* vertex, int64_t push) noexcept;
};

template<typename vertex_type>
int32_t Trees_Building::ReCalcHeight(vertex_type* vertex) noexcept {
    if (vertex == nullptr) {
        return 0;
    }
    return (vertex->param.height = std::max(ReCalcHeight<vertex_type>(vertex->left),
                                            ReCalcHeight<vertex_type>(vertex->right)) + 1);
}

template<typename vertex_type>
int32_t Trees_Building::ReCalcSize(vertex_type* vertex) noexcept {
    if (vertex == nullptr) {
        return 0;
    }
    return (vertex->param.size = ReCalcSize(vertex->left) + ReCalcSize(vertex->right) + 1);
}

template<typename vertex_type>
void Trees_Building::ReCalcPosX(vertex_type* vertex, int64_t x) noexcept {
    if (vertex == nullptr) {
        return;
    }
    if (vertex->left != nullptr) {
        vertex->left->param.posX = vertex->param.posX - (1ll << (x - 1));
        ReCalcPosX<vertex_type>(vertex->left, x - 1);
    }
    if (vertex->right != nullptr) {
        vertex->right->param.posX = vertex->param.posX + (1ll << (x - 1));
        ReCalcPosX<vertex_type>(vertex->right, x - 1);
    }
}

template<typename vertex_type>
void Trees_Building::ReBuildTree(vertex_type* vertex) noexcept {
    if (vertex == nullptr) {
        return;
    }
    ReBuildTree<vertex_type>(vertex->left);
    ReBuildTree<vertex_type>(vertex->right);
    int64_t left = ((vertex->left == nullptr) ? vertex->param.posX : vertex->left->param.L);
    int64_t right = ((vertex->right == nullptr) ? vertex->param.posX : vertex->right->param.R);
    vertex->param.L = left;
    vertex->param.R = right;
}

template<typename vertex_type>
void Trees_Building::ReCalcRadius(VERTEX<vertex_type>* node, float& RAD) noexcept {
    if (node == nullptr) {
        return;
    }
    ReCalcRadius<vertex_type>(node->left, RAD);
    node->radius = RAD;
    ReCalcRadius<vertex_type>(node->right, RAD);
}

template<typename vertex_type>
VERTEX<vertex_type>* Trees_Building::Tree_Building_InOrder(vertex_type *vertex, VERTEX<vertex_type> *node,
                                           std::pair<float, float> last_coords, int64_t x,
                                           TREE_OPTIONS& TREE_OPT) noexcept {
    if (vertex == nullptr) {
        return nullptr;
    }
    // node copy
    node = new VERTEX<vertex_type>(vertex);
    if (last_coords.first == 1250 && last_coords.second == 0) { // root
        node->coords = {1250 + TREE_OPT.TREE_W * (vertex->param.posX + vertex->param.sdv) * 30,
                        last_coords.second + 30};
    } else {
        node->coords = {1250 + TREE_OPT.TREE_W * (vertex->param.posX + vertex->param.sdv) * 30,
                        last_coords.second + 2 * (std::max(TREE_OPT.TREE_H,
                                                           float(vertex->param.size) / 20.f)) * 30};
    }
    node->val = vertex->val;
    node->radius = 30;
    node->COLOR = vertex->param.COLOR;
    // node copy
    node->left = Tree_Building_InOrder<vertex_type>(vertex->left, node->left,
                                                    node->coords, x - 1, TREE_OPT);
    node->right = Tree_Building_InOrder<vertex_type>(vertex->right, node->right,
                                                     node->coords, x - 1, TREE_OPT);
    return node;
}

template<typename vertex_type> void Trees_Building::Update_LR
(vertex_type* vertex, int SDV) noexcept {
    if (vertex == nullptr) {
        return;
    }
    if (vertex->left != nullptr) {
        vertex->param.L = vertex->left->param.L + SDV;
    } else {
        vertex->param.L = vertex->param.posX + vertex->param.sdv;
    }
    if (vertex->right != nullptr) {
        vertex->param.R = vertex->right->param.R + SDV;
    } else {
        vertex->param.R = vertex->param.posX + vertex->param.sdv;
    }
}

template<typename vertex_type>
void Trees_Building::Compression(vertex_type* vertex, int64_t H,
                 int64_t path_sum, int LorR) noexcept {
    if (vertex == nullptr) {
        return;
    }
    Compression<vertex_type>(vertex->left, H - 1,
                             path_sum - (1ll << std::max(static_cast<int64_t>(0), (H - 1))), 0);
    Compression<vertex_type>(vertex->right, H - 1,
                             path_sum + (1ll << std::max(static_cast<int64_t>(0), (H - 1))), 1);
    vertex->param.sdv = 0;
    // update X
    Update_LR<vertex_type>(vertex);
    int64_t Max = (1ll << H) - 1 + path_sum;
    int64_t Min = -((1ll << H) - 1) + path_sum;
    if (LorR == 0) {
        auto vertex_r = vertex->param.R;
        auto rz = Max - vertex_r;
        vertex->param.sdv += rz;
    } else if (LorR == 1) {
        auto vertex_l = vertex->param.L;
        auto rz = vertex_l - Min;
        vertex->param.sdv -= rz;
    }
    Update_LR<vertex_type>(vertex, vertex->param.sdv);
}

template<typename vertex_type>
void Trees_Building::LazyUpdates(vertex_type* vertex, int64_t push) noexcept {
    if (vertex == nullptr) {
        return;
    }
    int last_sdv = vertex->param.sdv;
    vertex->param.sdv += push;
    push += last_sdv;
    LazyUpdates<vertex_type>(vertex->left, push);
    LazyUpdates<vertex_type>(vertex->right, push);
}

template<typename vertex_type, typename tree_type>
VERTEX<vertex_type>* Trees_Building::Build_Tree(tree_type& TREE, TREE_OPTIONS& TREE_OPT) noexcept {
    VERTEX<vertex_type>* root = nullptr;
    // ReCalc
    ReCalcHeight<vertex_type>(TREE.root);
    TREE.root->param.posX = 0;
    ReCalcPosX<vertex_type>(TREE.root, (TREE.root->param.height - 1));
    ReBuildTree<vertex_type>(TREE.root);
    ReCalcSize(TREE.root);
    // ReCalc
    Compression<vertex_type>(TREE.root, (TREE.root->param.height - 1));
    LazyUpdates<vertex_type>(TREE.root, 0);
    root = Tree_Building_InOrder<vertex_type>(TREE.root, root, {1250, 0},
                                              (TREE.root->param.height - 1), TREE_OPT);
    // 1250 - center of WINDOW_W
    return root;
}
