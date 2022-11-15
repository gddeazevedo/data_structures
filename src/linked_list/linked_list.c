#include "linked_list.h"

LinkedList* new_List() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void print_list(LinkedList* list) {
    if (list->head == NULL) {
        printf("[]\n");
        return;
    }

    Node* aux = list->head;

    printf("[ ");
    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }

    printf("]\n");
}

void push_front(LinkedList* list, int value) {
    if (list->head == NULL) {
        list->head = (Node*) malloc(sizeof(Node));
        list->head->data = value;
        list->head->next = NULL;
    } else {
        Node* aux = (Node*) malloc(sizeof(Node));
        aux->data = value;
        aux->next = list->head;
        list->head = aux;
        aux = NULL;
    }
}