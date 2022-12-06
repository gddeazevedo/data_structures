#include <stdio.h>

#define L 10

void make_set();
int find(int node);
void union_sets(int x, int y); // x and y are nodes


int parents[L];
int ranks[L];

void main() {

}

void make_set() {
    for (int i = 0; i < L; i++) {
        parents[i] = i;
        ranks[i] = 0;
    }
}

int find(int node) {
    if (node != parents[node]) {
        parents[node] = find(parents[node]);
    }

    return parents[node];
}

void union_sets(int x, int y) {
    int rx = find(x);
    int ry = find(y);

    if (rx == ry) return;

    if (ranks[rx] > ranks[ry]) {
        parents[ry] = rx;
    } else {
        parents[rx] = ry;

        if (ranks[rx] == ranks[ry]) {
            ranks[ry] += 1;
        }
    }
}
