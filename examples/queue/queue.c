#include "queue.h"

Queue* new_Queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = 0;
    q->tail = 0;
    q->max_size = 9;
    return q;
}

void qempty(Queue* queue) {
    queue->head = 0;
    queue->tail = 0;
}

bool qis_empty(Queue* queue) {
    return queue->head == 0;
}

void enqueue(Queue* queue, int value) {
    int position = queue->tail % queue->max_size + 1;

    if (position != queue->head) {
        queue->tail = position;
        queue->it[queue->tail] = value;

        if (qis_empty(queue)) {
            queue->head = 1;
        }
    } else {
        printf("Queue is full!\n");
    }
}

int dequeue(Queue* queue) {
    if (!qis_empty(queue)) {
        int value = queue->it[queue->head];

        if (queue->head == queue->tail) {
            qempty(queue);
        } else {
            queue->head = queue->head % queue->max_size + 1;
        }

        return value;
    }

    printf("Queue is empty!\n");
    return -1;
}

void print_queue(Queue* queue) {
    if (qis_empty(queue)) {
        printf("Empty queue\n");
        return;
    }

    for (int i = 0; i <= queue->max_size; i++) {
        if (queue->head == queue->tail)
            printf("[{%d}] ", queue->it[i]);
        else if (i == queue->head) {
            printf("[%d] ", queue->it[i]);
        } else if (i == queue->tail) {
            printf("{%d} ", queue->it[i]);
        } else {
            printf("%d ", queue->it[i]);
        }
    }

    printf("\n");
}