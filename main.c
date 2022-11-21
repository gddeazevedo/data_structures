#include "src/stack/stack.h"


void main() {
    Stack* stack = new_Stack();
    push(stack, 10);
    push(stack, 30);
    push(stack, 1);
    push(stack, 40);
    print_stack(stack);
    pop(stack);
    pop(stack);
    print_stack(stack);
}