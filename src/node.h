#ifndef NODE_H
#define NODE_H

typedef struct __node {
    int data;
    struct __node* next;
} Node;

typedef struct __double_node {
    int data;
    struct __double_node* prev;
    struct __double_node* next;
} DoubleNode;

#endif