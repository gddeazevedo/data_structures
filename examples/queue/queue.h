#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int it[10];
    int max_size;
    int head;
    int tail;
} Queue;

Queue* new_Queue();
bool qis_empty(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
void print_queue(Queue* queue);

#endif