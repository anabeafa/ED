#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int topo;
} Pilha;

void empilhar(Pilha *pilha, char item) {
    if (pilha->topo == MAX_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    pilha->items[++pilha->topo] = item;
}

char desempilhar(Pilha *pilha) {
    if (pilha->topo == -1) {
        printf("Erro: Pilha vazia\n");
        return '\0';
    }
    return pilha->items[pilha->topo--];
}

int precedencia(char op) {
    if (op == '~') return 3;
    else if (op == '&') return 2;
    else if (op == '|') return 1;
    return 0;
}

int ehOperador(char c) {
    return (c == '~' || c == '&' || c == '|');
}


void infixaParaPosfixa(char *infixa, char *posfixa) {
    Pilha pilha;
    pilha.topo = -1;
    int i = 0, j = 0;

  
    while (infixa[i] != '\0') {
        char simbolo = infixa[i];

        if (simbolo == 'V' || simbolo == 'F') {
            posfixa[j++] = simbolo;
        }
        else if (simbolo == '(') {
            empilhar(&pilha, simbolo);
        }
   
        else if (simbolo == ')') {
      
            while (pilha.topo != -1 && pilha.items[pilha.topo] != '(') {
                posfixa[j++] = desempilhar(&pilha);
            }
         
            if (pilha.topo == -1) {
                printf("Erro: Expressão inválida\n");
                return;
            }
         
            desempilhar(&pilha);
        }
   
        else if (ehOperador(simbolo)) {

            while (pilha.topo != -1 && precedencia(pilha.items[pilha.topo]) >= precedencia(simbolo)) {
                posfixa[j++] = desempilhar(&pilha);
            }
      
            empilhar(&pilha, simbolo);
        }
        i++;
    }

    while (pilha.topo != -1) {
        if (pilha.items[pilha.topo] == '(') {
            printf("Erro: Expressão inválida\n");
            return;
        }
        posfixa[j++] = desempilhar(&pilha);
    }

    posfixa[j] = '\0';
}

int main() {
    char infixaExpressao[MAX_SIZE];
    char posfixaExpressao[MAX_SIZE];

    printf("Digite a expressão lógica infixa: ");
    fgets(infixaExpressao, MAX_SIZE, stdin);
    infixaParaPosfixa(infixaExpressao, posfixaExpressao);
    printf("Expressão posfixa: %s\n", posfixaExpressao);

    return 0;
}