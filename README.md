# Estruturas de Dados em C

<h2>
Tópicos

- [1 - Pilhas](#1---pilhas)
- [2 - Filas](#2---filas)
- [3 - Listas Encadeadas](#3---listas-encadeadas)
- [4 - Lista duplamente encadeada](#4---lista-duplamente-encadeada)

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
typedef struct {
    Node* prev;
    Node* current;
} SearchContent;

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
SearchContent* search(LinkedList* list, int value); // Pesquisa por um item em uma lista encadeada ordenada
void invert(LinkedList* list);                      // Inverte uma lista encadeada 
void empty_list(LinkedList* list);                  // Esvazia uma lista encadeada
```

## 4 - Lista duplamente encadeada

- Similar às listas encadeadas
- Porém, cada nó tem a referência para o nó seguinte e para o nó anterior
- O nó cabeça (head) é usado como nó auxiliar, ele não armazena valor
- A referência seguinte do ultímo nó é o nó cabeça
- A referência anterior do nó cabeça é o último nó
- Uma lista vazia possui apenas o nó cabeça, com a referência anterior e seguinte sendo o próprio nó cabeça

### [Funções](./src/doubly_linked_list/doubly_linked_list.h)

```c
typedef struct __double_node {
    int data;
    struct __double_node* prev;
    struct __double_node* next;
} DoubleNode;

typedef struct {
    DoubleNode* head;
} DoublyLinkedList;

DoublyLinkedList* new_DoublyLinkedList(); // Retorna um ponteiro para uma lista duplamente encadeada
DoubleNode* search_in(DoublyLinkedList* list, int value); // Pesquisa um valor em uma lista duplamente encadeada ordenada
void insert_in_order_in(DoublyLinkedList* list, int value); // Insere um valor de forma ordenada em uma lista duplamente encadeada ordenada
void remove_from(DoublyLinkedList* list, int value); // Remove um valor da lista duplamente encadeada
void print_doubly_linked_list(DoublyLinkedList* list); // Mostra o conteúdo da lista duplamente encadeada
```