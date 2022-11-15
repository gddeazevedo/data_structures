#include <stdlib.h>
#include <stdio.h>


typedef struct __node {
    int data;
    struct __node* next;
} Node;


typedef struct {
    Node* head;
} LinkedList;


void push_front(LinkedList* list, int value);
void push_back(LinkedList* list, int value);
void insert_in_order(LinkedList* list, int value);
void print_list(LinkedList* list);


void main() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;

    push_front(list, 10);
    push_front(list, 9);
    push_front(list, 1);
    push_back(list, 14);
    push_back(list, 20);
    push_back(list, 21);
    push_back(list, 23);
    push_front(list, 0);
    insert_in_order(list, 12);
    insert_in_order(list, 24);
    insert_in_order(list, -10);
    insert_in_order(list, 2);
    print_list(list); // [ -10 0 1 2 9 10 12 14 20 21 23 24 ]
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
        list->head = (Node*) malloc(sizeof(Node));
        list->head->data = value;
        list->head->next = NULL;
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
    if (list->head == NULL) {
        list->head = (Node*) malloc(sizeof(Node));
        list->head->data = value;
        list->head->next = NULL;
    } else {
        if (value <= list->head->data) {
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
}

void print_list(LinkedList* list) {
    Node* aux = list->head;

    printf("[ ");

    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }

    printf("]\n");
}
