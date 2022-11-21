#include "stack.h"

Stack* new_Stack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value) {
    Node* aux = (Node*) malloc(sizeof(Stack));
    aux->data = value;
    aux->next = stack->top;
    stack->top = aux;
    aux = NULL;
}

int pop(Stack* stack) {
    if (stack->top != NULL) {
        Node* aux = stack->top;
        stack->top = stack->top->next;
        int value = aux->data;
        aux->next = NULL;
        free(aux);
        aux = NULL;
        return value;
    }

    printf("Stack is empty!\n");
    return -100000;
}

void empty_stack(Stack* stack) {
    while (stack->top != NULL) {
        pop(stack);
    }
}

void print_stack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    Node* aux = stack->top;

    printf("top->%d\n", aux->data);

    while (1) {
        aux = aux->next;
        if (aux == NULL) break;
        printf("     %d\n", aux->data);
    }
}
