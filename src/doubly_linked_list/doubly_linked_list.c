#include "doubly_linked_list.h"


DoublyLinkedList* new_DoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    return list;
}

void dpush_front(DoublyLinkedList* list, int value) {
    DoubleNode* new_node = (DoubleNode*) malloc(sizeof(DoubleNode));
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head != NULL) {
        list->head->prev = new_node;
    }

    list->head = new_node;
    new_node = NULL;
}

int dpop_front(DoublyLinkedList* list) {
    if (list->head != NULL) {
        DoubleNode* aux = list->head;
        list->head = list->head->next;

        if (list->head != NULL)
            list->head->prev = NULL;

        aux->next = NULL;
        int value = aux->data;
        free(aux);
        aux = NULL;
        return value;
    }

    printf("List is empty!\n");
    return -1000000;
}

void d_insert(DoublyLinkedList* list, int value) {
    if (list->head == NULL || value <= list->head->data) {
        dpush_front(list, value);
    } else {
        DoubleNode* current = list->head;

        while (current->next != NULL && value > current->next->data) {
            current = current->next;
        }

        if (current->next == NULL) {
            current->next = (DoubleNode*) malloc(sizeof(DoubleNode));
            current->next->data = value;
            current->next->next = NULL;
            current->next->prev = current;
        } else {
            DoubleNode* tmp = (DoubleNode*) malloc(sizeof(DoubleNode));
            tmp->data = value;
            tmp->next = current->next;
            tmp->prev = current;
            current->next = tmp;
            tmp->next->prev = tmp;
            tmp = NULL;
        }

        current = NULL;
    }
}

void d_remove(DoublyLinkedList* list, int value) {
    DoubleNode* current = list->head;

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found!\n");
        return;
    }

    current->next->prev = current->prev;
    current->prev->next = current->next;
    current->prev = NULL;
    current->next = NULL;
    free(current);
    current = NULL;
}

void print_doubly_linked_list(DoublyLinkedList* list) {
    DoubleNode* current = list->head;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}
