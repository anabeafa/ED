#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char itens[MAX_SIZE];
    int frente, tras;
} Fila;

void entrar(Fila *fila, char item) {
    if ((fila->tras + 1) % MAX_SIZE == fila->frente) {
        printf("Erro: Fila cheia\n");
        return;
    }
    fila->tras = (fila->tras + 1) % MAX_SIZE;
    fila->itens[fila->tras] = item;
}

char sair(Fila *fila) {
    if (fila->frente == fila->tras) {
        printf("Erro: Fila vazia\n");
        return '\0';
    }
    fila->frente = (fila->frente + 1) % MAX_SIZE;
    return fila->itens[fila->frente];
}

char primeiro(Fila *fila) {
    if (fila->frente == fila->tras) {
        printf("Erro: Fila vazia\n");
        return '\0';
    }
    int proximo = (fila->frente + 1) % MAX_SIZE;
    return fila->itens[proximo];
}

char ultimo(Fila *fila) {
    if (fila->frente == fila->tras) {
        printf("Erro: Fila vazia\n");
        return '\0';
    }
    return fila->itens[fila->tras];
}

int filaCheia(Fila *fila) {
    return (fila->tras + 1) % MAX_SIZE == fila->frente;
}

int filaVazia(Fila *fila) {
    return fila->frente == fila->tras;
}

void empilhar(Fila *fila1, Fila *fila2, char item) {
    while (!filaVazia(fila1)) {
        entrar(fila2, sair(fila1));
    }
    entrar(fila1, item);
    while (!filaVazia(fila2)) {
        entrar(fila1, sair(fila2));
    }
}

char desempilhar(Fila *fila) {
    return sair(fila);
}

int main() {
    Fila fila1, fila2;
    fila1.frente = fila1.tras = MAX_SIZE - 1;
    fila2.frente = fila2.tras = MAX_SIZE - 1;

    empilhar(&fila1, &fila2, 'A');
    empilhar(&fila1, &fila2, 'B');
    empilhar(&fila1, &fila2, 'C');

    printf("Desempilhando: %c\n", desempilhar(&fila1));
    printf("Desempilhando: %c\n", desempilhar(&fila1));
    printf("Desempilhando: %c\n", desempilhar(&fila1));

    return 0;
}