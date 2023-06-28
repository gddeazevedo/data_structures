#ifndef __avl_tree_h
#define __avl_tree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct __avl_node {
    int key;
    int height;
    int bf; // balance factor
    struct __avl_node *parent;
    struct __avl_node *left; // child
    struct __avl_node *right; // child
} AVLNode;


typedef struct __avl_tree {
    AVLNode *root;
} AVLTree;


AVLTree* newAVLTree();
AVLNode* newAVLNode(int key);
AVLNode* avl_tree_search(AVLNode *node, int key);
AVLNode* avl_tree_min(AVLNode *root);
AVLNode* avl_tree_max(AVLNode *root);
AVLNode* avl_tree_successor(AVLNode *node);
AVLNode* avl_tree_predecessor(AVLNode *node);


void in_order_walk(AVLNode *root);
void pre_order_walk(AVLNode* root);
void avl_tree_insert(AVLTree *tree, int key);
void avl_tree_remove(AVLTree *tree, int key);
void transplant(AVLTree *tree, AVLNode *u, AVLNode *v);
void left_rotate(AVLTree *tree, AVLNode *node);
void right_rotate(AVLTree *tree, AVLNode *node);
void update_height_and_bf(AVLNode *node);
void balance(AVLTree *tree, AVLNode *node);
void fixup(AVLTree *tree, AVLNode *node);

int max(int x, int y);
int get_avlnode_height(AVLNode *node);

#endif