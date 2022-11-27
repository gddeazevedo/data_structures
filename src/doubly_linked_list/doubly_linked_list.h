#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../node.h"

typedef struct {
    DoubleNode* head;
} DoublyLinkedList;

DoublyLinkedList* new_DoublyLinkedList();
DoubleNode* search_in(DoublyLinkedList* list, int value);
void insert_in_order_in(DoublyLinkedList* list, int value);
void remove_from(DoublyLinkedList* list, int value);
void print_doubly_linked_list(DoublyLinkedList* list);

#endif