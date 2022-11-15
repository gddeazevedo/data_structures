// Converte notação parentizada para notação polonesa reversa

#include <stdio.h>
#include <string.h>

char expressao[] = "((4+(5*6)) - (2+7))";
char exp_convertida[10];
char stack[10];
int topo = -1;

int is_operador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void push(char val) {
    if (topo < 10) {
        topo++;
        stack[topo] = val;
    }
}

char pop() {
    if (topo > - 1) {
        char val = stack[topo];
        topo--;
        return val;
    }
}

void convert() {
    int p = -1;
    for (int i = 0; i < strlen(expressao); i++) {
        if (expressao[i] == '(') continue;

        if (is_operador(expressao[i])) {
            push(expressao[i]);
        } else if (expressao[i] == ')') {
            char operador = pop();
            p++;
            exp_convertida[p] = operador;
        } else {
            p++;
            exp_convertida[p] = expressao[i];
        }
    }
}

void main() {
    convert();
    printf("%s\n", exp_convertida);
}
