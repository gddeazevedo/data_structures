#include <stdio.h>
#include <string.h>


#define null -1000000
#define L 10


typedef struct {
    char key[50];
    int item;
    int next;
} Node;


typedef struct {
    int prev;
    int current;
} SearchContent;


Node table[L];
int n = 0;


int hash(char* key) {
    int counter = 0;
    int len = strlen(key);

    for (int i = 0; i < len; i++)
        counter += key[i];

    return (counter * counter + len) % L;
}


SearchContent search(char* key) {
    int p = hash(key);
    int ant = p;

    while (table[p].next != null && strcmp(table[p].key, key) != 0) {
        ant = p;
        p = table[p].next;
    }

    if (strcmp(table[p].key, key) != 0) {
        p = null;
    }

    return (SearchContent) {
        .current = p,
        .prev = ant
    };
}

void put(char* key, int item) {
    SearchContent content = search(key);
    int prev = content.prev;
    int current = content.current;

    if (current == null && n < L) {
        if (table[prev].item == null) {
            current = prev;
            table[current].item = item;
            strcpy(table[current].key, key);
        } else {
            int j = table[prev].next;
            strcpy(table[j].key, key);
            table[j].item = item;
            table[prev].next = j;
        }

        n += 1;
    }
}

void main() {
    for (int i = 0; i < L; i++) {
        table[i].next = null;
    }

    put("Gabriel", 21);
}