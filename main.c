#include "src/linked_list/linked_list.h"


void main() {
    LinkedList* list = new_List();

    for (int i = 10; i > 0; i--) {
        push_front(list, i * 10);
    }

    push_front(list, -10);
    push_back(list, 101);
    insert_in_order(list, 5);
    insert_in_order(list, 29);
    insert_in_order(list, 31);

    print_list(list);
}