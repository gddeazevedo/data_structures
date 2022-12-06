#include <stdio.h>


int c_vector[10];

void make_set(int* c_vector, int n);
int find(int* c_vector, int el);
void union_sets(int* c_vector, int n, int x, int y);

void main() {
    int n = sizeof(c_vector) / sizeof(int);
    make_set(c_vector, n);
    union_sets(c_vector, n, 0, 5);
    union_sets(c_vector, n, 9, 5);
    union_sets(c_vector, n, 5, 2);

    for (int i = 0; i < n; i++) {
        printf("%d ", c_vector[i]);
    }

    printf("\n");
}

void make_set(int* c_vector, int n) {
    for (int i = 0; i < n; i++)
        c_vector[i] = i;
}

int find(int* c_vector, int el) {
    return c_vector[el];
}

void union_sets(int* c_vector, int n,  int x, int y) {
    int rx = find(c_vector, x);
    int ry = find(c_vector, y);

    if (rx != ry) {
        for (int i = 0; i < 10; i++) {
            if (c_vector[i] == ry) {
                c_vector[i] = c_vector[x];
            }
        }
    }
}