# Estruturas de Dados em C


## 1 - Pilhas

- Seguem o princípio LIFO (Last In First Out)
- Inserções (push) e deleções (pop) ocorrem no final da pilha
- Funções:
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
