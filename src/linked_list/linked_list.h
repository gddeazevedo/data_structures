#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct __node {
    int data;
    struct __node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;


LinkedList* new_List();
void print_list(LinkedList* list);
void push_front(LinkedList* list, int value);
void push_back(LinkedList* list, int value);
void insert_in_order(LinkedList* list, int value);

#endif