#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../node.h"

typedef struct {
    Node* top;
} Stack;

Stack* new_Stack();
void push(Stack* stack, int value);
int pop(Stack* stack);
void empty_stack(Stack* stack);
void print_stack(Stack* stack);

#endif