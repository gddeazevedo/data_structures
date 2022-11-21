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

int pop_front(LinkedList* list) {
    if (list->head != NULL) {
        Node* aux = list->head;
        list->head = list->head->next;
        aux->next = NULL;
        int value = aux->data;
        free(aux);
        return value;
    }

    printf("List is empty!\n");
    return -1000000;
}

int pop_back(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty!\n");
        return -10000;
    }

    Node* prev = list->head;
    Node* aux = list->head;

    while (aux->next != NULL) {
        prev = aux;
        aux = aux->next;
    }

    if (aux == prev) {
        aux = NULL;
        prev = NULL;
        return pop_front(list);
    }

    prev->next = NULL;
    int value = aux->data;
    free(aux);

    return value;
}

void remove_in_order(LinkedList* list, int value) {
    SearchContent* content = search(list, value);

    Node* current = content->current;
    Node* prev = content->prev;

    if (current != NULL && current == list->head) {
        list->head = current->next;
        current->next = NULL;
        free(current);
    } else if (current != NULL) {
        prev->next = current->next;
        current->next = NULL;
        free(current);
    } else {
        printf("Element not found!\n");
    }
}

void insert_in_order(LinkedList* list, int value) {
    if (list->head == NULL || value < list->head->data) {
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

SearchContent* search(LinkedList* list, int value) {
    Node* prev = list->head;
    Node* aux = list->head;
    Node* current = NULL;

    while (aux != NULL) {
        if (aux->data < value) {
            prev = aux;
            aux = aux->next;
        } else {
            if (aux->data == value) {
                current = aux;
            }

            aux = NULL;
        }
    }

    SearchContent* content = (SearchContent*) malloc(sizeof(SearchContent));
    content->current = current;
    content->prev = prev;

    return content;
}
