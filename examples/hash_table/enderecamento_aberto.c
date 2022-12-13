#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define KEY_SIZE 50

typedef struct {
    char key[KEY_SIZE];
    int item;
} Node;

typedef struct {
    int ant;
    int p;
} Search;

Node* table[TABLE_SIZE];
int n = 0;

unsigned int hash(char* key) {
    int hash_value = 0;
    int len = strlen(key);

    for (int i = 0; i < len; i++) {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % TABLE_SIZE;
    }

    return hash_value;
}


Search search(char* key) {
    int p = hash(key);
    int ant = p;

    while (table[p] != NULL && strcmp(table[p]->key, key) != 0) {
        ant = p;
        p = (p % TABLE_SIZE) + 1;
    }

    if (table[p] == NULL) p = -1;

    return (Search) {
        .ant = ant,
        .p = p
    };
}

void put(char* key, int item) {
    Search s = search(key);
    int ant = s.ant;
    int p = s.p;

    if (p == -1 && n < TABLE_SIZE) {
        table[ant] = (Node*) malloc(sizeof(Node));
        table[ant]->item = item;
        strcpy(table[ant]->key, key);
        n++;
    }
}


int main() {
    put("Person1", 12);
    put("Person2", 13);
    put("Person3", 14);
    put("Person4", 15);


    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            printf("\t%i\t%s: %d\n", i, table[i]->key, table[i]->item);
        } else {
            printf("\t%i\t---: ---\n", i);
        }
    }

    return 0; 
}
