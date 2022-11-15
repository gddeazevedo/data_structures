#include <stdio.h>


#define MAX 10

typedef int bool;

int deque[MAX];
int head = 0;
int tail = 0;


void enqueue_head(int value);
void enqueue_tail(int value);
int dequeue_head();
int dequeue_tail();
void empty();
bool is_empty();

void main() {
    enqueue_head(10);
    enqueue_head(12);
    enqueue_head(12);
    enqueue_head(12);
    enqueue_head(12);
    enqueue_head(12);
    enqueue_head(12);
    enqueue_head(12);
    enqueue_head(12);
    enqueue_head(12);

    dequeue_head();
    dequeue_tail();
    dequeue_tail();
    dequeue_tail();
    dequeue_tail();
    dequeue_head();
    dequeue_head();
    dequeue_tail();

    for (int i = 1; i < MAX; i++) {
        if (head == tail && i == head) {
            printf("[{%d}] ", deque[i]);
        } else if (i == head) {
            printf("[%d] ", deque[i]);
        } else if (i == tail) {
            printf("{%d} ", deque[i]);
        } else {
            printf("%d ", deque[i]);
        }
    }

    printf("\n");
}

void enqueue_head(int value) {
    if (is_empty()) {
        head = 1;
        tail = 1;
        deque[head] = value;
        return;
    }

    int new_position = head % MAX - 1;

    if (new_position == 0) {
        new_position = MAX - 1;
    }

    if (new_position != tail) {
        head = new_position;
        deque[head] = value;
    } else {
        printf("Deque is full!\n");
    }
}

void enqueue_tail(int value) {
    int new_position = tail % MAX + 1;

    if (new_position != head) {
        tail = new_position;
        deque[tail] = value;

        if (is_empty()) {
            head = 1;
        }
    } else {
        printf("Deque is full!\n");
    }
}

int dequeue_head() {
    if (!is_empty()) {
        int value = deque[head];

        if (head == tail) {
            empty();
        } else {
            head = head % MAX + 1;
        }

        return value;
    }

    printf("Deque is empty!\n");
    return -1000000;
}

int dequeue_tail() {
    if (is_empty()) {
        printf("Deque is empty!\n");
        return -1000000;
    }

    int value = deque[tail];
    
    if (head == tail) {
        empty();
    } else {
        tail = tail % MAX - 1;

        if (tail == 0) {
            tail = MAX - 1;
        }
    }

    return value;
}

void empty() {
    head = 0;
    tail = 0;
}

bool is_empty() {
    return head == 0;
}
