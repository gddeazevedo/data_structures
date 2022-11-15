# Estruturas de Dados em C

<h2>
Tópicos

- [1 - Pilhas](#1---pilhas)
- [2 - Filas](#2---filas)
- [3 - Listas Encadeadas](#3---listas-encadeadas)

</h2>

## 1 - Pilhas

- Seguem o princípio LIFO (Last In First Out)
- Inserções (push) e deleções (pop) ocorrem no final da pilha
### [Funções](./src/stack/stack.h):

```c
typedef struct {
    int it[10];   // A pilha em si
    int max_size; // Tamanho máximo da pilha
    int top;      // Índice do último elemento dentro da pilha
} Stack;

void push(Stack* stack, int value); // Empilha um elemento
int pop(Stack* stack, int value);   // Desempilha um elemento e retorna o elemento desempilhado
void empty(Stack* stack);           // Esvazia a pilha (top == -1)
bool is_empty(Stack* stack);        // Retorna true se a pilha estiver vazia e false se não
Stack* new_Stack();                 // Retorna um ponteiro para uma pilha
```

## 2 - Filas

- Seguem o princípio FIFO (First In First Out)
- Inserções (enqueue) ocorrem no final da fila e deleções (dequeue) ocorrem no início da fila
- Filas com vetor possuem caráter circular, ou seja para determinar onde se insere um item se usa aritmética modular:
```tail = tail % max_size + 1;```
- Para que a fórmula acima funcione, é preciso que o primeiro índice seja o 1
### [Funções](./src/queue/queue.h):

```c
typedef struct {
    int it[10];   // A fila em si
    int max_size; // Tamanho máximo da fila
    int head;     // Início da fila
    int tail;     // Final da fila
} Queue;

Queue* new_Queue();                        // Retorna um ponteiro para a fila
bool qis_empty(Queue* queue);              // Retorna true se a fila estiver vazia e false se não
void enqueue(Queue* queue, int value);     // Adiciona um elemento no final da fila
int dequeue(Queue* queue);                 // Remove um elemento no início da fila
void print_queue(Queue* queue);            // Mostra os elementos da fila
```

## 3 - Listas encadeadas

- Armazena elementos de forma não contígua
- Lista composta de nós, cada nó armazena um valor e um ponteiro para o próximo nó na lista
- Pode se inserir elementos onde desejar, porém inserções no início possuem complexidade O(1) e inserções no final possuem complexidade O(n)

### [Funções](./src/linked_list/linked_list.h):

```c
typedef struct __node {
    int data;              // valor
    struct __node* next;   // ponteiro para o próximo nó na lista
} Node;

typedef struct {
    Node* head;           // primeiro nó na lista (não está vazio)
} LinkedList;


LinkedList* new_List();                            // Retorna um ponteiro para uma lista
void print_list(LinkedList* list);                 // Mostra a lista
void push_front(LinkedList* list, int value);      // Adiciona um elemento no início da lista
void push_back(LinkedList* list, int value);       // Adiciona um elemento no final da lista
void insert_in_order(LinkedList* list, int value); // Adiciona um elemento na posição correta numa lista ordenada de forma crescente
```
