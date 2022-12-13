#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define L 50
#define MAX_KEY 50

typedef struct __node {
    char key[MAX_KEY];
    int item;
    struct __node* next;
} Node;

static Node* table[L];

static Node* search(char* key);
static int hash(char* key);
int get(char* key);
void put(char* key, int item);
void print_hash_table();

#endif