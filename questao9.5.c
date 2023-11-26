#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void inserirNoInicio(Node** referenciaC, int novoDado) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->data = novoDado;
    novoNo->next = *referenciaC;
    *referenciaC = novoNo;
}

int soma(Node* no) {
    if (no == NULL) {
        return 0; 
    }
    return no->data + soma(no->next);
}

int main() {
    Node* c = NULL;
    
    inserirNoInicio(&c, 4);
    inserirNoInicio(&c, 5);
    inserirNoInicio(&c, 1);
    inserirNoInicio(&c, 3);

    int resultado = soma(c);
    printf("A soma dos elementos da lista é: %d\n", resultado);

    return 0;
}