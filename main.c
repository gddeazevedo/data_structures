#include "src/queue/queue.h"
#include "src/linked_list/linked_list.h"
#include "src/doubly_linked_list/doubly_linked_list.h"
#include "src/stack/stack.h"

void main() {
    LinkedList* list = new_List();
    
    push_front(list, 10);
    push_front(list, 100);
    push_front(list, 40);
    push_front(list, 8);
    push_back(list, -10);

    remove_element(list, 40);
    remove_element(list, 10);
    remove_element(list, -10);

    print_list(list);
}
