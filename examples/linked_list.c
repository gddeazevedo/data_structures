#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Using head node as auxiliar node

typedef struct __node {
    int data;
    struct __node* next;
} Node;

typedef struct {
    Node* current;
    Node* prev;
} SearchContent;

typedef struct {
    Node* head;
} LinkedList;


LinkedList* new_LinkedList();
void push_front(LinkedList* list, int value);
int pop_front(LinkedList* list);
void insert_in(LinkedList* list, int value);
void remove_from(LinkedList* list, int value);
SearchContent* search(LinkedList* list, int value);
void print_list(LinkedList* list);

void main() {
    LinkedList* list = new_LinkedList();
    push_front(list, 10);
    push_front(list, 1);
    push_front(list, 2);
    pop_front(list);
    insert_in(list, 3);
    insert_in(list, 2);
    insert_in(list, 9);
    insert_in(list, 11);
    insert_in(list, 9);
    remove_from(list, 2);
    remove_from(list, 11);
    print_list(list);
}

LinkedList* new_LinkedList() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = (Node*) malloc(sizeof(Node));
    list->head->next = NULL;
    return list;
}

void push_front(LinkedList* list, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = list->head->next;
    list->head->next = new_node;
}

int pop_front(LinkedList* list) {
    Node* aux = list->head->next;
    list->head->next = aux->next;
    int value = aux->data;
    free(aux);
    return value;
}

void insert_in(LinkedList* list, int value) {
    SearchContent* content = search(list, value);
    Node* current = content->current;
    Node* prev = content->prev;
    bool value_was_not_found = current == NULL; 

    if (value_was_not_found) {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = prev->next;
        prev->next = new_node;
    }
}

void remove_from(LinkedList* list, int value) {
    SearchContent* content = search(list, value);
    Node* current = content->current;
    Node* prev = content->prev;
    bool value_was_found = current != NULL;

    if (value_was_found) {
        prev->next = current->next;
        free(current);
    }
}

SearchContent* search(LinkedList* list, int value) {
    Node* prev = list->head;
    Node* aux = list->head->next;
    Node* current = NULL;

    while (aux != NULL) {
        if (aux->data < value) {
            prev = aux;
            aux = aux->next;
        } else {
            if (aux->data == value) {
                current = aux;
            }
            break;
        }
    }

    SearchContent* content = (SearchContent*) malloc(sizeof(SearchContent));
    content->current = current;
    content->prev = prev;

    return content;
}

void print_list(LinkedList* list) {
    Node* current = list->head->next;

    printf("[ ");
    
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("]\n");
}
