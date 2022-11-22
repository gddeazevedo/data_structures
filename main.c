#include "src/queue/queue.h"
#include "src/linked_list/linked_list.h"
#include "src/doubly_linked_list/doubly_linked_list.h"
#include "src/stack/stack.h"

void main() {
    DoublyLinkedList* dlist = new_DoublyLinkedList();
    dpush_front(dlist, 4);
    dpush_front(dlist, 2);
    dpush_front(dlist, 1);
    d_insert(dlist, 1);
    d_insert(dlist, 5);
    d_insert(dlist, 3);
    d_insert(dlist, 40);

    for (int i = 0; i < 3; i++) dpop_front(dlist);

    d_insert(dlist, 15);
    d_insert(dlist, 10);
    d_insert(dlist, 20);
    d_insert(dlist, 9);

    print_doubly_linked_list(dlist);

    d_remove(dlist, 20);
    d_remove(dlist, 100);
    d_remove(dlist, 4);

    print_doubly_linked_list(dlist);

}
