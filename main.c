#include "src/queue/queue.h"
#include "src/linked_list/linked_list.h"
#include "src/doubly_linked_list/doubly_linked_list.h"
#include "src/stack/stack.h"

void main() {
    LinkedList* list = new_List();

    for (int i = 0; i < 11; i++) {
        push_front(list, i);
    }

    invert(list);

    print_list(list);
}
