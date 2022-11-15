#include "stack.h"


Stack* new_Stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->max_size = 10;
    stack->top = -1;
    return stack;
}

void empty(Stack* stack) {
    stack->top = -1;
}

bool is_empty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top < stack->max_size) {
        stack->top += 1;
        stack->it[stack->top] = value;
    } else {
        printf("Stack is full!\n");
    }
}

int pop(Stack* stack) {
    if (!is_empty(stack)) {
        int value = stack->it[stack->top];
        stack->top -= 1;
        return value;
    }

    printf("Stack is already empty!\n");
    return -1;
}

void print_stack(Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->it[i]);
    }
    printf("<-top\n");
}