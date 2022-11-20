#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10


typedef struct {
    int top;
    int max_size;
    int it[10];
} Stack;

Stack* new_Stack();
void empty(Stack* stack);
bool is_empty(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
void print_stack(Stack* stack);

#endif