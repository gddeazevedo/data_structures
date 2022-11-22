#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../node.h"

typedef struct {
    DoubleNode* head;
} DoublyLinkedList;

DoublyLinkedList* new_DoublyLinkedList();
void dpush_front(DoublyLinkedList* list, int value);
int dpop_front(DoublyLinkedList* list);
void d_insert(DoublyLinkedList* list, int value);
void d_remove(DoublyLinkedList* list, int value);
DoubleNode* d_search(DoublyLinkedList* list, int value);
void print_doubly_linked_list(DoublyLinkedList* list);

#endif