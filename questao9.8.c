#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void inserirNoInicio(Node** referenciaC, char novoDado) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = novoDado;
    novoNo->next = *referenciaC;
    *referenciaC = novoNo;
}

char enesimo(int n, Node* no) {
    if (n <= 0 || no == NULL) {
        printf("Erro fatal: n inválido ou excede o tamanho da lista\n");
        exit(1);
    }

    if (n == 1) {
        return no->data;
    }

    return enesimo(n - 1, no->next);
}

int main() {
    Node* c = NULL;

    inserirNoInicio(&c, 'd');
    inserirNoInicio(&c, 'c');
    inserirNoInicio(&c, 'b');
    inserirNoInicio(&c, 'a');

    char elemento = enesimo(3, c);
    printf("O elemento na posição 3 é: %c\n", elemento);

    return 0;
}