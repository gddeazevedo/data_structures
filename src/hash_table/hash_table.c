#include "hash_table.h"

static int hash(char* key) {
    int hash_value = 0;
    int key_len = strnlen(key, MAX_KEY);

    for (int i = 0; i < key_len; i++) {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % L;
    }

    return hash_value;
}

static Node* search(char* key) {
    Node* current = table[hash(key)];

    while (current != NULL && strcmp(current->key, key) != 0) {
        current = current->next;
    }

    return current;
}

int get(char* key) {
    Node* current = search(key);

    if (current == NULL) return -1;

    return current->item; 
}

void put(char* key, int item) {
    int index = hash(key);
    Node* current = search(key);

    if (current == NULL) {
        current = (Node*) malloc(sizeof(Node));
        current->item = item;
        strcpy(current->key, key);
        current->next = table[index];
        table[index] = current;
    }
}

void print_hash_table() {
    printf("{\n");
    for (int i = 0; i < L; i++) {
        Node* current = table[i];

        while (current != NULL) {
            printf(" %s: %d\n", current->key, current->item);
            current = current->next;
        }
    }
    printf("}\n");
}