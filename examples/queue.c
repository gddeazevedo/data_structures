#include <stdio.h>


#define MAX_INDEX 9

typedef int bool;

int queue[10];
int head = 0;
int tail = 0;


void enqueue(int value);
int dequeue();
bool is_empty();
void empty();


void main() {
    enqueue(10);
    enqueue(50);
    enqueue(30);
    enqueue(40);
    enqueue(30);
    enqueue(10);
    enqueue(10);
    enqueue(10);
    enqueue(10);
    enqueue(10);
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    for (int i = 1; i <= MAX_INDEX; i++) {
        if (head == tail && i == head) {
            printf("[{%d}] ", queue[i]);
        } else if (i == head) {
            printf("[%d] ", queue[i]);
        } else if (i == tail) {
            printf("{%d} ", queue[i]);
        } else {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}

void enqueue(int value) {
    int new_position = tail % MAX_INDEX + 1;

    if (new_position != head) {
        tail = new_position;
        queue[tail] = value;

        if (is_empty()) {
            head = 1;
        }
    } else {
        printf("Queue is full!\n");
    }
}

int dequeue() {
    if (!is_empty()) {
        int value = queue[head];

        if (head == tail) {
            empty();
        } else {
            head = head % MAX_INDEX + 1;
        }

        return value;
    } else {
        printf("Queue is empty!\n");
        return -10000000;
    }
}

bool is_empty() {
    return head == 0;
}

void empty() {
    head = 0;
    tail = 0;
}