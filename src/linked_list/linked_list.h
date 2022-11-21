#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include "../node.h"

typedef struct {
    Node* head;
} LinkedList;

typedef struct {
    Node* prev;
    Node* current;
} SearchContent;

LinkedList* new_List();
void print_list(LinkedList* list);
void push_front(LinkedList* list, int value);
void push_back(LinkedList* list, int value);
int pop_front(LinkedList* list);
int pop_back(LinkedList* list);
void remove_in_order(LinkedList* list, int value);
void insert_in_order(LinkedList* list, int value);
SearchContent* search(LinkedList* list, int value);

#endif