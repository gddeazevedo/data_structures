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
    Node* aux = (Node*) malloc(sizeof(Node));
    aux->data = value;
    aux->next = list->head;
    list->head = aux;
    aux = NULL;
}

void push_back(LinkedList* list, int value) {
    if (list->head == NULL) {
        push_front(list, value);
    } else {
        Node* aux = list->head;

        while (aux->next != NULL) {
            aux = aux->next;
        }

        aux->next = (Node*) malloc(sizeof(Node));
        aux->next->data = value;
        aux->next->next = NULL;
        aux = NULL;
    }
}

void insert_in_order(LinkedList* list, int value) {
    if (list->head == NULL || value <= list->head->data) {
        push_front(list, value);
    } else {
        Node* aux = list->head;

        while (aux->next != NULL && value > aux->next->data) {
            aux = aux->next;
        }

        if (aux->next == NULL) {
            aux->next = (Node*) malloc(sizeof(Node));
            aux->next->data = value;
            aux->next->next = NULL;
        } else {
            Node* tmp = (Node*) malloc(sizeof(Node));
            tmp->data = value;
            tmp->next = aux->next;
            aux->next = tmp;
            tmp = NULL;
        }

        aux = NULL;
    }
}