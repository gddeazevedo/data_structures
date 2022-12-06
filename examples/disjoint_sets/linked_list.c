#include <stdio.h>
#include <stdlib.h>

#define L 10

typedef struct __node {
    int el;
    struct __node* next;
    struct __node* repr;
} Node;

Node* sets[L];

void make_set(Node** sets);
Node* find(Node** sets, int node);
void union_sets(Node** sets, int x, int y);

void main() {
    make_set(sets);

    for (int i = 0; i < L; i++) {
        printf("%d ", sets[i]->el);
    }

    printf("\n");

    printf("%d\n", sets[5]->repr->el);
}

void make_set(Node** sets) {
    for (int i = 0; i < L; i++) {
        sets[i] = (Node*) malloc(sizeof(Node));
        sets[i]->el = i;
        sets[i]->repr = sets[i];
        sets[i]->next = NULL;
    }
}

Node* find(Node** sets, int node) {
    return sets[node]->repr;
}

void union_sets(Node** sets, int x, int y) {
    
}
