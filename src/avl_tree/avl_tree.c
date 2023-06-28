#include "avl_tree.h"

AVLTree* newAVLTree() {
    AVLTree *tree = (AVLTree *) malloc(sizeof(AVLTree));
    tree->root = NULL;
    return tree;
}

AVLNode* newAVLNode(int key) {
    AVLNode *node = (AVLNode *) malloc(sizeof(AVLNode));
    node->parent = NULL;
    node->left   = NULL;
    node->right  = NULL;
    node->key = key;
    node->height = 0;
    node->bf = 0;
    return node;
}

AVLNode* avl_tree_search(AVLNode *node, int key) {
    while (node != NULL && key != node->key) {
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    return node;
}

AVLNode* avl_tree_min(AVLNode *root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

AVLNode* avl_tree_max(AVLNode *root) {
    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

AVLNode* avl_tree_successor(AVLNode *node) {
    if (node->right != NULL) {
        return avl_tree_min(node->right);
    }

    AVLNode *aux = node->parent;

    while (aux != NULL && node == aux->right) {
        node = aux;
        aux = aux->parent;
    }

    return aux;
}

AVLNode* avl_tree_predecessor(AVLNode *node) {
    if (node->left != NULL) {
        return avl_tree_max(node->left);
    }

    AVLNode *aux = node->parent;

    while (aux != NULL && node == aux->left) {
        node = aux;
        aux = aux->parent;
    }
}


void in_order_walk(AVLNode *root) {}

void pre_order_walk(AVLNode* root) {}

void avl_tree_insert(AVLTree *tree, int key) {
    AVLNode *y = NULL;
    AVLNode *x = tree->root;
    AVLNode *z = newAVLNode(key);

    while (x != NULL) {
        y = x;

        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    z->parent = y;

    if (y == NULL) {
        tree->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    fixup(tree, z->parent);
}

void avl_tree_remove(AVLTree *tree, int key) {}

void transplant(AVLTree *tree, AVLNode *u, AVLNode *v) {}

void left_rotate(AVLTree *tree, AVLNode *node) {}

void right_rotate(AVLTree *tree, AVLNode *node) {}

void update_height_and_bf(AVLNode *node) {
    int lh = get_avlnode_height(node->left);
    int rh = get_avlnode_height(node->right);
    node->height = 1 + max(lh, rh);
    node->bf = rh - lh;
}

void balance(AVLTree *tree, AVLNode *node) {
    if (node->bf == -2) {
        if (node->left != NULL && node->left->bf > 0) {
            left_rotate(tree, node->left);
        }
        right_rotate(tree, node);
    } else if (node->bf == 2) {
        if (node->right != NULL && node->right->bf < 0) {
            right_rotate(tree, node->right);
        }
        left_rotate(tree, node);
    }
}

void fixup(AVLTree *tree, AVLNode *node) {
    while (node != NULL) {
        update_height_and_bf(node);
        balance(tree, node);
        node = node->parent;
    }
}

int max(int x, int y) {
    if (x > y) return x;
    return y;
}

int get_avlnode_height(AVLNode *node){ 
    if (node == NULL) return -1;
    return node->height;
}