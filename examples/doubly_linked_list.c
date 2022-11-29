#include <stdio.h>
#include <stdlib.h>


typedef struct __node {
    int data;
    struct __node* prev;
    struct __node* next;
} Node;

typedef struct {
    Node* head;
} DoublyLinkedList;


DoublyLinkedList* new_DoublyLinkedList();
Node* search(DoublyLinkedList* list, int value);
void insert_in(DoublyLinkedList* list, int value);
void remove_from(DoublyLinkedList* list, int value);
void print_list(DoublyLinkedList* list);

void main() {
    DoublyLinkedList* list = new_DoublyLinkedList();
    insert_in(list, 10);
    insert_in(list, 1);
    insert_in(list, 2);
    insert_in(list, -1);
    remove_from(list, -1);
    insert_in(list, -1);
    remove_from(list, -1);
    remove_from(list, 10);
    print_list(list);
}

DoublyLinkedList* new_DoublyLinkedList() {
    DoublyLinkedList* list = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList));
    list->head = (Node*) malloc(sizeof(Node));
    list->head->next = list->head;
    list->head->prev = list->head;
    return list;
}

Node* search(DoublyLinkedList* list, int value) {
    list->head->data = value;
    Node* current = list->head->next;

    while (current->data < value) {
        current = current->next;
    }

    return current;
}

void insert_in(DoublyLinkedList* list, int value) {
    Node* current = search(list, value);

    if (current == list->head || current->data != value) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = value;
        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;
    }
}

void remove_from(DoublyLinkedList* list, int value) {
    Node* current = search(list, value);

    if (current != list->head && current->data == value) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
}

void print_list(DoublyLinkedList* list) {
    Node* current = list->head->next;

    printf("[ ");

    while (current != list->head) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("]\n");
}