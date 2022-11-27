#include "doubly_linked_list.h"

DoublyLinkedList* new_DoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    list->head = (DoubleNode*) malloc(sizeof(DoubleNode));
    list->head->prev = list->head;
    list->head->next = list->head;
    return list;
}

DoubleNode* search_in(DoublyLinkedList* list, int value) {
    list->head->data = value;
    DoubleNode* current = list->head->next;

    while (current->data < value) {
        current = current->next;
    }

    return current;
}

void insert_in_order_in(DoublyLinkedList* list, int value) {
    DoubleNode* current = search_in(list, value);

    if (current == list->head || current->data != value) {
        DoubleNode* new_node = (DoubleNode*) malloc(sizeof(DoubleNode));
        new_node->data = value;
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
    } else {
        printf("Value already is in the list!\n");
    }
}

void remove_from(DoublyLinkedList* list, int value) {
    DoubleNode* current = search_in(list, value);
    
    if (current != list->head && current->data == value) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    } else {
        printf("Value not found!\n");
    }
}

void print_doubly_linked_list(DoublyLinkedList* list) {
    DoubleNode* current = list->head->next;

    printf("[ ");
    while (current != list->head) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("]\n");
}
