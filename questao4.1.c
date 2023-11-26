#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct {
    int itens[MAX_SIZE];
    int frente;
    int tras;
    int tamanho;
} Fila;

Fila criarFila() {
    Fila fila;
    fila.frente = 0;
    fila.tras = -1;
    fila.tamanho = 0;
    return fila;
}

void enfileirar(int elemento, Fila *fila) {
    if (fila->tamanho >= MAX_SIZE) {
        printf("Erro: Fila cheia\n");
        return;
    }
    fila->tras = (fila->tras + 1) % MAX_SIZE;
    fila->itens[fila->tras] = elemento;
    fila->tamanho++;
}

int desenfileirar(Fila *fila) {
    if (fila->tamanho == 0) {
        printf("Erro: Fila vazia\n");
        return -1;
    }
    int removido = fila->itens[fila->frente];
    fila->frente = (fila->frente + 1) % MAX_SIZE;
    fila->tamanho--;
    return removido;
}

int main() {
    Fila F = criarFila();

    enfileirar(1, &F);
    enfileirar(2, &F);
    enfileirar(3, &F);

  
    enfileirar(desenfileirar(&F), &F);
    enfileirar(desenfileirar(&F), &F);

    printf("%d\n", desenfileirar(&F));

    return 0;
}

/*Ele cria uma fila, adiciona os números 1, 2 e 3 à fila,
retira os dois primeiros números e os coloca de volta na fila.
Por fim, exibe o primeiro elemento restante na fila, que será 3. */