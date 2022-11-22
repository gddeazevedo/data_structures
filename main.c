#include "src/queue/queue.h"
#include "src/linked_list/linked_list.h"
#include "src/doubly_linked_list/doubly_linked_list.h"
#include "src/stack/stack.h"

void main() {
    LinkedList* list = new_List();

    push_front(list, 1);
    push_front(list, 2);
    push_front(list, 4);
    print_list(list);

    invert(list);
    // empty_list(list);

    print_list(list);
}
