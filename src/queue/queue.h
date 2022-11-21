#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../node.h"

typedef struct {
    Node* head;
    Node* tail;
} Queue;

Queue* new_Queue();
void empty_queue(Queue* queue);
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
void print_queue(Queue* queue);

#endif