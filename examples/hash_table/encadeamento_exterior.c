#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 50
#define KEY_MAX 50


typedef struct __node {
    char key[KEY_MAX];
    int item;
    struct __node* next;
} Node;


Node* table[L];


int hash(char* key) {
    int hash_value = 0;
    int key_len = strnlen(key, KEY_MAX);

    for (int i = 0; i < key_len; i++) {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % L;
    }

    return hash_value;
}

Node* search(char* key) {
    int index = hash(key);
    Node* current = table[index];

    while (current != NULL && strcmp(current->key, key) != 0) {
        current = current->next;
    }

    return current;
}

int get(char* key) {
    Node* current = table[hash(key)];

    while (current != NULL && strcmp(current->key, key) != 0) {
        current = current->next;
    }

    if (current == NULL) return -1;

    return current->item;
}

void put(char* key, int item) {
    int index = hash(key);
    Node* current = search(key);

    if (current == NULL) {
        current = (Node*) malloc(sizeof(Node));
        strcpy(current->key, key);
        current->item = item;
        current->next = table[index];
        table[index] = current;
    }
}

void print_table() {
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

int main() {
    put("Creed", 60);
    put("Jim", 35);
    put("Dwight", 40);
    put("Michael", 43);
    put("Pam", 32);
    put("Stanley", 65);

    printf("%d\n", get("Creed"));
    printf("%d\n", get("Jim"));
    printf("%d\n", get("Dwight"));
    printf("%d\n", get("Michael"));
    printf("%d\n", get("Pam"));
    printf("%d\n", get("Stanley"));

    printf("Creed hash: %d\n", hash("Creed"));
    printf("Jim hash: %d\n", hash("Jim"));
    printf("Dwight hash: %d\n", hash("Dwight"));
    printf("Michael hash: %d\n", hash("Michael"));
    printf("Pam hash: %d\n", hash("Pam"));
    printf("Stanley hash: %d\n", hash("Stanley"));

    print_table();

    return 0;
}
