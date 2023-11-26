#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void inserirNoInicio(Node** referenciaCabeca, int novoDado) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = novoDado;
    novoNo->next = *referenciaCabeca;
    *referenciaCabeca = novoNo;
}

int iguais(Node* noA, Node* noB) {
    while (noA != NULL && noB != NULL) {
        if (noA->data != noB->data) {
            return 0; 
        }
        noA = noA->next;
        noB = noB->next;
    }
    if (noA == NULL && noB == NULL) {
        return 1;
    }
    return 0;
}

int main() {
    Node* listaA = NULL;
    Node* listaB = NULL;
    Node* listaC = NULL;

    inserirNoInicio(&listaA, 3);
    inserirNoInicio(&listaA, 2);
    inserirNoInicio(&listaA, 1);

    inserirNoInicio(&listaB, 3);
    inserirNoInicio(&listaB, 2);
    inserirNoInicio(&listaB, 1);

    inserirNoInicio(&listaC, 2);
    inserirNoInicio(&listaC, 3);
    inserirNoInicio(&listaC, 1);

    printf("iguais(listaA, listaB) = %d\n", iguais(listaA, listaB));
    printf("iguais(listaA, listaC) = %d\n", iguais(listaA, listaC));
    return 0;
}