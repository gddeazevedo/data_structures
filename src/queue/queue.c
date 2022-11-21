#include "queue.h"

Queue* new_Queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void empty_queue(Queue* queue) {
    while (queue->head != NULL && queue->tail != NULL) {
        dequeue(queue);
    }
}

void enqueue(Queue* queue, int value) {
    Node* aux = (Node*) malloc(sizeof(Node));
    aux->data = value;
    aux->next = NULL;

    if (queue->tail != NULL) {
        queue->tail->next = aux;
    } else {
        queue->head = aux;
    }

    queue->tail = aux;
}

int dequeue(Queue* queue) {
    if (queue->head != NULL) {
        Node* aux = queue->head;
        queue->head = queue->head->next;
        aux->next = NULL;
        int value = aux->data;
        free(aux);

        if (queue->head == NULL) {
            queue->tail = NULL;
        }

        aux = NULL;
        return value;
    } else {
        printf("Queue is empty!\n");
        return -1000000;
    }
}

void print_queue(Queue* queue) {
    Node* aux = queue->head;

    while (aux != NULL) {
        printf("%d ", aux->data);
        aux = aux->next;
    }

    printf("\n");
}