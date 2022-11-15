#include <stdio.h>

#define MAX_INDEX 9

typedef int bool;

int stack[10];
int top = -1;

void push(int value);
int pop();
void empty();
bool is_empty();


void main() {
    push(12);
    push(14);
    push(50);
    push(50);
    push(50);
    push(50);
    push(50);
    push(50);push(50);push(50);push(50);push(50);push(50);
    // pop();
    // empty();

    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }

    printf("<-top\n");
}

void push(int value) {
    if (top <= MAX_INDEX) {
        top++;
        stack[top] = value;
    } else {
        printf("Stack is full!\n");
    }
}

int pop() {
    if (is_empty()) {
        printf("Underflow\n");
        return -1000000;
    }

    int value = stack[top];
    top--;
    return value;
}

void empty() {
    top = -1;
}

bool is_empty() {
    return top == -1;
}
