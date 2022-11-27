#include "src/queue/queue.h"
#include "src/linked_list/linked_list.h"
#include "src/doubly_linked_list/doubly_linked_list.h"
#include "src/stack/stack.h"

void main() {
    DoublyLinkedList* list = new_DoublyLinkedList();
    insert_in_order_in(list, 10);
    insert_in_order_in(list, 3);
    insert_in_order_in(list, 5);
    remove_from(list, 5);
    // insert_in_order_in(list, 5);
    remove_from(list, 10);
    remove_from(list, 3);
    remove_from(list, 1);
    print_doubly_linked_list(list);
}
