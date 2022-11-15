#include "src/linked_list/linked_list.h"


void main() {
    LinkedList* list = new_List();

    for (int i = 10; i > 0; i--) {
        push_front(list, i * 10);
    }

    print_list(list);
}