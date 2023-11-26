#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char itens[MAX_SIZE];
    int topo;
} Pilha;

void empilhar(Pilha *pilha, char item) {
    if (pilha->topo == MAX_SIZE - 1) {
        printf("Erro: Estouro da pilha\n");
        return;
    }
    pilha->itens[++pilha->topo] = item;
}

char desempilhar(Pilha *pilha) {
    if (pilha->topo == -1) {
        printf("Erro: Pilha vazia\n");
        return '\0';
    }
    return pilha->itens[pilha->topo--];
}

int prioridadeOperador(char operador) {
    if (operador == '~') {
        return 3;
    } else if (operador == '&' || operador == '|') {
        return 2;
    }
    return 1;
}

void infixaParaPosfixa(char *infixa, char *posfixa) {
    Pilha pilha;
    pilha.topo = -1;
    int i = 0;
    int j = 0;

    while (infixa[i] != '\0') {
        char simbolo = infixa[i];

        if (simbolo == 'V' || simbolo == 'F') {
            posfixa[j++] = simbolo;
        } else if (simbolo == '(') {
            empilhar(&pilha, simbolo);
        } else if (simbolo == ')') {
            while (pilha.itens[pilha.topo] != '(') {
                posfixa[j++] = desempilhar(&pilha);
            }
            desempilhar(&pilha);
        } else {
            while (pilha.topo != -1 && prioridadeOperador(pilha.itens[pilha.topo]) >= prioridadeOperador(simbolo)) {
                posfixa[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, simbolo);
        }
        i++;
    }

    while (pilha.topo != -1) {
        posfixa[j++] = desempilhar(&pilha);
    }

    posfixa[j] = '\0';
}

bool avaliarExpressaoPosfixa(char *posfixa) {
    Pilha pilha;
    pilha.topo = -1;
    int i = 0;

    while (posfixa[i] != '\0') {
        char simbolo = posfixa[i];

        if (simbolo == 'V' || simbolo == 'F') {
            empilhar(&pilha, simbolo);
        } else if (simbolo == '~') {
            char operando = desempilhar(&pilha);
            char resultado = (operando == 'V') ? 'F' : 'V';
            empilhar(&pilha, resultado);
        } else if (simbolo == '&' || simbolo == '|') {
            char operando2 = desempilhar(&pilha);
            char operando1 = desempilhar(&pilha);

            char resultado;
            if (simbolo == '&') {
                resultado = (operando1 == 'V' && operando2 == 'V') ? 'V' : 'F';
            } else {
                resultado = (operando1 == 'V' || operando2 == 'V') ? 'V' : 'F';
            }
            empilhar(&pilha, resultado);
        }
        i++;
    }

    return (desempilhar(&pilha) == 'V');
}

int main() {
    char expressaoInfixa[MAX_SIZE];
    char expressaoPosfixa[MAX_SIZE];

    printf("Digite a expressão lógica infixa: ");
    scanf("%s", expressaoInfixa);

    infixaParaPosfixa(expressaoInfixa, expressaoPosfixa);
    printf("Expressão lógica posfixa: %s\n", expressaoPosfixa);

    bool valor = avaliarExpressaoPosfixa(expressaoPosfixa);
    printf("Resultado da expressão: %s\n", valor ? "Verdadeiro" : "Falso");

    return 0;
}