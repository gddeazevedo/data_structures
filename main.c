#include "src/queue/queue.h"
#include "src/linked_list/linked_list.h"
#include "src/stack/stack.h"

void main() {
    Queue* queue = new_Queue();
    enqueue(queue, 10);
    enqueue(queue, 1);
    enqueue(queue, 30);
    print_queue(queue);
    int v = dequeue(queue);
    printf("%d\n", v);
    print_queue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
}